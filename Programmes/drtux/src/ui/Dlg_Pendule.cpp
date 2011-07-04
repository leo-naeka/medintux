/****************************************************************************
** Form implementation generated from reading ui file 'Dlg_Pendule.ui'
**
** Created: mer. mai 4 22:20:09 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "Dlg_Pendule.h"

#include <qvariant.h>
#include <qlineedit.h>
#include <qdatetimeedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a Dlg_Pendule as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
Dlg_Pendule::Dlg_Pendule( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setProperty( "name", "Dlg_Pendule" );
    QFont f( font() );
    f.setPointSize( 10 );
    setFont( f ); 
    Dlg_PenduleLayout = new QGridLayout( this, 1, 1, 1, 6, "Dlg_PenduleLayout"); 

    lineEdit_MinutesRef = new QLineEdit( this, "lineEdit_MinutesRef" );
    lineEdit_MinutesRef->setProperty( "paletteForegroundColor", QColor( 37, 125, 241 ) );
    lineEdit_MinutesRef->setProperty( "paletteBackgroundColor", QColor( 255, 255, 127 ) );
    QFont lineEdit_MinutesRef_font(  lineEdit_MinutesRef->font() );
    lineEdit_MinutesRef_font.setPointSize( 12 );
    lineEdit_MinutesRef_font.setBold( TRUE );
    lineEdit_MinutesRef->setFont( lineEdit_MinutesRef_font ); 
    lineEdit_MinutesRef->setProperty( "frameShape", "LineEditPanel" );
    lineEdit_MinutesRef->setProperty( "frameShadow", "Sunken" );
    lineEdit_MinutesRef->setProperty( "alignment", int( QLineEdit::AlignHCenter ) );
    lineEdit_MinutesRef->setProperty( "readOnly", QVariant( TRUE, 0 ) );

    Dlg_PenduleLayout->addWidget( lineEdit_MinutesRef, 0, 0 );

    layout_Button = new QHBoxLayout( 0, 0, 6, "layout_Button"); 

    timeEdit_Temps = new QTimeEdit( this, "timeEdit_Temps" );
    QFont timeEdit_Temps_font(  timeEdit_Temps->font() );
    timeEdit_Temps_font.setPointSize( 9 );
    timeEdit_Temps->setFont( timeEdit_Temps_font ); 
    layout_Button->addWidget( timeEdit_Temps );

    pushButton_Ok = new QPushButton( this, "pushButton_Ok" );
    pushButton_Ok->setProperty( "maximumSize", QSize( 30, 32767 ) );
    QFont pushButton_Ok_font(  pushButton_Ok->font() );
    pushButton_Ok_font.setPointSize( 9 );
    pushButton_Ok->setFont( pushButton_Ok_font ); 
    layout_Button->addWidget( pushButton_Ok );

    pushButton_Exit = new QPushButton( this, "pushButton_Exit" );
    pushButton_Exit->setProperty( "maximumSize", QSize( 55, 32767 ) );
    QFont pushButton_Exit_font(  pushButton_Exit->font() );
    pushButton_Exit_font.setPointSize( 9 );
    pushButton_Exit->setFont( pushButton_Exit_font ); 
    pushButton_Exit->setProperty( "flat", QVariant( FALSE, 0 ) );
    layout_Button->addWidget( pushButton_Exit );

    Dlg_PenduleLayout->addLayout( layout_Button, 1, 0 );
    languageChange();
    resize( QSize(176, 238).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Dlg_Pendule::~Dlg_Pendule()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Dlg_Pendule::languageChange()
{
    setProperty( "caption", tr( "Saisie de l'heure" ) );
    pushButton_Ok->setProperty( "text", tr( "&Ok" ) );
    pushButton_Ok->setProperty( "accel", QKeySequence( tr( "Alt+O" ) ) );
    pushButton_Exit->setProperty( "text", tr( "&Quitter" ) );
    pushButton_Exit->setProperty( "accel", QKeySequence( tr( "Alt+Q" ) ) );
}

