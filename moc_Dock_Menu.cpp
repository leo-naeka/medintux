/****************************************************************************
** Dock_Menu meta object code from reading C++ file 'Dock_Menu.h'
**
** Created: Wed May 4 22:20:49 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../ui/Dock_Menu.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#include <qvariant.h>
const char *Dock_Menu::className() const
{
    return "Dock_Menu";
}

QMetaObject *Dock_Menu::metaObj = 0;
static QMetaObjectCleanUp cleanUp_Dock_Menu( "Dock_Menu", &Dock_Menu::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString Dock_Menu::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Dock_Menu", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString Dock_Menu::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Dock_Menu", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* Dock_Menu::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"listView_AccesRapide_doubleClicked", 3, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_QVariant, "\x04", QUParameter::Out },
	{ "idInterv", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"exeAnnuaire", 2, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "paramString", &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod slot_2 = {"createIniParams", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "paramString", &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod slot_3 = {"getIniParams", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ "pCMoteurBase", &static_QUType_ptr, "CMoteurBase", QUParameter::In },
	{ "pRubList", &static_QUType_ptr, "RUBREC_LIST", QUParameter::In },
	{ "num_GUID", &static_QUType_charstar, 0, QUParameter::In },
	{ "id_doss", &static_QUType_charstar, 0, QUParameter::In },
	{ "dossNom", &static_QUType_charstar, 0, QUParameter::In },
	{ "dossPrenom", &static_QUType_charstar, 0, QUParameter::In },
	{ "user", &static_QUType_charstar, 0, QUParameter::In },
	{ "droits", &static_QUType_charstar, 0, QUParameter::In },
	{ "pAtcd_Code", &static_QUType_ptr, "Atcd_Code", QUParameter::In }
    };
    static const QUMethod slot_4 = {"setParams", 9, param_slot_4 };
    static const QUMethod slot_5 = {"createMenu", 0, 0 };
    static const QUMethod slot_6 = {"checkItemToSave", 0, 0 };
    static const QUParameter param_slot_7[] = {
	{ "pkDoc", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"getTerrain", 1, param_slot_7 };
    static const QUMethod slot_8 = {"getTerrain", 0, 0 };
    static const QUParameter param_slot_9[] = {
	{ "num_GUID", &static_QUType_charstar, 0, QUParameter::In },
	{ "id_doss", &static_QUType_charstar, 0, QUParameter::In },
	{ "dossNom", &static_QUType_charstar, 0, QUParameter::In },
	{ "dossPrenom", &static_QUType_charstar, 0, QUParameter::In },
	{ "pRubList", &static_QUType_ptr, "RUBREC_LIST", QUParameter::In }
    };
    static const QUMethod slot_9 = {"Slot_ChangeIdentity", 5, param_slot_9 };
    static const QUParameter param_slot_10[] = {
	{ "pRubList", &static_QUType_ptr, "RUBREC_LIST", QUParameter::In }
    };
    static const QUMethod slot_10 = {"getRubListAndUpdateView", 1, param_slot_10 };
    static const QUMethod slot_11 = {"createIdentAndNote", 0, 0 };
    static const QUMethod slot_12 = {"getVarFromRubList", 0, 0 };
    static const QUMethod slot_13 = {"setSexeAndParturienteDisplay", 0, 0 };
    static const QUMethod slot_14 = {"ATCD_HaveChanged", 0, 0 };
    static const QUMethod slot_15 = {"getATCDFromRubList", 0, 0 };
    static const QUMethod slot_16 = {"getObservationsFromRubList", 0, 0 };
    static const QUMethod slot_17 = {"getPrescriptionsFromRubList", 0, 0 };
    static const QUMethod slot_18 = {"getIntervenants", 0, 0 };
    static const QUMethod slot_19 = {"getDocumentsFromRubList", 0, 0 };
    static const QUParameter param_slot_20[] = {
	{ "item", &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ "p", &static_QUType_varptr, "\x0e", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_20 = {"m_ListView_AccesRapide_contextMenuRequested", 3, param_slot_20 };
    static const QUParameter param_slot_21[] = {
	{ "pPopup", &static_QUType_ptr, "ThemePopup", QUParameter::In },
	{ 0, &static_QUType_ptr, "CPrtQListViewItem", QUParameter::In }
    };
    static const QUMethod slot_21 = {"Terrain_createPopup", 2, param_slot_21 };
    static const QUParameter param_slot_22[] = {
	{ "pPopup", &static_QUType_ptr, "ThemePopup", QUParameter::In },
	{ 0, &static_QUType_ptr, "CPrtQListViewItem", QUParameter::In }
    };
    static const QUMethod slot_22 = {"Observations_createPopup", 2, param_slot_22 };
    static const QUParameter param_slot_23[] = {
	{ "pPopup", &static_QUType_ptr, "ThemePopup", QUParameter::In },
	{ 0, &static_QUType_ptr, "CPrtQListViewItem", QUParameter::In }
    };
    static const QUMethod slot_23 = {"Prescriptions_createPopup", 2, param_slot_23 };
    static const QUParameter param_slot_24[] = {
	{ "pPopup", &static_QUType_ptr, "ThemePopup", QUParameter::In },
	{ 0, &static_QUType_ptr, "CPrtQListViewItem", QUParameter::In }
    };
    static const QUMethod slot_24 = {"Documents_createPopup", 2, param_slot_24 };
    static const QUParameter param_slot_25[] = {
	{ "pPopup", &static_QUType_ptr, "ThemePopup", QUParameter::In }
    };
    static const QUMethod slot_25 = {"Droits_createPopup", 1, param_slot_25 };
    static const QUParameter param_slot_26[] = {
	{ "pQPopupMenu", &static_QUType_ptr, "ThemePopup", QUParameter::In }
    };
    static const QUMethod slot_26 = {"ATCDRubriques_createPopup", 1, param_slot_26 };
    static const QUMethod slot_27 = {"ATCD_MenuActionSetRubrique", 0, 0 };
    static const QUMethod slot_28 = {"Slot_FileSelected", 0, 0 };
    static const QUParameter param_slot_29[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_29 = {"OnMenuActivated", 1, param_slot_29 };
    static const QUParameter param_slot_30[] = {
	{ "pPopup", &static_QUType_ptr, "ThemePopup", QUParameter::In },
	{ "pCPrt", &static_QUType_ptr, "CPrtQListViewItem", QUParameter::In }
    };
    static const QUMethod slot_30 = {"ATCD_createPopup", 2, param_slot_30 };
    static const QUMethod slot_31 = {"ATCD_modifyDateGrossesse", 0, 0 };
    static const QUMethod slot_32 = {"ATCD_modifyCommentaire", 0, 0 };
    static const QUMethod slot_33 = {"ATCD_eraseIt", 0, 0 };
    static const QUMethod slot_34 = {"ATCD_changeEtat", 0, 0 };
    static const QUMethod slot_35 = {"ATCD_modifyDate", 0, 0 };
    static const QUMethod slot_36 = {"ATCD_ald_on", 0, 0 };
    static const QUMethod slot_37 = {"ATCD_ald_off", 0, 0 };
    static const QUMethod slot_38 = {"ATCD_view", 0, 0 };
    static const QUMethod slot_39 = {"ATCD_endGrossesse", 0, 0 };
    static const QUMethod slot_40 = {"ATCD_endAllaitement", 0, 0 };
    static const QUMethod slot_41 = {"ATCD_modifyIt", 0, 0 };
    static const QUMethod slot_42 = {"ATCD_addCIM10", 0, 0 };
    static const QUMethod slot_43 = {"ATCD_addTextuel", 0, 0 };
    static const QUMethod slot_44 = {"ATCD_addAllergie", 0, 0 };
    static const QUParameter param_slot_45[] = {
	{ "item", &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_45 = {"m_ListView_AccesRapide_clicked", 3, param_slot_45 };
    static const QUMethod slot_46 = {"m_Text_Note_textChanged", 0, 0 };
    static const QUParameter param_slot_47[] = {
	{ "state", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_47 = {"setModifiableState", 1, param_slot_47 };
    static const QUParameter param_slot_48[] = {
	{ "droits", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_48 = {"SetInterfaceOnDroits", 1, param_slot_48 };
    static const QUMethod slot_49 = {"but_ZoomPlus_clicked", 0, 0 };
    static const QUMethod slot_50 = {"but_ZoomMinus_clicked", 0, 0 };
    static const QUMethod slot_51 = {"but_ZoomDefault_clicked", 0, 0 };
    static const QUMethod slot_52 = {"m_LineEdit_ToSearch_returnPressed", 0, 0 };
    static const QUMethod slot_53 = {"but_NewIdent_clicked", 0, 0 };
    static const QUParameter param_slot_54[] = {
	{ "txt", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_54 = {"synchronizeNoteWith", 1, param_slot_54 };
    static const QUMethod slot_55 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "listView_AccesRapide_doubleClicked(QListViewItem*,const QPoint&,int)", &slot_0, QMetaData::Public },
	{ "exeAnnuaire(QString)", &slot_1, QMetaData::Public },
	{ "createIniParams(QString&)", &slot_2, QMetaData::Public },
	{ "getIniParams(QString&)", &slot_3, QMetaData::Public },
	{ "setParams(CMoteurBase*,RUBREC_LIST*,const char*,const char*,const char*,const char*,const char*,const char*,Atcd_Code*)", &slot_4, QMetaData::Public },
	{ "createMenu()", &slot_5, QMetaData::Public },
	{ "checkItemToSave()", &slot_6, QMetaData::Public },
	{ "getTerrain(QString)", &slot_7, QMetaData::Public },
	{ "getTerrain()", &slot_8, QMetaData::Public },
	{ "Slot_ChangeIdentity(const char*,const char*,const char*,const char*,RUBREC_LIST*)", &slot_9, QMetaData::Public },
	{ "getRubListAndUpdateView(RUBREC_LIST*)", &slot_10, QMetaData::Public },
	{ "createIdentAndNote()", &slot_11, QMetaData::Public },
	{ "getVarFromRubList()", &slot_12, QMetaData::Public },
	{ "setSexeAndParturienteDisplay()", &slot_13, QMetaData::Public },
	{ "ATCD_HaveChanged()", &slot_14, QMetaData::Public },
	{ "getATCDFromRubList()", &slot_15, QMetaData::Public },
	{ "getObservationsFromRubList()", &slot_16, QMetaData::Public },
	{ "getPrescriptionsFromRubList()", &slot_17, QMetaData::Public },
	{ "getIntervenants()", &slot_18, QMetaData::Public },
	{ "getDocumentsFromRubList()", &slot_19, QMetaData::Public },
	{ "m_ListView_AccesRapide_contextMenuRequested(QListViewItem*,const QPoint&,int)", &slot_20, QMetaData::Public },
	{ "Terrain_createPopup(ThemePopup*,CPrtQListViewItem*)", &slot_21, QMetaData::Public },
	{ "Observations_createPopup(ThemePopup*,CPrtQListViewItem*)", &slot_22, QMetaData::Public },
	{ "Prescriptions_createPopup(ThemePopup*,CPrtQListViewItem*)", &slot_23, QMetaData::Public },
	{ "Documents_createPopup(ThemePopup*,CPrtQListViewItem*)", &slot_24, QMetaData::Public },
	{ "Droits_createPopup(ThemePopup*)", &slot_25, QMetaData::Public },
	{ "ATCDRubriques_createPopup(ThemePopup*)", &slot_26, QMetaData::Public },
	{ "ATCD_MenuActionSetRubrique()", &slot_27, QMetaData::Public },
	{ "Slot_FileSelected()", &slot_28, QMetaData::Public },
	{ "OnMenuActivated(int)", &slot_29, QMetaData::Public },
	{ "ATCD_createPopup(ThemePopup*,CPrtQListViewItem*)", &slot_30, QMetaData::Public },
	{ "ATCD_modifyDateGrossesse()", &slot_31, QMetaData::Public },
	{ "ATCD_modifyCommentaire()", &slot_32, QMetaData::Public },
	{ "ATCD_eraseIt()", &slot_33, QMetaData::Public },
	{ "ATCD_changeEtat()", &slot_34, QMetaData::Public },
	{ "ATCD_modifyDate()", &slot_35, QMetaData::Public },
	{ "ATCD_ald_on()", &slot_36, QMetaData::Public },
	{ "ATCD_ald_off()", &slot_37, QMetaData::Public },
	{ "ATCD_view()", &slot_38, QMetaData::Public },
	{ "ATCD_endGrossesse()", &slot_39, QMetaData::Public },
	{ "ATCD_endAllaitement()", &slot_40, QMetaData::Public },
	{ "ATCD_modifyIt()", &slot_41, QMetaData::Public },
	{ "ATCD_addCIM10()", &slot_42, QMetaData::Public },
	{ "ATCD_addTextuel()", &slot_43, QMetaData::Public },
	{ "ATCD_addAllergie()", &slot_44, QMetaData::Public },
	{ "m_ListView_AccesRapide_clicked(QListViewItem*,const QPoint&,int)", &slot_45, QMetaData::Public },
	{ "m_Text_Note_textChanged()", &slot_46, QMetaData::Public },
	{ "setModifiableState(int)", &slot_47, QMetaData::Public },
	{ "SetInterfaceOnDroits(const QString&)", &slot_48, QMetaData::Public },
	{ "but_ZoomPlus_clicked()", &slot_49, QMetaData::Public },
	{ "but_ZoomMinus_clicked()", &slot_50, QMetaData::Public },
	{ "but_ZoomDefault_clicked()", &slot_51, QMetaData::Public },
	{ "m_LineEdit_ToSearch_returnPressed()", &slot_52, QMetaData::Public },
	{ "but_NewIdent_clicked()", &slot_53, QMetaData::Public },
	{ "synchronizeNoteWith(const char*)", &slot_54, QMetaData::Public },
	{ "languageChange()", &slot_55, QMetaData::Protected }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"Sign_ItemSelected", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"Sign_ActiverDocument", 3, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"Sign_SearchPatient", 1, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_3 = {"Sign_ActiverRubrique", 2, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_4 = {"Sign_GlossaireFileSelected", 2, param_signal_4 };
    static const QUMethod signal_5 = {"Sign_CreateNewIdent", 0, 0 };
    static const QUParameter param_signal_6[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod signal_6 = {"Sign_NoteToBeSynchronized", 2, param_signal_6 };
    static const QMetaData signal_tbl[] = {
	{ "Sign_ItemSelected(int)", &signal_0, QMetaData::Public },
	{ "Sign_ActiverDocument(QString,QString,int)", &signal_1, QMetaData::Public },
	{ "Sign_SearchPatient(QString)", &signal_2, QMetaData::Public },
	{ "Sign_ActiverRubrique(const char*,int)", &signal_3, QMetaData::Public },
	{ "Sign_GlossaireFileSelected(const char*,int)", &signal_4, QMetaData::Public },
	{ "Sign_CreateNewIdent()", &signal_5, QMetaData::Public },
	{ "Sign_NoteToBeSynchronized(int,const char*)", &signal_6, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"Dock_Menu", parentObject,
	slot_tbl, 56,
	signal_tbl, 7,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_Dock_Menu.setMetaObject( metaObj );
    return metaObj;
}

void* Dock_Menu::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "Dock_Menu" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL Sign_ItemSelected
void Dock_Menu::Sign_ItemSelected( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL Sign_ActiverDocument
void Dock_Menu::Sign_ActiverDocument( QString t0, QString t1, int t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_QString.set(o+1,t0);
    static_QUType_QString.set(o+2,t1);
    static_QUType_int.set(o+3,t2);
    activate_signal( clist, o );
}

// SIGNAL Sign_SearchPatient
void Dock_Menu::Sign_SearchPatient( QString t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 2, t0 );
}

// SIGNAL Sign_ActiverRubrique
void Dock_Menu::Sign_ActiverRubrique( const char* t0, int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 3 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_charstar.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL Sign_GlossaireFileSelected
void Dock_Menu::Sign_GlossaireFileSelected( const char* t0, int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 4 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_charstar.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL Sign_CreateNewIdent
void Dock_Menu::Sign_CreateNewIdent()
{
    activate_signal( staticMetaObject()->signalOffset() + 5 );
}

// SIGNAL Sign_NoteToBeSynchronized
void Dock_Menu::Sign_NoteToBeSynchronized( int t0, const char* t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 6 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_int.set(o+1,t0);
    static_QUType_charstar.set(o+2,t1);
    activate_signal( clist, o );
}

bool Dock_Menu::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: listView_AccesRapide_doubleClicked((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 1: static_QUType_QVariant.set(_o,QVariant(exeAnnuaire((QString)static_QUType_QString.get(_o+1)))); break;
    case 2: createIniParams((QString&)static_QUType_QString.get(_o+1)); break;
    case 3: getIniParams((QString&)static_QUType_QString.get(_o+1)); break;
    case 4: setParams((CMoteurBase*)static_QUType_ptr.get(_o+1),(RUBREC_LIST*)static_QUType_ptr.get(_o+2),(const char*)static_QUType_charstar.get(_o+3),(const char*)static_QUType_charstar.get(_o+4),(const char*)static_QUType_charstar.get(_o+5),(const char*)static_QUType_charstar.get(_o+6),(const char*)static_QUType_charstar.get(_o+7),(const char*)static_QUType_charstar.get(_o+8),(Atcd_Code*)static_QUType_ptr.get(_o+9)); break;
    case 5: createMenu(); break;
    case 6: checkItemToSave(); break;
    case 7: getTerrain((QString)static_QUType_QString.get(_o+1)); break;
    case 8: getTerrain(); break;
    case 9: Slot_ChangeIdentity((const char*)static_QUType_charstar.get(_o+1),(const char*)static_QUType_charstar.get(_o+2),(const char*)static_QUType_charstar.get(_o+3),(const char*)static_QUType_charstar.get(_o+4),(RUBREC_LIST*)static_QUType_ptr.get(_o+5)); break;
    case 10: getRubListAndUpdateView((RUBREC_LIST*)static_QUType_ptr.get(_o+1)); break;
    case 11: createIdentAndNote(); break;
    case 12: getVarFromRubList(); break;
    case 13: setSexeAndParturienteDisplay(); break;
    case 14: ATCD_HaveChanged(); break;
    case 15: getATCDFromRubList(); break;
    case 16: getObservationsFromRubList(); break;
    case 17: getPrescriptionsFromRubList(); break;
    case 18: getIntervenants(); break;
    case 19: getDocumentsFromRubList(); break;
    case 20: m_ListView_AccesRapide_contextMenuRequested((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 21: Terrain_createPopup((ThemePopup*)static_QUType_ptr.get(_o+1),(CPrtQListViewItem*)static_QUType_ptr.get(_o+2)); break;
    case 22: Observations_createPopup((ThemePopup*)static_QUType_ptr.get(_o+1),(CPrtQListViewItem*)static_QUType_ptr.get(_o+2)); break;
    case 23: Prescriptions_createPopup((ThemePopup*)static_QUType_ptr.get(_o+1),(CPrtQListViewItem*)static_QUType_ptr.get(_o+2)); break;
    case 24: Documents_createPopup((ThemePopup*)static_QUType_ptr.get(_o+1),(CPrtQListViewItem*)static_QUType_ptr.get(_o+2)); break;
    case 25: Droits_createPopup((ThemePopup*)static_QUType_ptr.get(_o+1)); break;
    case 26: ATCDRubriques_createPopup((ThemePopup*)static_QUType_ptr.get(_o+1)); break;
    case 27: ATCD_MenuActionSetRubrique(); break;
    case 28: Slot_FileSelected(); break;
    case 29: OnMenuActivated((int)static_QUType_int.get(_o+1)); break;
    case 30: ATCD_createPopup((ThemePopup*)static_QUType_ptr.get(_o+1),(CPrtQListViewItem*)static_QUType_ptr.get(_o+2)); break;
    case 31: ATCD_modifyDateGrossesse(); break;
    case 32: ATCD_modifyCommentaire(); break;
    case 33: ATCD_eraseIt(); break;
    case 34: ATCD_changeEtat(); break;
    case 35: ATCD_modifyDate(); break;
    case 36: ATCD_ald_on(); break;
    case 37: ATCD_ald_off(); break;
    case 38: ATCD_view(); break;
    case 39: ATCD_endGrossesse(); break;
    case 40: ATCD_endAllaitement(); break;
    case 41: ATCD_modifyIt(); break;
    case 42: ATCD_addCIM10(); break;
    case 43: ATCD_addTextuel(); break;
    case 44: ATCD_addAllergie(); break;
    case 45: m_ListView_AccesRapide_clicked((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 46: m_Text_Note_textChanged(); break;
    case 47: setModifiableState((int)static_QUType_int.get(_o+1)); break;
    case 48: SetInterfaceOnDroits((const QString&)static_QUType_QString.get(_o+1)); break;
    case 49: but_ZoomPlus_clicked(); break;
    case 50: but_ZoomMinus_clicked(); break;
    case 51: but_ZoomDefault_clicked(); break;
    case 52: m_LineEdit_ToSearch_returnPressed(); break;
    case 53: but_NewIdent_clicked(); break;
    case 54: synchronizeNoteWith((const char*)static_QUType_charstar.get(_o+1)); break;
    case 55: languageChange(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool Dock_Menu::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: Sign_ItemSelected((int)static_QUType_int.get(_o+1)); break;
    case 1: Sign_ActiverDocument((QString)static_QUType_QString.get(_o+1),(QString)static_QUType_QString.get(_o+2),(int)static_QUType_int.get(_o+3)); break;
    case 2: Sign_SearchPatient((QString)static_QUType_QString.get(_o+1)); break;
    case 3: Sign_ActiverRubrique((const char*)static_QUType_charstar.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 4: Sign_GlossaireFileSelected((const char*)static_QUType_charstar.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 5: Sign_CreateNewIdent(); break;
    case 6: Sign_NoteToBeSynchronized((int)static_QUType_int.get(_o+1),(const char*)static_QUType_charstar.get(_o+2)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool Dock_Menu::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool Dock_Menu::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
