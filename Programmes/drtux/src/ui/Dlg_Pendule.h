/****************************************************************************
** Form interface generated from reading ui file 'Dlg_Pendule.ui'
**
** Created: mer. mai 4 22:17:02 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLG_PENDULE_H
#define DLG_PENDULE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLineEdit;
class QTimeEdit;
class QPushButton;

class Dlg_Pendule : public QDialog
{
    Q_OBJECT

public:
    Dlg_Pendule( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~Dlg_Pendule();

    QLineEdit* lineEdit_MinutesRef;
    QTimeEdit* timeEdit_Temps;
    QPushButton* pushButton_Ok;
    QPushButton* pushButton_Exit;

protected:
    QGridLayout* Dlg_PenduleLayout;
    QHBoxLayout* layout_Button;

protected slots:
    virtual void languageChange();

};

#endif // DLG_PENDULE_H
