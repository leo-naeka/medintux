/****************************************************************************
** CMyThemePopup meta object code from reading C++ file 'MyEditText.h'
**
** Created: Wed May 4 22:20:14 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../MyEditText.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CMyThemePopup::className() const
{
    return "CMyThemePopup";
}

QMetaObject *CMyThemePopup::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CMyThemePopup( "CMyThemePopup", &CMyThemePopup::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CMyThemePopup::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CMyThemePopup", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CMyThemePopup::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CMyThemePopup", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CMyThemePopup::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ThemePopup::staticMetaObject();
    static const QUMethod signal_0 = {"Sign_MouseOutPopup", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "Sign_MouseOutPopup()", &signal_0, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"CMyThemePopup", parentObject,
	0, 0,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CMyThemePopup.setMetaObject( metaObj );
    return metaObj;
}

void* CMyThemePopup::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CMyThemePopup" ) )
	return this;
    return ThemePopup::qt_cast( clname );
}

// SIGNAL Sign_MouseOutPopup
void CMyThemePopup::Sign_MouseOutPopup()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

bool CMyThemePopup::qt_invoke( int _id, QUObject* _o )
{
    return ThemePopup::qt_invoke(_id,_o);
}

bool CMyThemePopup::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: Sign_MouseOutPopup(); break;
    default:
	return ThemePopup::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool CMyThemePopup::qt_property( int id, int f, QVariant* v)
{
    return ThemePopup::qt_property( id, f, v);
}

bool CMyThemePopup::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *CMyBulleWidget::className() const
{
    return "CMyBulleWidget";
}

QMetaObject *CMyBulleWidget::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CMyBulleWidget( "CMyBulleWidget", &CMyBulleWidget::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CMyBulleWidget::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CMyBulleWidget", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CMyBulleWidget::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CMyBulleWidget", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CMyBulleWidget::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"CMyBulleWidget", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CMyBulleWidget.setMetaObject( metaObj );
    return metaObj;
}

void* CMyBulleWidget::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CMyBulleWidget" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool CMyBulleWidget::qt_invoke( int _id, QUObject* _o )
{
    return QWidget::qt_invoke(_id,_o);
}

bool CMyBulleWidget::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool CMyBulleWidget::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool CMyBulleWidget::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


#include <qvariant.h>
const char *MyEditText::className() const
{
    return "MyEditText";
}

QMetaObject *MyEditText::metaObj = 0;
static QMetaObjectCleanUp cleanUp_MyEditText( "MyEditText", &MyEditText::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString MyEditText::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MyEditText", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString MyEditText::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MyEditText", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* MyEditText::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QTextEdit::staticMetaObject();
    static const QUMethod slot_0 = {"CouCou", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ "zoom", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"SetZoom", 1, param_slot_1 };
    static const QUMethod slot_2 = {"del", 0, 0 };
    static const QUMethod slot_3 = {"cut", 0, 0 };
    static const QUMethod slot_4 = {"paste", 0, 0 };
    static const QUParameter param_slot_5[] = {
	{ "ptr", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"setText", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "txt", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"setText", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::Out }
    };
    static const QUMethod slot_7 = {"getText", 1, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::Out },
	{ "pCRubRecord", &static_QUType_ptr, "CRubRecord", QUParameter::In }
    };
    static const QUMethod slot_8 = {"getText", 2, param_slot_8 };
    static const QUParameter param_slot_9[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::Out }
    };
    static const QUMethod slot_9 = {"getText_IfTypeIsDocuments", 1, param_slot_9 };
    static const QUParameter param_slot_10[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::Out },
	{ "len", &static_QUType_varptr, "\x10", QUParameter::In }
    };
    static const QUMethod slot_10 = {"getText_IfTypeIsDocuments", 2, param_slot_10 };
    static const QUParameter param_slot_11[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::Out },
	{ "pCRubRecord", &static_QUType_ptr, "CRubRecord", QUParameter::In }
    };
    static const QUMethod slot_11 = {"getText_IfTypeIsOrdoCalc", 2, param_slot_11 };
    static const QUParameter param_slot_12[] = {
	{ 0, &static_QUType_ptr, "QPixmap", QUParameter::Out },
	{ "in", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_12 = {"decodeStringTo_pQPixmap", 2, param_slot_12 };
    static const QUParameter param_slot_13[] = {
	{ 0, &static_QUType_QVariant, "\x06", QUParameter::Out },
	{ "in", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_13 = {"decodeStringTo_QPixmap", 2, param_slot_13 };
    static const QUParameter param_slot_14[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::Out },
	{ "pixIn", &static_QUType_varptr, "\x06", QUParameter::In }
    };
    static const QUMethod slot_14 = {"encodePixmapToBase64", 2, param_slot_14 };
    static const QUParameter param_slot_15[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::Out },
	{ "pQPixmap", &static_QUType_varptr, "\x06", QUParameter::In }
    };
    static const QUMethod slot_15 = {"encodePixmapToBase64", 2, param_slot_15 };
    static const QUMethod slot_16 = {"UpdateMenu", 0, 0 };
    static const QUParameter param_slot_17[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out }
    };
    static const QUMethod slot_17 = {"TotalCacheCreator", 1, param_slot_17 };
    static const QUMethod slot_18 = {"ListManager", 0, 0 };
    static const QUMethod slot_19 = {"PasteListItem", 0, 0 };
    static const QUMethod slot_20 = {"PasteFolderItem", 0, 0 };
    static const QUParameter param_slot_21[] = {
	{ "ext", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_21 = {"PasteTextItem", 1, param_slot_21 };
    static const QUParameter param_slot_22[] = {
	{ "path", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_22 = {"PasteFileItem", 1, param_slot_22 };
    static const QUMethod slot_23 = {"PopupItemFusionItem", 0, 0 };
    static const QUMethod slot_24 = {"PopupItemAddItem", 0, 0 };
    static const QUMethod slot_25 = {"PopupCreateList", 0, 0 };
    static const QUMethod slot_26 = {"PopupItemExeCustomItem", 0, 0 };
    static const QUMethod slot_27 = {"OnMenuAboutToHide", 0, 0 };
    static const QUParameter param_slot_28[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_28 = {"OnMenuActivated", 1, param_slot_28 };
    static const QUParameter param_slot_29[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_29 = {"OnMenuHighlighted", 1, param_slot_29 };
    static const QUMethod slot_30 = {"TimedDestroyMenuBulle", 0, 0 };
    static const QUMethod slot_31 = {"PopupItemModifierImage", 0, 0 };
    static const QUMethod slot_32 = {"PopupItemSaveImage", 0, 0 };
    static const QUMethod slot_33 = {"Slot_PopupActionDumy", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "CouCou()", &slot_0, QMetaData::Public },
	{ "SetZoom(int)", &slot_1, QMetaData::Public },
	{ "del()", &slot_2, QMetaData::Public },
	{ "cut()", &slot_3, QMetaData::Public },
	{ "paste()", &slot_4, QMetaData::Public },
	{ "setText(const char*)", &slot_5, QMetaData::Public },
	{ "setText(const QString&)", &slot_6, QMetaData::Public },
	{ "getText()", &slot_7, QMetaData::Public },
	{ "getText(CRubRecord*)", &slot_8, QMetaData::Public },
	{ "getText_IfTypeIsDocuments()", &slot_9, QMetaData::Public },
	{ "getText_IfTypeIsDocuments(int*)", &slot_10, QMetaData::Public },
	{ "getText_IfTypeIsOrdoCalc(CRubRecord*)", &slot_11, QMetaData::Public },
	{ "decodeStringTo_pQPixmap(const QString&)", &slot_12, QMetaData::Public },
	{ "decodeStringTo_QPixmap(const QString&)", &slot_13, QMetaData::Public },
	{ "encodePixmapToBase64(const QPixmap&)", &slot_14, QMetaData::Public },
	{ "encodePixmapToBase64(QPixmap*)", &slot_15, QMetaData::Public },
	{ "UpdateMenu()", &slot_16, QMetaData::Public },
	{ "TotalCacheCreator()", &slot_17, QMetaData::Public },
	{ "ListManager()", &slot_18, QMetaData::Public },
	{ "PasteListItem()", &slot_19, QMetaData::Public },
	{ "PasteFolderItem()", &slot_20, QMetaData::Public },
	{ "PasteTextItem(const QString&)", &slot_21, QMetaData::Public },
	{ "PasteFileItem(QString)", &slot_22, QMetaData::Public },
	{ "PopupItemFusionItem()", &slot_23, QMetaData::Public },
	{ "PopupItemAddItem()", &slot_24, QMetaData::Public },
	{ "PopupCreateList()", &slot_25, QMetaData::Public },
	{ "PopupItemExeCustomItem()", &slot_26, QMetaData::Public },
	{ "OnMenuAboutToHide()", &slot_27, QMetaData::Public },
	{ "OnMenuActivated(int)", &slot_28, QMetaData::Public },
	{ "OnMenuHighlighted(int)", &slot_29, QMetaData::Public },
	{ "TimedDestroyMenuBulle()", &slot_30, QMetaData::Public },
	{ "PopupItemModifierImage()", &slot_31, QMetaData::Public },
	{ "PopupItemSaveImage()", &slot_32, QMetaData::Public },
	{ "Slot_PopupActionDumy()", &slot_33, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"message", 2, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod signal_1 = {"Sign_ExeCommand", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod signal_2 = {"Sign_Exe_Plugin", 1, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod signal_3 = {"Sign_Exe_Mixture", 1, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_4 = {"Signal_Key_Delete_Pressed", 1, param_signal_4 };
    static const QUParameter param_signal_5[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_5 = {"Signal_Key_Backspace_Pressed", 1, param_signal_5 };
    static const QUMethod signal_6 = {"Signal_Del_Before", 0, 0 };
    static const QUMethod signal_7 = {"Signal_Del_After", 0, 0 };
    static const QUMethod signal_8 = {"Signal_Cut_Before", 0, 0 };
    static const QUMethod signal_9 = {"Signal_Cut_After", 0, 0 };
    static const QUMethod signal_10 = {"Signal_Paste_Before", 0, 0 };
    static const QUMethod signal_11 = {"Signal_Paste_After", 0, 0 };
    static const QUMethod signal_12 = {"Signal_Replace_Before", 0, 0 };
    static const QUMethod signal_13 = {"Signal_Replace_After", 0, 0 };
    static const QUParameter param_signal_14[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::InOut },
	{ 0, &static_QUType_QString, 0, QUParameter::InOut },
	{ 0, &static_QUType_varptr, "\x1f", QUParameter::InOut }
    };
    static const QUMethod signal_14 = {"Sign_Get_Custom_Menu", 4, param_signal_14 };
    static const QMetaData signal_tbl[] = {
	{ "message(const QString&,int)", &signal_0, QMetaData::Protected },
	{ "Sign_ExeCommand(QString&)", &signal_1, QMetaData::Protected },
	{ "Sign_Exe_Plugin(QString&)", &signal_2, QMetaData::Protected },
	{ "Sign_Exe_Mixture(QString&)", &signal_3, QMetaData::Protected },
	{ "Signal_Key_Delete_Pressed(int)", &signal_4, QMetaData::Protected },
	{ "Signal_Key_Backspace_Pressed(int)", &signal_5, QMetaData::Protected },
	{ "Signal_Del_Before()", &signal_6, QMetaData::Protected },
	{ "Signal_Del_After()", &signal_7, QMetaData::Protected },
	{ "Signal_Cut_Before()", &signal_8, QMetaData::Protected },
	{ "Signal_Cut_After()", &signal_9, QMetaData::Protected },
	{ "Signal_Paste_Before()", &signal_10, QMetaData::Protected },
	{ "Signal_Paste_After()", &signal_11, QMetaData::Protected },
	{ "Signal_Replace_Before()", &signal_12, QMetaData::Protected },
	{ "Signal_Replace_After()", &signal_13, QMetaData::Protected },
	{ "Sign_Get_Custom_Menu(const QString&,QString&,QString&,QKeySequence&)", &signal_14, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"MyEditText", parentObject,
	slot_tbl, 34,
	signal_tbl, 15,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_MyEditText.setMetaObject( metaObj );
    return metaObj;
}

void* MyEditText::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "MyEditText" ) )
	return this;
    return QTextEdit::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL message
void MyEditText::message( const QString& t0, int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_QString.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL Sign_ExeCommand
void MyEditText::Sign_ExeCommand( QString& t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_QString.set(o+1,t0);
    activate_signal( clist, o );
    t0 = static_QUType_QString.get(o+1);
}

// SIGNAL Sign_Exe_Plugin
void MyEditText::Sign_Exe_Plugin( QString& t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_QString.set(o+1,t0);
    activate_signal( clist, o );
    t0 = static_QUType_QString.get(o+1);
}

// SIGNAL Sign_Exe_Mixture
void MyEditText::Sign_Exe_Mixture( QString& t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 3 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_QString.set(o+1,t0);
    activate_signal( clist, o );
    t0 = static_QUType_QString.get(o+1);
}

// SIGNAL Signal_Key_Delete_Pressed
void MyEditText::Signal_Key_Delete_Pressed( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 4, t0 );
}

// SIGNAL Signal_Key_Backspace_Pressed
void MyEditText::Signal_Key_Backspace_Pressed( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 5, t0 );
}

// SIGNAL Signal_Del_Before
void MyEditText::Signal_Del_Before()
{
    activate_signal( staticMetaObject()->signalOffset() + 6 );
}

// SIGNAL Signal_Del_After
void MyEditText::Signal_Del_After()
{
    activate_signal( staticMetaObject()->signalOffset() + 7 );
}

// SIGNAL Signal_Cut_Before
void MyEditText::Signal_Cut_Before()
{
    activate_signal( staticMetaObject()->signalOffset() + 8 );
}

// SIGNAL Signal_Cut_After
void MyEditText::Signal_Cut_After()
{
    activate_signal( staticMetaObject()->signalOffset() + 9 );
}

// SIGNAL Signal_Paste_Before
void MyEditText::Signal_Paste_Before()
{
    activate_signal( staticMetaObject()->signalOffset() + 10 );
}

// SIGNAL Signal_Paste_After
void MyEditText::Signal_Paste_After()
{
    activate_signal( staticMetaObject()->signalOffset() + 11 );
}

// SIGNAL Signal_Replace_Before
void MyEditText::Signal_Replace_Before()
{
    activate_signal( staticMetaObject()->signalOffset() + 12 );
}

// SIGNAL Signal_Replace_After
void MyEditText::Signal_Replace_After()
{
    activate_signal( staticMetaObject()->signalOffset() + 13 );
}

// SIGNAL Sign_Get_Custom_Menu
void MyEditText::Sign_Get_Custom_Menu( const QString& t0, QString& t1, QString& t2, QKeySequence& t3 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 14 );
    if ( !clist )
	return;
    QUObject o[5];
    static_QUType_QString.set(o+1,t0);
    static_QUType_QString.set(o+2,t1);
    static_QUType_QString.set(o+3,t2);
    static_QUType_varptr.set(o+4,&t3);
    activate_signal( clist, o );
    t1 = static_QUType_QString.get(o+2);
    t2 = static_QUType_QString.get(o+3);
}

bool MyEditText::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: CouCou(); break;
    case 1: SetZoom((int)static_QUType_int.get(_o+1)); break;
    case 2: del(); break;
    case 3: cut(); break;
    case 4: paste(); break;
    case 5: setText((const char*)static_QUType_charstar.get(_o+1)); break;
    case 6: setText((const QString&)static_QUType_QString.get(_o+1)); break;
    case 7: static_QUType_QString.set(_o,getText()); break;
    case 8: static_QUType_QString.set(_o,getText((CRubRecord*)static_QUType_ptr.get(_o+1))); break;
    case 9: static_QUType_QString.set(_o,getText_IfTypeIsDocuments()); break;
    case 10: static_QUType_QString.set(_o,getText_IfTypeIsDocuments((int*)static_QUType_varptr.get(_o+1))); break;
    case 11: static_QUType_QString.set(_o,getText_IfTypeIsOrdoCalc((CRubRecord*)static_QUType_ptr.get(_o+1))); break;
    case 12: static_QUType_ptr.set(_o,decodeStringTo_pQPixmap((const QString&)static_QUType_QString.get(_o+1))); break;
    case 13: static_QUType_QVariant.set(_o,QVariant(decodeStringTo_QPixmap((const QString&)static_QUType_QString.get(_o+1)))); break;
    case 14: static_QUType_QString.set(_o,encodePixmapToBase64((const QPixmap&)*((const QPixmap*)static_QUType_ptr.get(_o+1)))); break;
    case 15: static_QUType_QString.set(_o,encodePixmapToBase64((QPixmap*)static_QUType_varptr.get(_o+1))); break;
    case 16: UpdateMenu(); break;
    case 17: static_QUType_int.set(_o,TotalCacheCreator()); break;
    case 18: ListManager(); break;
    case 19: PasteListItem(); break;
    case 20: PasteFolderItem(); break;
    case 21: PasteTextItem((const QString&)static_QUType_QString.get(_o+1)); break;
    case 22: PasteFileItem((QString)static_QUType_QString.get(_o+1)); break;
    case 23: PopupItemFusionItem(); break;
    case 24: PopupItemAddItem(); break;
    case 25: PopupCreateList(); break;
    case 26: PopupItemExeCustomItem(); break;
    case 27: OnMenuAboutToHide(); break;
    case 28: OnMenuActivated((int)static_QUType_int.get(_o+1)); break;
    case 29: OnMenuHighlighted((int)static_QUType_int.get(_o+1)); break;
    case 30: TimedDestroyMenuBulle(); break;
    case 31: PopupItemModifierImage(); break;
    case 32: PopupItemSaveImage(); break;
    case 33: Slot_PopupActionDumy(); break;
    default:
	return QTextEdit::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool MyEditText::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: message((const QString&)static_QUType_QString.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 1: Sign_ExeCommand((QString&)static_QUType_QString.get(_o+1)); break;
    case 2: Sign_Exe_Plugin((QString&)static_QUType_QString.get(_o+1)); break;
    case 3: Sign_Exe_Mixture((QString&)static_QUType_QString.get(_o+1)); break;
    case 4: Signal_Key_Delete_Pressed((int)static_QUType_int.get(_o+1)); break;
    case 5: Signal_Key_Backspace_Pressed((int)static_QUType_int.get(_o+1)); break;
    case 6: Signal_Del_Before(); break;
    case 7: Signal_Del_After(); break;
    case 8: Signal_Cut_Before(); break;
    case 9: Signal_Cut_After(); break;
    case 10: Signal_Paste_Before(); break;
    case 11: Signal_Paste_After(); break;
    case 12: Signal_Replace_Before(); break;
    case 13: Signal_Replace_After(); break;
    case 14: Sign_Get_Custom_Menu((const QString&)static_QUType_QString.get(_o+1),(QString&)static_QUType_QString.get(_o+2),(QString&)static_QUType_QString.get(_o+3),(QKeySequence&)*((QKeySequence*)static_QUType_ptr.get(_o+4))); break;
    default:
	return QTextEdit::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool MyEditText::qt_property( int id, int f, QVariant* v)
{
    return QTextEdit::qt_property( id, f, v);
}

bool MyEditText::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
