/****************************************************************************
** Form interface generated from reading ui file '../../MedinTuxTools/DlgMyMessageBox.ui'
**
** Created: mer. mai 4 22:17:01 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FORMDLGMYMESSAGEBOX_H
#define FORMDLGMYMESSAGEBOX_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTextEdit;
class QPushButton;

class FormDlgMyMessageBox : public QDialog
{
    Q_OBJECT

public:
    FormDlgMyMessageBox( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~FormDlgMyMessageBox();

    QTextEdit* textEditMesage;
    QPushButton* pushButton1;
    QPushButton* pushButton2;
    QPushButton* pushButton3;
    QPushButton* pushButton4;

public slots:
    virtual void pushButton1_clicked();
    virtual void pushButton2_clicked();
    virtual void pushButton3_clicked();
    virtual void pushButton4_clicked();

protected:
    QGridLayout* FormDlgMyMessageBoxLayout;
    QVBoxLayout* layout1;

protected slots:
    virtual void languageChange();

};

#endif // FORMDLGMYMESSAGEBOX_H
