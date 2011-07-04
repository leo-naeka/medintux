/****************************************************************************
** Dlg_MedicaAdjustPoso meta object code from reading C++ file 'Dlg_MedicaAdjustPoso.h'
**
** Created: Wed May 4 22:20:45 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../ui/Dlg_MedicaAdjustPoso.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *Dlg_MedicaAdjustPoso::className() const
{
    return "Dlg_MedicaAdjustPoso";
}

QMetaObject *Dlg_MedicaAdjustPoso::metaObj = 0;
static QMetaObjectCleanUp cleanUp_Dlg_MedicaAdjustPoso( "Dlg_MedicaAdjustPoso", &Dlg_MedicaAdjustPoso::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString Dlg_MedicaAdjustPoso::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Dlg_MedicaAdjustPoso", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString Dlg_MedicaAdjustPoso::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Dlg_MedicaAdjustPoso", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* Dlg_MedicaAdjustPoso::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "cPosologieIn", &static_QUType_ptr, "CPosologie", QUParameter::InOut },
	{ "pCMDI_Terrain", &static_QUType_ptr, "CMDI_Terrain", QUParameter::In },
	{ "pPoids", &static_QUType_varptr, "\x03", QUParameter::In },
	{ "pTaille", &static_QUType_varptr, "\x03", QUParameter::In }
    };
    static const QUMethod slot_0 = {"initDialog", 4, param_slot_0 };
    static const QUMethod slot_1 = {"initComboDuree", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ "poso", &static_QUType_ptr, "CPosologie", QUParameter::InOut }
    };
    static const QUMethod slot_2 = {"InterfaceToPoso", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "nb_prises", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"SetComboRepartOnValue", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ "poso", &static_QUType_ptr, "CPosologie", QUParameter::In },
	{ "upMin", &static_QUType_QString, 0, QUParameter::InOut },
	{ "upMax", &static_QUType_QString, 0, QUParameter::InOut },
	{ "upUnit", &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod slot_4 = {"ComputeSecondForm", 4, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ "str", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"lineEdit_Poids_textChanged", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "str", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"lineEdit_Taille_textChanged", 1, param_slot_6 };
    static const QUMethod slot_7 = {"SetSecondForm", 0, 0 };
    static const QUMethod slot_8 = {"radioButtonSecable1_clicked", 0, 0 };
    static const QUMethod slot_9 = {"radioButtonSecable2_clicked", 0, 0 };
    static const QUMethod slot_10 = {"radioButtonSecable4_clicked", 0, 0 };
    static const QUMethod slot_11 = {"DisplayResult", 0, 0 };
    static const QUParameter param_slot_12[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_12 = {"slider_VarPoso_valueChanged", 1, param_slot_12 };
    static const QUParameter param_slot_13[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_13 = {"comboBoxMoment_activated", 1, param_slot_13 };
    static const QUMethod slot_14 = {"textEditNote_textChanged", 0, 0 };
    static const QUParameter param_slot_15[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_15 = {"comboBoxPendant_textChanged", 1, param_slot_15 };
    static const QUMethod slot_16 = {"pushButtonOK_clicked", 0, 0 };
    static const QUMethod slot_17 = {"pushButton_A_clicked", 0, 0 };
    static const QUMethod slot_18 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "initDialog(CPosologie&,CMDI_Terrain*,QString*,QString*)", &slot_0, QMetaData::Public },
	{ "initComboDuree()", &slot_1, QMetaData::Public },
	{ "InterfaceToPoso(CPosologie&)", &slot_2, QMetaData::Public },
	{ "SetComboRepartOnValue(int)", &slot_3, QMetaData::Public },
	{ "ComputeSecondForm(const CPosologie&,QString&,QString&,QString&)", &slot_4, QMetaData::Public },
	{ "lineEdit_Poids_textChanged(const QString&)", &slot_5, QMetaData::Public },
	{ "lineEdit_Taille_textChanged(const QString&)", &slot_6, QMetaData::Public },
	{ "SetSecondForm()", &slot_7, QMetaData::Public },
	{ "radioButtonSecable1_clicked()", &slot_8, QMetaData::Public },
	{ "radioButtonSecable2_clicked()", &slot_9, QMetaData::Public },
	{ "radioButtonSecable4_clicked()", &slot_10, QMetaData::Public },
	{ "DisplayResult()", &slot_11, QMetaData::Public },
	{ "slider_VarPoso_valueChanged(int)", &slot_12, QMetaData::Public },
	{ "comboBoxMoment_activated(const QString&)", &slot_13, QMetaData::Public },
	{ "textEditNote_textChanged()", &slot_14, QMetaData::Public },
	{ "comboBoxPendant_textChanged(const QString&)", &slot_15, QMetaData::Public },
	{ "pushButtonOK_clicked()", &slot_16, QMetaData::Public },
	{ "pushButton_A_clicked()", &slot_17, QMetaData::Public },
	{ "languageChange()", &slot_18, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"Dlg_MedicaAdjustPoso", parentObject,
	slot_tbl, 19,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_Dlg_MedicaAdjustPoso.setMetaObject( metaObj );
    return metaObj;
}

void* Dlg_MedicaAdjustPoso::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "Dlg_MedicaAdjustPoso" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool Dlg_MedicaAdjustPoso::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: initDialog((CPosologie&)*((CPosologie*)static_QUType_ptr.get(_o+1)),(CMDI_Terrain*)static_QUType_ptr.get(_o+2),(QString*)static_QUType_varptr.get(_o+3),(QString*)static_QUType_varptr.get(_o+4)); break;
    case 1: initComboDuree(); break;
    case 2: InterfaceToPoso((CPosologie&)*((CPosologie*)static_QUType_ptr.get(_o+1))); break;
    case 3: SetComboRepartOnValue((int)static_QUType_int.get(_o+1)); break;
    case 4: ComputeSecondForm((const CPosologie&)*((const CPosologie*)static_QUType_ptr.get(_o+1)),(QString&)static_QUType_QString.get(_o+2),(QString&)static_QUType_QString.get(_o+3),(QString&)static_QUType_QString.get(_o+4)); break;
    case 5: lineEdit_Poids_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 6: lineEdit_Taille_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 7: SetSecondForm(); break;
    case 8: radioButtonSecable1_clicked(); break;
    case 9: radioButtonSecable2_clicked(); break;
    case 10: radioButtonSecable4_clicked(); break;
    case 11: DisplayResult(); break;
    case 12: slider_VarPoso_valueChanged((int)static_QUType_int.get(_o+1)); break;
    case 13: comboBoxMoment_activated((const QString&)static_QUType_QString.get(_o+1)); break;
    case 14: textEditNote_textChanged(); break;
    case 15: comboBoxPendant_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 16: pushButtonOK_clicked(); break;
    case 17: pushButton_A_clicked(); break;
    case 18: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool Dlg_MedicaAdjustPoso::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool Dlg_MedicaAdjustPoso::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool Dlg_MedicaAdjustPoso::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
