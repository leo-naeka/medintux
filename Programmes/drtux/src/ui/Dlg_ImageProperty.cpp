/****************************************************************************
** Form implementation generated from reading ui file 'Dlg_ImageProperty.ui'
**
** Created: mer. mai 4 22:20:01 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "Dlg_ImageProperty.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qslider.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a Dlg_ImageProperty as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
Dlg_ImageProperty::Dlg_ImageProperty( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setProperty( "name", "Dlg_ImageProperty" );
    Dlg_ImagePropertyLayout = new QGridLayout( this, 1, 1, 11, 6, "Dlg_ImagePropertyLayout"); 

    pushButton_Annuler = new QPushButton( this, "pushButton_Annuler" );

    Dlg_ImagePropertyLayout->addMultiCellWidget( pushButton_Annuler, 6, 6, 1, 2 );

    pushButton_Ok = new QPushButton( this, "pushButton_Ok" );

    Dlg_ImagePropertyLayout->addMultiCellWidget( pushButton_Ok, 5, 5, 1, 2 );

    pushButton_Save = new QPushButton( this, "pushButton_Save" );

    Dlg_ImagePropertyLayout->addMultiCellWidget( pushButton_Save, 4, 4, 1, 2 );

    layout9 = new QGridLayout( 0, 1, 1, 0, 6, "layout9"); 

    layout3 = new QHBoxLayout( 0, 0, 6, "layout3"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout3->addWidget( textLabel1 );

    lineEdit_width = new QLineEdit( this, "lineEdit_width" );
    lineEdit_width->setProperty( "maximumSize", QSize( 200, 32767 ) );
    lineEdit_width->setProperty( "readOnly", QVariant( TRUE, 0 ) );
    layout3->addWidget( lineEdit_width );
    spacer1 = new QSpacerItem( 51, 10, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout3->addItem( spacer1 );

    layout9->addLayout( layout3, 0, 0 );

    layout3_2 = new QHBoxLayout( 0, 0, 6, "layout3_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout3_2->addWidget( textLabel1_2 );

    lineEdit_height = new QLineEdit( this, "lineEdit_height" );
    lineEdit_height->setProperty( "maximumSize", QSize( 200, 32767 ) );
    lineEdit_height->setProperty( "readOnly", QVariant( TRUE, 0 ) );
    layout3_2->addWidget( lineEdit_height );
    spacer1_2 = new QSpacerItem( 51, 10, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout3_2->addItem( spacer1_2 );

    layout9->addLayout( layout3_2, 1, 0 );

    Dlg_ImagePropertyLayout->addLayout( layout9, 1, 0 );

    textLabel_Name = new QLabel( this, "textLabel_Name" );
    textLabel_Name->setProperty( "maximumSize", QSize( 32767, 25 ) );
    QFont textLabel_Name_font(  textLabel_Name->font() );
    textLabel_Name_font.setBold( TRUE );
    textLabel_Name->setFont( textLabel_Name_font ); 
    textLabel_Name->setProperty( "frameShape", "Box" );
    textLabel_Name->setProperty( "frameShadow", "Raised" );
    textLabel_Name->setProperty( "lineWidth", 2 );

    Dlg_ImagePropertyLayout->addMultiCellWidget( textLabel_Name, 0, 0, 0, 2 );
    spacer3 = new QSpacerItem( 16, 145, QSizePolicy::Minimum, QSizePolicy::Expanding );
    Dlg_ImagePropertyLayout->addMultiCell( spacer3, 1, 3, 2, 2 );

    layout6 = new QGridLayout( 0, 1, 1, 0, 6, "layout6"); 

    textEdit_FileName = new QTextEdit( this, "textEdit_FileName" );
    textEdit_FileName->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)4, 0, 0, textEdit_FileName->sizePolicy().hasHeightForWidth() ) );
    textEdit_FileName->setProperty( "maximumSize", QSize( 32767, 50 ) );
    QFont textEdit_FileName_font(  textEdit_FileName->font() );
    textEdit_FileName_font.setPointSize( 9 );
    textEdit_FileName_font.setBold( TRUE );
    textEdit_FileName_font.setItalic( TRUE );
    textEdit_FileName->setFont( textEdit_FileName_font ); 
    textEdit_FileName->setProperty( "frameShape", "Box" );
    textEdit_FileName->setProperty( "frameShadow", "Raised" );
    textEdit_FileName->setProperty( "lineWidth", 1 );
    textEdit_FileName->setProperty( "wordWrap", "WidgetWidth" );
    textEdit_FileName->setProperty( "wrapPolicy", "AtWordOrDocumentBoundary" );
    textEdit_FileName->setProperty( "readOnly", QVariant( TRUE, 0 ) );

    layout6->addWidget( textEdit_FileName, 0, 0 );

    pushButton_VoirSource = new QPushButton( this, "pushButton_VoirSource" );
    pushButton_VoirSource->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButton_VoirSource->sizePolicy().hasHeightForWidth() ) );
    pushButton_VoirSource->setProperty( "maximumSize", QSize( 100, 30 ) );
    QFont pushButton_VoirSource_font(  pushButton_VoirSource->font() );
    pushButton_VoirSource_font.setPointSize( 9 );
    pushButton_VoirSource_font.setBold( TRUE );
    pushButton_VoirSource_font.setItalic( TRUE );
    pushButton_VoirSource->setFont( pushButton_VoirSource_font ); 
    pushButton_VoirSource->setProperty( "toggleButton", QVariant( TRUE, 0 ) );
    pushButton_VoirSource->setProperty( "on", QVariant( FALSE, 0 ) );
    pushButton_VoirSource->setProperty( "flat", QVariant( FALSE, 0 ) );

    layout6->addWidget( pushButton_VoirSource, 0, 1 );

    Dlg_ImagePropertyLayout->addMultiCellLayout( layout6, 2, 2, 0, 1 );

    layout7 = new QGridLayout( 0, 1, 1, 0, 6, "layout7"); 

    pixmapLabel_Image = new QLabel( this, "pixmapLabel_Image" );
    pixmapLabel_Image->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)4, (QSizePolicy::SizeType)4, 0, 0, pixmapLabel_Image->sizePolicy().hasHeightForWidth() ) );
    pixmapLabel_Image->setProperty( "scaledContents", QVariant( TRUE, 0 ) );

    layout7->addWidget( pixmapLabel_Image, 1, 0 );

    slider_Width = new QSlider( this, "slider_Width" );
    slider_Width->setProperty( "orientation", "Horizontal" );

    layout7->addWidget( slider_Width, 0, 0 );

    slider_height = new QSlider( this, "slider_height" );
    slider_height->setProperty( "orientation", "Vertical" );

    layout7->addWidget( slider_height, 1, 1 );

    Dlg_ImagePropertyLayout->addMultiCellLayout( layout7, 3, 6, 0, 0 );
    languageChange();
    resize( QSize(388, 439).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Dlg_ImageProperty::~Dlg_ImageProperty()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Dlg_ImageProperty::languageChange()
{
    setProperty( "caption", trUtf8( "\x50\x72\x6f\x70\x72\x69\xc3\xa9\x74\xc3\xa9\x73\x20\x64\x65\x20\x6c\x27\x69\x6d\x61"
    "\x67\x65" ) );
    pushButton_Annuler->setProperty( "text", tr( "Annuler" ) );
    pushButton_Ok->setProperty( "text", tr( "&Quitter" ) );
    pushButton_Ok->setProperty( "accel", QKeySequence( tr( "Alt+Q" ) ) );
    pushButton_Save->setProperty( "text", tr( "Exporter" ) );
    textLabel1->setProperty( "text", tr( "Largeur : " ) );
    textLabel1_2->setProperty( "text", tr( "Hauteur : " ) );
    textLabel_Name->setProperty( "text", tr( "Nom de l'image :" ) );
    textEdit_FileName->setProperty( "text", tr( "Image Source : " ) );
    pushButton_VoirSource->setProperty( "text", tr( "&Voir" ) );
    pushButton_VoirSource->setProperty( "accel", QKeySequence( tr( "Alt+V" ) ) );
}

