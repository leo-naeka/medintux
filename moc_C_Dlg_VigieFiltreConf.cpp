/****************************************************************************
** C_Dlg_VigieFiltreConf meta object code from reading C++ file 'C_Dlg_VigieFiltreConf.h'
**
** Created: Wed May 4 22:20:30 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../C_Dlg_VigieFiltreConf.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *C_Dlg_VigieFiltreConf::className() const
{
    return "C_Dlg_VigieFiltreConf";
}

QMetaObject *C_Dlg_VigieFiltreConf::metaObj = 0;
static QMetaObjectCleanUp cleanUp_C_Dlg_VigieFiltreConf( "C_Dlg_VigieFiltreConf", &C_Dlg_VigieFiltreConf::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString C_Dlg_VigieFiltreConf::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_Dlg_VigieFiltreConf", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString C_Dlg_VigieFiltreConf::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_Dlg_VigieFiltreConf", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* C_Dlg_VigieFiltreConf::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = Dlg_VigieFiltreConf::staticMetaObject();
    static const QUMethod slot_0 = {"reject", 0, 0 };
    static const QUMethod slot_1 = {"accept", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "reject()", &slot_0, QMetaData::Protected },
	{ "accept()", &slot_1, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"C_Dlg_VigieFiltreConf", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_C_Dlg_VigieFiltreConf.setMetaObject( metaObj );
    return metaObj;
}

void* C_Dlg_VigieFiltreConf::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "C_Dlg_VigieFiltreConf" ) )
	return this;
    return Dlg_VigieFiltreConf::qt_cast( clname );
}

bool C_Dlg_VigieFiltreConf::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: reject(); break;
    case 1: accept(); break;
    default:
	return Dlg_VigieFiltreConf::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool C_Dlg_VigieFiltreConf::qt_emit( int _id, QUObject* _o )
{
    return Dlg_VigieFiltreConf::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool C_Dlg_VigieFiltreConf::qt_property( int id, int f, QVariant* v)
{
    return Dlg_VigieFiltreConf::qt_property( id, f, v);
}

bool C_Dlg_VigieFiltreConf::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
