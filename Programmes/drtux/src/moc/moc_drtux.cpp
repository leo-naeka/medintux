/****************************************************************************
** C_UserQAction meta object code from reading C++ file 'drtux.h'
**
** Created: Wed May 4 22:20:11 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../drtux.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *C_UserQAction::className() const
{
    return "C_UserQAction";
}

QMetaObject *C_UserQAction::metaObj = 0;
static QMetaObjectCleanUp cleanUp_C_UserQAction( "C_UserQAction", &C_UserQAction::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString C_UserQAction::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_UserQAction", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString C_UserQAction::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_UserQAction", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* C_UserQAction::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QAction::staticMetaObject();
    static const QUMethod slot_0 = {"Slot_UserQActionOn_TimerDone", 0, 0 };
    static const QUMethod slot_1 = {"Slot_On_UserQAction_Activated", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "Slot_UserQActionOn_TimerDone()", &slot_0, QMetaData::Private },
	{ "Slot_On_UserQAction_Activated()", &slot_1, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "C_UserQAction", QUParameter::In }
    };
    static const QUMethod signal_0 = {"Sign_UserQAction_TimerDone", 2, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "C_UserQAction", QUParameter::In }
    };
    static const QUMethod signal_1 = {"Sign_UserQAction_Activated", 2, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "Sign_UserQAction_TimerDone(const QString&,C_UserQAction*)", &signal_0, QMetaData::Private },
	{ "Sign_UserQAction_Activated(const QString&,C_UserQAction*)", &signal_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"C_UserQAction", parentObject,
	slot_tbl, 2,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_C_UserQAction.setMetaObject( metaObj );
    return metaObj;
}

void* C_UserQAction::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "C_UserQAction" ) )
	return this;
    return QAction::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL Sign_UserQAction_TimerDone
void C_UserQAction::Sign_UserQAction_TimerDone( const QString& t0, C_UserQAction* t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_QString.set(o+1,t0);
    static_QUType_ptr.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL Sign_UserQAction_Activated
void C_UserQAction::Sign_UserQAction_Activated( const QString& t0, C_UserQAction* t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_QString.set(o+1,t0);
    static_QUType_ptr.set(o+2,t1);
    activate_signal( clist, o );
}

bool C_UserQAction::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: Slot_UserQActionOn_TimerDone(); break;
    case 1: Slot_On_UserQAction_Activated(); break;
    default:
	return QAction::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool C_UserQAction::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: Sign_UserQAction_TimerDone((const QString&)static_QUType_QString.get(_o+1),(C_UserQAction*)static_QUType_ptr.get(_o+2)); break;
    case 1: Sign_UserQAction_Activated((const QString&)static_QUType_QString.get(_o+1),(C_UserQAction*)static_QUType_ptr.get(_o+2)); break;
    default:
	return QAction::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool C_UserQAction::qt_property( int id, int f, QVariant* v)
{
    return QAction::qt_property( id, f, v);
}

bool C_UserQAction::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *DrTux::className() const
{
    return "DrTux";
}

QMetaObject *DrTux::metaObj = 0;
static QMetaObjectCleanUp cleanUp_DrTux( "DrTux", &DrTux::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString DrTux::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "DrTux", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString DrTux::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "DrTux", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* DrTux::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QMainWindow::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out }
    };
    static const QUMethod slot_0 = {"SauverDossierAvantNouvelleAction", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out },
	{ "mode", &static_QUType_ptr, "SAVE_Mode", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SauverDossierAvantNouvelleAction", 2, param_slot_1 };
    static const QUMethod slot_2 = {"Slot_SauverLesMeubles", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ "path", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"recordPathModulesMenus", 1, param_slot_3 };
    static const QUMethod slot_4 = {"Slot_OnGlossaireLocalise", 0, 0 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"SlotMakeVisible", 1, param_slot_5 };
    static const QUMethod slot_6 = {"setZoom8", 0, 0 };
    static const QUMethod slot_7 = {"setZoom9", 0, 0 };
    static const QUMethod slot_8 = {"setZoom10", 0, 0 };
    static const QUMethod slot_9 = {"setZoom11", 0, 0 };
    static const QUMethod slot_10 = {"setZoom12", 0, 0 };
    static const QUMethod slot_11 = {"setZoom14", 0, 0 };
    static const QUMethod slot_12 = {"setZoom16", 0, 0 };
    static const QUMethod slot_13 = {"setZoom18", 0, 0 };
    static const QUMethod slot_14 = {"setZoom20", 0, 0 };
    static const QUMethod slot_15 = {"AutoSetActiveWindow", 0, 0 };
    static const QUMethod slot_16 = {"AfficheRubriques", 0, 0 };
    static const QUMethod slot_17 = {"Slot_TestVerrou", 0, 0 };
    static const QUMethod slot_18 = {"Slot_MenuRubriques", 0, 0 };
    static const QUMethod slot_19 = {"ActiverVigie", 0, 0 };
    static const QUParameter param_slot_20[] = {
	{ "guid", &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod slot_20 = {"Slot_GetActiveGUID", 1, param_slot_20 };
    static const QUParameter param_slot_21[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::Out },
	{ "docPk", &static_QUType_QString, 0, QUParameter::In },
	{ "rubName", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_21 = {"Slot_ActiverDocument", 3, param_slot_21 };
    static const QUParameter param_slot_22[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::Out },
	{ "docPk", &static_QUType_QString, 0, QUParameter::In },
	{ "rubName", &static_QUType_QString, 0, QUParameter::In },
	{ "mode", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_22 = {"Slot_ActiverDocument", 4, param_slot_22 };
    static const QUParameter param_slot_23[] = {
	{ "emetteur", &static_QUType_int, 0, QUParameter::In },
	{ "txt", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_23 = {"Slot_NoteToBeSynchronized", 2, param_slot_23 };
    static const QUParameter param_slot_24[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::Out }
    };
    static const QUMethod slot_24 = {"Slot_RecordDispos", 1, param_slot_24 };
    static const QUParameter param_slot_25[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::Out },
	{ "rubName", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_25 = {"IsExistRubrique", 2, param_slot_25 };
    static const QUParameter param_slot_26[] = {
	{ 0, &static_QUType_ptr, "CMDI_Generic", QUParameter::Out },
	{ "rubTyp", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_26 = {"IsExistRubrique", 2, param_slot_26 };
    static const QUParameter param_slot_27[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::Out }
    };
    static const QUMethod slot_27 = {"GetCurrentRubrique", 1, param_slot_27 };
    static const QUParameter param_slot_28[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::Out },
	{ "pRubName", &static_QUType_varptr, "\x03", QUParameter::In }
    };
    static const QUMethod slot_28 = {"GetCurrentRubrique", 2, param_slot_28 };
    static const QUParameter param_slot_29[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::Out },
	{ "pRubName", &static_QUType_varptr, "\x03", QUParameter::In },
	{ "rub_type", &static_QUType_varptr, "\x10", QUParameter::In }
    };
    static const QUMethod slot_29 = {"GetCurrentRubrique", 3, param_slot_29 };
    static const QUParameter param_slot_30[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::Out },
	{ "pRubName", &static_QUType_varptr, "\x03", QUParameter::In },
	{ "rub_type", &static_QUType_varptr, "\x10", QUParameter::In },
	{ "ppCRubRecord", &static_QUType_ptr, "CRubRecord*", QUParameter::InOut }
    };
    static const QUMethod slot_30 = {"GetCurrentRubrique", 4, param_slot_30 };
    static const QUParameter param_slot_31[] = {
	{ "path", &static_QUType_QString, 0, QUParameter::In },
	{ "action", &static_QUType_QString, 0, QUParameter::In },
	{ "typ", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_31 = {"OnGlossaireFileToEdit", 3, param_slot_31 };
    static const QUParameter param_slot_32[] = {
	{ "it", &static_QUType_ptr, "RUBREC_LIST::iterator", QUParameter::In },
	{ "qdt", &static_QUType_varptr, "\x1c", QUParameter::InOut },
	{ "libelle", &static_QUType_QString, 0, QUParameter::In },
	{ "subType", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_32 = {"DuplicateRecordWithNewDate", 4, param_slot_32 };
    static const QUParameter param_slot_33[] = {
	{ 0, &static_QUType_ptr, "CRubRecord", QUParameter::Out },
	{ "path", &static_QUType_charstar, 0, QUParameter::In },
	{ "mode", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_33 = {"OnGlossaireFileClicked", 3, param_slot_33 };
    static const QUParameter param_slot_34[] = {
	{ 0, &static_QUType_ptr, "CRubRecord", QUParameter::Out },
	{ "path", &static_QUType_charstar, 0, QUParameter::In },
	{ "mode", &static_QUType_int, 0, QUParameter::In },
	{ "noInquire", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_34 = {"OnGlossaireFileClicked", 4, param_slot_34 };
    static const QUParameter param_slot_35[] = {
	{ 0, &static_QUType_ptr, "CRubRecord", QUParameter::Out },
	{ "strData", &static_QUType_QString, 0, QUParameter::In },
	{ "typ", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_35 = {"AddNewRecordToRubrique", 3, param_slot_35 };
    static const QUParameter param_slot_36[] = {
	{ 0, &static_QUType_ptr, "CRubRecord", QUParameter::Out },
	{ "strData", &static_QUType_QString, 0, QUParameter::In },
	{ "typ", &static_QUType_int, 0, QUParameter::In },
	{ "path", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_36 = {"AddNewRecordToRubrique", 4, param_slot_36 };
    static const QUParameter param_slot_37[] = {
	{ 0, &static_QUType_ptr, "CRubRecord", QUParameter::Out },
	{ "strData", &static_QUType_QString, 0, QUParameter::In },
	{ "typ", &static_QUType_int, 0, QUParameter::In },
	{ "path", &static_QUType_charstar, 0, QUParameter::In },
	{ "pQDateTime", &static_QUType_varptr, "\x1c", QUParameter::In }
    };
    static const QUMethod slot_37 = {"AddNewRecordToRubrique", 5, param_slot_37 };
    static const QUParameter param_slot_38[] = {
	{ 0, &static_QUType_ptr, "CRubRecord", QUParameter::Out },
	{ "strData", &static_QUType_QString, 0, QUParameter::In },
	{ "typ", &static_QUType_int, 0, QUParameter::In },
	{ "path", &static_QUType_charstar, 0, QUParameter::In },
	{ "pQDateTime", &static_QUType_varptr, "\x1c", QUParameter::In },
	{ "libelle", &static_QUType_varptr, "\x03", QUParameter::In }
    };
    static const QUMethod slot_38 = {"AddNewRecordToRubrique", 6, param_slot_38 };
    static const QUParameter param_slot_39[] = {
	{ 0, &static_QUType_ptr, "CRubRecord", QUParameter::Out },
	{ "strData", &static_QUType_QString, 0, QUParameter::In },
	{ "typ", &static_QUType_int, 0, QUParameter::In },
	{ "path", &static_QUType_charstar, 0, QUParameter::In },
	{ "pQDateTime", &static_QUType_varptr, "\x1c", QUParameter::In },
	{ "libelle", &static_QUType_varptr, "\x03", QUParameter::In },
	{ "subType", &static_QUType_varptr, "\x03", QUParameter::In }
    };
    static const QUMethod slot_39 = {"AddNewRecordToRubrique", 7, param_slot_39 };
    static const QUParameter param_slot_40[] = {
	{ 0, &static_QUType_ptr, "CRubRecord", QUParameter::Out },
	{ "strData", &static_QUType_QString, 0, QUParameter::In },
	{ "typ", &static_QUType_int, 0, QUParameter::In },
	{ "path", &static_QUType_charstar, 0, QUParameter::In },
	{ "pQDateTime", &static_QUType_varptr, "\x1c", QUParameter::In },
	{ "libelle", &static_QUType_varptr, "\x03", QUParameter::In },
	{ "subType", &static_QUType_varptr, "\x03", QUParameter::In },
	{ "noInquire", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_40 = {"AddNewRecordToRubrique", 8, param_slot_40 };
    static const QUMethod slot_41 = {"OnDrTuxSaveRubList", 0, 0 };
    static const QUMethod slot_42 = {"SetTitle", 0, 0 };
    static const QUMethod slot_43 = {"recordProfil", 0, 0 };
    static const QUMethod slot_44 = {"add_ATCD_Favori", 0, 0 };
    static const QUMethod slot_45 = {"add_ATCD_Allergique", 0, 0 };
    static const QUMethod slot_46 = {"modifier_TTT_Fond", 0, 0 };
    static const QUMethod slot_47 = {"add_ATCD_Libre", 0, 0 };
    static const QUMethod slot_48 = {"add_CIM10", 0, 0 };
    static const QUParameter param_slot_49[] = {
	{ "visible", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_49 = {"On_Vigie_visibilityChanged", 1, param_slot_49 };
    static const QUParameter param_slot_50[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out },
	{ "date", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_50 = {"GetPossibleObservationDate", 2, param_slot_50 };
    static const QUMethod slot_51 = {"OnQuitterDrTux", 0, 0 };
    static const QUMethod slot_52 = {"OnMenuQuitterDrTux", 0, 0 };
    static const QUMethod slot_53 = {"OnCreateNewDoc", 0, 0 };
    static const QUMethod slot_54 = {"Codage_CCAM", 0, 0 };
    static const QUMethod slot_55 = {"PasteLabo", 0, 0 };
    static const QUMethod slot_56 = {"OnDrTuxUserChange", 0, 0 };
    static const QUParameter param_slot_57[] = {
	{ "droits", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_57 = {"SetInterfaceOnDroits", 1, param_slot_57 };
    static const QUParameter param_slot_58[] = {
	{ "num_GUID", &static_QUType_QString, 0, QUParameter::In },
	{ "id_doss", &static_QUType_QString, 0, QUParameter::In },
	{ "dossNom", &static_QUType_QString, 0, QUParameter::In },
	{ "dossPrenom", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_58 = {"OnDrTuxExeAnother", 4, param_slot_58 };
    static const QUParameter param_slot_59[] = {
	{ "num_GUID", &static_QUType_charstar, 0, QUParameter::In },
	{ "id_doss", &static_QUType_charstar, 0, QUParameter::In },
	{ "dossNom", &static_QUType_charstar, 0, QUParameter::In },
	{ "dossPrenom", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_59 = {"OnDrTuxPatientListMustBeUpdated", 4, param_slot_59 };
    static const QUParameter param_slot_60[] = {
	{ "num_GUID", &static_QUType_charstar, 0, QUParameter::In },
	{ "id_doss", &static_QUType_charstar, 0, QUParameter::In },
	{ "dossNom", &static_QUType_charstar, 0, QUParameter::In },
	{ "dossPrenom", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_60 = {"OnDrTuxIdentModified", 4, param_slot_60 };
    static const QUParameter param_slot_61[] = {
	{ "num_GUID", &static_QUType_charstar, 0, QUParameter::In },
	{ "id_doss", &static_QUType_charstar, 0, QUParameter::In },
	{ "dossNom", &static_QUType_charstar, 0, QUParameter::In },
	{ "dossPrenom", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_61 = {"OnDrTuxIdentChange", 4, param_slot_61 };
    static const QUParameter param_slot_62[] = {
	{ "num_GUID", &static_QUType_charstar, 0, QUParameter::In },
	{ "id_doss", &static_QUType_charstar, 0, QUParameter::In },
	{ "dossNom", &static_QUType_charstar, 0, QUParameter::In },
	{ "dossPrenom", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_62 = {"OnDrTuxIdentDelete", 4, param_slot_62 };
    static const QUMethod slot_63 = {"OnDrTuxIdentCurrentDelete", 0, 0 };
    static const QUParameter param_slot_64[] = {
	{ "rubName", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_64 = {"OnActiverRubrique", 1, param_slot_64 };
    static const QUParameter param_slot_65[] = {
	{ "rubName", &static_QUType_charstar, 0, QUParameter::In },
	{ "mode", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_65 = {"OnActiverRubrique", 2, param_slot_65 };
    static const QUParameter param_slot_66[] = {
	{ "rubName", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_66 = {"OnActiverOrCreateRubrique", 1, param_slot_66 };
    static const QUParameter param_slot_67[] = {
	{ "rubName", &static_QUType_charstar, 0, QUParameter::In },
	{ "mode", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_67 = {"OnActiverOrCreateRubrique", 2, param_slot_67 };
    static const QUParameter param_slot_68[] = {
	{ "rubName", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_68 = {"OnDeleteRubrique", 1, param_slot_68 };
    static const QUParameter param_slot_69[] = {
	{ "pQwidget", &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod slot_69 = {"OnOngletRubriquesChanged", 1, param_slot_69 };
    static const QUMethod slot_70 = {"OnCreateNewIdent", 0, 0 };
    static const QUParameter param_slot_71[] = {
	{ "primKey", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_71 = {"On_CreateNewRootInOrganiseur", 1, param_slot_71 };
    static const QUParameter param_slot_72[] = {
	{ "file", &static_QUType_QString, 0, QUParameter::In },
	{ "pDocSerialize", &static_QUType_varptr, "\x03", QUParameter::In }
    };
    static const QUMethod slot_72 = {"On_DragFileInOrganiseur", 2, param_slot_72 };
    static const QUMethod slot_73 = {"setupDocks", 0, 0 };
    static const QUMethod slot_74 = {"Slot_SetDockMenu_AccesRapide", 0, 0 };
    static const QUMethod slot_75 = {"Slot_SetDockMenu_Glossaire", 0, 0 };
    static const QUMethod slot_76 = {"Slot_SetDockMenu_RubriquesButton", 0, 0 };
    static const QUMethod slot_77 = {"Slot_SetDockMenu_Organiseur", 0, 0 };
    static const QUMethod slot_78 = {"setupFileActions", 0, 0 };
    static const QUMethod slot_79 = {"setupTextActions", 0, 0 };
    static const QUMethod slot_80 = {"setupEditActions", 0, 0 };
    static const QUMethod slot_81 = {"setupToolsActions", 0, 0 };
    static const QUMethod slot_82 = {"setupToolsTerrain", 0, 0 };
    static const QUMethod slot_83 = {"setupVigieActions", 0, 0 };
    static const QUParameter param_slot_84[] = {
	{ 0, &static_QUType_ptr, "MyEditText", QUParameter::Out }
    };
    static const QUMethod slot_84 = {"currentEditor", 1, param_slot_84 };
    static const QUParameter param_slot_85[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_85 = {"textFamily", 1, param_slot_85 };
    static const QUMethod slot_86 = {"textItalic", 0, 0 };
    static const QUMethod slot_87 = {"textBold", 0, 0 };
    static const QUMethod slot_88 = {"textUnderline", 0, 0 };
    static const QUMethod slot_89 = {"textColor", 0, 0 };
    static const QUParameter param_slot_90[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_90 = {"textSize", 1, param_slot_90 };
    static const QUParameter param_slot_91[] = {
	{ 0, &static_QUType_ptr, "QAction", QUParameter::In }
    };
    static const QUMethod slot_91 = {"textAlign", 1, param_slot_91 };
    static const QUParameter param_slot_92[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_92 = {"textStyle", 1, param_slot_92 };
    static const QUMethod slot_93 = {"editUndo", 0, 0 };
    static const QUMethod slot_94 = {"editRedo", 0, 0 };
    static const QUMethod slot_95 = {"editCut", 0, 0 };
    static const QUMethod slot_96 = {"editCopy", 0, 0 };
    static const QUMethod slot_97 = {"editPaste", 0, 0 };
    static const QUMethod slot_98 = {"editSelectAll", 0, 0 };
    static const QUMethod slot_99 = {"fast_textColor", 0, 0 };
    static const QUMethod slot_100 = {"getFormConfig", 0, 0 };
    static const QUParameter param_slot_101[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod slot_101 = {"editorChanged", 1, param_slot_101 };
    static const QUParameter param_slot_102[] = {
	{ "f", &static_QUType_varptr, "\x05", QUParameter::In }
    };
    static const QUMethod slot_102 = {"fontChanged", 1, param_slot_102 };
    static const QUParameter param_slot_103[] = {
	{ "c", &static_QUType_varptr, "\x0a", QUParameter::In }
    };
    static const QUMethod slot_103 = {"colorChanged", 1, param_slot_103 };
    static const QUParameter param_slot_104[] = {
	{ "a", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_104 = {"alignmentChanged", 1, param_slot_104 };
    static const QUParameter param_slot_105[] = {
	{ "e", &static_QUType_ptr, "QTextEdit", QUParameter::In }
    };
    static const QUMethod slot_105 = {"doConnections", 1, param_slot_105 };
    static const QUMethod slot_106 = {"CodageCim10All", 0, 0 };
    static const QUMethod slot_107 = {"ListManager", 0, 0 };
    static const QUMethod slot_108 = {"CreateList", 0, 0 };
    static const QUMethod slot_109 = {"DisplayContextListPopup", 0, 0 };
    static const QUMethod slot_110 = {"VidalDataSemp", 0, 0 };
    static const QUMethod slot_111 = {"UserChange", 0, 0 };
    static const QUParameter param_slot_112[] = {
	{ "plugin", &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod slot_112 = {"Slot_ExePlugin", 1, param_slot_112 };
    static const QUParameter param_slot_113[] = {
	{ "mixture", &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod slot_113 = {"Slot_ExeMixture", 1, param_slot_113 };
    static const QUMethod slot_114 = {"Slot_Renouveler_TTT_Fond", 0, 0 };
    static const QUParameter param_slot_115[] = {
	{ "it", &static_QUType_ptr, "RUBREC_LIST::iterator", QUParameter::In }
    };
    static const QUMethod slot_115 = {"Slot_PutPrescriptionInTerrain", 1, param_slot_115 };
    static const QUMethod slot_116 = {"OnSign_Ident_KillMe", 0, 0 };
    static const QUMethod slot_117 = {"TimedDeleteRubIdentite", 0, 0 };
    static const QUMethod slot_118 = {"Fenetres_en_cascade", 0, 0 };
    static const QUMethod slot_119 = {"Fenetres_en_mosaique", 0, 0 };
    static const QUMethod slot_120 = {"Fenetres_RetablirPosition", 0, 0 };
    static const QUMethod slot_121 = {"Fenetres_Identiques", 0, 0 };
    static const QUMethod slot_122 = {"savePos", 0, 0 };
    static const QUMethod slot_123 = {"saveOnlyChildPos", 0, 0 };
    static const QUParameter param_slot_124[] = {
	{ "mode", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_124 = {"savePos", 1, param_slot_124 };
    static const QUMethod slot_125 = {"Slot_actionApropos", 0, 0 };
    static const QUMethod slot_126 = {"Slot_actionAproposDisplay", 0, 0 };
    static const QUMethod slot_127 = {"tryToStopAPropos", 0, 0 };
    static const QUMethod slot_128 = {"filePrint", 0, 0 };
    static const QUMethod slot_129 = {"about", 0, 0 };
    static const QUMethod slot_130 = {"aboutQt", 0, 0 };
    static const QUParameter param_slot_131[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::Out },
	{ "script", &static_QUType_QString, 0, QUParameter::In },
	{ "pQAction", &static_QUType_ptr, "C_UserQAction", QUParameter::In }
    };
    static const QUMethod slot_131 = {"Slot_On_UserQAction_TimerDone", 3, param_slot_131 };
    static const QUParameter param_slot_132[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::Out },
	{ "script", &static_QUType_QString, 0, QUParameter::In },
	{ "pQAction", &static_QUType_ptr, "C_UserQAction", QUParameter::In }
    };
    static const QUMethod slot_132 = {"Slot_On_UserQAction_Activated", 3, param_slot_132 };
    static const QMetaData slot_tbl[] = {
	{ "SauverDossierAvantNouvelleAction()", &slot_0, QMetaData::Public },
	{ "SauverDossierAvantNouvelleAction(SAVE_Mode)", &slot_1, QMetaData::Public },
	{ "Slot_SauverLesMeubles()", &slot_2, QMetaData::Public },
	{ "recordPathModulesMenus(QString)", &slot_3, QMetaData::Public },
	{ "Slot_OnGlossaireLocalise()", &slot_4, QMetaData::Public },
	{ "SlotMakeVisible(const QString&)", &slot_5, QMetaData::Public },
	{ "setZoom8()", &slot_6, QMetaData::Public },
	{ "setZoom9()", &slot_7, QMetaData::Public },
	{ "setZoom10()", &slot_8, QMetaData::Public },
	{ "setZoom11()", &slot_9, QMetaData::Public },
	{ "setZoom12()", &slot_10, QMetaData::Public },
	{ "setZoom14()", &slot_11, QMetaData::Public },
	{ "setZoom16()", &slot_12, QMetaData::Public },
	{ "setZoom18()", &slot_13, QMetaData::Public },
	{ "setZoom20()", &slot_14, QMetaData::Public },
	{ "AutoSetActiveWindow()", &slot_15, QMetaData::Public },
	{ "AfficheRubriques()", &slot_16, QMetaData::Public },
	{ "Slot_TestVerrou()", &slot_17, QMetaData::Public },
	{ "Slot_MenuRubriques()", &slot_18, QMetaData::Public },
	{ "ActiverVigie()", &slot_19, QMetaData::Public },
	{ "Slot_GetActiveGUID(QString&)", &slot_20, QMetaData::Public },
	{ "Slot_ActiverDocument(QString,QString)", &slot_21, QMetaData::Public },
	{ "Slot_ActiverDocument(QString,QString,int)", &slot_22, QMetaData::Public },
	{ "Slot_NoteToBeSynchronized(int,const char*)", &slot_23, QMetaData::Public },
	{ "Slot_RecordDispos()", &slot_24, QMetaData::Public },
	{ "IsExistRubrique(const char*)", &slot_25, QMetaData::Public },
	{ "IsExistRubrique(int)", &slot_26, QMetaData::Public },
	{ "GetCurrentRubrique()", &slot_27, QMetaData::Public },
	{ "GetCurrentRubrique(QString*)", &slot_28, QMetaData::Public },
	{ "GetCurrentRubrique(QString*,int*)", &slot_29, QMetaData::Public },
	{ "GetCurrentRubrique(QString*,int*,CRubRecord**)", &slot_30, QMetaData::Public },
	{ "OnGlossaireFileToEdit(QString,QString,int)", &slot_31, QMetaData::Public },
	{ "DuplicateRecordWithNewDate(RUBREC_LIST::iterator,QDateTime&,const QString&,const QString&)", &slot_32, QMetaData::Public },
	{ "OnGlossaireFileClicked(const char*,int)", &slot_33, QMetaData::Public },
	{ "OnGlossaireFileClicked(const char*,int,int)", &slot_34, QMetaData::Public },
	{ "AddNewRecordToRubrique(const QString&,int)", &slot_35, QMetaData::Public },
	{ "AddNewRecordToRubrique(const QString&,int,const char*)", &slot_36, QMetaData::Public },
	{ "AddNewRecordToRubrique(const QString&,int,const char*,const QDateTime*)", &slot_37, QMetaData::Public },
	{ "AddNewRecordToRubrique(const QString&,int,const char*,const QDateTime*,const QString*)", &slot_38, QMetaData::Public },
	{ "AddNewRecordToRubrique(const QString&,int,const char*,const QDateTime*,const QString*,const QString*)", &slot_39, QMetaData::Public },
	{ "AddNewRecordToRubrique(const QString&,int,const char*,const QDateTime*,const QString*,const QString*,int)", &slot_40, QMetaData::Public },
	{ "OnDrTuxSaveRubList()", &slot_41, QMetaData::Public },
	{ "SetTitle()", &slot_42, QMetaData::Public },
	{ "recordProfil()", &slot_43, QMetaData::Public },
	{ "add_ATCD_Favori()", &slot_44, QMetaData::Public },
	{ "add_ATCD_Allergique()", &slot_45, QMetaData::Public },
	{ "modifier_TTT_Fond()", &slot_46, QMetaData::Public },
	{ "add_ATCD_Libre()", &slot_47, QMetaData::Public },
	{ "add_CIM10()", &slot_48, QMetaData::Public },
	{ "On_Vigie_visibilityChanged(bool)", &slot_49, QMetaData::Public },
	{ "GetPossibleObservationDate(const QString&)", &slot_50, QMetaData::Public },
	{ "OnQuitterDrTux()", &slot_51, QMetaData::Public },
	{ "OnMenuQuitterDrTux()", &slot_52, QMetaData::Public },
	{ "OnCreateNewDoc()", &slot_53, QMetaData::Public },
	{ "Codage_CCAM()", &slot_54, QMetaData::Public },
	{ "PasteLabo()", &slot_55, QMetaData::Public },
	{ "OnDrTuxUserChange()", &slot_56, QMetaData::Public },
	{ "SetInterfaceOnDroits(const QString&)", &slot_57, QMetaData::Public },
	{ "OnDrTuxExeAnother(QString,QString,QString,QString)", &slot_58, QMetaData::Public },
	{ "OnDrTuxPatientListMustBeUpdated(const char*,const char*,const char*,const char*)", &slot_59, QMetaData::Public },
	{ "OnDrTuxIdentModified(const char*,const char*,const char*,const char*)", &slot_60, QMetaData::Public },
	{ "OnDrTuxIdentChange(const char*,const char*,const char*,const char*)", &slot_61, QMetaData::Public },
	{ "OnDrTuxIdentDelete(const char*,const char*,const char*,const char*)", &slot_62, QMetaData::Public },
	{ "OnDrTuxIdentCurrentDelete()", &slot_63, QMetaData::Public },
	{ "OnActiverRubrique(const char*)", &slot_64, QMetaData::Public },
	{ "OnActiverRubrique(const char*,int)", &slot_65, QMetaData::Public },
	{ "OnActiverOrCreateRubrique(const char*)", &slot_66, QMetaData::Public },
	{ "OnActiverOrCreateRubrique(const char*,int)", &slot_67, QMetaData::Public },
	{ "OnDeleteRubrique(const char*)", &slot_68, QMetaData::Public },
	{ "OnOngletRubriquesChanged(QWidget*)", &slot_69, QMetaData::Public },
	{ "OnCreateNewIdent()", &slot_70, QMetaData::Public },
	{ "On_CreateNewRootInOrganiseur(QString)", &slot_71, QMetaData::Public },
	{ "On_DragFileInOrganiseur(QString,QString*)", &slot_72, QMetaData::Public },
	{ "setupDocks()", &slot_73, QMetaData::Public },
	{ "Slot_SetDockMenu_AccesRapide()", &slot_74, QMetaData::Public },
	{ "Slot_SetDockMenu_Glossaire()", &slot_75, QMetaData::Public },
	{ "Slot_SetDockMenu_RubriquesButton()", &slot_76, QMetaData::Public },
	{ "Slot_SetDockMenu_Organiseur()", &slot_77, QMetaData::Public },
	{ "setupFileActions()", &slot_78, QMetaData::Public },
	{ "setupTextActions()", &slot_79, QMetaData::Public },
	{ "setupEditActions()", &slot_80, QMetaData::Public },
	{ "setupToolsActions()", &slot_81, QMetaData::Public },
	{ "setupToolsTerrain()", &slot_82, QMetaData::Public },
	{ "setupVigieActions()", &slot_83, QMetaData::Public },
	{ "currentEditor()", &slot_84, QMetaData::Public },
	{ "textFamily(const QString&)", &slot_85, QMetaData::Public },
	{ "textItalic()", &slot_86, QMetaData::Public },
	{ "textBold()", &slot_87, QMetaData::Public },
	{ "textUnderline()", &slot_88, QMetaData::Public },
	{ "textColor()", &slot_89, QMetaData::Public },
	{ "textSize(const QString&)", &slot_90, QMetaData::Public },
	{ "textAlign(QAction*)", &slot_91, QMetaData::Public },
	{ "textStyle(int)", &slot_92, QMetaData::Public },
	{ "editUndo()", &slot_93, QMetaData::Public },
	{ "editRedo()", &slot_94, QMetaData::Public },
	{ "editCut()", &slot_95, QMetaData::Public },
	{ "editCopy()", &slot_96, QMetaData::Public },
	{ "editPaste()", &slot_97, QMetaData::Public },
	{ "editSelectAll()", &slot_98, QMetaData::Public },
	{ "fast_textColor()", &slot_99, QMetaData::Public },
	{ "getFormConfig()", &slot_100, QMetaData::Public },
	{ "editorChanged(QWidget*)", &slot_101, QMetaData::Public },
	{ "fontChanged(const QFont&)", &slot_102, QMetaData::Public },
	{ "colorChanged(const QColor&)", &slot_103, QMetaData::Public },
	{ "alignmentChanged(int)", &slot_104, QMetaData::Public },
	{ "doConnections(QTextEdit*)", &slot_105, QMetaData::Public },
	{ "CodageCim10All()", &slot_106, QMetaData::Public },
	{ "ListManager()", &slot_107, QMetaData::Public },
	{ "CreateList()", &slot_108, QMetaData::Public },
	{ "DisplayContextListPopup()", &slot_109, QMetaData::Public },
	{ "VidalDataSemp()", &slot_110, QMetaData::Public },
	{ "UserChange()", &slot_111, QMetaData::Public },
	{ "Slot_ExePlugin(QString&)", &slot_112, QMetaData::Public },
	{ "Slot_ExeMixture(QString&)", &slot_113, QMetaData::Public },
	{ "Slot_Renouveler_TTT_Fond()", &slot_114, QMetaData::Public },
	{ "Slot_PutPrescriptionInTerrain(RUBREC_LIST::iterator)", &slot_115, QMetaData::Public },
	{ "OnSign_Ident_KillMe()", &slot_116, QMetaData::Public },
	{ "TimedDeleteRubIdentite()", &slot_117, QMetaData::Public },
	{ "Fenetres_en_cascade()", &slot_118, QMetaData::Public },
	{ "Fenetres_en_mosaique()", &slot_119, QMetaData::Public },
	{ "Fenetres_RetablirPosition()", &slot_120, QMetaData::Public },
	{ "Fenetres_Identiques()", &slot_121, QMetaData::Public },
	{ "savePos()", &slot_122, QMetaData::Private },
	{ "saveOnlyChildPos()", &slot_123, QMetaData::Private },
	{ "savePos(int)", &slot_124, QMetaData::Private },
	{ "Slot_actionApropos()", &slot_125, QMetaData::Private },
	{ "Slot_actionAproposDisplay()", &slot_126, QMetaData::Private },
	{ "tryToStopAPropos()", &slot_127, QMetaData::Private },
	{ "filePrint()", &slot_128, QMetaData::Private },
	{ "about()", &slot_129, QMetaData::Private },
	{ "aboutQt()", &slot_130, QMetaData::Private },
	{ "Slot_On_UserQAction_TimerDone(const QString&,C_UserQAction*)", &slot_131, QMetaData::Private },
	{ "Slot_On_UserQAction_Activated(const QString&,C_UserQAction*)", &slot_132, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"Sign_OnIdentChange", 4, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"Sign_OnUserChange", 2, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"Sign_ActiverRubrique", 2, param_signal_2 };
    static const QUMethod signal_3 = {"Sign_QuitterDrTux", 0, 0 };
    static const QUMethod signal_4 = {"Sign_GlossaireRefresh", 0, 0 };
    static const QUMethod signal_5 = {"Sign_DrTux_Renouveler_TTT_Fond", 0, 0 };
    static const QUParameter param_signal_6[] = {
	{ 0, &static_QUType_ptr, "RUBREC_LIST::iterator", QUParameter::In }
    };
    static const QUMethod signal_6 = {"Sign_DrTux_PutPrescriptionInTerrain", 1, param_signal_6 };
    static const QUParameter param_signal_7[] = {
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_7 = {"Sign_OnGlossaireFileClicked", 2, param_signal_7 };
    static const QMetaData signal_tbl[] = {
	{ "Sign_OnIdentChange(const char*,const char*,const char*,const char*)", &signal_0, QMetaData::Public },
	{ "Sign_OnUserChange(const char*,const char*)", &signal_1, QMetaData::Public },
	{ "Sign_ActiverRubrique(const char*,int)", &signal_2, QMetaData::Public },
	{ "Sign_QuitterDrTux()", &signal_3, QMetaData::Public },
	{ "Sign_GlossaireRefresh()", &signal_4, QMetaData::Public },
	{ "Sign_DrTux_Renouveler_TTT_Fond()", &signal_5, QMetaData::Public },
	{ "Sign_DrTux_PutPrescriptionInTerrain(RUBREC_LIST::iterator)", &signal_6, QMetaData::Public },
	{ "Sign_OnGlossaireFileClicked(const char*,int)", &signal_7, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"DrTux", parentObject,
	slot_tbl, 133,
	signal_tbl, 8,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_DrTux.setMetaObject( metaObj );
    return metaObj;
}

void* DrTux::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "DrTux" ) )
	return this;
    return QMainWindow::qt_cast( clname );
}

// SIGNAL Sign_OnIdentChange
void DrTux::Sign_OnIdentChange( const char* t0, const char* t1, const char* t2, const char* t3 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[5];
    static_QUType_charstar.set(o+1,t0);
    static_QUType_charstar.set(o+2,t1);
    static_QUType_charstar.set(o+3,t2);
    static_QUType_charstar.set(o+4,t3);
    activate_signal( clist, o );
}

// SIGNAL Sign_OnUserChange
void DrTux::Sign_OnUserChange( const char* t0, const char* t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_charstar.set(o+1,t0);
    static_QUType_charstar.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL Sign_ActiverRubrique
void DrTux::Sign_ActiverRubrique( const char* t0, int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_charstar.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL Sign_QuitterDrTux
void DrTux::Sign_QuitterDrTux()
{
    activate_signal( staticMetaObject()->signalOffset() + 3 );
}

// SIGNAL Sign_GlossaireRefresh
void DrTux::Sign_GlossaireRefresh()
{
    activate_signal( staticMetaObject()->signalOffset() + 4 );
}

// SIGNAL Sign_DrTux_Renouveler_TTT_Fond
void DrTux::Sign_DrTux_Renouveler_TTT_Fond()
{
    activate_signal( staticMetaObject()->signalOffset() + 5 );
}

// SIGNAL Sign_DrTux_PutPrescriptionInTerrain
void DrTux::Sign_DrTux_PutPrescriptionInTerrain( RUBREC_LIST::iterator t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 6 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL Sign_OnGlossaireFileClicked
void DrTux::Sign_OnGlossaireFileClicked( const char* t0, int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 7 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_charstar.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    activate_signal( clist, o );
}

bool DrTux::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: static_QUType_int.set(_o,SauverDossierAvantNouvelleAction()); break;
    case 1: static_QUType_int.set(_o,SauverDossierAvantNouvelleAction((SAVE_Mode)(*((SAVE_Mode*)static_QUType_ptr.get(_o+1))))); break;
    case 2: Slot_SauverLesMeubles(); break;
    case 3: recordPathModulesMenus((QString)static_QUType_QString.get(_o+1)); break;
    case 4: Slot_OnGlossaireLocalise(); break;
    case 5: SlotMakeVisible((const QString&)static_QUType_QString.get(_o+1)); break;
    case 6: setZoom8(); break;
    case 7: setZoom9(); break;
    case 8: setZoom10(); break;
    case 9: setZoom11(); break;
    case 10: setZoom12(); break;
    case 11: setZoom14(); break;
    case 12: setZoom16(); break;
    case 13: setZoom18(); break;
    case 14: setZoom20(); break;
    case 15: AutoSetActiveWindow(); break;
    case 16: AfficheRubriques(); break;
    case 17: Slot_TestVerrou(); break;
    case 18: Slot_MenuRubriques(); break;
    case 19: ActiverVigie(); break;
    case 20: Slot_GetActiveGUID((QString&)static_QUType_QString.get(_o+1)); break;
    case 21: static_QUType_bool.set(_o,Slot_ActiverDocument((QString)static_QUType_QString.get(_o+1),(QString)static_QUType_QString.get(_o+2))); break;
    case 22: static_QUType_bool.set(_o,Slot_ActiverDocument((QString)static_QUType_QString.get(_o+1),(QString)static_QUType_QString.get(_o+2),(int)static_QUType_int.get(_o+3))); break;
    case 23: Slot_NoteToBeSynchronized((int)static_QUType_int.get(_o+1),(const char*)static_QUType_charstar.get(_o+2)); break;
    case 24: static_QUType_QString.set(_o,Slot_RecordDispos()); break;
    case 25: static_QUType_ptr.set(_o,IsExistRubrique((const char*)static_QUType_charstar.get(_o+1))); break;
    case 26: static_QUType_ptr.set(_o,IsExistRubrique((int)static_QUType_int.get(_o+1))); break;
    case 27: static_QUType_ptr.set(_o,GetCurrentRubrique()); break;
    case 28: static_QUType_ptr.set(_o,GetCurrentRubrique((QString*)static_QUType_varptr.get(_o+1))); break;
    case 29: static_QUType_ptr.set(_o,GetCurrentRubrique((QString*)static_QUType_varptr.get(_o+1),(int*)static_QUType_varptr.get(_o+2))); break;
    case 30: static_QUType_ptr.set(_o,GetCurrentRubrique((QString*)static_QUType_varptr.get(_o+1),(int*)static_QUType_varptr.get(_o+2),(CRubRecord**)static_QUType_ptr.get(_o+3))); break;
    case 31: OnGlossaireFileToEdit((QString)static_QUType_QString.get(_o+1),(QString)static_QUType_QString.get(_o+2),(int)static_QUType_int.get(_o+3)); break;
    case 32: DuplicateRecordWithNewDate((RUBREC_LIST::iterator)(*((RUBREC_LIST::iterator*)static_QUType_ptr.get(_o+1))),(QDateTime&)*((QDateTime*)static_QUType_ptr.get(_o+2)),(const QString&)static_QUType_QString.get(_o+3),(const QString&)static_QUType_QString.get(_o+4)); break;
    case 33: static_QUType_ptr.set(_o,OnGlossaireFileClicked((const char*)static_QUType_charstar.get(_o+1),(int)static_QUType_int.get(_o+2))); break;
    case 34: static_QUType_ptr.set(_o,OnGlossaireFileClicked((const char*)static_QUType_charstar.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3))); break;
    case 35: static_QUType_ptr.set(_o,AddNewRecordToRubrique((const QString&)static_QUType_QString.get(_o+1),(int)static_QUType_int.get(_o+2))); break;
    case 36: static_QUType_ptr.set(_o,AddNewRecordToRubrique((const QString&)static_QUType_QString.get(_o+1),(int)static_QUType_int.get(_o+2),(const char*)static_QUType_charstar.get(_o+3))); break;
    case 37: static_QUType_ptr.set(_o,AddNewRecordToRubrique((const QString&)static_QUType_QString.get(_o+1),(int)static_QUType_int.get(_o+2),(const char*)static_QUType_charstar.get(_o+3),(const QDateTime*)static_QUType_varptr.get(_o+4))); break;
    case 38: static_QUType_ptr.set(_o,AddNewRecordToRubrique((const QString&)static_QUType_QString.get(_o+1),(int)static_QUType_int.get(_o+2),(const char*)static_QUType_charstar.get(_o+3),(const QDateTime*)static_QUType_varptr.get(_o+4),(const QString*)static_QUType_varptr.get(_o+5))); break;
    case 39: static_QUType_ptr.set(_o,AddNewRecordToRubrique((const QString&)static_QUType_QString.get(_o+1),(int)static_QUType_int.get(_o+2),(const char*)static_QUType_charstar.get(_o+3),(const QDateTime*)static_QUType_varptr.get(_o+4),(const QString*)static_QUType_varptr.get(_o+5),(const QString*)static_QUType_varptr.get(_o+6))); break;
    case 40: static_QUType_ptr.set(_o,AddNewRecordToRubrique((const QString&)static_QUType_QString.get(_o+1),(int)static_QUType_int.get(_o+2),(const char*)static_QUType_charstar.get(_o+3),(const QDateTime*)static_QUType_varptr.get(_o+4),(const QString*)static_QUType_varptr.get(_o+5),(const QString*)static_QUType_varptr.get(_o+6),(int)static_QUType_int.get(_o+7))); break;
    case 41: OnDrTuxSaveRubList(); break;
    case 42: SetTitle(); break;
    case 43: recordProfil(); break;
    case 44: add_ATCD_Favori(); break;
    case 45: add_ATCD_Allergique(); break;
    case 46: modifier_TTT_Fond(); break;
    case 47: add_ATCD_Libre(); break;
    case 48: add_CIM10(); break;
    case 49: On_Vigie_visibilityChanged((bool)static_QUType_bool.get(_o+1)); break;
    case 50: static_QUType_int.set(_o,GetPossibleObservationDate((const QString&)static_QUType_QString.get(_o+1))); break;
    case 51: OnQuitterDrTux(); break;
    case 52: OnMenuQuitterDrTux(); break;
    case 53: OnCreateNewDoc(); break;
    case 54: Codage_CCAM(); break;
    case 55: PasteLabo(); break;
    case 56: OnDrTuxUserChange(); break;
    case 57: SetInterfaceOnDroits((const QString&)static_QUType_QString.get(_o+1)); break;
    case 58: OnDrTuxExeAnother((QString)static_QUType_QString.get(_o+1),(QString)static_QUType_QString.get(_o+2),(QString)static_QUType_QString.get(_o+3),(QString)static_QUType_QString.get(_o+4)); break;
    case 59: OnDrTuxPatientListMustBeUpdated((const char*)static_QUType_charstar.get(_o+1),(const char*)static_QUType_charstar.get(_o+2),(const char*)static_QUType_charstar.get(_o+3),(const char*)static_QUType_charstar.get(_o+4)); break;
    case 60: OnDrTuxIdentModified((const char*)static_QUType_charstar.get(_o+1),(const char*)static_QUType_charstar.get(_o+2),(const char*)static_QUType_charstar.get(_o+3),(const char*)static_QUType_charstar.get(_o+4)); break;
    case 61: OnDrTuxIdentChange((const char*)static_QUType_charstar.get(_o+1),(const char*)static_QUType_charstar.get(_o+2),(const char*)static_QUType_charstar.get(_o+3),(const char*)static_QUType_charstar.get(_o+4)); break;
    case 62: OnDrTuxIdentDelete((const char*)static_QUType_charstar.get(_o+1),(const char*)static_QUType_charstar.get(_o+2),(const char*)static_QUType_charstar.get(_o+3),(const char*)static_QUType_charstar.get(_o+4)); break;
    case 63: OnDrTuxIdentCurrentDelete(); break;
    case 64: OnActiverRubrique((const char*)static_QUType_charstar.get(_o+1)); break;
    case 65: OnActiverRubrique((const char*)static_QUType_charstar.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 66: OnActiverOrCreateRubrique((const char*)static_QUType_charstar.get(_o+1)); break;
    case 67: OnActiverOrCreateRubrique((const char*)static_QUType_charstar.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 68: OnDeleteRubrique((const char*)static_QUType_charstar.get(_o+1)); break;
    case 69: OnOngletRubriquesChanged((QWidget*)static_QUType_ptr.get(_o+1)); break;
    case 70: OnCreateNewIdent(); break;
    case 71: On_CreateNewRootInOrganiseur((QString)static_QUType_QString.get(_o+1)); break;
    case 72: On_DragFileInOrganiseur((QString)static_QUType_QString.get(_o+1),(QString*)static_QUType_varptr.get(_o+2)); break;
    case 73: setupDocks(); break;
    case 74: Slot_SetDockMenu_AccesRapide(); break;
    case 75: Slot_SetDockMenu_Glossaire(); break;
    case 76: Slot_SetDockMenu_RubriquesButton(); break;
    case 77: Slot_SetDockMenu_Organiseur(); break;
    case 78: setupFileActions(); break;
    case 79: setupTextActions(); break;
    case 80: setupEditActions(); break;
    case 81: setupToolsActions(); break;
    case 82: setupToolsTerrain(); break;
    case 83: setupVigieActions(); break;
    case 84: static_QUType_ptr.set(_o,currentEditor()); break;
    case 85: textFamily((const QString&)static_QUType_QString.get(_o+1)); break;
    case 86: textItalic(); break;
    case 87: textBold(); break;
    case 88: textUnderline(); break;
    case 89: textColor(); break;
    case 90: textSize((const QString&)static_QUType_QString.get(_o+1)); break;
    case 91: textAlign((QAction*)static_QUType_ptr.get(_o+1)); break;
    case 92: textStyle((int)static_QUType_int.get(_o+1)); break;
    case 93: editUndo(); break;
    case 94: editRedo(); break;
    case 95: editCut(); break;
    case 96: editCopy(); break;
    case 97: editPaste(); break;
    case 98: editSelectAll(); break;
    case 99: fast_textColor(); break;
    case 100: getFormConfig(); break;
    case 101: editorChanged((QWidget*)static_QUType_ptr.get(_o+1)); break;
    case 102: fontChanged((const QFont&)*((const QFont*)static_QUType_ptr.get(_o+1))); break;
    case 103: colorChanged((const QColor&)*((const QColor*)static_QUType_ptr.get(_o+1))); break;
    case 104: alignmentChanged((int)static_QUType_int.get(_o+1)); break;
    case 105: doConnections((QTextEdit*)static_QUType_ptr.get(_o+1)); break;
    case 106: CodageCim10All(); break;
    case 107: ListManager(); break;
    case 108: CreateList(); break;
    case 109: DisplayContextListPopup(); break;
    case 110: VidalDataSemp(); break;
    case 111: UserChange(); break;
    case 112: Slot_ExePlugin((QString&)static_QUType_QString.get(_o+1)); break;
    case 113: Slot_ExeMixture((QString&)static_QUType_QString.get(_o+1)); break;
    case 114: Slot_Renouveler_TTT_Fond(); break;
    case 115: Slot_PutPrescriptionInTerrain((RUBREC_LIST::iterator)(*((RUBREC_LIST::iterator*)static_QUType_ptr.get(_o+1)))); break;
    case 116: OnSign_Ident_KillMe(); break;
    case 117: TimedDeleteRubIdentite(); break;
    case 118: Fenetres_en_cascade(); break;
    case 119: Fenetres_en_mosaique(); break;
    case 120: Fenetres_RetablirPosition(); break;
    case 121: Fenetres_Identiques(); break;
    case 122: savePos(); break;
    case 123: saveOnlyChildPos(); break;
    case 124: savePos((int)static_QUType_int.get(_o+1)); break;
    case 125: Slot_actionApropos(); break;
    case 126: Slot_actionAproposDisplay(); break;
    case 127: tryToStopAPropos(); break;
    case 128: filePrint(); break;
    case 129: about(); break;
    case 130: aboutQt(); break;
    case 131: static_QUType_QString.set(_o,Slot_On_UserQAction_TimerDone((const QString&)static_QUType_QString.get(_o+1),(C_UserQAction*)static_QUType_ptr.get(_o+2))); break;
    case 132: static_QUType_QString.set(_o,Slot_On_UserQAction_Activated((const QString&)static_QUType_QString.get(_o+1),(C_UserQAction*)static_QUType_ptr.get(_o+2))); break;
    default:
	return QMainWindow::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool DrTux::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: Sign_OnIdentChange((const char*)static_QUType_charstar.get(_o+1),(const char*)static_QUType_charstar.get(_o+2),(const char*)static_QUType_charstar.get(_o+3),(const char*)static_QUType_charstar.get(_o+4)); break;
    case 1: Sign_OnUserChange((const char*)static_QUType_charstar.get(_o+1),(const char*)static_QUType_charstar.get(_o+2)); break;
    case 2: Sign_ActiverRubrique((const char*)static_QUType_charstar.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 3: Sign_QuitterDrTux(); break;
    case 4: Sign_GlossaireRefresh(); break;
    case 5: Sign_DrTux_Renouveler_TTT_Fond(); break;
    case 6: Sign_DrTux_PutPrescriptionInTerrain((RUBREC_LIST::iterator)(*((RUBREC_LIST::iterator*)static_QUType_ptr.get(_o+1)))); break;
    case 7: Sign_OnGlossaireFileClicked((const char*)static_QUType_charstar.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    default:
	return QMainWindow::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool DrTux::qt_property( int id, int f, QVariant* v)
{
    return QMainWindow::qt_property( id, f, v);
}

bool DrTux::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
