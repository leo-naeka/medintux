/****************************************************************************
** Atcd_Code meta object code from reading C++ file 'C_Atcd.h'
**
** Created: Wed May 4 22:20:29 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../C_Atcd.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *Atcd_Code::className() const
{
    return "Atcd_Code";
}

QMetaObject *Atcd_Code::metaObj = 0;
static QMetaObjectCleanUp cleanUp_Atcd_Code( "Atcd_Code", &Atcd_Code::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString Atcd_Code::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Atcd_Code", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString Atcd_Code::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Atcd_Code", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* Atcd_Code::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"emitATCD_Changed", 0, 0 };
    static const QUMethod slot_1 = {"addATCD_CIM10", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ "tabToSet", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"addATCD_CIM10", 1, param_slot_2 };
    static const QUMethod slot_3 = {"addATCD_Allergie", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ "parent", &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod slot_4 = {"changeDDR", 1, param_slot_4 };
    static const QMetaData slot_tbl[] = {
	{ "emitATCD_Changed()", &slot_0, QMetaData::Public },
	{ "addATCD_CIM10()", &slot_1, QMetaData::Public },
	{ "addATCD_CIM10(int)", &slot_2, QMetaData::Public },
	{ "addATCD_Allergie()", &slot_3, QMetaData::Public },
	{ "changeDDR(QWidget*)", &slot_4, QMetaData::Public }
    };
    static const QUMethod signal_0 = {"ATCD_Changed", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "ATCD_Changed()", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"Atcd_Code", parentObject,
	slot_tbl, 5,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_Atcd_Code.setMetaObject( metaObj );
    return metaObj;
}

void* Atcd_Code::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "Atcd_Code" ) )
	return this;
    return QObject::qt_cast( clname );
}

// SIGNAL ATCD_Changed
void Atcd_Code::ATCD_Changed()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

bool Atcd_Code::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: emitATCD_Changed(); break;
    case 1: addATCD_CIM10(); break;
    case 2: addATCD_CIM10((int)static_QUType_int.get(_o+1)); break;
    case 3: addATCD_Allergie(); break;
    case 4: changeDDR((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool Atcd_Code::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: ATCD_Changed(); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool Atcd_Code::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool Atcd_Code::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
