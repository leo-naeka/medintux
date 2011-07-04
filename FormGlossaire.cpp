/****************************************************************************
** Form implementation generated from reading ui file 'FormGlossaire.ui'
**
** Created: mer. mai 4 22:19:07 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "FormGlossaire.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a FormGlossaire as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
FormGlossaire::FormGlossaire( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setProperty( "name", "FormGlossaire" );
    setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)3, 0, 0, sizePolicy().hasHeightForWidth() ) );
    FormGlossaireLayout = new QGridLayout( this, 1, 1, 0, 0, "FormGlossaireLayout"); 

    layout3 = new QGridLayout( 0, 1, 1, 0, 6, "layout3"); 

    pushButtonNewDir = new QPushButton( this, "pushButtonNewDir" );
    pushButtonNewDir->setProperty( "maximumSize", QSize( 32, 32 ) );

    layout3->addWidget( pushButtonNewDir, 0, 3 );

    pushButtonBack = new QPushButton( this, "pushButtonBack" );
    pushButtonBack->setProperty( "maximumSize", QSize( 32, 32 ) );

    layout3->addWidget( pushButtonBack, 0, 0 );
    spacer1 = new QSpacerItem( 90, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout3->addItem( spacer1, 0, 6 );

    pushButtonEdit = new QPushButton( this, "pushButtonEdit" );
    pushButtonEdit->setProperty( "maximumSize", QSize( 32, 32 ) );

    layout3->addWidget( pushButtonEdit, 0, 2 );

    pushButtonMenu = new QPushButton( this, "pushButtonMenu" );
    pushButtonMenu->setProperty( "maximumSize", QSize( 32, 32 ) );

    layout3->addWidget( pushButtonMenu, 0, 5 );

    pushButtonHome = new QPushButton( this, "pushButtonHome" );
    pushButtonHome->setProperty( "maximumSize", QSize( 32, 32 ) );

    layout3->addWidget( pushButtonHome, 0, 1 );

    pushButtonLocalise = new QPushButton( this, "pushButtonLocalise" );
    pushButtonLocalise->setProperty( "maximumSize", QSize( 32, 32 ) );

    layout3->addWidget( pushButtonLocalise, 0, 4 );

    FormGlossaireLayout->addLayout( layout3, 0, 0 );
    languageChange();
    resize( QSize(331, 364).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
FormGlossaire::~FormGlossaire()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void FormGlossaire::languageChange()
{
    setProperty( "caption", tr( "InvisibleStringFormGlossaire" ) );
    pushButtonNewDir->setProperty( "text", QString::null );
    QToolTip::add( pushButtonNewDir, trUtf8( "\x43\x72\xc3\xa9\x65\x72\x20\x75\x6e\x20\x72\xc3\xa9\x70\x65\x72\x74\x6f\x69\x72\x65"
    "\x20\x64\x75\x20\x67\x6c\x6f\x73\x73\x61\x69\x72\x65" ) );
    pushButtonBack->setProperty( "text", QString::null );
    QToolTip::add( pushButtonBack, trUtf8( "\x52\x65\x6d\x6f\x6e\x74\x65\x72\x20\x64\x27\x75\x6e\x20\x72\xc3\xa9\x70\x65\x72\x74"
    "\x6f\x69\x72\x65\x20\x65\x6e\x20\x61\x72\x72\x69\xc3\xa8\x72\x65" ) );
    pushButtonEdit->setProperty( "text", QString::null );
    QToolTip::add( pushButtonEdit, tr( "Outils de modification des documents" ) );
    pushButtonMenu->setProperty( "text", QString::null );
    QToolTip::add( pushButtonMenu, tr( "Activer et afficher une rubrique..." ) );
    pushButtonHome->setProperty( "text", QString::null );
    QToolTip::add( pushButtonHome, trUtf8( "\x41\x6c\x6c\x65\x72\x20\x61\x75\x20\x72\xc3\xa9\x70\x65\x72\x74\x6f\x69\x72\x65\x20"
    "\x72\x61\x63\x69\x6e\x65\x20\x64\x65\x73\x20\x64\x6f\x63\x75\x6d\x65\x6e\x74\x73"
    "" ) );
    pushButtonLocalise->setProperty( "text", QString::null );
    QToolTip::add( pushButtonLocalise, trUtf8( "\x43\x68\x6f\x69\x73\x69\x72\x20\x75\x6e\x20\x72\xc3\xa9\x70\x65\x72\x74\x6f\x69\x72"
    "\x65\x20\x67\x6c\x6f\x73\x73\x61\x69\x72\x65" ) );
}

