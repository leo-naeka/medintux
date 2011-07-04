/****************************************************************************
** Form interface generated from reading ui file 'Dlg_AboutDrTux.ui'
**
** Created: mer. mai 4 22:17:01 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLG_ABOUTDRTUX_H
#define DLG_ABOUTDRTUX_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;

class Dlg_AboutDrTux : public QDialog
{
    Q_OBJECT

public:
    Dlg_AboutDrTux( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~Dlg_AboutDrTux();

    QLabel* textLabel_Image;

    virtual void init();

protected:
    QGridLayout* Dlg_AboutDrTuxLayout;

protected slots:
    virtual void languageChange();

};

#endif // DLG_ABOUTDRTUX_H
