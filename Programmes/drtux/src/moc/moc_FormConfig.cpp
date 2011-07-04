/****************************************************************************
** FormConfig meta object code from reading C++ file 'FormConfig.h'
**
** Created: Wed May 4 22:20:48 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../ui/FormConfig.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *FormConfig::className() const
{
    return "FormConfig";
}

QMetaObject *FormConfig::metaObj = 0;
static QMetaObjectCleanUp cleanUp_FormConfig( "FormConfig", &FormConfig::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString FormConfig::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "FormConfig", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString FormConfig::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "FormConfig", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* FormConfig::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"init_listViewRubParameters", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"listViewRubParameters_doubleClicked", 3, param_slot_1 };
    static const QUMethod slot_2 = {"AddNewRub", 0, 0 };
    static const QUMethod slot_3 = {"save_listViewRubParameters", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ "ParamsOfAppli", &static_QUType_charstar, 0, QUParameter::In },
	{ "ParamsOfUser", &static_QUType_charstar, 0, QUParameter::In },
	{ "PathOfAppli", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"setParams", 3, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ "ParamsOfAppli", &static_QUType_QString, 0, QUParameter::InOut },
	{ "ParamsOfUser", &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod slot_5 = {"getParams", 2, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "def", &static_QUType_QString, 0, QUParameter::In },
	{ "label", &static_QUType_ptr, "QLabel", QUParameter::InOut },
	{ "lineedit", &static_QUType_ptr, "QLineEdit", QUParameter::InOut }
    };
    static const QUMethod slot_6 = {"readVarString", 3, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ "param", &static_QUType_QString, 0, QUParameter::InOut },
	{ "def", &static_QUType_QString, 0, QUParameter::In },
	{ "label", &static_QUType_ptr, "QLabel", QUParameter::InOut },
	{ "spinbox", &static_QUType_ptr, "QSpinBox", QUParameter::In }
    };
    static const QUMethod slot_7 = {"readVarString", 4, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ "param", &static_QUType_QString, 0, QUParameter::InOut },
	{ "def", &static_QUType_QString, 0, QUParameter::In },
	{ "pW1", &static_QUType_ptr, "QLabel", QUParameter::InOut },
	{ "pW2", &static_QUType_ptr, "QLineEdit", QUParameter::InOut }
    };
    static const QUMethod slot_8 = {"readVarString", 4, param_slot_8 };
    static const QUParameter param_slot_9[] = {
	{ "param", &static_QUType_QString, 0, QUParameter::InOut },
	{ "def", &static_QUType_QString, 0, QUParameter::In },
	{ "pW1", &static_QUType_ptr, "QLabel", QUParameter::InOut },
	{ "pW2", &static_QUType_ptr, "QComboBox", QUParameter::InOut }
    };
    static const QUMethod slot_9 = {"readVarString", 4, param_slot_9 };
    static const QUParameter param_slot_10[] = {
	{ "param", &static_QUType_QString, 0, QUParameter::InOut },
	{ "defaut", &static_QUType_QString, 0, QUParameter::In },
	{ "pW1", &static_QUType_ptr, "QCheckBox", QUParameter::InOut },
	{ "ValPourOui", &static_QUType_charstar, 0, QUParameter::In },
	{ "ValPourNon", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_10 = {"readVarString", 5, param_slot_10 };
    static const QUMethod slot_11 = {"buttonHelp_clicked", 0, 0 };
    static const QUParameter param_slot_12[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_12 = {"CCAMPrefixe_textChanged", 1, param_slot_12 };
    static const QUParameter param_slot_13[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_13 = {"CCAMPostfixe_textChanged", 1, param_slot_13 };
    static const QUParameter param_slot_14[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_14 = {"CCAMCodePrefixe_textChanged", 1, param_slot_14 };
    static const QUParameter param_slot_15[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_15 = {"CCAMCodePostfixe_textChanged", 1, param_slot_15 };
    static const QUMethod slot_16 = {"buttonOk_clicked", 0, 0 };
    static const QUParameter param_slot_17[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_17 = {"listBox_highlighted", 1, param_slot_17 };
    static const QUMethod slot_18 = {"but_MenuImages_clicked", 0, 0 };
    static const QUMethod slot_19 = {"but_tmpRepTmp_clicked", 0, 0 };
    static const QUMethod slot_20 = {"but_RepGlossaire_clicked", 0, 0 };
    static const QUMethod slot_21 = {"but_RepAide_clicked", 0, 0 };
    static const QUMethod slot_22 = {"but_MasqueVigie_clicked", 0, 0 };
    static const QUMethod slot_23 = {"but_AppliContact_clicked", 0, 0 };
    static const QUMethod slot_24 = {"but_AppliUtilisateur_clicked", 0, 0 };
    static const QUMethod slot_25 = {"but_CCAMExe_clicked", 0, 0 };
    static const QUMethod slot_26 = {"but_CCAMConfig_clicked", 0, 0 };
    static const QUMethod slot_27 = {"but_RepDesPDF_clicked", 0, 0 };
    static const QUMethod slot_28 = {"but_RepTmpPDF_clicked", 0, 0 };
    static const QUMethod slot_29 = {"but_AppliPdftk_clicked", 0, 0 };
    static const QUMethod slot_30 = {"but_VisuPDF_clicked", 0, 0 };
    static const QUMethod slot_31 = {"pushButtonAddRubrique_clicked", 0, 0 };
    static const QUMethod slot_32 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "init_listViewRubParameters()", &slot_0, QMetaData::Public },
	{ "listViewRubParameters_doubleClicked(QListViewItem*,const QPoint&,int)", &slot_1, QMetaData::Public },
	{ "AddNewRub()", &slot_2, QMetaData::Public },
	{ "save_listViewRubParameters()", &slot_3, QMetaData::Public },
	{ "setParams(const char*,const char*,const char*)", &slot_4, QMetaData::Public },
	{ "getParams(QString&,QString&)", &slot_5, QMetaData::Public },
	{ "readVarString(QString,QLabel&,QLineEdit&)", &slot_6, QMetaData::Public },
	{ "readVarString(QString&,QString,QLabel&,QSpinBox*)", &slot_7, QMetaData::Public },
	{ "readVarString(QString&,QString,QLabel&,QLineEdit&)", &slot_8, QMetaData::Public },
	{ "readVarString(QString&,QString,QLabel&,QComboBox&)", &slot_9, QMetaData::Public },
	{ "readVarString(QString&,QString,QCheckBox&,const char*,const char*)", &slot_10, QMetaData::Public },
	{ "buttonHelp_clicked()", &slot_11, QMetaData::Public },
	{ "CCAMPrefixe_textChanged(const QString&)", &slot_12, QMetaData::Public },
	{ "CCAMPostfixe_textChanged(const QString&)", &slot_13, QMetaData::Public },
	{ "CCAMCodePrefixe_textChanged(const QString&)", &slot_14, QMetaData::Public },
	{ "CCAMCodePostfixe_textChanged(const QString&)", &slot_15, QMetaData::Public },
	{ "buttonOk_clicked()", &slot_16, QMetaData::Public },
	{ "listBox_highlighted(int)", &slot_17, QMetaData::Public },
	{ "but_MenuImages_clicked()", &slot_18, QMetaData::Public },
	{ "but_tmpRepTmp_clicked()", &slot_19, QMetaData::Public },
	{ "but_RepGlossaire_clicked()", &slot_20, QMetaData::Public },
	{ "but_RepAide_clicked()", &slot_21, QMetaData::Public },
	{ "but_MasqueVigie_clicked()", &slot_22, QMetaData::Public },
	{ "but_AppliContact_clicked()", &slot_23, QMetaData::Public },
	{ "but_AppliUtilisateur_clicked()", &slot_24, QMetaData::Public },
	{ "but_CCAMExe_clicked()", &slot_25, QMetaData::Public },
	{ "but_CCAMConfig_clicked()", &slot_26, QMetaData::Public },
	{ "but_RepDesPDF_clicked()", &slot_27, QMetaData::Public },
	{ "but_RepTmpPDF_clicked()", &slot_28, QMetaData::Public },
	{ "but_AppliPdftk_clicked()", &slot_29, QMetaData::Public },
	{ "but_VisuPDF_clicked()", &slot_30, QMetaData::Public },
	{ "pushButtonAddRubrique_clicked()", &slot_31, QMetaData::Public },
	{ "languageChange()", &slot_32, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"FormConfig", parentObject,
	slot_tbl, 33,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_FormConfig.setMetaObject( metaObj );
    return metaObj;
}

void* FormConfig::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "FormConfig" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool FormConfig::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: init_listViewRubParameters(); break;
    case 1: listViewRubParameters_doubleClicked((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 2: AddNewRub(); break;
    case 3: save_listViewRubParameters(); break;
    case 4: setParams((const char*)static_QUType_charstar.get(_o+1),(const char*)static_QUType_charstar.get(_o+2),(const char*)static_QUType_charstar.get(_o+3)); break;
    case 5: getParams((QString&)static_QUType_QString.get(_o+1),(QString&)static_QUType_QString.get(_o+2)); break;
    case 6: readVarString((QString)static_QUType_QString.get(_o+1),(QLabel&)*((QLabel*)static_QUType_ptr.get(_o+2)),(QLineEdit&)*((QLineEdit*)static_QUType_ptr.get(_o+3))); break;
    case 7: readVarString((QString&)static_QUType_QString.get(_o+1),(QString)static_QUType_QString.get(_o+2),(QLabel&)*((QLabel*)static_QUType_ptr.get(_o+3)),(QSpinBox*)static_QUType_ptr.get(_o+4)); break;
    case 8: readVarString((QString&)static_QUType_QString.get(_o+1),(QString)static_QUType_QString.get(_o+2),(QLabel&)*((QLabel*)static_QUType_ptr.get(_o+3)),(QLineEdit&)*((QLineEdit*)static_QUType_ptr.get(_o+4))); break;
    case 9: readVarString((QString&)static_QUType_QString.get(_o+1),(QString)static_QUType_QString.get(_o+2),(QLabel&)*((QLabel*)static_QUType_ptr.get(_o+3)),(QComboBox&)*((QComboBox*)static_QUType_ptr.get(_o+4))); break;
    case 10: readVarString((QString&)static_QUType_QString.get(_o+1),(QString)static_QUType_QString.get(_o+2),(QCheckBox&)*((QCheckBox*)static_QUType_ptr.get(_o+3)),(const char*)static_QUType_charstar.get(_o+4),(const char*)static_QUType_charstar.get(_o+5)); break;
    case 11: buttonHelp_clicked(); break;
    case 12: CCAMPrefixe_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 13: CCAMPostfixe_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 14: CCAMCodePrefixe_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 15: CCAMCodePostfixe_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 16: buttonOk_clicked(); break;
    case 17: listBox_highlighted((int)static_QUType_int.get(_o+1)); break;
    case 18: but_MenuImages_clicked(); break;
    case 19: but_tmpRepTmp_clicked(); break;
    case 20: but_RepGlossaire_clicked(); break;
    case 21: but_RepAide_clicked(); break;
    case 22: but_MasqueVigie_clicked(); break;
    case 23: but_AppliContact_clicked(); break;
    case 24: but_AppliUtilisateur_clicked(); break;
    case 25: but_CCAMExe_clicked(); break;
    case 26: but_CCAMConfig_clicked(); break;
    case 27: but_RepDesPDF_clicked(); break;
    case 28: but_RepTmpPDF_clicked(); break;
    case 29: but_AppliPdftk_clicked(); break;
    case 30: but_VisuPDF_clicked(); break;
    case 31: pushButtonAddRubrique_clicked(); break;
    case 32: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool FormConfig::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool FormConfig::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool FormConfig::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
