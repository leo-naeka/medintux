/****************************************************************************
** Dlg_PermsUserChoice meta object code from reading C++ file 'Dlg_PermsUserChoice.h'
**
** Created: Wed May 4 22:20:38 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../ui/Dlg_PermsUserChoice.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *Dlg_PermsUserChoice::className() const
{
    return "Dlg_PermsUserChoice";
}

QMetaObject *Dlg_PermsUserChoice::metaObj = 0;
static QMetaObjectCleanUp cleanUp_Dlg_PermsUserChoice( "Dlg_PermsUserChoice", &Dlg_PermsUserChoice::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString Dlg_PermsUserChoice::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Dlg_PermsUserChoice", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString Dlg_PermsUserChoice::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Dlg_PermsUserChoice", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* Dlg_PermsUserChoice::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pCMoteurBase", &static_QUType_ptr, "CMoteurBase", QUParameter::In },
	{ "pUserList", &static_QUType_varptr, "\x04", QUParameter::In },
	{ "uniqueUser", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"initDialog", 3, param_slot_0 };
    static const QUMethod slot_1 = {"pushButtonOk_clicked", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ "user", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"setListViewOnUser", 1, param_slot_2 };
    static const QUMethod slot_3 = {"pushButtonAnnuler_clicked", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_4 = {"ListView_UserList_doubleClicked", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ "text", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"lineEditNom_textChanged", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "str", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"comboBox_Specialites_activated", 1, param_slot_6 };
    static const QUMethod slot_7 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "initDialog(CMoteurBase*,QStringList*,const QString&)", &slot_0, QMetaData::Public },
	{ "pushButtonOk_clicked()", &slot_1, QMetaData::Public },
	{ "setListViewOnUser(const QString&)", &slot_2, QMetaData::Public },
	{ "pushButtonAnnuler_clicked()", &slot_3, QMetaData::Public },
	{ "ListView_UserList_doubleClicked(QListViewItem*)", &slot_4, QMetaData::Public },
	{ "lineEditNom_textChanged(const QString&)", &slot_5, QMetaData::Public },
	{ "comboBox_Specialites_activated(const QString&)", &slot_6, QMetaData::Public },
	{ "languageChange()", &slot_7, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"Dlg_PermsUserChoice", parentObject,
	slot_tbl, 8,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_Dlg_PermsUserChoice.setMetaObject( metaObj );
    return metaObj;
}

void* Dlg_PermsUserChoice::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "Dlg_PermsUserChoice" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool Dlg_PermsUserChoice::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: initDialog((CMoteurBase*)static_QUType_ptr.get(_o+1),(QStringList*)static_QUType_varptr.get(_o+2),(const QString&)static_QUType_QString.get(_o+3)); break;
    case 1: pushButtonOk_clicked(); break;
    case 2: setListViewOnUser((const QString&)static_QUType_QString.get(_o+1)); break;
    case 3: pushButtonAnnuler_clicked(); break;
    case 4: ListView_UserList_doubleClicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 5: lineEditNom_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 6: comboBox_Specialites_activated((const QString&)static_QUType_QString.get(_o+1)); break;
    case 7: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool Dlg_PermsUserChoice::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool Dlg_PermsUserChoice::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool Dlg_PermsUserChoice::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
