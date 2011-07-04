/****************************************************************************
** Dlg_AdvancedTerrain meta object code from reading C++ file 'Dlg_AdvancedTerrain.h'
**
** Created: Wed May 4 22:20:47 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../ui/Dlg_AdvancedTerrain.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *Dlg_AdvancedTerrain::className() const
{
    return "Dlg_AdvancedTerrain";
}

QMetaObject *Dlg_AdvancedTerrain::metaObj = 0;
static QMetaObjectCleanUp cleanUp_Dlg_AdvancedTerrain( "Dlg_AdvancedTerrain", &Dlg_AdvancedTerrain::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString Dlg_AdvancedTerrain::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Dlg_AdvancedTerrain", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString Dlg_AdvancedTerrain::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Dlg_AdvancedTerrain", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* Dlg_AdvancedTerrain::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"UpdateHtmlView", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"comboBox_Allaitement_activated", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"comboBox_UnitGrossesse_activated", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"comboBox_Hemodialyse_activated", 1, param_slot_3 };
    static const QUMethod slot_4 = {"pushButton_Ok_clicked", 0, 0 };
    static const QUMethod slot_5 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "UpdateHtmlView(const QString&)", &slot_0, QMetaData::Public },
	{ "comboBox_Allaitement_activated(const QString&)", &slot_1, QMetaData::Public },
	{ "comboBox_UnitGrossesse_activated(const QString&)", &slot_2, QMetaData::Public },
	{ "comboBox_Hemodialyse_activated(const QString&)", &slot_3, QMetaData::Public },
	{ "pushButton_Ok_clicked()", &slot_4, QMetaData::Public },
	{ "languageChange()", &slot_5, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"Dlg_AdvancedTerrain", parentObject,
	slot_tbl, 6,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_Dlg_AdvancedTerrain.setMetaObject( metaObj );
    return metaObj;
}

void* Dlg_AdvancedTerrain::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "Dlg_AdvancedTerrain" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool Dlg_AdvancedTerrain::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: UpdateHtmlView((const QString&)static_QUType_QString.get(_o+1)); break;
    case 1: comboBox_Allaitement_activated((const QString&)static_QUType_QString.get(_o+1)); break;
    case 2: comboBox_UnitGrossesse_activated((const QString&)static_QUType_QString.get(_o+1)); break;
    case 3: comboBox_Hemodialyse_activated((const QString&)static_QUType_QString.get(_o+1)); break;
    case 4: pushButton_Ok_clicked(); break;
    case 5: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool Dlg_AdvancedTerrain::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool Dlg_AdvancedTerrain::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool Dlg_AdvancedTerrain::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
