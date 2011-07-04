/****************************************************************************
** C_VigieListView meta object code from reading C++ file 'C_Organiseur.h'
**
** Created: Wed May 4 22:20:18 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../../../MedinTuxTools/C_Organiseur.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *C_VigieListView::className() const
{
    return "C_VigieListView";
}

QMetaObject *C_VigieListView::metaObj = 0;
static QMetaObjectCleanUp cleanUp_C_VigieListView( "C_VigieListView", &C_VigieListView::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString C_VigieListView::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_VigieListView", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString C_VigieListView::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_VigieListView", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* C_VigieListView::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = C_DragQListView::staticMetaObject();
    static const QUMethod slot_0 = {"clear", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ "pathDocuments", &static_QUType_QString, 0, QUParameter::In },
	{ "defaultMaskDirectory", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"On_DirectoryGlossaireChanged", 2, param_slot_1 };
    static const QMetaData slot_tbl[] = {
	{ "clear()", &slot_0, QMetaData::Public },
	{ "On_DirectoryGlossaireChanged(const QString&,const QString&)", &slot_1, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::InOut },
	{ 0, &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod signal_0 = {"Sign_MouseEnter", 2, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::InOut },
	{ 0, &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod signal_1 = {"Sign_MouseLeave", 2, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "Sign_MouseEnter(QString&,QString&)", &signal_0, QMetaData::Protected },
	{ "Sign_MouseLeave(QString&,QString&)", &signal_1, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"C_VigieListView", parentObject,
	slot_tbl, 2,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_C_VigieListView.setMetaObject( metaObj );
    return metaObj;
}

void* C_VigieListView::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "C_VigieListView" ) )
	return this;
    return C_DragQListView::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL Sign_MouseEnter
void C_VigieListView::Sign_MouseEnter( QString& t0, QString& t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
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
void C_VigieListView::Sign_MouseLeave( QString& t0, QString& t1 )
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

bool C_VigieListView::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: clear(); break;
    case 1: On_DirectoryGlossaireChanged((const QString&)static_QUType_QString.get(_o+1),(const QString&)static_QUType_QString.get(_o+2)); break;
    default:
	return C_DragQListView::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool C_VigieListView::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: Sign_MouseEnter((QString&)static_QUType_QString.get(_o+1),(QString&)static_QUType_QString.get(_o+2)); break;
    case 1: Sign_MouseLeave((QString&)static_QUType_QString.get(_o+1),(QString&)static_QUType_QString.get(_o+2)); break;
    default:
	return C_DragQListView::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool C_VigieListView::qt_property( int id, int f, QVariant* v)
{
    return C_DragQListView::qt_property( id, f, v);
}

bool C_VigieListView::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *C_Organiseur::className() const
{
    return "C_Organiseur";
}

QMetaObject *C_Organiseur::metaObj = 0;
static QMetaObjectCleanUp cleanUp_C_Organiseur( "C_Organiseur", &C_Organiseur::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString C_Organiseur::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_Organiseur", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString C_Organiseur::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "C_Organiseur", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* C_Organiseur::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = Form_Organiseur::staticMetaObject();
    static const QUMethod slot_0 = {"On_but_ConfFiltre_HideShow", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ "dragBreak", &static_QUType_bool, 0, QUParameter::InOut }
    };
    static const QUMethod slot_1 = {"On_DragMoveEvent", 2, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "dossGUID", &static_QUType_charstar, 0, QUParameter::In },
	{ "dossPk", &static_QUType_charstar, 0, QUParameter::In },
	{ "dossNom", &static_QUType_charstar, 0, QUParameter::In },
	{ "dossPrenom", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"On_IdentChange", 4, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "itemClicked", &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ "pnt", &static_QUType_varptr, "\x0e", QUParameter::In },
	{ "c", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"On_ItemClicked", 3, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ "itemClicked", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_4 = {"On_Sign_ItemClicked", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ "itemSrc", &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ "itemDst", &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ "verbe", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"On_ItemDraged_On_AnotherItem", 3, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "itemDst", &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ "fileList", &static_QUType_ptr, "QStrList", QUParameter::InOut },
	{ "verbe", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"On_FilesDraged_On_Item", 3, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ "itemDst", &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ "dragedText", &static_QUType_QString, 0, QUParameter::In },
	{ "verbe", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"On_TextDraged_On_Item", 3, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ "pQListViewItem", &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ "pos", &static_QUType_varptr, "\x0e", QUParameter::In },
	{ "c", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_8 = {"On_ContextMenuRequested", 3, param_slot_8 };
    static const QUMethod slot_9 = {"makeListeMonitor", 0, 0 };
    static const QUParameter param_slot_10[] = {
	{ "filtre", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_10 = {"makeListeMonitor", 1, param_slot_10 };
    static const QUMethod slot_11 = {"makeListeMonitorFromList", 0, 0 };
    static const QUMethod slot_12 = {"pushButtonDateDeb_clicked", 0, 0 };
    static const QUMethod slot_13 = {"pushButtonDateFin_clicked", 0, 0 };
    static const QUMethod slot_14 = {"On_but_ZoomPlus_clicked", 0, 0 };
    static const QUMethod slot_15 = {"On_but_ZoomMinus_clicked", 0, 0 };
    static const QUMethod slot_16 = {"On_but_ZoomDefault_clicked", 0, 0 };
    static const QUMethod slot_17 = {"On_but_SaveProfile_clicked", 0, 0 };
    static const QUMethod slot_18 = {"On_but_LoadProfile_clicked", 0, 0 };
    static const QUMethod slot_19 = {"On_checkBox_filtreActif_clicked", 0, 0 };
    static const QUMethod slot_20 = {"On_but_ConfFiltre_clicked", 0, 0 };
    static const QUMethod slot_21 = {"On_but_ConfFiltre_Plus_clicked", 0, 0 };
    static const QUMethod slot_22 = {"On_but_ConfFiltre_Moins_clicked", 0, 0 };
    static const QUParameter param_slot_23[] = {
	{ "str", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_23 = {"On_comboBox_FiltreVisu_activated", 1, param_slot_23 };
    static const QMetaData slot_tbl[] = {
	{ "On_but_ConfFiltre_HideShow()", &slot_0, QMetaData::Public },
	{ "On_DragMoveEvent(QListViewItem*,bool&)", &slot_1, QMetaData::Public },
	{ "On_IdentChange(const char*,const char*,const char*,const char*)", &slot_2, QMetaData::Public },
	{ "On_ItemClicked(QListViewItem*,const QPoint&,int)", &slot_3, QMetaData::Public },
	{ "On_Sign_ItemClicked(QListViewItem*)", &slot_4, QMetaData::Public },
	{ "On_ItemDraged_On_AnotherItem(QListViewItem*,QListViewItem*,const QString&)", &slot_5, QMetaData::Public },
	{ "On_FilesDraged_On_Item(QListViewItem*,QStrList&,const QString&)", &slot_6, QMetaData::Public },
	{ "On_TextDraged_On_Item(QListViewItem*,const QString&,const QString&)", &slot_7, QMetaData::Public },
	{ "On_ContextMenuRequested(QListViewItem*,const QPoint&,int)", &slot_8, QMetaData::Public },
	{ "makeListeMonitor()", &slot_9, QMetaData::Public },
	{ "makeListeMonitor(const QString&)", &slot_10, QMetaData::Public },
	{ "makeListeMonitorFromList()", &slot_11, QMetaData::Public },
	{ "pushButtonDateDeb_clicked()", &slot_12, QMetaData::Public },
	{ "pushButtonDateFin_clicked()", &slot_13, QMetaData::Public },
	{ "On_but_ZoomPlus_clicked()", &slot_14, QMetaData::Public },
	{ "On_but_ZoomMinus_clicked()", &slot_15, QMetaData::Public },
	{ "On_but_ZoomDefault_clicked()", &slot_16, QMetaData::Public },
	{ "On_but_SaveProfile_clicked()", &slot_17, QMetaData::Public },
	{ "On_but_LoadProfile_clicked()", &slot_18, QMetaData::Public },
	{ "On_checkBox_filtreActif_clicked()", &slot_19, QMetaData::Public },
	{ "On_but_ConfFiltre_clicked()", &slot_20, QMetaData::Public },
	{ "On_but_ConfFiltre_Plus_clicked()", &slot_21, QMetaData::Public },
	{ "On_but_ConfFiltre_Moins_clicked()", &slot_22, QMetaData::Public },
	{ "On_comboBox_FiltreVisu_activated(const QString&)", &slot_23, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"Sign_ActiverDocument", 3, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"Sign_CreateNewRootInOrganiseur", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x03", QUParameter::In }
    };
    static const QUMethod signal_2 = {"Sign_DragFileInOrganiseur", 2, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod signal_3 = {"Sign_IdentChangeInOrganiseur", 4, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::InOut },
	{ 0, &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod signal_4 = {"Sign_MouseEnter", 2, param_signal_4 };
    static const QMetaData signal_tbl[] = {
	{ "Sign_ActiverDocument(QString,QString,int)", &signal_0, QMetaData::Public },
	{ "Sign_CreateNewRootInOrganiseur(QString)", &signal_1, QMetaData::Public },
	{ "Sign_DragFileInOrganiseur(QString,QString*)", &signal_2, QMetaData::Public },
	{ "Sign_IdentChangeInOrganiseur(const char*,const char*,const char*,const char*)", &signal_3, QMetaData::Public },
	{ "Sign_MouseEnter(QString&,QString&)", &signal_4, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"C_Organiseur", parentObject,
	slot_tbl, 24,
	signal_tbl, 5,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_C_Organiseur.setMetaObject( metaObj );
    return metaObj;
}

void* C_Organiseur::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "C_Organiseur" ) )
	return this;
    return Form_Organiseur::qt_cast( clname );
}

// SIGNAL Sign_ActiverDocument
void C_Organiseur::Sign_ActiverDocument( QString t0, QString t1, int t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_QString.set(o+1,t0);
    static_QUType_QString.set(o+2,t1);
    static_QUType_int.set(o+3,t2);
    activate_signal( clist, o );
}

// SIGNAL Sign_CreateNewRootInOrganiseur
void C_Organiseur::Sign_CreateNewRootInOrganiseur( QString t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 1, t0 );
}

// SIGNAL Sign_DragFileInOrganiseur
void C_Organiseur::Sign_DragFileInOrganiseur( QString t0, QString* t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_QString.set(o+1,t0);
    static_QUType_varptr.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL Sign_IdentChangeInOrganiseur
void C_Organiseur::Sign_IdentChangeInOrganiseur( const char* t0, const char* t1, const char* t2, const char* t3 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 3 );
    if ( !clist )
	return;
    QUObject o[5];
    static_QUType_charstar.set(o+1,t0);
    static_QUType_charstar.set(o+2,t1);
    static_QUType_charstar.set(o+3,t2);
    static_QUType_charstar.set(o+4,t3);
    activate_signal( clist, o );
}

// SIGNAL Sign_MouseEnter
void C_Organiseur::Sign_MouseEnter( QString& t0, QString& t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 4 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_QString.set(o+1,t0);
    static_QUType_QString.set(o+2,t1);
    activate_signal( clist, o );
    t0 = static_QUType_QString.get(o+1);
    t1 = static_QUType_QString.get(o+2);
}

bool C_Organiseur::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: On_but_ConfFiltre_HideShow(); break;
    case 1: On_DragMoveEvent((QListViewItem*)static_QUType_ptr.get(_o+1),(bool&)static_QUType_bool.get(_o+2)); break;
    case 2: On_IdentChange((const char*)static_QUType_charstar.get(_o+1),(const char*)static_QUType_charstar.get(_o+2),(const char*)static_QUType_charstar.get(_o+3),(const char*)static_QUType_charstar.get(_o+4)); break;
    case 3: On_ItemClicked((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 4: On_Sign_ItemClicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 5: On_ItemDraged_On_AnotherItem((QListViewItem*)static_QUType_ptr.get(_o+1),(QListViewItem*)static_QUType_ptr.get(_o+2),(const QString&)static_QUType_QString.get(_o+3)); break;
    case 6: On_FilesDraged_On_Item((QListViewItem*)static_QUType_ptr.get(_o+1),(QStrList&)*((QStrList*)static_QUType_ptr.get(_o+2)),(const QString&)static_QUType_QString.get(_o+3)); break;
    case 7: On_TextDraged_On_Item((QListViewItem*)static_QUType_ptr.get(_o+1),(const QString&)static_QUType_QString.get(_o+2),(const QString&)static_QUType_QString.get(_o+3)); break;
    case 8: On_ContextMenuRequested((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 9: makeListeMonitor(); break;
    case 10: makeListeMonitor((const QString&)static_QUType_QString.get(_o+1)); break;
    case 11: makeListeMonitorFromList(); break;
    case 12: pushButtonDateDeb_clicked(); break;
    case 13: pushButtonDateFin_clicked(); break;
    case 14: On_but_ZoomPlus_clicked(); break;
    case 15: On_but_ZoomMinus_clicked(); break;
    case 16: On_but_ZoomDefault_clicked(); break;
    case 17: On_but_SaveProfile_clicked(); break;
    case 18: On_but_LoadProfile_clicked(); break;
    case 19: On_checkBox_filtreActif_clicked(); break;
    case 20: On_but_ConfFiltre_clicked(); break;
    case 21: On_but_ConfFiltre_Plus_clicked(); break;
    case 22: On_but_ConfFiltre_Moins_clicked(); break;
    case 23: On_comboBox_FiltreVisu_activated((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return Form_Organiseur::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool C_Organiseur::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: Sign_ActiverDocument((QString)static_QUType_QString.get(_o+1),(QString)static_QUType_QString.get(_o+2),(int)static_QUType_int.get(_o+3)); break;
    case 1: Sign_CreateNewRootInOrganiseur((QString)static_QUType_QString.get(_o+1)); break;
    case 2: Sign_DragFileInOrganiseur((QString)static_QUType_QString.get(_o+1),(QString*)static_QUType_varptr.get(_o+2)); break;
    case 3: Sign_IdentChangeInOrganiseur((const char*)static_QUType_charstar.get(_o+1),(const char*)static_QUType_charstar.get(_o+2),(const char*)static_QUType_charstar.get(_o+3),(const char*)static_QUType_charstar.get(_o+4)); break;
    case 4: Sign_MouseEnter((QString&)static_QUType_QString.get(_o+1),(QString&)static_QUType_QString.get(_o+2)); break;
    default:
	return Form_Organiseur::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool C_Organiseur::qt_property( int id, int f, QVariant* v)
{
    return Form_Organiseur::qt_property( id, f, v);
}

bool C_Organiseur::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
