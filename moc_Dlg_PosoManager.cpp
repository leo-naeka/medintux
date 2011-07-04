/****************************************************************************
** Dlg_PosoManager meta object code from reading C++ file 'Dlg_PosoManager.h'
**
** Created: Wed May 4 22:20:44 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../ui/Dlg_PosoManager.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *Dlg_PosoManager::className() const
{
    return "Dlg_PosoManager";
}

QMetaObject *Dlg_PosoManager::metaObj = 0;
static QMetaObjectCleanUp cleanUp_Dlg_PosoManager( "Dlg_PosoManager", &Dlg_PosoManager::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString Dlg_PosoManager::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Dlg_PosoManager", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString Dlg_PosoManager::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Dlg_PosoManager", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* Dlg_PosoManager::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "cip", &static_QUType_QString, 0, QUParameter::In },
	{ "tableSpecIndex", &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ "pQListView", &static_QUType_ptr, "QListView", QUParameter::In }
    };
    static const QUMethod slot_0 = {"initDialog", 4, param_slot_0 };
    static const QUMethod slot_1 = {"pushButton_QuitterClicked", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"lineEdit_PoidsTest_textChanged", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"lineEdit_TailleTest_textChanged", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"lineEdit_QMin_UP1_textChanged", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"lineEdit_QMax_UP1_textChanged", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"lineEditFactCorpQU_textChanged", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ "pQListView", &static_QUType_ptr, "QListView", QUParameter::In }
    };
    static const QUMethod slot_7 = {"ListViewProduitCopy", 1, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_8 = {"listView_Produits_clicked", 1, param_slot_8 };
    static const QUParameter param_slot_9[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_9 = {"listView_Produits_currentChanged", 1, param_slot_9 };
    static const QUParameter param_slot_10[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_10 = {"listView_Produits_Changed", 1, param_slot_10 };
    static const QUParameter param_slot_11[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_11 = {"listView_MedicaPoso_currentChanged", 1, param_slot_11 };
    static const QUParameter param_slot_12[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_12 = {"listView_MedicaPoso_clicked", 1, param_slot_12 };
    static const QUParameter param_slot_13[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_13 = {"listView_ItemToInterface", 1, param_slot_13 };
    static const QUParameter param_slot_14[] = {
	{ "poso", &static_QUType_ptr, "CPosologie", QUParameter::InOut }
    };
    static const QUMethod slot_14 = {"CPosologieToInterface", 1, param_slot_14 };
    static const QUParameter param_slot_15[] = {
	{ "poso", &static_QUType_ptr, "CPosologie", QUParameter::InOut }
    };
    static const QUMethod slot_15 = {"InterfaceToCPosologie", 1, param_slot_15 };
    static const QUMethod slot_16 = {"DisplayResult", 0, 0 };
    static const QUParameter param_slot_17[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out },
	{ "spec", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_17 = {"ComputeNbPrises", 2, param_slot_17 };
    static const QUParameter param_slot_18[] = {
	{ 0, &static_QUType_ptr, "CPosologie", QUParameter::In },
	{ "upMin", &static_QUType_QString, 0, QUParameter::InOut },
	{ "upMax", &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod slot_18 = {"ComputeSecondForm", 3, param_slot_18 };
    static const QUParameter param_slot_19[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_19 = {"slider_VarPoso_valueChanged", 1, param_slot_19 };
    static const QUMethod slot_20 = {"radioButtonSecable1_clicked", 0, 0 };
    static const QUMethod slot_21 = {"radioButtonSecable2_clicked", 0, 0 };
    static const QUMethod slot_22 = {"radioButtonSecable4_clicked", 0, 0 };
    static const QUParameter param_slot_23[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out }
    };
    static const QUMethod slot_23 = {"getSecabilite", 1, param_slot_23 };
    static const QUParameter param_slot_24[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_24 = {"comboBoxMoment_activated", 1, param_slot_24 };
    static const QUParameter param_slot_25[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_25 = {"comboBoxUP_1_textChanged", 1, param_slot_25 };
    static const QUParameter param_slot_26[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_26 = {"comboBoxUP_1_activated", 1, param_slot_26 };
    static const QUParameter param_slot_27[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_27 = {"comboBoxUP_2_textChanged", 1, param_slot_27 };
    static const QUParameter param_slot_28[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_28 = {"comboBoxUP_2_activated", 1, param_slot_28 };
    static const QUParameter param_slot_29[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_29 = {"lineEditQUP1byUP2_textChanged", 1, param_slot_29 };
    static const QUParameter param_slot_30[] = {
	{ "pQComboBox", &static_QUType_ptr, "QComboBox", QUParameter::In },
	{ "value", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_30 = {"SetComboOnThisLibelle", 2, param_slot_30 };
    static const QUParameter param_slot_31[] = {
	{ "pQComboBox", &static_QUType_ptr, "QComboBox", QUParameter::In },
	{ "value", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_31 = {"SetComboOnLibelle", 2, param_slot_31 };
    static const QUParameter param_slot_32[] = {
	{ "text", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_32 = {"comboBoxPeriode_activated", 1, param_slot_32 };
    static const QUParameter param_slot_33[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_33 = {"comboBoxFactCorpUnit_activated", 1, param_slot_33 };
    static const QUParameter param_slot_34[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_34 = {"comboBoxPendant_activated", 1, param_slot_34 };
    static const QUParameter param_slot_35[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_35 = {"lineEdit_SpecPrise_textChanged", 1, param_slot_35 };
    static const QUMethod slot_36 = {"pushButtonNewUP1_Unit_clicked", 0, 0 };
    static const QUMethod slot_37 = {"UnitTablesSynchronise", 0, 0 };
    static const QUMethod slot_38 = {"pushButtonNewUP2_Unit_clicked", 0, 0 };
    static const QUMethod slot_39 = {"pushButton_AddPoso_clicked", 0, 0 };
    static const QUParameter param_slot_40[] = {
	{ "poso", &static_QUType_ptr, "CPosologie", QUParameter::InOut }
    };
    static const QUMethod slot_40 = {"AddPosoToBase", 1, param_slot_40 };
    static const QUMethod slot_41 = {"pushButton_RecordPoso_clicked", 0, 0 };
    static const QUMethod slot_42 = {"pushButton_ErasePoso_clicked", 0, 0 };
    static const QUMethod slot_43 = {"pushButtonAdvancedTerrain_clicked", 0, 0 };
    static const QUMethod slot_44 = {"pushButtonListPosoCopier_clicked", 0, 0 };
    static const QUMethod slot_45 = {"pushButtonListPosoColler_clicked", 0, 0 };
    static const QUParameter param_slot_46[] = {
	{ "list_CPosologie", &static_QUType_ptr, "QPL_CPosologie", QUParameter::InOut }
    };
    static const QUMethod slot_46 = {"AddPosoListToBase", 1, param_slot_46 };
    static const QUMethod slot_47 = {"pushButtonDefPosoCopier_clicked", 0, 0 };
    static const QUMethod slot_48 = {"pushButtonDefPosoColler_clicked", 0, 0 };
    static const QUMethod slot_49 = {"pushButton_A_clicked", 0, 0 };
    static const QUMethod slot_50 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "initDialog(QString,const QString&,const QString&,QListView*)", &slot_0, QMetaData::Public },
	{ "pushButton_QuitterClicked()", &slot_1, QMetaData::Public },
	{ "lineEdit_PoidsTest_textChanged(const QString&)", &slot_2, QMetaData::Public },
	{ "lineEdit_TailleTest_textChanged(const QString&)", &slot_3, QMetaData::Public },
	{ "lineEdit_QMin_UP1_textChanged(const QString&)", &slot_4, QMetaData::Public },
	{ "lineEdit_QMax_UP1_textChanged(const QString&)", &slot_5, QMetaData::Public },
	{ "lineEditFactCorpQU_textChanged(const QString&)", &slot_6, QMetaData::Public },
	{ "ListViewProduitCopy(QListView*)", &slot_7, QMetaData::Public },
	{ "listView_Produits_clicked(QListViewItem*)", &slot_8, QMetaData::Public },
	{ "listView_Produits_currentChanged(QListViewItem*)", &slot_9, QMetaData::Public },
	{ "listView_Produits_Changed(QListViewItem*)", &slot_10, QMetaData::Public },
	{ "listView_MedicaPoso_currentChanged(QListViewItem*)", &slot_11, QMetaData::Public },
	{ "listView_MedicaPoso_clicked(QListViewItem*)", &slot_12, QMetaData::Public },
	{ "listView_ItemToInterface(QListViewItem*)", &slot_13, QMetaData::Public },
	{ "CPosologieToInterface(CPosologie&)", &slot_14, QMetaData::Public },
	{ "InterfaceToCPosologie(CPosologie&)", &slot_15, QMetaData::Public },
	{ "DisplayResult()", &slot_16, QMetaData::Public },
	{ "ComputeNbPrises(const QString&)", &slot_17, QMetaData::Public },
	{ "ComputeSecondForm(const CPosologie&,QString&,QString&)", &slot_18, QMetaData::Public },
	{ "slider_VarPoso_valueChanged(int)", &slot_19, QMetaData::Public },
	{ "radioButtonSecable1_clicked()", &slot_20, QMetaData::Public },
	{ "radioButtonSecable2_clicked()", &slot_21, QMetaData::Public },
	{ "radioButtonSecable4_clicked()", &slot_22, QMetaData::Public },
	{ "getSecabilite()", &slot_23, QMetaData::Public },
	{ "comboBoxMoment_activated(const QString&)", &slot_24, QMetaData::Public },
	{ "comboBoxUP_1_textChanged(const QString&)", &slot_25, QMetaData::Public },
	{ "comboBoxUP_1_activated(int)", &slot_26, QMetaData::Public },
	{ "comboBoxUP_2_textChanged(const QString&)", &slot_27, QMetaData::Public },
	{ "comboBoxUP_2_activated(int)", &slot_28, QMetaData::Public },
	{ "lineEditQUP1byUP2_textChanged(const QString&)", &slot_29, QMetaData::Public },
	{ "SetComboOnThisLibelle(QComboBox*,const QString&)", &slot_30, QMetaData::Public },
	{ "SetComboOnLibelle(QComboBox*,const QString&)", &slot_31, QMetaData::Public },
	{ "comboBoxPeriode_activated(const QString&)", &slot_32, QMetaData::Public },
	{ "comboBoxFactCorpUnit_activated(int)", &slot_33, QMetaData::Public },
	{ "comboBoxPendant_activated(const QString&)", &slot_34, QMetaData::Public },
	{ "lineEdit_SpecPrise_textChanged(const QString&)", &slot_35, QMetaData::Public },
	{ "pushButtonNewUP1_Unit_clicked()", &slot_36, QMetaData::Public },
	{ "UnitTablesSynchronise()", &slot_37, QMetaData::Public },
	{ "pushButtonNewUP2_Unit_clicked()", &slot_38, QMetaData::Public },
	{ "pushButton_AddPoso_clicked()", &slot_39, QMetaData::Public },
	{ "AddPosoToBase(CPosologie&)", &slot_40, QMetaData::Public },
	{ "pushButton_RecordPoso_clicked()", &slot_41, QMetaData::Public },
	{ "pushButton_ErasePoso_clicked()", &slot_42, QMetaData::Public },
	{ "pushButtonAdvancedTerrain_clicked()", &slot_43, QMetaData::Public },
	{ "pushButtonListPosoCopier_clicked()", &slot_44, QMetaData::Public },
	{ "pushButtonListPosoColler_clicked()", &slot_45, QMetaData::Public },
	{ "AddPosoListToBase(QPL_CPosologie&)", &slot_46, QMetaData::Public },
	{ "pushButtonDefPosoCopier_clicked()", &slot_47, QMetaData::Public },
	{ "pushButtonDefPosoColler_clicked()", &slot_48, QMetaData::Public },
	{ "pushButton_A_clicked()", &slot_49, QMetaData::Public },
	{ "languageChange()", &slot_50, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"Dlg_PosoManager", parentObject,
	slot_tbl, 51,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_Dlg_PosoManager.setMetaObject( metaObj );
    return metaObj;
}

void* Dlg_PosoManager::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "Dlg_PosoManager" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool Dlg_PosoManager::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: initDialog((QString)static_QUType_QString.get(_o+1),(const QString&)static_QUType_QString.get(_o+2),(const QString&)static_QUType_QString.get(_o+3),(QListView*)static_QUType_ptr.get(_o+4)); break;
    case 1: pushButton_QuitterClicked(); break;
    case 2: lineEdit_PoidsTest_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 3: lineEdit_TailleTest_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 4: lineEdit_QMin_UP1_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 5: lineEdit_QMax_UP1_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 6: lineEditFactCorpQU_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 7: ListViewProduitCopy((QListView*)static_QUType_ptr.get(_o+1)); break;
    case 8: listView_Produits_clicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 9: listView_Produits_currentChanged((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 10: listView_Produits_Changed((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 11: listView_MedicaPoso_currentChanged((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 12: listView_MedicaPoso_clicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 13: listView_ItemToInterface((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 14: CPosologieToInterface((CPosologie&)*((CPosologie*)static_QUType_ptr.get(_o+1))); break;
    case 15: InterfaceToCPosologie((CPosologie&)*((CPosologie*)static_QUType_ptr.get(_o+1))); break;
    case 16: DisplayResult(); break;
    case 17: static_QUType_int.set(_o,ComputeNbPrises((const QString&)static_QUType_QString.get(_o+1))); break;
    case 18: ComputeSecondForm((const CPosologie&)*((const CPosologie*)static_QUType_ptr.get(_o+1)),(QString&)static_QUType_QString.get(_o+2),(QString&)static_QUType_QString.get(_o+3)); break;
    case 19: slider_VarPoso_valueChanged((int)static_QUType_int.get(_o+1)); break;
    case 20: radioButtonSecable1_clicked(); break;
    case 21: radioButtonSecable2_clicked(); break;
    case 22: radioButtonSecable4_clicked(); break;
    case 23: static_QUType_int.set(_o,getSecabilite()); break;
    case 24: comboBoxMoment_activated((const QString&)static_QUType_QString.get(_o+1)); break;
    case 25: comboBoxUP_1_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 26: comboBoxUP_1_activated((int)static_QUType_int.get(_o+1)); break;
    case 27: comboBoxUP_2_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 28: comboBoxUP_2_activated((int)static_QUType_int.get(_o+1)); break;
    case 29: lineEditQUP1byUP2_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 30: SetComboOnThisLibelle((QComboBox*)static_QUType_ptr.get(_o+1),(const QString&)static_QUType_QString.get(_o+2)); break;
    case 31: SetComboOnLibelle((QComboBox*)static_QUType_ptr.get(_o+1),(const QString&)static_QUType_QString.get(_o+2)); break;
    case 32: comboBoxPeriode_activated((const QString&)static_QUType_QString.get(_o+1)); break;
    case 33: comboBoxFactCorpUnit_activated((int)static_QUType_int.get(_o+1)); break;
    case 34: comboBoxPendant_activated((const QString&)static_QUType_QString.get(_o+1)); break;
    case 35: lineEdit_SpecPrise_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 36: pushButtonNewUP1_Unit_clicked(); break;
    case 37: UnitTablesSynchronise(); break;
    case 38: pushButtonNewUP2_Unit_clicked(); break;
    case 39: pushButton_AddPoso_clicked(); break;
    case 40: AddPosoToBase((CPosologie&)*((CPosologie*)static_QUType_ptr.get(_o+1))); break;
    case 41: pushButton_RecordPoso_clicked(); break;
    case 42: pushButton_ErasePoso_clicked(); break;
    case 43: pushButtonAdvancedTerrain_clicked(); break;
    case 44: pushButtonListPosoCopier_clicked(); break;
    case 45: pushButtonListPosoColler_clicked(); break;
    case 46: AddPosoListToBase((QPL_CPosologie&)*((QPL_CPosologie*)static_QUType_ptr.get(_o+1))); break;
    case 47: pushButtonDefPosoCopier_clicked(); break;
    case 48: pushButtonDefPosoColler_clicked(); break;
    case 49: pushButton_A_clicked(); break;
    case 50: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool Dlg_PosoManager::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool Dlg_PosoManager::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool Dlg_PosoManager::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
