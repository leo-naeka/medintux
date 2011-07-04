/****************************************************************************
** Form implementation generated from reading ui file 'Dock_TabRubrique.ui'
**
** Created: mer. mai 4 22:19:06 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "Dock_TabRubrique.h"

#include <qvariant.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "Rubriques.h"
#include "CApp.h"
#include "../Dock_TabRubrique.ui.h"

/*
 *  Constructs a Dock_TabRubrique as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
Dock_TabRubrique::Dock_TabRubrique( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setProperty( "name", "Dock_TabRubrique" );
    setProperty( "minimumSize", QSize( 100, 100 ) );
    setProperty( "maximumSize", QSize( 32767, 32767 ) );
    Dock_TabRubriqueLayout = new QGridLayout( this, 1, 1, 11, 6, "Dock_TabRubriqueLayout"); 
    languageChange();
    resize( QSize(131, 245).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
Dock_TabRubrique::~Dock_TabRubrique()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Dock_TabRubrique::languageChange()
{
    setProperty( "caption", tr( "Dock_TabRubrique" ) );
}

