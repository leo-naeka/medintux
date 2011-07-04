/****************************************************************************
** Form interface generated from reading ui file 'DlgChoixUser.ui'
**
** Created: mer. mai 4 22:17:01 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLGCHOIXUSER_H
#define DLGCHOIXUSER_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QSplitter;
class QListView;
class QListViewItem;
class QPushButton;
class QLabel;
class QLineEdit;

class DlgChoixUser : public QDialog
{
    Q_OBJECT

public:
    DlgChoixUser( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~DlgChoixUser();

    QSplitter* splitterCentral;
    QListView* ListView_UserList;
    QPushButton* pushButtonConfig;
    QLabel* textLabelPassWord;
    QLineEdit* lineEditPassWord;
    QPushButton* pushButtonOK;
    QPushButton* pushButtonAnnuler;

protected:
    QGridLayout* DlgChoixUserLayout;
    QVBoxLayout* layout8;
    QSpacerItem* spacer2;
    QSpacerItem* spacer1;
    QHBoxLayout* layout4;
    QHBoxLayout* layout2;
    QHBoxLayout* layout1;

protected slots:
    virtual void languageChange();

};

#endif // DLGCHOIXUSER_H
