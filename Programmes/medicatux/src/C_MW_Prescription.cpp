#include "C_MW_Prescription.h"
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
#include <QTreeWidgetItemIterator>
#include <QTreeWidgetItem>
#include <QTreeWidget>
#include <QLineEdit>
#include <QWebSettings>
#include <QDesktopServices>
#include <QPrintDialog>
#include <QPrinter>
#include <QVariant>
#include <QDate>
#include <QWebFrame>
#include <QList>
#include <QTimer>
#include <QNetworkDiskCache>
#include <QFileInfo>
#include <QWebElementCollection>
#include <QWebElement>
#include <QProgressBar>
#include <QLabel>
#include <QMessageBox>
#include <QSignalMapper>
#include <QTextDocument>
#include <QColorDialog>
#include <QProgressDialog>
#include <QScrollBar>
#include <QHeaderView>
#include <QFontDialog>
#include <QToolBox>
#include <QProgressBar>
#include <QStyledItemDelegate>
#include <QInputDialog>
#include <QFileDialog>

#include "ui_C_MW_Prescription.h"
#include "../../MedinTuxTools-QT4/Theme/Theme.h"
#include "../../MedinTuxTools-QT4/Theme/ThemePopup.h"
#include "../../MedinTuxTools-QT4/C_Utils_Log.h"
#include "../../MedinTuxTools-QT4/C_Utils_Html.h"
#include "../../MedinTuxTools-QT4/C_Login/C_Dlg_Login.h"

#include "../../MedinTuxTools-QT4/C_DragQTreeWidget/C_DragQTreeWidget.h"
#include "../../MedinTuxTools-QT4/medicabase/C_BaseMedica.h"
#include "../../MedinTuxTools-QT4/medicabase/C_BDM_TheriaquePlugin.h"
#include "../../MedinTuxTools-QT4/medicabase/C_BDM_GenericPlugin.h"
#include "../../MedinTuxTools-QT4/medicabase/C_BDM_DatasempPlugin.h"
#include "../../MedinTuxTools-QT4/medicabase/C_Frm_Prescription.h"
#include "../../MedinTuxTools-QT4/medicabase/C_PatientCtx.h"
#include "../../MedinTuxTools-QT4/medicabase/C_UserCtx.h"
#include "../../MedinTuxTools-QT4/medicabase/C_LevelItemDelegate.h"
//#include "../../MedinTuxTools-QT4/medicabase/C_PopupDial_NotesInfos.h"
#include "../../MedinTuxTools-QT4/medicabase/C_Dlg_NotesInfos.h"
#include "../../MedinTuxTools-QT4/univers/C_DateTools.h"

#include "../../MedinTuxTools-QT4/C_PatientBase/C_PatientBase.h"
#include "CApp.h"

// #include <extensionsystem/pluginspec.h>
// typedef QList<ExtensionSystem::PluginSpec *> PluginSpecSet;


//================================ C_MW_Prescription =====================================================

//------------------------------------ C_MW_Prescription -------------------------------
C_MW_Prescription::C_MW_Prescription(QWidget *parent) :
    QMainWindow(parent),
    m_pGUI(new Ui::MainWindow)
{   //this->setAttribute(Qt::WA_DeleteOnClose);           // fait planter
    m_pGUI->setupUi(this);
    m_pC_BDM_Api               = 0;
    m_pC_PatientBase           = 0;
    m_pC_Frm_Prescription      = 0;
    m_pC_UserCtx               = 0;
    m_pC_PatientCtx            = 0;
    m_runMacroForAll           = 0;
    m_Apropos_Proc             = 0;
    m_pC_PopupDial_NotesInfos  = 0;
    m_drugListMax              = qMax(200, CApp::pCApp()->readUniqueParam( "medicatux session", "drug list limit").toInt());
    m_lastExportPath           = CApp::pCApp()->pathAppli()+"Ressources/exportList.xml";
    m_lastMonographiePath      = CApp::pCApp()->pathAppli();

    m_pGUI->checkBox_IndicationCIM10->hide();
    m_pGUI->checkBox_IndicationBDM->hide();
    m_pGUI->checkBox_SMR->hide();
    m_pGUI->checkBox_ASMR->hide();

    m_pGUI->webView_Help->hide();
    m_pGUI->label_ListMedoc->setText("");
    m_pGUI->textEdit_changeLog->hide(); // cacher le texte d'information

    m_pGUI->pushButton_CustomListMenu->setIcon( Theme::getIcon("medicatux/menu_left.png") ) ;
    m_pGUI->pushButton_CustomListMenu->setFlat(true);

    m_pGUI->toolBox_ListesProduits->setItemIcon ( "page_CustomList",  Theme::getIcon("medicatux/toolbox_custom.png") );
    m_pGUI->toolBox_ListesProduits->setItemIcon ( "page_Favoris",     Theme::getIcon("medicatux/toolbox_withposo.png") );
    m_pGUI->toolBox_ListesProduits->setItemIcon ( "page_Historique",  Theme::getIcon("medicatux/toolbox_historique.png") );
    // m_pGUI->toolBox_ListesProduits->setItemIcon ( "page_Accessoires", Theme::getIcon("medicatux/toolbox_accessoires.png") );

    //..........//////// navigateur internet ////////....................
    QWebSettings::globalSettings()->setAttribute(QWebSettings::JavascriptCanOpenWindows,TRUE);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::JavascriptCanAccessClipboard,TRUE);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::AutoLoadImages, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::OfflineStorageDatabaseEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::OfflineWebApplicationCacheEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::LocalStorageEnabled, true);

    delete m_pGUI->webView_Help;
    m_webView_Mono = new C_QWebView(m_pGUI->tab_bibliographie);
    m_webView_Mono->setObjectName(QString::fromUtf8("m_webView_Mono"));
    m_webView_Mono->setUrl(QUrl("about:blank"));
    m_webView_Mono->settings()->setLocalStoragePath ( CApp::pCApp()->pathAppli()+"/Ressources/web/" );
    m_webView_Mono->page()->setLinkDelegationPolicy ( QWebPage::DelegateAllLinks );      //QWebPage::DelegateAllLinks
    m_pGUI->gridLayout_15->addWidget(m_webView_Mono, 3, 0, 1, 2);

    delete m_pGUI->webView_HAS;
    m_webView_Info = new C_QWebView(m_pGUI->tab_Monographie);
    m_webView_Info->setObjectName(QString::fromUtf8("webView_HAS"));
    m_webView_Info->setUrl(QUrl("about:blank"));
    m_webView_Info->page()->setLinkDelegationPolicy ( QWebPage::DelegateAllLinks );      //QWebPage::DelegateAllLinks
    m_webView_Info->settings()->setAttribute( QWebSettings::JavascriptEnabled, true);
    m_webView_Info->settings()->setLocalStoragePath ( CApp::pCApp()->pathAppli()+"/Ressources/HtmlCache/" );
    m_pGUI->gridLayout_5->addWidget(m_webView_Info, 0, 0, 1, 1);
    //........... liste des plugins .............................................
    m_pGUI->comboBox_choixBase->addItems(CApp::pCApp()->getParamList("DBM_connectors","name",1));
    //..........//////// barre de menus ////////....................
    m_pGUI->pushButton_RetrySite->setIcon        ( Theme::getIcon(CApp::pCApp()->applicationName()+"/RelancerModele.png") ) ;
    m_pGUI->pushButton_UpdateCache->setIcon      ( Theme::getIcon(CApp::pCApp()->applicationName()+"/UpdateInBase.png") ) ;
    m_pGUI->pushButton_DefineLogin->setIcon      ( Theme::getIcon(CApp::pCApp()->applicationName()+"/login.png") ) ;
    m_pGUI->pushButton_AllItems->setIcon         ( Theme::getIcon(CApp::pCApp()->applicationName()+"/loop.png") ) ;
    //................. <navigateur web> ............................................
    m_pGUI->pushButton_Home->setIcon    ( Theme::getIcon("22x22/home.png") ) ;
    m_pGUI->pushButton_Print->setIcon   ( Theme::getIcon("22x22/fileprint.png") ) ;
    m_pGUI->pushButton_find->setIcon    ( Theme::getIcon("22x22/edit-find.png") ) ;
    m_pGUI->pushButton_Back->setIcon    ( m_webView_Mono->pageAction(QWebPage::Back)->icon() ) ;
    m_pGUI->pushButton_Reload->setIcon  ( m_webView_Mono->pageAction(QWebPage::Reload)->icon() ) ;
    m_pGUI->pushButton_Forward->setIcon ( m_webView_Mono->pageAction(QWebPage::Forward)->icon() ) ;
    m_pGUI->pushButton_Stop->setIcon    ( m_webView_Mono->pageAction(QWebPage::Stop)->icon() ) ;



    m_PathPageHelp = QString("../../Doc/%1/index.html").arg(CApp::pCApp()->applicationName());
    if ( QDir(m_PathPageHelp).isRelative()) {m_PathPageHelp.prepend(CApp::pCApp()->pathAppli()); m_PathPageHelp = QDir::cleanPath(m_PathPageHelp);}

    //................................. filtre de la liste des drogues ........................................
    m_pGUI->checkBox_Dci_filter->setChecked((CApp::pCApp()->readUniqueParam("medicatux filter", "dci").toUpper().startsWith('A')));  // A comme activated ou actif ou active
    m_pGUI->checkBox_Dc3_filter->setChecked((CApp::pCApp()->readUniqueParam("medicatux filter", "dc3").toUpper().startsWith('A')));  // A comme activated ou actif ou active
    m_pGUI->checkBox_Atc_filter->setChecked((CApp::pCApp()->readUniqueParam("medicatux filter", "atc").toUpper().startsWith('A')));
    m_pGUI->checkBox_Nom_filter->setChecked((CApp::pCApp()->readUniqueParam("medicatux filter", "nom").toUpper().startsWith('A')));
    m_pGUI->checkBox_Cip_filter->setChecked((CApp::pCApp()->readUniqueParam("medicatux filter", "cip").toUpper().startsWith('A')));  // cip
    m_pGUI->checkBox_Ucd_filter->setChecked((CApp::pCApp()->readUniqueParam("medicatux filter", "ucd").toUpper().startsWith('A')));  // prix
    m_pGUI->checkBox_Gen_filter->setChecked((CApp::pCApp()->readUniqueParam("medicatux filter", "gen").toUpper().startsWith('A')));  // generique
    m_pGUI->checkBox_Hop_filter->setChecked((CApp::pCApp()->readUniqueParam("medicatux filter", "hop").toUpper().startsWith('A')));  // hopital
    m_pGUI->checkBox_Vil_filter->setChecked((CApp::pCApp()->readUniqueParam("medicatux filter", "vil").toUpper().startsWith('A')));  // ville
    //.................................. mapper les signaux des checkBox de la liste des drogues .......................................
    m_DrugListFilter_SignalMapper = new QSignalMapper(this);
    connect(m_DrugListFilter_SignalMapper, SIGNAL(mapped(const QString &)),  this, SLOT(Slot_checkBox_DrugList_filter_stateChanged(const QString &)));

    connect(m_pGUI->checkBox_Dci_filter,   SIGNAL(stateChanged ( int  )),   m_DrugListFilter_SignalMapper, SLOT(map()));
    m_DrugListFilter_SignalMapper->setMapping(m_pGUI->checkBox_Dci_filter, "dci");
    connect(m_pGUI->checkBox_Dc3_filter,   SIGNAL(stateChanged ( int  )),   m_DrugListFilter_SignalMapper, SLOT(map()));
    m_DrugListFilter_SignalMapper->setMapping(m_pGUI->checkBox_Dc3_filter, "dc3");
    connect(m_pGUI->checkBox_Atc_filter,   SIGNAL(stateChanged ( int  )),   m_DrugListFilter_SignalMapper, SLOT(map()));
    m_DrugListFilter_SignalMapper->setMapping(m_pGUI->checkBox_Atc_filter, "atc");
    connect(m_pGUI->checkBox_Nom_filter,   SIGNAL(stateChanged ( int  )),   m_DrugListFilter_SignalMapper, SLOT(map()));
    m_DrugListFilter_SignalMapper->setMapping(m_pGUI->checkBox_Nom_filter, "nom");
    connect(m_pGUI->checkBox_Ucd_filter,   SIGNAL(stateChanged ( int  )),   m_DrugListFilter_SignalMapper, SLOT(map()));
    m_DrugListFilter_SignalMapper->setMapping(m_pGUI->checkBox_Ucd_filter, "ucd");
    connect(m_pGUI->checkBox_Cip_filter,   SIGNAL(stateChanged ( int  )),   m_DrugListFilter_SignalMapper, SLOT(map()));
    m_DrugListFilter_SignalMapper->setMapping(m_pGUI->checkBox_Cip_filter, "cip");
    connect(m_pGUI->checkBox_Gen_filter,   SIGNAL(stateChanged ( int  )),   m_DrugListFilter_SignalMapper, SLOT(map()));
    m_DrugListFilter_SignalMapper->setMapping(m_pGUI->checkBox_Gen_filter, "gen");
    connect(m_pGUI->checkBox_Vil_filter,   SIGNAL(stateChanged ( int  )),   m_DrugListFilter_SignalMapper, SLOT(map()));
    m_DrugListFilter_SignalMapper->setMapping(m_pGUI->checkBox_Vil_filter, "vil");
    connect(m_pGUI->checkBox_Hop_filter,   SIGNAL(stateChanged ( int  )),   m_DrugListFilter_SignalMapper, SLOT(map()));
    m_DrugListFilter_SignalMapper->setMapping(m_pGUI->checkBox_Hop_filter, "hop");

    //................................... bandeau de boutons du module de prescription ..................................................
    m_pGUI->toolButton_Help->setIcon( Theme::getIcon(CApp::pCApp()->applicationName()+"/APropos.png") ) ;
    m_pGUI->toolButton_erase_All->setIcon( Theme::getIcon(CApp::pCApp()->applicationName()+"/delete_Icon.png") ) ;
    //m_pGUI->toolButton_Help->setToolTip(tr("A propos de ce logiciel"));
    connect( m_pGUI->toolButton_Help,        SIGNAL(released ( )),                  this, SLOT(Slot_m_action_APropos ()) );
    connect( m_pGUI->toolButton_tout_Ald,    SIGNAL(clicked ( bool )),              this, SLOT(Slot_toolButton_tout_Ald_clicked ( bool )) );
    connect( m_pGUI->toolButton_non_Ald,     SIGNAL(clicked ( bool )),              this, SLOT(Slot_toolButton_non_Ald_clicked ( bool )) );
    connect( m_pGUI->toolButton_erase_All,   SIGNAL(clicked ( bool )),              this, SLOT(Slot_toolButton_erase_All_clicked ( bool )) );
    connect( m_pGUI->toolButton_Annuler,     SIGNAL(clicked ( bool )),              this, SLOT(Slot_toolButton_Annuler_clicked ( bool )) );
    connect( m_pGUI->toolButton_Ok,          SIGNAL(clicked ( bool )),              this, SLOT(Slot_toolButton_Ok_clicked ( bool )) );
    connect( m_pGUI->toolButton_Duration,    SIGNAL(clicked ( bool )),              this, SLOT(Slot_toolButton_Duration_clicked( bool )) );

    //................................... boutons de zoom du module de prescription ..................................................
    m_pGUI->toolButton_zoomUp->setIcon(Theme::getIcon("medicatux/viewmag+.png"));
    m_pGUI->toolButton_zoomDw->setIcon(Theme::getIcon("medicatux/viewmag-.png"));

    connect( m_pGUI->toolButton_zoomUp,       SIGNAL(released ( )),              this, SLOT(Slot_toolButton_zoomUpReleased (  )) );
    connect( m_pGUI->toolButton_zoomDw,       SIGNAL(released ( )),              this, SLOT(Slot_toolButton_zoomDwReleased (  )) );
    m_prescription_zoom_menu = new QMenu(this);
    m_prescription_zoom_menu->addAction(tr("1  - Mode r\303\251duit"));
    m_prescription_zoom_menu->addAction(tr("2  - Mode d\303\251ploy\303\251 "));
    m_prescription_zoom_menu->addSeparator();
    m_prescription_zoom_menu->addAction(tr("3  - Enregistrer la position courante comme mode r\303\251duit "));
    m_prescription_zoom_menu->addAction(tr("4  - Enregistrer la position courante comme mode d\303\251ploy\303\251 "));
    m_prescription_zoom_menu->addSeparator();
    m_prescription_zoom_menu->addAction(tr("5  - Choisir une couleur pour la zone non ALD"));
    m_prescription_zoom_menu->addAction(tr("6  - Choisir une couleur pour la zone ALD"));
    //m_prescription_zoom_menu->addSeparator();
    //m_prescription_zoom_menu->addAction(tr("7  - Cacher les graduations"));
    //m_prescription_zoom_menu->addAction(tr("8  - Montrer les graduations"));
    m_prescription_zoom_menu->addSeparator();
    m_prescription_zoom_menu->addAction(tr("9  - R\303\251initialiser la liste des m\303\251dicaments"));
    m_prescription_zoom_menu->addAction(tr("10 - R\303\251initialiser la liste des posologie favorites"));

    m_pGUI->toolButton_zoomDw->setMenu ( m_prescription_zoom_menu );
    m_pGUI->toolButton_zoomDw->setPopupMode ( QToolButton::MenuButtonPopup );
    connect( m_prescription_zoom_menu,   SIGNAL(triggered ( QAction* )),   this, SLOT(Slot_prescription_zoom_menu_triggered ( QAction* )) );

    //.................................. drag and drop .....................................................
    //                                   treeWidget_Produits doit etre promu en C_DragQTreeWidget avec designer
    m_pGUI->treeWidget_Produits->setMimeType("text/medintux_prd_drag");
    m_pGUI->treeWidget_Produits->setSortingEnabled(true);
    m_pGUI->treeWidget_Produits->setAlternatingRowColors ( TRUE );

    m_pGUI->treeWidget_Favoris->setMimeType("text/medintux_prd_drag");
    m_pGUI->treeWidget_Favoris->setSortingEnabled(true);
    m_pGUI->treeWidget_Favoris->setAlternatingRowColors ( TRUE );
    m_pGUI->treeWidget_Favoris->setSelectionMode(QAbstractItemView::ExtendedSelection);

    m_pGUI->treeWidget_CustomDrugsList->setMimeType("text/medintux_prd_drag");
    m_pGUI->treeWidget_CustomDrugsList->setSortingEnabled(true);
    m_pGUI->treeWidget_CustomDrugsList->setAlternatingRowColors ( TRUE );
    m_pGUI->treeWidget_CustomDrugsList->setSelectionMode(QAbstractItemView::ExtendedSelection);

    m_pGUI->treeWidget_Accessoires->setMimeType("text/medintux_prd_drag");
    m_pGUI->treeWidget_Accessoires->setSortingEnabled(true);
    m_pGUI->treeWidget_Accessoires->setAlternatingRowColors ( TRUE );

    m_pGUI->treeWidget_PatientDrugs->setMimeType("text/medintux_prd_drag");
    m_pGUI->treeWidget_PatientDrugs->setSortingEnabled(true);
    m_pGUI->treeWidget_PatientDrugs->setAlternatingRowColors ( TRUE );
    m_pGUI->pushButton_debListPatient->hide();
    m_pGUI->pushButton_finListPatient->hide();
    //m_pGUI->treeWidget_Accessoires->setSelectionMode(QAbstractItemView::ExtendedSelection);

    //QHeaderView *pQHeaderView = m_pGUI->treeWidget_Produits->header();     // cacher les colonnes du Pk et GUID
    /*
       Qt::AscendingOrder The items are sorted ascending e.g. starts with 'AAA' ends with 'ZZZ' in Latin-1 locales
       Qt::DescendingOrder
     */
    //pQHeaderView->setSortIndicator ( 0, Qt::AscendingOrder );
    // pQHeaderView->hideSection (2);
    // pQHeaderView->hideSection (3);
    // m_pGUI->treeWidget_Produits->setContextMenuPolicy ( Qt::CustomContextMenu );  //Qt::CustomContextMenu

    //.................................. autres connexions classiques .......................................
    /*
    connect( m_action_Configure,              SIGNAL(triggered ( bool )),              this, SLOT(Slot_m_action_Configure (bool)) );
    connect( m_action_ConfigureBase,          SIGNAL(triggered ( bool )),              this, SLOT(Slot_m_action_ConfigureBase (bool)) );
    connect( m_action_Deplie,                 SIGNAL(triggered ( bool )),              this, SLOT(Slot_m_action_Deplie (bool)) );
    connect( m_action_Replie,                 SIGNAL(triggered ( bool )),              this, SLOT(Slot_m_action_Replie (bool)) );
    connect( m_action_Test,                   SIGNAL(triggered ( bool )),              this, SLOT(Slot_m_action_Test (bool)) );
    connect( m_action_MakeBase,               SIGNAL(triggered ( bool )),              this, SLOT(Slot_m_action_MakeBase (bool)) );
    connect( m_action_MakeBaseGet,            SIGNAL(triggered ( bool )),              this, SLOT(Slot_m_action_MakeBaseGet (bool)) );
    connect( m_action_TestPlug,               SIGNAL(triggered ( bool )),              this, SLOT(Slot_m_action_TestPlug (bool)) );
    connect( m_action_APropos,                SIGNAL(triggered ( bool )),              this, SLOT(Slot_m_action_APropos (bool)) );
    */
    connect( m_pGUI->lineEdit_DrugsSearch,    SIGNAL(textChanged ( const QString & )),                 this, SLOT(Slot_lineEdit_DrugsSearch_textChanged (const QString &)) );
    connect( m_pGUI->lineEdit_DrugsSearch,    SIGNAL(Sign_keyPressEvent(QKeyEvent *, int &)),          this, SLOT(Slot_lineEditAutoLocator_keyPressEvent(QKeyEvent *, int &)) );


    connect( m_pGUI->treeWidget_Produits,        SIGNAL(Sign_giveMeDatas(QString &, QTreeWidgetItem* )), this, SLOT(Slot_giveDragtreeWidget_ProduitsItem_List_Data(QString &, QTreeWidgetItem*)));
    connect( m_pGUI->treeWidget_Favoris,         SIGNAL(Sign_giveMeDatas(QString &, QTreeWidgetItem* )), this, SLOT(Slot_giveDragtreeWidget_FavorisItem_List_Data(QString &, QTreeWidgetItem*)));
    connect( m_pGUI->treeWidget_CustomDrugsList, SIGNAL(Sign_giveMeDatas(QString &, QTreeWidgetItem* )), this, SLOT(Slot_giveDragtreeWidget_CustomDrugsListItem_List_Data(QString &, QTreeWidgetItem*)));
    connect( m_pGUI->treeWidget_Accessoires,     SIGNAL(Sign_giveMeDatas(QString &, QTreeWidgetItem* )), this, SLOT(Slot_giveDragtreeWidget_AccessoiresItem_List_Data(QString &, QTreeWidgetItem*)));
    connect( m_pGUI->treeWidget_PatientDrugs,    SIGNAL(Sign_giveMeDatas(QString &, QTreeWidgetItem* )), this, SLOT(Slot_giveDragtreeWidget_PatientDrugsItem_List_Data(QString &, QTreeWidgetItem*)));

    connect( m_pGUI->treeWidget_Produits,        SIGNAL(Sign_keyPressEvent(QKeyEvent *, int &, C_DragQTreeWidget*)), this, SLOT(Slot_keyPressEvent_TreeWidgetProducts(QKeyEvent *, int &, C_DragQTreeWidget*)));
    connect( m_pGUI->treeWidget_Favoris,         SIGNAL(Sign_keyPressEvent(QKeyEvent *, int &, C_DragQTreeWidget*)), this, SLOT(Slot_keyPressEvent_TreeWidgetProducts(QKeyEvent *, int &, C_DragQTreeWidget*)));
    connect( m_pGUI->treeWidget_CustomDrugsList, SIGNAL(Sign_keyPressEvent(QKeyEvent *, int &, C_DragQTreeWidget*)), this, SLOT(Slot_keyPressEvent_TreeWidgetProducts(QKeyEvent *, int &, C_DragQTreeWidget*)));
    connect( m_pGUI->treeWidget_Accessoires,     SIGNAL(Sign_keyPressEvent(QKeyEvent *, int &, C_DragQTreeWidget*)), this, SLOT(Slot_keyPressEvent_TreeWidgetProducts(QKeyEvent *, int &, C_DragQTreeWidget*)));
    connect( m_pGUI->treeWidget_PatientDrugs,    SIGNAL(Sign_keyPressEvent(QKeyEvent *, int &, C_DragQTreeWidget*)), this, SLOT(Slot_keyPressEvent_TreeWidgetProducts(QKeyEvent *, int &, C_DragQTreeWidget*)));

    connect( m_pGUI->treeWidget_PatientDrugs,     SIGNAL(itemClicked ( QTreeWidgetItem * , int  )),        this, SLOT(Slot_treeWidget_PatientDrugs_itemClicked ( QTreeWidgetItem * , int   )) );
    connect( m_pGUI->treeWidget_PatientDrugs,     SIGNAL(itemDoubleClicked ( QTreeWidgetItem * , int  )),  this, SLOT(Slot_treeWidget_PatientDrugs_itemDoubleClicked ( QTreeWidgetItem * , int   )) );
    // connect( m_pGUI->treeWidget_Produits,     SIGNAL(Sign_giveMeDatas(QString &, QTreeWidgetItem* )),  this, SLOT(Slot_giveDragtreeWidget_ProduitsItemData(QString &, QTreeWidgetItem*)));
    m_pGUI->treeWidget_PatientDrugs->setContextMenuPolicy(Qt::CustomContextMenu);
    connect( m_pGUI->treeWidget_PatientDrugs,     SIGNAL(customContextMenuRequested(QPoint)),              this, SLOT( Slot_Widget_PatientDrugs_ContextMenuRequested(QPoint)));


    connect( m_pGUI->treeWidget_Produits,     SIGNAL(itemClicked ( QTreeWidgetItem * , int  )),        this, SLOT(Slot_treeWidget_Produits_itemClicked ( QTreeWidgetItem * , int   )) );
    connect( m_pGUI->treeWidget_Produits,     SIGNAL(itemDoubleClicked ( QTreeWidgetItem * , int  )),  this, SLOT(Slot_treeWidget_Produits_itemDoubleClicked ( QTreeWidgetItem * , int   )) );
    // connect( m_pGUI->treeWidget_Produits,     SIGNAL(Sign_giveMeDatas(QString &, QTreeWidgetItem* )),  this, SLOT(Slot_giveDragtreeWidget_ProduitsItemData(QString &, QTreeWidgetItem*)));
    m_pGUI->treeWidget_Produits->setContextMenuPolicy(Qt::CustomContextMenu);
    connect( m_pGUI->treeWidget_Produits,     SIGNAL(customContextMenuRequested(QPoint)),              this, SLOT(Slot_Widget_Produits_ContextMenuRequested(QPoint)));

    connect( m_pGUI->treeWidget_Favoris,     SIGNAL(itemClicked ( QTreeWidgetItem * , int  )),        this, SLOT(Slot_treeWidget_Favoris_itemClicked ( QTreeWidgetItem * , int   )) );
    connect( m_pGUI->treeWidget_Favoris,     SIGNAL(itemDoubleClicked ( QTreeWidgetItem * , int  )),  this, SLOT(Slot_treeWidget_Favoris_itemDoubleClicked ( QTreeWidgetItem * , int   )) );
    // connect( m_pGUI->treeWidget_Favoris,     SIGNAL(Sign_giveMeDatas(QString &, QTreeWidgetItem* )),  this, SLOT(Slot_giveDragtreeWidget_FavorisItemData(QString &, QTreeWidgetItem*)));
    m_pGUI->treeWidget_Favoris->setContextMenuPolicy(Qt::CustomContextMenu);
    connect( m_pGUI->treeWidget_Favoris,     SIGNAL(customContextMenuRequested(QPoint)),              this, SLOT(Slot_Widget_treeWidget_Favoris_ContextMenuRequested(QPoint)));
    connect( m_pGUI->lineEdit_FavorisSearch,      SIGNAL(textChanged ( const QString & )),        this,   SLOT(Slot_lineEdit_lineEdit_FavorisSearch_textChanged (const QString &)) );
    connect( m_pGUI->lineEdit_FavorisSearch,      SIGNAL(Sign_keyPressEvent(QKeyEvent *, int &)), this,   SLOT(Slot_lineEdit_lineEdit_FavorisSearch_keyPressEvent(QKeyEvent *, int &)) );

    connect( m_pGUI->treeWidget_CustomDrugsList,     SIGNAL(itemClicked ( QTreeWidgetItem * , int  )),        this, SLOT(Slot_treeWidget_CustomDrugsList_itemClicked ( QTreeWidgetItem * , int   )) );
    connect( m_pGUI->treeWidget_CustomDrugsList,     SIGNAL(itemDoubleClicked ( QTreeWidgetItem * , int  )),  this, SLOT(Slot_treeWidget_CustomDrugsList_itemDoubleClicked ( QTreeWidgetItem * , int   )) );
    // connect( m_pGUI->treeWidget_CustomDrugsList,     SIGNAL(Sign_giveMeDatas(QString &, QTreeWidgetItem* )),  this, SLOT(Slot_giveDragtreeWidget_CustomDrugsListItemData(QString &, QTreeWidgetItem*)));
    m_pGUI->treeWidget_CustomDrugsList->setContextMenuPolicy(Qt::CustomContextMenu);
    connect( m_pGUI->treeWidget_CustomDrugsList,     SIGNAL(customContextMenuRequested(QPoint)),              this, SLOT(Slot_Widget_treeWidget_CustomDrugsList_ContextMenuRequested(QPoint)));

    connect( m_pGUI->treeWidget_Accessoires,          SIGNAL(itemClicked ( QTreeWidgetItem * , int  )),        this, SLOT(Slot_treeWidget_Accessoires_itemClicked ( QTreeWidgetItem * , int   )) );
    connect( m_pGUI->treeWidget_Accessoires,          SIGNAL(itemDoubleClicked ( QTreeWidgetItem * , int  )),  this, SLOT(Slot_treeWidget_Accessoires_itemDoubleClicked ( QTreeWidgetItem * , int   )) );
    // connect( m_pGUI->treeWidget_Accessoires,          SIGNAL(Sign_giveMeDatas(QString &, QTreeWidgetItem* )),  this, SLOT(Slot_giveDragtreeWidget_AccessoiresItemData(QString &, QTreeWidgetItem*)));
    m_pGUI->treeWidget_Accessoires->setContextMenuPolicy(Qt::CustomContextMenu);
    connect( m_pGUI->treeWidget_Accessoires,          SIGNAL(customContextMenuRequested(QPoint)),              this, SLOT(Slot_treeWidget_Accessoires_ContextMenuRequested(QPoint)));

    connect( m_pGUI->treeWidget_Indications, SIGNAL(itemClicked ( QTreeWidgetItem * , int  )),        this, SLOT(Slot_treeWidget_Indications_itemClicked ( QTreeWidgetItem * , int   )) );
    connect( m_pGUI->treeWidget_Composition, SIGNAL(itemClicked ( QTreeWidgetItem * , int  )),        this, SLOT(Slot_treeWidget_Composition_itemClicked ( QTreeWidgetItem * , int   )) );

    connect( m_pGUI->treeWidget_ATC,          SIGNAL(itemClicked ( QTreeWidgetItem * , int  )),        this, SLOT(Slot_treeWidget_ATC_itemClicked ( QTreeWidgetItem * , int   )) );
    //......................................... WEB VIEW ....................................................................
    connect( m_pGUI->lineEdit_url,            SIGNAL(returnPressed()),                      this, SLOT(Slot_LocationEdit_returnPressed()));
    connect( m_pGUI->lineEdit_find,           SIGNAL(returnPressed()),                      this, SLOT(Slot_WebFindEdit_returnPressed()));
    connect( m_pGUI->lineEdit_find,           SIGNAL(textChanged ( const QString &  ) ),    this, SLOT(Slot_WebFindEdit_textChanged (const QString & )) );

    connect( m_webView_Mono,            SIGNAL(urlChanged (  const QUrl &  )),     this,  SLOT(Slot_webView_urlChanged ( const QUrl &  )));
    connect( m_webView_Mono,            SIGNAL(loadStarted (  )),       this,             SLOT(Slot_On_webView_Help_loadStarted ()) );
    connect( m_webView_Mono,            SIGNAL(loadProgress (int)),     this,             SLOT(Slot_On_webView_Help_loadProgress (int)) );
    connect( m_webView_Mono,            SIGNAL(loadFinished (bool  )),  this,             SLOT(Slot_On_webView_Help_loadFinished (bool)) );
    connect( m_webView_Mono,            SIGNAL(statusBarMessage(const QString &)), this,  SLOT(Slot_On_webView_Help_statusBarMessage (const QString &)) );
    connect( m_webView_Mono,            SIGNAL(linkClicked ( const QUrl &  )),     this,  SLOT(Slot_webView_Mono_linkClicked ( const QUrl &  )));  // marche po

    // connect( m_webView_Info,                  SIGNAL(urlChanged (  const QUrl &  )),        this, SLOT(Slot_webView_Info_urlChanged ( const QUrl &  )));
    connect( m_webView_Info,                  SIGNAL(linkClicked ( const QUrl &  )),        this, SLOT(Slot_webView_Info_linkClicked ( const QUrl &  )));  // marche po

    connect( m_pGUI->pushButton_Home,         SIGNAL(clicked ( bool )),                   this, SLOT(Slot_actionWebHome  (bool)) );
    connect( m_pGUI->pushButton_Print,        SIGNAL(clicked ( bool )),                   this, SLOT(Slot_actionWebPrint (bool)) );
    connect( m_pGUI->pushButton_find,         SIGNAL(clicked ( bool )),                   this, SLOT(Slot_actionWebFind  (bool)) );

    connect( m_pGUI->pushButton_Back,         SIGNAL(clicked ( bool )),                   m_webView_Mono, SLOT(back ()) );
    connect( m_pGUI->pushButton_Reload,       SIGNAL(clicked ( bool )),                   m_webView_Mono, SLOT(reload ()) );
    connect( m_pGUI->pushButton_Forward,      SIGNAL(clicked ( bool )),                   m_webView_Mono, SLOT(forward ()) );
    connect( m_pGUI->pushButton_Stop,         SIGNAL(clicked ( bool )),                   m_webView_Mono, SLOT(stop ()) );

    connect( m_pGUI->pushButton_DefineLogin,  SIGNAL(clicked ( bool )),                  this,   SLOT(Slot_pushButton_DefineLogin (bool)) );
    connect( m_pGUI->pushButton_RetrySite,    SIGNAL(clicked ( bool )),                  this,   SLOT(Slot_On_pushButton_RetrySite(bool)) );
    connect( m_pGUI->pushButton_UpdateCache,  SIGNAL(clicked ( bool )),                  this,   SLOT(Slot_On_UpdateCache(bool)) );
    connect( m_pGUI->pushButton_AllItems,     SIGNAL(clicked ( bool )),                  this,   SLOT(Slot_On_pushButton_AllItems(bool)) );
    //....................................... combo du choix plugin ...........................................................................
    connect( m_pGUI->comboBox_choixBase,      SIGNAL(activated ( const QString & )),     this,   SLOT(Slot_On_comboBox_choixBase(const QString &)) );
    connect( m_pGUI->pushButton_PosoEditorFontChoice,     SIGNAL(clicked ( bool )),      this,   SLOT(Slot_On_pushButton_PosoEditorFontChoice(bool)) );
    connect( m_pGUI->pushButton_GeneralFontChoice,        SIGNAL(clicked ( bool )),      this,   SLOT(Slot_On_pushButton_GeneralFontChoice(bool)) );

    connect( m_pGUI->pushButton_CustomListMenu,       SIGNAL(clicked ( bool )),                       this,   SLOT(Slot_pushButton_pushButton_CustomListMenu(bool)) );
    connect( m_pGUI->comboBox_customList,             SIGNAL(activated ( const QString &)) ,          this,   SLOT(Slot_comboBox_customList_activated( const QString &)) );
    connect( m_pGUI->lineEdit_CustomSearch,           SIGNAL(textChanged ( const QString & )),        this,   SLOT(Slot_lineEdit_CustomSearch_textChanged (const QString &)) );
    connect( m_pGUI->lineEdit_CustomSearch,           SIGNAL(Sign_keyPressEvent(QKeyEvent *, int &)), this,   SLOT(Slot_lineEdit_CustomSearch_keyPressEvent(QKeyEvent *, int &)) );

    connect( m_pGUI->lineEdit_AccessoiresSearch,      SIGNAL(textChanged ( const QString & )),        this,   SLOT(Slot_lineEdit_AccessoiresSearch_textChanged (const QString &)) );
    connect( m_pGUI->lineEdit_AccessoiresSearch,      SIGNAL(Sign_keyPressEvent(QKeyEvent *, int &)), this,   SLOT(Slot_lineEdit_AccessoiresSearch_keyPressEvent(QKeyEvent *, int &)) );
    connect( m_pGUI->comboBox_FamillesProduits,       SIGNAL(activated (int )) ,                      this,   SLOT(Slot_comboBox_FamillesProduits_activated( int )) );

    //............................... le systeme de gestion des onglets ...........................................................
    m_Button_TabCorner     = new CMyColorButton(QApplication::palette ( this ).color(this->backgroundRole()), Theme::getIcon("medicatux/tabSet.png"), QRect(QRect(0,0,16,16)));
    connect( m_Button_TabCorner,                      SIGNAL(clicked ( bool )),                       this,   SLOT(Slot_m_Button_TabCorner_clicked(bool)) );
    m_pGUI->tabWidget_HAS_Infos->setCornerWidget ( m_Button_TabCorner);
    connect( m_pGUI->tabWidget_HAS_Infos,             SIGNAL(currentChanged (int )) ,                 this,   SLOT(Slot_tabWidget_Main_currentChanged( int )) );

    //............................... le systeme des listes de classification ...........................................................
    connect( m_pGUI->toolBox_classifications,         SIGNAL(currentChanged ( int )),                 this,   SLOT(Slot_toolBox_classifications_currentChanged(int)) );
    connect( m_pGUI->toolBox_ListesProduits,          SIGNAL(currentChanged ( int )),                 this,   SLOT(Slot_toolBox_ListesProduits_currentChanged(int)) );


    init_comboBox_BiblioURL();

    // CGestIni::parseAPI_oracle( CApp::pCApp()->pathAppli()+"oracle.sql", CApp::pCApp()->pathAppli()+"Mysql.sql",CApp::pCApp()->pathAppli()+"OCI_Template.h");
    //.................. completer statusBar avec progress et label ......................
    m_pQProgressBar  = new QProgressBar(this);
    m_pQLabel        = new QLabel(this);
    m_pQProgressBar->setMaximumWidth(150);
    statusBar()->addWidget(m_pQProgressBar);
    statusBar()->addWidget(m_pQLabel);
    statusBar()->hide();
    //............ cosmetique de monitoring a la base de donnee................
    //CApp::pCApp()->BDM_getDB()->setLogWidget(m_pGUI->textEdit_Monitor);
    //CApp::pCApp()->BDM_getDB()->setProgressWidget(m_pQProgressBar);
    //CApp::pCApp()->BDM_getDB()->setStatusWidget(m_pQLabel);
    //............ cosmetique de signalisation ................
    m_pQLabel->setText("");

    //.............. on cree le controleur de l'API medicamenteuse et on le branche sur le plugin de base de donnee .................
    m_pC_BDM_Api = new C_BDM_Api( CGestIni::Param_UpdateFromDisk(CApp::pCApp()->pathAppli()+"C_BDM_Api.cfg"),
                                  "MAIN_",
                                  CApp::pCApp()->iniParam(),
                                  CApp::pCApp()->pathTheme() + CApp::pCApp()->applicationName()+"/",
                                  CApp::pCApp()->pathAppli(),
                                  CApp::pCApp()->pathIni(),
                                  this);
    m_pC_BDM_Api->setLogWidget(m_pGUI->textEdit_Monitor);
    m_pC_BDM_Api->setProgressWidget(m_pQProgressBar);
    m_pC_BDM_Api->setStatusWidget(m_pQLabel);

    m_pGUI->treeWidget_ATC->header()->setResizeMode (0, QHeaderView::Interactive ); // QHeaderView::Stretch  QHeaderView::Interactive QHeaderView::ResizeToContents
    m_pGUI->treeWidget_ATC->header()->resizeSection (0, 400 );

    QString namePlugin = CApp::pCApp()->readUniqueParam("medicatux data source", "name");
    /*
    m_pC_PatientBase = new C_PatientBase(CGestIni::Param_UpdateFromDisk(CApp::pCApp()->pathAppli()+"C_PatientBase.cfg"),  // le fichier de config des noms de champ et tables
                                         CApp::pCApp()->iniParam(),                                                       // le contenu du .ini
                                         CApp::pCApp()->pathIni(),                                                        // le chemin de ce .ini
                                         this);                                                                           // l'objet pere et le saint esprit
    */
    // if (m_pC_PatientBase)
    //............................ recuperer et creer le contexte patient ................................
    m_pC_PatientCtx = new C_PatientCtx(CGestIni::Param_UpdateFromDisk(CApp::pCApp()->patientCtxFileName()), //"CApp::pCApp()->pathAppli()+/Ressources/ComFiles/30DC82DD-7632-2C46-9DC3-BC1AC0ECD20A-C_PatientCtx.xml"),  // le fichier des donnees
                                       CGestIni::Param_UpdateFromDisk(CApp::pCApp()->pathAppli()+"/Ressources/ComFiles/casalta.NABM"),                                           // le contenu du fichier de conversion labo
                                       CApp::pCApp()->pathAppli()+"/Ressources/ComFiles/casalta.NABM");                                                                          // le non du fichier de conversion labo
    //............................ recuperer et creer le contexte utilisateur (prescripteur) ................................
    m_pC_UserCtx    = new C_UserCtx(   CGestIni::Param_UpdateFromDisk( CApp::pCApp()->userCtxFileName())); //CApp::pCApp()->pathAppli() +"Ressources/ComFiles/UserCtx.xml") ); //CApp::pCApp()->userCtxFileName()));

    // ........................... passer a l'API le contexte patient et utilisateur........................................
    if (m_pC_BDM_Api)
       { m_pC_BDM_Api->setPatientContexte(m_pC_PatientCtx);
         m_pC_BDM_Api->setUserContexte(m_pC_UserCtx);
       }
    set_BDM_Plugin(namePlugin);
    //............................ creer la feuille d'elaboration des ordonnances ................................
    QFont fnt = setFontFromIniFile();
    add_C_Frm_Prescription( fnt, getInputGrammarList() );  // a faire absolument apres initialisation m_pC_BDM_PluginI et  m_pC_BDM_Api
    display_HAS_Status();      // a faire apres initialisation de m_pC_Frm_Prescription (faite dans add_C_Frm_Prescription)
    //............ titre interface et liste ........................
    setWindowTitle();       // le faire apres le contexte patient

    //................ placer le gestionnaire de cookie jar .............................
    m_pCookieJar = new CookieJar(CApp::pCApp()->pathAppli()+"/Ressources/cookies.txt", this, m_pGUI->textEdit_Monitor);
    m_webView_Mono->page()->networkAccessManager()->setCookieJar(m_pCookieJar);
    // m_webView_Info->page()->networkAccessManager()->setCookieJar(m_pCookieJar);
    //................ positionner les elements complementaires pour le gestionnaire de macro .............................
    //                 dont derive CApp
    CApp::pCApp()->setQNetworkAccessManager(m_webView_Mono->page()->networkAccessManager()); // positionne m_pC_Utils_Html
    CApp::pCApp()->setQProgressBar(m_pQProgressBar);        // positionne m_pC_Utils_Html
    CApp::pCApp()->setLogWidget(m_pGUI->textEdit_Monitor);  // positionne C_Macro_Core::setLogWidget()   dont est derivee C_Macro dont est co-derivee CApp
    CApp::pCApp()->setQWebView(m_webView_Mono);
    m_pGUI->lineEdit_DrugsSearch->setFocus();
    fillCustomDrugListCombo("BDM");

    setPositionsFromIniFile();
    //setWindowFlags(Qt::WindowStaysOnTopHint);
    //............ ne surtout pas changer les sequences ....................
    //             suivantes (seules a mettre les fenetres en avant plan sur Mac)
    setWindowState(windowState() & ~Qt::WindowMinimized);
    show();
    activateWindow();
    raise();
}
//--------------------------------- getInputGrammarList -----------------------------------------------------------------------
QStringList C_MW_Prescription::getInputGrammarList()
{ QStringList grammarList;
  QString grammarInputData = CGestIni::Param_UpdateFromDisk( CApp::pCApp()->grammarFileName() );
  if (grammarInputData.length()==0) return grammarList;
  grammarList = CGestIni::getXmlDataList("OrdoLine", grammarInputData);
  return grammarList;
}
//--------------------------------- Slot_toolButton_tout_Ald_clicked -----------------------------------------------------------------------
void C_MW_Prescription::Slot_toolButton_tout_Ald_clicked ( bool )
{
 if (m_pC_Frm_Prescription==0) return;
     m_pC_Frm_Prescription->set_Ald_On_All_Products("ALD");
}
//--------------------------------- Slot_toolButton_non_Ald_clicked -----------------------------------------------------------------------
void C_MW_Prescription::Slot_toolButton_non_Ald_clicked ( bool )
{if (m_pC_Frm_Prescription==0) return;
    m_pC_Frm_Prescription->set_Ald_On_All_Products("");

}
//--------------------------------- Slot_toolButton_erase_All_clicked -----------------------------------------------------------------------
void C_MW_Prescription::Slot_toolButton_erase_All_clicked ( bool )
{   if (m_pC_Frm_Prescription==0) return;
    m_pC_Frm_Prescription->delete_All_Products();
}
//--------------------------------- Slot_toolButton_Annuler_clicked -----------------------------------------------------------------------
void C_MW_Prescription::Slot_toolButton_Annuler_clicked ( bool )
{   close();
}
//--------------------------------- Slot_toolButton_Ok_clicked -----------------------------------------------------------------------
void C_MW_Prescription::Slot_toolButton_Ok_clicked ( bool )
{    //........... enregistrer les ordo ..................
    QString mask         = CGestIni::Param_UpdateFromDisk(CApp::pCApp()->pathAppli()+"/Ressources/OrdoMask/OrdoMask.xml");
    ordoToHtml(mask);
    close();
}
//--------------------------------- Slot_toolButton_Duration_clicked -----------------------------------------------------------------------
void C_MW_Prescription::Slot_toolButton_Duration_clicked( bool )
{   if (m_pC_Frm_Prescription==0) return;
    QMenu       *pQMenu       = new QMenu(this);  pQMenu->setFont(this->font());
    QString      options_text = CGestIni::Param_UpdateFromDisk( CApp::pCApp()->pathAppli()+"/Ressources/DurationPopup.txt" ).remove('\r');
    QStringList  options_list = options_text.split('\n', QString::SkipEmptyParts);
    if ( options_list.size()==0 ) return;
    for (int i=0; i< options_list.size(); ++i)
        { ThemePopup::addOptionMenu( pQMenu, options_list.at(i) );
        }
    QAction *QAction = pQMenu->exec(this->cursor().pos());
    if (QAction)
       { m_pC_Frm_Prescription->set_Duration_On_All_Products( QAction->data().toString() );
       }
}

//--------------------------------- Slot_toolBox_ListesProduits_currentChanged -----------------------------------------------------------------------
void C_MW_Prescription::Slot_toolBox_ListesProduits_currentChanged(int index)
{ QWidget *pQWidget          = m_pGUI->toolBox_ListesProduits->widget ( index );
  fill_only_showed_treeWidgets( pQWidget->objectName() );
}
//------------------------ fill_only_showed_treeWidgets ---------------------------------------
void C_MW_Prescription::fill_only_showed_treeWidgets(const QString &objName)
{//......... remplissage des listes ......................
    if (objName=="page_Produits")
       { initDrugListFilter();
         if (m_pGUI->treeWidget_Produits->topLevelItemCount()==0)             Slot_lineEdit_DrugsSearch_textChanged ("");
         m_pGUI->lineEdit_DrugsSearch->setFocus();
       }
    else if (objName=="page_CustomList")
       {  if ( m_pGUI->treeWidget_CustomDrugsList->topLevelItemCount()==0 )   fillCustomDrugListCombo("BDM");
          m_pGUI->lineEdit_CustomSearch->setFocus();
       }
    else if (objName=="page_Accessoires")
       { if ( m_pGUI->treeWidget_Accessoires->topLevelItemCount()==0 )        Datasemp_fill_treeWidget_Accessoires(m_pGUI->treeWidget_Accessoires, m_pGUI->comboBox_FamillesProduits->currentIndex()+2);
         m_pGUI->lineEdit_AccessoiresSearch->setFocus();
       }
    else if (objName=="page_Favoris")
       { if ( m_pGUI->treeWidget_Favoris->topLevelItemCount()==0)             fill_treeWidget_Favoris();
         m_pGUI->lineEdit_FavorisSearch->setFocus();
       }
    else if (objName=="page_Historique")
       { if ( m_pGUI->treeWidget_PatientDrugs->topLevelItemCount()==0)        fill_treeWidget_Historique();
         m_pGUI->lineEdit_HistoriqueSearch->setFocus();
       }
}
//--------------------------------- fill_treeWidget_Historique -----------------------------------------------------------------------
void C_MW_Prescription::fill_treeWidget_Historique()
{ if (m_pC_PatientCtx == 0)   return;
  //if (m_pC_BDM_Api    == 0 )  return;
  QList < C_BDM_DrugListRecord >  drugsList;
  for (int i=0; i< m_pC_PatientCtx->prescriptionsList().size(); ++i)
      { QString grammar = m_pC_PatientCtx->prescriptionsList().at(i);
        int nextPos              = 0;
        QString status           = CGestIni::getXmlData(     "status",    grammar, &nextPos);
        QString id               = CGestIni::getXmlData(     "gph_id",    grammar, &nextPos);
        QString id_type          = CGestIni::getXmlData(     "gph_it",    grammar, &nextPos);
        //QString pk               = CGestIni::getXmlData(     "gph_pk",    grammar, &nextPos);
        //QString    s_dateRed     = CGestIni::getXmlData(     "gph_dr",    grammar, &nextPos).left(10);
        //QString    s_dateDeb     = CGestIni::getXmlData(     "gph_dt",    grammar, &nextPos).left(10);
        QString commercialName   = CGestIni::getXmlData(     "gph_na",    grammar, &nextPos);
        QString compoXmlParts    = CGestIni::getXmlData(     "gph_dcl",   grammar, &nextPos);
        QStringList dciList      = CGestIni::getXmlDataList( "gph_dc",    compoXmlParts);
        dciList <<"";
        dciList <<"";
        dciList <<"";
        drugsList.append( C_BDM_DrugListRecord( id,
                                                id_type,
                                                commercialName,
                                                CGestIni::getXmlData( "gph_dcn", dciList[0]),
                                                CGestIni::getXmlData( "gph_dcn", dciList[1]),
                                                CGestIni::getXmlData( "gph_dcn", dciList[2]),
                                                status.contains('F') ? "CTX_F" : "CTX_I",
                                                "fr",
                                                "ucd",
                                                "ucd_price",
                                                "",         //sera rempli a la volee lors d'un clic  m_pC_BDM_Api->ATC_from_CIP(id),
                                                "",
                                                "VH"
                                              )
                        );
      }
  fill_treeWidget_ProductsFromDrugList(m_pGUI->treeWidget_PatientDrugs, drugsList);
}

//--------------------------------- Slot_toolBox_classifications_currentChanged -----------------------------------------------------------------------
void C_MW_Prescription::Slot_toolBox_classifications_currentChanged(int index)
{ QWidget *pQWidget  = m_pGUI->toolBox_classifications->widget ( index );
  QString  name      = pQWidget->objectName();
  QString id         = "";
  QTreeWidget  *pQTreeWidget = currrentProductListTreeWidget();
  if ( pQTreeWidget     == 0 ) return;
  QTreeWidgetItem *pQTreeWidgetItem = pQTreeWidget->currentItem();
  if ( name == "page_ATC" )
     { if ( pQTreeWidgetItem == 0 ) return;
       setListATC_onCode (pQTreeWidgetItem->text( COL_ATC ) );
     }
  else if ( name == "page_Indications" )
     { if ( pQTreeWidgetItem ) id  = pQTreeWidgetItem->text( COL_ID );
       fillTreeWidgetIndications( id );
     }
  else if ( name == "page_Composition" )
     { if ( pQTreeWidgetItem ) id  = pQTreeWidgetItem->text( COL_ID );
       fillTreeWidgetComposition( id );
     }
}

//--------------------------------- Slot_m_Button_TabCorner_clicked -----------------------------------------------------------------------
void C_MW_Prescription::Slot_m_Button_TabCorner_clicked(bool)
{   m_pGUI->tabWidget_HAS_Infos->doPageChoiceMenu( this );
}

//--------------------------------- currrentProductListTreeWidget -----------------------------------------------------------------------
QTreeWidget  *C_MW_Prescription::currrentProductListTreeWidget()
{   QWidget      *pQWidget     = m_pGUI->toolBox_ListesProduits->currentWidget();
    if      (pQWidget->objectName()=="page_Produits")    return m_pGUI->treeWidget_Produits;
    else if (pQWidget->objectName()=="page_CustomList")  return m_pGUI->treeWidget_CustomDrugsList;
    else if (pQWidget->objectName()=="page_Accessoires") return m_pGUI->treeWidget_Accessoires;
    else if (pQWidget->objectName()=="page_Favoris")     return m_pGUI->treeWidget_Favoris;
    else if (pQWidget->objectName()=="page_Historique")  return m_pGUI->treeWidget_PatientDrugs;
    return 0;
}
//--------------------------------- ordoToHtml -----------------------------------------------------------------------
QString C_MW_Prescription::ordoToHtml( const QString &mask /* = "" */ )
{   QString html      = "";
    QString  xml      = "";
    if (mask.length())
       {int nextPos  = 0;
        QString deb          = CGestIni::getXmlData( "start_doc",       mask, &nextPos);
        QString is_ald_txt   = CGestIni::getXmlData( "is_ald_part",     mask, &nextPos);
        QString no_ald_txt   = CGestIni::getXmlData( "no_ald_part",     mask, &nextPos);
        QString lineMask     = CGestIni::getXmlData( "product_line",    mask, &nextPos);
        QString end          = CGestIni::getXmlData( "end_doc",         mask, &nextPos);
        QString html         = deb;
        int mentionIsALD     = 0;
        int mentionNonALD    = 0;
        int i                = 0;
        QStringList grammar_list = m_pC_Frm_Prescription->grammarList();
        for ( i=0; i<grammar_list.size(); ++i )
            {  QString grammar = grammar_list.at(i);
               if ( C_PosologieGrammar::ald( grammar ).length())
                  { if (mentionIsALD == 0)                  html += is_ald_txt;
                    ++mentionIsALD;
                  }
               else
                  { if (mentionIsALD && mentionNonALD==0 )  html += no_ald_txt;
                    ++mentionNonALD;
                  }
               xml  += "<OrdoLine>\n"+grammar+"</OrdoLine>\n\n";
               html += C_PosologieGrammar::fuse  ( grammar               ,
                                                   lineMask              ,
                                                   m_pC_Frm_Prescription->imagePath("NonSubstituable.png"),
                                                   QString::number(i+1)
                                                 );
            } //end for ( i=0; i<grammar_list.size(); ++i )
        html  += end;
        //........... mentions versions LAP et source de donnees ...........
        html   = html.replace("{{DATA_SRC}}",    m_pC_BDM_Api->dataSourceVersion());
        html   = html.replace("{{LAP_VERSION}}", tr("%1 %2 %3").arg(CApp::pCApp()->ApplicationVersion(),__DATE__,__TIME__));
        QString guid = "noPatient";
        if (m_pC_PatientCtx && m_pC_PatientCtx->get_guid().length()) guid = m_pC_PatientCtx->get_guid();
        CGestIni::Param_UpdateToDisk( QString ( CApp::pCApp()->pathAppli()+"/Ressources/ComFiles/Ordo_%1_.html" ).arg(guid), html);
        CGestIni::Param_UpdateToDisk( QString ( CApp::pCApp()->pathAppli()+"/Ressources/ComFiles/Ordo_%1_.xml"  ).arg(guid),  xml);
        return html;
       }

    QString     css  =   CGestIni::Param_UpdateFromDisk ( CApp::pCApp()->pathAppli()+"/Ressources/Ordonnance.css" );
    if (css.length()==0)
        { css   =
                       "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">"
                       "<html>"
                       "<head>"
                       "    <meta name=\"qrichtext\" content=\"1\" />"
                       "    <style type=\"text/css\">"
                       "        span.mainName {"
                       "         color:#000000;"                                    // 1 color dci
                       "         font-family: arial, verdana, sans-serif;"
                       "         text-decoration: underline;"
                       "         font-size: 10px;"
                       "         font-weight: bold;"
                       "        }"
                       "        span.optionalName {"
                       "          color:#000000;"                                   // 2 color commercial name
                       "          font-family: arial, verdana, sans-serif;"
                       "          font-style: italic;"
                       "          font-size: 10px;"
                       "        }"
                       "        span.texteNormal {"
                       "          color:#000000;"                                   // 3 color text normal
                       "          font-family: arial, verdana, sans-serif;"
                       "          font-size: 10px;"
                       "        }"
                       "        span.numOrdre {"
                       "          color:#000000;"                                   // 4 color num Ordre
                       "          font-family: arial, verdana, sans-serif;"
                       "          font-size: 10px;"
                       "          font-weight: bold;"
                       "        }"

                       "        span.drugForme {"
                       "          color:#000000;"                                   // 5 color forme
                       "          font-family: arial, verdana, sans-serif;"
                       "          font-size: 10px;"
                       "          font-weight: bold;"
                       "        }"
                       "    </style>"
                       "</head>";
        }  // endif (css.length()==0)
    //.................. une methode (on recupere toute la liste )............................
    int mentionIsALD  = 0;
    int mentionNonALD = 0;
    int i             = 0;
    QStringList grammar_list = m_pC_Frm_Prescription->grammarList("ALL");
    for ( i=0; i<grammar_list.size(); ++i )
        {  QString grammar = grammar_list.at(i);
           if ( C_PosologieGrammar::ald( grammar ).length())
              { if (mentionIsALD == 0)                  html += CGestIni::Param_UpdateFromDisk(CApp::pCApp()->pathAppli()+"/Ressources/MentionsALD/AvecALD.html");
                ++mentionIsALD;
              }
           else
              { if (mentionIsALD && mentionNonALD==0 )  html += CGestIni::Param_UpdateFromDisk(CApp::pCApp()->pathAppli()+"/Ressources/MentionsALD/SansALD.html");
                ++mentionNonALD;
              }
           xml  += "<OrdoLine>\n"+grammar+"</OrdoLine>\n\n";
           html += C_PosologieGrammar::toHtml(  grammar,
                                                m_pC_Frm_Prescription->imagePath("NonSubstituable.png"),
                                                css ,               // css par defaut
                                                QColor(Qt::black),
                                                QString::number(i+1)
                                             );
        } //end for ( i=0; i<grammar_list.size(); ++i )
    QString guid = "noPatient";
    if (m_pC_PatientCtx && m_pC_PatientCtx->get_guid().length()) guid = m_pC_PatientCtx->get_guid();
    CGestIni::Param_UpdateToDisk( QString ( CApp::pCApp()->pathAppli()+"/Ressources/ComFiles/Ordo_%1.html" ).arg(guid), html);
    CGestIni::Param_UpdateToDisk( QString ( CApp::pCApp()->pathAppli()+"/Ressources/ComFiles/Ordo_%1.xml"  ).arg(guid),  xml);
    return html;
}

//--------------------------------- Slot_tabWidget_Main_currentChanged -----------------------------------------------------------------------
void C_MW_Prescription::Slot_tabWidget_Main_currentChanged( int index)
{   if (m_pC_Frm_Prescription==0) return;
    if (index ==-1)               return;

    QWidget *pTab_QWidget =  m_pGUI->tabWidget_HAS_Infos->widget(index);
    if (pTab_QWidget->objectName()=="tab_Ident")
       {  //......... renseigner l'interface avec le contexte d'entree (patient et user prescripteur) ..................
          patientCtxToInterface(m_pC_PatientCtx);
          userCtxToInterface(m_pC_UserCtx);
       }
    else if (pTab_QWidget->objectName()=="tab_Monographie")
       {  QTreeWidgetItem *pQTreeWidgetItem = currrentProductListTreeWidget()->currentItem();  //getSelectedListViewItem( currrentProductListTreeWidget() );
          if (pQTreeWidgetItem==0) return;
          treeWidget_Produits_itemClicked ( pQTreeWidgetItem, 0  );
       }
    else if (pTab_QWidget->objectName()=="tab_ordonnance")
       {  QString mask         = CGestIni::Param_UpdateFromDisk(CApp::pCApp()->pathAppli()+"/Ressources/OrdoMask/OrdoMask.xml");
          m_pGUI->textEdit_ordonnance->setText(ordoToHtml(mask));
       }
}

//--------------------------------- prescriptionToXML ----------------------------------------------------------------------------
QString  C_MW_Prescription::prescriptionToXML(C_Frm_Prescription *m_pC_Frm_Prescription)
{   Q_UNUSED (m_pC_Frm_Prescription);
    return "";
}

//--------------------------------- Slot_webView_Mono_linkClicked -----------------------------------------------------------------------
void C_MW_Prescription::Slot_webView_Mono_linkClicked ( const QUrl & url )
{ if (URL_ExecSpecialSyntax ( url.toString().trimmed() ,CApp::pCApp()->pathAppli())) return;
  m_webView_Mono->load (url );
}
//--------------------------------- getCustomMonographiePropertys -----------------------------------------------------------------------
int  C_MW_Prescription::getCustomMonographiePropertys ( QString &title , QString &author, QDateTime &date_time, QString &text)
{ /*
  if (m_pC_PopupDial_NotesInfos==0)
     { //QPoint        pos = mapFromGlobal (QCursor::pos());
       QPoint        pos (m_webView_Mono->x(),m_webView_Mono->y());
       QRect initialRect = QRect(pos.x(),pos.y(),1,1);    // m_Button_Indic->x()+m_Button_Indic->width()
       QRect deployRect  = QRect(pos.x(),pos.y(),100,200);
       QColor color      = QApplication::palette ( this ).color(this->backgroundRole());
       m_pC_PopupDial_NotesInfos = new    C_PopupDial_NotesInfos(this, title, author, date_time, color ,initialRect, deployRect);
       connect( m_pC_PopupDial_NotesInfos,       SIGNAL(Sign_finished(const QString &)) ,   this,   SLOT(Slot_PopupDial_NotesInfos_finished( const QString & )) );
       m_pC_PopupDial_NotesInfos->show();
     }
  m_pC_PopupDial_NotesInfos->setToDeployRect ();
  */
    C_Dlg_NotesInfos *p_dlg = new C_Dlg_NotesInfos(this,title,author,date_time, text);
    if (p_dlg && p_dlg->exec()==1)
       { title     = p_dlg->title();
         author    = p_dlg->author();
         date_time = p_dlg->date_time();
         text      = p_dlg->texte(); qDebug()<<text;
         delete p_dlg;
         return 1;
       }
    delete p_dlg;
    return 0;
}
/*
//--------------------------------- Slot_PopupDial_NotesInfos_finished -----------------------------------------------------------------------
void  C_MW_Prescription::Slot_PopupDial_NotesInfos_finished( const QString &direction )
{if (direction=="TO_INITIAL")
    { m_pC_PopupDial_NotesInfos->deleteLater();
      m_pC_PopupDial_NotesInfos = 0;
    }
}
*/
//--------------------------------- URL_ExecSpecialSyntax -----------------------------------------------------------------------
int  C_MW_Prescription::URL_ExecSpecialSyntax ( QString urlStr , const QString &pathAppli)
{   // qDebug()<<urlStr;
    if (urlStr.startsWith("exec:"))    // modify:#ancre_id_[1-index]_   remove:#ancre_id_[1-index]_
       {urlStr = urlStr.mid(5);
        QStringList argList = urlStr.split("||");
        urlStr = argList[0]; if (!argList.isEmpty()) argList.removeAt(0);
        if ( QDir(urlStr).isRelative()) urlStr.prepend(pathAppli);
        urlStr = QDir::cleanPath(urlStr) + F_EXE;
#ifdef Q_WS_MAC
        QString module = urlStr;
        int     posDeb = module.lastIndexOf("/");
        if (posDeb != -1)
           { ++posDeb;
             module = module.mid(posDeb);
           }
        urlStr += ".app/Contents/MacOS/" + module;
#endif
        QProcess::startDetached(urlStr, argList);
        return 1;
       }
    else if (urlStr.startsWith("remove:#ancre"))
       { QString  pk =  CGestIni::CutStrRight( urlStr, "remove:#ancre_id_[");
                  pk =  CGestIni::CutStrLeft(pk, "-");
         if (pk.length()==0) return 1;
         int ret          = QMessageBox::warning( this, tr("Delete a note"),
                                                  "Delete a note",
                                                  QMessageBox::Cancel
                                                | QMessageBox::Apply,
                                                  QMessageBox::Cancel);
         if (ret==QMessageBox::Apply)
            {m_pC_BDM_Api->delete_CustomMonographie(pk);
             show_ProductMonographie(m_last_drugListRecord);
            }
       }
    else if (urlStr.startsWith("modify:#ancre"))
       { QString  pk =  CGestIni::CutStrRight( urlStr, "modify:#ancre_id_[");
                  pk =  CGestIni::CutStrLeft(pk, "-");
         if (pk.length()==0) return 1;
         QByteArray datas;
         QString   libelle;
         QString   author;
         QDateTime date_time;
         QString   texte  =  m_pC_BDM_Api->get_CustomMonographie( pk, libelle,  author,  date_time);
         if ( getCustomMonographiePropertys ( libelle , author, date_time, texte) )
            { datas = texte.toLatin1();
              if (datas.isEmpty())
                 { QMessageBox msgBox;
                    msgBox.setText(tr ("Nothing in Note Editor."));
                    msgBox.exec();
                    return 1;
                 }
              m_pC_BDM_Api->update_CustomMonographie(pk, libelle, author, date_time, datas);
              show_ProductMonographie(m_last_drugListRecord);
            }
       }
    else if (urlStr.startsWith("new:#ancre"))
       { QString title       = "Titre de la note";
         QString author      = "Anonyme";
         QDateTime date_time = QDateTime::currentDateTime();
         QString   texte     = "Entrez ici le texte de la note....";
         if (m_pC_UserCtx)
            {author = m_pC_UserCtx->get_usual_name() + ";"+m_pC_UserCtx->get_forename();
            }
         QByteArray datas;
         if (getCustomMonographiePropertys ( title , author, date_time, texte))
            { datas = texte.toLatin1();
              if (datas.isEmpty())
                 { QMessageBox msgBox;
                    msgBox.setText(tr ("Nothing in Note Editor."));
                    msgBox.exec();
                    return 1;
                 }
              m_pC_BDM_Api->add_Monographie_to_CustomMonographie( title, author, datas, date_time, m_last_drugListRecord);
              show_ProductMonographie(m_last_drugListRecord);
            }
       }
    else if (urlStr.startsWith("mailto:"))
       {urlStr      = urlStr.mid(7);
        int posArg  = urlStr.indexOf("?");                 //"mailto:%1?subject=%2&body=%3" la liste d'arguments commence apr?s '?' et sont separes par '&'
        if (posArg != -1)
           {++posArg;
            QString   argMailTo = urlStr.mid(posArg);
            QStringList argList = argMailTo.split("&");
            QString       token = "";
            QString       value = "";
            int           nbArg = argList.count();
            int               i = 0;
            urlStr              = urlStr.left(posArg);
            while( i<nbArg)
                {int posEgal  = argList[i].indexOf("=");
                 token        = "";
                 value        = "";
                 if (posEgal != -1)
                    {++posEgal;
                     token = argList[i].left(posEgal);
                     value = argList[i].mid(posEgal);
                    }
                 if (value.startsWith("file:")||value.startsWith("$File"))
                    {value = value.mid(5);
                     if ( QDir(value).isRelative()) value.prepend(pathAppli);
                     value = QDir::cleanPath(value);
                     value = CGestIni::Param_UpdateFromDisk(value);
                    }
                 urlStr += token+value;
                 ++i;
                 if (i<nbArg) urlStr += "&";
                }
            }
        QDesktopServices::openUrl (urlStr.prepend("mailto:") );
        return 1;
       }
    return 0;
}

//--------------------------------------- Datasemp_fill_treeWidget_Accessoires -------------------------------------------------------
/*
# define COL_PROD_NAME    0
# define COL_DCI_1        1
# define COL_DCI_2        2
# define COL_DCI_3        3
# define COL_PRIX         4
# define COL_ATC          5
# define COL_ID           6
# define COL_CIS          7
# define COL_ORG          8
# define COL_ID_TYP       9
# define COL_SPEC_KEY     10
# define COL_GENERIQUE    11
# define COL_STATUT       12
 */
int C_MW_Prescription::Datasemp_fill_treeWidget_Accessoires(QTreeWidget *pQTreeWidget, int familleIndex, const QString &text  /* = "" */)
{pQTreeWidget->clear();
 if (m_pC_BDM_Api==0)                           return 0;
 if (m_pC_BDM_Api->plugin_name() != "Datasemp") return 0;
 QTreeWidgetItem *item;
 QString familleSemp = "";
 if (familleIndex==7) familleSemp = "1X";           // homeopathie
 else                 familleSemp = QString::number(familleIndex);
 //................. Preparer la requete ............................................................................
 //                                                                     homeopathie 1X  --> f1 pointe sur t0g.f0 pour boiron et t0h.f0 pour weleda
 //                                                     fk = 1 = Sp\303\251cialit\303\251s ; 2 = Di\303\251t\303\251tiques ; 3 = V\303\251t\303\251rinaires ; 4 = Parapharmacie ; 5 = Accessoires ; 6 = Divers (herboristerie, etc.) ; 7 = Hom\303\251opathie
 //                                                     0   1   2   3   4   5
 QString              requete  =               " SELECT fK, ge, f0, fG, f2, f1 FROM t00 WHERE fk like '" + familleSemp + "%' ";
 //                                     Famille SEMP____^   ^   ^   ^   ^   ^
 //                                     PrimaryKey _________|   |   |   |   |
 //                                     Code produit____________|   |   |   |
 //                                     Libelle Medicament _________|   |   |
 //                                     code CIP _______________________|   |
 //                                     code_UV ____________________________|
 if (text.length())  requete  +=                " AND (f3 like '%" + text + "%' OR f3 like '%"+ text.toUpper() + "%')";
                     requete  +=                " limit 0,300";

 QSqlQuery query(m_pC_BDM_Api->get_database());
 if ( ! query.exec(requete) )
    { // m_pC_BDM_Api->outSQL_error( *pQSqlQuery, QObject::tr("ERREUR : C_MW_Prescription::Datasemp_fill_treeWidget_Accessoires() can't execute requete"), requete, __FILE__, __LINE__);
      return 0;
    }
 QIcon datasempIcone  = Theme::getIcon("medicatux/toolbox_accessoires.png");
 if (query.isActive() )
    {while (query.next())
           {QString id      = query.value(4).toString();                      // m_BDM_POSO_HIT_PK
            QString id_type = "cip";                  // cip
            if (id.length()==0)
               {id      = query.value(2).toString();
                id_type = "DS_NPRD";                  // numero de produit
               }
            item =   new QTreeWidgetItem (pQTreeWidget);
            if (item)  //  paranoiac attitude
            {    item->setText( COL_PROD_NAME, CGestIni::Utf8_Query(query, 3) );   // libelle
                 item->setText( COL_DCI_1     , "");               // DCI_1
                 item->setText( COL_DCI_2     , "");               // DCI_2
                 item->setText( COL_DCI_3     , "");               // DCI_3
                 item->setText( COL_PRIX      , "");               // Prix
                 item->setText( COL_ATC       , "");               // ATC
                 item->setText( COL_ID        , id);               // ID CIP
                 item->setText( COL_ORG       , "DS_A");           // PROVENANCE DS_A pour D ata S emp et A Accessoires
                 item->setText( COL_ID_TYP    , id_type);          // ID Type
                 item->setText( COL_GENERIQUE , "");               // generique   G R ou S
                 item->setText( COL_STATUT    , "VH");             // statut  Ville Hopital VH ou H
                 item->setIcon( COL_PROD_NAME , datasempIcone);
              } // end if (item)  //  paranoiac attitude
           }    // end while (query.next())
    }  // endif (query.isActive() )
 return 1;
}

//--------------------------------------- Slot_pushButton_exportCustomList -------------------------------------------------------
void C_MW_Prescription::Slot_pushButton_exportCustomList(bool)
{ exportDrugsList(m_pGUI->treeWidget_CustomDrugsList, 1);
}
//--------------------------------------- Slot_pushButton_importCustomList -------------------------------------------------------
void C_MW_Prescription::Slot_pushButton_importCustomList(bool)
{ importDrugsList(m_pGUI->treeWidget_CustomDrugsList, 0);
}
//--------------------------------------- importDrugsList -------------------------------------------------------
int C_MW_Prescription::importDrugsList(QTreeWidget *pQTreeWidget, bool clearList /* = 0*/)
{
  QString fileName = QFileDialog::getOpenFileName(this, tr("Export products list"),
                                                     m_lastExportPath,
                                                     tr("Xml files (*.XML *.xml)"));
  if (fileName.length()==0)   return 0;
  m_lastExportPath         = fileName;

  QString          dataXML = CGestIni::Param_UpdateFromDisk( fileName );
  QStringList drugsXmlList = CGestIni::getXmlDataList("C_BDM_DrugListRecord", dataXML);
  QString         userName = "BDM";
  QString         listName = m_pGUI->comboBox_customList->currentText();

  int                   nb = drugsXmlList.size();
  int                    i = 0;
  QList < C_BDM_DrugListRecord > drugsList;
  for ( i = 0; i < nb; ++i)
      { drugsList.append( C_BDM_DrugListRecord::unSerialize(drugsXmlList[i]) );
      }
  if  (drugsList.size())
      { if (clearList) pQTreeWidget->clear();
        add_Product_to_CustomProductsList(userName, listName, drugsList);
      }
  return nb;
}

//--------------------------------------- exportDrugsList -------------------------------------------------------
void C_MW_Prescription::exportDrugsList(QTreeWidget *pQTreeWidget, bool selectMode /* = 0*/)
{
 QString fileName = QFileDialog::getSaveFileName(this, tr("Import products list"),
                                                   m_lastExportPath,
                                                   tr("Xml files (*.XML *.xml)"));
 if (fileName.length()==0) return ;
 m_lastExportPath = fileName;

 QString dataXML = "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>\n"
                    "<!-- Projet    : MedinTux                              -->\n"
                    "<!-- Module    : medicabase                            -->\n"
                    "<!-- Objet     : C_BDM_DrugListRecordArray             -->\n"
                    "<!-- guru mail : sevin-roland@medintux.org             -->\n"
                    "<!-- Copyright : (C) 2004-to-2013 and for the eternity -->\n";
  dataXML +=        "<C_BDM_DrugListRecordArray>\n"
                    "   <version>1</version>\n";
  QList < C_BDM_DrugListRecord > drugsList = makeDrugsListRecords_From_QTreeWidgetProducts(pQTreeWidget,  selectMode);
  for (int i=0; i<drugsList.size(); ++i)
      {dataXML += drugsList[i].serialize(0,"   ");    // serialisation sans le header
      }
  dataXML +=        "</C_BDM_DrugListRecordArray>\n";

  CGestIni::CGestIni::Param_UpdateToDisk(fileName,dataXML.toLatin1());
}

//--------------------------------- Slot_lineEdit_lineEdit_FavorisSearch_textChanged -----------------------------------------------------------------------
void  C_MW_Prescription::Slot_lineEdit_lineEdit_FavorisSearch_textChanged (const QString &text)
{  fill_treeWidget_Favoris(text);
}
//--------------------------------- Slot_lineEdit_lineEdit_FavorisSearch_keyPressEvent -----------------------------------------------------------------------
void  C_MW_Prescription::Slot_lineEdit_lineEdit_FavorisSearch_keyPressEvent(QKeyEvent *event, int &callStandardEvent)
{ lineEdit_searchProducts_keyPressEvent(m_pGUI->treeWidget_Favoris, event, callStandardEvent);
}

//--------------------------------------- Slot_comboBox_FamillesProduits_activated -------------------------------------------------------
void C_MW_Prescription::Slot_comboBox_FamillesProduits_activated( int familleIndex)
 {Datasemp_fill_treeWidget_Accessoires(m_pGUI->treeWidget_Accessoires, familleIndex+2);
 }
//--------------------------------------- Slot_lineEdit_AccessoiresSearch_textChanged -------------------------------------------------------
void C_MW_Prescription::Slot_lineEdit_AccessoiresSearch_textChanged (const QString &text)
{Datasemp_fill_treeWidget_Accessoires(m_pGUI->treeWidget_Accessoires, m_pGUI->comboBox_FamillesProduits->currentIndex()+2, text);
}
//--------------------------------------- Slot_treeWidget_CustomDrugsList_itemClicked -------------------------------------------------------
void C_MW_Prescription::Slot_lineEdit_AccessoiresSearch_keyPressEvent(QKeyEvent *event, int &callStandardEvent)
{lineEdit_searchProducts_keyPressEvent(m_pGUI->treeWidget_Accessoires, event, callStandardEvent);
}

//--------------------------------------- Slot_lineEdit_CustomSearch_textChanged -------------------------------------------------------
void C_MW_Prescription::Slot_lineEdit_CustomSearch_textChanged (const QString &text)
{   if (m_pC_BDM_Api==0) return;
    QString         userName = "BDM";
    QString         listName = m_pGUI->comboBox_customList->currentText();

    QList < C_BDM_DrugListRecord > drugsList = m_pC_BDM_Api->selectCustomProductsList( userName,  listName, text, (C_BDM_PluginI::flags)  ( (int)C_BDM_PluginI::nom_filter
                                                                                                                                           |(int)C_BDM_PluginI::atc_filter
                                                                                                                                           |(int)C_BDM_PluginI::dci_filter
                                                                                                                                           |(int)C_BDM_PluginI::cip_filter
                                                                                                                                           |(int)C_BDM_PluginI::dc3_filter
                                                                                                                                          )
                                                                                     );

    m_pGUI->treeWidget_CustomDrugsList->clear();
    fill_treeWidget_ProductsFromDrugList(m_pGUI->treeWidget_CustomDrugsList, drugsList);
}

//--------------------------------------- Slot_lineEdit_CustomSearch_keyPressEvent -------------------------------------------------------
void C_MW_Prescription::Slot_lineEdit_CustomSearch_keyPressEvent(QKeyEvent *event, int &callStandardEvent)
{ lineEdit_searchProducts_keyPressEvent(m_pGUI->treeWidget_CustomDrugsList, event, callStandardEvent);
  // if ( ! m_pGUI->lineEdit_CustomSearch->hasFocus() )  m_pGUI->lineEdit_CustomSearch->setFocus();
}

//--------------------------------------- lineEdit_searchProducts_keyPressEvent -------------------------------------------------------
void C_MW_Prescription::lineEdit_searchProducts_keyPressEvent(QTreeWidget *pQTreeWidget, QKeyEvent *event, int &callStandardEvent)
{   QTreeWidgetItem * pQTreeWidgetItem = 0;
    switch(event->key())
      {case Qt::Key_Return:
       case Qt::Key_Enter:
             pQTreeWidgetItem = getSelectedListViewItem( pQTreeWidget );
             if (pQTreeWidgetItem==0 && pQTreeWidget->topLevelItemCount()==1 )
                {pQTreeWidgetItem = pQTreeWidget->topLevelItem(COL_PROD_NAME);
                 if (pQTreeWidgetItem) pQTreeWidgetItem->setSelected(TRUE);
                }
             Slot_add_product_In_C_Frm_Prescription(pQTreeWidgetItem);
             callStandardEvent = 0;
             break;
       case Qt::Key_Down:
            {pQTreeWidgetItem = getSelectedListViewItem(pQTreeWidget);
             if (pQTreeWidgetItem)
                {QTreeWidgetItem * pQTreeWidgetItemBelow = pQTreeWidget->itemBelow( pQTreeWidgetItem );
                 if (pQTreeWidgetItemBelow)
                    {pQTreeWidgetItem->setSelected(FALSE);
                     pQTreeWidgetItemBelow->setSelected(TRUE);
                     pQTreeWidget->scrollToItem (pQTreeWidgetItemBelow);
                    }
                }
             else if (pQTreeWidget->topLevelItemCount ())
                {pQTreeWidgetItem = pQTreeWidget->topLevelItem(COL_PROD_NAME);
                 if (pQTreeWidgetItem) pQTreeWidgetItem->setSelected(TRUE);
                }
             callStandardEvent = 0;
            }
            break;
       case Qt::Key_Up:
            {pQTreeWidgetItem = getSelectedListViewItem(pQTreeWidget);
             if (pQTreeWidgetItem)
                {QTreeWidgetItem * pQTreeWidgetItemAbove = pQTreeWidget->itemAbove( pQTreeWidgetItem );
                 if (pQTreeWidgetItemAbove)
                    {pQTreeWidgetItem->setSelected(FALSE);
                     pQTreeWidgetItemAbove->setSelected(TRUE);
                     pQTreeWidget->scrollToItem (pQTreeWidgetItemAbove);
                    }
                }
             else if (pQTreeWidget->topLevelItemCount ())
                {pQTreeWidgetItem = pQTreeWidget->topLevelItem(COL_PROD_NAME);
                 if (pQTreeWidgetItem) pQTreeWidgetItem->setSelected(TRUE);
                }
             callStandardEvent = 0;
            }
            break;
      }
}

//--------------------------------------- Slot_Widget_Produits_ContextMenuRequested -------------------------------------------------------
void C_MW_Prescription::Slot_Widget_Produits_ContextMenuRequested(QPoint )
{drugsList_ContextMenuRequested(  m_pGUI->treeWidget_Produits);
}
//--------------------------------------- Slot_Widget_treeWidget_Favoris_ContextMenuRequested -------------------------------------------------------
void C_MW_Prescription::Slot_Widget_treeWidget_Favoris_ContextMenuRequested(QPoint )
{drugsList_ContextMenuRequested(  m_pGUI->treeWidget_Favoris);
}
//--------------------------------------- Slot_Widget_treeWidget_CustomDrugsList_ContextMenuRequested -------------------------------------------------------
void C_MW_Prescription::Slot_Widget_treeWidget_CustomDrugsList_ContextMenuRequested(QPoint )
{drugsList_ContextMenuRequested(  m_pGUI->treeWidget_CustomDrugsList);
}
//--------------------------------------- Slot_treeWidget_Accessoires_ContextMenuRequested -------------------------------------------------------
void C_MW_Prescription::Slot_treeWidget_Accessoires_ContextMenuRequested(QPoint)
{drugsList_ContextMenuRequested(  m_pGUI->treeWidget_Accessoires);
}
//--------------------------------------- Slot_treeWidget_PatientDrugs_ContextMenuRequested -------------------------------------------------------
void C_MW_Prescription::Slot_treeWidget_PatientDrugs_ContextMenuRequested(QPoint)
{drugsList_ContextMenuRequested(  m_pGUI->treeWidget_Accessoires);
}
//--------------------------------------- Slot_pushButton_pushButton_CustomListMenu -------------------------------------------------------
void C_MW_Prescription::Slot_pushButton_pushButton_CustomListMenu(bool)
{ m_pGUI->pushButton_CustomListMenu->setIcon( Theme::getIcon("medicatux/menu_down.png") ) ;
  drugsList_ContextMenuRequested( m_pGUI->treeWidget_CustomDrugsList);
  m_pGUI->pushButton_CustomListMenu->setIcon( Theme::getIcon("medicatux/menu_left.png") ) ;
}

//--------------------------------------- drugsList_ContextMenuRequested -------------------------------------------------------
void C_MW_Prescription::drugsList_ContextMenuRequested(QTreeWidget *pQTreeWidget)
{   QWidget *pQWIdget                  = m_pGUI->toolBox_ListesProduits->currentWidget();
    QString  pageName                  = pQWIdget->objectName();
    QTreeWidgetItem * pQTreeWidgetItem = pQTreeWidget->currentItem();
    QString userName                   = "BDM";
    QString listName                   = m_pGUI->comboBox_customList->currentText();
    int                              i = 0;
    QStringList optionList;
    optionList     << tr("$ContextMenuProducts");             // titre

    if (pQTreeWidgetItem)
       { optionList     << "=1=#medicatux/add_to_prescription.png#"   + tr("Add this product to current prescription");
         optionList     << "=3=#medicatux/monographie.png#"           + tr("show monographie for this product");
         optionList     << "-----------";
         if (pageName == "page_CustomList")
            { optionList << "=4=#medicatux/objectDel.png#"            + tr("Remove selected items from custom drugs list '%1'.").arg(listName);
            }
         if (m_pGUI->comboBox_customList->count())
            { optionList << ">customDrugsList<"+tr("#medicatux/sequenceadd.png#Add this item to custom drugs list");   // menu d'appel du sous menu
              for (int id=0; id<m_pGUI->comboBox_customList->count();++id)                                             // options du sous menu
                  { QString item = m_pGUI->comboBox_customList->itemText(id);  // nom de la custom drugs list
                    optionList << "<customDrugsList>=_"+item+"="+ item;        // l'identification de l'option (entre deux signes =) est : _ suivi du nom de la liste
                  }
            }
       }
    if (pageName == "page_CustomList")
       { optionList << "-----------";
         optionList << "=5=#medicatux/edit.png#"                      + tr("create new free item for custom drugs list '%1'.").arg(listName);
         if (pQTreeWidget->selectedItems().size())
             optionList << "=6=#medicatux/export_list.png#"           + tr("Export selected items from  '%1'.").arg(listName);
         optionList << "=7=#medicatux/import_list.png#"               + tr("Import items for '%1'.").arg(listName);
         optionList << "-----------";
         optionList << "=8=#medicatux/create_list.png#"               + tr("Create a new custom drugs list.");
         optionList << "=9=#medicatux/remove_list.png#"               + tr("Remove custom drugs list '%1'.").arg(listName);

       }
    if (optionList.size()==0) return;

    optionList     << "-----------";
    optionList     << "=0=#medicatux/QuitterMenu.png#"         + tr("Quit this menu.");
    //........................ si commence par _ alors une liste custom ..............................
    //                         a ete cliquee
    QString option = ThemePopup(optionList,this, " border: 1px solid #8f8f91; border-radius: 6px; font-size: 11px;").DoPopupList();
    if (option.startsWith('_') && pQTreeWidgetItem)
       { QList < C_BDM_DrugListRecord > drugsList =  makeDrugsListRecords_From_QTreeWidgetProducts(pQTreeWidget, 1);
         add_Product_to_CustomProductsList(userName, option.mid(1), drugsList);
         return;
       }
    switch(option.toInt())
    {  case 1:             //...... Add this product to current prescription ......
            { QList<QTreeWidgetItem *> itemsList = pQTreeWidget->selectedItems();
              for ( i=0; i<itemsList.size(); ++i )
                  {treeWidget_Produits_itemDoubleClicked ( itemsList.at(i) , 0  );
                  }
            } break;
       case 3:             //...... show monographie for this product ......
            { show_ProductMonographie(C_BDM_DrugListRecord_From_QTreeWidgetProductsItem (pQTreeWidgetItem));
            } break;
       case 4:             //...... Remove this item from this list ......
            {
             QList < C_BDM_DrugListRecord > drugsList = makeDrugsListRecords_From_QTreeWidgetProducts(pQTreeWidget, 1);    // 1 car on veut tous ceux selectionnes
             QString                          message = "";
             int                                   nb = drugsList.size();
             if (nb > 1)
                {if (nb>10)
                    { message = tr("Remove all the %1 selecteds products.<br />"
                                   "from <font color=#0000ff><b>'%2'</b></font> drugs list .Do you want this?").arg(QString::number(nb), listName);
                    }
                 else
                    { QString productsStr = "<font size=7pts color=#ff0000><b>";
                      for ( i=0; i<nb; ++i )
                          { productsStr += "<br />&nbsp;&nbsp;&nbsp;&nbsp;'" + drugsList.at(i).commercialName() + "'";
                          }
                      productsStr += "<br /></b></font>";
                      message = tr("Remove all the following %1 selected products.<br />"
                                   "from <font color=#0000ff><b>'%2'</b></font> drugs list .Do you want this?").arg(productsStr, listName);
                    }
                }
             else
                {message = tr("This product <font color=#ff0000><b>'%1'</b></font> must be deleted.<br />"
                               "from <font color=#0000ff><b>'%2'</b></font> drugs list .Do you want this?").arg(pQTreeWidgetItem->text(COL_PROD_NAME), listName);
                }
             int ret          = QMessageBox::warning( this, tr("Delete a product"),
                                                      message,
                                                      QMessageBox::Cancel
                                                    | QMessageBox::Apply,
                                                      QMessageBox::Cancel);
             if (ret==QMessageBox::Apply)
                { for (i=0; i<nb; ++i)
                      { m_pC_BDM_Api->del_Product_from_CustomProductsList(userName, listName, drugsList.at(i));
                      }
                  changeCurrentCustomList(userName, listName);     // on recharge la liste
                } // endif (ret==QMessageBox::Apply)
            } break;
       case 5:             //...... create new item for this list ......
            {  bool ok;
               QString drugName = QInputDialog::getText(this, tr("give your custom drugname"),
                                                        tr("Give your new custom drug name:"), QLineEdit::Normal,
                                                        "", &ok);
               if (ok && !drugName.isEmpty())
                 { QString id      = m_pC_BDM_Api->GUID_Create();
                   QString id_type = "FRT";
                   /*    C_BDM_DrugListRecord(QString id,
                         QString id_type,
                         QString commercialName,
                         QString dci_1Name,
                         QString dc2_1Name,
                         QString dc3_1Name,
                         QString owner,
                         QString lang,
                         QString ucd,
                         QString ucd_price,
                         QString atc,
                         QString generique,
                         QString statut
                        )
                    */
                   C_BDM_DrugListRecord c_bdm_druglistrecord(id,id_type, drugName,"","","","OW","fr","","","","","VH");
                   QList < C_BDM_DrugListRecord > drugsList;
                   drugsList.append(c_bdm_druglistrecord);
                   add_Product_to_CustomProductsList(userName, listName, drugsList );
                 }
            } break;
       case 6:             //...... Export selected items for this list ......
            { Slot_pushButton_exportCustomList(true);
            } break;
       case 7:             //...... Import items for this list ......
            { Slot_pushButton_importCustomList(true);
            } break;
       case 8:             //...... Create a new list ......
            {  Slot_pushButton_addCustomList(true);
            } break;
       case 9:             //...... Remove this list ......
            { Slot_pushButton_delCustomList(true);
            } break;
    }
}

//--------------------------------------- add_Product_to_CustomProductsList -------------------------------------------------------
int  C_MW_Prescription::add_Product_to_CustomProductsList(const QString &userName, const QString &listName, QList < C_BDM_DrugListRecord > &drugsList)
{//............ activer eventuellement la liste ..........................
 if (m_pGUI->comboBox_customList->currentText() != listName) Slot_comboBox_customList_activated(listName);
 //............ ajouter la liste de drogue en base ........................
 if ( m_pC_BDM_Api->add_Product_to_CustomProductsList(userName, listName, drugsList) )
    { //.......... ajouter les nouveaux a la treewidget ......................
      QList < QTreeWidgetItem* >  itemsList;
      if (  fill_treeWidget_ProductsFromDrugList(m_pGUI->treeWidget_CustomDrugsList, drugsList, &itemsList))
         {
            m_pGUI->toolBox_ListesProduits->setCurrentItem (  "page_CustomList");
            //............. selectionner les nouveaux arrivants ....................
            for (int i = 0; i < itemsList.size(); ++i)
                { QTreeWidgetItem *item = itemsList.at(i);
                  item->setSelected(true);
                  // m_pGUI->treeWidget_CustomDrugsList->setCurrentItem(item);
                }
            return itemsList.size();
         }
    }
 return 0;
}
//--------------------------------------- Slot_keyPressEvent_TreeWidgetProducts -------------------------------------------------------
void C_MW_Prescription::Slot_keyPressEvent_TreeWidgetProducts(QKeyEvent *event, int &callStandardEvent, C_DragQTreeWidget* pQTreeWidget)
{   QTreeWidgetItem * pQTreeWidgetItem = 0;
    switch(event->key())
      {case Qt::Key_Return:
       case Qt::Key_Enter:
             pQTreeWidgetItem = getSelectedListViewItem( pQTreeWidget );
             if (pQTreeWidgetItem==0 && pQTreeWidget->topLevelItemCount()==1 )
                {pQTreeWidgetItem = pQTreeWidget->topLevelItem(COL_PROD_NAME);
                 if (pQTreeWidgetItem) pQTreeWidgetItem->setSelected(TRUE);
                }
             Slot_add_product_In_C_Frm_Prescription(pQTreeWidgetItem);
             callStandardEvent = 0;
             break;
      }  // end switch(event->key())
}

//--------------------------------------- Slot_treeWidget_Produits_itemClicked -------------------------------------------------------
void C_MW_Prescription::Slot_treeWidget_Produits_itemClicked ( QTreeWidgetItem *pQTreeWidgetItem , int c  )
{treeWidget_Produits_itemClicked (  pQTreeWidgetItem, c);
}
//--------------------------------------- Slot_treeWidget_Favoris_itemClicked --------------------------------------------------
void C_MW_Prescription::Slot_treeWidget_Favoris_itemClicked       ( QTreeWidgetItem *pQTreeWidgetItem , int c  )
{treeWidget_Produits_itemClicked (  pQTreeWidgetItem, c);
}
//--------------------------------------- Slot_treeWidget_CustomDrugsList_itemClicked -------------------------------------------------------
void C_MW_Prescription::Slot_treeWidget_CustomDrugsList_itemClicked ( QTreeWidgetItem *pQTreeWidgetItem , int c  )
{treeWidget_Produits_itemClicked (  pQTreeWidgetItem, c);
}
//--------------------------------------- Slot_treeWidget_Accessoires_itemClicked -------------------------------------------------------
void C_MW_Prescription::Slot_treeWidget_Accessoires_itemClicked ( QTreeWidgetItem *pQTreeWidgetItem , int c   )
{treeWidget_Produits_itemClicked (  pQTreeWidgetItem, c);
}
//--------------------------------------- Slot_treeWidget_PatientDrugs_itemClicked -------------------------------------------------------
void C_MW_Prescription::Slot_treeWidget_PatientDrugs_itemClicked ( QTreeWidgetItem *pQTreeWidgetItem , int c   )
{treeWidget_Produits_itemClicked (  pQTreeWidgetItem, c);
}

//--------------------------------------- setListATC_onCode -------------------------------
void C_MW_Prescription::setListATC_onCode ( const QString &atc )
{
    QString toFind                 = "";
    //...................... se positionner sur le code ATC .......................
    QTreeWidgetItemIterator it(m_pGUI->treeWidget_ATC);
    while (*it)
      { QTreeWidgetItem *pQTreeWidgetItem = (*it);
        toFind=pQTreeWidgetItem->text(1);
        if (toFind==atc)
           { m_pGUI->treeWidget_ATC->scrollToItem(pQTreeWidgetItem, QAbstractItemView::PositionAtCenter);   // QAbstractItemView::EnsureVisible
             pQTreeWidgetItem->setSelected(true);
             pQTreeWidgetItem->setExpanded(true);
           }
        else
           { pQTreeWidgetItem->setSelected(false);
             pQTreeWidgetItem->setExpanded(false);
           }
        ++it;
      }
    //............ replacer la scroll bar ATC a gauche ............................
    //             (car se centre au milieu apres selection item)
    m_pGUI->treeWidget_ATC->horizontalScrollBar()->setSliderPosition(0);
}

//--------------------------------------- treeWidget_Produits_itemClicked -------------------------------
void C_MW_Prescription::treeWidget_Produits_itemClicked ( QTreeWidgetItem * pQTreeWidgetItem, int /* c */  )
{   if (pQTreeWidgetItem==0)       return;

    QString cip       = pQTreeWidgetItem->text(COL_ID);
    QWidget *pQWIdget = m_pGUI->tabWidget_HAS_Infos->currentWidget();
    QString tabName   = pQWIdget ? pQWIdget->objectName() : "";
    m_pGUI->label_ListMedoc->setText(cip);
    if (tabName      == "tab_bibliographie" )
       { getBiblioForItemEnCours(0, pQTreeWidgetItem);    //0 car  ne pas forcer (si deja en base recupere celui en base)
       }
    else if (tabName == "tab_Monographie" )
       { show_ProductMonographie(C_BDM_DrugListRecord_From_QTreeWidgetProductsItem (pQTreeWidgetItem));
       }

    pQWIdget = m_pGUI->toolBox_classifications->currentWidget();
    if (pQWIdget == m_pGUI->toolBox_classifications->toolWidgetByTabObjectName("page_Indications"))
       {  fillTreeWidgetIndications( cip );
       }
    else if (pQWIdget == m_pGUI->toolBox_classifications->toolWidgetByTabObjectName( "page_Composition"))
       {  fillTreeWidgetComposition(cip);
       }
    else if (pQWIdget == m_pGUI->toolBox_classifications->toolWidgetByTabObjectName( "page_ATC"))
       { QString atc =  pQTreeWidgetItem->text(COL_ATC);
         if (atc.length()==0 && cip.length() && m_pC_BDM_Api) atc = m_pC_BDM_Api->ATC_from_CIP(cip);
         setListATC_onCode ( atc);
       }
}

//------------------------------------ Slot_treeWidget_Produits_itemDoubleClicked --------------------------------------------------
 void C_MW_Prescription::Slot_treeWidget_Produits_itemDoubleClicked ( QTreeWidgetItem *pQTreeWidgetItem , int c )
 {   treeWidget_Produits_itemDoubleClicked (pQTreeWidgetItem , c  );
 }
//------------------------------------ Slot_treeWidget_CustomDrugsList_itemDoubleClicked -------------------------------------------------------
void C_MW_Prescription::Slot_treeWidget_CustomDrugsList_itemDoubleClicked ( QTreeWidgetItem *pQTreeWidgetItem , int c  )
{   treeWidget_Produits_itemDoubleClicked (pQTreeWidgetItem , c  );
}
//------------------------------------ Slot_treeWidget_Favoris_itemDoubleClicked --------------------------------------------------
 void C_MW_Prescription::Slot_treeWidget_Favoris_itemDoubleClicked ( QTreeWidgetItem *pQTreeWidgetItem , int  c )
 {   treeWidget_Produits_itemDoubleClicked (pQTreeWidgetItem , c  );
 }
//--------------------------------------- Slot_treeWidget_Accessoires_itemDoubleClicked -------------------------------------------------------
void C_MW_Prescription::Slot_treeWidget_Accessoires_itemDoubleClicked ( QTreeWidgetItem *pQTreeWidgetItem , int c  )
{    treeWidget_Produits_itemDoubleClicked (pQTreeWidgetItem , c  );
}
//--------------------------------------- Slot_treeWidget_PatientDrugs_itemDoubleClicked -------------------------------------------------------
void C_MW_Prescription::Slot_treeWidget_PatientDrugs_itemDoubleClicked ( QTreeWidgetItem *pQTreeWidgetItem , int c  )
{    treeWidget_Produits_itemDoubleClicked (pQTreeWidgetItem , c  );
}
//------------------------------------ treeWidget_Produits_itemDoubleClicked --------------------------------------------------
void C_MW_Prescription::treeWidget_Produits_itemDoubleClicked ( QTreeWidgetItem *pQTreeWidgetItem , int  )
{   if (pQTreeWidgetItem==0) return;
    QWidget                 *pTab_QWidget =  m_pGUI->tabWidget_HAS_Infos->tabWidgetByTabObjectName(  "tab_Prescription");
    if ( pTab_QWidget == 0 ) pTab_QWidget =  m_pGUI->tabWidget_HAS_Infos->activeTabWidgetByObjectName( "tab_Prescription");
    if ( pTab_QWidget == 0 ) return;
    m_pGUI->tabWidget_HAS_Infos->setCurrentWidget ( pTab_QWidget );
    Slot_add_product_In_C_Frm_Prescription(pQTreeWidgetItem);
}

//------------------------------------ Slot_giveDragtreeWidget_ProduitsItem_List_Data -------------------------------
void C_MW_Prescription::Slot_giveDragtreeWidget_ProduitsItem_List_Data(QString &data, QTreeWidgetItem *)
{   giveDragtreeWidget_CustomDrugsListItem_List_Data(data, m_pGUI->treeWidget_Produits);
}
//------------------------------------ Slot_giveDragtreeWidget_FavorisItem_List_Data --------------------------------------------------
void C_MW_Prescription::Slot_giveDragtreeWidget_FavorisItem_List_Data   (QString &data, QTreeWidgetItem * )
{   giveDragtreeWidget_CustomDrugsListItem_List_Data(data, m_pGUI->treeWidget_Favoris);
}
//--------------------------------------- Slot_giveDragtreeWidget_CustomDrugsListItem_List_Data -------------------------------------------------------
void C_MW_Prescription::Slot_giveDragtreeWidget_CustomDrugsListItem_List_Data(QString &data, QTreeWidgetItem *)
{   giveDragtreeWidget_CustomDrugsListItem_List_Data(data, m_pGUI->treeWidget_CustomDrugsList);
}
//--------------------------------------- Slot_giveDragtreeWidget_AccessoiresItem_List_Data -------------------------------------------------------
void C_MW_Prescription::Slot_giveDragtreeWidget_AccessoiresItem_List_Data(QString &data, QTreeWidgetItem *)
{   giveDragtreeWidget_CustomDrugsListItem_List_Data(data, m_pGUI->treeWidget_Accessoires);
}
//--------------------------------------- Slot_giveDragtreeWidget_PatientDrugsItem_List_Data -------------------------------------------------------
void C_MW_Prescription::Slot_giveDragtreeWidget_PatientDrugsItem_List_Data(QString &data, QTreeWidgetItem *)
{   giveDragtreeWidget_CustomDrugsListItem_List_Data(data, m_pGUI->treeWidget_PatientDrugs);
}
//--------------------------------------- giveDragtreeWidget_CustomDrugsListItem_List_Data -------------------------------------------------------
void C_MW_Prescription::giveDragtreeWidget_CustomDrugsListItem_List_Data(QString &dataXML, QTreeWidget *pQTreeWidget)
{
    dataXML  = "<C_BDM_DrugListRecordArray>\n";
    QList < C_BDM_DrugListRecord > drugsList = makeDrugsListRecords_From_QTreeWidgetProducts(pQTreeWidget,  1);
    for (int i=0; i<drugsList.size(); ++i)
        {dataXML += drugsList[i].serialize(0,"   ");    // serialisation sans le header
        }
    dataXML += "</C_BDM_DrugListRecordArray>\n";
}

//--------------------------------------- Slot_pushButton_addCustomList -------------------------------------------------------
void C_MW_Prescription::Slot_pushButton_addCustomList(bool)
{ if (  m_pC_BDM_Api==0 )                                                return;
  if (! m_pC_BDM_Api->isValid() )                                        return;
  QString userName = "BDM";
  bool ok;
  QString listName = QInputDialog::getText(this, tr("give your custom drugs list name"),
                                           tr("Give your new custom drugs list name:"), QLineEdit::Normal,
                                           "", &ok);
  if (ok && !listName.isEmpty())
    { m_pC_BDM_Api->createCustomProductsList(userName, listName);
      CApp::pCApp()->writeParam((CApp::pCApp()->applicationName() +"_TabManager").toAscii(), "Custom Products List", listName.toAscii());  // afin que fillCustomDrugListCombo se positionne dessus
      fillCustomDrugListCombo(userName);
    }
}

//--------------------------------------- Slot_pushButton_delCustomList -------------------------------------------------------
void C_MW_Prescription::Slot_pushButton_delCustomList(bool)
{ if (  m_pC_BDM_Api==0 )                                                return;
  if (! m_pC_BDM_Api->isValid() )                                        return;
  QString userName = "BDM";
  QString listName = m_pGUI->comboBox_customList->currentText();
  int ret          = QMessageBox::warning( this, tr("Delete a custom drug list"),
                                           tr("The custom drug list <font color=#ff0000><b>'%1'</b></font> must be deleted.<br />"
                                           "Do you want this?").arg(listName),
                                           QMessageBox::Cancel
                                         | QMessageBox::Apply,
                                           QMessageBox::Cancel);
  if (ret==QMessageBox::Apply)
     { m_pC_BDM_Api->deleteCustomProductsList( userName, listName);
       fillCustomDrugListCombo(userName);
     }
}

//--------------------------------------- Slot_comboBox_customList_activated -------------------------------------------------------
void C_MW_Prescription::Slot_comboBox_customList_activated( const QString &listName)
{ setCustomDrugListComboOn_ListName("BDM", listName);
  CApp::pCApp()->writeParam((CApp::pCApp()->applicationName() +"_TabManager").toAscii(), "Custom Products List", listName.toAscii());
  CApp::pCApp()->updateIniParamToDisk();
}

//--------------------------------------- makeDrugsListRecords_From_QTreeWidgetProducts -------------------------------------------------------
QList < C_BDM_DrugListRecord > C_MW_Prescription::makeDrugsListRecords_From_QTreeWidgetProducts(QTreeWidget *pQTreeWidget, int selectMode /* = 0*/)
{//........... creer la liste des enregistrements a partir de la QTreeWidget des produits ....................
 int                             nb = pQTreeWidget->topLevelItemCount();
 QTreeWidgetItem  *pQTreeWidgetItem = 0;
 QList < C_BDM_DrugListRecord > drugsList;

 for (int i=0; i<nb; ++i)
    { pQTreeWidgetItem = pQTreeWidget->topLevelItem (i);
      if ( pQTreeWidgetItem )
         { if (selectMode)
              {
                if (pQTreeWidgetItem->isSelected()) drugsList.append( C_BDM_DrugListRecord_From_QTreeWidgetProductsItem (pQTreeWidgetItem) );
              }
           else
              { drugsList.append( C_BDM_DrugListRecord_From_QTreeWidgetProductsItem (pQTreeWidgetItem) );
              }
         }
    }
 return drugsList;
}

//--------------------------------------- C_BDM_DrugListRecord_From_QTreeWidgetProductsItem -------------------------------------------------------
/*
    C_BDM_DrugListRecord(QString id,                0
                         QString id_type,           1
                         QString commercialName,    2
                         QString dci_1Name,         3
                         QString dc2_1Name,         4
                         QString dc3_1Name,         5
                         QString owner,             6
                         QString lang,              7
                         QString ucd,               8
                         QString ucd_price,         9
                         QString atc,               10
                         QString generique,         11
                         QString statut             12
                        )

# define COL_NAME         0
# define COL_DCI_1        1
# define COL_DCI_2        2
# define COL_DCI_3        3
# define COL_PRIX         4
# define COL_ATC          5
# define COL_ID           6
# define COL_CIS          7
# define COL_ORG          8
# define COL_ID_TYP       9
# define COL_SPEC_KEY     10
# define COL_GENERIQUE    11
# define COL_STATUT       12
 */
C_BDM_DrugListRecord C_MW_Prescription::C_BDM_DrugListRecord_From_QTreeWidgetProductsItem (QTreeWidgetItem  *pQTreeWidgetItem)
{ return     C_BDM_DrugListRecord( pQTreeWidgetItem->text(COL_ID),         // 0  id
                                   pQTreeWidgetItem->text(COL_ID_TYP),     // 1  id_type
                                   pQTreeWidgetItem->text(COL_PROD_NAME),  // 2  commercialName
                                   pQTreeWidgetItem->text(COL_DCI_1),      // 3  dci_1Name
                                   pQTreeWidgetItem->text(COL_DCI_2),      // 4  dci_2Name
                                   pQTreeWidgetItem->text(COL_DCI_3),      // 5  dci_3Name
                                   pQTreeWidgetItem->text(COL_ORG),        // 6  owner
                                   "fr",                                   // 7  lang
                                   "",                                     // 8  ucd
                                   pQTreeWidgetItem->text(COL_PRIX),       // 9  ucd_price
                                   pQTreeWidgetItem->text(COL_ATC),        // 10 atc
                                   pQTreeWidgetItem->text(COL_GENERIQUE),  // 11 generique
                                   pQTreeWidgetItem->text(COL_STATUT)      // 12 statut
                                 );
}

//--------------------------------------- setCustomDrugListComboOn_ListName -------------------------------------------------------
void C_MW_Prescription::setCustomDrugListComboOn_ListName(const QString &_userName, const QString &listName)
{int index = m_pGUI->comboBox_customList->findText ( listName );
 if (index != -1)
    {changeCurrentCustomList(_userName, listName);
     m_pGUI->comboBox_customList->setCurrentIndex(index);
     index = m_pGUI->toolBox_ListesProduits->toolWidgetIndexByTabObjectName("page_CustomList");
     m_pGUI->toolBox_ListesProduits->setItemText ( index, tr("Products list for %1").arg(listName) );
    }
}

//--------------------------------------- changeCurrentCustomList -------------------------------------------------------
void C_MW_Prescription::changeCurrentCustomList(const QString &_userName, const QString &listName)
{

   QList < C_BDM_DrugListRecord > drugsList = m_pC_BDM_Api->selectCustomProductsList(_userName,  listName,"", C_BDM_PluginI::no_filter);
   m_pGUI->treeWidget_CustomDrugsList->clear();
   fill_treeWidget_ProductsFromDrugList(m_pGUI->treeWidget_CustomDrugsList, drugsList);
}

//--------------------------------------- fillCustomDrugListCombo -------------------------------------------------------
void C_MW_Prescription::fillCustomDrugListCombo(const QString &_userName)
{ if (  m_pC_BDM_Api==0 )                                                return;
  if (! m_pC_BDM_Api->isValid() )                                        return;
#ifdef Q_WS_MAC
   QString userName     = _userName;
#endif
#ifdef Q_WS_WIN
   QString userName     = _userName.toLower();
#endif
#ifdef Q_WS_X11
   QString userName     = _userName;
#endif
  QStringList customList = m_pC_BDM_Api->getListCustomProductsList(userName);
  QString listName       = "";
  m_pGUI->comboBox_customList->clear();
  if (customList.size())
     { m_pGUI->comboBox_customList->insertItems(0, customList);
       listName = CApp::pCApp()->readUniqueParam((CApp::pCApp()->applicationName() +"_TabManager").toAscii(), "Custom Products List");
       if (listName.length()==0 || m_pGUI->comboBox_customList->findText ( listName ) == -1)
           { listName = customList.at(0);
             CApp::pCApp()->writeParam((CApp::pCApp()->applicationName() +"_TabManager").toAscii(), "Custom Products List", listName.toAscii());
           }
       setCustomDrugListComboOn_ListName( _userName, listName);
     }
}

//--------------------------------------- fillTreeWidgetComposition -------------------------------------------------------
void C_MW_Prescription::fillTreeWidgetComposition(const QString &cip)
{QWidget *pQWidget = m_pGUI->toolBox_classifications->toolWidgetByTabObjectName( "page_Composition");
 if (  pQWidget != m_pGUI->toolBox_classifications->currentWidget () )  return;           // si pas la page courante cela ne la concerne pas
 if (  m_pC_BDM_Api==0 )                                                return;
 if (! m_pC_BDM_Api->isValid() )                                        return;
 QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
 m_pGUI->treeWidget_Composition->clear();
 //.................. composition DCI .....................................................................
 //              C_InterResultPair.Code1()     is the quantity
 //              C_InterResultPair.CodeTyp1()  is the quantity unit
 //              C_InterResultPair.Term1()     is the composant name (DCI)
 QList<C_CompositionItem> compositionList = m_pC_BDM_Api->getCompositionFromCIP(cip);
 QTreeWidgetItem                *item     = 0;
 C_CompositionItem    compositionItem;
 for (int i = 0; i < compositionList.size(); ++i)
     { compositionItem   =  compositionList.at(i);
       item =   new QTreeWidgetItem (m_pGUI->treeWidget_Composition);
       item->setText(0,compositionItem.name());          // libelle
       item->setText(1,compositionItem.amount());        // quantite
       item->setText(2,compositionItem.unit());          // unite
     }
 QApplication::restoreOverrideCursor();
}
//--------------------------------------- Slot_treeWidget_Composition_itemClicked -------------------------------------------------------
void C_MW_Prescription::Slot_treeWidget_Composition_itemClicked ( QTreeWidgetItem *pQTreeWidgetItem , int   )
{   if ( pQTreeWidgetItem == 0 ) return;
    QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
    QList < C_BDM_DrugListRecord >  drugsList;
    QTime                        debTime     = QTime::currentTime();
    m_pC_BDM_Api->outMessage(tr("-------------- '%1' SELECT PRODUCTS FROM COMPOSITION --------------").arg(m_pC_BDM_Api->plugin_name()));
    drugsList += m_pC_BDM_Api->selectProductsList ("%"+pQTreeWidgetItem->text(0)//.remove("BASE").
                                                                                 .remove("ACIDE")
                                                                                 .remove("ANHYDRE")
                                                                                 .remove("TRIHYDRATE")
                                                                                 .remove("MONOHYDRATE")
                                                                                 .remove("EXTRAIT")
                                                                                 .remove("SODIQUE")
                                                                                 .remove("PULVERISE").trimmed(),
                                                   C_BDM_PluginI::dca_filter  , 7000 );
    m_pGUI->treeWidget_Produits->clear();
    int nb = fill_treeWidget_ProductsFromDrugList(m_pGUI->treeWidget_Produits, drugsList);
    if ( nb )
       { m_pGUI->toolBox_ListesProduits->setCurrentItem ( "page_Produits" );
       }
    m_pGUI->label_ListMedoc->setText(tr("%1 sur %2 produit(s)").arg(QString::number(nb),QString::number(m_pC_BDM_Api->drugsList_Size())));
    m_pC_BDM_Api->outMessage(tr("Plugin '%1' Slot_treeWidget_Composition_itemClicked() en : %2").arg(m_pC_BDM_Api->plugin_name(),   QTime (0, 0, 0, 0 ).addMSecs(debTime.msecsTo(QTime::currentTime())).toString("mm:ss:zzz") ));
    QApplication::restoreOverrideCursor();
}

//--------------------------------------- fill_treeWidget_ProductsFromDrugList -------------------------------------------------------
int C_MW_Prescription::fill_treeWidget_ProductsFromDrugList(QTreeWidget *pQTreeWidget, const QList < C_BDM_DrugListRecord >  &drugsList, QList < QTreeWidgetItem* >  *pItemssList /* = 0 */)
{int                    nb           = drugsList.size();
 QTreeWidgetItem       *item         = 0;
 C_BDM_DrugListRecord   drugRecord;
 QIcon datasempIcone    = Theme::getIcon("medicatux/VidalItem.png");
 QIcon theriaqueIcone   = Theme::getIcon("medicatux/TheriaqueItem.png");
 QIcon freeDrugIcone    = Theme::getIcon("medicatux/edit.png");
 QIcon accessoireIcone  = Theme::getIcon("medicatux/toolbox_accessoires.png");
 QIcon historiqueIcone  = Theme::getIcon("medicatux/masculin.png");
 QIcon ttt_fondIcone    = Theme::getIcon("medicatux/ttt_fondIcone.png");
 QIcon favoricip        = Theme::getIcon("medicatux/favoricip.png");
 if (m_pC_PatientCtx && m_pC_PatientCtx->get_sexe().left(1).toUpper()=="F") historiqueIcone = Theme::getIcon("medicatux/feminin.png");

 for (int i = 0; i < nb; ++i )
    { drugRecord = drugsList.at(i);
      item =   new QTreeWidgetItem (pQTreeWidget);
      if (item)  //  paranoiac attitude
         { item->setText(0,drugRecord.commercialName());   // libelle
           item->setText(1,drugRecord.dci_1Name());        // DCI_1
           item->setText(2,drugRecord.dci_2Name());        // DCI_2
           item->setText(3,drugRecord.dci_3Name());        // DCI_3
           item->setText(4,drugRecord.ucd_price());        // Prix
           item->setText(5,drugRecord.atc());              // ATC
           item->setText(6,drugRecord.id());               // ID CIP
           item->setText(8,drugRecord.owner());            // PROVENANCE
           item->setText(9,drugRecord.id_type());          // ID Type
           item->setText(11,drugRecord.generique());       // generique   G R ou S
           item->setText(12,drugRecord.statut());          // statut  Ville Hopital VH ou H
           if (pItemssList) pItemssList->append(item);

           if (drugRecord.owner()=="DS_A")       item->setIcon(0,accessoireIcone);
           else if (drugRecord.owner()=="DS")    item->setIcon(0,datasempIcone);
           else if (drugRecord.owner()=="TH")    item->setIcon(0,theriaqueIcone);
           else if (drugRecord.owner()=="CTX_I") item->setIcon(0,historiqueIcone);
           else if (drugRecord.owner()=="CTX_F") item->setIcon(0,ttt_fondIcone);
           else if (drugRecord.id_type()=="CIP") item->setIcon(0,favoricip);
           else                                  item->setIcon(0,freeDrugIcone);
        } // end if (item)  //  paranoiac attitude
    }
 return nb;
}

//--------------------------------------- Slot_treeWidget_Indications_itemClicked -------------------------------------------------------
void C_MW_Prescription::Slot_treeWidget_Indications_itemClicked ( QTreeWidgetItem *pQTreeWidgetItem , int c   )
{if ( pQTreeWidgetItem == 0 ) return;
 if (c==1)
    {

    }
 else
    {QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
     QList < C_BDM_DrugListRecord >  drugsList;
     QTime                        debTime     = QTime::currentTime();
     QStringList                     cipList  = m_pC_BDM_Api->getCIPFromIndication( pQTreeWidgetItem->text(2), pQTreeWidgetItem->text(3) );
     m_pC_BDM_Api->outMessage(tr("-------------- '%1' SELECT PRODUCTS FROM INDICATION --------------").arg(m_pC_BDM_Api->plugin_name()));
     m_pC_BDM_Api->outMessage(tr("Plugin '%1' Slot_treeWidget_Indications_itemClicked() getCIPFromIndication() en : %2").arg(m_pC_BDM_Api->plugin_name(),   QTime (0, 0, 0, 0 ).addMSecs(debTime.msecsTo(QTime::currentTime())).toString("mm:ss:zzz") ));
     debTime                                  = QTime::currentTime();
     QString cipListStr = cipList.join("','");
     if (cipList.size())
         {  drugsList += m_pC_BDM_Api->selectProductsList ("'"+cipListStr+"'", C_BDM_PluginI::cip_list  , 7000 );
         }
     m_pC_BDM_Api->outMessage(tr("Plugin '%1' Slot_treeWidget_Indications_itemClicked() selectProductsList() en : %2").arg(m_pC_BDM_Api->plugin_name(),   QTime (0, 0, 0, 0 ).addMSecs(debTime.msecsTo(QTime::currentTime())).toString("mm:ss:zzz") ));
     debTime                                  = QTime::currentTime();
     m_pGUI->treeWidget_Produits->clear();
     int nb = fill_treeWidget_ProductsFromDrugList(m_pGUI->treeWidget_Produits, drugsList);
     if (nb)
        {  m_pGUI->toolBox_ListesProduits->setCurrentItem ( "page_Produits" );
        }
     m_pGUI->label_ListMedoc->setText(tr("%1 sur %2 produit(s)").arg(QString::number(nb),QString::number(m_pC_BDM_Api->drugsList_Size())));
     m_pC_BDM_Api->outMessage(tr("Plugin '%1' Slot_treeWidget_Indications_itemClicked() fill treeWidget_Produits en : %2").arg(m_pC_BDM_Api->plugin_name(),   QTime (0, 0, 0, 0 ).addMSecs(debTime.msecsTo(QTime::currentTime())).toString("mm:ss:zzz") ));
     QApplication::restoreOverrideCursor();
    }
}

//--------------------------------------- fillTreeWidgetIndications -------------------------------------------------------
void C_MW_Prescription::fillTreeWidgetIndications(const QString &cip)
{QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
 m_pGUI->treeWidget_Indications->clear();
 //............ rajouter les indications liees au terrain du patient ..................
 fillTreeWidgetIndicationsFromPatientContext();
 //............ rajouter les indications liees au produit en entree ..................
 QList <C_BDM_IndicationRecord>    retList = m_pC_BDM_Api->getIndicationsFromCIP( cip, C_BDM_PluginI::ALL_INDIC );
 QTreeWidgetItem                    *item  = 0;
 C_LevelItemDelegate *pC_LevelItemDelegate = 0;
 // int pageIndex                             = toolWidgetIndexByTabObjectName(m_pGUI->toolBox_classifications, "page_Indications");
 // m_pGUI->toolBox_classifications->setItemText ( pageIndex, tr("Indications : ") + name.left(12)+"..." );
 if (retList.size())
    { for (int i = 0; i < retList.size(); ++i )
          { C_BDM_IndicationRecord indicationRecord   = retList.at(i);
            QString codeTyp                           = indicationRecord.codeTyp();
            item                                      = new QTreeWidgetItem (m_pGUI->treeWidget_Indications);
            pC_LevelItemDelegate                      = new C_LevelItemDelegate(m_pGUI->treeWidget_Indications);
            m_pGUI->treeWidget_Indications->setItemDelegate(pC_LevelItemDelegate);
            item->setText(1,indicationRecord.level());        // niveau
            item->setText(0,indicationRecord.indication());   // libelle
            item->setText(2,indicationRecord.code());         // code
            item->setText(3,codeTyp);                         // codeTyp
            item->setText(4,indicationRecord.descriptif());   // commentaire
            if (codeTyp=="CIM")
               {item->setIcon(0,Theme::getIcon("medicatux/CimItem.png"));
               }
            else if (codeTyp=="DS_I")
               {item->setIcon(0,Theme::getIcon("medicatux/VidalItem.png"));
               }
            else if (codeTyp=="TH_I")
               {item->setIcon(0,Theme::getIcon("medicatux/TheriaqueItem.png"));
               }
            else
               {item->setIcon(0,Theme::getIcon("medicatux/HasItem.png"));
               }
          }
    }
 QApplication::restoreOverrideCursor();
}
//--------------------------------------- fillTreeWidgetIndicationsFromPatientContext -------------------------------------------------------
void C_MW_Prescription::fillTreeWidgetIndicationsFromPatientContext()
{ QTreeWidgetItem                    *item  = 0;
  if (m_pC_PatientCtx)
    {QList <C_LifeEvent> eventLifeList = m_pC_PatientCtx->lifeEventList();
     QIcon item_icone = Theme::getIcon("medicatux/terrain_indic.png");
     for (int i = 0; i < eventLifeList.size(); ++i)
         {C_LifeEvent lifeEvent = eventLifeList.at(i);
          QString codeTyp       = lifeEvent.codeTyp();
          if ( codeTyp=="CIM" )
             { item   = new QTreeWidgetItem (m_pGUI->treeWidget_Indications);
               item->setIcon(0,item_icone);
               item->setText(0,lifeEvent.libelle());   // libelle
               item->setText(1,"");                    // niveau y en a pas
               item->setText(2,lifeEvent.code());      // code
               item->setText(3,codeTyp);               // code type
               item->setText(4,lifeEvent.comment());   // commentaire
             }
         }
    }
}

//--------------------------------------- Slot_On_pushButton_GeneralFontChoice -------------------------------------------------------
void C_MW_Prescription::Slot_On_pushButton_GeneralFontChoice(bool)
{   QString pixSize    = "11";
    QString family     = "Arial";
    QFont   initialFnt = this->font();

#ifdef Q_WS_MAC
    QString section    = "medicatux MacFontParam";
#endif
#ifdef Q_WS_WIN
    QString section    = "medicatux WinFontParam";
#endif
#ifdef Q_WS_X11
    QString section    = "medicatux LinFontParam";
#endif
    if (CApp::pCApp()->readParam(section.toAscii(), "interface", &pixSize, &family)==QString::null)  // zero = pas d'erreur
       { initialFnt.setFamily(family);
         initialFnt.setPixelSize(qMax(8,qMin(pixSize.toInt(),40)));
       }
    bool   ok;
    QFont  font = QFontDialog::getFont(&ok, initialFnt, this);
    if (ok)
       { this->setFont(font);
        QFontMetrics fm( font );
        int pixSize = fm.leading()+fm.height();
        CApp::pCApp()->writeParam(section.toAscii(), "interface", QString::number(pixSize).toAscii(), font.family().toAscii());
       }
}

//--------------------------------------- Slot_On_pushButton_PosoEditorFontChoice ----------------------------------------------------------
void C_MW_Prescription::Slot_On_pushButton_PosoEditorFontChoice(bool)
{   QString pixSize    = "11";
    QString family     = "Arial";
    QFont   initialFnt = this->font();
#ifdef Q_WS_MAC
    QString section    = "medicatux MacFontParam";
#endif
#ifdef Q_WS_WIN
    QString section    = "medicatux WinFontParam";
#endif
#ifdef Q_WS_X11
    QString section    = "medicatux LinFontParam";
#endif
    if (CApp::pCApp()->readParam(section.toAscii(), "posologieEditor", &pixSize, &family)==QString::null)  // zero = pas d'erreur
       { initialFnt.setFamily(family);
         initialFnt.setPixelSize(qMax(8,qMin(pixSize.toInt(),40)));
       }
    bool   ok;
    QFont  font = QFontDialog::getFont(&ok, initialFnt, this);
    if (ok)
       { if (m_pC_Frm_Prescription) m_pC_Frm_Prescription->setFont(font);
         QFontMetrics fm( font );
         int pixSize = fm.leading()+fm.height();
         CApp::pCApp()->writeParam(section.toAscii(), "posologieEditor", QString::number(pixSize).toAscii(), font.family().toAscii());
       }
}

//--------------------------------------- recordPositions -------------------------------------------------------------------------------
void C_MW_Prescription::recordPositions()
{   int x  =  this->x();
    int y  =  this->y();
    int w  =  this->width();
    int h  =  this->height();
    //................. enregistrer position fenetre principale .........................
    CApp::pCApp()->writeParam("medicatux geometry", "MainWindow",      QString::number(x).toAscii(), QString::number(y).toAscii(), QString::number(w).toAscii(),  QString::number(h).toAscii());
    CApp::pCApp()->writeParam("medicatux session" , "drug list limit", QString::number(m_drugListMax).toAscii());

    //................. enregistrer spliters .........................
    QList<int>  list = m_pGUI->splitter_g->sizes();
    CApp::pCApp()->writeParam("medicatux geometry", "splitter_g", QString::number(list[0]).toAscii(), QString::number(list[1]).toAscii());
    list = m_pGUI->splitter_d->sizes();
    CApp::pCApp()->writeParam("medicatux geometry", "splitter_d", QString::number(list[0]).toAscii(), QString::number(list[1]).toAscii());
    //................... enregistrer la position des tabulations ...................
    writeMainTabWidgetConfig();
    //................... enregistrer la fenetre d'affichage des interactions ...................
    // le faire dans le C_MW_Prescription::event() QEvent::Close car ici m_pC_Frm_Prescription est deja mort
    //................... enregistrer les headers de la liste des medocs ...................
    /* marche pas ??!!
    QHeaderView *pQHeaderView = m_pGUI->treeWidget_Produits->header ();
    QByteArray             ba = pQHeaderView->saveState();
    CApp::pCApp()->writeParam("medicatux geometry", "list products header", ba.toHex());
    */
    //................... enregistrer la config listview des medocs ..................
#ifdef Q_WS_MAC
    QString sufix     = "_mac.dsp";
#endif
#ifdef Q_WS_WIN
    QString sufix     = "_win.dsp";
#endif
#ifdef Q_WS_X11
    QString sufix     = "_lin.dsp";
#endif
    save_treeWidgetState(sufix, m_pGUI->treeWidget_Produits);
    save_treeWidgetState(sufix, m_pGUI->treeWidget_Favoris);
    save_treeWidgetState(sufix, m_pGUI->treeWidget_Indications);
    save_treeWidgetState(sufix, m_pGUI->treeWidget_Composition);
    save_treeWidgetState(sufix, m_pGUI->treeWidget_CustomDrugsList);
    save_treeWidgetState(sufix, m_pGUI->treeWidget_Accessoires);
    save_treeWidgetState(sufix, m_pGUI->treeWidget_PatientDrugs);
}
//--------------------------------------- save_treeWidgetState ----------------------------------------------------------
void C_MW_Prescription::save_treeWidgetState(const QString &sufix, QTreeWidget *pQTreeWidget)
{   QString nomFicDPS = CApp::pCApp()->pathAppli()+"Ressources/list_"+pQTreeWidget->objectName()+"_header" + sufix;
    QFile file( nomFicDPS );
    file.setFileName( nomFicDPS );
    if ( file.open( QIODevice::WriteOnly ) )
       { file. write (pQTreeWidget->header()->saveState());
         file.close();
       }
}
//--------------------------------------- restore_treeWidgetState ----------------------------------------------------------
void C_MW_Prescription::restore_treeWidgetState(const QString &sufix, QTreeWidget *pQTreeWidget)
{   QString nomFicDPS = CApp::pCApp()->pathAppli()+"Ressources/list_"+pQTreeWidget->objectName()+"_header" + sufix;
    if ( QFile::exists(nomFicDPS) )
       { QFile file( nomFicDPS );
         if ( file.open( QIODevice::ReadOnly ) )
            { pQTreeWidget->header()->restoreState(file.readAll());
              file.close();
            }
       }
}
//--------------------------------------- setPositionsFromIniFile ----------------------------------------------------------
void C_MW_Prescription::setPositionsFromIniFile()
{   QString val1, val2, val3, val4;
    if (CApp::pCApp()->readParam("medicatux geometry", "MainWindow", &val1, &val2, &val3, &val4)==QString::null)  // zero = pas d'erreur
       {move(   val1.toInt(),   val2.toInt() );
        resize( val3.toInt(),   val4.toInt() );
       }
    QList <int> list;
    if (CApp::pCApp()->readParam("medicatux geometry", "splitter_d", &val1, &val2)==QString::null)  // zero = pas d'erreur
       {list.clear();
        list.append(val1.toInt());
        list.append(val2.toInt());
        m_pGUI->splitter_d->setSizes(list);
      }
    if (CApp::pCApp()->readParam("medicatux geometry", "splitter_g", &val1, &val2)==QString::null)  // zero = pas d'erreur
       {list.append(val1.toInt());
        list.append(val2.toInt());
        m_pGUI->splitter_g->setSizes(list);
      }

    //...... charge la config listview des medocs .................
#ifdef Q_WS_MAC
    QString sufix     = "_mac.dsp";
#endif
#ifdef Q_WS_WIN
    QString sufix     = "_win.dsp";
#endif
#ifdef Q_WS_X11
    QString sufix     = "_lin.dsp";
#endif
    restore_treeWidgetState(sufix, m_pGUI->treeWidget_Produits);
    restore_treeWidgetState(sufix, m_pGUI->treeWidget_Favoris);
    restore_treeWidgetState(sufix, m_pGUI->treeWidget_Indications);
    restore_treeWidgetState(sufix, m_pGUI->treeWidget_Composition);
    restore_treeWidgetState(sufix, m_pGUI->treeWidget_CustomDrugsList);
    restore_treeWidgetState(sufix, m_pGUI->treeWidget_Accessoires);
    restore_treeWidgetState(sufix, m_pGUI->treeWidget_PatientDrugs);
    //m_pGUI->treeWidget_Indications->header()->hideSection(3);
    //m_pGUI->treeWidget_Indications->header()->hideSection(4);
    m_pGUI->treeWidget_Indications->header()->showSection(3);
    m_pGUI->treeWidget_Indications->header()->showSection(4);

    // setFontFromIniFile(); deja fait lors creation C_Frm_Prescription

    setMainTabWidgetConfig();
}
//--------------------------------- setFontFromIniFile -----------------------------------------------------------------------
QFont C_MW_Prescription::setFontFromIniFile()
{    //....... config polices .....................
    QString pixSize    = "11";
    QString family     = "Arial";
    QFont   initialFnt = this->font();
#ifdef Q_WS_MAC
    QString section    = "medicatux MacFontParam";
#endif
#ifdef Q_WS_WIN
    QString section    = "medicatux WinFontParam";
#endif
#ifdef Q_WS_X11
    QString section    = "medicatux LinFontParam";
#endif
    if (CApp::pCApp()->readParam(section.toAscii(), "interface", &pixSize, &family)==QString::null)  // zero = pas d'erreur
       { initialFnt.setPixelSize(pixSize.toInt());
         initialFnt.setFamily(family);
         this->setFont(initialFnt);
       }
    if (CApp::pCApp()->readParam(section.toAscii(), "posologieEditor", &pixSize, &family)==QString::null)  // zero = pas d'erreur
       { initialFnt.setPixelSize(pixSize.toInt());
         initialFnt.setFamily(family);
         if (m_pC_Frm_Prescription) m_pC_Frm_Prescription->setFont(initialFnt);
       }
    return  initialFnt;  // retiurne la fonte de m_pC_Frm_Prescription
}

//--------------------------------- setMainTabWidgetConfig -----------------------------------------------------------------------
void C_MW_Prescription::setMainTabWidgetConfig()
{
    QByteArray section                = (CApp::pCApp()->applicationName() +"_TabManager").toAscii();
    QString defaultTab                = CApp::pCApp()->readUniqueParam(  section, "defaultTab");
    QString defaultProductsList       = CApp::pCApp()->readUniqueParam(  section, "defaultProductsList");
    QString defaultClassificationList = CApp::pCApp()->readUniqueParam(  section, "defaultClassificationList");
    QString defaultAccessoryList      = CApp::pCApp()->readUniqueParam(  section, "defaultAccessoryList");
    //......... recuperer la liste des onglets a inactiver .................................................
    //          attention : c'est le texte du titre de l'onglet qui est stocke dans la liste
    //                      et non le objectName
    int       index   = -1;
    QStringList list  = CApp::pCApp()->getParamList( section , "inactiveTab", 1);
    for (int i = 0; i<list.size(); ++i)
        { m_pGUI->tabWidget_HAS_Infos->tabWidgetByTabText(list[i], &index);
          m_pGUI->tabWidget_HAS_Infos->Slot_CloseRequested(index);
        }

    //............. activer l'onglet par defaut ..............................................................
    //              attention : la c'est l'objectName qui est stocke
    m_pGUI->tabWidget_HAS_Infos->setCurrentItem ( defaultTab );
    //............. activer la liste des produits par defaut ..............................................................
    //              attention : la c'est l'objectName qui est stocke
    m_pGUI->toolBox_ListesProduits->setCurrentItem ( defaultProductsList );
    //............. activer la liste des classifications par defaut ..............................................................
    //              attention : la c'est l'objectName qui est stocke
    m_pGUI->toolBox_classifications->setCurrentItem ( defaultClassificationList );
    //............. activer la combo accessoires ..............................................................
    index = m_pGUI->comboBox_FamillesProduits->findText(defaultAccessoryList);
    if (index != -1) { m_pGUI->comboBox_FamillesProduits->setCurrentIndex(index);
                       Slot_comboBox_FamillesProduits_activated( index);
                     }
}

//--------------------------------- writeMainTabWidgetConfig -----------------------------------------------------------------------
void C_MW_Prescription::writeMainTabWidgetConfig()
{ QStringList list     = m_pGUI->tabWidget_HAS_Infos->removedList();
  QByteArray section   = (CApp::pCApp()->applicationName() +"_TabManager").toAscii();
  QWidget *pQWidget    = m_pGUI->toolBox_ListesProduits->currentWidget();
  if (pQWidget)
     { CApp::pCApp()->writeParam(  section, "defaultProductsList", pQWidget->objectName().toAscii());
     }
  pQWidget = m_pGUI->toolBox_classifications->currentWidget();
  if (pQWidget)
     { CApp::pCApp()->writeParam(  section, "defaultClassificationList", pQWidget->objectName().toAscii());
     }
  CApp::pCApp()->writeParam(   section, "defaultAccessoryList", m_pGUI->comboBox_FamillesProduits->currentText().toAscii());
  CApp::pCApp()->writeParam(   section, "defaultTab",           m_pGUI->tabWidget_HAS_Infos->currentWidget()->objectName().toAscii());
  CApp::pCApp()->replaceList(  section, "inactiveTab",          list );
}

//------------------------ Slot_PrescriptionWantGeometry ---------------------------------------
void C_MW_Prescription::Slot_PrescriptionWantGeometry(QRect &application_rect, QRect &wdg_rect)
{ QString val1, val2, val3, val4;
  application_rect = this->geometry();         // ok on peut toujours repondre a ca
  wdg_rect = QRect(-1,-1,-1,-1);               // par defaut non connu
  if (  CApp::pCApp()->readParam("medicatux geometry", "interaction window", &val1, &val2, &val3, &val4)==QString::null)  // zero = pas d'erreur
     {  wdg_rect = QRect(val1.toInt(),val2.toInt(),val3.toInt(),val4.toInt());
     }
}
//-------------------------------- Slot_On_comboBox_choixBase ------------------------------------------------------
void C_MW_Prescription::Slot_On_comboBox_choixBase(const QString &namePlugin)
{  set_BDM_Plugin(namePlugin);
   if (m_pC_Frm_Prescription)
      { m_pC_Frm_Prescription->set_Thread_DBM_Plugin( namePlugin );
        m_pC_Frm_Prescription->Slot_evaluateAllInteractions();
      }
   setWindowTitle();
}

//-------------------------------- set_BDM_Plugin ------------------------------------------------------
/*! \brief connect API to source datas via C_BDM_InitPluginI interface which provides data to  C_BDM_Api
 *  \param QString namePlugin of C_BDM_InitPluginI data source ( 'theriaque' 'datasemp')
 *  \return C_BDM_PluginI * pointer on plugin or zero if error
 */

C_BDM_PluginI *C_MW_Prescription::set_BDM_Plugin(const QString &_namePlugin)   // theriaque datasemp C_BDM_GENERICPLUGIN
{   QTime debTime       = QTime::currentTime();
    QTime debGTime      = QTime::currentTime();
    QString namePlugin  = _namePlugin.toUpper().trimmed();
    C_BDM_PluginI *pC_BDM_PluginI = 0;
    m_pC_BDM_Api->outMessage(tr("=============== SET DATABASE '%1' =====================").arg(namePlugin ));
    //.............. on cherche le plugin de base de donnee dans la liste.................
    QMap<QString, C_BDM_PluginI*>::const_iterator it = CApp::pCApp()->m_pC_BDM_PluginI_Map.find(namePlugin);
    //.............. si non trouve on initialise le plugin ...............................
    if (it == CApp::pCApp()->m_pC_BDM_PluginI_Map.constEnd() )  // si pas trouve le creer et le rajouter a la liste
       {
            QString confData =   QString("[BDM_Configuration]\n"
                                         "     PathAppli     = %2\n"
                                         "     PathIni       = %3\n").arg( CApp::pCApp()->pathAppli() , CApp::pCApp()->pathIni());
            if (namePlugin=="THERIAQUE")
               { debTime  = QTime::currentTime();
                 pC_BDM_PluginI = new C_BDM_TheriaquePlugin(confData, "MAIN_", 0, m_pGUI->textEdit_Monitor, m_pQProgressBar);
                 m_pC_BDM_Api->outMessage(tr("Database '%1' creation en : %2").arg(namePlugin,   QTime (0, 0, 0, 0 ).addMSecs(debTime.msecsTo(QTime::currentTime())).toString("mm:ss:zzz") ));
               }

            else if (namePlugin=="C_BDM_GENERICPLUGIN")
              { debTime  = QTime::currentTime();
                pC_BDM_PluginI =  new C_BDM_GenericPlugin(confData, "MAIN_", 0, m_pGUI->textEdit_Monitor, m_pQProgressBar);
                m_pC_BDM_Api->outMessage(tr("Database '%1' creation en : %2").arg(namePlugin,   QTime (0, 0, 0, 0 ).addMSecs(debTime.msecsTo(QTime::currentTime())).toString("mm:ss:zzz") ));
              }

            else if (namePlugin=="DATASEMP")
               { debTime  = QTime::currentTime();
                 pC_BDM_PluginI =  new C_BDM_DatasempPlugin(confData, "MAIN_", 0, m_pGUI->textEdit_Monitor, m_pQProgressBar);
                 m_pC_BDM_Api->outMessage(tr("Database '%1' creation en : %2").arg(namePlugin,   QTime (0, 0, 0, 0 ).addMSecs(debTime.msecsTo(QTime::currentTime())).toString("mm:ss:zzz") ));
               }
            else if (namePlugin.length()==0)
               { m_pC_BDM_Api->outMessage(tr("failure in data source initialisation :  <b>empty plugin name</b>"));
               }
            else
               { m_pC_BDM_Api->outMessage(tr("failure in data source <b>%1</b> unknow name").arg(namePlugin));
               }

            //............................... CASSOS SI NOM INCONNU ................................
            if (pC_BDM_PluginI==0)  return 0;
            if (pC_BDM_PluginI->isInitialised())
               {  CApp::pCApp()->m_pC_BDM_PluginI_Map[namePlugin] = pC_BDM_PluginI;
               }
            else
               {  pC_BDM_PluginI = 0;
                  m_pC_BDM_Api->outMessage(tr("failure in drug data source <b>%1</b> initialisation").arg(namePlugin));
               }
       }
    //.............. si trouve on prend le plugin ...............................
    else
      {pC_BDM_PluginI = it.value();
      }

    //....................... activer ce plugin dans tous les objets qui en depcomboBox_choixBaseendent ..................
    if ( pC_BDM_PluginI && pC_BDM_PluginI->isInitialised() && m_pC_BDM_Api)
       {
          m_pC_BDM_Api->connectToDataSource( pC_BDM_PluginI );             // donner au controleur le plugin
          CApp::pCApp()->set_BDM_Plugin(pC_BDM_PluginI);                   // set_BDM_Plugin est defini dans C_Macro.h dont CApp est derive
          m_pC_BDM_Api->addOwner(pC_BDM_PluginI->owner());                 // n'est rajoute que si n'existe pas
          if (m_pC_BDM_Api->drugsList_Size()==0)   //  cas du plugin generique (pas de base medicamenteuse)
             { m_pGUI->toolBox_ListesProduits->unactiveItemByObjectName("page_Accessoires");
               m_pGUI->toolBox_ListesProduits->unactiveItemByObjectName("page_Produits");
               m_pGUI->toolBox_classifications->unactiveItemByObjectName("page_Composition");
               m_pGUI->toolBox_classifications->unactiveItemByObjectName("page_ATC");
             }
          else
             { m_pGUI->toolBox_ListesProduits->activeItemByObjectName("page_Produits");
               m_pGUI->toolBox_classifications->activeItemByObjectName("page_Composition");
               m_pGUI->toolBox_classifications->activeItemByObjectName("page_ATC");
               if (namePlugin=="DATASEMP")
                  { m_pGUI->toolBox_ListesProduits->activeItemByObjectName("page_Accessoires");
                    m_pGUI->toolBox_ListesProduits->setItemIcon ( "page_Accessoires", Theme::getIcon("medicatux/toolbox_accessoires.png") ); // pourquoi pert il son icone ??
                  }
               else
                  { m_pGUI->toolBox_ListesProduits->unactiveItemByObjectName("page_Accessoires");
                  }
               int indexPage = m_pGUI->toolBox_ListesProduits->toolWidgetIndexByTabObjectName("page_Produits");
               m_pGUI->toolBox_ListesProduits->setItemText ( indexPage, tr("Products %1").arg(_namePlugin) );
               m_pGUI->toolBox_ListesProduits->setItemIcon ( indexPage, m_pC_BDM_Api->plugin_icon() );
               debTime  = QTime::currentTime();
               //......... remplissage des listes ......................
               m_pC_BDM_Api->fill_ATC_treeWidget(m_pGUI->treeWidget_ATC);  // ATC doit toujours etre remplie
               m_pC_BDM_Api->outMessage(tr("Database '%1' fill_ATC_treeWidget() en : %2").arg(namePlugin, QTime (0, 0, 0, 0 ).addMSecs(debTime.msecsTo(QTime::currentTime())).toString("mm:ss:zzz") ));
             }
          debTime  = QTime::currentTime();
          fill_only_showed_treeWidgets( m_pGUI->toolBox_ListesProduits->currentWidget()->objectName() );
          m_pC_BDM_Api->outMessage(tr("Database '%1' Slot_lineEdit_DrugsSearch_textChanged() en : %2").arg(namePlugin, QTime (0, 0, 0, 0 ).addMSecs(debTime.msecsTo(QTime::currentTime())).toString("mm:ss:zzz") ));
          QString section = "medicatux data source";
          CApp::pCApp()->writeParam(section.toAscii(), "name", namePlugin.toAscii());
          if (m_pC_Frm_Prescription)
             { m_pC_Frm_Prescription->Slot_evaluateAllInteractions();
               m_pC_Frm_Prescription->set_Thread_DBM_Plugin( namePlugin );
             }
          m_pC_BDM_Api->outMessage(tr("Database '%1' connect\303\251e en : %2").arg(namePlugin,   QTime (0, 0, 0, 0 ).addMSecs(debGTime.msecsTo(QTime::currentTime())).toString("mm:ss:zzz") ));
       }
    else
       {pC_BDM_PluginI = 0;
       }
    return pC_BDM_PluginI;
}

//------------------------ display_HAS_Status ---------------------------------------
void C_MW_Prescription::display_HAS_Status()
{ if (m_pC_Frm_Prescription==0) return;
  m_pC_Frm_Prescription->display_HAS_Status();
}

//------------------------ setWindowTitle ---------------------------------------
void C_MW_Prescription::setWindowTitle()
{QString title = CApp::pCApp()->applicationName()  + " (" +  m_pC_BDM_Api->dataSourceVersion() + ") ";
 if (m_pC_PatientCtx && m_pC_PatientCtx->get_usual_name().length())
    {
     title += m_pC_PatientCtx->get_usual_name() + " " + m_pC_PatientCtx->get_forename() + tr(" \303\242ge : ") + m_pC_PatientCtx->get_age() + tr(" poids : ") + m_pC_PatientCtx->poids();

    }
 QMainWindow::setWindowTitle(title);
}
//------------------------ userCtxToInterface ---------------------------------------
void C_MW_Prescription::userCtxToInterface(C_UserCtx *pC_UserCtx)
{if (pC_UserCtx==0) return;
 m_pGUI->lineEdit_UserNom->setText(pC_UserCtx->get_usual_name());
 m_pGUI->lineEdit_UserPrenom->setText(pC_UserCtx->get_forename() );
 m_pGUI->lineEdit_UserTitre->setText(pC_UserCtx->get_Titre() );
 m_pGUI->lineEdit_UserAdresse->setText(pC_UserCtx->get_Adresse() );
 m_pGUI->lineEdit_UserCodePostal->setText(pC_UserCtx->get_CodePostal() );
 m_pGUI->lineEdit_UserVille->setText(pC_UserCtx->get_Ville() );
 m_pGUI->lineEdit_UserEmail->setText(pC_UserCtx->get_Email() );
 m_pGUI->lineEdit_UserRPPS->setText(pC_UserCtx->get_Nu_RPPS() );
 m_pGUI->lineEdit_UserClefRPPS->setText(pC_UserCtx->get_Nu_ClefRPPS() );
 m_pGUI->lineEdit_UserNumOrdinal->setText(pC_UserCtx->get_Nu_ordinal() );
 m_pGUI->lineEdit_UserTel1->setText(pC_UserCtx->get_Tel1() );
 m_pGUI->lineEdit_UserTel2->setText(pC_UserCtx->get_Tel2() );
 m_pGUI->lineEdit_UserTel3->setText(pC_UserCtx->get_Tel3() );
}

//------------------------ patientCtxToInterface ---------------------------------------
void C_MW_Prescription::patientCtxToInterface(C_PatientCtx *pC_PatientCtx)
{QString dateStr = "";
 if (pC_PatientCtx==0) return;
 dateStr = pC_PatientCtx->get_dateOfBirth("dd-MM-yyyy");
 m_pGUI->lineEdit_Nom->setText(pC_PatientCtx->get_usual_name());
 m_pGUI->lineEdit_NomNaissance->setText(pC_PatientCtx->get_young_name());
 m_pGUI->lineEdit_Prenom->setText(pC_PatientCtx->get_forename());
 m_pGUI->lineEdit_DateNaissance->setText(dateStr);
 m_pGUI->lineEdit_poids->setText(pC_PatientCtx->poids());
 m_pGUI->lineEdit_taille->setText(pC_PatientCtx->taille());
 QString sexe = pC_PatientCtx->get_sexe().left(1);
 m_pGUI->lineEdit_sexe->setText( (sexe=="M")?tr("Masculin"):tr("F\303\251minin"));
 m_pGUI->label_DtNaiss->setText(tr("\303\242g\303\251 de <b>%1</b> n\303\251%2 le ").arg(C_DateTools::CalculeDiffAge(pC_PatientCtx->get_dateOfBirth()),(sexe=="M")?"":"e"));
 QList <C_LifeEvent> lifeEventList =  pC_PatientCtx->lifeEventList();
 m_pGUI->treeWidget_ATCD->clear();
 for (int i=0; i<lifeEventList.size(); ++i)
     {QTreeWidgetItem *item = new QTreeWidgetItem(m_pGUI->treeWidget_ATCD);
      item->setText(0,lifeEventList.at(i).code());
      item->setText(1,lifeEventList.at(i).codeTyp());
      item->setText(2,lifeEventList.at(i).libelle());
      item->setText(3,lifeEventList.at(i).AldSportVigilanceProperty());
      item->setText(4,lifeEventList.at(i).medintuxClass());
      item->setText(5,lifeEventList.at(i).comment());
      item->setText(6,lifeEventList.at(i).dateDeb());
      item->setText(7,lifeEventList.at(i).dateFin());
      m_pGUI->treeWidget_ATCD->addTopLevelItem(item);
     }
}
//------------------------ Slot_retranslateUi ---------------------------------------
void C_MW_Prescription::Slot_retranslateUi()
{
}
//------------------------------------ C_MW_Prescription -------------------------------
C_MW_Prescription::~C_MW_Prescription()
{   delete m_pGUI;
    if (m_pC_BDM_Api)      delete m_pC_BDM_Api;
    if (m_pC_PatientCtx)   delete m_pC_PatientCtx;
    // if (m_pC_PatientBase)  delete m_pC_PatientBase;
}
//------------------------ event -----------------------------------------
bool C_MW_Prescription::event ( QEvent * e )
{if (e->type()==QEvent::Close)
    {if (m_pC_Frm_Prescription)
        { QRect rect = m_pC_Frm_Prescription-> get_displayInteractionWindowGeometry();
          //................... enregistrer la fenetre d'affichage des interactions ...................
          if ( rect.x() != -1 )
             { CApp::pCApp()->writeParam("medicatux geometry", "interaction window", QString::number(rect.x()).toAscii(),     QString::number(rect.y()).toAscii(),
                                                                                     QString::number(rect.width()).toAscii(), QString::number(rect.height()).toAscii()
                                        );
             }
          m_pC_Frm_Prescription->Slot_close();
        }
     Slot_Apropos_Proc_finished (0,  QProcess::NormalExit);
    }
 return QMainWindow::event(e);
}
//------------------------ Slot_Apropos_Proc_finished -----------------------------------------
void C_MW_Prescription::Slot_Apropos_Proc_finished (int,  QProcess::ExitStatus)
{if (m_Apropos_Proc)
    {m_Apropos_Proc->terminate();
     m_Apropos_Proc->waitForFinished (5000);
     delete m_Apropos_Proc;
     m_Apropos_Proc = 0;
    }
}

//------------------------ add_C_Frm_Prescription -----------------------------------------
int C_MW_Prescription::add_C_Frm_Prescription(const QFont &fnt, const QStringList &grammarList)
{ m_pC_Frm_Prescription = new C_Frm_Prescription( CApp::pCApp()->pathTheme() + CApp::pCApp()->applicationName()+"/",
                                                  m_pC_BDM_Api,
                                                  m_pGUI->scrollArea_Prescription,
                                                  this );
 QString section     = "medicatux products config";
 QString value_ald   = CApp::pCApp()->readUniqueParam(section, "background color ald");
 QString value_std   = CApp::pCApp()->readUniqueParam(section, "background color std");
 int childs_w        = CApp::pCApp()->readUniqueParam(section, "last width").toInt();
 int childs_h        = CApp::pCApp()->readUniqueParam(section, "last height").toInt();

 m_pC_Frm_Prescription->setChildsColors(value_std, value_ald);
 m_pC_Frm_Prescription->setChildsSize(childs_w, childs_h);

 m_pGUI->scrollArea_Prescription->setWidget(m_pC_Frm_Prescription);
 connect( m_pC_Frm_Prescription,  SIGNAL(Sign_child_LeaveLastEditZone()),                  this, SLOT(Slot_child_LeaveLastEditZone()));
 connect( m_pC_Frm_Prescription,  SIGNAL(Sign_PrescriptionWantGeometry(QRect &, QRect &)), this, SLOT(Slot_PrescriptionWantGeometry(QRect &, QRect &)));
 connect( m_pC_Frm_Prescription,  SIGNAL(Sign_ProductNumberClicked( C_Frm_Produit* )),     this, SLOT(Slot_ProductNumberClicked( C_Frm_Produit* )));
 connect( m_pC_Frm_Prescription,  SIGNAL(Sign_FavorisAdded( C_Frm_Produit* )),             this, SLOT(Slot_FavorisAdded( C_Frm_Produit* )));       // mettre a jour la liste des favoris
 m_pC_Frm_Prescription->setFont(fnt);
 if (grammarList.length())
    {m_pC_Frm_Prescription->setGrammarList(grammarList);
    }
 return 0;
}

//------------------------ Slot_add_product_In_C_Frm_Prescription ---------------------------------------
/*
    C_BDM_DrugListRecord(QString id,
                         QString id_type,
                         QString commercialName,
                         QString dci_1Name,
                         QString dc2_1Name,
                         QString dc3_1Name,
                         QString owner,
                         QString lang,
                         QString ucd,
                         QString ucd_price,
                         QString atc,
                         QString generique,
                         QString statut
                        )
                        */
void C_MW_Prescription::Slot_add_product_In_C_Frm_Prescription(QTreeWidgetItem * pQTreeWidgetItem)
{ if (m_pC_Frm_Prescription==0)   return;
  if (pQTreeWidgetItem==0)        return;
  QString xmlData   = "";
  if ( can_use_API(pQTreeWidgetItem) )                               // produits concernes par m_pC_BDM_Api
     { QList < C_BDM_DrugListRecord > drugList = m_pC_BDM_Api->selectProductsList (pQTreeWidgetItem->text(COL_ID), C_BDM_PluginI::cip_filter);
       if (drugList.count())
          { xmlData = drugList.first().serialize();
            m_pC_Frm_Prescription->appendNewObject(xmlData, true);
          }
     }
  else                                                               // produits de provenance obscure
     { C_BDM_DrugListRecord c_bdm_druglistrecord = C_BDM_DrugListRecord_From_QTreeWidgetProductsItem (pQTreeWidgetItem);
       xmlData = c_bdm_druglistrecord.serialize();
       m_pC_Frm_Prescription->appendNewObject(xmlData, true);
     }
}
//------------------------ can_use_API ---------------------------------------
bool C_MW_Prescription::can_use_API( QTreeWidgetItem * pQTreeWidgetItem )
{return pQTreeWidgetItem->text(COL_ID_TYP)=="CIP";
}

//------------------------ Slot_child_LeaveLastEditZone ---------------------------------------
void C_MW_Prescription::Slot_child_LeaveLastEditZone()
{m_pGUI->lineEdit_DrugsSearch->setFocus();
 m_pGUI->lineEdit_DrugsSearch->selectAll();
}

//--------------------------------- Slot_lineEditAutoLocator_keyPressEvent -----------------------------------------------------------------------
void C_MW_Prescription::Slot_lineEditAutoLocator_keyPressEvent(QKeyEvent *event, int &callStandardEvent)
{ lineEdit_searchProducts_keyPressEvent(m_pGUI->treeWidget_Produits, event, callStandardEvent);
}

//--------------------------------- getSelectedListViewItem -------------------------------------------------------------
QTreeWidgetItem * C_MW_Prescription::getSelectedListViewItem(QTreeWidget *pQTreeWidget)
{ if (pQTreeWidget==0) return 0;
  QList<QTreeWidgetItem *> list = pQTreeWidget->selectedItems ();
  int nb                        = list.size();
  if (nb) return list[nb-1];               // on prend le dernier de la selection
  return 0;
}

//------------------------------------ Slot_m_action_APropos -------------------------------
void C_MW_Prescription::Slot_m_action_APropos ()
{   QString macAdr;
    QString ipAdr  = CApp::pCApp()->get_Current_IP_Adr(&macAdr);
    CGestIni::Param_UpdateToDisk(CApp::pCApp()->pathAppli()+"Ressources/Changements.html",
                                 m_pGUI->textEdit_changeLog->toHtml().replace("{{IP_ADR}}",  ipAdr)
                                                                     .replace("{{MAC_ADR}}", macAdr)
                                                                     .replace("{{PATH_INI}}",CApp::pCApp()->pathIni())
                                 );
    QString pathExeAPropos     = CGestIni::Construct_Name_Exe("APropos",       QFileInfo (qApp->argv()[0]).path());
    QStringList argList;
    //......................... completer les autres arguments .........................................
    argList << CApp::pCApp()->applicationName();                                                            // 1  nom du module
    argList << tr("Module for drugs prescription");                                                         // 2  description courte
    argList << CApp::pCApp()->ApplicationAndQtVersion(tr("%1:%2").arg(__DATE__,__TIME__));                  // 3  numero de version
    argList << CApp::pCApp()->pathAppli()+"Ressources/Changements.html";                                    // 4  fichiers decrivant les changements
    argList <<"";                                                                                           // 5  Icone par defaut
    argList <<"";                                                                                           // 6  aide en ligne (vide pour prendre celle par defaut)
    argList <<"";                                                                                           // 7  apropos (on met une chaine vide pour qu'il prenne celui par d?faut)
    argList << (m_pC_BDM_Api?m_pC_BDM_Api->dataSourceVersion():tr("Drug DB version not available"));        // 8  numero de version de la base de donnee
    if (m_Apropos_Proc==0)
       { m_Apropos_Proc = new QProcess(this);
         if (m_Apropos_Proc)
            {connect( m_Apropos_Proc, SIGNAL(finished ( int,  QProcess::ExitStatus)),  this, SLOT(Slot_Apropos_Proc_finished (int,  QProcess::ExitStatus)) );
             m_Apropos_Proc->start(pathExeAPropos, argList);
             m_Apropos_Proc->waitForStarted  (4000);
            }
       }
}

//------------------------------------ Slot_toolButton_zoomUpReleased -------------------------------
void C_MW_Prescription::Slot_toolButton_zoomUpReleased (  )
{if (m_pC_Frm_Prescription==0) return;
 m_pC_Frm_Prescription->setZoom(5);
 QSize size      = m_pC_Frm_Prescription->getChildsSize();
 QString section = "medicatux products config";
 CApp::pCApp()->writeParam(section.toAscii(), "last height", QString::number(size.height()).toAscii());
 CApp::pCApp()->writeParam(section.toAscii(), "last width",  QString::number(size.width()).toAscii());
}

//------------------------------------ Slot_toolButton_zoomDwReleased -------------------------------
void C_MW_Prescription::Slot_toolButton_zoomDwReleased (  )
{if (m_pC_Frm_Prescription==0) return;
 m_pC_Frm_Prescription->setZoom(-5);
 QString section = "medicatux products config";
 QSize size      = m_pC_Frm_Prescription->getChildsSize();
 CApp::pCApp()->writeParam(section.toAscii(), "last height", QString::number(size.height()).toAscii());
 CApp::pCApp()->writeParam(section.toAscii(), "last width",  QString::number(size.width()).toAscii());
}
//------------------------------------ Slot_prescription_zoom_menu_triggered -------------------------------
void C_MW_Prescription::Slot_prescription_zoom_menu_triggered ( QAction* pQAction)
{ if (m_pC_Frm_Prescription==0) return;
   // tr("1 - Mode r\303\251duit");
   // tr("2 - Mode d\303\251ploy\303\251 ");
   // tr("3 - Enregistrer la position courante comme mode r\303\251duit");
   // tr("4 - Enregistrer la position courante comme mode d\303\251ploy\303\251");
   // tr("5 - Choisir une couleur pour la zone non ALD");
   // tr("6 - Choisir une couleur pour la zone ALD");
   // tr("7 - Cacher les graduations");
   // tr("8 - Montrer les graduations");
   // tr("9 - d\303\251sactiver 'apres-midi'"));
   // tr("10- activer 'apres-midi'"));
   // tr("11- d\303\251sactiver 'coucher'"));
   // tr("12- activer 'coucher'"));
   // tr("13- d\303\251sactiver 'nuit'"));
   // tr("14- activer 'nuit'"));

  QSize size      = m_pC_Frm_Prescription->getChildsSize();
  int option      = pQAction->text ().left(2).trimmed().toInt();
  QString value   = "";
  QString section = "medicatux products config";
  if (option == 1)
    { value = CApp::pCApp()->readUniqueParam(section, "reduct height");
      if (value.length()==0) return;
      m_pC_Frm_Prescription->setChildsSize(0,value.toInt());
      CApp::pCApp()->writeParam(section.toAscii(), "last height", value.toAscii());
    }
  else if (option == 2)
    { value = CApp::pCApp()->readUniqueParam(section, "deploy height");
      if (value.length()==0) return;
      m_pC_Frm_Prescription->setChildsSize(0,value.toInt());
      CApp::pCApp()->writeParam(section.toAscii(), "last height", value.toAscii());
    }
  else if (option == 3)
    { CApp::pCApp()->writeParam(section.toAscii(), "reduct height", QString::number(size.height()).toAscii());
    }
  else if (option == 4)
    { CApp::pCApp()->writeParam(section.toAscii(), "deploy height", QString::number(size.height()).toAscii());
    }
  else if (option == 5)
    { QString value_ald   = CApp::pCApp()->readUniqueParam(section, "background color ald");
      QString value_std   = CApp::pCApp()->readUniqueParam(section, "background color std");
      QColor      color   = QColorDialog::getColor ( QColor(value_std.remove('#').prepend('#')), this );
      if (color.isValid())
         { value_std = color.name();
           CApp::pCApp()->writeParam(section.toAscii(), "background color std", value_std.toAscii());
           m_pC_Frm_Prescription->setChildsColors(value_std, value_ald);
         }
    }
  else if (option == 6)
    { QString value_ald   = CApp::pCApp()->readUniqueParam(section, "background color ald");
      QString value_std   = CApp::pCApp()->readUniqueParam(section, "background color std");
      QColor      color   = QColorDialog::getColor ( QColor(value_ald.remove('#').prepend('#')), this );
      if (color.isValid())
         { value_ald = color.name();
           CApp::pCApp()->writeParam(section.toAscii(), "background color ald", value_ald.toAscii());
           m_pC_Frm_Prescription->setChildsColors(value_std, value_ald);
         }
    }
  else if (option == 9 )    // "9 - R\303\251initialiser la liste des m\303\251dicaments"
    { if (m_pC_BDM_Api) m_pC_BDM_Api->updateDrugLists();
      Slot_lineEdit_DrugsSearch_textChanged (""); //on remet a jour la liste
    }
  else if (option == 10 )   // "10 - R\303\251initialiser la liste des posologies favorites"
    { if (m_pC_BDM_Api) m_pC_BDM_Api->reinitHitsList();
    }
}

//------------------------------------ Slot_onQuit -------------------------------
void C_MW_Prescription::Slot_onQuit()
{   m_webView_Mono->stop();
    m_runMacroForAll = 0;
    if (m_pC_Frm_Prescription)m_pC_Frm_Prescription->Slot_close();
    if (CApp::pCApp()->u_Html()) CApp::pCApp()->u_Html()->breakHttpProcess();
    Slot_On_webView_Help_loadFinished(TRUE);
    recordPositions();
    if ( CApp::pCApp()->readUniqueParam( CApp::pCApp()->applicationName() +" session", "log_file").toLower()[0] != 'n')
        CGestIni::Param_UpdateToDisk(CApp::pCApp()->pathAppli()+"/Ressources/Log"+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz")+".html", m_pGUI->textEdit_Monitor->toHtml());
}

//------------------------------------ Slot_treeWidget_ATC_itemClicked -------------------------------
void C_MW_Prescription::Slot_treeWidget_ATC_itemClicked ( QTreeWidgetItem *pQTreeWidgetItem , int   )
{if (pQTreeWidgetItem==0) return;
 if (m_pC_BDM_Api==0)     return;
 QWidget                 *pTab_QWidget =  m_pGUI->toolBox_ListesProduits->toolWidgetByTabObjectName("page_Produits");   // zero si retire
 if ( pTab_QWidget == 0 ) return;
 m_pGUI->toolBox_ListesProduits->setCurrentWidget ( pTab_QWidget );
 int nb = m_pC_BDM_Api->selectProductsList(m_pGUI->treeWidget_Produits, pQTreeWidgetItem->text(1), C_BDM_PluginI::atc_filter , 20000 /* m_drugListMax */);
 m_pGUI->label_ListMedoc->setText(tr("%1 sur %2 produit(s)").arg(QString::number(nb),QString::number(m_pC_BDM_Api->drugsList_Size())));
}

//------------------------------------ Slot_pushButton_DefineLogin -------------------------------
void C_MW_Prescription::Slot_pushButton_DefineLogin (bool)
{
        int index =   m_pGUI->comboBox_BiblioURL->currentIndex();
        if (index==-1)           return;

        QString biblioType  = ""; // m_pGUI->comboBox_BiblioURL->itemData(index).toString();
        QString biblioUrl   = ""; // m_pGUI->comboBox_BiblioURL->itemText(index);
        QString biblioLogin = "";
        QString biblioPassw = "";
        get_BiblioType_Url_Login_Pass_FromComboBiblio(index, &biblioType, &biblioUrl, &biblioLogin, &biblioPassw);
        C_Dlg_Login *dlg    = new C_Dlg_Login(biblioLogin, biblioPassw, this);
        if (!dlg)             return;
        if (dlg->exec()==QDialog::Accepted)
           {biblioLogin = dlg->get_Login();    // dlg->get_CriptedLogin("#");
            biblioPassw = dlg->get_Password(); //.dlg->get_CriptedPassword("#");
            m_pGUI->comboBox_BiblioURL->removeItem (index );  // virer l'ancien item
            m_pGUI->comboBox_BiblioURL->insertItem(index, QIcon(CApp::pCApp()->pathTheme() + CApp::pCApp()->applicationName()+"/"+ biblioType+".png"), biblioUrl, QVariant(biblioType+"|"+biblioLogin+"|"+biblioPassw));
            m_pGUI->comboBox_BiblioURL->setCurrentIndex(index);
            comboBox_BiblioURLToIniFile();
           }
        delete dlg;
}

//------------------------------------ init_comboBox_BiblioURL -------------------------------
void C_MW_Prescription::init_comboBox_BiblioURL()
{
 QStringList lst;
 QStringList prmList;
 QString  biblioType = "";
 QString  url        = "";
 QString  login      = "";
 QString  passw      = "";
 QString  str        = "";

 CGestIni::Param_GetList( CApp::pCApp()->pathIni(), QString("prescription Biblio sites"), lst );
 for (int i=0; i<lst.count(); ++i)
     {str        = lst[i];
      prmList    = str.split(',');
      biblioType = prmList[0].remove(".png").trimmed();
      url        = prmList[1].trimmed();
      if (prmList.count()>2) {login = prmList[2].trimmed(); if (login.length() && login.at(0)=='#') login = CApp::pCApp()->criptedToUnCripted(login.mid(1));}
      if (prmList.count()>3) {passw = prmList[3].trimmed(); if (passw.length() && passw.at(0)=='#') passw = CApp::pCApp()->criptedToUnCripted(passw.mid(1));}
      m_pGUI->comboBox_BiblioURL->addItem(QIcon(CApp::pCApp()->pathTheme()+CApp::pCApp()->applicationName()+"/"+ biblioType+".png"), url, QVariant(biblioType+"|"+login+"|"+passw));
     }
 m_pGUI->comboBox_BiblioURL->setCurrentIndex(0);
}

//------------------------------------ get_BiblioType_Url_Login_Pass_FromComboBiblio -------------------------------
void C_MW_Prescription::get_BiblioType_Url_Login_Pass_FromComboBiblio(int comboIndex, QString *p_bibliotype, QString *p_url, QString *p_login,QString *p_passw)
{
  QStringList   clist  =  m_pGUI->comboBox_BiblioURL->itemData(comboIndex).toString().split('|');
  if (p_bibliotype)   *p_bibliotype = clist[0];
  if (p_url       )   *p_url        = m_pGUI->comboBox_BiblioURL->itemText(comboIndex);
  if (p_login     )   *p_login      = clist[1];    // {*p_login      = clist[1]; if (p_login->length() && p_login->at(0)=='#') *p_login = CApp::pCApp()->criptedToUnCripted(p_login->mid(1));}
  if (p_passw     )   *p_passw      = clist[2];    // {*p_passw      = clist[2]; if (p_passw->length() && p_passw->at(0)=='#') *p_passw = CApp::pCApp()->criptedToUnCripted(p_passw->mid(1));}
}

//------------------------------------ comboBox_BiblioURLToIniFile -------------------------------
void C_MW_Prescription::comboBox_BiblioURLToIniFile()
{
    CApp::pCApp()->removeSectionParam("prescription Biblio sites");

    int              nb =   m_pGUI->comboBox_BiblioURL->count();
    QString biblioType  = "";
    QString biblioUrl   = "";
    QString biblioLogin = "";
    QString biblioPassw = "";

    for (int index = 0; index < nb; ++index)
       { get_BiblioType_Url_Login_Pass_FromComboBiblio(index, &biblioType, &biblioUrl,&biblioLogin, &biblioPassw);
         CApp::pCApp()->writeParam("prescription Biblio sites",
                                    tr("site %1").arg(QString::number(index)).toAscii(),
                                    biblioType.toAscii(),
                                    biblioUrl.toLatin1(),
                                    (CApp::pCApp()->unCriptedToCripted(biblioLogin,"#")).toAscii(),
                                    (CApp::pCApp()->unCriptedToCripted(biblioPassw,"#")).toAscii());
       }
    CApp::pCApp()->updateIniParamToDisk();
}

//------------------------------------ Slot_On_pushButton_AllItems -------------------------------
void C_MW_Prescription::Slot_On_pushButton_AllItems(bool)
{QString biblioType    = "";
 QString biblioUrl     = "";
 QString biblioLogin   = "";
 QString biblioPassw   = "";
 int index             =   m_pGUI->comboBox_BiblioURL->currentIndex();
 if (index==-1)           return;
 //......... desenabler les controles ..............
 m_pGUI->treeWidget_Produits->setEnabled(FALSE);
 m_pGUI->pushButton_RetrySite->setEnabled(FALSE);
 m_pGUI->pushButton_UpdateCache->setEnabled(FALSE);
 //......... sauf celui d'arret .....................
 m_pGUI->pushButton_AllItems->setEnabled(TRUE);
 get_BiblioType_Url_Login_Pass_FromComboBiblio(index, &biblioType, &biblioUrl, &biblioLogin, &biblioPassw);
 QString lastItemFile  = CApp::pCApp()->pathAppli() + "Ressources/web/" + biblioType + "/LastItem.txt";
 int          nb_total = 0;
 int     lastItemIndex = 0;
 int     stopIndex     = 0;
 int                 i = 0;
 if (m_runMacroForAll==0)
    {
     m_runMacroForAll  = 1;
     nb_total          = m_pC_BDM_Api->selectProductsList(m_pGUI->treeWidget_Produits, "", getDrugListFilter());
     stopIndex         = nb_total;
     m_pGUI->label_ListMedoc->setText(tr("%1 sur %2 produit(s)").arg(QString::number(nb_total),QString::number(m_pC_BDM_Api->drugsList_Size())));
     QStringList  lst  = CGestIni::Param_UpdateFromDisk(lastItemFile).split('|',QString::SkipEmptyParts);
     if (lst.count()> 0) lastItemIndex     = lst[0].toInt();
     if (lst.count()> 1) stopIndex         = lst[1].toInt();
     if (lastItemIndex > 0)
        {
         if (QMessageBox::question ( this, tr("Reprendre"), tr("Reprendre au dernier index produit trait\303\251 :%1 (Confirmez) ou du d\303\251but index : 0 (Annulez)").arg(lastItemIndex),QMessageBox::Ok, QMessageBox::Cancel) != QMessageBox::Ok)
            {lastItemIndex = 0;
             // CApp::pCApp()->BDM_getDB()->biblio_DeleteRecords("", "fr",  biblioType);
            }
         if (stopIndex != nb_total)
            { if (QMessageBox::question ( this, tr("Interrompre"), tr("Interrompre au produit d'index %1 (Confirmez) ou en fin de liste (Annulez)").arg(stopIndex),QMessageBox::Ok, QMessageBox::Cancel) != QMessageBox::Ok)
                 {stopIndex = nb_total;
                 }
            }
        }
     m_pGUI->pushButton_AllItems->setIcon ( Theme::getIcon(CApp::pCApp()->applicationName()+"/loopRun.png") );
    }
 else
    {m_runMacroForAll = 0;
     C_Utils_Log::outMessage( m_pGUI->textEdit_Monitor, tr("Proc\303\251dure interrompue au dernier index en cours : %1").arg(CGestIni::Param_UpdateFromDisk(lastItemFile).toInt()));
    }

 QString    refNbTryStr = "";
 int             curTry = 1;
 int           refNbTry = 3;
 QString          state = "";
 QTreeWidgetItemIterator it (m_pGUI->treeWidget_Produits);
 while(m_runMacroForAll && *it)
    { state                              = "";
      QTreeWidgetItem * pQTreeWidgetItem = (*it);                           // nom du composant
      m_pGUI->treeWidget_Produits->setCurrentItem(pQTreeWidgetItem);
      m_pGUI->treeWidget_Produits->setItemSelected(pQTreeWidgetItem, TRUE);
      m_pGUI->treeWidget_Produits->scrollToItem(pQTreeWidgetItem);
      if (i>=lastItemIndex)
         { state       = runMacroForCurrentItem(pQTreeWidgetItem).trimmed();
           refNbTryStr = CApp::pCApp()->getVarValue("$NombreEssais").trimmed();
           if ( refNbTryStr.length()) refNbTry = refNbTryStr.toInt();
           CGestIni::Param_UpdateToDisk(lastItemFile, QString::number(i));
           C_Utils_Log::outMessage( m_pGUI->textEdit_Monitor, tr("Dernier index en cours : %1").arg(i));
           m_pQLabel->setText(tr("Trait\303\251(s) : %1 sur %2").arg(QString::number(i),QString::number(nb_total)));
         }
      if ( state.length() && ++curTry <= refNbTry)  // si  erreur on re-essaye en decrementant le nbr d'essais
         {C_Utils_Log::outMessage( m_pGUI->textEdit_Monitor, tr(".        %1eme tentative car \303\251chec de la pr\303\251c\303\251dente, index en cours : %2").arg(QString::number(curTry), QString::number(i)));
         }
      else
         {++i;
          ++it;
          if (i>=stopIndex) break;
          curTry  = 1;
         }
    }
 m_runMacroForAll = 0;
 m_pGUI->pushButton_AllItems->setIcon         ( Theme::getIcon(CApp::pCApp()->applicationName()+"/loop.png") );
 m_pGUI->pushButton_RetrySite->show();
 //......... enabler les controles ..............
 m_pGUI->treeWidget_Produits->setEnabled(TRUE);
 m_pGUI->pushButton_RetrySite->setEnabled(TRUE);
 m_pGUI->pushButton_UpdateCache->setEnabled(TRUE);
 m_pGUI->pushButton_AllItems->setEnabled(TRUE);

 m_webView_Mono->stop();
 Slot_On_webView_Help_loadFinished(TRUE);
}

//------------------------------------ runMacroForCurrentItem -------------------------------
QString C_MW_Prescription::runMacroForCurrentItem()
{   QWidget *pQWidget                   =  m_pGUI->toolBox_ListesProduits->currentWidget();
    QTreeWidgetItem *pQTreeWidgetItem   =  0;
    if (pQWidget->objectName()=="page_Produits")
       { pQTreeWidgetItem = m_pGUI->treeWidget_Produits->currentItem();
       }
    else if (pQWidget->objectName()=="page_Favoris")
       { pQTreeWidgetItem = m_pGUI->treeWidget_Favoris->currentItem();
       }
    else if (pQWidget->objectName()=="page_CustomList")
       { pQTreeWidgetItem = m_pGUI->treeWidget_CustomDrugsList->currentItem();
       }

    if (pQTreeWidgetItem==0) return"";
    return runMacroForCurrentItem(pQTreeWidgetItem);
}
//------------------------------------ runMacroForCurrentItem -------------------------------
QString C_MW_Prescription::runMacroForCurrentItem(QTreeWidgetItem *pQTreeWidgetItem)
{if (pQTreeWidgetItem==0) return QString::null;
 int index =   m_pGUI->comboBox_BiblioURL->currentIndex();
 if (index==-1)           return QString::null;
 QString biblioType  = ""; // m_pGUI->comboBox_BiblioURL->itemData(index).toString();
 QString biblioUrl   = ""; // m_pGUI->comboBox_BiblioURL->itemText(index);
 QString biblioLogin = "";
 QString biblioPassw = "";
 get_BiblioType_Url_Login_Pass_FromComboBiblio(index, &biblioType, &biblioUrl,&biblioLogin, &biblioPassw);

 QString  atc            = pQTreeWidgetItem->text(COL_ATC);
 QString  cip            = pQTreeWidgetItem->text(COL_ID);
 QString  cis            = ""; // CApp::pCApp()->BDM_getDB()->get_CIS_From_CIP(cip);           // id est CIP en attendant mieux
 QString  rcp            = ""; // CApp::pCApp()->BDM_getDB()->get_RCP_From_CIS(cis);
 if (m_pC_BDM_Api)
    {     cis            = m_pC_BDM_Api->get_CIS_and_RCP_From_CIP(cip, &rcp);
      if ( atc.length()==0 && cip.length() )
          atc            = m_pC_BDM_Api->ATC_from_CIP(cip);
    }
 QString macro           = CGestIni::Param_UpdateFromDisk(CApp::pCApp()->pathAppli() + "Ressources/web/" + biblioType + ".txt");
 QString specName        = pQTreeWidgetItem->text(COL_PROD_NAME);
 index                   = specName.indexOf("/");
 if (index==-1) index    = specName.indexOf(",");
 if (index!=-1) specName = specName.left(index);

 macro.replace("{{ATC}}",         atc);
 macro.replace("{{RCP}}",         rcp);
 macro.replace("{{CIS}}",         cis);
 macro.replace("{{CIP7}}",        cip);
 macro.replace("{{PASSWORD}}",    biblioPassw);
 macro.replace("{{LOGIN}}",       biblioLogin);
 macro.replace("{{ITEM_NAME}}",   C_Utils_Html::protectSymbolByAntiSlash(C_Utils_Html::protectSymbolByAntiSlash(C_Utils_Html::protectSymbolByAntiSlash(pQTreeWidgetItem->text(COL_PROD_NAME)),'('),')'));
 macro.replace("{{SPEC_NAME}}",   specName);
 macro.replace("{{MACRO NAME}}",  biblioType + ".txt");
 return CApp::pCApp()->run(&macro);

 //C_Utils_Log::outMessage( m_pGUI->textEdit_Monitor, test);
}

//------------------------------------ Slot_On_UpdateCache -------------------------------
void C_MW_Prescription::Slot_On_UpdateCache(bool)
{QTreeWidgetItem *pQTreeWidgetItem = m_pGUI->treeWidget_Produits->currentItem();
 if (pQTreeWidgetItem==0) return ;
 int index =   m_pGUI->comboBox_BiblioURL->currentIndex();
 if (index==-1)           return ;
 //......... desenabler les controles ..............
 m_pGUI->treeWidget_Produits->setEnabled(FALSE);
 m_pGUI->pushButton_RetrySite->setEnabled(FALSE);
 m_pGUI->pushButton_UpdateCache->setEnabled(FALSE);
 m_pGUI->pushButton_AllItems->setEnabled(FALSE);
 QString biblioType  = ""; // m_pGUI->comboBox_BiblioURL->itemData(index).toString();
 QString biblioUrl   = ""; // m_pGUI->comboBox_BiblioURL->itemText(index);
 QString biblioLogin = "";
 QString biblioPassw = "";
 get_BiblioType_Url_Login_Pass_FromComboBiblio(index, &biblioType, &biblioUrl,&biblioLogin, &biblioPassw);

 QString  atc           = pQTreeWidgetItem->text(COL_ATC);
 QString  cip           = pQTreeWidgetItem->text(COL_ID);
 QString  cis           = ""; // CApp::pCApp()->BDM_getDB()->get_CIS_From_CIP(cip);           // id est CIP en attendant mieux
 QString  rcp           = ""; // CApp::pCApp()->BDM_getDB()->get_RCP_From_CIS(cis);
 if (m_pC_BDM_Api)
    {     cis           = m_pC_BDM_Api->get_CIS_and_RCP_From_CIP(cip, &rcp);
      if ( atc.length()==0 && cip.length() )
          atc           = m_pC_BDM_Api->ATC_from_CIP(cip);
    }
 QString macroFileName  = biblioType + "_Update.txt";
 QString macro          = CGestIni::Param_UpdateFromDisk(CApp::pCApp()->pathAppli() + "Ressources/web/" + macroFileName);
 QString specName       = pQTreeWidgetItem->text(COL_PROD_NAME);
 index                  = specName.indexOf("/");
 if (index==-1) index   = specName.indexOf(",");
 if (index!=-1)specName = specName.left(index);

 if (macro.length()==0)
    {C_Utils_Log::outMessage( m_pGUI->textEdit_Monitor, tr("Macro : %1").arg(macroFileName));
    }
 else
   {
    macro.replace("{{ATC}}",         atc);
    macro.replace("{{RCP}}",         rcp);
    macro.replace("{{CIS}}",         cis);
    macro.replace("{{CIP7}}",        cip);
    macro.replace("{{PASSWORD}}",    biblioPassw);
    macro.replace("{{LOGIN}}",       biblioLogin);
    macro.replace("{{ITEM_NAME}}",   C_Utils_Html::protectSymbolByAntiSlash(C_Utils_Html::protectSymbolByAntiSlash(C_Utils_Html::protectSymbolByAntiSlash(pQTreeWidgetItem->text(COL_PROD_NAME)),'('),')'));
    macro.replace("{{MACRO NAME}}",  macroFileName);
    macro.replace("{{SPEC_NAME}}",   specName);
    /*QString ret = */ CApp::pCApp()->run(&macro);
   }
 //......... enabler les controles ..............
 m_pGUI->treeWidget_Produits->setEnabled(TRUE);
 m_pGUI->pushButton_RetrySite->setEnabled(TRUE);
 m_pGUI->pushButton_UpdateCache->setEnabled(TRUE);
 m_pGUI->pushButton_AllItems->setEnabled(TRUE);
}

//------------------------------------ Slot_On_pushButton_RetrySite -------------------------------
void C_MW_Prescription::Slot_On_pushButton_RetrySite(bool)
{   QWidget *pQWidget                   =  m_pGUI->toolBox_ListesProduits->currentWidget();
    QTreeWidgetItem *pQTreeWidgetItem   =  0;
    if (pQWidget->objectName()=="page_Produits")
       { pQTreeWidgetItem = m_pGUI->treeWidget_Produits->currentItem();
       }
    else if (pQWidget->objectName()=="page_Favoris")
       { pQTreeWidgetItem = m_pGUI->treeWidget_Favoris->currentItem();
       }
    if (pQTreeWidgetItem==0) return;
    getBiblioForItemEnCours(1, pQTreeWidgetItem);   // forcer le reload (meme si deja en base)
}


//------------------------------------ getBiblioForItemEnCours -------------------------------
void C_MW_Prescription::getBiblioForItemEnCours(bool forceCache, QTreeWidgetItem *pQTreeWidgetItem)
{
    //QTreeWidgetItem *pQTreeWidgetItem = m_pGUI->treeWidget_Produits->currentItem();
    if (pQTreeWidgetItem==0) return;
    int index =   m_pGUI->comboBox_BiblioURL->currentIndex();
    if (index==-1)          return;
    //......... desenabler les controles ..............
    m_pGUI->treeWidget_Produits->setEnabled(FALSE);
    m_pGUI->pushButton_RetrySite->setEnabled(FALSE);
    m_pGUI->pushButton_UpdateCache->setEnabled(FALSE);
    m_pGUI->pushButton_AllItems->setEnabled(FALSE);
    QString ret         = "";
    QString biblioType  = ""; // m_pGUI->comboBox_BiblioURL->itemData(index).toString();
    QString biblioUrl   = ""; // m_pGUI->comboBox_BiblioURL->itemText(index);
    QString biblioLogin = "";
    QString biblioPassw = "";
    get_BiblioType_Url_Login_Pass_FromComboBiblio(index, &biblioType, &biblioUrl,&biblioLogin, &biblioPassw);

    QString  specName        = pQTreeWidgetItem->text(COL_PROD_NAME);
    index                    = specName.indexOf("/");
    if (index==-1) index     = specName.indexOf(",");
    if (index!=-1) specName  = specName.left(index);
    QString  atc             = pQTreeWidgetItem->text(COL_ATC);
    QString  cip             = pQTreeWidgetItem->text(COL_ID);
    QString  cis             = ""; // CApp::pCApp()->BDM_getDB()->get_CIS_From_CIP(cip);           // id est CIP en attendant mieux
    QString  rcp             = ""; // CApp::pCApp()->BDM_getDB()->get_RCP_From_CIS(cis);
    if (m_pC_BDM_Api)
       {     cis             = m_pC_BDM_Api->get_CIS_and_RCP_From_CIP(cip, &rcp);
         if ( atc.length()==0 && cip.length() )
             atc             = m_pC_BDM_Api->ATC_from_CIP(cip);

       }
    biblioUrl.replace("{{ATC}}",atc);
    biblioUrl.replace("{{RCP}}",rcp);
    biblioUrl.replace("{{CIS}}",cis);
    biblioUrl.replace("{{CIP7}}",cip);
    biblioUrl.replace("{{ITEM_NAME}}",pQTreeWidgetItem->text(COL_PROD_NAME));
    biblioUrl.replace("{{SPEC_NAME}}",specName);
    //........................ chercher enregistrement biblio ..............................
    C_BiblioData cb;
    //                         pour ce type de medoc
    // cb   = CApp::pCApp()->BDM_getDB()->biblio_getDataFrom_TypeLangId(pQTreeWidgetItem->text(COL_ID), "fr", biblioType);
    if (cb.m_pk.length())                                                                                          //........... voir si  y a pas des donnees a mettre en cache .......
       { if (cb.m_data.length()==0 || forceCache)                                                                                // il ya des donnees de header (dont l'url) mais pas dans le blob
            {C_Utils_Log::outMessage( m_pGUI->textEdit_Monitor, tr(" Head found but data not Found in database :id=%1 lang=%2 biblioType=%3 %1").arg(pQTreeWidgetItem->text(COL_ID),"fr",biblioType));
             ret = runMacroForCurrentItem();
            }
        else  // ......... on prend le contenu du cache ..............................
            { QString baseUrl = CApp::pCApp()->pathAppli() + "Ressources/web/"+biblioType+"/";
              baseUrl = baseUrl.prepend("file:");
              m_webView_Mono->setHtml(cb.m_data, QUrl(baseUrl));
              // CGestIni::Param_UpdateToDisk("/home/ro/html.html", cb.m_data);
              m_pGUI->lineEdit_url->setText(cb.m_url);
              C_Utils_Log::outMessage( m_pGUI->textEdit_Monitor, tr(" Find in database :id=%1 lang=%2 biblioType=%3 %1").arg(pQTreeWidgetItem->text(COL_ID),"fr",biblioType));
              //......... enabler les controles ..............
              m_pGUI->treeWidget_Produits->setEnabled(TRUE);
              m_pGUI->pushButton_RetrySite->setEnabled(TRUE);
              m_pGUI->pushButton_UpdateCache->setEnabled(TRUE);
              m_pGUI->pushButton_AllItems->setEnabled(TRUE);
              return;
            }
       }
    //....................... pas de biblio pour ce topic ...................................
    //                        faut le creer
    else
      { C_Utils_Log::outMessage( m_pGUI->textEdit_Monitor, tr(" Nothing Found in database :id=%1 lang=%2 biblioType=%3 %1").arg(pQTreeWidgetItem->text(COL_ID),"fr",biblioType));
        ret = runMacroForCurrentItem();
      }
    C_Utils_Log::outMessage( m_pGUI->textEdit_Monitor, tr("Retour : %1").arg(ret));
    m_pGUI->lineEdit_url->setText(biblioUrl);
    //......... enabler les controles ..............
    m_pGUI->treeWidget_Produits->setEnabled(TRUE);
    m_pGUI->pushButton_RetrySite->setEnabled(TRUE);
    m_pGUI->pushButton_UpdateCache->setEnabled(TRUE);
    m_pGUI->pushButton_AllItems->setEnabled(TRUE);
}

//------------------------------------ fill_treeWidget_Favoris --------------------------------------------------
int C_MW_Prescription::fill_treeWidget_Favoris(const QString &text /*=""*/)
{    QList < C_BDM_DrugListRecord >  drugsList;
     if (m_pC_BDM_Api==0)      return 0;
     m_pGUI->treeWidget_Favoris->clear();
     drugsList =  m_pC_BDM_Api->selectFavorisList (text, C_BDM_PluginI::cip_filter ,10000);  // au delas de 10000 on ne peut plus appeler
     fill_treeWidget_ProductsFromDrugList(m_pGUI->treeWidget_Favoris, drugsList);
    return m_pGUI->treeWidget_Favoris->topLevelItemCount();
}

//------------------------ Slot_FavorisAdded ---------------------------------------------------------------------------------------
// ACTION :      // mettre a jour la liste des favoris
void C_MW_Prescription::Slot_FavorisAdded(C_Frm_Produit *)
{        fill_treeWidget_Favoris();
}
//------------------------------------ Slot_checkBox_DrugList_filter_stateChanged --------------------------------------------------
void C_MW_Prescription::Slot_checkBox_DrugList_filter_stateChanged(const QString &mappedText)
{
    QCheckBox *pQCheckBox = qobject_cast<QCheckBox *>(m_DrugListFilter_SignalMapper->mapping (mappedText ));
    if (pQCheckBox->isChecked()) CApp::pCApp()->writeParam("medicatux filter",mappedText.toAscii(),tr("actif").toAscii() );
    else                         CApp::pCApp()->writeParam("medicatux filter",mappedText.toAscii(),tr("non actif").toAscii() );
    initDrugListFilter();
    Slot_lineEdit_DrugsSearch_textChanged (m_pGUI->lineEdit_DrugsSearch->text()); //on remet a jour la liste
}

//------------------------------------ Slot_ProductNumberClicked --------------------------------------------------
void C_MW_Prescription::Slot_ProductNumberClicked(C_Frm_Produit *pC_Frm_Produit)
{show_ProductMonographie(*pC_Frm_Produit);
}
//------------------------------------ show_ProductMonographie --------------------------------------------------
void C_MW_Prescription::show_ProductMonographie(const C_BDM_DrugListRecord & drugListRecord)
{
 QWidget                 *pTab_QWidget = m_pGUI->tabWidget_HAS_Infos->tabWidgetByTabObjectName("tab_Monographie");      // zero si retire
 if ( pTab_QWidget == 0 ) pTab_QWidget = m_pGUI->tabWidget_HAS_Infos->activeTabWidgetByObjectName("tab_Monographie");   // aller chercher dans la liste des retires
 if ( pTab_QWidget == 0 ) return;
 m_pGUI->tabWidget_HAS_Infos->setCurrentWidget ( pTab_QWidget );
 int      i           = 0;
 QString id           = drugListRecord.id();
 QTime tm_deb         = QTime::currentTime();
 QString html         = m_pC_BDM_Api->getMonographieFromCIP(id);                      // recuperer monographie standard de la bdm medicamenteuse
 C_Utils_Log::outMessage( m_pGUI->textEdit_Monitor, tr(" Time to get BDM    Monographie of %1 = %2").arg(id,  QTime (0, 0, 0, 0 ).addMSecs(tm_deb.msecsTo(QTime::currentTime())).toString("mm:ss:zzz") ));
 QTime tm_tmp         = QTime::currentTime();
 QStringList htmlList = m_pC_BDM_Api-> selectCustomMonographie(drugListRecord);       // recuperer la liste des notes personnelles
 bool  noLast_hr_tag  = html.length()==0 || htmlList.size()==0;                       // flag d'ajout du tag <hr/>
 //.......... inserer les liens des pages custom ...............................
 QString link_str     = "";  // liens crees sur les notes personnelles
 QString part_str     = "";  // texte correspondant a une note
 QString cible        = "";  // texte correspondant la cible d'une note
 int      pos_deb     = -1;
 int      pos_end     = -1;

 if (htmlList.size())           // on parse toutes les notes pour en extraire les infos pour creer les liens
    {
     // html  +=  "<hr/><p align=\"center\"><font color=#0000ff><b>NOTES COMPL&#201;MENTAIRES PERSONNELLES</b></font></p>";
     for (i=0; i<htmlList.size(); ++i)    // on merge toutes les notes recuperees par la requete SQL en installant les liens adequats
         { part_str = htmlList.at(i);                            // recuperer la liste des notes
           pos_deb  = part_str.indexOf("<a name=\"ancre_id_[");
           if ( pos_deb != -1 )
              { pos_deb += 19;
                pos_end  = part_str.indexOf("]_\"></a><br />",pos_deb);
              }
           if ( pos_end != -1 )
              { cible     = part_str.mid(pos_deb, pos_end-pos_deb);
                link_str += "&nbsp;&nbsp;&nbsp;" // ATTENTION en 4.8.5 conversion possible des majuscules en minuscules ==> nom des ancres toujours en minuscules
                            "&nbsp;&nbsp;<a href=\"modify:#ancre_id_[" + cible + "]_\"><img src=\"./EditPicto.png\"> modifier</a>"   +  // ce lien sera a interpreter dans URL_ExecSpecialSyntax
                            "&nbsp;&nbsp;<a href=\"remove:#ancre_id_[" + cible + "]_\"><img src=\"./RemovePicto.png\"> effacer</a>"  +  // ce lien sera a interpreter dans URL_ExecSpecialSyntax
                            "&nbsp;&nbsp;<a href=\"#ancre_id_["        + cible + "]_\"><img src=\"./NotePicto.png\"> voir la note : <font size=2px color=#ff0000>" + CGestIni::CutStrRight( cible,"-" ) + "</font></a>"+ // ce lien est actif
                            "<br />";    // lien sur la cible, le du lien texte est coupe apres les informations du pk
                html     +=  part_str + "<br />"; // joindre la note a la page
              }
         }
    }
 html  = "<a name=\"monographie_start\"></a>"             // placer lancre de debut de page
         "<hr/><p align=\"center\"><font color=#0000ff><b>NOTES COMPL&#201;MENTAIRES PERSONNELLES</b></font>&nbsp;&nbsp;"
         "<a href=\"new:#ancre_id_[note]_\"><img src=\"./NewNotePicto.png\"> ajouter</a></p><hr/>" + link_str + (noLast_hr_tag?"":"<hr/>") + html;  // on place les liens au debut de page puis la monographie standard suivieie des notes
 C_Utils_Log::outMessage( m_pGUI->textEdit_Monitor, tr(" Time to get CUSTOM Monographie of %1 = %2").arg(id,  QTime (0, 0, 0, 0 ).addMSecs(tm_tmp.msecsTo(QTime::currentTime())).toString("mm:ss:zzz") ));
 C_Utils_Log::outMessage( m_pGUI->textEdit_Monitor, tr(" Time to get TOTAL  Monographie of %1 = %2").arg(id,  QTime (0, 0, 0, 0 ).addMSecs(tm_deb.msecsTo(QTime::currentTime())).toString("mm:ss:zzz") ));
 m_webView_Info->setHtml(html, QUrl::fromLocalFile(m_pC_BDM_Api->plugin_image_source() ));
 m_last_drugListRecord = drugListRecord;
}

//------------------------------------ initDrugListFilter --------------------------------------------------
void C_MW_Prescription::initDrugListFilter()
{   if (m_pC_BDM_Api==0) return;
    int flags = C_BDM_Api::no_filter;
    if (m_pGUI->checkBox_Atc_filter->isChecked()) flags |= C_BDM_Api::atc_filter;
    if (m_pGUI->checkBox_Nom_filter->isChecked()) flags |= C_BDM_Api::nom_filter;
    if (m_pGUI->checkBox_Ucd_filter->isChecked()) flags |= C_BDM_Api::ucd_filter;
    if (m_pGUI->checkBox_Dci_filter->isChecked()) flags |= C_BDM_Api::dci_filter;
    if (m_pGUI->checkBox_Dc3_filter->isChecked()) flags |= C_BDM_Api::dc3_filter;
    if (m_pGUI->checkBox_Cip_filter->isChecked()) flags |= C_BDM_Api::cip_filter;
    if (m_pGUI->checkBox_Gen_filter->isChecked()) flags |= C_BDM_Api::gen_filter;
    if (m_pGUI->checkBox_Hop_filter->isChecked()) flags |= C_BDM_Api::hop_filter;
    if (m_pGUI->checkBox_Vil_filter->isChecked()) flags |= C_BDM_Api::vil_filter;
    if (!flags) flags |= C_BDM_Api::nom_filter;
    setDrugListFilter( (C_BDM_PluginI::flags)flags );
}
//-------------------------------- setDrugListFilter ------------------------------------------------------
void  C_MW_Prescription::setDrugListFilter(C_BDM_PluginI::flags flags)
{m_drugListFilter = flags;
}
//-------------------------------- getDrugListFilter ------------------------------------------------------
C_BDM_PluginI::flags C_MW_Prescription::getDrugListFilter()
{ return m_drugListFilter;
}
//------------------------------------ Slot_lineEdit_DrugsSearch_textChanged -------------------------------
void C_MW_Prescription::Slot_lineEdit_DrugsSearch_textChanged (const QString &text)
{if (m_pC_BDM_Api==0) return;
 int nb = m_pC_BDM_Api->selectProductsList(m_pGUI->treeWidget_Produits, text, getDrugListFilter(),m_drugListMax);
 m_pGUI->label_ListMedoc->setText(tr("%1 sur %2 produit(s)").arg(QString::number(nb),QString::number(m_pC_BDM_Api->drugsList_Size())));
}

//------------------------------------ Slot_m_action_Deplie -------------------------------
void C_MW_Prescription::Slot_m_action_Deplie (bool)
{expand_QTreeWidget_GUI ( TRUE );
}

//------------------------------------ Slot_m_action_Replie -------------------------------
void C_MW_Prescription::Slot_m_action_Replie (bool)
{  expand_QTreeWidget_GUI ( FALSE );
}
//------------------------------------ expand_QTreeWidget_GUI -------------------------------
void C_MW_Prescription::expand_QTreeWidget_GUI ( bool state)
{   expand_QTreeWidget(m_pGUI->treeWidget_ATC,state);
}
//------------------------------------ expand_QTreeWidget -------------------------------
void C_MW_Prescription::expand_QTreeWidget( QTreeWidget *pQTreeWidget, bool state)
{  QTreeWidgetItemIterator it(pQTreeWidget);
    while (*it)
     { (*it)->setExpanded(state);
       ++it;
     }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////// WEB VIEW ///////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//--------------------------------- Slot_webView_linkClicked -----------------------------------------------------------------------
void C_MW_Prescription::Slot_webView_linkClicked ( const QUrl & url )
{if (URL_ExecSpecialSyntax ( url.toString().trimmed() ,CApp::pCApp()->pathAppli())) return;
 m_webView_Mono->load (url );
}
/*
//--------------------------------- Slot_webView_Info_urlChanged -----------------------------------------------------------------------
void C_MW_Prescription::Slot_webView_Info_urlChanged( const QUrl & url )
{// m_webView_Info->load (url );
}
*/
//--------------------------------- Slot_webView_Info_linkClicked -----------------------------------------------------------------------
void C_MW_Prescription::Slot_webView_Info_linkClicked( const QUrl & url )
{ QString urlText = url.toString();
 if (URL_ExecSpecialSyntax (urlText.trimmed() ,CApp::pCApp()->pathAppli())) return;
 //qDebug()<<urlText;
 int pos = 0;
 if ( ( pos=urlText.indexOf("Drug_CIP=") ) != -1)
    {int nb = m_pC_BDM_Api->selectProductsList(m_pGUI->treeWidget_Produits, urlText.mid(pos+9), getDrugListFilter());
     m_pGUI->label_ListMedoc->setText(tr("%1 sur %2 produit(s)").arg(QString::number(nb),QString::number(m_pC_BDM_Api->drugsList_Size())));
    }
 m_webView_Info->load (url );
}

//--------------------------------- Slot_On_webView_Help_statusBarMessage -----------------------------------------------------------------------
void C_MW_Prescription::Slot_On_webView_Help_statusBarMessage (const QString &text)
{m_pQLabel->setText(text);
}

//--------------------------------- Slot_On_webView_Help_loadStarted -----------------------------------------------------------------------
void C_MW_Prescription::Slot_On_webView_Help_loadStarted()
{m_pQProgressBar->setValue(0);
 m_pQProgressBar->show();
 m_pQLabel->show();
}

//--------------------------------- Slot_On_webView_Help_loadProgress -----------------------------------------------------------------------
void C_MW_Prescription::Slot_On_webView_Help_loadProgress(int progress)
{m_pQProgressBar->setValue(progress);
 m_pGUI->pushButton_Stop->setEnabled(TRUE);
 m_pQProgressBar->show();
 m_pQLabel->show();
}

//--------------------------------- Slot_On_webView_Help_loadFinished -----------------------------------------------------------------------
void C_MW_Prescription::Slot_On_webView_Help_loadFinished(bool )
{//m_pQProgressBar->hide();
 //m_pQLabel->hide();
 m_pGUI->pushButton_Stop->setEnabled(FALSE);
 CApp::pCApp()->setEndPageDisplay(TRUE);
}

//--------------------------------- Slot_LocationEdit_returnPressed -----------------------------------------------------------------------
void C_MW_Prescription::Slot_LocationEdit_returnPressed()
{   QUrl url = QUrl(m_pGUI->lineEdit_url->text());
    m_webView_Mono->setUrl (QUrl(url));
}
//--------------------------------- Slot_WebFindEdit_returnPressed -----------------------------------------------------------------------
void C_MW_Prescription::Slot_WebFindEdit_returnPressed()
{Slot_actionWebFind (true);
}

//--------------------------------- Slot_WebFindEdit_textChanged -----------------------------------------------------------------------
void C_MW_Prescription::Slot_WebFindEdit_textChanged (const QString &text )
{m_webView_Mono->findText ("",   QWebPage::HighlightAllOccurrences );  // clear the selection
 m_webView_Mono->findText (text, QWebPage::HighlightAllOccurrences );
}

//--------------------------------- Slot_actionWebFind -----------------------------------------------------------------------
void C_MW_Prescription::Slot_actionWebFind (bool)
{m_webView_Mono->findText (m_pGUI->lineEdit_find->text(), QWebPage::FindWrapsAroundDocument );
}
//--------------------------------- Slot_actionWebPrint -----------------------------------------------------------------------
void C_MW_Prescription::Slot_actionWebPrint (bool)
{
 #ifndef QT_NO_PRINTER
     QPrinter printer(QPrinter::HighResolution);
     QPrintDialog *printDialog = new QPrintDialog(&printer, this);
     if (printDialog->exec() == QDialog::Accepted)
        {     m_webView_Mono->print ( &printer );
        }
 #endif // QT_NO_PRINTER
}

//--------------------------------- Slot_actionWebHome -----------------------------------------------------------------------
void C_MW_Prescription::Slot_actionWebHome (bool)
{m_webView_Mono->setUrl (QUrl(m_PathPageHelp));
}

//--------------------------------- Slot_webView_urlChanged -----------------------------------------------------------------------
void C_MW_Prescription::Slot_webView_urlChanged ( const QUrl &url  )
{m_pGUI->lineEdit_url->setText(url.toString());
}
