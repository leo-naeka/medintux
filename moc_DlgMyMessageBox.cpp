/****************************************************************************
** FormDlgMyMessageBox meta object code from reading C++ file 'DlgMyMessageBox.h'
**
** Created: Wed May 4 22:20:40 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../ui/DlgMyMessageBox.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *FormDlgMyMessageBox::className() const
{
    return "FormDlgMyMessageBox";
}

QMetaObject *FormDlgMyMessageBox::metaObj = 0;
static QMetaObjectCleanUp cleanUp_FormDlgMyMessageBox( "FormDlgMyMessageBox", &FormDlgMyMessageBox::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString FormDlgMyMessageBox::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "FormDlgMyMessageBox", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString FormDlgMyMessageBox::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "FormDlgMyMessageBox", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* FormDlgMyMessageBox::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"pushButton1_clicked", 0, 0 };
    static const QUMethod slot_1 = {"pushButton2_clicked", 0, 0 };
    static const QUMethod slot_2 = {"pushButton3_clicked", 0, 0 };
    static const QUMethod slot_3 = {"pushButton4_clicked", 0, 0 };
    static const QUMethod slot_4 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "pushButton1_clicked()", &slot_0, QMetaData::Public },
	{ "pushButton2_clicked()", &slot_1, QMetaData::Public },
	{ "pushButton3_clicked()", &slot_2, QMetaData::Public },
	{ "pushButton4_clicked()", &slot_3, QMetaData::Public },
	{ "languageChange()", &slot_4, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"FormDlgMyMessageBox", parentObject,
	slot_tbl, 5,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_FormDlgMyMessageBox.setMetaObject( metaObj );
    return metaObj;
}

void* FormDlgMyMessageBox::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "FormDlgMyMessageBox" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool FormDlgMyMessageBox::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: pushButton1_clicked(); break;
    case 1: pushButton2_clicked(); break;
    case 2: pushButton3_clicked(); break;
    case 3: pushButton4_clicked(); break;
    case 4: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool FormDlgMyMessageBox::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool FormDlgMyMessageBox::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool FormDlgMyMessageBox::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
