/****************************************************************************
** Form interface generated from reading ui file '../../MedinTuxTools/DlgListOff_Listes.ui'
**
** Created: mer. mai 4 22:17:01 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FORMDLGLISTOFF_LISTES_H
#define FORMDLGLISTOFF_LISTES_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QListBox;
class QListBoxItem;
class QPushButton;
class QLineEdit;
class QLabel;

class FormDlgListOff_Listes : public QDialog
{
    Q_OBJECT

public:
    FormDlgListOff_Listes( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~FormDlgListOff_Listes();

    QListBox* listBoxListes;
    QPushButton* but_Valide;
    QPushButton* but_Annule;
    QLineEdit* lineEdit_Find;
    QLabel* textLabel1;

    QString m_ItemName;
    QString m_PathGlossaire;

    virtual QString getSelectedItem();

public slots:
    virtual void setPath( const char * path );
    virtual void initDialog( QString pathListItem );
    virtual void lineEdit_Find_textChanged( const QString & text );
    virtual void listBoxListes_clicked( QListBoxItem * pQListBoxItem );
    virtual void listBoxListes_returnPressed( QListBoxItem * pQListBoxItem );
    virtual void but_Annule_clicked();
    virtual void but_Valide_clicked();

protected:
    QGridLayout* FormDlgListOff_ListesLayout;
    QHBoxLayout* layout2;
    QSpacerItem* spacer1;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;

    void init();

};

#endif // FORMDLGLISTOFF_LISTES_H
