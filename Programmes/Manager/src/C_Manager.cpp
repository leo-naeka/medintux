/********************************* C_Manager.cpp *********************************
*  #include "C_Manager.h"                                                        *
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
*   Commissariat \303\240 l'Energie Atomique                                            *
*   - CEA,                                                                       *
*                            31-33 rue de la F\303\251d\303\251ration, 75752 PARIS cedex 15.   *
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

#include "C_Manager.h"
#include "ui_C_Manager.h"

#include "CApp.h"
#include "../../MedinTuxTools-QT4/Theme/Theme.h"
#include "../../MedinTuxTools-QT4/Theme/ThemePopup.h"
#include "../../MedinTuxTools-QT4/C_QWebView/C_QWebView.h"
#include "../../MedinTuxTools-QT4/Agenda/C_Dlg_Agenda.h"
#include "../../MedinTuxTools-QT4/C_DragQTreeWidget/C_DragQTreeWidget.h"
#include "../../MedinTuxTools-QT4/UserList/C_Frm_UserList.h"
#include "../../MedinTuxTools-QT4/C_Dlg_DoList/C_Dlg_DoList.h"
#include "../../MedinTuxTools-QT4/CHtmlTools.h"
#include "../../SesamVitale-QT4/C_Vitale.h"
#include "C_Dlg_Assure.h"

#include <QString>
#include <QStringList>
#include <QAction>
#include <QTextStream>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QProcess>
#include <QHeaderView>
#include <QPixmap>
#include <QComboBox>
#include <QKeyEvent>
#include <QWhatsThis>
#include <QCursor>
#include <QKeySequence>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QBoxLayout>
#include <QFrame>
#include <QProcess>
#include <QFileInfo>
#include <QSqlError>
#include <QLineEdit>
#include <QUrl>
#include <QtWebKit/QWebView>
#include <QWebSettings>
#include <QHostInfo>
#include <QPrintDialog>
#include <QPrinter>
#include <QInputDialog>
#include <QFontDialog>
#include <QSettings>                    //Cz_Pyxvital

#define MODE_SELECTION_PATIENT 0
#define MODE_CREATION_PATIENT  1
#define MODE_MULTICRITERE      2

//#define SESAM_VERSION
#define AGENDA_SUB_TITLE_H    15
#define W_DATE_EDIT           70
#define ID_INTERV              4


//====================================== C_Manager ==========================================================
//--------------------------------------------------------- C_Manager ---------------------------------------
C_Manager::C_Manager(CMoteurBase *pCMoteurBase,  QWidget *parent, const QString & name)
   : QMainWindow(parent, name), m_pGUI(new Ui::C_ManagerClass), m_pCMoteurBase(pCMoteurBase)
{   m_Apropos_Proc      = 0;
   m_List_GUI_Mode[0]  = "MODE_SELECTION_PATIENT";
   m_List_GUI_Mode[1]  = "MODE_CREATION_PATIENT";
   m_List_GUI_Mode[2]  = "MODE_MULTICRITERE";
   m_pGUI->setupUi(this);
   m_pGUI->textEdit_Changements->hide(); // juste present pour contenir le texte des changements
   m_pC_Frm_UserList   = 0;
   m_Ident_IsModified  = 0;
   m_Contacts_Run      = FALSE;
   m_NomadismeToolBar  = 0;
   m_FSEenCours        = FALSE;            //Cz_Pyxvital
   m_timerFSE          = 0;                //Cz_Pyxvital

   // ................ listview patient (pomotion de C_DragQTreeWidget)  .................................
   m_pGUI->listView_Patient->setSortingEnabled(true);
   m_pGUI->listView_Patient->setMimeType("text/medintux_rdv_drag");
   QHeaderView *pQHeaderView = m_pGUI->listView_Patient->header();     // cacher les colonnes du Pk et GUID
   pQHeaderView->hideSection (2);
   pQHeaderView->hideSection (3);
   m_pGUI->listView_Patient->setAlternatingRowColors ( TRUE );
   m_pGUI->listView_Patient->setContextMenuPolicy ( Qt::CustomContextMenu );  //Qt::CustomContextMenu
   //m_pGUI->listView_Patient->setDragEnabled (TRUE );                           // ne surtout pas activer car active les mecanismes de la classe de base
   //m_pGUI->listView_Patient->setDragDropMode ( QAbstractItemView::DragOnly );  // et c'est le boxon

   //qDebug(QHostInfo::localHostName ()+"."+QHostInfo::localDomainName ());
   //QString background_color = "#1200ff";
   //QString styles           = QString("background-color: %1; border: 1px solid #8f8f91; border-radius: 6px; font-size: 9px;").arg(background_color);
   //QString styles           = QString("background: qlineargradient(x1:0, y1:0, x2:1, y2:1,stop:0 white, stop: 0.4 #00e4ff, stop:1 #007eff); border: 1px solid #8f8f91; border-radius: 6px; font-size: 9px;");
   QString styles           = QString("background: qlineargradient(x1:0, y1:0, x2:1, y2:1,stop:0 white, stop: 0.4 #00e4ff, stop:1 #007eff); border: 1px solid #8f8f91; border-radius: 1px; font-size: 9px;");
       //..............................//////// MENUS ////////.................................................
   //................................. options de menus ....................
   m_actionRecordWindowsPos = new QAction(this);
   m_actionRecordWindowsPos->setObjectName(QString::fromUtf8("actionRecordWindowsPos"));
   m_actionSetGlobalFont = new QAction(this);
   m_actionSetGlobalFont->setObjectName(QString::fromUtf8("actionSetGlobalFont"));
   m_actionHideShowLogo  = new QAction(this);
   m_actionHideShowLogo->setObjectName(QString::fromUtf8("actionHideShowLogo"));
   //m_actionRecordWindowsPos->setText(QApplication::translate("C_ManagerClass", "Enregistrer la position des fen\303\252tres", 0, QApplication::UnicodeUTF8));

   m_action_ModeNomade = new QAction(this);
   m_action_ModeNomade->setObjectName(QString::fromUtf8("action_ModeNomade"));
   //m_action_ModeNomade->setText(QApplication::translate("C_ManagerClass", "Nomadisme", 0, QApplication::UnicodeUTF8));

   m_action_ToModeConnect = new QAction(this);
   m_action_ToModeConnect->setObjectName(QString::fromUtf8("action_ToModeConnect"));
   //m_action_ToModeConnect->setText(QApplication::translate("C_ManagerClass", "J'arrive et me reconnecte au serveur", 0, QApplication::UnicodeUTF8));

   m_action_UserParams = new QAction(this);
   m_action_UserParams->setObjectName(QString::fromUtf8("action_GestionProfils"));

   m_action_DebloquerBases = new QAction(this);
   m_action_DebloquerBases->setObjectName(QString::fromUtf8("action_DebloquerBases"));
   //m_action_DebloquerBases->setText(QApplication::translate("C_ManagerClass", "D\303\251bloquer les bases et les verrous", 0, QApplication::UnicodeUTF8));

   m_action_AccesWebMedTux = new QAction(this);
   m_action_AccesWebMedTux->setObjectName(QString::fromUtf8("action_AccesWebMedTux"));

   m_actionImprimer = new QAction(this);
   m_actionImprimer->setObjectName(QString::fromUtf8("actionImprimer"));
   m_actionImprimer->setShortcutContext(Qt::ApplicationShortcut);

   m_actionQuitter = new QAction(this);
   m_actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
   m_actionQuitter->setShortcutContext(Qt::ApplicationShortcut);


   m_action_NouveauDossier = new QAction(this);
   m_action_NouveauDossier->setObjectName(QString::fromUtf8("actionNouveauDossier"));
   m_action_NouveauDossier->setShortcutContext(Qt::ApplicationShortcut);
   //m_actionQuitter->setShortcut(QApplication::translate("C_ManagerClass", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
   //m_actionQuitter->setText(QApplication::translate("C_ManagerClass", "Quitter", 0, QApplication::UnicodeUTF8));

   //..........//////// barre de menus ////////....................
   m_menuBar = new QMenuBar(this);
   m_menuBar->setObjectName(QString::fromUtf8("menuBar"));
   m_menuBar->setGeometry(QRect(0, 0, 1015, 23));
   //................. menu fichier ..........................
   m_menuFichiers = new QMenu(m_menuBar);
   m_menuFichiers->setObjectName(QString::fromUtf8("menuFichiers"));
   //m_menuFichiers->setTitle(QApplication::translate("C_ManagerClass", "Fichiers", 0, QApplication::UnicodeUTF8));
   m_menuFichiers->addAction(m_action_AccesWebMedTux);
   m_menuFichiers->addSeparator();
   m_menuFichiers->addAction(m_action_NouveauDossier);
   m_menuFichiers->addSeparator();
   m_menuFichiers->addAction(m_action_ModeNomade);
   m_menuFichiers->addAction(m_action_DebloquerBases);
   m_menuFichiers->addAction(m_action_UserParams);
   m_menuFichiers->addSeparator();
   m_menuFichiers->addAction(m_actionImprimer);
   m_menuFichiers->addSeparator();
   m_menuFichiers->addAction(m_actionQuitter);
   m_menuFichiers->addSeparator();
   m_menuBar->addAction(m_menuFichiers->menuAction());

   m_pGUI->webView_MedWebTux_h->hide();

   m_webView_MedWebTux = new C_QWebView(m_pGUI->tab_Web);
   m_webView_MedWebTux->setObjectName(QString::fromUtf8("webView_MedWebTux"));
   m_webView_MedWebTux->setUrl(QUrl("about:blank"));
   m_pGUI->gridLayout_2->addWidget(m_webView_MedWebTux, 0, 0, 1, 1);

   //.................. menu Affichage et fenetres ................................................
   m_menuFenetre = new QMenu(m_menuBar);
   m_menuFenetre->addAction(m_actionRecordWindowsPos);
   m_menuFenetre->addAction(m_actionSetGlobalFont);
   m_menuFenetre->addAction(m_actionHideShowLogo);
   m_action_dockMenu = m_menuFenetre->insertMenu ( m_actionRecordWindowsPos, createPopupMenu () );
   m_menuBar->addAction(m_menuFenetre->menuAction());

   //................... outils onglet web ..........................................
   m_action_WebPrint = new QAction(this);
   m_action_WebPrint->setObjectName(QString::fromUtf8("action_WebPrint"));
   m_action_WebPrint->setIconSet ( Theme::getIcon("22x22/fileprint.png") ) ;

   m_action_WebHelp = new QAction(this);
   m_action_WebHelp->setObjectName(QString::fromUtf8("action_WebHelp"));
   m_action_WebHelp->setIconSet ( Theme::getIcon("22x22/help.png") ) ;

   m_action_WebHome = new QAction(this);
   m_action_WebHome->setObjectName(QString::fromUtf8("action_WebHome"));
   m_action_WebHome->setIconSet ( Theme::getIcon("22x22/WebMedTux.png") ) ;

   m_action_WebFind = new QAction(this);
   m_action_WebFind->setObjectName(QString::fromUtf8("action_WebFind"));
   m_action_WebFind->setIconSet ( Theme::getIcon("22x22/edit-find.png") ) ;

   m_action_WebStop = new QAction(this);
   m_action_WebStop->setObjectName(QString::fromUtf8("action_WebStop"));
   m_action_WebStop->setIcon( m_webView_MedWebTux->pageAction(QWebPage::Stop)->icon() ) ;


   m_locationEdit = new QLineEdit(this);
   m_locationEdit->setSizePolicy(QSizePolicy::Expanding, m_locationEdit->sizePolicy().verticalPolicy());

   m_WebFindEdit = new QLineEdit(this);
   m_WebFindEdit->setSizePolicy(QSizePolicy::Expanding, m_locationEdit->sizePolicy().verticalPolicy());
   m_WebToolBar = addToolBar(tr("Navigation"));

   QWebSettings::globalSettings()->setAttribute(QWebSettings::JavascriptCanOpenWindows,TRUE);
   QWebSettings::globalSettings()->setAttribute(QWebSettings::JavascriptCanAccessClipboard,TRUE);
   //m_webView_Mono->page()->setLinkDelegationPolicy ( QWebPage::DelegateAllLinks );      //QWebPage::DelegateAllLinks
   QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);
   QWebSettings::globalSettings()->setAttribute(QWebSettings::AutoLoadImages, true);
   QWebSettings::globalSettings()->setAttribute(QWebSettings::OfflineStorageDatabaseEnabled, true);
   QWebSettings::globalSettings()->setAttribute(QWebSettings::OfflineWebApplicationCacheEnabled, true);
   QWebSettings::globalSettings()->setAttribute(QWebSettings::LocalStorageEnabled, true);

   // m_webView_MedWebTux->settings()->setAttribute(QWebSettings::JavascriptCanOpenWindows,TRUE);
   // m_webView_MedWebTux->settings()->setAttribute(QWebSettings::JavascriptCanAccessClipboard,TRUE);

   m_WebToolBar->addAction(m_webView_MedWebTux->pageAction(QWebPage::Back));
   m_WebToolBar->addAction(m_webView_MedWebTux->pageAction(QWebPage::Forward));
   m_WebToolBar->addAction(m_webView_MedWebTux->pageAction(QWebPage::Reload));
   //m_WebToolBar->addAction(m_webView_MedWebTux->pageAction(QWebPage::Stop));
   m_WebToolBar->addAction(m_action_WebStop);

   m_WebToolBar->addAction(m_action_WebPrint);
   m_WebToolBar->addAction(m_action_WebHome);
   m_WebToolBar->addAction(m_action_WebHelp);
   m_WebToolBar->addWidget(m_locationEdit);
   m_WebToolBar->addAction(m_action_WebFind);
   m_WebToolBar->addWidget(m_WebFindEdit);

   //...................... menu a propos ............................
   m_menuInfo        = new QMenu(m_menuBar);
   m_action_A_Propos = new QAction(this);
   m_action_A_Propos->setObjectName(QString::fromUtf8("actionApropos"));
   m_action_Aide     = new QAction(this);
   m_action_Aide->setObjectName(QString::fromUtf8("action_Aide"));
   m_menuInfo->addAction(m_action_A_Propos);
   m_menuInfo->addAction(m_action_Aide);
   m_menuBar->addAction(m_menuInfo->menuAction());

   setMenuBar(m_menuBar);

   //...........//////// DOCK de la liste des utilisateurs ////////.........................................
   m_pC_Frm_UserList = new C_Frm_UserList(m_pCMoteurBase, this);
   QLabel * wdg_labelDocWidget_Title_User = new QLabel(this);
   wdg_labelDocWidget_Title_User->setStyleSheet(styles);
   wdg_labelDocWidget_Title_User->setText(tr("Liste des utilisateurs"));
   wdg_labelDocWidget_Title_User->setAlignment ( Qt::AlignHCenter|Qt::AlignVCenter );
   m_pGUI->wdg_DockWidget_User->setTitleBarWidget ( wdg_labelDocWidget_Title_User );
   m_pGUI->wdg_DockWidget_User->setWidget(m_pC_Frm_UserList);

   //..........////////.DOCK de l'Agenda le logo de DMD ////////.........................................
   m_pGUI->textLabelPixMap->setPixmap ( Theme::getIcon("DMD-Logo-03.png") );

   //...........  Titre l'agenda ........................................................
   m_AgendaDockTitle = new QLabel(this);
   m_AgendaDockTitle->setStyleSheet(styles);
   m_AgendaDockTitle->setText(tr("Agenda"));
   m_AgendaDockTitle->setAlignment ( Qt::AlignHCenter|Qt::AlignVCenter );
   m_pGUI->wdg_DockWidget_Agenda->setTitleBarWidget ( m_AgendaDockTitle );
   //........... combobox ajouter un agenda utilisateur....................
   initComboBoxAgendaUser();
   //............ liste des jours ....................
   m_pAgendaQLayout = new QHBoxLayout ( m_pGUI->frame_MultiAgenda );
   m_pAgendaQLayout->setSpacing(3);
   m_pAgendaQLayout->setMargin(0);
   m_pAgendaQLayout->setObjectName(QString::fromUtf8("m_pAgendaQLayout"));
   m_pAgendaQLayout->setContentsMargins(0, 0, 0, 0);

   addUserAgenda(G_pCApp->m_SignUser, QDate::currentDate());
   setComboBoxOnValue(m_pGUI->comboBoxAgendaUser, G_pCApp->m_SignUser);
   //........................ customiser quelques widgets ..............................
   pQHeaderView = m_pGUI->listView_Doublons->header();                 // cacher les colonnes du Pk et GUID
   pQHeaderView->hideSection (2);
   pQHeaderView->hideSection (3);
   m_pGUI->listView_Doublons->setContextMenuPolicy ( Qt::CustomContextMenu );
   m_pGUI->listView_Doublons->hide();

   pQHeaderView = m_pGUI->listView_Vitale->header();                   // cacher les colonnes du Pk et GUID
   pQHeaderView->hideSection (2);
   pQHeaderView->hideSection (3);
   pQHeaderView->hideSection (4);
   pQHeaderView->hideSection (5);
   pQHeaderView->hideSection (6);
   pQHeaderView->hideSection (7);
   pQHeaderView->hideSection (8);

   m_pGUI->listView_Vitale->setContextMenuPolicy ( Qt::CustomContextMenu );
   m_pGUI->listView_Vitale->hide();

   pQHeaderView = m_pGUI->listView_Praticiens->header();               // cacher colonne ID
   pQHeaderView->hideSection (4);
   pQHeaderView->resizeSection ( 0,100 );
   m_pGUI->listView_Praticiens->setContextMenuPolicy ( Qt::CustomContextMenu );
   QList <int> list;                                                   // reduire le spliter des listes
   list.append(140);
   list.append(width()-140);
   m_pGUI->splitter_SepListIdent->setSizes(list);
   //................ bouton de creation de dossier ......................
   /*
   QString style =        "QPushButton {"
                          "border: 2px solid #8f8f91;"
                          "border-radius: 6px;"
                          "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #f6f7fa, stop: 1 #dadbde);"
                          "color: red;"
                          "font-weight: bold;"
                          "min-width: 80px;}"
                          "QPushButton:pressed {"
                          "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #f6f7fa);}";
   m_pGUI->pushButtonNew->setStyleSheet(style);
   m_pGUI->pushButtonCreate->setStyleSheet(style);
   m_pGUI->pushButtonCancelCreate->setStyleSheet(style);
   */
   m_pGUI->pushButtonMenuNew->setPixmap ( Theme::getIcon("BoutonNewWithout.png") );
   /*
   m_ButtonNew_PopMenu = new QMenu ( tr("Nouveau dossier"),  m_pGUI->pushButtonMenuNew );
   if (m_ButtonNew_PopMenu)
      {m_ButtonNew_PopMenu->addAction ( tr("Nouveau dossier en utilisant les donn\303\251es d\303\251j\303\240 pr\303\251sentes"), this, SLOT(Slot_NewDossWithoutErase()), QKeySequence (Qt::CTRL + Qt::Key_P) );
       m_pGUI->pushButtonMenuNew->setMenu ( m_ButtonNew_PopMenu );
      }
   */
   //.............................. verifier si PA sigems doit etre active ...........................................

   m_pGUI->pushButton_SigemsPA->setIcon ( QIcon (Theme::getIcon( "22x22/InterSigems.png"))) ;
   if (QDir().exists(G_pCApp->m_PathSigemsPA)) m_pGUI->pushButton_SigemsPA->show();
   else                                        m_pGUI->pushButton_SigemsPA->hide();

   //................. positionner les masques de saisie ..........................
   m_pGUI->lineEdit_DtNss->setInputMask ("99-99-9999");
   m_pGUI->lineEdit_DtNss_Assure->setInputMask ("99-99-9999");
   m_pGUI->lineEdit_Tel1->setInputMask ("99 99 99 99 99 99 99");
   m_pGUI->lineEdit_Tel2->setInputMask ("99 99 99 99 99 99 99");
   m_pGUI->lineEdit_Tel3->setInputMask ("99 99 99 99 99 99 99");
   m_pGUI->lineEdit_NumSecu->setInputMask ("9 99 99 99 999 999");    //2  30  19  62  965  231
   m_pGUI->lineEdit_CdPostal->setInputMask ("99 999");
   m_pGUI->lineEdit_RangGeme->setInputMask ("99");
   //........................ images de la carte vitale ...............................
   QPixmap px = Theme::getIcon("UserList/Carte_CPS_Butt.png");
   m_pGUI->pushButtonVitale->setIcon        (px );
   m_pGUI->pushButtonVitale->setIconSize(QSize(px.width(),px.height()));
   m_pGUI->pushButtonVitale->setIcon ( QIcon (Theme::getIcon( "VitaleButt.png"))) ;
   //QRect rect = m_pGUI->pushButtonNew->geometry();
   //m_pGUI->pushButtonNew->setMaximumHeight(m_pGUI->pushButtonVitale->height());
   //m_pGUI->pushButtonNew->setAttribute(Qt::WA_MacBrushedMetal);
   //.................... initialiser la liste patients ...............................
   m_pGUI->pushButton_ReinitListe->setIcon ( Theme::getIcon("listview_renouv.png") );
   m_pGUI->pushButtonDetruire->setIcon ( Theme::getIcon("EffaceDossier.png") );
   m_pGUI->pushButtonInfo->setIcon ( Theme::getIcon("help.png") );

if (CGestIni::Param_ReadUniqueParam(G_pCApp->m_LocalParam, "Sesam-Vitale", "ModuleName")!= "PYXVITAL")
   {m_pGUI->pushButtonVitaleMenu->hide();
   }
 else
  {
   px = Theme::getIcon("VitaleButtMenu.png");
   m_pGUI->pushButtonVitaleMenu->setIcon        (px );
   m_pGUI->pushButtonVitaleMenu->setIconSize(QSize(px.width(),px.height()));
   m_pGUI->pushButtonVitaleMenu->setIcon ( QIcon (px)) ;
  }

 //.................. remplir la liste des patients......................
   initListePatient("","");
   //.................. masquer le bouton Solde Patient si on a pas la compta......................         CZ_Cpta
   if (CGestIni::Param_ReadUniqueParam(G_pCApp->m_LocalParam, "Comptabilite", "Controle solde") != "oui")
       m_pGUI->pushButton_solde->hide();

   //.................. recuperer la qualite des ayants droits......................
   QString param;
   CGestIni::Param_UpdateFromDisk(G_pCApp->m_PathAppli + "Ressources/QualiteBeneficiaire.tbl" , param);
   param = param.trimmed();
   param = param.remove('\r');
   param = param.replace(',',' ');
   m_pGUI->comboBoxQualiteAyantDroit->clear();
   QStringList lst = param.split('\n', QString::SkipEmptyParts);
   if (lst.count())
      { lst.removeFirst ();  // virer les lignes de commentaires
        lst.removeFirst ();
      }
   else
      {qDebug(tr("Ressources/QualiteBeneficiaire.tbl not found"));
      }
   m_pGUI->comboBoxQualiteAyantDroit->insertItems(0, lst);    //Qt::CaseSensitivity
   //........................ connecter les slot de verification ...........................................................................................
   connect( m_pGUI->lineEdit_DtNss,    SIGNAL( Sign_focusOutEvent(QFocusEvent*, int &)),         this,     SLOT(   Slot_OutFocuslineEdit_DtNss(QFocusEvent*, int &)));
   connect( m_pGUI->lineEditVille,     SIGNAL( Sign_focusOutEvent(QFocusEvent*, int &)),         this,     SLOT(   Slot_OutFocusVille(QFocusEvent*, int &))  );
   connect( m_pGUI->lineEdit_CdPostal, SIGNAL( Sign_focusOutEvent(QFocusEvent*, int &)),         this,     SLOT(   Slot_OutFocusCodePostal(QFocusEvent*, int &))  );
   connect( m_pGUI->lineEdit_CdPostal, SIGNAL( Sign_keyPressEvent(QKeyEvent *, int &)),          this,     SLOT(   Slot_CharEventCodePostal(QKeyEvent *, int &)) );

   connect( m_pGUI->lineEdit_NumSecu, SIGNAL( Sign_keyPressEvent(QKeyEvent *, int &)),           this,     SLOT(   Slot_CharEventNumSecu(QKeyEvent *, int &)) );
   connect( m_pGUI->lineEdit_NumSecu, SIGNAL( Sign_focusInEvent(QFocusEvent*, int &)),           this,     SLOT(   Slot_InFocusNumSecu(QFocusEvent*, int &))  );
   connect( m_pGUI->lineEdit_NumSecu, SIGNAL( Sign_focusOutEvent(QFocusEvent*, int &)),          this,     SLOT(   Slot_OutFocusNumSecu(QFocusEvent*, int &))  );
   //........................ connecter les slot de changement ............................................................................................
   connect( m_pGUI->lineEdit_NomDossier,         SIGNAL( textChanged ( const QString & ) ),        this, SLOT(   Slot_TextChanged_lineEdit_NomDossier(const QString & )    ));
   connect( m_pGUI->lineEdit_PrenomDossier,      SIGNAL( textChanged ( const QString & ) ),        this, SLOT(   Slot_TextChanged_lineEdit_PrenomDossier(const QString & ) ));
   connect( m_pGUI->lineEdit_NomDeNss,           SIGNAL( textChanged ( const QString & ) ),        this, SLOT(   Slot_TextChanged_lineEdit_NomDeNss(const QString & )      ));
   connect( m_pGUI->lineEdit_DtNss,              SIGNAL( textChanged ( const QString & ) ),        this, SLOT(   Slot_TextChanged_lineEdit_DtNss(const QString & )         ));
   connect( m_pGUI->lineEdit_DtNss_Assure,       SIGNAL( textChanged ( const QString & ) ),        this, SLOT(   Slot_TextChanged_lineEdit_DtNss_Assure(const QString &)   ));
   connect( m_pGUI->lineEdit_Titre,              SIGNAL( textChanged ( const QString & ) ),        this, SLOT(   Slot_TextChanged_lineEdit_Titre(const QString & )         ));
   connect( m_pGUI->lineEdit_Profession,         SIGNAL( textChanged ( const QString & ) ),        this, SLOT(   Slot_TextChanged_lineEdit_Profession(const QString &)     ));
   connect( m_pGUI->textEdit_Adresse,            SIGNAL( textChanged ( ) ),                        this, SLOT(   Slot_TextChanged_textEdit_Adresse( ))  );
   connect( m_pGUI->lineEdit_Tel1,               SIGNAL( textChanged ( const QString & ) ),        this, SLOT(   Slot_TextChanged_lineEdit_Tel1(const QString & ))  );
   connect( m_pGUI->lineEdit_Tel2,               SIGNAL( textChanged ( const QString & ) ),        this, SLOT(   Slot_TextChanged_lineEdit_Tel2(const QString & ))  );
   connect( m_pGUI->lineEdit_Tel3,               SIGNAL( textChanged ( const QString & ) ),        this, SLOT(   Slot_TextChanged_lineEdit_Tel3(const QString & ))  );
   connect( m_pGUI->lineEdit_CdPostal,           SIGNAL( textChanged ( const QString & ) ),        this, SLOT(   Slot_TextChanged_lineEdit_CdPostal(const QString & ))  );
   connect( m_pGUI->lineEditVille,               SIGNAL( textChanged ( const QString & ) ),        this, SLOT(   Slot_TextChanged_lineEditVille(const QString & )) );
   connect( m_pGUI->lineEdit_Email,              SIGNAL( textChanged ( const QString & ) ),        this, SLOT(   Slot_TextChanged_lineEdit_Email(const QString & )) );
   connect( m_pGUI->lineEdit_NumSecu,            SIGNAL( textChanged ( const QString & ) ),        this, SLOT(   Slot_TextChanged_lineEdit_NumSecu(const QString & )) );
   connect( m_pGUI->lineEdit_NomAssure,          SIGNAL( textChanged ( const QString & ) ),        this, SLOT(   Slot_TextChanged_lineEdit_NomAssure(const QString & ))  );
   connect( m_pGUI->lineEdit_PrenomAssure,       SIGNAL( textChanged ( const QString & ) ),        this, SLOT(   Slot_TextChanged_lineEdit_PrenomAssure(const QString & ))  );
   connect( m_pGUI->textEdit_Note,               SIGNAL( textChanged ( ) ),                        this, SLOT(   Slot_TextChanged_textEdit_Note( )) );
   connect( m_pGUI->lineEdit_RangGeme,           SIGNAL( textChanged (const QString & ) ),         this, SLOT(   Slot_TextChanged_lineEdit_RangGeme(const QString &)) );
   connect( m_pGUI->comboBoxSexe,                SIGNAL( currentIndexChanged (const QString & ) ), this, SLOT(   Slot_TextChanged_comboBoxSexe( const QString &))  );
   connect( m_pGUI->comboBoxQualiteAyantDroit,   SIGNAL( currentIndexChanged (const QString & ) ), this, SLOT(   Slot_TextChanged_comboBoxQualiteAyantDroit( const QString &))  );
   connect( m_pGUI->comboBoxAgendaUser,          SIGNAL( activated( const QString & )),            this, SLOT(   Slot_comboBoxAgendaUser_activated( const QString& )) );
   //................... connexions ....................................................
   connect( m_pC_Frm_UserList,                SIGNAL(Sign_UserSelected( QTreeWidgetItem * , QTreeWidgetItem * )),       this, SLOT(Slot_UserSelected_InListUser( QTreeWidgetItem * , QTreeWidgetItem *)) );
   connect( m_pC_Frm_UserList,                SIGNAL(Sign_UserMustBeEdited( const QString&, const QString& )),          this, SLOT(Slot_EditUser( const QString&, const QString&)) );
   connect( m_action_UserParams,              SIGNAL(triggered()),                                                      this, SLOT(Slot_pushButton_action_UserParams()) );

   connect( m_pC_Frm_UserList,                SIGNAL(Sign_UserMustBeUnloged(int& )),                                    this, SLOT(Slot_UserMustBeUnloged(int&)) );
   connect( m_pGUI->listView_Praticiens,      SIGNAL(itemDoubleClicked ( QTreeWidgetItem * , int  )),                   this, SLOT(Slot_listView_Praticiens_DoubleClicked( QTreeWidgetItem * , int)) );
   connect( m_pGUI->listView_Praticiens ,     SIGNAL(customContextMenuRequested( const QPoint &)),                      this, SLOT(Slot_listView_Praticiens_contextMenuRequested (const QPoint &)) );
   connect( m_pGUI->pushButtonAcceder,        SIGNAL(clicked()),                                                        this, SLOT(Slot_pushButtonAcceder_Clicked()) );
   connect( m_pGUI->pushButton_AddMedTTT,     SIGNAL(clicked()),                                                        this, SLOT(Slot_pushButton_AddMedTTT_clicked()) );
   connect( m_pGUI->pushButton_AddMedTTT_Fast,SIGNAL(clicked ()),                                                       this, SLOT(Slot_pushButton_AddMedTTT_Fast_clicked ()) );
   connect( m_pGUI->pushButton_DelMedTTT,     SIGNAL(clicked()),                                                        this, SLOT(Slot_pushButton_DelMedTTT_clicked()) );
   connect( m_pGUI->pushButtonCreate,         SIGNAL(clicked()),                                                        this, SLOT(Slot_pushButtonCreate()) );
   connect( m_pGUI->pushButtonSavModif,       SIGNAL(clicked()),                                                        this, SLOT(Slot_pushButtonSavModifWithoutConfirmation()) );
   connect( m_pGUI->pushButton_MultiCritere,  SIGNAL(clicked()),                                                        this, SLOT(Slot_pushButton_MultiCritere()) );
   connect( m_pGUI->pushBut_MultiCritFind,    SIGNAL(clicked()),                                                        this, SLOT(Slot_pushBut_MultiCritFind()) );
   connect( m_pGUI->pushButton_Effacer,       SIGNAL(clicked()),                                                        this, SLOT(Slot_pushButton_Effacer_clicked()) );
   connect( m_pGUI->pushBut_ExitMultiCritere, SIGNAL(clicked()),                                                        this, SLOT(Slot_pushBut_ExitMultiCritere()) );
   connect( m_pGUI->pushButtonInfo,           SIGNAL(clicked()),                                                        this, SLOT(Slot_pushButtonInfoClicked( )) );
   connect( m_pGUI->pushButtonDetruire,       SIGNAL(clicked()),                                                        this, SLOT(Slot_pushButtonDetruire_clicked( )) );
   connect( m_pGUI->pushButtonNew,            SIGNAL(clicked()),                                                        this, SLOT(Slot_pushButtonNew_clicked( )) );
   connect( m_pGUI->pushButtonMenuNew,        SIGNAL(clicked()),                                                        this, SLOT(Slot_pushButtonMenuNew_clicked( )) );
   connect( m_pGUI->pushButtonCancelCreate,   SIGNAL(clicked()),                                                        this, SLOT(Slot_pushButtonCancelCreate_clicked( )) );
   connect( m_pGUI->lineEditAutoLocator,      SIGNAL(textChanged(const QString &)),                                     this, SLOT(Slot_lineEditAutoLocator_textChanged(const QString &)) );
   connect( m_pGUI->lineEditAutoLocator,      SIGNAL(Sign_keyPressEvent(QKeyEvent *, int &)),                           this, SLOT(Slot_lineEditAutoLocator_keyPressEvent(QKeyEvent *, int &)) );

   connect( m_pGUI->pushButtonVitale,         SIGNAL(clicked()),                                                        this, SLOT(Slot_pushButtonVitale_clicked()) );

   connect( m_pGUI->pushButton_ReinitListe,   SIGNAL(clicked()),                                                        this, SLOT(Slot_pushButton_ReinitListe_clicked()) );
   connect( m_pGUI->listView_Patient,         SIGNAL(itemClicked ( QTreeWidgetItem * , int  )),                         this, SLOT(Slot_listView_Patient_Clicked( QTreeWidgetItem * , int)) );
   connect( m_pGUI->listView_Patient,         SIGNAL(itemDoubleClicked ( QTreeWidgetItem * , int  )),                   this, SLOT(Slot_listView_Patient_DoubleClicked( QTreeWidgetItem * , int)) );
   connect( m_pGUI->listView_Patient ,        SIGNAL(itemSelectionChanged ()),                                          this, SLOT(Slot_ListView_itemSelectionChanged ()) );
   connect( m_pGUI->listView_Patient ,        SIGNAL(customContextMenuRequested( const QPoint &)),                      this, SLOT(Slot_ListView_ContextMenuRequested (const QPoint &)) );
   connect( m_pGUI->listView_Patient,         SIGNAL( Sign_giveMeDatas(QString &, QTreeWidgetItem* )),                  this, SLOT(Slot_giveDraglistView_PatientItemData(QString &, QTreeWidgetItem*)));

   connect( m_pGUI->listView_Doublons ,       SIGNAL(itemSelectionChanged ()),                                          this, SLOT(Slot_listView_DoublonsSelectionChanged ()) );
   connect( m_pGUI->listView_Doublons ,       SIGNAL(customContextMenuRequested( const QPoint &)),                      this, SLOT(Slot_listView_Doublons_contextMenuRequested (const QPoint &)) );
   connect( m_pGUI->listView_Vitale,          SIGNAL(itemClicked ( QTreeWidgetItem * , int  )),                         this, SLOT(Slot_listView_Vitale_Clicked( QTreeWidgetItem * , int)) );
   connect( m_pGUI->listView_Vitale,          SIGNAL(itemDoubleClicked ( QTreeWidgetItem * , int  )),                   this, SLOT(Slot_listView_Vitale_DoubleClicked( QTreeWidgetItem * , int)) );
   connect( m_pGUI->listView_Vitale ,         SIGNAL(itemSelectionChanged ()),                                          this, SLOT(Slot_listView_VitaleSelectionChanged ()) );
   connect( m_pGUI->listView_Vitale ,         SIGNAL(customContextMenuRequested( const QPoint &)),                      this, SLOT(Slot_listView_Vitale_ContextMenuRequested (const QPoint &)) );

   connect( m_actionRecordWindowsPos,         SIGNAL(triggered ( bool )),                                            this, SLOT(Slot_actionRecordWindowsPos_triggered (bool)) );
   connect( m_actionSetGlobalFont,            SIGNAL(triggered ( bool )),                                            this, SLOT(Slot_actionSetGlobalFont_triggered (bool)) );
   connect( m_actionHideShowLogo,             SIGNAL(triggered ( bool )),                                            this, SLOT(Slot_actionHideShowLogo_triggered (bool)) );
   connect( m_action_DebloquerBases,          SIGNAL(triggered ( bool )),                                            this, SLOT(Slot_action_DebloquerBases (bool)) );
   connect( m_actionImprimer,                 SIGNAL(triggered ( bool )),                                            this, SLOT(Slot_action_Imprimer (bool)) );

   connect( m_actionQuitter,                  SIGNAL(triggered ()),                                                  G_pCApp, SLOT(quit()) );   // revient faire le menage par le signal  Sign_QuitterRequired
   connect(G_pCApp,                           SIGNAL(Sign_QuitterRequired()),                                        this, SLOT(Slot_SauverLesMeubles()));
   connect( m_action_A_Propos,                SIGNAL(triggered ( bool )),                                            this, SLOT(Slot_actionApropos (bool)) );
   connect( m_action_Aide,                    SIGNAL(triggered ( bool )),                                            this, SLOT(Slot_action_Aide (bool)) );

   connect( m_pGUI->pushButton_FSE,           SIGNAL(clicked()),                                                     this, SLOT(Slot_pushButton_FSE()) );                                      //Cz_Pyxvital
   connect( m_pGUI->pushButtonVitale,         SIGNAL(customContextMenuRequested( const QPoint &)),                   this, SLOT(Slot_Button_Vitale_ContextMenuRequested (const QPoint &)) );   //Cz_Pyxvital
   connect( m_pGUI->pushButtonVitaleMenu,     SIGNAL(clicked()),                                                     this, SLOT(Slot_Button_Vitale_MenuRequested ()) );

   connect( m_pGUI->tabWidget_Central,        SIGNAL(currentChanged ( int  )),                                       this, SLOT(Slot_tabWidget_Central_currentChanged (int)) );
   connect( m_locationEdit,                   SIGNAL(returnPressed()),                                               this, SLOT(Slot_LocationEdit_returnPressed()));
   connect( m_webView_MedWebTux,              SIGNAL(loadStarted (  )),                                              this, SLOT(Slot_On_webView_MedWebTux_loadStarted ()) );
   connect( m_webView_MedWebTux,              SIGNAL(loadProgress (int)),                                            this, SLOT(Slot_On_webView_MedWebTux_loadProgress (int)) );
   connect( m_webView_MedWebTux,              SIGNAL(loadFinished (bool  )),                                         this, SLOT(Slot_On_webView_MedWebTux_loadFinished (bool)) );
   connect( m_WebFindEdit,                    SIGNAL(returnPressed()),                                               this, SLOT(Slot_WebFindEdit_returnPressed()));
   connect( m_WebFindEdit,                    SIGNAL(textChanged ( const QString &  ) ),                             this, SLOT(Slot_WebFindEdit_textChanged (const QString & )) );
   connect( m_webView_MedWebTux,              SIGNAL(urlChanged ( const QUrl &  )),                                  this, SLOT(Slot_webView_MedWebTux_urlChanged ( const QUrl &  )));
   connect( m_action_WebPrint,                SIGNAL(triggered ( bool )),                                            this, SLOT(Slot_actionWebPrint (bool)) );
   connect( m_action_WebHome,                 SIGNAL(triggered ( bool )),                                            this, SLOT(Slot_actionWebHome (bool)) );
   connect( m_action_WebHelp,                 SIGNAL(triggered ( bool )),                                            this, SLOT(Slot_actionWebHelp (bool)) );
   connect( m_action_WebFind,                 SIGNAL(triggered ( bool )),                                            this, SLOT(Slot_actionWebFind (bool)) );
   connect( m_action_WebStop,                 SIGNAL(triggered ( bool )),                                            this, SLOT(Slot_actionWebStop (bool)) );
   connect( m_action_AccesWebMedTux,          SIGNAL(triggered ( bool )),                                            this, SLOT(Slot_action_AccesWebMedTux (bool)) );
   connect( m_action_NouveauDossier,          SIGNAL(triggered ( bool )),                                            this, SLOT(Slot_actionMenuNew_clicked( bool)) );
   // test saisie reglt direct CZ_Cpta.
   connect( m_pGUI->pushButton_solde,         SIGNAL(clicked()),                                                     this, SLOT(Slot_Saisie_Reglement ()) );
   connect( m_pGUI->pushButton_SigemsPA,      SIGNAL(clicked()),                                                     this, SLOT(Slot_pushButton_SigemsPA_Clicked()) );

   //....................... nomadisme ....................................................
   if (G_pCApp->m_IsGestionNomadisme)
      {m_NomadismeToolBar = addToolBar(tr("NomadisemetoolBar")); //new QToolBar(this);
       m_NomadismeToolBar->setObjectName(QString::fromUtf8("m_NomadismeToolBar"));
       m_NomadismeToolBar->addAction(m_action_ModeNomade);         // ajouter l'option a la barre d'outils
       //addToolBar(Qt::TopToolBarArea, m_NomadismeToolBar);         // ajouter la barre d'outils a la fenetre principale
       if (G_pCApp->m_IsNomadeActif)
          {m_action_ModeNomade->setText(tr("Quitter le mode Nomade et se reconnecter au serveur central"));
           m_action_ModeNomade->setIconSet ( Theme::getIcon("32x32/unconnected.png") ) ;
           G_pCApp->CouCou(tr("Mode Nomade activ\303\251 "));
          }
       else
          {m_action_ModeNomade->setText(tr("Se d\303\251connecter du serveur central et passer en mode Nomade"));
           m_action_ModeNomade->setIconSet ( Theme::getIcon("32x32/connected.png") ) ;
           G_pCApp->CouCou(tr("Mode Master activ\303\251 "));
          }
       m_NomadismeToolBar->addAction(m_action_ModeNomade);
       connect( m_action_ModeNomade,        SIGNAL(triggered ( bool )),                                               this, SLOT(Slot_action_ModeConnect_triggered (bool)) );
      // connect( m_pGUI->action_ToModeConnect,     SIGNAL(triggered ( bool )),                                               this, SLOT(Slot_action_ToModeConnect_triggered (bool)) );
     }
  else
     {m_action_ModeNomade->setText(tr("Gestion du nomadisme non activ\303\251e"));
      m_action_ModeNomade->setVisible ( FALSE );
     }
   //.......................... tenir compte de la version .............................
#ifdef SESAM_VERSION
   connect( m_pC_Frm_UserList,    SIGNAL(Sign_CPS_IsClicked()), this, SLOT(Slot_CPS_IsClicked()) );
#endif
   //................... position sur l'ecran ....................................................

   QString val1, val2, val3, val4;
   if (CGestIni::Param_ReadParam(G_pCApp->m_LocalParam,"ManagerPos", "Positions", &val1, &val2, &val3, &val4)==QString::null)  // zero = pas d'erreur
      {move(val1.toInt(),   val2.toInt());
       resize(val3.toInt(), val4.toInt());
      }
   else
      {QRect rect =  QApplication::desktop()->availableGeometry();   // juste pour faire bouger les choses ajustement du bas)
       setGeometry ( rect );
      }

   setInterfaceOnProfil(MODE_SELECTION_PATIENT);
   get_RecordDispos();
   if (m_pGUI->wdg_DockWidget_Agenda->isHidden()) m_AgendaInitialVisbility   = 0;
   else                                           m_AgendaInitialVisbility   = 1;
   if (m_pGUI->wdg_DockWidget_User->isHidden())   m_UserListInitialVisbility = 0;
   else                                           m_UserListInitialVisbility = 1;
   //.............. positionner le premier focus ...................................................
   setIdentModifiedState(FALSE); // car pas d'identite selectionne
   setIdentiteDisabled();        // car pas d'identite selectionne
   setVerrou(FALSE);             // car pas d'identite ni lancee
   if (!G_pCApp->m_IsAppStartWithUser)
      {m_pGUI->tabWidget_Central->setEnabled(FALSE);
       m_pGUI->wdg_DockWidget_Agenda->setEnabled(FALSE);
       m_pGUI->wdg_DockWidget_Agenda->hide();
       m_pGUI->wdg_DockWidget_User->show();
      }
   else         setMedWebTuxOnUser();
   m_pGUI->lineEditAutoLocator->setFocus();
   //G_pCApp->CouCou("Coucou", Theme::getPath(Theme::WithSeparator)+"MessagePopVigie.png");
   //CGestIni::Param_UpdateToDisk("/home/ro/Tabstyle.txt", G_pCApp->styleSheet ());
   m_pGUI->pushButton_AddMedTTT_Fast->setIcon ( QIcon (Theme::getIcon( "16x16/Left.png" ))) ;;
   m_pMasterSocket = 0;
   m_pSlaveSocket  = 0;
   statusBar()->hide();
   setTitle();
   G_pCApp->setWindowIcon (Theme::getIcon("32x32/Manager.png") );
   //...................... timer de verification p\303\251riodique ...............................
   m_pReconnectTimer       = new QTimer(this);
   if (m_pReconnectTimer)
      {m_pReconnectTimer->start (3000);
       connect( m_pReconnectTimer, SIGNAL(timeout()), this, SLOT(Slot_OnTimer()) );
      }
   demarrerAccessoires();
   Slot_retranslateUi();
   m_pGUI->tabWidget_Central->setCurrentIndex (0);
   Slot_tabWidget_Central_currentChanged (0);
   //setUnifiedTitleAndToolBarOnMac(true);  // pas bon car les toolbars ne sont pas deplacables
   //............. placer les fontes de caractere sur les widgets .........
   initWidgetsList();
   setAllWidgetsOnFont(G_pCApp->m_GuiFont);
}

//------------------------ ~C_Manager ---------------------------------------
C_Manager::~C_Manager()
{   if (m_pReconnectTimer)
      {m_pReconnectTimer->stop();
       disconnect( m_pReconnectTimer, SIGNAL(timeout()), this, SLOT(Slot_OnTimer()) );
      }
   if (m_pMasterSocket) delete m_pMasterSocket;
   if (m_pSlaveSocket)  delete m_pSlaveSocket;
   delete m_pGUI;
}

//------------------------ setAllWidgetsOnFont ---------------------------------------
void C_Manager::setAllWidgetsOnFont(const QFont &font)
{for (int i = 0; i < G_pCApp->m_widgetList.size(); ++i)
    { G_pCApp->m_widgetList.at(i)->setFont(font);
      //qDebug() << G_pCApp->m_widgetList.at(i)->name();
    }
}
//------------------------ initWidgetsList ---------------------------------------
void C_Manager::initWidgetsList()
{
 G_pCApp->m_widgetList.append(m_pGUI->wdg_DockWidget_Agenda);
 G_pCApp->m_widgetList.append(m_pGUI->wdg_DockWidget_User);
 G_pCApp->m_widgetList.append(m_pGUI->comboBoxAgendaUser);
 G_pCApp->m_widgetList.append(m_pGUI->labelAgendaSelect);
 G_pCApp->m_widgetList.append(m_pGUI->textLabelPixMap);
 G_pCApp->m_widgetList.append(m_pGUI->frame_MultiAgenda);
 G_pCApp->m_widgetList.append(m_pGUI->tabWidget_Central);
 G_pCApp->m_widgetList.append(m_pGUI->groupBoxPatient);
 G_pCApp->m_widgetList.append(m_pGUI->label_nom);
 G_pCApp->m_widgetList.append(m_pGUI->lineEdit_NomDossier);
 G_pCApp->m_widgetList.append(m_pGUI->label_prenom);
 G_pCApp->m_widgetList.append(m_pGUI->lineEdit_PrenomDossier);
 G_pCApp->m_widgetList.append(m_pGUI->label_nomnss);
 G_pCApp->m_widgetList.append(m_pGUI->lineEdit_NomDeNss);
 G_pCApp->m_widgetList.append(m_pGUI->label_sexe);
 G_pCApp->m_widgetList.append(m_pGUI->comboBoxSexe);
 G_pCApp->m_widgetList.append(m_pGUI->label_titre);
 G_pCApp->m_widgetList.append(m_pGUI->lineEdit_Titre);
 G_pCApp->m_widgetList.append(m_pGUI->label_dtnss);
 G_pCApp->m_widgetList.append(m_pGUI->lineEdit_DtNss);
 G_pCApp->m_widgetList.append(m_pGUI->label_rangem);
 G_pCApp->m_widgetList.append(m_pGUI->lineEdit_RangGeme);
 G_pCApp->m_widgetList.append(m_pGUI->label_profession);
 G_pCApp->m_widgetList.append(m_pGUI->lineEdit_Profession);
 G_pCApp->m_widgetList.append(m_pGUI->label_adresse);
 G_pCApp->m_widgetList.append(m_pGUI->textEdit_Adresse);
 G_pCApp->m_widgetList.append(m_pGUI->label_tel1);
 G_pCApp->m_widgetList.append(m_pGUI->lineEdit_Tel1);
 G_pCApp->m_widgetList.append(m_pGUI->label_tel2);
 G_pCApp->m_widgetList.append(m_pGUI->lineEdit_Tel2);
 G_pCApp->m_widgetList.append(m_pGUI->label_tel3);
 G_pCApp->m_widgetList.append(m_pGUI->lineEdit_Tel3);
 G_pCApp->m_widgetList.append(m_pGUI->label_codepostal);
 G_pCApp->m_widgetList.append(m_pGUI->lineEdit_CdPostal);
 G_pCApp->m_widgetList.append(m_pGUI->pushButton_SigemsPA);
 G_pCApp->m_widgetList.append(m_pGUI->label_email);
 G_pCApp->m_widgetList.append(m_pGUI->lineEdit_Email);
 G_pCApp->m_widgetList.append(m_pGUI->groupBoxAssure);
 G_pCApp->m_widgetList.append(m_pGUI->label_nss);
 G_pCApp->m_widgetList.append(m_pGUI->lineEdit_NumSecu);
 G_pCApp->m_widgetList.append(m_pGUI->lineEdit_NssClef);
 G_pCApp->m_widgetList.append(m_pGUI->label_beneficiaire);
 G_pCApp->m_widgetList.append(m_pGUI->comboBoxQualiteAyantDroit);
 G_pCApp->m_widgetList.append(m_pGUI->label_nomassure);
 G_pCApp->m_widgetList.append(m_pGUI->lineEdit_NomAssure);
 G_pCApp->m_widgetList.append(m_pGUI->label_prenomassure);
 G_pCApp->m_widgetList.append(m_pGUI->lineEdit_PrenomAssure);
 G_pCApp->m_widgetList.append(m_pGUI->label_dnssassure);
 G_pCApp->m_widgetList.append(m_pGUI->lineEdit_DtNss_Assure);
 G_pCApp->m_widgetList.append(m_pGUI->tabWidgetNotes);
 G_pCApp->m_widgetList.append(m_pGUI->pushButton_AddMedTTT);
 G_pCApp->m_widgetList.append(m_pGUI->pushButton_AddMedTTT_Fast);
 G_pCApp->m_widgetList.append(m_pGUI->listView_Praticiens);
 G_pCApp->m_widgetList.append(m_pGUI->pushButton_DelMedTTT);
 G_pCApp->m_widgetList.append(m_pGUI->pushBut_ExitMultiCritere);
 G_pCApp->m_widgetList.append(m_pGUI->pushBut_MultiCritFind);
 G_pCApp->m_widgetList.append(m_pGUI->pushButton_Effacer);
 G_pCApp->m_widgetList.append(m_pGUI->pushButton_MultiCritere);
 G_pCApp->m_widgetList.append(m_pGUI->pushButtonAcceder);
 G_pCApp->m_widgetList.append(m_pGUI->pushButton_FSE);
 G_pCApp->m_widgetList.append(m_pGUI->pushButtonCreate);
 G_pCApp->m_widgetList.append(m_pGUI->pushButtonSavModif);
 G_pCApp->m_widgetList.append(m_pGUI->pushButtonCancelCreate);
 G_pCApp->m_widgetList.append(m_pGUI->textEdit_Note);
 G_pCApp->m_widgetList.append(m_pGUI->pushButtonNew);
 G_pCApp->m_widgetList.append(m_pGUI->pushButtonMenuNew);
 G_pCApp->m_widgetList.append(m_pGUI->pushButtonVitale);
 G_pCApp->m_widgetList.append(m_pGUI->pushButtonVitaleMenu);
 G_pCApp->m_widgetList.append(m_pGUI->pushButtonDetruire);
 G_pCApp->m_widgetList.append(m_pGUI->pushButtonInfo);
 G_pCApp->m_widgetList.append(m_pGUI->listView_Vitale);
 G_pCApp->m_widgetList.append(m_pGUI->listView_Doublons);
 G_pCApp->m_widgetList.append(m_pGUI->label_rechercherliste);
 G_pCApp->m_widgetList.append(m_pGUI->pushButton_ReinitListe);
 G_pCApp->m_widgetList.append(m_pGUI->lineEditAutoLocator);
 G_pCApp->m_widgetList.append(m_pGUI->listView_Patient);
 G_pCApp->m_widgetList.append(m_pGUI->textLabel_NumGuid);
 G_pCApp->m_widgetList.append(m_pGUI->textLabel_NumDoss);
}
//------------------------ Slot_retranslateUi ---------------------------------------
void C_Manager::Slot_retranslateUi()
{m_actionRecordWindowsPos->setText(QApplication::translate("C_ManagerClass", "Enregistrer la position des fen\303\252tres", 0, QApplication::UnicodeUTF8));
m_actionSetGlobalFont->setText(QApplication::translate("C_ManagerClass", "Choisir une police de caract\303\250res pour Manager...", 0, QApplication::UnicodeUTF8));
m_actionHideShowLogo->setText(QApplication::translate("C_ManagerClass", "Cacher montrer le logo Data M\303\251dical Design", 0, QApplication::UnicodeUTF8));
m_action_ModeNomade->setText(QApplication::translate("C_ManagerClass", "Nomadisme", 0, QApplication::UnicodeUTF8));
m_action_ToModeConnect->setText(QApplication::translate("C_ManagerClass", "J'arrive et me reconnecte au serveur", 0, QApplication::UnicodeUTF8));
m_action_WebPrint->setText(QApplication::translate("C_ManagerClass", "Imprimer le contenu de cette page", 0, QApplication::UnicodeUTF8));
m_action_WebHome->setText(QApplication::translate("C_ManagerClass", "Acc\303\250s au dossier m\303\251dical en mode web par MedWebTux", 0, QApplication::UnicodeUTF8));
m_action_WebHelp->setText(QApplication::translate("C_ManagerClass", "Acc\303\250s  aux pages d'aide et documentation de MedinTux", 0, QApplication::UnicodeUTF8));
m_action_WebFind->setText(QApplication::translate("C_ManagerClass", "Rechercher le texte saisi ci-contre \303\240 droite", 0, QApplication::UnicodeUTF8));
m_action_DebloquerBases->setText(QApplication::translate("C_ManagerClass", "D\303\251verrouiller tous les dossiers et verrous", 0, QApplication::UnicodeUTF8));
m_action_dockMenu->setText(QApplication::translate("C_ManagerClass", "Afficher cacher les fen\303\252tres des utilisateurs et de l'agenda", 0, QApplication::UnicodeUTF8));
m_action_NouveauDossier->setText(QApplication::translate("C_ManagerClass", "Nouveau dossier", 0, QApplication::UnicodeUTF8));
m_action_NouveauDossier->setShortcut(QApplication::translate("C_ManagerClass", "Ctrl+N", 0, QApplication::UnicodeUTF8));
m_actionQuitter->setText(QApplication::translate("C_ManagerClass", "Quitter", 0, QApplication::UnicodeUTF8));
m_actionQuitter->setShortcut(QApplication::translate("C_ManagerClass", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
m_menuFichiers->setTitle(QApplication::translate("C_ManagerClass", "Fichiers", 0, QApplication::UnicodeUTF8));
m_menuFenetre->setTitle(QApplication::translate("C_ManagerClass", "Affichage et fen\303\252tres", 0, QApplication::UnicodeUTF8));
m_action_A_Propos->setText(QApplication::translate("C_ManagerClass", "A propos de Manager", 0, QApplication::UnicodeUTF8));
m_menuInfo->setTitle(QApplication::translate("C_ManagerClass", "Aide", 0, QApplication::UnicodeUTF8));
m_action_AccesWebMedTux->setText(QApplication::translate("C_ManagerClass", "Acc\303\250s au dossier m\303\251dical en mode web par MedWebTux", 0, QApplication::UnicodeUTF8));
m_action_Aide->setText(QApplication::translate("C_ManagerClass", "Documentation de MedinTux", 0, QApplication::UnicodeUTF8));
m_action_UserParams->setText(QApplication::translate("C_ManagerClass", "Gestion des profils utilisateur", 0, QApplication::UnicodeUTF8));
m_action_UserParams->setShortcut(QApplication::translate("C_ManagerClass", "Ctrl+G", 0, QApplication::UnicodeUTF8));
m_actionImprimer->setText(QApplication::translate("C_ManagerClass", "Imprimer", 0, QApplication::UnicodeUTF8));
m_actionImprimer->setShortcut(QApplication::translate("C_ManagerClass", "Ctrl+P", 0, QApplication::UnicodeUTF8));
if (m_NomadismeToolBar) m_NomadismeToolBar->setWindowTitle(QApplication::translate("C_ManagerClass", "Outils pour le nomadisme", 0, QApplication::UnicodeUTF8));
}
//--------------------------------- closeEvent -----------------------------------------------------------------------
void C_Manager::closeEvent(QCloseEvent *event)
{   Slot_SauverLesMeubles();
    event->accept();
    /*
    if (maybeSave()) {
        writeSettings();
        event->accept();
    } else {
        event->ignore();
    }
   */
}
///////////////////////////////////////// WEB PAGE /////////////////////////////////////////////////////
//--------------------------------- Slot_On_webView_MedWebTux_loadStarted -----------------------------------------------------------------------
void C_Manager::Slot_On_webView_MedWebTux_loadStarted()
{m_pGUI->progressBarWebView->setValue(0);
m_pGUI->progressBarWebView->show();
}
//--------------------------------- Slot_On_webView_MedWebTux_loadProgress -----------------------------------------------------------------------
void C_Manager::Slot_On_webView_MedWebTux_loadProgress(int progress)
{m_pGUI->progressBarWebView->setValue(progress);
m_action_WebStop->setEnabled(TRUE);
}

//--------------------------------- Slot_On_webView_MedWebTux_loadFinished -----------------------------------------------------------------------
void C_Manager::Slot_On_webView_MedWebTux_loadFinished(bool)
{m_pGUI->progressBarWebView->hide();
m_action_WebStop->setEnabled(FALSE);
}

//--------------------------------- Slot_actionWebStop -----------------------------------------------------------------------
void C_Manager::Slot_actionWebStop (bool)
{m_pGUI->progressBarWebView->hide();
m_webView_MedWebTux->stop();
m_action_WebStop->setEnabled(FALSE);
}

//--------------------------------- Slot_LocationEdit_returnPressed -----------------------------------------------------------------------
void C_Manager::Slot_LocationEdit_returnPressed()
{
   QUrl url = QUrl(m_locationEdit->text());
   m_webView_MedWebTux->load(url);
   m_webView_MedWebTux->setFocus();
}
//--------------------------------- Slot_WebFindEdit_returnPressed -----------------------------------------------------------------------
void C_Manager::Slot_WebFindEdit_returnPressed()
{Slot_actionWebFind (true);
}
// [Web_Browser]
//    StartPage = ../../Doc/index.html
// QString page =  CGestIni::Param_ReadUniqueParam(G_pCApp->m_LocalParam, "Web_Browser", "StartPage");

//--------------------------------- Slot_WebFindEdit_textChanged -----------------------------------------------------------------------
void C_Manager::Slot_WebFindEdit_textChanged (const QString &text )
{m_webView_MedWebTux->findText ("",   QWebPage::HighlightAllOccurrences );  // clear the selection
m_webView_MedWebTux->findText (text, QWebPage::HighlightAllOccurrences );
}

//--------------------------------- Slot_actionWebFind -----------------------------------------------------------------------
void C_Manager::Slot_actionWebFind (bool)
{m_webView_MedWebTux->findText (m_WebFindEdit->text(), QWebPage::FindWrapsAroundDocument );
}

//--------------------------------- Slot_actionWebPrint -----------------------------------------------------------------------
void C_Manager::Slot_actionWebPrint (bool)
{
#ifndef QT_NO_PRINTER
    QPrinter printer(QPrinter::HighResolution);
    QPrintDialog *printDialog = new QPrintDialog(&printer, this);
    if (printDialog->exec() == QDialog::Accepted)
       {     m_webView_MedWebTux->print ( &printer );
       }
#endif // QT_NO_PRINTER
}
//--------------------------------- Slot_action_Aide -----------------------------------------------------------------------
void C_Manager::Slot_action_Aide (bool)
{Slot_actionWebHelp (TRUE);
m_pGUI->tabWidget_Central->setCurrentIndex ( 1 );
}

//--------------------------------- Slot_action_AccesWebMedTux -----------------------------------------------------------------------
void C_Manager::Slot_action_AccesWebMedTux (bool)
{setMedWebTuxOnUser();
m_pGUI->tabWidget_Central->setCurrentIndex ( 1 );
}

//--------------------------------- Slot_actionWebHome -----------------------------------------------------------------------
void C_Manager::Slot_actionWebHome (bool)
{setMedWebTuxOnUser();
}

//--------------------------------- Slot_actionWebHelp -----------------------------------------------------------------------
void C_Manager::Slot_actionWebHelp (bool)
{
   QString page =  "../../Doc/index.html";
   if ( QDir(page).isRelative()&& !page.startsWith("http"))
    {page.prepend(G_pCApp->m_PathAppli);
     page = QDir::cleanPath(page);
    }
 m_webView_MedWebTux->setUrl(QUrl(page));
 m_locationEdit->setText(page);
}
//--------------------------------- setMedWebTuxOnUser -----------------------------------------------------------------------
void C_Manager::setMedWebTuxOnUser()
{
 //   [Web_Browser]
 //       MedWebTuxUrl = http://localhost/MedWebTux/
 QString medWebTuxUrl =  CGestIni::Param_ReadUniqueParam(G_pCApp->m_LocalParam, "Web_Browser", "MedWebTuxUrl");
 QString cripted_password;
 G_pCApp->m_pCMoteurBase->GetUserPrimKey(G_pCApp->m_SignUser, &cripted_password   /* = 0  */);
 QString page =                    medWebTuxUrl           +"?adr="         + G_pCApp->m_pCMoteurBase->m_HostName
                                                          + "&loginbase="  + G_pCApp->m_pCMoteurBase->m_UserName
                                                          + "&pwd="        + G_pCApp->m_pCMoteurBase->m_PassWord
                                                          + "&login="      + G_pCApp->m_SignUser
                                                          + "&pass="       + cripted_password
                                                          + "&ID="; //+&ID=xxx
m_webView_MedWebTux->setUrl(QUrl(page));
m_locationEdit->setText(page);
}

//--------------------------------- Slot_webView_MedWebTux_urlChanged -----------------------------------------------------------------------
void C_Manager::Slot_webView_MedWebTux_urlChanged ( const QUrl &url  )
{m_locationEdit->setText(url.toString());
}

//--------------------------------- Slot_action_DebloquerBases -----------------------------------------------------------------------
void C_Manager::Slot_action_DebloquerBases (bool)
{G_pCApp->m_pCMoteurBase->DeVerrouilleTout();
}

///////////////////////////////////////// ACCESSOIRE ///////////////////////////////////////////////////
//---------------------------------------------- demarrerAccessoires -----------------------------------------------------------------------
void C_Manager::demarrerAccessoires()
{
 //.................. recuperer la liste des programmes Accessoires a demarrer en meme temps ................................................
 //                                              et les lancer
 // [Accessoires]
 // QLaboFTP = ../../QLaboFTP/bin/QLaboFTP
QStringList accessoiresList;
CGestIni::Param_GetList(G_pCApp->m_LocalParam, tr("Accessoires"), "", accessoiresList );
if (accessoiresList.count())
   {for ( QStringList::Iterator it = accessoiresList.begin(); it != accessoiresList.end(); ++it )
        { demarrerUnAccessoire(*it);
        }
   }
}

//---------------------------------------------- demarrerUnAccessoire -----------------------------------------------------------------------
void C_Manager::demarrerUnAccessoire(QString accessoire_path)
{
QStringList argList;
QString  pathExe = QDir::cleanDirPath (QFileInfo (qApp->argv()[0]).dirPath (true)) + "/" + accessoire_path.trimmed();
#ifdef Q_WS_WIN
   pathExe +=".exe";
//#else
#endif
QProcess::startDetached (pathExe, argList);
}

//--------------------------------- Slot_action_DebloquerBases -----------------------------------------------------------------------
void C_Manager::Slot_tabWidget_Central_currentChanged (int index)
{if (index==0)
   {m_WebToolBar->hide();
   }
else
   {m_WebToolBar->show();
   }
}

//--------------------------------- Slot_SauverLesMeubles --------------------------------------------------------------------------------
void C_Manager::Slot_SauverLesMeubles()
{tryToStopAPropos();
}

//----------------------------------- Slot_actionApropos -----------------------------------------------------------------------
void C_Manager::Slot_actionApropos(bool)
{QTimer::singleShot ( 100, this,SLOT(Slot_actionAproposDisplay()) );
}

//----------------------------------- Slot_actionAproposDisplay -----------------------------------------------------------------------
void C_Manager::Slot_actionAproposDisplay()
{        CGestIni::Param_UpdateToDisk(G_pCApp->m_PathAppli+"Ressources/Changements.html",m_pGUI->textEdit_Changements->toHtml());
        QString pathExeAPropos     = CGestIni::Construct_Name_Exe("APropos", QFileInfo (qApp->argv()[0]).path());
        QString pathBinRessources  = CGestIni::Construct_PathBin_Module("APropos", QFileInfo (qApp->argv()[0]).path())+"Ressources/";
        QStringList argList;
        QProcess::ProcessState procState;
        //......................... completer les autres arguments .........................................
        argList << "Manager";                                                       // 1  nom du module
        argList << tr("Module de gestion de l'agenda et de la liste des patients"); // 2  description courte
        argList << (G_pCApp->getNumVers()+" Qt : "+QT_VERSION_STR);                 // 3  numero de version
        argList << G_pCApp->m_PathAppli+"Ressources/Changements.html";              // 4  fichiers d?crivant les changements
        argList << Theme::getPath(Theme::WithSeparator)+"32x32/Manager.png";        // 5  Icone du programme
        argList << QDir::cleanPath(G_pCApp->m_PathAppli+"../../Doc/index.html") ;   // 6  aide en ligne
        //QProcess::startDetached (pathExeAPropos, argList);

        if (m_Apropos_Proc==0)
           {m_action_A_Propos->setDisabled(TRUE);
            m_Apropos_Proc = new QProcess(this);
            m_Apropos_Proc->start(pathExeAPropos, argList);
            SLEEP(1);
            G_pCApp->processEvents ();
            while ( (procState = m_Apropos_Proc->state())== QProcess::Running ) // && QFile::exists(pathBinRessources+"~A_propos.html")
                  { //qDebug(QString::number(procState).toAscii());
                    QApplication::processEvents ( QEventLoop::WaitForMoreEvents );
                  }
            if (m_Apropos_Proc) delete m_Apropos_Proc;
            m_Apropos_Proc = 0;
            QFile::remove(pathBinRessources+"~A_propos.html");
            m_action_A_Propos->setDisabled(FALSE);
           }

}
//--------------------------------------- tryToStopAPropos ----------------------------------------------------------
void C_Manager::tryToStopAPropos()
{if (m_Apropos_Proc==0) return;
m_Apropos_Proc->kill();   // terminate() ne fonctionne pas
}

//--------------------------------- Slot_OnTimer ---------------------------------------------------------------------------------------
void C_Manager::Slot_OnTimer()
{if (G_pCApp->m_pCMoteurBase->OpenBase()==0) return;
if ( m_pCMoteurBase->IsDossierVerrouille(G_pCApp->identitePatientGUID()))
   {setVerrou(TRUE);
   }
else
   {setVerrou(FALSE);
   }
G_pCApp->m_pCMoteurBase->CloseBase();
}

///////////////////////////////////////// SIGEMS ///////////////////////////////////////////////////
//--------------------------------- Slot_pushButton_SigemsPA_Clicked -----------------------------------------------------------------------
void C_Manager::Slot_action_Imprimer (bool)
{
#ifndef QT_NO_PRINTER
QString   modele = "";
QString     path = G_pCApp->m_PathAppli + "Ressources/identiteModele"; //.html";
CGestIni::Param_UpdateFromDisk(path+".html" , modele);
if (modele.length()==0)
   {G_pCApp->CouCou(tr("Maquette d'impression '%1' vide").arg(path));
    return;
   }
modele.replace("{{DATE}}",                    QDate::currentDate().toString("dd/MM/yyyy"));
modele.replace("{{TIME}}",                    QTime::currentTime().toString("hh:mm"));
modele.replace("{{NOM PATIENT}}",             m_pGUI->lineEdit_NomDossier->text());
modele.replace("{{PRENOM PATIENT}}",          m_pGUI->lineEdit_PrenomDossier->text());
modele.replace("{{NOM NAISSANCE PATIENT}}",   m_pGUI->lineEdit_NomDeNss->text());
modele.replace("{{NUM. TEL1 PATIENT}}",       m_pGUI->lineEdit_Tel1->text());
modele.replace("{{NUM. TEL2 PATIENT}}",       m_pGUI->lineEdit_Tel2->text());
modele.replace("{{NUM. TEL3 PATIENT}}",       m_pGUI->lineEdit_Tel3->text());
modele.replace("{{EMAIL PATIENT}}",           m_pGUI->lineEdit_Email->text());
modele.replace("{{DATE NAISSANCE PATIENT}}",  m_pGUI->lineEdit_DtNss->text());
modele.replace("{{SEXE PATIENT}}",            m_pGUI->comboBoxSexe->currentText());
modele.replace("{{TITRE PATIENT}}",           m_pGUI->lineEdit_Titre->text());
modele.replace("{{PROFESSION PATIENT}}",      m_pGUI->lineEdit_Profession->text());
modele.replace("{{VILLE PATIENT}}",           m_pGUI->lineEditVille->text());
modele.replace("{{CODE POSTAL PATIENT}}",     m_pGUI->lineEdit_CdPostal->text());
modele.replace("{{ADRESSE PATIENT}}",         m_pGUI->textEdit_Adresse->text());
modele.replace("{{NUM. SECU PATIENT}}",       m_pGUI->lineEdit_NumSecu->text()+" "+ m_pGUI->lineEdit_NssClef->text());
modele.replace("{{NOM ASSURE}}",              m_pGUI->lineEdit_NomAssure->text());
modele.replace("{{PRENOM ASSURE}}",           m_pGUI->lineEdit_PrenomAssure->text());
modele.replace("{{DATE NAISSANCE ASSURE}}",   m_pGUI->lineEdit_DtNss_Assure->text());
modele.replace("{{DEBUT DROITS}}",            m_pGUI->lineEdit_DroitsDateDeb->text());
modele.replace("{{FIN DROITS}}",              m_pGUI->lineEdit_DroitsDateFin->text());
QString    cas = m_pGUI->lineEdit_CodeRegime->text()+m_pGUI->lineEdit_CaisseGest->text()+m_pGUI->lineEdit_CentreGest->text();
modele.replace("{{CAS}}",                     cas);
modele.replace("{{CODE REGIME}}",             m_pGUI->lineEdit_CodeRegime->text());
modele.replace("{{CODE GESTION}}",            m_pGUI->lineEdit_CodeGest->text());
modele.replace("{{CAISSE GESTIONNAIRE}}",     m_pGUI->lineEdit_CaisseGest->text());
modele.replace("{{CENTRE GESTIONNAIRE}}",     m_pGUI->lineEdit_CentreGest->text());
modele.replace("{{RANG GEM}}",                m_pGUI->lineEdit_RangGeme->text());
modele.replace("{{QUALITE AYANT DROIT}}",     m_pGUI->comboBoxQualiteAyantDroit->currentText());
CGestIni::Param_UpdateToDisk(path+"-P.html" , modele);

QWebView *pQWebView = new QWebView(this); if (pQWebView==0)   return;
pQWebView->load(QUrl(path + "-P.html"));

QPrinter printer(QPrinter::HighResolution);
//printer.setOutputFormat(QPrinter::PdfFormat);
//QFileInfo fi(path);

//if (destPdfFile.length()==0) destPdfFile = fi.path()+"/"+fi.baseName()+".pdf";                // name = "archive.tar.gz"
//printer.setOutputFileName (destPdfFile);
//pQWebView->show();
//if (QFile::exists(destPdfFile)) QFile::remove(destPdfFile);
QString printerName = "";
CGestIni::Param_ReadParam( G_pCApp->m_LocalParam, "Print", "Printer name", &printerName);
if (printerName.length()) printer.setPrinterName(printerName);
QPrintDialog *printDialog = new QPrintDialog(&printer, pQWebView);
if (printDialog->exec() == QDialog::Accepted)
   {pQWebView->print ( &printer );
    printerName = printer.printerName();
    CGestIni::Param_WriteParam( &G_pCApp->m_LocalParam, "Print", "Printer name", printerName);
    CGestIni::Param_UpdateToDisk(G_pCApp->m_PathAppli+"Manager.ini", G_pCApp->m_LocalParam);
   }
delete pQWebView;
#endif // QT_NO_PRINTER
}

//--------------------------------- Slot_pushButton_SigemsPA_Clicked -----------------------------------------------------------------------
void C_Manager::Slot_pushButton_SigemsPA_Clicked()
{// {{:: exe_process (noWaitEnd  ,../../InterfaceSigems/bin/interfacesigems,{{NOM PATIENT}},{{PRENOM PATIENT}},{{GET_DOSS_GUID}},{{USER LOGIN MEDECIN}} )}}
   //............ controle du sexe ...............................
   if (m_pGUI->comboBoxSexe->currentText().toUpper()[0]=='I')
      {QMessageBox  msgBox;
       QPushButton *femininButton  = msgBox.addButton(tr("&F\303\251minin"),  QMessageBox::ActionRole);
       QPushButton *masculinButton = msgBox.addButton(tr("&Masculin"), QMessageBox::ActionRole);
       msgBox.setText(tr("Il est important de bien rentrer le sexe"));
       msgBox.exec();

       if (msgBox.clickedButton() == femininButton)
          {m_pGUI->comboBoxSexe->setCurrentItem ( 1 );
          }
       else
          {m_pGUI->comboBoxSexe->setCurrentItem ( 0 );
          }
       m_pGUI->pushButtonSavModif->setEnabled(TRUE);
      }
   //................... controle de la coherence Nss et sexe ....................
   if (m_pGUI->comboBoxQualiteAyantDroit->currentItem()==0)
      {if ( (m_pGUI->comboBoxSexe->currentText().toUpper()[0]=='F'&&m_pGUI->lineEdit_NumSecu->text()[0]!='2') ||
            (m_pGUI->comboBoxSexe->currentText().toUpper()[0]=='M'&&m_pGUI->lineEdit_NumSecu->text()[0]!='1')
          )
          {QMessageBox  msgBox;
           QPushButton *annuler = msgBox.addButton(tr("Annuler"), QMessageBox::ActionRole);
           msgBox.setText(tr("Incoh\303\251rence entre le sexe du patient et le premier chiffre de son num\303\251ro de s\303\251curit\303\251 sociale"));
           msgBox.exec();
           return;
          }
      }

   QString pathExe =  G_pCApp->m_PathSigemsPA+"InterfaceSigems";
   #ifdef  Q_WS_WIN
          pathExe += ".exe";
   #endif
   #ifdef Q_WS_X11
          pathExe += "";
   #endif
   #ifdef  Q_WS_MAC
          int pos = pathExe.lastIndexOf("/");
          if (pos != -1) pathExe = pathExe+".app/Contents/MacOS/"+pathExe.mid(pos+1);
   #endif
   if (!QFile::exists (pathExe ))
      {G_pCApp->CouCou(tr("Chemin du plugin InterfaceSigems non trouv\303\251 : ").arg(pathExe));
       return;
      }

   if( getInterfaceMode()==MODE_CREATION_PATIENT)
     {onCreateAction(0);
     }
   else if ( getInterfaceMode()==MODE_SELECTION_PATIENT && m_pGUI->pushButtonSavModif->isEnabled())
     {Slot_pushButtonSavModif();
     }
   QStringList             argList;
   argList << G_pCApp->m_LastNom;
   argList << G_pCApp->m_LastPrenom;
   argList << G_pCApp->m_LastGUID;
   argList << G_pCApp->m_SignUser;
   QProcess::startDetached (pathExe, argList);
}

///////////////////////////////////////// NOMADISME ///////////////////////////////////////////////////
//--------------------------------- Slot_action_ToModeNomade_triggered -----------------------------------------------------------------------
void C_Manager::Slot_action_ToModeNomade_triggered (bool)
{if (m_pMasterSocket) delete m_pMasterSocket;
if (m_pSlaveSocket)  delete m_pSlaveSocket;
QAbstractSocket *m_pMasterSocket = new QAbstractSocket( QAbstractSocket::TcpSocket,    this );
connect(m_pMasterSocket,      SIGNAL(hostFound ()),                                    this, SLOT(Slot_hostMasterFound ()) );
connect(m_pMasterSocket,      SIGNAL(error ( QAbstractSocket::SocketError  )),         this, SLOT(Slot_hostMasterError (QAbstractSocket::SocketError )) );
connect(m_pMasterSocket,      SIGNAL(stateChanged ( QAbstractSocket::SocketState  )),  this, SLOT(Slot_hostMasterStateChanged (QAbstractSocket::SocketState )) );

QAbstractSocket *m_pSlaveSocket = new QAbstractSocket( QAbstractSocket::TcpSocket,     this );
connect(m_pSlaveSocket,       SIGNAL(hostFound ()),                                    this, SLOT(Slot_hostSlaveFound ()) );
connect(m_pSlaveSocket,       SIGNAL(error ( QAbstractSocket::SocketError  )),         this, SLOT(Slot_hostSlaveError (QAbstractSocket::SocketError )) );
connect(m_pSlaveSocket,       SIGNAL(stateChanged ( QAbstractSocket::SocketState  )),  this, SLOT(Slot_hostSlaveStateChanged (QAbstractSocket::SocketState )) );
m_pMasterSocket->connectToHost ( "192.168.10.10", 3306);
if (m_pMasterSocket->waitForConnected(2000)) qDebug(QString("stateMaster  : connected").toLatin1());
//else                                         qDebug(QString("stateMaster  : not connected").toLatin1());
m_pSlaveSocket->connectToHost ( "localhost", 3306);
if (m_pSlaveSocket->waitForConnected(2000))  qDebug(QString("stateSlave  : connected").toLatin1());
//else                                         qDebug(QString("stateSlave  : not connected").toLatin1());
}

//--------------------------------- socketStateToString -----------------------------------------------------------------------
QString  C_Manager::socketStateToString(QAbstractSocket::SocketState socketState, const QString& prefix )
{switch (socketState)
       { case QAbstractSocket::UnconnectedState: return tr("%1 The socket is not connected.").arg(prefix);
         case QAbstractSocket::HostLookupState:  return tr("%1 The socket is performing a host name lookup.").arg(prefix);
         case QAbstractSocket::ConnectingState:  return tr("%1 The socket has started establishing a connection.").arg(prefix);
         case QAbstractSocket::ConnectedState:   return tr("%1 A connection is established.").arg(prefix);
         case QAbstractSocket::BoundState:       return tr("%1 The socket is bound to an address and port (for servers).").arg(prefix);
         case QAbstractSocket::ClosingState:     return tr("%1 The socket is about to close (data may still be waiting to be written).").arg(prefix);
         case QAbstractSocket::ListeningState:   return tr("%1 For internal use only.").arg(prefix);
       }
return QString::null;
}
//--------------------------------- Slot_hostMasterStateChanged -----------------------------------------------------------------------
void C_Manager::Slot_hostMasterStateChanged (QAbstractSocket::SocketState socketState)
{qDebug(socketStateToString(socketState, tr("Etat du Maitre : ")).toLatin1());
}
//--------------------------------- Slot_hostSlaveStateChanged -----------------------------------------------------------------------
void C_Manager::Slot_hostSlaveStateChanged (QAbstractSocket::SocketState socketState)
{qDebug(socketStateToString(socketState, tr("Etat du Nomade : ")).toLatin1());
}

//--------------------------------- Slot_action_ToModeConnect_triggered -----------------------------------------------------------------------
void C_Manager::Slot_hostMasterFound ()
{//qDebug(QString("host MasterFound").toLatin1());
}
//--------------------------------- Slot_action_ToModeConnect_triggered -----------------------------------------------------------------------
void C_Manager::Slot_hostSlaveFound ()
{//qDebug(QString("host SlaveFound").toLatin1());
}

//--------------------------------- Slot_hostMasterError -----------------------------------------------------------------------
void C_Manager::Slot_hostMasterError (QAbstractSocket::SocketError socketError)
{switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, tr("MasterError"),
                                 tr("The host was not found. Please check the "
                                    "host name and port settings."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, tr("MasterError"),
                                 tr("The connection was refused by the peer. "
                                    "Make sure the fortune server is running, "
                                    "and check that the host name and port "
                                    "settings are correct.  %1"));
        break;
    default:
        QMessageBox::information(this, tr("MasterError"),
                                 tr("The following error occurred: %1.")
                                 .arg(m_pMasterSocket->errorString()));
    }
}
//--------------------------------- Slot_hostSlaveError -----------------------------------------------------------------------
void C_Manager::Slot_hostSlaveError (QAbstractSocket::SocketError socketError)
{switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, tr("SlaveError"),
                                 tr("The host was not found. Please check the "
                                    "host name and port settings."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, tr("SlaveError"),
                                 tr("The connection was refused by the peer. "
                                    "Make sure the fortune server is running, "
                                    "and check that the host name and port "
                                    "settings are correct."));
        break;
    default:
        QMessageBox::information(this, tr("SlaveError"),
                                 tr("The following error occurred: %1.")
                                 .arg(m_pSlaveSocket->errorString()));
    }
}
//--------------------------------- setAndSaveNomadeState -----------------------------------------------------------------------
void C_Manager::setAndSaveNomadeState (int nomadismeStateToSet)
{CGestIni::Param_WriteParam(&G_pCApp->m_LocalParam,"Connexion", "nomadisme", nomadismeStateToSet==TRUE?"actif":"non actif");
CGestIni::Param_UpdateToDisk(G_pCApp->m_PathAppli+"Manager.ini", G_pCApp->m_LocalParam);
if (nomadismeStateToSet)
   {//............ positionner le bouton et icone sur la nouvelle action possible ......................
    //             CAD puisqu'on est actuellement en mode nomade l'action possible
    //                 est de le quitter pour passer en mode Master
    m_action_ModeNomade->setText(tr("Quitter le mode Nomade et se reconnecter au serveur central"));
    m_action_ModeNomade->setIconSet ( Theme::getIcon("32x32/unconnected.png") ) ;
   }
else
   {m_action_ModeNomade->setText(tr("Se d\303\251connecter du serveur central et passer en mode Nomade"));
    m_action_ModeNomade->setIconSet ( Theme::getIcon("32x32/connected.png") ) ;
   }
}

//---------------------------------------------- testConnection -----------------------------------------------------------------------
int C_Manager::testConnection(QString connexionVar,  QString *errMess )
{
        QString param;
        QString  driver, baseToConnect, sqlUserName, sqlPass, hostName, port;
        CGestIni::Param_UpdateFromDisk(G_pCApp->m_PathAppli+"Manager.ini", param);
        if (CGestIni::Param_ReadParam( param, "Connexion", connexionVar, &driver, &baseToConnect, &sqlUserName, &sqlPass, &hostName, &port) != QString::null )  // zero = pas d'erreur
           {return FALSE;
           }
       QSqlDatabase::removeDatabase ("TEST_CONNECTION");
       QSqlDatabase defaultDB  = QSqlDatabase::addDatabase(driver, "TEST_CONNECTION");
       defaultDB.setDatabaseName( baseToConnect );
       defaultDB.setUserName    ( sqlUserName );
       defaultDB.setPassword    ( sqlPass );
       defaultDB.setHostName    ( hostName);
       defaultDB.setPort        ( port.toInt());
       if ( ! defaultDB.open() )
          {QString qstr = "";
           qstr += tr("Failed to open database : ")    + "TEST_CONNECTION  Driver : " +  QString(driver) + "  " + QString(baseToConnect) + "\r\n" +
                    defaultDB.lastError().driverText() + "\r\n" + defaultDB.lastError().databaseText();
           qWarning(qstr.toLatin1());
           if (errMess) *errMess = qstr;
           QSqlDatabase::removeDatabase ("TEST_CONNECTION");
           return 0;
          }
       defaultDB.close();
       QSqlDatabase::removeDatabase ("TEST_CONNECTION");
       return 1;
}

//--------------------------------- Slot_action_ModeConnect_triggered -----------------------------------------------------------------------
void C_Manager::Slot_action_ModeConnect_triggered (bool)
{
if (identIsModified() && G_pCApp->isCurrentIdentiteValid() && G_pCApp->IsThisDroitExist(G_pCApp->m_Droits, "idc") )
    { Slot_pushButtonSavModif();
    }
QApplication::setOverrideCursor ( QCursor(Qt::WaitCursor) );
if (G_pCApp->m_IsGestionNomadisme==CMoteurBase::fullReplication)
   {
    action_fullSwitchReplication_triggered ();
   }
else if (G_pCApp->m_IsGestionNomadisme==CMoteurBase::fullSynchro)
  {action_fullSynchroReplication_triggered ();
  }
QApplication::restoreOverrideCursor();
}
//--------------------------------- tryToFindConnectionFromList -----------------------------------------------------------------------
QString C_Manager::tryToFindConnectionFromList (QString connexionVar,  QString *errMess)
{        //..................... recuperer la liste des connections possibles ..................
        //QStringList connectList;
        QString param;
        CGestIni::Param_UpdateFromDisk(G_pCApp->m_PathAppli+"Manager.ini", param);
        QString  driver, baseToConnect, sqlUserName, sqlPass, hostName, port;
        //..................... tester la liste des connections possibles ..................
        //                      et s'arreter a la premiere possible
             if (CGestIni::Param_ReadParam( param, "Connexion", connexionVar, &driver, &baseToConnect, &sqlUserName, &sqlPass, &hostName, &port) == QString::null )  // zero = pas d'erreur
                {QSqlDatabase::removeDatabase ("TEST_CONNECTION");
                 QSqlDatabase defaultDB  = QSqlDatabase::addDatabase(driver, "TEST_CONNECTION");
                 defaultDB.setDatabaseName( baseToConnect );
                 defaultDB.setUserName    ( sqlUserName );
                 defaultDB.setPassword    ( sqlPass );
                 defaultDB.setHostName    ( hostName);
                 defaultDB.setPort        ( port.toInt());
                 if ( ! defaultDB.open() )
                    {QString qstr = "";
                     qstr += tr("Failed to open database : ")    + "TEST_CONNECTION  Driver : " +  QString(driver) + "  " + QString(baseToConnect) + "\r\n" +
                     defaultDB.lastError().driverText() + "\r\n" + defaultDB.lastError().databaseText();
                     qWarning(qstr.toLatin1());
                     if (errMess) *errMess = qstr;
                     QSqlDatabase::removeDatabase ("TEST_CONNECTION");
                     return QString::null;
                    }
                 defaultDB.close();
                 QSqlDatabase::removeDatabase ("TEST_CONNECTION");
                 return "Ok";
                }
return QString::null;
}
//--------------------------------- getScriptNomadePath -----------------------------------------------------------------------
QString C_Manager::getScriptNomadePath()
{
    #ifdef Q_WS_MAC
        QString scriptPath = G_pCApp->m_PathAppli + "Nomadisme/MacOSScripts";
        return scriptPath.replace("/", QDir::separator ());
    #endif
    #ifdef Q_WS_WIN
        QString scriptPath = G_pCApp->m_PathAppli + "Nomadisme/WindowsScripts";
        return   scriptPath.replace("/", QDir::separator());
    #endif
    #ifdef Q_WS_X11
        QString scriptPath = G_pCApp->m_PathAppli + "Nomadisme/LinuxScripts";
        return scriptPath.replace("/", QDir::separator ());
    #endif
}

//--------------------------------- action_fullSynchroReplication_triggered -----------------------------------------------------------------------
void C_Manager::action_fullSynchroReplication_triggered ()
{QString errMess   = "";
QString paramConn = tryToFindConnectionFromList ("Master", &errMess);
if (paramConn.length()==0)
   {QMessageBox::information( this, tr("CONNECTION AU SERVEUR MAITRE NON POSSIBLE"),
                                    tr ( " <b><u>ATTENTION</b></u> ! la connexion au serveur ma\303\256tre <br>")+
                                    tr ( "est non possible.<br><u>Erreur :</u><br><pre>" ) + errMess + "</pre><br>" +
                                    tr(  "Veuillez v\303\251rifier vos branchements et param\303\250tres.") ,
                                    tr("Annu&ler"), 0, 0,
                                    0, 0 );
    return;
   }
QString login_Master,   login_Nomade;
QString host_Master,    host_Nomade;
QString pass_Master,    pass_Nomade;
QString port_Master,    port_Nomade;
QString driver, baseToOpen;
//............... recuperation des valeurs dans le .INI ...........
QString param;
CGestIni::Param_UpdateFromDisk(G_pCApp->m_PathAppli+"Manager.ini", param);
CGestIni::Param_ReadParam( param, "Connexion", "Master",  &driver,  &baseToOpen, &login_Master,  &pass_Master,    &host_Master,  &port_Master);
CGestIni::Param_ReadParam( param, "Connexion", "Nomade",  &driver,  &baseToOpen, &login_Nomade,  &pass_Nomade,    &host_Nomade,  &port_Nomade);

QString scriptPath  = getScriptNomadePath();
QStringList paramList; CGestIni::Param_GetList(param, "Connexion", "listParam", paramList );
/*
    #ifdef Q_WS_MAC
    #endif
    #ifdef Q_WS_WIN
        setBatchParametres(scriptPath+"/Bat_StopCircularRepli.bat", paramList);
        QString scriptToDo  = QString("\"")+scriptPath  + "/Bat_StopCircularRepli.bat\" \"" + scriptPath + "\" \"" +
                              host_Master +"\" \""+ login_Master +"\" \"" +  pass_Master +"\" \"" +  port_Master +"\" \""  +
                              host_Nomade +"\" \""+ login_Nomade +"\" \"" +  pass_Nomade +"\" \"" +  port_Nomade + "\"";
    #endif
    #ifdef Q_WS_X11
    #endif
        //                                                        lancer le script ..............................................
        QStringList argList;
        putScriptWaitFlag(   scriptPath  + "/ScriptStatus.txt");
    #ifdef Q_WS_X11
            argList<<"777"<<scriptToDo;  QProcess::execute ("chmod", argList); argList.clear();      argList<<scriptToDo;
            QProcess::execute ("bash", argList);
    #endif
    #ifdef Q_WS_MAC
             argList<<"777"<<scriptToDo;  QProcess::execute ("chmod", argList); argList.clear();      argList<<scriptToDo;
             QProcess::execute ("bash", argList);
    #endif
    #ifdef Q_WS_WIN
             QProcess::startDetached (QString ("cmd /c start ") + scriptToDo ); //START.EXE /B /MIN leScriptAmasquer.CMD
             //QProcess::startDetached (QString ("START.EXE /B /MIN ") + scriptToDo ); //START.EXE /B /MIN leScriptAmasquer.CMD
    #endif
        //................. attendre la fin de l'execution du script .......................................................
        waitForEndScript( scriptPath + "/ScriptStatus.txt" );
        //................. apres mise a jour recuperer fichier ............................................................
        //                  etat de la repli circulaire apres arret boucle circulaire
        QString repliStatus;
        CGestIni::Param_UpdateFromDisk(scriptPath  + "/Out_PosRepliLoop.txt", repliStatus);

        //            Master_Host: aadmaison.homedns.org
        //            Master_User: server104
        //            Master_Port: 3306
        //            Master_Log_File: LogBin103.000001
        //            Read_Master_Log_Pos: 2008

        QString master_Host         ="";
        QString master_User         ="";
        QString master_Port         ="";
        QString master_Log_File     ="";
        QString read_Master_Log_Pos ="";
        QString masterKey           = CGestIni::Param_ReadUniqueParam( param, "Connexion", "MasterKey");
        //........................ les appels doivent etre dans l'ordre d'appartion des variables .................
        //                         dans le fichier a analyser
        int pos                             = 0;
                       master_Host          = extractVarFromMysqlStatus(repliStatus, "Master_Host:",         pos);
        if (pos != -1) master_User          = extractVarFromMysqlStatus(repliStatus, "Master_User:",         pos);
        if (pos != -1) master_Port          = extractVarFromMysqlStatus(repliStatus, "Master_Port:",         pos);
        if (pos != -1) master_Log_File      = extractVarFromMysqlStatus(repliStatus, "Master_Log_File:",     pos);
        if (pos != -1) read_Master_Log_Pos  = extractVarFromMysqlStatus(repliStatus, "Read_Master_Log_Pos:", pos);
        if (pos == -1) return;          // serait bon de relancer la repli circulaire
     */
        //.......................... synchro ..............................................
        setConnectParametres( scriptPath + "/ScriptStartSlave.mod");      // ---> transforme en .txt      // etape 2
        setConnectParametres( scriptPath + "/ScriptStartMasterSrc.mod");  // ---> transforme en .txt      // etape 2
        setConnectParametres( scriptPath + "/ScriptJeReviens.mod");       // ---> transforme en .txt      // etape 3
        setConnectParametres( scriptPath + "/ScriptRelanceRepli.mod");    // ---> transforme en .txt      // etape 6

        //                                                        lancer le script ..............................................
        putScriptWaitFlag(   scriptPath  + "/ScriptStatus.txt");
    #ifdef Q_WS_X11
        QStringList argList;
        setBatchParametres(scriptPath+"/Bat_JeSynchronise.sh", paramList);
        QString  scriptToDo  = QString("'")+scriptPath  + "/Bat_JeSynchronise.sh' '" + scriptPath + "' '" +
                               host_Master +"' '"+ login_Master +"' '" +  pass_Master +"' '" +  port_Master + "' '"  +
                               host_Nomade +"' '"+ login_Nomade +"' '" +  pass_Nomade +"' '" +  port_Nomade + "'";
        argList<<"777"<<scriptToDo;  QProcess::execute ("chmod", argList);// argList.clear();      argList<<scriptToDo;
        QProcess::startDetached (QString ("bash ") + scriptToDo ); //START.EXE /B /MIN leScriptAmasquer.CMD
        //QProcess::execute ("bash", argList);
    #endif
    #ifdef Q_WS_MAC
        QStringList argList;
        setBatchParametres(scriptPath+"/Bat_JeSynchronise.sh", paramList);
        QString  scriptToDo  = QString("'")+scriptPath  + "/Bat_JeSynchronise.sh' '" + scriptPath + "' '" +
                               host_Master +"' '"+ login_Master +"' '" +  pass_Master +"' '" +  port_Master + "' '"  +
                               host_Nomade +"' '"+ login_Nomade +"' '" +  pass_Nomade +"' '" +  port_Nomade + "'";
        argList<<"777"<<scriptToDo;  QProcess::execute ("chmod", argList);// argList.clear();      argList<<scriptToDo;
        QProcess::startDetached (QString ("bash ") + scriptToDo ); //START.EXE /B /MIN leScriptAmasquer.CMD
    #endif
    #ifdef Q_WS_WIN
        setBatchParametres(scriptPath+"/Bat_JeSynchronise.bat", paramList);
        QString  scriptToDo  = QString("\"")+scriptPath  + QDir::separator()+"Bat_JeSynchronise.bat\" \"" + scriptPath + "\" \"" +
                               host_Master +"\" \""+ login_Master +"\" \"" +  pass_Master +"\" \"" +  port_Master +"\" \""  +
                               host_Nomade +"\" \""+ login_Nomade +"\" \"" +  pass_Nomade +"\" \"" +  port_Nomade + "\"";
        QProcess::startDetached (QString ("cmd /c start ") + scriptToDo ); //START.EXE /B /MIN leScriptAmasquer.CMD
             //QProcess::startDetached (QString ("START.EXE /B /MIN ") + scriptToDo ); //START.EXE /B /MIN leScriptAmasquer.CMD
    #endif
        //................. attendre la fin de l'execution du script .......................................................
        waitForEndScript( scriptPath + "/ScriptStatus.txt" );

        allAgendasReconnect(driver, baseToOpen, login_Nomade, pass_Nomade, host_Nomade, port_Nomade);
        G_pCApp->changeAllModuleConnectionParam(driver, baseToOpen, login_Nomade, pass_Nomade, host_Nomade, port_Nomade);
        G_pCApp->m_pCMoteurBase->BaseConnect(driver, baseToOpen, login_Nomade, pass_Nomade, host_Nomade, port_Nomade,0, G_pCApp->m_pCMoteurBase->GetDataBaseLabel());
        G_pCApp->CouCou(tr("Mode nomade activ\303\251\nconnect\303\251  : ") + G_pCApp->m_pCMoteurBase->GetDataBaseLabel() + QString("\ndriver : %1\nbase : %2\nuser : %3\nhost : %4").arg(driver, baseToOpen, login_Nomade, host_Nomade+":"+port_Nomade),"", 4000);
}

//--------------------------------- extractVarFromMysqlStatus -----------------------------------------------------------------------
QString C_Manager::extractVarFromMysqlStatus(const QString &repliSatus, QString var, int &pos)
{int end = -1;
//if (!var.endsWith(':')) var += ":";
if (pos==-1) pos = 0;
pos = repliSatus.indexOf(var, pos);
if (pos != -1)
   {pos += var.length();
    end  = repliSatus.indexOf("\n",pos);
    if (end != -1)
        {int deb = pos;
         pos     = end;
         return repliSatus.mid(deb,end-deb).remove("\r").trimmed();
        }
   }
pos = -1;
return QString::null;
}

//--------------------------------- action_fullSwitchReplication_triggered -----------------------------------------------------------------------
void C_Manager::action_fullSwitchReplication_triggered ()
{
QString err = "";
int nomadismeStateToSet = G_pCApp->m_IsNomadeActif; nomadismeStateToSet ^= 1;
if (nomadismeStateToSet)  //.......... Master vers Nomade (JE PARS)........................................................................
   {if (testConnection("Nomade",&err)==TRUE)
       {//reconnectToMaster(G_pCApp->m_IsGestionNomadisme);            // CZ 22.10.2010
        if (reconnectToMaster(G_pCApp->m_IsGestionNomadisme) == -1)    // CZ 22.10.2010
           return;                                                     // CZ 22.10.2010
       }
    else
       { QMessageBox::information( this, tr("CONNECTION AU SERVEUR NOMADE NON POSSIBLE"),
                                    tr ( " <b><u>ATTENTION</b></u> ! la connexion au serveur nomade <br>")+
                                    tr ( "est non possible.<br><u>Erreur :</u><br><pre>" ) + err + "</pre><br>" +
                                    tr(  "Veuillez v\303\251rifier vos branchements et param\303\250tres.") ,
                                    tr("Annu&ler"), 0, 0,
                                    0, 0 );
         return;
       }
   }
else                           //..........Nomade vers Master (J'ARRIVE) ........................................................................
   {QString err;
    if (testConnection("Master",&err)==TRUE)
       {reconnectToMaster(G_pCApp->m_IsGestionNomadisme);
       }
    else
       { QMessageBox::information( this, tr("CONNECTION AU SERVEUR MAITRE NON POSSIBLE"),
                                    tr ( " <b><u>ATTENTION</b></u> ! la connexion au serveur ma\303\256tre <br>")+
                                    tr ( "est non possible.<br><u>Erreur :</u><br><pre>" ) + err + "</pre><br>" +
                                    tr(  "Veuillez v\303\251rifier vos branchements et param\303\250tres.") ,
                                    tr("Annu&ler"), 0, 0,
                                    0, 0 );
         return;
       }
   }
//............. \303\240 ce stade le changement de mode a reussi ...................
//              donc en prendre note et l'enteriner
G_pCApp->m_IsNomadeActif = nomadismeStateToSet;
setAndSaveNomadeState (nomadismeStateToSet);
//.............. replacer l'interface sur le nouveau mode .......................
QStringList userList; G_pCApp->m_pCMoteurBase->GetUserList( userList );
if (userList.indexOf ( G_pCApp->m_User )== -1)
   {G_pCApp->m_User      = userList[0];
    G_pCApp->m_SignUser  = userList[0];
   }
G_pCApp->lireDroitsUtilisateurs();
initComboBoxAgendaUser();
deleteAllAgendas();
if (m_pC_Frm_UserList) m_pC_Frm_UserList->setDefaultParameter();
reinitAgendaOnUser(G_pCApp->m_User , G_pCApp->m_SignUser);
setInterfaceOnProfil(MODE_SELECTION_PATIENT);
Slot_pushButton_ReinitListe_clicked();
setTitle();
}

//---------------------------------------------- reconnectToNomade -----------------------------------------------------------------------
int C_Manager::reconnectToNomade(int gestionNomadisme)
{   int ret = FALSE;
   QString login_Master,   login_Nomade;
   QString host_Master,    host_Nomade;
   QString pass_Master,    pass_Nomade;
   QString port_Master,    port_Nomade;
   QString driver, baseToOpen;
   //............... recuperation des valeurs dans le .INI ...........
   QString param;
   CGestIni::Param_UpdateFromDisk(G_pCApp->m_PathAppli+"Manager.ini", param);
   CGestIni::Param_ReadParam( param, "Connexion", "Master",  &driver,  &baseToOpen, &login_Master,  &pass_Master,  &host_Master,  &port_Master);
   CGestIni::Param_ReadParam( param, "Connexion", "Nomade",  &driver,  &baseToOpen, &login_Nomade,  &pass_Nomade,  &host_Nomade,  &port_Nomade);

   QString scriptPath  = getScriptNomadePath();
   switch(gestionNomadisme)
   {case CMoteurBase::fullReplication:
       {QStringList paramList; CGestIni::Param_GetList(param, "Connexion", "listParam", paramList );
        setConnectParametres(scriptPath  + "/ScriptJePars.mod");
        putScriptWaitFlag(   scriptPath  + "/ScriptStatus.txt");
        #ifdef Q_WS_MAC
        #endif
        #ifdef Q_WS_WIN
           QString scriptMode = CGestIni::Param_ReadUniqueParam( param, "Connexion", "ScriptMode");
           if (scriptMode=="Spybase")
              {///////////////////// CZ A REVOIR 22.10.2010 //////////// debut
               QString  pathExe;
               QStringList argList;

               pathExe = QDir::cleanDirPath (QFileInfo (qApp->argv()[0]).dirPath (true) + "/../../Spybase/bin/Spybase.exe");
               argList << "JePars" ;
               QProcess::startDetached (pathExe, argList);
               ///////////////////// CZ A REVOIR 22.10.2010 ///////// fin

              }
           else
              {setBatchParametres(scriptPath+"/Bat_JePars.bat",paramList);
               QString scriptToDo  = QString("\"")+scriptPath  +QDir::separator()+"Bat_JePars.bat\" \"" + scriptPath + "\" \"" +
                                     host_Master +"\" \""+ login_Master +"\" \"" +  pass_Master +"\" \"" +  port_Master +"\" \""  +
                                     host_Nomade +"\" \""+ login_Nomade +"\" \"" +  pass_Nomade +"\" \"" +  port_Nomade + "\"";
               QProcess::startDetached (QString ("cmd /c start ") + scriptToDo ); //START.EXE /B /MIN leScriptAmasquer.CMD
              }
        #endif
        #ifdef Q_WS_X11
           QStringList argList;
           setBatchParametres(scriptPath+"/Bat_JePars.sh",paramList);
           QString scriptToDo  = QString("'")+scriptPath  + "/Bat_JePars.sh' '" + scriptPath + "' '" +
                                 host_Master +"' '"+ login_Master +"' '" +  pass_Master +"' '" +  port_Master +"' '"  +
                                 host_Nomade +"' '"+ login_Nomade +"' '" +  pass_Nomade +"' '" +  port_Nomade + "'";
           argList<<"777"<<scriptToDo;  QProcess::execute ("chmod", argList);// argList.clear();      argList<<scriptToDo;
           QProcess::startDetached (QString ("bash ") + scriptToDo ); //START.EXE /B /MIN leScriptAmasquer.CMD
           //QProcess::execute ("bash", argList);
        #endif
        //................. attendre la fin de l'execution du script ...............................
        waitForEndScript( scriptPath + "/ScriptStatus.txt" );
        //................. apres mise a jour se connecter au nomade .......................................................
        allAgendasReconnect(driver, baseToOpen, login_Nomade, pass_Nomade, host_Nomade, port_Nomade);
        G_pCApp->changeAllModuleConnectionParam(driver, baseToOpen, login_Nomade, pass_Nomade, host_Nomade, port_Nomade);
        G_pCApp->m_pCMoteurBase->BaseConnect(driver, baseToOpen, login_Nomade, pass_Nomade, host_Nomade, port_Nomade,0, G_pCApp->m_pCMoteurBase->GetDataBaseLabel());
        G_pCApp->CouCou(tr("Mode nomade activ\303\251\nconnect\303\251  : ") + G_pCApp->m_pCMoteurBase->GetDataBaseLabel() + QString("\ndriver : %1\nbase : %2\nuser : %3\nhost : %4").arg(driver, baseToOpen, login_Nomade, host_Nomade+":"+port_Nomade),"", 4000);
       } break;
    case CMoteurBase::progMasterUpdate:
       {/*
        ret = FALSE;
        waitForsyncEmulDemonResponse(synchroMethode + " Stop ");
        //.............. se reconnecter \303\240 la base nomade locale...........................................
        QString driver, baseToOpen, user, password, hostname, port;
        if (CGestIni::Param_ReadParam( G_pCApp->m_LocalParam, "Connexion", "Nomade", &driver, &baseToOpen, &user, &password, &hostname, &port) != QString::null )
           { G_pCApp->CouCou(tr("Param\303\250tres \n[Connexion]\nNomade = \nnon trouv\303\251s dans Manager.ini: "));
           }
        else if (G_pCApp->m_pCMoteurBase->BaseConnect(driver, baseToOpen, user, password, hostname, port,0, G_pCApp->m_pCMoteurBase->GetDataBaseLabel()) == 0)
           { G_pCApp->CouCou(tr("Echec de la reconnexion au serveur Nomade : \ndriver : %1\nbase : %2\nuser : %3\nhost : %4").arg(driver, baseToOpen, user, hostname+":"+port));
           }
        else
          { //.............. reinitialisation des tables de synchro (les vider) ...........................
            ret = TRUE;
            G_pCApp->m_pCMoteurBase->synchroInitTables();
            G_pCApp->CouCou(tr("Mode nomade activ\303\251\nconnect\303\251  : ") + G_pCApp->m_pCMoteurBase->GetDataBaseLabel() + QString("\ndriver : %1\nbase : %2\nuser : %3\nhost : %4").arg(driver, baseToOpen, user, hostname+":"+port),"", 4000);
          */
          } break;
      } //end switch(G_pCApp->m_IsGestionNomadisme)
    return ret;
}
//---------------------------------------------- reconnectToMaster -----------------------------------------------------------------------
int C_Manager::reconnectToMaster(int gestionNomadisme)
{    int ret = FALSE;
    QString login_Master,   login_Nomade;
    QString host_Master,    host_Nomade;
    QString pass_Master,    pass_Nomade;
    QString port_Master,    port_Nomade;
    QString driver, baseToOpen;
    //............... recuperation des valeurs dans le .INI ...........
    QString param;
    CGestIni::Param_UpdateFromDisk(G_pCApp->m_PathAppli+"Manager.ini", param);
    if (CGestIni::Param_ReadParam( param, "Connexion", "Nomade",  &driver,  &baseToOpen, &login_Nomade,  &pass_Nomade,  &host_Nomade,  &port_Nomade)!=QString::null)
       { G_pCApp->CouCou(tr("Param\303\250tres \n[Connexion]\nNomade = \nnon trouv\303\251s dans Manager.ini: "));
       }
    if (CGestIni::Param_ReadParam( param, "Connexion", "Master",  &driver,  &baseToOpen, &login_Master,  &pass_Master,  &host_Master,  &port_Master)!=QString::null)
       { G_pCApp->CouCou(tr("Param\303\250tres \n[Connexion]\nMaster = \nnon trouv\303\251s dans Manager.ini: "));
       }

    QString scriptPath  = getScriptNomadePath();
    switch(gestionNomadisme)
    {
     case CMoteurBase::fullReplication:
       {QStringList paramList; CGestIni::Param_GetList(param, "Connexion", "listParam", paramList );
        setConnectParametres( scriptPath + "/ScriptJeReviens.mod");
        putScriptWaitFlag(    scriptPath + "/ScriptStatus.txt");

        #ifdef Q_WS_MAC
        #endif
        #ifdef Q_WS_WIN
           QString scriptMode = CGestIni::Param_ReadUniqueParam( param, "Connexion", "ScriptMode");
           if (scriptMode=="Spybase")
              {///////////////////// CZ A REVOIR 22.10.2010 //////////// d?but
               QString  pathExe;
               QStringList argList;

               pathExe = QDir::cleanDirPath (QFileInfo (qApp->argv()[0]).dirPath (true) + "/../../Spybase/bin/Spybase.exe");
               argList << "JeReviens" ;
               QProcess::startDetached (pathExe, argList);
               ///////////////////// CZ A REVOIR 22.10.2010 ///////// fin
              }
           else
              { setBatchParametres(scriptPath+"/Bat_JeReviens.bat", paramList);
                QString scriptToDo  = QString("\"")+scriptPath  + QDir::separator() + "Bat_JeReviens.bat\" \""  + scriptPath + "\" \"" +
                                      host_Master +"\" \""+ login_Master + "\" \""  +  pass_Master +"\" \"" +  port_Master + "\" \"" +
                                      host_Nomade +"\" \""+ login_Nomade + "\" \""  +  pass_Nomade +"\" \"" +  port_Nomade + "\"";
                QProcess::startDetached (QString ("cmd /c start ") + scriptToDo );
              }
        #endif
        #ifdef Q_WS_X11
           QStringList argList;
           setBatchParametres(scriptPath+"/Bat_JeReviens.sh", paramList);
           QString scriptToDo  = QString("'")+scriptPath  + "/Bat_JeReviens.sh' '"  + scriptPath + "' '" +
                                 host_Master +"' '"+ login_Master +"' '" +  pass_Master +"' '" +  port_Master + "' '" +
                                 host_Nomade +"' '"+ login_Nomade +"' '" +  pass_Nomade +"' '" +  port_Nomade + "'";
           argList<<"777"<<scriptToDo;  QProcess::execute ("chmod", argList);// argList.clear();      argList<<scriptToDo;
           QProcess::startDetached (QString ("bash ") + scriptToDo ); //START.EXE /B /MIN leScriptAmasquer.CMD
        #endif
           //................. attendre la fin de l'execution du script ...............................
           /*-------------------------------CZ 22.10.2010-----------------------------------------------------
           waitForEndScript( scriptPath + "/ScriptStatus.txt" );
           //................. apres mise a jour se connecter au master .......................................................
           G_pCApp->changeAllModuleConnectionParam(driver, baseToOpen, login_Master, pass_Master, host_Master, port_Master);
           allAgendasReconnect(driver, baseToOpen, login_Master, pass_Master, host_Master, port_Master);
           G_pCApp->m_pCMoteurBase->BaseConnect(driver, baseToOpen, login_Master, pass_Master, host_Master, port_Master,0, G_pCApp->m_pCMoteurBase->GetDataBaseLabel());
           G_pCApp->CouCou(tr("Mode master activ\303\251\nconnect\303\251 \303\240 : ") + G_pCApp->m_pCMoteurBase->GetDataBaseLabel() + QString("\ndriver : %1\nbase : %2\nuser : %3\nhost : %4").arg(driver, baseToOpen, login_Master, host_Master+":"+port_Master),"", 4000);
           -------------------------------CZ 22.10.2010---------------------------------------------------*/
           /////////////////////// / CZ 22.10.2010 //////////// debut ///
           if (waitForEndScript( scriptPath + "/ScriptStatus.txt" ) == 0)
              {//................. apres mise a jour se connecter au master .......................................................
               G_pCApp->changeAllModuleConnectionParam(driver, baseToOpen, login_Master, pass_Master, host_Master, port_Master);
               allAgendasReconnect(driver, baseToOpen, login_Master, pass_Master, host_Master, port_Master);
               G_pCApp->m_pCMoteurBase->BaseConnect(driver, baseToOpen, login_Master, pass_Master, host_Master, port_Master,0, G_pCApp->m_pCMoteurBase->GetDataBaseLabel());
               G_pCApp->CouCou(tr("Mode master activ\303\251\nconnect\303\251 \303\240 : ") + G_pCApp->m_pCMoteurBase->GetDataBaseLabel() + QString("\ndriver : %1\nbase : %2\nuser : %3\nhost : %4").arg(driver, baseToOpen, login_Master, host_Master+":"+port_Master),"", 4000);
              }
           else
              {G_pCApp->CouCou(tr("Incident de connexion\nMode Nomade conserv\303\251.") );
               return -1;
              }
           /////////////////////// / CZ 22.10.2010 //////////// fin
       } break;
    case CMoteurBase::progMasterUpdate:
       {/*
        //......... se connecter au referentiel et le mettre \303\240 jour ...........................
        QString driver, baseToOpen, user, password, hostname, port;
        if (CGestIni::Param_ReadParam( G_pCApp->m_LocalParam, "Connexion", "Master", &driver, &baseToOpen, &user, &password, &hostname, &port) != QString::null )
           { G_pCApp->CouCou(tr("Param\303\250tres \n[Connexion]\nMaster = \nnon trouv\303\251s dans Manager.ini: "));
           }
        else if (G_pCApp->m_pCMoteurBase->synchroNomadeToMasterUpdate(driver, "MASTER_TUX", baseToOpen,  user,  password,  hostname, port ) == 0)
           {G_pCApp->CouCou(tr("Echec de la mise \303\240 jour\n et de la reconnexion au serveur ma\303\256tre \"MASTER_TUX\" : \ndriver : %1\nbase : %2\nuser : %3\nhost : %4").arg(driver, baseToOpen, user, hostname+":"+port));
           }
        else
           {ret = TRUE;
            G_pCApp->CouCou(tr("Mise \303\240 jour\net reconnexion au serveur ma\303\256tre \"MASTER_TUX\" r\303\251ussie :\ndriver : %1\nbase : %2\nuser : %3\nhost : %4").arg(driver, baseToOpen, user, hostname+":"+port),"", 4000);
           }
        //.............. effacer les tables de synchro ...........................
        G_pCApp->m_pCMoteurBase->synchroDropTables();
        //........... ecrire l'action \303\240 effectuer par le demon de synchro dans le Manager.ini ........................
        waitForsyncEmulDemonResponse(synchroMethode + " Start ");
        //................. apres mise \303\240 jour se connecter au master .......................................................
        G_pCApp->m_pCMoteurBase->BaseConnect(driver, baseToOpen, user, password, hostname, port,0, G_pCApp->m_pCMoteurBase->GetDataBaseLabel());
        G_pCApp->CouCou(tr("Mode master activ\303\251\nconnect\303\251 \303\240 : ") + G_pCApp->m_pCMoteurBase->GetDataBaseLabel() + QString("\ndriver : %1\nbase : %2\nuser : %3\nhost : %4").arg(driver, baseToOpen, user, hostname+":"+port),"", 4000);
        */
       }  break;
    case CMoteurBase::scriptOnly:
       {/*
        //.................se connecter au master .......................................................
        G_pCApp->m_pCMoteurBase->BaseConnect(driver, baseToOpen, login_Master, pass_Master, host_Master, port_Master,0, G_pCApp->m_pCMoteurBase->GetDataBaseLabel());
        //........... ecrire l'action \303\240 effectuer par le demon de synchro dans le Manager.ini ........................
        waitForsyncEmulDemonResponse(synchroMethode + " Start ");
        G_pCApp->CouCou(tr("Mode master activ\303\251\nconnect\303\251 \303\240 : ")     +
                        G_pCApp->m_pCMoteurBase->GetDataBaseLabel() +
                        QString("\ndriver : %1\nbase : %2\nuser : %3\nhost : %4").arg(driver, baseToOpen, login_Master, host_Master+":"+port_Master),"", 4000);
        */
       }
   }
    return ret;
}
//--------------------------------- setBatchParametres -----------------------------------------------------------------------
void C_Manager::setBatchParametres(const QString &scriptSqlIn, const QStringList &parmList)
{QString scriptStr;
QString path = QFileInfo(scriptSqlIn).path()+"/"+QFileInfo(scriptSqlIn).baseName()+".mod";
CGestIni::Param_UpdateFromDisk(path, scriptStr);
for (int i = 0; i < parmList.size(); ++i)
    {QString param =  parmList[i];
     if (param.left(6)=="$toAbs")
        {if ( QDir(param).isRelative()) param.prepend(G_pCApp->m_PathAppli);
         param = QDir::cleanPath(param); param.replace("/", QDir::separator ());
        }
     scriptStr.replace(QString("{{param ") + QString::number(i)+"}}",   param);
    }
CGestIni::Param_UpdateToDisk(scriptSqlIn, scriptStr);
}

//--------------------------------- setConnectParametres -----------------------------------------------------------------------
/*
CHANGE MASTER TO MASTER_HOST='{{reverse host}}',
MASTER_PORT={{reverse port}},
MASTER_USER='{{reverse user}}',
MASTER_PASSWORD='{{reverse pass}}',
MASTER_LOG_FILE='{{reverse log bin}}',

   Gestion nomadisme = active
   nomadisme   = actif
   Master      = QMYSQL3 , DrTuxTest , slave402  ,aixact  , WXP-MAXDATA    , 3306, LogBin
   Master      = QMYSQL3 , DrTuxTest , root      ,        , localhost      , 3306, LogBin
   Nomade      = QMYSQL3 , DrTuxTest , server401 , aixact , localhost      , 3306, LogBin
   Reverse     = QMYSQL3 , DrTuxTest , server401 , aixact , 192.168.69.101 , 3306, LogBinNomade.000001
   Parametres  = QMYSQL3 , DrTuxTest , root      ,        , localhost      , 3306, LogBin
*/
void C_Manager::setConnectParametres(const QString &scriptSqlIn,
                                    const QString master_Host         /*=""*/,
                                    const QString master_User         /*=""*/,
                                    const QString master_Port         /*=""*/,
                                    const QString masterKey_in        /*=""*/,
                                    const QString master_Log_File     /*=""*/,
                                    const QString read_Master_Log_Pos /*=""*/
                                   )
{QString login_Master,   login_masterSrcN,   login_masterSrcR,  login_Nomade,   login_Reverse;
QString host_Master,    host_masterSrcN,    host_masterSrcR,    host_Nomade,    host_Reverse;
QString pass_Master,    pass_masterSrcN,    pass_masterSrcR,    pass_Nomade,    pass_Reverse;
QString port_Master,    port_masterSrcN,    port_masterSrcR,    port_Nomade,    port_Reverse;
QString logBin_Master,  logBin_masterSrcN,  logBin_masterSrcR,  logBin_Nomade,  logBin_Reverse;
QString log_Pos_Master, log_Pos_masterSrcN, log_Pos_masterSrcR, log_Pos_Nomade, log_Pos_Reverse;
QString dumy;
QString masterKey = masterKey_in;
if (masterKey[0]=='$') masterKey = CGestIni::PassWordDecode(masterKey.remove('$'));
//............... recuperation des valeurs dans le .INI ...........
QString param;
CGestIni::Param_UpdateFromDisk(G_pCApp->m_PathAppli+"Manager.ini", param);
CGestIni::Param_ReadParam( param, "Connexion", "Master",     &dumy,    &dumy,       &login_Master,    &pass_Master,        &host_Master,      &port_Master,      &logBin_Master,     &log_Pos_Master);
CGestIni::Param_ReadParam( param, "Connexion", "Nomade",     &dumy,    &dumy,       &login_Nomade,    &pass_Nomade,        &host_Nomade,      &port_Nomade,      &logBin_Nomade,     &log_Pos_Nomade);
CGestIni::Param_ReadParam( param, "Connexion", "Reverse",    &dumy,    &dumy,       &login_Reverse,   &pass_Reverse,       &host_Reverse,     &port_Reverse,     &logBin_Reverse,    &log_Pos_Reverse);
CGestIni::Param_ReadParam( param, "Connexion", "MasterSrcN", &dumy,    &dumy,       &login_masterSrcN, &pass_masterSrcN,   &host_masterSrcN,  &port_masterSrcN,  &logBin_masterSrcN, &log_Pos_masterSrcN);
CGestIni::Param_ReadParam( param, "Connexion", "MasterSrcR", &dumy,    &dumy,       &login_masterSrcR, &pass_masterSrcR,   &host_masterSrcR,  &port_masterSrcR,  &logBin_masterSrcR, &log_Pos_masterSrcR);

//............... remplacement des tags et tokens .................
QString scriptStr;
CGestIni::Param_UpdateFromDisk(scriptSqlIn, scriptStr);
scriptStr.replace("{{master user}}",      login_Master);
scriptStr.replace("{{masterSrcN user}}",  login_masterSrcN);
scriptStr.replace("{{masterSrcR user}}",  login_masterSrcR);
scriptStr.replace("{{nomade user}}",      login_Nomade);
scriptStr.replace("{{reverse user}}",     login_Reverse);

scriptStr.replace("{{master host}}",      host_Master);
scriptStr.replace("{{masterSrcN host}}",  host_masterSrcN);
scriptStr.replace("{{masterSrcR host}}",  host_masterSrcR);
scriptStr.replace("{{nomade host}}",      host_Nomade);
scriptStr.replace("{{reverse host}}",     host_Reverse);

scriptStr.replace("{{master pass}}",      pass_Master);
scriptStr.replace("{{masterSrcN pass}}",  pass_masterSrcN);
scriptStr.replace("{{masterSrcR pass}}",  pass_masterSrcR);
scriptStr.replace("{{nomade pass}}",      pass_Nomade);
scriptStr.replace("{{reverse pass}}",     pass_Reverse);

scriptStr.replace("{{master port}}",      port_Master);
scriptStr.replace("{{masterSrcN port}}",  port_masterSrcN);
scriptStr.replace("{{masterSrcR port}}",  port_masterSrcR);
scriptStr.replace("{{nomade port}}",      port_Nomade);
scriptStr.replace("{{reverse port}}",     port_Reverse);

scriptStr.replace("{{master logbin}}",       logBin_Master);
scriptStr.replace("{{masterSrcN logbin}}",   logBin_masterSrcN);
scriptStr.replace("{{masterSrcR logbin}}",   logBin_masterSrcR);
scriptStr.replace("{{nomade logbin}}",       logBin_Nomade);
scriptStr.replace("{{reverse logbin}}",      logBin_Reverse);

scriptStr.replace("{{master log_Pos}}",      log_Pos_Master);
scriptStr.replace("{{masterSrcN log_Pos}}",  log_Pos_masterSrcN);
scriptStr.replace("{{masterSrcR log_Pos}}",  log_Pos_masterSrcR);
scriptStr.replace("{{nomade log_Pos}}",      log_Pos_Nomade);
scriptStr.replace("{{reverse log_Pos}}",     log_Pos_Reverse);

//................... infos lues dans les fichers status ..................
scriptStr.replace("{{Master_Host}}",         master_Host);
scriptStr.replace("{{Master_User}}",         master_User);
scriptStr.replace("{{Master_Port}}",         master_Port);
scriptStr.replace("{{MasterKey}}",           masterKey);
scriptStr.replace("{{Master_Log_File}}",     master_Log_File);
scriptStr.replace("{{Read_Master_Log_Pos}}", read_Master_Log_Pos);

QString scriptSqlOut = QFileInfo(scriptSqlIn).path()+"/"+QFileInfo(scriptSqlIn).baseName()+".txt";
CGestIni::Param_UpdateToDisk(scriptSqlOut, scriptStr);
}

//--------------------------------- waitForsyncEmulDemonResponse -----------------------------------------------------------------------
void C_Manager::waitForsyncEmulDemonResponse(const QString &action)
{        QFileInfo qfi(qApp->argv()[0]);
        //........... recuperer le syncEmul.ini ........................
        QString pathSyncIni = CGestIni::Construct_Name_File_Ini("syncEmul",   qfi.dirPath (true), "");
        QString syncParam;
        CGestIni::Param_UpdateFromDisk(pathSyncIni, syncParam);
        //........... ecrire l'action \303\240 effectuer par le demon de synchro dans le Manager.ini ........................
        CGestIni::Param_WriteParam(&syncParam,"Connexion", "slaveSatus", action);
        CGestIni::Param_UpdateToDisk(pathSyncIni,syncParam);

        //........... attendre quel le demon de synchro ait fini son travail .............................................
        //            slaveSatus == "synchro Terminated" dans Manager.ini
        int         ok = 0;
        while (ok<2000)
           {SLEEP(1);
            CGestIni::Param_UpdateFromDisk(pathSyncIni,syncParam);
            QString status = CGestIni::Param_ReadUniqueParam( syncParam, "Connexion", "slaveSatus");
            if (status=="synchro Terminated") break;
            ++ok;
           }
}
//--------------------------------- putScriptWaitFlag -----------------------------------------------------------------------
void C_Manager::putScriptWaitFlag(const QString &scriptStatusFile)
{        //........... recuperer le syncEmul.ini ........................
        QString syncParam = "started";
        CGestIni::Param_UpdateToDisk(scriptStatusFile,   syncParam);
}
//--------------------------------- waitForEndScript -----------------------------------------------------------------------
int C_Manager::waitForEndScript(const QString &scriptStatusFile)
{        //........... recuperer le syncEmul.ini ........................
        QString syncParam;
        //........... attendre que le script ait fini son travail .............................................
        int  ok = 0;
        while (ok<2000)
           {SLEEP(1);
            CGestIni::Param_UpdateFromDisk(scriptStatusFile, syncParam);
            //if (syncParam.indexOf("terminated") != -1) break;            // CZ 22-10-2010
            if (syncParam.indexOf("terminated") != -1) return( 0);         // CZ 22-10-2010
            if (syncParam.indexOf("Incident") != -1)   return(-1);         // CZ 22-10-2010
            ++ok;
           }
        return -1;                                                         // RS 16-02-2011
}

///////////////////////////////////////// LANCEMENT DE DR TUX ////////////////////////////////////////
//--------------------------------- Slot_LauchPatient -----------------------------------------------------------------------
//  ACTION : ce slot est appel\303\251 lors d'un clic sur le bouton de lancement de dossier d'un rendez vous
void C_Manager::Slot_LauchPatient(const QString &guid, C_RendezVous *pC_RendezVous)
{
if (guid.length()== 0)
   { if  ( pC_RendezVous && pC_RendezVous->m_Nom.length() && pC_RendezVous->m_Prenom.length())
         { m_pGUI->lineEditAutoLocator->setText(pC_RendezVous->m_Nom+";"+pC_RendezVous->m_Prenom);
           if (m_pGUI->listView_Patient->topLevelItemCount()==1)
              {
               QTreeWidgetItemIterator it(m_pGUI->listView_Patient);
               QTreeWidgetItem *pQListViewItem = 0;
               while (*it) { pQListViewItem = (*it); if (pQListViewItem != 0) break;
                             ++it;
                           }
               if (pQListViewItem)
                  {pQListViewItem->setSelected(TRUE);      // pour mettre \303\240 jour la fiche identite
                   int ret = QMessageBox::information( this, tr("Lancer un dossier"),
                                               tr( "Un dossier existe pour ce nom : <br><b>«" + pC_RendezVous->m_Nom + "  " + pC_RendezVous->m_Prenom +
                                                   "»</b>" +
                                                   "<br>faut-il lancer ce dossier ?"
                                                  ) ,
                                               tr("&Lancer"), tr("&Annuler"), 0,
                                               1, 1 );
                   if (ret==0)
                      { Slot_LauchPatient(pQListViewItem->text(3));
                      }
                  } //if (pQListViewItem)
              }
           else if (m_pGUI->listView_Patient->topLevelItemCount()==0)
              {int ret = QMessageBox::information( this, tr("Cr\303\251er un dossier"),
                                               tr( "Il n'existe pas de dossier avec ce nom : <br><b>«" + pC_RendezVous->m_Nom + "  " + pC_RendezVous->m_Prenom +
                                                   "»</b>" +
                                                   "<br>faut-il en cr\303\251er un ?"
                                                  ) ,
                                               tr("&Cr\303\251er un dossier"), tr("&Annuler"), 0,
                                               1, 1 );
              if (ret==0)
                 {Slot_pushButtonNew_clicked();
                  m_pGUI->lineEdit_NomDossier->setText(pC_RendezVous->m_Nom);
                  m_pGUI->lineEdit_PrenomDossier->setText(pC_RendezVous->m_Prenom);
                  m_pGUI->lineEdit_Tel1->setText(pC_RendezVous->m_Tel);
                 }
              }
         }
    else
         {int ret = QMessageBox::information( this, tr("Cr\303\251er un dossier"),
                                              tr( "Cr\303\251er un nouveau dossier ?"  ) ,
                                              tr("&Cr\303\251er un dossier"), tr("&Annuler"), 0,
                                              1, 1 );
             if (ret==0)
                {Slot_pushButtonNew_clicked();
                 if (pC_RendezVous)
                    {m_pGUI->lineEdit_NomDossier->setText(pC_RendezVous->m_Nom);
                     m_pGUI->lineEdit_PrenomDossier->setText(pC_RendezVous->m_Prenom);
                     m_pGUI->lineEdit_Tel1->setText(pC_RendezVous->m_Tel);
                    }
                }
         }
   }
else      //if (guid.length()== 0)
   {Slot_LauchPatient(guid);
   }
}

//--------------------------------- Slot_LauchPatient -----------------------------------------------------------------------
void C_Manager::Slot_LauchPatient(const QString &guid)
{if (guid.length()==0) return;
//........... si pr\303\251sent dans la liste patient...............
//            lancer le dossier
if (guid == G_pCApp->m_LastGUID)
   {Slot_pushButtonAcceder_Clicked();
    return;
   }
//........... si pas pr\303\251sent dans la liste patient...............
//            requeter pour recuperer les infos
if  (m_pCMoteurBase->OpenBase()==0) return;
QString requete  = "SELECT ";
        requete += m_pCMoteurBase->m_DOSS_INDEX_NOM                     + ", "  +     // 0
                   m_pCMoteurBase->m_DOSS_INDEX_PRENOM                  + ", "  +     // 1
                   m_pCMoteurBase->m_DOSS_INDEX_PRIM_KEY                + "  "  +     // 2
                   " FROM "   + m_pCMoteurBase->m_DOSS_INDEX_TBL_NAME   + " WHERE " +
                                m_pCMoteurBase->m_DOSS_INDEX_GUID       + " = '"    + guid + "' ";
 QString nom,prenom,pk;   // on va \303\240 la peche de ça
 QSqlQuery query(requete , m_pCMoteurBase->getDatabase() );
 //.................. si la requ\303\250te a un resultat ..............................................
 if (query.isActive())
    {while (query.next())
        { nom    =  m_pCMoteurBase->Utf8_Query(query, 0 );   // Nom
          prenom =  m_pCMoteurBase->Utf8_Query(query, 1 );   // Prenom
          pk     =  m_pCMoteurBase->Utf8_Query(query, 2 );   // PK
        } // while (query.next())
    } //endif (query.isActive())
 m_pCMoteurBase->CloseBase();
 //................. si infos retrouv\303\251es ......................................................
 if (pk.length())
    {accederDossier   (nom,         // Nom assur\303\251
                       prenom,      // Prenom assur\303\251
                       pk,          // numero PrimKey
                       guid,        // GUID dossier
                       G_pCApp->m_User,            // login de l'utilisateur en cours
                       G_pCApp->m_SignUser);       // login de l'utilisateur signataire en cours
    }
}

//--------------------------------- Slot_pushButtonAcceder_Clicked -----------------------------------------------------------------------
void C_Manager::Slot_pushButtonAcceder_Clicked()
{   accederDossier(G_pCApp->m_LastNom,         // Nom assur\303\251
                  G_pCApp->m_LastPrenom,      // Prenom assur\303\251
                  G_pCApp->m_LastPK,          // numero PrimKey
                  G_pCApp->m_LastGUID,        // GUID dossier
                  G_pCApp->m_User,            // login de l'utilisateur en cours
                  G_pCApp->m_SignUser);       // login de l'utilisateur signataire en cours

   //................. Patient List Mode = clear .........................................
   QString val;
   if (CGestIni::Param_ReadParam(G_pCApp->m_LocalParam, "Derniere Session", "Patient List Mode", &val)==QString::null && (val.at(0).lower() == 'c'))   // = zero si pas d'erreur
      { m_pGUI->lineEditAutoLocator->clear();
        m_pGUI->listView_Patient->clear();
        clearIdentFields();
        m_pGUI->lineEditAutoLocator->setFocus();
      }
   else
      { m_pGUI->lineEditAutoLocator->setFocus();
      }
}

//--------------------------------- accederDossier -----------------------------------------------------------------------------
void C_Manager::accederDossier( QString nom,  QString prenom, const QString &primKey, const QString &guid, const QString &user, const QString &sign_user)
{  if (G_pCApp->IsThisDroitExist( "idg")==0)
     {G_pCApp->CouCou(tr( "Vos droits sont insuffisants pour lancer un dossier"));
      return;
     }
   if (getInterfaceMode() != MODE_CREATION_PATIENT && m_pGUI->pushButtonSavModif->isEnabled() )  //Slot_pushButtonSavModif();
   /*
   if (pushButtonSavModif->isEnabled() && G_pCApp->IsThisDroitExist(G_pCApp->m_Droits, "idc") && (!pushButton_QuitterMultiCritere->isShown()) )
      {int ret   = QMessageBox::warning ( this, tr("Enregistrer les modifications :"),
                                    tr( "<u><b>ATTENTION :</u></b><br>&nbsp;&nbsp;&nbsp;le dossier :<br>&nbsp;&nbsp; <b><font color=\"#e80d0d\">") +
                                    G_pCApp->m_LastNom  + " " + G_pCApp->m_LastPrenom  +
                                    tr(  "</font></b>&nbsp;&nbsp; a \303\251t\303\251 modifi\303\251, faut il enregistrer les modifications avant de l'ouvrir"),
                                    tr("&Modifier"), tr("Annu&ler"), 0,
                                    1, 1
                                    );
      if (ret==0) */
         {Slot_pushButtonSavModif();
          nom       = G_pCApp->m_LastNom;
          prenom    = G_pCApp->m_LastPrenom;
         }
   //   }
   // pDrTux = new DrTux(argv[1],       // utilisateur
   //                    argv[2],       // num_doss (GUID dossier)
   //                    argv[3],       // ID_Doss (fchgnrl2002_nom_prenom WHERE ID_PrimKey = ID_Doss)
   //                    argv[4],       // nom dossier
   //                    argv[5]        // prenom dossier
   //                   );
   QString usedBy, value;
   if ( m_pCMoteurBase->IsDossierVerrouille( guid, usedBy ))
      {CGestIni::Param_ReadParam(G_pCApp->m_LocalParam, "Gestion des dossiers", "Acces Concurrent", &value);   // path editeur de texte non d\303\251fini
       if (value.lower().left(3) == tr("exc"))
          {QMessageBox::information( this, tr(  "DOSSIER NON ACCESSIBLE"),
                                     tr(  " <b><b><u>ATTENTION</b></u> ! Ce dossier <font color=\"#e80d0d\"><b>")          + nom     + " " + prenom  +
                                     tr(  "</b></font> est actuellement ouvert sur le poste suivant : <b>" )   + usedBy  +
                                     tr(  "</b>.<br> Son acc\303\250s est non possible sur le poste actuel.<br>"
                                          "Veuillez le faire fermer sur le poste qui l'utilise actuellement avant d'y acc\303\251der sur ce poste.") ,
                                     tr("Annu&ler"),0 , 0,
                                     1, 1 );
           return;
          }
       //.............. si l'utilisateur du dossier est le m\303\252me que celui du poste de travail...................................
       //               alors le dossier est d\303\251j\303\240 lanc\303\251 sur le poste de travail local
       //               on le lance et alors il se met en premier plan (car g\303\250re comme cela l'instance unique)
       // sinon on demande si l'on veut lancer le dossier pr\303\251sent sur un autre poste avec avertisement des
       // cons\303\251quences
       if (m_pCMoteurBase->m_UserName + "@" + m_pCMoteurBase->m_HostName != usedBy &&
           alertVerrou(usedBy, nom, prenom)!=0)
          {return;
          }
      }
   //................. met \303\240 jour le formulaire identite sur le patient ................................

   if (getInterfaceMode() != MODE_CREATION_PATIENT) DataToFormulaire(primKey, nom, prenom);    //==0) return;   // met \303\240 jour  G_pCApp->m_LastNom, G_pCApp->m_LastPrenom, G_pCApp->m_LastGUID, G_pCApp->m_LastPK

   #ifdef Q_WS_WIN
      QString pathExe  = CGestIni::Construct_Name_Exe("drtux",QFileInfo (qApp->argv()[0]).dirPath (true));
   #else
      QString pathExe  = CGestIni::Construct_Name_Exe("Manager",QFileInfo (qApp->argv()[0]).dirPath (true), "guinch");
   #endif
   QStringList argList;
   //......................... completer les arguments de lancement.........................................
   argList <<( user );
   argList <<( sign_user );
   argList <<( guid );
   argList <<( primKey );
   argList <<( nom.replace("'","~@~") );
   argList <<( prenom.replace("'","~@~") );

   QString str = CGestIni::Construct_Name_File_Ini("Manager",QFileInfo (qApp->argv()[0]).dirPath (true), "");
   argList <<(str );  // fichier ini

   str = CGestIni::Construct_Name_File_Ini("Manager",QFileInfo (qApp->argv()[0]).dirPath (true), "DataBase.cfg");
   argList <<( str ); // fichier cfgBase

   setVerrou(TRUE);
   //QProcess *myProcess = new QProcess(0);
   //myProcess->start(pathExe, argList);
   QProcess::startDetached (pathExe, argList);
    // QProcess   *proc;
   //proc.start(pathExe, argList);
   //if (!proc.waitForStarted(6000))   G_pCApp->CouCou(tr( "Le process : %1 n'a pu \303\252tre lanc\303\251").arg(pathExe));
   //  QProcess   proc;
   //  proc.start(pathExe, argList);
     //SLEEP(100);
   //  QApplication::processEvents ( QEventLoop::WaitForMore );
   //  int i = 100;
   //  while (proc.state()==QProcess::Running && --i )
  //        { //SLEEP(100);
  //          QApplication::processEvents ( QEventLoop::WaitForMore );
  //        }
}

//--------------------------------------- alertVerrou -------------------------------------------------------------------------------
int  C_Manager::alertVerrou(const QString &userBy, const QString &dossNom, const QString &dossPrenom)
{   QString value;
   CGestIni::Param_ReadParam(G_pCApp->m_LocalParam, "Gestion des dossiers", "Acces Concurrent", &value);   // path editeur de texte non d\303\251fini
   if (value.lower() == tr("non possible"))
   {  QMessageBox::information( this, tr(  "OUVERTURE CONFLICTUELLE"),
                                tr(  " <b><u>ATTENTION</b></u> ! Ce dossier <font color=\"#e80d0d\"><b>")          + dossNom     + " " + dossPrenom  +
                                tr(  "</b></font> est d\303\251j\303\240 ouvert sur le poste suivant : <b>" )   + userBy  +
                                tr(  "</b><br> Son acc\303\250s n'est possible qu'en lecture seulement,<br>"
                                     "il se mettra automatiquement en mode \303\251criture<br>"
                                     "d\303\251s qu'il sera disponible sur votre poste") ,
                                //"&nbsp;&nbsp;&nbsp;&nbsp; ° <b>Quitter pour <u>Annuler</u></b> l'op\303\251ration en cours" ) ,
                                tr("Annu&ler"),0 , 0,
                                1, 1 );
       return 1;
   }
   return QMessageBox::information( this, tr("OUVERTURE CONFLICTUELLE"),
                                    tr ( " <b><u>ATTENTION</b></u> ! Ce dossier <b>")          + dossNom     + " " + dossPrenom  +
                                    tr(  "</b> est d\303\251j\303\240 ouvert sur le poste suivant : <b>" )   + userBy  +
                                    tr(  "</b><br> Faut-il tenter tout de m\303\252me l'ouverture ?<br>") ,
                                    //"&nbsp;&nbsp;&nbsp;&nbsp; ° <b>Quitter pour <u>Annuler</u></b> l'op\303\251ration en cours" ) ,   1111b0
                                    tr("&Ouvrir"), tr("Annu&ler"), 0,
                                    1, 1 );
}

///////////////////////////////////////// LECTURE VITALE ////////////////////////////////////////
//--------------------------------- Slot_listView_Vitale_DoubleClicked -----------------------------------------------------------------------
void C_Manager::Slot_listView_Vitale_DoubleClicked( QTreeWidgetItem *pQTreeWidgetItem , int)
{
#ifdef SESAM_VERSION
if (pQTreeWidgetItem==0) return;
Slot_listView_VitaleSelectionChanged (); // se repositionner sur cet ayant droit au cas ou liste modifi\303\251e
//QTreeWidgetItem *pQListViewItem = getSelectedListViewItem(m_pGUI->listView_Vitale);
//if (pQListViewItem==0) return;

int nb = m_pGUI->listView_Patient->topLevelItemCount();
if (pQTreeWidgetItem->text(6).length()==0 /*nb==0*/)           // pas de patient trouv\303\251 pour cette carte vitale alors on le propose en cr\303\251ation
   {if (getInterfaceMode() != MODE_CREATION_PATIENT)
       {   Slot_NewDossWithoutErase(); // se Mettre en mode creation
       }
    // Placer les donn\303\251es SV
    setInterfaceOnVitaleData(  G_pCApp->m_pVitale,                  // donn\303\251es carte vitale
                               pQTreeWidgetItem->text(8).toInt()    // occurence
                            );
   }
else if (nb==1)      // un seul patient trouv\303\251 pour cette carte vitale alors on le lance
   { //Cz_Pyxvital     si on ne gÃ¨re pas le dossier Patient on lance directement la FSE
    if (m_Facture_Seule == "oui")
        Slot_pushButton_FSE();
    else
       Slot_pushButtonAcceder_Clicked();
   }
#endif
}

//--------------------------------- Slot_listView_Vitale_Clicked -----------------------------------------------------------------------
void C_Manager::Slot_listView_Vitale_Clicked( QTreeWidgetItem * pQListViewItem, int /* column*/  )
{
   #ifdef SESAM_VERSION
   Slot_listView_VitaleSelectionChanged ();
           /*
   if (pQListViewItem==0) return;
   C_Vitale       *pcVitale =  G_pCApp->m_pVitale;
   if (pcVitale && m_pGUI->lineEdit_NumSecu->text().remove(' ')==pcVitale->GetMember(8,  101, 1))
      {
       QString debDroits = pQListViewItem->text(9);
       QString finDroits = pQListViewItem->text(10);
       m_pGUI->lineEdit_DroitsDateDeb->setText(debDroits.mid(6,2)+"/"+debDroits.mid(4,2)+"/"+debDroits.mid(0,4));
       m_pGUI->lineEdit_DroitsDateFin->setText(finDroits.mid(6,2)+"/"+finDroits.mid(4,2)+"/"+finDroits.mid(0,4));
       m_pGUI->lineEdit_CAS->setText(pQListViewItem->text(11));
      }
   else
      {m_pGUI->lineEdit_DroitsDateDeb->setText("");
       m_pGUI->lineEdit_DroitsDateFin->setText("");
       m_pGUI->lineEdit_CAS->setText("");
      }

     //Slot_listView_VitaleSelectionChanged ();
      */
   #endif
}

//--------------------------------- Slot_listView_VitaleSelectionChanged -----------------------------------------------------------------------
void C_Manager::Slot_listView_VitaleSelectionChanged ()
{
#ifdef SESAM_VERSION
QTreeWidget         *pQlistView = m_pGUI->listView_Patient;
QTreeWidgetItem *pQListViewItem = getSelectedListViewItem(m_pGUI->listView_Vitale);
if (pQListViewItem==0) return;
C_Vitale *pcVitale = G_pCApp->m_pVitale;
int occurence      = pQListViewItem->text(8).toInt();

//................. determine si le nom prenom entrent dans la comparaison ..........................
QString localParam = "";   CGestIni::Param_UpdateFromDisk(G_pCApp->m_PathIni, localParam);
bool matchOnNom    = (CGestIni::Param_ReadUniqueParam(localParam, "Sesam-Vitale", "Compare_Nom")    == "ok");
bool matchOnPrenom = (CGestIni::Param_ReadUniqueParam(localParam, "Sesam-Vitale", "Compare_Prenom") == "ok");

//............ formater qq trucs pour les rendre compatble avec le match SQL ....................
QString dnss      = pQListViewItem->text(2).left(8);             //  199306010000   -->  19930601
        dnss      = dnss.insert(4,'-');                          //  19930601       -->  1993-0601
        dnss      = dnss.insert(7,'-');                          //  1993-0601      -->  1993-06-01
        dnss     += " 00:00:00";                                 //  1993-0601      -->  1993-06-01 00:00:00
QString numSecu   = pQListViewItem->text(3);
        numSecu  += CMoteurBase::ComputeClef_Secu(numSecu);
QString rangGem   = pQListViewItem->text(4);
QString debDroits = pQListViewItem->text(9);
QString finDroits = pQListViewItem->text(10);
//............. remplir la zone des droits quelque soit le numero de secu CV-GUI .............................
 setInterfaceOnDroitsSociaux(pcVitale, occurence, 1);
//QString    cas = pcVitale->GetMember(10,  101, 1)+pcVitale->GetMember(11,  101, 1)+pcVitale->GetMember(12,  101, 1).left(3);


//m_pGUI->lineEdit_CAS->setText(pQListViewItem->text(11));
//............ determine si le nom prenom entrent dans la comparaison .....................
QString     nom    = pQListViewItem->text(0);
QString     prenom = pQListViewItem->text(1);
if (QDate::isValid ( dnss.mid(0,4).toInt(), dnss.mid(5,2).toInt(), dnss.mid(8,2).toInt() ) )  // si date de naiss invalide on est oblig\303\251 de se servir du nom prenom
   { if (!matchOnNom)     nom    = "";
     if (!matchOnPrenom)  prenom = "";
   }
if (rangGem.length()==1) rangGem = rangGem.prepend("0");
//.................... lors de cet appel la listview est \303\240 rebattir .....................
//                     et donc appel \303\240 SelectionChanged
//                     donc modification de L'identit\303\251 globale
//                     donc appel \303\240 sauvegarde avant
if (getInterfaceMode()==MODE_SELECTION_PATIENT && identIsModified() && G_pCApp->isCurrentIdentiteValid() && G_pCApp->IsThisDroitExist(G_pCApp->m_Droits, "idc") )
   {savModifications(G_pCApp->identitePatientNom(), G_pCApp->identitePatientPrenom(), G_pCApp->identitePatientPk());
   }

int nb = G_pCApp->m_pCMoteurBase->GetPatientListFromNomPrenomSecuDtNssGeme( pQlistView,
                                                                            nom,                         // nom
                                                                            prenom,                      // prenom
                                                                            dnss,                        // date Nss // doit etre 1993-06-01 00:00:00
                                                                            numSecu,                     // num secu // 160196296519557
                                                                            rangGem,                     // rang gemellaire
                                                                            pQListViewItem->text(5),     // qualite d'ayant droit
                                                                            "",      //  adresse,
                                                                            "",      //  codePost,
                                                                            "",      //  ville,
                                                                            "",      //  sexe,
                                                                            "",      //  profession,
                                                                            "",      //  nomJfille
                                                                            "",      //  nomAss,
                                                                            "",      //  prenomAss,
                                                                            "",      //  tel1,
                                                                            "",      //  tel2,
                                                                            "",      //  tel3,
                                                                            "",      //  email,
                                                                            " = ",   //  egal_like  " = ",
                                                                            m_pGUI->textLabel_StateList
                                                                          );
// if (nb==0)                // pas de patient trouv\303\251 pour cette carte vitale
// else if (nb==1)          // un seul patient trouv\303\251 pour cette carte vitale alors on efface l'\303\251ventuel patient en cours de cr\303\251ation
switch(getInterfaceMode())
      {case MODE_SELECTION_PATIENT:
            {if (nb==1)                    // un seul patient trouv\303\251 pour cette carte vitale alors on efface l'\303\251ventuel patient en cours de cr\303\251ation
                {QTreeWidgetItem* pQTreeWidgetItem = pQlistView->topLevelItem(0) ;// il n'y en a qu'un 'if (nb==1)' donc le premier est le bon
                 if (pQTreeWidgetItem) pQTreeWidgetItem->setSelected(TRUE);
                }
             else //if (nb==0)                // pas de patient trouv\303\251 pour cette carte vitale ou plus d'un
                {setIdentiteDisabled();
                 clearIdentFields();
                 QString dtnss = pQListViewItem->text(2).left(8);
                 if (dtnss.length()) listPatientsByDateNss(dtnss);
                }
             setInterfaceOnDroitsSociaux(pcVitale, occurence);
            }break;
       case MODE_CREATION_PATIENT:
            {/*
             int ret   = QMessageBox::warning ( this, tr("S\303\251lection de la liste de la carte vitale :"),
                                    tr( "<u><b>ATTENTION :</u></b><br>&nbsp;&nbsp;&nbsp;voulez utiliser les donn\303\251es de l'ayant droit suivant :<br>&nbsp;&nbsp; <b><font color=\"#e80d0d\">") +
                                    pQListViewItem->text(0)  + " " + pQListViewItem->text(1)  +
                                    tr(  "</font></b><br>&nbsp;&nbsp; pour remplir les donn\303\251es du patient en cours de cr\303\251ation ?"),
                                    tr("&Utiliser"), tr("Annu&ler"), 0,
                                    0, 1
                                    );
             if (ret==0)
                {setInterfaceOnVitaleData(G_pCApp->m_pVitale,                        // donn\303\251es carte vitale
                                          pQListViewItem->text(8).toInt()            // occurence de l'ayant droit
                                         );
                }
              */
              //setInterfaceOnDroitsSociaux(pcVitale);
             }break;
       case MODE_MULTICRITERE:
            {
            }break;
       } //endswitch(getInterfaceMode())
#endif
}

//------------------------------------------------------- compareListVitaleWithBase --------------------------------------------------
//    met \303\240 jour la listview vitale sur patient trouv\303\251 dans la base des patient ou pas
void  C_Manager:: compareListVitaleWithBase()
{
#ifdef SESAM_VERSION
       //................. determine si le nom prenom entrent dans la comparaison ..........................
       QString localParam = "";   CGestIni::Param_UpdateFromDisk(G_pCApp->m_PathIni, localParam);
       bool matchOnNom    = (CGestIni::Param_ReadUniqueParam(localParam, "Sesam-Vitale", "Compare_Nom")    == "ok");
       bool matchOnPrenom = (CGestIni::Param_ReadUniqueParam(localParam, "Sesam-Vitale", "Compare_Prenom") == "ok");

       QTreeWidgetItemIterator it( m_pGUI->listView_Vitale );
       while ( *it )
          {
             QTreeWidgetItem *pQListViewItem = *it;
             //............ formater qq trucs pour les rendre compatble avec le match SQL ....................
             QString dnss     = pQListViewItem->text(2).left(8);             //  199306010000   -->  19930601
                     dnss     = dnss.insert(4,'-');                          //  19930601       -->  1993-0601
                     dnss     = dnss.insert(7,'-');                          //  1993-0601      -->  1993-06-01
                     dnss    += " 00:00:00";                                 //  1993-0601      -->  1993-06-01 00:00:00
             QString numSecu  = pQListViewItem->text(3);
                     numSecu += CMoteurBase::ComputeClef_Secu(numSecu);
             QString rangGem  = pQListViewItem->text(4);
             if (rangGem.length()==1) rangGem = rangGem.prepend("0");
             //............ determine si le nom prenom entrent dans la comparaison .....................
             QString nom    = pQListViewItem->text(0);
             QString prenom = pQListViewItem->text(1);
             if (QDate::isValid ( dnss.mid(0,4).toInt(), dnss.mid(5,2).toInt(), dnss.mid(8,2).toInt() ) )  // si date de naiss invalide on est oblig\303\251 de se servir du nom prenom
             {
                 if (!matchOnNom)     nom    = "";
                 if (!matchOnPrenom)  prenom = "";
             }
             if (G_pCApp->m_pCMoteurBase->GetPatientListFromNomPrenomSecuDtNssGeme( 0,                           // pas de listview car on veut juste savoir si trouve
                                                                                    nom,        // nom
                                                                                    prenom,     // prenom
                                                                                    dnss,                        // date Nss // doit etre 1993-06-01 00:00:00
                                                                                    numSecu,                     // num secu // 160196296519557
                                                                                    rangGem,                     // rang gemellaire
                                                                                    pQListViewItem->text(5),     // qualite d'ayant droit
                                                                                    "",      //  adresse,
                                                                                    "",      //  codePost,
                                                                                    "",      //  ville,
                                                                                    "",      //  sexe,
                                                                                    "",      //  profession,
                                                                                    "",      //  nomJfille
                                                                                    "",      //  nomAss,
                                                                                    "",      //  prenomAss,
                                                                                    "",      //  tel1,
                                                                                    "",      //  tel2,
                                                                                    "",      //  tel3,
                                                                                    "",      //  email,
                                                                                    " = ",   //  egal_like  " = ",
                                                                                    m_pGUI->textLabel_StateList
                                                                                  )
                )
                {pQListViewItem->setIcon ( 0, QIcon(Theme::getIcon( "16x16/VitaleOk.png")) );
                 pQListViewItem->setText(6, "-");                                           // 6 pk doss
                }
             else
                {pQListViewItem->setIcon ( 0, QIcon(Theme::getIcon( "16x16/VitaleNotOk.png")) );
                 pQListViewItem->setText(6, "");
                }
           ++it;
          }
#endif
}

//--------------------------------- Slot_listView_Vitale_MenuRequested -----------------------------------------------------------------------
void C_Manager::Slot_listView_Vitale_MenuRequested ()
{ //QTreeWidget         *pQlistView = m_pGUI->listView_Patient;
#ifdef SESAM_VERSION
QTreeWidgetItem *pQListViewItem = getSelectedListViewItem(m_pGUI->listView_Vitale);
if (pQListViewItem==0)     return;
if (G_pCApp->m_pVitale==0) return;

C_Vitale       *pcVitale =  G_pCApp->m_pVitale;
int               action = -1;
QString       val_actual = "";
QString              tmp = "";
int            occurence = pQListViewItem->text(8).toInt();
int  qualiteAyantDroit_V = pcVitale->GetMember(14,  104, occurence).toInt();
int  qualiteAyantDroit_P = m_pGUI->comboBoxQualiteAyantDroit->currentItem ();


QString p_nom, p_prenom;  pcVitale->GetNomPrenomAyanDroit(occurence, ";", &p_nom, &p_prenom);
QStringList list;

//....................... si l'identite de la CV selectionnee correspondant \303\240 un dossier d\303\251ja en base .................
//                        on propose de completer le dossier avec les donn\303\251es qui diff\303\250rent
//                        que si le patient selectionne dans liste des patients est le m\303\252me que celui de la CV
if (pQListViewItem->text(6).length()                                      &&
    pcVitale->Compare(occurence, m_pGUI->lineEdit_NumSecu->text().remove(' '),
                                 m_pGUI->lineEdit_DtNss->text().remove('-'),
                                 m_pGUI->lineEdit_RangGeme->text())==0  &&
                                 getInterfaceMode()==MODE_SELECTION_PATIENT
   )
   {tmp = pcVitale->GetMember(1,  104, occurence) + " " + pcVitale->GetMember(3,  104, occurence);
    if (m_pGUI->lineEdit_NomDossier->text()+" "+m_pGUI->lineEdit_PrenomDossier->text() != tmp)
        list.append(tr("1- Mettre \303\240 jour l'identit\303\251 avec le nom et pr\303\251nom de l'ayant droit : ") + tmp);

    tmp = pcVitale->GetMember(2,  104, occurence).trimmed();
    if (tmp.length() && m_pGUI->lineEdit_NomDeNss->text().remove(' ') != tmp)
        list.append(tr("2- Mettre \303\240 jour l'identit\303\251 avec le nom de naissance : ") + tmp);
    /*
    tmp =  pcVitale->GetMember(8,  101, 1);                      // ce menu ne devrait pas etre possible car match obligatoire pour cette donn\303\251e
    if (tmp.length()>1 && tmp != m_pGUI->lineEdit_NumSecu->text())
        list.append(tr("3- Mettre \303\240 jour l'identit\303\251 avec le num\303\251ro de SS : ") + tmp + " "+CMoteurBase::ComputeClef_Secu(tmp));
    */
    tmp =  pcVitale->GetAdresseAyanDroit(occurence);
    if (tmp.length()==0) tmp =  pcVitale->GetAdresseAssure();
    val_actual = m_pGUI->textEdit_Adresse->text();
    if (tmp.length() &&  val_actual != tmp)
        list.append(tr("4- Mettre \303\240 jour l'identit\303\251 avec l'adresse : ") + tmp);

    pcVitale->GetCodePostalVilleAyanDroit(occurence, &tmp,0);  // code postal ville
    if (tmp.length()==0) pcVitale->GetCodePostalVilleAssure(&tmp, 0);
    if (tmp.length() && m_pGUI->lineEdit_CdPostal->text().remove(' ') != tmp)
        list.append(tr("5- Mettre \303\240 jour l'identit\303\251 avec le code postal : ") + tmp);

    pcVitale->GetCodePostalVilleAyanDroit(occurence,0, &tmp);  // code postal ville
    if (tmp.length()==0) pcVitale->GetCodePostalVilleAssure(0 ,&tmp);
    if (tmp.length() && m_pGUI->lineEditVille->text() != tmp)
        list.append(tr("6- Mettre \303\240 jour l'identit\303\251 avec la ville : ") + tmp);

    tmp = pcVitale->GetNomPrenomAssure();
    if (tmp.length() && m_pGUI->lineEdit_NomAssure->text()+" "+m_pGUI->lineEdit_PrenomAssure->text() != tmp)
        list.append(tr("7- Mettre \303\240 jour l'identit\303\251 avec le nom et pr\303\251nom de l'assur\303\251 : ") + tmp);
    /*
    tmp = pcVitale->GetRangGemellaire(occurence);                  // ce menu ne devrait pas etre possible car match obligatoire pour cette donn\303\251e
    if (tmp.length() && m_pGUI->lineEdit_RangGeme->text() != tmp)
        list.append(tr("8- Mettre \303\240 jour l'identit\303\251 avec le rang g\303\251mellaire : ") + tmp);

    tmp = pcVitale->GetDateNaissanceAyantDroit(occurence,0,"/");  // ce menu ne devrait pas etre possible car match obligatoire pour cette donn\303\251e
    if (tmp.length() && m_pGUI->lineEdit_DtNss->getMixText() != tmp)
        list.append(tr("9- Mettre \303\240 jour l'identit\303\251 avec la date de naissance : ") + tmp);
    */
    if (qualiteAyantDroit_V !=  qualiteAyantDroit_P)
        list.append(tr("10- Mettre \303\240 jour l'identit\303\251 avec le type d'ayant droit : ") + pcVitale->CodeQualiteToName( QString::number(qualiteAyantDroit_V )));

    if (list.count()) list.append(tr("11- Mettre \303\240 jour l'identit\303\251 avec toutes les donn\303\251es de la carte vitale ") );
   }

//............... Menu recherche pour toutes les identites de la CV ..........................
list.append("----------");
tmp =  pcVitale->GetMember(8,  101, 1); tmp += " "+CMoteurBase::ComputeClef_Secu(tmp);
if (tmp.length()>1) list.append(tr("23- Rechercher avec le num\303\251ro de SS : ") + tmp);

tmp = pcVitale->GetNomPrenomAyanDroit(occurence);
if (tmp.length()) list.append(tr("27- Rechercher avec le nom et pr\303\251nom de l'ayant droit : ") + tmp);

pcVitale->GetNomPrenomAyanDroit(occurence, ";", &p_nom, &p_prenom);
if (p_nom.length())    list.append(tr("28- Rechercher avec le nom de l'ayant droit    : ")    + p_nom);
if (p_prenom.length()) list.append(tr("29- Rechercher avec le pr\303\251nom de l'ayant droit : ")    + p_prenom);

tmp = pcVitale->GetDateNaissanceAyantDroit(occurence);
if (tmp.length()) list.append(tr("30- Rechercher avec la date de naissance : ") + tmp);

//............... que si identite de la CV ne correspond pas \303\240 un dossier en base ........................
//                on propose de l'attribuer au dossier selectionne
if (pQListViewItem->text(6).length()==0)
   {list.append(tr("-------------") );
    if ( getInterfaceMode()==MODE_CREATION_PATIENT)
       { list.append("-------------");
         list.append(tr("33- Utiliser les donn\303\251es de la carte sesam Vitale : %1 pour remplir celles du patient en cours de cr\303\251ation").arg(p_nom + " " + p_prenom));
       }
    else
       { list.append(tr("31- Cr\303\251er un nouveau dossier avec l'identit\303\251 s\303\251lectionn\303\251e de la carte vitale : ") + p_nom + " " + p_prenom);
         list.append("-------------");
         QTreeWidgetItem *pQListViewItemPatient =  getSelectedListViewItem(m_pGUI->listView_Patient);
         if (pQListViewItemPatient)
            {list.append(tr("32- Attribuer les \303\251l\303\251ments de cette carte vitale au patient s\303\251lectionn\303\251 : ")+ pQListViewItemPatient->text(0) + " " + pQListViewItemPatient->text(1));
            }
       }
   }

//.................. actionner le menu et les actions .................................................
QString ret = G_pCApp->DoPopupList(list); action = ret.find('-'); if (action != -1) action = ret.left(action).toInt();
switch(action)
       {case 1:
             {m_pGUI->lineEdit_NomDossier->setText(      pcVitale->GetMember(1,  104, occurence));
              m_pGUI->lineEdit_PrenomDossier->setText(   pcVitale->GetMember(3,  104, occurence));
             } break;
        case 2:
             {m_pGUI->lineEdit_NomDeNss->setText(   pcVitale->GetMember(2,  104, occurence));
             } break;
        case 3:
             {tmp =  pcVitale->GetMember(8,  101, 1);
              m_pGUI->lineEdit_NumSecu->setText(tmp);
              m_pGUI->lineEdit_NssClef->setText(CMoteurBase::ComputeClef_Secu(tmp));
             } break;
        case 4:
             {tmp =  pcVitale->GetAdresseAyanDroit(occurence);
              if (tmp.length()==0) tmp =  pcVitale->GetAdresseAssure();
              m_pGUI->textEdit_Adresse->setText(tmp);
             } break;
        case 5:
             {pcVitale->GetCodePostalVilleAyanDroit(occurence, &tmp,0);  // code postal
              if (tmp.length()==0) pcVitale->GetCodePostalVilleAssure(&tmp, 0);
              m_pGUI->lineEdit_CdPostal->setText(tmp);
              tryToSetVilleFromCodePostal();
             } break;
        case 6:
             {pcVitale->GetCodePostalVilleAyanDroit(occurence,0, &tmp);  // ville
              if (tmp.length()==0) pcVitale->GetCodePostalVilleAssure( 0, &tmp);
              m_pGUI->lineEditVille->setText(tmp);
             tryToSetCodePostalFromVille();
             } break;
        case 7:
             {pcVitale->GetNomPrenomAssure(" ", &p_nom, &p_prenom);
              m_pGUI->lineEdit_NomAssure->setText(p_nom);
              m_pGUI->lineEdit_PrenomAssure->setText(p_prenom);
             } break;
        case 8:
             {tmp = pcVitale->GetRangGemellaire(occurence);
              m_pGUI->lineEdit_RangGeme->setText(tmp);
             } break;
        case 9:
             {tmp = pcVitale->GetDateNaissanceAyantDroit(occurence,0,"");
              m_pGUI->lineEdit_DtNss->setText(tmp);
             } break;
        case 10:
             {m_pGUI->comboBoxQualiteAyantDroit->setCurrentItem ( qualiteAyantDroit_V );
              //m_pGUI->OnActivated_comboBoxQualiteAyantDroit( qualiteAyantDroit_V );
              if (m_pGUI->comboBoxSexe->currentItem()==2)  tryToSetInterfaceFromAyantDroit( m_pGUI->comboBoxQualiteAyantDroit->currentIndex(), 0);
             } break;
        case 11:
             {setInterfaceOnVitaleData(G_pCApp->m_pVitale,occurence );
             } break;
        case 23:
             {tmp =  pcVitale->GetMember(8,  101, 1); tmp +=CMoteurBase::ComputeClef_Secu(tmp);
              if (G_pCApp->m_pCMoteurBase->GetPatientListFromNomPrenomSecuDtNssGeme(m_pGUI->listView_Patient,         // pas de listview car on veut juste savoir si trouve
                                                                                    "",         // nom
                                                                                    "",         // prenom
                                                                                    "",         // date Nss // doit etre 1993-06-01 00:00:00
                                                                                    tmp,        // num secu // 160196296519557
                                                                                    "",         // rang gemellaire
                                                                                    "",         // qualite d'ayant droit
                                                                                    "",         // adresse,
                                                                                    "",         // codePost,
                                                                                    "",         // ville,
                                                                                    "",         // sexe,
                                                                                    "",         // profession,
                                                                                    "",      //  nomJfille
                                                                                    "",      //  nomAss,
                                                                                    "",      //  prenomAss,
                                                                                    "",      //  tel1,
                                                                                    "",      //  tel2,
                                                                                    "",      //  tel3,
                                                                                    "",      //  email,
                                                                                    " LIKE ",   // egal_like  " = ",
                                                                                    m_pGUI->textLabel_StateList
                                                                                  )
                 )
                 {
                 }
             } break;
        case 27:
             {tmp = pcVitale->GetNomPrenomAyanDroit(occurence,";");
              m_pGUI->lineEditAutoLocator->setText(tmp);
              //m_pGUI->lineEditAutoLocator_textChanged( tmp );
             } break;
        case 28:
             {pcVitale->GetNomPrenomAyanDroit(occurence, ";", &p_nom, &p_prenom);
              m_pGUI->lineEditAutoLocator->setText(p_nom);
              //m_pGUI->lineEditAutoLocator_textChanged( p_nom );
             } break;
        case 29:
             {pcVitale->GetNomPrenomAyanDroit(occurence, ";", &p_nom, &p_prenom);
              m_pGUI->lineEditAutoLocator->setText(p_prenom.prepend(";%"));
              //m_pGUI->lineEditAutoLocator_textChanged( p_prenom );
             } break;
        case 30:
             {listPatientsByDateNss(pcVitale->GetMember(12, 104, occurence).left(8));
             } break;
        case 31:
             {Slot_NewDossWithoutErase();
              setInterfaceOnVitaleData(G_pCApp->m_pVitale,                // donn\303\251es carte vitale
                                       occurence                          // occurence
                                      );
             } break;
        case 33:
             {setInterfaceOnProfil(MODE_CREATION_PATIENT);
              setInterfaceOnVitaleData(G_pCApp->m_pVitale,                // donn\303\251es carte vitale
                                       occurence                          // occurence
                                      );
             } break;

        case 32:
             {setCVonPatient (pcVitale,  occurence);
             } break;
       }
#endif
}
//--------------------------------- setCVonPatient -----------------------------------------------------------------------
void C_Manager::setCVonPatient (C_Vitale *pcVitale, int occurence)
{
#ifdef SESAM_VERSION
   QString tmp      = pcVitale->GetNomPrenomAyanDroit(occurence, " ").replace('\'',' ').replace('-',' ');
   tmp              = tmp.simplified();   tmp   = tmp.trimmed();   tmp   = tmp.upper();
   QString p_nom    = m_pGUI->lineEdit_NomDossier->text() + " "+m_pGUI->lineEdit_PrenomDossier->text();
   p_nom            = p_nom=p_nom.replace('\'',' ').replace('-',' '); p_nom.simplified(); p_nom = p_nom.trimmed(); p_nom = p_nom.upper();
   QString dnss_1   = pcVitale->GetDateNaissanceAyantDroit(occurence,0,"-");
   QString dnss_2   = m_pGUI->lineEdit_DtNss->text();
   QString cd_p_1   = ""; pcVitale->GetCodePostalVilleAssure(&cd_p_1, 0);
   QString cd_p_2   = m_pGUI->lineEdit_CdPostal->text().remove(' ');
   QString secu_1   = pcVitale->GetMember(8,  101, 1);
   QString secu_2   = m_pGUI->lineEdit_NumSecu->text().remove(' ');
   int nb_criteres  = 0;
   QString mess_Cri = "";
   if (tmp    != p_nom)                                    {mess_Cri += tr( "<br>&nbsp;&nbsp;&nbsp;&nbsp;- le nom pr\303\251nom doit changer pour  : <b><font color=\"#e80d0d\">")   + pcVitale->GetNomPrenomAyanDroit(occurence, " ")  + tr("</font></b>,"); ++nb_criteres;}
   if (dnss_1 != dnss_2)                                   {mess_Cri += tr( "<br>&nbsp;&nbsp;&nbsp;&nbsp;- la date de naissance doit changer pour  : <b><font color=\"#e80d0d\">")   + dnss_1       + tr("</font></b>,"); ++nb_criteres;}
   if (cd_p_1.toInt() && cd_p_1.toInt() != cd_p_2.toInt()) {mess_Cri += tr( "<br>&nbsp;&nbsp;&nbsp;&nbsp;- le code postal doit changer pour  : <b><font color=\"#e80d0d\">")         + cd_p_1       + tr("</font></b>,"); ++nb_criteres;}
   if (secu_1 != secu_2)                                   {mess_Cri += tr( "<br>&nbsp;&nbsp;&nbsp;&nbsp;- le num\303\251ro de SS doit changer pour  : <b><font color=\"#e80d0d\">") + secu_1       + tr("</font></b>."); ++nb_criteres;}
   QString message  = tr ( "<b><font color=\"#e80d0d\">ATTENTION OP\303\211RATION \303\200 HAUT RISQUE </font></b>")                           +
                      tr(  "<hr><br> La personne : <b><font color=\"#1200ff\">") + m_pGUI->lineEdit_NomDossier->text() + " "+m_pGUI->lineEdit_PrenomDossier->text()          + "</font></b>" +
                      tr(  "<br> n\303\251e le : <b><font color=\"#1200ff\">" )  + dnss_2                                                                                    + "</font></b>";
   if (cd_p_2.toInt())
       message += tr(  "<br> habitant : <b>%1 %2</b>").arg(m_pGUI->lineEdit_CdPostal->text(), m_pGUI->lineEditVille->text());

   message += tr(  "<br> ayant pour num\303\251ro de SS : <b>")              + secu_2                       + "</b><br>";
   if (nb_criteres==1)
      {message += tr(  "<hr><br><img src=%1/32x32/warning.png> diff\303\250re <b><font color=\"#e80d0d\">du</font></b> crit\303\250re suivant \303\240 modifier :").arg(Theme::getPath(Theme::WithNoSeparator));
       message += mess_Cri;
      }
   else if (nb_criteres)
      {message += tr(  "<hr><br><img src=%1/32x32/warning.png> diff\303\250re d'au moins des <b><font color=\"#e80d0d\">").arg(Theme::getPath(Theme::WithNoSeparator))+ QString::number(nb_criteres) + tr("</font></b> crit\303\250res suivants \303\240 modifier :");
       message += mess_Cri;
      }
   else
      {message += tr(  "<hr><br>semble \303\252tre la m\303\252me que celle de la carte Vitale<br>nom, pr\303\251nom, num\303\251ro de SS, date de naissance identiques.");
      }
   message += tr("<br><hr>confirmez vous tout de m\303\252me cette op\303\251ration ? ");
   if (m_pGUI->lineEdit_RangGeme->text().length())
       message += tr("<br>&nbsp;&nbsp;&nbsp;&nbsp;=> en sachant que <b>ce patient a d\303\251j\303\240 probablement \303\251t\303\251 cr\303\251\303\251 par une carte vitale</b>. ");
   if (tmp    != p_nom)
      {message += tr("<br>&nbsp;&nbsp;&nbsp;&nbsp;=> en sachant qu'un changement de nom et pr\303\251nom est suspect,");
       message += tr(" car tous <b>les documents du dossier en cours vont \303\252tre attribu\303\251s au nouveau nom</b>. ");
      }
   if (dnss_1 != dnss_2)
       message += tr("<br>&nbsp;&nbsp;&nbsp;&nbsp;=> en sachant qu'un changement de date de naissance est suspect. ");

   int sel = QMessageBox::information( this, tr("Vitaliser un patient"), message ,
                                      //"&nbsp;&nbsp;&nbsp;&nbsp; ° <b>Quitter pour <u>Annuler</u></b> l'op\303\251ration en cours" ) ,
                                      tr("&Annuler"), tr("Confirmer"), 0 /*tr("Annuler")*/,
                                      0, 0 );
   if (sel != 1) return;
   message  = tr(  "<b><font color=\"#e80d0d\">ETES VOUS CERTAIN DE CETTE OPERATION </font></b>") +
              tr(  "<hr><br> il est encore temps d'annuler cette op\303\251ration.") +
              tr(  "<br> qui sera non r\303\251verssible apr\303\250s confirmation." ) +
              tr(  "<br><hr>confirmez vous de nouveau cette op\303\251ration ? ");
   sel = QMessageBox::information( this, tr("Attribution d'une carte Vitale \303\240 une identit\303\251 patient"), message,
                                         tr("&Attribuer la carte Vitale"),tr("&Annuler") , 0 /*tr("Annuler")*/,
                                         1, 1 );
   if (sel == 1) return;
   setInterfaceOnVitaleData(G_pCApp->m_pVitale,occurence );
   Slot_pushButtonSavModifWithoutConfirmation();
#endif
}

//--------------------------------- Slot_listView_Vitale_ContextMenuRequested -----------------------------------------------------------------------
void C_Manager::Slot_listView_Vitale_ContextMenuRequested (const QPoint &)
{Slot_listView_Vitale_MenuRequested();
}

//--------------------------------- Slot_pushButtonVitale_clicked -----------------------------------------------------------------------
void C_Manager::Slot_pushButtonVitale_clicked()
{
#ifdef SESAM_VERSION
int last_occurence    = 0;

QTreeWidget *pQlistView = m_pGUI->listView_Vitale;
pQlistView->show();                                    // afficher la liste de la carte vitale

QString pathPlugin, pathLog, moduleName;
CGestIni::Param_ReadParam(G_pCApp->m_LocalParam, "Sesam-Vitale", "pathPlugin",       &pathPlugin);
CGestIni::Param_ReadParam(G_pCApp->m_LocalParam, "Sesam-Vitale", "pathLog",          &pathLog);
CGestIni::Param_ReadParam(G_pCApp->m_LocalParam, "Sesam-Vitale", "ModuleName",       &moduleName);

//Cz_Pyxvital -------------------------DEBUT -----------------------------------------------------------------
if (pathPlugin.length())
     {
     pQlistView->clear();
     if (moduleName=="PYXVITAL")
       {
       if (m_timerFSE != 0 && m_timerFSE->isActive() && !m_FSEenCours)     // arrÃªt du controle du Patient en cours sur Pyxvital
           m_timerFSE->stop();
       // On lance Aixvital qui appelera Pyxvital pour lire la Carte Vitale en aveugle et retourne le fichier Patient.par
       m_ficPatientPar = appelPyxvital ( "m_Command = CVH\r\n");
       // au retour de Pyxvital on alimente la structure m_pVitale avec les donn\303\251es de Patient.par
       // pour continuer ensuite avec le traitement standard ...
       QSettings *settings = new QSettings(m_ficPatientPar, QSettings::IniFormat);
       QString    nss = settings->value(tr("B\303\251n\303\251ficiaire/Num\303\251ro")).toString();
       if (G_pCApp->m_pVitale) delete G_pCApp->m_pVitale;
       G_pCApp->m_pVitale = new C_Vitale;
       G_pCApp->m_pVitale->SetMember(8, 101, nss, nss.length(), 1);                        // Num S\303\251cu Assur\303\251
       int i;
       QString zitem = "toto";
       QString numBenef;
       for (i=1; i<100; i++)
            {
            numBenef = QString("B\303\251n\303\251ficiaire_%1").arg(i) ;
                                                                           // BUG : 1er champ pas pris en compte
            G_pCApp->m_pVitale->SetMember(8, 104, "", 0, i);               // CP bidon pour BUG ?????
                                                                           // REvoir initialisation de m_pVitale
            zitem = settings->value(tr(numBenef) + tr("/Nom")).toString();
            if (zitem.length() < 1) break;
            G_pCApp->m_pVitale->SetMember(1, 104, zitem, zitem.length(), i);               // Nom
            zitem = settings->value(tr(numBenef) + tr("/Code_qualit\303\251")).toString();
            //if (zitem.length()==1) zitem = zitem.prepend("0");
            G_pCApp->m_pVitale->SetMember(14, 104, zitem, zitem.length(), i);              // Qualit\303\251 Ayant Droit
            zitem = settings->value(tr(numBenef) + tr("/Pr\303\251nom")).toString() ;
            G_pCApp->m_pVitale->SetMember(3, 104, zitem, zitem.length(), i);               // Pr\303\251nom
            zitem = settings->value(tr(numBenef) + tr("/Date_de_naissance")).toString() ;          // 15/02/1958
            QString dnss     = zitem.mid(6,4) + zitem.mid(3,2) + zitem.mid(0,2) + "0000";  // 195802150000
            G_pCApp->m_pVitale->SetMember(12, 104, dnss, dnss.length(), i);                // Date naissance
            zitem = settings->value(tr(numBenef) + tr("/Rang_g\303\251mellaire")).toString();
            G_pCApp->m_pVitale->SetMember(13, 104, zitem, zitem.length(), i);              // Rang G\303\251mellaire
            }   // fin du for i
          last_occurence = i;      // A revoir ??
       //Cz_Pyxvital ---------------------------FIN-----------------------------------------------------
   }   // fin if PYXVITAL
else   // cas standard du QFSEVITALE
   { //..................................... ne pas rajouter "/" car c'est un nom de fichier ..........................
     if ( QDir::isRelativePath ( pathPlugin ) )  pathPlugin = QDir::cleanDirPath (pathPlugin.prepend(G_pCApp->m_PathAppli));
     //..................................... rajouter "/" car le chemin doit Ãªtre donn\303\251 avec ..........................
     if ( QDir::isRelativePath ( pathLog ) )     pathLog    = QDir::cleanDirPath (pathLog.prepend(G_pCApp->m_PathAppli) )+"/";

     QString pluginScript  = "[Execute]\r\n";
             pluginScript += "pathPlugin="      + pathPlugin                                           + "\r\n" +
                        "pathIni=****\r\n" +                   //**** car indique d'utiliser le pathIni local du plugin
                        "maskExch=Bonjour tout le monde\r\n"
                        "[Parametres]\r\n"
                        "m_Command       = READ_VITALE\r\n"
                        "m_PathLog       =" + pathLog                                             + "\r\n" +
                        "m_DateConsult   =" + QDate::currentDate().toString("yyyyMMdd");

     if (pathPlugin.length())
         {G_pCApp->m_pVitale->UnSerialize(G_pCApp->PluginExe(this, pluginScript, CMoteurBase::endWait));
          last_occurence = G_pCApp->m_pVitale->GetNbOccurences(104) + 1;  //Cz_Pyxvital ?????? Marche mal si pyxvital ???
         }
       } // fin else  - cas QFSEVITALE

       //.................................... La suite du traitement est commune ...........................

         //................. determine si le nom prenom entrent dans la comparaison ..........................
         QString localParam = "";   CGestIni::Param_UpdateFromDisk(G_pCApp->m_PathIni, localParam);
         bool matchOnNom    = (CGestIni::Param_ReadUniqueParam(localParam, "Sesam-Vitale", "Compare_Nom")    == "ok");
         bool matchOnPrenom = (CGestIni::Param_ReadUniqueParam(localParam, "Sesam-Vitale", "Compare_Prenom") == "ok");

         QString    nss = G_pCApp->m_pVitale->GetMember(8,  101, 1);
         // last_occurence = G_pCApp->m_pVitale->GetNbOccurences(104) + 1;  //Cz_Pyxvital
         int i;
         // pQlistView->clear();   //Cz_Pyxvital  -- remont\303\251 avant l'appel au plugin
         for (i=1; i<last_occurence; ++i)
             {QTreeWidgetItem *pQListViewItem = new QTreeWidgetItem();
              if (pQListViewItem)
                 {pQListViewItem->setText(0,  G_pCApp->m_pVitale->GetMember(1,  104, i));    // 0  nom
                  pQListViewItem->setText(1,  G_pCApp->m_pVitale->GetMember(3,  104, i));    // 1  prenom
                  pQListViewItem->setText(2,  G_pCApp->m_pVitale->GetMember(12, 104, i));    // 2  date Nss
                  pQListViewItem->setText(3,  nss);                                          // 3  num secu
                  pQListViewItem->setText(4,  G_pCApp->m_pVitale->GetMember(13,  104, i));   // 4  rang geme
                  pQListViewItem->setText(5,  G_pCApp->m_pVitale->GetMember(14,  104, i));   // 5  qualite ayant-droit
                  pQListViewItem->setText(6,  "");                                           // 6  pk doss
                  pQListViewItem->setText(7,  "");                                           // 7  GUID
                  pQListViewItem->setText(8,  QString::number(i));                           // 8  occurence
                  pQListViewItem->setText(9,  G_pCApp->m_pVitale->GetMember(1,   105, i));   // 9  date ouverture droits
                  pQListViewItem->setText(10, G_pCApp->m_pVitale->GetMember(2,   105, i));   // 10 date fin droits
                  pQlistView->addTopLevelItem(pQListViewItem);
                  //............ formater qq trucs pour les rendre compatible avec le match SQL ....................
                  QString dnss     = pQListViewItem->text(2).left(8);             //  199306010000   -->  19930601
                          dnss     = dnss.insert(4,'-');                          //  19930601       -->  1993-0601
                          dnss     = dnss.insert(7,'-');                          //  1993-0601      -->  1993-06-01
                          dnss    += " 00:00:00";                                 //  1993-0601      -->  1993-06-01 00:00:00
                  QString numSecu  = pQListViewItem->text(3);
                          numSecu += CMoteurBase::ComputeClef_Secu(numSecu);
                  QString rangGem  = pQListViewItem->text(4);
                  if (rangGem.length()==1) rangGem = rangGem.prepend("0");
                  //............ determine si le nom prenom entrent dans la comparaison .....................
                  QString        nom = pQListViewItem->text(0);
                  QString     prenom = pQListViewItem->text(1);
                  if (QDate::isValid ( dnss.mid(0,4).toInt(), dnss.mid(5,2).toInt(), dnss.mid(8,2).toInt() ) ) // si date de naiss invalide on est obligï¿½ de se servir du nom prenom
                     { if (!matchOnNom)     nom    = "";
                       if (!matchOnPrenom)  prenom = "";
                     }
                  if (G_pCApp->m_pCMoteurBase->GetPatientListFromNomPrenomSecuDtNssGeme( 0,                      // pas de listview car on veut juste savoir si trouve
                                                                                    nom,                         // nom
                                                                                    prenom,                      // prenom
                                                                                    dnss,                        // date Nss // doit etre 1993-06-01 00:00:00
                                                                                    numSecu,                     // num secu // 160196296519557
                                                                                    rangGem,                     // rang gemellaire
                                                                                    pQListViewItem->text(5),     // qualite d'ayant droit
                                                                                    "",      //  adresse,
                                                                                    "",      //  codePost,
                                                                                    "",      //  ville,
                                                                                    "",      //  sexe,
                                                                                    "",      //  profession,
                                                                                    "",      //  nomJfille
                                                                                    "",      //  nomAss,
                                                                                    "",      //  prenomAss,
                                                                                    "",      //  tel1,
                                                                                    "",      //  tel2,
                                                                                    "",      //  tel3,
                                                                                    "",      //  email,
                                                                                    " = ",   //  egal_like  " = ",
                                                                                    m_pGUI->textLabel_StateList
                                                                                  )
                     )
                     {pQListViewItem->setIcon ( 0, QIcon(Theme::getIcon( "16x16/VitaleOk.png")) );
                      pQListViewItem->setText(6, "-");                                           // 6 pk doss
                     }
                  else
                     {pQListViewItem->setIcon ( 0, QIcon(Theme::getIcon( "16x16/VitaleNotOk.png")) );
                      pQListViewItem->setText(6, "");
                     }
                 }  // else if (pQListViewItem)
             } //for (i=1; i<last_occurence; ++i)
        } //if (pathPlugin.length())
     if (last_occurence<2) pQlistView->hide();
     else
        {//.......Redimensionner la longueur de la liste des b\303\251n\303\251ficiiaires en fct du nbre d'Item.........
         int nb = pQlistView->topLevelItemCount ();
         if (nb)
            {QTreeWidgetItem *pQTreeWidgetItem = pQlistView->topLevelItem(0);
             QRect                        rect = pQlistView->visualItemRect (pQTreeWidgetItem );
             int                             h = rect.height()* (nb + 3);
             QList<int> list = m_pGUI->splitter_listPatient->sizes();
             int delta = h - list[0];  list[0] += delta; list[1] -= delta;
             m_pGUI->splitter_listPatient->setSizes ( list );
             //........... si un seul ayant droit le selectionner............
             if (nb==1)
                {pQlistView->setCurrentItem ( pQTreeWidgetItem );
                 pQTreeWidgetItem->setSelected ( TRUE );
                }
            }
        }
   // } // if (moduleName=="PIXVITALE")  >>>Cz_Pyxvital -- d\303\251coupage modifi\303\251 pour ptofiter du code commun

#endif
}

//--------------------------------- setInterfaceOnVitaleData ----------------------------------------------------------------------------------------------
void C_Manager::setInterfaceOnVitaleData(void *pcvitale_in, int occurence)
{
/*
#ifdef SESAM_VERSION

       if (pcvitale_in==0) return;
       C_Vitale  *pcVitale = (C_Vitale*) pcvitale_in;

       //.............. nom prenom patient ...........................
       m_pGUI->lineEdit_NomDossier->setText(      pcVitale->GetMember(1,  104, occurence));
       m_pGUI->lineEdit_PrenomDossier->setText(   pcVitale->GetMember(3,  104, occurence));

       //.............. adresse ...........................
       QString adresse = pcVitale->GetAdresseAyanDroit(occurence);
       if (m_pGUI->textEdit_Adresse->text().length()==0 ||       // si adresse determine et pas mode creation alors ne pas y toucher car la CV peut etre non renseignee
           m_pGUI->pushButtonCreate->isShown()
          ) m_pGUI->textEdit_Adresse->setText(         adresse       );

       //lineEdit_Tel1->setText(            ToNum(query.value( 3).toString())    );
       //lineEdit_Tel2->setText(            ToNum(query.value( 4).toString())    );
       //lineEdit_Tel3->setText(            ToNum(query.value( 5).toString())    );
       //lineEdit_Email->setText(           CGestIni::Utf8_Query(query , 6)      );
       //.............. code postal ville ...........................
       QString codePostLocalite = pcVitale->GetMember(8,  104, occurence);
       if (m_pGUI->lineEdit_CdPostal->text().remove(' ').toInt()==0 ||       // si codePostal determine et pas mode creation alors ne pas y toucher car la CV peut etre non renseignee
           m_pGUI->pushButtonCreate->isShown()
          ) m_pGUI->lineEdit_CdPostal->setText(        codePostLocalite.left(5) );
       if (m_pGUI->lineEditVille->text().length()==0 ||                      // si ville determine et pas mode creation alors ne pas y toucher car la CV peut etre non renseignee
           m_pGUI->pushButtonCreate->isShown()
          ) m_pGUI->lineEditVille->setText(    codePostLocalite.mid(6)  );

       //QString sexe                  =    CGestIni::Utf8_Query(query , 9)       ;
       //if (sexe.left(1).lower() == "m")   comboBoxSexe->setCurrentItem ( 0 ) ;
       //else                               comboBoxSexe->setCurrentItem ( 1 ) ;
       //.............. rang gemellaire ...........................
       QString rangGem  = pcVitale->GetMember(13,  104, occurence);
       if (rangGem.length()==0) rangGem = rangGem.prepend("0");
       if (rangGem.length()==1) rangGem = rangGem.prepend("0");
       m_pGUI->lineEdit_RangGeme->setText( rangGem );

       //lineEdit_Sexe->setText(            CGestIni::Utf8_Query(query , 9)      );
       //textLabel_NumDoss->setText(        CGestIni::Utf8_Query(query , 10)     );
       if (m_pGUI->lineEdit_NomDeNss->text().length()==0 ||           // si ville determine et pas mode creation alors ne pas y toucher car la CV peut etre non renseignee
           m_pGUI->pushButtonCreate->isShown()
          )m_pGUI->lineEdit_NomDeNss->setText(        pcVitale->GetMember(2,  104, occurence)     );
       //lineEdit_Titre->setText(           CGestIni::Utf8_Query(query , 12)     );
       //lineEdit_Profession->setText(      CGestIni::Utf8_Query(query , 13)     );
       //.......................... ayant droit ........................................
       int qualiteAyantDroit = pcVitale->GetMember(14,  104, occurence).toInt();
       m_pGUI->comboBoxQualiteAyantDroit->setCurrentItem ( qualiteAyantDroit );
       tryToSetInterfaceFromAyantDroit( qualiteAyantDroit, 0 );
       //............. rechercher l'assure .............................................
       int last_occurence = pcVitale->GetNbOccurences(104) + 1;
       int i;
       for (i=1; i<last_occurence; ++i)
           {if (pcVitale->GetMember(14,  104, i).toInt()==0)    //  qualite ayant-droit si zero c'est l'assure
               {m_pGUI->lineEdit_NomAssure->setText(       pcVitale->GetMember(1,  104, i)      );   // recuperer son nom
                m_pGUI->lineEdit_PrenomAssure->setText(    pcVitale->GetMember(3,  104, i)      );   // recuperer son prenom
                //............ si adresse ayant droit est non d\303\251finie ..............................
                //             proposer celle de l'assure
                if (adresse.trimmed().length()==0)
                   {adresse =pcVitale->GetAdresseAyanDroit(i) ;
                    if (m_pGUI->textEdit_Adresse->text().length()==0 ||       // si adresse determine et pas mode creation alors ne pas y toucher car la CV peut etre non renseignee
                        m_pGUI->pushButtonCreate->isShown()
                       )m_pGUI->textEdit_Adresse->setText(adresse);
                    codePostLocalite = pcVitale->GetMember(8,  104, i);
                    if (m_pGUI->lineEdit_CdPostal->text().remove(' ').toInt()==0 ||       // si codePostal determine et pas mode creation alors ne pas y toucher car la CV peut etre non renseignee
                        m_pGUI->pushButtonCreate->isShown()
                       )m_pGUI->lineEdit_CdPostal->setText(        codePostLocalite.left(5) );
                    if (m_pGUI->lineEditVille->text().length()==0 ||           // si ville determine et pas mode creation alors ne pas y toucher car la CV peut etre non renseignee
                        m_pGUI->pushButtonCreate->isShown()
                       )m_pGUI->lineEditVille->setText(            codePostLocalite.mid(6)  );
                   }
                break;
               }
           }

       //....................... trucs speciaux ........................................
       QString qDteNss =    pcVitale->GetMember(12, 104, occurence);                   // 199306010000
               qDteNss =    qDteNss.mid(6,2)+qDteNss.mid(4,2)+qDteNss.mid(0,4);        // 01061993
       m_pGUI->lineEdit_DtNss->setText(qDteNss);
       int jour, mois, annee;
       jour  = qDteNss.mid(0,2).toInt();
       mois  = qDteNss.mid(2,2).toInt();
       annee = qDteNss.mid(4,4).toInt();
       if (QDate::isValid ( annee, mois, jour ) )
          {QDate dt(annee, mois, jour);
           / *textLabel_Age->setText(m_pCMoteurBase->CalculeDiffAge(&dt, 0, TRUE, 0)); * / m_pGUI->groupBoxPatient->setTitle(tr("Patient \303\242g\303\251 de : ")+m_pCMoteurBase->CalculeDiffAge(&dt, 0, TRUE, 0));
          }
       else
          { / *textLabel_Age->setText(tr("Date de naissance non valide")); * / m_pGUI->groupBoxPatient->setTitle(tr("Patient avec une date de naissance non valide"));
           m_pGUI->lineEdit_Titre->setText("");
          }
       //....................... numero secu ........................................
       QString   nss =  pcVitale->GetMember(8,  101, 1);
       m_pGUI->lineEdit_NumSecu->setText(nss);
       m_pGUI->lineEdit_NssClef->setText(CMoteurBase::ComputeClef_Secu(nss));
       //................ sexe ......................................................
       if (m_pGUI->comboBoxSexe->currentItem()==2 ||       // si sexe determine et pas mode creation alors ne pas toucher au sexe
           m_pGUI->pushButtonCreate->isShown()
          )setSexFromQualiteAyantDroit(qualiteAyantDroit);
#endif
*/
#ifdef SESAM_VERSION

       if (pcvitale_in==0) return;
       C_Vitale  *pcVitale = (C_Vitale*) pcvitale_in;

       //.............. nom prenom patient ...........................
       m_pGUI->lineEdit_NomDossier->setText(      pcVitale->GetMember(1,  104, occurence));
       m_pGUI->lineEdit_PrenomDossier->setText(   pcVitale->GetMember(3,  104, occurence));

       //.............. adresse ...........................
       QString adresse = pcVitale->GetAdresseAyanDroit(occurence);
       if (m_pGUI->textEdit_Adresse->text().length()==0 ||       // si adresse determine et pas mode creation alors ne pas y toucher car la CV peut etre non renseignee
           m_pGUI->pushButtonCreate->isShown()
          ) m_pGUI->textEdit_Adresse->setText(         adresse       );

       //lineEdit_Tel1->setText(            ToNum(query.value( 3).toString())    );
       //lineEdit_Tel2->setText(            ToNum(query.value( 4).toString())    );
       //lineEdit_Tel3->setText(            ToNum(query.value( 5).toString())    );
       //lineEdit_Email->setText(           CGestIni::Utf8_Query(query , 6)      );
       //.............. code postal ville ...........................
       QString codePostLocalite = pcVitale->GetMember(8,  104, occurence);
       if (m_pGUI->lineEdit_CdPostal->text().remove(' ').toInt()==0 ||       // si codePostal determine et pas mode creation alors ne pas y toucher car la CV peut etre non renseignee
           m_pGUI->pushButtonCreate->isShown()
          ) m_pGUI->lineEdit_CdPostal->setText(        codePostLocalite.left(5) );
       if (m_pGUI->lineEditVille->text().length()==0 ||                      // si ville determine et pas mode creation alors ne pas y toucher car la CV peut etre non renseignee
           m_pGUI->pushButtonCreate->isShown()
          ) m_pGUI->lineEditVille->setText(    codePostLocalite.mid(6)  );

       //QString sexe                  =    CGestIni::Utf8_Query(query , 9)       ;
       //if (sexe.left(1).lower() == "m")   comboBoxSexe->setCurrentItem ( 0 ) ;
       //else                               comboBoxSexe->setCurrentItem ( 1 ) ;
       //.............. rang gemellaire ...........................
       QString rangGem  = pcVitale->GetMember(13,  104, occurence);
       if (rangGem.length()==0) rangGem = rangGem.prepend("0");
       if (rangGem.length()==1) rangGem = rangGem.prepend("0");
       m_pGUI->lineEdit_RangGeme->setText( rangGem );

       //lineEdit_Sexe->setText(            CGestIni::Utf8_Query(query , 9)      );
       //textLabel_NumDoss->setText(        CGestIni::Utf8_Query(query , 10)     );
       if (m_pGUI->lineEdit_NomDeNss->text().length()==0 ||           // si ville determine et pas mode creation alors ne pas y toucher car la CV peut etre non renseignee
           m_pGUI->pushButtonCreate->isShown()
          )m_pGUI->lineEdit_NomDeNss->setText(        pcVitale->GetMember(2,  104, occurence)     );
       //lineEdit_Titre->setText(           CGestIni::Utf8_Query(query , 12)     );
       //lineEdit_Profession->setText(      CGestIni::Utf8_Query(query , 13)     );
       //.......................... ayant droit ........................................
       int qualiteAyantDroit = pcVitale->GetMember(14,  104, occurence).toInt();
       m_pGUI->comboBoxQualiteAyantDroit->setCurrentItem ( qualiteAyantDroit );
       tryToSetInterfaceFromAyantDroit( qualiteAyantDroit, 0 );
       //............. rechercher l'assure .............................................
       QString qDteNss;
       int last_occurence = pcVitale->GetNbOccurences(104) + 1;
       int i;
       bool assureFind = FALSE;
       for (i=1; i<last_occurence; ++i)
           {
            if (pcVitale->GetMember(14,  104, i).toInt()==0)    //  qualite ayant-droit si zero c'est l'assure
               {
                assureFind = TRUE;
                m_pGUI->lineEdit_NomAssure->setText(       pcVitale->GetMember(1,  104, i)      );   // recuperer son nom
                m_pGUI->lineEdit_PrenomAssure->setText(    pcVitale->GetMember(3,  104, i)      );   // recuperer son prenom
                qDteNss =    pcVitale->GetMember(12, 104, i);                                // recuperer sa date de naissance
                qDteNss =    qDteNss.mid(6,2)+qDteNss.mid(4,2)+qDteNss.mid(0,4);             // 01061993
                m_pGUI->lineEdit_DtNss_Assure->setText(qDteNss);   //lineEdit_DtNss_Assure

                //............ si adresse ayant droit est non d\303\251finie ..............................
                //             proposer celle de l'assure
                if (adresse.trimmed().length()==0)
                   {adresse =pcVitale->GetAdresseAyanDroit(i) ;
                    if (m_pGUI->textEdit_Adresse->text().length()==0 ||       // si adresse determine et pas mode creation alors ne pas y toucher car la CV peut etre non renseignee
                        m_pGUI->pushButtonCreate->isShown()
                       )m_pGUI->textEdit_Adresse->setText(adresse);
                    codePostLocalite = pcVitale->GetMember(8,  104, i);
                    if (m_pGUI->lineEdit_CdPostal->text().remove(' ').toInt()==0 ||       // si codePostal determine et pas mode creation alors ne pas y toucher car la CV peut etre non renseignee
                        m_pGUI->pushButtonCreate->isShown()
                       )m_pGUI->lineEdit_CdPostal->setText(        codePostLocalite.left(5) );
                    if (m_pGUI->lineEditVille->text().length()==0 ||           // si ville determine et pas mode creation alors ne pas y toucher car la CV peut etre non renseignee
                        m_pGUI->pushButtonCreate->isShown()
                       )m_pGUI->lineEditVille->setText(            codePostLocalite.mid(6)  );
                   }
                break;
               }
           }
       if (assureFind==FALSE)
          {if (getInterfaceMode() == MODE_CREATION_PATIENT)
              {m_pGUI->lineEdit_DtNss_Assure->setText("");
               m_pGUI->lineEdit_PrenomAssure->setText("");
              }
           G_pCApp->CouCou(tr( "Carte vitale sans les donn\303\251es de l'assur\303\251, v\303\251rifiez les manuellement."));
           C_Dlg_Assure *dlg = new C_Dlg_Assure(this, m_pGUI->lineEdit_NomAssure->text(), m_pGUI->lineEdit_PrenomAssure->text(), m_pGUI->lineEdit_DtNss_Assure->text());
           if (dlg)
              {if (dlg->exec()==QDialog::Accepted)
                  {m_pGUI->lineEdit_NomAssure->setText(dlg->getNom());
                   m_pGUI->lineEdit_PrenomAssure->setText(dlg->getPrenom());
                   m_pGUI->lineEdit_DtNss_Assure->setText(dlg->getDateNss());
                  }
               delete dlg;
              }
          }
       //....................... trucs speciaux ........................................
       qDteNss =    pcVitale->GetMember(12, 104, occurence);                   // 199306010000
       qDteNss =    qDteNss.mid(6,2)+qDteNss.mid(4,2)+qDteNss.mid(0,4);        // 01061993
       m_pGUI->lineEdit_DtNss->setText(qDteNss);   //lineEdit_DtNss_Assure
       int jour, mois, annee;
       jour  = qDteNss.mid(0,2).toInt();
       mois  = qDteNss.mid(2,2).toInt();
       annee = qDteNss.mid(4,4).toInt();
       if (QDate::isValid ( annee, mois, jour ) )
          {QDate dt(annee, mois, jour);
           /*textLabel_Age->setText(m_pCMoteurBase->CalculeDiffAge(&dt, 0, TRUE, 0)); */ m_pGUI->groupBoxPatient->setTitle(tr("Patient (b\303\251n\303\251ficiaire) \303\242g\303\251 de : ")+m_pCMoteurBase->CalculeDiffAge(&dt, 0, TRUE, 0));
          }
       else
          { /*textLabel_Age->setText(tr("Date de naissance non valide")); */ m_pGUI->groupBoxPatient->setTitle(tr("Patient (b\303\251n\303\251ficiaire) avec une date de naissance non valide"));
           m_pGUI->lineEdit_Titre->setText("");
          }
       //....................... numero secu ........................................
       QString   nss =  pcVitale->GetMember(8,  101, 1);
       m_pGUI->lineEdit_NumSecu->setText(nss);
       m_pGUI->lineEdit_NssClef->setText(CMoteurBase::ComputeClef_Secu(nss));
       //................ sexe ......................................................
       if (m_pGUI->comboBoxSexe->currentItem()==2 ||       // si sexe determine et pas mode creation alors ne pas toucher au sexe
           m_pGUI->pushButtonCreate->isShown()
          )setSexFromQualiteAyantDroit(qualiteAyantDroit);

       // Cz_Pyxvital -------------------------- DEBUT ---------------------------------------
       // Si on est en mode facture seule, sans gestion du dossier patient
       // on lance directement la cr\303\251ation du patient puis la saisie FSE.
       if (m_Facture_Seule  == "oui")
           {Slot_pushButtonCreate();             // Cr\303\251ation du patient dans la base.
            Slot_pushButton_FSE();               // lancement saisie FSE.
           }
       setInterfaceOnDroitsSociaux(pcVitale, occurence);
       //Cz_Pyxvital -------------------------- FIN ----------------------------------------
#endif
}

//------------------------------------------------------- setInterfaceOnDroitsSociaux --------------------------------------------------
//    met \303\240 jour les elements de l'interface relatifs au droits sociaux sur ceux de la carte vitale
void  C_Manager::setInterfaceOnDroitsSociaux(C_Vitale       *pcVitale, int occurence, int anyWay /* = 0 */)
{
#ifdef SESAM_VERSION
if (anyWay==0 && pcVitale && m_pGUI->lineEdit_NumSecu->text().remove(' ') != pcVitale->GetMember(8,  101, 1))
   {clearDroitsFields();
    return;
   }
QString debDroits = pcVitale->GetMember(1,   105, occurence);
QString finDroits = pcVitale->GetMember(2,   105, occurence);
m_pGUI->lineEdit_DroitsDateDeb->setText(debDroits.mid(6,2)+"/"+debDroits.mid(4,2)+"/"+debDroits.mid(0,4));
m_pGUI->lineEdit_DroitsDateFin->setText(finDroits.mid(6,2)+"/"+finDroits.mid(4,2)+"/"+finDroits.mid(0,4));
m_pGUI->lineEdit_CodeRegime->setText(pcVitale->GetMember(10,  101, 1));
m_pGUI->lineEdit_CaisseGest->setText(pcVitale->GetMember(11,  101, 1));
m_pGUI->lineEdit_CentreGest->setText(pcVitale->GetMember(12,  101, 1));
m_pGUI->lineEdit_CodeGest->setText(pcVitale->GetMember(13,  101, 1));
#endif
}
///////////////////////////////////////// MEDECIN TRAITANT ////////////////////////////////////////
//--------------------------------- Slot_listView_Praticiens_contextMenuRequested -----------------------------------------------------------------------
void C_Manager::Slot_listView_Praticiens_contextMenuRequested (const QPoint &)
{
QTreeWidgetItem *pQListViewItem = getSelectedListViewItem(m_pGUI->listView_Praticiens);
if (pQListViewItem==0)            return;
//............... menu des qualites ..........................
QStringList lst;
QString removeProp = tr("Retirer la propri\303\251t\303\251 'En qualit\303\251 de'");
CGestIni::Param_GetList(G_pCApp->m_LocalParam, "Qualite intervenant", "",  lst );
if (lst.count()==0)               return;
lst.append ( "-------------" );
lst.append ( removeProp );
QString ret = G_pCApp->DoPopupList(lst);
if (ret.length()==0)              return;
if (ret == removeProp) ret="";
//............. placer le retour du menu ...................
pQListViewItem->setText(3, ret);
if (getInterfaceMode()==MODE_CREATION_PATIENT )  return;     // on se contente de renseigner uniquement la listview (l'enregistrement se fera apres click sur enregistrer)
//............ enregistrer l'info ..........................
QString numGUID   = G_pCApp->identitePatientGUID();
QString iD_Doss   = G_pCApp->identitePatientPk();
m_pCMoteurBase->PatientIntervenantsWrite( iD_Doss , numGUID, pQListViewItem->text(4),  pQListViewItem->text(3));
}

//--------------------------------- Slot_pushButton_AddMedTTT_clicked -----------------------------------------------------------------------
void C_Manager::Slot_pushButton_AddMedTTT_clicked()
{QString idInterv = "";
//............ recuperer \303\251ventuel ID praticien en cours .......................................
QTreeWidgetItem *pQListViewItem = getSelectedListViewItem(m_pGUI->listView_Praticiens);
if (pQListViewItem) idInterv = pQListViewItem->text(ID_INTERV);
exeAnnuaire( idInterv );
}
//--------------------------------- Slot_pushButton_AddMedTTT_clicked -----------------------------------------------------------------------
void C_Manager::Slot_pushButton_AddMedTTT_Fast_clicked ()
{   QString numGUID   = "";
   QString iD_Doss   = "";
   QTreeWidgetItem *pQListViewItem =  m_pGUI->listView_Patient->currentItem();
   if (getInterfaceMode()==MODE_CREATION_PATIENT)
      {   numGUID    = m_pCMoteurBase->GUID_Create();
          iD_Doss    = "";
      }
   else if ( pQListViewItem)
      {   numGUID    = G_pCApp->identitePatientGUID();
          iD_Doss    = G_pCApp->identitePatientPk();
      }
   else return;


QString defEnQualiteDe = "";
CGestIni::Param_ReadParam(G_pCApp->m_LocalParam, "Gestion des contacts", "qualite par defaut", &defEnQualiteDe );         // path editeur de texte non d\303\251fini
QString defSpecialite = "";
if (CGestIni::Param_ReadParam(G_pCApp->m_LocalParam, "Gestion des contacts", "specialite par defaut", &defSpecialite )!=QString::null)     return;         // path editeur de texte non d\303\251fini
QStringList listIntervenants = m_pCMoteurBase->PatientIntervenantsGetData(defSpecialite,"|");
if (listIntervenants.count()==0) return;
m_pGUI->pushButton_AddMedTTT_Fast->setIcon ( QIcon (Theme::getIcon( "16x16/Down.png" ))) ;

C_Dlg_DoList* dlg = new C_Dlg_DoList(listIntervenants, "|", 2, C_Dlg_DoList::SingleSelection, this);
QString ret       = "";
if (dlg)
   {if (dlg->exec()==QDialog::Accepted) ret = dlg->getStringSingleSelectedResult();
    delete dlg;
   }
m_pGUI->pushButton_AddMedTTT_Fast->setIcon ( QIcon (Theme::getIcon( "16x16/Left.png" ))) ;

if (ret.length()==0)             return;
QStringList listArg =ret.split("|",QString::KeepEmptyParts);
if (listArg.count()<4)           return;
QString nom      = listArg[0];
QString prenom   = listArg[1];
QString spec     = listArg[2];
QString id       = listArg[3];
QTreeWidgetItem *pQTreeWidgetItemInterv = 0;
if (getInterfaceMode()==MODE_CREATION_PATIENT)
   { pQTreeWidgetItemInterv = new QTreeWidgetItem();
   }
else if (m_pCMoteurBase->PatientIntervenantsWrite( iD_Doss , numGUID, id, defEnQualiteDe) != 0)
   { pQTreeWidgetItemInterv = new QTreeWidgetItem();
   }
if (pQTreeWidgetItemInterv)
   {pQTreeWidgetItemInterv->setText(0,spec);
    pQTreeWidgetItemInterv->setText(1,nom);
    pQTreeWidgetItemInterv->setText(2,prenom);
    pQTreeWidgetItemInterv->setText(3,defEnQualiteDe);
    pQTreeWidgetItemInterv->setText(4,id);
    m_pGUI->listView_Praticiens->addTopLevelItem(pQTreeWidgetItemInterv);
   }
}

//--------------------------------- Slot_pushButton_DelMedTTT_clicked -----------------------------------------------------------------------
void C_Manager::Slot_pushButton_DelMedTTT_clicked()
{  if (G_pCApp->IsThisDroitExist( "idc")==0)
     {G_pCApp->CouCou(tr( "Vos droits sont insuffisants pour modifier un dossier"));
      return;
     }
   QTreeWidgetItem *pQListViewItem = getSelectedListViewItem(m_pGUI->listView_Praticiens);
   if (pQListViewItem==0) return;

   //...... si MODE CREATION ..................
   // les intervenants ne sont justes que cr\303\251\303\251s dans la listview
   // et n'existent pas encore en base donc juste effacer l'item
   //...... si pas MODE CREATION ..................
   // les intervenants sont en base donc effacer l'item
   // et la donn\303\251e correspondante en base
   if (getInterfaceMode() != MODE_CREATION_PATIENT)
      {  m_pCMoteurBase->PatientIntervenantsDelete( pQListViewItem->text(ID_INTERV), G_pCApp->identitePatientGUID());
      }
   delete pQListViewItem;
}

//--------------------------------- Slot_listView_Praticiens_DoubleClicked -------------------------------------------------------------
void C_Manager::Slot_listView_Praticiens_DoubleClicked( QTreeWidgetItem *pQTreeWidgetItem, int )
{QString idInterv = "";
if (pQTreeWidgetItem) idInterv = pQTreeWidgetItem->text(ID_INTERV);
exeAnnuaire(idInterv);
}

//--------------------------------- exeAnnuaire -------------------------------------------------------------
void C_Manager::exeAnnuaire(QString idInterv )
{   if (G_pCApp->IsThisDroitExist( "idc")==0)
     {G_pCApp->CouCou(tr( "Vos droits sont insuffisants pour modifier un dossier"));
      return;
     }
   //.............................. rechercher executable et son fichier d'echange ..........................
   QString pathExe = CGestIni::Construct_Name_Exe("personnes",QFileInfo (qApp->argv()[0]).dirPath (true));
   if ( !QFile::exists( pathExe ) ) {G_pCApp->CouCou(tr( "L'ex\303\251cutable '%1' n'a pas \303\251t\303\251 trouv\303\251.").arg(pathExe));  return; }

   QString pathExch;
   // si path executable non d\303\251fini le fixer par defaut sur '../../tmp'
   if (CGestIni::Param_ReadParam(G_pCApp->m_LocalParam, "Repertoire Temporaire", "Repertoire", &pathExch)!=QString::null)
      {pathExch = "../../tmp";
      }
   // Adaptation \303\240 la plateforme
   if ( QDir(pathExch).isRelative()) pathExch.prepend(G_pCApp->m_PathAppli);
   pathExch += "/ManagerGetPersonnne"+  m_pCMoteurBase->GUID_Create() +".ech";   // on cree un nom de fichier unique
   pathExch = QDir::cleanDirPath(pathExch);
   // l'effacer au ca ou ne l'aurait pas deja ete
   QFile::remove (pathExch);

   QStringList argList;
   //......................... completer les autres arguments .........................................
   argList <<( pathExch );
   argList <<( "Record" );
   argList <<( idInterv );
   argList <<( G_pCApp->m_Droits );

   if (m_Contacts_Run==FALSE)
      {m_Contacts_Run = TRUE;
       QProcess   proc;
       proc.start(pathExe, argList);
       SLEEP(1);
       G_pCApp->processEvents ();
       while (proc.state()==QProcess::Running )
          { QApplication::processEvents ( QEventLoop::WaitForMore );
          }
       m_Contacts_Run = FALSE;

       //......... recuperer fichier d'echange .............
       //          genere par l'executable
       QString ret;
       CGestIni::Param_UpdateFromDisk(pathExch, ret);
       //............... analyse du retour ................
       QString id, spec,nom, prenom;
       int deb =  0;
       int end = ret.find('|');
       id      = ret.mid(deb, end-deb);
       deb     = end + 1;
       end     = ret.find('|', deb);
       nom     = ret.mid(deb, end-deb);
       deb     = end + 1;
       end     = ret.find('|', deb);
       prenom  = ret.mid(deb, end-deb);
       deb     = end + 1;
       spec    = ret.mid(deb);
       //................... si le dossier est en cr\303\251ation ajout uniquement dans la listview ...........................
       QTreeWidgetItem* pQTreeWidgetItemInterv = 0;
       if (getInterfaceMode() == MODE_CREATION_PATIENT)
          { pQTreeWidgetItemInterv = new QTreeWidgetItem();
          }
       //................... si le dossier est deja cree on enregistre  ...........................
       //                    l'intervenant avec les identifiants patients connus
       else if (m_pCMoteurBase->PatientIntervenantsWrite( G_pCApp->identitePatientPk() , G_pCApp->identitePatientGUID(), id, "") != 0)
          { pQTreeWidgetItemInterv = new QTreeWidgetItem();
          }
       if (pQTreeWidgetItemInterv)
          {pQTreeWidgetItemInterv->setText(0,spec);
           pQTreeWidgetItemInterv->setText(1,nom);
           pQTreeWidgetItemInterv->setText(2,prenom);
           pQTreeWidgetItemInterv->setText(3,"");      // en qualite de
           pQTreeWidgetItemInterv->setText(4,id);
           m_pGUI->listView_Praticiens->addTopLevelItem(pQTreeWidgetItemInterv);
          }
      }
   QFile::remove (pathExch);
}


///////////////////////////////////////// PROFILS D'INTERFACE ////////////////////////////////////////
//--------------------------------- setInterfaceOnCurrentProfil -----------------------------------------------------------------------
// #define MODE_SELECTION_PATIENT 1
// #define MODE_CREATION_PATIENT  2
// #define MODE_MULTICRITERE      3
void C_Manager::setInterfaceOnCurrentProfil()
{setInterfaceOnProfil(getInterfaceMode());
}

//--------------------------------- setTitle -----------------------------------------------------------------------
void C_Manager::setTitle()
{QString title = "";
QString nom, prenom;
if (G_pCApp->m_SignUser.length())
   {m_pCMoteurBase->GetUserNomPrenom( G_pCApp->m_SignUser, nom, prenom);
    title   = tr("Manager-V %1 utilis\303\251 par : ").arg(G_pCApp->getNumVers());
    title  += nom + " " + prenom + tr("  connect\303\251 au serveur : ")+ m_pCMoteurBase->m_DriverName + " "+ m_pCMoteurBase->m_UserName+"@"+m_pCMoteurBase->m_HostName+":"+m_pCMoteurBase->m_Port;
   }
else
   {title  += tr("Manager-V %1 connect\303\251 au serveur : ").arg(G_pCApp->getNumVers())+ m_pCMoteurBase->m_DriverName + " "+ m_pCMoteurBase->m_UserName+"@"+m_pCMoteurBase->m_HostName+":"+m_pCMoteurBase->m_Port;
   }
setCaption(title);
}
//--------------------------------- Slot_actionMenuNew_clicked -----------------------------------------------------------------------
void C_Manager::Slot_actionMenuNew_clicked( bool )
{Slot_pushButtonNew_clicked();
}

//--------------------------------- Slot_pushBut_ExitMultiCritere -----------------------------------------------------------------------
void C_Manager::Slot_pushBut_ExitMultiCritere()
{setInterfaceOnProfil(MODE_SELECTION_PATIENT);
}
//--------------------------------- Slot_pushButton_Effacer_clicked -----------------------------------------------------------------------
void C_Manager::Slot_pushButton_Effacer_clicked()
{clearIdentFields();
}
//--------------------------------- Slot_pushButton_MultiCritere -----------------------------------------------------------------------
void C_Manager::Slot_pushButton_MultiCritere()
{ if (identIsModified() && G_pCApp->isCurrentIdentiteValid() && G_pCApp->IsThisDroitExist(G_pCApp->m_Droits, "idc") )
    { Slot_pushButtonSavModif();
    }
setInterfaceOnProfil(MODE_MULTICRITERE);
}
//--------------------------------- Slot_pushBut_MultiCritFind -----------------------------------------------------------------------
void C_Manager::Slot_pushBut_MultiCritFind()
{ //............... faire la recherche multicritere .......................
QString dtNss = m_pGUI->lineEdit_DtNss->text().remove('-');
if (dtNss.length()==8) dtNss = dtNss.mid(4,4)+"-"+dtNss.mid(2,2)+"-"+dtNss.mid(0,2)+" 00:00:00";
else                   dtNss = "";
QString numSecu  = m_pGUI->lineEdit_NumSecu->text().remove(' ');
if (numSecu.length()==0)           numSecu  = "";
else  if (numSecu.length()==13)    numSecu += CMoteurBase::ComputeClef_Secu(numSecu);
else                               numSecu += "%";
QString sexe     = m_pGUI->comboBoxSexe->currentText().left(1).upper();
QString cdPost   = m_pGUI->lineEdit_CdPostal->text().remove(' ');
if (cdPost.length()==0 || cdPost.toInt()==0)   cdPost  = "";
else if (cdPost.length()<5)                    cdPost += "%";

         G_pCApp->m_pCMoteurBase->GetPatientListFromNomPrenomSecuDtNssGeme( m_pGUI->listView_Patient,
                                                                            m_pGUI->lineEdit_NomDossier->text().trimmed(),                         // nom
                                                                            m_pGUI->lineEdit_PrenomDossier->text().trimmed(),                      // prenom
                                                                            dtNss,                                            // date Nss // doit etre 1993-06-01 00:00:00
                                                                            numSecu,                               // num secu // 160196296519557
                                                                            m_pGUI->lineEdit_RangGeme->text().trimmed(),                     // rang gemellaire
                                                                            "255",     // qualite d'ayant droit 255 pour ne pas requetter dessus
                                                                            m_pGUI->textEdit_Adresse->text().trimmed(),      //  adresse,
                                                                            cdPost,                                          //  codePost,
                                                                            m_pGUI->lineEditVille->text().trimmed(),         //  ville,
                                                                            sexe,              //  sexe,
                                                                            m_pGUI->lineEdit_Profession->text().trimmed(),      //  profession,
                                                                            m_pGUI->lineEdit_NomDeNss->text().trimmed(),      //  nomJfille
                                                                            m_pGUI->lineEdit_NomAssure->text().trimmed(),      //  nomAss,
                                                                            m_pGUI->lineEdit_PrenomAssure->text().trimmed(),      //  prenomAss,
                                                                            m_pGUI->lineEdit_Tel1->text().trimmed(),      //  tel1,
                                                                            m_pGUI->lineEdit_Tel2->text().trimmed(),      //  tel2,
                                                                            m_pGUI->lineEdit_Tel3->text().trimmed(),      //  tel3,
                                                                            m_pGUI->lineEdit_Email->text().trimmed(),      //  email,
                                                                            " LIKE ",   //  egal_like  " = ",
                                                                            m_pGUI->textLabel_StateList
                                                                          );
}

//--------------------------------- SetInterfaceOnProfil -----------------------------------------------------------------------
// #define MODE_SELECTION_PATIENT 1
// #define MODE_CREATION_PATIENT  2
// #define MODE_MULTICRITERE      3
void C_Manager::setInterfaceOnProfil(int mode)
{
if (G_pCApp->IsThisDroitExist("idv"))
   {
   }
 //................... bouton creer et acceder ou creer ...........................
if (CGestIni::Param_ReadUniqueParam(G_pCApp->m_LocalParam, "Derniere Session", tr("Mode de creation dossier")).lower()[0] == 'a' &&
    G_pCApp->IsThisDroitExist("idg")
   )
   {m_pGUI->pushButtonCreate->setText(tr("&Cr\303\251er et acc\303\251der"));
   }
else
   {m_pGUI->pushButtonCreate->setText(tr("&Cr\303\251er le dossier"));
   }
 if (G_pCApp->IsThisDroitExist("adm")) m_action_DebloquerBases->setVisible( TRUE );
 else                                  m_action_DebloquerBases->setVisible( FALSE );
 if (G_pCApp->IsThisDroitExist("nog")) m_action_ModeNomade->setEnabled ( G_pCApp->m_IsGestionNomadisme );
 else                                  m_action_ModeNomade->setEnabled ( FALSE );
//........................... MODE_SELECTION_PATIENT ...........................
m_InterfaceMode = mode;

switch (mode)
{case MODE_SELECTION_PATIENT:
     {QString style  = getBoxStyle(mode);
      m_pGUI->groupBoxPatient->setStyleSheet(style);
      m_pGUI->groupBoxAssure->setStyleSheet(style);
      //m_pGUI->tabWidgetNotes->setStyleSheet(style);

      m_pGUI->pushButtonCancelCreate->hide();
      m_pGUI->pushButtonCreate->hide();
      m_pGUI->pushBut_ExitMultiCritere->hide();
      m_pGUI->pushButton_Effacer->hide();
      m_pGUI->pushBut_MultiCritFind->hide();

       //........ creer et modifier un dossier .................
      if (G_pCApp->IsThisDroitExist("idc"))
         {m_pGUI->pushButtonNew->show();
          m_action_NouveauDossier->setEnabled(TRUE);
          m_pGUI->pushButtonMenuNew->show();
          m_pGUI->pushButtonSavModif->show();
         }
      else
         {m_pGUI->pushButtonNew->hide();
          m_action_NouveauDossier->setEnabled(FALSE);
          m_pGUI->pushButtonMenuNew->hide();
          m_pGUI->pushButtonSavModif->hide();
         }
      //.......... lancer un dossier ...............
      if (G_pCApp->IsThisDroitExist("idg"))
         {m_pGUI->pushButtonAcceder->show();
         }
      else
         {m_pGUI->pushButtonAcceder->hide();
         }
      //.......... detruire un dossier ..............
      if (G_pCApp->IsThisDroitExist("idd"))
         {m_pGUI->pushButtonDetruire->hide();
         }
      else
         {m_pGUI->pushButtonDetruire->show();
          m_pGUI->pushButtonDetruire->setEnabled(TRUE);
         }
      m_pGUI->pushButtonVitale->show();
      m_pGUI->pushButton_MultiCritere->show();
      //.......... lancer une FSE ...............          //Cz_Pyxvital ????    Ajouter un droit d'accÃ¨s FSE
      if (G_pCApp->IsThisDroitExist("fse"))
         {m_pGUI->pushButton_FSE->show();
         }
      else
         {m_pGUI->pushButton_FSE->hide();
         }
     }break;
 //........................... MODE_CREATION_PATIENT ...............................
 case MODE_CREATION_PATIENT:
     {if (G_pCApp->IsThisDroitExist("idc"))
         { QString style  = getBoxStyle(mode);
           m_pGUI->groupBoxPatient->setStyleSheet(style);
           m_pGUI->groupBoxAssure->setStyleSheet(style);

           m_pGUI->pushButtonCancelCreate->show();
           m_pGUI->pushButtonCreate->show();


           m_pGUI->pushButtonSavModif->hide();
           m_pGUI->pushButtonAcceder->hide();
           m_pGUI->pushBut_ExitMultiCritere->hide();
           m_pGUI->pushButton_Effacer->hide();
           m_pGUI->pushButtonDetruire->hide();
           m_pGUI->pushButtonNew->hide();
           m_action_NouveauDossier->setEnabled(FALSE);
           //m_pGUI->pushButtonMenuNew->hide();
           //m_pGUI->pushButtonVitale->hide();
           m_pGUI->pushButton_MultiCritere->hide();
           m_pGUI->pushBut_MultiCritFind->hide();
           m_pGUI->pushButton_FSE->hide();                 //Cz_Pyxvital


           m_pGUI->groupBoxPatient->setEnabled ( TRUE );
           m_pGUI->groupBoxAssure->setEnabled ( TRUE );
           m_pGUI->tabWidgetNotes->setEnabled ( TRUE );

         }
     }break;
 //........................... MODE_MULTICRITERE ...........................
 case MODE_MULTICRITERE:
     {QString style  = getBoxStyle(mode);
      m_pGUI->groupBoxPatient->setStyleSheet(style);
      m_pGUI->groupBoxAssure->setStyleSheet(style);

      m_pGUI->pushBut_ExitMultiCritere->show();
      m_pGUI->pushButton_Effacer->show();
      m_pGUI->pushBut_MultiCritFind->show();

      m_pGUI->pushButtonCancelCreate->hide();
      m_pGUI->pushButtonCreate->hide();
      m_pGUI->pushButtonSavModif->hide();
      m_pGUI->pushButtonAcceder->hide();
      m_pGUI->pushButtonDetruire->hide();
      m_pGUI->pushButtonNew->hide();
      m_action_NouveauDossier->setEnabled(FALSE);
      m_pGUI->pushButtonMenuNew->hide();
      m_pGUI->pushButtonVitale->hide();
      m_pGUI->pushButton_MultiCritere->hide();
      m_pGUI->pushButton_FSE->hide();                 //Cz_Pyxvital

      m_pGUI->groupBoxPatient->setEnabled ( TRUE );
      m_pGUI->groupBoxAssure->setEnabled ( TRUE );
      m_pGUI->tabWidgetNotes->setEnabled ( TRUE );

     }break;
}

}
//------------------------------------------- setIdentiteEnabled -----------------------------------------------------------------------
void C_Manager::setIdentiteEnabled()
{m_pGUI->pushButton_FSE->setEnabled (TRUE );                 //Cz_Pyxvital
if (m_pGUI->groupBoxPatient->isEnabled()) return;
m_pGUI->groupBoxPatient->setEnabled ( TRUE );
m_pGUI->groupBoxAssure->setEnabled ( TRUE );
m_pGUI->tabWidgetNotes->setEnabled ( TRUE );
m_pGUI->pushButtonAcceder->setEnabled (TRUE );

}

//------------------------------------------- setIdentiteDisabled -----------------------------------------------------------------------
void C_Manager::setIdentiteDisabled()
{if (! m_pGUI->groupBoxPatient->isEnabled()) return;
m_pGUI->groupBoxPatient->setEnabled (FALSE );
m_pGUI->groupBoxAssure->setEnabled (FALSE );
m_pGUI->tabWidgetNotes->setEnabled (FALSE );
m_pGUI->pushButtonAcceder->setEnabled ( FALSE );
m_pGUI->pushButton_FSE->setEnabled (FALSE );                 //Cz_Pyxvital

}

//--------------------------------- setIdentModifiedState -----------------------------------------------------------------------
void C_Manager::setIdentModifiedState(int state)
{if (G_pCApp->isCurrentIdentiteValid() && !isVerrou() )
   {m_Ident_IsModified = state;
    if (m_Ident_IsModified) m_pGUI->pushButtonSavModif->setEnabled(TRUE);
    else                    m_pGUI->pushButtonSavModif->setEnabled(FALSE);
   }
else  // si identite invalide ou verrouillee on dit que le dossier n'est pas modifie
   {m_Ident_IsModified = FALSE;
    m_pGUI->pushButtonSavModif->setEnabled(FALSE);
   }
}

//------------------------------------------- setVerrouForCurrentIdent -----------------------------------------------------------------------
void C_Manager::setVerrouForCurrentIdent()
{if (G_pCApp->isCurrentIdentiteValid())
   { setVerrou(m_pCMoteurBase->IsDossierVerrouille( G_pCApp->identitePatientGUID()));
   }
else
   { setVerrou(FALSE);
   }
}

//------------------------------------------- setVerrou -----------------------------------------------------------------------
void C_Manager::setVerrou(bool state)
{m_IsVerrouOn = state;
if (state){ m_pGUI->pushButtonAcceder->setIcon ( Theme::getIcon("listview_locked.png") );
            m_pGUI->pushButtonDetruire->setEnabled(FALSE);
          }
else      { m_pGUI->pushButtonAcceder->setIcon ( Theme::getIcon("listview_acceder.png") );
            m_pGUI->pushButtonDetruire->setEnabled(TRUE);
          }
}

///////////////////////////////////////// TRAITEMENT SPECIAUX DES CONTROLES DE CHAMP ////////////////////////////////////////
//--------------------------------- setSexFromQualiteAyantDroit -------------------------------------------------------------
int C_Manager::setSexFromQualiteAyantDroit(int qualiteAyantDroit)
{       QString nss =  m_pGUI->lineEdit_NumSecu->text();
       switch(qualiteAyantDroit)
             {case 0:    // assure
                       {if (nss[0]=='1')  m_pGUI->comboBoxSexe->setCurrentItem ( 0 ) ;
                        else              m_pGUI->comboBoxSexe->setCurrentItem ( 1 ) ;
                        tryToSetTitreFromDateNss();  // regler le TITRE
                       } break;
              case 2:   // conjoint
              case 3:   // conjoint divorc\303\251
              case 4:   // concubin
              case 5:   // conjoint separe
              case 7:   // conjoint veuf
                       {if (nss[0]=='1')  m_pGUI->comboBoxSexe->setCurrentItem ( 1 ) ;
                        else              m_pGUI->comboBoxSexe->setCurrentItem ( 0 ) ;
                         tryToSetTitreFromDateNss();  // regler le TITRE
                       } break;
              default: {m_pGUI->lineEdit_Titre->setText("");
                        m_pGUI->comboBoxSexe->setCurrentItem ( 2 ) ;
                       } break;
             }
   return m_pGUI->comboBoxSexe->currentItem();
}
//--------------------------------- Slot_pushButtonInfoClicked -------------------------------------------------------------
void C_Manager::Slot_pushButtonInfoClicked()
{QWhatsThis::showText (QCursor().pos(), tr("<font color=\"#000000\">Pour chercher par le nom et le pr\303\251nom, il faut s\303\251parer le pr\303\251nom du nom par un point-virgule. Exemple : <b>MARTIN;JEAN</b><br><br>"
                         "Le Symbole pour cent % plac\303\251 avant ou apr\303\250s le nom ou pr\303\251nom permet de faire une recherche sur tout ce qui contient l'expression<br>"
                         "Exemple :  <b>%MART;%JE</b> cherchera toutes les personnes dont le nom contient : <b>MART</b> et dont le pr\303\251nom contient : <b>JE</b></font>" ));
}

//---- AYANT DROIT ------------- tryToSetInterfaceFromAyantDroit ---------------------------------------------------------------------------------
void  C_Manager::tryToSetInterfaceFromAyantDroit( int qualiteAssure, int focusMustBePotionned)
{if (qualiteAssure ==0)
   {m_pGUI->lineEdit_NomAssure->setEnabled(FALSE);
    m_pGUI->lineEdit_PrenomAssure->setEnabled(FALSE);
    m_pGUI->lineEdit_DtNss_Assure->setEnabled(FALSE);
    //QString        dtNss      = m_pGUI->lineEdit_DtNss->text().remove('-');
    //QDate        qDteNss(dtNss.mid(4,4).toInt(), dtNss.mid(2,2).toInt(),  dtNss.mid(0,2).toInt()  );
    //if (qDteNss.isValid () )    m_pGUI->lineEdit_DtNss_Assure->setText(lineEdit_DtNss_Assure->text());
   }
else
   {m_pGUI->lineEdit_NomAssure->setEnabled(TRUE);
    m_pGUI->lineEdit_PrenomAssure->setEnabled(TRUE);
     m_pGUI->lineEdit_DtNss_Assure->setEnabled(TRUE);
    if (m_pGUI->lineEdit_NumSecu->text().remove(' ').length()==13 && m_pGUI->lineEdit_NumSecu->hasFocus() &&
        focusMustBePotionned)      m_pGUI->lineEdit_NomAssure->setFocus();
    if (m_pGUI->lineEdit_NomAssure->text().trimmed().length()==0)                               m_pGUI->lineEdit_NomAssure->setText(m_pGUI->lineEdit_NomDossier->text());
    if (m_pGUI->lineEdit_PrenomAssure->text().trimmed().length()==0)                            m_pGUI->lineEdit_PrenomAssure->setText(m_pGUI->lineEdit_PrenomDossier->text());
   }
}

//-- DATE NAISSANCE --------------------------------- Slot_OutFocuslineEdit_DtNss -----------------------------------------------------------------------
void C_Manager::Slot_OutFocuslineEdit_DtNss(QFocusEvent*, int &)
{ tryToSetTitreFromDateNss();
}

//------------------------------------------- tryToSetTitreFromDateNss -----------------------------------------------------------------------
void C_Manager::tryToSetTitreFromDateNss()
{
   // `HistN0_Date`  >=  "2001-05-19T11:09:40" AND `HistN0_Date`  <=  "2001-05-20T11:09:41";
   QString resolvToken("");
   QString        dtNss      = m_pGUI->lineEdit_DtNss->text().remove('-');
   QDate        qDteNss(dtNss.mid(4,4).toInt(), dtNss.mid(2,2).toInt(),  dtNss.mid(0,2).toInt()  );
   if (qDteNss.isValid () )
      {QString sAge = m_pCMoteurBase->CalculeDiffAge(&qDteNss, 0, TRUE, 0);
       m_pGUI->groupBoxPatient->setTitle(tr("Patient (b\303\251n\303\251ficiaire) \303\242g\303\251 de : ")+sAge);
       int i = 0; while (sAge[i]>='0' && sAge[i]<='9') ++i; sAge.truncate(i);
       int               age      = sAge.toInt();

       if (age < 15)                                              resolvToken="L'enfant";
       if (age >= 15 && age <= 21)
          { if (m_pGUI->comboBoxSexe->currentItem()==1)           resolvToken="Mademoiselle";
            else if (m_pGUI->comboBoxSexe->currentItem()==0)      resolvToken="Monsieur";
            else                                                  resolvToken="";
          }
       if (age>21)
          {if (m_pGUI->comboBoxSexe->currentItem()==1)            resolvToken="Madame";
           else if (m_pGUI->comboBoxSexe->currentItem()==0)       resolvToken="Monsieur";
           else                                                   resolvToken="";
          }
       m_pGUI->lineEdit_Titre->setText(resolvToken);
      }
   else
      {m_pGUI->groupBoxPatient->setTitle(tr("Patient (b\303\251n\303\251ficiaire) avec une date de naissance non valide"));
       m_pGUI->lineEdit_Titre->setText("");
      }
}

//-- VILLE --------------------------------- Slot_OutFocusVille -----------------------------------------------------------------------
void C_Manager::Slot_OutFocusVille(QFocusEvent*, int &)
{tryToSetCodePostalFromVille();
}

//------------------------------------------- tryToSetCodePostalFromVille -----------------------------------------------------------------------
void C_Manager::tryToSetCodePostalFromVille()
{//if (m_pCMoteurBase==0) return;
   QString codePostal("");
   QString ville = m_pGUI->lineEditVille->text().trimmed();
   //.......... si pas de ville saisie on tente avec le code postal .........................
   if (ville.length()==0)
      {tryToSetVilleFromCodePostal();
       return;
      }
   //............... chercher liste de codepostaux pouvant correspondre \303\240 cette ville .............
   QStringList codePostalList;
   m_pCMoteurBase->GetCodePostalFromVille( ville.replace("SAINT ","ST "),  codePostalList);
   if (codePostalList.findIndex ( m_pGUI->lineEdit_CdPostal->text().remove(' ') + " " + m_pGUI->lineEditVille->text() ) != -1 ) return;

   int nb = codePostalList.count();
   if (nb==1)
      {codePostal = codePostalList[0];
      }
   else if (nb>1 && nb<35 )
      {//............... deconnecter car lors popup on va quitter le champ lineEditVille .................
       //                pour eviter de rerentrer ici en boucle
       QObject::disconnect( m_pGUI->lineEditVille, SIGNAL( Sign_focusOutEvent(QFocusEvent*, int &)), this,     SLOT(   Slot_OutFocusVille(QFocusEvent*, int &))  );
       codePostal = G_pCApp->DoPopupList(codePostalList);
       connect( m_pGUI->lineEditVille,             SIGNAL( Sign_focusOutEvent(QFocusEvent*, int &)), this,     SLOT(   Slot_OutFocusVille(QFocusEvent*, int &))  );
      }
   //............ separer la ville du code postal ...................................................
   int pos = codePostal.find(' ');
   if (pos != -1)
      {ville      = codePostal.mid(pos+1);
       codePostal = codePostal.left(pos);
      }
   if (//lineEdit_CdPostal->text().length()<5           ||                               // si code postal incomplet
       (codePostal.length()!=0 /*&& lineEdit_CdPostal->text() != codePostal */)            // ou non conforme avec celui de la ville
      )
      {m_pGUI->lineEdit_CdPostal->setText(codePostal );                                        // placer celui de la ville
       m_pGUI->lineEditVille->setText(ville);
       return;
      }
   //.............. si pas de code postal trouv\303\251 pour cette ville tenter de placer la ville du code postal .............
   if (codePostal.length()==0 )
      {ville = m_pCMoteurBase->GetVilleFromCodePostal(m_pGUI->lineEdit_CdPostal->text().remove(' '));
       if (ville.length()!=0) m_pGUI->lineEditVille->setText(ville);
      }
}

//-- CODE POSTAL --------------------------------- Slot_OutFocusCodePostal -----------------------------------------------------------------------
void C_Manager::Slot_OutFocusCodePostal(QFocusEvent*, int &)
{tryToSetVilleFromCodePostal();
}

//------------------------------------------- Slot_CharEventCodePostal -----------------------------------------------------------------------
void C_Manager::Slot_CharEventCodePostal(QKeyEvent *event, int &ret)
{ // on incorpore le caractere dans la QLineEdit car ce n'est pas encore fait
 // lors de l'appel de ce Slot par  C_QLineEdit
 m_pGUI->lineEdit_CdPostal->doParentPressEvent(event);
 ret = 0;    // du coup plus besoin d'\303\252tre trait\303\251 en retour de slot par C_QLineEdit
 //.......... maintenant  on  traite le code postal .................
 //           en appelant directement la fonction de contrôle
 tryToSetVilleFromCodePostal();
}

//------------------------------------------- tryToSetVilleFromCodePostal -----------------------------------------------------------------------
void C_Manager::tryToSetVilleFromCodePostal()
{   QStringList villeList;
   QString codePostal = m_pGUI->lineEdit_CdPostal->text().remove(' ');
   if (codePostal.length()==5)
   {m_pCMoteurBase->GetVilleFromCodePostal(codePostal, villeList);
       int nb = villeList.count();
       if (nb==1)
          {m_pGUI->lineEditVille->setText(villeList[0]);
          }
       else if (nb>1 && nb<35 )
       {if (villeList.findIndex ( m_pGUI->lineEditVille->text()) == -1 )  // si la ville ne correspond pas au code postal
           {//............... deconnecter car lors popup on va quitter le champ lineEdit_CdPostal .................
            //                pour eviter de rerentrer ici en boucle
            QObject::disconnect( m_pGUI->lineEdit_CdPostal, SIGNAL( Sign_focusOutEvent(QFocusEvent*, int &)),    this,     SLOT(   Slot_OutFocusCodePostal(QFocusEvent*, int &))  );
            QString ville = G_pCApp->DoPopupList(villeList);
            if (ville.length()>0) m_pGUI->lineEditVille->setText(ville);
            connect( m_pGUI->lineEdit_CdPostal, SIGNAL( Sign_focusOutEvent(QFocusEvent*, int &)),                this,     SLOT(   Slot_OutFocusCodePostal(QFocusEvent*, int &))  );
           }
       }
   }
   else
   {m_pGUI->lineEditVille->clear();
   }
}

//-- NUM SECU --------------------------------- Slot_CharEventNumSecu -----------------------------------------------------------------------
void C_Manager::Slot_CharEventNumSecu(QKeyEvent *event, int &ret)
{ // on incorpore le caractere dans la QLineEdit car ce n'est pas encore fait
 // lors de l'appel de ce Slot par  C_QLineEdit
 m_pGUI->lineEdit_NumSecu->doParentPressEvent(event);
 ret = 0;    // du coup plus besoin d'\303\252tre trait\303\251 en retour de slot par C_QLineEdit
 //.......... maintenant  on  traite le code postal .................
 //           en appelant directement la fonction de contrôle
 QString numsecu = m_pGUI->lineEdit_NumSecu->text().remove(' ');  //18105m_IsModifiable = 0;
 if (numsecu.length()==13)
      {m_pGUI->lineEdit_NssClef->setText(m_pCMoteurBase->ComputeClef_Secu(numsecu));
      }
   else
      {m_pGUI->lineEdit_NssClef->clear();
      }
}
// ---------------------------------------------- Slot_InFocusNumSecu  --------------------------------------------------------------
void C_Manager::Slot_InFocusNumSecu(QFocusEvent*, int &)
{   QString numsecu = m_pGUI->lineEdit_NumSecu->text().remove(' ');  //18105m_IsModifiable = 0;

   if (numsecu.length()==0)
      { if (m_pGUI->comboBoxSexe->currentItem() != 1)  numsecu += "1";
        else                                           numsecu += "2";
        QString dtnss = m_pGUI->lineEdit_DtNss->text().remove('-');
        if (dtnss.length()==8)
           {numsecu += dtnss.mid(6);
            numsecu += dtnss.mid(2,2);
           }
        m_pGUI->lineEdit_NumSecu->setText(numsecu);
        m_pGUI->lineEdit_NumSecu->setCursorPosition (numsecu.length());
      }
}

//---------------------------------------------- Slot_OutFocusNumSecu ----------------------------------------------
void C_Manager::Slot_OutFocusNumSecu(QFocusEvent*, int &)
{   QString numsecu = m_pGUI->lineEdit_NumSecu->text().remove(' ');  //18105
   if (numsecu.length()==13)
      {m_pGUI->lineEdit_NssClef->setText(m_pCMoteurBase->ComputeClef_Secu(numsecu));
      }
   else
      {m_pGUI->lineEdit_NssClef->clear();
      }

   QString leftNumSecu("");
   if (m_pGUI->comboBoxSexe->currentItem() != 1) leftNumSecu += "1";
   else                                          leftNumSecu += "2";
   QString dtnss = m_pGUI->lineEdit_DtNss->text().remove('-');
   if (dtnss.length()==8)
      {   leftNumSecu += dtnss.mid(6);
          leftNumSecu += dtnss.mid(2,2);
      }
   if (numsecu.length()>=5 && leftNumSecu.length()>=5 && leftNumSecu != numsecu.left(5))
      { QObject::disconnect( m_pGUI->lineEdit_NumSecu, SIGNAL( Sign_focusInEvent(QFocusEvent*, int &)),           this,     SLOT(   Slot_InFocusNumSecu(QFocusEvent*, int &))  );
        QObject::disconnect( m_pGUI->lineEdit_NumSecu, SIGNAL( Sign_focusOutEvent(QFocusEvent*, int &)),          this,     SLOT(   Slot_OutFocusNumSecu(QFocusEvent*, int &))  );
       if (m_pGUI->comboBoxQualiteAyantDroit->currentItem()==0) m_pGUI->comboBoxQualiteAyantDroit->setCurrentItem(9);  // autre ayant droit
       m_pGUI->lineEdit_NomAssure->setEnabled(TRUE);
       m_pGUI->lineEdit_PrenomAssure->setEnabled(TRUE);
       if (m_pGUI->lineEdit_NomAssure->text()=="")     m_pGUI->lineEdit_NomAssure->setText(m_pGUI->lineEdit_NomDossier->text());
       if (numsecu.length()==13 && m_pGUI->lineEdit_NumSecu->hasFocus())
          {m_pGUI->lineEdit_NomAssure->setFocus();
           m_pGUI->lineEdit_NomAssure->setCursorPosition (-1);
          }
       connect( m_pGUI->lineEdit_NumSecu, SIGNAL( Sign_focusInEvent(QFocusEvent*, int &)),           this,     SLOT(   Slot_InFocusNumSecu(QFocusEvent*, int &))  );
       connect( m_pGUI->lineEdit_NumSecu, SIGNAL( Sign_focusOutEvent(QFocusEvent*, int &)),          this,     SLOT(   Slot_OutFocusNumSecu(QFocusEvent*, int &))  );
     }
   else
      {m_pGUI->comboBoxQualiteAyantDroit->setCurrentItem(0);
       m_pGUI->lineEdit_NomAssure->setEnabled(FALSE);
       m_pGUI->lineEdit_PrenomAssure->setEnabled(FALSE);
      }
}

////////////////////////////////////// DETECTION DES MODIFICATIONS DE LA FICHE IDENTITE ////////////////////////////////////////////////////////
//........................ Slot_TextChanged_lineEdit_NomDossier ............................................................................................
void C_Manager::Slot_TextChanged_lineEdit_NomDeNss(const QString & )
{setIdentModifiedState(TRUE);
}
void C_Manager::Slot_TextChanged_lineEdit_DtNss(const QString & )
{setIdentModifiedState(TRUE);
}
void C_Manager::Slot_TextChanged_lineEdit_Titre(const QString & )
{setIdentModifiedState(TRUE);
}
void C_Manager::Slot_TextChanged_lineEdit_Profession(const QString & )
{setIdentModifiedState(TRUE);
}
void C_Manager::Slot_TextChanged_textEdit_Adresse( )
{setIdentModifiedState(TRUE);
}
void C_Manager::Slot_TextChanged_lineEdit_Tel1(const QString & )
{setIdentModifiedState(TRUE);
}
void C_Manager::Slot_TextChanged_lineEdit_Tel2(const QString & )
{setIdentModifiedState(TRUE);
}
void C_Manager::Slot_TextChanged_lineEdit_Tel3(const QString & )
{setIdentModifiedState(TRUE);
}
void C_Manager::Slot_TextChanged_lineEdit_CdPostal(const QString & )
{setIdentModifiedState(TRUE);
}
void C_Manager::Slot_TextChanged_lineEditVille(const QString & )
{setIdentModifiedState(TRUE);
}
void C_Manager::Slot_TextChanged_lineEdit_Email(const QString & )
{setIdentModifiedState(TRUE);
}
void C_Manager::Slot_TextChanged_lineEdit_NumSecu(const QString & )
{setIdentModifiedState(TRUE);
}
void C_Manager::Slot_TextChanged_lineEdit_NomAssure(const QString & )
{setIdentModifiedState(TRUE);
}
void C_Manager::Slot_TextChanged_lineEdit_PrenomAssure(const QString & )
{setIdentModifiedState(TRUE);
}
void C_Manager::Slot_TextChanged_textEdit_Note( )
{setIdentModifiedState(TRUE);
}
void C_Manager::Slot_TextChanged_lineEdit_DtNss_Assure(const QString &)
{setIdentModifiedState(TRUE);
}
void C_Manager::Slot_TextChanged_lineEdit_RangGeme(const QString &)
{setIdentModifiedState(TRUE);
}
void C_Manager::Slot_TextChanged_comboBoxSexe( const QString &)
{tryToSetTitreFromDateNss(); setIdentModifiedState(TRUE);
}
void C_Manager::Slot_TextChanged_comboBoxQualiteAyantDroit( const QString &)
{tryToSetInterfaceFromAyantDroit( m_pGUI->comboBoxQualiteAyantDroit->currentIndex(), 1); setIdentModifiedState(TRUE);
}

//////////////////////////////////////// LISTE DES PATIENTS ////////////////////////////////////////////////////////////////////////////////
//--------------------------------- Slot_giveDraglistView_PatientItemData -----------------------------------------------------------------------
void C_Manager::Slot_giveDraglistView_PatientItemData(QString &data, QTreeWidgetItem *pQTreeWidgetItem)
{   if (pQTreeWidgetItem==0) return;
   C_RendezVous rdv;
   rdv.m_GUID   = pQTreeWidgetItem->text(LIST_GUID);
   rdv.m_Nom    = pQTreeWidgetItem->text(LIST_NOM);
   rdv.m_Prenom = pQTreeWidgetItem->text(LIST_PRENOM);
   rdv.m_Tel    = "";
   if (G_pCApp->isCurrentIdentiteSame(pQTreeWidgetItem))
      {rdv.m_Tel    = m_pGUI->lineEdit_Tel1->text();
      }
   data = rdv.serialize(&rdv);
}

//--------------------------------- Slot_listView_Patient_Clicked -----------------------------------------------------------------------
void C_Manager::Slot_listView_Patient_Clicked( QTreeWidgetItem *pQListViewItem , int)
{
#ifdef SESAM_VERSION
if (pQListViewItem==0) return;
clearDroitsFields();
#endif
}

//--------------------------------- Slot_listView_Patient_DoubleClicked -----------------------------------------------------------------------
void C_Manager::Slot_listView_Patient_DoubleClicked( QTreeWidgetItem *, int)
{//Slot_pushButtonAcceder_Clicked();
// Cz_Pyxvital     si on ne gÃ¨re pas le dossier Patient on lance directement la FSE
if (m_Facture_Seule == "oui")
    Slot_pushButton_FSE();
else
    Slot_pushButtonAcceder_Clicked();

}

//--------------------------------- listPatientsByDateNss -----------------------------------------------------------------------
void C_Manager::listPatientsByDateNss(QString dateNss)
{
dateNss     = dateNss.insert(4,'-');                           //  19930601       -->  1993-0601
dateNss     = dateNss.insert(7,'-');                           //  1993-0601      -->  1993-06-01
dateNss    += " 00:00:00";                                     //  1993-0601      -->  1993-06-01 00:00:00
//m_pGUI->pushButtonCancel_clicked();
if (G_pCApp->m_pCMoteurBase->GetPatientListFromNomPrenomSecuDtNssGeme(m_pGUI->listView_Patient,         // pas de listview car on veut juste savoir si trouve
                                                                     "",         // nom
                                                                     "",         // prenom
                                                                     dateNss,    // date Nss // doit etre 1993-06-01 00:00:00
                                                                     "",         // num secu // 160196296519557
                                                                     "",         // rang gemellaire
                                                                     "",         // qualite d'ayant droit
                                                                     "",         // adresse,
                                                                     "",         // codePost,
                                                                     "",         // ville,
                                                                     "",         // sexe,
                                                                     "",         // profession,
                                                                     "",         //  nomJfille
                                                                     "",         //  nomAss,
                                                                     "",         //  prenomAss,
                                                                     "",         //  tel1,
                                                                     "",         //  tel2,
                                                                     "",         //  tel3,
                                                                     "",         //  email,
                                                                     " LIKE ",   // egal_like  " = ",
                                                                     m_pGUI->textLabel_StateList
                                                                   )
  )
  {
  }
}
//--------------------------------- Slot_ListView_ContextMenuRequested -----------------------------------------------------------------------
void C_Manager::Slot_ListView_ContextMenuRequested (const QPoint &)
{Slot_pushButtonMenuNew_clicked();
}

//--------------------------------- Slot_pushButtonMenuNew_clicked -----------------------------------------------------------------------
void C_Manager::Slot_pushButtonMenuNew_clicked()
{
QStringList list;
QTreeWidgetItem *pQListViewItem         = getSelectedListViewPatientItem();
QTreeWidgetItem *pQListViewItemVitale   = getSelectedListViewItem(m_pGUI->listView_Vitale);
if (pQListViewItem){if( getInterfaceMode()==MODE_CREATION_PATIENT)
                        list.append(tr("Utiliser les donn\303\251es de : %1 pour remplir celles du patient en cours de cr\303\251ation").arg(pQListViewItem->text(LIST_NOM)+" "+pQListViewItem->text(LIST_PRENOM)));
                    else
                        list.append(tr("Cr\303\251er un nouveau dossier en se servant des donn\303\251es de : ")+pQListViewItem->text(LIST_NOM)+" "+pQListViewItem->text(LIST_PRENOM));
                    list.append("-------------");
                   }
if (m_pGUI->listView_Doublons->isShown())  list.append(tr("Fermer la liste de r\303\251solution des doublons"));
else if (G_pCApp->IsThisDroitExist("adr")) list.append(tr("Ouvrir la liste de r\303\251solution des doublons"));
if (pQListViewItem){ //.............. verifier si pas verrouill\303\251 .................................if (!G_pCApp->IsThisDroitExist("adr")) return;
                     if (! m_pCMoteurBase->IsDossierVerrouille   ( pQListViewItem->text(LIST_GUID)) )
                        {if ( G_pCApp->IsThisDroitExist("adr")) list.append(tr("Placer ce patient : %1 dans la liste de r\303\251solution des doublons").arg(pQListViewItem->text(LIST_NOM)+" "+pQListViewItem->text(LIST_PRENOM)));
                         list.append("-------------");
                        }
                     else if (!G_pCApp->IsThisDroitExist("nbv"))
                        {list.append("-------------");
                         list.append(tr("D\303\251verrouiller le dossier de ce patient : %1 ").arg(pQListViewItem->text(LIST_NOM)+" "+pQListViewItem->text(LIST_PRENOM)));
                         list.append("-------------");
                        }

                     //list.append(tr("Rechercher par le nom : ")+lineEdit_NomDossier->text());
                     //list.append(tr("Rechercher par le pr\303\251nom : ")+lineEdit_PrenomDossier->text());
                     list.append(tr("Rechercher par la date de naissance : ")+m_pGUI->lineEdit_DtNss->text());
                     //list.append(tr("Rechercher par le n. de jeune fille : ")+lineEdit_NomDeNss->text());
                     list.append(tr("Rechercher par le num\303\251ro de s\303\251curit\303\251 sociale : ")+m_pGUI->lineEdit_NumSecu->text());
                     list.append(tr("Rechercher avec le nom le pr\303\251nom et la date de naissance : ")  +m_pGUI->lineEditAutoLocator->text().replace(";"," ")+" "+m_pGUI->lineEdit_DtNss->text());
                   }
 #ifdef SESAM_VERSION
if (pQListViewItemVitale && pQListViewItem)
   {QString dnss      = pQListViewItemVitale->text(2).left(8);             //  199306010000   -->  19930601
    dnss = dnss.mid(6,2)+"-"+dnss.mid(4,2)+"-"+dnss.mid(0,4);
    if (dnss==m_pGUI->lineEdit_DtNss->text())
       {list.prepend("-------------");
        list.prepend(tr("#22x22/VitaleButtLitle.png#Associer la carte vitale s\303\251lectionn\303\251e : %1 \303\240 ce patient : %2").arg(pQListViewItemVitale->text(0)+" "+pQListViewItemVitale->text(1),pQListViewItem->text(LIST_NOM)+" "+pQListViewItem->text(LIST_PRENOM)));
       }
   }
#endif
QString      ret = G_pCApp->DoPopupList(list,"");
bool pas_present = TRUE;
switch((int)(QChar(ret[0]).latin1()))
   {
   #ifdef SESAM_VERSION
    case 'A':
      { setCVonPatient ( G_pCApp->m_pVitale, pQListViewItemVitale->text(8).toInt());
      } break;
   #endif
    case 'D':
      {m_pCMoteurBase->DeVerrouilleDossier ( pQListViewItem->text(LIST_GUID));
       pQListViewItem->setIcon ( 0, QIcon() );
      } break;
    case 'P':
      {m_pGUI->listView_Doublons->show();
       QTreeWidgetItem *pQListViewItem_D = 0;
       //.............. verifier si pas deja present .................................
       QTreeWidgetItemIterator it (m_pGUI->listView_Doublons);
       while (*it)
             { pQListViewItem_D = (*it);
               if (pQListViewItem->text(LIST_PK_PATIENT) == pQListViewItem_D->text(LIST_PK_PATIENT))
                  {pas_present = FALSE;
                   break;
                  }
               ++it;
             }
       if (pas_present)
          {pQListViewItem_D = new QTreeWidgetItem(*pQListViewItem);   // copie de pQListViewItem
           if (pQListViewItem_D) m_pGUI->listView_Doublons->addTopLevelItem(pQListViewItem_D);
          }
       else
          {G_pCApp->CouCou(tr("Le patient : %1 \r\nest d\303\251j\303\240 pr\303\251sent dans la liste \r\nde r\303\251solution des doublons").arg(pQListViewItem->text(LIST_NOM)+" "+pQListViewItem->text(LIST_PRENOM)));
          }
       //.............. verifier si pas verrouill\303\251 .................................
       /*               inutile car normalement ne devrait pas etre possible
                        car si verrouille le menu ne permet pas d'ajout au doublon
       QString usedBy;
       if (m_pCMoteurBase->IsDossierVerrouille   ( pQListViewItem_D->text(LIST_GUID), usedBy ))
          {pQListViewItem_D->setIcon ( 0, QIcon(Theme::getIcon( "16x16/locked.png")) );
           pQListViewItem_D->setText ( 4, usedBy );
          }
       else
          {pQListViewItem_D->setIcon ( 0, QIcon() );
           pQListViewItem_D->setText ( 4, "" );
          }
       */
       break;
      }
    case 'U':
     {m_pGUI->textEdit_Note->clear();
      m_pGUI->listView_Praticiens->clear();
      DataToFormulaire( pQListViewItem );
      break;
     }
    case 'C':
     {m_pGUI->textEdit_Note->clear();
      m_pGUI->listView_Praticiens->clear();
      Slot_NewDossWithoutErase();
      break;
     }
    case 'N':
     {Slot_pushButtonNew_clicked();
      break;
     }
    case 'F':
      {m_pGUI->listView_Doublons->hide();
       break;
      }
    case 'O':
      {m_pGUI->listView_Doublons->show();
       break;
      }
    case 'R':
      {QString nom     = "";
       QString prenom  = "";
       QString dtNss   = "";
       QString numSecu = "";
       QString jeuneF  = "";
       if      (ret.find(tr("le nom"))!=-1)       nom        =   QString("%")+m_pGUI->lineEdit_NomDossier->text()+"%";
       if      (ret.find(tr("pr\303\251nom"))!=-1)       prenom     =   QString("%")+m_pGUI->lineEdit_PrenomDossier->text()+"%";
       dtNss = m_pGUI->lineEdit_DtNss->text().remove('-');
       if      (ret.find(tr("date"))!=-1)         dtNss      =   dtNss.mid(4,4)+"-"+dtNss.mid(2,2)+"-"+dtNss.mid(0,2)+ " 00:00:00";
       if      (ret.find(tr("num\303\251ro"))!=-1)       numSecu    =   QString("%")+m_pGUI->lineEdit_NumSecu->text().remove(' ')+"%";
       if      (ret.find(tr("jeune fille"))!=-1)  jeuneF     =   QString("%")+m_pGUI->lineEdit_NomDeNss->text()+"%";
       if (G_pCApp->m_pCMoteurBase->GetPatientListFromNomPrenomSecuDtNssGeme(m_pGUI->listView_Patient,         // pas de listview car on veut juste savoir si trouve
                                                                                    nom,        // nom
                                                                                    prenom,     // prenom
                                                                                    dtNss,      // date Nss // doit etre 1993-06-01 00:00:00
                                                                                    numSecu,    // num secu // 160196296519557
                                                                                    "",         // rang gemellaire
                                                                                    "",         // qualite d'ayant droit
                                                                                    "",         // adresse,
                                                                                    "",         // codePost,
                                                                                    "",         // ville,
                                                                                    "",         // sexe,
                                                                                    "",         // profession,
                                                                                    jeuneF,     //  nomJfille
                                                                                    "",         //  nomAss,
                                                                                    "",         //  prenomAss,
                                                                                    "",         //  tel1,
                                                                                    "",         //  tel2,
                                                                                    "",         //  tel3,
                                                                                    "",         //  email,
                                                                                    " LIKE ",   // egal_like  " = ",
                                                                                    m_pGUI->textLabel_StateList
                                                                                  )
                 )
                 {
                 }
       break;
      }
   }
}
//--------------------------------- Slot_TextChanged_lineEdit_NomDossier -----------------------------------------------------------------------
void C_Manager::Slot_TextChanged_lineEdit_NomDossier(const QString &nom)
{if (getInterfaceMode()==MODE_CREATION_PATIENT) initListePatient( nom, m_pGUI->lineEdit_PrenomDossier->text());
else                                           setIdentModifiedState(TRUE);
}
//--------------------------------- Slot_TextChanged_lineEdit_PrenomDossier -----------------------------------------------------------------------
void C_Manager::Slot_TextChanged_lineEdit_PrenomDossier(const QString &prenom)
{if (getInterfaceMode()==MODE_CREATION_PATIENT) initListePatient(m_pGUI->lineEdit_NomDossier->text(), prenom);
else                                           setIdentModifiedState(TRUE);
}

//--------------------------------- Slot_lineEditAutoLocator_keyPressEvent -----------------------------------------------------------------------
void C_Manager::Slot_lineEditAutoLocator_keyPressEvent(QKeyEvent *event, int &callStandardEvent)
{QTreeWidgetItem * pQTreeWidgetItem = 0;
switch(event->key())
  {case Qt::Key_Return:
   case Qt::Key_Enter:
         pQTreeWidgetItem = getSelectedListViewPatientItem();
         if (pQTreeWidgetItem==0 && m_pGUI->listView_Patient->topLevelItemCount()==1)
            {pQTreeWidgetItem = m_pGUI->listView_Patient->topLevelItem(0);
             if (pQTreeWidgetItem) pQTreeWidgetItem->setSelected(TRUE);
            }
         if (getInterfaceMode()==MODE_SELECTION_PATIENT) Slot_pushButtonAcceder_Clicked();
         callStandardEvent = 0;
        break;
   case Qt::Key_Down:
        {pQTreeWidgetItem = getSelectedListViewPatientItem();
         if (pQTreeWidgetItem)
            {QTreeWidgetItem * pQTreeWidgetItemBelow = m_pGUI->listView_Patient->itemBelow( pQTreeWidgetItem );
             if (pQTreeWidgetItemBelow)
                {pQTreeWidgetItem->setSelected(FALSE);
                 pQTreeWidgetItemBelow->setSelected(TRUE);
                }
            }
         else if (m_pGUI->listView_Patient->topLevelItemCount ())
            {pQTreeWidgetItem = m_pGUI->listView_Patient->topLevelItem(0);
             if (pQTreeWidgetItem) pQTreeWidgetItem->setSelected(TRUE);
            }
         callStandardEvent = 0;
        }
        break;
   case Qt::Key_Up:
        {pQTreeWidgetItem = getSelectedListViewPatientItem();
         if (pQTreeWidgetItem)
            {QTreeWidgetItem * pQTreeWidgetItemAbove = m_pGUI->listView_Patient->itemAbove( pQTreeWidgetItem );
             if (pQTreeWidgetItemAbove)
                {pQTreeWidgetItem->setSelected(FALSE);
                 pQTreeWidgetItemAbove->setSelected(TRUE);
                }
            }
         else if (m_pGUI->listView_Patient->topLevelItemCount ())
            {pQTreeWidgetItem = m_pGUI->listView_Patient->topLevelItem(0);
             if (pQTreeWidgetItem) pQTreeWidgetItem->setSelected(TRUE);
            }
         callStandardEvent = 0;
        }
        break;
  }
}

//--------------------------------- Slot_pushButton_ReinitListe_clicked -----------------------------------------------------------------------
void C_Manager::Slot_pushButton_ReinitListe_clicked()
{m_pGUI->lineEditAutoLocator->setText("");
m_pGUI->lineEditAutoLocator->setFocus();
Slot_lineEditAutoLocator_textChanged("");
}

//--------------------------------- getSelectedListViewPatientItem -------------------------------------------------------------
QTreeWidgetItem * C_Manager::getSelectedListViewPatientItem()
{   return getSelectedListViewItem(m_pGUI->listView_Patient);
}

//--------------------------------- getSelectedListViewItem -------------------------------------------------------------
QTreeWidgetItem * C_Manager::getSelectedListViewItem(QTreeWidget *pQTreeWidget)
{QList<QTreeWidgetItem *> list = pQTreeWidget->selectedItems ();
if (list.count()) return list[0];
return 0;
}

//--------------------------------- Slot_ListView_itemSelectionChanged -------------------------------------------------------------
void C_Manager::Slot_ListView_itemSelectionChanged()
{
QTreeWidgetItem *pQListViewItem = getSelectedListViewPatientItem();
if (G_pCApp->isCurrentIdentiteSame(pQListViewItem))               return;
if (pQListViewItem==0)
   {G_pCApp->setCurrentIdentite(pQListViewItem);
    switch ( getInterfaceMode() )
           {case MODE_SELECTION_PATIENT:
                {setIdentiteDisabled();
                 setVerrouForCurrentIdent();
                }break;
            case MODE_CREATION_PATIENT:
                {setVerrouForCurrentIdent();
                }break;
            case MODE_MULTICRITERE:
                {setVerrouForCurrentIdent();
                }break;
           }
    return;
   }
//................... si besoin positionner le cadenas sur l'item  ...........
if (m_pCMoteurBase->IsDossierVerrouille   ( pQListViewItem->text(LIST_GUID)))
   {//pQListViewItem->setIcon ( 0, QIcon(Theme::getIcon( "16x16/locked.png")) );
   }
 else
   {//pQListViewItem->setIcon ( 0, QIcon() );
   }
//................... action de la selection selon interface ...........
switch ( getInterfaceMode() )
       {
        case MODE_SELECTION_PATIENT:
             {if (identIsModified() && G_pCApp->isCurrentIdentiteValid() && G_pCApp->IsThisDroitExist(G_pCApp->m_Droits, "idc") )
                 {/*  pas besoin de questionner c'est d\303\251j\303\240 fait dans la fonction : Slot_pushButtonSavModif()
                  int ret   = QMessageBox::warning ( this, tr("Enregistrer les modifications :"),
                                    tr( "<u><b>ATTENTION :</u></b><br>&nbsp;&nbsp;&nbsp;le dossier :<br>&nbsp;&nbsp; <b><font color=\"#e80d0d\">") +
                                    G_pCApp->m_LastNom  + " " + G_pCApp->m_LastPrenom  +
                                    tr(  "</font></b>&nbsp;&nbsp; a \303\251t\303\251 modifi\303\251, faut il enregistrer les modifications avant de s\303\251lectionner un autre dossier"),
                                    tr("&Modifier"), tr("Annu&ler"), 0,
                                    1, 1
                                    );
                   if (ret==0)
                      {Slot_pushButtonSavModif();
                      }
                   */
                  Slot_pushButtonSavModif();
                 }
              DataToFormulaire( pQListViewItem);
            }break;
        case MODE_CREATION_PATIENT:
            {/*
             int ret   = QMessageBox::warning ( this, tr("S\303\251lection d'un patient dans liste des patients :"),
                                    tr( "<u><b>ATTENTION :</u></b><br>&nbsp;&nbsp;&nbsp;voulez utiliser les donn\303\251es du patient suivant :<br>&nbsp;&nbsp; <b><font color=\"#e80d0d\">") +
                                    pQListViewItem->text(0)  + " " + pQListViewItem->text(1)  +
                                    tr(  "</font></b><br>&nbsp;&nbsp; pour remplir les donn\303\251es du patient en cours de cr\303\251ation ?"),
                                    tr("&Utiliser"), tr("Annu&ler"), 0,
                                    0, 1
                                    );
             if (ret==0)
                {DataToFormulaire( pQListViewItem);
                 return;
                }
                */
            }break;
        case MODE_MULTICRITERE:
            {DataToFormulaire( pQListViewItem);
            }break;
       } //end switch ( getInterfaceMode() )
G_pCApp->setCurrentIdentite(pQListViewItem);
if (G_pCApp->isCurrentIdentiteValid()) setIdentiteEnabled();
setVerrouForCurrentIdent();
}

//--------------------------------- DataToFormulaire -------------------------------------------------------------
int C_Manager::DataToFormulaire( const QTreeWidgetItem *pQTreeWidgetItem )
{if (pQTreeWidgetItem==0) return 0;
return DataToFormulaire( pQTreeWidgetItem->text(LIST_PK_PATIENT), pQTreeWidgetItem->text(LIST_NOM), pQTreeWidgetItem->text(LIST_PRENOM));
}
//--------------------------------- DataToFormulaire -------------------------------------------------------------
int C_Manager::DataToFormulaire( const QString &refToPrimkeyDoss, const QString &nom, const QString &prenom )
{/*
  QString      m_DOSS_IDENT_GUID;        // GUID du dossier auquel l'enregistrement fait reference
  QString      m_DOSS_IDENT_NSS ;        // date de naissance
  QString      m_DOSS_IDENT_SEX;         // sexe
  QString      m_DOSS_IDENT_JFNOM;       // nom de jeune fille
  QString      m_DOSS_IDENT_NB_ENF;      // nombre d'enfants
  QString      m_DOSS_IDENT_RUE;         // adresse
  QString      m_DOSS_IDENT_CODE_POST;   // Code postal
  QString      m_DOSS_IDENT_VILLE;       // Ville
  QString      m_DOSS_IDENT_CEDEX;       // cedex
  QString      m_DOSS_IDENT_PAYS;        // pays
  QString      m_DOSS_IDENT_TEL1;        // Telephone 1
  QString      m_DOSS_IDENT_TEL2;        // Telephone 2
  QString      m_DOSS_IDENT_TEL3;        // Telephone 3
  QString      m_DOSS_IDENT_TEL1_TYP;    // Telephone 1  type (parent amis etc...)
  QString      m_DOSS_IDENT_TEL2_TYP;    // Telephone 2
  QString      m_DOSS_IDENT_TEL3_TYP;    // Telephone 3
  QString      m_DOSS_IDENT_NUMSS;       // Num\303\251ro de secu
  QString      m_DOSS_IDENT_EMAIL;       // Num\303\251ro de secu
  QString      m_DOSS_IDENT_IS_ASS;      // le patient est il l'assur\303\251
  QString      m_DOSS_IDENT_NOM_ASS;     // nom de l'assur\303\251
  QString      m_DOSS_IDENT_PRENOM_ASS;  // pr\303\251nom de l'assur\303\251
  QString      m_DOSS_IDENT_NSS_ASS;     // date de naissance de l'assure
  QString      m_DOSS_IDENT_PROF;        // profession
  QString      m_DOSS_IDENT_TITRE;       // Titre( Dr Mr Md Pr ...)
  QString      m_DOSS_IDENT_REF_PK;      // reference \303\240 la primary key: DOSS_INDEX_PRIM_KEY de la table: DOSS_INDEX
*/
   //............................... recuperer les notes ............................................
   QString data;
   m_pCMoteurBase->PatientNoteGetData(refToPrimkeyDoss ,  data);
   m_pGUI->textEdit_Note->setText(data);
   clearDroitsFields();

   //m_pGUI->lineEdit_CAS->setText("");
   m_pCMoteurBase->PatientIntervenantsGetData(refToPrimkeyDoss , m_pGUI->listView_Praticiens);
   //............... chaines d'erreurs  ..................................................
   if  (m_pCMoteurBase->OpenBase()==0) return 0;

   //............... crer un curseur SQL ..................................................
   QString requete  = QString( "SELECT ");
           requete += m_pCMoteurBase->m_DOSS_IDENT_NOM_ASS          + ", " +       // 0
                      m_pCMoteurBase->m_DOSS_IDENT_PRENOM_ASS       + ", " +       // 1
                      m_pCMoteurBase->m_DOSS_IDENT_RUE              + ", " +       // 2
                      m_pCMoteurBase->m_DOSS_IDENT_TEL1             + ", " +       // 3
                      m_pCMoteurBase->m_DOSS_IDENT_TEL2             + ", " +       // 4
                      m_pCMoteurBase->m_DOSS_IDENT_TEL3             + ", " +       // 5
                      m_pCMoteurBase->m_DOSS_IDENT_EMAIL            + ", " +       // 6
                      m_pCMoteurBase->m_DOSS_IDENT_CODE_POST        + ", " +       // 7
                      m_pCMoteurBase->m_DOSS_IDENT_VILLE            + ", " +       // 8
                      m_pCMoteurBase->m_DOSS_IDENT_SEX              + ", " +       // 9
                      m_pCMoteurBase->m_DOSS_IDENT_GUID             + ", " +       // 10
                      m_pCMoteurBase->m_DOSS_IDENT_JFNOM            + ", " +       // 11
                      m_pCMoteurBase->m_DOSS_IDENT_TITRE            + ", " +       // 12
                      m_pCMoteurBase->m_DOSS_IDENT_PROF             + ", " +       // 13
                      m_pCMoteurBase->m_DOSS_IDENT_NSS              + ", " +       // 14
                      m_pCMoteurBase->m_DOSS_IDENT_NUMSS            + ", " +       // 15
                      m_pCMoteurBase->m_DOSS_IDENT_IS_ASS           + ", " +       // 16
                      m_pCMoteurBase->m_DOSS_IDENT_NSS_ASS          + ", " +       // 17
                      m_pCMoteurBase->m_DOSS_IDENT_GEME             + " FROM "  +  // 18
                      m_pCMoteurBase->m_DOSS_IDENT_TBL_NAME         + " WHERE " +
                      m_pCMoteurBase->m_DOSS_IDENT_REF_PK           + " = '"    + refToPrimkeyDoss + "';";

   QSqlQuery query( requete  , m_pCMoteurBase->getDatabase() );                     // ouvrir un curseur sur la table
   if ( query.isActive() && query.next())
      {
       m_pGUI->lineEdit_NomAssure->setText(       CGestIni::Utf8_Query(query , 0)      );
       m_pGUI->lineEdit_PrenomAssure->setText(    CGestIni::Utf8_Query(query , 1)      );
       m_pGUI->lineEdit_NomDossier->setText(nom);
       m_pGUI->lineEdit_PrenomDossier->setText(prenom);
       m_pGUI->textEdit_Adresse->setText(         CGestIni::Utf8_Query(query , 2)      );
       m_pGUI->lineEdit_Tel1->setText(            ToNum(query.value( 3).toString())    );
       m_pGUI->lineEdit_Tel2->setText(            ToNum(query.value( 4).toString())    );
       m_pGUI->lineEdit_Tel3->setText(            ToNum(query.value( 5).toString())    );
       m_pGUI->lineEdit_Email->setText(           CGestIni::Utf8_Query(query , 6)      );
       QString cd = ToNum(query.value( 7).toString());
       if (cd.toInt()==0) cd =""; if (cd.length()==4)cd.prepend("0");  // 6000 --> 06000
       m_pGUI->lineEdit_CdPostal->setText(        cd    );
       m_pGUI->lineEditVille->setText(            CGestIni::Utf8_Query(query , 8)      );

       QString sexe                       =    CGestIni::Utf8_Query(query , 9)    ;
       if       (sexe.left(1).lower() == "m")  m_pGUI->comboBoxSexe->setCurrentItem ( 0 ) ;
       else  if (sexe.left(1).lower() == "f")  m_pGUI->comboBoxSexe->setCurrentItem ( 1 ) ;
       else                                    m_pGUI->comboBoxSexe->setCurrentItem ( 2 ) ;
       m_pGUI->lineEdit_RangGeme->setText(        query.value( 18).toString()          );

       if (getInterfaceMode() != MODE_CREATION_PATIENT)  m_pGUI->textLabel_NumDoss->setText(        CGestIni::Utf8_Query(query , 10)     );
       m_pGUI->lineEdit_NomDeNss->setText(        CGestIni::Utf8_Query(query , 11)     );
       m_pGUI->lineEdit_Titre->setText(           CGestIni::Utf8_Query(query , 12)     );
       m_pGUI->lineEdit_Profession->setText(      CGestIni::Utf8_Query(query , 13)     );

       //....................... trucs speciaux ........................................
       QDate qDteNss =                  query.value( 14).toDate();    // dnss patient
       m_pGUI->lineEdit_DtNss->setText(CHtmlTools::yyyyMMdd_to_ddMMyyyy(query.value( 14).toString() ,"-"));
       if (qDteNss.isValid()) m_pGUI->groupBoxPatient->setTitle(tr("Patient (b\303\251n\303\251ficiaire) \303\242g\303\251 de : ") + m_pCMoteurBase->CalculeDiffAge(&qDteNss, 0, TRUE, 0));
       else                   m_pGUI->groupBoxPatient->setTitle(tr("Patient (b\303\251n\303\251ficiaire) avec une date de naissance non valide"));

       qDteNss =                  query.value( 17).toDate();          // dnss assure
       m_pGUI->lineEdit_DtNss_Assure->setText(CHtmlTools::yyyyMMdd_to_ddMMyyyy(query.value( 17).toString() ,"-"));
       //if ( !qDteNss.isValid()) m_pGUI->lineEdit_DtNss_Assure->setText(qDteNss.toString(QString("ddMMyyyy")));
       //else                     m_pGUI->lineEdit_DtNss_Assure->setText("");
       QString   nss =                  query.value( 15).toString();
       m_pGUI->lineEdit_NumSecu->setText( nss.left(13)  );
       m_pGUI->lineEdit_NssClef->setText( nss.mid(13)   );
       //.............. qualite assure ..........................
       int qualiteAssure = query.value( 16).toInt()-1;   // 0 l'assur\303\251 est le patient  (1 moins 1)
       if (qualiteAssure < 0) qualiteAssure = 9;
       if (qualiteAssure > 9) qualiteAssure = 9;
       m_pGUI->comboBoxQualiteAyantDroit->setCurrentItem(qualiteAssure);
       tryToSetInterfaceFromAyantDroit(qualiteAssure, 0);
       m_pCMoteurBase->CloseBase();
       setIdentModifiedState(FALSE);
       Controle_Solde_Patient(query.value( 10).toString());
       return 1;
   }
else
   {   m_pCMoteurBase->OutSQL_error(query);
       m_pCMoteurBase->CloseBase();
       return 0;
   }
}
//--------------------------------- ToNum ---------------------------------------------------------------------------------
QString C_Manager::ToNum(QString in)
{for(int i=0; i<in.length(); )
   {if (in.at(i)<'0' || in.at(i)>'9') in.remove(i,1);
       else ++i;
   }
   return in;
}

//--------------------------------- initListePatient ---------------------------------------------------------------------------
void C_Manager::initListePatient( const QString & qstr_nom, const QString & qstr_prenom)
{   m_pCMoteurBase->GetPatientList(m_pGUI->listView_Patient,
                                           qstr_nom,
                                           qstr_prenom,
                                           m_pGUI->textLabel_StateList
                                          );
   m_pGUI->listView_Patient->sortItems (0, Qt::AscendingOrder );
   //m_pLastQListViewItem = 0;
}
//--------------------------------- Slot_lineEditAutoLocator_textChanged -------------------------------------------------------------
void C_Manager::Slot_lineEditAutoLocator_textChanged(const QString &)
{   QStringList lst = m_pGUI->lineEditAutoLocator->text().split(';',QString::KeepEmptyParts);
   //.................. rechercher le separateur de nom ; prenom .......................
   if (lst.count()==1) initListePatient( lst[0], "");
   else                initListePatient( lst[0], lst[1]);
}

//--------------------------------- Slot_pushButtonDetruire_clicked -------------------------------------------------------------
void C_Manager::Slot_pushButtonDetruire_clicked()
{   if ( !G_pCApp->isCurrentIdentiteValid() )
      {G_pCApp->CouCou(tr("Op\303\251ration non possible : \rpas de dossier valide s\303\251lectionn\303\251."));
       return;
      }
   QString nom       = G_pCApp->identitePatientNom() ;
   QString prenom    = G_pCApp->identitePatientPrenom();
   if (G_pCApp->IsThisDroitExist("idd"))
      {QMessageBox::warning ( this, tr("Effacement d'un dossier patient :"),
                              tr ( " Vos droits sont insuffisants pour effacer le dossier : <br><b> <font color=\"#e80d0d\"> ")     +
                              nom  + " " + prenom  +  "</b></font>",
                              tr("OK"));
      return;
      }
   QTreeWidgetItem *pQListViewItem =  getSelectedListViewPatientItem();
   if ( pQListViewItem == 0)                 return;

   QString numGUID   = G_pCApp->identitePatientGUID();
   QString iD_Doss   = G_pCApp->identitePatientPk();

   //............. verifier si le dossier n'est pas deja verrouille ..................................
   //              car utilise par quelqu'un d'autre
   QString  usedBy;
   if (m_pCMoteurBase->VerrouilleDossier (numGUID, G_pCApp->getUser() , usedBy  )==0)
      {QMessageBox::warning ( this, tr("Effacement d'un dossier patient :"),
                           tr ( " ATTENTION :\r\n      Impossible d'effacer le dossier : \r\n      ")     +
                           nom  + " " + prenom  +
                           tr(  "\r\n      en cours d'utilisation par : ") + usedBy ,
                           tr("OK"), 0, 0,
                           1, 1
                           );
       return;
      }

   //............. noter la nouvelle identit\303\251 ..................................
   switch  (QMessageBox::warning ( this, tr("Effacement d'un dossier patient :"),
                                  tr ( "<u><b> ATTENTION !</u></b><br>      VOUS VOUS APPR\303\212TEZ \303\200 EFFACER LE DOSSIER : <br>      <font color=\"#e80d0d\"><b>")     +
                                  nom  + " " +prenom  +
                                  tr(  "</b></font><br>&nbsp;&nbsp;&nbsp;CETTE ACTION EST IRR\303\211VERSIBLE<br>"
                                       "&nbsp;&nbsp;&nbsp;ET LES DONN\303\211ES DU DOSSIER SERONT"
                                       "&nbsp;&nbsp;&nbsp;<u><b>IRR\303\211CUP\303\211RABLES</b></u> PAR LA SUITE") ,
                                  tr("&Effacer"), tr("&NON"), 0,
                                  1, 1 )
           )
           {case 1: m_pCMoteurBase->DeVerrouilleDossier (numGUID);
            return ;
           }
   //.................. effacer la note ...................................
   QString pk = m_pCMoteurBase->PatientNoteIsThisExist(iD_Doss);
   m_pCMoteurBase->PatientNoteDelete(pk,                       G_pCApp->m_IsNomadeActif?G_pCApp->m_IsGestionNomadisme:0 );
   m_pCMoteurBase->PatientIntervenantsAllDelete( iD_Doss);
   //.................. effacer le dossier ...................................
   RUBREC_LIST rubList;
   m_pCMoteurBase->initRubriquesList(&rubList, numGUID);     // lire et reinitialiser la liste des rubriques
   m_pCMoteurBase->DossIdentDelete(&rubList, numGUID, iD_Doss, G_pCApp->m_IsNomadeActif?G_pCApp->m_IsGestionNomadisme:0);
   //................... liberer l'ancien verrou ...............................
   m_pCMoteurBase->DeVerrouilleDossier (numGUID);

   //.............. ya plus de dossier en cours ...................................................
   G_pCApp->clearCurrentIdentite();

   //............. effacer l'item correspondant dans la liste .........................
   //              et selectionner le patient suivant .................................
   QList <QTreeWidgetItem *> list = m_pGUI->listView_Patient->findItems ( iD_Doss, Qt::MatchExactly, LIST_PK_PATIENT );
   if (list.count())
      {//............ on recupere l'item \303\240 effacer ..................................
       QTreeWidgetItem *qlistViewItem  =  list[0];  // on recupere l'item \303\240 effacer
       //............ on recupere le prochain ou si pas le precedent ................
       //             (pour eventuellement l'activer)
       QTreeWidgetItem           *newQListViewItem = m_pGUI->listView_Patient->itemBelow(qlistViewItem);
       if (newQListViewItem==0)   newQListViewItem = m_pGUI->listView_Patient->itemAbove(qlistViewItem);
       //............ on efface de la liste .........................................
       delete qlistViewItem;
       //............. on reactive le suivant ou precedent ..........................
       m_pGUI->listView_Patient->clearSelection ();
       if (newQListViewItem!=0)
          {newQListViewItem->setSelected ( TRUE );
           m_pGUI->listView_Patient->scrollToItem ( newQListViewItem );
          }
       else
          {setIdentModifiedState(FALSE); // car pas d'identite selectionne
           setIdentiteDisabled();        // car pas d'identite selectionne
           setVerrou(FALSE);             // car pas d'identite ni lancee
          }
      }
   compareListVitaleWithBase();
}
///////////////////////////////////////// GESTION DES DOUBLONS  ////////////////////////////////////////
//--------------------------------- Slot_listView_Doublons_contextMenuRequested -----------------------------------------------------------------------
void C_Manager::Slot_listView_Doublons_contextMenuRequested( const QPoint & )
{Slot_listView_Doublons_MenuRequested();
}
//--------------------------------- Slot_listView_DoublonsSelectionChanged -----------------------------------------------------------------------
void C_Manager::Slot_listView_DoublonsSelectionChanged()
{QTreeWidgetItem *pQListViewItem = getSelectedListViewItem(m_pGUI->listView_Doublons);
if (pQListViewItem) DataToFormulaire( pQListViewItem->text(LIST_PK_PATIENT), pQListViewItem->text(LIST_NOM), pQListViewItem->text(LIST_PRENOM));
}

//--------------------------------- Slot_listView_Doublons_MenuRequested -----------------------------------------------------------------------
void C_Manager::Slot_listView_Doublons_MenuRequested()
{QTreeWidgetItem * pQListViewItem = getSelectedListViewItem(m_pGUI->listView_Doublons);
QStringList list;
list.append(tr("Fermer la liste de r\303\251solution des doublons"));
list.append(tr("Effacer la liste de r\303\251solution des doublons"));
if (pQListViewItem)
   {list.append(tr("Retirer de la liste des doublons ce dossier : ")                     + pQListViewItem->text(0)+" "+pQListViewItem->text(1));
    list.append(tr("Tester si les dossiers sont verrouill\303\251s et utilisables"));
    list.append("------");
    list.append(tr("Assigner tous les dossiers pr\303\251sents dans cette liste au patient : ") + pQListViewItem->text(0)+" "+pQListViewItem->text(1));
   }
QString    ret = G_pCApp->DoPopupList(list);
QString usedBy = "";
bool isVerrou  = FALSE;
switch((int)(QChar(ret[0]).latin1()))
   {case 'T':
      {//.............. verifier si verrous .................................
       QTreeWidgetItemIterator it( m_pGUI->listView_Doublons );
       while ( *it )
          {QTreeWidgetItem *pQListViewItem_D = (*it);
           if (m_pCMoteurBase->IsDossierVerrouille   ( pQListViewItem_D->text(3), usedBy ))
              {pQListViewItem_D->setIcon ( 0, QIcon(Theme::getIcon( "16x16/locked.png")) );
               pQListViewItem_D->setText ( 4, usedBy );
               isVerrou = TRUE;
              }
           else
              {pQListViewItem_D->setIcon ( 0, QIcon() );
               pQListViewItem_D->setText ( 4, "" );
              }
           ++it;
          }
       break;
      }
    case 'A':
      {if (m_pGUI->listView_Doublons->topLevelItemCount() <=1) return;
       if ( (G_pCApp->m_IsNomadeActif?G_pCApp->m_IsGestionNomadisme:0)==CMoteurBase::progMasterUpdate)
          {G_pCApp->CouCou(tr("Ce mode de nomadisme ne permet pas la r\303\251solution des doublons"));
           return;
          }
       QString message  = tr ( "<b><font color=\"#e80d0d\">ATTENTION OP\303\211RATION DE FUSION \303\200 HAUT RISQUE </font></b>")                           +
                          tr(  "<hr><br> La personne : <b><font color=\"#1200ff\">") + pQListViewItem->text(0)+" "+pQListViewItem->text(1) + "</font></b>" +
                          tr(  "<br> va \303\252tre celle \303\240 laquelle seront attribu\303\251s tous les dossiers suivants : <hr>" ) ;
       QTreeWidgetItemIterator ut( m_pGUI->listView_Doublons );
       while ( *ut )
              {QTreeWidgetItem *pQListViewItem_D = (*ut);
               if (pQListViewItem_D->text(2) != pQListViewItem->text(2))
                   message += tr(  "<br> &nbsp;&nbsp;&nbsp;&nbsp;=> Dossier : <b><font color=\"#1200ff\">") + pQListViewItem_D->text(0)+" "+pQListViewItem_D->text(1) + "</font></b>";
               ++ut;
              }
               message += tr("<br><hr>confirmez-vous tout de m\303\252me cette op\303\251ration ? ");
       int sel = QMessageBox::information( this, tr("Fusionner plusieurs dossiers"), message,
                                                 tr("&Annuler"), tr("&Fusionner les dossiers"), 0 /*tr("Annuler")*/,
                                                 0, 1 );
       if (sel != 1)                             return;
       message  = tr(  "<b><font color=\"#e80d0d\">\303\212TES VOUS CERTAIN DE CETTE FUSION </font></b>") +
                  tr(  "<hr><br> il est encore temps d'annuler cette op\303\251ration.") +
                  tr(  "<br> qui sera non r\303\251versible apr\303\250s confirmation." ) +
                  tr(  "<br><hr>confirmez-vous de nouveau cette op\303\251ration ? ");
       sel = QMessageBox::information( this, tr("Fusionner plusieurs dossiers"), message,
                                             tr("&Fusionner les dossiers"),tr("&Annuler") , 0 /*tr("Annuler")*/,
                                             1, 1 );
       if (sel == 1)                         return;
       //.............. verifier si verrous .................................
       QTreeWidgetItemIterator it( m_pGUI->listView_Doublons );
       while ( *it )
          {QTreeWidgetItem *pQListViewItem_D = (*it);
           if (m_pCMoteurBase->IsDossierVerrouille   ( pQListViewItem_D->text(3), usedBy ))
              {pQListViewItem_D->setIcon ( 0, QIcon(Theme::getIcon( "16x16/locked.png")) );
               pQListViewItem_D->setText ( 4, usedBy );
               isVerrou = TRUE;
              }
           else
              {pQListViewItem_D->setIcon ( 0, QIcon() );
               pQListViewItem_D->setText ( 4, "" );
              }
           ++it;
          }
       if (isVerrou==FALSE)
          {//............ poser les verrous .....................
           QTreeWidgetItemIterator it( m_pGUI->listView_Doublons );
           while ( *it )
               {QTreeWidgetItem *pQListViewItem_D = (*it);
                 m_pCMoteurBase->VerrouilleDossier ( pQListViewItem_D->text(3), G_pCApp->m_User , usedBy );
                 ++it;
                }
           m_pCMoteurBase->ResoudreDoublons(pQListViewItem, m_pGUI->listView_Doublons, G_pCApp->m_IsNomadeActif?G_pCApp->m_IsGestionNomadisme:0);
           m_pCMoteurBase->DeVerrouilleDossier ( pQListViewItem->text(3));
           QString nom    = pQListViewItem->text(0);
           QString prenom = pQListViewItem->text(1);
           m_pGUI->listView_Doublons->clear () ;
           initListePatient( nom, prenom);
          }
       break;
       }
    case 'E':
      {m_pGUI->listView_Doublons->clear ();
       m_pGUI->listView_Doublons->hide();
       break;
      }
    case 'R':
      {delete(pQListViewItem);
       break;
      }
    case 'F':
      {m_pGUI->listView_Doublons->hide();
       break;
      }
    case 'O':
      {m_pGUI->listView_Doublons->show();
       break;
      }
   }
}

//////////////////////////////////////// ENREGISTREMENT CREATION MISE A JOUR //////////////////////////////////////////////////////
//--------------------------------- Slot_pushButtonSavModifWithoutConfirmation() -----------------------------------------------------------------------
void C_Manager::Slot_pushButtonSavModifWithoutConfirmation()
{savModifications(G_pCApp->identitePatientNom(), G_pCApp->identitePatientPrenom(), G_pCApp->identitePatientPk(), 0);
}
//--------------------------------- Slot_pushButtonSavModif -----------------------------------------------------------------------
void C_Manager::Slot_pushButtonSavModif()
{savModifications(G_pCApp->identitePatientNom(), G_pCApp->identitePatientPrenom(), G_pCApp->identitePatientPk());
}

//--------------------------------- savModifications -------------------------------------------------------------
void C_Manager::savModifications(const QString &oldNom, const QString &oldPrenom,  const QString &oldPk, int confirmModif /*=1*/)
{  if (G_pCApp->IsThisDroitExist("idc")==0)
     {G_pCApp->CouCou(tr( "Vos droits sont insuffisants pour enregistrer un dossier"));
      return;
     }
   int     ret       = 0;
   QString nom       = m_pGUI->lineEdit_NomDossier->text().stripWhiteSpace () ;
   QString prenom    = m_pGUI->lineEdit_PrenomDossier->text().stripWhiteSpace () ;
   QString numGUID   = G_pCApp->identitePatientGUID();

   if (oldNom != nom || oldPrenom != prenom)
   { ret   = QMessageBox::warning ( this, tr("Enregistrement :"),
                                    tr( "<u><b>ATTENTION :</u></b><br>&nbsp;&nbsp;&nbsp;\303\252tes-vous certain que ce dossier :<br>&nbsp;&nbsp; <font color=\"#e80d0d\"><b>")     +
                                    oldNom  + " " + oldPrenom  +
                                    tr(  "</b></font>&nbsp;&nbsp;doit \303\252tre modifi\303\251, et notamment<br>&nbsp;&nbsp;avec ces nouveaux nom et pr\303\251nom : <font color=\"#1111b0\"><b>") +
                                    nom + " " + prenom + tr("</b></font>&nbsp;&nbsp;(votre intention ne serait elle pas plut\303\264t de cr\303\251er un nouveau dossier)"),
                                    tr("&Modifier"), tr("Annu&ler"), 0,
                                    1, 1
                                    );
   }
   else
   {if (confirmModif)
       {
        ret   = QMessageBox::warning ( this, tr("Enregistrement :"),
                                       tr ( "<u><b>ATTENTION :</u></b><br>&nbsp;&nbsp;&nbsp;confirmez-vous les modifications&nbsp;&nbsp;apport\303\251es \303\240 ce dossier : <br>&nbsp;&nbsp;<font color=\"#e80d0d\"><b>")     +
                                       oldNom  + " " + oldPrenom  + "</b></font>",
                                       tr("&Modifier"), tr("Annu&ler"), 0,
                                       1, 1
                                       );
       }
    else
       {ret = 0;
       }
   }
   if (ret == 1)
      {//ListView_Patient_clicked( ListView_Patient->currentItem ());    // rafraichir l'ancien dossier
       DataToFormulaire(oldPk, oldNom, oldPrenom);
       return;
      }

   QString  usedBy;
   if (m_pCMoteurBase->VerrouilleDossier (numGUID, G_pCApp->getUser() , usedBy  )==0)
      {QMessageBox::warning ( this, tr("Enregistrement :"),
                           tr ( " ATTENTION :\r\n      Impossible d'enregistrer le dossier : \r\n      ")     +
                           nom  + " " +prenom  +
                           tr(  "\r\n    car il est en cours d'utilisation par : ") + usedBy ,
                           tr("&Valider"), 0, 0,
                           1, 1
                           );
       return;
      }
   if (nom == "")
      {nom = tr("ANONYME");
       m_pGUI->lineEdit_NomDossier->setText(nom);
      }
   PtrListIdentFieldData list_field;   //  cr\303\251er la liste: nom champs <-> valeurs
   setFieldListData(list_field);
   nom             = nom.upper();
   prenom          = prenom.upper();
   QString iD_Doss = m_pCMoteurBase->GetDossPrimKeyFromGUID(numGUID);
   m_pCMoteurBase->DossIdentIndexUpdate(iD_Doss, nom, prenom, &list_field ,           G_pCApp->m_IsNomadeActif?G_pCApp->m_IsGestionNomadisme:0);
   m_pCMoteurBase->PatientNoteWrite(iD_Doss ,numGUID,  m_pGUI->textEdit_Note->text(), G_pCApp->m_IsNomadeActif?G_pCApp->m_IsGestionNomadisme:0);
   m_pCMoteurBase->DeVerrouilleDossier (numGUID);

   //............. mettre \303\240 jour la liste au cas ou le nom change .................................
   QList <QTreeWidgetItem *> list = m_pGUI->listView_Patient->findItems ( iD_Doss, Qt::MatchExactly, LIST_PK_PATIENT );
   if (list.count())
      {//............ on recupere l'item \303\240 effacer ..................................
       QTreeWidgetItem *qlistViewItem  =  list[0];  // on recupere l'item \303\240 effacer
       if (qlistViewItem)
          {   qlistViewItem->setText(LIST_NOM , nom);
              qlistViewItem->setText(LIST_PRENOM ,prenom);
          }
      }
   list = m_pGUI->listView_Doublons->findItems ( iD_Doss, Qt::MatchExactly, LIST_PK_PATIENT );
   if (list.count())
      {QTreeWidgetItem *qlistViewItem  =  list[0];  // on recupere l'item \303\240 effacer
        if (qlistViewItem)
           {   qlistViewItem->setText(LIST_NOM , nom);
               qlistViewItem->setText(LIST_PRENOM ,prenom);
           }
      }
   //................... cela peut avoir change dans le formulaire ....................................
   G_pCApp->m_LastNom                   = nom;
   G_pCApp->m_LastPrenom                = prenom;
   compareListVitaleWithBase();
   setIdentModifiedState(FALSE);
}
//--------------------------------- Slot_pushButtonCreate -----------------------------------------------------------------------
void C_Manager::Slot_pushButtonCreate()
{onCreateAction(1);
}

//--------------------------------- onCreateAction -----------------------------------------------------------------------
void C_Manager::onCreateAction(int lauchEnabled  /*  = 1 */)
{    QString nom        = m_pGUI->lineEdit_NomDossier->text().trimmed () ;
    QString prenom     = m_pGUI->lineEdit_PrenomDossier->text().trimmed () ;
    QString numGUID    = m_pGUI->textLabel_NumDoss->text();
    if (nom == "") nom = tr("ANONYME");
    //.............. rechercher les doublons ....................
    QString   dnss     = m_pGUI->lineEdit_DtNss->text().remove('-');                      //  05061956
    if (dnss.length()==8) dnss = dnss.mid(4,4)+"-"+dnss.mid(2,2)+"-"+dnss.mid(0,2)+" 00:00:00";
    else                  dnss = "";
    QString numSecu  = m_pGUI->lineEdit_NumSecu->text().remove(' ');
    if (numSecu.length()==13)     numSecu += CMoteurBase::ComputeClef_Secu(numSecu).remove(' ');
    else if (numSecu.length()==0) numSecu  = "";
    else                          numSecu += "%";

   int nb = G_pCApp->m_pCMoteurBase->GetPatientListFromNomPrenomSecuDtNssGeme( m_pGUI->listView_Patient,
                                                                               nom,                         // nom
                                                                               prenom,                      // prenom
                                                                               dnss,                        // date Nss // doit etre 1993-06-01 00:00:00
                                                                               numSecu,              // num secu // 160196296519557
                                                                             "",                     // rang gemellaire
                                                                             "",     // qualite d'ayant droit
                                                                             "",      //  adresse,
                                                                             "",      //  codePost,
                                                                             "",      //  ville,
                                                                             "",      //  sexe,
                                                                             "",      //  profession,
                                                                             "",      //  nomJfille
                                                                             "",      //  nomAss,
                                                                             "",      //  prenomAss,
                                                                             "",      //  tel1,
                                                                             "",      //  tel2,
                                                                             "",      //  tel3,
                                                                             "",      //  email,
                                                                             " = ",   //  egal_like  " = ",
                                                                             m_pGUI->textLabel_StateList
                                                                           );
   if (nb)
      {      QString  message  = tr(  "<hr><b><font color=\"#e80d0d\">DOUBLONS POSSIBLES SUR LES ELEMENTS SUIVANTS : </font></b>")                         +
                                 tr(  "<br><hr> nom pr\303\251nom : <b><font color=\"#1200ff\">") + nom + " " +   prenom         + "</font></b>";
              if (dnss.length())
                      message += tr(  "<br> n\303\251e le : <b><font color=\"#1200ff\">" )         + dnss                         + "</font></b>";
              if (m_pGUI->lineEdit_CdPostal->text().remove(' ').toInt() !=0)
                      message += tr(  "<br> code postal  : <b><font color=\"#1200ff\">")     + m_pGUI->lineEdit_CdPostal->text()    + "</font></b>";
              if (numSecu.length())
                      message += tr(  "<br> num\303\251ro de SS : <b><font color=\"#1200ff\">")     + numSecu                      + "</font></b><br>";
                      message += tr(  "<br><hr> d'une personne d\303\251j\303\240 pr\303\251sente dans la liste des dossiers ");
                      message += tr(  "confirmez-vous tout de m\303\252me cette op\303\251ration au risque de cr\303\251er un doublon ?");
             int sel = QMessageBox::information( this, tr("Doublons possibles"), message,
                                                 //"&nbsp;&nbsp;&nbsp;&nbsp; ° <b>Quitter pour <u>Annuler</u></b> l'op\303\251ration en cours" ) ,
                                            tr("&Annuler"), tr("Confirmer"), 0 /*tr("Annuler")*/,
                                            0, 1 );
              if (sel != 1)
                 {setInterfaceOnProfil(MODE_SELECTION_PATIENT);
                  return;
                 }
      }
   else if ( (nb    = G_pCApp->m_pCMoteurBase->GetPatientListFromNomPrenomSecuDtNssGeme( m_pGUI->listView_Patient,
                                                                               nom,                         // nom
                                                                               prenom,                      // prenom
                                                                               "",                        // date Nss // doit etre 1993-06-01 00:00:00
                                                                               "",              // num secu // 160196296519557
                                                                               "",                     // rang gemellaire
                                                                               "",     // qualite d'ayant droit
                                                                               "",      //  adresse,
                                                                               "",      //  codePost,
                                                                               "",      //  ville,
                                                                               "",      //  sexe,
                                                                               "",      //  profession,
                                                                               "",      //  nomJfille
                                                                               "",      //  nomAss,
                                                                               "",      //  prenomAss,
                                                                               "",      //  tel1,
                                                                               "",      //  tel2,
                                                                               "",      //  tel3,
                                                                               "",      //  email,
                                                                               " = ",   //  egal_like  " = ",
                                                                               m_pGUI->textLabel_StateList
                                                                             )))
      {      QString  message  = tr(  "<hr><b><font color=\"#e80d0d\">DOUBLONS POSSIBLES SUR LE NOM PRENOM </font></b>")                         +
                                 tr(  "<br> La personne : <b><font color=\"#1200ff\">") + nom + " " +   prenom         + "</font></b>";
                      message += tr(  "<hr><br> pr\303\251sente des similitudes de nom avec les dossiers pr\303\251sents dans la liste des dossiers ");
                      message += tr(  "<br><hr>confirmez-vous tout de m\303\252me cette op\303\251ration au risque de cr\303\251er un doublon ?");
             int sel = QMessageBox::information( this, tr("Doublons possibles"), message,
                                                 //"&nbsp;&nbsp;&nbsp;&nbsp; ° <b>Quitter pour <u>Annuler</u></b> l'op\303\251ration en cours" ) ,
                                            tr("&Annuler"), tr("Confirmer"), 0 /*tr("Annuler")*/,
                                            0, 1 );
              if (sel != 1)
                 {setInterfaceOnProfil(MODE_SELECTION_PATIENT);
                  return;
                 }
      }

   PtrListIdentFieldData list_field;    //  cr\303\251er la liste: nom champs <-> valeurs
   setFieldListData(list_field);

   QString pk_Doss = m_pCMoteurBase->DossIdentIndexCreate(nom, prenom, numGUID,  &list_field , G_pCApp->m_IsNomadeActif?G_pCApp->m_IsGestionNomadisme:0);
   if (pk_Doss != "")
   {   //.......................... ecrire la note ............................................
       //setVerrouForCurrentIdent();
       QString  usedBy;
       m_pCMoteurBase->VerrouilleDossier (numGUID, G_pCApp->getUser() , usedBy  );
       nom            = nom.upper();
       prenom         = prenom.upper();
       m_pCMoteurBase->PatientNoteWrite(pk_Doss ,numGUID,  m_pGUI->textEdit_Note->text(), G_pCApp->m_IsNomadeActif?G_pCApp->m_IsGestionNomadisme:0);
       //...................... ecrire les intervenants ................................................................
       QTreeWidgetItemIterator it(m_pGUI->listView_Praticiens);
       while (*it)
             { QTreeWidgetItem *pQListViewItem = (*it);
               m_pCMoteurBase->PatientIntervenantsWrite( pk_Doss , numGUID, pQListViewItem->text(POS_ID_INTERV),  pQListViewItem->text(POS_QUAL_INTERV));
               ++it;
             }
       //............. se remettre en mode modification .......................................
       m_pCMoteurBase->DeVerrouilleDossier (numGUID);
       setInterfaceOnProfil(MODE_SELECTION_PATIENT);
       //.............. creer un nouvel item correspondant au nouveau patient ...............
       //              comme on est en mode selection l'identite
       //              se repositionnera dessus
       QTreeWidgetItem * pQListViewItem = new QTreeWidgetItem();
       if (pQListViewItem)
          { pQListViewItem->setText(0,nom);
            pQListViewItem->setText(1,prenom);
            pQListViewItem->setText(2,pk_Doss);
            pQListViewItem->setText(3,numGUID);
            m_pGUI->listView_Patient->addTopLevelItem(pQListViewItem);
            m_pGUI->listView_Patient->scrollToItem(pQListViewItem);
            pQListViewItem->setSelected(TRUE);
            G_pCApp->setCurrentIdentite(pQListViewItem);
           }
   }
   //................. Patient List Mode = clear .........................................
   QString val;
   if (CGestIni::Param_ReadParam(G_pCApp->m_LocalParam, "Derniere Session", "Patient List Mode", &val)==QString::null)   // = zero si pas d'erreur
      {if (val.at(0).lower() == 'c')
          {m_pGUI->lineEditAutoLocator->setText("");
           m_pGUI->listView_Patient->clear();
           clearIdentFields();
          }
      }
   m_pGUI->lineEditAutoLocator->setFocus();
   m_pGUI->lineEditAutoLocator->selectAll ();
   compareListVitaleWithBase();
   //if (m_pGUI->pushButtonCreate->text().indexOf(tr("acc\303\251der")) != -1)
   //   {Slot_LauchPatient(numGUID);
   //   }
       // if (m_pGUI->pushButtonCreate->text().indexOf(tr("acc\303\251der")) != -1)                           // Cz_Pyxvital
   m_pGUI->pushButton_FSE->setEnabled (TRUE );
   if (lauchEnabled && m_pGUI->pushButtonCreate->text().indexOf(tr("acc\303\251der")) != -1 && m_Facture_Seule != "oui")  // Cz_Pyxvital
      {Slot_LauchPatient(numGUID);
      }

}
//--------------------------------- Slot_pushButtonNew_clicked -----------------------------------------------------------------------
void C_Manager::Slot_pushButtonNew_clicked( )
{ //................... se mettre en mode creation en effaçant les champs.................................
if (identIsModified() && G_pCApp->isCurrentIdentiteValid() && G_pCApp->IsThisDroitExist(G_pCApp->m_Droits, "idc") )
    { Slot_pushButtonSavModif();
    }
 clearIdentFields();
 Slot_NewDossWithoutErase();
}
//--------------------------------- Slot_NewDossWithoutErase -----------------------------------------------------------------------
void C_Manager::Slot_NewDossWithoutErase( )
{ //................... se mettre en mode creation sans effaçer les champs.................................
 setInterfaceOnProfil(MODE_CREATION_PATIENT);
 m_pGUI->textLabel_NumDoss->setText(m_pCMoteurBase->GUID_Create());   // TRES IMPORTANT SERA (si confirmation de la creation) LE GUID DU NOUVEAU DOSSIER
 m_pGUI->lineEdit_NomDossier->setFocus();
}
//--------------------------------- Slot_pushButtonCancelCreate_clicked -----------------------------------------------------------------------
void C_Manager::Slot_pushButtonCancelCreate_clicked()
{setInterfaceOnProfil(MODE_SELECTION_PATIENT);
m_pGUI->textLabel_NumDoss->setText("");
setIdentiteDisabled();        // car pas d'identite selectionne
setIdentModifiedState(FALSE); // pas de modif \303\240 enregistrer
}
//--------------------------------- clearIdentFields -----------------------------------------------------------------------
void C_Manager::clearIdentFields()
{   m_pGUI->lineEdit_NomAssure->clear();
   m_pGUI->lineEdit_PrenomAssure->clear();
   m_pGUI->lineEdit_NomDeNss->clear();
   m_pGUI->textEdit_Adresse->clear();
   m_pGUI->lineEdit_Tel1->clear();
   m_pGUI->lineEdit_Tel2->clear();
   m_pGUI->lineEdit_Tel3->clear();
   m_pGUI->lineEdit_CdPostal->clear();
   m_pGUI->lineEditVille->clear();
   if (getInterfaceMode() == MODE_SELECTION_PATIENT)  m_pGUI->textLabel_NumDoss->clear();
   m_pGUI->lineEdit_Email->clear();
   m_pGUI->lineEdit_NomDossier->clear();
   m_pGUI->lineEdit_PrenomDossier->clear();
   m_pGUI->lineEdit_Profession->clear();
   m_pGUI->lineEdit_DtNss->setText("");
   m_pGUI->lineEdit_Titre->setText("");
   m_pGUI->lineEdit_RangGeme->setText("");
   m_pGUI->lineEdit_NumSecu->clear();
   m_pGUI->lineEdit_NssClef->clear();
   m_pGUI->textEdit_Note->clear();
   m_pGUI->lineEdit_DtNss_Assure->clear();
   m_pGUI->listView_Praticiens->clear();
   clearDroitsFields();
   //m_pGUI->comboBoxSexe->setCurrentText ("");
}
//--------------------------------- clearDroitsFields ------------------------------------------------------------------------
void C_Manager::clearDroitsFields()
{   m_pGUI->lineEdit_DroitsDateDeb->setText("");
   m_pGUI->lineEdit_DroitsDateFin->setText("");
   m_pGUI->lineEdit_CodeRegime->setText("");
   m_pGUI->lineEdit_CaisseGest->setText("");
   m_pGUI->lineEdit_CentreGest->setText("");
   m_pGUI->lineEdit_CodeGest->setText("");
}
//--------------------------------- setFieldListData ------------------------------------------------------------------------
void C_Manager::setFieldListData(PtrListIdentFieldData &list_field)
{   list_field.append( new CIdentFieldData(m_pCMoteurBase->m_DOSS_IDENT_NOM_ASS,    m_pGUI->lineEdit_NomAssure->text().trimmed(),          FTN_MAJ_STRING));
   list_field.append( new CIdentFieldData(m_pCMoteurBase->m_DOSS_IDENT_PRENOM_ASS, m_pGUI->lineEdit_PrenomAssure->text().trimmed(),       FTN_MAJ_STRING));
   list_field.append( new CIdentFieldData(m_pCMoteurBase->m_DOSS_IDENT_JFNOM,      m_pGUI->lineEdit_NomDeNss->text().trimmed(),           FTN_MAJ_STRING));
   list_field.append( new CIdentFieldData(m_pCMoteurBase->m_DOSS_IDENT_TITRE,      m_pGUI->lineEdit_Titre->text().trimmed(),              FTN_STRING));
   list_field.append( new CIdentFieldData(m_pCMoteurBase->m_DOSS_IDENT_RUE,        m_pGUI->textEdit_Adresse->text(),                      FTN_STRING));
   list_field.append( new CIdentFieldData(m_pCMoteurBase->m_DOSS_IDENT_TEL1,       m_pGUI->lineEdit_Tel1->text(),                         FTN_MAJ_STRING));
   list_field.append( new CIdentFieldData(m_pCMoteurBase->m_DOSS_IDENT_TEL2,       m_pGUI->lineEdit_Tel2->text(),                         FTN_MAJ_STRING));
   list_field.append( new CIdentFieldData(m_pCMoteurBase->m_DOSS_IDENT_TEL3,       m_pGUI->lineEdit_Tel3->text(),                         FTN_MAJ_STRING));
   list_field.append( new CIdentFieldData(m_pCMoteurBase->m_DOSS_IDENT_EMAIL,      m_pGUI->lineEdit_Email->text(),                        FTN_STRING));
   list_field.append( new CIdentFieldData(m_pCMoteurBase->m_DOSS_IDENT_CODE_POST,  m_pGUI->lineEdit_CdPostal->text().remove(' '),         FTN_INTEGER));
   list_field.append( new CIdentFieldData(m_pCMoteurBase->m_DOSS_IDENT_VILLE,      m_pGUI->lineEditVille->text(),                         FTN_MAJ_STRING));
   QString sexe;
   if (m_pGUI->comboBoxSexe->currentItem() == 0)        sexe = "M";
   else  if (m_pGUI->comboBoxSexe->currentItem() == 1)  sexe = "F";
   else                                                 sexe = "I";
   list_field.append( new CIdentFieldData(m_pCMoteurBase->m_DOSS_IDENT_SEX,        sexe,                                                                FTN_MAJ_STRING));
   list_field.append( new CIdentFieldData(m_pCMoteurBase->m_DOSS_IDENT_NUMSS,      m_pGUI->lineEdit_NumSecu->text().remove(' ')+
                                                                                   m_pGUI->lineEdit_NssClef->text(),                                    FTN_NUM_STRING));
   list_field.append( new CIdentFieldData(m_pCMoteurBase->m_DOSS_IDENT_NSS,        m_pGUI->lineEdit_DtNss->text().remove('-'),                          FTN_STR_DATETIME));
   list_field.append( new CIdentFieldData(m_pCMoteurBase->m_DOSS_IDENT_IS_ASS,     QString::number(m_pGUI->comboBoxQualiteAyantDroit->currentItem()+1), FTN_INTEGER));
   list_field.append( new CIdentFieldData(m_pCMoteurBase->m_DOSS_IDENT_NSS_ASS,    m_pGUI->lineEdit_DtNss_Assure->text().remove('-'),                   FTN_STR_DATETIME));
   list_field.append( new CIdentFieldData(m_pCMoteurBase->m_DOSS_IDENT_PROF,       m_pGUI->lineEdit_Profession->text(),                                 FTN_MAJ_STRING));
   QString                  rangGem  = m_pGUI->lineEdit_RangGeme->text().trimmed();
   //if (rangGem.length()==0) rangGem = rangGem.prepend("0");
   //if (rangGem.length()==1) rangGem = rangGem.prepend("0");
   list_field.append( new CIdentFieldData(m_pCMoteurBase->m_DOSS_IDENT_GEME,       rangGem,                                                             FTN_MAJ_STRING));
}

/////////////////////////////////////////////////// AGENDA ///////////////////////////////////////////////////////////////////////////

//------------------------------------------- initComboBoxAgendaUser -----------------------------------------------------------------------
void C_Manager::initComboBoxAgendaUser()
{
   //........... combobox ajouter un agenda utilisateur....................
   m_pGUI->comboBoxAgendaUser->clear();
   QStringList userList;
   G_pCApp->m_pCMoteurBase->GetUserList( userList , "-sgn-agc");
   m_pGUI->comboBoxAgendaUser->insertItems ( 0, userList );
   if (!G_pCApp->IsThisDroitExist("agm"))
      {m_pGUI->comboBoxAgendaUser->hide();
       m_pGUI->labelAgendaSelect->hide();
      }
}

//------------------------ allAgendasReconnect ---------------------------------------
void C_Manager::allAgendasReconnect(      const QString &driver,        // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
                                         const QString &baseToConnect, // nom de la base: si QODBC3 -> nom de la source de donn\303\251es (userDSN)
                                         const QString &user,          // = "root"
                                         const QString &pasword,       // = ""
                                         const QString &hostname,      // = "localhost"
                                         const QString &port           // = "port",
                                   )
{   QMapIterator<QString, C_Frm_Agenda*> it(m_AgendaMap);
   while (it.hasNext())
         {it.next();
          C_Frm_Agenda *pC_Frm_Agenda = it.value();
          if (pC_Frm_Agenda)
             {pC_Frm_Agenda->baseReConnect(driver, baseToConnect, user, pasword, hostname, port);
              break;          // une seule fois suffit car la base est toujours avec le m\303\252me label quelque soit l'agenda
             }
         }
}

//--------------------------------- setComboBoxOnValue ------------------------------------------------------------
int C_Manager::setComboBoxOnValue(QComboBox *pQComboBox, const QString& value)
{if (value.length()==0)return -1;
int index = pQComboBox->findText (value,  Qt::MatchExactly );  //Qt::MatchExactly | Qt::MatchCaseSensitive
if (index != -1) pQComboBox->setCurrentIndex  (index);
return index;
}

//------------------------ reinitAgendaOnUser ---------------------------------------
void C_Manager::reinitAgendaOnUser(const QString & /*user*/ , const QString & signUser)
{   //.................. version non fonctionnelle je ne sais pas pourquoi ........................
   //m_pC_Frm_Agenda->reinitAgendaOnUser(pUserItem, pSignUserItem);  // ne fonctionne pas !!! pourquoi ???
   //.................. version fonctionnelle mais detruit tout et refait tout  ........................
   setTitle();
   QDate  startDate              = QDate::currentDate();
   if (m_AgendaMap.count(signUser))
      {C_Frm_Agenda *pC_Frm_Agenda   = m_AgendaMap[signUser];
       if (pC_Frm_Agenda)
          {startDate  = pC_Frm_Agenda->getStartDate();  // recuperer la date de debut avant de reconstruire
           if (G_pCApp->IsThisDroitExist("agm")) {deleteAgenda(signUser);  m_pGUI->comboBoxAgendaUser->show();m_pGUI->labelAgendaSelect->show();}
           else                                  {deleteAllAgendas();      m_pGUI->comboBoxAgendaUser->hide();m_pGUI->labelAgendaSelect->hide();}
          }
      }
   else
      {if (G_pCApp->IsThisDroitExist("agm"))    {                          m_pGUI->comboBoxAgendaUser->show();m_pGUI->labelAgendaSelect->show();}
       else                                     { deleteAllAgendas();      m_pGUI->comboBoxAgendaUser->hide();m_pGUI->labelAgendaSelect->hide();}
      }
   addUserAgenda(signUser, startDate);
   setComboBoxOnValue(m_pGUI->comboBoxAgendaUser, signUser);

}

//------------------------ deleteAllAgendas ---------------------------------------
QStringList C_Manager::deleteAllAgendas()
{   QStringList agendasList = getAgendasList();
   //.................. les effacer ...............................
   for (int i = 0; i < agendasList.size(); ++i)
       {deleteAgenda(agendasList[i]);
       }
   m_AgendaMap.clear();
   return agendasList;
}

//------------------------ getAgendasList ---------------------------------------
QStringList C_Manager::getAgendasList()
{   QStringList agendasList;
   QMapIterator<QString, C_Frm_Agenda*> it(m_AgendaMap);
   while (it.hasNext())
         {it.next();
          agendasList<<it.key();
         }
   return agendasList;
}

//---------------------------------------------- eraseUserAgenda -----------------------------------------------------------------------
void C_Manager::eraseUserAgenda(C_Frm_Agenda* pC_Frm_Agenda)
{if (pC_Frm_Agenda)
   {deleteAgenda(pC_Frm_Agenda->getSignUser());
   }
}

//---------------------------------------------- Slot_buttonAgendaDelete_Clicked -----------------------------------------------------------------------
void C_Manager::Slot_buttonAgendaDelete_Clicked(Wdg_ButtonPtr *pWdg_ButtonPtr)
{QString name     = pWdg_ButtonPtr->objectName();
QString signUser = name.remove(tr("ButtonClose_"));
deleteAgenda(signUser);
}

//---------------------------------------------- Slot_buttonAgendaDelete_Clicked -----------------------------------------------------------------------
void C_Manager::deleteAgenda(const QString &signUser)
{QFrame *pQFrame = m_pGUI->frame_MultiAgenda->findChild<QFrame *>("agendaRacine_" + signUser);
if (pQFrame)
   {m_AgendaMap.remove ( signUser );
    m_pAgendaQLayout->removeWidget(pQFrame);
    delete pQFrame;
   }
}

//---------------------------------------------- Slot_comboBoxAgendaUser_activated -----------------------------------------------------------------------
void C_Manager::Slot_comboBoxAgendaUser_activated( const QString &signUser )
{
   if (!G_pCApp->IsThisDroitExist("agc") &&      // si pas d'agenda possible pour l'utilisateur en cours
       !G_pCApp->IsThisDroitExist("agm"))        // et qu'il n'est pas autorise a gerer des agendas multiples (ceux des autres)
      {G_pCApp->CouCou(tr("Vous n'avez pas les droits suffisants pour utiliser l'agenda"));
       return;
      }
 addUserAgenda(signUser, QDate::currentDate());
 //if (G_pCApp->IsThisDroitExistForThisUser(signUser, "agc")) m_pGUI->scrollArea_MultiAgenda->show(); // peut avoir ete cache par
}
//---------------------------------------------- Slot_pQPushButtonAgendaDate_Clicked -----------------------------------------------------------------------
void C_Manager::Slot_pQPushButtonAgendaDate_Clicked (Wdg_ButtonPtr* pWdg_ButtonPtr)
{    /*
    if (!G_pCApp->IsThisDroitExist("agc") &&      // si pas d'agenda possible pour l'utilisateur en cours
        !G_pCApp->IsThisDroitExist("agm"))        // et qu'il n'est pas autorise a gerer des agendas multiples (ceux des autres)
       {G_pCApp->CouCou(tr("Vous n'avez pas les droits suffisants pour utiliser l'agenda"));
        return;
       }
    */
//............... recuperer un pointeur sur l'agenda .................................................
C_Frm_Agenda  *pC_Frm_Agenda  = (C_Frm_Agenda*) pWdg_ButtonPtr->getPtr_1();
QLineEdit     *pQLineEditDate = (QLineEdit*)    pWdg_ButtonPtr->getPtr_2();
if (pC_Frm_Agenda->getPaintMode() >= C_Frm_Agenda::NORMAL)
   {//............... recuperer la date de ce calendrier .................................................
    QDate   dateIn = pC_Frm_Agenda->getStartDate();
    //............... lancer le calendrier .................................................
    QString date  = execCalendrier(dateIn); date = date.remove('-');
    QDate dateNew = QDate::fromString(date, "ddMMyyyy");
    //....................... analyse du retour ..........................................................................
    if (dateNew.isValid () && dateNew != dateIn )
       {pQLineEditDate->setText(date);
        pC_Frm_Agenda->reinitAgendaOnDate(dateNew);
       }
   }
else
   {QWebView *pQWebView = pC_Frm_Agenda->getWebView();
    if (pQWebView==0) return;
    pQWebView->back();
   }
}
//---------------------------------------------- setUserAgendaVisible -----------------------------------------------------------------------
void C_Manager::setUserAgendaVisible(const QString &signUser)
{m_tmpSignUser = signUser;
QTimer::singleShot(30, this, SLOT(Slot_setUserAgendaVisible()));
}
//---------------------------------------------- Slot_setUserAgendaVisible -----------------------------------------------------------------------
void C_Manager::Slot_setUserAgendaVisible()
{QFrame *pQFrame = m_pGUI->frame_MultiAgenda->findChild<QFrame *>("agendaRacine_" + m_tmpSignUser);
if (pQFrame)
   { m_pGUI->scrollArea_MultiAgenda->ensureWidgetVisible ( pQFrame,0 , 0);
   }
Wdg_ButtonPtr *pQPushButton  = m_pGUI->frame_MultiAgenda->findChild<Wdg_ButtonPtr *>("ButtonClose_" + m_tmpSignUser);
if (pQPushButton)  m_pGUI->scrollArea_MultiAgenda->ensureWidgetVisible ( pQPushButton, 0, 0);
}
//---------------------------------------------- Slot_setUserAgendaVisible -----------------------------------------------------------------------
void C_Manager::Slot_pQPushButtonMenuAgenda_Clicked(Wdg_ButtonPtr* pWdg_ButtonPtr)
{   Theme::setFontSize_Menu(9);
   QStringList optionList;
   optionList<<tr("$Agenda");
   optionList<<tr("=1=#Agenda/h-01.png#Repr\303\251senter l'agenda avec un pixel par minute.");
   optionList<<tr("=2=#Agenda/h-02.png#Repr\303\251senter l'agenda avec deux pixels par minute.");
   optionList<<tr("=3=#Agenda/h-03.png#Repr\303\251senter l'agenda avec trois pixels par minute.");
   optionList<<tr("=4=#Agenda/h-04.png#Repr\303\251senter l'agenda avec quatre pixels par minute.");
   optionList<<tr("=5=#Agenda/h-05.png#Repr\303\251senter l'agenda avec cinq pixels par minute.");
   optionList<<"-----------";
   optionList<<tr("=6=#Agenda/h-01.png#Fixer les rendez-vous sur un multiple de une minute.");
   optionList<<tr("=10=#Agenda/h-05.png#Fixer les rendez-vous sur un multiple de cinq minutes.");
   optionList<<tr("=15=#Agenda/h-10.png#Fixer les rendez-vous sur un multiple de dix minutes.");
   optionList<<tr("=20=#Agenda/p-15.png#Fixer les rendez-vous sur un multiple de quinze minutes.");
   optionList<<"-----------";
   optionList<<tr("=21=#Agenda/agendaDebut.png#Fixer la premi\303\250re heure visible.");
   optionList<<tr("=22=#Agenda/agendaFin.png#Fixer la derni\303\250re heure visible.");
   optionList<<"-----------";
   optionList<<tr("=30=#Agenda/h-00.png#Annuler la mise \303\240.jour automatique.");
   optionList<<tr("=35=#Agenda/h-05.png#Intervalle de mise \303\240.jour de cinq secondes.");
   optionList<<tr("=40=#Agenda/h-10.png#Intervalle de mise \303\240.jour de dix secondes.");
   optionList<<tr("=50=#Agenda/p-20.png#Intervalle de mise \303\240.jour de vingt secondes.");
   optionList<<tr("=90=#Agenda/p-60.png#Intervalle de mise \303\240.jour de une minute");
   optionList<<"-----------";
   optionList<<tr("=100=#Agenda/AgendaSingleLine.png#Repr\303\251senter la vue miniature (mode repli\303\251) sur une ligne.");
   optionList<<tr("=101=#Agenda/AgendaDoubleLine.png#Repr\303\251senter la vue miniature (mode repli\303\251) sur deux lignes.");
   optionList<<"-----------";
   optionList<<tr("=110=#Agenda/changeWidth.png#Modifier la largeur de l'agenda.");
   optionList<<"-----------";
   optionList<<tr("=120=#Agenda/noConfirmModif.png#D\303\251sactiver la confirmation des modifications.");
   optionList<<tr("=121=#Agenda/ConfirmModif.png#Activer la confirmation des modifications.");
   optionList<<"-----------";
   optionList<<tr("=180=#Agenda/QuitterMenu.png#Quitter ce menu.");

   pWdg_ButtonPtr->setIcon(Theme::getIcon("Agenda/AgendaMenuDown.png"));
   QString option = ThemePopup(optionList,this, " border: 1px solid #8f8f91; border-radius: 6px; font-size: 11px;").DoPopupList();
   pWdg_ButtonPtr->setIcon(Theme::getIcon("Agenda/AgendaMenu.png"));

   if (option.length()==0) return;
   int opt = option.toInt();
   C_Frm_Agenda  *pC_Frm_Agenda  = (C_Frm_Agenda*) pWdg_ButtonPtr->getPtr_1();
   if (opt>=1 && opt<=5)
      {pC_Frm_Agenda->changePixelParMinute(opt);
       CGestIni::Param_WriteParam(&G_pCApp->m_LocalParam, "Agenda" , "Nombre pixels par minute" , QString::number(opt));
       CGestIni::Param_UpdateToDisk(G_pCApp->m_PathAppli+"Manager.ini", G_pCApp->m_LocalParam);
      }
   else if (opt>=6 && opt<=20)
      {pC_Frm_Agenda->changeMagnetisme(opt-5);
       CGestIni::Param_WriteParam(&G_pCApp->m_LocalParam, "Agenda" , "Magnetisme" , QString::number(opt-5));
       CGestIni::Param_UpdateToDisk(G_pCApp->m_PathAppli+"Manager.ini", G_pCApp->m_LocalParam);
      }
   else if (opt>=100 && opt<=101)
      {opt = opt - 100;
       pC_Frm_Agenda->changeRepresentation(opt);
       CGestIni::Param_WriteParam(&G_pCApp->m_LocalParam, "Agenda" , "Representation" , QString::number(opt));
       CGestIni::Param_UpdateToDisk(G_pCApp->m_PathAppli+"Manager.ini", G_pCApp->m_LocalParam);
      }
   else if (opt>=120 && opt<=121)
     {opt = (opt-120)*3;
      pC_Frm_Agenda->changeModifConfirm(opt);
      CGestIni::Param_WriteParam(&G_pCApp->m_LocalParam, "Agenda" , "Modif confirm" , QString::number(opt));
      CGestIni::Param_UpdateToDisk(G_pCApp->m_PathAppli+"Manager.ini", G_pCApp->m_LocalParam);
     }
   else if (opt>=21 && opt<=22)
     {bool ok;
      QString text = QInputDialog::getText(this, tr("saisir une heure de la forme hh:mm"), tr("Heure (hh:mm) :"), QLineEdit::Normal, opt==21?"08:00":"19:00", &ok).trimmed();
      if (ok && text.length())
         {QTime tm = QTime::fromString(text,"hh:mm");
          if (!tm.isValid()) return;
          if (opt==21)
             {pC_Frm_Agenda->changeStartTime ( text );
              CGestIni::Param_WriteParam(&G_pCApp->m_LocalParam, "Agenda" , "Heure limite basse" , text);
             }
          else
             {pC_Frm_Agenda->changeEndTime (text);
              CGestIni::Param_WriteParam(&G_pCApp->m_LocalParam, "Agenda" , "Heure limite haute" , text);
             }
          CGestIni::Param_UpdateToDisk(G_pCApp->m_PathAppli+"Manager.ini", G_pCApp->m_LocalParam);
         }
      }
   else if (opt>=30 && opt<=90)
      {pC_Frm_Agenda->changeRafraichissement(opt-30);
       CGestIni::Param_WriteParam(&G_pCApp->m_LocalParam, "Agenda" , "Rafraichissement" , QString::number(opt-30));
       CGestIni::Param_UpdateToDisk(G_pCApp->m_PathAppli+"Manager.ini", G_pCApp->m_LocalParam);
      }
   else if (opt==110)
     {bool ok;
      QString text = QInputDialog::getText(this, tr("Saisir la largeur de l'agenda"), tr("Largeur en pixels :"), QLineEdit::Normal, "300", &ok).trimmed();
      if (ok && text.length())
         {QScrollArea   *scrollArea_Days            = (QScrollArea*)pWdg_ButtonPtr->getPtr_2();
          //QFrame        *agendaFrameDaysAndTitle    = (QFrame*)pWdg_ButtonPtr->getPtr_3();
          QFrame        *agendaFrameDaysAndTitle    = (QFrame*)pWdg_ButtonPtr->getPtr_3();
          //QVBoxLayout   *agendaVBoxDaysAndTitle     = (QVBoxLayout*)pWdg_ButtonPtr->getPtr_3();
          int value = qMin(600,qMax(text.toInt(),150));
          pC_Frm_Agenda->changeAgendaWidth( value );
          scrollArea_Days->resize(value+10, scrollArea_Days->height());

          agendaFrameDaysAndTitle->resize(value+10, agendaFrameDaysAndTitle->height());
          //agendaVBoxDaysAndTitle->resize(value+10, agendaVBoxDaysAndTitle->height());
          CGestIni::Param_WriteParam(&G_pCApp->m_LocalParam, "Agenda" , "Largeur" , text);
          CGestIni::Param_UpdateToDisk(G_pCApp->m_PathAppli + "Manager.ini", G_pCApp->m_LocalParam);
         }
      }
}

//---------------------------------------------- execCalendrier -----------------------------------------------------------------------
QString C_Manager::execCalendrier(const QDate &dateIn)
{     //............... lancer le calendrier .................................................
    QString pathPlugin;
    CGestIni::Param_ReadParam(G_pCApp->m_LocalParam, "Gestion du calendrier", "pathPlugin",       &pathPlugin);
    //..................................... ne pas rajouter "/" car c'est un nom de fichier ..........................
    if ( QDir::isRelativePath ( pathPlugin ) )  pathPlugin = QDir::cleanDirPath (pathPlugin.prepend(G_pCApp->m_PathAppli));
    QString date   = dateIn.toString("ddMMyyyy");
    QString presel = Theme::getPath(TRUE)+"Agenda/MenuPreselDate.txt";
    QString pluginScript  = "[Execute]\r\n";
            pluginScript += "pathPlugin="      + pathPlugin                                           + "\r\n" +
                            "pathIni=****\r\n" +                //**** car indique d'utiliser le pathIni du plugin
                            "maskExch= non utilise\r\n"
                            "[Parametres]\r\n"
                            "m_StartDate        = " + date      + "\r\n"     +
                            "m_ReturnFormat    = ddMMyyyy\r\n" +
                            "m_InfDate         = " + date      + "\r\n"     +     // date lim inf
                            "m_SupDate         = " + date      + "\r\n"     +     // date lim sup
                            "m_PreselMenu      = " + presel    + "\r\n"     +
                            "m_modeToShow      = days" //debDate endDate hours
                            ;

   return G_pCApp->PluginExe(this, pluginScript, CApp::endWait);
}

//---------------------------------------------- addUserAgenda -----------------------------------------------------------------------
C_Frm_Agenda *C_Manager::addUserAgenda(const QString &signUser, QDate date, QFrame **ppQFrame)
{   if (signUser.length()==0) return 0;
   if (m_AgendaMap.count(signUser))
      {setUserAgendaVisible(signUser);
       return 0;
      }
   QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
   QString nom, prenom;
   m_pCMoteurBase->GetUserNomPrenom( signUser, nom, prenom);
   m_pGUI->wdg_DockWidget_Agenda->setUpdatesEnabled(false);
   QString        userDroits                 = G_pCApp->m_pCMoteurBase->GetUserPermisions(signUser);
   QString        imageFolder                = Theme::getPath()+"Agenda/";
   QString        styles                     = QString("border-radius: 6px; background: qlineargradient(x1:0, y1:0, x2:1, y2:1,stop:0 white, stop: 0.4 #8baaae, stop:1 #2a4a6b); border: 1px solid #8f8f91; border-radius: 1px; font-size: 9px;");
   QFrame        *agendaFrameDaysAndTitle    = new QFrame(m_pGUI->frame_MultiAgenda);
                                               agendaFrameDaysAndTitle->setObjectName(tr("agendaRacine_")+signUser);
                                               agendaFrameDaysAndTitle->setStyleSheet("font-size: 10px;");
   QFrame        *frameButtonAndTitle        = new QFrame(agendaFrameDaysAndTitle);
   QVBoxLayout   *agendaVBoxDaysAndTitle     = new QVBoxLayout(agendaFrameDaysAndTitle); agendaVBoxDaysAndTitle->setObjectName(tr("agendaVBoxDaysAndTitle_") + signUser);
   QScrollArea   *scrollArea_Days            = new QScrollArea(agendaFrameDaysAndTitle);
   C_Frm_Agenda  *pC_Frm_Agenda              = new C_Frm_Agenda( date, scrollArea_Days, G_pCApp->m_PathAppli, G_pCApp->m_LocalParam, signUser,G_pCApp->m_User,nom+" "+prenom, userDroits);        // creer la liste des jours
   QLabel        *pQLabel                    = new QLabel(frameButtonAndTitle); pQLabel->setStyleSheet(styles);
   QLineEdit     *pQLineEditDate             = new QLineEdit(frameButtonAndTitle); pQLineEditDate->setInputMask ("99-99-9999"); pQLineEditDate->setStyleSheet(styles);
   Wdg_ButtonPtr *pQPushButtonDate           = new Wdg_ButtonPtr( frameButtonAndTitle , tr("ButtonDate_")  + signUser); pQPushButtonDate->setPtr_1(pC_Frm_Agenda); pQPushButtonDate->setPtr_2(pQLineEditDate);
   Wdg_ButtonPtr *pQPushButtonClose          = new Wdg_ButtonPtr( frameButtonAndTitle , tr("ButtonClose_") + signUser); pQPushButtonClose->setPtr_1(pC_Frm_Agenda);
   Wdg_ButtonPtr *pQPushButtonMenu           = new Wdg_ButtonPtr( frameButtonAndTitle , tr("ButtonMenu_") + signUser);
                                                   pQPushButtonMenu->setPtr_1(pC_Frm_Agenda);
                                                   pQPushButtonMenu->setPtr_2(scrollArea_Days);
                                                   pQPushButtonMenu->setPtr_3(agendaFrameDaysAndTitle);
   QScrollBar    *pQScrollBar                = scrollArea_Days->verticalScrollBar();   // juste pour la largeur
   int            wScroll                    = 14;
   pC_Frm_Agenda->setUser(signUser);
   QString        scrollStyle ="QScrollBar:vertical {"
                               "  border: 1px solid grey;"
                               "  background: #868786;"
                               "  width: %3px;"
                               "  margin: 15px 0 15px 0;"
                               "}"
                               "QScrollBar::handle:vertical {"
                               //"    background: white;"
                               "background: qlineargradient(x1:0, y1:0, x2:1, y2:1,stop:0 white, stop: 0.4 #8baaae, stop:1 #2a4a6b); border: 1px solid #8f8f91;"
                               "    min-height: 20px;"
                               "}"
                               "QScrollBar::add-line:vertical {"
                               "    border: 1px solid grey;"
                               //"    background: #32CC99;"
                               "background-image: url(%2);"
                               "    height: 12px;"
                               "    subcontrol-position: bottom;"
                               "    subcontrol-origin: margin;"
                               "}"

                               "QScrollBar::sub-line:vertical {"
                               "    border: 1px solid grey;"
                               //"    background: #32CC99;"
                               "background-image: url(%1);"
                               "    height: 12px;"
                               "    subcontrol-position: top;"
                               "    subcontrol-origin: margin;"
                               "}"
                               //"QScrollBar::up-arrow:vertical {"
                               //"    border: 0px solid grey;"
                               //"    width: 15px;"
                               //"    height: 15px;"
                               //"    background: white;"
                               //"background-image: url(%1);"
                               //"}"
                               //"QScrollBar::down-arrow:vertical {"
                               //"    border: 0px solid grey;"
                               //"    width: 15px;"
                               //"    height: 15px;"
                               //"    background: white;"
                               //"background-image: url(%2);"
                               //"}"
                               ;
   agendaVBoxDaysAndTitle->setSpacing(5);
   agendaVBoxDaysAndTitle->setMargin(0);
   agendaVBoxDaysAndTitle->setContentsMargins(0, 0, 0, 0);

   pQScrollBar->setStyleSheet(scrollStyle.arg(imageFolder+"SliderUp.png",imageFolder+"SliderDown.png", QString::number(wScroll)));
   scrollArea_Days->setWidget(pC_Frm_Agenda);
   int w                      = pC_Frm_Agenda->width() + wScroll+5;
   frameButtonAndTitle->setMinimumSize ( w , AGENDA_SUB_TITLE_H);
   frameButtonAndTitle->setMaximumSize ( w , AGENDA_SUB_TITLE_H);

   pQPushButtonClose->resize(   AGENDA_SUB_TITLE_H , AGENDA_SUB_TITLE_H);
   pQPushButtonClose->move  ( 0 , 0);
   pQPushButtonClose->setIcon(Theme::getIcon("Agenda/CloseAgenda.png"));

   pQPushButtonMenu->resize(   AGENDA_SUB_TITLE_H , AGENDA_SUB_TITLE_H);
   pQPushButtonMenu->move  ( W_DATE_EDIT + AGENDA_SUB_TITLE_H + AGENDA_SUB_TITLE_H, 0);
   pQPushButtonMenu->setIcon(Theme::getIcon("Agenda/AgendaMenu.png"));
   pQPushButtonMenu->setToolTip ( tr("<font color=\"#000000\">Menu d'options diverses pour l'agenda.</font>") );

   pQPushButtonDate->resize     ( AGENDA_SUB_TITLE_H , AGENDA_SUB_TITLE_H);
   pQPushButtonDate->move       ( AGENDA_SUB_TITLE_H  , 0);
   if (pC_Frm_Agenda->getPaintMode() >= C_Frm_Agenda::NORMAL)
      {pQPushButtonDate->setIcon    ( Theme::getIcon("Agenda/dateChange.png"));
       pQPushButtonDate->setToolTip ( tr("<font color=\"#000000\">Saisie de la date de d\303\251but de l'agenda.</font>") );
       pQPushButtonClose->setToolTip (tr("<font color=\"#000000\">Fermer cet agenda.</font>") );
      }
   else
      {pQPushButtonDate->setIcon    ( Theme::getIcon("Agenda/goBack.png"));
       pQPushButtonDate->setToolTip ( tr("<font color=\"#000000\">Revenir \303\240 la page pr\303\251cedente.</font>") );
       pQPushButtonClose->setToolTip (tr("<font color=\"#000000\">Fermer cette page.</font>") );
      }
   pQLineEditDate->setText      (date.toString("ddMMyyyy"));
   pQLineEditDate->setStyleSheet(QString("border-radius: 6px; background-color: #fff9d8; border: 1px solid #8f8f91; border-radius: 1px; font-size: 9px;"));
   pQLineEditDate->setAlignment ( Qt::AlignHCenter );
   pQLineEditDate->resize       ( W_DATE_EDIT, AGENDA_SUB_TITLE_H );
   pQLineEditDate->move         ( AGENDA_SUB_TITLE_H + AGENDA_SUB_TITLE_H  , 0);
   pQLineEditDate->setToolTip   (tr("<font color=\"#000000\">Saisie de la date de d\303\251but de l'agenda.</font>") );
   pQLineEditDate->setReadOnly  ( TRUE );

   pQLabel->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
   pQLabel->setText( QString(" <font color=\"#FFFFFF\"><b>") + nom + " " + prenom +"</b></font>" );
   pQLabel->resize ( w - AGENDA_SUB_TITLE_H - AGENDA_SUB_TITLE_H - W_DATE_EDIT, AGENDA_SUB_TITLE_H );
   pQLabel->move   ( AGENDA_SUB_TITLE_H + AGENDA_SUB_TITLE_H +  W_DATE_EDIT  , 0);

   scrollArea_Days->setMaximumSize ( w , 16777215);
   agendaVBoxDaysAndTitle->addWidget(frameButtonAndTitle);
   agendaVBoxDaysAndTitle->addWidget(scrollArea_Days);
   if (ppQFrame) *ppQFrame = agendaFrameDaysAndTitle;
   m_pAgendaQLayout->addWidget(agendaFrameDaysAndTitle);
   m_AgendaMap[signUser] = pC_Frm_Agenda;

   connect( pQPushButtonClose ,SIGNAL(clicked (Wdg_ButtonPtr*)), this, SLOT(Slot_buttonAgendaDelete_Clicked (Wdg_ButtonPtr*)) );
   connect( pQPushButtonDate , SIGNAL(clicked (Wdg_ButtonPtr*)), this, SLOT(Slot_pQPushButtonAgendaDate_Clicked (Wdg_ButtonPtr*)) );
   connect( pQPushButtonMenu , SIGNAL(clicked (Wdg_ButtonPtr*)), this, SLOT(Slot_pQPushButtonMenuAgenda_Clicked (Wdg_ButtonPtr*)) );
   connect( pC_Frm_Agenda,     SIGNAL(Sign_LauchPatient(const QString &, C_RendezVous *)),   this, SLOT( Slot_LauchPatient(const QString &, C_RendezVous *)));

   G_pCApp->processEvents(QEventLoop::ExcludeUserInputEvents,10000);  // obligatoire si l'on veut que l'agenda se positionne sur le bon user
   m_tmpSignUser = signUser;
   Slot_setUserAgendaVisible();
   m_pGUI->wdg_DockWidget_Agenda->setUpdatesEnabled(TRUE);
   QApplication::restoreOverrideCursor();
   //m_pGUI->scrollArea_MultiAgenda->horizontalScrollBar()
   //setUserAgendaVisible(signUser);
   //m_pGUI->frame_MultiAgenda->setGeometry(0,0,200,200);
   //m_pGUI->frame_MultiAgenda->show();
   //pC_Frm_Agenda->show();
   //m_pGUI->scrollArea_MultiAgenda->ensureVisible ( int x, int y, int xmargin = 50, int ymargin = 50 )

   return pC_Frm_Agenda;
}

////////////////////////////////////// EDITION DES UTILISATEURS ////////////////////////////////////////////////////////////////////////////
//---------------------------------------------- Slot_pushButton_action_UserParams -----------------------------------------------------------------------
void C_Manager::Slot_pushButton_action_UserParams()
{editUser("");
}

//---------------------------------------------- Slot_EditUser -----------------------------------------------------------------------
void C_Manager::Slot_EditUser(const QString& /*user*/, const QString& /*signUser*/)
{editUser("");
}

//--------------------------------- Slot_UserMustBeUnloged --------------------------------------------------------------------------------
void C_Manager::Slot_UserMustBeUnloged(int &)
{//m_pC_Frm_UserList->reinitOn_SignUser_User_Name("", "");
setIdentiteDisabled();
m_pGUI->tabWidget_Central->setEnabled(FALSE);
m_pGUI->wdg_DockWidget_Agenda->setEnabled(FALSE);
}

//---------------------------------------------- editUser -----------------------------------------------------------------------
void C_Manager::editUser(QString cps)
{
QProcess  proc;
//........ recuperer l'ancienne liste des utilisateurs  .............................................
//          (pour comparer apres gest_user )
QStringList oldUserList;
m_pCMoteurBase->GetUserList(oldUserList);  // recuperer l'ancienne liste des utilisateurs (pour comparer apres gest_user )
//........ localiser gest_user .............................................
QString pathExe = CGestIni::Construct_Name_Exe("gest_user",QFileInfo (qApp->argv()[0]).dirPath (true));
//........ nourrir les arguments d'appel de gest_user .......................
QStringList argList;
argList <<( G_pCApp->m_User);                                        // Nom de l'utilisateur
argList <<( QString("#")+G_pCApp->m_CriptedPassWord );               // passWord
if (cps.length()) argList <<( cps.replace(",","__*$*__" ));
proc.start(pathExe, argList);
SLEEP(1);
QApplication::processEvents();
// positionne un flag dans l'application appelante
while (proc.state()==QProcess::Running )
      { QApplication::processEvents ( QEventLoop::WaitForMore );
      }
//................. soit creation d'un nouvel utilisateur et alors le selectionner ..........................
//                  soit effacement d'un utilisateur et alors se mettre en unlogued

//........ recuperer l'ancienne liste des utilisateurs  .............................................
//          (pour comparer apres gest_user )
QStringList newUserList;
m_pCMoteurBase->GetUserList(newUserList,"-sgn-agc");  // recuperer l'ancienne liste des utilisateurs (pour comparer apres gest_user )
m_pGUI->comboBoxAgendaUser->clear();
m_pGUI->comboBoxAgendaUser->insertItems ( 0, newUserList );
//............. si pas de changement cassos ...........................................................
if (newUserList == oldUserList) return;
//............. si cps -> selectionner si possible l'utilisateur de la cps ...............................
#ifdef SESAM_VERSION
if (cps.length())    // si cps active
   {QStringList fieldList;
    fieldList << m_pCMoteurBase->m_USER_IDENT_LOGIN;
    fieldList << m_pCMoteurBase->m_USER_IDENT_PASSWORD;
    QString userPk = m_pCMoteurBase->GetUserPrimKeyFromNumOrdre(G_pCApp->m_pCps->m_NIR, "-sgn", &fieldList);
    if (userPk.length())
       {QString userRet            = fieldList[0];
        G_pCApp->m_User            = userRet;
        G_pCApp->m_SignUser        = userRet;
        G_pCApp->m_CriptedPassWord = fieldList[1];     // m_USER_IDENT_PASSWORD
        Slot_reinitManagerOnUser(G_pCApp->m_User, G_pCApp->m_SignUser);
        return;
       }
   } // endif (cps.length())    // si cps active
#endif
 //............. verifier si l'utilisateur en cours est toujours l\303\240 ...............................
 //              si pas la reinitialiser la liste des utilisateurs
 //              et se mettre en unlogued
 QString userPk = m_pCMoteurBase->GetUserPrimKey(G_pCApp->m_User);
 if ( userPk.length()==0)
    {if (m_pC_Frm_UserList) m_pC_Frm_UserList->reinitOn_SignUser_User_Name("", "");
    }
}

//------------------------ Slot_CPS_IsClicked ---------------------------------------
void C_Manager::Slot_CPS_IsClicked()
{/*
#ifdef SESAM_VERSION

    QString          userPk = "";
    QString            user = "";
    QString            pass = "";
    QString      moduleName = "";
    int ret;

QString pathPlugin, pathLog;
CGestIni::Param_ReadParam(G_pCApp->m_LocalParam, "Sesam-Vitale", "pathPlugin",       &pathPlugin);
CGestIni::Param_ReadParam(G_pCApp->m_LocalParam, "Sesam-Vitale", "pathLog",          &pathLog);
CGestIni::Param_ReadParam(G_pCApp->m_LocalParam, "Sesam-Vitale", "ModuleName",       &moduleName);

if (moduleName == "PIXVITALE")
   {
   }
else
   {
    //..................................... ne pas rajouter "/" car c'est un nom de fichier ..........................
    if ( QDir::isRelativePath ( pathPlugin ) )  pathPlugin = QDir::cleanDirPath (pathPlugin.prepend(G_pCApp->m_PathAppli));
    //..................................... rajouter "/" car le chemin doit \303\252tre donn\303\251 avec ..........................
    if ( QDir::isRelativePath ( pathLog ) )     pathLog    = QDir::cleanDirPath (pathLog.prepend(G_pCApp->m_PathAppli) )+"/";

    QString pluginScript  = "[Execute]\r\n";
            pluginScript += "pathPlugin="      + pathPlugin                                           + "\r\n" +
                            "pathIni=****\r\n" +                // **** car indique d'utiliser le pathIni du plugin
                            "maskExch=Bonjour tout le monde\r\n"
                            "[Parametres]\r\n"
                            "m_Command       = READ_CPS\r\n"
                            "m_PathLog       =" + pathLog                                             + "\r\n" +
                            "m_DateConsult   =" + QDate::currentDate().toString("yyyyMMdd");
    //.............. liste des champs a extraire .......................................
    //               lors recherche de l'utilisateur indique par la Carte CPS
    QString     cps_data = "";
    QStringList fieldList;
    fieldList.append(m_pCMoteurBase->m_USER_IDENT_LOGIN);           // 0
    fieldList.append(m_pCMoteurBase->m_USER_IDENT_PASSWORD);        // 1
    if (pathPlugin.length())
       {cps_data = G_pCApp->PluginExe(this, pluginScript, CApp::endWait);
        G_pCApp->m_pCps->UnSerialize(cps_data);
        //CGestIni::Param_UpdateToDisk(G_pCApp->m_PathAppli + "test_ps.txt", ps_file);
        userPk = m_pCMoteurBase->GetUserPrimKeyFromNumOrdre(G_pCApp->m_pCps->m_NIR, "-sgn", &fieldList);
       }
    //.......................... si existe d\303\251j\303\240 le selectionner ..................................
    if (userPk.length())
       {if (G_pCApp->m_pCps->m_NIR.length())
           {user = fieldList[0];                           // m_USER_IDENT_LOGIN
            //m_CMDI_Identification->SetUser(user,"");
            G_pCApp->m_User            = user;
            G_pCApp->m_SignUser        = user;
            G_pCApp->m_CriptedPassWord = fieldList[1];     // m_USER_IDENT_PASSWORD
            G_pCApp->lireDroitsUtilisateurs();
            Slot_reinitManagerOnUser(G_pCApp->m_User, G_pCApp->m_SignUser);
           }
       }
    //.......................... sinon le cr\303\251er .........................................
    else if ( G_pCApp->m_pCps->m_NIR.length() && G_pCApp->m_pCps->m_Nom.length() && G_pCApp->m_pCps->m_Prenom.length())
       { ret = QMessageBox::information( this, tr("Utilisateur inconnu"),
                                               tr( "L'utilisateur : <b>«" + G_pCApp->m_pCps->m_Nom + "  " + G_pCApp->m_pCps->m_Prenom +
                                                   "»</b>de cette carte de praticien de sant\303\251<br/> n'est pas connu de MedinTux, <br/>" +
                                                   "faut-il cr\303\251er un nouvel utilisateur avec ?"
                                                  ) ,
                                               tr("&Cr\303\251er"), tr("&Annuler"), 0,
                                               1, 1 );
         if (ret==0)
            { editUser(cps_data);    // todo evaluer si au retour l'utilisateur est effac\303\251
            }
       }
   } // end else if (moduleName == "PIXVITALE")
#endif
   */
#ifdef SESAM_VERSION

    QString     userPk = "";
    QString     user = "";
    QString     pass = "";
    QString     moduleName = "";
    QString     cps_data = "";             // Cz_Pyxvital: d\303\251clarations sorties du if ...
    QStringList fieldList;                 // Cz_Pyxvital

    int ret;

QString pathPlugin, pathLog;
CGestIni::Param_ReadParam(G_pCApp->m_LocalParam, "Sesam-Vitale", "pathPlugin",       &pathPlugin);
CGestIni::Param_ReadParam(G_pCApp->m_LocalParam, "Sesam-Vitale", "pathLog",          &pathLog);
CGestIni::Param_ReadParam(G_pCApp->m_LocalParam, "Sesam-Vitale", "ModuleName",       &moduleName);

 if (moduleName == "PYXVITAL")
   {
    // Cz_Pyxvital ------------- DEBUT -----------------------------------------------------------------
    // Ex\303\251cution du programme Aixvitale avec le paramÃ¨tre CPS (lecture carte CPS)
    // Aixvitale lancera lui mÃªme la DLL de Pyxvital avec le paramÃ¨tre P.
    // Aixvitale retourne le nom complet du fichier Praticien.par contenant les infos lues sur la carte
    QString     fic_PraticienPar = "";     // exemple de nom attendu : "C:/pyxvital/INTERF/Praticien.par";
    fieldList.append(m_pCMoteurBase->m_USER_IDENT_LOGIN);           // 0
    fieldList.append(m_pCMoteurBase->m_USER_IDENT_PASSWORD);        // 1

    fic_PraticienPar = appelPyxvital ( "m_Command = CPS\r\n");
    if (fic_PraticienPar.length())
       {
       // au retour de AIxvitale on traite le fichier Praticien.par pour r\303\251alimenter cps_data...
       QSettings *settings = new QSettings(fic_PraticienPar, QSettings::IniFormat);
       G_pCApp->m_pCps->m_TypePS               = settings->value(tr("PS/Type_carte")).toString();
       G_pCApp->m_pCps->m_TypeIdNat            = settings->value(tr("PS/ADELI")).toString();
       G_pCApp->m_pCps->m_NIR                  = settings->value(tr("PS/Num\303\251ro")).toString();
       G_pCApp->m_pCps->m_Clef_NIR             = settings->value(tr("PS/Cl\303\251")).toString();
       G_pCApp->m_pCps->m_Nom                  = settings->value(tr("PS/Nom")).toString();
       G_pCApp->m_pCps->m_Prenom               = settings->value(tr("PS/Pr\303\251nom")).toString();
       G_pCApp->m_pCps->m_CodeCivilite         = settings->value(tr("PS/Code_civilit\303\251")).toString();
       G_pCApp->m_pCps->m_SectActivite         = settings->value(tr("PS/Secteur_activit\303\251")).toString();
       G_pCApp->m_pCps->m_TypIdentStruct       = settings->value(tr("PS/Type_identif_structure")).toString();
       G_pCApp->m_pCps->m_NumIdentStruct       = settings->value(tr("PS/Num\303\251ro_identif_structure")).toString();
       G_pCApp->m_pCps->m_NumIdentStructClef   = settings->value(tr("PS/Cl\303\251_identif_structure")).toString();
       G_pCApp->m_pCps->m_RaisonSocialeStruct  = settings->value(tr("PS/Raison_sociale_structure")).toString();
       G_pCApp->m_pCps->m_CodeConvention       = settings->value(tr("PS/Code_convention")).toString();
       G_pCApp->m_pCps->m_CodeSpecialite       = settings->value(tr("PS/Code_sp\303\251cialit\303\251")).toString();
       G_pCApp->m_pCps->m_CodeZoneTarif        = settings->value(tr("PS/Code_zone_tarifaire")).toString();
       G_pCApp->m_pCps->m_CodeZoneIk           = settings->value(tr("PS/Code_zone_IK")).toString();
       G_pCApp->m_pCps->m_CodeAgr1             = settings->value(tr("PS/Code_agr\303\251ment_1")).toString();
       G_pCApp->m_pCps->m_CodeAgr2             = settings->value(tr("PS/Code_agr\303\251ment_2")).toString();
       G_pCApp->m_pCps->m_CodeAgr3             = settings->value(tr("PS/Code_agr\303\251ment_3")).toString();
       G_pCApp->m_pCps->m_HabilitationSignFact = settings->value(tr("PS/Habilitation_Facture")).toString();
       G_pCApp->m_pCps->m_HabilitationSignLot  = settings->value(tr("PS/Habilitation_Lot")).toString();
       cps_data = G_pCApp->m_pCps->Serialize();

       userPk = m_pCMoteurBase->GetUserPrimKeyFromNumOrdre(G_pCApp->m_pCps->m_NIR, "-sgn", &fieldList);
       }
   } // fin if PYXVITAL
   // Cz_Pyxvital ------------------------ FIN -----------------------------------------------------
else   // cas standard QFSEVITALE
   {
    //..................................... ne pas rajouter "/" car c'est un nom de fichier ..........................
    if ( QDir::isRelativePath ( pathPlugin ) )  pathPlugin = QDir::cleanDirPath (pathPlugin.prepend(G_pCApp->m_PathAppli));
    //..................................... rajouter "/" car le chemin doit Ãªtre donn\303\251 avec ..........................
    if ( QDir::isRelativePath ( pathLog ) )     pathLog    = QDir::cleanDirPath (pathLog.prepend(G_pCApp->m_PathAppli) )+"/";

    QString pluginScript  = "[Execute]\r\n";
            pluginScript += "pathPlugin="      + pathPlugin                                           + "\r\n" +
                            "pathIni=****\r\n" +                //**** car indique d'utiliser le pathIni du plugin
                            "maskExch=Bonjour tout le monde\r\n"
                            "[Parametres]\r\n"
                            "m_Command       = READ_CPS\r\n"
                            "m_PathLog       =" + pathLog                                             + "\r\n" +
                            "m_DateConsult   =" + QDate::currentDate().toString("yyyyMMdd");
    //.............. liste des champs a extraire .......................................
    //               lors recherche de l'utilisateur indique par la Carte CPS
    // QString     cps_data = "";              // Cz_Pyxvital : d\303\251claration sortie du if
    // QStringList fieldList;                  // Cz_Pyxvital : d\303\251claration sortie du if
    fieldList.append(m_pCMoteurBase->m_USER_IDENT_LOGIN);           // 0
    fieldList.append(m_pCMoteurBase->m_USER_IDENT_PASSWORD);        // 1
    if (pathPlugin.length())
       {cps_data = G_pCApp->PluginExe(this, pluginScript, CApp::endWait);
        G_pCApp->m_pCps->UnSerialize(cps_data);
        //CGestIni::Param_UpdateToDisk(G_pCApp->m_PathAppli + "test_ps.txt", ps_file);
        userPk = m_pCMoteurBase->GetUserPrimKeyFromNumOrdre(G_pCApp->m_pCps->m_NIR, "-sgn", &fieldList);
       }
    } // end else Cas QFSEVITALE . Cz_Pyxvital ... La suite est commune .

    //.......................... si existe d\303\251jï¿½  le selectionner ..................................
    if (userPk.length())
       {if (G_pCApp->m_pCps->m_NIR.length())
           {user = fieldList[0];                           // m_USER_IDENT_LOGIN
            //m_CMDI_Identification->SetUser(user,"");
            G_pCApp->m_User            = user;
            G_pCApp->m_SignUser        = user;
            G_pCApp->m_CriptedPassWord = fieldList[1];     // m_USER_IDENT_PASSWORD
            G_pCApp->lireDroitsUtilisateurs();
            Slot_reinitManagerOnUser(G_pCApp->m_User, G_pCApp->m_SignUser);
            //CZ_Cpta deb
            reinitAgendaOnUser(G_pCApp->m_User , G_pCApp->m_SignUser);
            setInterfaceOnProfil(MODE_SELECTION_PATIENT);
            m_pGUI->tabWidget_Central->setEnabled(TRUE);
            m_pGUI->wdg_DockWidget_Agenda->setEnabled(TRUE);
            //CZ_Cpta fin
           }
       }
    //.......................... sinon le cr\303\251er .........................................
    else if ( G_pCApp->m_pCps->m_NIR.length() && G_pCApp->m_pCps->m_Nom.length() && G_pCApp->m_pCps->m_Prenom.length())
       { ret = QMessageBox::information( this, tr("Utilisateur inconnu"),
                                               tr( "L'utilisateur : <b> «" + G_pCApp->m_pCps->m_Nom + "  " + G_pCApp->m_pCps->m_Prenom +
                                                   "»</b> de cette carte de praticien de sant\303\251<br/> n'est pas connu de MedinTux, <br/>" +
                                                   "faut-il cr\303\251er un nouvel utilisateur avec ?"
                                                  ) ,
                                               tr("&Cr\303\251er"), tr("&Annuler"), 0,
                                               1, 1 );
         if (ret==0)
            { editUser(cps_data);    // todo evaluer si au retour l'utilisateur est effac\303\251
            }
       }
   // } // end else if (moduleName == "PIXVITALE") Cz_Pyxvital .  fin du else remont\303\251e pour r\303\251cup code commun
#endif

}

//------------------------ Slot_UserSelected_InListUser ---------------------------------------
void C_Manager::Slot_UserSelected_InListUser(QTreeWidgetItem *pUserItem , QTreeWidgetItem *pSignUserItem)
{   G_pCApp->m_User     = pUserItem->text(0);
   G_pCApp->m_SignUser = pSignUserItem->text(0);
   // G_pCApp->lireDroitsUtilisateurs(); deja fait dans l'autentification

   reinitAgendaOnUser(G_pCApp->m_User , G_pCApp->m_SignUser);
   setInterfaceOnProfil(MODE_SELECTION_PATIENT);
   m_pGUI->tabWidget_Central->setEnabled(TRUE);
   m_pGUI->wdg_DockWidget_Agenda->setEnabled(TRUE);
   replaceInitialDockVisibility();
   setMedWebTuxOnUser();
   //addUserAgenda(G_pCApp->m_SignUser, QDate::currentDate());
   //............ ATTENTION AUX CONNEXIONS CIRCULAIRES .............
   // reinitListUserOnUser(G_pCApp->m_User , G_pCApp->m_SignUser); surtout pas car connexion circulaire !! m'a fait perdre une journ\303\251e ce truc
   // ==> ne pas appeler les trucs suivant :  Slot_reinitManagerOnUser
}

//------------------------ reinitListUserOnUser ---------------------------------------
void C_Manager::reinitListUserOnUser(const QString &user , const QString &signUser)
{  if (m_pC_Frm_UserList==0) return;
   m_pC_Frm_UserList->reinitOn_SignUser_User_Name(user, signUser);
}
//------------------------ replaceInitialDockVisibility ---------------------------------------
void C_Manager::replaceInitialDockVisibility()
{ if (m_AgendaInitialVisbility==1) m_pGUI->wdg_DockWidget_Agenda->show();
 if (m_AgendaInitialVisbility==0) m_pGUI->wdg_DockWidget_Agenda->hide();
 m_AgendaInitialVisbility   = 2;  // cet etat ne doit fonctionner qu'au debut lors login
 if (m_UserListInitialVisbility==1)  m_pGUI->wdg_DockWidget_User->show();
 if (m_UserListInitialVisbility==0)  m_pGUI->wdg_DockWidget_User->hide();
 m_UserListInitialVisbility = 2;  // cet etat ne doit fonctionner qu'au debut lors login
}
//------------------------ reinitManagerOnUser ---------------------------------------
void C_Manager::Slot_reinitManagerOnUser(QTreeWidgetItem *pUserItem , QTreeWidgetItem *pSignUserItem)
{   //............. prendre note des nouveaux utilisateurs .......................................
   Slot_reinitManagerOnUser(pUserItem->text(0) , pSignUserItem->text(0));
}

//------------------------ reinitManagerOnUser ---------------------------------------
void C_Manager::Slot_reinitManagerOnUser(const QString &user , const QString &signUser)
{reinitAgendaOnUser(user , signUser);
reinitListUserOnUser(user , signUser);
G_pCApp->m_User            = user;
G_pCApp->m_SignUser        = signUser;
G_pCApp->lireDroitsUtilisateurs();
setInterfaceOnProfil(MODE_SELECTION_PATIENT);
replaceInitialDockVisibility();
setMedWebTuxOnUser();
}

////////////////////////////////////////////// POSITIONS DES FENETRES ////////////////////////////////////////////////////////
//------------------------ Slot_actionRecordWindowsPos_triggered ---------------------------------------
void C_Manager::Slot_actionRecordWindowsPos_triggered(bool)
{Slot_RecordPos();
}
//------------------------ Slot_actionHideShowLogo_triggered ---------------------------------------
void C_Manager::Slot_actionHideShowLogo_triggered (bool)
{if (m_pGUI->textLabelPixMap->isShown())m_pGUI->textLabelPixMap->hide();
else                                   m_pGUI->textLabelPixMap->show();

}

//------------------------ Slot_actionSetGlobalFont_triggered ---------------------------------------
void C_Manager::Slot_actionSetGlobalFont_triggered (bool)
{   //bool ok=FALSE;
   QFontDialog fdlg(G_pCApp->m_GuiFont, this);
   fdlg.setOption ( QFontDialog::DontUseNativeDialog ,TRUE );
   fdlg.setCurrentFont ( G_pCApp->m_GuiFont );
   fdlg.setCaption(tr("Mais que fait la police ?"));
   fdlg.setModal ( TRUE );
   //fdlg.setWindowFlags ((fdlg.windowFlags()&~(Qt::WindowCloseButtonHint|Qt::Dialog)|));
   if (fdlg.exec()==QDialog::Accepted)
   //QFont font = QFontDialog::getFont( &ok, G_pCApp->m_GuiFont, this, tr("Mais que fait la police ?"));
   // QFontDialog::getFont ( bool * ok, const QFont & initial, QWidget * parent, const QString & title, FontDialogOptions options )
   //if (ok )
      {/*
       Family = Arial
       Italic = 0
       Underline = 0
       PointSize = 10
       Weight = 50
       */
       QFont font = fdlg.selectedFont ();
       CGestIni::Param_WriteParam(&G_pCApp->m_LocalParam, "Font", "Family",     font.family() );
       CGestIni::Param_WriteParam(&G_pCApp->m_LocalParam, "Font", "PointSize",  QString::number(font.pointSize()) );
       CGestIni::Param_WriteParam(&G_pCApp->m_LocalParam, "Font", "Italic",     QString::number(font.italic()) );
       CGestIni::Param_WriteParam(&G_pCApp->m_LocalParam, "Font", "Underline",  QString::number(font.underline()) );
       CGestIni::Param_WriteParam(&G_pCApp->m_LocalParam, "Font", "Weight",     QString::number(font.weight()) );
       setAllWidgetsOnFont(font);
       G_pCApp->m_GuiFont = font;
       QApplication::setFont(font);
       CGestIni::Param_UpdateToDisk(G_pCApp->m_PathAppli + "Manager.ini", G_pCApp->m_LocalParam);
      }
}

//---------------------------------------------- get_RecordDispos ------------------------------------------------------------
void C_Manager::get_RecordDispos()
{   QString path = G_pCApp->m_PathAppli + "Manager.dps";
   if ( !QFile::exists(path) )                return;
   QFile file( path );
   if ( !file.open( QIODevice::ReadOnly ) )   return;
   restoreState (file.readAll());
   file.close();
}

//---------------------------------------------- Slot_RecordDispos ------------------------------------------------------------
void C_Manager::Slot_RecordDispos()
{   QFile file( G_pCApp->m_PathAppli + "Manager.dps" );
   if ( !file.open( QIODevice::WriteOnly ) )        return;
   file. write (saveState());
   file.close();
}

//---------------------------------------------- Slot_RecordPos ------------------------------------------------------------
void C_Manager::Slot_RecordPos()
{
   int x  =  this->x();
   int y  =  this->y();
   int w  =  this->width();
   int h  =  this->height();
   CGestIni::Param_WriteParam(&G_pCApp->m_LocalParam, "ManagerPos", "Positions",
                                 QString::number(x),      QString::number(y),
                                 QString::number(w),      QString::number(h));
   CGestIni::Param_UpdateToDisk(G_pCApp->m_PathAppli + "Manager.ini", G_pCApp->m_LocalParam);
   Slot_RecordDispos();
}

//////////////////////////////// GESTION DU STYLE DES MODES (CREATION SELECTION MULTICRITERE) ////////////////////////////////////////////////////////
//---------------------------------------------- getBoxStyle -----------------------------------------------------------------------------------------
QString C_Manager::getBoxStyle(int mode)
{ QString folderDefStyle  = "";

 #ifdef Q_WS_WIN
    folderDefStyle = G_pCApp->m_PathAppli+"Ressources/Win/BoxStyle_";
 #endif
 #ifdef Q_WS_MAC
    folderDefStyle = G_pCApp->m_PathAppli+"Ressources/Mac/BoxStyle_";
 #endif
 #ifdef Q_WS_X11
    folderDefStyle = G_pCApp->m_PathAppli+"Ressources/Lin/BoxStyle_";
 #endif
 QString style  = CGestIni::Param_UpdateFromDisk(folderDefStyle + m_List_GUI_Mode[mode]+".css");
 int pointSize  = G_pCApp->m_GuiFont.pointSize();
 if (style.length()!=0) return style.arg(pointSize);
 switch (mode)
    {default :
     case MODE_SELECTION_PATIENT:
          return QString("QGroupBox {"
                              "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #E0E0E0, stop: 1 #FFFFFF);"
                              "border: 1px solid gray;"
                              "border-radius: 5px;"
                              "font-size: %1px;"
                              "font-weight: bold;"
                              "padding-top: 7ex;"    // marge int\303\251rieure au cadre pour placer le premier objet
                              "margin-top: 1ex;} "   // marge entre le cadre et le haut de l'objet
                 "QGroupBox::title {"
                              "subcontrol-origin: margin;"
                              "subcontrol-position: top left;" /* position at the top center */
                              "left: 20px;"             // ofset de deplacement gauche
                              "padding-top: 2px;"       // marge int\303\251rieure gauche au cadre pour placer le premier objet (texte)
                              "padding-left: 10px;"     // marge int\303\251rieure gauche au cadre pour placer le premier objet (texte)
                              "padding-right: 10px;"    // marge int\303\251rieure droite au cadre pour placer le premier objet (texte)
                              "border-radius: 3px;"
                              "border: 1px solid gray;"
                              //"border-bottom-style: none;"
                              //"border-style: none;"
                              "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #8e8b8d, stop: 1 #FFFFFF);}").arg(pointSize);
     case MODE_CREATION_PATIENT:
          return QString("QGroupBox {"
                              "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #6976f7, stop: 1 #FFFFFF);"
                              "border: 1px solid gray;"
                              "border-radius: 5px;"
                              "font-size: %1px;"
                              "font-weight: bold;"
                              "padding-top: 7ex;"    // marge int\303\251rieure au cadre pour placer le premier objet
                              "margin-top: 1ex;} "   // marge entre le cadre et le haut de l'objet
                 "QGroupBox::title {"
                              "subcontrol-origin: margin;"
                              "subcontrol-position: top left;" /* position at the top center */
                              "left: 20px;"             // ofset de deplacement gauche
                              "padding-top: 2px;"       // marge int\303\251rieure gauche au cadre pour placer le premier objet (texte)
                              "padding-left: 10px;"     // marge int\303\251rieure gauche au cadre pour placer le premier objet (texte)
                              "padding-right: 10px;"    // marge int\303\251rieure droite au cadre pour placer le premier objet (texte)
                              "border-radius: 3px;"
                              "border: 1px solid gray;"
                              //"border-bottom-style: none;"
                              //"border-style: none;"
                              "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #4b55b0, stop: 1 #FFFFFF);}").arg(pointSize);
     case MODE_MULTICRITERE:
          return QString("QGroupBox {"
                              "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ff743e, stop: 1 #FFFFFF);"
                              "border: 1px solid gray;"
                              "border-radius: 5px;"
                              "font-size: %1px;"
                              "font-weight: bold;"
                              "padding-top: 7ex;"    // marge int\303\251rieure au cadre pour placer le premier objet
                              "margin-top: 1ex;} "   // marge entre le cadre et le haut de l'objet
                 "QGroupBox::title {"
                              "subcontrol-origin: margin;"
                              "subcontrol-position: top left;" /* position at the top center */
                              "left: 20px;"             // ofset de deplacement gauche
                              "padding-top: 2px;"       // marge int\303\251rieure gauche au cadre pour placer le premier objet (texte)
                              "padding-left: 10px;"     // marge int\303\251rieure gauche au cadre pour placer le premier objet (texte)
                              "padding-right: 10px;"    // marge int\303\251rieure droite au cadre pour placer le premier objet (texte)
                              "border-radius: 3px;"
                              "border: 1px solid gray;"
                              //"border-bottom-style: none;"
                              //"border-style: none;"
                              "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #af512d, stop: 1 #FFFFFF);}").arg(pointSize);
      }

}

//---------------------------------------------- getTabStyle ------------------------------------------------------------
QString C_Manager::getTabStyle(int mode)
{ QString folderDefStyle  = "";
#ifdef Q_WS_WIN
   folderDefStyle = G_pCApp->m_PathAppli+"Ressources/Win/TabStyle_";
#endif
#ifdef Q_WS_MAC
   folderDefStyle = G_pCApp->m_PathAppli+"Ressources/Mac/TabStyle_";
#endif
#ifdef Q_WS_X11
   folderDefStyle = G_pCApp->m_PathAppli+"Ressources/Lin/TabStyle_";
#endif
QString style  = CGestIni::Param_UpdateFromDisk(folderDefStyle + m_List_GUI_Mode[mode]+".css");
int pointSize  = G_pCApp->m_GuiFont.pointSize();
if (style.length()!=0) return style.arg(pointSize);
 switch (mode)
    {default :
     case MODE_CREATION_PATIENT:
          return QString("QGroupBox {"
                              "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #6976f7, stop: 1 #FFFFFF);"
                              "border: 1px solid gray;"
                              "border-radius: 5px;"
                              "font-size: %1px;"
                              "font-weight: bold;"
                              "padding-top: 2ex;"    // marge int\303\251rieure au cadre pour placer le premier objet
                              "margin-top: 1ex;} "   // marge entre le cadre et le haut de l'objet
                 "QGroupBox::title {"
                              "subcontrol-origin: margin;"
                              "subcontrol-position: top left;" /* position at the top center */
                              "left: 20px;"             // ofset de deplacement gauche
                              "padding-top: 2px;"       // marge int\303\251rieure gauche au cadre pour placer le premier objet (texte)
                              "padding-left: 10px;"     // marge int\303\251rieure gauche au cadre pour placer le premier objet (texte)
                              "padding-right: 10px;"    // marge int\303\251rieure droite au cadre pour placer le premier objet (texte)
                              "border-radius: 3px;"
                              "border: 1px solid gray;"
                              //"border-bottom-style: none;"
                              //"border-style: none;"
                              "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #4b55b0, stop: 1 #FFFFFF);}").arg(pointSize);
     case MODE_MULTICRITERE:
          return QString("QGroupBox {"
                              "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ff743e, stop: 1 #FFFFFF);"
                              "border: 1px solid gray;"
                              "border-radius: 5px;"
                              "font-size: %1px;"
                              "font-weight: bold;"
                              "padding-top: 2ex;"    // marge int\303\251rieure au cadre pour placer le premier objet
                              "margin-top: 1ex;} "   // marge entre le cadre et le haut de l'objet
                 "QGroupBox::title {"
                              "subcontrol-origin: margin;"
                              "subcontrol-position: top left;" /* position at the top center */
                              "left: 20px;"             // ofset de deplacement gauche
                              "padding-top: 2px;"       // marge int\303\251rieure gauche au cadre pour placer le premier objet (texte)
                              "padding-left: 10px;"     // marge int\303\251rieure gauche au cadre pour placer le premier objet (texte)
                              "padding-right: 10px;"    // marge int\303\251rieure droite au cadre pour placer le premier objet (texte)
                              "border-radius: 3px;"
                              "border: 1px solid gray;"
                              //"border-bottom-style: none;"
                              //"border-style: none;"
                              "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #af512d, stop: 1 #FFFFFF);}").arg(pointSize);;
     case MODE_SELECTION_PATIENT:
          return QString("QGroupBox {"
                              "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #E0E0E0, stop: 1 #FFFFFF);"
                              "border: 1px solid gray;"
                              "border-radius: 5px;"
                              "font-size: %1px;"
                              "font-weight: bold;"
                              "padding-top: 2ex;"    // marge int\303\251rieure au cadre pour placer le premier objet
                              "margin-top: 1ex;} "   // marge entre le cadre et le haut de l'objet
                 "QGroupBox::title {"
                              "subcontrol-origin: margin;"
                              "subcontrol-position: top left;" /* position at the top center */
                              "left: 20px;"             // ofset de deplacement gauche
                              "padding-top: 2px;"       // marge int\303\251rieure gauche au cadre pour placer le premier objet (texte)
                              "padding-left: 10px;"     // marge int\303\251rieure gauche au cadre pour placer le premier objet (texte)
                              "padding-right: 10px;"    // marge int\303\251rieure droite au cadre pour placer le premier objet (texte)
                              "border-radius: 3px;"
                              "border: 1px solid gray;"
                              //"border-bottom-style: none;"
                              //"border-style: none;"
                              "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #8e8b8d, stop: 1 #FFFFFF);}").arg(pointSize);;

      }
}
//Cz_Pyxvital ------------------------------- DEBUT -----------------------------------------------------
//----------------------------------- Slot_saisieFSEenCours -------------------------------------------------------------------------
// ContrÃ´le si la saisie FSE par PYxvital est en cours .
// --> test de la pr\303\251sence du fichier Facture.par
// --> si seulement un acte a \303\251t\303\251 saisi, le fichier Facture.par contient un groupe "Prestation" ?? PAS SUR
// --> si la FSE est valid\303\251e le fichier Facture.par contient le groupe "Tarification" avec un "Taux".
// ContrÃ´le si le patient en cours dans Pyxvital est bien le patient s\303\251lectionn\303\251 dans Manager
void C_Manager::Slot_saisieFSEenCours()
{   bool finFSE = false;
   QString nomficErreur = m_ficFacturePar;                      // CZ_Cpta
   nomficErreur = nomficErreur.replace("Facture","Erreurs");
   if (QFile::exists(nomficErreur) )                           // il y a eu une erreur ou un Annuler dans Pyxvital
       {finFSE = true;
       }
   if (QFile::exists(m_ficFacturePar) )
       {QSettings *settings = new QSettings(m_ficFacturePar, QSettings::IniFormat);
       QString    numfact = settings->value(tr("Tarification/Taux")).toString();
       if (numfact.length() > 0)                               // la saisie est terminÃ©e : La FSE a ete validee.
         {finFSE = true;
         }
       else                                                  // au moins une ligne d'acte a ete saisie : La saisie est en cours.
         {m_FSEenCours = TRUE;
         m_pGUI->pushButton_FSE->setText("Annuler la facture en cours") ;
         }
       }
   if (finFSE)
       {           // soit : la FSE a ete validee.
                   // soit : on a saisit un autre patient dans Pyxvital >> ce qui est interdit.
                   // soit on a reselectionne un autre patient dans medintux sans saisiz d'actes dans Pyxvital
       m_FSEenCours = FALSE;
       m_pGUI->pushButton_FSE->setText(tr("Facturer"));
       m_pGUI->pushButton_FSE->setEnabled (FALSE );            // dÃ©sactiver ce bouton en plus ????
       m_timerFSE->stop();                                     // arrÃ?Âªt du timer d'attente du fichier Facture.par
       QTreeWidget *pQlistView = m_pGUI->listView_Vitale;
       pQlistView->clear();
       Controle_Solde_Patient(G_pCApp->identitePatientGUID());                       // CZ_Cpta

       } // fin du FSE validÃ©e
}


//--------------------------------- Slot_pushButton_FSE -----------------------------------------------------------------------
// Lancement de Pyxvital pour saisie des actes et validation des FSE .
// Pour simplifier la proc\303\251dure :
// - manager g\303\251nÃ¨re syst\303\251matiquement un fichier CV.par contenant toutes les infos du patient (+ les donn\303\251es AMC ?, AMO ?)
// - c'est Aixvitale qui testera si la CV a \303\251t\303\251 lue ...
// - si CV OK avec patient en cours, c'est la CV qui est prise en compte.
// - si pas de CV et D\303\251grad\303\251 OK , c'est CV.par qui sera pris par Pyxvital.
void C_Manager::Slot_pushButton_FSE()
{
#ifdef SESAM_VERSION
   QString zcvdns ;
   QString zcvnss ;
   QString zcvqual ;
   QString zcvrang ;
   QString zcvnom ;
   QString zcvprn ;
   QString numSecu;
   QString rangGem;
   QString qualite;

   QString moduleName;
   QString interf_Pyx;

   CGestIni::Param_ReadParam(G_pCApp->m_LocalParam, "Sesam-Vitale", "ModuleName",       &moduleName);
   CGestIni::Param_ReadParam(G_pCApp->m_LocalParam, "Sesam-Vitale", "Interface_module", &interf_Pyx);

  if (moduleName=="PYXVITAL")    // test inutile
     {
      // vÃ©rification qu'une FSE n'est pas dÃ©jÃ?  en cours de saisie
      if (m_FSEenCours)
         {
          int ret    = QMessageBox::warning ( this, tr("FSE en cours"),
                       tr( "<u><b>ATTENTION :</u></b><br><br>Une FSE est en cours de saisie !<br>Voulez vous abandonner la FSE en cours ?"),
                       tr("&Abandonner la FSE en cours"), tr("Annu&ler"), 0, 1, 1);
          if (ret == 1) return;
          // voir comment effacer le formulaire Pyxvital si acte dÃ©jÃ?  saisi...
          // la lecture de la CV remet tout a zÃ©ro...
         }

      // cherche si le patient sÃ©lectionnÃ© dans la liste patient est bien dans la liste Vitale
      QTreeWidgetItemIterator it( m_pGUI->listView_Vitale );
      bool patientOK = false;
      m_typFact = "";
         while ( *it )
            {
               QTreeWidgetItem *pQListViewItem = *it;
               zcvnss   = pQListViewItem->text(3);
               zcvrang  = pQListViewItem->text(4);
               if (zcvrang.length()== 1) zcvrang = zcvrang.prepend("0");
               zcvqual  = pQListViewItem->text(5);
               zcvnom   = pQListViewItem->text(0);
               zcvprn   = pQListViewItem->text(1);

               numSecu  = m_pGUI->lineEdit_NumSecu->text(); numSecu.remove(" ");
               if (  zcvnss  ==  numSecu &&
                     zcvqual == qualite.setNum(m_pGUI->comboBoxQualiteAyantDroit->currentIndex())  &&
                     zcvrang == m_pGUI->lineEdit_RangGeme->text() &&
                     zcvnom  == m_pGUI->lineEdit_NomDossier->text() &&
                     zcvprn  == m_pGUI->lineEdit_PrenomDossier->text()
                     // Voir si tester la date de naissance ?????
                  )
                  { patientOK = true ;
                    m_typFact = "FSE";
                    break;
                  }
               ++it;
            }
     if (!patientOK)
         {
         // PAs de FSE possible car pas de CV -- on propose un autre choix !
         // Debut CZ_Cpta
         QMessageBox msgBox;
         msgBox.setText(tr("<b>La carte Sesam-Vitale n'a pas \303\251t\303\251 lue pour ce patient !<br><br></b>"
                             "Que voulez-vous faire : <br><br>"
                             "- Annuler et lire la carte Sesam Vitale,<br>"
                             "- Continuer et saisir une feuille de soin en mode D\303\251grad\303\251,<br>"
                             "- Continuer et saisir une feuille de soin papier ,<br>"
                             "- Continuer et saisir une facture.<br>"));
         msgBox.addButton(tr("Annuler"),                 QMessageBox::HelpRole);
         msgBox.addButton(tr("Mode d\303\251grad\303\251"),            QMessageBox::HelpRole);
         msgBox.addButton(tr("Saisir une FSP"),          QMessageBox::HelpRole);
         msgBox.addButton(tr("Saisir une facture"),      QMessageBox::HelpRole);
         QFont ft("sans",10,0,0);
         msgBox.setFont(ft);
         msgBox.window()->setWindowTitle("Choix du type de facturation");
         int ret = msgBox.exec();
         if ( ret == 0) return;
         if ( ret == 1) m_typFact = "DEG";
         if ( ret == 2) m_typFact = "FSP";
         if ( ret == 3) m_typFact = "PFA";
         // fin CZ_Cpta

         zcvnom   = m_pGUI->lineEdit_NomDossier->text();
         zcvprn   = m_pGUI->lineEdit_PrenomDossier->text();

         // CrÃ©ation du fichier CV.par ...................................................................
         // Le fichier CV.Par ne sert que pour le mode DÃ©gradÃ©, les FSP ou les prÃ©factures.
         // les infos fournies sont donc celles de la base Medintux et non pas celles de la Carte SV
         QString nomFicCVpar = interf_Pyx + "/CV.par";
         remove (nomFicCVpar);
         QSettings *settings = new QSettings(nomFicCVpar, QSettings::IniFormat);

         settings->beginGroup("Beneficiaire");
         settings->setValue("Nom",               m_pGUI->lineEdit_NomDossier->text());
         settings->setValue("Prenom",            m_pGUI->lineEdit_PrenomDossier->text());
         zcvqual.setNum(m_pGUI->comboBoxQualiteAyantDroit->currentIndex());
         if (zcvqual.length() == 1) zcvqual.prepend("0");
         settings->setValue("Code_qualite",      zcvqual);
         zcvdns = m_pGUI->lineEdit_DtNss->text();   zcvdns.replace(2,1,"/");  zcvdns.replace(5,1,"/");
         settings->setValue("date_de_naissance", zcvdns);
         zcvrang = m_pGUI->lineEdit_RangGeme->text();
         zcvrang.setNum(zcvrang.toInt());
         settings->setValue("Rang_gemellaire", zcvrang);                        // CZ_Cpta
         settings->endGroup();

         settings->beginGroup("Assure");
         settings->setValue("Nom",               m_pGUI->lineEdit_NomAssure->text());
         settings->setValue("Prenom",            m_pGUI->lineEdit_PrenomAssure->text());
         zcvnss = m_pGUI->lineEdit_NumSecu->text(); zcvnss.remove(" ");
         settings->setValue("Numero",            zcvnss);
         settings->setValue("Cle",               m_pGUI->lineEdit_NssClef->text());
         // pas de date de naissance de l'assurÃ©
         settings->endGroup();
         settings->sync();
         // ajouter la saisie et le stockage des champs dans les onglets AMC - AMO
         // pas obligatoire car on peut les saisir dans Pyxvital
         /*
         QString m_codeRegime;
         QString m_caisseGestionnaire;
         QString m_centreGestionnaire;
         m_codeRegime = "01";
         m_caisseGestionnaire = "999";
         m_centreGestionnaire = "9999";
         settings->beginGroup("Medico_administratif");
         settings->setValue("Code_regime",         m_codeRegime);
         settings->setValue("Caisse_gestionnaire", m_caisseGestionnaire);
         settings->setValue("Centre_gestionnaire", m_centreGestionnaire);
         settings->endGroup();
         */
         }

         // appel Ã?  AixVitale (qui lance Pyxvital) pour saisie des actes et gÃ©nÃ©ration de la FSE.
         //--- dÃ©but CZ_Cpta

         QString numPS = G_pCApp->m_pCps->m_NIR.length() > 6 ? G_pCApp->m_pCps->m_NIR : "PasLu";
         QString listParam =  "p_actionPyx =" + m_typFact                              + "\r\n"
                              "p_logUser ="   + G_pCApp->m_User                        + "\r\n"
                              "m_typFact ="   + m_typFact                              + "\r\n"
                              "p_numSecu ="   + zcvnss                                 + "\r\n"
                              "p_qualite ="   + zcvqual                                + "\r\n"
                              "p_rangGem ="   + zcvrang                                + "\r\n"
                              "p_nom ="       + zcvnom                                 + "\r\n"
                              "p_prenom ="    + zcvprn                                 + "\r\n"
                              "p_datnss ="    + m_pGUI->lineEdit_DtNss->text()         + "\r\n"
                            //"p_datnss ="    + m_pGUI->lineEdit_DtNss_Assure->text()  + "\r\n"
                              "p_GUIDPat ="   + G_pCApp->identitePatientGUID()         + "\r\n"
                              "p_PKPat ="     + G_pCApp->identitePatientPk()           + "\r\n"
                              "p_NumPS ="     + numPS                                  + "\r\n"
                              "p_NomAssu ="   + m_pGUI->lineEdit_NomAssure->text()     + "\r\n"
                              "p_PreAssu ="   + m_pGUI->lineEdit_PrenomAssure->text()  + "\r\n";
         //--- fin CZ_Cpta
         m_ficFacturePar = appelPyxvital ( listParam);
        if (m_ficFacturePar.length())
           {
            // AU retour :
            // - soit on a pu lancer Pyxvital, et on a le nom du futur fichier Facture.par en retour.
            //   on boucle sur le test de la prÃ©sence de ce fichier pour le traiter...
            // - soit on a le mot "Erreur" avec le message d'erreur.
             if (strncmp (m_ficFacturePar,"Erreur",6) != 0 )
                 {
                 if (m_timerFSE == 0)
                     { m_timerFSE = new QTimer(this);
                     connect(m_timerFSE, SIGNAL(timeout()), this, SLOT(Slot_saisieFSEenCours()));
                     }
                 if (!m_timerFSE->isActive())
                     m_timerFSE->start(1000);
                 }
            }
    } // fin if PYXVITAL
#endif
}
//-------------------------------------- appelPyxvital -------------------------------------
QString C_Manager::appelPyxvital (QString listeParametres)
{
   QString pathPlugin, pathLog, pluginScript;
   CGestIni::Param_ReadParam(G_pCApp->m_LocalParam, "Sesam-Vitale", "pathPlugin",       &pathPlugin);
   CGestIni::Param_ReadParam(G_pCApp->m_LocalParam, "Sesam-Vitale", "pathLog",          &pathLog);

   if ( QDir::isRelativePath ( pathPlugin ) )  pathPlugin = QDir::cleanDirPath (pathPlugin.prepend(G_pCApp->m_PathAppli));
   if ( QDir::isRelativePath ( pathLog ) )     pathLog    = QDir::cleanDirPath (pathLog.prepend(G_pCApp->m_PathAppli) )+"/";

   if (pathPlugin.length())
       {
        pluginScript  = "[Execute]\r\n";
        pluginScript += "pathPlugin="      + pathPlugin    + "\r\n" +
                   "pathIni=****\r\n" +                   //**** car indique d'utiliser le pathIni local du plugin
                   "maskExch=Bonjour tout le monde\r\n"
                   "[Parametres]\r\n" +
                   listeParametres;

   return (G_pCApp->PluginExe(this, pluginScript, CMoteurBase::endWait));
   }
   return QString::null;
}
//--------------------------------- Slot_Button_Vitale_ContextMenuRequested -----------------------------------------------------------------------
void C_Manager::Slot_Button_Vitale_ContextMenuRequested (const QPoint &)
{Slot_Button_Vitale_MenuRequested();
}
//--------------------------------- Slot_Button_Vitale_MenuRequested -----------------------------------------------------------------------
void C_Manager::Slot_Button_Vitale_MenuRequested()
{
//#ifdef VITALE_VERSION
QStringList list;

list.append(tr("Formater les fichiers et T\303\250l\303\250transmettre"));            // CZ_Cpta
list.append(tr("T\303\250l\303\250transmission seule"));                              // CZ_Cpta
list.append(tr("D\303\250charger le TLA"));                                           // CZ_Cpta

list.append("----------");
list.append(tr("Liste des recettes"));                                  // CZ_Cpta2
list.append("----------");
list.append(tr("Lancer Pyxvital"));
list.append("----------");

//.................. actionner le menu et les actions .................................................
QString ret = G_pCApp->DoPopupList(list);
/***********
action = ret.find('-');
if (action != -1) action = ret.left(action).toInt();
switch(action)
       {case 1:    appelPyxvital ( "m_Action  = FTL\r\n"
                                   "m_logUser ="  + G_pCApp->m_User + "\r\n"); // CZ_Cpta;
                   break;                                                      // CZ_Cpta;
        case 2:    appelPyxvital ( "m_Action = TEL\r\n");     break;          // CZ_Cpta;
        case 0:    appelPyxvital ( "m_Action = PYX\r\n");     break;
        case 3:    appelCompta   ("TDB");                     break;          // CZ_Cpta2
       }
***********/
//Debut CZ_Cpta2
QString    queFaire = ret.left(6);

   if (queFaire == tr("Format"))
       appelPyxvital ( "m_Action  = FTL\r\n" "m_logUser ="  + G_pCApp->m_User + "\r\n");
   else
   if (queFaire == tr("T\303\250l\303\250tr"))
       appelPyxvital ( "m_Action = TEL\r\n" "m_logUser ="  + G_pCApp->m_User + "\r\n"); //
   else
   if (queFaire == tr("Liste "))
       appelCompta   ("TDB");
   else
   if (queFaire == tr("Lancer"))
       appelPyxvital ( "m_Action = PYX\r\n");
   else
   if (queFaire == tr("D\303\250char"))
       appelPyxvital ( "m_Action = TLA\r\n" "m_logUser ="  + G_pCApp->m_User + "\r\n"); // MODIF CZ 11.05.2010
//fin CZ_Cpta2
//#endif
}

//-----------------------------------------------Controle_Solde_Patient----------------------------------------
void C_Manager::Controle_Solde_Patient(QString guidPatient)
{
double  soldePatient = 0;
double  soldePayeur  = 0;
QString requete;
QPixmap iconeSolde;
QString localParam  = "";

//    CGestIni::Param_UpdateFromDisk(G_pCApp->m_PathIni, localParam);
if (CGestIni::Param_ReadUniqueParam(G_pCApp->m_LocalParam, "Comptabilite", "Controle solde") != "oui")
       return;
   if (G_pCApp->IsThisDroitExist("sld"))
       m_pGUI->pushButton_solde->setVisible ( true );
   else
       {m_pGUI->pushButton_solde->setVisible ( false ); return; }

   if  (m_pCMoteurBase->OpenBase()==0)                                                                    return;
   requete =  "SELECT "
              " FE_GUIDPayeur, ROUND(FE_TotAssure,2), ROUND(FE_TotRegltASS,2), ROUND(FE_MtPP,2) "  // 0-1-2-3
              " FROM fact_entete "
              " WHERE (( FE_GUIDPatient        = '" + guidPatient + "' ) "
              " or     ( FE_GUIDPayeur         = '" + guidPatient + "' )) "
              " and    (ROUND(FE_TotAssure,2) != ROUND(FE_TotRegltASS + FE_MtPP,2)) "
              " and    (FE_Soldee             != 'S' )" ;
 QSqlQuery query(requete , m_pCMoteurBase->getDatabase() );
 if (query.isActive())
    {while (query.next())
        {if (query.value(0).toString().length() > 1 && query.value(0).toString() != guidPatient)
               soldePayeur   +=  query.value(1).toDouble() - query.value(2).toDouble() - query.value(3).toDouble();
            else
                soldePatient +=  query.value(1).toDouble() - query.value(2).toDouble() - query.value(3).toDouble();
        } // while (query.next())
    } //endif (query.isActive())
 m_pCMoteurBase->CloseBase();
if (soldePatient > 0)                 // affiche drapeau Rouge
       m_pGUI->pushButton_solde->setIcon ( Theme::getIcon("SoldeRouge.png") );

   else
       if (soldePayeur  > 0)           // affiche drapeau Orange
           m_pGUI->pushButton_solde->setIcon ( Theme::getIcon("SoldeOrange.png") );
       else
           m_pGUI->pushButton_solde->setIcon ( Theme::getIcon("SoldeVert.png") );
}

//------------------------------------Slot_Saisie_Reglement--------------------------------------------------
void C_Manager::Slot_Saisie_Reglement()
{
   #ifdef SESAM_VERSION
   QString localParam  = "";

   CGestIni::Param_UpdateFromDisk(G_pCApp->m_PathIni, localParam);
   if (CGestIni::Param_ReadUniqueParam(localParam, "Comptabilite", "Saisie reglement") != "oui")
       return;

   if (!G_pCApp->IsThisDroitExist("rgl"))
       return;

   QString numPS = G_pCApp->m_pCps->m_NIR.length() > 6 ? G_pCApp->m_pCps->m_NIR : "PasLu";
   QString zcvrang = m_pGUI->lineEdit_RangGeme->text();
   zcvrang.setNum(zcvrang.toInt());
   QString zcvnss  = m_pGUI->lineEdit_NumSecu->text(); zcvnss.remove(" ");
   QString zcvqual;    zcvqual.setNum(m_pGUI->comboBoxQualiteAyantDroit->currentIndex());
   if (zcvqual.length() == 1) zcvqual.prepend("0");
       QString listParam =  "p_actionPyx =" "REG"                                      "\r\n"
                            "p_logUser ="   + G_pCApp->m_User                        + "\r\n"
                            "m_typFact ="   "XXX"                                      "\r\n"
                            "p_numSecu ="   + zcvnss                                 + "\r\n"
                            "p_qualite ="   + zcvqual                                + "\r\n"
                            "p_rangGem ="   + zcvrang                                + "\r\n"
                            "p_nom ="       + m_pGUI->lineEdit_NomDossier->text()    + "\r\n"
                            "p_prenom ="    + m_pGUI->lineEdit_PrenomDossier->text() + "\r\n"
                            "p_datnss ="    + m_pGUI->lineEdit_DtNss->text()         + "\r\n"
                            //"p_datnss ="    + m_pGUI->lineEdit_DtNss_Assure->text()  + "\r\n"
                            "p_GUIDPat ="   + G_pCApp->identitePatientGUID()         + "\r\n"
                            "p_PKPat ="     + G_pCApp->identitePatientPk()           + "\r\n"
                            "p_NumPS ="     + numPS                                  + "\r\n"
                            "p_NomAssu ="   + m_pGUI->lineEdit_NomAssure->text()     + "\r\n"
                            "p_PreAssu ="   + m_pGUI->lineEdit_PrenomAssure->text()  + "\r\n";

      appelPyxvital ( listParam);
   #endif
}
//-------------------------------------- appelTDBCpta -------------------------------------
void C_Manager::appelCompta (QString /*nomProgCPta*/)
{
   QString  pathExe;
   QStringList argList;

   CGestIni::Param_ReadParam(G_pCApp->m_LocalParam, "Comptabilite", "pathTDB", &pathExe);
   pathExe = QDir::cleanDirPath (QFileInfo (qApp->argv()[0]).dirPath (true) + "/" + pathExe);
   // argList <<  pathExe;
   argList << G_pCApp->m_User;                             // CZ_Cpta2
   #ifdef Q_WS_WIN
       pathExe +=".exe";
    //#else
    #endif
    QProcess::startDetached (pathExe, argList);
}
//Cz_Pyxvital ------------------------------------- FIN ---------------------------------------------------------

