/****************************************************************************
** Form implementation generated from reading ui file 'Dlg_HtmlView.ui'
**
** Created: mer. mai 4 22:19:45 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "Dlg_HtmlView.h"

#include <qvariant.h>
#include <qdir.h>
#include <qtextbrowser.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "CApp.h"
#include "../Dlg_HtmlView.ui.h"

/*
 *  Constructs a Dlg_HtmlView as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
Dlg_HtmlView::Dlg_HtmlView( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setProperty( "name", "Dlg_HtmlView" );
    Dlg_HtmlViewLayout = new QGridLayout( this, 1, 1, 11, 6, "Dlg_HtmlViewLayout"); 

    textBrowser = new QTextBrowser( this, "textBrowser" );

    Dlg_HtmlViewLayout->addWidget( textBrowser, 0, 0 );
    languageChange();
    resize( QSize(590, 475).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
Dlg_HtmlView::~Dlg_HtmlView()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Dlg_HtmlView::languageChange()
{
    setProperty( "caption", tr( "Monographie" ) );
}

