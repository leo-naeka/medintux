/****************************************************************************
** CApp meta object code from reading C++ file 'CApp.h'
**
** Created: Wed May 4 22:15:53 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../CApp.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CApp::className() const
{
    return "CApp";
}

QMetaObject *CApp::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CApp( "CApp", &CApp::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CApp::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CApp", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CApp::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CApp", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CApp::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QApplication::staticMetaObject();
    static const QUMethod slot_0 = {"quit", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "quit()", &slot_0, QMetaData::Public }
    };
    static const QUMethod signal_0 = {"Sign_QuitterRequired", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "Sign_QuitterRequired()", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"CApp", parentObject,
	slot_tbl, 1,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CApp.setMetaObject( metaObj );
    return metaObj;
}

void* CApp::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CApp" ) )
	return this;
    if ( !qstrcmp( clname, "CSetupBase" ) )
	return (CSetupBase*)this;
    return QApplication::qt_cast( clname );
}

// SIGNAL Sign_QuitterRequired
void CApp::Sign_QuitterRequired()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

bool CApp::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: quit(); break;
    default:
	return QApplication::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CApp::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: Sign_QuitterRequired(); break;
    default:
	return QApplication::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool CApp::qt_property( int id, int f, QVariant* v)
{
    return QApplication::qt_property( id, f, v);
}

bool CApp::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
