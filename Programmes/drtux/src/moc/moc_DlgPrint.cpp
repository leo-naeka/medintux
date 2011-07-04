/****************************************************************************
** DlgPrint meta object code from reading C++ file 'DlgPrint.h'
**
** Created: Wed May 4 22:20:42 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../ui/DlgPrint.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *DlgPrint::className() const
{
    return "DlgPrint";
}

QMetaObject *DlgPrint::metaObj = 0;
static QMetaObjectCleanUp cleanUp_DlgPrint( "DlgPrint", &DlgPrint::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString DlgPrint::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "DlgPrint", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString DlgPrint::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "DlgPrint", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* DlgPrint::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "value", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"slider_Marg_Top_sliderMoved", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "value", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"slider_Head_H_sliderMoved", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "value", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"slider_Marg_Left_sliderMoved", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "value", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"slider_Marg_Right_sliderMoved", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ "value", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"slider_Marg_Bottom_sliderMoved", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ "value", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"slider_Foot_H_sliderMoved", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "nb_page", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"UpdateTextePageInfo", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out },
	{ "pBodyTextEdit", &static_QUType_ptr, "QTextEdit", QUParameter::In },
	{ "IdentPrimKey", &static_QUType_QString, 0, QUParameter::InOut },
	{ "pCMoteurBase", &static_QUType_ptr, "CMoteurBase", QUParameter::In },
	{ "pRubList", &static_QUType_ptr, "RUBREC_LIST", QUParameter::In },
	{ "id_Obs", &static_QUType_int, 0, QUParameter::In },
	{ "id_Prs", &static_QUType_int, 0, QUParameter::In },
	{ "observText", &static_QUType_charstar, 0, QUParameter::In },
	{ "userActuelPk", &static_QUType_charstar, 0, QUParameter::In },
	{ "rubName", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"initDialog", 10, param_slot_7 };
    static const QUMethod slot_8 = {"executeTransfertMacro", 0, 0 };
    static const QUMethod slot_9 = {"SetCaption", 0, 0 };
    static const QUMethod slot_10 = {"pushButtonSave_clicked", 0, 0 };
    static const QUMethod slot_11 = {"SetDialogOnPrinterSpec", 0, 0 };
    static const QUParameter param_slot_12[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_12 = {"comboBox_TypeDoc_activated", 1, param_slot_12 };
    static const QUParameter param_slot_13[] = {
	{ "item", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_13 = {"comboBox_TypeDoc_activated", 1, param_slot_13 };
    static const QUParameter param_slot_14[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_14 = {"SetDialogOnHeadAndFoot", 1, param_slot_14 };
    static const QUParameter param_slot_15[] = {
	{ "txt", &static_QUType_QString, 0, QUParameter::In },
	{ "font", &static_QUType_varptr, "\x05", QUParameter::InOut }
    };
    static const QUMethod slot_15 = {"GetPossibleDefaultFont", 2, param_slot_15 };
    static const QUParameter param_slot_16[] = {
	{ "pDocument", &static_QUType_varptr, "\x03", QUParameter::In },
	{ "userActuelPk", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_16 = {"FusionneDocument", 2, param_slot_16 };
    static const QUMethod slot_17 = {"AdjustHeightFootAndHead", 0, 0 };
    static const QUParameter param_slot_18[] = {
	{ "pRichText", &static_QUType_ptr, "QSimpleRichText", QUParameter::In }
    };
    static const QUMethod slot_18 = {"initRichBodyText", 1, param_slot_18 };
    static const QUParameter param_slot_19[] = {
	{ "pRichText", &static_QUType_ptr, "QSimpleRichText", QUParameter::In }
    };
    static const QUMethod slot_19 = {"initRichHeadText", 1, param_slot_19 };
    static const QUParameter param_slot_20[] = {
	{ "pRichText", &static_QUType_ptr, "QSimpleRichText", QUParameter::In }
    };
    static const QUMethod slot_20 = {"initRichFootText", 1, param_slot_20 };
    static const QUMethod slot_21 = {"pushButtonOk_clicked", 0, 0 };
    static const QUMethod slot_22 = {"pushButtonPrint_2_clicked", 0, 0 };
    static const QUMethod slot_23 = {"pushButtonPrint_2_2_clicked", 0, 0 };
    static const QUMethod slot_24 = {"pushButtonPrint_clicked", 0, 0 };
    static const QUParameter param_slot_25[] = {
	{ "nbCopies", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_25 = {"printDoc", 1, param_slot_25 };
    static const QUParameter param_slot_26[] = {
	{ "prim_key", &static_QUType_QString, 0, QUParameter::In },
	{ "type", &static_QUType_int, 0, QUParameter::In },
	{ "update", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_26 = {"GetHeadAndFoot", 3, param_slot_26 };
    static const QUMethod slot_27 = {"pushButtonQuitter_clicked", 0, 0 };
    static const QUMethod slot_28 = {"pushButtonConfigurer_clicked", 0, 0 };
    static const QUMethod slot_29 = {"pushButtonPrevious_clicked", 0, 0 };
    static const QUMethod slot_30 = {"pushButtonNext_clicked", 0, 0 };
    static const QUParameter param_slot_31[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_31 = {"checkBox_Duplicata_stateChanged", 1, param_slot_31 };
    static const QUMethod slot_32 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "slider_Marg_Top_sliderMoved(int)", &slot_0, QMetaData::Public },
	{ "slider_Head_H_sliderMoved(int)", &slot_1, QMetaData::Public },
	{ "slider_Marg_Left_sliderMoved(int)", &slot_2, QMetaData::Public },
	{ "slider_Marg_Right_sliderMoved(int)", &slot_3, QMetaData::Public },
	{ "slider_Marg_Bottom_sliderMoved(int)", &slot_4, QMetaData::Public },
	{ "slider_Foot_H_sliderMoved(int)", &slot_5, QMetaData::Public },
	{ "UpdateTextePageInfo(int)", &slot_6, QMetaData::Public },
	{ "initDialog(QTextEdit*,QString&,CMoteurBase*,RUBREC_LIST*,int,int,const char*,const char*,const char*)", &slot_7, QMetaData::Public },
	{ "executeTransfertMacro()", &slot_8, QMetaData::Public },
	{ "SetCaption()", &slot_9, QMetaData::Public },
	{ "pushButtonSave_clicked()", &slot_10, QMetaData::Public },
	{ "SetDialogOnPrinterSpec()", &slot_11, QMetaData::Public },
	{ "comboBox_TypeDoc_activated(const QString&)", &slot_12, QMetaData::Public },
	{ "comboBox_TypeDoc_activated(int)", &slot_13, QMetaData::Public },
	{ "SetDialogOnHeadAndFoot(int)", &slot_14, QMetaData::Public },
	{ "GetPossibleDefaultFont(const QString&,QFont&)", &slot_15, QMetaData::Public },
	{ "FusionneDocument(QString*,QString)", &slot_16, QMetaData::Public },
	{ "AdjustHeightFootAndHead()", &slot_17, QMetaData::Public },
	{ "initRichBodyText(QSimpleRichText*)", &slot_18, QMetaData::Public },
	{ "initRichHeadText(QSimpleRichText*)", &slot_19, QMetaData::Public },
	{ "initRichFootText(QSimpleRichText*)", &slot_20, QMetaData::Public },
	{ "pushButtonOk_clicked()", &slot_21, QMetaData::Public },
	{ "pushButtonPrint_2_clicked()", &slot_22, QMetaData::Public },
	{ "pushButtonPrint_2_2_clicked()", &slot_23, QMetaData::Public },
	{ "pushButtonPrint_clicked()", &slot_24, QMetaData::Public },
	{ "printDoc(int)", &slot_25, QMetaData::Public },
	{ "GetHeadAndFoot(QString,int,int)", &slot_26, QMetaData::Public },
	{ "pushButtonQuitter_clicked()", &slot_27, QMetaData::Public },
	{ "pushButtonConfigurer_clicked()", &slot_28, QMetaData::Public },
	{ "pushButtonPrevious_clicked()", &slot_29, QMetaData::Public },
	{ "pushButtonNext_clicked()", &slot_30, QMetaData::Public },
	{ "checkBox_Duplicata_stateChanged(int)", &slot_31, QMetaData::Public },
	{ "languageChange()", &slot_32, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"DlgPrint", parentObject,
	slot_tbl, 33,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_DlgPrint.setMetaObject( metaObj );
    return metaObj;
}

void* DlgPrint::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "DlgPrint" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool DlgPrint::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slider_Marg_Top_sliderMoved((int)static_QUType_int.get(_o+1)); break;
    case 1: slider_Head_H_sliderMoved((int)static_QUType_int.get(_o+1)); break;
    case 2: slider_Marg_Left_sliderMoved((int)static_QUType_int.get(_o+1)); break;
    case 3: slider_Marg_Right_sliderMoved((int)static_QUType_int.get(_o+1)); break;
    case 4: slider_Marg_Bottom_sliderMoved((int)static_QUType_int.get(_o+1)); break;
    case 5: slider_Foot_H_sliderMoved((int)static_QUType_int.get(_o+1)); break;
    case 6: UpdateTextePageInfo((int)static_QUType_int.get(_o+1)); break;
    case 7: static_QUType_int.set(_o,initDialog((QTextEdit*)static_QUType_ptr.get(_o+1),(QString&)static_QUType_QString.get(_o+2),(CMoteurBase*)static_QUType_ptr.get(_o+3),(RUBREC_LIST*)static_QUType_ptr.get(_o+4),(int)static_QUType_int.get(_o+5),(int)static_QUType_int.get(_o+6),(const char*)static_QUType_charstar.get(_o+7),(const char*)static_QUType_charstar.get(_o+8),(const char*)static_QUType_charstar.get(_o+9))); break;
    case 8: executeTransfertMacro(); break;
    case 9: SetCaption(); break;
    case 10: pushButtonSave_clicked(); break;
    case 11: SetDialogOnPrinterSpec(); break;
    case 12: comboBox_TypeDoc_activated((const QString&)static_QUType_QString.get(_o+1)); break;
    case 13: comboBox_TypeDoc_activated((int)static_QUType_int.get(_o+1)); break;
    case 14: SetDialogOnHeadAndFoot((int)static_QUType_int.get(_o+1)); break;
    case 15: GetPossibleDefaultFont((const QString&)static_QUType_QString.get(_o+1),(QFont&)*((QFont*)static_QUType_ptr.get(_o+2))); break;
    case 16: FusionneDocument((QString*)static_QUType_varptr.get(_o+1),(QString)static_QUType_QString.get(_o+2)); break;
    case 17: AdjustHeightFootAndHead(); break;
    case 18: initRichBodyText((QSimpleRichText*)static_QUType_ptr.get(_o+1)); break;
    case 19: initRichHeadText((QSimpleRichText*)static_QUType_ptr.get(_o+1)); break;
    case 20: initRichFootText((QSimpleRichText*)static_QUType_ptr.get(_o+1)); break;
    case 21: pushButtonOk_clicked(); break;
    case 22: pushButtonPrint_2_clicked(); break;
    case 23: pushButtonPrint_2_2_clicked(); break;
    case 24: pushButtonPrint_clicked(); break;
    case 25: printDoc((int)static_QUType_int.get(_o+1)); break;
    case 26: GetHeadAndFoot((QString)static_QUType_QString.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3)); break;
    case 27: pushButtonQuitter_clicked(); break;
    case 28: pushButtonConfigurer_clicked(); break;
    case 29: pushButtonPrevious_clicked(); break;
    case 30: pushButtonNext_clicked(); break;
    case 31: checkBox_Duplicata_stateChanged((int)static_QUType_int.get(_o+1)); break;
    case 32: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool DlgPrint::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool DlgPrint::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool DlgPrint::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
