/****************************************************************************
** CViewPageWidget meta object code from reading C++ file 'CPrinter.h'
**
** Created: Wed May 4 22:20:16 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../CPrinter.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CViewPageWidget::className() const
{
    return "CViewPageWidget";
}

QMetaObject *CViewPageWidget::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CViewPageWidget( "CViewPageWidget", &CViewPageWidget::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CViewPageWidget::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CViewPageWidget", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CViewPageWidget::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CViewPageWidget", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CViewPageWidget::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"CViewPageWidget", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CViewPageWidget.setMetaObject( metaObj );
    return metaObj;
}

void* CViewPageWidget::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CViewPageWidget" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool CViewPageWidget::qt_invoke( int _id, QUObject* _o )
{
    return QWidget::qt_invoke(_id,_o);
}

bool CViewPageWidget::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool CViewPageWidget::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool CViewPageWidget::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
