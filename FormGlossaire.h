/****************************************************************************
** Form interface generated from reading ui file 'FormGlossaire.ui'
**
** Created: mer. mai 4 22:17:01 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FORMGLOSSAIRE_H
#define FORMGLOSSAIRE_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;

class FormGlossaire : public QWidget
{
    Q_OBJECT

public:
    FormGlossaire( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~FormGlossaire();

    QPushButton* pushButtonNewDir;
    QPushButton* pushButtonBack;
    QPushButton* pushButtonEdit;
    QPushButton* pushButtonMenu;
    QPushButton* pushButtonHome;
    QPushButton* pushButtonLocalise;

protected:
    QGridLayout* FormGlossaireLayout;
    QGridLayout* layout3;
    QSpacerItem* spacer1;

protected slots:
    virtual void languageChange();

};

#endif // FORMGLOSSAIRE_H
