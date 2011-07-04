/****************************************************************************
** CMyQTable meta object code from reading C++ file 'CMyQtable.h'
**
** Created: Wed May 4 22:20:17 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../CMyQtable.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CMyQTable::className() const
{
    return "CMyQTable";
}

QMetaObject *CMyQTable::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CMyQTable( "CMyQTable", &CMyQTable::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CMyQTable::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CMyQTable", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CMyQTable::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CMyQTable", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CMyQTable::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QTable::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "row", &static_QUType_int, 0, QUParameter::In },
	{ "col", &static_QUType_int, 0, QUParameter::In },
	{ "pos", &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_0 = {"Slot_ContextMenuRequested", 3, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "row", &static_QUType_int, 0, QUParameter::In },
	{ "col", &static_QUType_int, 0, QUParameter::In },
	{ "button", &static_QUType_int, 0, QUParameter::In },
	{ "mousePos", &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_1 = {"Slot_Clicked", 4, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "row", &static_QUType_int, 0, QUParameter::In },
	{ "col", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"Slot_ValueChanged", 2, param_slot_2 };
    static const QMetaData slot_tbl[] = {
	{ "Slot_ContextMenuRequested(int,int,const QPoint&)", &slot_0, QMetaData::Public },
	{ "Slot_Clicked(int,int,int,const QPoint&)", &slot_1, QMetaData::Public },
	{ "Slot_ValueChanged(int,int)", &slot_2, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ "pCMyQTable", &static_QUType_ptr, "CMyQTable", QUParameter::In },
	{ "name", &static_QUType_charstar, 0, QUParameter::In },
	{ "row", &static_QUType_int, 0, QUParameter::In },
	{ "col", &static_QUType_int, 0, QUParameter::In },
	{ "pos", &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod signal_0 = {"Sign_ContextMenuRequested", 5, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "pCMyQTable", &static_QUType_ptr, "CMyQTable", QUParameter::In },
	{ "name", &static_QUType_charstar, 0, QUParameter::In },
	{ "row", &static_QUType_int, 0, QUParameter::In },
	{ "col", &static_QUType_int, 0, QUParameter::In },
	{ "button", &static_QUType_int, 0, QUParameter::In },
	{ "mousePos", &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod signal_1 = {"Sign_Clicked", 6, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ "row", &static_QUType_int, 0, QUParameter::In },
	{ "col", &static_QUType_int, 0, QUParameter::In },
	{ "pCMyQTable", &static_QUType_ptr, "CMyQTable", QUParameter::In }
    };
    static const QUMethod signal_2 = {"Sign_ValueChanged", 3, param_signal_2 };
    static const QMetaData signal_tbl[] = {
	{ "Sign_ContextMenuRequested(CMyQTable*,const char*,int,int,const QPoint&)", &signal_0, QMetaData::Public },
	{ "Sign_Clicked(CMyQTable*,const char*,int,int,int,const QPoint&)", &signal_1, QMetaData::Public },
	{ "Sign_ValueChanged(int,int,CMyQTable*)", &signal_2, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"CMyQTable", parentObject,
	slot_tbl, 3,
	signal_tbl, 3,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CMyQTable.setMetaObject( metaObj );
    return metaObj;
}

void* CMyQTable::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CMyQTable" ) )
	return this;
    return QTable::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL Sign_ContextMenuRequested
void CMyQTable::Sign_ContextMenuRequested( CMyQTable* t0, const char* t1, int t2, int t3, const QPoint& t4 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[6];
    static_QUType_ptr.set(o+1,t0);
    static_QUType_charstar.set(o+2,t1);
    static_QUType_int.set(o+3,t2);
    static_QUType_int.set(o+4,t3);
    static_QUType_varptr.set(o+5,&t4);
    activate_signal( clist, o );
}

// SIGNAL Sign_Clicked
void CMyQTable::Sign_Clicked( CMyQTable* t0, const char* t1, int t2, int t3, int t4, const QPoint& t5 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[7];
    static_QUType_ptr.set(o+1,t0);
    static_QUType_charstar.set(o+2,t1);
    static_QUType_int.set(o+3,t2);
    static_QUType_int.set(o+4,t3);
    static_QUType_int.set(o+5,t4);
    static_QUType_varptr.set(o+6,&t5);
    activate_signal( clist, o );
}

// SIGNAL Sign_ValueChanged
void CMyQTable::Sign_ValueChanged( int t0, int t1, CMyQTable* t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_int.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    static_QUType_ptr.set(o+3,t2);
    activate_signal( clist, o );
}

bool CMyQTable::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: Slot_ContextMenuRequested((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+3))); break;
    case 1: Slot_Clicked((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 2: Slot_ValueChanged((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    default:
	return QTable::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CMyQTable::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: Sign_ContextMenuRequested((CMyQTable*)static_QUType_ptr.get(_o+1),(const char*)static_QUType_charstar.get(_o+2),(int)static_QUType_int.get(_o+3),(int)static_QUType_int.get(_o+4),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+5))); break;
    case 1: Sign_Clicked((CMyQTable*)static_QUType_ptr.get(_o+1),(const char*)static_QUType_charstar.get(_o+2),(int)static_QUType_int.get(_o+3),(int)static_QUType_int.get(_o+4),(int)static_QUType_int.get(_o+5),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+6))); break;
    case 2: Sign_ValueChanged((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(CMyQTable*)static_QUType_ptr.get(_o+3)); break;
    default:
	return QTable::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool CMyQTable::qt_property( int id, int f, QVariant* v)
{
    return QTable::qt_property( id, f, v);
}

bool CMyQTable::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
