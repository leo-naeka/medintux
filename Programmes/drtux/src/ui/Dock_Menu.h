/****************************************************************************
** Form interface generated from reading ui file 'Dock_Menu.ui'
**
** Created: mer. mai 4 22:17:02 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DOCK_MENU_H
#define DOCK_MENU_H

#include <qvariant.h>
#include <qwidget.h>
#include <qstringlist.h>
#include <qpixmap.h>
#include "CMoteur_Base.h"
#include "CRubList.h"
#include "C_Atcd.h"
#include "../../MedinTuxTools/CPrtQListViewItem.h"
#include "C_Var.h"
#include "../../MedinTuxTools/ThemePopup.h"

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLineEdit;
class QTextEdit;
class QLabel;
class QListView;
class QListViewItem;

class Dock_Menu : public QWidget
{
    Q_OBJECT

public:
    Dock_Menu( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Dock_Menu();

    QPushButton* but_NewIdent;
    QLineEdit* m_LineEdit_ToSearch;
    QTextEdit* m_Text_Note;
    QLabel* textLabel1;
    QListView* m_ListView_AccesRapide;
    QLabel* m_Lbl_Sexe;
    QLabel* m_Lbl_Nom;
    QPushButton* but_ZoomPlus;
    QPushButton* but_ZoomMinus;
    QPushButton* but_ZoomDefault;

    int m_ClickBehavior;
    bool m_ParentInBold;
    bool m_OpenATCD;
    int m_DefaultFontSize;
    bool m_Droits_Modif_ATCD;
    bool m_Droits_Modif_TTTFond;
    bool m_Droits_Modif_Variables;
    bool m_Droits_View_TTTFond;
    bool m_Droits_View_Variables;
    bool m_Droits_View_Prescriptions;
    bool m_Droits_View_Observations;
    bool m_Droits_View_Documents;
    bool m_Droits_View_Identite;
    bool m_Droits_View_Courriers;
    bool m_Droits_View_Certificats;
    bool m_Droits_View_ATCD;
    bool m_Droits_Create_Prescriptions;
    bool m_Droits_Create_Observations;
    bool m_Droits_Create_Documents;
    bool m_Droits_Create_Certificats;
    bool m_Droits_Create_Courriers;
    bool m_Droits_Create_ATCD;
    QString m_SelectedFile;
    bool m_ShowDoc;
    bool m_ShowPrescr;
    bool m_ShowObs;
    bool m_ShowIdentity;
    QString m_PkDocTerrain;
    bool m_IsFeminin;
    QString m_Identity;
    CPrtQListViewItem* m_Item_Vars;
    int m_Id_RubList_ToUseForThisTerrain;
    CPrtQListViewItem* m_Item_Intervenants;
    CPrtQListViewItem* m_Item_Documents;
    QPixmap m_PixMap_Parturiente ;
    CPrtQListViewItem* m_Item_Observations;
    QPixmap m_PixMap_Homme;
    CPrtQListViewItem* m_Item_Coordonnees;
    QString m_User;
    QString m_DossPrenom;
    QString m_DossNom;
    QString m_Id_Doss;
    QString m_GUID;
    RUBREC_LIST* m_pRubList;
    CMoteurBase* m_pCMoteurBase;
    CPrtQListViewItem* m_Item_ATCD;
    QPixmap m_PixMap_Femme;
    QStringList m_QStringList_ATCD;
    Atcd_Code* m_pAtcd_Code;
    CPrtQListViewItem* m_Item_Prescriptions;
    bool m_Notes_Changed;
    Var_Code* m_pVar_Code;
    ThemePopup* m_Popup;
    Atcd_Element* m_pAtcd_Element_Selected;
    int m_IsModifiable;
    bool m_ShowTerrain;
    bool m_ShowGlossaire;
    bool m_Droits_All;
    bool m_OpenTerrain;
    bool m_OpenObs;
    bool m_OpenPrescr;
    bool m_OpenDoc;
    bool m_OpenIdentity;
    bool m_OpenVars;
    QString m_TypeATCD_Selectionne;
    bool m_TerrainIsModified;
    bool m_OpenVisuNote;
    bool m_OpenInterv;
    bool m_ShowInterv;
    CPrtQListViewItem* m_Item_Terrains;

    virtual int directoryToPopup( ThemePopup * pPopup, QString path, int numSousMenus );

public slots:
    virtual void listView_AccesRapide_doubleClicked( QListViewItem * pQListViewItem, const QPoint &, int );
    virtual QStringList exeAnnuaire( QString idInterv );
    virtual void createIniParams( QString & paramString );
    virtual void getIniParams( QString & paramString );
    virtual void setParams( CMoteurBase * pCMoteurBase, RUBREC_LIST * pRubList, const char * num_GUID, const char * id_doss, const char * dossNom, const char * dossPrenom, const char * user, const char * droits, Atcd_Code * pAtcd_Code );
    virtual void createMenu();
    virtual void checkItemToSave();
    virtual void getTerrain( QString pkDoc );
    virtual void getTerrain();
    virtual void Slot_ChangeIdentity( const char * num_GUID, const char * id_doss, const char * dossNom, const char * dossPrenom, RUBREC_LIST * pRubList );
    virtual void getRubListAndUpdateView( RUBREC_LIST * pRubList );
    virtual void createIdentAndNote();
    virtual void getVarFromRubList();
    virtual void setSexeAndParturienteDisplay();
    virtual void ATCD_HaveChanged();
    virtual void getATCDFromRubList();
    virtual void getObservationsFromRubList();
    virtual void getPrescriptionsFromRubList();
    virtual void getIntervenants();
    virtual void getDocumentsFromRubList();
    virtual void m_ListView_AccesRapide_contextMenuRequested( QListViewItem * item, const QPoint & p, int );
    virtual void Terrain_createPopup( ThemePopup * pPopup, CPrtQListViewItem * );
    virtual void Observations_createPopup( ThemePopup * pPopup, CPrtQListViewItem * );
    virtual void Prescriptions_createPopup( ThemePopup * pPopup, CPrtQListViewItem * );
    virtual void Documents_createPopup( ThemePopup * pPopup, CPrtQListViewItem * );
    virtual void Droits_createPopup( ThemePopup * pPopup );
    virtual void ATCDRubriques_createPopup( ThemePopup * pQPopupMenu );
    virtual void ATCD_MenuActionSetRubrique();
    virtual void Slot_FileSelected();
    virtual void OnMenuActivated( int id );
    virtual void ATCD_createPopup( ThemePopup * pPopup, CPrtQListViewItem * pCPrt );
    virtual void ATCD_modifyDateGrossesse();
    virtual void ATCD_modifyCommentaire();
    virtual void ATCD_eraseIt();
    virtual void ATCD_changeEtat();
    virtual void ATCD_modifyDate();
    virtual void ATCD_ald_on();
    virtual void ATCD_ald_off();
    virtual void ATCD_view();
    virtual void ATCD_endGrossesse();
    virtual void ATCD_endAllaitement();
    virtual void ATCD_modifyIt();
    virtual void ATCD_addCIM10();
    virtual void ATCD_addTextuel();
    virtual void ATCD_addAllergie();
    virtual void m_ListView_AccesRapide_clicked( QListViewItem * item, const QPoint &, int );
    virtual void m_Text_Note_textChanged();
    virtual void setModifiableState( int state );
    virtual void SetInterfaceOnDroits( const QString & droits );
    virtual void but_ZoomPlus_clicked();
    virtual void but_ZoomMinus_clicked();
    virtual void but_ZoomDefault_clicked();
    virtual void m_LineEdit_ToSearch_returnPressed();
    virtual void but_NewIdent_clicked();
    virtual void synchronizeNoteWith( const char * txt );

signals:
    void Sign_ItemSelected( int );
    void Sign_ActiverDocument(QString , QString, int );
    void Sign_SearchPatient(QString);
    void Sign_ActiverRubrique( const char*, int );
    void Sign_GlossaireFileSelected(const char*, int);
    void Sign_CreateNewIdent();
    void Sign_NoteToBeSynchronized(int, const char* );

protected:
    QGridLayout* Dock_MenuLayout;
    QHBoxLayout* layout5;
    QVBoxLayout* layout7;
    QHBoxLayout* layout6;
    QHBoxLayout* layout6_2;
    QSpacerItem* spacer2_2;
    QHBoxLayout* layout5_2;

protected slots:
    virtual void languageChange();

private:
    void init();
    void destroy();

};

#endif // DOCK_MENU_H
