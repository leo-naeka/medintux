/****************************************************************************
** CApp meta object code from reading C++ file 'CApp.h'
**
** Created: Wed May 4 22:20:12 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../CApp.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CApp::className() const
{
    return "CApp";
}

QMetaObject *CApp::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CApp( "CApp", &CApp::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CApp::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CApp", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CApp::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CApp", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CApp::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = C_MUI_App::staticMetaObject();
    static const QUMethod slot_0 = {"Slot_FileSelected", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"Slot_OnMenuActivated", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"Slot_On_MainMenuActivated", 1, param_slot_2 };
    static const QUMethod slot_3 = {"quit", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ "pCCoolPopup", &static_QUType_ptr, "CCoolPopup", QUParameter::In }
    };
    static const QUMethod slot_4 = {"CouCouUp", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ "pCCoolPopup", &static_QUType_ptr, "CCoolPopup", QUParameter::In }
    };
    static const QUMethod slot_5 = {"CouCouStop", 1, param_slot_5 };
    static const QUMethod slot_6 = {"CouCouDestroy", 0, 0 };
    static const QUMethod slot_7 = {"Slot_popup_HierarchOptionSelected", 0, 0 };
    static const QUParameter param_slot_8[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_8 = {"Slot_popup_HierarchActivated", 1, param_slot_8 };
    static const QMetaData slot_tbl[] = {
	{ "Slot_FileSelected()", &slot_0, QMetaData::Public },
	{ "Slot_OnMenuActivated(int)", &slot_1, QMetaData::Public },
	{ "Slot_On_MainMenuActivated(int)", &slot_2, QMetaData::Public },
	{ "quit()", &slot_3, QMetaData::Public },
	{ "CouCouUp(CCoolPopup*)", &slot_4, QMetaData::Public },
	{ "CouCouStop(CCoolPopup*)", &slot_5, QMetaData::Public },
	{ "CouCouDestroy()", &slot_6, QMetaData::Public },
	{ "Slot_popup_HierarchOptionSelected()", &slot_7, QMetaData::Public },
	{ "Slot_popup_HierarchActivated(int)", &slot_8, QMetaData::Public }
    };
    static const QUMethod signal_0 = {"Sign_popup_HierarchOptionSelected", 0, 0 };
    static const QUMethod signal_1 = {"Sign_QuitterRequired", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "Sign_popup_HierarchOptionSelected()", &signal_0, QMetaData::Public },
	{ "Sign_QuitterRequired()", &signal_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"CApp", parentObject,
	slot_tbl, 9,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CApp.setMetaObject( metaObj );
    return metaObj;
}

void* CApp::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CApp" ) )
	return this;
    return C_MUI_App::qt_cast( clname );
}

// SIGNAL Sign_popup_HierarchOptionSelected
void CApp::Sign_popup_HierarchOptionSelected()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL Sign_QuitterRequired
void CApp::Sign_QuitterRequired()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

bool CApp::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: Slot_FileSelected(); break;
    case 1: Slot_OnMenuActivated((int)static_QUType_int.get(_o+1)); break;
    case 2: Slot_On_MainMenuActivated((int)static_QUType_int.get(_o+1)); break;
    case 3: quit(); break;
    case 4: CouCouUp((CCoolPopup*)static_QUType_ptr.get(_o+1)); break;
    case 5: CouCouStop((CCoolPopup*)static_QUType_ptr.get(_o+1)); break;
    case 6: CouCouDestroy(); break;
    case 7: Slot_popup_HierarchOptionSelected(); break;
    case 8: Slot_popup_HierarchActivated((int)static_QUType_int.get(_o+1)); break;
    default:
	return C_MUI_App::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CApp::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: Sign_popup_HierarchOptionSelected(); break;
    case 1: Sign_QuitterRequired(); break;
    default:
	return C_MUI_App::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool CApp::qt_property( int id, int f, QVariant* v)
{
    return C_MUI_App::qt_property( id, f, v);
}

bool CApp::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
