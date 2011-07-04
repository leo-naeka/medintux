/****************************************************************************
** CMDI_Observation meta object code from reading C++ file 'CMDI_Observation.h'
**
** Created: Wed May 4 22:20:26 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../CMDI_Observation.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CMDI_Observation::className() const
{
    return "CMDI_Observation";
}

QMetaObject *CMDI_Observation::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CMDI_Observation( "CMDI_Observation", &CMDI_Observation::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CMDI_Observation::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CMDI_Observation", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CMDI_Observation::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CMDI_Observation", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CMDI_Observation::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CMDI_Generic::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "user", &static_QUType_charstar, 0, QUParameter::In },
	{ "sign_user", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"RubOnUserChange", 2, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "num_GUID", &static_QUType_charstar, 0, QUParameter::In },
	{ "id_doss", &static_QUType_charstar, 0, QUParameter::In },
	{ "dossNom", &static_QUType_charstar, 0, QUParameter::In },
	{ "dossPrenom", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"OnIdentChange", 4, param_slot_1 };
    static const QUMethod slot_2 = {"OnPrint", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ "state", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"SetModifiableState", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ "command", &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod slot_4 = {"Slot_ExeCommand", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::InOut },
	{ 0, &static_QUType_QString, 0, QUParameter::InOut },
	{ 0, &static_QUType_varptr, "\x1f", QUParameter::InOut }
    };
    static const QUMethod slot_5 = {"Slot_Get_Custom_Menu", 4, param_slot_5 };
    static const QUMethod slot_6 = {"On_pushButtonAppend", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "RubOnUserChange(const char*,const char*)", &slot_0, QMetaData::Public },
	{ "OnIdentChange(const char*,const char*,const char*,const char*)", &slot_1, QMetaData::Public },
	{ "OnPrint()", &slot_2, QMetaData::Public },
	{ "SetModifiableState(int)", &slot_3, QMetaData::Public },
	{ "Slot_ExeCommand(QString&)", &slot_4, QMetaData::Public },
	{ "Slot_Get_Custom_Menu(const QString&,QString&,QString&,QKeySequence&)", &slot_5, QMetaData::Public },
	{ "On_pushButtonAppend()", &slot_6, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"message", 2, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "name", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"Sign_RubIsDeleted", 1, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "message(const QString&,int)", &signal_0, QMetaData::Public },
	{ "Sign_RubIsDeleted(const char*)", &signal_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"CMDI_Observation", parentObject,
	slot_tbl, 7,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CMDI_Observation.setMetaObject( metaObj );
    return metaObj;
}

void* CMDI_Observation::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CMDI_Observation" ) )
	return this;
    return CMDI_Generic::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL message
void CMDI_Observation::message( const QString& t0, int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_QString.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL Sign_RubIsDeleted
void CMDI_Observation::Sign_RubIsDeleted( const char* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_charstar.set(o+1,t0);
    activate_signal( clist, o );
}

bool CMDI_Observation::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: RubOnUserChange((const char*)static_QUType_charstar.get(_o+1),(const char*)static_QUType_charstar.get(_o+2)); break;
    case 1: OnIdentChange((const char*)static_QUType_charstar.get(_o+1),(const char*)static_QUType_charstar.get(_o+2),(const char*)static_QUType_charstar.get(_o+3),(const char*)static_QUType_charstar.get(_o+4)); break;
    case 2: OnPrint(); break;
    case 3: SetModifiableState((int)static_QUType_int.get(_o+1)); break;
    case 4: Slot_ExeCommand((QString&)static_QUType_QString.get(_o+1)); break;
    case 5: Slot_Get_Custom_Menu((const QString&)static_QUType_QString.get(_o+1),(QString&)static_QUType_QString.get(_o+2),(QString&)static_QUType_QString.get(_o+3),(QKeySequence&)*((QKeySequence*)static_QUType_ptr.get(_o+4))); break;
    case 6: On_pushButtonAppend(); break;
    default:
	return CMDI_Generic::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CMDI_Observation::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: message((const QString&)static_QUType_QString.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 1: Sign_RubIsDeleted((const char*)static_QUType_charstar.get(_o+1)); break;
    default:
	return CMDI_Generic::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool CMDI_Observation::qt_property( int id, int f, QVariant* v)
{
    return CMDI_Generic::qt_property( id, f, v);
}

bool CMDI_Observation::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
