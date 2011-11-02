 /********************************* C_Dlg_Agenda.cpp ******************************
 *  #include "C_Dlg_Agenda.h"                                                     *
 * ...............................................................................*
 *   Project   :  MedinTux  (typographie made in france)                          *
 *   Copyright : (C) 2004-2005-2006-2007-2008-2009-2010 and for the eternity      *
 *   by        :  Sevin Roland     from   MedinTux project                        *
 *   E-Mail    : roland-sevin@medintux.org                                        *
 *   Web site  : www.medintux.org                                                 *
 * ...............................................................................*
 *                                                                                *
 *   This program is free software; you can redistribute it and/or modify         *
 *   it under the terms of the CeCILL Version 1 du 21/06/2004                     *
 *   License (GPL compatible)                                                     *
 *                              http://www.cecill.info/                           *
 *   as published by :                                                            *
 *                                                                                *
 *   Commissariat \303\240 l'Energie Atomique                                     *
 *   - CEA,                                                                       *
 *              31-33 rue de la F\303\251d\303\251ration, 75752 PARIS cedex 15.   *
 *                            FRANCE                                              *
 *   Centre National de la Recherche Scientifique                                 *
 *   - CNRS,                                                                      *
 *                            3 rue Michel-Ange, 75794 Paris cedex 16.            *
 *                            FRANCE                                              *
 *   Institut National de Recherche en Informatique et en Automatique             *
 *   - INRIA,                                                                     *
 *                            Domaine de Voluceau, Rocquencourt, BP 105, 78153    *
 *                            FRANCE                                              *
 *                                                                                *
 *         This program is distributed in the hope that it will be useful,        *
 *         but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *         MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                   *
 *         CeCILL  License (GPL compatible) for more details.                     *
 *                                                                                *
 **********************************************************************************/

#include "C_Dlg_Agenda.h"
#include "../../MedinTuxTools-QT4/CHtmlTools.h"
#include "../../MedinTuxTools-QT4/Theme/Theme.h"
#include "../../MedinTuxTools-QT4/Theme/ThemePopup.h"
#include "../../MedinTuxTools-QT4/CGestIni.h"
#include <QToolTip>
#include <QObject>
#include <QWhatsThis>
#include <QFileInfo>
#include <QCursor>
#include <QFont>
#include <QTreeWidgetItem>
#include <QDebug>
#include <QMessageBox>
#include <QMap>
#include <QBoxLayout>
#include <QDesktopWidget>
#include <QPalette>
#include <QHelpEvent>
#include <QByteArray>
#include <QPoint>
#include <QRect>
#include <QGradient>
#include <QClipboard>
#include <QMimeData>
#include <QApplication>

#define LOOKREFRESH          if (m_RefreshTimer) Slot_StopTimer(1)    // bloquer le raffraississement
#define UNLOOKREFRESH        if (m_RefreshTimer) Slot_StopTimer(0)
#include "C_Dlg_RdvTypeConfig.h"
/*
#ifndef AGENDA_IN_GUI
//====================================== C_Dlg_MainWindow ==========================================================
//------------------------ C_Dlg_MainWindow ---------------------------------------
C_Dlg_MainWindow::C_Dlg_MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass)
{   ui->setupUi(this);
    ui->mle_debut->setInputMask ("99-99-9999");
    ui->pushButtonDateDeb->setIcon ( Theme::getIcon("Left.png") );
    connect( ui->pushButtonDateDeb, SIGNAL( clicked ()  ),  this ,  SLOT(   On_pushButtonDateDebClicked()  ));
    //........... le logo de DMD .........................................
    ui->textLabelPixMap->setPixmap ( Theme::getIcon("DMD-Logo-03.png") );
    //........... creer et afficher la liste des jours ....................
    delete ui->scrollAreaWidgetContents;                                                  // virer le widget plac\303\251 dans la QScrollArea par designer car polue
    m_pMultiAgendaFrame = new QFrame ( ui->scrollArea_Days);
    m_pAgendaQLayout    = new QBoxLayout ( QBoxLayout::LeftToRight, m_pMultiAgendaFrame );
    m_pC_Frm_Agenda     = new C_Frm_Agenda(QDate::currentDate(), m_pMultiAgendaFrame, G_pCApp->m_PathAppli, G_pCApp->m_LocalParam, &m_C_RendezVousCopy, G_pCApp->m_SignUser);   // creer la liste des jours
    m_pC_Frm_Agenda->QFrame::move(300,0);
    //m_pAgendaQLayout->addWidget(m_pC_Frm_Agenda);
    //m_pAgendaQLayout->addWidget(m_pC_Frm_Agenda2);

    ui->scrollArea_Days->setWidget ( m_pMultiAgendaFrame );        // le placer en widget central de la QScrollArea pour le rendre scrollable
    //m_pC_Frm_Agenda  = new C_Frm_Agenda(QDate::currentDate(), ui->scrollArea_Days, G_pCApp->m_PathAppli, G_pCApp->m_LocalParam, G_pCApp->m_SignUser);   // creer la liste des jours
    //ui->scrollArea_Days->setWidget ( m_pC_Frm_Agenda );        // le placer en widget central de la QScrollArea pour le rendre scrollable
}
//------------------------ C_Dlg_MainWindow ---------------------------------------
C_Dlg_MainWindow::C_Dlg_MainWindow( const QString &pathAppli, const QString &localParam, const QString &signUser, QWidget *parent)
: QMainWindow(parent), ui(new Ui::MainWindowClass)
{   ui->setupUi(this);
    ui->mle_debut->setInputMask ("99-99-9999");
    ui->pushButtonDateDeb->setIcon ( Theme::getIcon("Left.png") );
    connect( ui->pushButtonDateDeb, SIGNAL( clicked ()  ),  this ,  SLOT(   On_pushButtonDateDebClicked()  ));
    //........... le logo de DMD .........................................
    ui->textLabelPixMap->setPixmap ( Theme::getIcon("DMD-Logo-03.png") );
    //........... creer et afficher la liste des jours ....................
    delete ui->scrollAreaWidgetContents;                                                  // virer le widget plac\303\251 dans la QScrollArea par designer car polue

    m_pMultiAgendaFrame = new QFrame ( ui->scrollArea_Days);
    m_pAgendaQLayout    = new QBoxLayout ( QBoxLayout::LeftToRight, m_pMultiAgendaFrame );
    m_pC_Frm_Agenda     = new C_Frm_Agenda(QDate::currentDate(), m_pMultiAgendaFrame, G_pCApp->m_PathAppli, G_pCApp->m_LocalParam, &m_C_RendezVousCopy, G_pCApp->m_SignUser);   // creer la liste des jours
    m_pC_Frm_Agenda->QFrame::move(10,0);
    m_pAgendaQLayout->addWidget(m_pC_Frm_Agenda);

    ui->scrollArea_Days->setWidget ( m_pMultiAgendaFrame );        // le placer en widget central de la QScrollArea pour le rendre scrollable
    //m_pC_Frm_Agenda = new C_Frm_Agenda(QDate::currentDate(), ui->scrollArea_Days, pathAppli, localParam, signUser);   // creer la liste des jours
    //ui->scrollArea_Days->setWidget ( m_pC_Frm_Agenda );        // le placer en widget central de la QScrollArea pour le rendre scrollable
}

//------------------------ ~C_Dlg_MainWindow ---------------------------------------
C_Dlg_MainWindow::~C_Dlg_MainWindow()
{delete ui;
}
//------------------------ reinitAgendaOnDate ---------------------------------------
void C_Dlg_MainWindow::On_pushButtonDateDebClicked()
{//m_pC_Frm_Agenda->clear();
}
#endif
*/


//====================================== C_Frm_Agenda ==========================================================
//------------------------ C_Frm_Agenda ---------------------------------------------
C_Frm_Agenda::C_Frm_Agenda(const QDate &date,
                           QWidget *parent               /*=0*/,
                           const QString& pathAppli      /*=""*/,
                           const QString &localParamIn   /*=""*/ ,
                           const QString &signUser       /*="admin"*/,
                           const QString &user           /*="admin"*/,
                           const QString &userNomPrenom  /*=""*/,
                           const QString &droits         /*="-sgn-agc-agm"*/,
                           const QString &googleUser     /*=""*/,
                           const QString &googlePass     /*=""*/
                           )
    : QFrame(parent)
{   m_PathAppli         = pathAppli;
    m_SignUser          = signUser;
    m_User              = user;
    m_UserNomPrenom     = userNomPrenom;
    m_pC_GoogleAPI      = 0;
    m_googleUser        = googleUser;
    m_googlePass        = googlePass;
    m_StartDate         = date;
    m_Magnetisme        = 5;
    m_Droits            = droits;
    if (m_User.length()==0) m_User = m_SignUser;
    m_PaintMode         = C_Frm_Agenda::DISABLED;
    m_pQWebView         = 0;
    m_BackgroundMessage = "";
    m_StylePopup        = " border: 1px solid #8f8f91; border-radius: 6px; font-size: 11px;";
    if (m_Droits.indexOf("agm")!=-1) m_PaintMode |= C_Frm_Agenda::FOR_OTHERS;
    if (m_Droits.indexOf("agc")!=-1) m_PaintMode |= C_Frm_Agenda::NORMAL;
    setAcceptDrops ( TRUE );


    //.......................... si mode normal alors activer et tout initialiser .........................................
    if (m_PaintMode >= C_Frm_Agenda::NORMAL)
    {
    //........................ on va peut etre en avoir besoin pour determiner path appli ........................
    //                         ( si non fourni en entree)
    QFileInfo qfi(qApp->argv()[0]);
    //.................... recuperer le path de l'application si pas fourni en entree ................................
    if (m_PathAppli.length()==0)
       {m_PathAppli    =  CGestIni::Construct_PathBin_Module("Agenda", qfi.path ());
       }
    //....................... si pas de parametre locaux fourni aller les chercher ...................................
    //                        dans Agenda.ini
    m_LocalParam   = localParamIn;
    if (m_LocalParam.length()==0)
       {CGestIni::Param_UpdateFromDisk(m_PathAppli+"Agenda.ini", m_LocalParam);
       }
    //...................... nomadisme ......................................................
    QString val1, connexionVar;
    m_IsGestionNomadisme       = FALSE;
    m_IsNomadeActif            = FALSE;
    if (CGestIni::Param_ReadParam(m_LocalParam.toAscii(),"Connexion", "Gestion nomadisme", &val1)==QString::null && (val1=val1.lower())!= "inactif")  // zero = pas d'erreur
       {if (val1=="fullreplication")
            m_IsGestionNomadisme = C_Frm_Agenda::fullReplication;
        else if (val1=="progmasterupdate")
            m_IsGestionNomadisme = C_Frm_Agenda::progMasterUpdate;
        else if (val1=="fullsynchro")
            m_IsGestionNomadisme = C_Frm_Agenda::fullSynchro;
       }
    if (m_IsGestionNomadisme && CGestIni::Param_ReadParam(m_LocalParam.toAscii(),"Connexion", "nomadisme", &val1)==QString::null && val1.lower()[0]=='a')  // zero = pas d'erreur
       {m_IsNomadeActif = TRUE;
       }
    if (m_IsNomadeActif) connexionVar     = "Nomade";
    else                 connexionVar     = "Master";
    //.............................. recuperer les parametres de connexion ..........................................
    //                               dans les parametres locaux
    QString driver, base, baseUser, password, hostname, port;
    if (CGestIni::Param_ReadParam(m_LocalParam.toAscii(), "Connexion", connexionVar, &driver, &base, &baseUser, &password, &hostname, &port ) != QString::null)
       { driver       = "QMYSQL3";
         base         = "DrTuxTest";
         baseUser     = "root";
         password     = "";
         hostname     = "localhost";
         port         = "3306";
        }
    //.............................. recuperer le fichier des noms des bases et champ ..........................................
    QString  baseCfg;
    CGestIni::Param_UpdateFromDisk(m_PathAppli + "DataBaseAgenda.cfg" , baseCfg);
    //.............................. creer le moteur de base de donnee de l'agenda ..........................................
    QString errMess;
    m_pCMoteurAgenda = new CMoteurAgenda(driver,        // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
                                         base,          // nom de la base: si QODBC3 -> nom de la source de donn\303\251es (userDSN)
                                         baseUser,      // = "root"
                                         password,      // = ""
                                         hostname,
                                         port,
                                         baseCfg.toAscii(),
                                         QString("BASE_AGENDA_%1").arg(signUser),   // important car lors fermeture l'utilisateur ne detruit que sa base
                                         &errMess,
                                         this);         // passer le parent afin que le moteur de base soit detruit avec l'agenda
    //....................... positionner le nombre de jours visible et l'ofset de jour de  depart  ............................................................
    m_StartBefore  = BEFORE_DAYS;          // valeurs par defaut
    m_NbDayToSee  =  NB_DAYS_TO_SEE;       // valeurs par defaut
    QString val;
    if (CGestIni::Param_ReadParam(m_LocalParam.toAscii(), "Agenda", "Nombre de jours visibles", &val)              == QString::null) m_NbDayToSee  = qMin(qMax(val.toInt(),10),400);
    if (CGestIni::Param_ReadParam(m_LocalParam.toAscii(), "Agenda", "Nombre de jours avant le premier jour", &val) == QString::null) m_StartBefore = qMin(qMax(val.toInt(),0),20);
    m_NbDayToSee += m_StartBefore;
    m_pCMoteurAgenda->SetDaysHeight(qMax(CGestIni::Param_ReadUniqueParam(m_LocalParam.toAscii(), "Agenda", "Hauteur jour").toInt(),15));
    setResoPixByMinutes(qMin(qMax(CGestIni::Param_ReadUniqueParam(m_LocalParam.toAscii(), "Agenda","Nombre pixels par minute").toInt(),1),15));
    //....................... positionner le bon mode openClose ................................................................................................
    m_Magnetisme = qMax(1,CGestIni::Param_ReadUniqueParam(m_LocalParam.toAscii(), "Agenda", "Magnetisme").toInt());
    m_pCMoteurAgenda->setOpenCloseMode(CGestIni::Param_ReadUniqueParam(m_LocalParam.toAscii(), "Connexion","Fermer requetes").toInt());
    //....................... recuperer les reglages des dimensions graphiques ds rdv ..........................................................................
    m_pCMoteurAgenda->SetModifConfirm (CGestIni::Param_ReadUniqueParam(m_LocalParam.toAscii(),"Agenda", "Modif confirm").toInt());
    m_pCMoteurAgenda->SetDebDay (CGestIni::Param_ReadUniqueParam(m_LocalParam.toAscii(),"Agenda", "Heure limite basse"));
    m_pCMoteurAgenda->SetEndDay (CGestIni::Param_ReadUniqueParam(m_LocalParam.toAscii(),"Agenda", "Heure limite haute"));
    m_pCMoteurAgenda->SetRafraichissement (CGestIni::Param_ReadUniqueParam(m_LocalParam.toAscii(),"Agenda", "Rafraichissement").toInt());
    m_pCMoteurAgenda->SetDaysHeight(qMax(CGestIni::Param_ReadUniqueParam(m_LocalParam.toAscii(), "Agenda", "Hauteur jour").toInt(),15));
    m_pCMoteurAgenda->SetMinDaysHeight(qMax(CGestIni::Param_ReadUniqueParam(m_LocalParam.toAscii(), "Agenda", "Hauteur mini jour").toInt(),3));
    m_pCMoteurAgenda->SetSpaceBetwenDays(CGestIni::Param_ReadUniqueParam(m_LocalParam.toAscii(), "Agenda", "Afficher espace vide").toInt());
    m_pCMoteurAgenda->SetProportionnalDays(CGestIni::Param_ReadUniqueParam(m_LocalParam.toAscii(), "Agenda", "Hauteur jour proportionnelle").toInt());
    m_pCMoteurAgenda->SetRepresentation(CGestIni::Param_ReadUniqueParam(m_LocalParam.toAscii(), "Agenda", "Representation").toInt());
    int agendaWidth = CGestIni::Param_ReadUniqueParam(m_LocalParam.toAscii(), "Agenda", "Largeur").toInt();
    m_pCMoteurAgenda->SetAgendaWidth(qMin(600,qMax(agendaWidth,150)));
    m_pCMoteurAgenda->SetVerboseMode(CGestIni::Param_ReadUniqueParam(m_LocalParam.toAscii(), "Agenda", "VerboseMode").toInt());
    m_pCMoteurAgenda->COL_Get_List(m_ColorProfils);
    m_pBMC = new C_BitMapCollection(Theme::getPath(TRUE)+"Agenda/", agendaWidth, m_pCMoteurAgenda->GetRepresentation()?DOUBLE_DAY_HEIGHT:DAY_HEIGHT);
    reinitAgendaOnDate(m_StartDate);
   }
 else
   { //.............. voir si texte dans le theme .....................................
     int agendaWidth = CGestIni::Param_ReadUniqueParam(m_LocalParam.toAscii(), "Agenda", "Largeur").toInt();
     agendaWidth = qMin(600,qMax(agendaWidth,150));
     QString themeDefAgenda   = Theme::getPath(TRUE)+"Agenda/agenda_inaccessible.html";
     if (m_PaintMode >= C_Frm_Agenda::FOR_OTHERS) themeDefAgenda   = Theme::getPath(TRUE)+"Agenda/agenda_multiple.html";
     CGestIni::Param_UpdateFromDisk(themeDefAgenda, m_BackgroundMessage);
     if (m_BackgroundMessage.length()==0) m_BackgroundMessage = tr("Schedule not available for this user: %1").arg(m_SignUser);
     //.............. positionner les widgets .....................................
     QDesktopWidget *pDesktop = QApplication::desktop();
     int h = pDesktop->availableGeometry().height();
     m_pQWebView = new QWebView(this);
     m_pQWebView->setObjectName(QString::fromUtf8("webView_Agenda"));
     m_pQWebView->setStyleSheet ( "background-color: white;" );
     m_pQWebView->setUrl(QUrl(themeDefAgenda));
     m_pQWebView->resize (agendaWidth, h );
     setFixedHeight (h);
     setFixedWidth(agendaWidth);
   }
}

//---------------------------- C_Frm_Agenda ------------------------------------------------
C_Frm_Agenda::~C_Frm_Agenda()
{ delete m_pBMC;
  if (m_pC_GoogleAPI) delete m_pC_GoogleAPI;
}

//---------------------------- getWebView ------------------------------------------------
QWebView *C_Frm_Agenda::getWebView()
{return m_pQWebView;
}

//---------------------------- baseReConnect ------------------------------------------------
void C_Frm_Agenda::baseReConnect(         const QString &driver,        // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
                                          const QString &baseToConnect, // nom de la base: si QODBC3 -> nom de la source de donn\303\251es (userDSN)
                                          const QString &user,          // = "root"
                                          const QString &pasword,       // = ""
                                          const QString &hostname,      // = "localhost"
                                          const QString &port           // = "port"
                                )
{if (m_PaintMode < C_Frm_Agenda::NORMAL) return;
 m_pCMoteurAgenda->BaseConnect(driver, baseToConnect, user, pasword, hostname, port, 0, m_pCMoteurAgenda->GetDataBaseLabel());
}
//------------------------ setGoogleLoginParam ---------------------------------------
void C_Frm_Agenda::setGoogleLoginParam (const QString &googleUser, const QString &googlePass )
{m_googleUser = googleUser;
 m_googlePass = googlePass;
}
//------------------------ changePixelParMinute ---------------------------------------
void C_Frm_Agenda::changePixelParMinute ( int pixelParMinute )
{setResoPixByMinutes(pixelParMinute);
 reinitAgendaOnDate(m_StartDate);
}
//------------------------ changeStartTime ---------------------------------------
void C_Frm_Agenda::changeStartTime ( const QString &time )
{m_pCMoteurAgenda->SetDebDay (time);
 reinitAgendaOnDate(m_StartDate);
}
//------------------------ changeEndTime ---------------------------------------
void C_Frm_Agenda::changeEndTime ( const QString &time )
{m_pCMoteurAgenda->SetEndDay (time);
 reinitAgendaOnDate(m_StartDate);
}
//------------------------ changeMagnetisme ---------------------------------------
void C_Frm_Agenda::changeMagnetisme ( int magnetisme )
{setMagnetisme(magnetisme);
 reinitAgendaOnDate(m_StartDate);
}
//------------------------ changeRafraichissement ---------------------------------------
void C_Frm_Agenda::changeRafraichissement(int rafraichissement)
{m_pCMoteurAgenda->SetRafraichissement(rafraichissement);
 reinitAgendaOnDate(m_StartDate);
}
//------------------------ changeModifConfirm ---------------------------------------
void C_Frm_Agenda::changeModifConfirm(int value)
{m_pCMoteurAgenda->SetModifConfirm(value);
}
//------------------------ changeRepresentation ---------------------------------------
void C_Frm_Agenda::changeRepresentation(int representation)
{m_pCMoteurAgenda->SetRepresentation(representation);
if (representation) m_pBMC->resizeBitMapToDayHeight(m_pCMoteurAgenda->GetAgendaWidth(), DOUBLE_DAY_HEIGHT);
else                m_pBMC->resizeBitMapToDayHeight(m_pCMoteurAgenda->GetAgendaWidth(), DAY_HEIGHT);
 reinitAgendaOnDate(m_StartDate);
}
//------------------------ changeAgendaWidth ---------------------------------------
void C_Frm_Agenda::changeAgendaWidth(int value)
{m_pCMoteurAgenda->SetAgendaWidth(value);
 m_pCMoteurAgenda->GetRepresentation();
 if (m_pCMoteurAgenda->GetRepresentation())
     m_pBMC->resizeBitMapToDayHeight(value, DOUBLE_DAY_HEIGHT);
 else
     m_pBMC->resizeBitMapToDayHeight(value, DAY_HEIGHT);
 reinitAgendaOnDate(m_StartDate);
}
//------------------------ reinitAgendaOnUser ---------------------------------------
void C_Frm_Agenda::reinitAgendaOnUser(const QString &signUser, const QString &droits)
{m_SignUser  = signUser;
 m_Droits    = droits;
 m_PaintMode = C_Frm_Agenda::DISABLED;
 if (m_Droits.indexOf("agm")!=-1) m_PaintMode |= C_Frm_Agenda::FOR_OTHERS;
 if (m_Droits.indexOf("agc")!=-1) m_PaintMode |= C_Frm_Agenda::NORMAL;
 if (m_PaintMode < C_Frm_Agenda::NORMAL) return;
 reinitAgendaOnDate(m_StartDate);
}
//------------------------ reinitAgendaOnDate ---------------------------------------
void C_Frm_Agenda::reinitAgendaOnDate(QDate dateDeb)
{m_StartDate = dateDeb;
 QMap<QDate,int> map = m_pCMoteurAgenda->RDV_Get_ListNbFor2Months(m_StartDate.addDays (-m_StartBefore ),m_SignUser);
 reinitAgendaOnDate(m_StartDate,map);
}

//------------------------ reinitAgendaOnDate ---------------------------------------
void C_Frm_Agenda::reinitAgendaOnDate(QDate dateDeb , QMap<QDate,int> map)
{clear();
 if (m_PaintMode >= C_Frm_Agenda::NORMAL)
    { int nb;
      m_StartDate = dateDeb;
      dateDeb     = dateDeb.addDays (-m_StartBefore );
      int      y  = FIRST_DAY_POS_Y;     // ofset de demarrage en haut de la fenetre agenda
      for (int i=0;  i<m_NbDayToSee; ++i)
          {
          if ( !map.contains(dateDeb) )
              nb = 0 ;
          else
              nb = map[dateDeb];
          //qDebug() << dateDeb.toString("dd-MM-yyyy");
          C_Frm_Day* pC_Frm_Day = new C_Frm_Day(
                                        m_pCMoteurAgenda,
                                        &m_ColorProfils,
                                        m_pBMC,
                                        dateDeb,
                                        m_SignUser,
                                        m_User,
                                        m_UserNomPrenom,
                                        this,
                                        getMagnetisme(),
                                        W_OFSET,
                                        y,
                                        getResoPixByMinutes()
                                       );
              if (pC_Frm_Day)
                 {y += appendDay (pC_Frm_Day  );
                  connect( pC_Frm_Day, SIGNAL( Sign_agenda_GetInfoFromUser(QString &, QString &, QString &, QString &)),
                           this,       SIGNAL( Sign_agenda_GetInfoFromUser(QString &, QString &, QString &, QString &)));
                  connect( pC_Frm_Day, SIGNAL( Sign_LauchPatient(const QString &, C_RendezVous *)),
                           this,       SIGNAL( Sign_LauchPatient(const QString &, C_RendezVous *)));

                 }
              dateDeb = dateDeb.addDays (1);
              pC_Frm_Day->show();
          }
      setFixedHeight (y);
      setFixedWidth(m_pCMoteurAgenda->GetAgendaWidth());
     }
}
//---------------------------------------- OnButtonGoogleClickedPtr --------------------------------------------
void C_Frm_Agenda::OnButtonGoogleClickedPtr (const char*, void *ptrOnDay)
{
 if (m_pC_GoogleAPI==0) m_pC_GoogleAPI = new C_GoogleAPI(this);
 if (! m_pC_GoogleAPI->login(m_googleUser, m_googlePass) )
    {GoogleConnectionErrorDisplay();
     return;
    }
 C_Frm_Day *pC_Frm_Day = (C_Frm_Day*) ptrOnDay;
 if (pC_Frm_Day) pC_Frm_Day->toGoogle(m_pC_GoogleAPI);
}

//---------------------------------------- toGoogleSynchonization --------------------------------------------
void C_Frm_Agenda::toGoogleSynchonization(int months)
{QDateTime dateDeb = QDateTime(m_StartDate.addDays (-m_StartBefore ), QTime::fromString("00:00:00","hhmmss"));
 QDateTime dateEnd = dateDeb.addMonths( months );
 toGoogle(dateDeb, dateEnd);
}

//---------------------------------------- toGoogle --------------------------------------------
void C_Frm_Agenda::toGoogle(const QDateTime &dateDeb, const QDateTime &dateEnd)
{
 QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
 if (m_pC_GoogleAPI==0) m_pC_GoogleAPI = new C_GoogleAPI(this);
 if (! m_pC_GoogleAPI->login(m_googleUser, m_googlePass) )
    {GoogleConnectionErrorDisplay();
     QApplication::restoreOverrideCursor ();
     return;
    }
 QString errMess       = "";
 QString reqDateDebStr = dateDeb.toString("yyyyMMddhhmmss");
 QString reqDateEndStr = dateEnd.toString("yyyyMMddhhmmss");
 RDV_LIST rdvList;
 int nb = m_pCMoteurAgenda->RDV_Get_List( reqDateDebStr,  reqDateEndStr, m_SignUser, rdvList, CMoteurAgenda::OnlyDateWhithName, &errMess );
 if (nb==0) {QApplication::restoreOverrideCursor (); return;}
 //.................. on efface les RDV deja presents entre ces deux dates ...................
 m_pC_GoogleAPI->deleteAllEventsBetweenTwoDates(dateDeb.date(), dateEnd.date());
 //.................. on prepare la liste des RDV google ........................
 C_GoogleEventList eventsList;
 for (int i  = 0; i < nb; ++i)
     { C_RendezVous *pRdv = dynamic_cast<C_RendezVous*>(rdvList[i]);
       eventsList.append( C_GoogleEvent(pRdv->m_Nom+";"+pRdv->m_Prenom                        ,
                                        pRdv->m_date                                          ,
                                        pRdv->m_date.addSecs(pRdv->m_Duree*60)                ,
                                        CHtmlTools::HtmlToAscii(pRdv->m_Note)                 ,
                                        pRdv->m_Where                                         ,
                                        C_RendezVous::getRdvColor(*pRdv, &m_ColorProfils)  ));
     }
 //............ on cree dans google les rdv en mode batch ..................
 m_pC_GoogleAPI->createSeveralEvents(eventsList);
 if (m_pC_GoogleAPI->getError().length())QMessageBox::question ((QWidget*)parent(),
                                                                tr("Error in Google transaction"),
                                                                tr("<b>Error C_Frm_Agenda::toGoogle() : error in Google transation:</b><br>%1").arg(m_pC_GoogleAPI->getError()),
                                                                QMessageBox::Cancel);
 QApplication::restoreOverrideCursor();
}
//---------------------------------------- GoogleConnectionErrorDisplay --------------------------------------------
void C_Frm_Agenda::GoogleConnectionErrorDisplay()
{QMessageBox::about(this, tr("Google connection failled"),
                    tr("<b>Google connection failled for Agenda for MedinTux.</b><br> ") +
                    tr("<p>Developed using <a href=\"http://qt.nokia.com\">Qt ")
                       + qVersion() + tr(" framework</a>.</p>"
                       "<p>Email : <a href=\"mailto:roland-sevin@medintux.org\">roland-sevin@medintux.org</a></p>"));
}

//----------------------------------- On_AgendaMustBeReArange -------------------------------------------
void C_Frm_Agenda::On_AgendaMustBeReArange()
{ if (m_PaintMode < C_Frm_Agenda::NORMAL) return;
  int     y  = FIRST_DAY_POS_Y;        // ofset de demarrage en haut de la fenetre agenda
  for (int i = 0; i < C_Frm_DayList::size(); ++i)
     {C_Frm_Day *pC_Frm_Day = at(i);
                 pC_Frm_Day->moveWidget( W_OFSET, y );
            y += pC_Frm_Day->getHeight();
     }
  setFixedHeight (y);
}

//====================================== C_Frm_Day ==========================================================
//-------------------------------------- C_Frm_Day ----------------------------------------------------------
C_Frm_Day::C_Frm_Day(CMoteurAgenda *pCMoteurAgenda ,
                     MAP_COLOR *pcolorProfils,
                     C_BitMapCollection  *pC_BitMapCollection,
                     QDate date,
                     const QString &signUser,
                     const QString &user,
                     const QString &userNomPrenom,
                     QWidget *parent,
                     int timeGranu,
                     int x, int y, int resoPix)
    : QFrame(parent )
{
 QFrame::move ( x, y );
 m_pBMC                = pC_BitMapCollection;
 m_pCMoteurAgenda      = pCMoteurAgenda;
 m_Magnetisme          = timeGranu;
 m_pColorProfils       = pcolorProfils;
 m_Date                = date;
 m_SignUser            = signUser;
 m_User                = user;
 m_PixByMinute         = resoPix;
 m_DayLF               = m_pCMoteurAgenda->GetRepresentation();
 m_BaseDayHeight       = m_DayLF?DOUBLE_DAY_HEIGHT:DAY_HEIGHT;
 m_Height              = m_BaseDayHeight;
 m_rafraich            = m_pCMoteurAgenda->GetRafraichissement();
 m_RefreshTimer        = 0;
 m_DontRecreateWidget  = 0;
 m_UserNomPrenom       = userNomPrenom;
 m_pQRubberBand        = new QRubberBand(QRubberBand::Rectangle, this); // ne sera active que lors des l'agrandissement deplacement du widget
 m_IsDayExpand         = 0;
 m_Width               = m_pCMoteurAgenda->GetAgendaWidth();

 if (m_rafraich>=4)
    {m_RefreshTimer        = new QTimer(this);
     m_RefreshTimer->setInterval(m_rafraich*1000);
    }
 setAcceptDrops (TRUE);
 resize(m_Width,     m_Height );
 m_HeureDeb = m_pCMoteurAgenda->GetDebDay(); if (m_HeureDeb.length()==0) {m_HeureDeb = "07:00"; m_pCMoteurAgenda->SetDebDay("07:00");}
 m_HeureFin = m_pCMoteurAgenda->GetEndDay(); if (m_HeureFin.length()==0) {m_HeureFin = "20:00"; m_pCMoteurAgenda->SetEndDay("20:00");}

 m_ButtonExpand = new CMyButton(m_pBMC->m_ButtonExpand_Pixmap, this, "", this);
 m_ButtonExpand->setGeometry(2,(m_BaseDayHeight/2)-m_pBMC->m_ButtonExpand_Pixmap.height()/2,m_pBMC->m_ButtonExpand_Pixmap.width()+2,m_pBMC->m_ButtonExpand_Pixmap.height()+2);
 if (m_DayLF)
    {int y =   LINE_RESUME_HEIGHT;
     m_ButtonExpand->setGeometry(2,y,m_pBMC->m_ButtonExpand_Pixmap.width()+2,m_pBMC->m_ButtonExpand_Pixmap.height()+2);
    }
 m_ButtonExpand->setFlat( TRUE );
 m_ButtonExpand->setToolTip ( "<font color=\"#000000\">"+tr("Opens and closes a page of the schedule.")+"</font>" );

 m_ButtonNewRDV = new CMyButton(m_pBMC->m_ButtonNewRDV_Pixmap, this, "", this);
 m_ButtonNewRDV->setGeometry(m_Width - 22,-1,20, m_BaseDayHeight);
 m_ButtonNewRDV->setFlat( TRUE );
 m_ButtonNewRDV->setToolTip ( "<font color=\"#000000\">"+tr("Add a new appointment at this date.")+"</font>" );

 m_ButtonSave = new CMyButton(m_pBMC->m_ButtonSave_Pixmap, this, "", this);
 m_ButtonSave->setGeometry(m_Width - 42,-1,20, m_BaseDayHeight);
 m_ButtonSave->setFlat( TRUE );
 m_ButtonSave->setToolTip ( "<font color=\"#000000\">"+tr("Save this day as template.</font>") );

 m_ButtonGoogle = new CMyButton(m_pBMC->m_ButtonGoogle_Pixmap, this, "", this);
 m_ButtonGoogle->setGeometry(m_Width - 62,-1,20, m_BaseDayHeight);
 m_ButtonGoogle->setFlat( TRUE );
 m_ButtonGoogle->setToolTip ( "<font color=\"#000000\">"+tr("Push to Google Agenda.</font>") );


 connect( m_ButtonNewRDV,  SIGNAL( Sign_ButtonClickedPtr (const char*, void *)  ),     this ,     SLOT(   OnButtonNewRDVClickedPtr (const char*, void *)  )  );
 connect( m_ButtonSave,    SIGNAL( Sign_ButtonClickedPtr (const char*, void *)  ),     this ,     SLOT(   OnButtonSaveClickedPtr (const char*, void *)  ) );
 connect( m_ButtonGoogle,  SIGNAL( Sign_ButtonClickedPtr (const char*, void *)  ),     parent ,   SLOT(   OnButtonGoogleClickedPtr (const char*, void *)  ) );
 connect( m_ButtonExpand,  SIGNAL( Sign_ButtonClickedPtr (const char*, void *)  ),     this ,     SLOT(   OnButtonExpandClickedPtr (const char*, void *)  ) );
 connect( this,            SIGNAL( Sign_AgendaMustBeReArange ()  ),                    parent ,   SLOT(   On_AgendaMustBeReArange()  ) );

 if (m_RefreshTimer)
    {connect(m_RefreshTimer, SIGNAL(timeout()), this, SLOT(Slot_RefreshView()));
     m_RefreshTimer->start();
    }

 /*
 if (CMoteurBase::IsThisDroitExist(G_pCApp->m_Droits, "agv")) {m_ButtonExpand->setEnabled(TRUE); }
 else                                                         {m_ButtonExpand->setEnabled(FALSE);}
 if (CMoteurBase::IsThisDroitExist(G_pCApp->m_Droits, "agc")) {m_ButtonSave->setEnabled(TRUE);  m_ButtonNewRDV->setEnabled(TRUE);}
 else                                                         {m_ButtonSave->setEnabled(FALSE); m_ButtonNewRDV->setEnabled(FALSE);}
 m_Default_labelColor = m_pQlabel_titre->paletteBackgroundColor();
 */
 m_pCMoteurAgenda->RDV_Get_List(m_Date, m_SignUser, m_cacheRDV_List);    // si il existe des rdv pour ce jour aller en chercher la liste
 m_ButtonNewRDV->hide();
 m_ButtonSave->hide();
 m_ButtonGoogle->hide();
 if (m_Date==QDate::currentDate()) ExpandDialog();
 setMouseTracking (TRUE );
}

//---------------------------- ~C_Frm_Day ------------------------------------------------
C_Frm_Day::~C_Frm_Day()
{
}
//---------------------------- toGoogle ------------------------------------------------
void C_Frm_Day::toGoogle(C_GoogleAPI *pC_GoogleAPI)
{   QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
    //.................. on efface les RDV deja presents ce jour ...................
    pC_GoogleAPI->deleteAllEventsBetweenTwoDates(getDate(), getDate().addDays(1));
    //.................. on prepare la liste des RDV google ........................
    C_GoogleEventList eventsList;
    for (int i  = 0; i < m_cacheRDV_List.count(); ++i)
        { C_RendezVous *pRdv = dynamic_cast<C_RendezVous*>(m_cacheRDV_List[i]);
          eventsList.append( C_GoogleEvent(pRdv->m_Nom+";"+pRdv->m_Prenom         ,
                                           pRdv->m_date                           ,
                                           pRdv->m_date.addSecs(pRdv->m_Duree*60) ,
                                           CHtmlTools::HtmlToAscii(pRdv->m_Note)  ,
                                           pRdv->m_Where                          ,
                                           getRdvColor(*pRdv)  ));
         }
    //............ on cree dans google les rdv en mode batch ..................
    pC_GoogleAPI->createSeveralEvents(eventsList);
    if (pC_GoogleAPI->getError().length())QMessageBox::question ((QWidget*)parent(),
                                                                 tr("Error in Google transaction"),
                                                                 tr("<b>Error in Google transation:</b><br>%1").arg(pC_GoogleAPI->getError()),
                                                                 QMessageBox::Cancel);
    QApplication::restoreOverrideCursor ();
}
//---------------------------- dropEvent ------------------------------------------------
void C_Frm_Day::dropEvent(QDropEvent *event)
 {  if (event->mimeData()->hasFormat("text/medintux_rdv_drag"))
        {event->acceptProposedAction ();
         QToolTip::hideText();
         QTimer::singleShot(10, this, SLOT(Slot_Drop_Rdv ()));
        }
 }
//---------------------------- dragEnterEvent ------------------------------------------------
void C_Frm_Day::dragEnterEvent(QDragEnterEvent *event)
{if (event->mimeData()->hasFormat("text/medintux_rdv_drag"))
    {event->acceptProposedAction ();
    }
 }
//---------------------------- dragMoveEvent ------------------------------------------------
void C_Frm_Day::dragMoveEvent(QDragMoveEvent * event)
 {  if (event->mimeData()->hasFormat("text/medintux_rdv_drag"))
       {QPoint     pos = mapFromGlobal ( QCursor::pos() );
        QString tm_str = "";
        C_RendezVous rdv; rdv.m_Duree = -2;
        if (isDayExpand())
           { QTime  tm   =  posY_toTime(pos.y());
             tm_str      =  tm.toString("hh:mm");
           }
        else
           { rdv         = getResumeRdvFromXY (  pos.x(),  pos.y() );;
             int mn      = XYToMinutesInResume ( pos.x(),pos.y());
             if (mn==-1) {QToolTip::hideText();      // cassos si pas dans une zone exploitable
                          event->ignore();
                          m_DropedRdv.m_GUID = "";   // effacer les donnees du rdv venant du drag and drop
                          return;
                         }
             int h       = mn/60;
             mn          = mn - (h*60);
             tm_str      = QString("%1:%2").arg(QString::number(h).rightJustified (2, '0'),QString::number(mn).rightJustified (2, '0'));
           }
        m_DropedRdv  = C_RendezVous::unSerialize(QString(event->mimeData()->data ( "text/medintux_rdv_drag" ))); // intialiser le rdv sur les donnees venant du drag and drop

        if (rdv.m_GUID.length()||rdv.m_Nom.length()||rdv.m_Prenom.length())
           {tm_str = "<table cellSpacing=\"0\"  cellpadding=\"4\" width=100% border=\"1\">"    // #FF8000
                        "<tbody>"
                        "<tr>"
                        "<td width=100% align=\"left\" bgcolor=\"#FEFFDD\">"+
                        QString(tr("On the")+"&nbsp;<b><font color=\"#0000FF\">%1</font></b>&nbsp;"+tr("at")+"&nbsp;<b><font color=\"#e80d0d\">%2</font></b>&nbsp;"+tr("(duration")+"&nbsp;:&nbsp;<b><font color=\"#e80d0d\">%3</b></font>&nbsp;mn) <b>"+tr("Occupied")+"</b>&nbsp;par&nbsp;<font color=\"#FF8000\"><b>%4</b></font></b>"
                        "</TD>"
                        "</TBODY>"
                        "</TABLE>").arg(m_Date.toString("dd-MM-yyyy"),rdv.m_date.time().toString("hh:mm"), QString::number(rdv.m_Duree), rdv.m_Nom.replace(" ","&nbsp;")+"&nbsp;"+rdv.m_Prenom.replace(" ","&nbsp;")) ;
           }
        else if (rdv.m_PrimKey.length())
           {tm_str = "<TABLE cellSpacing=\"0\"  cellpadding=\"4\" width=100% border=\"1\">"
                        "<TBODY>"
                        "<TR>"
                        "<TD width=100% align=\"left\" bgcolor=\"#FEFFDD\">"+
                        QString(tr("The")+"&nbsp;<b><font color=\"#0000FF\">%1</font></b>&nbsp;"+tr("at")+"&nbsp;<b><font color=\"#e80d0d\">%2</font></b>&nbsp;"+tr("(duration")+"&nbsp;:&nbsp;<b><font color=\"#e80d0d\">%3</b></font>&nbsp;mn <b>"+tr("available")+"</b>&nbsp;pour&nbsp;"
                        "<font color=\"#FF8000\"><b>%4</b></font>&nbsp;"+tr("with")+"&nbsp;<b><font color=\"#0000FF\">%5</font></b>"
                        "</TD>"
                        "</TBODY>"
                        "</TABLE>").arg( m_Date.toString("dd-MM-yyyy"), rdv.m_date.time().toString("hh:mm"), QString::number(rdv.m_Duree), m_DropedRdv.m_Nom.replace(" ","&nbsp;") + "&nbsp;" + m_DropedRdv.m_Prenom.replace(" ","&nbsp;") ,m_UserNomPrenom.replace(" ","&nbsp;")) ;
           }
        else
           {tm_str = "<TABLE cellSpacing=\"0\"  cellpadding=\"4\" width=100% border=\"1\">"
                        "<TBODY>"
                        "<TR>"
                        "<TD width=100% align=\"left\" bgcolor=\"#FEFFDD\">"+
                        tr("The")+QString("&nbsp;<b><font color=\"#0000FF\">%1</font></b>&nbsp;"+tr("at")+"&nbsp;<b><font color=\"#e80d0d\">%2</font> "+tr("Creation")+"</b>&nbsp;"+tr("for")+"&nbsp;<font color=\"#FF8000\"><b>%3</b></font>"
                        "&nbsp;"+tr("with")+"&nbsp;<b><font color=\"#0000FF\">%4</font></b> "
                        "</TD>"
                        "</TBODY>"
                        "</TABLE>").arg(m_Date.toString("dd-MM-yyyy"),tm_str, m_DropedRdv.m_Nom.replace(" ","&nbsp;") + "&nbsp;" + m_DropedRdv.m_Prenom.replace(" ","&nbsp;"), m_UserNomPrenom.replace(" ","&nbsp;")) ;
           }
        pos = QCursor::pos(); pos.setX(pos.x()+30);
        QToolTip::showText (pos,  tm_str, this, this->rect() );
        event->acceptProposedAction ();
       }
 }

//---------------------------- dragLeaveEvent ------------------------------------------------
void C_Frm_Day::dragLeaveEvent ( QDragLeaveEvent *  )
{   QToolTip::hideText();
    m_DropedRdv.m_GUID = "";   // effacer les donnees du rdv venant du drag and drop
}
//------------------------ Slot_Drop_Rdv -----------------------------------------------------
void C_Frm_Day::Slot_Drop_Rdv ()
{  QMouseEvent mouseEvent(QEvent::MouseButtonPress, mapFromGlobal ( QCursor::pos() ), Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);
   On_Day_mousePressEvent ( &mouseEvent );
}
//------------------------ Slot_RefreshView ---------------------------------------
void  C_Frm_Day::Slot_RefreshView()
{if (m_DontRecreateWidget) return;
 m_pCMoteurAgenda->RDV_Get_List(m_Date, m_SignUser, m_cacheRDV_List);    // si il existe des rdv pour ce jour aller en chercher la liste
 if (isDayExpand())
    {if (m_cacheRDV_List.count())
        { RecreateRendezVousListWidget(m_cacheRDV_List);                 // recreer les widgets avec
        }
     else
        {clear();
        }
    }
 ReArangeIfDayHeightChange();                 // reajuster eventuellement la hauteur du jour et reorganiser les jours sous jacents et mettre a jour la hauteur du jour
}
//---------------------------------------- computeDayHeight --------------------------------------------
int  C_Frm_Day::computeDayHeight()
{if (isDayExpand())  return (getStartTime().secsTo(getStopTime())/60*getResoPixByMinutes()) + 10 + m_BaseDayHeight +  FIRST_DAY_POS_Y;
 else                return m_BaseDayHeight;
}

//---------------------------------------- ReArangeIfDayHeightChange --------------------------------------------
// verifie si la hauteur calculee du jour est modifiee (exemple apres deplacement d'un rdv apres la limite sup ou inf)
// si elle a ete modifie remet a jour la variable de hauteur m_Height avec la nouvelle hauteur calculee
// et reorganise les jours sous jacents avec la ouvelle hauteur
void  C_Frm_Day::ReArangeIfDayHeightChange()
{ //................. si jour replie la hauteur est fixe ..........................
  //                  donc on a juste a raffraichier l'affichage du resume
  if (!isDayExpand())
     {update();
     }
  else
    { //............. on note la hauteur actuelle .................................
      int actualHeight    = m_Height;                // on note la hauteur actuellement en cours
      m_Height            = computeDayHeight();      // on calcule la hauteur souhaitable
      //............ si pas la meme que celle en place ..................
      //             on reajuste les widgets de rdv sous jacents
      if (actualHeight!=m_Height)
         {resize(m_Width, m_Height );
          emit Sign_AgendaMustBeReArange();
         }
      else
         {update();      // si hauteur non modifie il n'y a juste qu'a raffraichir l'affichage
         }
    }
}

//---------------------------------------- ExpandDialog --------------------------------------------
void  C_Frm_Day::ExpandDialog()
{if (!isDayExpand())
    //............................... SI deja replie alors expandre et construire la liste des widgets rendez vous .........................
    {m_IsDayExpand = 1;
     int nb = m_cacheRDV_List.count(); //m_pCMoteurAgenda->RDV_Get_List(m_Date, m_SignUser, m_cacheRDV_List);    // si il existe des rdv pour ce jour aller en chercher la liste
     if (nb==0) nb = MaskDayToAgendaDay (m_cacheRDV_List);   // soit il en existe pas et on place le masque de la semaine pr\303\251vu (si il existe)
     if (nb) RecreateRendezVousListWidget(m_cacheRDV_List);                                 // recreer les widgets avec la liste des rendez vous
     m_ButtonNewRDV->show();
     m_ButtonSave->show();
     m_ButtonGoogle->show();
     m_ButtonExpand->setIcon(m_pBMC->m_ButtonExpand_Close_Pixmap); // icone pour le jour ouvert
    }
 else
    //............................... SI deja expande alors replier et detruire la liste des rendez vous .........................
    {m_IsDayExpand = 0;
     m_ButtonNewRDV->hide();
     m_ButtonSave->hide();
     m_ButtonGoogle->hide();
     clear();  // effacer les widgets
     m_ButtonExpand->setIcon(m_pBMC->m_ButtonExpand_Open_Pixmap); // icone pour le jour ferme
    }
 m_Height = computeDayHeight();
 resize(m_Width, m_Height );
}

//------------------------ paintEvent ---------------------------------------
void C_Frm_Day::paintEvent ( QPaintEvent * /*event*/)
{
  QPainter p(this);
  QFont    f            = font();
  int  y_deb            = FIRST_DAY_POS_Y + m_BaseDayHeight;
  QDate curDt           = QDate::currentDate();
  int timePosPixmapX    = 0;
  int timePosPixmapY    = 0;
  //////////////////////////////////////////////////// JOUR EXPANSE ////////////////////////////////////////////////////////
  if (isDayExpand())    // si jour expand
     {
       QTime tps  = getStartTime();
       int y_der  = tps.secsTo(getStopTime())/60*getResoPixByMinutes();
       //............................ titre du jour ..............
       f.setPointSize(8); f.setBold(TRUE); p.setFont ( f );
       p.drawPixmap (0, y_deb-m_BaseDayHeight-3, m_pBMC->m_HeadOpenDay_Pixmap );
       p.setPen (Qt::black);
       p.drawText ( QPoint(DAY_OFS_X,y_deb-8), getDate().toString("ddd dd MMMM yyyy") );
       if (m_Date==curDt && m_rafraich>=4)
          {p.setPen (QColor ( "#d22f2f" ));
           p.drawText (QPoint(DAY_OFS_X + 170, y_deb-8),QTime::currentTime().toString("hh:mm:ss"));
           //........ heure courante .........
           int    mnDeb      = tps.hour()*60 + tps.minute();   // initialise au debut de  if (isDayExpand())
           QTime     tm      = QTime::currentTime();
           int    mnCur      = tm.hour()*60+tm.minute(); mnCur -= mnDeb;
           int     posY      = mnCur*getResoPixByMinutes();
           p.drawPixmap (0, posY+y_deb-m_pBMC->m_AgendaHourIndic_Pixmap.height()/2, m_pBMC->m_AgendaHourIndic_Pixmap);
          }
       //.................. graduations ........................
       f.setPointSize(6); f.setBold(TRUE); p.setFont ( f );
       for (int y = 0; y <= y_der; y += 15*getResoPixByMinutes())
           { int    posY  = y+y_deb;
             QString txt  = tps.toString("hh:mm");
             if (txt==m_HeureDeb)       {p.setPen (Qt::darkRed);   f.setBold(TRUE);   p.setFont ( f );}
             else if (txt==m_HeureFin)  {p.setPen (Qt::darkRed);   f.setBold(TRUE);   p.setFont ( f );}
             else if (txt.mid(3)=="00") {p.setPen (Qt::darkGray);  f.setBold(TRUE);   p.setFont ( f );}
             else                       {p.setPen (Qt::lightGray); f.setBold(FALSE);  p.setFont ( f );}
             p.drawLine (30 , posY, m_Width,posY);
             p.drawText ( QPoint(0,posY+5), tps.toString(txt) );
             tps=tps.addSecs(60*15);
           }  //endfor (int y = 0; y < y_der; y += 15)
       p.setPen (Qt::lightGray);
       p.drawLine (m_Width-1 , 0, m_Width-1,y_der+50);
     } // endif (pC_Frm_Day->isDayExpand())
  //////////////////////////////////////////////////// JOUR REPLIE ////////////////////////////////////////////////////////
  else
     {
      QTime tpsDeb      = getStartTime();
      QTime tpsEnd      = getStopTime();
      int nbMnToSee     = getNbMinutesToseeInResume(tpsDeb, tpsEnd);
      int nbRdv         = m_cacheRDV_List.count();
      int    mnDeb      = tpsDeb.hour()*60 + tpsDeb.minute();
      int   ofsetX      = DAY_OFS_X;
      int     posX      = 0;
      int     posY      = 0;
      int    mnCur      = 0;
      int        h      = 0;
      int        w      = 0;
      QRect     rp;
      int secondResumeY =  HEAD_RESUME_OFY + FIRST_DAY_POS_Y + LINE_RESUME_HEIGHT + 5;    //HEAD_RESUME_OFY+FIRST_DAY_POS_Y +  LINE_RESUME_HEIGHT + 5
      C_RendezVous *rdv = 0;

      //..................... bitmap de deco ........................
      if      (m_Date.dayOfWeek() == Qt::Saturday)  p.drawPixmap (0, y_deb-m_BaseDayHeight-3, m_pBMC->m_HeadSatDay_Pixmap );
      else if (m_Date.dayOfWeek() == Qt::Sunday)    p.drawPixmap (0, y_deb-m_BaseDayHeight-3, m_pBMC->m_HeadSunDay_Pixmap );
      else                                          p.drawPixmap (0, y_deb-m_BaseDayHeight-3, m_pBMC->m_HeadCloseDay_Pixmap);


      //if (nbRdv)   // ....... bitmap du resume (deux si double ligne) ..........
         {
          if (nbRdv) p.drawPixmap (ofsetX-5, HEAD_RESUME_OFY+y_deb-m_BaseDayHeight, m_pBMC->m_HeadResume_Pixmap );
          p.setPen ("#6b6a6a");
          rp = m_pBMC->m_HeadResume_Pixmap.rect();
          rp.setX(ofsetX-5);
          rp.setY(HEAD_RESUME_OFY+y_deb-m_BaseDayHeight);
          rp.setHeight(m_pBMC->m_HeadResume_Pixmap.height());
          rp.setWidth(m_pBMC->m_HeadResume_Pixmap.width());
          p.drawRoundedRect (rp, 4, 4);
          if  (m_DayLF>0)
              {rp.setY(secondResumeY);
               rp.setWidth(m_pBMC->m_HeadResume_Pixmap.width());
               rp.setHeight(m_pBMC->m_HeadResume_Pixmap.height());
               if (nbRdv) p.drawPixmap (ofsetX-5, secondResumeY, m_pBMC->m_HeadResume_Pixmap );
               p.drawRoundedRect (rp, 4, 4);
              }
         }
      if (m_Date==curDt && m_rafraich>=4 )  //....... heure courante ..........
         {QTime tm           = QTime::currentTime();
          mnCur              = tm.hour()*60+tm.minute();
          if ( tm>tpsDeb &&  tm<tpsEnd )  // on calcule maintenant et on affiche le cursur des heures en dernier pour ne pas se faire recouvrir
             {QPoint point   = computeResumePosXYFromTimeInMinute(mnCur, mnDeb, nbMnToSee, m_pBMC->m_HeadResume_Pixmap.width()-LINE_RESUME_XMARG, LINE_RESUME_HEIGHT + 5, m_DayLF?2:1);
              timePosPixmapX = point.x() + ofsetX;
              timePosPixmapY = point.y() + 2;
             }
          f.setPointSize(7); f.setBold(FALSE); p.setFont ( f );
          p.setPen (QColor ( "#d22f2f" ));
          p.drawText ( QPoint(220, y_deb-6), QTime::currentTime().toString("hh:mm:ss") );
         }
      f.setPointSize(6); p.setFont ( f );
      //..................... graduations horaires ........................
      for (int i = 0; nbRdv && i <= nbMnToSee; i += 15)
          {mnCur        = mnDeb + i;
           h            = mnCur/60;
           QPoint point = computeResumePosXYFromTimeInMinute(mnCur, mnDeb, nbMnToSee, m_pBMC->m_HeadResume_Pixmap.width()-LINE_RESUME_XMARG, LINE_RESUME_HEIGHT + 5, m_DayLF?2:1);
           posX         = point.x() + ofsetX;
           posY         = point.y() + 20;
           if (h*60==mnCur)
              {p.setPen (QColor ( "#ff0000" ));
               p.drawLine (posX , posY, posX, posY+2);
               p.setPen (QColor ( Qt::darkGray ));
               if (h==0)         p.drawText ( QPoint(posX+2, posY+9), QString::number(h) );
               else if (h>9)     p.drawText ( QPoint(posX-5, posY+9), QString::number(h) );
               else              p.drawText ( QPoint(posX-2, posY+9), QString::number(h) );
              }
           else
              {p.setPen (QColor ( Qt::white ));
               p.drawLine (posX , posY, posX, posY+2);
              }
          }
      //................... lire la liste des rendez-vous et afficher le resume colore .....................
      for (int i = 0; i < nbRdv; ++i)
          {//.......... creer et ajouter le widget du rendez vous .................................
           rdv         = m_cacheRDV_List[i];
           QRect rect2 = QRect(-1,-1,-1,-1);     // est initialise si un rectangle s'etend sur deux lignes (un bout a la ligne d'avant, l'autre sur l'autre ligne)
           QRect rect  = computeResumeRdvGeometry(rdv, mnDeb, nbMnToSee, m_pBMC->m_HeadResume_Pixmap.width()-LINE_RESUME_XMARG, LINE_RESUME_HEIGHT + 5, m_DayLF?2:1,rect2);
           w           = rect.width();
           h           = rect.height();
           posX        = rect.x() + ofsetX;
           posY        = rect.y() + 8;

           //............ tracer le rectangle normal (ou du haut) ............
           QColor color(getRdvColor(*rdv));                  // couleur rdv
           p.fillRect ( posX, posY, w, 11, color);           // tracer rectangle plein
           p.setPen (color.darker(120));                     // tracer le contour en le foncant
           p.drawRoundedRect ( posX, posY, w, h, 0, 0);      // radius 0 ->rectangle

           //............ tracer les elements relatifs a un rendez vous sur deux lignes ............
           if (rect2.x()!=-1)           // si le rectangle est coupe en deux (un bout a la ligne d'avant, l'autre sur l'autre ligne) on trace l'autre bout
              {//............ tracer le triangle de droite en haut qui signale la coupure ............
               posX += w;          // se mettre a droite du rectangle
               //p.setPen (color.darker(180));
               //p.drawLine (posX , posY, posX, posY + h);
               ++posX;
               p.setPen (QColor("#FF0000"));
               p.drawLine (posX , posY+2, posX, posY + h -2);
               ++posX;
               p.drawLine (posX , posY+4, posX, posY + h -4);
               ++posX;
               p.drawLine (posX , posY+5, posX, posY + h -5);

               //............ tracer le rectangle du bas ............
               w           = rect2.width();
               posX        = rect2.x() + ofsetX;
               posY        = rect2.y() + 8;
               p.fillRect ( posX, posY, w, 11, color);           // tracer rectangle plein
               p.setPen (color.darker(120));                     // tracer le contour en le foncant
               p.drawRoundedRect ( posX, posY, w, h, 0, 0);      // radius 0 ->rectangle

               //............ tracer le triangle de gauche en bas qui signale la coupure ............
               //p.setPen (color.darker(180));
               //p.drawLine (posX , posY , posX, posY + h);
               --posX;
               p.setPen (QColor("#FF0000"));
               p.drawLine (posX , posY+2, posX, posY + h -2);
               --posX;
               p.drawLine (posX , posY+4, posX, posY + h -4);
               --posX;
               p.drawLine (posX , posY+5, posX, posY + h -5);
               //........ retablir valeurs pour tracage du point ...................
               w     = rect.width();
               posX  = rect.x() + ofsetX;
              }
           //........... si occupe le signaler avec un point noir heu! rouge............
           //            (pas le comedon)
           if (rdv->m_GUID.length()||rdv->m_Nom.length()||rdv->m_Prenom.length())
              {posY  = rect.y() + 12;
               if (m_DayLF)
                  {p.fillRect ( posX+w/2-1, posY, 4, 4, QColor(Qt::red)); // tracer rectangle plein
                   p.fillRect ( posX+w/2-1, posY, 2, 2, QColor(Qt::red).lighter(160));
                  }
               else
                   {
                    p.fillRect ( posX+w/2, posY, 2, 2, QColor(Qt::red)); // tracer rectangle plein
                    p.fillRect ( posX+w/2, posY, 1, 1, QColor(Qt::red).lighter(160));
                   }
              }
         }
      //..................... nb rdv........................
      if (nbRdv)
         {
          f.setPointSize(7); f.setBold(FALSE); p.setFont ( f );
          p.setPen (QColor("#FF0000"));
          p.drawText ( QPoint(130, y_deb-6),QString::number(nbRdv));
          f.setPointSize(7); f.setBold(FALSE); p.setFont ( f );
          p.setPen (QColor("#000000"));
          p.drawText ( QPoint(144, y_deb-6), tr(" Appointment") );
         }
      //............................ titre du jour ................................................
      f.setPointSize(7); f.setBold(FALSE); p.setFont ( f );
      p.setPen (Qt::black);
      p.drawText ( QPoint(DAY_OFS_X, y_deb-6), getDate().toString("ddd dd MMMM yyyy") );

     }  // end else if (isDayExpand())
  ////////////////////////////////// COMMON /////////////////////////////////
  if (m_Date==curDt)       // tracer les rectangles interieurs rouges du jour courant
     { QColor color("#d22f2f");
       p.setPen (color.lighter(180));
       p.drawRoundedRect (2, 2, m_Width-4, m_BaseDayHeight-4, 2, 2);
       p.setPen (color.lighter(195));
       p.drawRoundedRect (3, 3, m_Width-6, m_BaseDayHeight-6, 2, 2);
       p.setPen (color);
     }
  else
     { p.setPen (Qt::black);
     }
  //............. cadre noir du jour .....................................
  p.drawRoundedRect (1, 1, m_Width-2, m_BaseDayHeight-2, 2, 2);
  if (timePosPixmapX) p.drawPixmap (timePosPixmapX, timePosPixmapY, m_pBMC->m_AgendaTimeArrow_Pixmap );
  //QFrame::paintEvent(event);
}
//---------------------------------------- generate_cacheRDV_List_FromDayWidget --------------------------------------------
void C_Frm_Day::generate_cacheRDV_List_FromDayWidget()
{m_cacheRDV_List.clear();                      // detruit aussi les objets pointes par les pointeurs
 for (int i = 0; i < C_Frm_RdvList::size(); ++i)
      {C_RendezVous *pC_RendezVous = new C_RendezVous();
       *pC_RendezVous = *at(i);                // on recupere et copie les valeurs du widget
        m_cacheRDV_List.append(pC_RendezVous);  // ne surtout pas ajouter directement le pointeur sur l'instance du rdv du widget
      }
}

//------------------------ Slot_StopTimer ---------------------------------------
void  C_Frm_Day::Slot_StopTimer(int state)
{if (state) ++m_DontRecreateWidget;
 else       --m_DontRecreateWidget;
 if(m_RefreshTimer==0) return;
 if (state)  {m_RefreshTimer->stop();  if (m_pCMoteurAgenda->GetVerboseMode()) qDebug()<< tr("DontCreate set to : %1").arg(m_DontRecreateWidget);}
 else        {m_RefreshTimer->start(); if (m_pCMoteurAgenda->GetVerboseMode()) qDebug()<< tr("DontCreate set to : %1").arg(m_DontRecreateWidget);}
}

//------------------------ event ---------------------------------------
bool C_Frm_Day::event(QEvent * event )
{   int x,y;
    switch ((int)event->type())
    {/*  marche pas ??? clavier non recu ??
     case QEvent::KeyPress:
       {QKeyEvent *pQKeyEvent = (QKeyEvent*) event;
        if (x>= 22 && y>= HEAD_RESUME_OFY && y<= HEAD_RESUME_OFY + 20 && x<=m_Width-4)
           {switch (pQKeyEvent->key ())
               {case Qt::Key_Left:
                     { QCursor::setPos ( QCursor::pos().x()-1, QCursor::pos().y() );
                     }  return TRUE;
                case Qt::Key_Right:
                     { QCursor::setPos ( QCursor::pos().x()+1, QCursor::pos().y() );
                     }  return TRUE;
               }
           }
       }
     */
    case QEvent::ToolTip:
       {QToolTip::showText (QCursor::pos(), toolTip () , this);
        return TRUE;
       }
    case QEvent::MouseMove:
       {
        QMouseEvent *pQMouseEvent = (QMouseEvent*) event;
        x = pQMouseEvent->pos().x();
        y = pQMouseEvent->pos().y();
        C_RendezVous rdv;
        if (isDayExpand())      rdv = getRdvUnderMouse(y);
        else                    rdv = getResumeRdvFromXY ( x, y );
        if (rdv.getDuree() != 0)
           {setToolTip (rdv.getQWhatsThisString(Theme::getPath(TRUE), getRdvColor(rdv)));
           }
        else
           {int mn  = -1;
            int nbMnToEnd;
            if (isDayExpand())     mn = posY_toMinutes(y);
            else                   mn = XYToMinutesInResume (x,y, &nbMnToEnd);
            if (mn!=-1)
               {int mnNext;
                getRdvAfterThisTimeInMinutes( mn, &mnNext);
                if (mnNext==-1) mnNext  = nbMnToEnd;    // 24h00
                else            mnNext -= mn;
                int h   = mn/60;
                mn      = mn - (h*60);
                int hD  = mnNext/60;
                mnNext  = mnNext - (hD*60);
                setToolTip ("<font color=\"#000000\">"+QString(tr("Free space at : %1 h %2 mn \nmaximum possible duration:")+ "%3 h %4 mn</font>").arg(QString::number(h),QString::number(mn),QString::number(hD),QString::number(mnNext)));
               }
           }
       }
    } //endswitch event->type()()
    QFrame::event(event);
    return TRUE;
}
//------------------------ getRdvColor ---------------------------------------
QString C_Frm_Day::getRdvColor(const C_RendezVous & rdv)
{   return C_RendezVous::getRdvColor(rdv, m_pColorProfils);
}

//------------------------ getResumeRdvFromXY ---------------------------------------
//  NOTE : suppose que m_cacheRDV_List est a jour car se fonde dessus,
//         car lors d'un jour replie les widgets sont non disponibles
C_RendezVous C_Frm_Day::getResumeRdvFromXY ( int x, int y )
{   C_RendezVous rdvNull;   rdvNull.m_Duree = 0;
    C_RendezVous *pRdv =  getRdvUnderMouseInResume(x,y);
    if (pRdv) return *pRdv;
    return rdvNull;
}
//------------------------ getNbMinutesToseeInResume ---------------------------------------
int C_Frm_Day::getNbMinutesToseeInResume()
{QTime tpsDeb      = getStartTime();
 QTime tpsEnd      = getStopTime();
 return getNbMinutesToseeInResume(tpsDeb,tpsEnd);
}
//------------------------ getNbMinutesToseeInResume ---------------------------------------
int C_Frm_Day::getNbMinutesToseeInResume(const QTime &tpsDeb, const QTime &tpsEnd)
{return (tpsDeb.secsTo(tpsEnd)/60)+3;
}
 //------------------------ getRdvUnderMouseInResume ---------------------------------------
 //  NOTE : suppose que m_cacheRDV_List est a jour car se fonde dessus,
 //         car lors d'un jour replie les widgets sont non disponibles
C_RendezVous *C_Frm_Day::getRdvUnderMouseInResume ( int x, int y , int *index /* = 0 */)
{   QTime tpsDeb         = getStartTime();
    QTime tpsEnd         = getStopTime();
    int nbMnToSee        = getNbMinutesToseeInResume(tpsDeb, tpsEnd);
    int nbRdv            = m_cacheRDV_List.count();
    int    mnDeb         = 0;
    int    mnEnd         = 0;
    C_RendezVous *rdv    = 0;
    int   ofsetX         = DAY_OFS_X;
    mnDeb                = tpsDeb.hour()*60 + tpsDeb.minute();
    mnEnd                = mnDeb  + nbMnToSee;
    //................... lire la liste des rendez-vous et afficher le resume colore .....................
    for (int i = 0; i < nbRdv; ++i)
        {//.......... creer et ajouter le widget du rendez vous .................................
         rdv         = m_cacheRDV_List[i];
         QRect rect2 = QRect(-1,-1,-1,-1);  // est initialise si un rectangle s'etend sur deux lignes (un bout a la ligne d'avant, l'autre sur l'autre ligne)
         QRect rect  = computeResumeRdvGeometry(rdv, mnDeb, nbMnToSee, m_pBMC->m_HeadResume_Pixmap.width()-LINE_RESUME_XMARG, LINE_RESUME_HEIGHT + 5, m_DayLF?2:1, rect2, LINE_RESUME_HEIGHT + 10);
         rect.setX(rect.x()-1);rect.setWidth(rect.width()+2);   // on agrandi un peu
         if (rect.contains(x - ofsetX , y , TRUE)) {if (index) *index = i; return  rdv;}
         if (rect2.x() != -1)               // si le rectangle est coupe en deux (un bout a la ligne d'avant, l'autre sur l'autre ligne) on verifie aussi si souris dedans l'autre bout
            {rect2.setX(rect2.x()-1);rect2.setWidth(rect2.width()+2);   // on agrandi un peu
             if (rect2.contains(x - ofsetX , y , TRUE)) {if (index) *index = i; return  rdv;}
            }
        }
    if (index) *index = -1;
    return 0;
}

//---------------------------------------- computeResumeRdvGeometry ---------------------------------------------------------------
//....startTimeInMinutes........>|......[1]..........[2].....................[3].............[4]..................|             line 0  <|
//                               |............[5]............[6]............[ 7 ]..............................[ 8|             line 1  <|-- lineH (in pixels)
//                               |  ]............[9]....[10]............[11]......................................|<...EndTime  line 2
//                               ^.........................(widthSegment)        in pixels  ......................^
//                                                         (segmentInMinutes)    in minutes
//                               ^..............^
//                                            (debSegmentInMn) for rdv[9]
//                         from >|            (nbTotalMinutesToSee)            Line 0 + Line 1 + Line 2           |< to EndTime
//

QRect C_Frm_Day::computeResumeRdvGeometry(C_RendezVous *pRdv, int startTimeInMinutes, int nbTotalMinutesToSee, int widthSegment, int lineH, int nbLine, QRect &rect2, int rectH /*=6*/)
{QRect rect;
 int reliquat          = 0;          // reliquat a placer sur l'autre ligne si un rdv deborde sur l'autre ligne
 int segmentInMinutes  = nbTotalMinutesToSee / nbLine;
 int posInMinutes      = pRdv->m_date.time().hour()*60 + pRdv->m_date.time().minute() - startTimeInMinutes;
 int line              = (posInMinutes)     / segmentInMinutes;    // + pRdv->m_Duree pour passer a la ligne si deborde a droite
 int debSegmentInMn    = posInMinutes - line * segmentInMinutes;
 rect.setX (     (widthSegment * debSegmentInMn)  / segmentInMinutes );
 rect.setY(       lineH        * line);
 //........... verifier si deborde pas a droite ..........................
 //            auquel cas generer le deuxieme rectangle
 reliquat =  (debSegmentInMn + pRdv->m_Duree)-segmentInMinutes;
 if (reliquat>0)
    {rect.setWidth(  ((widthSegment * (pRdv->m_Duree - reliquat) )  / segmentInMinutes) );
     rect2.setWidth( ((widthSegment * (reliquat) )                  / segmentInMinutes) );
     rect2.setY(       lineH        * (line + 1) );
     rect2.setX (0);
     rect2.setHeight(rectH);
    }
 else
    {rect.setWidth( ((widthSegment * pRdv->m_Duree )  / segmentInMinutes) );
    }
 rect.setHeight(rectH);
 return rect;
}

//---------------------------------------- computeResumeRdvGeometry ---------------------------------------------------------------
//....startTimeInMinutes........>|......[1]..........[2].....................[3].............[4]..................|             line 0  <|
//                               |............[5]............[6]............[ 7 ]..............................[ 8|             line 1  <|-- lineH (in pixels)
//                               |  ]............[9]....[10]............[11]......................................|<...EndTime  line 2
//                               ^.........................(widthSegment)        in pixels  ......................^
//                                                         (segmentInMinutes)    in minutes
//                               ^..............^
//                                            (debSegmentInMn) for rdv[9]
//                         from >|            (nbTotalMinutesToSee)            Line 0 + Line 1 + Line 2           |< to EndTime
//

QPoint C_Frm_Day::computeResumePosXYFromTimeInMinute(int timeInMinutes, int startTimeInMinutes, int nbTotalMinutesToSee, int widthSegment, int lineH, int nbLine)
{QPoint point;
 int segmentInMinutes  = nbTotalMinutesToSee / nbLine;
 int posInMinutes      = timeInMinutes - startTimeInMinutes;
 int line              = posInMinutes   / segmentInMinutes;
 int debSegmentInMn    = posInMinutes - line * segmentInMinutes;
 point.setX (    (widthSegment * debSegmentInMn)  / segmentInMinutes );
 point.setY(      lineH        * line);
 return point;
}

//------------------------ XYToMinutesInResume ---------------------------------------
int C_Frm_Day::XYToMinutesInResume ( int x, int y, int *retNbMnToEnd /* = 0 */)
{QTime tpsDeb                = getStartTime();
 QTime tpsEnd                = getStopTime();
 int nbTotalMinutesToSee     = getNbMinutesToseeInResume(tpsDeb, tpsEnd);
 int    nbLine               = m_DayLF?2:1;
 int segmentInMinutes        = nbTotalMinutesToSee / nbLine;
 int lineH                   = LINE_RESUME_HEIGHT + 5;

 int   ofsetX      = DAY_OFS_X;
 int   posY        = y - FIRST_DAY_POS_Y - HEAD_RESUME_OFY;
 int   posX        = x - ofsetX;         // relativier au pixel signifiant
 //........... determiner la ligne pointee .............................
 int   curY        = 0;
 int     i         = 0;
 for (i=0; i<nbLine; ++i)
     {//qDebug() << tr("Inf=%1 Sup=%2 PosY=%3 i=%4").arg(QString::number(curY),QString::number(curY + lineH),QString::number(posY),QString::number(i));
      if (posY >= curY && posY <= curY + LINE_RESUME_HEIGHT) break;   // si dans fourchette on break
      curY     += lineH;
     }
 if (i==nbLine)  return -1;    // on est pas dans une fourchette de ligne (soit trop bas soit trop haut) cassos avec -1
 //............... calcul ...................................
 int   mnDeb       = tpsDeb.hour()*60 + tpsDeb.minute();
 int   mnCur       = ((posX * segmentInMinutes) / ( m_pBMC->m_HeadResume_Pixmap.width()-LINE_RESUME_XMARG))+(segmentInMinutes*i); mnCur = mnCur/getMagnetisme(); mnCur *=getMagnetisme(); // un peut de granulometrie que diable
 if (retNbMnToEnd) *retNbMnToEnd = nbTotalMinutesToSee-mnCur;
 return mnDeb + mnCur;
}

//---------------------------------------- get_C_Frm_RdvBeforeAndAfter --------------------------------------------
int C_Frm_Day::get_C_Frm_RdvBeforeAndAfter(int y_pos, C_Frm_Rdv **pC_Frm_RdvBefore,  C_Frm_Rdv **pC_Frm_RdvAfter /*=0*/)
{ //................ rechercher le Rdv d'avant et d'apres ............................
  int nearYinf                           = -1;
  int nearYsup                           = 400000;
  *pC_Frm_RdvBefore                      = 0;
  if (pC_Frm_RdvAfter) *pC_Frm_RdvAfter  = 0;
  int  nb          = C_Frm_RdvList::size();
  for (int i = 0; i < nb; ++i)
     {C_Frm_Rdv *pC_Frm_Rdv  = C_Frm_RdvList::at(i);
      int frmYinf = pC_Frm_Rdv->y();
      int frmYsup = pC_Frm_Rdv->y() + pC_Frm_Rdv->getHeight();
      if ( (y_pos    >= frmYinf - 1 && y_pos <= frmYsup + 1) ) return 0;
      if (frmYinf  >= nearYinf && frmYinf <= y_pos)  {nearYinf = frmYinf; *pC_Frm_RdvBefore = pC_Frm_Rdv;}
      if (frmYsup  <= nearYsup && frmYsup >= y_pos)  {nearYsup = frmYsup; if (pC_Frm_RdvAfter) *pC_Frm_RdvAfter  = pC_Frm_Rdv;}
     }
  return 1;
}

//---------------------------- getRdvAfterThisTimeInMinutes ------------------------------------------------
//  NOTE : suppose que m_cacheRDV_List est a jour car se fonde dessus pour creer la liste des widgets de rendez-vous
//         fait appel a m_cacheRDV_List car appelee en mode replie
C_RendezVous C_Frm_Day::getRdvAfterThisTimeInMinutes(int minutesRef, int *mnRet /* =0 */)
{C_RendezVous rdvNull; rdvNull.m_Duree = -1;
 int nb   = m_cacheRDV_List.count();
 int deb  = -1;
 for (int i  = 0; i < nb; ++i)
     {
      deb = m_cacheRDV_List[i]->m_date.time().hour()*60+m_cacheRDV_List[i]->m_date.time().minute();
       if (deb>minutesRef)
          {if (mnRet) *mnRet = deb;
           return *m_cacheRDV_List[i];
          }
      }
 if (mnRet) *mnRet = -1;
 return rdvNull;
}

//---------------------------- getRdvBeforeThisTimeInMinutes ------------------------------------------------
//  NOTE : suppose que m_cacheRDV_List est a jour car se fonde dessus pour creer la liste des widgets de rendez-vous
//         fait appel a m_cacheRDV_List car appelee en mode replie
C_RendezVous C_Frm_Day::getRdvBeforeThisTimeInMinutes(int minutesRef, int *mnRet /* =0 */)
{C_RendezVous rdvRet; rdvRet.m_Duree = -1;
 int nb   = m_cacheRDV_List.count();
 if (nb==0) {  if (mnRet) *mnRet = -1;     return rdvRet;}
 int deb  = -1;
 int   i  = nb;
 int last = -1;
 while (i)
    {--i;
     deb = m_cacheRDV_List[i]->m_date.time().hour()*60+m_cacheRDV_List[i]->m_date.time().minute();
     if (deb<minutesRef && deb>=last)
        {last   = deb;
         rdvRet = *m_cacheRDV_List[i];
        }
     }
 if (mnRet) *mnRet = last;
 return rdvRet;
}

//---------------------------------------- isCopyExist --------------------------------------------
bool C_Frm_Day::isCopyExist()
{ return QApplication::clipboard()->mimeData()->hasFormat("text/medintux_rdv");
}

//---------------------------------------- getCopy --------------------------------------------
C_RendezVous C_Frm_Day::getCopy()
{ C_RendezVous rdv;
  const QMimeData *mimeData   = QApplication::clipboard()->mimeData();
  if (mimeData->hasFormat ("text/medintux_rdv" ))
     {rdv = C_RendezVous::unSerialize(QString(mimeData->data ( "text/medintux_rdv" )));
     }
  return rdv;
}

//---------------------------------------- Slot_ReplaceRdvByDroppedRdv --------------------------------------------
void C_Frm_Day::Slot_ReplaceRdvByDroppedRdv(C_Frm_Rdv *pC_Frm_Rdv_Dst)
{ LOOKREFRESH;
  C_RendezVous rdvSrc;
  getLastDroppedData(rdvSrc.m_Nom, rdvSrc.m_Prenom, rdvSrc.m_Tel, rdvSrc.m_GUID, rdvSrc.m_Where);
  if (rdvSrc.m_GUID.length()) replaceRdvByRdv(pC_Frm_Rdv_Dst, rdvSrc);
  UNLOOKREFRESH;
}
//---------------------------------------- replaceRdvByRdv --------------------------------------------
void C_Frm_Day::replaceRdvByRdv(C_Frm_Rdv *pC_Frm_Rdv_Dst, const C_RendezVous &rdvSrc)
{

  if (pC_Frm_Rdv_Dst == 0)        return;
  if (pC_Frm_Rdv_Dst->m_GUID.length()||pC_Frm_Rdv_Dst->m_Nom.length()||pC_Frm_Rdv_Dst->m_Prenom.length()) // si rendez-vous d\303\251j\303\240 attribu\303\251 demander confirmation du changement
     {int ret   = QMessageBox::warning ( this, tr("Modify an appointment :"),
                                         QString( "<u><b>"+tr("WARNING")+"</u> :<br /></b>"+tr("The actual appointment taken for:")+"<br />"
                                             " <b><font color=\"#1200ff\">%1</font></b><hr>").arg( pC_Frm_Rdv_Dst->m_Nom  + " " + pC_Frm_Rdv_Dst->m_Prenom ) +
                                         QString(tr( "will change et will be given to:")+"<br />"
                                             "<b><font color=\"#ff0000\">%1</font></b><br />").arg(rdvSrc.m_Nom+' '+rdvSrc.m_Prenom) +
                                         tr("Confirm modification ?"),
                                         tr("&Modify"), tr("&Cancel"), 0, 1, 1
                                       );
      if (ret==1)                  return;
     }
  //............. modifier le widget ................................................
  pC_Frm_Rdv_Dst->m_GUID   = rdvSrc.m_GUID;
  pC_Frm_Rdv_Dst->m_Nom    = rdvSrc.m_Nom;
  pC_Frm_Rdv_Dst->m_Prenom = rdvSrc.m_Prenom;
  pC_Frm_Rdv_Dst->m_Tel    = rdvSrc.m_Tel;
  pC_Frm_Rdv_Dst->m_Where  = rdvSrc.m_Where;

  pC_Frm_Rdv_Dst->m_textLabel_Nom->setText(rdvSrc.m_Nom + " " + rdvSrc.m_Prenom);
  pC_Frm_Rdv_Dst->m_ButtonAcceder->setEnabled(TRUE);
  pC_Frm_Rdv_Dst->m_ButtonAcceder->setIcon(m_pBMC->m_ButtonAcceder_Pixmap);

  //........... enregistrer la modification dans la base ................
  QString errMess;
  if ( ! m_pCMoteurAgenda->RDV_Update(*pC_Frm_Rdv_Dst, &errMess) )
     {qDebug() << errMess;
     }
}

//---------------------------------------- getRdvUnderMouse --------------------------------------------
C_RendezVous C_Frm_Day::getRdvUnderMouse(int y_pos)
{   //................... parcourir la liste des rendez vous ........................
    //                    verifier si souris  sur un des rendez vous
    C_RendezVous rdvNull; rdvNull.m_Duree = 0;
    int y_last     = -2;
    int i          = 0;
    C_Frm_Rdv *pC_Frm_Rdv     = 0;
    int                   nb  = C_Frm_RdvList::size();
    if (nb==0)   { return rdvNull;}
    for ( i = 0; i < nb; ++i )
        {pC_Frm_Rdv = C_Frm_RdvList::at(i);
         y_last     = pC_Frm_Rdv->y() + pC_Frm_Rdv->getHeight();
         if (y_pos >= pC_Frm_Rdv->y()-1 && y_pos <=  y_last+1)  break;
        }
    //.................. si souris sur rendez-vous cassos .............................................
    if (i>=nb)    { return rdvNull;}
    else          { return *pC_Frm_Rdv->rdv_instance();}
}

//---------------------------------------- getLastDroppedData --------------------------------------------
int C_Frm_Day::getLastDroppedData(QString &nom, QString &prenom, QString &tel, QString &guid, QString &where)
{nom      = "";
 prenom   = "";
 tel      = "";
 guid     = "";
 if (m_DropedRdv.m_GUID.length()==0) return 0;
 nom      = m_DropedRdv.m_Nom;
 prenom   = m_DropedRdv.m_Prenom;
 tel      = m_DropedRdv.m_Tel;
 guid     = m_DropedRdv.m_GUID;
 where    = m_DropedRdv.m_Where;
 m_DropedRdv.m_GUID = ""; // on ne sert des donnees qu'une fois
 return 1;
}

//---------------------------- adjustToMagnetisme ------------------------------------------------
int    C_Frm_Day::adjustToMagnetisme(int value)
{value       -= (FIRST_DAY_POS_Y + m_BaseDayHeight);        // enlever les ofset non significatifs pour le temps
 int pixMag   = getMagnetisme() * getResoPixByMinutes();
 int midleMag = pixMag / 2;
 value        = (value+midleMag)/pixMag;
 return (value*pixMag) + (FIRST_DAY_POS_Y + m_BaseDayHeight);
}

//---------------------------------------- mousePressEvent --------------------------------------------
void C_Frm_Day::mousePressEvent ( QMouseEvent * event )
{On_Day_mousePressEvent ( event );
}

//---------------------------------------- On_Day_mousePressEvent --------------------------------------------
void C_Frm_Day::On_Day_mousePressEvent ( QMouseEvent * event )
{ int ymgn       = event->y();// sera ajuste au magnetisme
  QString   type   = "";
  QDateTime dt;
  QDateTime dtLast;
  QString   nom ,prenom ,tel, guid, where;
  int       isDropedData = getLastDroppedData(nom, prenom, tel, guid, where);
  LOOKREFRESH;
  if (isDayExpand())
     {int y_pos      =  ymgn;
      int i          =  0;
      int y_last     = -2;
      int y_lastRdv  = -1;
      //................... parcourir la liste des rendez vous ........................
      //                    verifier si souris  sur un des rendez vous
      C_Frm_Rdv *pC_Frm_Rdv     = 0;
      int                   nb  = C_Frm_RdvList::size();
      for ( i = 0; i < nb; ++i )
          {pC_Frm_Rdv = C_Frm_RdvList::at(i);
           y_last     = pC_Frm_Rdv->y() + pC_Frm_Rdv->getHeight();
           if (y_pos >= pC_Frm_Rdv->y()-1 && y_pos <=  y_last+1)  break;
          }
      //.................. si souris sur pC_Frm_Rdv-vous cassos car sera traite inside pC_Frm_Rdv .............................................
      if (i<nb)
         { UNLOOKREFRESH;    return;
         }

      //................ rechercher le Rdv d'avant et d'apres ............................
      C_Frm_Rdv *pC_Frm_RdvBefore = 0;
      get_C_Frm_RdvBeforeAndAfter(y_pos, &pC_Frm_RdvBefore);      // cassos si on est dans un rdv

      if (pC_Frm_RdvBefore==-0)  y_lastRdv = 0; // si cliqu\303\251 apr\303\251s le der des der (en a pas apres pour le test)
      else                       y_lastRdv = pC_Frm_RdvBefore->y() + pC_Frm_RdvBefore->height();      // si cliqu\303\251 apr\303\251s le der des der (en a pas apres pour le test)

      //................... souris sur espace libre .....................................................
      ymgn     = adjustToMagnetisme(y_pos);
      dt       = QDateTime(m_Date, posY_toTime(ymgn));     // recuperer la date li\303\251e \303\240 la position souris
      dtLast   = QDateTime(m_Date,posY_toTime(y_lastRdv)); // recuperer la date li\303\251e au dernier rendez-vous en arri303\250re de la souris
      if (pC_Frm_RdvBefore) type = pC_Frm_RdvBefore->m_Type;
     }
  else
     {int index          = -1;
      C_RendezVous *pRdv = getRdvUnderMouseInResume ( event->x(), event->y() , &index);
      if (pRdv)
         {if (isDropedData)
             {
              if (pRdv->m_GUID.length()||pRdv->m_Nom.length()||pRdv->m_Prenom.length()) // si rendez-vous d\303\251j\303\240 attribu\303\251 demander confirmation du changement
                 {int ret   = QMessageBox::warning ( this, tr("Modify an appointment :"),
                                                     tr( "<u><b>WARNING</u> :<br /></b> The actual appointment taken for :")+QString("<br />"
                                                         " <b><font color=\"#1200ff\">%1</font></b><hr>").arg( pRdv->m_Nom  + " " + pRdv->m_Prenom ) +
                                                     tr( "will be given to:")+QString("<br />"
                                                         "<b><font color=\"#ff0000\">%1</font></b><br />").arg(nom+' '+prenom) +
                                                     tr( "Confirm modification ?"),
                                                     tr("&Modify"), tr("&Cancel"), 0, 1, 1
                                                   );
                  if (ret==1)  {UNLOOKREFRESH; return; }
                 }
              pRdv->m_GUID   = guid;
              pRdv->m_Nom    = nom;
              pRdv->m_Prenom = prenom;
              pRdv->m_Tel    = tel;
              pRdv->m_Where  = where;
              QString errMess; if ( ! m_pCMoteurAgenda->RDV_Update(*pRdv, &errMess) ) qDebug() << errMess;
              update();
              UNLOOKREFRESH;
              return;
             } // endif (isDropedData)
          //.............. actionner le menu des RDV ......................................
          else /*if (pRdv->m_GUID.length()||pRdv->m_Nom.length()||pRdv->m_Prenom.length())*/
             { QString ret = doRdvMenu(pRdv,1);
               // "Copy" "Replace" "Cut" "Type :" "Status :"  "Modify"  "Open" "Anomymize" "Quit"
               if (ret.length())
                  {if (ret.indexOf("Status :") != -1)
                      { QString statut = ret.remove("Status :");
                        pRdv->m_State  = statut.trimmed();
                      }
                   else if (ret.indexOf("Type :") != -1)
                      { QString type = ret.remove("Type :");
                        pRdv->m_Type = type.trimmed();
                      }
                   else if (ret.indexOf("Delete") != -1)  // il ne  peut pas se detruire lui meme et sortir ensuite de sa fonction donc QTIMER
                      {if (index != -1)
                          {if (m_pCMoteurAgenda->isModifToConfirm()&2  &&
                               QMessageBox::question ((QWidget*)parent(),
                                                      tr("Confirm delete"),
                                                      tr("Confirm deleting this appointment "),
                                                      QMessageBox::Ok|QMessageBox::Cancel)==QMessageBox::Cancel)
                              {UNLOOKREFRESH;
                               return;
                              }
                           if (m_pCMoteurAgenda->RDV_Delete(pRdv->m_PrimKey))
                             {m_cacheRDV_List.removeIndex(index);
                              update();
                              UNLOOKREFRESH;
                              return;
                             }
                          }
                      }
                   else if (ret.indexOf("Cut") != -1)  // il ne  peut pas se detruire lui meme et sortir ensuite de sa fonction donc QTIMER
                      {if (m_pCMoteurAgenda->isModifToConfirm()&2  &&
                           QMessageBox::question ((QWidget*)parent(),
                                                  tr("Confirm delete"),
                                                  tr("Confirm deleting this appointment"),
                                                  QMessageBox::Ok|QMessageBox::Cancel)==QMessageBox::Cancel)
                          {UNLOOKREFRESH;
                           return;
                          }
                       if (index != -1)
                          {copyRdv(*pRdv);
                           if (m_pCMoteurAgenda->RDV_Delete(pRdv->m_PrimKey))
                              {m_cacheRDV_List.removeIndex(index);
                               update();
                               UNLOOKREFRESH;
                               return;
                              }
                          }
                      }
                   else if (ret.indexOf("Copy") != -1)
                      { copyRdv(*pRdv);
                      }
                   else if (ret.indexOf("Replace") != -1)
                      {C_RendezVous    rdv = getCopy();    // on recupere le rendez-vous
                       pRdv->m_Nom     = rdv.m_Nom;
                       pRdv->m_Prenom  = rdv.m_Prenom;
                       pRdv->m_Note    = rdv.m_Note;
                       pRdv->m_Where   = rdv.m_Where;
                       pRdv->m_GUID    = rdv.m_GUID;
                       pRdv->m_PrimKey = rdv.m_PrimKey;
                       pRdv->m_Tel     = rdv.m_Tel;
                       pRdv->m_Type    = rdv.m_Type;
                       pRdv->m_State   = rdv.m_State;
                      }
                   else if (ret.indexOf("Modify") != -1)
                      {rdvPropertyDialog(pRdv);
                      }
                   else if (ret.indexOf("Anomymize") != -1)
                      {pRdv->m_Nom    ="";
                       pRdv->m_Prenom ="";
                       pRdv->m_GUID   ="";
                       pRdv->m_Tel    ="";
                       pRdv->m_Note   ="";
                       pRdv->m_Where  ="";
                      }
                   else if (ret.indexOf("Open") != -1)
                      {emit Sign_LauchPatient(pRdv->m_GUID, pRdv);
                      }
                  }
               QString errMess; if ( ! m_pCMoteurAgenda->RDV_Update(*pRdv, &errMess) ) qDebug() << errMess;
               update();
               UNLOOKREFRESH;
               return;
             } // endif else (isDropedData)
         } // endif (pRdv)
      C_RendezVous rdv;
      int    mn  = XYToMinutesInResume (event->x(),event->y()); if (mn==-1) {UNLOOKREFRESH;    return;}
      int     h  = mn/60;
      rdv        = getRdvBeforeThisTimeInMinutes(mn);
      if (rdv.m_Duree>=0)
         {dtLast = rdv.getDateTime().addSecs(rdv.m_Duree*60); // ajouter duree pour se placer apres
          type   = rdv.m_Type;
         }
      else
         {dtLast = QDateTime(m_Date,getStartTime());
          type   = "";
         }
      mn         = mn - (h*60);
      dt         = QDateTime(m_Date, QTime(h,mn));     // recuperer la date li\303\251e \303\240 la position souris
     }

  //................ menu ....................
  Theme::setFontSize_Menu(9);
  QStringList optionList;
  optionList<<"$Agenda";
  if (guid.length())
     {optionList<<"=8=#Agenda/NewDocWithIdentAfter.png#"+tr("Create after the last one for the %2 at %3 an appointment with the patient '%1' selected in the list.").arg(nom+ " " +prenom,dtLast.date().toString("dd-MM-yyyy"),dtLast.time().toString("hh|mm").replace('|','h'));
      optionList<<"=3=#Agenda/NewDocWithIdent.png#"+tr("Create for the %2 at %3 an appointment with the patient '%1' selected in the list.").arg(nom+ " " +prenom, dt.date().toString("dd-MM-yyyy"),dt.time().toString("hh|mm").replace('|','h'));
      optionList<<"-----------";
     }
  optionList<<"=7=#Agenda/NewDocAfter.png#"+tr("Create an appointment after the last one for the %1 at %2").arg(dtLast.date().toString("dd-MM-yyyy"),dtLast.time().toString("hh|mm").replace('|','h'));
  optionList<<"=6=#Agenda/NewDoc.png#"+tr("Create an appointment for the %1 at  %2").arg(dt.date().toString("dd-MM-yyyy"),dt.time().toString("hh|mm").replace('|','h'));
  optionList<<"=1=#Agenda/NewDoc.png#"+tr("Create for the %1 at %2 an empty appointment with no identity").arg(dt.date().toString("dd-MM-yyyy"),dt.time().toString("hh|mm").replace('|','h'));
  optionList<<"-----------";

  //.......................... menu coller si rendez-vous en buffer de copie existe ...............
  if (isCopyExist())
     {C_RendezVous rdv = getCopy();
      if (rdv.m_Nom.trimmed().length()||rdv.m_Prenom.trimmed().length())
         {optionList<<"=4=#Agenda/editpaste.png#"+tr("Paste the appointment with the patient '%1' at this date : %2 at this hour: %3").arg(rdv.m_Nom.trimmed()+" "+rdv.m_Prenom.trimmed(),
                                                                                                                    dt.date().toString("dd-MM-yyyy"),
                                                                                                                    dt.time().toString("hh|mm").replace('|','h')
                                                                                                                   );
          optionList<<"=9=#Agenda/editpasteLast.png#"+tr("Paste after the last one the appointment with the patient '%1' ").arg(rdv.m_Nom.trimmed()+" "+rdv.m_Prenom.trimmed());
         }
      else
         {optionList<<"=4=#Agenda/editpaste.png#"+tr("Paste at this date : %1 and at this hour : %2 the appointment from copy memory").arg(dt.date().toString("dd-MM-yyyy"),
                                                                                                       dt.time().toString("hh|mm").replace('|','h')
                                                                                                      );
          optionList<<"=9=#Agenda/editpasteLast.png#"+tr("Paste after the last one the appointment from the copy memory.");
         }
     }

  optionList<<"=5=#Agenda/configure.png#"+tr("Configure the types of appointments");
  optionList<<"-----------";
  optionList<<"=2=#Agenda/QuitterMenu.png#"+tr("Quit this menu");
  int                     opt = ThemePopup(optionList,this, " border: 1px solid #8f8f91; border-radius: 6px; font-size: 11px;").DoPopupList().trimmed().toInt();
  C_RendezVous* pC_RendezVous = 0;        // si new apres --> ne pas deleter car append
  switch (opt)
     {case 5: {C_Dlg_RdvTypeConfig *pC_Dlg_RdvTypeConfig = new C_Dlg_RdvTypeConfig(m_pColorProfils, m_pCMoteurAgenda, this);
               if (pC_Dlg_RdvTypeConfig==0)                              {UNLOOKREFRESH;    return;}
               pC_Dlg_RdvTypeConfig->exec();
               delete pC_Dlg_RdvTypeConfig;                              {UNLOOKREFRESH;    return;}
              }
     case 6:  {newRDVAtThisDate(dt, 15, type);                           {UNLOOKREFRESH;    return;}
              }
     case 7:  {newRDVAtThisDate(dtLast, 15, type);                       {UNLOOKREFRESH;    return;}
              }
     case 8:  {newRDVAtThisDate(dtLast, 15, type,nom,prenom,tel,guid, where);   {UNLOOKREFRESH;    return;}
              }
     case 3:  {newRDVAtThisDate(dt, 15, type, nom, prenom, tel, guid, where);   {UNLOOKREFRESH;    return;}
              }
     case 4:  {C_RendezVous rdv = getCopy();       // paste
               pC_RendezVous    = new C_RendezVous(dt , rdv.m_Duree, rdv.m_Nom, rdv.m_Prenom, rdv.m_Tel, rdv.m_Note, rdv.m_GUID, m_SignUser, m_User, rdv.m_Type,"",rdv.m_State,rdv.m_Where);
              } break;
     case 9:  {C_RendezVous rdv = getCopy();       // paste last
               pC_RendezVous    = new C_RendezVous(dtLast , rdv.m_Duree, rdv.m_Nom, rdv.m_Prenom, rdv.m_Tel, rdv.m_Note, rdv.m_GUID, m_SignUser, m_User, rdv.m_Type,"",rdv.m_State,rdv.m_Where);
              } break;
     case 1:  {pC_RendezVous    = new C_RendezVous(dt , 15, "", "", "", "", "", m_SignUser, m_User, ""); // anonyme
              } break;
     default: {UNLOOKREFRESH;
               return;
              }
     }
  if (pC_RendezVous==0)                                         {UNLOOKREFRESH;    return;}
  C_Frm_Rdv *pC_Frm_Rdv = appendNewRDVItem(pC_RendezVous);    // ne pas effacer pC_RendezVous car appendNewRDVItem
  //................. repositionner le widget du rendez vous ...............................
  if (pC_Frm_Rdv)
     {if (isDayExpand())  pC_Frm_Rdv->show();
      ReArangeIfDayHeightChange();                 // reajuster eventuellement la hauteur du jour et reorganiser les jours sous jacents et mettre a jour la hauteur du jour
     }
  UNLOOKREFRESH;
}

//---------------------------- doRdvMenu ------------------------------------------------
QString C_Frm_Day::doRdvMenu(C_RendezVous *pRdvDst, int isOptionDetruire  /* = 0 */)
{

    // "Copy" "Replace" "Cut" "Type :" "Status :"  "Modify"  "Open" "Anomymize" "Quit"
    C_QMenuRdv menu(tr("Appointment available"),(QWidget*)parent());
    menu.setStyleSheet("font-size: 12px");  // "border: 1px solid #8f8f91; border-radius: 6px; font-size: 11px; color:#000000;border-width: 3px;  border-style: solid;  border-color: blue; background: yellow; icon-size:16px"
    //..............menu clasique copier coller couper ...............................
    menu.addAction (m_pBMC->m_Copier_Pixmap, tr("Copy the current appointment into the copy memory")
                   )->setData ("Copy");

    //.......................... menu coller si rendez-vous en buffer de copie existe ...............
    C_RendezVous rdvCopy = getCopy();
    if (isCopyExist())
    {if (rdvCopy.m_Nom.trimmed().length()||rdvCopy.m_Prenom.trimmed().length())
            menu.addAction (m_pBMC->m_Paste_Pixmap,
                            tr("Replace the actual appointment with the one inside the copy memory with the name of the patient: '%1' ").arg(rdvCopy.m_Nom.trimmed()+" "+rdvCopy.m_Prenom.trimmed())
                           )->setData ("Replace");
        else
            menu.addAction (m_pBMC->m_Paste_Pixmap, tr("Replace the actual appointment with the one inside the copy memory.")
                           )->setData ("Replace");
    }
    menu.addAction (m_pBMC->m_Cut_Pixmap, tr("Cut the current appointment and put into the copy memory")
                   )->setData ("Cut");
    menu.addSeparator ();
    //............. creer le menu des types avec les types couleurs .....................
    QLabel grabLabel;
    grabLabel.setGeometry (0, 0, 16, 16);
    QMap<QString, C_ColorType>::const_iterator it = m_pColorProfils->constBegin();

    grabLabel.setStyleSheet(QString("border: 2px solid #010101; background-color: #FFFFFF;"));
    QPixmap pix = QPixmap::grabWidget (&grabLabel, 0, 0, 16, 16 );
    while (it != m_pColorProfils->constEnd())
    {C_ColorType ct = it.value();
        grabLabel.setStyleSheet(QString("border: 2px solid #010101; background-color: ")+ct.getColor()+";");
        pix = QPixmap::grabWidget (&grabLabel, 0, 0, 16, 16 );
        if (it.key().trimmed().length())
        {menu.addAction (QIcon(pix), tr("Appointment of type: %1").arg(it.key())
                        )->setData (QString("Type :%1").arg(it.key()));
        }
        ++it;
    }
    //............. creer le menu des statuts.....................
    menu.addSeparator ();
    QMapIterator<QString, QPixmap> ut(m_pBMC->m_StatutsPixmap);
    while (ut.hasNext())
    {ut.next();
        menu.addAction (ut.value(), tr("Appointment Status: %1").arg(ut.key())
                        )->setData (QString("Status :%1").arg(ut.key()));
    }
    menu.addSeparator ();
    menu.addAction (m_pBMC->m_Configure_Pixmap,     tr("Modify the parameters of this appointment...")
                   )->setData ("Modify");
    if (pRdvDst->m_GUID.length())
       { menu.addAction (m_pBMC->m_ButtonAcceder_Pixmap, tr("Open folder: %1").arg(pRdvDst->m_Nom+" "+pRdvDst->m_Prenom)
                       )->setData ("Open");
       }
    menu.addSeparator ();
    menu.addAction (m_pBMC->m_ButtonDelete_Pixmap,  tr("Make this appointment anonymous and available")
                   )->setData ("Anomymize");
    if (isOptionDetruire) menu.addAction (m_pBMC->m_MenuRendezvousDel,    tr("Delete this appointment")
       )->setData ("Delete");
    menu.addSeparator ();
    menu.addAction (m_pBMC->m_QuitterMenu_Pixmap,   tr("Quit this menu")
                   )->setData ("Quit");
    grabLabel.hide();
    QPoint pt = QCursor::pos();
    //.......... si on est sur un rendez occupe vous afficher le titre .........................
    if (pRdvDst->m_Nom.length()||pRdvDst->m_Prenom.length())
    {menu.setLabelRdvText(QString("<b><font color=\"#ff0000\">%1</font>/<font color=\"#ff0000\">%2</font> <font color=\"#000000\">%3</font></b>").arg(pRdvDst->m_date.time().toString("hh:mm"), QString::number(pRdvDst->m_Duree), pRdvDst->m_Nom+" "+pRdvDst->m_Prenom),
                          pRdvDst->m_Type,
                          C_RendezVous::getRdvColor(*pRdvDst, m_pColorProfils)
                         );
    }
    //.......... si on est sur un rendez libre vous afficher disponible .........................
    else
    {menu.setLabelRdvText(QString("<b><font color=\"#ff0000\">%1</font>/<font color=\"#ff0000\">%2</font> <font color=\"#000000\">%3</font></b>").arg(pRdvDst->m_date.time().toString("hh:mm"), QString::number(pRdvDst->m_Duree), tr(" Appointment available ")),
                          pRdvDst->m_Type,
                          C_RendezVous::getRdvColor(*pRdvDst, m_pColorProfils)
                         );
    }
    QAction  *pQAction =  menu.exec (pt);
    QString        ret = "";
    if (pQAction)  ret = pQAction->data().toString();
    return ret;
}
//---------------------------------------- copyRdv --------------------------------------------
void C_Frm_Day::copyRdv(const C_RendezVous &rdv)
{QByteArray data(rdv.serialize().toAscii());
 QMimeData *mimeData = new QMimeData;
 mimeData->setData("text/medintux_rdv", data);
 QClipboard *clipboard = QApplication::clipboard();
 clipboard->setMimeData ( mimeData );    // a ne pas deleter
}

//---------------------------------------- newRDVAtThisDate --------------------------------------------
void C_Frm_Day::newRDVAtThisDate(QDateTime dateTime, int duree, const QString &type /*=""*/, const QString &nom /*=""*/, const QString &prenom /*=""*/, const QString &tel /*=""*/, const QString &guid /*=""*/, const QString &where /*=""*/, const QString &pk /*=""*/)
{// ne pas looker c'est fait avant l'appel
 C_RendezVous *pC_RendezVous = new C_RendezVous(dateTime, duree,"","","","","",m_SignUser, m_User);
 if (type.length())   pC_RendezVous->m_Type    = type;
 if (nom.length())    pC_RendezVous->m_Nom     = nom;
 if (prenom.length()) pC_RendezVous->m_Prenom  = prenom;
 if (tel.length())    pC_RendezVous->m_Tel     = tel;
 if (guid.length())   pC_RendezVous->m_GUID    = guid;
 if (where.length())  pC_RendezVous->m_Where   = where;
 if (pk.length())     pC_RendezVous->m_PrimKey = pk;

 C_Dlg_RdvTypeConfig *pC_Dlg_RdvTypeConfig   = new C_Dlg_RdvTypeConfig(m_pColorProfils, m_pCMoteurAgenda, this, pC_RendezVous, 1);
 if (pC_Dlg_RdvTypeConfig && pC_Dlg_RdvTypeConfig->exec() == QDialog::Accepted)
    {C_Frm_Rdv *pC_Frm_Rdv = appendNewRDVItem(pC_RendezVous);    // ne pas effacer pC_RendezVous car appendNewRDVItem
     if (pC_Frm_Rdv)                                             // si echec pC_RendezVous aura ete efface
        {if (isDayExpand())  pC_Frm_Rdv->show();
         ReArangeIfDayHeightChange();                            // reajuster eventuellement la hauteur du jour et reorganiser les jours sous jacents et mettre a jour la hauteur du jour
        }
     delete pC_Dlg_RdvTypeConfig;
     return;
    }
 delete pC_RendezVous;                                           // effacer pC_RendezVous car pas appendNewRDVItem
}

//---------------------------- appendNewRDVItem ------------------------------------------------
// ATTENTION destruction de pC_RendezVous si echec
C_Frm_Rdv* C_Frm_Day::appendNewRDVItem(C_RendezVous *pC_RendezVous)
{     // ne pas looker c'est fait avant l'appel
      QString       errMess = "";
      C_Frm_Rdv *pC_Frm_Rdv = 0;
      //................... enregistrer le rendez vous dans la base ..........................................
      if ( (pC_RendezVous->m_PrimKey = m_pCMoteurAgenda->RDV_Create(*pC_RendezVous, &errMess)).length()==0)
         {delete pC_RendezVous;
          return 0;
         }
      //...................creer le widget rendez vous dans celui du jour .......................
      pC_Frm_Rdv = append_C_Frm_Rdv(new C_Frm_Rdv( pC_RendezVous,
                                                   getResoPixByMinutes(),                    // resolution en pixels
                                                   getMagnetisme(),
                                                   m_pQRubberBand,
                                                   m_pCMoteurAgenda,
                                                   m_pColorProfils,
                                                   m_pBMC,
                                                   m_pCMoteurAgenda->GetMinDaysHeight(),
                                                   m_pCMoteurAgenda->GetProportionnalDays(),
                                                   0,0,this
                                                 )
                                   );
    //generate_cacheRDV_List_FromDayWidget();    // synchroniser le cache --> pas bon car si en mode replie pas de widgets
    m_cacheRDV_List.appendRdv(pC_RendezVous);    // donc on l'ajoute donc simplement  la liste et ca le fait
    pC_Frm_Rdv->adjustWidgetToMagnetisme();      // faut recadrer au contraintes de magnetisme
    readjustListWidgetPositions();               // revoir toutes les positions car le debut peut avoir change si place avant la limite sup
    update();                                    // faut aussi reafficher le fond si changement de debut
    return pC_Frm_Rdv;
}

//---------------------------- Slot_ButtonAccederClicked ------------------------------------------------
void C_Frm_Day::Slot_ButtonAccederClicked(const char*, void *ptr)
{if (ptr==0) return;
 LOOKREFRESH;     // bloquer le raffraississement
 C_Frm_Rdv *pC_Frm_Rdv = (C_Frm_Rdv*)ptr;
 emit Sign_LauchPatient(pC_Frm_Rdv->m_GUID, pC_Frm_Rdv);
 UNLOOKREFRESH;
}

//---------------------------- Slot_ButtonRDVDeleteClicked ------------------------------------------------
void C_Frm_Day::Slot_ButtonRDVDeleteClicked(const char*, void *ptr)
{LOOKREFRESH;     // bloquer le raffraississement
 if (m_pCMoteurAgenda->isModifToConfirm()&2  &&
     QMessageBox::question ((QWidget*)parent(),
                            tr("Confirm delete"),
                            tr("Confirm deleting this appointment "),
                            QMessageBox::Ok|QMessageBox::Cancel)==QMessageBox::Cancel)
    {UNLOOKREFRESH;
     return;
    }


 if (ptr ==0)                                                  { UNLOOKREFRESH;    return; }
 C_Frm_Rdv *pC_Frm_Rdv = (C_Frm_Rdv*)ptr;
 if (m_pCMoteurAgenda->RDV_Delete(pC_Frm_Rdv->m_PrimKey)==0)   { UNLOOKREFRESH;    return; };    // cassos si echec de  l'effacement dans la base

 //................... lire la liste des widget rendez-vous du jour .....................
 //                    et effacer celui \303\240 effacer
 C_Frm_Rdv *pC_Frm_Rdv_inDay = 0;
 for (int i = 0; i < C_Frm_RdvList::size(); ++i)
      {pC_Frm_Rdv_inDay = at(i);
       if (pC_Frm_Rdv_inDay == pC_Frm_Rdv)
          {removeAt(i);
           delete pC_Frm_Rdv;
           pC_Frm_Rdv = 0;
           break;
          }
      }
 generate_cacheRDV_List_FromDayWidget();    // l'effacement se fait en mode deplie donc widgets presents synchroniser le cache
 //........... si effacement reussi ..........
 //           mettre \303\240 jour le nombre et le titre
 if (pC_Frm_Rdv==0)
    { ReArangeIfDayHeightChange();                  // reajuster eventuellement la hauteur du jour et reorganiser les jours sous jacents et mettre a jour la hauteur du jour
    }
 UNLOOKREFRESH;
}

//---------------------------------------- rdvPropertyDialog--------------------------------------------
int C_Frm_Day::rdvPropertyDialog(C_RendezVous *rdvDst)
{LOOKREFRESH;
 C_Dlg_RdvTypeConfig *pC_Dlg_RdvTypeConfig = new C_Dlg_RdvTypeConfig(m_pColorProfils, m_pCMoteurAgenda, this, rdvDst);
 int ret = pC_Dlg_RdvTypeConfig->exec();
 delete pC_Dlg_RdvTypeConfig;
 UNLOOKREFRESH;
 return ret;
}

//---------------------------------------- Slot_RendezVousChangeClicked --------------------------------------------
void C_Frm_Day::Slot_RendezVousChangeClicked(C_Frm_Rdv *pC_Frm_Rdv)
{LOOKREFRESH;
 C_RendezVous rdvModified = *pC_Frm_Rdv->rdv_instance();
 C_Dlg_RdvTypeConfig *pC_Dlg_RdvTypeConfig = new C_Dlg_RdvTypeConfig(m_pColorProfils, m_pCMoteurAgenda, this, &rdvModified);
 if (pC_Dlg_RdvTypeConfig && pC_Dlg_RdvTypeConfig->exec() == QDialog::Accepted)
    {pC_Frm_Rdv->setWidgetOnRdv(rdvModified);                // on reajuste le widget sur les nouvelles donn\303\251es
     pC_Frm_Rdv->setWidgetStyleOnRdv(rdvModified);
     QTime startTime = getStartTime();
     int       y_deb = FIRST_DAY_POS_Y + m_BaseDayHeight + startTime.secsTo(rdvModified.getDateTime().time())/60*getResoPixByMinutes();
     pC_Frm_Rdv->move( W_RDV_OFSET, y_deb);
     pC_Frm_Rdv->RDV_Update();                    // enregistrer en base
     readjustListWidgetPositions();               // revoir toutes les positions car le debut peut avoir change si place avant la limite sup
     ReArangeIfDayHeightChange();                 // reajuster eventuellement la hauteur du jour et reorganiser les jours sous jacents et mettre a jour la hauteur du jour
    }
 delete pC_Dlg_RdvTypeConfig;
 UNLOOKREFRESH;
}

//---------------------------------------- OnButtonNewRDVClickedPtr --------------------------------------------
void C_Frm_Day::OnButtonNewRDVClickedPtr(const char*, void*)
{newRDVAtThisDate(QDateTime(QDate::currentDate(), QTime::currentTime()), 15);
}

//---------------------------------------- OnButtonExpandClickedPtr --------------------------------------------
void C_Frm_Day::OnButtonExpandClickedPtr (const char*, void*)
{ExpandDialog();
 emit Sign_AgendaMustBeReArange();   // si un jour est deplie ou replie il faut  redeplacer tous les widgets sous jacents
}

//---------------------------------------- OnButtonSaveClickedPtr --------------------------------------------
void C_Frm_Day::OnButtonSaveClickedPtr (const char*, void *)
{
 //................ effacer toutes les entr\303\251es de ce jour de la semaine ........................
 m_pCMoteurAgenda->MASK_DayDelete( m_Date.dayOfWeek(), m_SignUser);
 //.................. enregistrer tous les rendez-vous de ce jour ..............................
 //                   comme modele pour ce jour
 for (int i = 0; i < C_Frm_RdvList::size(); ++i)
      {m_pCMoteurAgenda->MASK_Append(*at(i));
      }
}

//---------------------------------------- getStartTime --------------------------------------------
QTime C_Frm_Day::getStartTime()
{
 QTime  tpsDeb;
 tpsDeb = QTime::fromString(m_HeureDeb+":00");
 int minute, heure;
 if (m_cacheRDV_List.size()) tpsDeb   = qMin(getFirstRdv(m_cacheRDV_List)->getDateTime().time(), tpsDeb);
 minute =  tpsDeb.minute(); minute/=15; minute*=15;   // arondir au 1/4 heure (affichage graduations)
 heure  =  tpsDeb.hour();
 tpsDeb = QTime(heure,minute,0,0);
 //QString strDebug = tr("StartTime : %1").arg(tpsDeb.toString("hh:mm:ss"));
 //if(this->isDayExpand()) qDebug() << strDebug;
 return tpsDeb;
}

//---------------------------------------- getStopTime --------------------------------------------
QTime C_Frm_Day::getStopTime()
{
 QDateTime tpsCur;
 QDateTime tpsMax = QDateTime(m_Date, QTime::fromString("23:59:59"));
 QDateTime tpsEnd = QDateTime(m_Date, QTime::fromString(m_HeureFin+":00"));
 C_RendezVous *pRdv = getLastRdv();
 if (pRdv)
    {tpsCur   = QDateTime(pRdv->m_date.addSecs(pRdv->m_Duree*60 ));
     tpsEnd   = qMin(tpsMax, qMax(tpsCur, tpsEnd));
    }
 return tpsEnd.time();
}

//---------------------------------------- getFirstRdv --------------------------------------------
//  NOTE : suppose que m_cacheRDV_List est a jour car se fonde dessus pour creer la liste des widgets de rendez-vous
C_RendezVous *C_Frm_Day::getFirstRdv(const C_RendezVousList &rendezVousList)
{    C_RendezVous *pRdv    = 0;
     C_RendezVous *pRdvMin = 0;
     QDateTime   minTps;
     QDateTime   current;
     for (int i = 0; i < rendezVousList.size(); ++i)
         {pRdv       = rendezVousList[i];
          current    = pRdv->m_date;
          // au debut faut bien affecter une valeur \303\240 minTps pour commencer
          // soit c'est d'emble la  + petite
          // soit elle le deviendra lors du parcours de la boucle
          if (i==0) {minTps          = current;
                    }
          if (current <= minTps)
             {minTps          = current;
              pRdvMin         = pRdv;
             }
         }
     return pRdvMin;
}

//---------------------------------------- getLastRdv --------------------------------------------
//  NOTE : suppose que m_cacheRDV_List est a jour car se fonde dessus pour creer la liste des widgets de rendez-vous
C_RendezVous *C_Frm_Day::getLastRdv()
{
     C_RendezVous *pRdv    = 0;
     C_RendezVous *pRdvMax = 0;
     QDateTime   maxTps = QDateTime(m_Date,QTime(00,00,01));
     QDateTime   current;
     for (int i = 0; i < m_cacheRDV_List.size(); ++i)
         {pRdv       = m_cacheRDV_List[i];
          current    = pRdv->m_date.addSecs(pRdv->m_Duree*60);
          if (current >= maxTps)
             {maxTps          = current;
              pRdvMax   = pRdv;
             }
         }
     return pRdvMax;
}

//---------------------------------------- RecreateRendezVousListWidget --------------------------------------------
//  NOTE : suppose que m_cacheRDV_List est a jour car se fonde dessus pour creer la liste des widgets de rendez-vous
int C_Frm_Day::RecreateRendezVousListWidget(C_RendezVousList &rendezVousList)
{
    if (m_DontRecreateWidget && m_pCMoteurAgenda->GetVerboseMode()) {qDebug()<< tr("recreate blocked : %1 ").arg(m_DontRecreateWidget); return 0;}
    if (m_pCMoteurAgenda->GetVerboseMode())                         {qDebug()<< tr("recreate not blocked : %1").arg(m_DontRecreateWidget) ;}
         int posY              = 0;
         QTime tpsDeb          = getStartTime();   // QTime::fromString(m_HeureDeb+":00");
         int     y_deb         = FIRST_DAY_POS_Y + m_BaseDayHeight;
         C_Frm_Rdv *pC_Frm_Rdv = 0;
         int nb                =  rendezVousList.size();
         //................... lire la liste des rendez-vous et creer les widget .....................
         clear();
         for (int i = 0; i < nb; ++i)
             {//.......... creer et ajouter le widget du rendez vous .................................
              pC_Frm_Rdv = append_C_Frm_Rdv(new C_Frm_Rdv( rendezVousList.at(i),
                                                           getResoPixByMinutes(),                    // resolution en pixels
                                                           getMagnetisme(),
                                                           m_pQRubberBand,
                                                           m_pCMoteurAgenda,
                                                           m_pColorProfils,
                                                           m_pBMC,
                                                           m_pCMoteurAgenda->GetMinDaysHeight(),
                                                           m_pCMoteurAgenda->GetProportionnalDays(),
                                                           0,0,this
                                                          )
                                           );  //int x = W_OFSET, int y = 0, QWidget *parent = 0));
              //.............. on postionne le rendez vous \303\240 sa place .............................................................
              //               \303\240 la suite de l'autre + l'espace libre
              //               \303\240 ce niveau m_ExpandHeight pointe apres le dernier RDV place .......................................
              posY = tpsDeb.secsTo(pC_Frm_Rdv->m_date.time())/60*getResoPixByMinutes();
              pC_Frm_Rdv->move( W_RDV_OFSET, posY + y_deb);
              pC_Frm_Rdv->show();
             }
         int y_fin      = m_BaseDayHeight;
         if (pC_Frm_Rdv)
            { y_fin  =  y_deb + tpsDeb.secsTo(getStopTime())/60*pC_Frm_Rdv->getResoPixByMinutes();
            }
         return y_fin;
}
//---------------------------------------- readjustListWidgetPositions --------------------------------------------
void C_Frm_Day::readjustListWidgetPositions()
{   C_Frm_Rdv *pC_Frm_Rdv  = 0;
    QTime      tpsDeb      = getStartTime();   // QTime::fromString(m_HeureDeb+":00");
    int        y_deb       = FIRST_DAY_POS_Y + m_BaseDayHeight;
    int posY;
    for (int i = 0; i < C_Frm_RdvList::count(); ++i)
        {pC_Frm_Rdv = at(i);
         posY = tpsDeb.secsTo(pC_Frm_Rdv->m_date.time())/60*getResoPixByMinutes();
         pC_Frm_Rdv->move( W_RDV_OFSET, posY + y_deb);
        }
}

//---------------------------------------- MaskDayToAgendaDay --------------------------------------------
// ACTION : recree une liste de RDV \303\240 partir du masque de RDV prevu pour ce jour et reinitiaise la liste
//          des rdv du jour dessus
int C_Frm_Day::MaskDayToAgendaDay (C_RendezVousList &rendezVousList)
{
 //............. recuperer le template de rdv pour ce jour de la semaine ...................
 int nb = m_pCMoteurAgenda->MASK_GetDay_RDV_List(m_Date,  m_SignUser, rendezVousList);
 if (nb==0) { return 0;}
 //.................. enregistrer tous les rendez-vous modeles de ce jour de la semaine ..............................
 //                   comme rendez-vous pour cette date
 for (int i = 0; i < rendezVousList.size(); ++i)
     {m_pCMoteurAgenda->RDV_Create(*rendezVousList.at(i));
     }
 return nb;
}

//---------------------------------------- time_toPosY --------------------------------------------
int C_Frm_Day::time_toPosY(const QTime &time)
{int posY              = 0;
 QTime tpsDeb          = getStartTime();   // QTime::fromString(m_HeureDeb+":00");
 int     y_deb         = FIRST_DAY_POS_Y + m_BaseDayHeight;
 posY                  = tpsDeb.secsTo(time)/60*getResoPixByMinutes();
 return posY + y_deb;
}

//---------------------------- posY_toTime ------------------------------------------------
QTime   C_Frm_Day::posY_toTime(int posY)
{QTime tpsDeb          = getStartTime();
 if (posY == -1) { return tpsDeb;}
 int     y_deb         = FIRST_DAY_POS_Y + m_BaseDayHeight;
 int     mn            = ((posY - y_deb)/getResoPixByMinutes()); mn /=getMagnetisme(); mn*=getMagnetisme();  // un peu de granulometrie
 return tpsDeb.addSecs(mn*60);
}

//---------------------------- posY_toMinutes ------------------------------------------------
int   C_Frm_Day::posY_toMinutes(int posY)
{QTime tpsDeb          = getStartTime();
 int mnST              = tpsDeb.hour()*60 + tpsDeb.minute();
 if (posY == -1) { return mnST;}
 int     y_deb         = FIRST_DAY_POS_Y + m_BaseDayHeight;
 int     mn            = ((posY - y_deb)/getResoPixByMinutes()); mn /=getMagnetisme(); mn*=getMagnetisme();  // un peu de granulometrie
 return mn + mnST;
}

//====================================================== C_Frm_Rdv ======================================================================
//------------------------------------------------------ pC_RendezVous ----------------------------------------------------------------------
C_Frm_Rdv::C_Frm_Rdv (  C_RendezVous *pC_RendezVous,       // data
                      //........... gui .................
                      int                resoPix ,
                      int             timeGranu ,
                      QRubberBand    *pQRubberBand,
                      CMoteurAgenda     *pCMoteurAgenda ,
                      MAP_COLOR         *colorProfils      ,
                      C_BitMapCollection  *pC_BitMapCollection,
                      int minHeight, int ,
                      int ,  int , QWidget *parent)
         ://........... gui .................
          QFrame(parent)
{   m_PixByMinute         = resoPix;
    m_pBMC                = pC_BitMapCollection;
    m_pCMoteurAgenda      = pCMoteurAgenda;
    m_pColorProfils       = colorProfils;
    m_MinHeight           = minHeight;
    m_GrabIsOn            = 0;
    m_pQRubberBand        = 0;
    m_EditTimerActive     = 0;
    m_Magnetisme          = timeGranu;
    m_Width               = pCMoteurAgenda->GetAgendaWidth();

  //...................... style du cadre g\303\251n\303\251ral .......................................
 /*
 if (pC_RendezVous->m_Type.length())
     setStyleSheet(tr("background-color: ")+(*m_pColorProfils)[pC_RendezVous->m_Type]+"; border: 1px solid #8f8f91; border-radius: 6px;");  // background-color: #960101 background-image: url(images/welcome.png
 else
     setStyleSheet("background-color: #FFFFFF; border: 1px solid #8f8f91; border-radius: 6px;");  // background-color: #960101 background-image: url(images/welcome.png
 */
 //m_pQRubberBand = new QRubberBand(QRubberBand::Rectangle, parent); // ne sera active que lors des l'agrandissement deplacement du widget
 m_pQRubberBand = pQRubberBand;
 setMouseTracking (TRUE );
 setAcceptDrops   (TRUE );
 //...................... placer les labels et le texte ................................
 int  widget_h       = 14-1;                  // hauteur m_MinHeight
 m_widget_w          = m_Width - W_RDV_OFSET;
 m_button_HeureDuree = new C_RdvHeureButton(this);
 //m_button_HeureDuree->setStyleSheet("border: 1px solid #8f8f91;font-size: 8px;top: 2px;");//font-weight: bold;
 m_button_HeureDuree->setFlat(true);
 m_button_HeureDuree->setGeometry( 6,  2, 82,  widget_h-2);

 m_textLabel_Nom     = new QLabel(this);
 m_textLabel_Nom->setGeometry( 137,  2, m_widget_w-137-5, widget_h-2);
 //m_textLabel_Nom->setStyleSheet("border-style: none;font-size: 8px;");

 m_InfoEdit          = new C_AgendaEdit(this);
 m_InfoEdit->setVerticalScrollBarPolicy (Qt::ScrollBarAlwaysOff);
 //m_InfoEdit->setStyleSheet("border: 1px none #8f8f91;padding 6px; border-radius: 6px; font-size: 8px;");

//.................. style des bontons ...................................
//QString style = "QPushButton { border: 1px solid #8f8f91; border-radius: 0px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #f6f7fa, stop: 1 #dadbde);}"    // style normal
//                "QPushButton:pressed {                    border-radius: 0px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #f6f7fa);}";   // style selectionne
m_ButtonDelete = new CMyButton(m_pBMC->m_RdvCancel_Pixmap, this, "", this);
m_ButtonDelete->setGeometry(90, 0, widget_h, widget_h);   // icone = carre donc widget_hxwidget_h
m_ButtonDelete->setFlat( TRUE );
m_ButtonDelete->setToolTip ( "<font color=\"#000000\">"+tr("Delete this appointment")+"</font>" );
//m_ButtonDelete->setStyleSheet(style);  // background-color: #960101 background-image: url(images/welcome.png

m_ButtonChange = new CMyButton(m_pBMC->m_ButtonChange_Pixmap, this, "", this);
m_ButtonChange->setGeometry(105, 0, widget_h, widget_h);
m_ButtonChange->setFlat( TRUE );
m_ButtonChange->setToolTip ( "<font color=\"#000000\">"+TR("Modify the appointment.")+"</font>" );
//m_ButtonChange->setStyleSheet(style);  // background-color: #960101 background-image: url(images/welcome.png

m_ButtonAcceder = new CMyButton(m_pBMC->m_ButtonChange_Pixmap, this, "", this);
m_ButtonAcceder->setGeometry(120, 0, widget_h, widget_h);
m_ButtonAcceder->setFlat( TRUE );
m_ButtonAcceder->setToolTip ( "<font color=\"#000000\">"+TR("Access the patient's folder.")+"</font>" );  //AgendaCreateDoss.png
//m_ButtonAcceder->setStyleSheet(style);  // background-color: #960101 background-image: url(images/welcome.png

//.......................... installer le filtre evenementiel ....................................
m_textLabel_Nom->setMouseTracking (TRUE );
m_button_HeureDuree->setMouseTracking (TRUE );
m_ButtonChange->setMouseTracking (TRUE );
m_ButtonDelete->setMouseTracking (TRUE );
m_ButtonAcceder->setMouseTracking (TRUE );

m_textLabel_Nom->installEventFilter(this);
m_button_HeureDuree->installEventFilter(this);
m_ButtonChange->installEventFilter(this);
m_ButtonDelete->installEventFilter(this);
m_ButtonAcceder->installEventFilter(this);

setWidgetOnRdv(*pC_RendezVous);
setWidgetStyleOnRdv(*pC_RendezVous);

connect( m_ButtonAcceder,      SIGNAL( Sign_ButtonClickedPtr (const char*, void *) ),           parent ,   SLOT(   Slot_ButtonAccederClicked(const char*, void *) ));
//................................ on emet ce signal en direction du pere pour qu'il efface le rendez-vous ......................................
connect( this,                 SIGNAL( Sign_DeleteRendezVous (const char*, void *)  ),          parent ,   SLOT(   Slot_ButtonRDVDeleteClicked(const char*, void *)  ));
connect( m_ButtonDelete,       SIGNAL( Sign_ButtonClickedPtr (const char*, void *)  ),          parent ,   SLOT(   Slot_ButtonRDVDeleteClicked(const char*, void *)  ));
connect( this,                 SIGNAL( Sign_RendezVousChangeClicked(C_Frm_Rdv*)),               parent ,   SLOT(   Slot_RendezVousChangeClicked(C_Frm_Rdv*)));
connect( this,                 SIGNAL( Sign_StopTimer(int )),                                   parent ,   SLOT(   Slot_StopTimer(int)));
connect( this,                 SIGNAL( Sign_ReplaceRdvByDroppedRdv(C_Frm_Rdv *)),               parent ,   SLOT(   Slot_ReplaceRdvByDroppedRdv(C_Frm_Rdv *)));

connect( m_ButtonChange,       SIGNAL( Sign_ButtonClickedPtr (const char*, void *)  ), this ,     SLOT(   Slot_ButtonChangeClicked(const char*, void *)  ));
connect( m_button_HeureDuree,  SIGNAL( clicked ()  ),                                  this ,     SLOT(   Slot_textLabel_HeureClicked()  )  );
connect( m_InfoEdit,           SIGNAL( textChanged ()),                                this ,     SLOT(   Slot_InfoEdittextChanged()  )  );
connect( m_InfoEdit,           SIGNAL( cursorPositionChanged ()),                      this ,     SLOT(   Slot_InfoEdit_cursorPositionChanged()  )  );
connect( m_InfoEdit,           SIGNAL( Sign_focusOutEvent(QFocusEvent *)),             this ,     SLOT(   Slot_InfoEditFocusOutEvent(QFocusEvent *)  )  );
 /*
  if (CMoteurBase::IsThisDroitExist(G_pCApp->m_Droits, "agc")) {m_ButtonDelete->setEnabled(TRUE);   m_ButtonChange->setEnabled(TRUE);}
  else                                                         {m_ButtonDelete->setEnabled(FALSE);  m_ButtonChange->setEnabled(FALSE);}
 */
}
//------------------------ ~C_Frm_Rdv ---------------------------------------
C_Frm_Rdv::~C_Frm_Rdv()
{
}
//------------------------ paintEvent ---------------------------------------
void C_Frm_Rdv::paintEvent ( QPaintEvent * /*event*/ )
{ QColor color(getRdvColor());
  QPainter p(this);
  //int h = height();
  //p.setPen (color.lighter(150));
  //for (int i = 4; i <h-5; ++i)
  //    {/*if (i&1) */p.drawLine(1,i,4,i);
  //    }
  p.fillRect ( 1, 4, 4, height()-8, color.lighter(150) );
  //p.setPen (Qt::gray);
  //QRectF rect (0,10,4,h-23);
  //p.drawRoundedRect (rect, 0, 0);

  //QFrame::paintEvent(event);
}
//---------------------------------------- getMagnetisme --------------------------------------------
int C_Frm_Rdv::getMagnetisme()
{return m_Magnetisme;
}

//---------------------------------------- setWidgetStyleOnRdv --------------------------------------------
void C_Frm_Rdv::setWidgetStyleOnRdv(const C_RendezVous &rdv) // to do : detecter si la date n'est pas en dehors du jour actuel
{QString background_color = C_RendezVous::getRdvColor(rdv, m_pColorProfils);
 //QString styles = QString(" background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 %1, stop: 1 #dadbde);").arg(background_color);
 QString styles = QString("background-color: %1; border: 1px solid #8f8f91; border-radius: 6px; font-size: 9px;").arg(background_color);
 //QString styles = QString("background-color: %1;  qlineargradient(x1: 0, y1: 0, x2: 0.5, y2: 0.5, stop: 0 #FF92BB, stop: 1 white); border:1px; border-radius: 6px; font-size: 9px;").arg(background_color);
 //QString styles = QString("background-color: %1; border: 3px solid #8f8f91; border-radius: 6px; font-size: 9px;").arg("qlineargradient(x1: 0, y1: 0, x2: 0.5, y2: 0.5, stop: 0 #FF92BB, stop: 1 white)");

 setStyleSheet(styles);

 QString style = "QPushButton { border: 1px solid #8f8f91; border-radius: 0px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #f6f7fa, stop: 1 #dadbde);}"    // style normal
                 "QPushButton:pressed {                    border-radius: 0px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #f6f7fa);}";   // style selectionne
 m_ButtonDelete->setStyleSheet(style);   // background-color: #960101 background-image: url(images/welcome.png
 m_ButtonChange->setStyleSheet(style);   // background-color: #960101 background-image: url(images/welcome.png
 m_ButtonAcceder->setStyleSheet(style);  // background-color: #960101 background-image: url(images/welcome.png
 m_InfoEdit->setStyleSheet(QString("background-color: %1; border: 1px none #8f8f91;padding 6px; border-radius: 6px; font-size: 9px;").arg(background_color));
 m_InfoEdit->setMenuBackgroundColor((*m_pColorProfils)[rdv.m_Type].getColor());
 m_button_HeureDuree->setStyleSheet(QString("background-color: %1; border: 1px solid #8f8f91;font-size: 9px;top: 2px;").arg(background_color));//font-weight: bold;
 m_textLabel_Nom->setStyleSheet(QString("background-color: %1; border-style: none;font-size: 9px;").arg(background_color));
}

//---------------------------------------- setWidgetOnRdv --------------------------------------------
void C_Frm_Rdv::setWidgetOnRdv(const C_RendezVous &rdv) // to do : detecter si la date n'est pas en dehors du jour actuel
{m_date     = rdv.m_date;
 m_Duree    = rdv.m_Duree;
 m_Nom      = rdv.m_Nom;
 m_Prenom   = rdv.m_Prenom;
 m_Tel      = rdv.m_Tel;
 m_Note     = rdv.m_Note;
 m_GUID     = rdv.m_GUID;
 m_PrisPar  = rdv.m_PrisPar;
 m_PrisAvec = rdv.m_PrisAvec;
 m_Type     = rdv.m_Type;
 m_PrimKey  = rdv.m_PrimKey;
 m_State    = rdv.m_State;
 m_Where    = rdv.m_Where;
 m_InfoEdit->setText(m_Note);
 m_button_HeureDuree->setText(computeTextButton());
 m_textLabel_Nom->setText(m_Nom + " " + m_Prenom);
 placeInfoEdit(m_Duree*m_PixByMinute);
 //......................... les tool tip ..................................
 if ( m_GUID.length()!=0) m_ButtonAcceder->setIcon(m_pBMC->m_ButtonAcceder_Pixmap);
 else                     m_ButtonAcceder->setIcon(m_pBMC->m_ButtonCreateDoss);

 //....................... rechercher le statut .............................
 QString statutRdv = rdv.m_State;

 if (statutRdv.length()==0) statutRdv = tr("Undefined status");
 else
    {QMap<QString, QPixmap>::const_iterator it = m_pBMC->m_StatutsPixmap.find(statutRdv);
     if (it != m_pBMC->m_StatutsPixmap.end())    m_ButtonChange->setIcon(it.value());
    }
 resize ( QSize ( m_widget_w, getHeight())) ;
}

//---------------------------- Slot_InfoEditFocusOutEvent ------------------------------------------------
void C_Frm_Rdv::Slot_InfoEditFocusOutEvent(QFocusEvent *)
{m_Note = m_InfoEdit->text();
 RDV_Update();
 //emit Sign_StopTimer(m_SavStateLook);
}

//---------------------------------------- Slot_InfoEdit_cursorPositionChanged -----------------------------------------
void C_Frm_Rdv::Slot_InfoEdit_cursorPositionChanged ()
{Slot_InfoEdittextChanged();
}
//---------------------------- Slot_InfoEdittextChanged ------------------------------------------------
void C_Frm_Rdv::Slot_InfoEdittextChanged()
{m_Note     = m_InfoEdit->text();
 if (m_EditTimerActive==0)
    {emit Sign_StopTimer(1);
     QTimer::singleShot(2000, this, SLOT(Slot_EditTimeOut()));
     m_EditTimerActive = 1;
    }
}
//---------------------------- Slot_EditTimeOut ------------------------------------------------
void C_Frm_Rdv::Slot_EditTimeOut()
{m_Note     = m_InfoEdit->text();
 RDV_Update();
 m_EditTimerActive = 0;
 emit Sign_StopTimer(0);
}

//---------------------------- placeInfoEdit ------------------------------------------------
void C_Frm_Rdv::placeInfoEdit (int h)
 {  int ofsetY = 15;
    if (h>28)
       {m_InfoEdit->show();
       }
    else
       {m_InfoEdit->hide();
       }
    m_InfoEdit->setGeometry ( 6, ofsetY, 200, h-ofsetY-4 );
 }
//---------------------------- setGeometry ------------------------------------------------
void C_Frm_Rdv::setGeometry ( int x, int y, int w, int h )
 { QFrame::setGeometry(x,y,w,h);
    placeInfoEdit (h);
 }
//---------------------------- dragEnterEvent ------------------------------------------------
void C_Frm_Rdv::dragEnterEvent(QDragEnterEvent *event)
 {  if (event->mimeData()->hasFormat("text/medintux_rdv_drag"))
       {event->acceptProposedAction();
       }
 }
//---------------------------- dragMoveEvent ------------------------------------------------
void C_Frm_Rdv::dragMoveEvent(QDragMoveEvent * event)
 {  if (event->proposedAction() == Qt::CopyAction && event->mimeData()->hasFormat("text/medintux_rdv_drag"))
        {event->acceptProposedAction ();
        }
 }
//---------------------------- dropEvent ------------------------------------------------
void C_Frm_Rdv::dropEvent(QDropEvent *event)
 {  if (event->proposedAction() == Qt::CopyAction && event->mimeData()->hasFormat("text/medintux_rdv_drag"))
        {const QMimeData *mimeData            = event->mimeData();
         ((C_Frm_Day*)parent())->m_DropedRdv  = C_RendezVous::unSerialize(QString(mimeData->data ( "text/medintux_rdv_drag" )));
         QTimer::singleShot(10, this, SLOT(Slot_Drop_Rdv ()));
         event->acceptProposedAction ();
        }
 }
//---------------------------- dragLeaveEvent ------------------------------------------------
void C_Frm_Rdv::dragLeaveEvent ( QDragLeaveEvent *  )
{   ((C_Frm_Day*)parent())->m_DropedRdv.m_GUID = "";   // effacer les donnees du rdv venant du drag and drop
}

//------------------------ Slot_Drop_Rdv -----------------------------------------------------
void C_Frm_Rdv::Slot_Drop_Rdv ()
{  emit Sign_ReplaceRdvByDroppedRdv(this); // recuperer de l'info dans un eventel OBJET connect\303\251
}

//---------------------------- eventFilter ------------------------------------------------
bool C_Frm_Rdv::eventFilter(QObject *obj, QEvent *event)
     {
      if (obj == m_textLabel_Nom     ||
          //obj == m_textLabel_Type    ||
          obj == m_button_HeureDuree ||
          obj == m_ButtonChange      ||
          obj == m_ButtonDelete      ||
          obj == m_ButtonAcceder
         )
         {
          if (event->type() == QEvent::MouseMove)
             {QMouseEvent  *mouseEvent = static_cast<QMouseEvent*>(event);
              QWidget        *pQWidget = static_cast<QWidget*> (obj);
              QMouseEvent  modifiedMouseEvent(QEvent::MouseMove,
                                              pQWidget->mapToParent( mouseEvent->pos() ),
                                              mouseEvent->globalPos() ,
                                              mouseEvent->button(),
                                              mouseEvent->buttons(),
                                              Qt::NoModifier
                                              );
              mouseMoveEvent (&modifiedMouseEvent , pQWidget);
              return true;
             }
          else
             {return false;
             }
         }
      else
         {// pass the event on to the parent class
           return QFrame::eventFilter(obj, event);
         }
    }
//---------------------------- getRdvColor ------------------------------------------------
QString C_Frm_Rdv::getRdvColor()
{return C_RendezVous::getRdvColor(*this, m_pColorProfils);
}

//---------------------------- getQWhatsThisString ------------------------------------------------
QString C_Frm_Rdv::getQWhatsThisString()
{return C_RendezVous::getQWhatsThisString(Theme::getPath(TRUE), C_RendezVous::getRdvColor(*this, m_pColorProfils));
}

//---------------------------- Slot_textLabel_HeureClicked ------------------------------------------------
void C_Frm_Rdv::Slot_textLabel_HeureClicked()
{QWhatsThis::showText (QCursor::pos(), getQWhatsThisString());
}

//---------------------------- Slot_ButtonChangeClicked ------------------------------------------------
void C_Frm_Rdv::Slot_ButtonChangeClicked(const char*, void *ptr)
{if (ptr==0) return;
 emit Sign_RendezVousChangeClicked(this);
}

//---------------------------- computeTextButton ------------------------------------------------
QString C_Frm_Rdv::computeTextButton()
{QString str  = m_date.time().toString("hh:mm")+"/";
 if (m_Duree>60)
     str += QTime(0,0,0).addSecs(m_Duree*60).toString("hh:mm").replace(':','h');
 else
     str += QString::number(m_Duree)+" mn";
 return str;
}

//---------------------------- posY_toTime ------------------------------------------------
QTime   C_Frm_Rdv::posY_toTime(int posY)
{return ((C_Frm_Day*)parent())->posY_toTime(posY);
}
//---------------------------- time_toPosY ------------------------------------------------
int   C_Frm_Rdv::time_toPosY(const QTime &tm)
{return ((C_Frm_Day*)parent())->time_toPosY(tm);
}
//---------------------------- mouseMoveEvent ------------------------------------------------
void    C_Frm_Rdv::mouseMoveEvent ( QMouseEvent * event )
{mouseMoveEvent ( event , 0 );
}
//---------------------------- adjustToMagnetisme ------------------------------------------------
int    C_Frm_Rdv::adjustToMagnetisme(int value)
{return ((C_Frm_Day*)parent())->adjustToMagnetisme(value);
}

//---------------------------- mouseMoveEvent ------------------------------------------------
void    C_Frm_Rdv::mouseMoveEvent ( QMouseEvent * event , QWidget *pQWidget )
{int y         = event->pos().y();
 //int y         = adjustToMagnetisme(event->pos().y());
 if (m_GrabIsOn)
    {int deltaY    =  y - m_startPosY;
     if (qAbs( deltaY) )
        {QRect rect    = geometry ();
         if (m_GrabIsOn==TOP_START)
            {int posY = rect.y()+deltaY;
             m_pQRubberBand->setGeometry (rect.x(),  posY, width(), qMax(height() - deltaY, 3));
             m_date       = QDateTime(m_date.date(), posY_toTime(posY));
             m_Duree      = qMax((height() - deltaY)/getResoPixByMinutes(), getMagnetisme());
             m_button_HeureDuree->setText(computeTextButton());
             rect = m_pQRubberBand->geometry ();
             setGeometry(rect.x(),posY,rect.width(),rect.height());
            }
         else if ( m_GrabIsOn==BOTTOM_START)
            {m_pQRubberBand->setGeometry (rect.x(), rect.y(), width(), qMax(height() + deltaY, 3));
             m_Duree      = qMax((height() + deltaY)/getResoPixByMinutes(), getMagnetisme());
             m_button_HeureDuree->setText(computeTextButton());
             //............ marche pas ici (boucle reentrante)................
             //rect = m_pQRubberBand->geometry ();
             //setGeometry(rect.x(),rect.y(),rect.width(),rect.height());
            }
         else if ( m_GrabIsOn==MIDLE_START)
            {int posY = rect.y() + deltaY;
             posY     = adjustToMagnetisme(posY);
             m_pQRubberBand->setGeometry (rect.x(),  posY, width(), height());
             m_date       = QDateTime(m_date.date(), posY_toTime(posY));
             m_button_HeureDuree->setText(computeTextButton());
             rect = m_pQRubberBand->geometry ();
             setGeometry(rect.x(),rect.y(),rect.width(),rect.height());
            }
        }
    }
  else
    { if (pQWidget)    // si on est au dessus d'un widget fils
         { setCursor(Qt::ArrowCursor);
         }
      else
         {if (y<=SIZE_BORDER_DAY || y>=height()-SIZE_BORDER_DAY)
             { setCursor(Qt::SizeVerCursor);
             }
          else
             { setCursor(Qt::OpenHandCursor);
             }
         }
    }
  QFrame::mouseMoveEvent ( event );
}

//---------------------------- mouseReleaseEvent ------------------------------------------------
void C_Frm_Rdv::mouseReleaseEvent ( QMouseEvent * /*event*/ )
{int isPositionModified = 0;   // petite sophistication : ne poser la question que si changement de coordonnees sinon cassos
 if (m_GrabIsOn)
    {QRect rect          = m_pQRubberBand->geometry ();
     if (m_GrabIsOn==TOP_START)    // chichiterie indispensable pour reajuster la date en gardant le bas fixe
        {QTime tm = posY_toTime(rect.y() + rect.height());
         int   mn = tm.hour()*60+tm.minute()-m_Duree;
         int   hr = mn/60; mn = mn - hr*60;
         m_date   = QDateTime(m_date.date(),QTime(hr,mn));
        }
     isPositionModified  = m_PosYSav - y() + m_HeightSav- rect.height();
    }
 m_pQRubberBand->hide();
 releaseMouse();           // degraber la souris
 setCursor(Qt::SizeVerCursor);
 if (!m_pCMoteurAgenda->isModifToConfirm()&1) RDV_Update();
 if (isPositionModified)
    {
     if (m_pCMoteurAgenda->isModifToConfirm()&1 &&
         QMessageBox::question ((QWidget*)parent(),
                                tr("Confirm modification"),
                                tr("The features of this appointment have been modified \nConfirm modifications "),
                                QMessageBox::Ok|QMessageBox::Cancel)==QMessageBox::Cancel)
        {m_date                      = m_C_RendezVousSav.m_date; // restituer la config initiale
         m_Duree                     = m_C_RendezVousSav.m_Duree;
         m_button_HeureDuree->setText(computeTextButton());
         this->setGeometry(m_PosXSav,m_PosYSav,m_WidthSav,m_HeightSav);
        }
    }
 adjustWidgetToMagnetisme();                             // recadrer le widget aux contraintes du magnetisme
 RDV_Update();                                           // enregistrer en base
 ((C_Frm_Day*)parent())->readjustListWidgetPositions();  // revoir toutes les positions car le debut peut avoir change si place avant la limite sup
 ((C_Frm_Day*)parent())->ReArangeIfDayHeightChange();    // reajuster eventuellement la hauteur du jour et reorganiser les jours sous jacents et mettre a jour la hauteur du jour
 emit Sign_StopTimer(0);                                 // debloquer le timer de mise a jour
 m_GrabIsOn  = 0;
}

//---------------------------- adjustWidgetToMagnetisme ------------------------------------------------
void C_Frm_Rdv::adjustWidgetToMagnetisme(C_Frm_Rdv::adjustMode mode  /* = C_Frm_Rdv::TimeAndGraphic */)
{int mag           = getMagnetisme();
 int midleMag      = mag/2;
 m_Duree           = (m_Duree+midleMag)/mag; m_Duree = qMax((int)m_Duree * mag, qMax(m_MinHeight/getResoPixByMinutes(),mag));
 int   mn          = m_date.time().hour()*60+m_date.time().minute();    mn = (mn+midleMag) / mag; mn *= mag;
 int   hr          = mn / 60;
       mn          = mn - hr*60;
 QTime tm          = QTime(hr,mn);
 m_date            = QDateTime(m_date.date(), tm);
 if (mode==C_Frm_Rdv::JustTime) return;
 m_button_HeureDuree->setText(computeTextButton());
 setGeometry(0,0,m_widget_w, m_Duree*getResoPixByMinutes());
 move(W_RDV_OFSET, time_toPosY(tm));
}

//---------------------------- mousePressEvent ------------------------------------------------
void C_Frm_Rdv::mousePressEvent(QMouseEvent *event)
 {   if (event->button() == Qt::LeftButton)
        {if (m_GrabIsOn==0)
            {
             ((C_Frm_Day*)parent())->Slot_StopTimer(1);   // le timer sera debloque lors du release button
             //.............. ajuster le rectangle de depart au magnetisme .................
             //               au cas ou le rendez vous ne serait pas aligne
             m_C_RendezVousSav = *this;            // sauver la config initiale
             m_PosXSav         = x();
             m_PosYSav         = y();
             m_WidthSav        = width();
             m_HeightSav       = height();

             QRect rect        = geometry ();
             int top           = rect.y();          //adjustToMagnetisme(rect.y());
             int htr           = rect.height();     //rect.height()/getMagnetisme(); htr     = qMax(htr * getMagnetisme(), getMagnetisme()) ;
             int y             = event->pos().y();  //adjustToMagnetisme(event->pos().y());
             m_startPosY       = y;

             //..................... on demarre le rectangle elastique .....................
             if (m_startPosY<=SIZE_BORDER_DAY)
                { m_GrabIsOn = TOP_START;
                  m_pQRubberBand->setGeometry (rect.x(), top, width(), htr);
                  //m_pQRubberBand->show(); inutile car rajustement de la taille du widget cible se fait en temps reel
                  grabMouse (QCursor(Qt::SizeVerCursor));
                }
             else if ( m_startPosY>=height()-SIZE_BORDER_DAY)
                { m_GrabIsOn = BOTTOM_START;
                  m_pQRubberBand->setGeometry (rect.x(), top, width(), htr);
                  m_pQRubberBand->show();   // oblige car le reajustemnt en temps reel ne fonctionne pas (boucle)
                  grabMouse (QCursor(Qt::SizeVerCursor));
                  m_pQRubberBand->show();
                }
             else
                { m_GrabIsOn = MIDLE_START;
                  m_pQRubberBand->setGeometry (rect.x(), top, width(), htr);
                  //m_pQRubberBand->show(); //m_pQRubberBand->show(); inutile car rajustement de la taille du widget cible se fait en temps reel
                  setCursor(Qt::ClosedHandCursor);
                }
             rect = m_pQRubberBand->geometry ();
             setGeometry(rect.x(),rect.y(),rect.width(),rect.height());
             }
         else
             {/*
              QDrag *drag         = new QDrag(this);
              QMimeData *mimeData = new QMimeData;
              QRect rect(-4,0,width(),height());

              QPixmap pix = QPixmap::grabWidget (this, rect );
              mimeData->setText("Drag day");
              mimeData->setImageData(pix);
              drag->setMimeData(mimeData);
              drag->setPixmap(pix);
              Qt::DropAction dropAction = drag->exec();
              */
             }
         }
     else if (event->button() == Qt::RightButton && m_GrabIsOn==0)
         { //................ menu ....................
           ((C_Frm_Day*)parent())->Slot_StopTimer(1);   // le timer ser debloque lors du release button
           QString       ret =  ((C_Frm_Day*)parent())->doRdvMenu(this->rdv_instance());
           // "Copy" "Replace" "Cut" "Type :" "Status :"  "Modify"  "Open" "Anomymize" "Quit"
           if (ret.length())
              {if (ret.indexOf("Status :") != -1)
                  { QString statut = ret.remove("Status :");
                    m_State = statut.trimmed();
                    setWidgetOnRdv(*this);                // on reajuste le widget sur les nouvelles donn\303\251es
                    setWidgetStyleOnRdv(*this);
                    RDV_Update();
                  }
               else if (ret.indexOf("Type :") != -1)
                  { QString type = ret.remove("Type :");
                    m_Type = type.trimmed();
                    setWidgetOnRdv(*this);                // on reajuste le widget sur les nouvelles donn\303\251es
                    setWidgetStyleOnRdv(*this);
                    RDV_Update();
                  }
               else if (ret.indexOf("Cut") != -1)  // il ne  peut pas se detruire lui meme et sortir ensuite de sa fonction donc QTIMER
                  {QTimer::singleShot(10, this, SLOT(Slot_cut()) );
                  }
               else if (ret.indexOf("Copy") != -1)
                    Slot_copy();
               else if (ret.indexOf("Replace") != -1)
                    replaceWithCopy();
               else if (ret.indexOf("Modify") != -1)
                  {emit Sign_RendezVousChangeClicked(this);
                  }
               else if (ret.indexOf("Anomymize") != -1)
                  {m_Nom="";
                   m_Prenom="";
                   m_GUID="";
                   m_Tel="";
                   m_Note="";
                   m_Where="";
                   setWidgetOnRdv(*this);                // on reajuste le widget sur les nouvelles donn\303\251es
                   setWidgetStyleOnRdv(*this);
                   RDV_Update();
                  }
               else if (ret.indexOf("Open") != -1)
                  {((C_Frm_Day*)parent())->Slot_ButtonAccederClicked(0, this);
                  }
              }
         event->accept();
         ((C_Frm_Day*)parent())->Slot_StopTimer(0);
        }
 }

//---------------------------------------- RDV_Update --------------------------------------------
void C_Frm_Rdv::RDV_Update()
{ //............ enregistrer ...............
 QString errMess;
 if ( ! m_pCMoteurAgenda->RDV_Update(*this, &errMess) )
    {qDebug()<< errMess;
    }
 ((C_Frm_Day*)parent())->generate_cacheRDV_List_FromDayWidget();  // la on peut on est forcement en position ouverte (widgets presents)
}
//---------------------------------------- isCopyExist --------------------------------------------
bool C_Frm_Rdv::isCopyExist()
{ return QApplication::clipboard()->mimeData()->hasFormat("text/medintux_rdv");
}
//---------------------------------------- getCopy --------------------------------------------
C_RendezVous C_Frm_Rdv::getCopy()
{   C_RendezVous rdv;
    const QClipboard *clipboard = QApplication::clipboard();
    const QMimeData *mimeData   = clipboard->mimeData();
    if (mimeData->hasFormat ("text/medintux_rdv" ))
       {rdv = C_RendezVous::unSerialize(QString(mimeData->data ( "text/medintux_rdv" )));
       }
    return rdv;
}

//---------------------------------------- Slot_copy --------------------------------------------
void C_Frm_Rdv::Slot_copy()
{QByteArray data(serialize(this).toAscii());
 QMimeData *mimeData = new QMimeData;
 mimeData->setData("text/medintux_rdv", data);
 QClipboard *clipboard = QApplication::clipboard();
 clipboard->setMimeData ( mimeData );    // a ne pas deleter
}

//---------------------------------------- serialize --------------------------------------------
QString C_Frm_Rdv::serialize(C_Frm_Rdv *pC_Frm_Rdv)
{return C_RendezVous::serialize(pC_Frm_Rdv);
}

//---------------------------------------- unSerialize --------------------------------------------
C_RendezVous C_Frm_Rdv::unSerialize(const QString & data)
{return C_RendezVous::unSerialize(data);
}
//---------------------------------------- replaceWithCopy --------------------------------------------
void C_Frm_Rdv::replaceWithCopy()
{
 if ( !isCopyExist()) return;
 C_RendezVous    rdv = getCopy();    // on recupere le rendez-vous
 rdv.m_date          = m_date;       // on garde la date d'origine
 rdv.m_PrimKey       = m_PrimKey;    // on garde la primary key car on est sur le meme rendez-vous
 rdv.m_PrisPar       = m_PrisPar;    // on garde l'utilisateur qui a pris le RDV
 rdv.m_PrisAvec      = m_PrisAvec;   // on garde l'utilisateur en cours
 rdv.m_State         = m_State;
 setWidgetOnRdv(rdv);                // on reajuste le widget sur les nouvelles donn\303\251es
 setWidgetStyleOnRdv(rdv);
 RDV_Update();
}

//---------------------------------------- Slot_cut --------------------------------------------
void  C_Frm_Rdv::Slot_cut()
{Slot_copy();
 emit Sign_DeleteRendezVous ("d\303\251gage tu pues", (void*) this);  // ca va au pere (le jour) qui le tue
}

//---------------------------- GetHeight ------------------------------------------------
int C_Frm_Rdv::getHeight()
{int height  = m_Duree * m_PixByMinute; // height = qMax( m_Duree * m_PixByMinute,  (long)m_MinHeight);
 return qMax(height, m_MinHeight);   // il faut un minimum de visibilite
}

/*
//====================================== C_LabelDrag =======================================================
bool C_LabelDrag::event ( QEvent * e )
{ //QString txt = this->text();
  QRect rect = this->rect();
  if (e->type()==QEvent::Move)
     {//qDebug() << QString::number(e->type());
      //QToolTip::showText (QCursor::pos(), toolTip () , this);
      //QToolTip::showText (QCursor::pos(),  this->text(), this, rect );
      //setUpdatesEnabled(FALSE);
      //QTimer::singleShot(3,this,SLOT (repaint ()));
     }
  if (e->type()==QEvent::Paint)
     {
        paintEvent ( (QPaintEvent *) e);
     }
  return false;
}

// juste pour ajuster le widget a la largeur du texte
//---------------------------- paintEvent ------------------------------------------------
// juste pour ajuster le widget a la largeur du texte
void C_LabelDrag::paintEvent ( QPaintEvent * event )
    {QString txt = this->text();
     QPainter p(this);
     QRect rect = p.boundingRect (this->rect(), Qt::TextSingleLine, text());
     rect.setHeight(height());
     //if (text().length()>60)
     //if (0)
     //{
         rect.setWidth((int)((float)rect.width()*0.3));
         resize( rect.width(),height());
         p.drawText(3,rect.height(),this->text());
         qDebug() << txt;
     //}
     //QLabel::paintEvent(event);
    }
*/
