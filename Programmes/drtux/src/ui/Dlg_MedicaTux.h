/****************************************************************************
** Form interface generated from reading ui file 'Dlg_MedicaTux.ui'
**
** Created: mer. mai 4 22:17:02 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLG_MEDICATUX_H
#define DLG_MEDICATUX_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qdialog.h>
#include <qapplication.h>
#include <qpopupmenu.h>
#include <qcursor.h>
#include "Global.h"
#include "../../MedinTuxTools/CMedicaBase.h"

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class CMaskedLineEdit;
class QProgressBar;
class QSplitter;
class QLabel;
class QPushButton;
class QCheckBox;
class QComboBox;
class QTabWidget;
class QWidget;
class QWidgetStack;
class QListView;
class QListViewItem;
class QLineEdit;
class QTextBrowser;

class Dlg_MedicaTux : public QDialog
{
    Q_OBJECT

public:
    Dlg_MedicaTux( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~Dlg_MedicaTux();

    QProgressBar* progressBar_EDMed;
    QSplitter* splitter3;
    QLabel* textLabel_CIP_Find;
    CMaskedLineEdit* lineEdit_EdMed__CIP_Find;
    QPushButton* pushButton_CIP_Find;
    QCheckBox* checkBox_Dispo;
    QCheckBox* checkBox_Generiques;
    QPushButton* pushButtonDown;
    QPushButton* pushButtonDownProd;
    QComboBox* comboBox_Specialites;
    QTabWidget* tabWidgetSelect;
    QWidget* tab;
    QComboBox* comboBoxClassifications;
    QWidgetStack* widgetStack_Classifications;
    QWidget* ATC;
    QListView* listView_EdMed_ATC;
    QWidget* TherapVidal;
    QListView* listViewTherapClassVidal;
    QLineEdit* lineEdit_Produit;
    QWidget* tab_2;
    QLineEdit* lineEdit_FindNomSubce;
    QListView* listView_Substance;
    QWidget* tab_3;
    QLineEdit* lineEdit_Find_Indic;
    QListView* listView_IndicList;
    QLabel* textLabelLogo;
    QPushButton* pushButtonByPrincipe;
    QPushButton* pushButtonByGenerique;
    QPushButton* pushButtonByReferent;
    QPushButton* pushButtonByObsolete;
    QPushButton* pushButtonByStandard;
    QListView* listView_Produits;
    QLabel* textLabel_Status;
    QPushButton* pushButtonQuit;
    QTabWidget* tabWidget_Tables;
    QWidget* tab_4;
    QPushButton* pushButtonEditPoso;
    QSplitter* splitter2;
    QTextBrowser* textBrowser_Posologies;
    QWidget* tab_5;
    QTextBrowser* textBrowser_Monographie;
    QWidget* tab_6;
    QTextBrowser* textBrowser_Prescription;
    QLabel* textLabel_Poids;
    QLabel* textLabel_Taille;
    QComboBox* comboBoxPendant;
    QPushButton* pushButtonALD_Off;
    QPushButton* pushButtonALD;
    QPushButton* pushButtonPrescErase;
    QPushButton* pushButton_Ok;

    virtual int initDialog( CMedicaBase * pCMedBase, QString * ordoStruct );
    virtual int initDialog( CMedicaBase * pCMedBase, const QPL_CPosologie & posologieOrdoList );
    virtual int getCurrentPageID_ByTitle( QTabWidget * pQTabWidget, const QString & title );
    virtual QString DoPopupList( QStringList & list );
    virtual int Convert_CRLF_To_BR( const char * text, QString & dstQStr, int flag );
    virtual QString Get_OrdoXmlStruct();

public slots:
    virtual int initDialog( CMedicaBase * pCMedBase );
    virtual void initComboDuree();
    virtual void pushButton_CIP_Find_clicked();
    virtual void tabWidget_Tables_currentChanged( QWidget * );
    virtual void listView_Produits_currentChanged( QListViewItem * pQListViewItem );
    virtual void listView_Produits_doubleClicked( QListViewItem * );
    virtual void listView_Produits_clicked( QListViewItem * pQListViewItem );
    virtual void comboBox_Specialites_activated( int id );
    virtual void pushButtonDown_clicked();
    virtual void pushButtonDownProd_clicked();
    virtual void lineEdit_Produit_textChanged( const QString & text );
    virtual void checkBox_Generiques_stateChanged( int );
    virtual void checkBox_Dispo_stateChanged( int );
    virtual void InitListMedicament();
    virtual void listView_EdMed_ATC_clicked( QListViewItem * pQListViewItem );
    virtual void listViewTherapClassVidal_clicked( QListViewItem * pQListViewItem );
    virtual void pushButtonByGenerique_clicked();
    virtual void pushButtonByReferent_clicked();
    virtual void pushButtonByObsolete_clicked();
    virtual void pushButtonByStandard_clicked();
    virtual void comboBoxClassifications_activated( int id );
    virtual void lineEdit_Find_Indic_textChanged( const QString & txt );
    virtual void listView_IndicList_clicked( QListViewItem * pQListViewItem );
    virtual void pushButtonByPrincipe_clicked();
    virtual void listView_Produits_rightButtonClicked( QListViewItem *, const QPoint &, int );
    virtual void OnMenuActivated( int id );
    virtual void GetPopupItem();
    virtual void PopupQuantiteAccessoire( CPosologie & poso );
    virtual void PopupDureeTraitement( CPosologie & poso, int num );
    virtual void lineEdit_FindNomSubce_textChanged( const QString & txt );
    virtual void listView_Substance_clicked( QListViewItem * pQListViewItem );
    virtual void textBrowser_Posologies_anchorClicked( const QString &, const QString & link );
    virtual void pushButtonEditPoso_clicked();
    virtual void textBrowser_PrescriptionRefresh( QPL_CPosologie & posoList );
    virtual void pushButtonPrescErase_clicked();
    virtual void pushButtonALD_Off_clicked();
    virtual void pushButtonALD_clicked();
    virtual void comboBoxPendant_activated( int item );
    virtual void comboBoxPendant_textChanged( const QString & text );
    virtual void textBrowser_Prescription_anchorClicked( const QString &, const QString & link );
    virtual QPL_CPosologie GetOrdoList();
    virtual void pushButton_Ok_clicked();

protected:
    CMedicaBase *m_pCMedBase;
    QString m_PosoCIP;
    QPL_CPosologie m_CPosologieOrdoList;
    QPopupMenu *m_pQPopupMenu;
    QString m_RetPopupItem;
    QString m_CurrentPopupItem;
    QPL_CPosologie m_QPL_CPosologie;
    QString PAGE_INFO_GENE;
    QString PAGE_INFO_COMPO;
    QString PAGE_INFO_EXTRA;
    QString PAGE_EDIT_POSO;
    QString PAGE_EDIT_MEDIC;
    QString PAGE_PRESCRIPTION;
    QString PAGE_MONOGRAPHIE;
    QString PAGE_POSOLOGIES;

    QGridLayout* Dlg_MedicaTuxLayout;
    QGridLayout* layout12;
    QHBoxLayout* layout16;
    QVBoxLayout* layout32;
    QGridLayout* layout11;
    QGridLayout* tabLayout;
    QGridLayout* ATCLayout;
    QGridLayout* TherapVidalLayout;
    QGridLayout* tabLayout_2;
    QVBoxLayout* layout6;
    QGridLayout* tabLayout_3;
    QVBoxLayout* layout15;
    QVBoxLayout* layout89;
    QHBoxLayout* layout14;
    QSpacerItem* spacer1;
    QGridLayout* tabLayout_4;
    QSpacerItem* spacer3;
    QGridLayout* tabLayout_5;
    QGridLayout* tabLayout_6;
    QHBoxLayout* layout10;
    QSpacerItem* spacer1_2;
    QVBoxLayout* layout9;
    QHBoxLayout* layout10_2;
    QSpacerItem* spacer4;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;
    QPixmap image1;

    void init();
    void destroy();

};

#endif // DLG_MEDICATUX_H
