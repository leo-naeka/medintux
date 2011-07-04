/****************************************************************************
** C_DragQListView meta object code from reading C++ file 'CPrtQListViewItem.h'
**
** Created: Wed May 4 22:15:52 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../../../MedinTuxTools/CPrtQListViewItem.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *C_DragQListView::className() const
{
    return "C_DragQListView";
}

QMetaObject *C_DragQListView::metaObj = 0;
static QMetaObjectCleanUp cleanUp_C_DragQListView( "C_DragQListView", &C_DragQListView::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString C_DragQListView::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_DragQListView", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString C_DragQListView::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_DragQListView", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* C_DragQListView::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QListView::staticMetaObject();
    static const QUMethod slot_0 = {"openFolder", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "openFolder()", &slot_0, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ "dragBreak", &static_QUType_bool, 0, QUParameter::InOut }
    };
    static const QUMethod signal_0 = {"Sign_DragMoveEvent", 2, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod signal_1 = {"Sign_ItemClicked", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"Sign_ItemDraged_On_AnotherItem", 3, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_ptr, "QStrList", QUParameter::InOut },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_3 = {"Sign_FilesDraged_On_Item", 3, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_4 = {"Sign_TextDraged_On_Item", 3, param_signal_4 };
    static const QMetaData signal_tbl[] = {
	{ "Sign_DragMoveEvent(QListViewItem*,bool&)", &signal_0, QMetaData::Public },
	{ "Sign_ItemClicked(QListViewItem*)", &signal_1, QMetaData::Public },
	{ "Sign_ItemDraged_On_AnotherItem(QListViewItem*,QListViewItem*,const QString&)", &signal_2, QMetaData::Public },
	{ "Sign_FilesDraged_On_Item(QListViewItem*,QStrList&,const QString&)", &signal_3, QMetaData::Public },
	{ "Sign_TextDraged_On_Item(QListViewItem*,const QString&,const QString&)", &signal_4, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"C_DragQListView", parentObject,
	slot_tbl, 1,
	signal_tbl, 5,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_C_DragQListView.setMetaObject( metaObj );
    return metaObj;
}

void* C_DragQListView::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "C_DragQListView" ) )
	return this;
    return QListView::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL Sign_DragMoveEvent
void C_DragQListView::Sign_DragMoveEvent( QListViewItem* t0, bool& t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,t0);
    static_QUType_bool.set(o+2,t1);
    activate_signal( clist, o );
    t1 = static_QUType_bool.get(o+2);
}

// SIGNAL Sign_ItemClicked
void C_DragQListView::Sign_ItemClicked( QListViewItem* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL Sign_ItemDraged_On_AnotherItem
void C_DragQListView::Sign_ItemDraged_On_AnotherItem( QListViewItem* t0, QListViewItem* t1, const QString& t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_ptr.set(o+1,t0);
    static_QUType_ptr.set(o+2,t1);
    static_QUType_QString.set(o+3,t2);
    activate_signal( clist, o );
}

// SIGNAL Sign_FilesDraged_On_Item
void C_DragQListView::Sign_FilesDraged_On_Item( QListViewItem* t0, QStrList& t1, const QString& t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 3 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_ptr.set(o+1,t0);
    static_QUType_ptr.set(o+2,&t1);
    static_QUType_QString.set(o+3,t2);
    activate_signal( clist, o );
}

// SIGNAL Sign_TextDraged_On_Item
void C_DragQListView::Sign_TextDraged_On_Item( QListViewItem* t0, const QString& t1, const QString& t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 4 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_ptr.set(o+1,t0);
    static_QUType_QString.set(o+2,t1);
    static_QUType_QString.set(o+3,t2);
    activate_signal( clist, o );
}

bool C_DragQListView::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: openFolder(); break;
    default:
	return QListView::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool C_DragQListView::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: Sign_DragMoveEvent((QListViewItem*)static_QUType_ptr.get(_o+1),(bool&)static_QUType_bool.get(_o+2)); break;
    case 1: Sign_ItemClicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 2: Sign_ItemDraged_On_AnotherItem((QListViewItem*)static_QUType_ptr.get(_o+1),(QListViewItem*)static_QUType_ptr.get(_o+2),(const QString&)static_QUType_QString.get(_o+3)); break;
    case 3: Sign_FilesDraged_On_Item((QListViewItem*)static_QUType_ptr.get(_o+1),(QStrList&)*((QStrList*)static_QUType_ptr.get(_o+2)),(const QString&)static_QUType_QString.get(_o+3)); break;
    case 4: Sign_TextDraged_On_Item((QListViewItem*)static_QUType_ptr.get(_o+1),(const QString&)static_QUType_QString.get(_o+2),(const QString&)static_QUType_QString.get(_o+3)); break;
    default:
	return QListView::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool C_DragQListView::qt_property( int id, int f, QVariant* v)
{
    return QListView::qt_property( id, f, v);
}

bool C_DragQListView::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
