/****************************************************************************
** Dlg_ImageProperty meta object code from reading C++ file 'Dlg_ImageProperty.h'
**
** Created: Wed May 4 22:20:48 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../ui/Dlg_ImageProperty.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *Dlg_ImageProperty::className() const
{
    return "Dlg_ImageProperty";
}

QMetaObject *Dlg_ImageProperty::metaObj = 0;
static QMetaObjectCleanUp cleanUp_Dlg_ImageProperty( "Dlg_ImageProperty", &Dlg_ImageProperty::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString Dlg_ImageProperty::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Dlg_ImageProperty", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString Dlg_ImageProperty::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Dlg_ImageProperty", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* Dlg_ImageProperty::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "languageChange()", &slot_0, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"Dlg_ImageProperty", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_Dlg_ImageProperty.setMetaObject( metaObj );
    return metaObj;
}

void* Dlg_ImageProperty::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "Dlg_ImageProperty" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool Dlg_ImageProperty::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool Dlg_ImageProperty::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool Dlg_ImageProperty::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool Dlg_ImageProperty::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
