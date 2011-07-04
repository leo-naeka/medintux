/****************************************************************************
** CDlg_PasswordGet meta object code from reading C++ file 'cdlg_passwordget.h'
**
** Created: Wed May 4 22:20:22 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../../../MedinTuxTools/cdlg_passwordget.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CDlg_PasswordGet::className() const
{
    return "CDlg_PasswordGet";
}

QMetaObject *CDlg_PasswordGet::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CDlg_PasswordGet( "CDlg_PasswordGet", &CDlg_PasswordGet::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CDlg_PasswordGet::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CDlg_PasswordGet", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CDlg_PasswordGet::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CDlg_PasswordGet", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CDlg_PasswordGet::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = Dlg_PasswordGet::staticMetaObject();
    static const QUMethod slot_0 = {"reject", 0, 0 };
    static const QUMethod slot_1 = {"accept", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "reject()", &slot_0, QMetaData::Protected },
	{ "accept()", &slot_1, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"CDlg_PasswordGet", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CDlg_PasswordGet.setMetaObject( metaObj );
    return metaObj;
}

void* CDlg_PasswordGet::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CDlg_PasswordGet" ) )
	return this;
    return Dlg_PasswordGet::qt_cast( clname );
}

bool CDlg_PasswordGet::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: reject(); break;
    case 1: accept(); break;
    default:
	return Dlg_PasswordGet::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CDlg_PasswordGet::qt_emit( int _id, QUObject* _o )
{
    return Dlg_PasswordGet::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool CDlg_PasswordGet::qt_property( int id, int f, QVariant* v)
{
    return Dlg_PasswordGet::qt_property( id, f, v);
}

bool CDlg_PasswordGet::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
