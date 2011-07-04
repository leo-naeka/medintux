/****************************************************************************
** Form interface generated from reading ui file 'DlgGetText.ui'
**
** Created: mer. mai 4 22:17:01 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLGGETTEXT_H
#define DLGGETTEXT_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTextEdit;
class QPushButton;

class DlgGetText : public QDialog
{
    Q_OBJECT

public:
    DlgGetText( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~DlgGetText();

    QTextEdit* textEdit;
    QPushButton* pushButtonOK;
    QPushButton* pushButtonCancel;
    QPushButton* pushButtonClearAndQuit;

public slots:
    virtual void pushButtonOK_clicked();
    virtual void pushButtonCancel_clicked();
    virtual void pushButtonClearAndQuit_clicked();

protected:
    QGridLayout* DlgGetTextLayout;
    QSpacerItem* spacer1;

protected slots:
    virtual void languageChange();

};

#endif // DLGGETTEXT_H
