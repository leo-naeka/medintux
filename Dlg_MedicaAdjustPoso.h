/****************************************************************************
** Form interface generated from reading ui file 'Dlg_MedicaAdjustPoso.ui'
**
** Created: mer. mai 4 22:17:02 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLG_MEDICAADJUSTPOSO_H
#define DLG_MEDICAADJUSTPOSO_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qdialog.h>
#include <qapplication.h>
#include "../../MedinTuxTools/CMedicaBase.h"
#include "Global.h"
#include "CMDI_Terrain.h"

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class CMaskedLineEdit;
class QLabel;
class QGroupBox;
class QLineEdit;
class QPushButton;
class QSlider;
class QRadioButton;
class QComboBox;
class QTextBrowser;
class QFrame;
class QTextEdit;

class Dlg_MedicaAdjustPoso : public QDialog
{
    Q_OBJECT

public:
    Dlg_MedicaAdjustPoso( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~Dlg_MedicaAdjustPoso();

    QLabel* textLabelMaxPosoAlert;
    QLabel* textLabelPdsUnit;
    QLabel* textLabelTailleUnit;
    QLabel* textLabelPoids;
    QLabel* textLabelTaille;
    CMaskedLineEdit* lineEdit_Poids;
    CMaskedLineEdit* lineEdit_Taille;
    QGroupBox* groupBox_UP;
    QLineEdit* lineEdit_QMin_UP1;
    QPushButton* pushButton_A;
    QLineEdit* lineEdit_QMax_UP1;
    QLabel* textLabelUnite_UP1;
    QLineEdit* lineEdit_QMin_UP2;
    QLabel* lineEdit_a_UP2;
    QLineEdit* lineEdit_QMax_UP2;
    QLabel* textLabelUnite_UP2;
    QSlider* slider_VarPoso;
    QRadioButton* radioButtonSecable1;
    QRadioButton* radioButtonSecable2;
    QRadioButton* radioButtonSecable4;
    QLabel* textLabel_Pendant;
    QComboBox* comboBoxPendant;
    QPushButton* pushButton_NextPoso;
    QLabel* textLabel_Moment;
    QComboBox* comboBoxMoment;
    QTextBrowser* textBrowser_Result;
    QFrame* frameIco4;
    QLabel* textLabel_Moment_2_2;
    QComboBox* comboBoxNbNuit;
    QPushButton* pushButtonCPNuit100;
    QPushButton* pushButtonCPNuit75;
    QPushButton* pushButtonCPNuit50;
    QPushButton* pushButtonCPNuit25;
    QFrame* frameIco2;
    QLabel* textLabel_Moment_2_4;
    QComboBox* comboBoxNbMidi;
    QPushButton* pushButtonCPMidi100;
    QPushButton* pushButtonCPMidi75;
    QPushButton* pushButtonCPMidi50;
    QPushButton* pushButtonCPMidi25;
    QFrame* frameIco1;
    QLabel* textLabel_Moment_2;
    QComboBox* comboBoxNbMatin;
    QPushButton* pushButtonCPMatin100;
    QPushButton* pushButtonCPMatin75;
    QPushButton* pushButtonCPMatin50;
    QPushButton* pushButtonCPMatin25;
    QFrame* frameIco3;
    QLabel* textLabel_Moment_2_3;
    QComboBox* comboBoxNbSoir;
    QPushButton* pushButtonCPSoir100;
    QPushButton* pushButtonCPSoir75;
    QPushButton* pushButtonCPSoir50;
    QPushButton* pushButtonCPSoir25;
    QPushButton* pushButtonOK;
    QPushButton* pushButtonQuit;
    QTextEdit* textEditNote;
    QLabel* textLabel1;

    CPosologie m_PosoIn;
    QString *m_pPoids;
    QString *m_pTaille;

public slots:
    virtual void initDialog( CPosologie & cPosologieIn, CMDI_Terrain * pCMDI_Terrain, QString * pPoids, QString * pTaille );
    virtual void initComboDuree();
    virtual void InterfaceToPoso( CPosologie & poso );
    virtual void SetComboRepartOnValue( int nb_prises );
    virtual void ComputeSecondForm( const CPosologie & poso, QString & upMin, QString & upMax, QString & upUnit );
    virtual void lineEdit_Poids_textChanged( const QString & str );
    virtual void lineEdit_Taille_textChanged( const QString & str );
    virtual void SetSecondForm();
    virtual void radioButtonSecable1_clicked();
    virtual void radioButtonSecable2_clicked();
    virtual void radioButtonSecable4_clicked();
    virtual void DisplayResult();
    virtual void slider_VarPoso_valueChanged( int );
    virtual void comboBoxMoment_activated( const QString & );
    virtual void textEditNote_textChanged();
    virtual void comboBoxPendant_textChanged( const QString & );
    virtual void pushButtonOK_clicked();
    virtual void pushButton_A_clicked();

protected:
    QGridLayout* Dlg_MedicaAdjustPosoLayout;
    QGridLayout* layout9;
    QSpacerItem* spacer1;
    QVBoxLayout* layout12;
    QVBoxLayout* layout10;
    QGridLayout* groupBox_UPLayout;
    QHBoxLayout* layout13;
    QSpacerItem* spacer5;
    QHBoxLayout* layout14;
    QSpacerItem* spacer6;
    QHBoxLayout* layout2;
    QVBoxLayout* layout6;
    QVBoxLayout* layout9_2;
    QSpacerItem* spacer2;
    QVBoxLayout* layout8;
    QGridLayout* layout21;
    QGridLayout* layoutAdjustIco;
    QGridLayout* frameIco4Layout;
    QGridLayout* frameIco2Layout;
    QGridLayout* frameIco1Layout;
    QGridLayout* frameIco3Layout;
    QHBoxLayout* layout153;
    QSpacerItem* spacer4;
    QGridLayout* layout13_2;

protected slots:
    virtual void languageChange();

private:
    CMDI_Terrain *m_pCMDI_Terrain;
    QString m_FactCorpUnit;
    int m_Secabilite;
    QString m_ProdName;

    QPixmap image0;
    QPixmap image1;
    QPixmap image2;
    QPixmap image3;
    QPixmap image4;
    QPixmap image5;

    void init();

};

#endif // DLG_MEDICAADJUSTPOSO_H
