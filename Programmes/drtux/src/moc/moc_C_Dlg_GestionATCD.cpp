/****************************************************************************
** C_Dlg_GestionATCD meta object code from reading C++ file 'C_Dlg_GestionATCD.h'
**
** Created: Wed May 4 22:20:30 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../C_Dlg_GestionATCD.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *C_Dlg_GestionATCD::className() const
{
    return "C_Dlg_GestionATCD";
}

QMetaObject *C_Dlg_GestionATCD::metaObj = 0;
static QMetaObjectCleanUp cleanUp_C_Dlg_GestionATCD( "C_Dlg_GestionATCD", &C_Dlg_GestionATCD::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString C_Dlg_GestionATCD::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_Dlg_GestionATCD", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString C_Dlg_GestionATCD::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_Dlg_GestionATCD", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* C_Dlg_GestionATCD::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = Dlg_GestionATCD::staticMetaObject();
    static const QUMethod slot_0 = {"close", 0, 0 };
    static const QUMethod slot_1 = {"Slot_lineEditThesaurusFind1_F2_Pressed", 0, 0 };
    static const QUMethod slot_2 = {"Slot_lineEditThesaurusFind1_F6_Pressed", 0, 0 };
    static const QUMethod slot_3 = {"Slot_ThesaurusImport", 0, 0 };
    static const QUMethod slot_4 = {"Slot_ThesaurusExport", 0, 0 };
    static const QUMethod slot_5 = {"Slot_pushButtonFamilleGenreEdit", 0, 0 };
    static const QUMethod slot_6 = {"Slot_pushButtonThesaurusAdd_clicked", 0, 0 };
    static const QUMethod slot_7 = {"Slot_pushButtonThesaurusFreeAdd_clicked", 0, 0 };
    static const QUMethod slot_8 = {"Slot_pushButtonAddFreeToChoix_clicked", 0, 0 };
    static const QUMethod slot_9 = {"Slot_pushButton_AddToChoixFast_clicked", 0, 0 };
    static const QUMethod slot_10 = {"Slot_pushButtonAddMedicament_clicked", 0, 0 };
    static const QUMethod slot_11 = {"Slot_pushButtonThesaurus_Edit_clicked", 0, 0 };
    static const QUParameter param_slot_12[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_12 = {"Slot_listViewAllergies_clicked", 1, param_slot_12 };
    static const QUParameter param_slot_13[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_13 = {"Slot_listView_Produits_contextMenuRequested", 3, param_slot_13 };
    static const QUParameter param_slot_14[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ "pt", &static_QUType_varptr, "\x0e", QUParameter::In },
	{ "c", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_14 = {"Slot_listViewAllergies_contextMenuRequested", 3, param_slot_14 };
    static const QUParameter param_slot_15[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_15 = {"Slot_lineEditAutolcatorLibelle_textChanged", 1, param_slot_15 };
    static const QUParameter param_slot_16[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_16 = {"Slot_lineEditAutolcatorLibelle_2_textChanged", 1, param_slot_16 };
    static const QUParameter param_slot_17[] = {
	{ "qlistViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_17 = {"Slot_listViewCim10_rubriques_clicked", 1, param_slot_17 };
    static const QUParameter param_slot_18[] = {
	{ "pQWidget", &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod slot_18 = {"Slot_tabWidgetDicoATCD_currentChanged", 1, param_slot_18 };
    static const QUParameter param_slot_19[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ "pt", &static_QUType_varptr, "\x0e", QUParameter::In },
	{ "c", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_19 = {"Slot_listViewCim10_Libelles_contextMenuRequested", 3, param_slot_19 };
    static const QUParameter param_slot_20[] = {
	{ "qlistViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_20 = {"Slot_listViewCim10_Libelles_doubleClicked", 1, param_slot_20 };
    static const QUParameter param_slot_21[] = {
	{ "qlistViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_21 = {"Slot_listViewCim10_rubriques_doubleClicked", 1, param_slot_21 };
    static const QUParameter param_slot_22[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ "pt", &static_QUType_varptr, "\x0e", QUParameter::In },
	{ "c", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_22 = {"Slot_listViewCim10_rubriques_contextMenuRequested", 3, param_slot_22 };
    static const QUMethod slot_23 = {"Slot_pushButton_AddToChoix_clicked", 0, 0 };
    static const QUMethod slot_24 = {"Slot_pushButtonRemoveFromChoix_clicked", 0, 0 };
    static const QUParameter param_slot_25[] = {
	{ "section", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_25 = {"Slot_comboBox_Family_highlighted", 1, param_slot_25 };
    static const QUParameter param_slot_26[] = {
	{ "text", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_26 = {"Slot_combo_Family_activated", 1, param_slot_26 };
    static const QUParameter param_slot_27[] = {
	{ "qlistViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_27 = {"Slot_listViewThesaurus_doubleClicked", 1, param_slot_27 };
    static const QUParameter param_slot_28[] = {
	{ "qlistViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ "pos", &static_QUType_varptr, "\x0e", QUParameter::In },
	{ "c", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_28 = {"Slot_listViewThesaurus_contextMenuRequested", 3, param_slot_28 };
    static const QUParameter param_slot_29[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_29 = {"Slot_listViewThesaurus_returnPressed", 1, param_slot_29 };
    static const QUParameter param_slot_30[] = {
	{ "str", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_30 = {"Slot_lineEditThesaurusFind1_textChanged", 1, param_slot_30 };
    static const QUMethod slot_31 = {"Slot_lineEditThesaurusFind1_returnPressed", 0, 0 };
    static const QUMethod slot_32 = {"Slot_menuActionSetFamilleGenre", 0, 0 };
    static const QUMethod slot_33 = {"Slot_SaveThesaurus", 0, 0 };
    static const QUParameter param_slot_34[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ "col", &static_QUType_int, 0, QUParameter::In },
	{ "text", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_34 = {"Slot_listViewThesaurus_itemRenamed", 3, param_slot_34 };
    static const QUMethod slot_35 = {"Slot_ThesaurusDel", 0, 0 };
    static const QUParameter param_slot_36[] = {
	{ "qtext", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_36 = {"Slot_lineEditNomAllergie_textChanged", 1, param_slot_36 };
    static const QUParameter param_slot_37[] = {
	{ "qtext", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_37 = {"Slot_lineEditNomMedicament_textChanged", 1, param_slot_37 };
    static const QUParameter param_slot_38[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_38 = {"Slot_listView_Produits_clicked", 1, param_slot_38 };
    static const QUParameter param_slot_39[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_39 = {"Slot_listView_Produits_doubleClicked", 1, param_slot_39 };
    static const QUParameter param_slot_40[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_40 = {"Slot_listViewAllergies_doubleClicked", 1, param_slot_40 };
    static const QUParameter param_slot_41[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_41 = {"Slot_listViewCim10_Choix_doubleClicked", 1, param_slot_41 };
    static const QUParameter param_slot_42[] = {
	{ "genre", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_42 = {"Slot_comboBox_Genre_highlighted", 1, param_slot_42 };
    static const QUParameter param_slot_43[] = {
	{ "section", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_43 = {"Slot_combo_Genre_activated", 1, param_slot_43 };
    static const QUMethod slot_44 = {"Slot_reject", 0, 0 };
    static const QUMethod slot_45 = {"Slot_accept", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "close()", &slot_0, QMetaData::Protected },
	{ "Slot_lineEditThesaurusFind1_F2_Pressed()", &slot_1, QMetaData::Protected },
	{ "Slot_lineEditThesaurusFind1_F6_Pressed()", &slot_2, QMetaData::Protected },
	{ "Slot_ThesaurusImport()", &slot_3, QMetaData::Protected },
	{ "Slot_ThesaurusExport()", &slot_4, QMetaData::Protected },
	{ "Slot_pushButtonFamilleGenreEdit()", &slot_5, QMetaData::Protected },
	{ "Slot_pushButtonThesaurusAdd_clicked()", &slot_6, QMetaData::Protected },
	{ "Slot_pushButtonThesaurusFreeAdd_clicked()", &slot_7, QMetaData::Protected },
	{ "Slot_pushButtonAddFreeToChoix_clicked()", &slot_8, QMetaData::Protected },
	{ "Slot_pushButton_AddToChoixFast_clicked()", &slot_9, QMetaData::Protected },
	{ "Slot_pushButtonAddMedicament_clicked()", &slot_10, QMetaData::Protected },
	{ "Slot_pushButtonThesaurus_Edit_clicked()", &slot_11, QMetaData::Protected },
	{ "Slot_listViewAllergies_clicked(QListViewItem*)", &slot_12, QMetaData::Protected },
	{ "Slot_listView_Produits_contextMenuRequested(QListViewItem*,const QPoint&,int)", &slot_13, QMetaData::Protected },
	{ "Slot_listViewAllergies_contextMenuRequested(QListViewItem*,const QPoint&,int)", &slot_14, QMetaData::Protected },
	{ "Slot_lineEditAutolcatorLibelle_textChanged(const QString&)", &slot_15, QMetaData::Protected },
	{ "Slot_lineEditAutolcatorLibelle_2_textChanged(const QString&)", &slot_16, QMetaData::Protected },
	{ "Slot_listViewCim10_rubriques_clicked(QListViewItem*)", &slot_17, QMetaData::Protected },
	{ "Slot_tabWidgetDicoATCD_currentChanged(QWidget*)", &slot_18, QMetaData::Protected },
	{ "Slot_listViewCim10_Libelles_contextMenuRequested(QListViewItem*,const QPoint&,int)", &slot_19, QMetaData::Protected },
	{ "Slot_listViewCim10_Libelles_doubleClicked(QListViewItem*)", &slot_20, QMetaData::Protected },
	{ "Slot_listViewCim10_rubriques_doubleClicked(QListViewItem*)", &slot_21, QMetaData::Protected },
	{ "Slot_listViewCim10_rubriques_contextMenuRequested(QListViewItem*,const QPoint&,int)", &slot_22, QMetaData::Protected },
	{ "Slot_pushButton_AddToChoix_clicked()", &slot_23, QMetaData::Protected },
	{ "Slot_pushButtonRemoveFromChoix_clicked()", &slot_24, QMetaData::Protected },
	{ "Slot_comboBox_Family_highlighted(const QString&)", &slot_25, QMetaData::Protected },
	{ "Slot_combo_Family_activated(const QString&)", &slot_26, QMetaData::Protected },
	{ "Slot_listViewThesaurus_doubleClicked(QListViewItem*)", &slot_27, QMetaData::Protected },
	{ "Slot_listViewThesaurus_contextMenuRequested(QListViewItem*,const QPoint&,int)", &slot_28, QMetaData::Protected },
	{ "Slot_listViewThesaurus_returnPressed(QListViewItem*)", &slot_29, QMetaData::Protected },
	{ "Slot_lineEditThesaurusFind1_textChanged(const QString&)", &slot_30, QMetaData::Protected },
	{ "Slot_lineEditThesaurusFind1_returnPressed()", &slot_31, QMetaData::Protected },
	{ "Slot_menuActionSetFamilleGenre()", &slot_32, QMetaData::Protected },
	{ "Slot_SaveThesaurus()", &slot_33, QMetaData::Protected },
	{ "Slot_listViewThesaurus_itemRenamed(QListViewItem*,int,const QString&)", &slot_34, QMetaData::Protected },
	{ "Slot_ThesaurusDel()", &slot_35, QMetaData::Protected },
	{ "Slot_lineEditNomAllergie_textChanged(const QString&)", &slot_36, QMetaData::Protected },
	{ "Slot_lineEditNomMedicament_textChanged(const QString&)", &slot_37, QMetaData::Protected },
	{ "Slot_listView_Produits_clicked(QListViewItem*)", &slot_38, QMetaData::Protected },
	{ "Slot_listView_Produits_doubleClicked(QListViewItem*)", &slot_39, QMetaData::Protected },
	{ "Slot_listViewAllergies_doubleClicked(QListViewItem*)", &slot_40, QMetaData::Protected },
	{ "Slot_listViewCim10_Choix_doubleClicked(QListViewItem*)", &slot_41, QMetaData::Protected },
	{ "Slot_comboBox_Genre_highlighted(const QString&)", &slot_42, QMetaData::Protected },
	{ "Slot_combo_Genre_activated(const QString&)", &slot_43, QMetaData::Protected },
	{ "Slot_reject()", &slot_44, QMetaData::Protected },
	{ "Slot_accept()", &slot_45, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"C_Dlg_GestionATCD", parentObject,
	slot_tbl, 46,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_C_Dlg_GestionATCD.setMetaObject( metaObj );
    return metaObj;
}

void* C_Dlg_GestionATCD::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "C_Dlg_GestionATCD" ) )
	return this;
    return Dlg_GestionATCD::qt_cast( clname );
}

bool C_Dlg_GestionATCD::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: close(); break;
    case 1: Slot_lineEditThesaurusFind1_F2_Pressed(); break;
    case 2: Slot_lineEditThesaurusFind1_F6_Pressed(); break;
    case 3: Slot_ThesaurusImport(); break;
    case 4: Slot_ThesaurusExport(); break;
    case 5: Slot_pushButtonFamilleGenreEdit(); break;
    case 6: Slot_pushButtonThesaurusAdd_clicked(); break;
    case 7: Slot_pushButtonThesaurusFreeAdd_clicked(); break;
    case 8: Slot_pushButtonAddFreeToChoix_clicked(); break;
    case 9: Slot_pushButton_AddToChoixFast_clicked(); break;
    case 10: Slot_pushButtonAddMedicament_clicked(); break;
    case 11: Slot_pushButtonThesaurus_Edit_clicked(); break;
    case 12: Slot_listViewAllergies_clicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 13: Slot_listView_Produits_contextMenuRequested((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 14: Slot_listViewAllergies_contextMenuRequested((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 15: Slot_lineEditAutolcatorLibelle_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 16: Slot_lineEditAutolcatorLibelle_2_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 17: Slot_listViewCim10_rubriques_clicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 18: Slot_tabWidgetDicoATCD_currentChanged((QWidget*)static_QUType_ptr.get(_o+1)); break;
    case 19: Slot_listViewCim10_Libelles_contextMenuRequested((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 20: Slot_listViewCim10_Libelles_doubleClicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 21: Slot_listViewCim10_rubriques_doubleClicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 22: Slot_listViewCim10_rubriques_contextMenuRequested((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 23: Slot_pushButton_AddToChoix_clicked(); break;
    case 24: Slot_pushButtonRemoveFromChoix_clicked(); break;
    case 25: Slot_comboBox_Family_highlighted((const QString&)static_QUType_QString.get(_o+1)); break;
    case 26: Slot_combo_Family_activated((const QString&)static_QUType_QString.get(_o+1)); break;
    case 27: Slot_listViewThesaurus_doubleClicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 28: Slot_listViewThesaurus_contextMenuRequested((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 29: Slot_listViewThesaurus_returnPressed((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 30: Slot_lineEditThesaurusFind1_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 31: Slot_lineEditThesaurusFind1_returnPressed(); break;
    case 32: Slot_menuActionSetFamilleGenre(); break;
    case 33: Slot_SaveThesaurus(); break;
    case 34: Slot_listViewThesaurus_itemRenamed((QListViewItem*)static_QUType_ptr.get(_o+1),(int)static_QUType_int.get(_o+2),(const QString&)static_QUType_QString.get(_o+3)); break;
    case 35: Slot_ThesaurusDel(); break;
    case 36: Slot_lineEditNomAllergie_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 37: Slot_lineEditNomMedicament_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 38: Slot_listView_Produits_clicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 39: Slot_listView_Produits_doubleClicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 40: Slot_listViewAllergies_doubleClicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 41: Slot_listViewCim10_Choix_doubleClicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 42: Slot_comboBox_Genre_highlighted((const QString&)static_QUType_QString.get(_o+1)); break;
    case 43: Slot_combo_Genre_activated((const QString&)static_QUType_QString.get(_o+1)); break;
    case 44: Slot_reject(); break;
    case 45: Slot_accept(); break;
    default:
	return Dlg_GestionATCD::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool C_Dlg_GestionATCD::qt_emit( int _id, QUObject* _o )
{
    return Dlg_GestionATCD::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool C_Dlg_GestionATCD::qt_property( int id, int f, QVariant* v)
{
    return Dlg_GestionATCD::qt_property( id, f, v);
}

bool C_Dlg_GestionATCD::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
