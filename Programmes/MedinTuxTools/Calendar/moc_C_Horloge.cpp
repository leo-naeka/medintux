/****************************************************************************
** C_Horloge_Label meta object code from reading C++ file 'C_Horloge.h'
**
** Created: Fri Apr 1 20:27:23 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "C_Horloge.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *C_Horloge_Label::className() const
{
    return "C_Horloge_Label";
}

QMetaObject *C_Horloge_Label::metaObj = 0;
static QMetaObjectCleanUp cleanUp_C_Horloge_Label( "C_Horloge_Label", &C_Horloge_Label::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString C_Horloge_Label::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_Horloge_Label", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString C_Horloge_Label::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_Horloge_Label", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* C_Horloge_Label::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QLabel::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"C_Horloge_Label", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_C_Horloge_Label.setMetaObject( metaObj );
    return metaObj;
}

void* C_Horloge_Label::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "C_Horloge_Label" ) )
	return this;
    return QLabel::qt_cast( clname );
}

bool C_Horloge_Label::qt_invoke( int _id, QUObject* _o )
{
    return QLabel::qt_invoke(_id,_o);
}

bool C_Horloge_Label::qt_emit( int _id, QUObject* _o )
{
    return QLabel::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool C_Horloge_Label::qt_property( int id, int f, QVariant* v)
{
    return QLabel::qt_property( id, f, v);
}

bool C_Horloge_Label::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *C_HM_Wdg::className() const
{
    return "C_HM_Wdg";
}

QMetaObject *C_HM_Wdg::metaObj = 0;
static QMetaObjectCleanUp cleanUp_C_HM_Wdg( "C_HM_Wdg", &C_HM_Wdg::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString C_HM_Wdg::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_HM_Wdg", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString C_HM_Wdg::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_HM_Wdg", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* C_HM_Wdg::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::Out },
	{ "e", &static_QUType_ptr, "QEvent", QUParameter::In }
    };
    static const QUMethod slot_0 = {"event", 2, param_slot_0 };
    static const QUMethod slot_1 = {"mouseEnter", 0, 0 };
    static const QUMethod slot_2 = {"mouseLeave", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "event(QEvent*)", &slot_0, QMetaData::Public },
	{ "mouseEnter()", &slot_1, QMetaData::Protected },
	{ "mouseLeave()", &slot_2, QMetaData::Protected }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"Sign_HeureClicked", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"Sign_MouseEnter", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"Sign_MouseLeave", 1, param_signal_2 };
    static const QMetaData signal_tbl[] = {
	{ "Sign_HeureClicked(QString)", &signal_0, QMetaData::Protected },
	{ "Sign_MouseEnter(QString)", &signal_1, QMetaData::Protected },
	{ "Sign_MouseLeave(QString)", &signal_2, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"C_HM_Wdg", parentObject,
	slot_tbl, 3,
	signal_tbl, 3,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_C_HM_Wdg.setMetaObject( metaObj );
    return metaObj;
}

void* C_HM_Wdg::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "C_HM_Wdg" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL Sign_HeureClicked
void C_HM_Wdg::Sign_HeureClicked( QString t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL Sign_MouseEnter
void C_HM_Wdg::Sign_MouseEnter( QString t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 1, t0 );
}

// SIGNAL Sign_MouseLeave
void C_HM_Wdg::Sign_MouseLeave( QString t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 2, t0 );
}

bool C_HM_Wdg::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: static_QUType_bool.set(_o,event((QEvent*)static_QUType_ptr.get(_o+1))); break;
    case 1: mouseEnter(); break;
    case 2: mouseLeave(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool C_HM_Wdg::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: Sign_HeureClicked((QString)static_QUType_QString.get(_o+1)); break;
    case 1: Sign_MouseEnter((QString)static_QUType_QString.get(_o+1)); break;
    case 2: Sign_MouseLeave((QString)static_QUType_QString.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool C_HM_Wdg::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool C_HM_Wdg::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *C_Horloge::className() const
{
    return "C_Horloge";
}

QMetaObject *C_Horloge::metaObj = 0;
static QMetaObjectCleanUp cleanUp_C_Horloge( "C_Horloge", &C_Horloge::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString C_Horloge::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_Horloge", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString C_Horloge::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_Horloge", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* C_Horloge::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QFrame::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "t", &static_QUType_varptr, "\x1b", QUParameter::In }
    };
    static const QUMethod slot_0 = {"setTime", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "hr", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"On_HeuresClicked", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "mn", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"On_MinutesClicked", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"On_MouseMinuteLeave", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ "mn", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"On_MouseMinuteEnter", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"On_MouseHeureLeave", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "hr", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"On_MouseHeureEnter", 1, param_slot_6 };
    static const QMetaData slot_tbl[] = {
	{ "setTime(const QTime&)", &slot_0, QMetaData::Public },
	{ "On_HeuresClicked(QString)", &slot_1, QMetaData::Protected },
	{ "On_MinutesClicked(QString)", &slot_2, QMetaData::Protected },
	{ "On_MouseMinuteLeave(QString)", &slot_3, QMetaData::Protected },
	{ "On_MouseMinuteEnter(QString)", &slot_4, QMetaData::Protected },
	{ "On_MouseHeureLeave(QString)", &slot_5, QMetaData::Protected },
	{ "On_MouseHeureEnter(QString)", &slot_6, QMetaData::Protected }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_varptr, "\x1b", QUParameter::In }
    };
    static const QUMethod signal_0 = {"Sign_HorlogeTimeChanged", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "Sign_HorlogeTimeChanged(const QTime&)", &signal_0, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"C_Horloge", parentObject,
	slot_tbl, 7,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_C_Horloge.setMetaObject( metaObj );
    return metaObj;
}

void* C_Horloge::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "C_Horloge" ) )
	return this;
    return QFrame::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL Sign_HorlogeTimeChanged
void C_Horloge::Sign_HorlogeTimeChanged( const QTime& t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_varptr.set(o+1,&t0);
    activate_signal( clist, o );
}

bool C_Horloge::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setTime((const QTime&)*((const QTime*)static_QUType_ptr.get(_o+1))); break;
    case 1: On_HeuresClicked((QString)static_QUType_QString.get(_o+1)); break;
    case 2: On_MinutesClicked((QString)static_QUType_QString.get(_o+1)); break;
    case 3: On_MouseMinuteLeave((QString)static_QUType_QString.get(_o+1)); break;
    case 4: On_MouseMinuteEnter((QString)static_QUType_QString.get(_o+1)); break;
    case 5: On_MouseHeureLeave((QString)static_QUType_QString.get(_o+1)); break;
    case 6: On_MouseHeureEnter((QString)static_QUType_QString.get(_o+1)); break;
    default:
	return QFrame::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool C_Horloge::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: Sign_HorlogeTimeChanged((const QTime&)*((const QTime*)static_QUType_ptr.get(_o+1))); break;
    default:
	return QFrame::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool C_Horloge::qt_property( int id, int f, QVariant* v)
{
    return QFrame::qt_property( id, f, v);
}

bool C_Horloge::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
