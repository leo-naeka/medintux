/****************************************************************************
** Form implementation generated from reading ui file 'Dlg_VigieFiltreConf.ui'
**
** Created: mer. mai 4 22:20:09 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "Dlg_VigieFiltreConf.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtextedit.h>
#include <qlineedit.h>
#include <qtextbrowser.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a Dlg_VigieFiltreConf as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
Dlg_VigieFiltreConf::Dlg_VigieFiltreConf( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setProperty( "name", "Dlg_VigieFiltreConf" );
    Dlg_VigieFiltreConfLayout = new QGridLayout( this, 1, 1, 11, 6, "Dlg_VigieFiltreConfLayout"); 

    pushButton_Annuler = new QPushButton( this, "pushButton_Annuler" );

    Dlg_VigieFiltreConfLayout->addWidget( pushButton_Annuler, 3, 1 );

    pushButton_Ok = new QPushButton( this, "pushButton_Ok" );

    Dlg_VigieFiltreConfLayout->addWidget( pushButton_Ok, 3, 0 );

    layout1 = new QGridLayout( 0, 1, 1, 0, 6, "layout1"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    QFont textLabel2_font(  textLabel2->font() );
    textLabel2_font.setBold( TRUE );
    textLabel2->setFont( textLabel2_font ); 

    layout1->addWidget( textLabel2, 0, 0 );

    textEdit_Authorized = new QTextEdit( this, "textEdit_Authorized" );
    textEdit_Authorized->setProperty( "textFormat", "PlainText" );

    layout1->addWidget( textEdit_Authorized, 1, 0 );

    Dlg_VigieFiltreConfLayout->addMultiCellLayout( layout1, 2, 2, 0, 1 );

    layout2 = new QGridLayout( 0, 1, 1, 0, 6, "layout2"); 

    lineEdit_FiltreName = new QLineEdit( this, "lineEdit_FiltreName" );

    layout2->addWidget( lineEdit_FiltreName, 0, 1 );

    textLabel1 = new QLabel( this, "textLabel1" );
    QFont textLabel1_font(  textLabel1->font() );
    textLabel1_font.setBold( TRUE );
    textLabel1->setFont( textLabel1_font ); 

    layout2->addWidget( textLabel1, 0, 0 );

    Dlg_VigieFiltreConfLayout->addMultiCellLayout( layout2, 1, 1, 0, 1 );

    textBrowser1 = new QTextBrowser( this, "textBrowser1" );
    textBrowser1->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, textBrowser1->sizePolicy().hasHeightForWidth() ) );
    QFont textBrowser1_font(  textBrowser1->font() );
    textBrowser1_font.setItalic( TRUE );
    textBrowser1->setFont( textBrowser1_font ); 

    Dlg_VigieFiltreConfLayout->addMultiCellWidget( textBrowser1, 0, 0, 0, 1 );
    languageChange();
    resize( QSize(354, 392).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Dlg_VigieFiltreConf::~Dlg_VigieFiltreConf()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Dlg_VigieFiltreConf::languageChange()
{
    setProperty( "caption", tr( "Configurer un filtre" ) );
    pushButton_Annuler->setProperty( "text", tr( "Annuler" ) );
    pushButton_Ok->setProperty( "text", tr( "Confirmer" ) );
    textLabel2->setProperty( "text", trUtf8( "\x4c\x69\x73\x74\x65\x20\x64\x65\x73\x20\x72\xc3\xa9\x70\x65\x72\x74\x6f\x69\x72\x65"
    "\x73\x20\xc3\xa0\x20\x61\x66\x66\x69\x63\x68\x65\x72\x20\x64\x61\x6e\x73\x20\x63"
    "\x65\x20\x66\x69\x6c\x74\x72\x65\x20\x28\x75\x6e\x20\x70\x61\x72\x20\x6c\x69\x67"
    "\x6e\x65\x29" ) );
    textLabel1->setProperty( "text", tr( "Nom du filtre" ) );
    textBrowser1->setProperty( "text", trUtf8( "\x55\x6e\x20\x66\x69\x6c\x74\x72\x65\x20\x65\x73\x74\x20\x75\x6e\x65\x20\x6c\x69\x73"
    "\x74\x65\x20\x64\x65\x20\x63\x6c\x61\x73\x73\x65\x75\x72\x73\x20\x28\x75\x6e\x20"
    "\x70\x61\x72\x20\x6c\x69\x67\x6e\x65\x29\x2e\x20\x4c\x6f\x72\x73\x71\x75\x65\x20"
    "\x6c\x65\x20\x66\x69\x6c\x74\x72\x65\x20\x65\x73\x74\x20\x61\x63\x74\x69\x76\xc3"
    "\xa9\x2c\x20\x73\x65\x75\x6c\x73\x20\x63\x65\x73\x20\x63\x6c\x61\x73\x73\x65\x75"
    "\x72\x73\x20\x73\x65\x72\x6f\x6e\x74\x20\x76\x69\x73\x69\x62\x6c\x65\x73\x2e\xa"
    "\x53\x69\x20\x76\x6f\x75\x73\x20\x6d\x6f\x64\x69\x66\x69\x65\x7a\x20\x6c\x65\x20"
    "\x6e\x6f\x6d\x20\x64\x27\x75\x6e\x20\x66\x69\x6c\x74\x72\x65\x20\x64\xc3\xa9\x6a"
    "\xc3\xa0\x20\x65\x78\x69\x73\x74\x61\x6e\x74\x2c\x20\x63\x65\x6c\x61\x20\x63\x72"
    "\xc3\xa9\xc3\xa9\x72\x61\x20\x75\x6e\x20\x6e\x6f\x75\x76\x65\x61\x75\x20\x66\x69"
    "\x6c\x74\x72\x65\x2c\x20\x63\x6f\x70\x69\x65\x20\x64\x65\x20\x63\x65\x6c\x75\x69"
    "\x20\x64\xc3\xa9\x6a\xc3\xa0\x20\x65\x78\x69\x73\x74\x61\x6e\x74\x2c\x20\x61\x76"
    "\x65\x63\x20\x6c\x65\x20\x6e\x6f\x75\x76\x65\x61\x75\x20\x6e\x6f\x6d\x2e\x20\x43"
    "\x65\x6c\x61\x20\x65\x73\x74\x20\x75\x74\x69\x6c\x65\x20\x70\x6f\x75\x72\x20\x63"
    "\x72\xc3\xa9\x65\x72\x20\x64\x65\x73\x20\x6e\x6f\x75\x76\x65\x61\x75\x78\x20\x66"
    "\x69\x6c\x74\x72\x65\x73\x20\xc3\xa0\x20\x70\x61\x72\x74\x69\x72\x20\x64\x27\x75"
    "\x6e\x20\x6d\x6f\x64\xc3\xa8\x6c\x65\x2e" ) );
}

