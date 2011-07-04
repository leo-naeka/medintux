/****************************************************************************
** Form interface generated from reading ui file 'Dlg_AdvancedTerrain.ui'
**
** Created: mer. mai 4 22:17:02 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLG_ADVANCEDTERRAIN_H
#define DLG_ADVANCEDTERRAIN_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class CMaskedLineEdit;
class QGroupBox;
class QLabel;
class QPushButton;
class QComboBox;
class QTextBrowser;

class Dlg_AdvancedTerrain : public QDialog
{
    Q_OBJECT

public:
    Dlg_AdvancedTerrain( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~Dlg_AdvancedTerrain();

    QGroupBox* groupBox5_2_3_2;
    QLabel* textLabel1_5_2_2;
    QLabel* textLabel1_3_2_2_2;
    CMaskedLineEdit* LineEdit_BiliMax;
    CMaskedLineEdit* LineEdit_BiliMin;
    QLabel* textLabel2_4_2_2_2;
    QGroupBox* groupBox5_2_3_2_2;
    QLabel* textLabel1_5_2_2_2;
    QLabel* textLabel1_3_2_2_2_2;
    CMaskedLineEdit* LineEdit_EjectMax;
    CMaskedLineEdit* LineEdit_EjectMin;
    QLabel* textLabel2_4_2_2_2_2;
    QPushButton* pushButton_Ok;
    QGroupBox* groupBox4;
    QLabel* textLabel1_2;
    CMaskedLineEdit* LineEdit_AnMin;
    CMaskedLineEdit* LineEdit_AnMax;
    QLabel* textLabel2;
    QLabel* textLabel2_3;
    CMaskedLineEdit* LineEdit_MoisMin;
    CMaskedLineEdit* LineEdit_MoisMax;
    QLabel* textLabel2_2_2;
    QLabel* textLabel2_2;
    QComboBox* comboBoxAgeMin;
    QComboBox* comboBoxAgeMax;
    QGroupBox* groupBox5_3;
    QLabel* textLabel1_4;
    QLabel* textLabel1_3_3;
    CMaskedLineEdit* LineEdit_PoidsMax;
    CMaskedLineEdit* LineEdit_PoidsMin;
    QLabel* textLabel2_4_3;
    QGroupBox* groupBox5_2_3;
    QLabel* textLabelGrossesseEntre;
    CMaskedLineEdit* LineEdit_GrossesseMin;
    QLabel* textLabel_GrossesseEt;
    CMaskedLineEdit* LineEdit_GrossesseMax;
    QComboBox* comboBox_UnitGrossesse;
    QGroupBox* groupBox5_2;
    QLabel* textLabel_EntreClearence;
    QLabel* textLabel_EtClearence;
    CMaskedLineEdit* LineEdit_ClearenceMax;
    CMaskedLineEdit* LineEdit_ClearenceMin;
    QLabel* textLabel_UnitClearence;
    QComboBox* comboBox_Hemodialyse;
    QGroupBox* groupBox_Creat;
    QLabel* textLabel1;
    QLabel* textLabel1_3;
    CMaskedLineEdit* LineEdit_CreatMax;
    CMaskedLineEdit* LineEdit_CreatMin;
    QLabel* textLabel2_4;
    QTextBrowser* textBrowser_ResultView;
    QGroupBox* groupBox5_2_2;
    QComboBox* comboBox_Allaitement;

    virtual int initDialog( QString & terrain );
    virtual QString dialogToTerrain();
    virtual QString EDToVal( const QString & var, QString textMin, QString textMax, const QString & unit );

public slots:
    virtual void UpdateHtmlView( const QString & );
    virtual void comboBox_Allaitement_activated( const QString & );
    virtual void comboBox_UnitGrossesse_activated( const QString & );
    virtual void comboBox_Hemodialyse_activated( const QString & );
    virtual void pushButton_Ok_clicked();

protected:
    QGridLayout* Dlg_AdvancedTerrainLayout;
    QSpacerItem* spacer3;
    QGridLayout* groupBox5_2_3_2Layout;
    QGridLayout* groupBox5_2_3_2_2Layout;
    QGridLayout* groupBox4Layout;
    QSpacerItem* spacer1;
    QSpacerItem* spacer2;
    QGridLayout* groupBox5_3Layout;
    QHBoxLayout* groupBox5_2_3Layout;
    QGridLayout* groupBox5_2Layout;
    QGridLayout* groupBox_CreatLayout;
    QGridLayout* groupBox5_2_2Layout;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;

    void init();

};

#endif // DLG_ADVANCEDTERRAIN_H
