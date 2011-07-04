/****************************************************************************
** Form implementation generated from reading ui file '../../MedinTuxTools/DLG_InsertList.ui'
**
** Created: mer. mai 4 22:19:13 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "DLG_InsertList.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlistbox.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "../../../MedinTuxTools/DLG_InsertList.ui.h"

/*
 *  Constructs a Dlg_InsertList as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
Dlg_InsertList::Dlg_InsertList( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setProperty( "name", "Dlg_InsertList" );
    Dlg_InsertListLayout = new QGridLayout( this, 1, 1, 11, 6, "Dlg_InsertListLayout"); 

    pushButtonOk = new QPushButton( this, "pushButtonOk" );

    Dlg_InsertListLayout->addWidget( pushButtonOk, 1, 1 );
    spacer1 = new QSpacerItem( 224, 16, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Dlg_InsertListLayout->addItem( spacer1, 1, 0 );

    layout1 = new QGridLayout( 0, 1, 1, 0, 0, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );

    layout1->addWidget( textLabel1, 0, 0 );

    listBox_InsertList = new QListBox( this, "listBox_InsertList" );

    layout1->addMultiCellWidget( listBox_InsertList, 1, 1, 0, 1 );

    lineEdit_Find = new QLineEdit( this, "lineEdit_Find" );
    lineEdit_Find->setProperty( "frameShape", "LineEditPanel" );
    lineEdit_Find->setProperty( "frameShadow", "Sunken" );

    layout1->addWidget( lineEdit_Find, 0, 1 );

    Dlg_InsertListLayout->addMultiCellLayout( layout1, 0, 0, 0, 1 );
    languageChange();
    resize( QSize(334, 463).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
Dlg_InsertList::~Dlg_InsertList()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Dlg_InsertList::languageChange()
{
    setProperty( "caption", tr( "Liste d'insertion" ) );
    pushButtonOk->setProperty( "text", tr( "Ok" ) );
    textLabel1->setProperty( "text", tr( "Rechercher :" ) );
}

