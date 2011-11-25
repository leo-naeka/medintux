 /*********************************** CMoteurAgenda.h **********************
 *  #include "CMoteurAgenda.h"        QT4-ready                            *
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
#ifndef  CMOTEUR_AGENDA_H
#define  CMOTEUR_AGENDA_H
#include "C_RendezVous.h"

#include <QObject>
#include <QList>
#include <QSqlQuery>
#include <QDateTime>
#include <QTimer>
#include <QTreeWidget>        // CZA
#include <QLabel>             // CZA

#define BASE_AGENDA            "BaseAgenda"
#define SKIP_BLANK_CAR(a)       while( *(a) && (*(a)==' ' || *(a)=='\t' || *(a)== 96) ) (a)++
#define NEXT_LINE(a)            while( *(a) && *(a)!='\r' && *(a)!='\n')(a)++; while( *(a) && (*(a)=='\r'|| *(a)=='\n'))(a)++
#define DUMMY_TEST_SQL_COMMAND  "SELECT 1"
#define DB_TIME_TO_RECONNECT    1800000         //reconnexion toutes les 1/2 heures

#define TYP_ICON 0
#define TYP_NAME 1
#define TYP_COUL 2
#define TYP_TIME 3


//===================================== CMoteurAgenda ========================================================================
class CMoteurAgenda : public QObject
{
 Q_OBJECT
 public:
    enum listMode {
        OnlyDateWhithName,
        AllDates,
        DateWhithAnyName
    };
 //............................... METHODES .........................................................................

 public:

  //................................... configuration et connection de la base de données ..............................
  CMoteurAgenda(const QString &driver,        // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
                const QString &DataBaseName,  // nom de la base: si QODBC3 -> nom de la source de données (userDSN)
                const QString &user,          // = "root"
                const QString &password,      // = ""
                const QString &hostname,
                const QString &port,
                const char* confFile,
                const QString &baseLabel,
                QString*    errMess,
                QObject *   parent = 0) ;

  ~CMoteurAgenda();
  void initBase   (const QString &driver,        // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
                   const QString &DataBaseName,  // nom de la base: si QODBC3 -> nom de la source de données (userDSN)
                   const QString &user,          // = "root"
                   const QString &password,      // = ""
                   const QString &hostname,
                   const QString &port,
                   const char* confFile,
                   const QString &baseLabel,
                   QString*    errMess);

  int BaseConnect(const QString &driver,        // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
                             const QString &DataBaseName,  // nom de la base: si QODBC3 -> nom de la source de données (userDSN)
                             const QString &user,          // = "root"
                             const QString &pasword,       // = ""
                             const QString &hostname,      // = "localhost"
                             const QString &port,
                             QString*    errMess ,
                             const QString &baseLabel);
  int             SetConfBase(const char* confFile, QString *errMess);
  char           *SetConfBase_SetProperties(char *pt, QString &propertie, const char *token, int *line , QString &err);
  QString         makeNextPk(const QString &tableName, const QString host, const QString &pkFieldName);
  static void     GotoDebug();
  int             MASK_Append(const C_RendezVous &rendezVous, QString *errMess = 0);
  int             MASK_GetDay_RDV_List(const QDate &date, const QString &user, RDV_LIST &rdvList, QString *errMess =0);
  int             MASK_DayDelete( int dayOfWeek, const QString &user, QString *errMess =0);
  int             COL_Create(const QString name, const QString color, const QString duree, QString *errMess =0);
  int             COL_Get_List(MAP_COLOR &colorProfils, QString *errMess =0);
  int             COL_AllDelete(QString *errMess = 0);
  int             COL_RecordAllColorMap(MAP_COLOR *pColorMap, QString *errMess =0);
  int             COL_Delete( const QString name, QString *errMess =0);
  QString         RDV_IsThisRendezVousExist(const C_RendezVous &rendezVous, QString *errMess =0);
  QMap<QDate,int> RDV_Get_ListNbFor2Months(QDate date, const QString &user);
  int             RDV_Get_ListNb(QDate date, const QString &user);
  int             RDV_Get_List(QDate date, const QString &user,      RDV_LIST &rdvList, int mode = CMoteurAgenda::AllDates, QString *errMess =0 );
  int             RDV_Get_List(QDate date, const QString &user,      RDV_LIST *rdvList, int mode = CMoteurAgenda::AllDates, QString *errMess =0 );
  int             RDV_Get_List(QString reqDateDebStr, QString reqDateEndStr, const QString &user, RDV_LIST &rdvList, int mode = CMoteurAgenda::AllDates, QString *errMess =0);
  int             RDV_Get_List(QString reqDateDebStr, QString reqDateEndStr, const QString &user, RDV_LIST *rdvList, int mode = CMoteurAgenda::AllDates, QString *errMess =0);

  QString         RDV_Create(const C_RendezVous &rendezVous, QString *errMess =0 );
  int             RDV_Update(const C_RendezVous &rendezVous, QString *errMess =0 );
  int             RDV_Delete( const QString &primKey, QString *errMess =0);
  static QString  dayOfWeek(int dayOfWeek);
  QString         OutSQL_error(const QSqlQuery &cur, const char *messFunc =0, const char *requete=0);
  QString         OutSQL_error(const QSqlError &error, const char *messFunc =0, const char *requete =0);
  void            creerRDVFactices (QString user);

  void            SetMinDaysHeight(int = 15);
  void            SetVerboseMode(int mode) {m_isVerbose = mode;}
  int             GetVerboseMode() {return m_isVerbose;}
  void            SetEditNoteMode(int value = 1){m_EditNoteMode=value;}
  int             GetEditNoteMode(){return m_EditNoteMode;}
  void            SetRafraichissement(int raf= 0){m_Rafraichissement = raf;}
  int             GetRafraichissement(){return m_Rafraichissement;}
  void            SetDebDay(const QString &deb){m_TimeDeb = deb;}
  void            SetEndDay(const QString &end){m_TimeEnd = end;}
  QString         GetDebDay(){return m_TimeDeb;}
  QString         GetEndDay(){return m_TimeEnd;}
  void            SetModifConfirm(int modifConfirm= 0){m_ModifConfirm = modifConfirm;}
  int             isModifToConfirm(){return m_ModifConfirm;}
  void            SetRepresentation(int rep= 0){m_Representation = rep;}
  int             GetRepresentation(){return m_Representation;}
  void            SetAgendaWidth(int value= 300){m_AgendaWidth = value;}
  int             GetAgendaWidth(){return m_AgendaWidth;}
  void            SetAgendaWeekWidth(int value= 1200){m_AgendaWeekWidth = value;}   // CZA
  int             GetAgendaWeekWidth(){return m_AgendaWeekWidth;}                   // CZA
  void            SetNbDayInWeek(int value= 6){m_NbDayInModeWeek = value;}          // CZA
  int             GetNbDayInWeek(){return m_NbDayInModeWeek;}                       // CZA
  void            SetNbDayInModeDay(int value= 6){m_NbDayInModeDay = value;}
  int             GetNbDayInModeDay(){return m_NbDayInModeDay;}
  void            SetWeekOrDay(QString WoD = "DAY"){m_WeekOrDay = WoD;}             // CZA
  QString         GetWeekOrDay(){return m_WeekOrDay;}                               // CZA
  void            SetAgendaSimple(int presimple = 0){m_PresentSimple = presimple;}  // CZA
  void            SetTitleHeight(int = 15);                                         // CZA
  void            SetWeeksToSee(int value = 28){m_nbWeeksToSee=value;}
  int             GetWeeksToSee(){return m_nbWeeksToSee;}
  void            chargeListePlagesDisponibles(QTreeWidget  *pQlistView, QString user); // CZA
  void            ajouterPlageDispo(QTreeWidget  *pQlistViewPlage, QDateTime DatePlageDeb, QDateTime DatePlageFin, int fini); // CZA

  int             GetMinDaysHeight();
  void            setOpenCloseMode(int /*mode */ ){/*m_CloseAfterQuery=mode; if (m_CloseAfterQuery==0 && m_DataBase &&  m_DataBase->isOpen()==FALSE) m_DataBase->open();*/ }
  int             OpenBase();
  void            CloseBase(); //m_CloseAfterQuery
  QString         GetDataBaseLabel(){return m_BaseLabel;}
  // CZA ----
  long            GetPatientList(     QTreeWidget *pQlistView,     // pointeur sur une QListView ?  3 colonnes
                                  const QString   &qstr_nom,       // nom d'entr�e
                                  const QString   &qstr_prenom,    // prenom d'entr�
                                        QLabel    *statutMess=0,   // pointeur sur Qlabel de sortie message
                                        QString   *errMess=0       // pointeur sur Qlabel de sortie message
                                 );

  // --- CZA

//............................... DATA .............................................................................
 public:
  int           m_EditNoteMode;
  int           m_nbWeeksToSee;
  int           m_isVerbose;
  int           m_AgendaWidth;
  int           m_AgendaWeekWidth;          // CZA
  int           m_NbDayInModeWeek;          // CZA
  int           m_NbDayInModeDay;
  int           m_PresentSimple;            // CZA
  int           m_TitleHeight;              // CZA
  int           m_MinDaysHeight;
  int           m_ModifConfirm;
  int           m_Rafraichissement;
  int           m_Representation;       // 0/sur 1 ligne 1/sur deux lignes
  QString       m_WeekOrDay;            // Vide ou DAY = affichage journee, WEEK= Affichage Semaine // CZA
  QString       m_TimeDeb;
  QString       m_TimeEnd;
  //QString       m_log;
  //......................... configuration des tables ...............................................................
  QString      m_AGENDA_TBL_NAME;         // non de la table DU FICHIER GENERAL D'INDEX DES DOSSIERS
  QString      m_AGENDA_DATETIME;         // date et heure du RDV
  QString      m_AGENDA_DUREE;            // duree (en minutes)  RDV
  QString      m_AGENDA_GUID;             // un champ GUID unique qualifiant le numero de dossier du patient ayant ce RDV (si déj�  connu)
  QString      m_AGENDA_NOM;              // un champ NOM   qualifiant le nom du dossier
  QString      m_AGENDA_PRENOM;           // un champ PRENOM   qualifiant le prenom du dossier
  QString      m_AGENDA_TEL;              // téléphone (pour annuler)
  QString      m_AGENDA_PRIS_PAR;         // Utilisateur du programme
  QString      m_AGENDA_PRIS_AVEC;        // Médecin avec lequel le RDV a été pris
  QString      m_AGENDA_TYPE;             // Type de RDV
  QString      m_AGENDA_NOTE;             // Note
  QString      m_AGENDA_PRIM_KEY;         // une clef primaire
  QString      m_AGENDA_STATUS;           // etat du rendez vous
  QString      m_AGENDA_WHERE;            // endroit du rendez vous

  QString      m_COLOR_PROFIL_TBL_NAME;
  QString      m_COLOR_PROFIL_NAME;
  QString      m_COLOR_PROFIL_COLOR;
  QString      m_COLOR_PROFIL_DUREE;

  QString      m_MASK_TBL_NAME;
  QString      m_MASK_PRIM_KEY;
  QString      m_MASK_MOTIF;
  QString      m_MASK_TYPE;
  QString      m_MASK_HEURE;
  QString      m_MASK_DUREE;
  QString      m_MASK_USER;
  QString      m_MASK_DAYOFWEEK;


private:
  //......................... parametres de connexion ...............................................................
  QString       m_BaseLabel;
  int           m_IsValid;
  QTimer       *m_pReconnectTimer;

public slots:
  void On_ReconnectTimerDone();
signals:
  void Sign_ReconnectTimerDone();

};


#endif
