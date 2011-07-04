/****************************************************************************
** Form implementation generated from reading ui file 'DlgChoixUser.ui'
**
** Created: mer. mai 4 22:19:25 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "DlgChoixUser.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qsplitter.h>
#include <qheader.h>
#include <qlistview.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "../DlgChoixUser.ui.h"

/*
 *  Constructs a DlgChoixUser as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
DlgChoixUser::DlgChoixUser( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setProperty( "name", "DlgChoixUser" );
    DlgChoixUserLayout = new QGridLayout( this, 1, 1, 11, 6, "DlgChoixUserLayout"); 

    splitterCentral = new QSplitter( this, "splitterCentral" );
    splitterCentral->setProperty( "orientation", "Horizontal" );

    ListView_UserList = new QListView( splitterCentral, "ListView_UserList" );
    ListView_UserList->addColumn( tr( "Utilisateur" ) );
    ListView_UserList->addColumn( tr( "Nom                  " ) );
    ListView_UserList->addColumn( trUtf8( "\x50\x72\xc3\xa9\x6e\x6f\x6d" ) );
    ListView_UserList->addColumn( tr( "ID" ) );
    ListView_UserList->addColumn( tr( "GUID" ) );
    ListView_UserList->setProperty( "acceptDrops", QVariant( TRUE, 0 ) );
    ListView_UserList->setProperty( "frameShape", "StyledPanel" );
    ListView_UserList->setProperty( "frameShadow", "Sunken" );
    ListView_UserList->setProperty( "rootIsDecorated", QVariant( TRUE, 0 ) );

    QWidget* privateLayoutWidget = new QWidget( splitterCentral, "layout8" );
    layout8 = new QVBoxLayout( privateLayoutWidget, 11, 6, "layout8"); 

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    pushButtonConfig = new QPushButton( privateLayoutWidget, "pushButtonConfig" );
    layout4->addWidget( pushButtonConfig );
    layout8->addLayout( layout4 );
    spacer2 = new QSpacerItem( 10, 31, QSizePolicy::Minimum, QSizePolicy::Expanding );
    layout8->addItem( spacer2 );

    layout2 = new QHBoxLayout( 0, 0, 6, "layout2"); 

    textLabelPassWord = new QLabel( privateLayoutWidget, "textLabelPassWord" );
    layout2->addWidget( textLabelPassWord );

    lineEditPassWord = new QLineEdit( privateLayoutWidget, "lineEditPassWord" );
    lineEditPassWord->setProperty( "echoMode", "Password" );
    layout2->addWidget( lineEditPassWord );
    layout8->addLayout( layout2 );
    spacer1 = new QSpacerItem( 16, 25, QSizePolicy::Minimum, QSizePolicy::Expanding );
    layout8->addItem( spacer1 );

    layout1 = new QHBoxLayout( 0, 0, 6, "layout1"); 

    pushButtonOK = new QPushButton( privateLayoutWidget, "pushButtonOK" );
    pushButtonOK->setProperty( "default", QVariant( TRUE, 0 ) );
    layout1->addWidget( pushButtonOK );

    pushButtonAnnuler = new QPushButton( privateLayoutWidget, "pushButtonAnnuler" );
    layout1->addWidget( pushButtonAnnuler );
    layout8->addLayout( layout1 );

    DlgChoixUserLayout->addWidget( splitterCentral, 0, 0 );
    languageChange();
    resize( QSize(553, 280).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections

    // buddies
    textLabelPassWord->setBuddy( lineEditPassWord );
}

/*
 *  Destroys the object and frees any allocated resources
 */
DlgChoixUser::~DlgChoixUser()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void DlgChoixUser::languageChange()
{
    setProperty( "caption", tr( "Choix des utilisateurs" ) );
    ListView_UserList->header()->setLabel( 0, tr( "Utilisateur" ) );
    ListView_UserList->header()->setLabel( 1, tr( "Nom                  " ) );
    ListView_UserList->header()->setLabel( 2, trUtf8( "\x50\x72\xc3\xa9\x6e\x6f\x6d" ) );
    ListView_UserList->header()->setLabel( 3, tr( "ID" ) );
    ListView_UserList->header()->setLabel( 4, tr( "GUID" ) );
    pushButtonConfig->setProperty( "text", tr( "&Configurer" ) );
    pushButtonConfig->setProperty( "accel", QKeySequence( tr( "Alt+C" ) ) );
    textLabelPassWord->setProperty( "text", tr( "&Mot de passe : " ) );
    pushButtonOK->setProperty( "text", tr( "&Valider" ) );
    pushButtonOK->setProperty( "accel", QKeySequence( tr( "Alt+V" ) ) );
    pushButtonAnnuler->setProperty( "text", tr( "Annu&ler" ) );
    pushButtonAnnuler->setProperty( "accel", QKeySequence( tr( "Alt+L" ) ) );
}

