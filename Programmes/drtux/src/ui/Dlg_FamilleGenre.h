/****************************************************************************
** Form interface generated from reading ui file 'Dlg_FamilleGenre.ui'
**
** Created: mer. mai 4 22:17:02 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLG_FAMILLEGENRE_H
#define DLG_FAMILLEGENRE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QListView;
class QListViewItem;
class QLabel;

class Dlg_FamilleGenre : public QDialog
{
    Q_OBJECT

public:
    Dlg_FamilleGenre( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~Dlg_FamilleGenre();

    QPushButton* pushButton_Quit;
    QPushButton* pushButton_add_Genre;
    QPushButton* pushButton_add_Famille;
    QPushButton* pushButton_del;
    QPushButton* pushButton_save;
    QListView* listView_FamilleGenre;
    QLabel* textLabel1;

protected:
    QGridLayout* Dlg_FamilleGenreLayout;
    QSpacerItem* spacer1;

protected slots:
    virtual void languageChange();

};

#endif // DLG_FAMILLEGENRE_H
