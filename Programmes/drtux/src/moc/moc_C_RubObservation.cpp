/****************************************************************************
** C_RubObservation meta object code from reading C++ file 'C_RubObservation.h'
**
** Created: Wed May 4 22:20:33 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../C_RubObservation.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *C_RubObservation::className() const
{
    return "C_RubObservation";
}

QMetaObject *C_RubObservation::metaObj = 0;
static QMetaObjectCleanUp cleanUp_C_RubObservation( "C_RubObservation", &C_RubObservation::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString C_RubObservation::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_RubObservation", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString C_RubObservation::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_RubObservation", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* C_RubObservation::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"languageChange", 0, 0 };
    static const QUMethod slot_1 = {"SaveTextInRubList", 0, 0 };
    static const QUMethod slot_2 = {"pushButtonRubDateChange_clicked", 0, 0 };
    static const QUMethod slot_3 = {"pushButtonSave_clicked", 0, 0 };
    static const QUMethod slot_4 = {"pushButtonDelete_clicked", 0, 0 };
    static const QUParameter param_slot_5[] = {
	{ "item", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"comboBox_RubName_activated", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "item", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"comboBox_RubName_highlighted", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ 0, &static_QUType_ptr, "QObject", QUParameter::In }
    };
    static const QUMethod slot_7 = {"FormPatientList_destroyed", 1, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ "state", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_8 = {"SetModifiableState", 1, param_slot_8 };
    static const QUMethod slot_9 = {"On_buttonDragClicked", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "languageChange()", &slot_0, QMetaData::Protected },
	{ "SaveTextInRubList()", &slot_1, QMetaData::Public },
	{ "pushButtonRubDateChange_clicked()", &slot_2, QMetaData::Public },
	{ "pushButtonSave_clicked()", &slot_3, QMetaData::Public },
	{ "pushButtonDelete_clicked()", &slot_4, QMetaData::Public },
	{ "comboBox_RubName_activated(int)", &slot_5, QMetaData::Public },
	{ "comboBox_RubName_highlighted(int)", &slot_6, QMetaData::Public },
	{ "FormPatientList_destroyed(QObject*)", &slot_7, QMetaData::Public },
	{ "SetModifiableState(int)", &slot_8, QMetaData::Public },
	{ "On_buttonDragClicked()", &slot_9, QMetaData::Public }
    };
    static const QUMethod signal_0 = {"Sign_SaveButtonClicked", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "Sign_SaveButtonClicked()", &signal_0, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"C_RubObservation", parentObject,
	slot_tbl, 10,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_C_RubObservation.setMetaObject( metaObj );
    return metaObj;
}

void* C_RubObservation::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "C_RubObservation" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL Sign_SaveButtonClicked
void C_RubObservation::Sign_SaveButtonClicked()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

bool C_RubObservation::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: languageChange(); break;
    case 1: SaveTextInRubList(); break;
    case 2: pushButtonRubDateChange_clicked(); break;
    case 3: pushButtonSave_clicked(); break;
    case 4: pushButtonDelete_clicked(); break;
    case 5: comboBox_RubName_activated((int)static_QUType_int.get(_o+1)); break;
    case 6: comboBox_RubName_highlighted((int)static_QUType_int.get(_o+1)); break;
    case 7: FormPatientList_destroyed((QObject*)static_QUType_ptr.get(_o+1)); break;
    case 8: SetModifiableState((int)static_QUType_int.get(_o+1)); break;
    case 9: On_buttonDragClicked(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool C_RubObservation::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: Sign_SaveButtonClicked(); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool C_RubObservation::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool C_RubObservation::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
