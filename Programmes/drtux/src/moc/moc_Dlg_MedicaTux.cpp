/****************************************************************************
** Dlg_MedicaTux meta object code from reading C++ file 'Dlg_MedicaTux.h'
**
** Created: Wed May 4 22:20:45 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../ui/Dlg_MedicaTux.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *Dlg_MedicaTux::className() const
{
    return "Dlg_MedicaTux";
}

QMetaObject *Dlg_MedicaTux::metaObj = 0;
static QMetaObjectCleanUp cleanUp_Dlg_MedicaTux( "Dlg_MedicaTux", &Dlg_MedicaTux::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString Dlg_MedicaTux::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Dlg_MedicaTux", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString Dlg_MedicaTux::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Dlg_MedicaTux", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* Dlg_MedicaTux::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out },
	{ "pCMedBase", &static_QUType_ptr, "CMedicaBase", QUParameter::In }
    };
    static const QUMethod slot_0 = {"initDialog", 2, param_slot_0 };
    static const QUMethod slot_1 = {"initComboDuree", 0, 0 };
    static const QUMethod slot_2 = {"pushButton_CIP_Find_clicked", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod slot_3 = {"tabWidget_Tables_currentChanged", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_4 = {"listView_Produits_currentChanged", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_5 = {"listView_Produits_doubleClicked", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_6 = {"listView_Produits_clicked", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"comboBox_Specialites_activated", 1, param_slot_7 };
    static const QUMethod slot_8 = {"pushButtonDown_clicked", 0, 0 };
    static const QUMethod slot_9 = {"pushButtonDownProd_clicked", 0, 0 };
    static const QUParameter param_slot_10[] = {
	{ "text", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_10 = {"lineEdit_Produit_textChanged", 1, param_slot_10 };
    static const QUParameter param_slot_11[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_11 = {"checkBox_Generiques_stateChanged", 1, param_slot_11 };
    static const QUParameter param_slot_12[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_12 = {"checkBox_Dispo_stateChanged", 1, param_slot_12 };
    static const QUMethod slot_13 = {"InitListMedicament", 0, 0 };
    static const QUParameter param_slot_14[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_14 = {"listView_EdMed_ATC_clicked", 1, param_slot_14 };
    static const QUParameter param_slot_15[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_15 = {"listViewTherapClassVidal_clicked", 1, param_slot_15 };
    static const QUMethod slot_16 = {"pushButtonByGenerique_clicked", 0, 0 };
    static const QUMethod slot_17 = {"pushButtonByReferent_clicked", 0, 0 };
    static const QUMethod slot_18 = {"pushButtonByObsolete_clicked", 0, 0 };
    static const QUMethod slot_19 = {"pushButtonByStandard_clicked", 0, 0 };
    static const QUParameter param_slot_20[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_20 = {"comboBoxClassifications_activated", 1, param_slot_20 };
    static const QUParameter param_slot_21[] = {
	{ "txt", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_21 = {"lineEdit_Find_Indic_textChanged", 1, param_slot_21 };
    static const QUParameter param_slot_22[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_22 = {"listView_IndicList_clicked", 1, param_slot_22 };
    static const QUMethod slot_23 = {"pushButtonByPrincipe_clicked", 0, 0 };
    static const QUParameter param_slot_24[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_24 = {"listView_Produits_rightButtonClicked", 3, param_slot_24 };
    static const QUParameter param_slot_25[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_25 = {"OnMenuActivated", 1, param_slot_25 };
    static const QUMethod slot_26 = {"GetPopupItem", 0, 0 };
    static const QUParameter param_slot_27[] = {
	{ "poso", &static_QUType_ptr, "CPosologie", QUParameter::InOut }
    };
    static const QUMethod slot_27 = {"PopupQuantiteAccessoire", 1, param_slot_27 };
    static const QUParameter param_slot_28[] = {
	{ "poso", &static_QUType_ptr, "CPosologie", QUParameter::InOut },
	{ "num", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_28 = {"PopupDureeTraitement", 2, param_slot_28 };
    static const QUParameter param_slot_29[] = {
	{ "txt", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_29 = {"lineEdit_FindNomSubce_textChanged", 1, param_slot_29 };
    static const QUParameter param_slot_30[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_30 = {"listView_Substance_clicked", 1, param_slot_30 };
    static const QUParameter param_slot_31[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ "link", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_31 = {"textBrowser_Posologies_anchorClicked", 2, param_slot_31 };
    static const QUMethod slot_32 = {"pushButtonEditPoso_clicked", 0, 0 };
    static const QUParameter param_slot_33[] = {
	{ "posoList", &static_QUType_ptr, "QPL_CPosologie", QUParameter::InOut }
    };
    static const QUMethod slot_33 = {"textBrowser_PrescriptionRefresh", 1, param_slot_33 };
    static const QUMethod slot_34 = {"pushButtonPrescErase_clicked", 0, 0 };
    static const QUMethod slot_35 = {"pushButtonALD_Off_clicked", 0, 0 };
    static const QUMethod slot_36 = {"pushButtonALD_clicked", 0, 0 };
    static const QUParameter param_slot_37[] = {
	{ "item", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_37 = {"comboBoxPendant_activated", 1, param_slot_37 };
    static const QUParameter param_slot_38[] = {
	{ "text", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_38 = {"comboBoxPendant_textChanged", 1, param_slot_38 };
    static const QUParameter param_slot_39[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ "link", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_39 = {"textBrowser_Prescription_anchorClicked", 2, param_slot_39 };
    static const QUMethod slot_40 = {"GetOrdoList", 0, 0 };
    static const QUMethod slot_41 = {"pushButton_Ok_clicked", 0, 0 };
    static const QUMethod slot_42 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "initDialog(CMedicaBase*)", &slot_0, QMetaData::Public },
	{ "initComboDuree()", &slot_1, QMetaData::Public },
	{ "pushButton_CIP_Find_clicked()", &slot_2, QMetaData::Public },
	{ "tabWidget_Tables_currentChanged(QWidget*)", &slot_3, QMetaData::Public },
	{ "listView_Produits_currentChanged(QListViewItem*)", &slot_4, QMetaData::Public },
	{ "listView_Produits_doubleClicked(QListViewItem*)", &slot_5, QMetaData::Public },
	{ "listView_Produits_clicked(QListViewItem*)", &slot_6, QMetaData::Public },
	{ "comboBox_Specialites_activated(int)", &slot_7, QMetaData::Public },
	{ "pushButtonDown_clicked()", &slot_8, QMetaData::Public },
	{ "pushButtonDownProd_clicked()", &slot_9, QMetaData::Public },
	{ "lineEdit_Produit_textChanged(const QString&)", &slot_10, QMetaData::Public },
	{ "checkBox_Generiques_stateChanged(int)", &slot_11, QMetaData::Public },
	{ "checkBox_Dispo_stateChanged(int)", &slot_12, QMetaData::Public },
	{ "InitListMedicament()", &slot_13, QMetaData::Public },
	{ "listView_EdMed_ATC_clicked(QListViewItem*)", &slot_14, QMetaData::Public },
	{ "listViewTherapClassVidal_clicked(QListViewItem*)", &slot_15, QMetaData::Public },
	{ "pushButtonByGenerique_clicked()", &slot_16, QMetaData::Public },
	{ "pushButtonByReferent_clicked()", &slot_17, QMetaData::Public },
	{ "pushButtonByObsolete_clicked()", &slot_18, QMetaData::Public },
	{ "pushButtonByStandard_clicked()", &slot_19, QMetaData::Public },
	{ "comboBoxClassifications_activated(int)", &slot_20, QMetaData::Public },
	{ "lineEdit_Find_Indic_textChanged(const QString&)", &slot_21, QMetaData::Public },
	{ "listView_IndicList_clicked(QListViewItem*)", &slot_22, QMetaData::Public },
	{ "pushButtonByPrincipe_clicked()", &slot_23, QMetaData::Public },
	{ "listView_Produits_rightButtonClicked(QListViewItem*,const QPoint&,int)", &slot_24, QMetaData::Public },
	{ "OnMenuActivated(int)", &slot_25, QMetaData::Public },
	{ "GetPopupItem()", &slot_26, QMetaData::Public },
	{ "PopupQuantiteAccessoire(CPosologie&)", &slot_27, QMetaData::Public },
	{ "PopupDureeTraitement(CPosologie&,int)", &slot_28, QMetaData::Public },
	{ "lineEdit_FindNomSubce_textChanged(const QString&)", &slot_29, QMetaData::Public },
	{ "listView_Substance_clicked(QListViewItem*)", &slot_30, QMetaData::Public },
	{ "textBrowser_Posologies_anchorClicked(const QString&,const QString&)", &slot_31, QMetaData::Public },
	{ "pushButtonEditPoso_clicked()", &slot_32, QMetaData::Public },
	{ "textBrowser_PrescriptionRefresh(QPL_CPosologie&)", &slot_33, QMetaData::Public },
	{ "pushButtonPrescErase_clicked()", &slot_34, QMetaData::Public },
	{ "pushButtonALD_Off_clicked()", &slot_35, QMetaData::Public },
	{ "pushButtonALD_clicked()", &slot_36, QMetaData::Public },
	{ "comboBoxPendant_activated(int)", &slot_37, QMetaData::Public },
	{ "comboBoxPendant_textChanged(const QString&)", &slot_38, QMetaData::Public },
	{ "textBrowser_Prescription_anchorClicked(const QString&,const QString&)", &slot_39, QMetaData::Public },
	{ "GetOrdoList()", &slot_40, QMetaData::Public },
	{ "pushButton_Ok_clicked()", &slot_41, QMetaData::Public },
	{ "languageChange()", &slot_42, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"Dlg_MedicaTux", parentObject,
	slot_tbl, 43,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_Dlg_MedicaTux.setMetaObject( metaObj );
    return metaObj;
}

void* Dlg_MedicaTux::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "Dlg_MedicaTux" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool Dlg_MedicaTux::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: static_QUType_int.set(_o,initDialog((CMedicaBase*)static_QUType_ptr.get(_o+1))); break;
    case 1: initComboDuree(); break;
    case 2: pushButton_CIP_Find_clicked(); break;
    case 3: tabWidget_Tables_currentChanged((QWidget*)static_QUType_ptr.get(_o+1)); break;
    case 4: listView_Produits_currentChanged((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 5: listView_Produits_doubleClicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 6: listView_Produits_clicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 7: comboBox_Specialites_activated((int)static_QUType_int.get(_o+1)); break;
    case 8: pushButtonDown_clicked(); break;
    case 9: pushButtonDownProd_clicked(); break;
    case 10: lineEdit_Produit_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 11: checkBox_Generiques_stateChanged((int)static_QUType_int.get(_o+1)); break;
    case 12: checkBox_Dispo_stateChanged((int)static_QUType_int.get(_o+1)); break;
    case 13: InitListMedicament(); break;
    case 14: listView_EdMed_ATC_clicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 15: listViewTherapClassVidal_clicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 16: pushButtonByGenerique_clicked(); break;
    case 17: pushButtonByReferent_clicked(); break;
    case 18: pushButtonByObsolete_clicked(); break;
    case 19: pushButtonByStandard_clicked(); break;
    case 20: comboBoxClassifications_activated((int)static_QUType_int.get(_o+1)); break;
    case 21: lineEdit_Find_Indic_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 22: listView_IndicList_clicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 23: pushButtonByPrincipe_clicked(); break;
    case 24: listView_Produits_rightButtonClicked((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 25: OnMenuActivated((int)static_QUType_int.get(_o+1)); break;
    case 26: GetPopupItem(); break;
    case 27: PopupQuantiteAccessoire((CPosologie&)*((CPosologie*)static_QUType_ptr.get(_o+1))); break;
    case 28: PopupDureeTraitement((CPosologie&)*((CPosologie*)static_QUType_ptr.get(_o+1)),(int)static_QUType_int.get(_o+2)); break;
    case 29: lineEdit_FindNomSubce_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 30: listView_Substance_clicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 31: textBrowser_Posologies_anchorClicked((const QString&)static_QUType_QString.get(_o+1),(const QString&)static_QUType_QString.get(_o+2)); break;
    case 32: pushButtonEditPoso_clicked(); break;
    case 33: textBrowser_PrescriptionRefresh((QPL_CPosologie&)*((QPL_CPosologie*)static_QUType_ptr.get(_o+1))); break;
    case 34: pushButtonPrescErase_clicked(); break;
    case 35: pushButtonALD_Off_clicked(); break;
    case 36: pushButtonALD_clicked(); break;
    case 37: comboBoxPendant_activated((int)static_QUType_int.get(_o+1)); break;
    case 38: comboBoxPendant_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 39: textBrowser_Prescription_anchorClicked((const QString&)static_QUType_QString.get(_o+1),(const QString&)static_QUType_QString.get(_o+2)); break;
    case 40: GetOrdoList(); break;
    case 41: pushButton_Ok_clicked(); break;
    case 42: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool Dlg_MedicaTux::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool Dlg_MedicaTux::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool Dlg_MedicaTux::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
