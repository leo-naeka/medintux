/****************************************************************************
** CMyButton meta object code from reading C++ file 'MyButton.h'
**
** Created: Wed May 4 22:20:16 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../MyButton.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CMyButton::className() const
{
    return "CMyButton";
}

QMetaObject *CMyButton::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CMyButton( "CMyButton", &CMyButton::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CMyButton::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CMyButton", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CMyButton::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CMyButton", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CMyButton::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QPushButton::staticMetaObject();
    static const QUMethod slot_0 = {"Slot_OnButtonClicked", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "Slot_OnButtonClicked()", &slot_0, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ "name", &static_QUType_charstar, 0, QUParameter::In },
	{ "ptr", &static_QUType_ptr, "void", QUParameter::In }
    };
    static const QUMethod signal_0 = {"Sign_ButtonClickedPtr", 2, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "name", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"Sign_ButtonClicked", 1, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "Sign_ButtonClickedPtr(const char*,void*)", &signal_0, QMetaData::Public },
	{ "Sign_ButtonClicked(const char*)", &signal_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"CMyButton", parentObject,
	slot_tbl, 1,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CMyButton.setMetaObject( metaObj );
    return metaObj;
}

void* CMyButton::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CMyButton" ) )
	return this;
    return QPushButton::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL Sign_ButtonClickedPtr
void CMyButton::Sign_ButtonClickedPtr( const char* t0, void* t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_charstar.set(o+1,t0);
    static_QUType_ptr.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL Sign_ButtonClicked
void CMyButton::Sign_ButtonClicked( const char* t0 )
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

bool CMyButton::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: Slot_OnButtonClicked(); break;
    default:
	return QPushButton::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CMyButton::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: Sign_ButtonClickedPtr((const char*)static_QUType_charstar.get(_o+1),(void*)static_QUType_ptr.get(_o+2)); break;
    case 1: Sign_ButtonClicked((const char*)static_QUType_charstar.get(_o+1)); break;
    default:
	return QPushButton::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool CMyButton::qt_property( int id, int f, QVariant* v)
{
    return QPushButton::qt_property( id, f, v);
}

bool CMyButton::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
