/****************************************************************************
** C_MUI_App meta object code from reading C++ file 'C_MUI_App.h'
**
** Created: Wed May 4 22:20:11 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../../../SesamVitale-QT3/C_MUI_App.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *C_MUI_App::className() const
{
    return "C_MUI_App";
}

QMetaObject *C_MUI_App::metaObj = 0;
static QMetaObjectCleanUp cleanUp_C_MUI_App( "C_MUI_App", &C_MUI_App::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString C_MUI_App::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_MUI_App", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString C_MUI_App::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_MUI_App", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* C_MUI_App::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QtSingleApplication::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"C_MUI_App", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_C_MUI_App.setMetaObject( metaObj );
    return metaObj;
}

void* C_MUI_App::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "C_MUI_App" ) )
	return this;
    return QtSingleApplication::qt_cast( clname );
}

bool C_MUI_App::qt_invoke( int _id, QUObject* _o )
{
    return QtSingleApplication::qt_invoke(_id,_o);
}

bool C_MUI_App::qt_emit( int _id, QUObject* _o )
{
    return QtSingleApplication::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool C_MUI_App::qt_property( int id, int f, QVariant* v)
{
    return QtSingleApplication::qt_property( id, f, v);
}

bool C_MUI_App::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
