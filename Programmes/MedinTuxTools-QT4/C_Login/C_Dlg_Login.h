#ifndef C_DLG_LOGIN_H
#define C_DLG_LOGIN_H

#include <QDialog>
namespace Ui {
    class C_Dlg_Login;
}

class QTimer;
//===========================================  C_Dlg_Login ===================================
class C_Dlg_Login : public QDialog
{
    Q_OBJECT

public:

    enum Visibility  {Show    = 0,
                      OnEdit  = 1,
                      Hide    = 2,
                     };


    explicit C_Dlg_Login(const QString &login, const QString &password, QWidget *parent = 0);
    ~C_Dlg_Login();

    //---------------------------------------- get_Login -----------------------------------------
    QString  get_Login();
    //---------------------------------------- get_Password -----------------------------------------
    QString  get_Password();
    //---------------------------------------- get_CriptedLogin -----------------------------------------
    QString  get_CriptedLogin(const QString &prefix = "");
    //---------------------------------------- get_CriptedPassword -----------------------------------------
    QString  get_CriptedPassword(const QString &prefix = "");
private:
    //---------------------------------------- set_LoginOnState -----------------------------------------
    void set_LoginOnState     (C_Dlg_Login::Visibility state);
    //---------------------------------------- set_PasswordOnState -----------------------------------------
    void set_PasswordOnState  (C_Dlg_Login::Visibility state);
    //---------------------------------------- getModeEditState -----------------------------------------
    void getModeEditState ();
    //---------------------------------------- getModeEditState -----------------------------------------
    C_Dlg_Login::Visibility nextModeEditState (C_Dlg_Login::Visibility state);
private slots:
    //---------------------------------------- Slot_pushButton_LoginHideShow -----------------------------------------
    void Slot_pushButton_LoginHideShow  (bool);
    //---------------------------------------- Slot_pushButton_PasswordHideShow -----------------------------------------
    void Slot_pushButton_PasswordHideShow  (bool);
    //---------------------------------------- Slot_pushButton_LoginOk -----------------------------------------
    void Slot_pushButton_LoginOk  (bool);
    //---------------------------------------- Slot_pushButton_LoginCancel -----------------------------------------
    void Slot_pushButton_LoginCancel  (bool);
    //---------------------------------------- Slot_lineEdit_Login_cursorPositionChanged -----------------------------------------
    void Slot_lineEdit_Login_cursorPositionChanged (int , int);
    //---------------------------------------- Slot_lineEdit_Password_cursorPositionChanged -----------------------------------------
    void Slot_lineEdit_Password_cursorPositionChanged (int , int);
    //---------------------------------------- Slot_TimerIsTimeOut -----------------------------------------
    void Slot_TimerIsTimeOut();

private:
    QString                   m_nonCriptedLogin;
    QString                   m_nonCriptedPassword;
    C_Dlg_Login::Visibility   m_stateLoginEyes;
    C_Dlg_Login::Visibility   m_statePasswordEyes;
    QTimer                   *m_pQTimer;
    int                       m_TimerPasswordCount;
    int                       m_TimerLoginCount;
    Ui::C_Dlg_Login          *m_pGUI;
};

#endif // C_DLG_LOGIN_H
