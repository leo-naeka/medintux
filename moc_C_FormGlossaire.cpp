/****************************************************************************
** C_FormGlossaire meta object code from reading C++ file 'C_FormGlossaire.h'
**
** Created: Wed May 4 22:20:13 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../C_FormGlossaire.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *C_FormGlossaire::className() const
{
    return "C_FormGlossaire";
}

QMetaObject *C_FormGlossaire::metaObj = 0;
static QMetaObjectCleanUp cleanUp_C_FormGlossaire( "C_FormGlossaire", &C_FormGlossaire::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString C_FormGlossaire::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_FormGlossaire", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString C_FormGlossaire::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_FormGlossaire", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* C_FormGlossaire::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = FormGlossaire::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "droits", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"setInterfaceOnPermisions", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "pQwdgRub", &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod slot_1 = {"OnGlossaireRubriqueActived", 1, param_slot_1 };
    static const QUMethod slot_2 = {"Slot_RestaureConnection", 0, 0 };
    static const QUMethod slot_3 = {"Slot_GlossaireRefresh", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ "path", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"SetCurrentPath", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ "path", &static_QUType_QString, 0, QUParameter::In },
	{ "defaultMaskDirectory", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"SetCurrentPath", 2, param_slot_5 };
    static const QUMethod slot_6 = {"pushButtonBack_clicked", 0, 0 };
    static const QUMethod slot_7 = {"pushButtonHome_clicked", 0, 0 };
    static const QUMethod slot_8 = {"pushButtonMenu_clicked", 0, 0 };
    static const QUMethod slot_9 = {"pushButtonNewDir_clicked", 0, 0 };
    static const QUMethod slot_10 = {"pushButtonDelDir_clicked", 0, 0 };
    static const QUParameter param_slot_11[] = {
	{ "button", &static_QUType_int, 0, QUParameter::In },
	{ "item", &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ "pos", &static_QUType_varptr, "\x0e", QUParameter::In },
	{ "c", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_11 = {"On_mouseButtonClicked", 4, param_slot_11 };
    static const QUMethod slot_12 = {"ListView_Glossaire_clicked", 0, 0 };
    static const QUParameter param_slot_13[] = {
	{ "qlistViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_13 = {"ListView_Glossaire_clicked", 1, param_slot_13 };
    static const QUParameter param_slot_14[] = {
	{ "qlistViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_14 = {"ListView_Glossaire_doubleClicked", 1, param_slot_14 };
    static const QUParameter param_slot_15[] = {
	{ "qlistViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_15 = {"ListView_Glossaire_returnPressed", 1, param_slot_15 };
    static const QUParameter param_slot_16[] = {
	{ "qlistViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_16 = {"ListView_Glossaire_selectionChanged", 1, param_slot_16 };
    static const QUMethod slot_17 = {"pushButtonEdit_clicked", 0, 0 };
    static const QUParameter param_slot_18[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_18 = {"ListView_Glossaire_contextMenuRequested", 3, param_slot_18 };
    static const QUMethod slot_19 = {"Slot_PopupActionDumy", 0, 0 };
    static const QUMethod slot_20 = {"Slot_PopupActionNewModele", 0, 0 };
    static const QUMethod slot_21 = {"Slot_PopupActionNewDoc", 0, 0 };
    static const QUMethod slot_22 = {"Slot_PopupActionAddDoc", 0, 0 };
    static const QUMethod slot_23 = {"Slot_PopupActionReplaceDoc", 0, 0 };
    static const QUMethod slot_24 = {"Slot_PopupActionEditDoc", 0, 0 };
    static const QUMethod slot_25 = {"Slot_PopupActionRenameDoc", 0, 0 };
    static const QUMethod slot_26 = {"Slot_PopupActionDeleteDoc", 0, 0 };
    static const QUMethod slot_27 = {"Slot_PopupActionRenameDir", 0, 0 };
    static const QUParameter param_slot_28[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_28 = {"OnMenuActivated", 1, param_slot_28 };
    static const QUParameter param_slot_29[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_29 = {"OnMenuHighlighted", 1, param_slot_29 };
    static const QUMethod slot_30 = {"OnMenuAboutToHide", 0, 0 };
    static const QUParameter param_slot_31[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::InOut },
	{ 0, &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod slot_31 = {"On_Sign_MouseEnter", 2, param_slot_31 };
    static const QUParameter param_slot_32[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::InOut },
	{ 0, &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod slot_32 = {"On_Sign_MouseLeave", 2, param_slot_32 };
    static const QMetaData slot_tbl[] = {
	{ "setInterfaceOnPermisions(const QString&)", &slot_0, QMetaData::Public },
	{ "OnGlossaireRubriqueActived(QWidget*)", &slot_1, QMetaData::Public },
	{ "Slot_RestaureConnection()", &slot_2, QMetaData::Public },
	{ "Slot_GlossaireRefresh()", &slot_3, QMetaData::Public },
	{ "SetCurrentPath(const QString&)", &slot_4, QMetaData::Public },
	{ "SetCurrentPath(const QString&,const QString&)", &slot_5, QMetaData::Public },
	{ "pushButtonBack_clicked()", &slot_6, QMetaData::Public },
	{ "pushButtonHome_clicked()", &slot_7, QMetaData::Public },
	{ "pushButtonMenu_clicked()", &slot_8, QMetaData::Public },
	{ "pushButtonNewDir_clicked()", &slot_9, QMetaData::Public },
	{ "pushButtonDelDir_clicked()", &slot_10, QMetaData::Public },
	{ "On_mouseButtonClicked(int,QListViewItem*,const QPoint&,int)", &slot_11, QMetaData::Public },
	{ "ListView_Glossaire_clicked()", &slot_12, QMetaData::Public },
	{ "ListView_Glossaire_clicked(QListViewItem*)", &slot_13, QMetaData::Public },
	{ "ListView_Glossaire_doubleClicked(QListViewItem*)", &slot_14, QMetaData::Public },
	{ "ListView_Glossaire_returnPressed(QListViewItem*)", &slot_15, QMetaData::Public },
	{ "ListView_Glossaire_selectionChanged(QListViewItem*)", &slot_16, QMetaData::Public },
	{ "pushButtonEdit_clicked()", &slot_17, QMetaData::Public },
	{ "ListView_Glossaire_contextMenuRequested(QListViewItem*,const QPoint&,int)", &slot_18, QMetaData::Public },
	{ "Slot_PopupActionDumy()", &slot_19, QMetaData::Public },
	{ "Slot_PopupActionNewModele()", &slot_20, QMetaData::Public },
	{ "Slot_PopupActionNewDoc()", &slot_21, QMetaData::Public },
	{ "Slot_PopupActionAddDoc()", &slot_22, QMetaData::Public },
	{ "Slot_PopupActionReplaceDoc()", &slot_23, QMetaData::Public },
	{ "Slot_PopupActionEditDoc()", &slot_24, QMetaData::Public },
	{ "Slot_PopupActionRenameDoc()", &slot_25, QMetaData::Public },
	{ "Slot_PopupActionDeleteDoc()", &slot_26, QMetaData::Public },
	{ "Slot_PopupActionRenameDir()", &slot_27, QMetaData::Public },
	{ "OnMenuActivated(int)", &slot_28, QMetaData::Public },
	{ "OnMenuHighlighted(int)", &slot_29, QMetaData::Public },
	{ "OnMenuAboutToHide()", &slot_30, QMetaData::Public },
	{ "On_Sign_MouseEnter(QString&,QString&)", &slot_31, QMetaData::Public },
	{ "On_Sign_MouseLeave(QString&,QString&)", &slot_32, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"Sign_FileSelected", 2, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"Sign_FileToEdit", 3, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"Sign_FileChanged", 2, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_3 = {"Sign_DirectoryChanged", 2, param_signal_3 };
    static const QMetaData signal_tbl[] = {
	{ "Sign_FileSelected(const char*,int)", &signal_0, QMetaData::Public },
	{ "Sign_FileToEdit(QString,QString,int)", &signal_1, QMetaData::Public },
	{ "Sign_FileChanged(const char*,int)", &signal_2, QMetaData::Public },
	{ "Sign_DirectoryChanged(const QString&,const QString&)", &signal_3, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"C_FormGlossaire", parentObject,
	slot_tbl, 33,
	signal_tbl, 4,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_C_FormGlossaire.setMetaObject( metaObj );
    return metaObj;
}

void* C_FormGlossaire::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "C_FormGlossaire" ) )
	return this;
    return FormGlossaire::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL Sign_FileSelected
void C_FormGlossaire::Sign_FileSelected( const char* t0, int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_charstar.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL Sign_FileToEdit
void C_FormGlossaire::Sign_FileToEdit( QString t0, QString t1, int t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_QString.set(o+1,t0);
    static_QUType_QString.set(o+2,t1);
    static_QUType_int.set(o+3,t2);
    activate_signal( clist, o );
}

// SIGNAL Sign_FileChanged
void C_FormGlossaire::Sign_FileChanged( const char* t0, int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_charstar.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL Sign_DirectoryChanged
void C_FormGlossaire::Sign_DirectoryChanged( const QString& t0, const QString& t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 3 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_QString.set(o+1,t0);
    static_QUType_QString.set(o+2,t1);
    activate_signal( clist, o );
}

bool C_FormGlossaire::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setInterfaceOnPermisions((const QString&)static_QUType_QString.get(_o+1)); break;
    case 1: OnGlossaireRubriqueActived((QWidget*)static_QUType_ptr.get(_o+1)); break;
    case 2: Slot_RestaureConnection(); break;
    case 3: Slot_GlossaireRefresh(); break;
    case 4: SetCurrentPath((const QString&)static_QUType_QString.get(_o+1)); break;
    case 5: SetCurrentPath((const QString&)static_QUType_QString.get(_o+1),(const QString&)static_QUType_QString.get(_o+2)); break;
    case 6: pushButtonBack_clicked(); break;
    case 7: pushButtonHome_clicked(); break;
    case 8: pushButtonMenu_clicked(); break;
    case 9: pushButtonNewDir_clicked(); break;
    case 10: pushButtonDelDir_clicked(); break;
    case 11: On_mouseButtonClicked((int)static_QUType_int.get(_o+1),(QListViewItem*)static_QUType_ptr.get(_o+2),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+3)),(int)static_QUType_int.get(_o+4)); break;
    case 12: ListView_Glossaire_clicked(); break;
    case 13: ListView_Glossaire_clicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 14: ListView_Glossaire_doubleClicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 15: ListView_Glossaire_returnPressed((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 16: ListView_Glossaire_selectionChanged((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 17: pushButtonEdit_clicked(); break;
    case 18: ListView_Glossaire_contextMenuRequested((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 19: Slot_PopupActionDumy(); break;
    case 20: Slot_PopupActionNewModele(); break;
    case 21: Slot_PopupActionNewDoc(); break;
    case 22: Slot_PopupActionAddDoc(); break;
    case 23: Slot_PopupActionReplaceDoc(); break;
    case 24: Slot_PopupActionEditDoc(); break;
    case 25: Slot_PopupActionRenameDoc(); break;
    case 26: Slot_PopupActionDeleteDoc(); break;
    case 27: Slot_PopupActionRenameDir(); break;
    case 28: OnMenuActivated((int)static_QUType_int.get(_o+1)); break;
    case 29: OnMenuHighlighted((int)static_QUType_int.get(_o+1)); break;
    case 30: OnMenuAboutToHide(); break;
    case 31: On_Sign_MouseEnter((QString&)static_QUType_QString.get(_o+1),(QString&)static_QUType_QString.get(_o+2)); break;
    case 32: On_Sign_MouseLeave((QString&)static_QUType_QString.get(_o+1),(QString&)static_QUType_QString.get(_o+2)); break;
    default:
	return FormGlossaire::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool C_FormGlossaire::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: Sign_FileSelected((const char*)static_QUType_charstar.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 1: Sign_FileToEdit((QString)static_QUType_QString.get(_o+1),(QString)static_QUType_QString.get(_o+2),(int)static_QUType_int.get(_o+3)); break;
    case 2: Sign_FileChanged((const char*)static_QUType_charstar.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 3: Sign_DirectoryChanged((const QString&)static_QUType_QString.get(_o+1),(const QString&)static_QUType_QString.get(_o+2)); break;
    default:
	return FormGlossaire::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool C_FormGlossaire::qt_property( int id, int f, QVariant* v)
{
    return FormGlossaire::qt_property( id, f, v);
}

bool C_FormGlossaire::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
