/****************************************************************************
** QtSingleApplication meta object code from reading C++ file 'qtsingleapplication.h'
**
** Created: Wed May 4 22:20:10 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../../../SesamVitale-QT3/qtsingleapplication.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtSingleApplication::className() const
{
    return "QtSingleApplication";
}

QMetaObject *QtSingleApplication::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtSingleApplication( "QtSingleApplication", &QtSingleApplication::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtSingleApplication::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtSingleApplication", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtSingleApplication::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtSingleApplication", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtSingleApplication::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QApplication::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::Out },
	{ "message", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"sendMessage", 2, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::Out },
	{ "message", &static_QUType_QString, 0, QUParameter::In },
	{ "timeout", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"sendMessage", 3, param_slot_1 };
    static const QUMethod slot_2 = {"activateMainWidget", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "sendMessage(const QString&)", &slot_0, QMetaData::Public },
	{ "sendMessage(const QString&,int)", &slot_1, QMetaData::Public },
	{ "activateMainWidget()", &slot_2, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ "message", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"messageReceived", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "messageReceived(const QString&)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtSingleApplication", parentObject,
	slot_tbl, 3,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtSingleApplication.setMetaObject( metaObj );
    return metaObj;
}

void* QtSingleApplication::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtSingleApplication" ) )
	return this;
    return QApplication::qt_cast( clname );
}

// SIGNAL messageReceived
void QtSingleApplication::messageReceived( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

bool QtSingleApplication::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: static_QUType_bool.set(_o,sendMessage((const QString&)static_QUType_QString.get(_o+1))); break;
    case 1: static_QUType_bool.set(_o,sendMessage((const QString&)static_QUType_QString.get(_o+1),(int)static_QUType_int.get(_o+2))); break;
    case 2: activateMainWidget(); break;
    default:
	return QApplication::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtSingleApplication::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: messageReceived((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return QApplication::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QtSingleApplication::qt_property( int id, int f, QVariant* v)
{
    return QApplication::qt_property( id, f, v);
}

bool QtSingleApplication::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
