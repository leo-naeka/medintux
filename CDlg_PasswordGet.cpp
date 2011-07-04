 /*************************** CDlg_PasswordGet.cpp *************************
 *  #include "CDlg_PasswordGet.h"                                          *
 * ........................................................................*
 *   Project   :  MedinTux  (typographie made in france)                   *
 *   Copyright :  (C) 2005-2006-2007-2008-2009-2010 and for the eternity   *
 *   by        :  Sevin Roland     from   MedinTux project                 *
 *   E-Mail    :  roland-sevin@medintux.org                                *
 *   Web site  :  www.medintux.org                                         *
 * ........................................................................*
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "CDlg_PasswordGet.h"
#include "../../MedinTuxTools-QT4/CMoteur_Base.h"
//------------------------------------------------------ CDlg_PasswordGet -------------------------------------------------------------------
CDlg_PasswordGet::CDlg_PasswordGet(QString *passToGet, QWidget *parent)
    :QDialog(parent), m_pPassToGet(passToGet)
{
    m_ui.setupUi(this);
    m_ui.lineEditPassword->setFocus();
    connect( m_ui.pushButtonOK,      SIGNAL( clicked() ), this, SLOT( accept() ) );
    connect( m_ui.pushButtonAnnuler, SIGNAL( clicked() ), this, SLOT( reject() ) );

}
CDlg_PasswordGet::CDlg_PasswordGet( QWidget *parent)
    :QDialog(parent), m_pPassToGet(0)
{
    m_ui.setupUi(this);
    m_ui.lineEditPassword->setFocus();
    connect( m_ui.pushButtonOK,      SIGNAL( clicked() ), this, SLOT( accept() ) );
    connect( m_ui.pushButtonAnnuler, SIGNAL( clicked() ), this, SLOT( reject() ) );

}


//------------------------------------------------------ changeEvent -------------------------------------------------------------------
void CDlg_PasswordGet::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui.retranslateUi(this);
        break;
    default:
        break;
    }
}

//------------------------------------------------------ ~CDlg_PasswordGet -------------------------------------------------------------------
CDlg_PasswordGet::~CDlg_PasswordGet()
{}

/*$SPECIALIZATION$*/
//------------------------------------------------------ reject -------------------------------------------------------------------
void CDlg_PasswordGet::reject()
{ QDialog::reject();
}

//------------------------------------------------------ accept -------------------------------------------------------------------
void CDlg_PasswordGet::accept()
{ if (m_pPassToGet)
  {QString pass = m_ui.lineEditPassword->text();
   CMoteurBase::PassWordEncode(pass);
   *m_pPassToGet = pass;
  }
  QDialog::accept();
}

//------------------------------------------------------ IsPasswordMustBeRecord -------------------------------------------------------------------
bool CDlg_PasswordGet::IsPasswordMustBeRecord()
{ return m_ui.checkBoxMemorise->isChecked();
}

