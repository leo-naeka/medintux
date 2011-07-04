/****************************************************************************
** FormRubTerrain meta object code from reading C++ file 'RubTerrain.h'
**
** Created: Wed May 4 22:20:34 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../ui/RubTerrain.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *FormRubTerrain::className() const
{
    return "FormRubTerrain";
}

QMetaObject *FormRubTerrain::metaObj = 0;
static QMetaObjectCleanUp cleanUp_FormRubTerrain( "FormRubTerrain", &FormRubTerrain::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString FormRubTerrain::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "FormRubTerrain", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString FormRubTerrain::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "FormRubTerrain", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* FormRubTerrain::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"ButtonSaveDisplay", 1, param_slot_0 };
    static const QUMethod slot_1 = {"sexeAndParturienteDisplay", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ "state", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"setModifiedState", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "droits", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"SetInterfaceOnDroits", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ "state", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"Set_ATCD_Visible", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ "state", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"Set_TTT_Visible", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "state", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"Set_VAR_Visible", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ "state", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"SetModifiableState", 1, param_slot_7 };
    static const QUMethod slot_8 = {"cacher", 0, 0 };
    static const QUParameter param_slot_9[] = {
	{ "nb", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_9 = {"montrer", 1, param_slot_9 };
    static const QUParameter param_slot_10[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out }
    };
    static const QUMethod slot_10 = {"SetData", 1, param_slot_10 };
    static const QUParameter param_slot_11[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::Out }
    };
    static const QUMethod slot_11 = {"GetSurface", 1, param_slot_11 };
    static const QUParameter param_slot_12[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::Out }
    };
    static const QUMethod slot_12 = {"GetPoids", 1, param_slot_12 };
    static const QUMethod slot_13 = {"pushButtonNew_clicked", 0, 0 };
    static const QUMethod slot_14 = {"NEW_MenuActionWithCopy", 0, 0 };
    static const QUMethod slot_15 = {"NEW_MenuActionWithoutVarValue", 0, 0 };
    static const QUMethod slot_16 = {"NEW_MenuActionWithEmptyCopy", 0, 0 };
    static const QUMethod slot_17 = {"NEW_MenuActionWithBlankCopy", 0, 0 };
    static const QUParameter param_slot_18[] = {
	{ "data", &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod slot_18 = {"NEW_AddNewTerrain", 1, param_slot_18 };
    static const QUParameter param_slot_19[] = {
	{ "item", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_19 = {"comboBox_RubName_highlighted", 1, param_slot_19 };
    static const QUParameter param_slot_20[] = {
	{ "item", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_20 = {"comboBox_RubName_activated", 1, param_slot_20 };
    static const QUMethod slot_21 = {"ATCD_HaveChanged", 0, 0 };
    static const QUMethod slot_22 = {"ATCD_setInForm", 0, 0 };
    static const QUParameter param_slot_23[] = {
	{ "strDST", &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod slot_23 = {"FormToData", 1, param_slot_23 };
    static const QUMethod slot_24 = {"clearForm", 0, 0 };
    static const QUMethod slot_25 = {"DataToForm", 0, 0 };
    static const QUParameter param_slot_26[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "CMyQTable", QUParameter::In }
    };
    static const QUMethod slot_26 = {"Slot_OnValueTableChanged", 3, param_slot_26 };
    static const QUParameter param_slot_27[] = {
	{ "poids", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_27 = {"VAR_SetPoids", 1, param_slot_27 };
    static const QUParameter param_slot_28[] = {
	{ "poids", &static_QUType_QString, 0, QUParameter::In },
	{ "taille", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_28 = {"VAR_SetPoidsTaille", 2, param_slot_28 };
    static const QUParameter param_slot_29[] = {
	{ "pCMyQTable", &static_QUType_ptr, "CMyQTable", QUParameter::In },
	{ "valueList", &static_QUType_varptr, "\x04", QUParameter::InOut }
    };
    static const QUMethod slot_29 = {"VAR_addValueInTable", 2, param_slot_29 };
    static const QUMethod slot_30 = {"ClearAllTableValues", 0, 0 };
    static const QUMethod slot_31 = {"pushButtonNewVAR_clicked", 0, 0 };
    static const QUParameter param_slot_32[] = {
	{ "fileName", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_32 = {"newVAR_Add", 1, param_slot_32 };
    static const QUMethod slot_33 = {"pushButtonDellAllVAR_clicked", 0, 0 };
    static const QUMethod slot_34 = {"Slot_AllTableDelete", 0, 0 };
    static const QUParameter param_slot_35[] = {
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ "ptr", &static_QUType_ptr, "void", QUParameter::In }
    };
    static const QUMethod slot_35 = {"Slot_TableButtonClicked", 2, param_slot_35 };
    static const QUMethod slot_36 = {"VAR_MenuActionDelete", 0, 0 };
    static const QUMethod slot_37 = {"VAR_MenuActionChangeDate", 0, 0 };
    static const QUMethod slot_38 = {"VAR_MenuActionNewDate", 0, 0 };
    static const QUMethod slot_39 = {"VAR_MenuActionConfig", 0, 0 };
    static const QUMethod slot_40 = {"VAR_MenuActionDetruireVar", 0, 0 };
    static const QUParameter param_slot_41[] = {
	{ "name", &static_QUType_charstar, 0, QUParameter::In },
	{ "ptr", &static_QUType_ptr, "void", QUParameter::In }
    };
    static const QUMethod slot_41 = {"Slot_TableNewDateClicked", 2, param_slot_41 };
    static const QUParameter param_slot_42[] = {
	{ "pCMyQTable", &static_QUType_ptr, "CMyQTable", QUParameter::In },
	{ "name", &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_42 = {"OnCMyQTableClicked", 6, param_slot_42 };
    static const QUMethod slot_43 = {"pushButtonSave_clicked", 0, 0 };
    static const QUParameter param_slot_44[] = {
	{ "strDST", &static_QUType_QString, 0, QUParameter::InOut },
	{ "areValueToBeListed", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_44 = {"VAR_GetModeleList", 2, param_slot_44 };
    static const QUParameter param_slot_45[] = {
	{ "qlistViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ "pos", &static_QUType_varptr, "\x0e", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_45 = {"listView_TTT_contextMenuRequested", 3, param_slot_45 };
    static const QUMethod slot_46 = {"TTT_SlotMenuActionModifier", 0, 0 };
    static const QUMethod slot_47 = {"Alert_WriteOnly", 0, 0 };
    static const QUParameter param_slot_48[] = {
	{ "it", &static_QUType_ptr, "RUBREC_LIST::iterator", QUParameter::In }
    };
    static const QUMethod slot_48 = {"TTT_PutPrescriptionInTerrain", 1, param_slot_48 };
    static const QUParameter param_slot_49[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out }
    };
    static const QUMethod slot_49 = {"TTT_MenuActionModifier", 1, param_slot_49 };
    static const QUMethod slot_50 = {"TTT_MenuActionRenouveler", 0, 0 };
    static const QUMethod slot_51 = {"TTT_MenuActionPrescrire", 0, 0 };
    static const QUMethod slot_52 = {"TTT_MenuActionSetRenouveler", 0, 0 };
    static const QUMethod slot_53 = {"TTT_MenuActionSetIntercurent", 0, 0 };
    static const QUParameter param_slot_54[] = {
	{ "pQListView", &static_QUType_ptr, "QListView", QUParameter::In },
	{ "ordo_list", &static_QUType_ptr, "QPL_CPosologie", QUParameter::InOut }
    };
    static const QUMethod slot_54 = {"TTT_OrdoListToListView", 2, param_slot_54 };
    static const QUParameter param_slot_55[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_55 = {"listView_TTT_doubleClicked", 1, param_slot_55 };
    static const QUMethod slot_56 = {"pushButtonNewTTT_clicked", 0, 0 };
    static const QUMethod slot_57 = {"pushButtonDellAllTTT_clicked", 0, 0 };
    static const QUParameter param_slot_58[] = {
	{ "pQPopupMenu", &static_QUType_ptr, "QPopupMenu", QUParameter::In }
    };
    static const QUMethod slot_58 = {"Add_popMenu_ATCD_Type", 1, param_slot_58 };
    static const QUParameter param_slot_59[] = {
	{ "qlistViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ "pos", &static_QUType_varptr, "\x0e", QUParameter::In },
	{ "c", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_59 = {"listView_ATCD_contextMenuRequested", 3, param_slot_59 };
    static const QUMethod slot_60 = {"ATCD_setAldOn", 0, 0 };
    static const QUMethod slot_61 = {"ATCD_setAldOff", 0, 0 };
    static const QUParameter param_slot_62[] = {
	{ "state", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_62 = {"ATCD_setAldOnOff", 1, param_slot_62 };
    static const QUParameter param_slot_63[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_63 = {"listView_ATCD_doubleClicked", 1, param_slot_63 };
    static const QUMethod slot_64 = {"ATCD_MenuActionNewFromFavori", 0, 0 };
    static const QUMethod slot_65 = {"ATCD_MenuActionNewCIM10", 0, 0 };
    static const QUMethod slot_66 = {"ATCD_MenuActionSetDate", 0, 0 };
    static const QUMethod slot_67 = {"ATCD_MenuActionDelDate", 0, 0 };
    static const QUMethod slot_68 = {"ATCD_MenuActionNewAllergie", 0, 0 };
    static const QUMethod slot_69 = {"ATCD_MenuActionNewTexteLibre", 0, 0 };
    static const QUMethod slot_70 = {"ATCD_MenuActionDel", 0, 0 };
    static const QUMethod slot_71 = {"ATCD_MenuActionMultiDel", 0, 0 };
    static const QUMethod slot_72 = {"ATCD_MenuActionChangeEtatGueri", 0, 0 };
    static const QUMethod slot_73 = {"ATCD_MenuActionChangeEtatActif", 0, 0 };
    static const QUMethod slot_74 = {"ATCD_MenuActionSetFamilleGenre", 0, 0 };
    static const QUMethod slot_75 = {"ATCD_MenuActionSetCommentaire", 0, 0 };
    static const QUMethod slot_76 = {"pushButtonNewATCD_clicked", 0, 0 };
    static const QUMethod slot_77 = {"pushButtonDellAllATCD_clicked", 0, 0 };
    static const QUParameter param_slot_78[] = {
	{ "str", &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod slot_78 = {"StringToEscapeString", 1, param_slot_78 };
    static const QUParameter param_slot_79[] = {
	{ "str", &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod slot_79 = {"EscapeStringToString", 1, param_slot_79 };
    static const QUMethod slot_80 = {"checkBoxGrossesse_clicked", 0, 0 };
    static const QUMethod slot_81 = {"checkBoxAllaitement_clicked", 0, 0 };
    static const QUMethod slot_82 = {"QPushButton_DDR_clicked", 0, 0 };
    static const QUMethod slot_83 = {"pushButtonDelete_clicked", 0, 0 };
    static const QUMethod slot_84 = {"pushButtonRubDateChange_clicked", 0, 0 };
    static const QUMethod slot_85 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "ButtonSaveDisplay(const QString&)", &slot_0, QMetaData::Public },
	{ "sexeAndParturienteDisplay()", &slot_1, QMetaData::Public },
	{ "setModifiedState(int)", &slot_2, QMetaData::Public },
	{ "SetInterfaceOnDroits(const QString&)", &slot_3, QMetaData::Public },
	{ "Set_ATCD_Visible(int)", &slot_4, QMetaData::Public },
	{ "Set_TTT_Visible(int)", &slot_5, QMetaData::Public },
	{ "Set_VAR_Visible(int)", &slot_6, QMetaData::Public },
	{ "SetModifiableState(int)", &slot_7, QMetaData::Public },
	{ "cacher()", &slot_8, QMetaData::Public },
	{ "montrer(int)", &slot_9, QMetaData::Public },
	{ "SetData()", &slot_10, QMetaData::Public },
	{ "GetSurface()", &slot_11, QMetaData::Public },
	{ "GetPoids()", &slot_12, QMetaData::Public },
	{ "pushButtonNew_clicked()", &slot_13, QMetaData::Public },
	{ "NEW_MenuActionWithCopy()", &slot_14, QMetaData::Public },
	{ "NEW_MenuActionWithoutVarValue()", &slot_15, QMetaData::Public },
	{ "NEW_MenuActionWithEmptyCopy()", &slot_16, QMetaData::Public },
	{ "NEW_MenuActionWithBlankCopy()", &slot_17, QMetaData::Public },
	{ "NEW_AddNewTerrain(QString&)", &slot_18, QMetaData::Public },
	{ "comboBox_RubName_highlighted(int)", &slot_19, QMetaData::Public },
	{ "comboBox_RubName_activated(int)", &slot_20, QMetaData::Public },
	{ "ATCD_HaveChanged()", &slot_21, QMetaData::Public },
	{ "ATCD_setInForm()", &slot_22, QMetaData::Public },
	{ "FormToData(QString&)", &slot_23, QMetaData::Public },
	{ "clearForm()", &slot_24, QMetaData::Public },
	{ "DataToForm()", &slot_25, QMetaData::Public },
	{ "Slot_OnValueTableChanged(int,int,CMyQTable*)", &slot_26, QMetaData::Public },
	{ "VAR_SetPoids(QString)", &slot_27, QMetaData::Public },
	{ "VAR_SetPoidsTaille(QString,QString)", &slot_28, QMetaData::Public },
	{ "VAR_addValueInTable(CMyQTable*,QStringList&)", &slot_29, QMetaData::Public },
	{ "ClearAllTableValues()", &slot_30, QMetaData::Public },
	{ "pushButtonNewVAR_clicked()", &slot_31, QMetaData::Public },
	{ "newVAR_Add(const char*)", &slot_32, QMetaData::Public },
	{ "pushButtonDellAllVAR_clicked()", &slot_33, QMetaData::Public },
	{ "Slot_AllTableDelete()", &slot_34, QMetaData::Public },
	{ "Slot_TableButtonClicked(const char*,void*)", &slot_35, QMetaData::Public },
	{ "VAR_MenuActionDelete()", &slot_36, QMetaData::Public },
	{ "VAR_MenuActionChangeDate()", &slot_37, QMetaData::Public },
	{ "VAR_MenuActionNewDate()", &slot_38, QMetaData::Public },
	{ "VAR_MenuActionConfig()", &slot_39, QMetaData::Public },
	{ "VAR_MenuActionDetruireVar()", &slot_40, QMetaData::Public },
	{ "Slot_TableNewDateClicked(const char*,void*)", &slot_41, QMetaData::Public },
	{ "OnCMyQTableClicked(CMyQTable*,const char*,int,int,int,const QPoint&)", &slot_42, QMetaData::Public },
	{ "pushButtonSave_clicked()", &slot_43, QMetaData::Public },
	{ "VAR_GetModeleList(QString&,int)", &slot_44, QMetaData::Public },
	{ "listView_TTT_contextMenuRequested(QListViewItem*,const QPoint&,int)", &slot_45, QMetaData::Public },
	{ "TTT_SlotMenuActionModifier()", &slot_46, QMetaData::Public },
	{ "Alert_WriteOnly()", &slot_47, QMetaData::Public },
	{ "TTT_PutPrescriptionInTerrain(RUBREC_LIST::iterator)", &slot_48, QMetaData::Public },
	{ "TTT_MenuActionModifier()", &slot_49, QMetaData::Public },
	{ "TTT_MenuActionRenouveler()", &slot_50, QMetaData::Public },
	{ "TTT_MenuActionPrescrire()", &slot_51, QMetaData::Public },
	{ "TTT_MenuActionSetRenouveler()", &slot_52, QMetaData::Public },
	{ "TTT_MenuActionSetIntercurent()", &slot_53, QMetaData::Public },
	{ "TTT_OrdoListToListView(QListView*,QPL_CPosologie&)", &slot_54, QMetaData::Public },
	{ "listView_TTT_doubleClicked(QListViewItem*)", &slot_55, QMetaData::Public },
	{ "pushButtonNewTTT_clicked()", &slot_56, QMetaData::Public },
	{ "pushButtonDellAllTTT_clicked()", &slot_57, QMetaData::Public },
	{ "Add_popMenu_ATCD_Type(QPopupMenu*)", &slot_58, QMetaData::Public },
	{ "listView_ATCD_contextMenuRequested(QListViewItem*,const QPoint&,int)", &slot_59, QMetaData::Public },
	{ "ATCD_setAldOn()", &slot_60, QMetaData::Public },
	{ "ATCD_setAldOff()", &slot_61, QMetaData::Public },
	{ "ATCD_setAldOnOff(const QString&)", &slot_62, QMetaData::Public },
	{ "listView_ATCD_doubleClicked(QListViewItem*)", &slot_63, QMetaData::Public },
	{ "ATCD_MenuActionNewFromFavori()", &slot_64, QMetaData::Public },
	{ "ATCD_MenuActionNewCIM10()", &slot_65, QMetaData::Public },
	{ "ATCD_MenuActionSetDate()", &slot_66, QMetaData::Public },
	{ "ATCD_MenuActionDelDate()", &slot_67, QMetaData::Public },
	{ "ATCD_MenuActionNewAllergie()", &slot_68, QMetaData::Public },
	{ "ATCD_MenuActionNewTexteLibre()", &slot_69, QMetaData::Public },
	{ "ATCD_MenuActionDel()", &slot_70, QMetaData::Public },
	{ "ATCD_MenuActionMultiDel()", &slot_71, QMetaData::Public },
	{ "ATCD_MenuActionChangeEtatGueri()", &slot_72, QMetaData::Public },
	{ "ATCD_MenuActionChangeEtatActif()", &slot_73, QMetaData::Public },
	{ "ATCD_MenuActionSetFamilleGenre()", &slot_74, QMetaData::Public },
	{ "ATCD_MenuActionSetCommentaire()", &slot_75, QMetaData::Public },
	{ "pushButtonNewATCD_clicked()", &slot_76, QMetaData::Public },
	{ "pushButtonDellAllATCD_clicked()", &slot_77, QMetaData::Public },
	{ "StringToEscapeString(QString&)", &slot_78, QMetaData::Public },
	{ "EscapeStringToString(QString&)", &slot_79, QMetaData::Public },
	{ "checkBoxGrossesse_clicked()", &slot_80, QMetaData::Public },
	{ "checkBoxAllaitement_clicked()", &slot_81, QMetaData::Public },
	{ "QPushButton_DDR_clicked()", &slot_82, QMetaData::Public },
	{ "pushButtonDelete_clicked()", &slot_83, QMetaData::Public },
	{ "pushButtonRubDateChange_clicked()", &slot_84, QMetaData::Public },
	{ "languageChange()", &slot_85, QMetaData::Protected }
    };
    static const QUMethod signal_0 = {"Sign_SaveButtonClicked", 0, 0 };
    static const QUParameter param_signal_1[] = {
	{ "strData", &static_QUType_QString, 0, QUParameter::In },
	{ "typ", &static_QUType_int, 0, QUParameter::In },
	{ "path", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"Sign_Renouveler", 3, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "Sign_SaveButtonClicked()", &signal_0, QMetaData::Public },
	{ "Sign_Renouveler(const QString&,int,const char*)", &signal_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"FormRubTerrain", parentObject,
	slot_tbl, 86,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_FormRubTerrain.setMetaObject( metaObj );
    return metaObj;
}

void* FormRubTerrain::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "FormRubTerrain" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL Sign_SaveButtonClicked
void FormRubTerrain::Sign_SaveButtonClicked()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL Sign_Renouveler
void FormRubTerrain::Sign_Renouveler( const QString& t0, int t1, const char* t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_QString.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    static_QUType_charstar.set(o+3,t2);
    activate_signal( clist, o );
}

bool FormRubTerrain::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: ButtonSaveDisplay((const QString&)static_QUType_QString.get(_o+1)); break;
    case 1: sexeAndParturienteDisplay(); break;
    case 2: setModifiedState((int)static_QUType_int.get(_o+1)); break;
    case 3: SetInterfaceOnDroits((const QString&)static_QUType_QString.get(_o+1)); break;
    case 4: Set_ATCD_Visible((int)static_QUType_int.get(_o+1)); break;
    case 5: Set_TTT_Visible((int)static_QUType_int.get(_o+1)); break;
    case 6: Set_VAR_Visible((int)static_QUType_int.get(_o+1)); break;
    case 7: SetModifiableState((int)static_QUType_int.get(_o+1)); break;
    case 8: cacher(); break;
    case 9: montrer((int)static_QUType_int.get(_o+1)); break;
    case 10: static_QUType_int.set(_o,SetData()); break;
    case 11: static_QUType_QString.set(_o,GetSurface()); break;
    case 12: static_QUType_QString.set(_o,GetPoids()); break;
    case 13: pushButtonNew_clicked(); break;
    case 14: NEW_MenuActionWithCopy(); break;
    case 15: NEW_MenuActionWithoutVarValue(); break;
    case 16: NEW_MenuActionWithEmptyCopy(); break;
    case 17: NEW_MenuActionWithBlankCopy(); break;
    case 18: NEW_AddNewTerrain((QString&)static_QUType_QString.get(_o+1)); break;
    case 19: comboBox_RubName_highlighted((int)static_QUType_int.get(_o+1)); break;
    case 20: comboBox_RubName_activated((int)static_QUType_int.get(_o+1)); break;
    case 21: ATCD_HaveChanged(); break;
    case 22: ATCD_setInForm(); break;
    case 23: FormToData((QString&)static_QUType_QString.get(_o+1)); break;
    case 24: clearForm(); break;
    case 25: DataToForm(); break;
    case 26: Slot_OnValueTableChanged((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(CMyQTable*)static_QUType_ptr.get(_o+3)); break;
    case 27: VAR_SetPoids((QString)static_QUType_QString.get(_o+1)); break;
    case 28: VAR_SetPoidsTaille((QString)static_QUType_QString.get(_o+1),(QString)static_QUType_QString.get(_o+2)); break;
    case 29: VAR_addValueInTable((CMyQTable*)static_QUType_ptr.get(_o+1),(QStringList&)*((QStringList*)static_QUType_ptr.get(_o+2))); break;
    case 30: ClearAllTableValues(); break;
    case 31: pushButtonNewVAR_clicked(); break;
    case 32: newVAR_Add((const char*)static_QUType_charstar.get(_o+1)); break;
    case 33: pushButtonDellAllVAR_clicked(); break;
    case 34: Slot_AllTableDelete(); break;
    case 35: Slot_TableButtonClicked((const char*)static_QUType_charstar.get(_o+1),(void*)static_QUType_ptr.get(_o+2)); break;
    case 36: VAR_MenuActionDelete(); break;
    case 37: VAR_MenuActionChangeDate(); break;
    case 38: VAR_MenuActionNewDate(); break;
    case 39: VAR_MenuActionConfig(); break;
    case 40: VAR_MenuActionDetruireVar(); break;
    case 41: Slot_TableNewDateClicked((const char*)static_QUType_charstar.get(_o+1),(void*)static_QUType_ptr.get(_o+2)); break;
    case 42: OnCMyQTableClicked((CMyQTable*)static_QUType_ptr.get(_o+1),(const char*)static_QUType_charstar.get(_o+2),(int)static_QUType_int.get(_o+3),(int)static_QUType_int.get(_o+4),(int)static_QUType_int.get(_o+5),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+6))); break;
    case 43: pushButtonSave_clicked(); break;
    case 44: VAR_GetModeleList((QString&)static_QUType_QString.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 45: listView_TTT_contextMenuRequested((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 46: TTT_SlotMenuActionModifier(); break;
    case 47: Alert_WriteOnly(); break;
    case 48: TTT_PutPrescriptionInTerrain((RUBREC_LIST::iterator)(*((RUBREC_LIST::iterator*)static_QUType_ptr.get(_o+1)))); break;
    case 49: static_QUType_int.set(_o,TTT_MenuActionModifier()); break;
    case 50: TTT_MenuActionRenouveler(); break;
    case 51: TTT_MenuActionPrescrire(); break;
    case 52: TTT_MenuActionSetRenouveler(); break;
    case 53: TTT_MenuActionSetIntercurent(); break;
    case 54: TTT_OrdoListToListView((QListView*)static_QUType_ptr.get(_o+1),(QPL_CPosologie&)*((QPL_CPosologie*)static_QUType_ptr.get(_o+2))); break;
    case 55: listView_TTT_doubleClicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 56: pushButtonNewTTT_clicked(); break;
    case 57: pushButtonDellAllTTT_clicked(); break;
    case 58: Add_popMenu_ATCD_Type((QPopupMenu*)static_QUType_ptr.get(_o+1)); break;
    case 59: listView_ATCD_contextMenuRequested((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 60: ATCD_setAldOn(); break;
    case 61: ATCD_setAldOff(); break;
    case 62: ATCD_setAldOnOff((const QString&)static_QUType_QString.get(_o+1)); break;
    case 63: listView_ATCD_doubleClicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 64: ATCD_MenuActionNewFromFavori(); break;
    case 65: ATCD_MenuActionNewCIM10(); break;
    case 66: ATCD_MenuActionSetDate(); break;
    case 67: ATCD_MenuActionDelDate(); break;
    case 68: ATCD_MenuActionNewAllergie(); break;
    case 69: ATCD_MenuActionNewTexteLibre(); break;
    case 70: ATCD_MenuActionDel(); break;
    case 71: ATCD_MenuActionMultiDel(); break;
    case 72: ATCD_MenuActionChangeEtatGueri(); break;
    case 73: ATCD_MenuActionChangeEtatActif(); break;
    case 74: ATCD_MenuActionSetFamilleGenre(); break;
    case 75: ATCD_MenuActionSetCommentaire(); break;
    case 76: pushButtonNewATCD_clicked(); break;
    case 77: pushButtonDellAllATCD_clicked(); break;
    case 78: StringToEscapeString((QString&)static_QUType_QString.get(_o+1)); break;
    case 79: EscapeStringToString((QString&)static_QUType_QString.get(_o+1)); break;
    case 80: checkBoxGrossesse_clicked(); break;
    case 81: checkBoxAllaitement_clicked(); break;
    case 82: QPushButton_DDR_clicked(); break;
    case 83: pushButtonDelete_clicked(); break;
    case 84: pushButtonRubDateChange_clicked(); break;
    case 85: languageChange(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool FormRubTerrain::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: Sign_SaveButtonClicked(); break;
    case 1: Sign_Renouveler((const QString&)static_QUType_QString.get(_o+1),(int)static_QUType_int.get(_o+2),(const char*)static_QUType_charstar.get(_o+3)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool FormRubTerrain::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool FormRubTerrain::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
