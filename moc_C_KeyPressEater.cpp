/****************************************************************************
** C_KeyPressEater meta object code from reading C++ file 'C_KeyPressEater.h'
**
** Created: Wed May 4 22:20:18 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../C_KeyPressEater.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *C_KeyPressEater::className() const
{
    return "C_KeyPressEater";
}

QMetaObject *C_KeyPressEater::metaObj = 0;
static QMetaObjectCleanUp cleanUp_C_KeyPressEater( "C_KeyPressEater", &C_KeyPressEater::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString C_KeyPressEater::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_KeyPressEater", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString C_KeyPressEater::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_KeyPressEater", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* C_KeyPressEater::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod signal_0 = {"Sign_F1_Pressed", 0, 0 };
    static const QUMethod signal_1 = {"Sign_F2_Pressed", 0, 0 };
    static const QUMethod signal_2 = {"Sign_F6_Pressed", 0, 0 };
    static const QUParameter param_signal_3[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod signal_3 = {"Sign_Down_Pressed", 1, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod signal_4 = {"Sign_Up_Pressed", 1, param_signal_4 };
    static const QMetaData signal_tbl[] = {
	{ "Sign_F1_Pressed()", &signal_0, QMetaData::Public },
	{ "Sign_F2_Pressed()", &signal_1, QMetaData::Public },
	{ "Sign_F6_Pressed()", &signal_2, QMetaData::Public },
	{ "Sign_Down_Pressed(QListViewItem*)", &signal_3, QMetaData::Public },
	{ "Sign_Up_Pressed(QListViewItem*)", &signal_4, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"C_KeyPressEater", parentObject,
	0, 0,
	signal_tbl, 5,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_C_KeyPressEater.setMetaObject( metaObj );
    return metaObj;
}

void* C_KeyPressEater::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "C_KeyPressEater" ) )
	return this;
    return QObject::qt_cast( clname );
}

// SIGNAL Sign_F1_Pressed
void C_KeyPressEater::Sign_F1_Pressed()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL Sign_F2_Pressed
void C_KeyPressEater::Sign_F2_Pressed()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

// SIGNAL Sign_F6_Pressed
void C_KeyPressEater::Sign_F6_Pressed()
{
    activate_signal( staticMetaObject()->signalOffset() + 2 );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL Sign_Down_Pressed
void C_KeyPressEater::Sign_Down_Pressed( QListViewItem* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 3 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL Sign_Up_Pressed
void C_KeyPressEater::Sign_Up_Pressed( QListViewItem* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 4 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

bool C_KeyPressEater::qt_invoke( int _id, QUObject* _o )
{
    return QObject::qt_invoke(_id,_o);
}

bool C_KeyPressEater::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: Sign_F1_Pressed(); break;
    case 1: Sign_F2_Pressed(); break;
    case 2: Sign_F6_Pressed(); break;
    case 3: Sign_Down_Pressed((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 4: Sign_Up_Pressed((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool C_KeyPressEater::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool C_KeyPressEater::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
