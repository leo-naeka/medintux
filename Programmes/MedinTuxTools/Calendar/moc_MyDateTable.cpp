/****************************************************************************
** MyDateTable meta object code from reading C++ file 'MyDateTable.h'
**
** Created: Fri Apr 1 20:27:23 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "MyDateTable.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *MyDateTable::className() const
{
    return "MyDateTable";
}

QMetaObject *MyDateTable::metaObj = 0;
static QMetaObjectCleanUp cleanUp_MyDateTable( "MyDateTable", &MyDateTable::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString MyDateTable::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MyDateTable", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString MyDateTable::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MyDateTable", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* MyDateTable::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QGridView::staticMetaObject();
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_varptr, "\x1a", QUParameter::In }
    };
    static const QUMethod signal_0 = {"dateChanged", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "cur", &static_QUType_varptr, "\x1a", QUParameter::In },
	{ "old", &static_QUType_varptr, "\x1a", QUParameter::In }
    };
    static const QUMethod signal_1 = {"dateChanged", 2, param_signal_1 };
    static const QUMethod signal_2 = {"tableClicked", 0, 0 };
    static const QUMethod signal_3 = {"tableDoubleClicked", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "dateChanged(QDate)", &signal_0, QMetaData::Protected },
	{ "dateChanged(const QDate&,const QDate&)", &signal_1, QMetaData::Protected },
	{ "tableClicked()", &signal_2, QMetaData::Protected },
	{ "tableDoubleClicked()", &signal_3, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"MyDateTable", parentObject,
	0, 0,
	signal_tbl, 4,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_MyDateTable.setMetaObject( metaObj );
    return metaObj;
}

void* MyDateTable::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "MyDateTable" ) )
	return this;
    return QGridView::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL dateChanged
void MyDateTable::dateChanged( QDate t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_varptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL dateChanged
void MyDateTable::dateChanged( const QDate& t0, const QDate& t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_varptr.set(o+1,&t0);
    static_QUType_varptr.set(o+2,&t1);
    activate_signal( clist, o );
}

// SIGNAL tableClicked
void MyDateTable::tableClicked()
{
    activate_signal( staticMetaObject()->signalOffset() + 2 );
}

// SIGNAL tableDoubleClicked
void MyDateTable::tableDoubleClicked()
{
    activate_signal( staticMetaObject()->signalOffset() + 3 );
}

bool MyDateTable::qt_invoke( int _id, QUObject* _o )
{
    return QGridView::qt_invoke(_id,_o);
}

bool MyDateTable::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: dateChanged((QDate)(*((QDate*)static_QUType_ptr.get(_o+1)))); break;
    case 1: dateChanged((const QDate&)*((const QDate*)static_QUType_ptr.get(_o+1)),(const QDate&)*((const QDate*)static_QUType_ptr.get(_o+2))); break;
    case 2: tableClicked(); break;
    case 3: tableDoubleClicked(); break;
    default:
	return QGridView::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool MyDateTable::qt_property( int id, int f, QVariant* v)
{
    return QGridView::qt_property( id, f, v);
}

bool MyDateTable::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
