/****************************************************************************
** Form implementation generated from reading ui file 'Dock_Menu.ui'
**
** Created: mer. mai 4 22:20:04 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "Dock_Menu.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qlabel.h>
#include <qheader.h>
#include <qlistview.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "../Dock_Menu.ui.h"

/*
 *  Constructs a Dock_Menu as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
Dock_Menu::Dock_Menu( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setProperty( "name", "Dock_Menu" );
    setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)3, 0, 0, sizePolicy().hasHeightForWidth() ) );
    setProperty( "minimumSize", QSize( 50, 0 ) );
    setProperty( "maximumSize", QSize( 32767, 32767 ) );
    Dock_MenuLayout = new QGridLayout( this, 1, 1, 5, 6, "Dock_MenuLayout"); 

    layout5 = new QHBoxLayout( 0, 0, 6, "layout5"); 

    but_NewIdent = new QPushButton( this, "but_NewIdent" );
    but_NewIdent->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 26, 26, but_NewIdent->sizePolicy().hasHeightForWidth() ) );
    but_NewIdent->setProperty( "minimumSize", QSize( 20, 20 ) );
    but_NewIdent->setProperty( "maximumSize", QSize( 20, 20 ) );
    but_NewIdent->setProperty( "toggleButton", QVariant( FALSE, 0 ) );
    but_NewIdent->setProperty( "flat", QVariant( TRUE, 0 ) );
    layout5->addWidget( but_NewIdent );

    m_LineEdit_ToSearch = new QLineEdit( this, "m_LineEdit_ToSearch" );
    m_LineEdit_ToSearch->setProperty( "frameShape", "LineEditPanel" );
    m_LineEdit_ToSearch->setProperty( "frameShadow", "Sunken" );
    layout5->addWidget( m_LineEdit_ToSearch );

    Dock_MenuLayout->addLayout( layout5, 1, 0 );

    m_Text_Note = new QTextEdit( this, "m_Text_Note" );
    m_Text_Note->setProperty( "minimumSize", QSize( 50, 0 ) );
    m_Text_Note->setProperty( "maximumSize", QSize( 32767, 100 ) );
    m_Text_Note->setProperty( "readOnly", QVariant( FALSE, 0 ) );
    m_Text_Note->setProperty( "undoRedoEnabled", QVariant( TRUE, 0 ) );

    Dock_MenuLayout->addWidget( m_Text_Note, 4, 0 );

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setProperty( "minimumSize", QSize( 0, 22 ) );
    textLabel1->setProperty( "maximumSize", QSize( 32767, 22 ) );
    textLabel1->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignCenter ) );

    Dock_MenuLayout->addWidget( textLabel1, 0, 0 );

    layout7 = new QVBoxLayout( 0, 0, 2, "layout7"); 

    layout6 = new QHBoxLayout( 0, 0, 2, "layout6"); 
    layout7->addLayout( layout6 );

    m_ListView_AccesRapide = new QListView( this, "m_ListView_AccesRapide" );
    m_ListView_AccesRapide->setProperty( "minimumSize", QSize( 50, 0 ) );
    m_ListView_AccesRapide->setProperty( "maximumSize", QSize( 32767, 32767 ) );
    m_ListView_AccesRapide->setProperty( "paletteBackgroundColor", QColor( 255, 255, 255 ) );
    m_ListView_AccesRapide->setProperty( "frameShadow", "Sunken" );
    m_ListView_AccesRapide->setProperty( "resizePolicy", "Manual" );
    m_ListView_AccesRapide->setProperty( "selectionMode", "Single" );
    m_ListView_AccesRapide->setProperty( "allColumnsShowFocus", QVariant( TRUE, 0 ) );
    m_ListView_AccesRapide->setProperty( "rootIsDecorated", QVariant( TRUE, 0 ) );
    m_ListView_AccesRapide->setProperty( "showToolTips", QVariant( TRUE, 0 ) );
    m_ListView_AccesRapide->setProperty( "resizeMode", "AllColumns" );
    layout7->addWidget( m_ListView_AccesRapide );

    Dock_MenuLayout->addLayout( layout7, 3, 0 );

    layout6_2 = new QHBoxLayout( 0, 0, 6, "layout6_2"); 

    m_Lbl_Sexe = new QLabel( this, "m_Lbl_Sexe" );
    m_Lbl_Sexe->setProperty( "minimumSize", QSize( 30, 50 ) );
    m_Lbl_Sexe->setProperty( "maximumSize", QSize( 50, 50 ) );
    m_Lbl_Sexe->setProperty( "scaledContents", QVariant( TRUE, 0 ) );
    layout6_2->addWidget( m_Lbl_Sexe );

    m_Lbl_Nom = new QLabel( this, "m_Lbl_Nom" );
    m_Lbl_Nom->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignVCenter ) );
    layout6_2->addWidget( m_Lbl_Nom );
    spacer2_2 = new QSpacerItem( 45, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout6_2->addItem( spacer2_2 );

    layout5_2 = new QHBoxLayout( 0, 0, 6, "layout5_2"); 

    but_ZoomPlus = new QPushButton( this, "but_ZoomPlus" );
    but_ZoomPlus->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 16, 16, but_ZoomPlus->sizePolicy().hasHeightForWidth() ) );
    but_ZoomPlus->setProperty( "minimumSize", QSize( 20, 20 ) );
    but_ZoomPlus->setProperty( "maximumSize", QSize( 20, 20 ) );
    but_ZoomPlus->setProperty( "toggleButton", QVariant( FALSE, 0 ) );
    but_ZoomPlus->setProperty( "flat", QVariant( TRUE, 0 ) );
    layout5_2->addWidget( but_ZoomPlus );

    but_ZoomMinus = new QPushButton( this, "but_ZoomMinus" );
    but_ZoomMinus->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 20, 20, but_ZoomMinus->sizePolicy().hasHeightForWidth() ) );
    but_ZoomMinus->setProperty( "minimumSize", QSize( 20, 20 ) );
    but_ZoomMinus->setProperty( "maximumSize", QSize( 20, 20 ) );
    but_ZoomMinus->setProperty( "toggleButton", QVariant( FALSE, 0 ) );
    but_ZoomMinus->setProperty( "flat", QVariant( TRUE, 0 ) );
    layout5_2->addWidget( but_ZoomMinus );

    but_ZoomDefault = new QPushButton( this, "but_ZoomDefault" );
    but_ZoomDefault->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 20, 20, but_ZoomDefault->sizePolicy().hasHeightForWidth() ) );
    but_ZoomDefault->setProperty( "minimumSize", QSize( 20, 20 ) );
    but_ZoomDefault->setProperty( "maximumSize", QSize( 20, 20 ) );
    but_ZoomDefault->setProperty( "toggleButton", QVariant( FALSE, 0 ) );
    but_ZoomDefault->setProperty( "flat", QVariant( TRUE, 0 ) );
    layout5_2->addWidget( but_ZoomDefault );
    layout6_2->addLayout( layout5_2 );

    Dock_MenuLayout->addLayout( layout6_2, 2, 0 );
    languageChange();
    resize( QSize(296, 360).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( m_ListView_AccesRapide, SIGNAL( contextMenuRequested(QListViewItem*,const QPoint&,int) ), this, SLOT( m_ListView_AccesRapide_contextMenuRequested(QListViewItem*,const QPoint&,int) ) );
    connect( m_Text_Note, SIGNAL( textChanged() ), this, SLOT( m_Text_Note_textChanged() ) );
    connect( m_ListView_AccesRapide, SIGNAL( clicked(QListViewItem*,const QPoint&,int) ), this, SLOT( m_ListView_AccesRapide_clicked(QListViewItem*,const QPoint&,int) ) );
    connect( m_LineEdit_ToSearch, SIGNAL( returnPressed() ), this, SLOT( m_LineEdit_ToSearch_returnPressed() ) );
    connect( but_NewIdent, SIGNAL( clicked() ), this, SLOT( but_NewIdent_clicked() ) );
    connect( but_ZoomPlus, SIGNAL( clicked() ), this, SLOT( but_ZoomPlus_clicked() ) );
    connect( but_ZoomMinus, SIGNAL( clicked() ), this, SLOT( but_ZoomMinus_clicked() ) );
    connect( but_ZoomDefault, SIGNAL( clicked() ), this, SLOT( but_ZoomDefault_clicked() ) );
    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
Dock_Menu::~Dock_Menu()
{
    destroy();
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Dock_Menu::languageChange()
{
    setProperty( "caption", tr( "Dock_Menu" ) );
    but_NewIdent->setProperty( "text", QString::null );
    QToolTip::add( but_NewIdent, trUtf8( "\x43\x72\xc3\xa9\x65\x72\x20\x75\x6e\x20\x6e\x6f\x75\x76\x65\x61\x75\x20\x64\x6f\x73"
    "\x73\x69\x65\x72\x20\x70\x61\x74\x69\x65\x6e\x74" ) );
    QToolTip::add( m_LineEdit_ToSearch, trUtf8( "\x53\x61\x69\x73\x69\x65\x20\x64\x75\x20\x6e\x6f\x6d\x3b\x70\x72\xc3\xa9\x6e\x6f\x6d"
    "\x20\x64\x27\x75\x6e\x20\x6e\x6f\x75\x76\x65\x61\x75\x20\x70\x61\x74\x69\x65\x6e"
    "\x74\x2e\x20\x28\x61\x70\x70\x75\x79\x65\x72\x20\x73\x75\x72\x20\x74\x6f\x75\x63"
    "\x68\x65\x20\x45\x6e\x74\x72\xc3\xa9\x65\x20\x70\x6f\x75\x72\x20\x63\x6f\x6e\x66"
    "\x69\x72\x6d\x65\x72\x29" ) );
    textLabel1->setProperty( "text", trUtf8( "\x3c\x62\x3e\x41\x63\x63\xc3\xa8\x73\x20\x52\x61\x70\x69\x64\x65\x3c\x2f\x62\x3e" ) );
    QToolTip::add( m_ListView_AccesRapide, trUtf8( "\x41\x63\x63\xc3\xa8\x73\x20\x72\x61\x70\x69\x64\x65\x20\x61\x75\x78\x20\xc3\xa9\x6c"
    "\xc3\xa9\x6d\x65\x6e\x74\x73\x20\x64\x75\x20\x64\x6f\x73\x73\x69\x65\x72\x20\x6d"
    "\xc3\xa9\x64\x69\x63\x61\x6c" ) );
    QWhatsThis::add( m_ListView_AccesRapide, trUtf8( "\x41\x63\x63\xc3\xa8\x73\x20\x72\x61\x70\x69\x64\x65\x20\x61\x75\x78\x20\xc3\xa9\x6c"
    "\xc3\xa9\x6d\x65\x6e\x74\x73\x20\x64\x75\x20\x64\x6f\x73\x73\x69\x65\x72\x20\x6d"
    "\xc3\xa9\x64\x69\x63\x61\x6c" ) );
    m_Lbl_Nom->setProperty( "text", tr( "textLabel1" ) );
    but_ZoomPlus->setProperty( "text", QString::null );
    QToolTip::add( but_ZoomPlus, tr( "Augmente le zoom" ) );
    but_ZoomMinus->setProperty( "text", QString::null );
    QToolTip::add( but_ZoomMinus, tr( "Diminue le zoom" ) );
    but_ZoomDefault->setProperty( "text", QString::null );
    QToolTip::add( but_ZoomDefault, trUtf8( "\x5a\x6f\x6f\x6d\x20\x70\x61\x72\x20\x64\xc3\xa9\x66\x61\x75\x74" ) );
}

