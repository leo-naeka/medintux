#include "C_BaseCommon.h"
#include <QByteArray>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QUuid>
#include <QSqlError>
#include <QString>
#include <QTimer>
#include <QObject>
#include <QFile>
#include <QProgressBar>
#include <QTextStream>
#include <QApplication>
#include <QMap>
#include <QMapIterator>
#include <QLabel>

#include "../MedinTuxTools-QT4/CGestIni.h"
#include "../MedinTuxTools-QT4/C_Utils_Log.h"
#include "uuid/C_MyUuid.h"


#define   DUMMY_TEST_SQL_COMMAND   "SELECT 1"

//---------------------------------------- C_BaseCommon -------------------------------------------------------
C_BaseCommon::C_BaseCommon(QObject *parent)
    : QObject(parent), C_Log()
{m_BaseLabel       = "";
 m_LastError       = "";
 m_StatusWidget    = 0;
 m_pQProgressBar   = 0;
 m_pReconnectTimer = 0;
 m_GUID_CreateMode = C_BaseCommon::byMyself;
 m_ownerList.clear();
}

//---------------------------------------- C_BaseCommon -------------------------------------------------------
C_BaseCommon::~C_BaseCommon()
{if (m_pReconnectTimer)
    {m_pReconnectTimer->stop();
     disconnect( m_pReconnectTimer, SIGNAL(timeout()), this, SLOT(Slot_ReconnectTimerDone()) );
    }
 QSqlDatabase::database( m_BaseLabel ).close();
 QSqlDatabase::removeDatabase (m_BaseLabel);
}

//---------------------------------------- EncodePassword_InConnectionParam -------------------------------------------------------
bool C_BaseCommon::EncodePassword_InConnectionParam(const QString &param, const QString &section, QString* errMess /* =0*/)
{

 QString driver;             // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
 QString dataBaseToConnect;  // nom de la base: si QODBC3 -> nom de la source de données (userDSN)
 QString user;               // = "root"
 QString password;           // = ""
 QString hostname;           // = "localhost"
 QString port;               // = "3306"
 if (CGestIni::Param_ReadParam(  param.toAscii(), section.toAscii(), "Parametres", &driver, &dataBaseToConnect, &user, &password, &hostname, &port) !=0 )  // zero = pas d'erreur
    { if (errMess) *errMess  = QObject::tr("C_BaseCommon::EncodePassword_InConnectionParam() : error in parameters : CGestIni::Param_ReadParam() may be : key 'Parametres' omitted in section 'Connexion'");
      return 0;
    }
 if (password.startsWith('#'))   password = CGestIni::PassWordDecode(password.mid(1));
 password = CGestIni::PassWordEncode(password);
 password.prepend('#');
 QString tmp = param;
 CGestIni::Param_WriteParam(  &tmp, section.toAscii(), "Parametres", driver.toAscii(), dataBaseToConnect.toAscii(), user.toAscii(), password.toAscii(), hostname.toAscii(), port.toAscii());
 return 1;
}

//---------------------------------------- BaseConnect -------------------------------------------------------
bool C_BaseCommon::BaseConnect(const QString &param, const QString &baseLabel, const QString &dataBase /* ="" */, QString* errMess /* =0*/, const QString &section  /* = "Connexion" */)
{

 QString driver;             // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
 QString dataBaseToConnect;  // nom de la base: si QODBC3 -> nom de la source de données (userDSN)
 QString user;               // = "root"
 QString password;           // = ""
 QString hostname;           // = "localhost"
 QString port;               // = "3306"

 m_LastError     = "";
 m_BaseLabel     = "";
 if (CGestIni::Param_ReadParam(  param.toAscii(), section.toAscii(), "Parametres", &driver, &dataBaseToConnect, &user, &password, &hostname, &port) !=0 )  // zero = pas d'erreur
    { m_LastError = tr("C_BaseCommon::BaseConnect() : error in parameters : CGestIni::Param_ReadParam() may be : key 'Parametres' omitted in section 'Connexion'");
      if (errMess) *errMess = m_LastError;
      outMessage( m_LastError);
      return 0;
    }
 if (dataBase.length()) dataBaseToConnect = dataBase; // si le nom de la base de donnees a laquelle se connecter est precisee, alor on le prend au lieu de celui des parametres ini
 int timeToReconnect =  DB_TIME_TO_RECONNECT;
 QString value       = "";
 if (CGestIni::Param_ReadParam(  param.toAscii(), "Connexion", "TimeToReconnect", &value) ==0 )  // zero = pas d'erreur
    { timeToReconnect = value.toInt();
    }
 return BaseConnect(baseLabel,
                    driver,
                    dataBaseToConnect,
                    user ,
                    password ,
                    hostname ,
                    port.toInt(),
                    timeToReconnect,
                    errMess);
}

 //---------------------------------------- BaseConnect -------------------------------------------------------
 bool C_BaseCommon::BaseConnect(const QString &baseLabel,    // 0
                                const QString &driver,       // 1
                                const QString &dataBase,     // 2
                                const QString &user ,        // 3
                                const QString &_password ,   // 4
                                const QString &hostname ,    // 5
                                int port,                    // 6
                                int timeToReconnect /* = DB_TIME_TO_RECONNECT */,
                                QString* errMess    /* = 0*/)
 {
  QString password = _password;
  if (password.startsWith('#'))   password = CGestIni::PassWordDecode(password.mid(1));
  QSqlDatabase::removeDatabase (baseLabel);
  QSqlDatabase defaultDB  = QSqlDatabase::addDatabase(driver, baseLabel);
  defaultDB.setDatabaseName( dataBase );
  defaultDB.setUserName    ( user     );
  defaultDB.setPassword    ( password );
  defaultDB.setHostName    ( hostname );
  defaultDB.setPort        ( port     );

  if ( ! defaultDB.open() )
     { m_LastError = tr("C_BaseCommon::BaseConnect() : Failed to open database : ")    +
                         baseLabel   + " Driver : " +  QString(driver) + "  " +
                         QString(dataBase) + "\n" +
                         defaultDB.lastError().driverText() + "\n" + defaultDB.lastError().databaseText();
       if (errMess) *errMess = m_LastError;
       outMessage(m_LastError);
       return 0;
    }
  m_BaseLabel       = baseLabel;
  m_pReconnectTimer = new QTimer (this);
  if (m_pReconnectTimer)
     { m_pReconnectTimer->setInterval(timeToReconnect);
       m_pReconnectTimer->start();
       connect( m_pReconnectTimer, SIGNAL(timeout()), this, SLOT(Slot_ReconnectTimerDone()) );
     }
  return 1;
}

//-----------------------------------------------------  isThisTableExist -------------------------------------------
 /*! \brief database().tables(QSql::Tables ); return all tables of all databases not just the tables list
  * of our connected database. The way is to see if table selection is possible.
  *  \param  table_name the table name
  *  \return 1/all is ok 0/table not exists
  */
bool C_BaseCommon::isThisTableExist(const QString &table)
{   QSqlQuery query( database() );
    return query.exec( QString("SELECT 1 FROM %1  limit 0").arg(table));
}

//-----------------------------------------------------  tablesList -------------------------------------------
 /*! \brief database().tables(QSql::Tables ); return all tables of all databases not just the tables list
  *  of our connected database. The way is to see if table selection is possible. Its not very fast ...
  *  \return tablesList
  */
QStringList C_BaseCommon::tablesList()
{   QStringList tableList   = database().tables(QSql::Tables );
    QString     tableToTest = "";
    QStringList retList;
    QSqlQuery   query( database() );
    for (int i=0; i<tableList.size();++i)
        { tableToTest = tableList[i];
          if ( retList.indexOf(tableToTest) == -1 &&              // if another database has the same table name ...
               query.exec( QString("SELECT 1 FROM %1  limit 0 ").arg(tableToTest) )
             ) retList.append(tableToTest);
        }
    return retList;
}

//-----------------------------------------------------  setStatusWidget -------------------------------------------
void C_BaseCommon::setStatusWidget(QLabel *statusWidget)
{m_StatusWidget = statusWidget;
 statusWidget->setText("");
}
//-----------------------------------------------------  statusWidget -------------------------------------------
QLabel  *C_BaseCommon::statusWidget()
{return m_StatusWidget;
}
//-----------------------------------------------------  statusWidgetSetText -------------------------------------------
void C_BaseCommon::statusWidgetSetText(const QString & text)
{if (m_StatusWidget) m_StatusWidget->setText(text);
}

//-----------------------------------------------------  setProgressWidget -------------------------------------------
void C_BaseCommon::setProgressWidget(QProgressBar *pQProgressBar)
{m_pQProgressBar = pQProgressBar;
}
//-----------------------------------------------------  progressWidget -------------------------------------------
QProgressBar * C_BaseCommon::progressWidget()
{return m_pQProgressBar;
}


//-----------------------------------------------------  Slot_ReconnectTimerDone -------------------------------------------
void C_BaseCommon::Slot_ReconnectTimerDone()
{if (!database().isOpen()) database().open();
 QSqlQuery query(QString::null , database() );
 query.exec(DUMMY_TEST_SQL_COMMAND);
}

//---------------------------------------- database -------------------------------------------------------
QSqlDatabase C_BaseCommon::database()
{ return QSqlDatabase::database(m_BaseLabel);
}

//--------------------------- setLastError -----------------------------------------------------------
void        C_BaseCommon::setLastError(const QString &error){ m_LastError = error;}
//--------------------------- getLastError -----------------------------------------------------------
QString     C_BaseCommon::getLastError(){return m_LastError;}
//............ gestion des owner ......................
//--------------------------- ownerList -----------------------------------------------------------
QStringList C_BaseCommon::ownerList()   {return m_ownerList;}
//--------------------------- isInOwnerList -----------------------------------------------------------
bool        C_BaseCommon::isInOwnerList(const QString &owner) { return m_ownerList.indexOf(owner) != -1;}
//--------------------------- addOwner -----------------------------------------------------------
void        C_BaseCommon::addOwner     (const QString &owner) { if (m_ownerList.indexOf(owner)==-1) m_ownerList<<owner;}

//--------------------------- getLastPrimaryKey -----------------------------------------------------------
QString C_BaseCommon::getLastPrimaryKey( const QString &table, const QString &pk_field_name, const QString &uniqueValue /*=""*/ , const QString &fieldWhereIsUniqueValue /*=""*/)
{   QString   ret     ="";
    QString   requete ="";
    QSqlQuery query( database() );
    if (uniqueValue.length()==0||fieldWhereIsUniqueValue.length()==0)
       {requete = QString("SELECT LAST_INSERT_ID() FROM %1 WHERE %2  = LAST_INSERT_ID()").arg( table, pk_field_name );
       }
    else
       {requete = QString("SELECT %1 FROM %2 WHERE %3  = '%4'").arg(pk_field_name, table, fieldWhereIsUniqueValue, uniqueValue);
       }
    if ( !query.exec(requete) )
       {m_LastError = tr("\nERROR  : C_BaseCommon::getLastPrimaryKey() \n%1\nREQUEST : %2").arg(query.lastError().text(),requete).toAscii();
        outMessage(m_LastError);
        return QString::null;
       }
    if ( query.next() ) ret = query.value(0).toString();
    else                ret = QString::null;
    return ret;
}
//--------------------------- dropBase -----------------------------------------------------------
int C_BaseCommon::dropBase(const QString &baseName)
{QString requete = QString("DROP DATABASE IF EXISTS %1"  ).arg(baseName);
 QSqlQuery query(QString::null , database() );
 if (!query.exec(requete))
    {m_LastError = tr("\nERROR  : C_BaseCommon::dropBase() \n%1\nREQUEST : %2").arg(query.lastError().text(),requete).toAscii();
     outMessage(m_LastError);
     return 0;
    }
 return 1;
}

//--------------------------- createBase -----------------------------------------------------------
int C_BaseCommon::createBase(const QString &baseName, int createMode /* = C_BaseCommon::OnlyIfNotExits */)
{   QSqlQuery query(QString::null , database() );
    QString requete = "";
    if (createMode== C_BaseCommon::OnlyIfNotExits )
       { requete = QString("CREATE DATABASE IF NOT EXISTS %1").arg(baseName);
       }
    else
       {requete = QString("DROP DATABASE   %1\n"
                          "CREATE DATABASE %1").arg(baseName);
       }
 if (!query.exec(requete))
    {m_LastError = tr("\nERROR  : C_BaseCommon::createBase() \n%1\nREQUEST : %2").arg(query.lastError().text(), requete).toAscii();
     outMessage(m_LastError);
     //CGestIni::Param_UpdateToDisk("/home/ro/sql.txt",tmp_schema);
     return 0;
    }
 return 1;
}

//--------------------------- dropTable -----------------------------------------------------------
int C_BaseCommon::dropTable(const QString &tableName)
{QString requete = QString("DROP TABLE IF EXISTS `%1`"  ).arg(tableName);
 QSqlQuery query(QString::null , database() );
 if (!query.exec(requete))
    {m_LastError = tr("\nERROR  : C_BaseCommon::dropTable() \n%1\nREQUEST : %2").arg(query.lastError().text(),requete).toAscii();
     outMessage(m_LastError);
     return 0;
    }
 return 1;
}

//--------------------------- createTable -----------------------------------------------------------
int C_BaseCommon::createTable(const QString &schema)
{QSqlQuery query(QString::null , database() );
 QString tmp_schema = schema;

 #ifdef SQLSYNTAX_MYSQL
         tmp_schema += "ENGINE = MyISAM ";
 #endif

 if ( !query.exec(schema) )
    { m_LastError = tr("\nERROR  : C_BaseCommon::createTable() \n%1\nREQUEST : %2").arg(query.lastError().text(), tmp_schema).toAscii();
      outMessage(m_LastError);
      //CGestIni::Param_UpdateToDisk("/home/ro/sql.txt",tmp_schema);
      return 0;
    }
 return 1;
}


//-----------------------------------------------------  executeSQL -------------------------------------------
/*! \brief  execute SQL instructions file
*   \param  const QString &fname                nom du fichier SQL � interpreter
*   \param  QProgressBar *pQProgressBar         barre de progression si besoin
*   \param  QTextEdit *pLogWidget               fenetre de log
*   \return
*/

void  C_BaseCommon::executeSQL( const QString &fname, QProgressBar *pQProgressBar /* = 0 */, QTextEdit *logWidget /* = 0 */)
{//....................... ouvrir le fichier en mode QTextStream ...........................
    if ( !QFile::exists( fname ) )            return;
    QFile file( fname );
    if ( !file.open( QIODevice::ReadOnly  ) ) return;
    if (pQProgressBar)
       {pQProgressBar->setValue(0);
        pQProgressBar->setRange(0,(int)(file.size()/1000));
       }
    long           nbMax  = 9000000;              //
    char          *buffer = new char[nbMax+5];    // +5 pour permettre analyse utf8 qui explore trois apres
    //.......... on d�clare une variable pour lire le fichier ligne � ligne ..................
    QString requete       = "";
    QString line          = "";
    QString table         = "";
    m_LineNum             = 0;
    m_position            = 0;
    QSqlQuery query(QString::null, database());
    while (!file.atEnd())

    {
        m_position += readLine(&file, buffer, line, nbMax); ++m_LineNum;
        if (pQProgressBar)  {pQProgressBar->setValue(m_position/1000); qApp->processEvents();qApp->processEvents();}
        //.................creation de la table .....................
        if (line.left(12)=="CREATE TABLE")
        {   int pos_deb          = 12;
            int pos              = line.indexOf("EXISTS",12);
            if (pos!=-1) pos_deb = pos + 6;
            pos = line.indexOf("(",pos_deb);
            if ( pos != -1 )
               {table   = line.mid(pos_deb, pos-pos_deb).trimmed();
                requete = QString("DROP TABLE IF EXISTS %1;").arg(table);
                query.exec( requete );
                outSQL_error(query, ("<font color=#ff0000><b>"+tr("ERROR:")+ "ParseSQL_Dump() </b></font>"), requete, __FILE__, __LINE__  );
                outMessage((tr("Creating table")+ "'<font color=#01eaff><b>%1</b></font>'....").arg( table)) ;
               }
            requete = line;
            while (!file.atEnd())
            {   m_position += readLine(&file, buffer, line, nbMax);   ++m_LineNum;
                line.remove("USING BTREE");
                if (pQProgressBar)  {pQProgressBar->setValue(m_position/1000); qApp->processEvents();qApp->processEvents();}
                if (line[0]==')' && (line[2]=='T' || line[2]=='E'))
                   {   if (line.left(7) == ") TYPE=" || line.left(9) == ") ENGINE=" )  // ne surtout pas inclure ';' dans la comparaison
                          {requete += ");";    // requete += ") ENGINE=MyISAM;";
                           requete.remove ("collate utf8_unicode_ci");
                           requete.remove ("collate utf8_bin");
                           requete.remove ("character set utf8");
                           query.exec(requete);
                           outSQL_error(query, "<font color=#ff0000><b> "+tr("ERROR:")+" parseSQL_Dump()</b></font>", requete ,__FILE__, __LINE__);
                           break;
                          }
                   }
               requete += line;
            } //endwhile (!file.atEnd())
        }
// INSERT INTO `RubriquesHead` VALUES (1,'30DC82DD-7632-2C46-9DC3-BC1AC0ECD20A',20030000,'Asthme sai','2004-12-08 19:23:41','admin',0,0);
// INSERT INTO `RubriquesHead` VALUES (2,'30DC82DD-7632-2C46-9DC3-BC1AC0ECD20A',20020200,'Bilan labo complet','2004-12-08 19:23:41','admin',0,0);
// INSERT INTO `ACCES2` VALUES ('A','� foyer ouvert'),('A','par ... abord '),('A','par dissection ...');
// INSERT INTO `codes_postaux` (`id`,`code_postal`,`ville`) VALUES
//  (26662,62153,'ABLAIN ST NAZAIRE'),
//  (35076,80320,'ABLAINCOURT PRESSOIR');
// INSERT INTO `BDM_CIP` (`CIP`, `CIP7`, `CIP_UCD`, `NATURE`, `NOM_COURT`, `INDIC_COND`, `DEBUT_REMB`, `FIN_REMB`, `CODE_LISTE`, `CODE_FORME`, `FORME`, `CODE_CPLT`, `CPLT_FORME`, `DOSAGE_SA`, `UNITE_SA`, `NB_UNITES`, `CODE_ATC`, `CLASSE_ATC`, `CODE_EPH`, `CLASSE_EPH`, `LABO`, `NOM_LONG1`, `NOM_LONG2`, `DATE_EFFET`, `SEUIL_ALER`, `SEUIL_REJE`, `PRESC_REST`, `EXCEPTIONS`, `TYPE`, `SEXE`, `INTERACT`, `PIH`, `PECP`) VALUES
// ('3400930000649', '3000064', '9000059', 'A', 'A 313 50 000 UI CAPSULE 30', '**', '1962-03-22', '0000-00-00', 1, '9', 'CAPSULE MOLLE', '320', 'CAPSULE MOLLE ORAL(E)', '50000', 'UI', '30', 'A11CA01', 'RETINOL (VIT A)', 'A11C1', 'VITAMINE A', 'PHARMA DEVELOPPEMENT', 'A 313 50 000 UI (VITAMINE A SYNTHETIQUE) 1 BOITE DE 30, CAPSULES MOLLES', '', '1999-03-02', 9, 21, 'N', 'N', '', 0, 0, '00', '00'),

        else if (line.left(11)=="INSERT INTO")
        {
            //............ isoler le verbe .................................................................
            int len_line;
            requete   = "";
            //..................... isoler les donn�es � inserer de toutes les donnees INSERT............................................
            //                      (aller jusqu'au ');' de fin
            do      {
                       len_line = line.length();
                       if (len_line>2)
                          { while (line[len_line-1]=='\r' || line[len_line-1]=='\n')
                                  {--len_line;
                                  }
                            if (line[len_line-2]==')' && line[len_line-1]==';')
                               { requete += line;
                                 parseSQL_InsertInto(requete, logWidget );
                                 break;
                               }
                          }
                       requete    += line;
                       m_position += readLine(&file, buffer, line, nbMax);   ++m_LineNum;
                       if (pQProgressBar) {pQProgressBar->setValue(m_position/1000); qApp->processEvents();qApp->processEvents();}
                    } while (!file.atEnd());
        }
    }
 delete buffer;
}
//-----------------------------------------------------  ParseSQL_InsertInto -------------------------------------------
// INSERT INTO `RubriquesHead` VALUES (1,'30DC82DD-7632-2C46-9DC3-BC1AC0ECD20A',20030000,'Asthme sai','2004-12-08 19:23:41','admin',0,0);
// INSERT INTO `RubriquesHead` VALUES (2,'30DC82DD-7632-2C46-9DC3-BC1AC0ECD20A',20020200,'Bilan labo complet','2004-12-08 19:23:41','admin',0,0);
// INSERT INTO `ACCES2` VALUES ('A','? foyer ouvert'),('A','par ... abord'),('A','par dissection ...');
// INSERT INTO `codes_postaux` (`id`,`code_postal`,`ville`) VALUES
//  (26662,62153,'ABLAIN ST NAZAIRE'),
//  (35076,80320,'ABLAINCOURT PRESSOIR');
void  C_BaseCommon::parseSQL_InsertInto(QString &text, QTextEdit */* logWidget  = 0 */)
{   int i, textLen;
    int len_sep       = 0;
    int deb           = text.indexOf("INSERT INTO");
    int pos           = text.indexOf("VALUES");
    QSqlQuery query(QString::null, database());
    if (pos ==-1 || deb==-1)
//       { outMessage(QObject::tr("    <font color=#ff0000><b>Syntax Error  line : %1 INSERT INTO VALUES : ParseSQL_InsertInto() INSERT INTO or VALUES not found </b></font>").arg(QString::number(m_LineNum)));
//       { outMessage(QObject::("    <font color=#ff0000><b>"+tr("Syntax Error  line : ")+"%1 INSERT INTO VALUES : ParseSQL_InsertInto() INSERT INTO or VALUES"+tr(" not found")+ "</b></font>").arg(QString::number(m_LineNum)));
       { outMessage(QObject::tr("    <font color=#ff0000><b>Syntax Error  line : %1 INSERT INTO VALUES : ParseSQL_InsertInto() INSERT INTO or VALUES not found</b></font>").arg(QString::number(m_LineNum)));
          return;
       }
    //............ isoler le verbe .................................................................
    pos         += 6;
    QString verb = text.mid(deb, pos-deb)+" ";  // "INSERT INTO `ACCES2` VALUES "
    //............ parser le reste pour les valeurs ................................................
    long end = -1;
    bool run = TRUE;
    //...................... se mettre sur premiere parenthese de donnees ........................................
    deb      = text.indexOf("(", pos);
    if ( deb==-1)
//       { outMessage(QObject::("    <font color=#ff0000><b>"+tr("Syntax Error  line: ")+"%1 INSERT INTO VALUES : start ')'  "+tr("not found")+"</b></font>").arg(QString::number(m_LineNum)));
       { outMessage(QObject::tr("    <font color=#ff0000><b>Syntax Error  line: %1 INSERT INTO VALUES : start ')'  not found</b></font>").arg(QString::number(m_LineNum)));
         return;
       }
    //....................... parser ................................................
    while (run)
    {
        end = C_Utils_Log::findNextSep(text, deb, "),");               //==> chercher fin d'un bloc de donnees par le separateur '),'
        if (end != -1)                                    // si trouve '),' chercher si "(" suit immediatement (virer les \r \n \t ' ') jusqu'a le rencontrer
           {len_sep = 0;
            i       = end + 2;
            textLen = text.length();
            while (i<textLen && ( text[i]==' '||text[i]=='\r'||text[i]=='\n'||text[i]=='\t') )++i;
            if (i>=textLen || text[i]!='(')              //  '),' trouve sans rencontrer le "("
//               { outMessage( QObject::"    <font color=#ff0000><b>"+tr("Syntax Error  line: ")+"%1 INSERT INTO VALUES : "+tr("start '),' present but end '(' not found")+ "</b></font>".arg(QString::number(m_LineNum)));
               { outMessage( QObject::tr("    <font color=#ff0000><b>Syntax Error  line: %1 INSERT INTO VALUES : start '),' present but end '(' not found</b></font>").arg(QString::number(m_LineNum)));
                 return;
               }
            else
               { len_sep = (i-end);
               }
           }
        if (end==-1)                                      //==> si pas trouve chercher derniere insertion ");"
           {   end = C_Utils_Log::findNextSep(text, deb, ");");
               if (end==-1)
//                  { outMessage( "    <font color=#ff0000><b>"+tr("Syntax Error  line: ")+"%1 INSERT INTO VALUES : "+tr("start  '),' and end ');' not found")+"</b></font>".arg(QString::number(m_LineNum)));
                  { outMessage(tr( "    <font color=#ff0000><b>Syntax Error  line: %1 INSERT INTO VALUES : start  '),' and end ');' not found</b></font>").arg(QString::number(m_LineNum)));
                    return;
                  }
               else
                  { run = FALSE;
                  }
           }
        //........................ si donnees valide les inserer ...................................................
        if (end!=-1)
           {   QString requete = verb + text.mid(deb, end-deb+1);
               query.exec(requete);
               outSQL_error(query, tr("<font color=#ff0000><b>ERROR : parseSQL_Dump() line %1 </b></font>").arg(QString::number(m_LineNum)), requete , __FILE__, __LINE__);
               if (run) deb = end + len_sep;
           }
    } //end while (run)
}

//-----------------------------------------------------  readLine -------------------------------------------
unsigned long  C_BaseCommon::readLine(QFile *pQFile, char *buffer, QString &outParam, unsigned long nbMax)
{
         unsigned long nb                              =  pQFile->readLine(buffer, nbMax);
         buffer[nb]                                    =  0;
         if (CGestIni::IsUtf8(buffer))     outParam    =  QString::fromUtf8 ( buffer ) ;
         else                              outParam    =  buffer;
         return nb;
}


//--------------------------- isThisValueLikeInTable -----------------------------------------------------------
QString  C_BaseCommon::isThisValueLikeInTable(const QString &tableName, const QString &fieldName, const QString &value, const QString fieldToRetrieve /* = "" */, const QString &wand /* = "" */)
{QSqlQuery query(QString::null , database() );
 QString field    = fieldToRetrieve; if (field.length()==0) field = tableName+"_pk";
 QString requete  = QString("SELECT `%1` FROM `%2` WHERE `%3`  LIKE ").arg( field, tableName, fieldName)+"'%" +value+"%'";
 addOwnerWandMention(requete, tableName, wand);

 if (!query.exec(requete))
    {m_LastError = tr("\nERROR: C_BaseCommon::isThisValueLikeInTable_ToPk( \n%1\nREQUEST: %2").arg(query.lastError().text(),requete).toAscii();
     outMessage(m_LastError);
     return QString::null;
    }
 if ( query.next() ) return query.value(0).toString();
 else                return QString::null;
}

//--------------------------- isThisValueLikeInTable_ToList -----------------------------------------------------------
QStringList  C_BaseCommon::isThisValueLikeInTable_ToList(const QString &tableName, const QString &fieldName, const QString &value, const QString fieldToRetrieve /* = "" */, const QString &wand /* = "" */ )
{QSqlQuery query(QString::null , database() );
 QString field    = fieldToRetrieve; if (field.length()==0) field = tableName + "_pk";
 QString requete  = QString("SELECT `%1` FROM `%2` WHERE `%3`  LIKE ").arg( field, tableName, fieldName)+"'%" +value+"%'";
 addOwnerWandMention(requete, tableName, wand);
 QStringList list;
 if (!query.exec(requete))
    {m_LastError = tr("\nERROR: C_BaseCommon::isThisValueLikeInTable_ToPkList() \n%1\nREQUEST: %2").arg(query.lastError().text(),requete).toAscii();
     outMessage(m_LastError);
     return list;
    }
 if (query.isActive())
    {while (query.next()) list << query.value(0).toString();
    }
 return list;
}
//--------------------------- isThisValueInTable -----------------------------------------------------------
QString C_BaseCommon::isThisValueInTable(const QString &tableName, const QString &fieldToTest, const QString &test_value, const QString fieldToRetrieve /* = "" */, const QString &wand /* = "" */)
{
 QSqlQuery query(QString::null , database() );
 QString field    = fieldToRetrieve; if (field.length()==0) field = tableName+"_pk";
 QString requete  = QString("SELECT `%1` FROM `%2` WHERE `%3`  = \"%4\"").arg( field, tableName, fieldToTest, test_value );
 addOwnerWandMention(requete, tableName, wand);
 if (!query.exec(requete))
    {m_LastError = tr("\nERROR: C_BaseCommon::isThisValueInTable( \n%1\nREQUEST: %2").arg(query.lastError().text(),requete).toAscii();
     outMessage(m_LastError);
     return QString::null;
    }
 if ( query.next() ) return query.value(0).toString();
 else                return QString::null;

}
//--------------------------- addOwnerWandMention -----------------------------------------------------------
QString C_BaseCommon::addOwnerWandMention(QString &requete, const QString &tableName, const QString &wand)
{ if (wand.length())
    {if (wand.startsWith("NO-OWNER-FILTER"))
        {requete += wand.mid(15);
        }
     else
        {requete += wand;
         requete += ownersSelectMention(tableName);
        }
    }
 else
   { requete += ownersSelectMention(tableName);
   }
 return requete;
}

//--------------------------- isThisValueInTable_ToList -----------------------------------------------------------
QStringList C_BaseCommon::isThisValueInTable_ToList(const QString &tableName, const QString &fieldName, const QString &value, const QString fieldToRetrieve /* = "" */, int keepEmpty /* = 1 */, const QString &wand /* = "" */)
{QSqlQuery query(QString::null , database() );
 QString            field    = fieldToRetrieve; if (field.length()==0) field = tableName+"_pk";
 QString            requete  = QString("SELECT `%1` FROM `%2` WHERE `%3`  = \"%4\"").arg( field, tableName, fieldName, value );
 addOwnerWandMention(requete, tableName, wand);
 QStringList list;
 if (!query.exec(requete))
    {m_LastError = tr("\nERROR: C_BaseCommon::isThisValueLikeInTable_ToPkList() \n%1\nREQUEST: %2").arg(query.lastError().text(),requete).toAscii();
     outMessage(m_LastError);
     return list;
    }
 if (query.isActive())
    {if (keepEmpty)
        {while (query.next()) list << query.value(0).toString();
        }
     else
         {while (query.next())
                {QString value = query.value(0).toString().trimmed();
                 if (value.length()) list <<  value;
                }
         }
    }
 return list;
}
//--------------------------- updateValueInTable -----------------------------------------------------------
bool C_BaseCommon::updateValueInTable(const QString &tableName, const QString &fieldToUpdate, const QString &value, const QString &valueToTest, const QString &fieldToTest /* = ""*/ )
{QSqlQuery query( database() );
 QString field_test = fieldToTest; if (field_test.length()==0) field_test = tableName + "_pk";
 QString prepare  = "UPDATE ";
 prepare         +=  tableName                + " SET \n";
 prepare         +=  fieldToUpdate            + " =?  \n";
 prepare         += " WHERE "   + field_test  + " ='"  + valueToTest  + "'";

 if (!query.prepare(prepare))
    {outSQL_error( query, tr("ERROR: C_BaseCommon::updateValueInTable() prepare"), prepare, __FILE__, __LINE__);
     return FALSE;
    }
 query.bindValue(0, value);
 if (!query.exec())
    {outSQL_error( query, tr("ERROR: C_BaseCommon::updateValueInTable() exec"), prepare, __FILE__, __LINE__);
     return FALSE;
    }
 return TRUE;
}

//--------------------------- deleteRecordInTable -----------------------------------------------------------
bool C_BaseCommon::deleteRecordInTable(const QString &tableName, const QString &valueToTest, const QString &fieldToTest  /*=""*/ )
{QSqlQuery query( database() );
 QString field_test = fieldToTest; if (field_test.length()==0) field_test = tableName + "_pk";
 QString requete    = QString("DELETE FROM %1 WHERE %2='%3' ").arg(tableName, field_test, valueToTest);

 if (!query.exec(requete))
    {outSQL_error( query, tr("ERROR: C_BaseCommon::deleteRecordInTable() "), requete, __FILE__, __LINE__);
     return FALSE;
    }
 return TRUE;
}

//--------------------------- ownersSelectMention -----------------------------------------------------------
QString C_BaseCommon::ownersSelectMention( const QString &tableName, C_BaseCommon::flags flags/*= C_BaseCommon::WhereAlreadyIn*/)
{QString str = "";
 int      nb = m_ownerList.size(); if (nb==0) return str;
 if (flags == C_BaseCommon::WhereAlreadyIn) str        += " AND   (";
 else                                       str        += " WHERE (";
 for (int i=0; i<nb; ++i)
     {if (i==0) str += QString("    `%1_owner`=\"%2\"").arg(tableName, m_ownerList[i]);
      else      str += QString(" OR `%1_owner`=\"%2\"").arg(tableName, m_ownerList[i]);
     }
 str        += " )";
 return str;
}
//--------------------------- countRecords -----------------------------------------------------------
long C_BaseCommon::countRecords(const QString & tableName, const QString &whereMention /* = "" */)
{QString requete = QString("SELECT COUNT(*) FROM %1 %2").arg(tableName, whereMention);
 QSqlQuery query(requete , database() );
 outSQL_error(query, tr("<font color=#ff0000><b>ERROR: C_BaseCommon::countRecords() </b></font>"), requete, __FILE__, __LINE__  );
   if (query.isActive() && query.next())
      {return (long) query.value(0).toDouble();
      }
 return 0;
}

//--------------------------- eraseTable -----------------------------------------------------------
int C_BaseCommon::eraseTable(const QString &tableName)
{QString requete = QString("DELETE FROM %1").arg(tableName);
 QSqlQuery query(QString::null , database() );
 if (!query.exec(requete))
    {m_LastError = tr("\nERROR: C_BaseCommon::eraseTable() \n%1\nREQUEST: %2").arg(query.lastError().text(),requete).toAscii();
     outMessage(m_LastError);
     return 0;
    }
 return 1;
}

//--------------------------- posFirstNonSpace -----------------------------------------------------------
int C_BaseCommon::posFirstNonSpace(const QString &line)
{int nb = line.length();
 for (int i=0; i<nb;++i)
     {if (line[i] != ' ') return i;
     }
 return -1;
}

//--------------------------- posLastEnclosedSymbol -----------------------------------------------------------
int C_BaseCommon::posLastEnclosedSymbol(const QString &str, const QString &symbolOuvrant, const QString &symbolFermant, int *posFermant_out /*=0*/)
{int pos        = str.length();
 int posOuvrant = -1;
 //int posFermant = -1;
 int isIn       = 0;
 int lenOuvrant = symbolOuvrant.length();
 int lenFermant = symbolFermant.length();
 if (posFermant_out) *posFermant_out = -1;
 if (pos==0)     return -1;

 do
    {--pos;
     if      (str.mid(pos,lenFermant)==symbolFermant)
             {if (posFermant_out && isIn==0) *posFermant_out = pos;
              ++isIn;
             }
     else if (str.mid(pos,lenOuvrant)==symbolOuvrant)
             {--isIn;
              posOuvrant = pos;
             }
     if (posOuvrant != -1 && isIn<=0) break;
    } while (pos);
 return posOuvrant;
}

//-----------------------------------------------------  GUID_Create --------------------------------------------------
QString C_BaseCommon::GUID_Create()
{
    if (get_GUID_CreateMode()==C_BaseCommon::byQT)
       {QString guid ( QUuid::createUuid ().toString());
        return  guid.mid(1, 36);
       }
    else
       {
        return C_MyUuid::create();     // version personnelle de creation du GUID car celle de QT buguee? sur certaines plateformes
       }
}

//-----------------------------------------------------  get_GUID_CreateMode --------------------------------------------------
C_BaseCommon::GUID_Mode C_BaseCommon::get_GUID_CreateMode()
{return  m_GUID_CreateMode;
}

