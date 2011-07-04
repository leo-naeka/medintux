/****************************************************************************
** C_Dlg_FamilleGenre meta object code from reading C++ file 'C_Dlg_FamilleGenre.h'
**
** Created: Wed May 4 22:20:32 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../C_Dlg_FamilleGenre.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *C_Dlg_FamilleGenre::className() const
{
    return "C_Dlg_FamilleGenre";
}

QMetaObject *C_Dlg_FamilleGenre::metaObj = 0;
static QMetaObjectCleanUp cleanUp_C_Dlg_FamilleGenre( "C_Dlg_FamilleGenre", &C_Dlg_FamilleGenre::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString C_Dlg_FamilleGenre::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_Dlg_FamilleGenre", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString C_Dlg_FamilleGenre::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_Dlg_FamilleGenre", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* C_Dlg_FamilleGenre::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = Dlg_FamilleGenre::staticMetaObject();
    static const QUMethod slot_0 = {"Slot_pushButton_save", 0, 0 };
    static const QUMethod slot_1 = {"Slot_pushButton_del", 0, 0 };
    static const QUMethod slot_2 = {"Slot_pushButton_add_Famille", 0, 0 };
    static const QUMethod slot_3 = {"Slot_pushButton_add_Genre", 0, 0 };
    static const QUMethod slot_4 = {"Slot_reject", 0, 0 };
    static const QUMethod slot_5 = {"Slot_accept", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "Slot_pushButton_save()", &slot_0, QMetaData::Protected },
	{ "Slot_pushButton_del()", &slot_1, QMetaData::Protected },
	{ "Slot_pushButton_add_Famille()", &slot_2, QMetaData::Protected },
	{ "Slot_pushButton_add_Genre()", &slot_3, QMetaData::Protected },
	{ "Slot_reject()", &slot_4, QMetaData::Protected },
	{ "Slot_accept()", &slot_5, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"C_Dlg_FamilleGenre", parentObject,
	slot_tbl, 6,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_C_Dlg_FamilleGenre.setMetaObject( metaObj );
    return metaObj;
}

void* C_Dlg_FamilleGenre::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "C_Dlg_FamilleGenre" ) )
	return this;
    return Dlg_FamilleGenre::qt_cast( clname );
}

bool C_Dlg_FamilleGenre::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: Slot_pushButton_save(); break;
    case 1: Slot_pushButton_del(); break;
    case 2: Slot_pushButton_add_Famille(); break;
    case 3: Slot_pushButton_add_Genre(); break;
    case 4: Slot_reject(); break;
    case 5: Slot_accept(); break;
    default:
	return Dlg_FamilleGenre::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool C_Dlg_FamilleGenre::qt_emit( int _id, QUObject* _o )
{
    return Dlg_FamilleGenre::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool C_Dlg_FamilleGenre::qt_property( int id, int f, QVariant* v)
{
    return Dlg_FamilleGenre::qt_property( id, f, v);
}

bool C_Dlg_FamilleGenre::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
