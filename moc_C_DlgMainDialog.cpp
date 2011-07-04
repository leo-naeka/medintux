/****************************************************************************
** C_DlgMainDialog meta object code from reading C++ file 'C_DlgMainDialog.h'
**
** Created: Wed May 4 22:15:54 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../C_DlgMainDialog.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *C_DlgMainDialog::className() const
{
    return "C_DlgMainDialog";
}

QMetaObject *C_DlgMainDialog::metaObj = 0;
static QMetaObjectCleanUp cleanUp_C_DlgMainDialog( "C_DlgMainDialog", &C_DlgMainDialog::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString C_DlgMainDialog::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_DlgMainDialog", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString C_DlgMainDialog::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_DlgMainDialog", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* C_DlgMainDialog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = Dlg_MainDialog::staticMetaObject();
    static const QUMethod slot_0 = {"Slot_close", 0, 0 };
    static const QUMethod slot_1 = {"Slot_SauverLesMeubles", 0, 0 };
    static const QUMethod slot_2 = {"Slot_actionApropos", 0, 0 };
    static const QUMethod slot_3 = {"Slot_actionAproposDisplay", 0, 0 };
    static const QUMethod slot_4 = {"tryToStopAPropos", 0, 0 };
    static const QUMethod slot_5 = {"pushButton_Load_SQL_clicked", 0, 0 };
    static const QUMethod slot_6 = {"pushButton_Qt3_clicked", 0, 0 };
    static const QUMethod slot_7 = {"pushButton_Qt4Sdk_clicked", 0, 0 };
    static const QUParameter param_slot_8[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_8 = {"checkBox_Nomadisme_stateChanged", 1, param_slot_8 };
    static const QUMethod slot_9 = {"pushButton_LireVitale_clicked", 0, 0 };
    static const QUMethod slot_10 = {"pushButtonMakeSQL_clicked", 0, 0 };
    static const QUParameter param_slot_11[] = {
	{ "dir_to_erase", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_11 = {"eraseDirectory", 1, param_slot_11 };
    static const QUParameter param_slot_12[] = {
	{ "src_PrefixDir", &static_QUType_QString, 0, QUParameter::InOut },
	{ "dir_to_explore", &static_QUType_QString, 0, QUParameter::In },
	{ "images_DstDir", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_12 = {"copyDirectory", 3, param_slot_12 };
    static const QUMethod slot_13 = {"copyDatasempImages", 0, 0 };
    static const QUMethod slot_14 = {"pushButtonImagesCopy_clicked", 0, 0 };
    static const QUParameter param_slot_15[] = {
	{ "version", &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod slot_15 = {"SetDatasempIndexVersion", 1, param_slot_15 };
    static const QUParameter param_slot_16[] = {
	{ "mode", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_16 = {"SetButtonIndexVidal", 1, param_slot_16 };
    static const QUMethod slot_17 = {"pushButton_MajBases_clicked", 0, 0 };
    static const QUMethod slot_18 = {"pushButtonConnexionAppl_clicked", 0, 0 };
    static const QUMethod slot_19 = {"pushButtonSwitchGetDatasemp_clicked", 0, 0 };
    static const QUMethod slot_20 = {"StopCUpdateThread", 0, 0 };
    static const QUParameter param_slot_21[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_21 = {"checkBox_SQL_MAJ_stateChanged", 1, param_slot_21 };
    static const QUParameter param_slot_22[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_22 = {"checkBox_STD_MAJ_stateChanged", 1, param_slot_22 };
    static const QUMethod slot_23 = {"timerDisplayDone", 0, 0 };
    static const QUParameter param_slot_24[] = {
	{ "mainDir", &static_QUType_QString, 0, QUParameter::In },
	{ "dir", &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod slot_24 = {"verifieDatasempDir", 2, param_slot_24 };
    static const QUMethod slot_25 = {"pushButton_SetDatasemp_clicked", 0, 0 };
    static const QUMethod slot_26 = {"pushButtonJustOneTable_clicked", 0, 0 };
    static const QUMethod slot_27 = {"pushButton_LancerDrTux_clicked", 0, 0 };
    static const QUMethod slot_28 = {"pushButton_SetBases_clicked", 0, 0 };
    static const QUMethod slot_29 = {"updateExit", 0, 0 };
    static const QUMethod slot_30 = {"updateText", 0, 0 };
    static const QUMethod slot_31 = {"updateError", 0, 0 };
    static const QUParameter param_slot_32[] = {
	{ "command", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_32 = {"execute", 1, param_slot_32 };
    static const QUParameter param_slot_33[] = {
	{ "command", &static_QUType_QString, 0, QUParameter::In },
	{ "curDir", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_33 = {"execute", 2, param_slot_33 };
    static const QUParameter param_slot_34[] = {
	{ "path", &static_QUType_QString, 0, QUParameter::In },
	{ "target", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_34 = {"Compilation", 2, param_slot_34 };
    static const QUMethod slot_35 = {"pushButton_compilation_clicked", 0, 0 };
    static const QUMethod slot_36 = {"pushButtonRemove_clicked", 0, 0 };
    static const QUMethod slot_37 = {"pushButton_FavPlus_clicked", 0, 0 };
    static const QUParameter param_slot_38[] = {
	{ "text", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_38 = {"comboBox_IP_Fav_highlighted", 1, param_slot_38 };
    static const QUParameter param_slot_39[] = {
	{ "text", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_39 = {"comboBox_IP_Fav_activated", 1, param_slot_39 };
    static const QUMethod slot_40 = {"pushButtonRemove_2_clicked", 0, 0 };
    static const QUMethod slot_41 = {"pushButton_FavPlus_2_clicked", 0, 0 };
    static const QUParameter param_slot_42[] = {
	{ "text", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_42 = {"comboBox_IP_Fav_2_highlighted", 1, param_slot_42 };
    static const QUParameter param_slot_43[] = {
	{ "text", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_43 = {"comboBox_IP_Fav_2_activated", 1, param_slot_43 };
    static const QUMethod slot_44 = {"pushButtonRemove_3_clicked", 0, 0 };
    static const QUMethod slot_45 = {"pushButton_FavPlus_3_clicked", 0, 0 };
    static const QUParameter param_slot_46[] = {
	{ "text", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_46 = {"comboBox_IP_Fav_3_highlighted", 1, param_slot_46 };
    static const QUParameter param_slot_47[] = {
	{ "text", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_47 = {"comboBox_IP_Fav_3_activated", 1, param_slot_47 };
    static const QUParameter param_slot_48[] = {
	{ "pQComboBox", &static_QUType_ptr, "QComboBox", QUParameter::In }
    };
    static const QUMethod slot_48 = {"fillFavoris", 1, param_slot_48 };
    static const QUParameter param_slot_49[] = {
	{ "pQComboBox", &static_QUType_ptr, "QComboBox", QUParameter::In }
    };
    static const QUMethod slot_49 = {"saveFavoris", 1, param_slot_49 };
    static const QUParameter param_slot_50[] = {
	{ "n_Version", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_50 = {"SetTitle", 1, param_slot_50 };
    static const QUMethod slot_51 = {"pushButton_InstallSesam_clicked", 0, 0 };
    static const QUMethod slot_52 = {"Slot_pushButton_setGalsINI_clicked", 0, 0 };
    static const QUMethod slot_53 = {"pushButton_IndexerDatasemp_clicked", 0, 0 };
    static const QUMethod slot_54 = {"IndexTimerDisplayDone", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "Slot_close()", &slot_0, QMetaData::Public },
	{ "Slot_SauverLesMeubles()", &slot_1, QMetaData::Public },
	{ "Slot_actionApropos()", &slot_2, QMetaData::Public },
	{ "Slot_actionAproposDisplay()", &slot_3, QMetaData::Public },
	{ "tryToStopAPropos()", &slot_4, QMetaData::Public },
	{ "pushButton_Load_SQL_clicked()", &slot_5, QMetaData::Public },
	{ "pushButton_Qt3_clicked()", &slot_6, QMetaData::Public },
	{ "pushButton_Qt4Sdk_clicked()", &slot_7, QMetaData::Public },
	{ "checkBox_Nomadisme_stateChanged(int)", &slot_8, QMetaData::Public },
	{ "pushButton_LireVitale_clicked()", &slot_9, QMetaData::Public },
	{ "pushButtonMakeSQL_clicked()", &slot_10, QMetaData::Public },
	{ "eraseDirectory(QString)", &slot_11, QMetaData::Public },
	{ "copyDirectory(QString&,QString,QString)", &slot_12, QMetaData::Public },
	{ "copyDatasempImages()", &slot_13, QMetaData::Public },
	{ "pushButtonImagesCopy_clicked()", &slot_14, QMetaData::Public },
	{ "SetDatasempIndexVersion(QString&)", &slot_15, QMetaData::Public },
	{ "SetButtonIndexVidal(int)", &slot_16, QMetaData::Public },
	{ "pushButton_MajBases_clicked()", &slot_17, QMetaData::Public },
	{ "pushButtonConnexionAppl_clicked()", &slot_18, QMetaData::Public },
	{ "pushButtonSwitchGetDatasemp_clicked()", &slot_19, QMetaData::Public },
	{ "StopCUpdateThread()", &slot_20, QMetaData::Public },
	{ "checkBox_SQL_MAJ_stateChanged(int)", &slot_21, QMetaData::Public },
	{ "checkBox_STD_MAJ_stateChanged(int)", &slot_22, QMetaData::Public },
	{ "timerDisplayDone()", &slot_23, QMetaData::Public },
	{ "verifieDatasempDir(const QString&,QString&)", &slot_24, QMetaData::Public },
	{ "pushButton_SetDatasemp_clicked()", &slot_25, QMetaData::Public },
	{ "pushButtonJustOneTable_clicked()", &slot_26, QMetaData::Public },
	{ "pushButton_LancerDrTux_clicked()", &slot_27, QMetaData::Public },
	{ "pushButton_SetBases_clicked()", &slot_28, QMetaData::Public },
	{ "updateExit()", &slot_29, QMetaData::Public },
	{ "updateText()", &slot_30, QMetaData::Public },
	{ "updateError()", &slot_31, QMetaData::Public },
	{ "execute(const QString&)", &slot_32, QMetaData::Public },
	{ "execute(const QString&,const QString)", &slot_33, QMetaData::Public },
	{ "Compilation(const QString&,const QString&)", &slot_34, QMetaData::Public },
	{ "pushButton_compilation_clicked()", &slot_35, QMetaData::Public },
	{ "pushButtonRemove_clicked()", &slot_36, QMetaData::Public },
	{ "pushButton_FavPlus_clicked()", &slot_37, QMetaData::Public },
	{ "comboBox_IP_Fav_highlighted(const QString&)", &slot_38, QMetaData::Public },
	{ "comboBox_IP_Fav_activated(const QString&)", &slot_39, QMetaData::Public },
	{ "pushButtonRemove_2_clicked()", &slot_40, QMetaData::Public },
	{ "pushButton_FavPlus_2_clicked()", &slot_41, QMetaData::Public },
	{ "comboBox_IP_Fav_2_highlighted(const QString&)", &slot_42, QMetaData::Public },
	{ "comboBox_IP_Fav_2_activated(const QString&)", &slot_43, QMetaData::Public },
	{ "pushButtonRemove_3_clicked()", &slot_44, QMetaData::Public },
	{ "pushButton_FavPlus_3_clicked()", &slot_45, QMetaData::Public },
	{ "comboBox_IP_Fav_3_highlighted(const QString&)", &slot_46, QMetaData::Public },
	{ "comboBox_IP_Fav_3_activated(const QString&)", &slot_47, QMetaData::Public },
	{ "fillFavoris(QComboBox*)", &slot_48, QMetaData::Public },
	{ "saveFavoris(QComboBox*)", &slot_49, QMetaData::Public },
	{ "SetTitle(QString)", &slot_50, QMetaData::Public },
	{ "pushButton_InstallSesam_clicked()", &slot_51, QMetaData::Public },
	{ "Slot_pushButton_setGalsINI_clicked()", &slot_52, QMetaData::Public },
	{ "pushButton_IndexerDatasemp_clicked()", &slot_53, QMetaData::Public },
	{ "IndexTimerDisplayDone()", &slot_54, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"C_DlgMainDialog", parentObject,
	slot_tbl, 55,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_C_DlgMainDialog.setMetaObject( metaObj );
    return metaObj;
}

void* C_DlgMainDialog::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "C_DlgMainDialog" ) )
	return this;
    return Dlg_MainDialog::qt_cast( clname );
}

bool C_DlgMainDialog::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: Slot_close(); break;
    case 1: Slot_SauverLesMeubles(); break;
    case 2: Slot_actionApropos(); break;
    case 3: Slot_actionAproposDisplay(); break;
    case 4: tryToStopAPropos(); break;
    case 5: pushButton_Load_SQL_clicked(); break;
    case 6: pushButton_Qt3_clicked(); break;
    case 7: pushButton_Qt4Sdk_clicked(); break;
    case 8: checkBox_Nomadisme_stateChanged((int)static_QUType_int.get(_o+1)); break;
    case 9: pushButton_LireVitale_clicked(); break;
    case 10: pushButtonMakeSQL_clicked(); break;
    case 11: eraseDirectory((QString)static_QUType_QString.get(_o+1)); break;
    case 12: copyDirectory((QString&)static_QUType_QString.get(_o+1),(QString)static_QUType_QString.get(_o+2),(QString)static_QUType_QString.get(_o+3)); break;
    case 13: copyDatasempImages(); break;
    case 14: pushButtonImagesCopy_clicked(); break;
    case 15: SetDatasempIndexVersion((QString&)static_QUType_QString.get(_o+1)); break;
    case 16: SetButtonIndexVidal((int)static_QUType_int.get(_o+1)); break;
    case 17: pushButton_MajBases_clicked(); break;
    case 18: pushButtonConnexionAppl_clicked(); break;
    case 19: pushButtonSwitchGetDatasemp_clicked(); break;
    case 20: StopCUpdateThread(); break;
    case 21: checkBox_SQL_MAJ_stateChanged((int)static_QUType_int.get(_o+1)); break;
    case 22: checkBox_STD_MAJ_stateChanged((int)static_QUType_int.get(_o+1)); break;
    case 23: timerDisplayDone(); break;
    case 24: verifieDatasempDir((const QString&)static_QUType_QString.get(_o+1),(QString&)static_QUType_QString.get(_o+2)); break;
    case 25: pushButton_SetDatasemp_clicked(); break;
    case 26: pushButtonJustOneTable_clicked(); break;
    case 27: pushButton_LancerDrTux_clicked(); break;
    case 28: pushButton_SetBases_clicked(); break;
    case 29: updateExit(); break;
    case 30: updateText(); break;
    case 31: updateError(); break;
    case 32: execute((const QString&)static_QUType_QString.get(_o+1)); break;
    case 33: execute((const QString&)static_QUType_QString.get(_o+1),(const QString)static_QUType_QString.get(_o+2)); break;
    case 34: Compilation((const QString&)static_QUType_QString.get(_o+1),(const QString&)static_QUType_QString.get(_o+2)); break;
    case 35: pushButton_compilation_clicked(); break;
    case 36: pushButtonRemove_clicked(); break;
    case 37: pushButton_FavPlus_clicked(); break;
    case 38: comboBox_IP_Fav_highlighted((const QString&)static_QUType_QString.get(_o+1)); break;
    case 39: comboBox_IP_Fav_activated((const QString&)static_QUType_QString.get(_o+1)); break;
    case 40: pushButtonRemove_2_clicked(); break;
    case 41: pushButton_FavPlus_2_clicked(); break;
    case 42: comboBox_IP_Fav_2_highlighted((const QString&)static_QUType_QString.get(_o+1)); break;
    case 43: comboBox_IP_Fav_2_activated((const QString&)static_QUType_QString.get(_o+1)); break;
    case 44: pushButtonRemove_3_clicked(); break;
    case 45: pushButton_FavPlus_3_clicked(); break;
    case 46: comboBox_IP_Fav_3_highlighted((const QString&)static_QUType_QString.get(_o+1)); break;
    case 47: comboBox_IP_Fav_3_activated((const QString&)static_QUType_QString.get(_o+1)); break;
    case 48: fillFavoris((QComboBox*)static_QUType_ptr.get(_o+1)); break;
    case 49: saveFavoris((QComboBox*)static_QUType_ptr.get(_o+1)); break;
    case 50: SetTitle((QString)static_QUType_QString.get(_o+1)); break;
    case 51: pushButton_InstallSesam_clicked(); break;
    case 52: Slot_pushButton_setGalsINI_clicked(); break;
    case 53: pushButton_IndexerDatasemp_clicked(); break;
    case 54: IndexTimerDisplayDone(); break;
    default:
	return Dlg_MainDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool C_DlgMainDialog::qt_emit( int _id, QUObject* _o )
{
    return Dlg_MainDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool C_DlgMainDialog::qt_property( int id, int f, QVariant* v)
{
    return Dlg_MainDialog::qt_property( id, f, v);
}

bool C_DlgMainDialog::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
