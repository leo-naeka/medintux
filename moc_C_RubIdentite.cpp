/****************************************************************************
** C_RubIdentite meta object code from reading C++ file 'C_RubIdentite.h'
**
** Created: Wed May 4 22:20:27 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../C_RubIdentite.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *C_RubIdentite::className() const
{
    return "C_RubIdentite";
}

QMetaObject *C_RubIdentite::metaObj = 0;
static QMetaObjectCleanUp cleanUp_C_RubIdentite( "C_RubIdentite", &C_RubIdentite::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString C_RubIdentite::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_RubIdentite", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString C_RubIdentite::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_RubIdentite", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* C_RubIdentite::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = FormRubIdent::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "key", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"CheckIfImageIsToRemoveFromIconView", 1, param_slot_0 };
    static const QUMethod slot_1 = {"On_Signal_Del_Before", 0, 0 };
    static const QUMethod slot_2 = {"On_Signal_Del_After", 0, 0 };
    static const QUMethod slot_3 = {"On_Signal_Paste_After", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ "name", &static_QUType_QString, 0, QUParameter::In },
	{ "date", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"SetRubDateName", 2, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ "item", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"comboBox_RubName_activated", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "item", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"comboBox_RubName_highlighted", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"OnMenuActivated", 1, param_slot_7 };
    static const QUMethod slot_8 = {"On_pushButtonSave", 0, 0 };
    static const QUMethod slot_9 = {"pushButtonRubDateChange_clicked", 0, 0 };
    static const QUMethod slot_10 = {"pushButtonDelete_clicked", 0, 0 };
    static const QUParameter param_slot_11[] = {
	{ "state", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_11 = {"SetModifiableState", 1, param_slot_11 };
    static const QUParameter param_slot_12[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_12 = {"listView_Praticiens_contextMenuRequested", 3, param_slot_12 };
    static const QUParameter param_slot_13[] = {
	{ "qualiteAssure", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_13 = {"OnActivated_comboBoxQualiteAyantDroit", 1, param_slot_13 };
    static const QUParameter param_slot_14[] = {
	{ "droits", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_14 = {"SetInterfaceOnDroits", 1, param_slot_14 };
    static const QUMethod slot_15 = {"OnOutFocuslineEdit_DtNss", 0, 0 };
    static const QUMethod slot_16 = {"OnInFocusNumSecu", 0, 0 };
    static const QUMethod slot_17 = {"OnOutFocusNumSecu", 0, 0 };
    static const QUMethod slot_18 = {"OnOutFocusVille", 0, 0 };
    static const QUMethod slot_19 = {"OnOutFocusCodePostal", 0, 0 };
    static const QUMethod slot_20 = {"GetPopupItem", 0, 0 };
    static const QUParameter param_slot_21[] = {
	{ 0, &static_QUType_ptr, "QEvent", QUParameter::In }
    };
    static const QUMethod slot_21 = {"OnCharEventCodePostal", 1, param_slot_21 };
    static const QUParameter param_slot_22[] = {
	{ 0, &static_QUType_ptr, "QEvent", QUParameter::In }
    };
    static const QUMethod slot_22 = {"OnCharEventNumSecu", 1, param_slot_22 };
    static const QUMethod slot_23 = {"SetData", 0, 0 };
    static const QUParameter param_slot_24[] = {
	{ "flag", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_24 = {"SetData", 1, param_slot_24 };
    static const QUMethod slot_25 = {"ClearDialog", 0, 0 };
    static const QUMethod slot_26 = {"pushButtonCreate_clicked", 0, 0 };
    static const QUMethod slot_27 = {"pushButtonSavModif_clicked", 0, 0 };
    static const QUParameter param_slot_28[] = {
	{ "list_field", &static_QUType_ptr, "PtrListIdentFieldData", QUParameter::InOut }
    };
    static const QUMethod slot_28 = {"SetFieldListData", 1, param_slot_28 };
    static const QUMethod slot_29 = {"pushButtonCancel_clicked", 0, 0 };
    static const QUParameter param_slot_30[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_30 = {"listView_Praticiens_doubleClicked", 1, param_slot_30 };
    static const QUMethod slot_31 = {"pushButton_AddMedTTT_clicked", 0, 0 };
    static const QUParameter param_slot_32[] = {
	{ "idInterv", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_32 = {"exeAnnuaire", 1, param_slot_32 };
    static const QUMethod slot_33 = {"pushButton_DelMedTTT_clicked", 0, 0 };
    static const QUMethod slot_34 = {"pushButton_ViewNotes_clicked", 0, 0 };
    static const QUParameter param_slot_35[] = {
	{ "txt", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_35 = {"synchronizeNoteWith", 1, param_slot_35 };
    static const QUMethod slot_36 = {"textEdit_Note_textChanged", 0, 0 };
    static const QUMethod slot_37 = {"On_buttonDragClicked", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "CheckIfImageIsToRemoveFromIconView(int)", &slot_0, QMetaData::Public },
	{ "On_Signal_Del_Before()", &slot_1, QMetaData::Public },
	{ "On_Signal_Del_After()", &slot_2, QMetaData::Public },
	{ "On_Signal_Paste_After()", &slot_3, QMetaData::Public },
	{ "SetRubDateName(const QString&,const QString&)", &slot_4, QMetaData::Public },
	{ "comboBox_RubName_activated(int)", &slot_5, QMetaData::Public },
	{ "comboBox_RubName_highlighted(int)", &slot_6, QMetaData::Public },
	{ "OnMenuActivated(int)", &slot_7, QMetaData::Public },
	{ "On_pushButtonSave()", &slot_8, QMetaData::Public },
	{ "pushButtonRubDateChange_clicked()", &slot_9, QMetaData::Public },
	{ "pushButtonDelete_clicked()", &slot_10, QMetaData::Public },
	{ "SetModifiableState(int)", &slot_11, QMetaData::Public },
	{ "listView_Praticiens_contextMenuRequested(QListViewItem*,const QPoint&,int)", &slot_12, QMetaData::Public },
	{ "OnActivated_comboBoxQualiteAyantDroit(int)", &slot_13, QMetaData::Public },
	{ "SetInterfaceOnDroits(const QString&)", &slot_14, QMetaData::Public },
	{ "OnOutFocuslineEdit_DtNss()", &slot_15, QMetaData::Public },
	{ "OnInFocusNumSecu()", &slot_16, QMetaData::Public },
	{ "OnOutFocusNumSecu()", &slot_17, QMetaData::Public },
	{ "OnOutFocusVille()", &slot_18, QMetaData::Public },
	{ "OnOutFocusCodePostal()", &slot_19, QMetaData::Public },
	{ "GetPopupItem()", &slot_20, QMetaData::Public },
	{ "OnCharEventCodePostal(QEvent*)", &slot_21, QMetaData::Public },
	{ "OnCharEventNumSecu(QEvent*)", &slot_22, QMetaData::Public },
	{ "SetData()", &slot_23, QMetaData::Public },
	{ "SetData(int)", &slot_24, QMetaData::Public },
	{ "ClearDialog()", &slot_25, QMetaData::Public },
	{ "pushButtonCreate_clicked()", &slot_26, QMetaData::Public },
	{ "pushButtonSavModif_clicked()", &slot_27, QMetaData::Public },
	{ "SetFieldListData(PtrListIdentFieldData&)", &slot_28, QMetaData::Public },
	{ "pushButtonCancel_clicked()", &slot_29, QMetaData::Public },
	{ "listView_Praticiens_doubleClicked(QListViewItem*)", &slot_30, QMetaData::Public },
	{ "pushButton_AddMedTTT_clicked()", &slot_31, QMetaData::Public },
	{ "exeAnnuaire(QString)", &slot_32, QMetaData::Public },
	{ "pushButton_DelMedTTT_clicked()", &slot_33, QMetaData::Public },
	{ "pushButton_ViewNotes_clicked()", &slot_34, QMetaData::Public },
	{ "synchronizeNoteWith(const char*)", &slot_35, QMetaData::Public },
	{ "textEdit_Note_textChanged()", &slot_36, QMetaData::Public },
	{ "On_buttonDragClicked()", &slot_37, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"Sign_IdentChange", 4, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"Sign_IdentModified", 4, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"Sign_PatientListMustBeUpdated", 4, param_signal_2 };
    static const QUMethod signal_3 = {"Sign_Ident_KillMe", 0, 0 };
    static const QUParameter param_signal_4[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod signal_4 = {"Sign_NoteToBeSynchronized", 2, param_signal_4 };
    static const QUMethod signal_5 = {"Sign_SaveButtonClicked", 0, 0 };
    static const QUParameter param_signal_6[] = {
	{ 0, &static_QUType_ptr, "RUBREC_LIST::iterator", QUParameter::In }
    };
    static const QUMethod signal_6 = {"Sign_RubChanged", 1, param_signal_6 };
    static const QMetaData signal_tbl[] = {
	{ "Sign_IdentChange(const char*,const char*,const char*,const char*)", &signal_0, QMetaData::Public },
	{ "Sign_IdentModified(const char*,const char*,const char*,const char*)", &signal_1, QMetaData::Public },
	{ "Sign_PatientListMustBeUpdated(const char*,const char*,const char*,const char*)", &signal_2, QMetaData::Public },
	{ "Sign_Ident_KillMe()", &signal_3, QMetaData::Public },
	{ "Sign_NoteToBeSynchronized(int,const char*)", &signal_4, QMetaData::Public },
	{ "Sign_SaveButtonClicked()", &signal_5, QMetaData::Public },
	{ "Sign_RubChanged(RUBREC_LIST::iterator)", &signal_6, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"C_RubIdentite", parentObject,
	slot_tbl, 38,
	signal_tbl, 7,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_C_RubIdentite.setMetaObject( metaObj );
    return metaObj;
}

void* C_RubIdentite::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "C_RubIdentite" ) )
	return this;
    return FormRubIdent::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL Sign_IdentChange
void C_RubIdentite::Sign_IdentChange( const char* t0, const char* t1, const char* t2, const char* t3 )
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

// SIGNAL Sign_IdentModified
void C_RubIdentite::Sign_IdentModified( const char* t0, const char* t1, const char* t2, const char* t3 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[5];
    static_QUType_charstar.set(o+1,t0);
    static_QUType_charstar.set(o+2,t1);
    static_QUType_charstar.set(o+3,t2);
    static_QUType_charstar.set(o+4,t3);
    activate_signal( clist, o );
}

// SIGNAL Sign_PatientListMustBeUpdated
void C_RubIdentite::Sign_PatientListMustBeUpdated( const char* t0, const char* t1, const char* t2, const char* t3 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[5];
    static_QUType_charstar.set(o+1,t0);
    static_QUType_charstar.set(o+2,t1);
    static_QUType_charstar.set(o+3,t2);
    static_QUType_charstar.set(o+4,t3);
    activate_signal( clist, o );
}

// SIGNAL Sign_Ident_KillMe
void C_RubIdentite::Sign_Ident_KillMe()
{
    activate_signal( staticMetaObject()->signalOffset() + 3 );
}

// SIGNAL Sign_NoteToBeSynchronized
void C_RubIdentite::Sign_NoteToBeSynchronized( int t0, const char* t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 4 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_int.set(o+1,t0);
    static_QUType_charstar.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL Sign_SaveButtonClicked
void C_RubIdentite::Sign_SaveButtonClicked()
{
    activate_signal( staticMetaObject()->signalOffset() + 5 );
}

// SIGNAL Sign_RubChanged
void C_RubIdentite::Sign_RubChanged( RUBREC_LIST::iterator t0 )
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

bool C_RubIdentite::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: CheckIfImageIsToRemoveFromIconView((int)static_QUType_int.get(_o+1)); break;
    case 1: On_Signal_Del_Before(); break;
    case 2: On_Signal_Del_After(); break;
    case 3: On_Signal_Paste_After(); break;
    case 4: SetRubDateName((const QString&)static_QUType_QString.get(_o+1),(const QString&)static_QUType_QString.get(_o+2)); break;
    case 5: comboBox_RubName_activated((int)static_QUType_int.get(_o+1)); break;
    case 6: comboBox_RubName_highlighted((int)static_QUType_int.get(_o+1)); break;
    case 7: OnMenuActivated((int)static_QUType_int.get(_o+1)); break;
    case 8: On_pushButtonSave(); break;
    case 9: pushButtonRubDateChange_clicked(); break;
    case 10: pushButtonDelete_clicked(); break;
    case 11: SetModifiableState((int)static_QUType_int.get(_o+1)); break;
    case 12: listView_Praticiens_contextMenuRequested((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 13: OnActivated_comboBoxQualiteAyantDroit((int)static_QUType_int.get(_o+1)); break;
    case 14: SetInterfaceOnDroits((const QString&)static_QUType_QString.get(_o+1)); break;
    case 15: OnOutFocuslineEdit_DtNss(); break;
    case 16: OnInFocusNumSecu(); break;
    case 17: OnOutFocusNumSecu(); break;
    case 18: OnOutFocusVille(); break;
    case 19: OnOutFocusCodePostal(); break;
    case 20: GetPopupItem(); break;
    case 21: OnCharEventCodePostal((QEvent*)static_QUType_ptr.get(_o+1)); break;
    case 22: OnCharEventNumSecu((QEvent*)static_QUType_ptr.get(_o+1)); break;
    case 23: SetData(); break;
    case 24: SetData((int)static_QUType_int.get(_o+1)); break;
    case 25: ClearDialog(); break;
    case 26: pushButtonCreate_clicked(); break;
    case 27: pushButtonSavModif_clicked(); break;
    case 28: SetFieldListData((PtrListIdentFieldData&)*((PtrListIdentFieldData*)static_QUType_ptr.get(_o+1))); break;
    case 29: pushButtonCancel_clicked(); break;
    case 30: listView_Praticiens_doubleClicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 31: pushButton_AddMedTTT_clicked(); break;
    case 32: exeAnnuaire((QString)static_QUType_QString.get(_o+1)); break;
    case 33: pushButton_DelMedTTT_clicked(); break;
    case 34: pushButton_ViewNotes_clicked(); break;
    case 35: synchronizeNoteWith((const char*)static_QUType_charstar.get(_o+1)); break;
    case 36: textEdit_Note_textChanged(); break;
    case 37: On_buttonDragClicked(); break;
    default:
	return FormRubIdent::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool C_RubIdentite::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: Sign_IdentChange((const char*)static_QUType_charstar.get(_o+1),(const char*)static_QUType_charstar.get(_o+2),(const char*)static_QUType_charstar.get(_o+3),(const char*)static_QUType_charstar.get(_o+4)); break;
    case 1: Sign_IdentModified((const char*)static_QUType_charstar.get(_o+1),(const char*)static_QUType_charstar.get(_o+2),(const char*)static_QUType_charstar.get(_o+3),(const char*)static_QUType_charstar.get(_o+4)); break;
    case 2: Sign_PatientListMustBeUpdated((const char*)static_QUType_charstar.get(_o+1),(const char*)static_QUType_charstar.get(_o+2),(const char*)static_QUType_charstar.get(_o+3),(const char*)static_QUType_charstar.get(_o+4)); break;
    case 3: Sign_Ident_KillMe(); break;
    case 4: Sign_NoteToBeSynchronized((int)static_QUType_int.get(_o+1),(const char*)static_QUType_charstar.get(_o+2)); break;
    case 5: Sign_SaveButtonClicked(); break;
    case 6: Sign_RubChanged((RUBREC_LIST::iterator)(*((RUBREC_LIST::iterator*)static_QUType_ptr.get(_o+1)))); break;
    default:
	return FormRubIdent::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool C_RubIdentite::qt_property( int id, int f, QVariant* v)
{
    return FormRubIdent::qt_property( id, f, v);
}

bool C_RubIdentite::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
