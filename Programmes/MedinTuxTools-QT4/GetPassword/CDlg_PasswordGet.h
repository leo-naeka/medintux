 /*************************** CDlg_PasswordGet.h ***************************
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
#ifndef CDLG_PASSWORDGET_H
#define CDLG_PASSWORDGET_H

#include "ui_CDlg_PasswordGet.h"

class CDlg_PasswordGet : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(CDlg_PasswordGet)
public:
    explicit CDlg_PasswordGet(QString *passToGet, QWidget *parent = 0);
    explicit CDlg_PasswordGet(QWidget *parent = 0);
    ~CDlg_PasswordGet();
    bool      IsPasswordMustBeRecord();
    void      reject();
    void      accept();
protected:
    virtual void changeEvent(QEvent *e);
    QString *m_pPassToGet;
private:
    Ui::CDlg_PasswordGet m_ui;
};

#endif // CDLG_PASSWORDGET_H
