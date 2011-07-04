/****************************************************************************
** C_ListViewATCDManager meta object code from reading C++ file 'C_ListViewATCDManager.h'
**
** Created: Wed May 4 22:20:32 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../C_ListViewATCDManager.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *C_ListViewATCDManager::className() const
{
    return "C_ListViewATCDManager";
}

QMetaObject *C_ListViewATCDManager::metaObj = 0;
static QMetaObjectCleanUp cleanUp_C_ListViewATCDManager( "C_ListViewATCDManager", &C_ListViewATCDManager::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString C_ListViewATCDManager::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_ListViewATCDManager", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString C_ListViewATCDManager::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_ListViewATCDManager", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* C_ListViewATCDManager::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "qlistViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ "pos", &static_QUType_varptr, "\x0e", QUParameter::In },
	{ "c", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"Slot_listView_ATCD_contextMenuRequested", 3, param_slot_0 };
    static const QUMethod slot_1 = {"ATCD_MenuActionNewCIM10", 0, 0 };
    static const QUMethod slot_2 = {"ATCD_MenuActionNewAllergie", 0, 0 };
    static const QUMethod slot_3 = {"ATCD_MenuActionNewTexteLibre", 0, 0 };
    static const QUMethod slot_4 = {"ATCD_MenuActionMultiDel", 0, 0 };
    static const QUMethod slot_5 = {"ATCD_MenuActionSetDate", 0, 0 };
    static const QUMethod slot_6 = {"ATCD_MenuActionDelDate", 0, 0 };
    static const QUMethod slot_7 = {"ATCD_MenuActionChangeEtatActif", 0, 0 };
    static const QUMethod slot_8 = {"ATCD_MenuActionChangeEtatGueri", 0, 0 };
    static const QUMethod slot_9 = {"ATCD_MenuActionSetCommentaire", 0, 0 };
    static const QUMethod slot_10 = {"ATCD_setAldOn", 0, 0 };
    static const QUMethod slot_11 = {"ATCD_setAldOff", 0, 0 };
    static const QUMethod slot_12 = {"ATCD_MenuActionSetFamilleGenre", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "Slot_listView_ATCD_contextMenuRequested(QListViewItem*,const QPoint&,int)", &slot_0, QMetaData::Public },
	{ "ATCD_MenuActionNewCIM10()", &slot_1, QMetaData::Public },
	{ "ATCD_MenuActionNewAllergie()", &slot_2, QMetaData::Public },
	{ "ATCD_MenuActionNewTexteLibre()", &slot_3, QMetaData::Public },
	{ "ATCD_MenuActionMultiDel()", &slot_4, QMetaData::Public },
	{ "ATCD_MenuActionSetDate()", &slot_5, QMetaData::Public },
	{ "ATCD_MenuActionDelDate()", &slot_6, QMetaData::Public },
	{ "ATCD_MenuActionChangeEtatActif()", &slot_7, QMetaData::Public },
	{ "ATCD_MenuActionChangeEtatGueri()", &slot_8, QMetaData::Public },
	{ "ATCD_MenuActionSetCommentaire()", &slot_9, QMetaData::Public },
	{ "ATCD_setAldOn()", &slot_10, QMetaData::Public },
	{ "ATCD_setAldOff()", &slot_11, QMetaData::Public },
	{ "ATCD_MenuActionSetFamilleGenre()", &slot_12, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"C_ListViewATCDManager", parentObject,
	slot_tbl, 13,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_C_ListViewATCDManager.setMetaObject( metaObj );
    return metaObj;
}

void* C_ListViewATCDManager::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "C_ListViewATCDManager" ) )
	return this;
    return QObject::qt_cast( clname );
}

bool C_ListViewATCDManager::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: Slot_listView_ATCD_contextMenuRequested((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 1: ATCD_MenuActionNewCIM10(); break;
    case 2: ATCD_MenuActionNewAllergie(); break;
    case 3: ATCD_MenuActionNewTexteLibre(); break;
    case 4: ATCD_MenuActionMultiDel(); break;
    case 5: ATCD_MenuActionSetDate(); break;
    case 6: ATCD_MenuActionDelDate(); break;
    case 7: ATCD_MenuActionChangeEtatActif(); break;
    case 8: ATCD_MenuActionChangeEtatGueri(); break;
    case 9: ATCD_MenuActionSetCommentaire(); break;
    case 10: ATCD_setAldOn(); break;
    case 11: ATCD_setAldOff(); break;
    case 12: ATCD_MenuActionSetFamilleGenre(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool C_ListViewATCDManager::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool C_ListViewATCDManager::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool C_ListViewATCDManager::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
