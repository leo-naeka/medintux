/****************************************************************************
** Form interface generated from reading ui file 'DlgDateNom.ui'
**
** Created: mer. mai 4 22:17:01 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLGDATENOM_H
#define DLGDATENOM_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class CMaskedLineEdit;
class QLabel;
class QLineEdit;
class QPushButton;

class DlgDateNom : public QDialog
{
    Q_OBJECT

public:
    DlgDateNom( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~DlgDateNom();

    QLabel* textLabelDate;
    QLabel* textLabelNom_2;
    QLabel* textLabelNom;
    QLabel* textLabelDate_2;
    QLineEdit* lineEdit_SubType;
    QPushButton* pushButtonOK;
    CMaskedLineEdit* cMaskedLineEditDate;
    QLineEdit* lineEditNom;
    CMaskedLineEdit* cMaskedLineEditTime;
    QPushButton* pushButtonDateDlg;

    QString *m_pNom;
    QString *m_pDateTime;
    QString *m_pSubType;

public slots:
    virtual void initDialog( QString * date_time, QString * nom, QString * subType );
    virtual void Slot_pushButtonDateDlg();
    virtual void pushButtonOK_clicked();

protected:
    QGridLayout* DlgDateNomLayout;
    QGridLayout* layout10;
    QGridLayout* layout3;
    QSpacerItem* spacer2;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;

};

#endif // DLGDATENOM_H
