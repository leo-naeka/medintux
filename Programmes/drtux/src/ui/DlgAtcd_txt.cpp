/****************************************************************************
** Form implementation generated from reading ui file 'DlgAtcd_txt.ui'
**
** Created: mer. mai 4 22:20:02 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "DlgAtcd_txt.h"

#include <qvariant.h>
#include <../../MedinTuxTools/CMaskedLineEdit.h>
#include <qpushbutton.h>
#include <qframe.h>
#include <qlabel.h>
#include <qcheckbox.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "../DlgAtcd_txt.ui.h"

/*
 *  Constructs a DlgAtcd_txt as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
DlgAtcd_txt::DlgAtcd_txt( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setProperty( "name", "DlgAtcd_txt" );
    DlgAtcd_txtLayout = new QGridLayout( this, 1, 1, 11, 6, "DlgAtcd_txtLayout"); 

    line1 = new QFrame( this, "line1" );
    line1->setProperty( "frameShape", "HLine" );
    line1->setProperty( "frameShadow", "Sunken" );
    line1->setProperty( "frameShape", QFrame::VLine );

    DlgAtcd_txtLayout->addWidget( line1, 1, 0 );

    lbl_Titre = new QLabel( this, "lbl_Titre" );
    lbl_Titre->setProperty( "maximumSize", QSize( 32767, 22 ) );
    lbl_Titre->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignCenter ) );

    DlgAtcd_txtLayout->addWidget( lbl_Titre, 0, 0 );

    layout6 = new QGridLayout( 0, 1, 1, 0, 6, "layout6"); 

    but_Annuler = new QPushButton( this, "but_Annuler" );

    layout6->addWidget( but_Annuler, 0, 2 );
    spacer1 = new QSpacerItem( 45, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout6->addItem( spacer1, 0, 0 );

    but_Valider = new QPushButton( this, "but_Valider" );
    but_Valider->setProperty( "default", QVariant( TRUE, 0 ) );

    layout6->addWidget( but_Valider, 0, 1 );

    DlgAtcd_txtLayout->addLayout( layout6, 9, 0 );

    layout6_2 = new QGridLayout( 0, 1, 1, 0, 6, "layout6_2"); 

    checkBox_IsALD = new QCheckBox( this, "checkBox_IsALD" );

    layout6_2->addWidget( checkBox_IsALD, 0, 0 );

    checkBox_IsActif = new QCheckBox( this, "checkBox_IsActif" );

    layout6_2->addWidget( checkBox_IsActif, 0, 1 );

    DlgAtcd_txtLayout->addLayout( layout6_2, 8, 0 );

    layout18 = new QGridLayout( 0, 1, 1, 0, 6, "layout18"); 

    m_LineEdit_Commentaire = new QLineEdit( this, "m_LineEdit_Commentaire" );

    layout18->addWidget( m_LineEdit_Commentaire, 0, 1 );

    textLabel_Commentaire = new QLabel( this, "textLabel_Commentaire" );
    textLabel_Commentaire->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)4, (QSizePolicy::SizeType)5, 0, 0, textLabel_Commentaire->sizePolicy().hasHeightForWidth() ) );

    layout18->addWidget( textLabel_Commentaire, 0, 0 );

    DlgAtcd_txtLayout->addLayout( layout18, 7, 0 );

    chkDate = new QCheckBox( this, "chkDate" );

    DlgAtcd_txtLayout->addWidget( chkDate, 5, 0 );

    layout21 = new QGridLayout( 0, 1, 1, 0, 6, "layout21"); 

    textLabel_Libelle = new QLabel( this, "textLabel_Libelle" );
    textLabel_Libelle->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)4, (QSizePolicy::SizeType)5, 0, 0, textLabel_Libelle->sizePolicy().hasHeightForWidth() ) );

    layout21->addWidget( textLabel_Libelle, 0, 0 );

    m_LineEdit_Libelle = new QLineEdit( this, "m_LineEdit_Libelle" );
    m_LineEdit_Libelle->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, m_LineEdit_Libelle->sizePolicy().hasHeightForWidth() ) );

    layout21->addWidget( m_LineEdit_Libelle, 0, 1 );

    DlgAtcd_txtLayout->addLayout( layout21, 2, 0 );

    layout21_2 = new QGridLayout( 0, 1, 1, 0, 6, "layout21_2"); 

    textLabel_Libelle_Long = new QLabel( this, "textLabel_Libelle_Long" );
    textLabel_Libelle_Long->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)4, (QSizePolicy::SizeType)5, 0, 0, textLabel_Libelle_Long->sizePolicy().hasHeightForWidth() ) );

    layout21_2->addWidget( textLabel_Libelle_Long, 0, 0 );

    m_LineEdit_Libelle_Long = new QLineEdit( this, "m_LineEdit_Libelle_Long" );
    m_LineEdit_Libelle_Long->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, m_LineEdit_Libelle_Long->sizePolicy().hasHeightForWidth() ) );

    layout21_2->addWidget( m_LineEdit_Libelle_Long, 0, 1 );

    DlgAtcd_txtLayout->addLayout( layout21_2, 3, 0 );

    layout9 = new QGridLayout( 0, 1, 1, 0, 6, "layout9"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    textLabel3_2->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)4, (QSizePolicy::SizeType)5, 0, 0, textLabel3_2->sizePolicy().hasHeightForWidth() ) );
    textLabel3_2->setProperty( "scaledContents", QVariant( TRUE, 0 ) );
    textLabel3_2->setProperty( "alignment", int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    layout9->addWidget( textLabel3_2, 0, 2 );

    pushButtonFamilleGenreEdit = new QPushButton( this, "pushButtonFamilleGenreEdit" );
    pushButtonFamilleGenreEdit->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)2, (QSizePolicy::SizeType)4, 0, 0, pushButtonFamilleGenreEdit->sizePolicy().hasHeightForWidth() ) );
    pushButtonFamilleGenreEdit->setProperty( "maximumSize", QSize( 22, 22 ) );

    layout9->addWidget( pushButtonFamilleGenreEdit, 0, 4 );

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)4, (QSizePolicy::SizeType)5, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    textLabel3->setProperty( "scaledContents", QVariant( TRUE, 0 ) );

    layout9->addWidget( textLabel3, 0, 0 );

    m_Combo_Family = new QComboBox( FALSE, this, "m_Combo_Family" );

    layout9->addWidget( m_Combo_Family, 0, 1 );

    m_Combo_Genre = new QComboBox( FALSE, this, "m_Combo_Genre" );

    layout9->addWidget( m_Combo_Genre, 0, 3 );

    DlgAtcd_txtLayout->addLayout( layout9, 4, 0 );

    layout8 = new QHBoxLayout( 0, 0, 6, "layout8"); 

    textLabel_date = new QLabel( this, "textLabel_date" );
    textLabel_date->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)4, (QSizePolicy::SizeType)5, 0, 0, textLabel_date->sizePolicy().hasHeightForWidth() ) );
    textLabel_date->setProperty( "minimumSize", QSize( 100, 20 ) );
    layout8->addWidget( textLabel_date );

    cMaskedLineDateAtcd = new CMaskedLineEdit( this, "cMaskedLineDateAtcd" );
    cMaskedLineDateAtcd->setProperty( "minimumSize", QSize( 100, 20 ) );
    cMaskedLineDateAtcd->setProperty( "maximumSize", QSize( 32767, 20 ) );
    cMaskedLineDateAtcd->setProperty( "carMask", 95 );
    layout8->addWidget( cMaskedLineDateAtcd );

    pushButtonDateDlg = new QPushButton( this, "pushButtonDateDlg" );
    pushButtonDateDlg->setProperty( "minimumSize", QSize( 22, 22 ) );
    pushButtonDateDlg->setProperty( "maximumSize", QSize( 22, 22 ) );
    layout8->addWidget( pushButtonDateDlg );

    DlgAtcd_txtLayout->addLayout( layout8, 6, 0 );
    languageChange();
    resize( QSize(587, 288).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( but_Valider, SIGNAL( clicked() ), this, SLOT( but_Valider_clicked() ) );
    connect( but_Annuler, SIGNAL( clicked() ), this, SLOT( but_Annuler_clicked() ) );
    connect( chkDate, SIGNAL( clicked() ), this, SLOT( chkDate_clicked() ) );
    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
DlgAtcd_txt::~DlgAtcd_txt()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void DlgAtcd_txt::languageChange()
{
    setProperty( "caption", trUtf8( "\x41\x6a\x6f\x75\x74\x65\x72\x20\x75\x6e\x20\x61\x6e\x74\xc3\xa9\x63\xc3\xa9\x64\x65"
    "\x6e\x74\x20\x65\x6e\x20\x6d\x6f\x64\x65\x20\x74\x65\x78\x74\x65" ) );
    lbl_Titre->setProperty( "text", trUtf8( "\x3c\x62\x3e\x41\x6a\x6f\x75\x74\x65\x72\x20\x75\x6e\x20\x61\x6e\x74\xc3\xa9\x63\xc3"
    "\xa9\x64\x65\x6e\x74\x20\x65\x6e\x20\x6d\x6f\x64\x65\x20\x74\x65\x78\x74\x65\x3c"
    "\x2f\x62\x3e" ) );
    but_Annuler->setProperty( "text", tr( "Annuler" ) );
    but_Valider->setProperty( "text", tr( "Valider" ) );
    checkBox_IsALD->setProperty( "text", tr( "En rapport avec une pathologie ALD" ) );
    checkBox_IsActif->setProperty( "text", trUtf8( "\x41\x63\x74\x69\x66\x20\x28\x70\x61\x74\x68\x6f\x6c\x6f\x67\x69\x65\x20\x65\x6e\x20"
    "\x63\x6f\x75\x72\x73\x2c\x20\x6e\x6f\x6e\x20\x67\x75\xc3\xa9\x72\x69\x65\x29" ) );
    textLabel_Commentaire->setProperty( "text", tr( "Commentaire" ) );
    chkDate->setProperty( "text", tr( "La date est connue" ) );
    textLabel_Libelle->setProperty( "text", trUtf8( "\x4c\x69\x62\x65\x6c\x6c\xc3\xa9\x20\x64\x65\x20\x6c\x27\x61\x6e\x74\xc3\xa9\x63\xc3"
    "\xa9\x64\x65\x6e\x74" ) );
    textLabel_Libelle_Long->setProperty( "text", trUtf8( "\x4c\x69\x62\x65\x6c\x6c\xc3\xa9\x20\x6c\x6f\x6e\x67\x20\x64\x65\x20\x6c\x27\x61\x6e"
    "\x74\xc3\xa9\x63\xc3\xa9\x64\x65\x6e\x74" ) );
    textLabel3_2->setProperty( "text", tr( "Genre :" ) );
    pushButtonFamilleGenreEdit->setProperty( "text", QString::null );
    QToolTip::add( pushButtonFamilleGenreEdit, tr( "Cliquez ici pour modifier les listes des familles et genres" ) );
    QWhatsThis::add( pushButtonFamilleGenreEdit, tr( "Cliquez ici pour modifier les listes des familles et genres" ) );
    textLabel3->setProperty( "text", trUtf8( "\x46\x61\x6d\x69\x6c\x6c\x65\x20\x64\x65\x20\x6c\x27\x61\x6e\x74\xc3\xa9\x63\xc3\xa9"
    "\x64\x65\x6e\x74" ) );
    textLabel_date->setProperty( "text", trUtf8( "\x44\x61\x74\x65\x20\x64\x65\x20\x6c\x27\x61\x6e\x74\xc3\xa9\x63\xc3\xa9\x64\x65\x6e"
    "\x74" ) );
    cMaskedLineDateAtcd->setProperty( "control", tr( "GGGGGGGG" ) );
    cMaskedLineDateAtcd->setProperty( "mask", tr( "__/__/____" ) );
    pushButtonDateDlg->setProperty( "text", QString::null );
    pushButtonDateDlg->setProperty( "accel", QKeySequence( QString::null ) );
    QToolTip::add( pushButtonDateDlg, tr( "Saisie de la date et de l'heure de la rubrique." ) );
}

