 /*********************************** CMoteurAgenda.cpp ********************
 *  #include "CMoteurAgenda.h"           QT4-ready                         *
 * ........................................................................*
 *   Project   :  MedinTux  (typographie made in france)                   *
 *   Copyright :  (C) 2005-2006-2007-2008-2009-2010 and for the eternity   *
 *   by        :  Sevin Roland     from   MedinTux project                 *
 *   E-Mail    :  roland-sevin@medintux.org                                *
 *   Web site  :  www.medintux.org                                         *
 * ........................................................................*
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "CMoteurAgenda.h"
#include "../../MedinTuxTools-QT4/CGestIni.h"
#include "C_Dlg_Agenda.h"

#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QTimer>
#include <QSqlTableModel>
#include <QDebug>

//#define TR QObject::tr

//=============================================== INCLUDES ===================================================================
//=============================================== IMPLEMENTATION =============================================================
//-----------------------------------------------------  CMoteurAgenda -------------------------------------------
CMoteurAgenda::CMoteurAgenda(const QString &driver,        // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
                             const QString &DataBaseName,  // nom de la base: si QODBC3 -> nom de la source de données (userDSN)
                             const QString &user,          // = "root"
                             const QString &password,      // = ""
                             const QString &hostname,
                             const QString &port,
                             const char    *confFile,
                             const QString &baseLabel,
                             QString*       errMess,
                             QObject*    parent
                            )
 : QObject(parent)
{ m_IsValid         = 0;
  m_pReconnectTimer = 0;
  m_ModifConfirm    = 0;
  m_Representation  = 0;
  //m_log             = "";
  initBase   ( driver,        // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
               DataBaseName,  // nom de la base: si QODBC3 -> nom de la source de données (userDSN)
               user,          // = "root"
               password,      // = ""
               hostname,
               port,
               confFile,
               baseLabel,
               errMess);
  SetDaysHeight();
  SetMinDaysHeight();
  SetSpaceBetwenDays();
}

//-----------------------------------------------------  initBase -------------------------------------------
void CMoteurAgenda::initBase   (const QString &driver,        // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
                                const QString &DataBaseName,  // nom de la base: si QODBC3 -> nom de la source de données (userDSN)
                                const QString &user,          // = "root"
                                const QString &password,      // = ""
                                const QString &hostname,
                                const QString &port,
                                const char* confFile,
                                const QString &baseLabel,
                                QString*    errMess)
{ int ret;
  QString mess;

  //................ configurer la classe .............................................
  if (confFile==0)                 {ret = 0; qDebug() << mess.toLatin1() + "\r\n ConfFile not found: " ;}
  else if (confFile[0]==0)         {ret = 0; qDebug() << mess.toLatin1() + "\r\n ConfFile empty: "   ;}
  else                             {ret = SetConfBase(confFile, &mess);          }

  if (ret==0)
     {qDebug()<<mess.toLatin1();
      if (errMess) *errMess = mess;
      return;
     }

   m_IsValid =  BaseConnect(  driver,        // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
                              DataBaseName,  // nom de la base: si QODBC3 -> nom de la source de données (userDSN)
                              user,          // = "root"
                              password,      // = ""
                              hostname,      // = "localhost"
                              port,          // = 3306
                              errMess,
                              baseLabel);
  if (m_IsValid)
     {m_pReconnectTimer       = new QTimer(this);
      if (m_pReconnectTimer)
         {m_pReconnectTimer->start (DB_TIME_TO_RECONNECT);
          connect( m_pReconnectTimer, SIGNAL(timeout()), this, SLOT(On_ReconnectTimerDone()) );
         }
      }
}


//-----------------------------------------------------  OpenBase -------------------------------------------
int   CMoteurAgenda::OpenBase()
{return 1;
}
//-----------------------------------------------------  CloseBase -------------------------------------------
void   CMoteurAgenda::CloseBase()
{return;
}

//-----------------------------------------------------  On_ReconnectTimerDone -------------------------------------------
void CMoteurAgenda::On_ReconnectTimerDone()
{QSqlDatabase::database(m_BaseLabel).close();
 QSqlDatabase::database(m_BaseLabel).open();

 OpenBase();
 QSqlQuery query(QString::null , QSqlDatabase::database(m_BaseLabel) );
 query.exec(DUMMY_TEST_SQL_COMMAND);
 CloseBase();
}

//-----------------------------------------------------  ~CMoteurAgenda -------------------------------------------
CMoteurAgenda::~CMoteurAgenda()
{if (m_pReconnectTimer)
    {m_pReconnectTimer->stop();
     disconnect( m_pReconnectTimer, SIGNAL(timeout()), this, SLOT(On_ReconnectTimerDone()) );
    }
 QSqlDatabase::database( m_BaseLabel ).close();
 QSqlDatabase::removeDatabase (m_BaseLabel);
}

//-----------------------------------------------------  BaseConnect -------------------------------------------
int    CMoteurAgenda::BaseConnect        (const QString &driver,        // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
                                          const QString &DataBaseName,  // nom de la base: si QODBC3 -> nom de la source de données (userDSN)
                                          const QString &user,          // = "root"
                                          const QString &pasword,       // = ""
                                          const QString &hostname,      // = "localhost"
                                          const QString &port,          // = "port"
                                          QString*       errMess,
                                          const QString &baseLabel)
    {   QSqlDatabase defaultDB;
        m_BaseLabel = baseLabel;
        if ( QSqlDatabase::contains(m_BaseLabel) )
           { QSqlDatabase::database(m_BaseLabel).close();
             QSqlDatabase::removeDatabase (m_BaseLabel);
           }
        defaultDB  = QSqlDatabase::addDatabase(driver, baseLabel);
        defaultDB.setDatabaseName( DataBaseName );
        defaultDB.setUserName(     user );
        defaultDB.setPassword(     pasword );
        defaultDB.setHostName(     hostname);
        defaultDB.setPort(         port.toInt());
        if ( ! defaultDB.open() )
           {QString qstr = "";
            qstr += tr("Failed to open database: ") + QString(driver) + "  " + QString(DataBaseName) + "\r\n" +
                     defaultDB.lastError().driverText() + "\r\n" + defaultDB.lastError().databaseText();
            qWarning()<<qstr.toLatin1();
            if (errMess) *errMess = qstr;
            return 0;
           }
        return 1;
    }

//-----------------------------------------------------  SetConfBase -------------------------------------------
int CMoteurAgenda::SetConfBase(const char* confFile, QString *errMess)
{
  QString  err = "";
  char    *deb = (char*) confFile;
  char     *pt = (char*) confFile;
  int     line = 0;

  pt = SetConfBase_SetProperties(deb, m_AGENDA_TBL_NAME,   "m_AGENDA_TBL_NAME",  &line , err); if (err.length())     goto SetConfBase_Error;  // non de la table DU FICHIER GENERAL D'INDEX DES DOSSIERS
  pt = SetConfBase_SetProperties(pt,  m_AGENDA_DATETIME,   "m_AGENDA_DATETIME",  &line , err); if (err.length())     goto SetConfBase_Error;  // date et heure du RDV
  pt = SetConfBase_SetProperties(pt,  m_AGENDA_DUREE,      "m_AGENDA_DUREE",     &line , err); if (err.length())     goto SetConfBase_Error;  // duree (en minutes)  RDV
  pt = SetConfBase_SetProperties(pt,  m_AGENDA_GUID,       "m_AGENDA_GUID",      &line , err); if (err.length())     goto SetConfBase_Error;  // un champ GUID unique qualifiant le numero de dossier du patient ayant ce RDV (si déj�  connu)
  pt = SetConfBase_SetProperties(pt,  m_AGENDA_NOM,        "m_AGENDA_NOM",       &line , err); if (err.length())     goto SetConfBase_Error;  // un champ NOM   qualifiant le nom du dossier
  pt = SetConfBase_SetProperties(pt,  m_AGENDA_PRENOM,     "m_AGENDA_PRENOM",    &line , err); if (err.length())     goto SetConfBase_Error;  // un champ PRENOM   qualifiant le prenom du dossier
  pt = SetConfBase_SetProperties(pt,  m_AGENDA_TEL,        "m_AGENDA_TEL",       &line , err); if (err.length())     goto SetConfBase_Error;  // téléphone (pour annuler)
  pt = SetConfBase_SetProperties(pt,  m_AGENDA_PRIS_PAR,   "m_AGENDA_PRIS_PAR",  &line , err); if (err.length())     goto SetConfBase_Error;  // Utilisateur du programme
  pt = SetConfBase_SetProperties(pt,  m_AGENDA_PRIS_AVEC,  "m_AGENDA_PRIS_AVEC", &line , err); if (err.length())     goto SetConfBase_Error;  // Médecin avec lequel le RDV a été pris
  pt = SetConfBase_SetProperties(pt,  m_AGENDA_TYPE,       "m_AGENDA_TYPE",      &line , err); if (err.length())     goto SetConfBase_Error;  // Type de RDV
  pt = SetConfBase_SetProperties(pt,  m_AGENDA_NOTE,       "m_AGENDA_NOTE",      &line , err); if (err.length())     goto SetConfBase_Error;  // Note
  pt = SetConfBase_SetProperties(pt,  m_AGENDA_PRIM_KEY,   "m_AGENDA_PRIM_KEY",  &line , err); if (err.length())     goto SetConfBase_Error;  // une clef primaire
  pt = SetConfBase_SetProperties(pt,  m_AGENDA_STATUS,     "m_AGENDA_STATUS",    &line , err); if (err.length())     goto SetConfBase_Error;  // etat du rendez vous
  pt = SetConfBase_SetProperties(pt,  m_AGENDA_WHERE,      "m_AGENDA_WHERE",     &line , err); if (err.length())     goto SetConfBase_Error;  // endroit du rendez vous

  pt = SetConfBase_SetProperties(deb, m_COLOR_PROFIL_TBL_NAME,    "m_COLOR_PROFIL_TBL_NAME",  &line , err); if (err.length())     goto SetConfBase_Error;
  pt = SetConfBase_SetProperties(pt,  m_COLOR_PROFIL_NAME,        "m_COLOR_PROFIL_NAME",      &line , err); if (err.length())     goto SetConfBase_Error;
  pt = SetConfBase_SetProperties(pt,  m_COLOR_PROFIL_COLOR,       "m_COLOR_PROFIL_COLOR",     &line , err); if (err.length())     goto SetConfBase_Error;
  pt = SetConfBase_SetProperties(pt,  m_COLOR_PROFIL_DUREE,       "m_COLOR_PROFIL_DUREE",     &line , err); if (err.length())     goto SetConfBase_Error;

  pt = SetConfBase_SetProperties(pt,  m_MASK_TBL_NAME,     "m_MASK_TBL_NAME",     &line , err); if (err.length())     goto SetConfBase_Error;
  pt = SetConfBase_SetProperties(pt,  m_MASK_PRIM_KEY,     "m_MASK_PRIM_KEY",     &line , err); if (err.length())     goto SetConfBase_Error;
  pt = SetConfBase_SetProperties(pt,  m_MASK_MOTIF,        "m_MASK_MOTIF",        &line , err); if (err.length())     goto SetConfBase_Error;
  pt = SetConfBase_SetProperties(pt,  m_MASK_TYPE,         "m_MASK_TYPE",         &line , err); if (err.length())     goto SetConfBase_Error;
  pt = SetConfBase_SetProperties(pt,  m_MASK_HEURE,        "m_MASK_HEURE",        &line , err); if (err.length())     goto SetConfBase_Error;
  pt = SetConfBase_SetProperties(pt,  m_MASK_DUREE,        "m_MASK_DUREE",        &line , err); if (err.length())     goto SetConfBase_Error;
  pt = SetConfBase_SetProperties(pt,  m_MASK_USER,         "m_MASK_USER",         &line , err); if (err.length())     goto SetConfBase_Error;
  pt = SetConfBase_SetProperties(pt,  m_MASK_DAYOFWEEK,    "m_MASK_DAYOFWEEK",    &line , err); if (err.length())     goto SetConfBase_Error;

  return 1;

SetConfBase_Error:
  if (errMess) *errMess = err;
  qDebug()<<err.toLatin1();
  return 0;

}

//--------------------------------------------- SetConfBase_SetProperties ------------------------------------------------
char  *CMoteurAgenda::SetConfBase_SetProperties(char *pt, QString &propertie, const char *token, int *line , QString &err)
{int nLine = *line;
 err  = "";
 long len_token = strlen (token);
 while(*pt)
    {SKIP_BLANK_CAR(pt);
     if (strncmp(pt, token, len_token)==0)
        {//return pt+len_token;
         pt         += len_token;
         err         = "";
         propertie   = "";
         //............. chercher premier delimiteur ...............................
          while(*pt && *pt!='\r' && *pt !='\n' && *pt !='\'' ) pt++;
          if (*pt=='\'')         // si delimiteur pas trouve erreur
             {pt++;               // passer le delimiteur
              char *end = pt;
              //............. chercher deuxiéme delimiteur ...............................
              while(*end && *end!='\r' && *end !='\n' && *end !='\'')end++;
              if (*end=='\'')
                 {propertie = QString::fromLatin1(pt, end-pt);
                  if (line) *line = nLine;
                  return end +1;
                 }
              else
                {err  = tr("Syntax Error: SetConfBaseGetValue()\r\n End delimiter \"'\"  not find at line N°: ");
                 err += QString::number(nLine);
                 if (line) *line = nLine;
                 return 0;
                }
             }
           else
             {err  = tr("Syntax Error: SetConfBaseGetValue()\r\n Start delimiter \"'\"  not find at line N°: ");
              err += QString::number(nLine);
              if (line) *line = nLine;
              return 0;
             }
        } //endif (strncmp(pt, token, len_token)==0)

     NEXT_LINE(pt);
     ++nLine;

    }
 err  = "Syntax Error: SetConfBase()\r\n";
 err += token;
 err += tr(" not found on line # ");
 err += QString::number(nLine);
 if (line) *line = nLine;
 return pt;
}

//--------------------------------------------- GotoDebug ------------------------------------------------
void CMoteurAgenda::GotoDebug()
{
}

//-------------------------------------- SetProportionnalDays ----------------------------------------------------------------------------
void  CMoteurAgenda::SetProportionnalDays(int val  /* = 15*/)
{m_ProportionnalHeight = val;
}
//-------------------------------------- GetProportionnalDays ----------------------------------------------------------------------------
int  CMoteurAgenda::GetProportionnalDays()
{return m_ProportionnalHeight;
}
//-------------------------------------- SetDaysHeight ----------------------------------------------------------------------------
void  CMoteurAgenda::SetDaysHeight(int val  /* = 15*/)
{m_DaysHeight = val;
}
//-------------------------------------- SetMinDaysHeight ----------------------------------------------------------------------------
void  CMoteurAgenda::SetMinDaysHeight(int val  /* = 15*/)
{m_MinDaysHeight = val;
}
//-------------------------------------- SetSpaceBetwenDays ----------------------------------------------------------------------------
void  CMoteurAgenda::SetSpaceBetwenDays(int val /* = 1*/)
{m_SpaceBetwenDays = val;
}
//-------------------------------------- GetDaysHeight ----------------------------------------------------------------------------
int  CMoteurAgenda::GetDaysHeight()
{return m_DaysHeight;
}
//-------------------------------------- GetMinDaysHeight ----------------------------------------------------------------------------
int  CMoteurAgenda::GetMinDaysHeight()
{return m_MinDaysHeight;
}
//-------------------------------------- GetSpaceBetwenDays ----------------------------------------------------------------------------
int  CMoteurAgenda::GetSpaceBetwenDays()
{return m_SpaceBetwenDays;
}

//-------------------------------------- makeNextPk ----------------------------------------------------------------------------
QString CMoteurAgenda::makeNextPk(const QString &tableName, const QString host,const QString &pkFieldName)
{ QString   requete  = "SELECT ";
            requete += pkFieldName + " FROM " + tableName + " WHERE Pk_Host = '" + host + "' AND ";
  QSqlQuery query(requete, QSqlDatabase::database(m_BaseLabel));
  return QString::null;
}

//-------------------------------------- MASK_Append ----------------------------------------------------------------------------
int CMoteurAgenda::MASK_Append(const C_RendezVous &rendezVous, QString *errMess /*=0*/)
{

  //................................. methode QSqlCursor .....................................
  //                         ne pose pas de PB avec valeur avec une apostrophe
  int ok  = FALSE;
  //............... ouvrir la base .......................................................
  if (OpenBase()==0) {if (errMess) *errMess = "CMoteurAgenda::MASK_Append(): database can't be opened";              return FALSE; }
  //............... crer un curseur SQL ..................................................
  QSqlQuery query(QSqlDatabase::database(m_BaseLabel));
  QString prepare  = "INSERT INTO ";
          prepare += m_MASK_TBL_NAME  + "(" +
                     m_MASK_HEURE     + "," + // 0
                     m_MASK_DUREE     + "," + // 1
                     m_MASK_USER      + "," + // 2
                     m_MASK_TYPE      + "," + // 3
                     m_MASK_MOTIF     + "," + // 4
                     m_MASK_DAYOFWEEK + ") VALUES (?,?,?,?,?,?)"; // 5

     query.prepare(prepare);
     query.bindValue(0, rendezVous.m_date.time());
     query.bindValue(1, (int)rendezVous.m_Duree);
     query.bindValue(2, rendezVous.m_PrisAvec);
     query.bindValue(3, rendezVous.m_Type);
     query.bindValue(4, rendezVous.m_Note);
     query.bindValue(5, rendezVous.m_date.date().dayOfWeek ());
     if (query.exec()) {ok = TRUE;}
     else              {QString mess = tr("Error : CMoteurAgenda::MASK_Append() \r\n") + prepare + "\r\n";
                        mess        += OutSQL_error(query, mess.toLatin1());      // rajouter le message sql
                        if (errMess) *errMess += mess;
                        ok = FALSE;
                       }
  CloseBase();
  return ok;
}

//--------------------------------------------- MASK_GetDay_RDV_List ------------------------------------------------
int CMoteurAgenda::MASK_GetDay_RDV_List(const QDate &date, const QString &user, RDV_LIST &rdvList, QString *errMess /*=0*/)
{ rdvList.clear();
  //................. ouvrir la base  ......................................................
  if (OpenBase()==0) {if (errMess) *errMess = "CMoteurAgenda::MASK_GetDay_RDV_List(): database can't be opened";              return 0; }
  //................. Preparer la requete ..................................................
  QString requete("");
  requete  += "SELECT " + m_MASK_HEURE        +  ","         // 0
                        + m_MASK_DUREE        +  ","         // 1
                        + m_MASK_USER         +  ","         // 2
                        + m_MASK_TYPE         +  ","         // 3
                        + m_MASK_MOTIF        +  ","         // 4
                        + m_MASK_DAYOFWEEK    +  ","         // 5
                        + m_MASK_PRIM_KEY     +  " FROM  "   // 10
                        + m_MASK_TBL_NAME     +  " WHERE "
                        + m_MASK_DAYOFWEEK    +  " = '" + QString::number(date.dayOfWeek()) +  "' AND "
                        + m_MASK_USER         +  " = '" + user                              + "' ORDER BY " + m_MASK_HEURE;
  int nb = 0;
  QSqlQuery query(requete , QSqlDatabase::database(m_BaseLabel) );
  //.................. si la requète a un resultat ..............................................
  if (query.isActive())
     { while (query.next())
             {
              rdvList.append(new C_RendezVous(QDateTime(date, query.value( 0 ).toTime()),   // date
                                              query.value( 1 ).toInt(),                     // duree
                                              "",                                           // nom       -> non utilise lors creation rdv par defaut
                                              "",                                           // prenom    -> non utilise lors creation rdv par defaut
                                              "",                                           // tel       -> non utilise lors creation rdv par defaut
                                              CGestIni::Utf8_Query(query, 4 ),              // note
                                              "",                                           // guid      -> non utilise lors creation rdv par defaut
                                              CGestIni::Utf8_Query(query, 2 ),              // prisAvec   (utilisateur signataire)
                                              "",                                           // prisPar   -> non utilise lors creation rdv par defaut
                                              CGestIni::Utf8_Query(query, 3 ),              // type
                                              ""                                            // primKey   -> non utilise lors creation rdv par defaut
                                           )
                            );
              ++ nb;
             } //end while (pSqlQuery->next())
     } //endif (query.isActive())
  CloseBase();
  return nb;
}

//-------------------------------------- MASK_DayDelete ----------------------------------------------------------------------------
int CMoteurAgenda::MASK_DayDelete( int dayOfWeek, const QString &user, QString *errMess /*=0*/)
{ //................. ouvrir la base  ......................................................
  if (OpenBase()==0) {if (errMess) *errMess = "CMoteurAgenda::MASK_DayDelete(): database can't be opened";              return FALSE; }
  //................. Preparer la requete ..................................................
  QString requete("DELETE FROM ");
          requete += m_MASK_TBL_NAME  + " WHERE "
                  +  m_MASK_USER      + "= '" + user                        + "' AND "
                  +  m_MASK_DAYOFWEEK + "= '" + QString::number(dayOfWeek)  + "'"  ;
  QSqlQuery query(QString::null , QSqlDatabase::database(m_BaseLabel) );
  query.exec(requete);
  //CloseBase();
  return TRUE;
}

//-------------------------------------- COL_Create ----------------------------------------------------------------------------
int CMoteurAgenda::COL_Create(const QString name, const QString color, const QString duree, QString *errMess /*=0*/)
{
  //................................. methode QSqlCursor .................................
  //                         ne pose pas de PB avec valeur avec une apostrophe
  int ok  = FALSE;
  //............... ouvrir la base .......................................................
  if (OpenBase()==0) {if (errMess) *errMess += "CMoteurAgenda::COL_Create(): database can't be opened";  return FALSE; }

  QSqlQuery query(QSqlDatabase::database(m_BaseLabel));
  QString prepare  = "INSERT INTO ";
          prepare += m_COLOR_PROFIL_TBL_NAME  + "(" +
                     m_COLOR_PROFIL_NAME      + "," +
                     m_COLOR_PROFIL_COLOR     + "," +
                     m_COLOR_PROFIL_DUREE     + ") VALUES (?,?,?)";

     query.prepare(prepare);
     query.bindValue(0, name);
     query.bindValue(1, color);
     query.bindValue(2, duree);
     if (query.exec()) {ok = TRUE;}
     else              {QString mess = tr("Error : CMoteurAgenda::COL_Create() \r\n") + prepare + "\r\n";
                        mess        += OutSQL_error(query, mess.toLatin1());      // rajouter le message sql
                        if (errMess) *errMess += mess;
                        ok = FALSE;
                       }
  /*
  //............... crer un curseur SQL ..................................................
  Q3SqlCursor cur(m_COLOR_PROFIL_TBL_NAME, TRUE, *m_DataBase);
  if ( !cur.canInsert ()) {CloseBase(); return FALSE;}
  //............... si OK on recupere le buffer et on le charge avec les données .........
  QSqlRecord *buffer = cur.primeInsert();                         // recuperer le buffer d'insertion
  buffer->setValue( m_COLOR_PROFIL_NAME,    name );
  buffer->setValue( m_COLOR_PROFIL_COLOR,   color );
  ok = cur.insert();                                          // ecrire le buffer avec les données
  //......................... fermer la base ..............................................
  */
  CloseBase();
  return ok;
}

//--------------------------------------------- COL_Get_List ------------------------------------------------
int CMoteurAgenda::COL_Get_List(MAP_COLOR &colorProfils, QString *errMess /*=0*/)
{ colorProfils.clear();
  //................. ouvrir la base  ......................................................
  //m_log  += "---------- CMoteurAgenda::COL_Get_List() requete  "+QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss")+ "------------------\r\n";
  if (OpenBase()==0) {if (errMess) *errMess = "CMoteurAgenda::COL_Get_List(): database can't be opened";              return 0; }
  //................. Preparer la requete ..................................................
  QString key     = "";
  QString requete = "";
  requete  += "SELECT " + m_COLOR_PROFIL_NAME       +  ","         // 0
                        + m_COLOR_PROFIL_COLOR      +  ","         // 1
                        + m_COLOR_PROFIL_DUREE      +  " FROM  "   // 2
                        + m_COLOR_PROFIL_TBL_NAME ;
  //m_log  += "---------- CMoteurAgenda::COL_Get_List() requete  "+QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss")+ "------------------\r\n";
  //m_log  += requete + "\r\n";
  int nb  = 0;
  QSqlQuery query(requete , QSqlDatabase::database(m_BaseLabel) );
  //.................. si la requète a un resultat .........................................
  if (query.isActive())
     { while (query.next())
             {key = CGestIni::Utf8_Query(query, 0 );
              colorProfils.insert(key, C_ColorType(key, query.value( 1 ).toString(), query.value( 2 ).toString()) );
              //m_log  += "       color : "+ QString::number(nb)+" Key :" + key + " " + query.value( 1 ).toString() + " " + query.value( 2 ).toString() + "\r\n";
              ++ nb;
             } //end while (pSqlQuery->next())
     } //endif (query.isActive())
  CloseBase();
  //CGestIni::Param_UpdateToDisk("C:/ColGet.txt",m_log);
  return nb;
}

//-------------------------------------- COL_AllDelete ----------------------------------------------------------------------------
int CMoteurAgenda::COL_AllDelete(QString *errMess /*=0*/)
{ //................. ouvrir la base  ......................................................
  if (OpenBase()==0) {if (errMess) *errMess = "CMoteurAgenda::RDV_Delete(): database can't be opened";              return FALSE; }
  //................. Preparer la requete ..................................................
  QString requete("DELETE FROM ");
          requete += m_COLOR_PROFIL_TBL_NAME  ;
  QSqlQuery query(QString::null , QSqlDatabase::database(m_BaseLabel) );
  query.exec(requete);
  CloseBase();
  return TRUE;
}
//-------------------------------------- COL_RecordAllColorMap ----------------------------------------------------------------------------
int CMoteurAgenda::COL_RecordAllColorMap(MAP_COLOR *pColorMap, QString *errMess /*=0*/)
{
  //................. ouvrir la base  ......................................................
  int nb  = 0;
  //m_log  += "---------- CMoteurAgenda::COL_RecordAllColorMap() requete  "+QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss")+ "------------------\r\n";
  if (OpenBase()==0) {if (errMess) *errMess = "CMoteurAgenda::RDV_Delete(): database can't be opened";              return FALSE; }
  QMap<QString, C_ColorType>::const_iterator it = pColorMap->constBegin();
  while (it != pColorMap->constEnd())
        {  QSqlQuery query(QSqlDatabase::database(m_BaseLabel));
           QString prepare  = "INSERT INTO ";
           prepare += m_COLOR_PROFIL_TBL_NAME + "(" +
                      m_COLOR_PROFIL_NAME     + "," +
                      m_COLOR_PROFIL_COLOR    + "," +
                      m_COLOR_PROFIL_DUREE    + ") VALUES (?,?,?)";
           query.prepare(prepare);
           //m_log  += prepare + "\r\n";
           C_ColorType ct=it.value();
           query.bindValue(0, ct.getType());
           query.bindValue(1, ct.getColor());
           query.bindValue(2, qMin(120,qMax (ct.getDuree().toInt(), 5 )));  // borner le truc avant que MySQL se fache
           //m_log  += "       color : "+ QString::number(nb)+" Key :" + ct.getType() + " " + ct.getColor() + " " + ct.getDuree() + "\r\n";
           ++ nb;
           if ( !query.exec()) { QString mess = tr("Error : CMoteurAgenda::COL_RecordAllColorMap() \r\n") + prepare + "\r\n";
                                 mess        += OutSQL_error(query, mess.toAscii());      // rajouter le message sql
                                 if (errMess) *errMess += mess;
                                 //m_log += "------ CMoteurAgenda::COL_RecordAllColorMap() erreur \r\n" + mess + "\r\n";
                                 break;
                               }
         ++it;
       }
  CloseBase();
  //CGestIni::Param_UpdateToDisk("C:/ColGet.txt",m_log);
  return TRUE;
}

//-------------------------------------- COL_Delete ----------------------------------------------------------------------------
int CMoteurAgenda::COL_Delete( const QString name, QString *errMess /*=0*/)
{ //................. ouvrir la base  ......................................................
  if (OpenBase()==0) {if (errMess) *errMess = "CMoteurAgenda::RDV_Delete(): database can't be opened";              return FALSE; }
  //................. Preparer la requete ..................................................
  QString requete("DELETE FROM ");
          requete += m_COLOR_PROFIL_TBL_NAME + " WHERE "
                  +  m_COLOR_PROFIL_NAME     + "= '" + name  + "'"  ;
  QSqlQuery query(QString::null , QSqlDatabase::database(m_BaseLabel) );
  query.exec(requete);
  CloseBase();
  return TRUE;
}

//-----------------------------------------------------  RDV_IsThisRendezVousExist -------------------------------------------
QString CMoteurAgenda::RDV_IsThisRendezVousExist(const C_RendezVous &rendezVous, QString *errMess /*=0*/)
{
  QString ret("");
  //................. ouvrir la base  ......................................................
  if (OpenBase()==0)    {if (errMess) *errMess = ("CAnalyse::RDV_IsThisRendezVousExist(): Echec de l'ouverture de la base");        return ret; }
  //................. filtrer selon donnée d'entrée ..................................................
  QString reqDateDebStr = rendezVous.m_date.date().toString("yyyyMMdd") + rendezVous.m_date.time().toString("hhmm") + "00";
  QString requete("");
  requete  += "SELECT " + m_AGENDA_PRIM_KEY   +  " FROM  "
                        + m_AGENDA_TBL_NAME   +  " WHERE "
                        + m_AGENDA_DATETIME   +  " = '" + reqDateDebStr         + "' AND "
                        + m_AGENDA_NOM        +  " = '" + rendezVous.m_Nom      + "' AND "
                        + m_AGENDA_PRENOM     +  " = '" + rendezVous.m_Prenom   + "' AND "
                        + m_AGENDA_PRIS_AVEC  +  " = '" + rendezVous.m_PrisAvec + "' AND "
                        + m_AGENDA_TYPE       +  " = '" + rendezVous.m_Type     + "' ";

  QSqlQuery query(requete , QSqlDatabase::database(m_BaseLabel) );
  //.................. si la requète a un resultat ..............................................
  if (query.isActive() && query.next())
     {ret   = query.value(0).toString();
     }

  CloseBase();
  return ret;
}

//-------------------------------------- RDV_Create ----------------------------------------------------------------------------
QString CMoteurAgenda::RDV_Create(const C_RendezVous &rendezVous, QString *errMess /*=0*/)
{
  //................................. methode QSqlCursor .....................................
  //                         ne pose pas de PB avec valeur avec une apostrophe
  QString ret  = "";
  //............... ouvrir la base .......................................................
  if (OpenBase()==0) {if (errMess) *errMess = "CMoteurAgenda::RDV_Create(): database can't be opened";              return FALSE; }

  QSqlQuery query(QSqlDatabase::database(m_BaseLabel));
  QString prepare  = "INSERT INTO ";
          prepare += m_AGENDA_TBL_NAME       + "(" +  //
                     m_AGENDA_DATETIME       + "," +  // 0
                     m_AGENDA_DUREE          + "," +  // 1
                     m_AGENDA_GUID           + "," +  // 2
                     m_AGENDA_NOM            + "," +  // 3
                     m_AGENDA_PRENOM         + "," +  // 4
                     m_AGENDA_TEL            + "," +  // 5
                     m_AGENDA_PRIS_AVEC      + "," +  // 6
                     m_AGENDA_PRIS_PAR       + "," +  // 7
                     m_AGENDA_TYPE           + "," +  // 8
                     m_AGENDA_STATUS         + "," +  // 9
                     m_AGENDA_WHERE          + "," +  // 10
                     m_AGENDA_NOTE           + ") "   // 11
                     "VALUES (?,?,?,?,?,?,?,?,?,?,?,?)";
  query.prepare(prepare);
  query.bindValue(0, rendezVous.m_date);
  query.bindValue(1, (int)rendezVous.m_Duree);
  query.bindValue(2, rendezVous.m_GUID);
  query.bindValue(3, rendezVous.m_Nom);
  query.bindValue(4, rendezVous.m_Prenom);
  query.bindValue(5, QString(rendezVous.m_Tel).remove(" "));
  query.bindValue(6, rendezVous.m_PrisAvec);
  query.bindValue(7, rendezVous.m_PrisPar);
  query.bindValue(8, rendezVous.m_Type);
  query.bindValue(9, rendezVous.m_State);
  query.bindValue(10,rendezVous.m_Where);
  query.bindValue(11,rendezVous.m_Note);
  if (!query.exec()){QString mess = tr("Error : CMoteurAgenda::RDV_Create() \r\n") + prepare + "\r\n";
                     mess        += OutSQL_error(query, mess.toLatin1());      // rajouter le message sql
                     if (errMess) *errMess += mess;
                    }
  //................. recuperer dernier primKey insere ..............................
  QString requete ("SELECT LAST_INSERT_ID() FROM ");
  requete += m_AGENDA_TBL_NAME + " WHERE " + m_AGENDA_PRIM_KEY + " = LAST_INSERT_ID()";
  QSqlQuery sqlQuery2(requete , QSqlDatabase::database(m_BaseLabel) );
  if ( sqlQuery2.next() )  ret =  sqlQuery2.value(0).toString();
  //......................... fermer la base ..............................................
  CloseBase();
  return ret;
}

//-------------------------------------- RDV_Update ----------------------------------------------------------------------------
int CMoteurAgenda::RDV_Update(const C_RendezVous &rendezVous, QString *errMess /*=0*/)
{ int ok  = FALSE;
  //............... ouvrir la base .......................................................
  if (OpenBase()==0) {if (errMess) *errMess = "CMoteurAgenda::RDV_Update(): database can't be opened";    return FALSE; }
  QSqlQuery query(QSqlDatabase::database(m_BaseLabel));
  QString prepare            = "";
  prepare                   += "UPDATE "           + m_AGENDA_TBL_NAME    + " SET " +
                               m_AGENDA_DATETIME   + " = ? ," +
                               m_AGENDA_DUREE      + " = ? ," +
                               m_AGENDA_GUID       + " = ? ," +
                               m_AGENDA_NOM        + " = ? ," +
                               m_AGENDA_PRENOM     + " = ? ," +
                               m_AGENDA_TEL        + " = ? ," +
                               m_AGENDA_PRIS_AVEC  + " = ? ," +
                               m_AGENDA_PRIS_PAR   + " = ? ," +
                               m_AGENDA_TYPE       + " = ? ," +
                               m_AGENDA_STATUS     + " = ? ," +
                               m_AGENDA_WHERE      + " = ? ," +
                               m_AGENDA_NOTE       + " = ?  " +
                               " WHERE " + m_AGENDA_PRIM_KEY      + " ='"  + rendezVous.m_PrimKey         + "'";
  query.prepare(prepare);
  query.bindValue(0, rendezVous.m_date);
  query.bindValue(1, (int)rendezVous.m_Duree);
  query.bindValue(2, rendezVous.m_GUID);
  query.bindValue(3, rendezVous.m_Nom);
  query.bindValue(4, rendezVous.m_Prenom);
  query.bindValue(5, QString(rendezVous.m_Tel).remove(" "));
  query.bindValue(6, rendezVous.m_PrisAvec);
  query.bindValue(7, rendezVous.m_PrisPar);
  query.bindValue(8, rendezVous.m_Type);
  query.bindValue(9, rendezVous.m_State);
  query.bindValue(10,rendezVous.m_Where);
  query.bindValue(11,rendezVous.m_Note);
  query.exec();
  if (query.exec()) {ok = TRUE;}
  else              {QString mess = tr("Error : CMoteurAgenda::MASK_Append() \r\n") + prepare + "\r\n";
                     mess        += OutSQL_error(query, mess.toLatin1());      // rajouter le message sql
                     if (errMess) *errMess += mess;
                     ok = FALSE;
                    }
  //......................... fermer la base ..............................................
  CloseBase();
  return ok;
}

//-------------------------------------- RDV_Delete ----------------------------------------------------------------------------
int CMoteurAgenda::RDV_Delete( const QString &primKey, QString *errMess /*=0*/)
{ //................. ouvrir la base  ......................................................
  if (OpenBase()==0) {if (errMess) *errMess = "CMoteurAgenda::RDV_Delete(): database can't be opened";              return FALSE; }
  //................. Preparer la requete ..................................................
  QString requete("DELETE FROM ");
          requete += m_AGENDA_TBL_NAME       + " WHERE "
                  +  m_AGENDA_PRIM_KEY       + "= '"       + primKey  + "' ";
  QSqlQuery query(QString::null , QSqlDatabase::database(m_BaseLabel) );
  query.exec(requete);
  CloseBase();
  return TRUE;
}

//--------------------------------------------- RDV_Get_ListNbFor2Months ------------------------------------------------
QMap<QDate,int> CMoteurAgenda::RDV_Get_ListNbFor2Months(QDate date, const QString &user)
{ int valeur = 0;
  //................. ouvrir la base  ......................................................
  OpenBase();
  //................. Preparer la requete ..................................................
  QMap<QDate,int> map ;
  QString reqDateDebStr = date.toString("yyyyMMdd") ;
  QString reqDateEndStr = date.addMonths(2).addDays(-1).toString("yyyyMMdd") ;// le dernier jour est compté avec between
  QString requete("");
  /*
  requete  += QString("SELECT ") +  QString(" DATE(Date_Time),COUNT(*) ")
                    + " FROM  "+ m_AGENDA_TBL_NAME
                    + " WHERE " + m_AGENDA_PRIS_AVEC  +  "  = '" + user + "'" + QString(" AND ")
                    + "Date("   + m_AGENDA_DATETIME   +  ") BETWEEN '" + reqDateDebStr + "' AND '" + reqDateEndStr
                    + "' GROUP BY Date(" + m_AGENDA_DATETIME + ")" ;// Un groupe permet au fonction d'agregat ici COUNT de compter ce qui il y a dans les groupes ici dans chaque journée
  */
  requete  += QString("SELECT ") +  QString(" Date_Time, COUNT(*) ")
                    + " FROM  "+ m_AGENDA_TBL_NAME
                    + " WHERE " + m_AGENDA_PRIS_AVEC  +  "  = '" + user + "'" + QString(" AND ")
                    + "  "      + m_AGENDA_DATETIME   +  "  BETWEEN '" + reqDateDebStr + "' AND '" + reqDateEndStr
                    + "' GROUP BY Date(" + m_AGENDA_DATETIME + ")" ;// Un groupe permet au fonction d'agregat ici COUNT de compter ce qui il y a dans les groupes ici dans chaque journée

  //qDebug(requete);
  //SELECT Date_Time, COUNT(*) FROM agenda where RDV_PrisAvec  = 'admin' and Date_Time BETWEEN '20090725' AND '20090924' GROUP BY Date(Date_Time)
  QSqlQuery query(requete , QSqlDatabase::database(m_BaseLabel) );
  if (query.isActive())
     {  while (query.next())
              {
               QDate date = query.value(0).toDate();
               valeur     = query.value(1).toInt();
               map[date]  = valeur ;
              }
     }
  else
     {qDebug()<<requete.toLatin1();
     }
  CloseBase();
  return  map;
}

//--------------------------------------------- RDV_Get_ListNb ------------------------------------------------
int CMoteurAgenda::RDV_Get_ListNb(QDate date, const QString &user)
{
//................. ouvrir la base  ......................................................
  OpenBase();
  //................. Preparer la requete ..................................................
  QString reqDateDebStr = date.toString("yyyyMMdd") + "000000";
  QString reqDateEndStr = date.toString("yyyyMMdd") + "235959";
  QString requete("");
  requete  += "SELECT COUNT(*) FROM "
           + m_AGENDA_TBL_NAME   +  " WHERE "
           + m_AGENDA_DATETIME   +  " BETWEEN '" + reqDateDebStr + "' AND '" + reqDateEndStr + "'  AND "
           + m_AGENDA_PRIS_AVEC  +  "  = '"      + user + "'" ;
  QSqlQuery query(requete , QSqlDatabase::database(m_BaseLabel) );
  query.next();
  int ret_int = query.value(0).toInt() ;
  CloseBase();
  return  ret_int;
}

//--------------------------------------------- RDV_Get_List ------------------------------------------------
int CMoteurAgenda::RDV_Get_List(QDate date, const QString &user, RDV_LIST &rdvList, int mode /*= CMoteurAgenda::AllDates*/, QString *errMess /*=0*/)
{ return RDV_Get_List( date, user, &rdvList,  mode , errMess );
}
//--------------------------------------------- RDV_Get_List ------------------------------------------------
int CMoteurAgenda::RDV_Get_List(QDate date, const QString &user, RDV_LIST *rdvList, int mode /*= CMoteurAgenda::AllDates*/, QString *errMess /*=0*/)
{
  //................. Preparer la requete ..................................................
  QString reqDateDebStr = date.toString("yyyyMMdd") + "000000";
  QString reqDateEndStr = date.toString("yyyyMMdd") + "235959";
  return RDV_Get_List(reqDateDebStr, reqDateEndStr, user, rdvList, mode , errMess );
}
//--------------------------------------------- RDV_Get_List ------------------------------------------------
int CMoteurAgenda::RDV_Get_List(QString reqDateDebStr, QString reqDateEndStr, const QString &user, RDV_LIST &rdvList, int mode /*= CMoteurAgenda::AllDates*/, QString *errMess /*=0*/)
{ return RDV_Get_List( reqDateDebStr, reqDateEndStr, user, &rdvList,  mode , errMess );
}
//--------------------------------------------- RDV_Get_List ------------------------------------------------
int CMoteurAgenda::RDV_Get_List(QString reqDateDebStr, QString reqDateEndStr, const QString &user, RDV_LIST *rdvList, int mode /*= CMoteurAgenda::AllDates*/, QString *errMess /*=0*/)
{ rdvList->clear();
  //................. ouvrir la base  ......................................................
  if (OpenBase()==0) {if (errMess) *errMess = "CMoteurAgenda::RDV_Get_List(): database can't be opened";              return 0; }
  QString requete("");
  requete  += "SELECT " + m_AGENDA_DATETIME   +  ","         // 0
                        + m_AGENDA_DUREE      +  ","         // 1
                        + m_AGENDA_GUID       +  ","         // 2
                        + m_AGENDA_NOM        +  ","         // 3
                        + m_AGENDA_PRENOM     +  ","         // 4
                        + m_AGENDA_TEL        +  ","         // 5
                        + m_AGENDA_PRIS_AVEC  +  ","         // 6
                        + m_AGENDA_PRIS_PAR   +  ","         // 7
                        + m_AGENDA_TYPE       +  ","         // 8
                        + m_AGENDA_STATUS     +  ","         // 9
                        + m_AGENDA_NOTE       +  ","         // 10
                        + m_AGENDA_WHERE      +  ","         // 11
                        + m_AGENDA_PRIM_KEY   +  " FROM  "   // 12
                        + m_AGENDA_TBL_NAME   +  " WHERE "
                        //+ m_AGENDA_DATETIME   +  " >= '" + reqDateDebStr + "' AND " + m_AGENDA_DATETIME + "<= '" + reqDateEndStr + "' AND "
                        + m_AGENDA_DATETIME   +  " BETWEEN '" + reqDateDebStr + "' AND '" + reqDateEndStr + "' AND "
                        + m_AGENDA_PRIS_AVEC  +  "  = '" + user + "' ORDER BY " + m_AGENDA_DATETIME;
  int nb = 0;
  QSqlQuery query(requete , QSqlDatabase::database(m_BaseLabel) );
  //.................. si la requète a un resultat ..............................................
  if (query.isActive())
     { while (query.next())
             {bool ok = TRUE;
              if (mode == CMoteurAgenda::OnlyDateWhithName && query.value(3).toString().length()==0) ok = FALSE;
              if (ok){C_RendezVous* pRdv =  new C_RendezVous(query.value( 0 ).toDateTime(),   // date
                                                             query.value( 1 ).toInt(),        // duree
                                                             CGestIni::Utf8_Query(query, 3 ), // nom
                                                             CGestIni::Utf8_Query(query, 4 ), // prenom,
                                                             query.value( 5 ).toString(),     // tel,
                                                             CGestIni::Utf8_Query(query, 10), // note,
                                                             query.value( 2 ).toString(),     // guid,
                                                             CGestIni::Utf8_Query(query, 6 ), // prisAvec,
                                                             CGestIni::Utf8_Query(query,7 ),  // prisPar,
                                                             CGestIni::Utf8_Query(query, 8),  // type,
                                                             query.value( 12).toString(),     // primKey
                                                             CGestIni::Utf8_Query(query, 9),  // State
                                                             CGestIni::Utf8_Query(query, 11)  // Where
                                                           );
                      rdvList->append(pRdv);
                      ++ nb;
                     } //end if (ok)
             } //end while (pSqlQuery->next())
     } //endif (query.isActive())
  CloseBase();
  return nb;
}

//-------------------------------------------------- dayOfWeek -----------------------------------------------
QString CMoteurAgenda::dayOfWeek(int dayOfWeek)
{
 switch(dayOfWeek)
        { case 1:  return  tr( "Monday");
          case 2:  return  tr( "Tuesday");
          case 3:  return  tr( "Wednesday");
          case 4:  return  tr( "Thursday");
          case 5:  return  tr( "Friday");
          case 6:  return  tr( "Saturday");
          case 7:  return  tr( "Sunday");
        }
 return QString::null;
}

//-------------------------------------------------- OutSQL_error -----------------------------------------------
QString CMoteurAgenda::OutSQL_error(const QSqlQuery &cur, const char *messFunc /*=0*/, const char *requete /*=0*/)
{   return OutSQL_error(cur.lastError(), messFunc, requete );
}

//-------------------------------------------------- OutSQL_error -----------------------------------------------
QString CMoteurAgenda::OutSQL_error(const QSqlError &error, const char *messFunc /*=0*/, const char *requete /*=0*/)
{    QString   qserr("");

     if (error.type() != QSqlError::NoError)
        {switch (error.type())
           { case    QSqlError::NoError:             qserr = tr(" - SQL no error occurred: ")          ; break;
             case    QSqlError::ConnectionError:     qserr = tr(" - SQL connection error: ")           ; break;
             case    QSqlError::StatementError:      qserr = tr(" - SQL statement syntax error: ")     ; break;
             case    QSqlError::TransactionError:    qserr = tr(" - SQL transaction failed error: ")   ; break;
             case    QSqlError::UnknownError:        qserr = tr(" - SQL unknown error: ")              ; break;
             default:                                qserr = tr(" - unknown SQL type error: ")         ; break;
           }
         if (messFunc) qDebug()<<messFunc;
         qDebug()<< qserr.append(error.databaseText()).toLatin1();
         if (requete) qDebug()<<requete;
        }
     return error.databaseText();
}


