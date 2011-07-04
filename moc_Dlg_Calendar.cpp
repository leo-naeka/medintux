/****************************************************************************
** Dlg_Calendar meta object code from reading C++ file 'Dlg_Calendar.h'
**
** Created: Wed May 4 22:20:39 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../ui/Dlg_Calendar.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#include <qvariant.h>
const char *Dlg_Calendar::className() const
{
    return "Dlg_Calendar";
}

QMetaObject *Dlg_Calendar::metaObj = 0;
static QMetaObjectCleanUp cleanUp_Dlg_Calendar( "Dlg_Calendar", &Dlg_Calendar::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString Dlg_Calendar::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Dlg_Calendar", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString Dlg_Calendar::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Dlg_Calendar", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* Dlg_Calendar::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "rQPixmap", &static_QUType_varptr, "\x06", QUParameter::In }
    };
    static const QUMethod slot_0 = {"DateMenu_setIcon", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "moinsQPixmap", &static_QUType_varptr, "\x06", QUParameter::In },
	{ "plusQPixmap", &static_QUType_varptr, "\x06", QUParameter::In }
    };
    static const QUMethod slot_1 = {"Month_setIcon", 2, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "moinsQPixmap", &static_QUType_varptr, "\x06", QUParameter::In },
	{ "plusQPixmap", &static_QUType_varptr, "\x06", QUParameter::In }
    };
    static const QUMethod slot_2 = {"Year_setIcon", 2, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "pdate", &static_QUType_varptr, "\x1a", QUParameter::In }
    };
    static const QUMethod slot_3 = {"setDateDeb", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ "mode", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"setMode", 1, param_slot_4 };
    static const QUMethod slot_5 = {"hideHeure", 0, 0 };
    static const QUParameter param_slot_6[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out },
	{ "dateTime", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"setDateTimeNatural_jjMMyyyy_Order", 2, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ "heure", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"setHeure", 1, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ "h", &static_QUType_int, 0, QUParameter::In },
	{ "m", &static_QUType_int, 0, QUParameter::In },
	{ "s", &static_QUType_int, 0, QUParameter::In },
	{ "ms", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_8 = {"setHeure", 4, param_slot_8 };
    static const QUParameter param_slot_9[] = {
	{ "time", &static_QUType_varptr, "\x1b", QUParameter::In }
    };
    static const QUMethod slot_9 = {"setHeure", 1, param_slot_9 };
    static const QUMethod slot_10 = {"SelectDateAll", 0, 0 };
    static const QUMethod slot_11 = {"Slot_OnReturnPressed", 0, 0 };
    static const QUMethod slot_12 = {"Slot_OnTableDoubleClicked", 0, 0 };
    static const QUMethod slot_13 = {"Slot_OnTableClicked", 0, 0 };
    static const QUParameter param_slot_14[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_14 = {"Slot_OnTextDateChanged", 1, param_slot_14 };
    static const QUParameter param_slot_15[] = {
	{ "date", &static_QUType_varptr, "\x1a", QUParameter::In }
    };
    static const QUMethod slot_15 = {"setDate", 1, param_slot_15 };
    static const QUParameter param_slot_16[] = {
	{ "date", &static_QUType_varptr, "\x1a", QUParameter::In }
    };
    static const QUMethod slot_16 = {"Slot_OndateChanged", 1, param_slot_16 };
    static const QUParameter param_slot_17[] = {
	{ "date", &static_QUType_varptr, "\x1a", QUParameter::In }
    };
    static const QUMethod slot_17 = {"AdjustInterfaceToDate", 1, param_slot_17 };
    static const QUParameter param_slot_18[] = {
	{ 0, &static_QUType_QVariant, "\x1a", QUParameter::Out }
    };
    static const QUMethod slot_18 = {"getDate", 1, param_slot_18 };
    static const QUMethod slot_19 = {"pushButtonYearPlus_clicked", 0, 0 };
    static const QUMethod slot_20 = {"pushButtonMonthPlus_clicked", 0, 0 };
    static const QUMethod slot_21 = {"pushButtonYearMoins_clicked", 0, 0 };
    static const QUMethod slot_22 = {"pushButtonMonthMoins_clicked", 0, 0 };
    static const QUParameter param_slot_23[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_23 = {"comboBoxMois_activated", 1, param_slot_23 };
    static const QUParameter param_slot_24[] = {
	{ "an", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_24 = {"comboBoxAn_activated", 1, param_slot_24 };
    static const QUParameter param_slot_25[] = {
	{ "an", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_25 = {"comboBoxAn_textChanged", 1, param_slot_25 };
    static const QUParameter param_slot_26[] = {
	{ "date", &static_QUType_varptr, "\x1a", QUParameter::In }
    };
    static const QUMethod slot_26 = {"setComboAnOnDate", 1, param_slot_26 };
    static const QUParameter param_slot_27[] = {
	{ "date", &static_QUType_varptr, "\x1a", QUParameter::In },
	{ "neg_Offset", &static_QUType_int, 0, QUParameter::In },
	{ "pos_Offset", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_27 = {"setComboAnOnDate_Offset", 3, param_slot_27 };
    static const QUMethod slot_28 = {"setMenuPreselectDateOn", 0, 0 };
    static const QUMethod slot_29 = {"setMenuPreselectDateOff", 0, 0 };
    static const QUParameter param_slot_30[] = {
	{ "itemList", &static_QUType_varptr, "\x04", QUParameter::In }
    };
    static const QUMethod slot_30 = {"setMenuPreSelectDate", 1, param_slot_30 };
    static const QUMethod slot_31 = {"Slot_pushButtonMenu_clicked", 0, 0 };
    static const QUParameter param_slot_32[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_32 = {"OnMenuActivated", 1, param_slot_32 };
    static const QUMethod slot_33 = {"GetPopupItem", 0, 0 };
    static const QUMethod slot_34 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "DateMenu_setIcon(const QPixmap&)", &slot_0, QMetaData::Public },
	{ "Month_setIcon(const QPixmap&,const QPixmap&)", &slot_1, QMetaData::Public },
	{ "Year_setIcon(const QPixmap&,const QPixmap&)", &slot_2, QMetaData::Public },
	{ "setDateDeb(QDate*)", &slot_3, QMetaData::Public },
	{ "setMode(const QString&)", &slot_4, QMetaData::Public },
	{ "hideHeure()", &slot_5, QMetaData::Public },
	{ "setDateTimeNatural_jjMMyyyy_Order(const QString&)", &slot_6, QMetaData::Public },
	{ "setHeure(const QString&)", &slot_7, QMetaData::Public },
	{ "setHeure(int,int,int,int)", &slot_8, QMetaData::Public },
	{ "setHeure(const QTime&)", &slot_9, QMetaData::Public },
	{ "SelectDateAll()", &slot_10, QMetaData::Public },
	{ "Slot_OnReturnPressed()", &slot_11, QMetaData::Public },
	{ "Slot_OnTableDoubleClicked()", &slot_12, QMetaData::Public },
	{ "Slot_OnTableClicked()", &slot_13, QMetaData::Public },
	{ "Slot_OnTextDateChanged(const QString&)", &slot_14, QMetaData::Public },
	{ "setDate(const QDate&)", &slot_15, QMetaData::Public },
	{ "Slot_OndateChanged(QDate)", &slot_16, QMetaData::Public },
	{ "AdjustInterfaceToDate(const QDate&)", &slot_17, QMetaData::Public },
	{ "getDate()", &slot_18, QMetaData::Public },
	{ "pushButtonYearPlus_clicked()", &slot_19, QMetaData::Public },
	{ "pushButtonMonthPlus_clicked()", &slot_20, QMetaData::Public },
	{ "pushButtonYearMoins_clicked()", &slot_21, QMetaData::Public },
	{ "pushButtonMonthMoins_clicked()", &slot_22, QMetaData::Public },
	{ "comboBoxMois_activated(const QString&)", &slot_23, QMetaData::Public },
	{ "comboBoxAn_activated(const QString&)", &slot_24, QMetaData::Public },
	{ "comboBoxAn_textChanged(const QString&)", &slot_25, QMetaData::Public },
	{ "setComboAnOnDate(const QDate&)", &slot_26, QMetaData::Public },
	{ "setComboAnOnDate_Offset(const QDate&,int,int)", &slot_27, QMetaData::Public },
	{ "setMenuPreselectDateOn()", &slot_28, QMetaData::Public },
	{ "setMenuPreselectDateOff()", &slot_29, QMetaData::Public },
	{ "setMenuPreSelectDate(const QStringList&)", &slot_30, QMetaData::Public },
	{ "Slot_pushButtonMenu_clicked()", &slot_31, QMetaData::Public },
	{ "OnMenuActivated(int)", &slot_32, QMetaData::Public },
	{ "GetPopupItem()", &slot_33, QMetaData::Public },
	{ "languageChange()", &slot_34, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"Dlg_Calendar", parentObject,
	slot_tbl, 35,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_Dlg_Calendar.setMetaObject( metaObj );
    return metaObj;
}

void* Dlg_Calendar::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "Dlg_Calendar" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool Dlg_Calendar::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: DateMenu_setIcon((const QPixmap&)*((const QPixmap*)static_QUType_ptr.get(_o+1))); break;
    case 1: Month_setIcon((const QPixmap&)*((const QPixmap*)static_QUType_ptr.get(_o+1)),(const QPixmap&)*((const QPixmap*)static_QUType_ptr.get(_o+2))); break;
    case 2: Year_setIcon((const QPixmap&)*((const QPixmap*)static_QUType_ptr.get(_o+1)),(const QPixmap&)*((const QPixmap*)static_QUType_ptr.get(_o+2))); break;
    case 3: setDateDeb((QDate*)static_QUType_varptr.get(_o+1)); break;
    case 4: setMode((const QString&)static_QUType_QString.get(_o+1)); break;
    case 5: hideHeure(); break;
    case 6: static_QUType_int.set(_o,setDateTimeNatural_jjMMyyyy_Order((const QString&)static_QUType_QString.get(_o+1))); break;
    case 7: setHeure((const QString&)static_QUType_QString.get(_o+1)); break;
    case 8: setHeure((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(int)static_QUType_int.get(_o+4)); break;
    case 9: setHeure((const QTime&)*((const QTime*)static_QUType_ptr.get(_o+1))); break;
    case 10: SelectDateAll(); break;
    case 11: Slot_OnReturnPressed(); break;
    case 12: Slot_OnTableDoubleClicked(); break;
    case 13: Slot_OnTableClicked(); break;
    case 14: Slot_OnTextDateChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 15: setDate((const QDate&)*((const QDate*)static_QUType_ptr.get(_o+1))); break;
    case 16: Slot_OndateChanged((QDate)(*((QDate*)static_QUType_ptr.get(_o+1)))); break;
    case 17: AdjustInterfaceToDate((const QDate&)*((const QDate*)static_QUType_ptr.get(_o+1))); break;
    case 18: static_QUType_QVariant.set(_o,QVariant(getDate())); break;
    case 19: pushButtonYearPlus_clicked(); break;
    case 20: pushButtonMonthPlus_clicked(); break;
    case 21: pushButtonYearMoins_clicked(); break;
    case 22: pushButtonMonthMoins_clicked(); break;
    case 23: comboBoxMois_activated((const QString&)static_QUType_QString.get(_o+1)); break;
    case 24: comboBoxAn_activated((const QString&)static_QUType_QString.get(_o+1)); break;
    case 25: comboBoxAn_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 26: setComboAnOnDate((const QDate&)*((const QDate*)static_QUType_ptr.get(_o+1))); break;
    case 27: setComboAnOnDate_Offset((const QDate&)*((const QDate*)static_QUType_ptr.get(_o+1)),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3)); break;
    case 28: setMenuPreselectDateOn(); break;
    case 29: setMenuPreselectDateOff(); break;
    case 30: setMenuPreSelectDate((const QStringList&)*((const QStringList*)static_QUType_ptr.get(_o+1))); break;
    case 31: Slot_pushButtonMenu_clicked(); break;
    case 32: OnMenuActivated((int)static_QUType_int.get(_o+1)); break;
    case 33: GetPopupItem(); break;
    case 34: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool Dlg_Calendar::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool Dlg_Calendar::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool Dlg_Calendar::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
