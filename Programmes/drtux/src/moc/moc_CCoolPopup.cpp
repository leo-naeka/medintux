/****************************************************************************
** C_MyLabel meta object code from reading C++ file 'CCoolPopup.h'
**
** Created: Wed May 4 22:20:21 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../../../MedinTuxTools/CCoolPopup.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *C_MyLabel::className() const
{
    return "C_MyLabel";
}

QMetaObject *C_MyLabel::metaObj = 0;
static QMetaObjectCleanUp cleanUp_C_MyLabel( "C_MyLabel", &C_MyLabel::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString C_MyLabel::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_MyLabel", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString C_MyLabel::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_MyLabel", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* C_MyLabel::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"C_MyLabel", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_C_MyLabel.setMetaObject( metaObj );
    return metaObj;
}

void* C_MyLabel::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "C_MyLabel" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool C_MyLabel::qt_invoke( int _id, QUObject* _o )
{
    return QWidget::qt_invoke(_id,_o);
}

bool C_MyLabel::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool C_MyLabel::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool C_MyLabel::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *CCoolPopup::className() const
{
    return "CCoolPopup";
}

QMetaObject *CCoolPopup::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CCoolPopup( "CCoolPopup", &CCoolPopup::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CCoolPopup::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CCoolPopup", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CCoolPopup::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CCoolPopup", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CCoolPopup::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"Appear", 0, 0 };
    static const QUMethod slot_1 = {"Disappear", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ "ft", &static_QUType_varptr, "\x05", QUParameter::In }
    };
    static const QUMethod slot_2 = {"setFont", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "textCol", &static_QUType_varptr, "\x0a", QUParameter::In }
    };
    static const QUMethod slot_3 = {"setTextColor", 1, param_slot_3 };
    static const QUMethod slot_4 = {"timerDisplayDone", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "Appear()", &slot_0, QMetaData::Public },
	{ "Disappear()", &slot_1, QMetaData::Public },
	{ "setFont(const QFont&)", &slot_2, QMetaData::Public },
	{ "setTextColor(const QColor&)", &slot_3, QMetaData::Public },
	{ "timerDisplayDone()", &slot_4, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"Sign_Clicked", 0, 0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_ptr, "CCoolPopup", QUParameter::In }
    };
    static const QUMethod signal_1 = {"Sign_Clicked", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_ptr, "CCoolPopup", QUParameter::In }
    };
    static const QUMethod signal_2 = {"Sign_PopupDown", 1, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_ptr, "CCoolPopup", QUParameter::In }
    };
    static const QUMethod signal_3 = {"Sign_PopupUp", 1, param_signal_3 };
    static const QMetaData signal_tbl[] = {
	{ "Sign_Clicked()", &signal_0, QMetaData::Public },
	{ "Sign_Clicked(CCoolPopup*)", &signal_1, QMetaData::Public },
	{ "Sign_PopupDown(CCoolPopup*)", &signal_2, QMetaData::Public },
	{ "Sign_PopupUp(CCoolPopup*)", &signal_3, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"CCoolPopup", parentObject,
	slot_tbl, 5,
	signal_tbl, 4,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CCoolPopup.setMetaObject( metaObj );
    return metaObj;
}

void* CCoolPopup::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CCoolPopup" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL Sign_Clicked
void CCoolPopup::Sign_Clicked()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL Sign_Clicked
void CCoolPopup::Sign_Clicked( CCoolPopup* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL Sign_PopupDown
void CCoolPopup::Sign_PopupDown( CCoolPopup* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL Sign_PopupUp
void CCoolPopup::Sign_PopupUp( CCoolPopup* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 3 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

bool CCoolPopup::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: Appear(); break;
    case 1: Disappear(); break;
    case 2: setFont((const QFont&)*((const QFont*)static_QUType_ptr.get(_o+1))); break;
    case 3: setTextColor((const QColor&)*((const QColor*)static_QUType_ptr.get(_o+1))); break;
    case 4: timerDisplayDone(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CCoolPopup::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: Sign_Clicked(); break;
    case 1: Sign_Clicked((CCoolPopup*)static_QUType_ptr.get(_o+1)); break;
    case 2: Sign_PopupDown((CCoolPopup*)static_QUType_ptr.get(_o+1)); break;
    case 3: Sign_PopupUp((CCoolPopup*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool CCoolPopup::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool CCoolPopup::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
