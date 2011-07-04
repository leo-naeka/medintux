/****************************************************************************
** Form implementation generated from reading ui file '../../gest_user/src/Dlg_PermsUserChoice.ui'
**
** Created: mer. mai 4 22:19:12 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "Dlg_PermsUserChoice.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qsplitter.h>
#include <qlabel.h>
#include <qheader.h>
#include <qlistview.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "CApp.h"
#include "../../drtux/src/CMoteur_Base.h"
#include "../../../gest_user/src/Dlg_PermsUserChoice.ui.h"

/*
 *  Constructs a Dlg_PermsUserChoice as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
Dlg_PermsUserChoice::Dlg_PermsUserChoice( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setProperty( "name", "Dlg_PermsUserChoice" );
    QFont f( font() );
    f.setPointSize( 9 );
    f.setBold( TRUE );
    setFont( f ); 
    Dlg_PermsUserChoiceLayout = new QGridLayout( this, 1, 1, 11, 6, "Dlg_PermsUserChoiceLayout"); 

    splitter1 = new QSplitter( this, "splitter1" );
    splitter1->setProperty( "orientation", "Horizontal" );

    pushButtonOk = new QPushButton( splitter1, "pushButtonOk" );

    pushButtonAnnuler = new QPushButton( splitter1, "pushButtonAnnuler" );

    Dlg_PermsUserChoiceLayout->addWidget( splitter1, 5, 0 );

    textLabel_Entete = new QLabel( this, "textLabel_Entete" );
    textLabel_Entete->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)5, 0, 0, textLabel_Entete->sizePolicy().hasHeightForWidth() ) );
    QFont textLabel_Entete_font(  textLabel_Entete->font() );
    textLabel_Entete->setFont( textLabel_Entete_font ); 
    textLabel_Entete->setProperty( "frameShape", "WinPanel" );
    textLabel_Entete->setProperty( "frameShadow", "Plain" );
    textLabel_Entete->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignCenter ) );

    Dlg_PermsUserChoiceLayout->addWidget( textLabel_Entete, 0, 0 );

    ListView_UserList = new QListView( this, "ListView_UserList" );
    ListView_UserList->addColumn( tr( "Login" ) );
    ListView_UserList->addColumn( tr( "Nom                  " ) );
    ListView_UserList->addColumn( trUtf8( "\x50\x72\xc3\xa9\x6e\x6f\x6d" ) );
    ListView_UserList->addColumn( tr( "ID" ) );
    ListView_UserList->addColumn( tr( "GUID" ) );
    ListView_UserList->setProperty( "paletteBackgroundColor", QColor( 115, 195, 195 ) );
    ListView_UserList->setProperty( "acceptDrops", QVariant( TRUE, 0 ) );
    ListView_UserList->setProperty( "frameShape", "StyledPanel" );
    ListView_UserList->setProperty( "frameShadow", "Sunken" );
    ListView_UserList->setProperty( "selectionMode", "Extended" );
    ListView_UserList->setProperty( "rootIsDecorated", QVariant( FALSE, 0 ) );

    Dlg_PermsUserChoiceLayout->addWidget( ListView_UserList, 4, 0 );

    buttonGroup1 = new QButtonGroup( this, "buttonGroup1" );
    buttonGroup1->setProperty( "margin", 3 );
    buttonGroup1->setColumnLayout(0, Qt::Vertical );
    buttonGroup1->layout()->setSpacing( 0 );
    buttonGroup1->layout()->setMargin( 5 );
    buttonGroup1Layout = new QGridLayout( buttonGroup1->layout() );
    buttonGroup1Layout->setAlignment( Qt::AlignTop );

    radioButtonContient = new QRadioButton( buttonGroup1, "radioButtonContient" );
    QFont radioButtonContient_font(  radioButtonContient->font() );
    radioButtonContient_font.setFamily( "Helvetica" );
    radioButtonContient->setFont( radioButtonContient_font ); 

    buttonGroup1Layout->addWidget( radioButtonContient, 1, 0 );

    radioButtonCommence = new QRadioButton( buttonGroup1, "radioButtonCommence" );
    QFont radioButtonCommence_font(  radioButtonCommence->font() );
    radioButtonCommence_font.setFamily( "Helvetica" );
    radioButtonCommence->setFont( radioButtonCommence_font ); 

    buttonGroup1Layout->addWidget( radioButtonCommence, 0, 0 );

    Dlg_PermsUserChoiceLayout->addWidget( buttonGroup1, 1, 0 );

    lineEditNom = new QLineEdit( this, "lineEditNom" );
    lineEditNom->setProperty( "frameShape", "LineEditPanel" );
    lineEditNom->setProperty( "frameShadow", "Sunken" );

    Dlg_PermsUserChoiceLayout->addWidget( lineEditNom, 2, 0 );

    layout1 = new QHBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)4, (QSizePolicy::SizeType)5, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( textLabel1 );

    comboBox_Specialites = new QComboBox( FALSE, this, "comboBox_Specialites" );
    layout1->addWidget( comboBox_Specialites );

    Dlg_PermsUserChoiceLayout->addLayout( layout1, 3, 0 );
    languageChange();
    resize( QSize(409, 606).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( pushButtonOk, SIGNAL( clicked() ), this, SLOT( pushButtonOk_clicked() ) );
    connect( pushButtonAnnuler, SIGNAL( clicked() ), this, SLOT( pushButtonAnnuler_clicked() ) );
    connect( ListView_UserList, SIGNAL( doubleClicked(QListViewItem*) ), this, SLOT( ListView_UserList_doubleClicked(QListViewItem*) ) );
    connect( lineEditNom, SIGNAL( textChanged(const QString&) ), this, SLOT( lineEditNom_textChanged(const QString&) ) );
    connect( comboBox_Specialites, SIGNAL( activated(const QString&) ), this, SLOT( comboBox_Specialites_activated(const QString&) ) );
    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
Dlg_PermsUserChoice::~Dlg_PermsUserChoice()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Dlg_PermsUserChoice::languageChange()
{
    setProperty( "caption", trUtf8( "\x53\xc3\xa9\x6c\x65\x63\x74\x69\x6f\x6e\x20\x64\x65\x73\x20\x75\x74\x69\x6c\x69\x73"
    "\x61\x74\x65\x75\x72\x73" ) );
    pushButtonOk->setProperty( "text", tr( "&Confirmer" ) );
    pushButtonOk->setProperty( "accel", QKeySequence( tr( "Alt+C" ) ) );
    pushButtonAnnuler->setProperty( "text", tr( "&Annuler" ) );
    pushButtonAnnuler->setProperty( "accel", QKeySequence( tr( "Alt+A" ) ) );
    textLabel_Entete->setProperty( "text", trUtf8( "\x3c\x62\x3e\x53\xc3\xa9\x6c\x65\x63\x74\x69\x6f\x6e\x6e\x65\x7a\x20\x6c\x65\x73\x20"
    "\x75\x74\x69\x6c\x69\x73\x61\x74\x65\x75\x72\x73\x20\x64\xc3\xa9\x6c\xc3\xa9\x67"
    "\x75\xc3\xa9\x73\x3c\x62\x72\x3e\xa\x71\x75\x69\x20\x73\x65\x72\x6f\x6e\x74"
    "\x20\x61\x75\x74\x6f\x72\x69\x73\xc3\xa9\x73\x20\xc3\xa0\x20\x75\x74\x69\x6c\x69"
    "\x73\x65\x72\x20\x4d\x65\x64\x69\x6e\x54\x75\x78\x20\x20\x3c\x62\x72\x3e\x65\x6e"
    "\x20\x76\x6f\x74\x72\x65\x20\x6e\x6f\x6d\x20\x65\x74\x20\x61\x76\x65\x63\x20\x76"
    "\x6f\x73\x20\x65\x6e\x2d\x74\xc3\xaa\x74\x65\x73\x3c\x2f\x62\x3e" ) );
    ListView_UserList->header()->setLabel( 0, tr( "Login" ) );
    ListView_UserList->header()->setLabel( 1, tr( "Nom                  " ) );
    ListView_UserList->header()->setLabel( 2, trUtf8( "\x50\x72\xc3\xa9\x6e\x6f\x6d" ) );
    ListView_UserList->header()->setLabel( 3, tr( "ID" ) );
    ListView_UserList->header()->setLabel( 4, tr( "GUID" ) );
    buttonGroup1->setProperty( "title", QString::null );
    radioButtonContient->setProperty( "text", tr( "Con&tient" ) );
    radioButtonContient->setProperty( "accel", QKeySequence( tr( "Alt+T" ) ) );
    radioButtonCommence->setProperty( "text", tr( "Co&mmence par" ) );
    radioButtonCommence->setProperty( "accel", QKeySequence( tr( "Alt+M" ) ) );
    textLabel1->setProperty( "text", tr( "Qualification" ) );
}

