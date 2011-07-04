/****************************************************************************
** Form interface generated from reading ui file 'RubIdentite.ui'
**
** Created: mer. mai 4 22:17:01 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FORMRUBIDENT_H
#define FORMRUBIDENT_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class CMaskedLineEdit;
class QTabWidget;
class QGroupBox;
class QLabel;
class QTextEdit;
class QComboBox;
class QLineEdit;
class QPushButton;
class QListView;
class QListViewItem;

class FormRubIdent : public QWidget
{
    Q_OBJECT

public:
    FormRubIdent( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~FormRubIdent();

    QTabWidget* tabWidget_Ident;
    QWidget* tab_Administratif;
    QGroupBox* groupBox1;
    QLabel* textLabel5;
    CMaskedLineEdit* lineEdit_CdPostal;
    QLabel* textLabel6;
    CMaskedLineEdit* lineEditVille;
    QLabel* textLabel2;
    CMaskedLineEdit* lineEdit_NomDossier;
    CMaskedLineEdit* lineEdit_PremomDossier;
    QLabel* textLabel2_2;
    QLabel* textLabel4;
    QTextEdit* textEdit_Adresse;
    CMaskedLineEdit* lineEdit_Tel3;
    CMaskedLineEdit* lineEdit_Tel1;
    QLabel* textLabel3_2_2_2;
    QLabel* textLabel3_2_2_3;
    CMaskedLineEdit* lineEdit_Tel2;
    QLabel* textLabel3_2_2;
    CMaskedLineEdit* lineEdit_DtNss;
    CMaskedLineEdit* lineEdit_RangGeme;
    QLabel* textLabel3_3_2_2;
    QLabel* textLabel3_3;
    QLabel* textLabel3;
    QComboBox* comboBoxSexe;
    QLabel* textLabel1_2;
    CMaskedLineEdit* lineEdit_Profession;
    QLabel* textLabel2_2_2;
    CMaskedLineEdit* lineEdit_NomDeNss;
    QLabel* textLabel2_2_2_2;
    CMaskedLineEdit* lineEdit_Titre;
    QLineEdit* lineEdit_Email;
    QLineEdit* textLabel_NumDoss;
    QLabel* textLabelNumeroDoss;
    QLabel* textLabel10;
    QGroupBox* groupBox2;
    QLabel* textLabel9;
    CMaskedLineEdit* lineEdit_PrenomAssure;
    CMaskedLineEdit* lineEdit_DtNss_Assure;
    QLabel* lineEdit_NssClef_2;
    QLabel* textLabel8;
    CMaskedLineEdit* lineEdit_NomAssure;
    QLabel* textLabelNumeroDoss_2;
    QComboBox* comboBoxQualiteAyantDroit;
    QLabel* lineEdit_NssClef;
    CMaskedLineEdit* lineEdit_NumSecu;
    QLabel* textLabel7;
    QTabWidget* tabWidgetNotes;
    QWidget* tab;
    QPushButton* pushButton_AddMedTTT;
    QPushButton* pushButton_DelMedTTT;
    QListView* listView_Praticiens;
    QWidget* tab_2;
    QTextEdit* textEdit_Note;
    QPushButton* pushButtonCancel;
    QPushButton* pushButtonCreate;
    QPushButton* pushButtonSavModif;
    QWidget* tab_Documents;
    QPushButton* pushButtonExporter;
    QPushButton* pushButtonPrint;
    QLabel* textLabel_UserName;
    QComboBox* comboBox_RubName;
    QLabel* textLabel1;
    QPushButton* pushButtonRubDateChange;
    QPushButton* pushButtonAdd;
    QPushButton* pushButtonSave;
    QPushButton* pushButtonDelete;
    QPushButton* textLabel_NbRub;

protected:
    QGridLayout* FormRubIdentLayout;
    QGridLayout* tab_AdministratifLayout;
    QGridLayout* groupBox1Layout;
    QHBoxLayout* layout32;
    QGridLayout* layout16;
    QHBoxLayout* layout31;
    QHBoxLayout* layout30;
    QGridLayout* layout29;
    QGridLayout* layout15;
    QHBoxLayout* layout15_2;
    QGridLayout* layout19;
    QGridLayout* groupBox2Layout;
    QHBoxLayout* layout35;
    QGridLayout* layout18;
    QGridLayout* layout17;
    QGridLayout* layout21;
    QGridLayout* layout23;
    QGridLayout* layout22;
    QGridLayout* tabLayout;
    QGridLayout* layout16_2;
    QVBoxLayout* layout14;
    QGridLayout* tabLayout_2;
    QGridLayout* layout27;
    QSpacerItem* spacer4;
    QSpacerItem* spacer6;
    QSpacerItem* spacer7;
    QSpacerItem* spacer5;
    QGridLayout* tab_DocumentsLayout;
    QGridLayout* layoutBarreTexte;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;

};

#endif // FORMRUBIDENT_H
