/****************************************************************************
** CW_EditText meta object code from reading C++ file 'CW_EditText.h'
**
** Created: Wed May 4 22:20:19 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../../../MedinTuxTools/CW_EditText.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CW_EditText::className() const
{
    return "CW_EditText";
}

QMetaObject *CW_EditText::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CW_EditText( "CW_EditText", &CW_EditText::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CW_EditText::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CW_EditText", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CW_EditText::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CW_EditText", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CW_EditText::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QTextEdit::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "txt", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"setText", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "setText(const QString&)", &slot_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"CW_EditText", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CW_EditText.setMetaObject( metaObj );
    return metaObj;
}

void* CW_EditText::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CW_EditText" ) )
	return this;
    return QTextEdit::qt_cast( clname );
}

bool CW_EditText::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setText((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return QTextEdit::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CW_EditText::qt_emit( int _id, QUObject* _o )
{
    return QTextEdit::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool CW_EditText::qt_property( int id, int f, QVariant* v)
{
    return QTextEdit::qt_property( id, f, v);
}

bool CW_EditText::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
