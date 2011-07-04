/****************************************************************************
** Dlg_InsertList meta object code from reading C++ file 'DLG_InsertList.h'
**
** Created: Wed May 4 22:20:38 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../ui/DLG_InsertList.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *Dlg_InsertList::className() const
{
    return "Dlg_InsertList";
}

QMetaObject *Dlg_InsertList::metaObj = 0;
static QMetaObjectCleanUp cleanUp_Dlg_InsertList( "Dlg_InsertList", &Dlg_InsertList::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString Dlg_InsertList::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Dlg_InsertList", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString Dlg_InsertList::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Dlg_InsertList", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* Dlg_InsertList::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pQStringList", &static_QUType_varptr, "\x04", QUParameter::InOut }
    };
    static const QUMethod slot_0 = {"initDialog", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "pQStringList", &static_QUType_varptr, "\x04", QUParameter::InOut },
	{ "nbField", &static_QUType_int, 0, QUParameter::In },
	{ "modeSel", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"initDialogField", 3, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "text_in", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"lineEdit_Find_textChanged", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "pQListBoxItem", &static_QUType_ptr, "QListBoxItem", QUParameter::In }
    };
    static const QUMethod slot_3 = {"listBox_InsertList_doubleClicked", 1, param_slot_3 };
    static const QUMethod slot_4 = {"pushButtonOk_clicked", 0, 0 };
    static const QUParameter param_slot_5[] = {
	{ "pQListBoxItem", &static_QUType_ptr, "QListBoxItem", QUParameter::In }
    };
    static const QUMethod slot_5 = {"listBox_InsertList_returnPressed", 1, param_slot_5 };
    static const QUMethod slot_6 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "initDialog(QStringList&)", &slot_0, QMetaData::Public },
	{ "initDialogField(QStringList&,int,const QString&)", &slot_1, QMetaData::Public },
	{ "lineEdit_Find_textChanged(const QString&)", &slot_2, QMetaData::Public },
	{ "listBox_InsertList_doubleClicked(QListBoxItem*)", &slot_3, QMetaData::Public },
	{ "pushButtonOk_clicked()", &slot_4, QMetaData::Public },
	{ "listBox_InsertList_returnPressed(QListBoxItem*)", &slot_5, QMetaData::Public },
	{ "languageChange()", &slot_6, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"Dlg_InsertList", parentObject,
	slot_tbl, 7,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_Dlg_InsertList.setMetaObject( metaObj );
    return metaObj;
}

void* Dlg_InsertList::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "Dlg_InsertList" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool Dlg_InsertList::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: initDialog((QStringList&)*((QStringList*)static_QUType_ptr.get(_o+1))); break;
    case 1: initDialogField((QStringList&)*((QStringList*)static_QUType_ptr.get(_o+1)),(int)static_QUType_int.get(_o+2),(const QString&)static_QUType_QString.get(_o+3)); break;
    case 2: lineEdit_Find_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 3: listBox_InsertList_doubleClicked((QListBoxItem*)static_QUType_ptr.get(_o+1)); break;
    case 4: pushButtonOk_clicked(); break;
    case 5: listBox_InsertList_returnPressed((QListBoxItem*)static_QUType_ptr.get(_o+1)); break;
    case 6: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool Dlg_InsertList::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool Dlg_InsertList::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool Dlg_InsertList::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
