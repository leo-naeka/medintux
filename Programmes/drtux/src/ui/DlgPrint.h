/****************************************************************************
** Form interface generated from reading ui file 'DlgPrint.ui'
**
** Created: mer. mai 4 22:17:01 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLGPRINT_H
#define DLGPRINT_H

#include <qvariant.h>
#include <qdialog.h>
#include <qsimplerichtext.h>
#include <qtextedit.h>
#include "CPrinter.h"
#include "CMoteur_Base.h"

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QFrame;
class QGroupBox;
class QSlider;
class QLineEdit;
class QLabel;
class QPushButton;
class QCheckBox;
class QComboBox;

class DlgPrint : public QDialog
{
    Q_OBJECT

public:
    DlgPrint( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~DlgPrint();

    QFrame* frameToolBar;
    QGroupBox* groupBox1;
    QFrame* frame4;
    QSlider* slider_Marg_Top;
    QLineEdit* lineEdit_Marg_Top;
    QLabel* textLabel1_;
    QFrame* frame6;
    QSlider* slider_Head_H;
    QLineEdit* lineEdit_Head_H;
    QLabel* textLabel1__2;
    QFrame* frame7;
    QSlider* slider_Marg_Left;
    QLineEdit* lineEdit_Marg_Left;
    QLabel* textLabel1__2_2_3;
    QFrame* frame9;
    QSlider* slider_Marg_Right;
    QLineEdit* lineEdit_Marg_Right;
    QLabel* textLabel1__2_2_3_2;
    QFrame* frame11;
    QSlider* slider_Marg_Bottom;
    QLineEdit* lineEdit_Marg_Bottom;
    QLabel* textLabel1__2_2_2;
    QFrame* frame10;
    QSlider* slider_Foot_H;
    QLineEdit* lineEdit_Foot_H;
    QLabel* textLabel1__2_2;
    QLineEdit* lineEditResoX;
    QLineEdit* lineEditResoY;
    QLabel* textLabel1__2_2_2_2_2;
    QLabel* textLabel1__2_2_2_2;
    QLabel* textLabel1__2_2_2_2_3_2;
    QLabel* textLabel1__2_2_2_2_3;
    QPushButton* pushButtonSave;
    QLabel* textLabel_NbPage;
    QGroupBox* groupBox2;
    QLabel* textLabel1__2_2_3_3_2;
    QLineEdit* lineEditZoom;
    QLineEdit* lineEdit_PageDeb;
    QLineEdit* lineEdit_PageFin;
    QLabel* textLabel_2;
    QLabel* textLabel_2_2;
    QLabel* textLabel1__2_2_3_3;
    QPushButton* pushButtonPrint_2;
    QPushButton* pushButtonPrint_2_2;
    QPushButton* pushButtonConfigurer;
    QPushButton* pushButtonPrint;
    QCheckBox* checkBox_Duplicata;
    QCheckBox* checkBox_PrintDuplicata;
    QPushButton* pushButtonPrevious;
    QPushButton* pushButtonNext;
    QComboBox* comboBox_TypeDoc;
    QPushButton* pushButtonQuitter;

    QPrinter* m_pQPrinter;
    float m_PageH;
    float m_PageW;

    virtual QString Get_User_Head_Foot( QString user, QString * foot, const QString & nameDoc, const QString & str_type );
    virtual QString GetCurrentComboPrimKey();
    virtual QString IsExistDuplicata();
    virtual QString GetNameDocFromCombo();

public slots:
    virtual void slider_Marg_Top_sliderMoved( int value );
    virtual void slider_Head_H_sliderMoved( int value );
    virtual void slider_Marg_Left_sliderMoved( int value );
    virtual void slider_Marg_Right_sliderMoved( int value );
    virtual void slider_Marg_Bottom_sliderMoved( int value );
    virtual void slider_Foot_H_sliderMoved( int value );
    virtual void UpdateTextePageInfo( int nb_page );
    virtual int initDialog( QTextEdit * pBodyTextEdit, QString & IdentPrimKey, CMoteurBase * pCMoteurBase, RUBREC_LIST * pRubList, int id_Obs, int id_Prs, const char * observText, const char * userActuelPk, const char * rubName );
    virtual void executeTransfertMacro();
    virtual void SetCaption();
    virtual void pushButtonSave_clicked();
    virtual void SetDialogOnPrinterSpec();
    virtual void comboBox_TypeDoc_activated( const QString & );
    virtual void comboBox_TypeDoc_activated( int item );
    virtual void SetDialogOnHeadAndFoot( int );
    virtual void GetPossibleDefaultFont( const QString & txt, QFont & font );
    virtual void FusionneDocument( QString * pDocument, QString userActuelPk );
    virtual void AdjustHeightFootAndHead();
    virtual void initRichBodyText( QSimpleRichText * pRichText );
    virtual void initRichHeadText( QSimpleRichText * pRichText );
    virtual void initRichFootText( QSimpleRichText * pRichText );
    virtual void pushButtonOk_clicked();
    virtual void pushButtonPrint_2_clicked();
    virtual void pushButtonPrint_2_2_clicked();
    virtual void pushButtonPrint_clicked();
    virtual void printDoc( int nbCopies );
    virtual void GetHeadAndFoot( QString prim_key, int type, int update );
    virtual void pushButtonQuitter_clicked();
    virtual void pushButtonConfigurer_clicked();
    virtual void pushButtonPrevious_clicked();
    virtual void pushButtonNext_clicked();
    virtual void checkBox_Duplicata_stateChanged( int );

protected:
    QString m_BodyText;
    QString m_UserActuelPk;
    QString m_FootText;
    QString m_HeadText;
    QString m_ObsText;
    QSimpleRichText * m_pFootRichText;
    QSimpleRichText * m_pBodyRichText;
    CViewPageWidget* m_pCViewPageWidget;
    QSimpleRichText * m_pHeadRichText;
    QTextEdit * m_pBodyTextEdit;
    CMoteurBase* m_pCMoteurBase;
    QString m_SignUser;
    QString m_IdentPrimKey;
    RUBREC_LIST* m_pRubList;
    int m_ID_Obs;
    int m_ID_Prs;


protected slots:
    virtual void languageChange();

private:
    void init();
    void destroy();

};

#endif // DLGPRINT_H
