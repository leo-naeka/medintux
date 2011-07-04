/****************************************************************************
** ThemePopup meta object code from reading C++ file 'ThemePopup.h'
**
** Created: Wed May 4 22:15:52 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../../../MedinTuxTools/ThemePopup.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *ThemePopup::className() const
{
    return "ThemePopup";
}

QMetaObject *ThemePopup::metaObj = 0;
static QMetaObjectCleanUp cleanUp_ThemePopup( "ThemePopup", &ThemePopup::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString ThemePopup::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ThemePopup", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString ThemePopup::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ThemePopup", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* ThemePopup::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QPopupMenu::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"memorisePopupItem", 1, param_slot_0 };
    static const QUMethod slot_1 = {"OnSelectPopupItem", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "memorisePopupItem(int)", &slot_0, QMetaData::Protected },
	{ "OnSelectPopupItem()", &slot_1, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"ThemePopup", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_ThemePopup.setMetaObject( metaObj );
    return metaObj;
}

void* ThemePopup::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "ThemePopup" ) )
	return this;
    return QPopupMenu::qt_cast( clname );
}

bool ThemePopup::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: memorisePopupItem((int)static_QUType_int.get(_o+1)); break;
    case 1: OnSelectPopupItem(); break;
    default:
	return QPopupMenu::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool ThemePopup::qt_emit( int _id, QUObject* _o )
{
    return QPopupMenu::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool ThemePopup::qt_property( int id, int f, QVariant* v)
{
    return QPopupMenu::qt_property( id, f, v);
}

bool ThemePopup::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
