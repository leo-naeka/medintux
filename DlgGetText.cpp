/****************************************************************************
** Form implementation generated from reading ui file 'DlgGetText.ui'
**
** Created: mer. mai 4 22:19:24 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "DlgGetText.h"

#include <qvariant.h>
#include <qtextedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "../DlgGetText.ui.h"

/*
 *  Constructs a DlgGetText as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
DlgGetText::DlgGetText( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setProperty( "name", "DlgGetText" );
    DlgGetTextLayout = new QGridLayout( this, 1, 1, 11, 6, "DlgGetTextLayout"); 

    textEdit = new QTextEdit( this, "textEdit" );

    DlgGetTextLayout->addMultiCellWidget( textEdit, 0, 0, 0, 3 );

    pushButtonOK = new QPushButton( this, "pushButtonOK" );
    pushButtonOK->setProperty( "maximumSize", QSize( 100, 30 ) );

    DlgGetTextLayout->addWidget( pushButtonOK, 1, 0 );

    pushButtonCancel = new QPushButton( this, "pushButtonCancel" );
    pushButtonCancel->setProperty( "maximumSize", QSize( 100, 30 ) );

    DlgGetTextLayout->addWidget( pushButtonCancel, 1, 1 );

    pushButtonClearAndQuit = new QPushButton( this, "pushButtonClearAndQuit" );
    pushButtonClearAndQuit->setProperty( "maximumSize", QSize( 130, 30 ) );

    DlgGetTextLayout->addWidget( pushButtonClearAndQuit, 1, 2 );
    spacer1 = new QSpacerItem( 205, 16, QSizePolicy::Expanding, QSizePolicy::Minimum );
    DlgGetTextLayout->addItem( spacer1, 1, 3 );
    languageChange();
    resize( QSize(518, 140).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( pushButtonOK, SIGNAL( clicked() ), this, SLOT( pushButtonOK_clicked() ) );
    connect( pushButtonCancel, SIGNAL( clicked() ), this, SLOT( pushButtonCancel_clicked() ) );
    connect( pushButtonClearAndQuit, SIGNAL( clicked() ), this, SLOT( pushButtonClearAndQuit_clicked() ) );

    // tab order
    setTabOrder( textEdit, pushButtonOK );
    setTabOrder( pushButtonOK, pushButtonCancel );
    setTabOrder( pushButtonCancel, pushButtonClearAndQuit );
}

/*
 *  Destroys the object and frees any allocated resources
 */
DlgGetText::~DlgGetText()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void DlgGetText::languageChange()
{
    setProperty( "caption", tr( "Saisissez un texte" ) );
    pushButtonOK->setProperty( "text", tr( "&Valider" ) );
    pushButtonOK->setProperty( "accel", QKeySequence( tr( "Alt+V" ) ) );
    pushButtonCancel->setProperty( "text", tr( "Annu&ler" ) );
    pushButtonCancel->setProperty( "accel", QKeySequence( tr( "Alt+L" ) ) );
    pushButtonClearAndQuit->setProperty( "text", tr( "Effacer et &quitter" ) );
    pushButtonClearAndQuit->setProperty( "accel", QKeySequence( tr( "Alt+Q" ) ) );
}

