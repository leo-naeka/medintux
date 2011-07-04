/****************************************************************************
** C_Dlg_ChoixUser meta object code from reading C++ file 'C_Dlg_ChoixUser.h'
**
** Created: Wed May 4 22:20:31 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../C_Dlg_ChoixUser.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *C_Dlg_ChoixUser::className() const
{
    return "C_Dlg_ChoixUser";
}

QMetaObject *C_Dlg_ChoixUser::metaObj = 0;
static QMetaObjectCleanUp cleanUp_C_Dlg_ChoixUser( "C_Dlg_ChoixUser", &C_Dlg_ChoixUser::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString C_Dlg_ChoixUser::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_Dlg_ChoixUser", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString C_Dlg_ChoixUser::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_Dlg_ChoixUser", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* C_Dlg_ChoixUser::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = DlgChoixUser::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "password", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"lineEditPassWord_textChanged", 1, param_slot_0 };
    static const QUMethod slot_1 = {"pushButtonConfig_clicked", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_2 = {"ListView_UserList_doubleClicked", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_3 = {"ListView_UserList_clicked", 1, param_slot_3 };
    static const QUMethod slot_4 = {"pushButtonOK_clicked", 0, 0 };
    static const QUMethod slot_5 = {"pushButtonAnnuler_clicked", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "lineEditPassWord_textChanged(const QString&)", &slot_0, QMetaData::Public },
	{ "pushButtonConfig_clicked()", &slot_1, QMetaData::Public },
	{ "ListView_UserList_doubleClicked(QListViewItem*)", &slot_2, QMetaData::Public },
	{ "ListView_UserList_clicked(QListViewItem*)", &slot_3, QMetaData::Public },
	{ "pushButtonOK_clicked()", &slot_4, QMetaData::Public },
	{ "pushButtonAnnuler_clicked()", &slot_5, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"C_Dlg_ChoixUser", parentObject,
	slot_tbl, 6,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_C_Dlg_ChoixUser.setMetaObject( metaObj );
    return metaObj;
}

void* C_Dlg_ChoixUser::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "C_Dlg_ChoixUser" ) )
	return this;
    return DlgChoixUser::qt_cast( clname );
}

bool C_Dlg_ChoixUser::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: lineEditPassWord_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 1: pushButtonConfig_clicked(); break;
    case 2: ListView_UserList_doubleClicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 3: ListView_UserList_clicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 4: pushButtonOK_clicked(); break;
    case 5: pushButtonAnnuler_clicked(); break;
    default:
	return DlgChoixUser::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool C_Dlg_ChoixUser::qt_emit( int _id, QUObject* _o )
{
    return DlgChoixUser::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool C_Dlg_ChoixUser::qt_property( int id, int f, QVariant* v)
{
    return DlgChoixUser::qt_property( id, f, v);
}

bool C_Dlg_ChoixUser::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
