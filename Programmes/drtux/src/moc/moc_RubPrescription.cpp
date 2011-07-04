/****************************************************************************
** FormRubPrescription meta object code from reading C++ file 'RubPrescription.h'
**
** Created: Wed May 4 22:20:36 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../ui/RubPrescription.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *FormRubPrescription::className() const
{
    return "FormRubPrescription";
}

QMetaObject *FormRubPrescription::metaObj = 0;
static QMetaObjectCleanUp cleanUp_FormRubPrescription( "FormRubPrescription", &FormRubPrescription::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString FormRubPrescription::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "FormRubPrescription", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString FormRubPrescription::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "FormRubPrescription", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* FormRubPrescription::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"pushButtonPlus_clicked", 0, 0 };
    static const QUMethod slot_1 = {"On_buttonDragClicked", 0, 0 };
    static const QUMethod slot_2 = {"pushButtonByPrincipe_clicked", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"listView_Produits_rightButtonClicked", 3, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"OnMenuActivated", 1, param_slot_4 };
    static const QUMethod slot_5 = {"GetPopupItem", 0, 0 };
    static const QUParameter param_slot_6[] = {
	{ "state", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"SetModifiableState", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ "pMyEditText", &static_QUType_ptr, "MyEditText", QUParameter::In }
    };
    static const QUMethod slot_7 = {"InitText", 1, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ 0, &static_QUType_ptr, "QObject", QUParameter::In }
    };
    static const QUMethod slot_8 = {"FormPatientList_destroyed", 1, param_slot_8 };
    static const QUParameter param_slot_9[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out }
    };
    static const QUMethod slot_9 = {"SetData", 1, param_slot_9 };
    static const QUParameter param_slot_10[] = {
	{ "item", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_10 = {"comboBox_RubName_highlighted", 1, param_slot_10 };
    static const QUParameter param_slot_11[] = {
	{ "item", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_11 = {"comboBox_RubName_activated", 1, param_slot_11 };
    static const QUParameter param_slot_12[] = {
	{ "it", &static_QUType_ptr, "RUBREC_LIST::iterator", QUParameter::In }
    };
    static const QUMethod slot_12 = {"PutDataInRubList", 1, param_slot_12 };
    static const QUMethod slot_13 = {"pushButtonDelete_clicked", 0, 0 };
    static const QUMethod slot_14 = {"pushButtonSave_clicked", 0, 0 };
    static const QUMethod slot_15 = {"pushButtonVidal_clicked", 0, 0 };
    static const QUMethod slot_16 = {"pushButtonRubDateChange_clicked", 0, 0 };
    static const QUParameter param_slot_17[] = {
	{ "name", &static_QUType_QString, 0, QUParameter::In },
	{ "date", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_17 = {"SetRubDateName", 2, param_slot_17 };
    static const QUMethod slot_18 = {"SaveTextInRubList", 0, 0 };
    static const QUMethod slot_19 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "pushButtonPlus_clicked()", &slot_0, QMetaData::Public },
	{ "On_buttonDragClicked()", &slot_1, QMetaData::Public },
	{ "pushButtonByPrincipe_clicked()", &slot_2, QMetaData::Public },
	{ "listView_Produits_rightButtonClicked(QListViewItem*,const QPoint&,int)", &slot_3, QMetaData::Public },
	{ "OnMenuActivated(int)", &slot_4, QMetaData::Public },
	{ "GetPopupItem()", &slot_5, QMetaData::Public },
	{ "SetModifiableState(int)", &slot_6, QMetaData::Public },
	{ "InitText(MyEditText*)", &slot_7, QMetaData::Public },
	{ "FormPatientList_destroyed(QObject*)", &slot_8, QMetaData::Public },
	{ "SetData()", &slot_9, QMetaData::Public },
	{ "comboBox_RubName_highlighted(int)", &slot_10, QMetaData::Public },
	{ "comboBox_RubName_activated(int)", &slot_11, QMetaData::Public },
	{ "PutDataInRubList(RUBREC_LIST::iterator)", &slot_12, QMetaData::Public },
	{ "pushButtonDelete_clicked()", &slot_13, QMetaData::Public },
	{ "pushButtonSave_clicked()", &slot_14, QMetaData::Public },
	{ "pushButtonVidal_clicked()", &slot_15, QMetaData::Public },
	{ "pushButtonRubDateChange_clicked()", &slot_16, QMetaData::Public },
	{ "SetRubDateName(const QString&,const QString&)", &slot_17, QMetaData::Public },
	{ "SaveTextInRubList()", &slot_18, QMetaData::Public },
	{ "languageChange()", &slot_19, QMetaData::Protected }
    };
    static const QUMethod signal_0 = {"Sign_SaveButtonClicked", 0, 0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_ptr, "RUBREC_LIST::iterator", QUParameter::In }
    };
    static const QUMethod signal_1 = {"Sign_RubChanged", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_ptr, "RUBREC_LIST::iterator", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x1c", QUParameter::InOut },
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"Sign_DuplicateData", 4, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_ptr, "RUBREC_LIST::iterator", QUParameter::In }
    };
    static const QUMethod signal_3 = {"Sign_PutPrescriptionInTerrain", 1, param_signal_3 };
    static const QUMethod signal_4 = {"Sign_Renouveler_TTT_Fond", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "Sign_SaveButtonClicked()", &signal_0, QMetaData::Public },
	{ "Sign_RubChanged(RUBREC_LIST::iterator)", &signal_1, QMetaData::Public },
	{ "Sign_DuplicateData(RUBREC_LIST::iterator,QDateTime&,const QString&,const QString&)", &signal_2, QMetaData::Public },
	{ "Sign_PutPrescriptionInTerrain(RUBREC_LIST::iterator)", &signal_3, QMetaData::Public },
	{ "Sign_Renouveler_TTT_Fond()", &signal_4, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"FormRubPrescription", parentObject,
	slot_tbl, 20,
	signal_tbl, 5,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_FormRubPrescription.setMetaObject( metaObj );
    return metaObj;
}

void* FormRubPrescription::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "FormRubPrescription" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL Sign_SaveButtonClicked
void FormRubPrescription::Sign_SaveButtonClicked()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL Sign_RubChanged
void FormRubPrescription::Sign_RubChanged( RUBREC_LIST::iterator t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL Sign_DuplicateData
void FormRubPrescription::Sign_DuplicateData( RUBREC_LIST::iterator t0, QDateTime& t1, const QString& t2, const QString& t3 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[5];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_varptr.set(o+2,&t1);
    static_QUType_QString.set(o+3,t2);
    static_QUType_QString.set(o+4,t3);
    activate_signal( clist, o );
}

// SIGNAL Sign_PutPrescriptionInTerrain
void FormRubPrescription::Sign_PutPrescriptionInTerrain( RUBREC_LIST::iterator t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 3 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL Sign_Renouveler_TTT_Fond
void FormRubPrescription::Sign_Renouveler_TTT_Fond()
{
    activate_signal( staticMetaObject()->signalOffset() + 4 );
}

bool FormRubPrescription::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: pushButtonPlus_clicked(); break;
    case 1: On_buttonDragClicked(); break;
    case 2: pushButtonByPrincipe_clicked(); break;
    case 3: listView_Produits_rightButtonClicked((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 4: OnMenuActivated((int)static_QUType_int.get(_o+1)); break;
    case 5: GetPopupItem(); break;
    case 6: SetModifiableState((int)static_QUType_int.get(_o+1)); break;
    case 7: InitText((MyEditText*)static_QUType_ptr.get(_o+1)); break;
    case 8: FormPatientList_destroyed((QObject*)static_QUType_ptr.get(_o+1)); break;
    case 9: static_QUType_int.set(_o,SetData()); break;
    case 10: comboBox_RubName_highlighted((int)static_QUType_int.get(_o+1)); break;
    case 11: comboBox_RubName_activated((int)static_QUType_int.get(_o+1)); break;
    case 12: PutDataInRubList((RUBREC_LIST::iterator)(*((RUBREC_LIST::iterator*)static_QUType_ptr.get(_o+1)))); break;
    case 13: pushButtonDelete_clicked(); break;
    case 14: pushButtonSave_clicked(); break;
    case 15: pushButtonVidal_clicked(); break;
    case 16: pushButtonRubDateChange_clicked(); break;
    case 17: SetRubDateName((const QString&)static_QUType_QString.get(_o+1),(const QString&)static_QUType_QString.get(_o+2)); break;
    case 18: SaveTextInRubList(); break;
    case 19: languageChange(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool FormRubPrescription::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: Sign_SaveButtonClicked(); break;
    case 1: Sign_RubChanged((RUBREC_LIST::iterator)(*((RUBREC_LIST::iterator*)static_QUType_ptr.get(_o+1)))); break;
    case 2: Sign_DuplicateData((RUBREC_LIST::iterator)(*((RUBREC_LIST::iterator*)static_QUType_ptr.get(_o+1))),(QDateTime&)*((QDateTime*)static_QUType_ptr.get(_o+2)),(const QString&)static_QUType_QString.get(_o+3),(const QString&)static_QUType_QString.get(_o+4)); break;
    case 3: Sign_PutPrescriptionInTerrain((RUBREC_LIST::iterator)(*((RUBREC_LIST::iterator*)static_QUType_ptr.get(_o+1)))); break;
    case 4: Sign_Renouveler_TTT_Fond(); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool FormRubPrescription::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool FormRubPrescription::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
