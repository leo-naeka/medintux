/****************************************************************************
** FormOngletRubrique meta object code from reading C++ file 'FormOngletRubrique.h'
**
** Created: Wed May 4 22:20:15 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../FormOngletRubrique.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *FormOngletRubrique::className() const
{
    return "FormOngletRubrique";
}

QMetaObject *FormOngletRubrique::metaObj = 0;
static QMetaObjectCleanUp cleanUp_FormOngletRubrique( "FormOngletRubrique", &FormOngletRubrique::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString FormOngletRubrique::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "FormOngletRubrique", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString FormOngletRubrique::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "FormOngletRubrique", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* FormOngletRubrique::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"languageChange", 0, 0 };
    static const QUMethod slot_1 = {"TimedSetOnglet", 0, 0 };
    static const QUMethod slot_2 = {"TimedRemoveOnglet", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ "pWdgRub", &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod slot_3 = {"OnRubriqueActived", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ "name", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"removePage", 1, param_slot_4 };
    static const QUMethod slot_5 = {"removeAllPage", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "languageChange()", &slot_0, QMetaData::Public },
	{ "TimedSetOnglet()", &slot_1, QMetaData::Public },
	{ "TimedRemoveOnglet()", &slot_2, QMetaData::Public },
	{ "OnRubriqueActived(QWidget*)", &slot_3, QMetaData::Public },
	{ "removePage(const char*)", &slot_4, QMetaData::Public },
	{ "removeAllPage()", &slot_5, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"message", 2, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "message(const QString&,int)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"FormOngletRubrique", parentObject,
	slot_tbl, 6,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_FormOngletRubrique.setMetaObject( metaObj );
    return metaObj;
}

void* FormOngletRubrique::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "FormOngletRubrique" ) )
	return this;
    return QWidget::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL message
void FormOngletRubrique::message( const QString& t0, int t1 )
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

bool FormOngletRubrique::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: languageChange(); break;
    case 1: TimedSetOnglet(); break;
    case 2: TimedRemoveOnglet(); break;
    case 3: OnRubriqueActived((QWidget*)static_QUType_ptr.get(_o+1)); break;
    case 4: removePage((const char*)static_QUType_charstar.get(_o+1)); break;
    case 5: removeAllPage(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool FormOngletRubrique::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: message((const QString&)static_QUType_QString.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool FormOngletRubrique::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool FormOngletRubrique::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
