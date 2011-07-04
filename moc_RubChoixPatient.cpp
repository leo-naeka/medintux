/****************************************************************************
** FormRubChoixPatient meta object code from reading C++ file 'RubChoixPatient.h'
**
** Created: Wed May 4 22:20:35 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../ui/RubChoixPatient.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *FormRubChoixPatient::className() const
{
    return "FormRubChoixPatient";
}

QMetaObject *FormRubChoixPatient::metaObj = 0;
static QMetaObjectCleanUp cleanUp_FormRubChoixPatient( "FormRubChoixPatient", &FormRubChoixPatient::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString FormRubChoixPatient::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "FormRubChoixPatient", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString FormRubChoixPatient::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "FormRubChoixPatient", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* FormRubChoixPatient::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "droits", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"SetInterfaceOnDroits", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "qstr_nom", &static_QUType_QString, 0, QUParameter::In },
	{ "qstr_prenom", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"InitAllList", 2, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ "id_doss", &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"reinitList", 4, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "patient", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"Slot_SearchFor", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ "qstr_in", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"lineEditAutoLocator_textChanged", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ "qlistViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_5 = {"ListView_Patient_clicked", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "qlistViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_6 = {"ListView_Patient_selectionChanged", 1, param_slot_6 };
    static const QUMethod slot_7 = {"RestaureLastGUID", 0, 0 };
    static const QUMethod slot_8 = {"pushButtonNew_clicked", 0, 0 };
    static const QUMethod slot_9 = {"pushButtonDelete_clicked", 0, 0 };
    static const QUMethod slot_10 = {"checkBoxAutre_clicked", 0, 0 };
    static const QUMethod slot_11 = {"pushButtonInfo_clicked", 0, 0 };
    static const QUMethod slot_12 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SetInterfaceOnDroits(const QString&)", &slot_0, QMetaData::Public },
	{ "InitAllList(const QString&,const QString&)", &slot_1, QMetaData::Public },
	{ "reinitList(const char*,const char*,const char*,const char*)", &slot_2, QMetaData::Public },
	{ "Slot_SearchFor(QString)", &slot_3, QMetaData::Public },
	{ "lineEditAutoLocator_textChanged(const QString&)", &slot_4, QMetaData::Public },
	{ "ListView_Patient_clicked(QListViewItem*)", &slot_5, QMetaData::Public },
	{ "ListView_Patient_selectionChanged(QListViewItem*)", &slot_6, QMetaData::Public },
	{ "RestaureLastGUID()", &slot_7, QMetaData::Public },
	{ "pushButtonNew_clicked()", &slot_8, QMetaData::Public },
	{ "pushButtonDelete_clicked()", &slot_9, QMetaData::Public },
	{ "checkBoxAutre_clicked()", &slot_10, QMetaData::Public },
	{ "pushButtonInfo_clicked()", &slot_11, QMetaData::Public },
	{ "languageChange()", &slot_12, QMetaData::Protected }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"Sign_IdentChange", 4, param_signal_0 };
    static const QUMethod signal_1 = {"Sign_CreateNewIdent", 0, 0 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"Sign_IdentDelete", 4, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_3 = {"Sign_DrTuxExeAnother", 4, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod signal_4 = {"Sign_GetActiveGUID", 1, param_signal_4 };
    static const QMetaData signal_tbl[] = {
	{ "Sign_IdentChange(const char*,const char*,const char*,const char*)", &signal_0, QMetaData::Public },
	{ "Sign_CreateNewIdent()", &signal_1, QMetaData::Public },
	{ "Sign_IdentDelete(const char*,const char*,const char*,const char*)", &signal_2, QMetaData::Public },
	{ "Sign_DrTuxExeAnother(QString,QString,QString,QString)", &signal_3, QMetaData::Public },
	{ "Sign_GetActiveGUID(QString&)", &signal_4, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"FormRubChoixPatient", parentObject,
	slot_tbl, 13,
	signal_tbl, 5,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_FormRubChoixPatient.setMetaObject( metaObj );
    return metaObj;
}

void* FormRubChoixPatient::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "FormRubChoixPatient" ) )
	return this;
    return QWidget::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL Sign_IdentChange
void FormRubChoixPatient::Sign_IdentChange( const char* t0, const char* t1, const char* t2, const char* t3 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[5];
    static_QUType_charstar.set(o+1,t0);
    static_QUType_charstar.set(o+2,t1);
    static_QUType_charstar.set(o+3,t2);
    static_QUType_charstar.set(o+4,t3);
    activate_signal( clist, o );
}

// SIGNAL Sign_CreateNewIdent
void FormRubChoixPatient::Sign_CreateNewIdent()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

// SIGNAL Sign_IdentDelete
void FormRubChoixPatient::Sign_IdentDelete( const char* t0, const char* t1, const char* t2, const char* t3 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[5];
    static_QUType_charstar.set(o+1,t0);
    static_QUType_charstar.set(o+2,t1);
    static_QUType_charstar.set(o+3,t2);
    static_QUType_charstar.set(o+4,t3);
    activate_signal( clist, o );
}

// SIGNAL Sign_DrTuxExeAnother
void FormRubChoixPatient::Sign_DrTuxExeAnother( QString t0, QString t1, QString t2, QString t3 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 3 );
    if ( !clist )
	return;
    QUObject o[5];
    static_QUType_QString.set(o+1,t0);
    static_QUType_QString.set(o+2,t1);
    static_QUType_QString.set(o+3,t2);
    static_QUType_QString.set(o+4,t3);
    activate_signal( clist, o );
}

// SIGNAL Sign_GetActiveGUID
void FormRubChoixPatient::Sign_GetActiveGUID( QString& t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 4 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_QString.set(o+1,t0);
    activate_signal( clist, o );
    t0 = static_QUType_QString.get(o+1);
}

bool FormRubChoixPatient::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SetInterfaceOnDroits((const QString&)static_QUType_QString.get(_o+1)); break;
    case 1: InitAllList((const QString&)static_QUType_QString.get(_o+1),(const QString&)static_QUType_QString.get(_o+2)); break;
    case 2: reinitList((const char*)static_QUType_charstar.get(_o+1),(const char*)static_QUType_charstar.get(_o+2),(const char*)static_QUType_charstar.get(_o+3),(const char*)static_QUType_charstar.get(_o+4)); break;
    case 3: Slot_SearchFor((QString)static_QUType_QString.get(_o+1)); break;
    case 4: lineEditAutoLocator_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 5: ListView_Patient_clicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 6: ListView_Patient_selectionChanged((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 7: RestaureLastGUID(); break;
    case 8: pushButtonNew_clicked(); break;
    case 9: pushButtonDelete_clicked(); break;
    case 10: checkBoxAutre_clicked(); break;
    case 11: pushButtonInfo_clicked(); break;
    case 12: languageChange(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool FormRubChoixPatient::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: Sign_IdentChange((const char*)static_QUType_charstar.get(_o+1),(const char*)static_QUType_charstar.get(_o+2),(const char*)static_QUType_charstar.get(_o+3),(const char*)static_QUType_charstar.get(_o+4)); break;
    case 1: Sign_CreateNewIdent(); break;
    case 2: Sign_IdentDelete((const char*)static_QUType_charstar.get(_o+1),(const char*)static_QUType_charstar.get(_o+2),(const char*)static_QUType_charstar.get(_o+3),(const char*)static_QUType_charstar.get(_o+4)); break;
    case 3: Sign_DrTuxExeAnother((QString)static_QUType_QString.get(_o+1),(QString)static_QUType_QString.get(_o+2),(QString)static_QUType_QString.get(_o+3),(QString)static_QUType_QString.get(_o+4)); break;
    case 4: Sign_GetActiveGUID((QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool FormRubChoixPatient::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool FormRubChoixPatient::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
