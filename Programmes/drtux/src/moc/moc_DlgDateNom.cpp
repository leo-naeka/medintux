/****************************************************************************
** DlgDateNom meta object code from reading C++ file 'DlgDateNom.h'
**
** Created: Wed May 4 22:20:43 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../ui/DlgDateNom.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *DlgDateNom::className() const
{
    return "DlgDateNom";
}

QMetaObject *DlgDateNom::metaObj = 0;
static QMetaObjectCleanUp cleanUp_DlgDateNom( "DlgDateNom", &DlgDateNom::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString DlgDateNom::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "DlgDateNom", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString DlgDateNom::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "DlgDateNom", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* DlgDateNom::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "date_time", &static_QUType_varptr, "\x03", QUParameter::In },
	{ "nom", &static_QUType_varptr, "\x03", QUParameter::In },
	{ "subType", &static_QUType_varptr, "\x03", QUParameter::In }
    };
    static const QUMethod slot_0 = {"initDialog", 3, param_slot_0 };
    static const QUMethod slot_1 = {"Slot_pushButtonDateDlg", 0, 0 };
    static const QUMethod slot_2 = {"pushButtonOK_clicked", 0, 0 };
    static const QUMethod slot_3 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "initDialog(QString*,QString*,QString*)", &slot_0, QMetaData::Public },
	{ "Slot_pushButtonDateDlg()", &slot_1, QMetaData::Public },
	{ "pushButtonOK_clicked()", &slot_2, QMetaData::Public },
	{ "languageChange()", &slot_3, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"DlgDateNom", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_DlgDateNom.setMetaObject( metaObj );
    return metaObj;
}

void* DlgDateNom::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "DlgDateNom" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool DlgDateNom::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: initDialog((QString*)static_QUType_varptr.get(_o+1),(QString*)static_QUType_varptr.get(_o+2),(QString*)static_QUType_varptr.get(_o+3)); break;
    case 1: Slot_pushButtonDateDlg(); break;
    case 2: pushButtonOK_clicked(); break;
    case 3: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool DlgDateNom::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool DlgDateNom::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool DlgDateNom::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
