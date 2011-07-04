/****************************************************************************
** Form implementation generated from reading ui file 'DlgDateNom.ui'
**
** Created: mer. mai 4 22:19:26 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "DlgDateNom.h"

#include <qvariant.h>
#include <stdlib.h>
#include <../../MedinTuxTools/CMaskedLineEdit.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "../DlgDateNom.ui.h"

/*
 *  Constructs a DlgDateNom as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
DlgDateNom::DlgDateNom( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setProperty( "name", "DlgDateNom" );
    DlgDateNomLayout = new QGridLayout( this, 1, 1, 11, 6, "DlgDateNomLayout"); 

    layout10 = new QGridLayout( 0, 1, 1, 0, 6, "layout10"); 

    textLabelDate = new QLabel( this, "textLabelDate" );
    textLabelDate->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)5, 0, 0, textLabelDate->sizePolicy().hasHeightForWidth() ) );
    textLabelDate->setProperty( "alignment", int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    layout10->addWidget( textLabelDate, 2, 0 );

    textLabelNom_2 = new QLabel( this, "textLabelNom_2" );
    textLabelNom_2->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)4, (QSizePolicy::SizeType)5, 0, 0, textLabelNom_2->sizePolicy().hasHeightForWidth() ) );
    textLabelNom_2->setProperty( "textFormat", "AutoText" );
    textLabelNom_2->setProperty( "alignment", int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    layout10->addWidget( textLabelNom_2, 1, 0 );

    textLabelNom = new QLabel( this, "textLabelNom" );
    textLabelNom->setProperty( "textFormat", "AutoText" );
    textLabelNom->setProperty( "alignment", int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    layout10->addWidget( textLabelNom, 0, 0 );

    DlgDateNomLayout->addLayout( layout10, 0, 0 );

    layout3 = new QGridLayout( 0, 1, 1, 0, 6, "layout3"); 

    textLabelDate_2 = new QLabel( this, "textLabelDate_2" );
    textLabelDate_2->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)4, (QSizePolicy::SizeType)5, 0, 0, textLabelDate_2->sizePolicy().hasHeightForWidth() ) );
    textLabelDate_2->setProperty( "alignment", int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    layout3->addWidget( textLabelDate_2, 2, 1 );

    lineEdit_SubType = new QLineEdit( this, "lineEdit_SubType" );
    lineEdit_SubType->setProperty( "frameShape", "LineEditPanel" );
    lineEdit_SubType->setProperty( "frameShadow", "Sunken" );
    lineEdit_SubType->setProperty( "maxLength", 40 );

    layout3->addMultiCellWidget( lineEdit_SubType, 1, 1, 0, 5 );

    pushButtonOK = new QPushButton( this, "pushButtonOK" );

    layout3->addWidget( pushButtonOK, 2, 5 );
    spacer2 = new QSpacerItem( 80, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout3->addItem( spacer2, 2, 4 );

    cMaskedLineEditDate = new CMaskedLineEdit( this, "cMaskedLineEditDate" );
    cMaskedLineEditDate->setProperty( "minimumSize", QSize( 100, 0 ) );
    cMaskedLineEditDate->setProperty( "maximumSize", QSize( 100, 32767 ) );
    QFont cMaskedLineEditDate_font(  cMaskedLineEditDate->font() );
    cMaskedLineEditDate->setFont( cMaskedLineEditDate_font ); 
    cMaskedLineEditDate->setProperty( "carMask", 32 );

    layout3->addWidget( cMaskedLineEditDate, 2, 0 );

    lineEditNom = new QLineEdit( this, "lineEditNom" );
    lineEditNom->setProperty( "maxLength", 40 );

    layout3->addMultiCellWidget( lineEditNom, 0, 0, 0, 5 );

    cMaskedLineEditTime = new CMaskedLineEdit( this, "cMaskedLineEditTime" );
    cMaskedLineEditTime->setProperty( "minimumSize", QSize( 100, 0 ) );
    cMaskedLineEditTime->setProperty( "maximumSize", QSize( 100, 32767 ) );
    QFont cMaskedLineEditTime_font(  cMaskedLineEditTime->font() );
    cMaskedLineEditTime->setFont( cMaskedLineEditTime_font ); 
    cMaskedLineEditTime->setProperty( "carMask", 32 );

    layout3->addWidget( cMaskedLineEditTime, 2, 2 );

    pushButtonDateDlg = new QPushButton( this, "pushButtonDateDlg" );
    pushButtonDateDlg->setProperty( "minimumSize", QSize( 22, 22 ) );
    pushButtonDateDlg->setProperty( "maximumSize", QSize( 22, 22 ) );

    layout3->addWidget( pushButtonDateDlg, 2, 3 );

    DlgDateNomLayout->addLayout( layout3, 0, 1 );
    languageChange();
    resize( QSize(506, 98).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( pushButtonOK, SIGNAL( clicked() ), this, SLOT( pushButtonOK_clicked() ) );

    // tab order
    setTabOrder( lineEditNom, pushButtonOK );

    // buddies
    textLabelNom_2->setBuddy( lineEditNom );
    textLabelNom->setBuddy( lineEditNom );
}

/*
 *  Destroys the object and frees any allocated resources
 */
DlgDateNom::~DlgDateNom()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void DlgDateNom::languageChange()
{
    setProperty( "caption", trUtf8( "\x53\x61\x69\x73\x69\x65\x20\x64\x65\x20\x6c\x61\x20\x64\x61\x74\x65\x20\x65\x74\x20"
    "\x64\x65\x20\x6c\x27\x69\x6e\x74\x69\x74\x75\x6c\xc3\xa9\x20\x64\x65\x20\x6c\x61"
    "\x20\x72\x75\x62\x72\x69\x71\x75\x65" ) );
    textLabelDate->setProperty( "text", tr( "Date :" ) );
    textLabelNom_2->setProperty( "text", tr( "Sous &type :" ) );
    textLabelNom->setProperty( "text", trUtf8( "\x26\x49\x6e\x74\x69\x74\x75\x6c\xc3\xa9\x20\x3a" ) );
    textLabelDate_2->setProperty( "text", tr( "Heure :" ) );
    QToolTip::add( lineEdit_SubType, trUtf8( "\x49\x63\x69\x20\x70\x6c\x61\x63\x65\x72\x20\x6c\x65\x20\x73\x6f\x75\x73\x20\x74\x79"
    "\x70\x65\x20\x64\x65\x20\x6c\x61\x20\x72\x75\x62\x72\x69\x71\x75\x65\x2c\x20\x70"
    "\x6f\x75\x72\x20\x6c\x61\x20\x6c\x69\x65\x72\x20\xc3\xa0\x20\x75\x6e\x20\x6d\x6f"
    "\x64\xc3\xa8\x6c\x65\x20\x64\x27\x69\x6d\x70\x72\x65\x73\x73\x69\x6f\x6e\x2e", "\x49\x63\x69\x20\x70\x6c\x61\x63\x65\x72\x20\x6c\x65\x20\x73\x6f\x75\x73\x20\x74\x79"
    "\x70\x65\x20\x64\x65\x20\x6c\x61\x20\x72\x75\x62\x72\x69\x71\x75\x65\x2c\x20\x70"
    "\x6f\x75\x72\x20\x6c\x61\x20\x6c\x69\x65\x72\x20\xc3\xa0\x20\x75\x6e\x20\x6d\x6f"
    "\x64\xc3\xa8\x6c\x65\x20\x64\x27\x69\x6d\x70\x72\x65\x73\x73\x69\x6f\x6e\x2e" ) );
    pushButtonOK->setProperty( "text", tr( "&Valider" ) );
    pushButtonOK->setProperty( "accel", QKeySequence( tr( "Alt+V" ) ) );
    cMaskedLineEditDate->setProperty( "control", tr( "GGGGGGGG" ) );
    cMaskedLineEditDate->setProperty( "mask", tr( "__-__-____" ) );
    cMaskedLineEditDate->setProperty( "text", QString::null );
    QToolTip::add( lineEditNom, trUtf8( "\x49\x63\x69\x20\x70\x6c\x61\x63\x65\x72\x20\x6c\x65\x20\x74\x69\x74\x72\x65\x20\x64"
    "\x65\x20\x6c\x61\x20\x72\x75\x62\x72\x69\x71\x75\x65\x20\x28\x63\x65\x6c\x75\x69"
    "\x20\x61\x66\x66\x69\x63\x68\xc3\xa9\x20\x64\x61\x6e\x73\x20\x6c\x61\x20\x6c\x69"
    "\x73\x74\x65\x20\x64\xc3\xa9\x72\x6f\x75\x6c\x61\x6e\x74\x65\x20\x64\x65\x73\x20"
    "\x72\x75\x62\x72\x69\x71\x75\x65\x73\x29\x2e" ) );
    QWhatsThis::add( lineEditNom, trUtf8( "\x49\x63\x69\x20\x70\x6c\x61\x63\x65\x72\x20\x6c\x65\x20\x74\x69\x74\x72\x65\x20\x64"
    "\x65\x20\x6c\x61\x20\x72\x75\x62\x72\x69\x71\x75\x65\x20\x28\x63\x65\x6c\x75\x69"
    "\x20\x61\x66\x66\x69\x63\x68\xc3\xa9\x20\x64\x61\x6e\x73\x20\x6c\x61\x20\x6c\x69"
    "\x73\x74\x65\x20\x64\xc3\xa9\x72\x6f\x75\x6c\x61\x6e\x74\x65\x20\x64\x65\x73\x20"
    "\x72\x75\x62\x72\x69\x71\x75\x65\x73\x29\x2e" ) );
    cMaskedLineEditTime->setProperty( "control", tr( "GGGG" ) );
    cMaskedLineEditTime->setProperty( "mask", tr( "__:__" ) );
    cMaskedLineEditTime->setProperty( "text", QString::null );
    pushButtonDateDlg->setProperty( "text", QString::null );
    pushButtonDateDlg->setProperty( "accel", QKeySequence( QString::null ) );
    QToolTip::add( pushButtonDateDlg, tr( "Saisie de la date et de l'heure de la rubrique." ) );
}

