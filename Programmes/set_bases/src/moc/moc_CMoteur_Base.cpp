/****************************************************************************
** CMoteurBase meta object code from reading C++ file 'CMoteur_Base.h'
**
** Created: Wed May 4 22:15:51 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../../../drtux/src/CMoteur_Base.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CMoteurBase::className() const
{
    return "CMoteurBase";
}

QMetaObject *CMoteurBase::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CMoteurBase( "CMoteurBase", &CMoteurBase::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CMoteurBase::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CMoteurBase", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CMoteurBase::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CMoteurBase", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CMoteurBase::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"On_ReconnectTimerDone", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "On_ReconnectTimerDone()", &slot_0, QMetaData::Public }
    };
    static const QUMethod signal_0 = {"Sign_ReconnectTimerDone", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "Sign_ReconnectTimerDone()", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"CMoteurBase", parentObject,
	slot_tbl, 1,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CMoteurBase.setMetaObject( metaObj );
    return metaObj;
}

void* CMoteurBase::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CMoteurBase" ) )
	return this;
    return QObject::qt_cast( clname );
}

// SIGNAL Sign_ReconnectTimerDone
void CMoteurBase::Sign_ReconnectTimerDone()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

bool CMoteurBase::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: On_ReconnectTimerDone(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CMoteurBase::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: Sign_ReconnectTimerDone(); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool CMoteurBase::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool CMoteurBase::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
