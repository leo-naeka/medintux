/****************************************************************************
** Form interface generated from reading ui file 'RubChoixPatient.ui'
**
** Created: mer. mai 4 22:17:01 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FORMRUBCHOIXPATIENT_H
#define FORMRUBCHOIXPATIENT_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qwidget.h>
#include <qsqldatabase.h>
#include "CMoteur_Base.h"
#include "../../MedinTuxTools/CPrtQListViewItem.h"

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLineEdit;
class QListView;
class QListViewItem;
class QLabel;
class QPushButton;
class QCheckBox;

class FormRubChoixPatient : public QWidget
{
    Q_OBJECT

public:
    FormRubChoixPatient( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~FormRubChoixPatient();

    QLineEdit* lineEditAutoLocator;
    QListView* ListView_Patient;
    QLabel* textLabel_StateList;
    QPushButton* pushButtonNew;
    QCheckBox* checkBoxAutre;
    QPushButton* pushButtonInfo;

    QString m_DossPrenom;
    QString m_ID_Doss;
    QString m_NumGUID;
    QString m_DossNom;
    CMoteurBase* m_pCMoteurBase;
    QString m_User;

public slots:
    virtual void SetInterfaceOnDroits( const QString & droits );
    virtual void InitAllList( const QString & qstr_nom, const QString & qstr_prenom );
    virtual void reinitList( const char *, const char * id_doss, const char *, const char * );
    virtual void Slot_SearchFor( QString patient );
    virtual void lineEditAutoLocator_textChanged( const QString & qstr_in );
    virtual void ListView_Patient_clicked( QListViewItem * qlistViewItem );
    virtual void ListView_Patient_selectionChanged( QListViewItem * qlistViewItem );
    virtual void RestaureLastGUID();
    virtual void pushButtonNew_clicked();
    virtual void pushButtonDelete_clicked();
    virtual void checkBoxAutre_clicked();
    virtual void pushButtonInfo_clicked();

signals:
    void Sign_IdentChange(const char*, const char*, const char*, const char* );
    void Sign_CreateNewIdent();
    void Sign_IdentDelete(const char*, const char*, const char*, const char* );
    void Sign_DrTuxExeAnother(QString, QString, QString, QString);
    void Sign_GetActiveGUID(QString &);

protected:
    QString m_LastGUID;

    QGridLayout* FormRubChoixPatientLayout;
    QHBoxLayout* layout2;
    QSpacerItem* spacer1;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;

    void init();

};

#endif // FORMRUBCHOIXPATIENT_H
