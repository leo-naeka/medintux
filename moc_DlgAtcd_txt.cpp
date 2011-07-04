/****************************************************************************
** DlgAtcd_txt meta object code from reading C++ file 'DlgAtcd_txt.h'
**
** Created: Wed May 4 22:20:48 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../ui/DlgAtcd_txt.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *DlgAtcd_txt::className() const
{
    return "DlgAtcd_txt";
}

QMetaObject *DlgAtcd_txt::metaObj = 0;
static QMetaObjectCleanUp cleanUp_DlgAtcd_txt( "DlgAtcd_txt", &DlgAtcd_txt::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString DlgAtcd_txt::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "DlgAtcd_txt", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString DlgAtcd_txt::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "DlgAtcd_txt", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* DlgAtcd_txt::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"Slot_pushButtonDateDlg", 0, 0 };
    static const QUMethod slot_1 = {"Slot_pushButtonFamilleGenreEdit", 0, 0 };
    static const QUMethod slot_2 = {"setDialogForAddToThesaurus", 0, 0 };
    static const QUMethod slot_3 = {"setComboFamilyGenre", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ "pAtcd_Code", &static_QUType_ptr, "Atcd_Code", QUParameter::In },
	{ "atcd", &static_QUType_ptr, "Atcd_Element", QUParameter::In }
    };
    static const QUMethod slot_4 = {"setATCD_toView", 2, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ "familyGenre", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"setFamilyGenre", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "b", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"setToUpdate", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ "libelle", &static_QUType_QString, 0, QUParameter::InOut },
	{ "family", &static_QUType_QString, 0, QUParameter::InOut },
	{ "date", &static_QUType_QString, 0, QUParameter::InOut },
	{ "commentaire", &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod slot_7 = {"getInfos", 4, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::Out }
    };
    static const QUMethod slot_8 = {"getDate", 1, param_slot_8 };
    static const QUParameter param_slot_9[] = {
	{ "dt_str", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_9 = {"setDateObserv", 1, param_slot_9 };
    static const QUParameter param_slot_10[] = {
	{ "dt", &static_QUType_varptr, "\x1a", QUParameter::In }
    };
    static const QUMethod slot_10 = {"setDateObserv", 1, param_slot_10 };
    static const QUMethod slot_11 = {"but_Valider_clicked", 0, 0 };
    static const QUMethod slot_12 = {"but_Annuler_clicked", 0, 0 };
    static const QUParameter param_slot_13[] = {
	{ "section", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_13 = {"comboBox_Family_highlighted", 1, param_slot_13 };
    static const QUParameter param_slot_14[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_14 = {"combo_Family_activated", 1, param_slot_14 };
    static const QUParameter param_slot_15[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_15 = {"combo_Genre_activated", 1, param_slot_15 };
    static const QUMethod slot_16 = {"chkDate_clicked", 0, 0 };
    static const QUMethod slot_17 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "Slot_pushButtonDateDlg()", &slot_0, QMetaData::Public },
	{ "Slot_pushButtonFamilleGenreEdit()", &slot_1, QMetaData::Public },
	{ "setDialogForAddToThesaurus()", &slot_2, QMetaData::Public },
	{ "setComboFamilyGenre()", &slot_3, QMetaData::Public },
	{ "setATCD_toView(Atcd_Code*,Atcd_Element*)", &slot_4, QMetaData::Public },
	{ "setFamilyGenre(QString)", &slot_5, QMetaData::Public },
	{ "setToUpdate(bool)", &slot_6, QMetaData::Public },
	{ "getInfos(QString&,QString&,QString&,QString&)", &slot_7, QMetaData::Public },
	{ "getDate()", &slot_8, QMetaData::Public },
	{ "setDateObserv(QString)", &slot_9, QMetaData::Public },
	{ "setDateObserv(QDate)", &slot_10, QMetaData::Public },
	{ "but_Valider_clicked()", &slot_11, QMetaData::Public },
	{ "but_Annuler_clicked()", &slot_12, QMetaData::Public },
	{ "comboBox_Family_highlighted(const QString&)", &slot_13, QMetaData::Public },
	{ "combo_Family_activated(int)", &slot_14, QMetaData::Public },
	{ "combo_Genre_activated(int)", &slot_15, QMetaData::Public },
	{ "chkDate_clicked()", &slot_16, QMetaData::Public },
	{ "languageChange()", &slot_17, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"DlgAtcd_txt", parentObject,
	slot_tbl, 18,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_DlgAtcd_txt.setMetaObject( metaObj );
    return metaObj;
}

void* DlgAtcd_txt::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "DlgAtcd_txt" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool DlgAtcd_txt::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: Slot_pushButtonDateDlg(); break;
    case 1: Slot_pushButtonFamilleGenreEdit(); break;
    case 2: setDialogForAddToThesaurus(); break;
    case 3: setComboFamilyGenre(); break;
    case 4: setATCD_toView((Atcd_Code*)static_QUType_ptr.get(_o+1),(Atcd_Element*)static_QUType_ptr.get(_o+2)); break;
    case 5: setFamilyGenre((QString)static_QUType_QString.get(_o+1)); break;
    case 6: setToUpdate((bool)static_QUType_bool.get(_o+1)); break;
    case 7: getInfos((QString&)static_QUType_QString.get(_o+1),(QString&)static_QUType_QString.get(_o+2),(QString&)static_QUType_QString.get(_o+3),(QString&)static_QUType_QString.get(_o+4)); break;
    case 8: static_QUType_QString.set(_o,getDate()); break;
    case 9: setDateObserv((QString)static_QUType_QString.get(_o+1)); break;
    case 10: setDateObserv((QDate)(*((QDate*)static_QUType_ptr.get(_o+1)))); break;
    case 11: but_Valider_clicked(); break;
    case 12: but_Annuler_clicked(); break;
    case 13: comboBox_Family_highlighted((const QString&)static_QUType_QString.get(_o+1)); break;
    case 14: combo_Family_activated((int)static_QUType_int.get(_o+1)); break;
    case 15: combo_Genre_activated((int)static_QUType_int.get(_o+1)); break;
    case 16: chkDate_clicked(); break;
    case 17: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool DlgAtcd_txt::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool DlgAtcd_txt::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool DlgAtcd_txt::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
