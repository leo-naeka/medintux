/****************************************************************************
** FormRubIdent meta object code from reading C++ file 'RubIdentite.h'
**
** Created: Wed May 4 22:20:34 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../ui/RubIdentite.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *FormRubIdent::className() const
{
    return "FormRubIdent";
}

QMetaObject *FormRubIdent::metaObj = 0;
static QMetaObjectCleanUp cleanUp_FormRubIdent( "FormRubIdent", &FormRubIdent::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString FormRubIdent::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "FormRubIdent", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString FormRubIdent::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "FormRubIdent", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* FormRubIdent::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "languageChange()", &slot_0, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"FormRubIdent", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_FormRubIdent.setMetaObject( metaObj );
    return metaObj;
}

void* FormRubIdent::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "FormRubIdent" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool FormRubIdent::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: languageChange(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool FormRubIdent::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool FormRubIdent::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool FormRubIdent::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
