/****************************************************************************
** Form implementation generated from reading ui file 'RubPrescription.ui'
**
** Created: mer. mai 4 22:19:04 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "RubPrescription.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qcombobox.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "DlgDateNom.h"
#include "../../MedinTuxTools/CHtmlTools.h"
#include "Dlg_MedicaTux.h"
#include "../../MedinTuxTools/CPrtQListBoxItem.h"
#include "../RubPrescription.ui.h"
static const unsigned char image0_data[] = { 
    0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d,
    0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x0b,
    0x08, 0x06, 0x00, 0x00, 0x00, 0xa9, 0xac, 0x77, 0x26, 0x00, 0x00, 0x01,
    0x09, 0x49, 0x44, 0x41, 0x54, 0x18, 0x95, 0x8d, 0x91, 0xbf, 0x4a, 0x03,
    0x41, 0x10, 0xc6, 0xbf, 0x59, 0x6f, 0x65, 0x17, 0xab, 0x2b, 0x02, 0x01,
    0x2d, 0x2e, 0xa4, 0xb4, 0xce, 0x0b, 0x1c, 0x47, 0x52, 0xe6, 0x11, 0x7c,
    0x01, 0x2b, 0x5f, 0x40, 0x5f, 0xc0, 0x60, 0x2b, 0xc4, 0xb7, 0x48, 0x91,
    0x22, 0x24, 0x41, 0x64, 0x11, 0xfb, 0xd8, 0x5a, 0x18, 0x92, 0x46, 0x30,
    0xc5, 0xe5, 0xe4, 0x2e, 0x9b, 0x1b, 0x8b, 0xf3, 0xf4, 0x36, 0xd7, 0xf8,
    0x83, 0x81, 0x19, 0xbe, 0x6f, 0x60, 0xfe, 0x90, 0x31, 0x06, 0x25, 0xdc,
    0xef, 0xf3, 0x7e, 0xbb, 0x05, 0x00, 0x08, 0xa5, 0x20, 0x46, 0x23, 0x42,
    0x05, 0x51, 0x26, 0xb6, 0xd7, 0x63, 0x71, 0xf2, 0x01, 0x15, 0x24, 0x50,
    0x41, 0x02, 0xcf, 0xff, 0x84, 0x8d, 0x22, 0xae, 0x99, 0x6d, 0xb7, 0xcb,
    0xc7, 0xcd, 0x18, 0xcd, 0x0b, 0x46, 0x67, 0x01, 0x74, 0x16, 0xc0, 0xe9,
    0x25, 0x43, 0xb5, 0xbe, 0xb0, 0x0b, 0xc3, 0xbf, 0x86, 0x27, 0xdf, 0xe7,
    0xe7, 0x16, 0xf1, 0xdb, 0x35, 0x98, 0xd9, 0x8d, 0xf7, 0x5b, 0xf0, 0xcb,
    0x39, 0xf1, 0xa3, 0xd6, 0x6c, 0x8c, 0x81, 0xd8, 0xc7, 0x31, 0x84, 0x66,
    0x04, 0x37, 0xa8, 0x71, 0x76, 0x05, 0xc8, 0x06, 0x23, 0x4f, 0x53, 0x77,
    0xe6, 0xff, 0x20, 0x84, 0xd6, 0xc8, 0x53, 0xc2, 0xf2, 0xae, 0x2e, 0xae,
    0x87, 0x80, 0xdd, 0x10, 0x48, 0xca, 0xc2, 0x7c, 0x34, 0x1e, 0x53, 0xb6,
    0x52, 0x58, 0x0f, 0x09, 0xcb, 0x41, 0xc5, 0xf8, 0x00, 0xac, 0xee, 0x09,
    0xc9, 0xab, 0x84, 0x9c, 0xcd, 0x08, 0x00, 0xa8, 0xbc, 0xf3, 0x2e, 0x0c,
    0x59, 0xb7, 0x53, 0xc8, 0x46, 0xb1, 0xbc, 0xdd, 0xfc, 0x18, 0xe7, 0xf3,
    0xdf, 0x5b, 0x53, 0xf5, 0x29, 0x36, 0x8a, 0x38, 0xcf, 0xb2, 0x42, 0xf0,
    0x3c, 0xc8, 0xe9, 0xd4, 0x79, 0x8a, 0xe7, 0x14, 0x93, 0x89, 0x23, 0x1e,
    0xf2, 0x0d, 0x52, 0xbd, 0x6d, 0x87, 0x17, 0x48, 0x59, 0xca, 0x00, 0x00,
    0x00, 0x00, 0x49, 0x45, 0x4e, 0x44, 0xae, 0x42, 0x60, 0x82
};


/*
 *  Constructs a FormRubPrescription as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
FormRubPrescription::FormRubPrescription( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    QImage img;
    img.loadFromData( image0_data, sizeof( image0_data ), "PNG" );
    image0 = img;
    if ( !name )
	setProperty( "name", "FormRubPrescription" );
    setProperty( "minimumSize", QSize( 0, 32 ) );
    setProperty( "maximumSize", QSize( 32767, 74 ) );
    FormRubPrescriptionLayout = new QGridLayout( this, 1, 1, 0, 0, "FormRubPrescriptionLayout"); 

    layout1 = new QHBoxLayout( 0, 0, 6, "layout1"); 

    textLabel_NbRub = new QPushButton( this, "textLabel_NbRub" );
    textLabel_NbRub->setProperty( "minimumSize", QSize( 22, 22 ) );
    textLabel_NbRub->setProperty( "maximumSize", QSize( 22, 22 ) );
    layout1->addWidget( textLabel_NbRub );

    comboBox_RubName = new QComboBox( FALSE, this, "comboBox_RubName" );
    comboBox_RubName->setProperty( "minimumSize", QSize( 100, 22 ) );
    comboBox_RubName->setProperty( "maximumSize", QSize( 32767, 22 ) );
    QFont comboBox_RubName_font(  comboBox_RubName->font() );
    comboBox_RubName_font.setPointSize( 9 );
    comboBox_RubName->setFont( comboBox_RubName_font ); 
    comboBox_RubName->setProperty( "sizeLimit", 20 );
    layout1->addWidget( comboBox_RubName );

    pushButtonRubDateChange = new QPushButton( this, "pushButtonRubDateChange" );
    pushButtonRubDateChange->setProperty( "maximumSize", QSize( 22, 22 ) );
    pushButtonRubDateChange->setProperty( "iconSet", QIconSet( image0 ) );
    layout1->addWidget( pushButtonRubDateChange );

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setProperty( "minimumSize", QSize( 50, 0 ) );
    textLabel1->setProperty( "maximumSize", QSize( 50, 32767 ) );
    QFont textLabel1_font(  textLabel1->font() );
    textLabel1_font.setPointSize( 9 );
    textLabel1->setFont( textLabel1_font ); 
    layout1->addWidget( textLabel1 );

    textLabel_UserName = new QLabel( this, "textLabel_UserName" );
    textLabel_UserName->setProperty( "maximumSize", QSize( 115, 32767 ) );
    QFont textLabel_UserName_font(  textLabel_UserName->font() );
    textLabel_UserName_font.setPointSize( 9 );
    textLabel_UserName->setFont( textLabel_UserName_font ); 
    textLabel_UserName->setProperty( "frameShape", "StyledPanel" );
    textLabel_UserName->setProperty( "frameShadow", "Sunken" );
    textLabel_UserName->setProperty( "scaledContents", QVariant( FALSE, 0 ) );
    textLabel_UserName->setProperty( "alignment", int( QLabel::AlignCenter ) );
    layout1->addWidget( textLabel_UserName );

    pushButtonSave = new QPushButton( this, "pushButtonSave" );
    pushButtonSave->setProperty( "maximumSize", QSize( 35, 30 ) );
    layout1->addWidget( pushButtonSave );

    pushButtonPrint = new QPushButton( this, "pushButtonPrint" );
    pushButtonPrint->setProperty( "maximumSize", QSize( 35, 30 ) );
    layout1->addWidget( pushButtonPrint );

    pushButtonDelete = new QPushButton( this, "pushButtonDelete" );
    pushButtonDelete->setProperty( "maximumSize", QSize( 35, 32767 ) );
    layout1->addWidget( pushButtonDelete );

    pushButtonPlus = new QPushButton( this, "pushButtonPlus" );
    pushButtonPlus->setProperty( "maximumSize", QSize( 35, 32767 ) );
    layout1->addWidget( pushButtonPlus );

    pushButtonVidal = new QPushButton( this, "pushButtonVidal" );
    pushButtonVidal->setProperty( "maximumSize", QSize( 35, 32767 ) );
    layout1->addWidget( pushButtonVidal );

    FormRubPrescriptionLayout->addLayout( layout1, 0, 0 );
    languageChange();
    resize( QSize(749, 32).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( pushButtonSave, SIGNAL( clicked() ), this, SLOT( pushButtonSave_clicked() ) );
    connect( pushButtonDelete, SIGNAL( clicked() ), this, SLOT( pushButtonDelete_clicked() ) );
    connect( pushButtonVidal, SIGNAL( clicked() ), this, SLOT( pushButtonVidal_clicked() ) );
    connect( pushButtonRubDateChange, SIGNAL( clicked() ), this, SLOT( pushButtonRubDateChange_clicked() ) );
    connect( pushButtonPlus, SIGNAL( clicked() ), this, SLOT( pushButtonPlus_clicked() ) );
    connect( comboBox_RubName, SIGNAL( highlighted(int) ), this, SLOT( comboBox_RubName_highlighted(int) ) );
    connect( comboBox_RubName, SIGNAL( activated(int) ), this, SLOT( comboBox_RubName_activated(int) ) );

    // tab order
    setTabOrder( comboBox_RubName, pushButtonRubDateChange );
    setTabOrder( pushButtonRubDateChange, pushButtonSave );
    setTabOrder( pushButtonSave, pushButtonPrint );
    setTabOrder( pushButtonPrint, pushButtonDelete );
    setTabOrder( pushButtonDelete, pushButtonVidal );
    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
FormRubPrescription::~FormRubPrescription()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void FormRubPrescription::languageChange()
{
    setProperty( "caption", tr( "InvisibleStringFormPrescription" ) );
    textLabel_NbRub->setProperty( "text", QString::null );
    QToolTip::add( textLabel_NbRub, trUtf8( "\x4d\x6f\x64\x69\x66\x69\x65\x72\x20\x6c\x61\x20\x64\x61\x74\x65\x20\x65\x74\x20\x6c"
    "\x27\x69\x6e\x74\x69\x74\x75\x6c\xc3\xa9\x20\x64\x75\x20\x64\x6f\x63\x75\x6d\x65"
    "\x6e\x74" ) );
    pushButtonRubDateChange->setProperty( "text", QString::null );
    QToolTip::add( pushButtonRubDateChange, trUtf8( "\x4d\x6f\x64\x69\x66\x69\x65\x72\x20\x6c\x61\x20\x64\x61\x74\x65\x20\x65\x74\x20\x6c"
    "\x27\x69\x6e\x74\x69\x74\x75\x6c\xc3\xa9\x20\x64\x75\x20\x64\x6f\x63\x75\x6d\x65"
    "\x6e\x74" ) );
    textLabel1->setProperty( "text", tr( "vu par :" ) );
    textLabel_UserName->setProperty( "text", tr( "Utilisateur" ) );
    pushButtonSave->setProperty( "text", QString::null );
    QToolTip::add( pushButtonSave, tr( "Enregistrer tout le dossier" ) );
    pushButtonPrint->setProperty( "text", QString::null );
    QToolTip::add( pushButtonPrint, trUtf8( "\x49\x6d\x70\x72\x69\x6d\x65\x72\x20\x63\x65\x74\x74\x65\x20\x66\x65\x6e\xc3\xaa\x74"
    "\x72\x65" ) );
    pushButtonDelete->setProperty( "text", QString::null );
    QToolTip::add( pushButtonDelete, trUtf8( "\x50\x6c\x61\x63\x65\x72\x20\x6c\x65\x20\x64\x6f\x63\x75\x6d\x65\x6e\x74\x20\x65\x6e"
    "\x20\x63\x6f\x75\x72\x73\x20\x63\x6f\x6d\x6d\x65\x20\x64\x6f\x63\x75\x6d\x65\x6e"
    "\x74\x20\xc3\xa0\x20\x65\x66\x66\x61\x63\x65\x72\x20\x28\x6e\x65\x20\x73\x65\x72"
    "\x61\x20\x65\x66\x66\x61\x63\xc3\xa9\x20\x71\x75\x27\x61\x70\x72\xc3\xa8\x73\x20"
    "\x65\x6e\x72\x65\x67\x69\x73\x74\x72\x65\x6d\x65\x6e\x74\x29" ) );
    pushButtonPlus->setProperty( "text", QString::null );
    QToolTip::add( pushButtonPlus, tr( "Actions diverses avec cette prescription" ) );
    pushButtonVidal->setProperty( "text", QString::null );
    QToolTip::add( pushButtonVidal, trUtf8( "\x4d\x6f\x64\x69\x66\x69\x65\x72\x20\x63\x65\x74\x74\x65\x20\x6f\x72\x64\x6f\x6e\x6e"
    "\x61\x6e\x63\x65\x20\x61\x76\x65\x63\x20\x6c\x27\x61\x73\x73\x69\x73\x74\x61\x6e"
    "\x74\x20\x64\x27\x61\x69\x64\x65\x20\xc3\xa0\x20\x6c\x61\x20\x70\x72\x65\x73\x63"
    "\x72\x69\x70\x74\x69\x6f\x6e" ) );
}

