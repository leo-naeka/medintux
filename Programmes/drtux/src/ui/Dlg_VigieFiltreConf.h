/****************************************************************************
** Form interface generated from reading ui file 'Dlg_VigieFiltreConf.ui'
**
** Created: mer. mai 4 22:17:02 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLG_VIGIEFILTRECONF_H
#define DLG_VIGIEFILTRECONF_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QTextEdit;
class QLineEdit;
class QTextBrowser;

class Dlg_VigieFiltreConf : public QDialog
{
    Q_OBJECT

public:
    Dlg_VigieFiltreConf( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~Dlg_VigieFiltreConf();

    QPushButton* pushButton_Annuler;
    QPushButton* pushButton_Ok;
    QLabel* textLabel2;
    QTextEdit* textEdit_Authorized;
    QLineEdit* lineEdit_FiltreName;
    QLabel* textLabel1;
    QTextBrowser* textBrowser1;

protected:
    QGridLayout* Dlg_VigieFiltreConfLayout;
    QGridLayout* layout1;
    QGridLayout* layout2;

protected slots:
    virtual void languageChange();

};

#endif // DLG_VIGIEFILTRECONF_H
