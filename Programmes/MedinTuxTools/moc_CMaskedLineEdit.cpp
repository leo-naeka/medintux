/****************************************************************************
** CMaskedLineEdit meta object code from reading C++ file 'CMaskedLineEdit.h'
**
** Created: Fri Apr 1 20:27:22 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "CMaskedLineEdit.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#include <qvariant.h>
const char *CMaskedLineEdit::className() const
{
    return "CMaskedLineEdit";
}

QMetaObject *CMaskedLineEdit::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CMaskedLineEdit( "CMaskedLineEdit", &CMaskedLineEdit::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CMaskedLineEdit::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CMaskedLineEdit", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CMaskedLineEdit::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CMaskedLineEdit", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CMaskedLineEdit::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QLineEdit::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "templ", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"setTemplate", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "Valid", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"setValid", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "text", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"setText", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "carMask", &static_QUType_varptr, "\x11", QUParameter::In }
    };
    static const QUMethod slot_3 = {"setCarMask", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ "numKeyboardMap", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"setNumKeyboardMap", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ "mixmod", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"setMixMode", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "cursPos", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"setCursorPosition", 1, param_slot_6 };
    static const QUMethod slot_7 = {"paste", 0, 0 };
    static const QUMethod slot_8 = {"copy", 0, 0 };
    static const QUMethod slot_9 = {"extendedCopy", 0, 0 };
    static const QUMethod slot_10 = {"cut", 0, 0 };
    static const QUMethod slot_11 = {"cutAll", 0, 0 };
    static const QUMethod slot_12 = {"clear", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "setTemplate(const QString&)", &slot_0, QMetaData::Public },
	{ "setValid(const QString&)", &slot_1, QMetaData::Public },
	{ "setText(const QString&)", &slot_2, QMetaData::Public },
	{ "setCarMask(const uint&)", &slot_3, QMetaData::Public },
	{ "setNumKeyboardMap(const QString&)", &slot_4, QMetaData::Public },
	{ "setMixMode(const int&)", &slot_5, QMetaData::Public },
	{ "setCursorPosition(int)", &slot_6, QMetaData::Public },
	{ "paste()", &slot_7, QMetaData::Public },
	{ "copy()", &slot_8, QMetaData::Public },
	{ "extendedCopy()", &slot_9, QMetaData::Public },
	{ "cut()", &slot_10, QMetaData::Public },
	{ "cutAll()", &slot_11, QMetaData::Public },
	{ "clear()", &slot_12, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ "ev", &static_QUType_ptr, "QEvent", QUParameter::In }
    };
    static const QUMethod signal_0 = {"Sig_CarEvent", 1, param_signal_0 };
    static const QUMethod signal_1 = {"Sig_KeyDown", 0, 0 };
    static const QUMethod signal_2 = {"Sig_KeyUp", 0, 0 };
    static const QUMethod signal_3 = {"Sig_FocusOut", 0, 0 };
    static const QUMethod signal_4 = {"Sig_FocusIn", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "Sig_CarEvent(QEvent*)", &signal_0, QMetaData::Private },
	{ "Sig_KeyDown()", &signal_1, QMetaData::Private },
	{ "Sig_KeyUp()", &signal_2, QMetaData::Private },
	{ "Sig_FocusOut()", &signal_3, QMetaData::Private },
	{ "Sig_FocusIn()", &signal_4, QMetaData::Private }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[6] = {
 	{ "int","mixMode", 0x10000103, &CMaskedLineEdit::metaObj, 0, -1 },
	{ "uint","carMask", 0x11000103, &CMaskedLineEdit::metaObj, 0, -1 },
	{ "QString","control", 0x3000003, &CMaskedLineEdit::metaObj, 0, -1 },
	{ "QString","mask", 0x3000003, &CMaskedLineEdit::metaObj, 0, -1 },
	{ "QString","numKeyboardMap", 0x3000103, &CMaskedLineEdit::metaObj, 0, -1 },
	{ "QString","text", 0x3000103, &CMaskedLineEdit::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"CMaskedLineEdit", parentObject,
	slot_tbl, 13,
	signal_tbl, 5,
#ifndef QT_NO_PROPERTIES
	props_tbl, 6,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CMaskedLineEdit.setMetaObject( metaObj );
    return metaObj;
}

void* CMaskedLineEdit::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CMaskedLineEdit" ) )
	return this;
    return QLineEdit::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL Sig_CarEvent
void CMaskedLineEdit::Sig_CarEvent( QEvent* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL Sig_KeyDown
void CMaskedLineEdit::Sig_KeyDown()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

// SIGNAL Sig_KeyUp
void CMaskedLineEdit::Sig_KeyUp()
{
    activate_signal( staticMetaObject()->signalOffset() + 2 );
}

// SIGNAL Sig_FocusOut
void CMaskedLineEdit::Sig_FocusOut()
{
    activate_signal( staticMetaObject()->signalOffset() + 3 );
}

// SIGNAL Sig_FocusIn
void CMaskedLineEdit::Sig_FocusIn()
{
    activate_signal( staticMetaObject()->signalOffset() + 4 );
}

bool CMaskedLineEdit::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setTemplate((const QString&)static_QUType_QString.get(_o+1)); break;
    case 1: setValid((const QString&)static_QUType_QString.get(_o+1)); break;
    case 2: setText((const QString&)static_QUType_QString.get(_o+1)); break;
    case 3: setCarMask((const uint&)*((const uint*)static_QUType_ptr.get(_o+1))); break;
    case 4: setNumKeyboardMap((const QString&)static_QUType_QString.get(_o+1)); break;
    case 5: setMixMode((const int&)static_QUType_int.get(_o+1)); break;
    case 6: setCursorPosition((int)static_QUType_int.get(_o+1)); break;
    case 7: paste(); break;
    case 8: copy(); break;
    case 9: extendedCopy(); break;
    case 10: cut(); break;
    case 11: cutAll(); break;
    case 12: clear(); break;
    default:
	return QLineEdit::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CMaskedLineEdit::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: Sig_CarEvent((QEvent*)static_QUType_ptr.get(_o+1)); break;
    case 1: Sig_KeyDown(); break;
    case 2: Sig_KeyUp(); break;
    case 3: Sig_FocusOut(); break;
    case 4: Sig_FocusIn(); break;
    default:
	return QLineEdit::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool CMaskedLineEdit::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setMixMode(v->asInt()); break;
	case 1: *v = QVariant( this->getMixMode() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setCarMask(v->asUInt()); break;
	case 1: *v = QVariant( this->getCarMask() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setValid(v->asString()); break;
	case 1: *v = QVariant( this->getValid() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: setTemplate(v->asString()); break;
	case 1: *v = QVariant( this->getTemplate() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 0: setNumKeyboardMap(v->asString()); break;
	case 1: *v = QVariant( this->getNumKeyboardMap() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 0: setText(v->asString()); break;
	case 1: *v = QVariant( this->text() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QLineEdit::qt_property( id, f, v );
    }
    return TRUE;
}

bool CMaskedLineEdit::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
