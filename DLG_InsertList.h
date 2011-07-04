/****************************************************************************
** Form interface generated from reading ui file '../../MedinTuxTools/DLG_InsertList.ui'
**
** Created: mer. mai 4 22:17:01 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLG_INSERTLIST_H
#define DLG_INSERTLIST_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QListBox;
class QListBoxItem;
class QLineEdit;

class Dlg_InsertList : public QDialog
{
    Q_OBJECT

public:
    Dlg_InsertList( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~Dlg_InsertList();

    QPushButton* pushButtonOk;
    QLabel* textLabel1;
    QListBox* listBox_InsertList;
    QLineEdit* lineEdit_Find;

public slots:
    virtual void initDialog( QStringList & pQStringList );
    virtual void initDialogField( QStringList & pQStringList, int nbField, const QString & modeSel );
    virtual void lineEdit_Find_textChanged( const QString & text_in );
    virtual void listBox_InsertList_doubleClicked( QListBoxItem * pQListBoxItem );
    virtual void pushButtonOk_clicked();
    virtual void listBox_InsertList_returnPressed( QListBoxItem * pQListBoxItem );

protected:
    QGridLayout* Dlg_InsertListLayout;
    QSpacerItem* spacer1;
    QGridLayout* layout1;

protected slots:
    virtual void languageChange();

private:
    void init();

};

#endif // DLG_INSERTLIST_H
