/****************************************************************************
** CMDI_Generic meta object code from reading C++ file 'CMDI_Generic.h'
**
** Created: Wed May 4 22:20:23 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../CMDI_Generic.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CMDI_Generic::className() const
{
    return "CMDI_Generic";
}

QMetaObject *CMDI_Generic::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CMDI_Generic( "CMDI_Generic", &CMDI_Generic::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CMDI_Generic::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CMDI_Generic", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CMDI_Generic::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CMDI_Generic", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CMDI_Generic::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QMainWindow::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "rubName", &static_QUType_charstar, 0, QUParameter::In },
	{ "mode", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"ActiverRubrique", 2, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "pathDocuments", &static_QUType_QString, 0, QUParameter::In },
	{ "defaultMaskDirectory", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"On_DirectoryGlossaireChanged", 2, param_slot_1 };
    static const QMetaData slot_tbl[] = {
	{ "ActiverRubrique(const char*,int)", &slot_0, QMetaData::Public },
	{ "On_DirectoryGlossaireChanged(const QString&,const QString&)", &slot_1, QMetaData::Public }
    };
    static const QUMethod signal_0 = {"Sign_Print", 0, 0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::InOut },
	{ 0, &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod signal_1 = {"Sign_MouseEnter", 2, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::InOut },
	{ 0, &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod signal_2 = {"Sign_MouseLeave", 2, param_signal_2 };
    static const QMetaData signal_tbl[] = {
	{ "Sign_Print()", &signal_0, QMetaData::Public },
	{ "Sign_MouseEnter(QString&,QString&)", &signal_1, QMetaData::Protected },
	{ "Sign_MouseLeave(QString&,QString&)", &signal_2, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"CMDI_Generic", parentObject,
	slot_tbl, 2,
	signal_tbl, 3,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CMDI_Generic.setMetaObject( metaObj );
    return metaObj;
}

void* CMDI_Generic::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CMDI_Generic" ) )
	return this;
    return QMainWindow::qt_cast( clname );
}

// SIGNAL Sign_Print
void CMDI_Generic::Sign_Print()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL Sign_MouseEnter
void CMDI_Generic::Sign_MouseEnter( QString& t0, QString& t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_QString.set(o+1,t0);
    static_QUType_QString.set(o+2,t1);
    activate_signal( clist, o );
    t0 = static_QUType_QString.get(o+1);
    t1 = static_QUType_QString.get(o+2);
}

// SIGNAL Sign_MouseLeave
void CMDI_Generic::Sign_MouseLeave( QString& t0, QString& t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_QString.set(o+1,t0);
    static_QUType_QString.set(o+2,t1);
    activate_signal( clist, o );
    t0 = static_QUType_QString.get(o+1);
    t1 = static_QUType_QString.get(o+2);
}

bool CMDI_Generic::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: ActiverRubrique((const char*)static_QUType_charstar.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 1: On_DirectoryGlossaireChanged((const QString&)static_QUType_QString.get(_o+1),(const QString&)static_QUType_QString.get(_o+2)); break;
    default:
	return QMainWindow::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CMDI_Generic::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: Sign_Print(); break;
    case 1: Sign_MouseEnter((QString&)static_QUType_QString.get(_o+1),(QString&)static_QUType_QString.get(_o+2)); break;
    case 2: Sign_MouseLeave((QString&)static_QUType_QString.get(_o+1),(QString&)static_QUType_QString.get(_o+2)); break;
    default:
	return QMainWindow::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool CMDI_Generic::qt_property( int id, int f, QVariant* v)
{
    return QMainWindow::qt_property( id, f, v);
}

bool CMDI_Generic::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
