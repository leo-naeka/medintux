/****************************************************************************
** Dock_TabRubrique meta object code from reading C++ file 'Dock_TabRubrique.h'
**
** Created: Wed May 4 22:20:36 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../ui/Dock_TabRubrique.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *Dock_TabRubrique::className() const
{
    return "Dock_TabRubrique";
}

QMetaObject *Dock_TabRubrique::metaObj = 0;
static QMetaObjectCleanUp cleanUp_Dock_TabRubrique( "Dock_TabRubrique", &Dock_TabRubrique::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString Dock_TabRubrique::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Dock_TabRubrique", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString Dock_TabRubrique::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Dock_TabRubrique", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* Dock_TabRubrique::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "butTxt", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"On_ButtonClicked", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "droits", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"SetInterfaceOnDroits", 1, param_slot_1 };
    static const QUMethod slot_2 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "On_ButtonClicked(const char*)", &slot_0, QMetaData::Public },
	{ "SetInterfaceOnDroits(const QString&)", &slot_1, QMetaData::Public },
	{ "languageChange()", &slot_2, QMetaData::Protected }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"Sign_ActiverOrCreateRubrique", 2, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "Sign_ActiverOrCreateRubrique(const char*,int)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"Dock_TabRubrique", parentObject,
	slot_tbl, 3,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_Dock_TabRubrique.setMetaObject( metaObj );
    return metaObj;
}

void* Dock_TabRubrique::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "Dock_TabRubrique" ) )
	return this;
    return QWidget::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL Sign_ActiverOrCreateRubrique
void Dock_TabRubrique::Sign_ActiverOrCreateRubrique( const char* t0, int t1 )
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

bool Dock_TabRubrique::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: On_ButtonClicked((const char*)static_QUType_charstar.get(_o+1)); break;
    case 1: SetInterfaceOnDroits((const QString&)static_QUType_QString.get(_o+1)); break;
    case 2: languageChange(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool Dock_TabRubrique::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: Sign_ActiverOrCreateRubrique((const char*)static_QUType_charstar.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool Dock_TabRubrique::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool Dock_TabRubrique::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
