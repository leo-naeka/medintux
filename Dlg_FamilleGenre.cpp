/****************************************************************************
** Form implementation generated from reading ui file 'Dlg_FamilleGenre.ui'
**
** Created: mer. mai 4 22:20:10 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "Dlg_FamilleGenre.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qheader.h>
#include <qlistview.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a Dlg_FamilleGenre as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
Dlg_FamilleGenre::Dlg_FamilleGenre( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setProperty( "name", "Dlg_FamilleGenre" );
    Dlg_FamilleGenreLayout = new QGridLayout( this, 1, 1, 0, 6, "Dlg_FamilleGenreLayout"); 

    pushButton_Quit = new QPushButton( this, "pushButton_Quit" );

    Dlg_FamilleGenreLayout->addWidget( pushButton_Quit, 2, 5 );
    spacer1 = new QSpacerItem( 200, 16, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Dlg_FamilleGenreLayout->addItem( spacer1, 2, 4 );

    pushButton_add_Genre = new QPushButton( this, "pushButton_add_Genre" );
    pushButton_add_Genre->setProperty( "maximumSize", QSize( 22, 22 ) );

    Dlg_FamilleGenreLayout->addWidget( pushButton_add_Genre, 2, 1 );

    pushButton_add_Famille = new QPushButton( this, "pushButton_add_Famille" );
    pushButton_add_Famille->setProperty( "maximumSize", QSize( 22, 22 ) );

    Dlg_FamilleGenreLayout->addWidget( pushButton_add_Famille, 2, 0 );

    pushButton_del = new QPushButton( this, "pushButton_del" );
    pushButton_del->setProperty( "maximumSize", QSize( 22, 22 ) );

    Dlg_FamilleGenreLayout->addWidget( pushButton_del, 2, 2 );

    pushButton_save = new QPushButton( this, "pushButton_save" );
    pushButton_save->setProperty( "maximumSize", QSize( 22, 22 ) );

    Dlg_FamilleGenreLayout->addWidget( pushButton_save, 2, 3 );

    listView_FamilleGenre = new QListView( this, "listView_FamilleGenre" );
    listView_FamilleGenre->addColumn( trUtf8( "\x4c\x69\x62\x65\x6c\x6c\xc3\xa9" ) );
    listView_FamilleGenre->setProperty( "rootIsDecorated", QVariant( TRUE, 0 ) );

    Dlg_FamilleGenreLayout->addMultiCellWidget( listView_FamilleGenre, 1, 1, 0, 5 );

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setProperty( "frameShape", "WinPanel" );
    textLabel1->setProperty( "frameShadow", "Plain" );

    Dlg_FamilleGenreLayout->addMultiCellWidget( textLabel1, 0, 0, 0, 5 );
    languageChange();
    resize( QSize(341, 441).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Dlg_FamilleGenre::~Dlg_FamilleGenre()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Dlg_FamilleGenre::languageChange()
{
    setProperty( "caption", trUtf8( "\x4d\x6f\x64\x69\x66\x69\x65\x72\x20\x6c\x65\x73\x20\x46\x61\x6d\x69\x6c\x6c\x65\x73"
    "\x20\x65\x74\x20\x67\x65\x6e\x72\x65\x73\x20\x64\x65\x73\x20\x61\x6e\x74\xc3\xa9"
    "\x63\xc3\xa9\x64\x65\x6e\x74\x73" ) );
    pushButton_Quit->setProperty( "text", tr( "Quitter" ) );
    pushButton_add_Genre->setProperty( "text", QString::null );
    QToolTip::add( pushButton_add_Genre, tr( "Ajouter un genre" ) );
    QWhatsThis::add( pushButton_add_Genre, tr( "Ajouter un genre" ) );
    pushButton_add_Famille->setProperty( "text", QString::null );
    QToolTip::add( pushButton_add_Famille, tr( "Ajouter une famille" ) );
    QWhatsThis::add( pushButton_add_Famille, tr( "Ajouter une famille" ) );
    pushButton_del->setProperty( "text", QString::null );
    QToolTip::add( pushButton_del, trUtf8( "\x45\x66\x66\x61\x63\x65\x72\x20\x6c\x27\x69\x74\x65\x6d\x20\x73\xc3\xa9\x6c\x65\x63"
    "\x74\x69\x6f\x6e\x6e\xc3\xa9" ) );
    QWhatsThis::add( pushButton_del, trUtf8( "\x45\x66\x66\x61\x63\x65\x72\x20\x6c\x27\x69\x74\x65\x6d\x20\x73\xc3\xa9\x6c\x65\x63"
    "\x74\x69\x6f\x6e\x6e\xc3\xa9" ) );
    pushButton_save->setProperty( "text", QString::null );
    QToolTip::add( pushButton_save, tr( "Enregistrer les modifications" ) );
    QWhatsThis::add( pushButton_save, tr( "Enregistrer les modifications" ) );
    listView_FamilleGenre->header()->setLabel( 0, trUtf8( "\x4c\x69\x62\x65\x6c\x6c\xc3\xa9" ) );
    QToolTip::add( listView_FamilleGenre, trUtf8( "\x4c\x69\x73\x74\x65\x20\x64\x65\x73\x20\x66\x61\x6d\x69\x6c\x6c\x65\x73\x20\x67\x65"
    "\x6e\x72\x65\x73\x20\x64\x27\x61\x6e\x74\xc3\xa9\x63\xc3\xa9\x64\x65\x6e\x74\x73"
    "" ) );
    QWhatsThis::add( listView_FamilleGenre, trUtf8( "\x4c\x69\x73\x74\x65\x20\x64\x65\x73\x20\x66\x61\x6d\x69\x6c\x6c\x65\x73\x20\x67\x65"
    "\x6e\x72\x65\x73\x20\x64\x27\x61\x6e\x74\xc3\xa9\x63\xc3\xa9\x64\x65\x6e\x74\x73"
    "" ) );
    textLabel1->setProperty( "text", trUtf8( "\x3c\x66\x6f\x6e\x74\x20\x73\x69\x7a\x65\x3d\x22\x2d\x31\x22\x3e\x43\x65\x74\x74\x65"
    "\x20\x62\x6f\xc3\xae\x74\x65\x20\x64\x65\x20\x64\x69\x61\x6c\x6f\x67\x75\x65\x20"
    "\x70\x65\x72\x6d\x65\x74\x20\x64\x65\x20\x6d\x6f\x64\x69\x66\x69\x65\x72\x20\x6c"
    "\x65\x73\x20\x3c\x62\x3e\x66\x61\x6d\x69\x6c\x6c\x65\x73\x3c\x2f\x62\x3e\x20\x65"
    "\x74\x20\x3c\x62\x3e\x67\x65\x6e\x72\x65\x73\x3c\x2f\x62\x3e\x20\x63\x61\x72\x61"
    "\x63\x74\xc3\xa9\x72\x69\x73\x61\x6e\x74\x20\x6c\x65\x73\x20\x3c\x62\x3e\x61\x6e"
    "\x74\xc3\xa9\x63\xc3\xa9\x64\x65\x6e\x74\x73\x3c\x2f\x62\x3e\x2e\x3c\x62\x72\x3e"
    "\xa\x45\x6e\x20\x65\x66\x66\x65\x74\x20\xc3\xa0\x20\x63\x68\x61\x71\x75\x65\x20"
    "\x61\x6e\x74\xc3\xa9\x63\xc3\xa9\x64\x65\x6e\x74\x20\x76\x6f\x75\x73\x20\x70\x6f"
    "\x75\x76\x65\x7a\x20\x61\x73\x73\x6f\x63\x69\x65\x72\x20\x75\x6e\x65\x20\x66\x61"
    "\x6d\x69\x6c\x6c\x65\x20\x6c\x65\x20\x63\x61\x72\x61\x63\x74\xc3\xa9\x72\x69\x73"
    "\x61\x6e\x74\x2c\x20\x63\x6f\x6d\x6d\x65\x20\x70\x61\x72\x20\x65\x78\x65\x6d\x70"
    "\x6c\x65\x20\x3c\x62\x3e\x4d\xc3\xa9\x64\x69\x63\x61\x75\x78\x3c\x2f\x62\x3e\x20"
    "\xa\x70\x6f\x75\x72\x20\x6c\x65\x73\x20\x61\x6e\x74\xc3\xa9\x63\xc3\xa9\x64\x65"
    "\x6e\x74\x73\x20\x6d\xc3\xa9\x64\x69\x63\x61\x75\x78\x20\x6f\x75\x20\x3c\x62\x3e"
    "\x43\x68\x69\x72\x75\x72\x67\x69\x63\x61\x75\x78\x3c\x2f\x62\x3e\x20\x70\x6f\x75"
    "\x72\x20\x6c\x65\x73\x20\x61\x6e\x74\xc3\xa9\x63\xc3\xa9\x64\x65\x6e\x74\x73\x20"
    "\x63\x68\x69\x72\x75\x72\x67\x69\x63\x61\x75\x78\x2e\x20\x43\x65\x73\x20\x66\x61"
    "\x6d\x69\x6c\x6c\x65\x73\x20\xa\x70\x65\x75\x76\x65\x6e\x74\x20\x65\x6c\x6c\x65"
    "\x20\x6d\xc3\xaa\x6d\x65\x20\x63\x6f\x6e\x74\x65\x6e\x69\x72\x20\x64\x65\x73\x20"
    "\x3c\x62\x3e\x67\x65\x6e\x72\x65\x73\x3c\x2f\x62\x3e\x20\x28\x66\x61\x63\x75\x6c"
    "\x74\x61\x74\x69\x66\x73\x29\x20\x70\x65\x72\x6d\x65\x74\x74\x61\x6e\x74\x20\x64"
    "\x27\x61\x66\x66\x69\x6e\x65\x72\x20\x6c\x65\x20\x74\x79\x70\x61\x67\x65\x20\x64"
    "\x65\x20\x63\x65\x73\x20\x61\x6e\x74\xc3\xa9\x63\xc3\xa9\x64\x65\x6e\x74\x73\x2e"
    "\x3c\x2f\x66\x6f\x6e\x74\x3e" ) );
}

