#ifndef C_MW_PRESCRIPTION_H
#define C_MW_PRESCRIPTION_H
#include <QtPlugin>
#include <QDebug>
#include <qglobal.h>
#include <QProcess>
#include <QItemDelegate>
#include <QStyledItemDelegate>

//#include <extensionsystem/pluginmanager.h>
//#include <extensionsystem/pluginspec.h>
//#include <extensionsystem/iplugin.h>
#include <QMainWindow>
#include "../../MedinTuxTools-QT4/C_Utils_Html.h"
#include "../../MedinTuxTools-QT4/C_QWebView/C_QWebView.h"
#include "../../MedinTuxTools-QT4/medicabase/C_BDM_Api.h"

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

namespace Ui {
    class MainWindow;
    class QMenuBar;
    class QToolBar;
    class QAction;
}
    class QTreeWidget;
    class QUrl;
    class QTreeWidgetItem;
    class CookieJar;
    class QNetworkDiskCache;
    class QProgressBar;
    class QLabel;
    class QWebView;
    class QSignalMapper;
    class C_PatientBase;
    class C_PatientCtx;
    class C_UserCtx;
    class C_Frm_Prescription;
    class C_Frm_Produit;
    class QToolBox;
    class C_PopupDial_NotesInfos;
    class C_PopupDial;
    class CMyColorButton;
    class C_DragQTreeWidget;
//==================================  C_MW_Prescription ============================================================
class C_MW_Prescription : public QMainWindow
{
    Q_OBJECT

public:
    explicit C_MW_Prescription(QWidget *parent = 0);
    ~C_MW_Prescription();
private:
    QString      prescriptionToXML(C_Frm_Prescription *m_pC_Frm_Prescription);
    QStringList  getInputGrammarList();
    void recordPositions();
    void setMainTabWidgetConfig();
    void writeMainTabWidgetConfig();
    void setPositionsFromIniFile();
    QFont setFontFromIniFile();
    void expand_QTreeWidget_GUI ( bool state);
    void expand_QTreeWidget( QTreeWidget *pQTreeWidget, bool state);
    void init_comboBox_BiblioURL();
    void getBiblioForItemEnCours(bool forceCache,QTreeWidgetItem *pQTreeWidgetItem);
    void get_BiblioType_Url_Login_Pass_FromComboBiblio(int comboIndex, QString *p_bibliotype, QString *p_url,QString *p_login=0,QString *p_pass=0);
    void comboBox_BiblioURLToIniFile();
    void initDrugListFilter();
    int  URL_ExecSpecialSyntax ( QString urlStr , const QString &pathAppli);      // WEB VIEW
    bool event ( QEvent * e );
    QTreeWidgetItem *getSelectedListViewItem(QTreeWidget *pQTreeWidget);
    QTreeWidget     *currrentProductListTreeWidget();
    void userCtxToInterface(C_UserCtx *pC_UserCtx);
    void patientCtxToInterface(C_PatientCtx *pC_PatientCtx);
    void setWindowTitle();
    int      fill_treeWidget_Favoris(const QString &text ="");
    void     fillTreeWidgetIndications(const QString &cip);
    void     fillTreeWidgetIndicationsFromPatientContext();
    void     fillTreeWidgetComposition(const QString &cip);
    void     fill_treeWidget_Historique();
    void     fillCustomDrugListCombo(const QString &user);
    int      fill_treeWidget_ProductsFromDrugList(QTreeWidget *pQTreeWidget, const QList < C_BDM_DrugListRecord >  &drugsList, QList < QTreeWidgetItem* >  *pItemsList  = 0 );
    void     fill_only_showed_treeWidgets(const QString &objName);
    void     setListATC_onCode ( const QString &atc );
    int      add_Product_to_CustomProductsList(const QString &userName, const QString &listName, QList < C_BDM_DrugListRecord > &drugsList);
    void     drugsList_ContextMenuRequested( QTreeWidget *pQTreeWidget );
    void     treeWidget_Produits_itemDoubleClicked (   QTreeWidgetItem *pQTreeWidgetItem , int  );
    void     treeWidget_Produits_itemClicked (         QTreeWidgetItem * pQTreeWidgetItem, int  c  );
    void     giveDragtreeWidget_CustomDrugsListItem_List_Data(QString &dataXML, QTreeWidget *pQTreeWidget);
    // void     giveDragtreeWidget_CustomDrugsListItemData(QString &data, QTreeWidget *pQTreeWidget);

    void     lineEdit_searchProducts_keyPressEvent(QTreeWidget *pQTreeWidget, QKeyEvent *event, int &callStandardEvent);
    bool     can_use_API( QTreeWidgetItem * pQTreeWidgetItem );
    int      getCustomMonographiePropertys ( QString &title , QString &author, QDateTime &date_time, QString &text);
    void                           exportDrugsList(QTreeWidget *pQTreeWidget, bool selectMode  = 0);
    int                            importDrugsList(QTreeWidget *pQTreeWidget, bool clearList   = 0);
    QList < C_BDM_DrugListRecord > makeDrugsListRecords_From_QTreeWidgetProducts(QTreeWidget *pQTreeWidget, int selectMode  = 0);
    C_BDM_DrugListRecord           C_BDM_DrugListRecord_From_QTreeWidgetProductsItem (QTreeWidgetItem  *pQTreeWidgetItem);

    int      Datasemp_fill_treeWidget_Accessoires(QTreeWidget *pQTreeWidget, int familleIndex, const QString &text  = "" );

    void     setCustomDrugListComboOn_ListName(const QString &userName, const QString &listName);
    void     changeCurrentCustomList(const QString &userName, const QString &listName);
    // QWidget *activeTabWidgetByObjectName (QTabWidget * pQTabWidget, const QString & widget_page_object_name, QMap<QString,  QWidget *> &removedObject); // ici la clef est le titre du tab (on recherche l'objet par son titre dans un menu)

    // QWidget *toolWidgetByTabObjectName(QToolBox* pQTabWidget, const QString &name, int *index  = 0 );
    // int      toolWidgetIndexByTabObjectName(QToolBox* pQTabWidget, const QString &name);
    //QWidget *tabWidgetByTabObjectName(QTabWidget* pQTabWidget, const QString &name);
    //int      tabWidgetIndexByTabObjectName(QTabWidget* pQTabWidget, const QString &name);
    //QWidget *tabWidgetByTabText(QTabWidget* pQTabWidget, const QString &text, int *index = 0);
    void     save_treeWidgetState    (const QString &sufix, QTreeWidget *pQTreeWidget);
    void     restore_treeWidgetState (const QString &sufix, QTreeWidget *pQTreeWidget);
    void     show_ProductMonographie (const C_BDM_DrugListRecord & drugListRecord);
    void     display_HAS_Status();

    QString  ordoToHtml(const QString &mask = "");
    //------------------------ setDrugListFilter -----------------------------------------
    /*! \brief set the drug filter
     */
    void              setDrugListFilter(C_BDM_PluginI::flags flags);

    //------------------------ getDrugListFilter -----------------------------------------
    /*! \brief get the drug filter
     */
    C_BDM_PluginI::flags  getDrugListFilter();

    //-------------------------------- set_BDM_Plugin ------------------------------------------------------
    /*! \brief connect API to source datas via C_BDM_InitPluginI interface which provides data to  C_BDM_Api
     *  \param QString namePlugin of C_BDM_InitPluginI data source ( 'theriaque' 'datasemp')
     *  \return C_BDM_PluginI * pointer on plugin or zero if error
     */
    C_BDM_PluginI *set_BDM_Plugin(const QString &_namePlugin);   // theriaque datasemp

    //................... methodees ................
    QString runMacroForCurrentItem();
    QString runMacroForCurrentItem(QTreeWidgetItem *pQTreeWidgetItem);
    int     add_C_Frm_Prescription(const QFont &fnt, const QStringList &grammarList = QStringList());
    //................... data .....................
    C_PatientBase          *m_pC_PatientBase;
    C_PatientCtx           *m_pC_PatientCtx;
    C_UserCtx              *m_pC_UserCtx;
    C_BDM_Api              *m_pC_BDM_Api;

    C_BDM_PluginI::flags    m_drugListFilter;
    int                     m_drugListMax;

    C_Frm_Prescription     *m_pC_Frm_Prescription;
    C_PopupDial_NotesInfos *m_pC_PopupDial_NotesInfos;
    QMenu                  *m_prescription_zoom_menu;
    QProgressBar           *m_pQProgressBar;
    QLabel                 *m_pQLabel;
    QSignalMapper          *m_DrugListFilter_SignalMapper;
    QString                 m_lastExportPath;
    QString                 m_lastMonographiePath;
    Ui::MainWindow         *m_pGUI;
    /*
    QMenuBar           *m_menuBar;
    QToolBar           *m_ToolBar;
    QAction            *m_action_Configure;
    QAction            *m_action_ConfigureBase;
    QAction            *m_action_Deplie;
    QAction            *m_action_Replie;
    QAction            *m_action_Test;
    QAction            *m_action_MakeBase;
    QAction            *m_action_MakeBaseGet;
    QAction            *m_action_TestPlug;
    QAction            *m_action_APropos;
    */
    int                 m_runMacroForAll;
    QString             m_PathPageHelp;                                            // WEB VIEW
    CookieJar           *m_pCookieJar;                                              // WEB VIEW
    QNetworkDiskCache   *m_diskCache;                                               // WEB VIEW
    C_QWebView          *m_webView_Mono;                                            // WEB VIEW
    C_QWebView          *m_webView_Info;
    QProcess            *m_Apropos_Proc;
    C_BDM_DrugListRecord m_last_drugListRecord;
    CMyColorButton      *m_Button_TabCorner;

public slots:
    void Slot_onQuit();

private slots:
    //..................... le bandeau de prescription ..........................................
    void Slot_m_action_APropos ();
    void Slot_toolButton_zoomUpReleased();
    void Slot_toolButton_zoomDwReleased();
    void Slot_prescription_zoom_menu_triggered ( QAction* pQAction);

    void Slot_toolButton_tout_Ald_clicked ( bool );
    void Slot_toolButton_non_Ald_clicked ( bool );
    void Slot_toolButton_erase_All_clicked ( bool );
    void Slot_toolButton_Annuler_clicked ( bool );
    void Slot_toolButton_Ok_clicked ( bool );
    void Slot_toolButton_Duration_clicked( bool );
    //........ la list view des favoris ............................................
    void Slot_keyPressEvent_TreeWidgetProducts(QKeyEvent *, int &, C_DragQTreeWidget*);
    void Slot_lineEdit_lineEdit_FavorisSearch_textChanged (const QString &);
    void Slot_lineEdit_lineEdit_FavorisSearch_keyPressEvent(QKeyEvent *, int &);

    //------------------------------------ Slot_giveDragtreeWidget_ProduitsItemListData -------------------------------
    void Slot_giveDragtreeWidget_ProduitsItem_List_Data(QString &data, QTreeWidgetItem *);
    void Slot_giveDragtreeWidget_FavorisItem_List_Data   (QString &data, QTreeWidgetItem * );
    void Slot_giveDragtreeWidget_CustomDrugsListItem_List_Data(QString &data, QTreeWidgetItem *);
    void Slot_giveDragtreeWidget_AccessoiresItem_List_Data(QString &data, QTreeWidgetItem *);
    void Slot_giveDragtreeWidget_PatientDrugsItem_List_Data(QString &data, QTreeWidgetItem *);

    void Slot_toolBox_classifications_currentChanged(int index);
    void Slot_toolBox_ListesProduits_currentChanged(int index);

    void Slot_tabWidget_Main_currentChanged( int index);
    // void Slot_tabWidget_Main_CloseRequested( int index);
    void Slot_m_Button_TabCorner_clicked(bool);

    void Slot_comboBox_FamillesProduits_activated( int );
    void Slot_webView_Mono_linkClicked ( const QUrl & url );

    void Slot_pushButton_pushButton_CustomListMenu(bool);
    void Slot_pushButton_addCustomList(bool);
    void Slot_pushButton_delCustomList(bool);
    void Slot_comboBox_customList_activated( const QString &);
    void Slot_pushButton_exportCustomList(bool);
    void Slot_pushButton_importCustomList(bool);
    void Slot_lineEdit_CustomSearch_textChanged (const QString &);
    void Slot_lineEdit_CustomSearch_keyPressEvent(QKeyEvent *, int &);

    void Slot_On_pushButton_PosoEditorFontChoice(bool);
    void Slot_On_pushButton_GeneralFontChoice(bool);

    void Slot_ProductNumberClicked( C_Frm_Produit *pC_Frm_Produit );
    void Slot_FavorisAdded(C_Frm_Produit *pC_Frm_Produit);
    void Slot_retranslateUi();
    void Slot_add_product_In_C_Frm_Prescription(QTreeWidgetItem * pQTreeWidgetItem);
    void Slot_PrescriptionWantGeometry(QRect &application_rect, QRect &wdg_rect);

    void Slot_lineEdit_DrugsSearch_textChanged (const QString &);
    //....... les listes de produits .................................
    void Slot_treeWidget_Produits_itemClicked       ( QTreeWidgetItem *pQTreeWidgetItem , int c  );
    void Slot_treeWidget_Produits_itemDoubleClicked ( QTreeWidgetItem *pQTreeWidgetItem , int c  );
    // void Slot_giveDragtreeWidget_ProduitsItemData   ( QString &, QTreeWidgetItem* );
    void Slot_Widget_Produits_ContextMenuRequested(QPoint);

    void Slot_treeWidget_Favoris_itemClicked       ( QTreeWidgetItem *pQTreeWidgetItem , int c  );
    void Slot_treeWidget_Favoris_itemDoubleClicked ( QTreeWidgetItem *pQTreeWidgetItem , int c  );
    // void Slot_giveDragtreeWidget_FavorisItemData   ( QString &, QTreeWidgetItem* );
    void Slot_Widget_treeWidget_Favoris_ContextMenuRequested(QPoint);

    void Slot_treeWidget_CustomDrugsList_itemClicked ( QTreeWidgetItem * , int   );
    void Slot_treeWidget_CustomDrugsList_itemDoubleClicked ( QTreeWidgetItem * , int   );
    // void Slot_giveDragtreeWidget_CustomDrugsListItemData(QString &, QTreeWidgetItem*);
    void Slot_Widget_treeWidget_CustomDrugsList_ContextMenuRequested(QPoint);

    void Slot_treeWidget_Accessoires_itemClicked ( QTreeWidgetItem * , int   );
    void Slot_treeWidget_Accessoires_itemDoubleClicked ( QTreeWidgetItem * , int   );
    // void Slot_giveDragtreeWidget_AccessoiresItemData(QString &, QTreeWidgetItem*);
    void Slot_treeWidget_Accessoires_ContextMenuRequested(QPoint);

    void Slot_treeWidget_PatientDrugs_itemClicked ( QTreeWidgetItem * , int   );
    void Slot_treeWidget_PatientDrugs_itemDoubleClicked ( QTreeWidgetItem * , int   );
    // void Slot_giveDragtreeWidget_PatientDrugsItemData(QString &, QTreeWidgetItem*);
    void Slot_treeWidget_PatientDrugs_ContextMenuRequested(QPoint);


    void Slot_lineEdit_AccessoiresSearch_keyPressEvent(QKeyEvent *, int &);
    void Slot_lineEdit_AccessoiresSearch_textChanged (const QString &);

    void Slot_treeWidget_Indications_itemClicked ( QTreeWidgetItem *pQTreeWidgetItem , int   );
    void Slot_treeWidget_Composition_itemClicked ( QTreeWidgetItem *pQTreeWidgetItem , int   );

    void Slot_lineEditAutoLocator_keyPressEvent(QKeyEvent *, int &);
    void Slot_treeWidget_ATC_itemClicked ( QTreeWidgetItem * , int   );
    // void Slot_m_action_Test (bool);
    // void Slot_m_action_Configure (bool);
    // void Slot_m_action_ConfigureBase (bool);
    void Slot_m_action_Deplie (bool);
    void Slot_m_action_Replie (bool);
    // void Slot_m_action_MakeBase (bool);
    // void Slot_m_action_MakeBaseGet (bool);
    // void Slot_m_action_TestPlug (bool);

    void Slot_child_LeaveLastEditZone();
    void Slot_checkBox_DrugList_filter_stateChanged(const QString &);

    void Slot_pushButton_DefineLogin (bool);
    void Slot_On_pushButton_RetrySite(bool);
    void Slot_On_UpdateCache(bool);
    void Slot_On_pushButton_AllItems(bool);

    void Slot_On_webView_Help_statusBarMessage (const QString &text);    // WEB VIEW
    void Slot_On_webView_Help_loadStarted();                             // WEB VIEW
    void Slot_On_webView_Help_loadProgress(int progress);                // WEB VIEW
    void Slot_On_webView_Help_loadFinished(bool ok);                     // WEB VIEW
    void Slot_LocationEdit_returnPressed();                              // WEB VIEW
    void Slot_WebFindEdit_returnPressed();                               // WEB VIEW
    void Slot_WebFindEdit_textChanged (const QString &text );            // WEB VIEW
    void Slot_actionWebFind (bool);                                      // WEB VIEW
    void Slot_actionWebPrint (bool);                                     // WEB VIEW
    void Slot_actionWebHome (bool);                                      // WEB VIEW
    void Slot_webView_urlChanged ( const QUrl &url  );                   // WEB VIEW
    void Slot_webView_linkClicked ( const QUrl & url );                  // WEB VIEW
    // void Slot_webView_Info_urlChanged( const QUrl & url );
    void Slot_webView_Info_linkClicked( const QUrl & url );
    void Slot_On_comboBox_choixBase(const QString &namePlugin);
    void Slot_Apropos_Proc_finished (int,  QProcess::ExitStatus);
};

#endif // C_MW_PRESCRIPTION_H
