/****************************************************************************
** Form interface generated from reading ui file 'RubTerrain.ui'
**
** Created: mer. mai 4 22:17:01 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FORMRUBTERRAIN_H
#define FORMRUBTERRAIN_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qwidget.h>
#include <qmap.h>
#include <qpopupmenu.h>
#include <qdialog.h>
#include <qtabwidget.h>
#include <qptrlist.h>
#include <qdatetime.h>
#include <qtable.h>
#include <qstringlist.h>
#include "CMoteur_Base.h"
#include "Global.h"
#include "CBigShrinker.h"
#include "CMyQtable.h"
#include "MyButton.h"
#include "../../MedinTuxTools/CMedicaBase.h"
#include "CApp.h"
#include "../../MedinTuxTools/CPrtQListBoxItem.h"
#include "C_Atcd.h"
#include "../../MedinTuxTools/ThemePopup.h"
#include "C_ListViewATCDManager.h"

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QSplitter;
class QListView;
class QListViewItem;
class QCheckBox;
class QComboBox;

class FormRubTerrain : public QWidget
{
    Q_OBJECT

public:
    FormRubTerrain( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~FormRubTerrain();

    QPushButton* pushButtonNewVAR;
    QPushButton* pushButtonDellAllVAR;
    QLabel* textLabel_VAR;
    QSplitter* splitter4;
    QPushButton* pushButtonNewATCD;
    QPushButton* pushButtonDellAllATCD;
    QLabel* textLabel_ATCD;
    QListView* listView_ATCD;
    QCheckBox* checkBoxGrossesse;
    QLabel* textLabelDDR;
    QPushButton* QPushButton_DDR;
    QCheckBox* checkBoxAllaitement;
    QPushButton* pushButtonNewTTT;
    QPushButton* pushButtonDellAllTTT;
    QLabel* textLabel_TTT_Encours;
    QListView* listView_TTT;
    QComboBox* comboBox_RubName;
    QPushButton* pushButtonRubDateChange;
    QPushButton* pushButtonSave;
    QPushButton* pushButtonDelete;
    QPushButton* pushButtonNew;

    int m_Selected_Id_RubList;
    QMap<int, ThemePopup* > m_PopupHeadMap;
    bool m_IsAllDroitsOn;
    int m_IsModifiable;
    int m_LastRub;
    QPtrList<CMyQTable> m_ptrListQTableVar;
    QPL_CPosologie m_OrdoList;
    QListViewItem *m_pQListViewItem ;
    RUBREC_LIST *m_pRubList;
    QString m_DossPrenom;
    QString m_DossNom;
    QString m_ID_Doss;
    CMoteurBase* m_pCMoteurBase;
    QString m_NumGUID;
    QScrollView* m_pQScrollView;
    CBigShrinker *m_pCBigShrinker;
    QVBoxLayout *m_pLayout_VAR;
    CMyQTable *m_pQTable;
    int m_IsModified;
    QString m_TypeATCD_Selectionne;
    Atcd_Code* m_pAtcd_Code;
    Atcd_Element* m_pAtcd_Element_Selected;
    C_ListViewATCDManager *m_pC_ListViewATCDManager;

    virtual int nbDate();
    virtual float PoidsToTaille( float poids, QString sexe );
    virtual QString GetTaille( float poids );
    virtual QString GetTaille();
    virtual int IfModified_SaveInRubList();
    virtual void VAR_SetTaille( QString taille );
    virtual CMyQTable * VAR_getTableValue( QDateTime * dt_deb, QDateTime * dt_max, const QString & table_name, const QString & col_name, QString & value, int * col_ret );
    virtual QString VAR_GetLastValeurVarTable( const QString & table_name, const QString & col_name );
    virtual void VAR_CreateTable( const char * text );
    virtual long VAR_RearangeTable();
    virtual long initComboRubName( void );
    virtual void ATCD_MenuActionChangeEtat( int etat );
    virtual int Current_RubList_ID();
    virtual RUBREC_LIST::iterator Current_RubList_Iterator();
    virtual int SetCurentDocByPrimkey( const QString & primKey );

public slots:
    virtual void ButtonSaveDisplay( const QString & );
    virtual void sexeAndParturienteDisplay();
    virtual void setModifiedState( int state );
    virtual void SetInterfaceOnDroits( const QString & droits );
    virtual void Set_ATCD_Visible( int state );
    virtual void Set_TTT_Visible( int state );
    virtual void Set_VAR_Visible( int state );
    virtual void SetModifiableState( int state );
    virtual void cacher();
    virtual void montrer( int nb );
    virtual int SetData();
    virtual QString GetSurface();
    virtual QString GetPoids();
    virtual void pushButtonNew_clicked();
    virtual void NEW_MenuActionWithCopy();
    virtual void NEW_MenuActionWithoutVarValue();
    virtual void NEW_MenuActionWithEmptyCopy();
    virtual void NEW_MenuActionWithBlankCopy();
    virtual void NEW_AddNewTerrain( QString & data );
    virtual void comboBox_RubName_highlighted( int item );
    virtual void comboBox_RubName_activated( int item );
    virtual void ATCD_HaveChanged();
    virtual void ATCD_setInForm();
    virtual void FormToData( QString & strDST );
    virtual void clearForm();
    virtual void DataToForm();
    virtual void Slot_OnValueTableChanged( int, int, CMyQTable * );
    virtual void VAR_SetPoids( QString poids );
    virtual void VAR_SetPoidsTaille( QString poids, QString taille );
    virtual void VAR_addValueInTable( CMyQTable * pCMyQTable, QStringList & valueList );
    virtual void ClearAllTableValues();
    virtual void pushButtonNewVAR_clicked();
    virtual void newVAR_Add( const char * fileName );
    virtual void pushButtonDellAllVAR_clicked();
    virtual void Slot_AllTableDelete();
    virtual void Slot_TableButtonClicked( const char *, void * ptr );
    virtual void VAR_MenuActionDelete();
    virtual void VAR_MenuActionChangeDate();
    virtual void VAR_MenuActionNewDate();
    virtual void VAR_MenuActionConfig();
    virtual void VAR_MenuActionDetruireVar();
    virtual void Slot_TableNewDateClicked( const char * name, void * ptr );
    virtual void OnCMyQTableClicked( CMyQTable * pCMyQTable, const char * name, int, int, int, const QPoint & );
    virtual void pushButtonSave_clicked();
    virtual void VAR_GetModeleList( QString & strDST, int areValueToBeListed );
    virtual void listView_TTT_contextMenuRequested( QListViewItem * qlistViewItem, const QPoint & pos, int );
    virtual void TTT_SlotMenuActionModifier();
    virtual void Alert_WriteOnly();
    virtual void TTT_PutPrescriptionInTerrain( RUBREC_LIST::iterator it );
    virtual int TTT_MenuActionModifier();
    virtual void TTT_MenuActionRenouveler();
    virtual void TTT_MenuActionPrescrire();
    virtual void TTT_MenuActionSetRenouveler();
    virtual void TTT_MenuActionSetIntercurent();
    virtual void TTT_OrdoListToListView( QListView * pQListView, QPL_CPosologie & ordo_list );
    virtual void listView_TTT_doubleClicked( QListViewItem * );
    virtual void pushButtonNewTTT_clicked();
    virtual void pushButtonDellAllTTT_clicked();
    virtual void Add_popMenu_ATCD_Type( QPopupMenu * pQPopupMenu );
    virtual void listView_ATCD_contextMenuRequested( QListViewItem * qlistViewItem, const QPoint & pos, int c );
    virtual void ATCD_setAldOn();
    virtual void ATCD_setAldOff();
    virtual void ATCD_setAldOnOff( const QString & state );
    virtual void listView_ATCD_doubleClicked( QListViewItem * pQListViewItem );
    virtual void ATCD_MenuActionNewFromFavori();
    virtual void ATCD_MenuActionNewCIM10();
    virtual void ATCD_MenuActionSetDate();
    virtual void ATCD_MenuActionDelDate();
    virtual void ATCD_MenuActionNewAllergie();
    virtual void ATCD_MenuActionNewTexteLibre();
    virtual void ATCD_MenuActionDel();
    virtual void ATCD_MenuActionMultiDel();
    virtual void ATCD_MenuActionChangeEtatGueri();
    virtual void ATCD_MenuActionChangeEtatActif();
    virtual void ATCD_MenuActionSetFamilleGenre();
    virtual void ATCD_MenuActionSetCommentaire();
    virtual void pushButtonNewATCD_clicked();
    virtual void pushButtonDellAllATCD_clicked();
    virtual void StringToEscapeString( QString & str );
    virtual void EscapeStringToString( QString & str );
    virtual void checkBoxGrossesse_clicked();
    virtual void checkBoxAllaitement_clicked();
    virtual void QPushButton_DDR_clicked();
    virtual void pushButtonDelete_clicked();
    virtual void pushButtonRubDateChange_clicked();

signals:
    void Sign_SaveButtonClicked();
    void Sign_Renouveler(const QString &strData, int typ, const char *path );

protected:
    QGridLayout* FormRubTerrainLayout;
    QHBoxLayout* layout10;
    QVBoxLayout* layout9;
    QVBoxLayout* layout14;
    QHBoxLayout* layout13;
    QVBoxLayout* layout10_2;
    QHBoxLayout* layout9_2;
    QSpacerItem* spacer1;
    QVBoxLayout* layout12;
    QHBoxLayout* layout11;
    QHBoxLayout* layout10_3;
    QSpacerItem* spacer2;
    QSpacerItem* spacer3;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;

    void init();

};

#endif // FORMRUBTERRAIN_H
