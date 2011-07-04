/****************************************************************************
** Form interface generated from reading ui file 'Dlg_HtmlView.ui'
**
** Created: mer. mai 4 22:17:01 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLG_HTMLVIEW_H
#define DLG_HTMLVIEW_H

#include <qvariant.h>
#include <qdialog.h>
#include "Global.h"

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTextBrowser;

class Dlg_HtmlView : public QDialog
{
    Q_OBJECT

public:
    Dlg_HtmlView( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~Dlg_HtmlView();

    QTextBrowser* textBrowser;

protected:
    QGridLayout* Dlg_HtmlViewLayout;

protected slots:
    virtual void languageChange();

private:
    void init();

};

#endif // DLG_HTMLVIEW_H
