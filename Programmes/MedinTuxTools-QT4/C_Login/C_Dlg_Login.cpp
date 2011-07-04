#include "C_Dlg_Login.h"
#include "ui_C_Dlg_Login.h"

#include <QTimer>
#include "../Theme.h"
#include "../C_AppCore.h"

//---------------------------------------- C_Dlg_Login -----------------------------------------
C_Dlg_Login::C_Dlg_Login( const QString &login, const QString &password, QWidget *parent) :
    QDialog(parent),
    m_pGUI(new Ui::C_Dlg_Login)
{   m_pGUI->setupUi(this);

    m_pQTimer              = new QTimer(this);
    m_TimerPasswordCount   = 0;
    m_TimerLoginCount      = 0;

    if (login.length()&&login[0]=='#')        m_nonCriptedLogin    = C_AppCore::appCore()->criptedToUnCripted(login.mid(1));
    else                                      m_nonCriptedLogin    = login;
    if (password.length()&& password[0]=='#') m_nonCriptedPassword = C_AppCore::appCore()->criptedToUnCripted(password.mid(1));
    else                                      m_nonCriptedPassword = password;

    getModeEditState ();

    set_LoginOnState(m_stateLoginEyes);
    set_PasswordOnState(m_statePasswordEyes);

    m_pGUI->lineEdit_Login->setText(m_nonCriptedLogin);
    m_pGUI->lineEdit_Password->setText(m_nonCriptedPassword);

    connect( m_pGUI->pushButton_LoginHideShow,       SIGNAL(clicked ( bool )),                     this, SLOT(Slot_pushButton_LoginHideShow  (bool)) );
    connect( m_pGUI->pushButton_PasswordHideShow,    SIGNAL(clicked ( bool )),                     this, SLOT(Slot_pushButton_PasswordHideShow  (bool)) );
    connect( m_pGUI->pushButton_LoginOk,             SIGNAL(clicked ( bool )),                     this, SLOT(Slot_pushButton_LoginOk (bool)) );
    connect( m_pGUI->pushButton_LoginCancel,         SIGNAL(clicked ( bool )),                     this, SLOT(Slot_pushButton_LoginCancel  (bool)) );
    connect( m_pGUI->lineEdit_Password,              SIGNAL(cursorPositionChanged ( int , int  )), this, SLOT(Slot_lineEdit_Password_cursorPositionChanged (int , int)) );
    connect( m_pGUI->lineEdit_Login,                 SIGNAL(cursorPositionChanged ( int , int  )), this, SLOT(Slot_lineEdit_Login_cursorPositionChanged (int , int)) );
    connect(m_pQTimer,                               SIGNAL(timeout()),                            this, SLOT(Slot_TimerIsTimeOut()));
    m_pQTimer->start(150);
}

//---------------------------------------- ~C_Dlg_Login -----------------------------------------
C_Dlg_Login::~C_Dlg_Login()
{   //if (m_pQTimer) delete m_pQTimer;
    delete m_pGUI;
}

//---------------------------------------- getModeEditState -----------------------------------------
void C_Dlg_Login::getModeEditState ()
{   QString state       = "";

    m_stateLoginEyes    = C_Dlg_Login::Show ;
    state       = C_AppCore::appCore()->readUniqueParam("Login dialog","login visibility");
    if (state.length())
       {if      (state=="show")      m_stateLoginEyes = C_Dlg_Login::Show ;
        else if (state=="hide   ")   m_stateLoginEyes = C_Dlg_Login::Hide ;
        else                         m_stateLoginEyes = C_Dlg_Login::OnEdit;
       }

    m_statePasswordEyes    = C_Dlg_Login::Hide ;
    state       = C_AppCore::appCore()->readUniqueParam("Login dialog","password visibility");
    if (state.length())
       {if      (state=="show")      m_statePasswordEyes = C_Dlg_Login::Show ;
        else if (state=="hide")      m_statePasswordEyes = C_Dlg_Login::Hide ;
        else                         m_statePasswordEyes = C_Dlg_Login::OnEdit ;
       }
}

//---------------------------------------- nextModeEditState -----------------------------------------
C_Dlg_Login::Visibility C_Dlg_Login::nextModeEditState (C_Dlg_Login::Visibility state)
{int i = (int) state; ++i; if (i > C_Dlg_Login::Hide) i = C_Dlg_Login::Show;
 state = (C_Dlg_Login::Visibility)i;
 return   state;
}

//---------------------------------------- Slot_lineEdit_Login_cursorPositionChanged -----------------------------------------
void C_Dlg_Login::Slot_lineEdit_Login_cursorPositionChanged (int , int)
{if (m_stateLoginEyes<=C_Dlg_Login::OnEdit)
    {m_pGUI->lineEdit_Login->setEchoMode ( QLineEdit::Normal );
     m_pGUI->pushButton_LoginHideShow->setIcon( Theme::getIcon("C_Dlg_Login/eyesOpenRed.png") );
     m_TimerLoginCount = 0;
    }
}

//---------------------------------------- Slot_lineEdit_Password_cursorPositionChanged -----------------------------------------
void C_Dlg_Login::Slot_lineEdit_Password_cursorPositionChanged (int , int)
{if (m_statePasswordEyes<=C_Dlg_Login::OnEdit)
    {m_pGUI->lineEdit_Password->setEchoMode ( QLineEdit::Normal );
     m_pGUI->pushButton_PasswordHideShow->setIcon( Theme::getIcon("C_Dlg_Login/eyesOpenRed.png") );
     m_TimerPasswordCount = 0;
    }
}

//---------------------------------------- Slot_TimerIsTimeOut -----------------------------------------
void C_Dlg_Login::Slot_TimerIsTimeOut()
{//................... le login ...........................
 if (m_stateLoginEyes==C_Dlg_Login::OnEdit)
    { if (m_TimerLoginCount>=6)
         {m_pGUI->lineEdit_Login->setEchoMode ( QLineEdit::Password );
          m_pGUI->pushButton_LoginHideShow->setIcon( Theme::getIcon("C_Dlg_Login/eyesOpenClose.png") );
         }
       else
        {
         if (m_TimerLoginCount&1)      m_pGUI->pushButton_LoginHideShow->setIcon( Theme::getIcon("C_Dlg_Login/eyesOpenClose.png") );
         else                          m_pGUI->pushButton_LoginHideShow->setIcon( Theme::getIcon("C_Dlg_Login/eyesOpenRed.png") );
        }
       ++ m_TimerLoginCount;
    }
else if (m_stateLoginEyes==C_Dlg_Login::Show)
    {m_pGUI->pushButton_LoginHideShow->setIcon( Theme::getIcon("C_Dlg_Login/eyesOpen.png") );
    }
else
    {m_pGUI->pushButton_LoginHideShow->setIcon( Theme::getIcon("C_Dlg_Login/eyesClose.png") );
    }
//................... le passsword ...........................
 if (m_statePasswordEyes==C_Dlg_Login::OnEdit)
    { if (m_TimerPasswordCount>=6)
         {m_pGUI->lineEdit_Password->setEchoMode ( QLineEdit::Password );
          m_pGUI->pushButton_PasswordHideShow->setIcon( Theme::getIcon("C_Dlg_Login/eyesOpenClose.png") );
         }
       else
        {
         if (m_TimerPasswordCount&1)   m_pGUI->pushButton_PasswordHideShow->setIcon( Theme::getIcon("C_Dlg_Login/eyesOpenClose.png") );
         else                          m_pGUI->pushButton_PasswordHideShow->setIcon( Theme::getIcon("C_Dlg_Login/eyesOpenRed.png") );
        }
       ++ m_TimerPasswordCount;
    }
 else if (m_statePasswordEyes==C_Dlg_Login::Show)
     {m_pGUI->pushButton_PasswordHideShow->setIcon( Theme::getIcon("C_Dlg_Login/eyesOpen.png") );
     }
 else
     {m_pGUI->pushButton_PasswordHideShow->setIcon( Theme::getIcon("C_Dlg_Login/eyesClose.png") );
     }
}

//---------------------------------------- Slot_pushButton_LoginHideShow -----------------------------------------
void C_Dlg_Login::Slot_pushButton_LoginHideShow  (bool)
{   m_stateLoginEyes = nextModeEditState (m_stateLoginEyes);
    set_LoginOnState(m_stateLoginEyes);
    if      (m_stateLoginEyes==C_Dlg_Login::Show)        C_AppCore::appCore()->writeParam("Login dialog","login visibility","show");
    else if (m_stateLoginEyes==C_Dlg_Login::Hide)        C_AppCore::appCore()->writeParam("Login dialog","login visibility","hide");
    else                                                 C_AppCore::appCore()->writeParam("Login dialog","login visibility","on edit");
    m_pGUI->lineEdit_Login->setFocus();
}
//---------------------------------------- Slot_pushButton_PasswordHideShow -----------------------------------------
void C_Dlg_Login::Slot_pushButton_PasswordHideShow  (bool)
{   m_statePasswordEyes = nextModeEditState (m_statePasswordEyes);
    set_PasswordOnState  (m_statePasswordEyes);
    if       (m_statePasswordEyes==C_Dlg_Login::Show)        C_AppCore::appCore()->writeParam("Login dialog","password visibility" ,"show");
    else  if (m_statePasswordEyes==C_Dlg_Login::Hide)        C_AppCore::appCore()->writeParam("Login dialog","password visibility" ,"hide");
    else                                                     C_AppCore::appCore()->writeParam("Login dialog","password visibility" ,"on edit");
    m_pGUI->lineEdit_Password->setFocus();
}

//---------------------------------------- set_LoginOnState -----------------------------------------
void C_Dlg_Login::set_LoginOnState  (C_Dlg_Login::Visibility  state)
{   if      (state==C_Dlg_Login::Show)           m_pGUI->pushButton_LoginHideShow->setIcon( Theme::getIcon("C_Dlg_Login/eyesOpen.png") );
    else if (state==C_Dlg_Login::Hide)           m_pGUI->pushButton_LoginHideShow->setIcon( Theme::getIcon("C_Dlg_Login/eyesClose.png") );
    else                                         m_pGUI->pushButton_LoginHideShow->setIcon( Theme::getIcon("C_Dlg_Login/eyesOpenClose.png") );
    if      (state==C_Dlg_Login::Show)           m_pGUI->lineEdit_Login->setEchoMode ( QLineEdit::Normal );
    else                                         m_pGUI->lineEdit_Login->setEchoMode ( QLineEdit::Password );
}
//---------------------------------------- set_PasswordOnState -----------------------------------------
void C_Dlg_Login::set_PasswordOnState  (C_Dlg_Login::Visibility state)
{   if      (state==C_Dlg_Login::Show)           m_pGUI->pushButton_PasswordHideShow->setIcon( Theme::getIcon("C_Dlg_Login/eyesOpen.png") );
    else if (state==C_Dlg_Login::Hide)           m_pGUI->pushButton_PasswordHideShow->setIcon( Theme::getIcon("C_Dlg_Login/eyesClose.png") );
    else                                         m_pGUI->pushButton_PasswordHideShow->setIcon( Theme::getIcon("C_Dlg_Login/eyesOpenClose.png") );
    if      (state==C_Dlg_Login::Show)           m_pGUI->lineEdit_Password->setEchoMode ( QLineEdit::Normal );
    else                                         m_pGUI->lineEdit_Password->setEchoMode ( QLineEdit::Password );
}
//---------------------------------------- Slot_pushButton_LoginCancel -----------------------------------------
void C_Dlg_Login::Slot_pushButton_LoginCancel  (bool) {QDialog::reject(); }

//---------------------------------------- Slot_pushButton_LoginOk -----------------------------------------
void C_Dlg_Login::Slot_pushButton_LoginOk  (bool)
{   m_nonCriptedLogin    = m_pGUI->lineEdit_Login->text().remove('#').trimmed();     // peut etre n'interdire que la premiere position pour '#'
    m_nonCriptedPassword = m_pGUI->lineEdit_Password->text().remove('#').trimmed();  // peut etre n'interdire que la premiere position pour '#'
    QDialog::accept();
}
//---------------------------------------- get_Login -----------------------------------------
QString C_Dlg_Login::get_Login()    {return m_nonCriptedLogin;}
//---------------------------------------- get_Password -----------------------------------------
QString C_Dlg_Login::get_Password() {return m_nonCriptedPassword;}
//---------------------------------------- get_CriptedLogin -----------------------------------------
QString C_Dlg_Login::get_CriptedLogin(const QString &prefix  /*= "" */)
{   QString str = C_AppCore::appCore()->unCriptedToCripted(m_nonCriptedLogin);
    str.prepend(prefix);
    return str;
}
//---------------------------------------- get_CriptedPassword -----------------------------------------
QString C_Dlg_Login::get_CriptedPassword( const QString &prefix/*= "" */)
{   QString str = C_AppCore::appCore()->unCriptedToCripted(m_nonCriptedPassword);
    str.prepend(prefix);
    return str;
    // return C_AppCore::appCore()->unCriptedToCripted(m_nonCriptedPassword).prepend(prefix); // plante
}
