/****************************************************************************
** Form interface generated from reading ui file 'RubPrescription.ui'
**
** Created: mer. mai 4 22:17:01 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FORMRUBPRESCRIPTION_H
#define FORMRUBPRESCRIPTION_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qwidget.h>
#include <qsqldatabase.h>
#include <qimage.h>
#include <qpopupmenu.h>
#include "CMoteur_Base.h"
#include "MyEditText.h"
#include "Global.h"
#include "CMDI_Terrain.h"

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QComboBox;
class QLabel;

class FormRubPrescription : public QWidget
{
    Q_OBJECT

public:
    FormRubPrescription( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~FormRubPrescription();

    QPushButton* textLabel_NbRub;
    QComboBox* comboBox_RubName;
    QPushButton* pushButtonRubDateChange;
    QLabel* textLabel1;
    QLabel* textLabel_UserName;
    QPushButton* pushButtonSave;
    QPushButton* pushButtonPrint;
    QPushButton* pushButtonDelete;
    QPushButton* pushButtonPlus;
    QPushButton* pushButtonVidal;

    int m_IsModifiable;
    QString m_DossPrenom;
    QString m_ID_Doss;
    QString m_NumGUID;
    CMoteurBase* m_pCMoteurBase;
    QString m_DossNom;
    MyEditText* m_pMyEditText;
    RUBREC_LIST *m_pRubList;
    int m_LastRub;
    QString m_User;
    QString m_CurrentPopupItem;
    QString m_RetPopupItem;
    QPopupMenu *m_pQPopupMenu;

    virtual QString DoPopupList( QStringList & list );
    virtual long initComboListOrdo( void );
    virtual int IfModified_SaveInRubList();
    virtual int Current_RubList_ID();
    virtual RUBREC_LIST::iterator Current_RubList_Iterator();
    virtual int SetCurentDocByPrimkey( const QString & primKey );
    virtual int GetCurrentOrdoList( QPL_CPosologie & ordo_List );

public slots:
    virtual void pushButtonPlus_clicked();
    virtual void On_buttonDragClicked();
    virtual void pushButtonByPrincipe_clicked();
    virtual void listView_Produits_rightButtonClicked( QListViewItem *, const QPoint &, int );
    virtual void OnMenuActivated( int id );
    virtual void GetPopupItem();
    virtual void SetModifiableState( int state );
    virtual void InitText( MyEditText * pMyEditText );
    virtual void FormPatientList_destroyed( QObject * );
    virtual int SetData();
    virtual void comboBox_RubName_highlighted( int item );
    virtual void comboBox_RubName_activated( int item );
    virtual void PutDataInRubList( RUBREC_LIST::iterator it );
    virtual void pushButtonDelete_clicked();
    virtual void pushButtonSave_clicked();
    virtual void pushButtonVidal_clicked();
    virtual void pushButtonRubDateChange_clicked();
    virtual void SetRubDateName( const QString & name, const QString & date );
    virtual void SaveTextInRubList();

signals:
    void Sign_SaveButtonClicked();
    void Sign_RubChanged(RUBREC_LIST::iterator);
    void Sign_DuplicateData(RUBREC_LIST::iterator, QDateTime &, const QString&, const QString&);
    void Sign_PutPrescriptionInTerrain(RUBREC_LIST::iterator);
    void Sign_Renouveler_TTT_Fond();

protected:
    bool m_IsBaseMedEnabled;

    QGridLayout* FormRubPrescriptionLayout;
    QHBoxLayout* layout1;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;

    void init();

};

#endif // FORMRUBPRESCRIPTION_H
