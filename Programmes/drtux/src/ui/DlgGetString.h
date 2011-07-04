/****************************************************************************
** Form interface generated from reading ui file '../../MedinTuxTools/DlgGetString.ui'
**
** Created: mer. mai 4 22:17:01 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FORMDLGGETSTRING_H
#define FORMDLGGETSTRING_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLineEdit;
class QTextBrowser;

class FormDlgGetString : public QDialog
{
    Q_OBJECT

public:
    FormDlgGetString( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~FormDlgGetString();

    QPushButton* pushButtonOK;
    QPushButton* pushButtonCancel;
    QLineEdit* lineEditString;
    QTextBrowser* textBrowserInfo;

public slots:
    virtual void pushButtonCancel_pressed();
    virtual void pushButtonOK_clicked();

protected:
    QGridLayout* FormDlgGetStringLayout;
    QSpacerItem* spacer1;

protected slots:
    virtual void languageChange();

};

#endif // FORMDLGGETSTRING_H
