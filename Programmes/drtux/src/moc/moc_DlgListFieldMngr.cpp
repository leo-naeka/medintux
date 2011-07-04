/****************************************************************************
** FormDlgListFieldMngr meta object code from reading C++ file 'DlgListFieldMngr.h'
**
** Created: Wed May 4 22:20:37 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../ui/DlgListFieldMngr.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *FormDlgListFieldMngr::className() const
{
    return "FormDlgListFieldMngr";
}

QMetaObject *FormDlgListFieldMngr::metaObj = 0;
static QMetaObjectCleanUp cleanUp_FormDlgListFieldMngr( "FormDlgListFieldMngr", &FormDlgListFieldMngr::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString FormDlgListFieldMngr::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "FormDlgListFieldMngr", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString FormDlgListFieldMngr::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "FormDlgListFieldMngr", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* FormDlgListFieldMngr::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "ret", &static_QUType_varptr, "\x03", QUParameter::In }
    };
    static const QUMethod slot_0 = {"setReturnVal", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "ret", &static_QUType_varptr, "\x03", QUParameter::In }
    };
    static const QUMethod slot_1 = {"setReturnValList", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "itemName", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"selectAndOpenItem", 1, param_slot_2 };
    static const QUMethod slot_3 = {"pushButtonImportMenuLocalize_clicked", 0, 0 };
    static const QUMethod slot_4 = {"pushButtonImportMenu_clicked", 0, 0 };
    static const QUParameter param_slot_5[] = {
	{ "drTuxParam", &static_QUType_QString, 0, QUParameter::In },
	{ "pathGlossaire", &static_QUType_QString, 0, QUParameter::In },
	{ "pathDrTux", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"initDialog", 3, param_slot_5 };
    static const QUMethod slot_6 = {"accept", 0, 0 };
    static const QUMethod slot_7 = {"reject", 0, 0 };
    static const QUParameter param_slot_8[] = {
	{ "font", &static_QUType_varptr, "\x05", QUParameter::InOut }
    };
    static const QUMethod slot_8 = {"setFontEdit", 1, param_slot_8 };
    static const QUParameter param_slot_9[] = {
	{ "e", &static_QUType_ptr, "QTextEdit", QUParameter::In }
    };
    static const QUMethod slot_9 = {"doConnections", 1, param_slot_9 };
    static const QUParameter param_slot_10[] = {
	{ "f", &static_QUType_varptr, "\x05", QUParameter::In }
    };
    static const QUMethod slot_10 = {"fontChanged", 1, param_slot_10 };
    static const QUParameter param_slot_11[] = {
	{ "c", &static_QUType_varptr, "\x0a", QUParameter::In }
    };
    static const QUMethod slot_11 = {"colorChanged", 1, param_slot_11 };
    static const QUParameter param_slot_12[] = {
	{ "a", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_12 = {"alignmentChanged", 1, param_slot_12 };
    static const QUParameter param_slot_13[] = {
	{ "state", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_13 = {"pushButtonUnderline_toggled", 1, param_slot_13 };
    static const QUParameter param_slot_14[] = {
	{ "state", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_14 = {"pushButtonItalique_toggled", 1, param_slot_14 };
    static const QUParameter param_slot_15[] = {
	{ "state", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_15 = {"pushButtonBold_toggled", 1, param_slot_15 };
    static const QUParameter param_slot_16[] = {
	{ "p", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_16 = {"textSize", 1, param_slot_16 };
    static const QUMethod slot_17 = {"pushButtonColor_clicked", 0, 0 };
    static const QUParameter param_slot_18[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_18 = {"buttonGroupJustif_pressed", 1, param_slot_18 };
    static const QUMethod slot_19 = {"pushButton_InsertImage_clicked", 0, 0 };
    static const QUParameter param_slot_20[] = {
	{ "qlistViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ "list_name", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_20 = {"AddSubFolder", 2, param_slot_20 };
    static const QUMethod slot_21 = {"MenuActionModifier", 0, 0 };
    static const QUParameter param_slot_22[] = {
	{ "qlistViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_22 = {"listViewList_doubleClicked", 1, param_slot_22 };
    static const QUMethod slot_23 = {"textEditField_textChanged", 0, 0 };
    static const QUMethod slot_24 = {"On_lineEditFindItem_F2_Pressed", 0, 0 };
    static const QUMethod slot_25 = {"On_lineEditFindItem_F6_Pressed", 0, 0 };
    static const QUParameter param_slot_26[] = {
	{ "qlistViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ "pos", &static_QUType_varptr, "\x0e", QUParameter::In },
	{ "v", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_26 = {"listViewList_contextMenuRequested", 3, param_slot_26 };
    static const QUParameter param_slot_27[] = {
	{ "qlistViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ "pos", &static_QUType_varptr, "\x0e", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_27 = {"listViewList_rightButtonClicked", 3, param_slot_27 };
    static const QUMethod slot_28 = {"MenuActionGotoListe", 0, 0 };
    static const QUMethod slot_29 = {"Slot_RestaureConnection", 0, 0 };
    static const QUMethod slot_30 = {"MenuActionListOffRef", 0, 0 };
    static const QUMethod slot_31 = {"MenuActionNewListe", 0, 0 };
    static const QUMethod slot_32 = {"MenuActionNewRef", 0, 0 };
    static const QUParameter param_slot_33[] = {
	{ "qsName", &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod slot_33 = {"ActionNewRef", 1, param_slot_33 };
    static const QUParameter param_slot_34[] = {
	{ "qsName", &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod slot_34 = {"ActionCreateNewRef", 1, param_slot_34 };
    static const QUMethod slot_35 = {"MenuActionNewSimple", 0, 0 };
    static const QUParameter param_slot_36[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out },
	{ "qsName", &static_QUType_QString, 0, QUParameter::In },
	{ "dirSrc", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_36 = {"MenuActionCreateNewSimple", 3, param_slot_36 };
    static const QUMethod slot_37 = {"MenuActionDelete", 0, 0 };
    static const QUMethod slot_38 = {"MenuActionRename", 0, 0 };
    static const QUMethod slot_39 = {"MenuActionIsExist", 0, 0 };
    static const QUParameter param_slot_40[] = {
	{ "button", &static_QUType_int, 0, QUParameter::In },
	{ "qlistViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ "pos", &static_QUType_varptr, "\x0e", QUParameter::In },
	{ "c", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_40 = {"listViewList_clicked", 4, param_slot_40 };
    static const QUParameter param_slot_41[] = {
	{ "qlistViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_41 = {"listViewList_returnPressed", 1, param_slot_41 };
    static const QUMethod slot_42 = {"pushButtonSave_clicked", 0, 0 };
    static const QUParameter param_slot_43[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::Out }
    };
    static const QUMethod slot_43 = {"saveTextIfModified", 1, param_slot_43 };
    static const QUParameter param_slot_44[] = {
	{ "path", &static_QUType_QString, 0, QUParameter::In },
	{ "text", &static_QUType_QString, 0, QUParameter::In },
	{ "qlistViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_44 = {"saveFile", 3, param_slot_44 };
    static const QUParameter param_slot_45[] = {
	{ "qtxt", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_45 = {"lineEditFindItem_textChanged", 1, param_slot_45 };
    static const QUMethod slot_46 = {"pushButtonSetMasque_clicked", 0, 0 };
    static const QUMethod slot_47 = {"MenuActionListGet", 0, 0 };
    static const QUMethod slot_48 = {"MenuActionInsertField", 0, 0 };
    static const QUParameter param_slot_49[] = {
	{ "path", &static_QUType_charstar, 0, QUParameter::In },
	{ "fieldList", &static_QUType_varptr, "\x04", QUParameter::InOut },
	{ "mustBeClear", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_49 = {"MakeInsertFieldList", 3, param_slot_49 };
    static const QUMethod slot_50 = {"MenuActionListNewRef", 0, 0 };
    static const QUParameter param_slot_51[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_51 = {"listViewList_spacePressed", 1, param_slot_51 };
    static const QUMethod slot_52 = {"pushButtonSetTextField_clicked", 0, 0 };
    static const QUMethod slot_53 = {"lineEditFindItem_returnPressed", 0, 0 };
    static const QUMethod slot_54 = {"pushButton_Quitter_clicked", 0, 0 };
    static const QUMethod slot_55 = {"pushButton_Ok_clicked", 0, 0 };
    static const QUMethod slot_56 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "setReturnVal(QString*)", &slot_0, QMetaData::Public },
	{ "setReturnValList(QString*)", &slot_1, QMetaData::Public },
	{ "selectAndOpenItem(QString)", &slot_2, QMetaData::Public },
	{ "pushButtonImportMenuLocalize_clicked()", &slot_3, QMetaData::Public },
	{ "pushButtonImportMenu_clicked()", &slot_4, QMetaData::Public },
	{ "initDialog(const QString&,const QString&,const QString&)", &slot_5, QMetaData::Public },
	{ "accept()", &slot_6, QMetaData::Public },
	{ "reject()", &slot_7, QMetaData::Public },
	{ "setFontEdit(QFont&)", &slot_8, QMetaData::Public },
	{ "doConnections(QTextEdit*)", &slot_9, QMetaData::Public },
	{ "fontChanged(const QFont&)", &slot_10, QMetaData::Public },
	{ "colorChanged(const QColor&)", &slot_11, QMetaData::Public },
	{ "alignmentChanged(int)", &slot_12, QMetaData::Public },
	{ "pushButtonUnderline_toggled(bool)", &slot_13, QMetaData::Public },
	{ "pushButtonItalique_toggled(bool)", &slot_14, QMetaData::Public },
	{ "pushButtonBold_toggled(bool)", &slot_15, QMetaData::Public },
	{ "textSize(const QString&)", &slot_16, QMetaData::Public },
	{ "pushButtonColor_clicked()", &slot_17, QMetaData::Public },
	{ "buttonGroupJustif_pressed(int)", &slot_18, QMetaData::Public },
	{ "pushButton_InsertImage_clicked()", &slot_19, QMetaData::Public },
	{ "AddSubFolder(QListViewItem*,QString)", &slot_20, QMetaData::Public },
	{ "MenuActionModifier()", &slot_21, QMetaData::Public },
	{ "listViewList_doubleClicked(QListViewItem*)", &slot_22, QMetaData::Public },
	{ "textEditField_textChanged()", &slot_23, QMetaData::Public },
	{ "On_lineEditFindItem_F2_Pressed()", &slot_24, QMetaData::Public },
	{ "On_lineEditFindItem_F6_Pressed()", &slot_25, QMetaData::Public },
	{ "listViewList_contextMenuRequested(QListViewItem*,const QPoint&,int)", &slot_26, QMetaData::Public },
	{ "listViewList_rightButtonClicked(QListViewItem*,const QPoint&,int)", &slot_27, QMetaData::Public },
	{ "MenuActionGotoListe()", &slot_28, QMetaData::Public },
	{ "Slot_RestaureConnection()", &slot_29, QMetaData::Public },
	{ "MenuActionListOffRef()", &slot_30, QMetaData::Public },
	{ "MenuActionNewListe()", &slot_31, QMetaData::Public },
	{ "MenuActionNewRef()", &slot_32, QMetaData::Public },
	{ "ActionNewRef(QString&)", &slot_33, QMetaData::Public },
	{ "ActionCreateNewRef(QString&)", &slot_34, QMetaData::Public },
	{ "MenuActionNewSimple()", &slot_35, QMetaData::Public },
	{ "MenuActionCreateNewSimple(QString,const QString&)", &slot_36, QMetaData::Public },
	{ "MenuActionDelete()", &slot_37, QMetaData::Public },
	{ "MenuActionRename()", &slot_38, QMetaData::Public },
	{ "MenuActionIsExist()", &slot_39, QMetaData::Public },
	{ "listViewList_clicked(int,QListViewItem*,const QPoint&,int)", &slot_40, QMetaData::Public },
	{ "listViewList_returnPressed(QListViewItem*)", &slot_41, QMetaData::Public },
	{ "pushButtonSave_clicked()", &slot_42, QMetaData::Public },
	{ "saveTextIfModified()", &slot_43, QMetaData::Public },
	{ "saveFile(QString,QString,QListViewItem*)", &slot_44, QMetaData::Public },
	{ "lineEditFindItem_textChanged(const QString&)", &slot_45, QMetaData::Public },
	{ "pushButtonSetMasque_clicked()", &slot_46, QMetaData::Public },
	{ "MenuActionListGet()", &slot_47, QMetaData::Public },
	{ "MenuActionInsertField()", &slot_48, QMetaData::Public },
	{ "MakeInsertFieldList(const char*,QStringList&,int)", &slot_49, QMetaData::Public },
	{ "MenuActionListNewRef()", &slot_50, QMetaData::Public },
	{ "listViewList_spacePressed(QListViewItem*)", &slot_51, QMetaData::Public },
	{ "pushButtonSetTextField_clicked()", &slot_52, QMetaData::Public },
	{ "lineEditFindItem_returnPressed()", &slot_53, QMetaData::Public },
	{ "pushButton_Quitter_clicked()", &slot_54, QMetaData::Public },
	{ "pushButton_Ok_clicked()", &slot_55, QMetaData::Public },
	{ "languageChange()", &slot_56, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"FormDlgListFieldMngr", parentObject,
	slot_tbl, 57,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_FormDlgListFieldMngr.setMetaObject( metaObj );
    return metaObj;
}

void* FormDlgListFieldMngr::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "FormDlgListFieldMngr" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool FormDlgListFieldMngr::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setReturnVal((QString*)static_QUType_varptr.get(_o+1)); break;
    case 1: setReturnValList((QString*)static_QUType_varptr.get(_o+1)); break;
    case 2: selectAndOpenItem((QString)static_QUType_QString.get(_o+1)); break;
    case 3: pushButtonImportMenuLocalize_clicked(); break;
    case 4: pushButtonImportMenu_clicked(); break;
    case 5: initDialog((const QString&)static_QUType_QString.get(_o+1),(const QString&)static_QUType_QString.get(_o+2),(const QString&)static_QUType_QString.get(_o+3)); break;
    case 6: accept(); break;
    case 7: reject(); break;
    case 8: setFontEdit((QFont&)*((QFont*)static_QUType_ptr.get(_o+1))); break;
    case 9: doConnections((QTextEdit*)static_QUType_ptr.get(_o+1)); break;
    case 10: fontChanged((const QFont&)*((const QFont*)static_QUType_ptr.get(_o+1))); break;
    case 11: colorChanged((const QColor&)*((const QColor*)static_QUType_ptr.get(_o+1))); break;
    case 12: alignmentChanged((int)static_QUType_int.get(_o+1)); break;
    case 13: pushButtonUnderline_toggled((bool)static_QUType_bool.get(_o+1)); break;
    case 14: pushButtonItalique_toggled((bool)static_QUType_bool.get(_o+1)); break;
    case 15: pushButtonBold_toggled((bool)static_QUType_bool.get(_o+1)); break;
    case 16: textSize((const QString&)static_QUType_QString.get(_o+1)); break;
    case 17: pushButtonColor_clicked(); break;
    case 18: buttonGroupJustif_pressed((int)static_QUType_int.get(_o+1)); break;
    case 19: pushButton_InsertImage_clicked(); break;
    case 20: AddSubFolder((QListViewItem*)static_QUType_ptr.get(_o+1),(QString)static_QUType_QString.get(_o+2)); break;
    case 21: MenuActionModifier(); break;
    case 22: listViewList_doubleClicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 23: textEditField_textChanged(); break;
    case 24: On_lineEditFindItem_F2_Pressed(); break;
    case 25: On_lineEditFindItem_F6_Pressed(); break;
    case 26: listViewList_contextMenuRequested((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 27: listViewList_rightButtonClicked((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 28: MenuActionGotoListe(); break;
    case 29: Slot_RestaureConnection(); break;
    case 30: MenuActionListOffRef(); break;
    case 31: MenuActionNewListe(); break;
    case 32: MenuActionNewRef(); break;
    case 33: ActionNewRef((QString&)static_QUType_QString.get(_o+1)); break;
    case 34: ActionCreateNewRef((QString&)static_QUType_QString.get(_o+1)); break;
    case 35: MenuActionNewSimple(); break;
    case 36: static_QUType_int.set(_o,MenuActionCreateNewSimple((QString)static_QUType_QString.get(_o+1),(const QString&)static_QUType_QString.get(_o+2))); break;
    case 37: MenuActionDelete(); break;
    case 38: MenuActionRename(); break;
    case 39: MenuActionIsExist(); break;
    case 40: listViewList_clicked((int)static_QUType_int.get(_o+1),(QListViewItem*)static_QUType_ptr.get(_o+2),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+3)),(int)static_QUType_int.get(_o+4)); break;
    case 41: listViewList_returnPressed((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 42: pushButtonSave_clicked(); break;
    case 43: static_QUType_bool.set(_o,saveTextIfModified()); break;
    case 44: saveFile((QString)static_QUType_QString.get(_o+1),(QString)static_QUType_QString.get(_o+2),(QListViewItem*)static_QUType_ptr.get(_o+3)); break;
    case 45: lineEditFindItem_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 46: pushButtonSetMasque_clicked(); break;
    case 47: MenuActionListGet(); break;
    case 48: MenuActionInsertField(); break;
    case 49: MakeInsertFieldList((const char*)static_QUType_charstar.get(_o+1),(QStringList&)*((QStringList*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 50: MenuActionListNewRef(); break;
    case 51: listViewList_spacePressed((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 52: pushButtonSetTextField_clicked(); break;
    case 53: lineEditFindItem_returnPressed(); break;
    case 54: pushButton_Quitter_clicked(); break;
    case 55: pushButton_Ok_clicked(); break;
    case 56: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool FormDlgListFieldMngr::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool FormDlgListFieldMngr::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool FormDlgListFieldMngr::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
