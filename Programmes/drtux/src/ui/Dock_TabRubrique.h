/****************************************************************************
** Form interface generated from reading ui file 'Dock_TabRubrique.ui'
**
** Created: mer. mai 4 22:17:01 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DOCK_TABRUBRIQUE_H
#define DOCK_TABRUBRIQUE_H

#include <qvariant.h>
#include <qwidget.h>
#include <qptrlist.h>
#include "MyButton.h"
#include "Global.h"

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;

class Dock_TabRubrique : public QWidget
{
    Q_OBJECT

public:
    Dock_TabRubrique( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Dock_TabRubrique();


    QPtrList<CMyButton> m_QPtrButtonList;

public slots:
    virtual void On_ButtonClicked( const char * butTxt );
    virtual void SetInterfaceOnDroits( const QString & droits );

signals:
    void Sign_ActiverOrCreateRubrique(const char*, int);

protected:
    QGridLayout* Dock_TabRubriqueLayout;

protected slots:
    virtual void languageChange();

private:
    void init();

};

#endif // DOCK_TABRUBRIQUE_H
