/****************************************************************************
** CBigShrinker meta object code from reading C++ file 'CBigShrinker.h'
**
** Created: Wed May 4 22:20:17 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../CBigShrinker.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CBigShrinker::className() const
{
    return "CBigShrinker";
}

QMetaObject *CBigShrinker::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CBigShrinker( "CBigShrinker", &CBigShrinker::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CBigShrinker::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CBigShrinker", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CBigShrinker::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CBigShrinker", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CBigShrinker::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QFrame::staticMetaObject();
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"clicked", 2, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "clicked(int,int)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"CBigShrinker", parentObject,
	0, 0,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CBigShrinker.setMetaObject( metaObj );
    return metaObj;
}

void* CBigShrinker::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CBigShrinker" ) )
	return this;
    return QFrame::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL clicked
void CBigShrinker::clicked( int t0, int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_int.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    activate_signal( clist, o );
}

bool CBigShrinker::qt_invoke( int _id, QUObject* _o )
{
    return QFrame::qt_invoke(_id,_o);
}

bool CBigShrinker::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: clicked((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    default:
	return QFrame::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool CBigShrinker::qt_property( int id, int f, QVariant* v)
{
    return QFrame::qt_property( id, f, v);
}

bool CBigShrinker::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
