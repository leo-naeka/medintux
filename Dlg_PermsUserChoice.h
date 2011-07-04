/****************************************************************************
** Form interface generated from reading ui file '../../gest_user/src/Dlg_PermsUserChoice.ui'
**
** Created: mer. mai 4 22:17:01 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLG_PERMSUSERCHOICE_H
#define DLG_PERMSUSERCHOICE_H

#include <qvariant.h>
#include <qdialog.h>
#include "../../drtux/src/CMoteur_Base.h"

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QSplitter;
class QPushButton;
class QLabel;
class QListView;
class QListViewItem;
class QButtonGroup;
class QRadioButton;
class QLineEdit;
class QComboBox;

class Dlg_PermsUserChoice : public QDialog
{
    Q_OBJECT

public:
    Dlg_PermsUserChoice( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~Dlg_PermsUserChoice();

    QSplitter* splitter1;
    QPushButton* pushButtonOk;
    QPushButton* pushButtonAnnuler;
    QLabel* textLabel_Entete;
    QListView* ListView_UserList;
    QButtonGroup* buttonGroup1;
    QRadioButton* radioButtonContient;
    QRadioButton* radioButtonCommence;
    QLineEdit* lineEditNom;
    QLabel* textLabel1;
    QComboBox* comboBox_Specialites;

    QStringList* m_pUserList;
    CMoteurBase *m_pCMoteurBase;

public slots:
    virtual void initDialog( CMoteurBase * pCMoteurBase, QStringList * pUserList, const QString & uniqueUser );
    virtual void pushButtonOk_clicked();
    virtual void setListViewOnUser( const QString & user );
    virtual void pushButtonAnnuler_clicked();
    virtual void ListView_UserList_doubleClicked( QListViewItem * );
    virtual void lineEditNom_textChanged( const QString & text );
    virtual void comboBox_Specialites_activated( const QString & str );

protected:
    QGridLayout* Dlg_PermsUserChoiceLayout;
    QGridLayout* buttonGroup1Layout;
    QHBoxLayout* layout1;

protected slots:
    virtual void languageChange();

private:
    void init();

};

#endif // DLG_PERMSUSERCHOICE_H
