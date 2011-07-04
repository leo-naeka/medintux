/****************************************************************************
** Form interface generated from reading ui file 'Dlg_PosoManager.ui'
**
** Created: mer. mai 4 22:17:02 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLG_POSOMANAGER_H
#define DLG_POSOMANAGER_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qdialog.h>
#include "Global.h"
#include "../../MedinTuxTools/CMedicaBase.h"
#include "CApp.h"
#include "Dlg_HtmlView.h"
#include "Dlg_AdvancedTerrain.h"

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class CMaskedLineEdit;
class QFrame;
class QLabel;
class QSplitter;
class QListView;
class QListViewItem;
class QPushButton;
class QGroupBox;
class QLineEdit;
class QComboBox;
class QSlider;
class QTextBrowser;
class QRadioButton;

class Dlg_PosoManager : public QDialog
{
    Q_OBJECT

public:
    Dlg_PosoManager( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~Dlg_PosoManager();

    QFrame* line1;
    QLabel* textLabel1_3;
    QFrame* line1_2;
    QSplitter* splitter1;
    QListView* listView_Produits;
    QPushButton* pushButtonListPosoCopier;
    QPushButton* pushButtonListPosoColler;
    QPushButton* pushButtonDefPosoCopier;
    QPushButton* pushButtonDefPosoColler;
    QListView* listView_MedicaPoso;
    QGroupBox* groupBox5_3;
    QPushButton* pushButtonAdvancedTerrain;
    QLineEdit* lineEdit_Terrain;
    QLabel* textLabel2_4_2_2_3;
    QComboBox* comboBox_Sexe;
    QLabel* textLabel2_4_4;
    CMaskedLineEdit* lineEdit_AgeMin;
    QLabel* textLabel2_4_2_4;
    CMaskedLineEdit* lineEdit_AgeMax;
    QLabel* textLabel2_5;
    CMaskedLineEdit* lineEdit_EdPo_PoidsMin;
    QLabel* textLabel3_2;
    CMaskedLineEdit* lineEdit_EdPo_PoidsMax;
    QLineEdit* lineEdit_Indication;
    QLabel* textLabel2_4_2_2_2_3;
    QGroupBox* groupBox_UP;
    QSlider* slider_VarPoso;
    QLabel* textLabel2;
    CMaskedLineEdit* lineEditFactCorpQU;
    QComboBox* comboBoxFactCorpUnit;
    QLabel* textLabel5;
    CMaskedLineEdit* lineEditQUP1byUP2;
    QLabel* textLabelCoeffResult;
    CMaskedLineEdit* lineEdit_TailleTest;
    CMaskedLineEdit* lineEdit_PoidsTest;
    QTextBrowser* textBrowser_Result;
    QLabel* textLabel2_2;
    QLabel* textLabel1;
    QLabel* lineEdit_a_UP2_2;
    QLineEdit* lineEdit_QMin_UP2;
    QLabel* lineEdit_a_UP2;
    QLineEdit* lineEdit_QMax_UP2;
    QComboBox* comboBoxUP_2;
    QPushButton* pushButtonNewUP2_Unit;
    QLabel* textLabel3;
    CMaskedLineEdit* lineEdit_Periode;
    QLabel* textLabel4;
    QComboBox* comboBoxPeriode;
    QLabel* textLabel4_2;
    CMaskedLineEdit* lineEdit_UP1_Max;
    QLabel* lineEdit_a_UP2_2_2;
    CMaskedLineEdit* lineEdit_QMin_UP1;
    QPushButton* pushButton_A;
    CMaskedLineEdit* lineEdit_QMax_UP1;
    QComboBox* comboBoxUP_1;
    QPushButton* pushButtonNewUP1_Unit;
    QGroupBox* groupBox16;
    QLabel* textLabel_Moment;
    QComboBox* comboBoxMoment;
    QLabel* textLabel_Pendant;
    QComboBox* comboBoxPendant;
    QPushButton* pushButton_PosoSchemaEx;
    QRadioButton* radioButtonSecable1;
    QRadioButton* radioButtonSecable4;
    QLineEdit* lineEdit_SpecPrise;
    QRadioButton* radioButtonSecable2;
    QLabel* textLabel1_2;
    QLineEdit* lineEdit_Note;
    QPushButton* pushButton_RecordPoso;
    QPushButton* pushButton_ErasePoso;
    QPushButton* pushButton_AddPoso;
    QPushButton* pushButton_Quitter;

    virtual float ExtractNumber( const QString text );
    virtual QString ComboFactCorpUnitToUnit();
    virtual QString ComboSexeToVal();
    virtual QString comboBoxMomentToSpecPrises( QString & spec );

public slots:
    virtual void initDialog( QString cip, const QString & tableSpecIndex, const QString &, QListView * pQListView );
    virtual void pushButton_QuitterClicked();
    virtual void lineEdit_PoidsTest_textChanged( const QString & );
    virtual void lineEdit_TailleTest_textChanged( const QString & );
    virtual void lineEdit_QMin_UP1_textChanged( const QString & );
    virtual void lineEdit_QMax_UP1_textChanged( const QString & );
    virtual void lineEditFactCorpQU_textChanged( const QString & );
    virtual void ListViewProduitCopy( QListView * pQListView );
    virtual void listView_Produits_clicked( QListViewItem * pQListViewItem );
    virtual void listView_Produits_currentChanged( QListViewItem * pQListViewItem );
    virtual void listView_Produits_Changed( QListViewItem * pQListViewItem );
    virtual void listView_MedicaPoso_currentChanged( QListViewItem * pQListViewItem );
    virtual void listView_MedicaPoso_clicked( QListViewItem * pQListViewItem );
    virtual void listView_ItemToInterface( QListViewItem * pQListViewItem );
    virtual void CPosologieToInterface( CPosologie & poso );
    virtual void InterfaceToCPosologie( CPosologie & poso );
    virtual void DisplayResult();
    virtual int ComputeNbPrises( const QString & spec );
    virtual void ComputeSecondForm( const CPosologie &, QString & upMin, QString & upMax );
    virtual void slider_VarPoso_valueChanged( int );
    virtual void radioButtonSecable1_clicked();
    virtual void radioButtonSecable2_clicked();
    virtual void radioButtonSecable4_clicked();
    virtual int getSecabilite();
    virtual void comboBoxMoment_activated( const QString & );
    virtual void comboBoxUP_1_textChanged( const QString & );
    virtual void comboBoxUP_1_activated( int );
    virtual void comboBoxUP_2_textChanged( const QString & );
    virtual void comboBoxUP_2_activated( int );
    virtual void lineEditQUP1byUP2_textChanged( const QString & );
    virtual void SetComboOnThisLibelle( QComboBox * pQComboBox, const QString & value );
    virtual void SetComboOnLibelle( QComboBox * pQComboBox, const QString & value );
    virtual void comboBoxPeriode_activated( const QString & text );
    virtual void comboBoxFactCorpUnit_activated( int );
    virtual void comboBoxPendant_activated( const QString & );
    virtual void lineEdit_SpecPrise_textChanged( const QString & );
    virtual void pushButtonNewUP1_Unit_clicked();
    virtual void UnitTablesSynchronise();
    virtual void pushButtonNewUP2_Unit_clicked();
    virtual void pushButton_AddPoso_clicked();
    virtual void AddPosoToBase( CPosologie & poso );
    virtual void pushButton_RecordPoso_clicked();
    virtual void pushButton_ErasePoso_clicked();
    virtual void pushButtonAdvancedTerrain_clicked();
    virtual void pushButtonListPosoCopier_clicked();
    virtual void pushButtonListPosoColler_clicked();
    virtual void AddPosoListToBase( QPL_CPosologie & list_CPosologie );
    virtual void pushButtonDefPosoCopier_clicked();
    virtual void pushButtonDefPosoColler_clicked();
    virtual void pushButton_A_clicked();

protected:
    CPosologie m_CPosologie;
    QString m_CIP;
    QString m_ProdName;
    Dlg_HtmlView *m_pDlg_HtmlView;
    QString m_TableSpecIndex;
    QPL_CPosologie m_CPosologieListMem;
    CPosologie m_CPosologieMem;

    QGridLayout* Dlg_PosoManagerLayout;
    QGridLayout* layout19;
    QVBoxLayout* layout21;
    QHBoxLayout* layout20;
    QSpacerItem* spacer4;
    QGridLayout* layout22;
    QHBoxLayout* layout19_2;
    QSpacerItem* spacer3_2;
    QGridLayout* groupBox5_3Layout;
    QGridLayout* layout69;
    QHBoxLayout* layout30;
    QSpacerItem* spacer3;
    QHBoxLayout* layout28;
    QHBoxLayout* layout29;
    QGridLayout* groupBox_UPLayout;
    QHBoxLayout* layout25;
    QHBoxLayout* layout24;
    QHBoxLayout* layout20_2;
    QHBoxLayout* layout26;
    QHBoxLayout* layout20_3;
    QHBoxLayout* layout24_2;
    QHBoxLayout* layout23;
    QGridLayout* groupBox16Layout;
    QGridLayout* layout23_2;
    QGridLayout* layout20_4;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;

    void init();
    void destroy();

};

#endif // DLG_POSOMANAGER_H
