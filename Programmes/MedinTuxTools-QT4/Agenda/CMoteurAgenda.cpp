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
#include <QDateTime>
#include <QSqlTableModel>
#include <QDebug>
#include <QMessageBox>
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
{ m_IsValid            = 0;
  m_pReconnectTimer    = 0;
  m_ModifConfirm       = 0;
  m_Representation     = 0;
  m_NbDayInModeWeek    = 7;
  m_nbWeeksToSee       = 28;
  m_buttonDeleteOnRdv  = 1;
  m_EditNoteMode       = 1;
  m_isVerbose          = 0;
  m_AgendaWidth        = 300;
  m_AgendaWeekWidth    = 1200;
  m_NbDayInModeWeek    = 5;
  m_NbDayInModeDay     = 60;
  m_TitleHeight        = 20;
  m_AgendaButtonHeight = 30;
  m_MinDaysHeight      = 5;
  m_ModifConfirm       = 0;
  m_Rafraichissement   = 120;
  m_Representation     = 1;       // 0/sur 1 ligne 1/sur deux lignes
  m_WeekDeploymentMode = 1;
  m_AnimationAuthorisation       = 0;
  m_HeightDaysHeaderInExpandMode = 25;
  m_isDayOfMonthToBeDisplay      = 0;
  m_WeekOrDay                    = "DAY";            // Vide ou DAY = affichage journee, WEEK= Affichage Semaine // CZA
  m_TitleTemplate                = "<font color=\"#FFFFFF\"><b>{{TITLE}}</b></font>";
  m_HtmlTemplateTitleMonth       = "<h2><b><font color=\"#FF0000\">{{MONTH_NAME}}</font></b></h2>";
  m_FormatDateInResumeD          = "ddd dd MMMM yyyy";
  m_FormatDateInResumeW          = "ddd dd MMMM yyyy";
  m_FormatDateInResumeM          = "ddd dd MMMM";
  initBase   ( driver,        // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
               DataBaseName,  // nom de la base: si QODBC3 -> nom de la source de données (userDSN)
               user,          // = "root"
               password,      // = ""
               hostname,
               port,
               confFile,
               baseLabel,
               errMess);
  SetMinDaysHeight();
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

//--------------------------------------------- SetAnimationAuthorisation ------------------------------------------------
void CMoteurAgenda::SetAnimationAuthorisation(const QString &value)
{if (value.length())
    {m_AnimationAuthorisation = value.toInt();
    }
}

//-------------------------------------- GetAnimationAuthorisation ----------------------------------------------------------------------------
int  CMoteurAgenda::GetAnimationAuthorisation()
{return m_AnimationAuthorisation;
}

//--------------------------------------------- SetWeekDeploymentMode ------------------------------------------------
void CMoteurAgenda::SetWeekDeploymentMode(const QString &value)
{if (value.length())
    {m_WeekDeploymentMode = value.toInt();
    }
}

//--------------------------------------------- GetWeekDeploymentMode ------------------------------------------------
int  CMoteurAgenda::GetWeekDeploymentMode()
{return m_WeekDeploymentMode;
}

//-------------------------------------- SetFormatDateInResume ----------------------------------------------------------------------------
void  CMoteurAgenda::SetFormatDateInResume(const QString &value )
{if (value.length())
    {   QStringList       lst = value.split('|', QString::SkipEmptyParts);
        //......... on recupere premiere valeur ............................
        //          par defaut les autres formats la prennent aussi
        m_FormatDateInResumeD = lst[0];
        m_FormatDateInResumeW = m_FormatDateInResumeD;
        m_FormatDateInResumeM = m_FormatDateInResumeD;
        //          si autres formats pr�cises alors les affecter ...........
        if (lst.size()>0) m_FormatDateInResumeW = lst[1];
        if (lst.size()>1) m_FormatDateInResumeM = lst[2];
    }
}
//-------------------------------------- GetFormatDateInResume ----------------------------------------------------------------------------
QString CMoteurAgenda::GetFormatDateInResume(char mode)
{switch((int)mode)
       {case 'D': return m_FormatDateInResumeD;
        case 'W': return m_FormatDateInResumeW;
        case 'M': return m_FormatDateInResumeM;
        default:  return m_FormatDateInResumeD;
       }
}
//-------------------------------------- SetHtmlTemplateTitleMonth ----------------------------------------------------------------------------
void  CMoteurAgenda::SetHtmlTemplateTitleMonth(const QString &value)
{if (value.length())
    { m_HtmlTemplateTitleMonth=value;
    }
}
//-------------------------------------- GetHtmlTemplateTitleMonth ----------------------------------------------------------------------------
QString CMoteurAgenda::GetHtmlTemplateTitleMonth()
{return m_HtmlTemplateTitleMonth;
}
//-------------------------------------- SetMinDaysHeight ----------------------------------------------------------------------------
void  CMoteurAgenda::SetMinDaysHeight(int val  /* = 15*/)
{m_MinDaysHeight = val;
}
//-------------------------------------- GetMinDaysHeight ----------------------------------------------------------------------------
int  CMoteurAgenda::GetMinDaysHeight()
{return m_MinDaysHeight;
}
//-------------------------------------- SetDaysHeight ----------------------------------------------------------------------------
void  CMoteurAgenda::SetTitleHeight(int val  /* = 15*/)
{m_TitleHeight = val;
}
//-------------------------------------- GetTitleHeight ----------------------------------------------------------------------------
int  CMoteurAgenda::GetTitleHeight()
{return m_TitleHeight;
}
//-------------------------------------- SetAgendaButtonBoxHeight ----------------------------------------------------------------------------
void CMoteurAgenda::SetAgendaButtonBoxHeight(int value)
{m_AgendaButtonHeight = value;
}
//-------------------------------------- GetAgendaButtonBoxHeight ----------------------------------------------------------------------------
int CMoteurAgenda::GetAgendaButtonBoxHeight()
{return m_AgendaButtonHeight;
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
  query.bindValue(3, QString(rendezVous.m_Nom).replace("&NBSP;","&nbsp;"));
  query.bindValue(4, QString(rendezVous.m_Prenom).replace("&NBSP;","&nbsp;"));
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
  query.bindValue(3, QString(rendezVous.m_Nom).replace("&NBSP;","&nbsp;"));
  query.bindValue(4, QString(rendezVous.m_Prenom).replace("&NBSP;","&nbsp;"));
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

//CZA --------------------------------------------------------------------------------------------
// A PLACER DANS UNE CLASSE SEPAREE APPELEE AUSSI PAR MANAGER >>>> BOULOT DE OUF !!!!
// A REVOIR AVEC RS
// EN ATTENDANT ....
#define DOSS_INDEX_TBL_NAME     "IndexNomPrenom"
#define DOSS_INDEX_NOM          "FchGnrl_NomDos"
#define DOSS_INDEX_PRENOM       "FchGnrl_Prenom"
#define DOSS_INDEX_PRIM_KEY     "ID_PrimKey"
#define DOSS_INDEX_GUID         "FchGnrl_IDDos"


#define DOSS_IDENT_TBL_NAME     "fchpat"
#define DOSS_IDENT_REF_PK       "FchPat_RefPk"
#define DOSS_IDENT_GUID         "FchPat_GUID_Doss"
#define DOSS_IDENT_NSS          "FchPat_Nee"
#define DOSS_IDENT_TEL1         "FchPat_Tel1"
#define DOSS_IDENT_SEXE         "FchPat_Sexe"

#define ST_LIST_PATIENT_MAX   "200"

//-----------------------------------------------------  GetPatientList -------------------------------------------
/*! \brief Remplit la QListView avec les patients retrouves dans la base de donnees.
 *  \param pQlistView : ListView qui recevra les patients recherches
 *  \param qsrt_nom : Nom a rechercher
 *  \param qsrt_prenom : Prenom a rechercher
 *  \param statusMess : message de retour
 *  \param errMess : Message d'erreur.
 *  \return nombre d'enregistrements inseres dans la QListView passee en paramètre
*/
long CMoteurAgenda::GetPatientList(       QTreeWidget     *pQlistView,
                                  const QString           &qstr_nom,
                                  const QString           &qstr_prenom,
                                        QLabel            * /* statutMess,  = 0  */,
                                        QString           *errMess     /* = 0  */
                                )

{QString   q_nom    = "";
 QString   q_prenom = "";
 QString   tmp      = "";
 //................. Preparer la requete .....................................
  if (OpenBase()==0)
     {if (errMess) *errMess = TR("CMoteurBase::GetPatientList(): data base can't be open");
      return 0;
     }
  QString requete, requete_ident;
  if (qstr_nom != ""||qstr_prenom!="")
     {q_nom    = qstr_nom;
      q_prenom = qstr_prenom;
     }
  q_nom.replace("\'","\\\'");
  q_prenom.replace("\'","\\\'");
  int nb_columns = pQlistView->columnCount();
  requete        = "SELECT ";
  requete       += DOSS_INDEX_NOM       ", "  DOSS_INDEX_PRENOM     ", "        // 0 - 1
                   DOSS_INDEX_PRIM_KEY  ", "  DOSS_INDEX_GUID       ", "        // 2 - 3
                   DOSS_IDENT_NSS       ", "  DOSS_IDENT_TEL1       ", "        // 4 - 5
                   DOSS_IDENT_SEXE
                   " FROM "                   DOSS_INDEX_TBL_NAME
                   " JOIN "             DOSS_IDENT_TBL_NAME
                   " ON "                     DOSS_INDEX_PRIM_KEY " = " DOSS_IDENT_REF_PK
                   " WHERE "
                   DOSS_INDEX_NOM       " LIKE '"   + q_nom      +  "%' AND "
                   DOSS_INDEX_PRENOM    " LIKE '"   + q_prenom   +   "%' "
                   " ORDER BY "               DOSS_INDEX_NOM  ","   DOSS_INDEX_PRENOM
                   " LIMIT "  ST_LIST_PATIENT_MAX;

  QSqlQuery query(requete , QSqlDatabase::database(m_BaseLabel) );
  //QSqlQuery query_ident;

  //................ scanner les enregistrements ................................................
  //                 pour remplir la listview

  int i  = 0;
  //.................. si la requète a un resultat ..............................................
  if (query.isActive())
  {pQlistView->clear();
   while (query.next())
   { //if (i < 200)
     { QTreeWidgetItem *pQTreeWidgetItem = new QTreeWidgetItem();
       if (pQTreeWidgetItem)
          {
           //CPrtQListViewItem* line = 0;
           //............... on rempli la listbox selon son nombre de colonnes .....................
           /*
            switch (nb_columns)
           {case 1:
                pQTreeWidgetItem->setText(0, Utf8_Query(query, 0 ));
                break;
            case 2:
                pQTreeWidgetItem->setText(0, Utf8_Query(query, 0 ));
                pQTreeWidgetItem->setText(1, Utf8_Query(query, 1 ));
                break;
            case 3:
                pQTreeWidgetItem->setText(0, Utf8_Query(query, 0 ));
                pQTreeWidgetItem->setText(1, Utf8_Query(query, 1 ));
                pQTreeWidgetItem->setText(2, Utf8_Query(query, 2 ));
                break;
            case 4:
                pQTreeWidgetItem->setText(0, Utf8_Query(query, 0 ));   // Nom
                pQTreeWidgetItem->setText(1, Utf8_Query(query, 1 ));   // Prenom
                pQTreeWidgetItem->setText(2, Utf8_Query(query, 2 ));   // PK
                pQTreeWidgetItem->setText(3, Utf8_Query(query, 3 ));   // GUID
                break;
            case 8 : // Recupère les elèments d'identite en plus
               {
                 requete_ident        = "SELECT " + m_DOSS_IDENT_RUE + ", " + m_DOSS_IDENT_CODE_POST + ", \n";
                 requete_ident        += m_DOSS_IDENT_VILLE + ", " + m_DOSS_IDENT_JFNOM + ", \n";
                 requete_ident        += m_DOSS_IDENT_TEL1 + ", " + m_DOSS_IDENT_TEL2 + " \n";
                 requete_ident        += " FROM " + m_DOSS_IDENT_TBL_NAME + " \nWHERE ";
                 requete_ident        += m_DOSS_IDENT_REF_PK    + " = "+ query.value(2).toString() + "; \n";
                 query_ident = QSqlQuery(requete_ident , QSqlDatabase::database(m_BaseLabel) );
                 if ( query_ident.isActive() && query_ident.next())
                 { line = new CPrtQListViewItem( pQlistView , line, Utf8_Query(query, 0 )); // Nom
                   // Si pas de CP enregistre alors il est == 0 ==> ne pas l'afficher
                   tmp = Utf8_Query(query_ident, 1) ;
                   if (tmp == "0") tmp ="";
                   line->setText( 1, Utf8_Query(query_ident, 3) );        // Nom JF
                   line->setText( 2, Utf8_Query(query, 1 ) );                // Prenom
                   line->setText( 3, Utf8_Query(query_ident, 0) );        // Rue
                   line->setText( 4, tmp );        // CP
                   line->setText( 5, Utf8_Query(query_ident, 2));        // Ville
                   line->setText( 6, Utf8_Query(query_ident, 4));        // Tel 1
                   line->setText( 7, Utf8_Query(query_ident, 5));        // Tel 2
                   line->setMultiLinesEnabled ( FALSE );                //Plusieurs lignes par item si necessaire
                   //......... Dichotomiser Affichage et donnees a exploiter ..........
                   line->setNom(    Utf8_Query(query, 0 ) );                // Nom
                   line->setPrenom( Utf8_Query(query, 1 ) );                // Prenom
                   line->setPkDoc(  Utf8_Query(query, 2 ) );                // PK
                   line->setGUID(   Utf8_Query(query, 3 ) );                // GUID
                 }

                break;
               }
            } // end switch (nb_columns)
           */
            if (query.value(6).toString() == "F")                      // Sexe
                pQTreeWidgetItem->setIcon(0,Theme::getIcon("Agenda/Femme.png"));
            else
                pQTreeWidgetItem->setIcon(0,Theme::getIcon("Agenda/Homme.png"));
            pQTreeWidgetItem->setText(0, query.value(0).toString());   // Nom
            pQTreeWidgetItem->setText(1, query.value(1).toString());   // Prenom
            pQTreeWidgetItem->setText(2, query.value(2).toString());   // PK
            pQTreeWidgetItem->setText(3, query.value(3).toString());   // GUID
            tmp = query.value(4).toString();                           // Date naissance
            pQTreeWidgetItem->setText(4,tmp.mid(8,2) + "-" + tmp.mid(5,2) +"-"+tmp.mid(0,4));
            pQTreeWidgetItem->setTextAlignment(4,Qt::AlignCenter);
            pQTreeWidgetItem->setText(5,query.value(5).toString());     // Tel 1
            pQTreeWidgetItem->setTextAlignment(5,Qt::AlignCenter);






           pQlistView->addTopLevelItem(pQTreeWidgetItem);
           if (i == 0) pQTreeWidgetItem->setSelected(true);
          } //endif (pQTreeWidgetItem)
       //else if (line) pQlistView->insertItem ( line );
       ++i;
     } // // fin if i < 200
     //++nb;
   } //end while (pSqlQuery->next())

   // Cacher les contenus des colonnes 8 et 9 si 10 demandes
   if (nb_columns == 10)
   { //pQlistView->hideColumn ( 8 );
     //pQlistView->hideColumn ( 9 );
   }
  } //endif (pSqlQuery && pSqlQuery->isActive())

  //ListViewPatient->setCurrentItem(0);   // se placer sur le premier enregistrement de la liste
  //....................... sortir le message d'erreur si besoin ..........................................
  /*
  if (statutMess)
     {int nb = GetNbRecord(m_DOSS_INDEX_TBL_NAME).toInt();
      QString txt = TR("Trouv\303\251(s) %1 parmi %2").arg(i).arg(nb);
      if ( i>=NB_LIST_PATIENT_MAX)
         {txt.prepend("<html><head><meta name=\"qrichtext\" content=\"1\" /> "
                      "</head><body><span style=\"font-weight:600; color:#ff0000;\">");
          txt +=      "</span></body></html>";
         }
      statutMess->setText( txt );
     }
     */
  CloseBase();
  return i;
}

//-------------------------------------chargeListePlagesDisponibles----------------------------------------------
// Lecture des Rdv ? venir dans Agenda pour recherche des plages disponibles.
void CMoteurAgenda::chargeListePlagesDisponibles(QTreeWidget  *pQlistViewPlage, QString user) // CZA
{
    QDateTime qDatePlageDeb = QDateTime::currentDateTime();   // ? partir de maintenant seulement.
    QString  sDatePlageDeb  = qDatePlageDeb.toString("yyyy-MM-dd hh:mm");
    QDateTime qDateFinJourn = QDateTime::currentDateTime();
    qDateFinJourn.setTime(QTime::fromString(m_TimeEnd,"hh:mm"));

    if (OpenBase()==0) { return ; }
    pQlistViewPlage->clear();
    //................. Preparer la requete ..................................................
    QString requete("");
    requete  += "SELECT " + m_AGENDA_DATETIME   +  ","         // 0
                          + m_AGENDA_DUREE                     // 1
                          + " FROM  " + m_AGENDA_TBL_NAME
                          +  " WHERE "
                          +  m_AGENDA_DATETIME   +  " >= '" + sDatePlageDeb
                          + "' AND "
                          + m_AGENDA_PRIS_AVEC  +  "  = '" + user
                          + "' ORDER BY " + m_AGENDA_DATETIME;

    QSqlQuery query(requete , QSqlDatabase::database(m_BaseLabel) );
    if (query.isActive())
       { while (query.next())
            { // tant qu'on a pas d?pass? la date du prochain rdv
            while ( qDatePlageDeb.operator <=(query.value( 0 ).toDateTime()))
                {
                // test si changement de journ?e avant prochain RDV
                // La date du prochain RDV est sup?rieure ? la fin de journ?e en cours
                if (query.value(0).toDateTime().operator >=(qDateFinJourn))
                    {
                    // on charge la plage jusqu'? la fin de journ?e.
                    ajouterPlageDispo(pQlistViewPlage, qDatePlageDeb, qDateFinJourn, 0);
                    // on change de jour.
                    qDatePlageDeb = qDatePlageDeb.addDays(1);
                    if (qDatePlageDeb.date().dayOfWeek() == 7) // on bosse pas le dimanche
                        qDatePlageDeb = qDatePlageDeb.addDays(1);

                    qDatePlageDeb.setTime(QTime::fromString(m_TimeDeb,"hh:mm"));
                    qDateFinJourn = qDatePlageDeb;
                    qDateFinJourn.setTime(QTime::fromString(m_TimeEnd,"hh:mm"));
                    continue;
                    } // fin chgt de jour

                // on charge la plage jusqu'au prochain RDV
                ajouterPlageDispo(pQlistViewPlage, qDatePlageDeb, query.value(0).toDateTime(), 0);

                // la nouvelle plage debut devient la fin du RDV
                qDatePlageDeb = query.value(0).toDateTime().addSecs(query.value( 1 ).toInt() * 60);
                } // fin while datedeb < date rdv

            } //end while (pSqlQuery->next())
       } //endif (query.isActive())
    ajouterPlageDispo(pQlistViewPlage, qDatePlageDeb, qDatePlageDeb, 1);
    CloseBase();
}
//------------------------------------ ajouterPlageDispo ---------------------------------------------------
// ALimente une ligne du treeview des plages dispo.
void CMoteurAgenda::ajouterPlageDispo(QTreeWidget  *pQlistViewPlage, QDateTime DatePlageDeb, QDateTime DatePlageFin, int fini)
{   QString zdat, zDuree;
    int dureePlage;
    QTreeWidgetItem *pQTreeWidgetItem = new QTreeWidgetItem();

    if (!fini)
        {dureePlage =   (DatePlageFin.time().hour() * 60 + DatePlageFin.time().minute())
                         - (DatePlageDeb.time().hour() * 60 + DatePlageDeb.time().minute());
        int h = dureePlage / 60;
        zdat  = QString::number(dureePlage - ( h * 60));
        if (zdat.length() == 1) zdat = "0" + zdat;
        zDuree = QString::number(h) + "h" + zdat;
        }

    if (pQTreeWidgetItem && dureePlage > 5)             // que les plages > ? 5 mn
        {
        zdat = DatePlageDeb.toString("dd-MM-yyyy hh:mm");
        DatePlageDeb.date().day();

        pQTreeWidgetItem->setText(0, DatePlageDeb.toString("ddd  dd-MM-yyyy"));                       // date
        pQTreeWidgetItem->setText(5, zdat.mid(0,10));                           // date
        pQTreeWidgetItem->setText(1, zdat.mid(11,2)+"h"+zdat.mid(14,2));        // heure d?but
        zdat = DatePlageFin.toString("dd-MM-yyyy hh:mm");
        if (!fini)
            {pQTreeWidgetItem->setText(2, zdat.mid(11,2)+"h"+zdat.mid(14,2));   // heure fin
            pQTreeWidgetItem->setText(3, zDuree);                               // duree
            }
        else
            pQTreeWidgetItem->setText(2, "Fin RDV");                            // heure fin
        pQTreeWidgetItem->setText(4, QString::number(DatePlageDeb.date().weekNumber())); // n? semaine

        pQTreeWidgetItem->setTextAlignment(0,Qt::AlignHCenter);
        pQTreeWidgetItem->setTextAlignment(1,Qt::AlignHCenter);
        pQTreeWidgetItem->setTextAlignment(2,Qt::AlignHCenter);
        pQTreeWidgetItem->setTextAlignment(3,Qt::AlignHCenter);
        pQTreeWidgetItem->setTextAlignment(4,Qt::AlignLeft);
        pQTreeWidgetItem->setIcon(4,Theme::getIcon("Agenda/Calendrier.png"));
        pQlistViewPlage->addTopLevelItem(pQTreeWidgetItem);
        }
}

//--------------------------------- creerRDVFactices --------------------------------------------------------------------------------
void CMoteurAgenda::creerRDVFactices (QString user, QDate date_in)
{
    //QMessageBox::warning(0, NomAppli + tr("export"), "");
    QStringList lnom;
    lnom << "LAGAFFE" << "ZEBULON" << "LUKE" << "SARQUO"   << "AULANDE" << "LAPINE" ;
    QStringList lpre;
    lpre << "GASTON"  << "Polux"   << "LUKY" <<  "Nicole"  << "FRANCOISE" <<"MARINETTE"  ;
    QDateTime date_time = QDateTime(date_in, QTime::fromString("08:00","hh:mm"));
    QDate          date ;
    QTime          time ;
    QString        datr;
    QSqlQuery query(QSqlDatabase::database(m_BaseLabel));

    QString requete = "INSERT into agenda ( Date_Time, Duree, Nom, Prenom, Tel, RDV_PrisAvec, RDV_PrisPar, Note, Type, status ) "
                      " VALUES ( :Date_Time, :Duree, :Nom, :Prenom, :Tel, :RDV_PrisAvec,:RDV_PrisPar, :Note, :Type, :status ) ";

    query.prepare(requete);

    int nbrdv = 1;
    int     j = 0;
    for (int mois = 1; mois <13; ++mois)
        {
            //for (int jour = 1; jour < 28; jour ++) // REMETTRE 28 POUR CREATION SUR UN AN !!!!!!!!!!!!!!!!!!!!!!!!
            for (int jour = 1; jour <= 14; ++jour)
            {date = date_time.date().addDays(jour-1);
                for (int heure = 0; heure < 12; ++heure)
                {
                    for (int minu = 0; minu < 50; minu = minu+15)
                    {   time = date_time.time().addSecs(heure*3600+minu*60);
                        //QString jr, mr,ar, hr, mir, datr;
                        //jr = QString::number(jour);     if (jour < 10)  jr = "0"+jr;
                        //mr = QString::number(mois);     if (mois < 10)  mr = "0"+mr;
                        //hr = QString::number(heure);    if (heure < 10) hr = "0"+hr;
                        //mir = QString::number(minu);    if (minu < 10)  mir = "0"+mir;
                        //datr = "2011-"  + mr + "-" + jr + " " + hr + ":" + mir + ":00";
                        datr = date.toString("yyyy-MM-dd")+"T"+time.toString("hh:mm:00");
                        query.bindValue(":Date_Time",       datr);
                        query.bindValue(":Duree",       "15");
                        if ( ++j  > 5) j =0;
                        query.bindValue(":Nom",         lnom.at(j));
                        query.bindValue(":Prenom",      lpre.at(j));
                        query.bindValue(":Tel",         "04.42.85.30.08");
                        query.bindValue(":RDV_PrisAvec",user);
                        query.bindValue(":RDV_PrisPar", user);
                        query.bindValue(":Note",        "Visite de controle");
                        query.bindValue(":Type",        "Urgences Chirurgicales");
                        query.bindValue(":status",      "Absent");

                        if (!query.exec() )
                            {OutSQL_error(query, "Erreur Insert Agenda", requete.toAscii());
                             return;
                            }
                        qDebug() << "RDV num�ro : " + QString::number(nbrdv++);
                    } // fin minute
                } // fin for heure
            } // fi jour
            break; // VIRER LE BREAK  POUR CREATION SUR UN AN !!!!!!!!!!!!!!!!!!!!!!!!
        } // fin mois
}
