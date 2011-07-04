/****************************************************************************
** DlgGetText meta object code from reading C++ file 'DlgGetText.h'
**
** Created: Wed May 4 22:20:42 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../ui/DlgGetText.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *DlgGetText::className() const
{
    return "DlgGetText";
}

QMetaObject *DlgGetText::metaObj = 0;
static QMetaObjectCleanUp cleanUp_DlgGetText( "DlgGetText", &DlgGetText::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString DlgGetText::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "DlgGetText", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString DlgGetText::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "DlgGetText", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* DlgGetText::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"pushButtonOK_clicked", 0, 0 };
    static const QUMethod slot_1 = {"pushButtonCancel_clicked", 0, 0 };
    static const QUMethod slot_2 = {"pushButtonClearAndQuit_clicked", 0, 0 };
    static const QUMethod slot_3 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "pushButtonOK_clicked()", &slot_0, QMetaData::Public },
	{ "pushButtonCancel_clicked()", &slot_1, QMetaData::Public },
	{ "pushButtonClearAndQuit_clicked()", &slot_2, QMetaData::Public },
	{ "languageChange()", &slot_3, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"DlgGetText", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_DlgGetText.setMetaObject( metaObj );
    return metaObj;
}

void* DlgGetText::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "DlgGetText" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool DlgGetText::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: pushButtonOK_clicked(); break;
    case 1: pushButtonCancel_clicked(); break;
    case 2: pushButtonClearAndQuit_clicked(); break;
    case 3: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool DlgGetText::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool DlgGetText::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool DlgGetText::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
