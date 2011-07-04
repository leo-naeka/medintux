/****************************************************************************
** Form interface generated from reading ui file 'Dlg_MainDialog.ui'
**
** Created: mer. mai 4 22:14:42 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLG_MAINDIALOG_H
#define DLG_MAINDIALOG_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qdialog.h>
#include <qsqldatabase.h>
#include <qprocess.h>
#include <qtimer.h>
#include "CUpdateThread.h"
#include "../../MedinTuxTools/CMedicaBase.h"
#include "CIndexMakeThread.h"
#include "../../drtux/src/CMoteur_Base.h"

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class CW_EditText;
class QLabel;
class QPushButton;
class QProgressBar;
class QTabWidget;
class QWidget;
class QComboBox;
class QGroupBox;
class QCheckBox;
class QLineEdit;

class Dlg_MainDialog : public QDialog
{
    Q_OBJECT

public:
    Dlg_MainDialog( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~Dlg_MainDialog();

    QLabel* textLabel_MedinTux;
    QLabel* textLabel_Progress;
    CW_EditText* textEdit_Message;
    QPushButton* pushButton_LancerDrTux;
    QProgressBar* progressBar_Load;
    QPushButton* quitPushButton;
    QTabWidget* tabWidget_Instal;
    QWidget* tab_Bases;
    QPushButton* pushButton_SetBases;
    QPushButton* pushButton_MajBases;
    QComboBox* comboBox_Bases;
    QPushButton* pushButton_Load_SQL;
    QWidget* tab_Vidal;
    QGroupBox* groupBox1;
    QPushButton* pushButton_IndexerDatasemp;
    QPushButton* pushButton_SetDatasemp;
    QPushButton* pushButtonJustOneTable;
    QPushButton* pushButtonImagesCopy;
    QCheckBox* checkBox_STD_MAJ;
    QPushButton* pushButtonMakeSQL;
    QLabel* textLabel3;
    QCheckBox* checkBox_SQL_MAJ;
    QPushButton* pushButtonSwitchGetDatasemp;
    QWidget* tab_Compilation;
    QPushButton* pushButton_compilation;
    QComboBox* comboBox_Executables;
    QLineEdit* lineEdit_Qt3;
    QLineEdit* lineEdit_Qt4Sdk;
    QPushButton* pushButton_Qt4Sdk;
    QPushButton* pushButton_Qt3;
    QLabel* textLabel_MacOS;
    QWidget* tab_Sesam;
    QGroupBox* groupBox5;
    QPushButton* pushButton_setGalsINI;
    QPushButton* pushButton_LireVitale;
    QPushButton* pushButton_InstallSesam;
    QComboBox* comboBox_PortLecteurWin;
    QComboBox* comboBox_PortLecteur;
    QLineEdit* lineEdit_BinaryPath;
    QLabel* textLabel_WindPathField;
    QLineEdit* lineEdit_SesamPath;
    QLabel* textLabel_SesamPath;
    QLineEdit* lineEdit_RootPass;
    QLabel* textLabel_RootField;
    QLabel* textLabel_AdminLinux;
    QGroupBox* groupBox3;
    QTabWidget* tabWidget_Nomadisme;
    QWidget* serveur_maitre;
    QLineEdit* lineEdit_Sql_Port;
    QLineEdit* lineEdit_Hostname;
    QPushButton* pushButton_FavPlus;
    QLabel* textLabel1_3_2;
    QPushButton* pushButtonRemove;
    QComboBox* comboBox_IP_Fav;
    QLabel* textLabel1_2;
    QLabel* textLabel1;
    QLineEdit* lineEdit_UserName;
    QLabel* textLabel1_3;
    QLineEdit* lineEdit_PassWord;
    QWidget* Serveur_nomade;
    QLabel* textLabel1_4;
    QLineEdit* lineEdit_UserName_2;
    QLabel* textLabel1_3_3;
    QLineEdit* lineEdit_PassWord_2;
    QLineEdit* lineEdit_Sql_Port_2;
    QComboBox* comboBox_IP_Fav_2;
    QPushButton* pushButton_FavPlus_2;
    QLineEdit* lineEdit_Hostname_2;
    QPushButton* pushButtonRemove_2;
    QLabel* textLabel1_3_2_2;
    QLabel* textLabel1_2_2;
    QWidget* TabPage;
    QLabel* textLabel1_4_2;
    QLineEdit* lineEdit_UserName_3;
    QLabel* textLabel1_3_3_2;
    QLineEdit* lineEdit_PassWord_3;
    QPushButton* pushButton_FavPlus_3;
    QLabel* textLabel1_3_2_2_2;
    QPushButton* pushButtonRemove_3;
    QComboBox* comboBox_IP_Fav_3;
    QLineEdit* lineEdit_Hostname_3;
    QLineEdit* lineEdit_Sql_Port_3;
    QLabel* textLabel1_2_2_2;
    QPushButton* pushButton_APropos;
    QCheckBox* checkBox_Nomadisme;
    QPushButton* pushButtonConnexionAppl;

    CMedicaBase *m_pCMedicaBase;

protected:
    bool m_testBaseProcRun;
    ;
    QDateTime m_dtDebComp;
    QSqlDatabase *m_DatasempBase;
    QString m_DatasempDir;
    QDateTime m_dtDeb;
    QSqlDatabase* m_Base;
    QProcess *m_proc;
    CUpdateThread *m_pCUpdateThread;
    QTimer *m_pQTimer;
    QTimer *m_pQTimerComp;
    bool m_BaseToInstallFlag;
    bool m_BaseVidalRun;
    CIndexMakeThread *m_pCIndexMakeThread;
    QTimer *m_pCindexQTimer;
    long m_ProgressTotal;
    QDateTime m_DateDeb;
    QString m_IndexStatus;
    QString m_BaseCfg;
    QString m_PatchParam;
    CMoteurBase *m_pCMoteurBase;
    QProcess* m_TestBasesProc;

    QGridLayout* Dlg_MainDialogLayout;
    QGridLayout* layout23;
    QGridLayout* tab_BasesLayout;
    QGridLayout* layout21;
    QGridLayout* tab_VidalLayout;
    QGridLayout* groupBox1Layout;
    QSpacerItem* spacer3;
    QGridLayout* layout9;
    QHBoxLayout* layout9_2;
    QSpacerItem* spacer1;
    QGridLayout* tab_CompilationLayout;
    QGridLayout* layout20;
    QGridLayout* layout18;
    QGridLayout* layout19;
    QGridLayout* tab_SesamLayout;
    QGridLayout* groupBox5Layout;
    QGridLayout* layout19_2;
    QGridLayout* layout9_2_2;
    QGridLayout* layout9_2_2_2;
    QGridLayout* layout9_3;
    QGridLayout* groupBox3Layout;
    QGridLayout* serveur_maitreLayout;
    QGridLayout* layout11;
    QHBoxLayout* layout4;
    QSpacerItem* spacer2;
    QGridLayout* Serveur_nomadeLayout;
    QHBoxLayout* layout4_2;
    QSpacerItem* spacer2_2;
    QGridLayout* layout21_2;
    QGridLayout* TabPageLayout;
    QHBoxLayout* layout4_2_2;
    QSpacerItem* spacer2_2_2;
    QGridLayout* layout20_2;
    QGridLayout* layout21_3;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;
    QPixmap image1;
    QPixmap image2;
    QPixmap image3;
    QPixmap image4;
    QPixmap image5;

};

#endif // DLG_MAINDIALOG_H
