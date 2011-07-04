/****************************************************************************
** Form implementation generated from reading ui file 'Dlg_AdvancedTerrain.ui'
**
** Created: mer. mai 4 22:19:46 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "Dlg_AdvancedTerrain.h"

#include <qvariant.h>
#include <../../MedinTuxTools/CMaskedLineEdit.h>
#include <qpushbutton.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qtextbrowser.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "Global.h"
#include "CApp.h"
#include "../../MedinTuxTools/CMedicaBase.h"
#include "../Dlg_AdvancedTerrain.ui.h"

/*
 *  Constructs a Dlg_AdvancedTerrain as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
Dlg_AdvancedTerrain::Dlg_AdvancedTerrain( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setProperty( "name", "Dlg_AdvancedTerrain" );
    Dlg_AdvancedTerrainLayout = new QGridLayout( this, 1, 1, 11, 6, "Dlg_AdvancedTerrainLayout"); 

    groupBox5_2_3_2 = new QGroupBox( this, "groupBox5_2_3_2" );
    QFont groupBox5_2_3_2_font(  groupBox5_2_3_2->font() );
    groupBox5_2_3_2_font.setBold( TRUE );
    groupBox5_2_3_2->setFont( groupBox5_2_3_2_font ); 
    groupBox5_2_3_2->setColumnLayout(0, Qt::Vertical );
    groupBox5_2_3_2->layout()->setSpacing( 6 );
    groupBox5_2_3_2->layout()->setMargin( 11 );
    groupBox5_2_3_2Layout = new QGridLayout( groupBox5_2_3_2->layout() );
    groupBox5_2_3_2Layout->setAlignment( Qt::AlignTop );

    textLabel1_5_2_2 = new QLabel( groupBox5_2_3_2, "textLabel1_5_2_2" );
    textLabel1_5_2_2->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_5_2_2->sizePolicy().hasHeightForWidth() ) );
    QFont textLabel1_5_2_2_font(  textLabel1_5_2_2->font() );
    textLabel1_5_2_2_font.setBold( FALSE );
    textLabel1_5_2_2->setFont( textLabel1_5_2_2_font ); 
    textLabel1_5_2_2->setProperty( "alignment", int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    groupBox5_2_3_2Layout->addWidget( textLabel1_5_2_2, 0, 0 );

    textLabel1_3_2_2_2 = new QLabel( groupBox5_2_3_2, "textLabel1_3_2_2_2" );
    textLabel1_3_2_2_2->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_3_2_2_2->sizePolicy().hasHeightForWidth() ) );
    QFont textLabel1_3_2_2_2_font(  textLabel1_3_2_2_2->font() );
    textLabel1_3_2_2_2_font.setBold( FALSE );
    textLabel1_3_2_2_2->setFont( textLabel1_3_2_2_2_font ); 
    textLabel1_3_2_2_2->setProperty( "alignment", int( QLabel::AlignCenter ) );

    groupBox5_2_3_2Layout->addWidget( textLabel1_3_2_2_2, 0, 2 );

    LineEdit_BiliMax = new CMaskedLineEdit( groupBox5_2_3_2, "LineEdit_BiliMax" );
    LineEdit_BiliMax->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, LineEdit_BiliMax->sizePolicy().hasHeightForWidth() ) );
    LineEdit_BiliMax->setProperty( "minimumSize", QSize( 70, 0 ) );
    QFont LineEdit_BiliMax_font(  LineEdit_BiliMax->font() );
    LineEdit_BiliMax_font.setBold( FALSE );
    LineEdit_BiliMax->setFont( LineEdit_BiliMax_font ); 
    LineEdit_BiliMax->setProperty( "focusPolicy", "StrongFocus" );
    LineEdit_BiliMax->setProperty( "carMask", 32 );

    groupBox5_2_3_2Layout->addWidget( LineEdit_BiliMax, 0, 3 );

    LineEdit_BiliMin = new CMaskedLineEdit( groupBox5_2_3_2, "LineEdit_BiliMin" );
    LineEdit_BiliMin->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, LineEdit_BiliMin->sizePolicy().hasHeightForWidth() ) );
    LineEdit_BiliMin->setProperty( "minimumSize", QSize( 70, 0 ) );
    QFont LineEdit_BiliMin_font(  LineEdit_BiliMin->font() );
    LineEdit_BiliMin_font.setBold( FALSE );
    LineEdit_BiliMin->setFont( LineEdit_BiliMin_font ); 
    LineEdit_BiliMin->setProperty( "focusPolicy", "StrongFocus" );
    LineEdit_BiliMin->setProperty( "carMask", 32 );

    groupBox5_2_3_2Layout->addWidget( LineEdit_BiliMin, 0, 1 );

    textLabel2_4_2_2_2 = new QLabel( groupBox5_2_3_2, "textLabel2_4_2_2_2" );
    QFont textLabel2_4_2_2_2_font(  textLabel2_4_2_2_2->font() );
    textLabel2_4_2_2_2_font.setBold( FALSE );
    textLabel2_4_2_2_2->setFont( textLabel2_4_2_2_2_font ); 

    groupBox5_2_3_2Layout->addWidget( textLabel2_4_2_2_2, 0, 4 );

    Dlg_AdvancedTerrainLayout->addMultiCellWidget( groupBox5_2_3_2, 5, 5, 0, 2 );

    groupBox5_2_3_2_2 = new QGroupBox( this, "groupBox5_2_3_2_2" );
    QFont groupBox5_2_3_2_2_font(  groupBox5_2_3_2_2->font() );
    groupBox5_2_3_2_2_font.setBold( TRUE );
    groupBox5_2_3_2_2->setFont( groupBox5_2_3_2_2_font ); 
    groupBox5_2_3_2_2->setColumnLayout(0, Qt::Vertical );
    groupBox5_2_3_2_2->layout()->setSpacing( 6 );
    groupBox5_2_3_2_2->layout()->setMargin( 11 );
    groupBox5_2_3_2_2Layout = new QGridLayout( groupBox5_2_3_2_2->layout() );
    groupBox5_2_3_2_2Layout->setAlignment( Qt::AlignTop );

    textLabel1_5_2_2_2 = new QLabel( groupBox5_2_3_2_2, "textLabel1_5_2_2_2" );
    textLabel1_5_2_2_2->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_5_2_2_2->sizePolicy().hasHeightForWidth() ) );
    QFont textLabel1_5_2_2_2_font(  textLabel1_5_2_2_2->font() );
    textLabel1_5_2_2_2_font.setBold( FALSE );
    textLabel1_5_2_2_2->setFont( textLabel1_5_2_2_2_font ); 
    textLabel1_5_2_2_2->setProperty( "alignment", int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    groupBox5_2_3_2_2Layout->addWidget( textLabel1_5_2_2_2, 0, 0 );

    textLabel1_3_2_2_2_2 = new QLabel( groupBox5_2_3_2_2, "textLabel1_3_2_2_2_2" );
    textLabel1_3_2_2_2_2->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_3_2_2_2_2->sizePolicy().hasHeightForWidth() ) );
    QFont textLabel1_3_2_2_2_2_font(  textLabel1_3_2_2_2_2->font() );
    textLabel1_3_2_2_2_2_font.setBold( FALSE );
    textLabel1_3_2_2_2_2->setFont( textLabel1_3_2_2_2_2_font ); 
    textLabel1_3_2_2_2_2->setProperty( "alignment", int( QLabel::AlignCenter ) );

    groupBox5_2_3_2_2Layout->addWidget( textLabel1_3_2_2_2_2, 0, 2 );

    LineEdit_EjectMax = new CMaskedLineEdit( groupBox5_2_3_2_2, "LineEdit_EjectMax" );
    LineEdit_EjectMax->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, LineEdit_EjectMax->sizePolicy().hasHeightForWidth() ) );
    LineEdit_EjectMax->setProperty( "minimumSize", QSize( 70, 0 ) );
    QFont LineEdit_EjectMax_font(  LineEdit_EjectMax->font() );
    LineEdit_EjectMax_font.setBold( FALSE );
    LineEdit_EjectMax->setFont( LineEdit_EjectMax_font ); 
    LineEdit_EjectMax->setProperty( "focusPolicy", "StrongFocus" );
    LineEdit_EjectMax->setProperty( "carMask", 32 );

    groupBox5_2_3_2_2Layout->addWidget( LineEdit_EjectMax, 0, 3 );

    LineEdit_EjectMin = new CMaskedLineEdit( groupBox5_2_3_2_2, "LineEdit_EjectMin" );
    LineEdit_EjectMin->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, LineEdit_EjectMin->sizePolicy().hasHeightForWidth() ) );
    LineEdit_EjectMin->setProperty( "minimumSize", QSize( 70, 0 ) );
    QFont LineEdit_EjectMin_font(  LineEdit_EjectMin->font() );
    LineEdit_EjectMin_font.setBold( FALSE );
    LineEdit_EjectMin->setFont( LineEdit_EjectMin_font ); 
    LineEdit_EjectMin->setProperty( "focusPolicy", "StrongFocus" );
    LineEdit_EjectMin->setProperty( "carMask", 32 );

    groupBox5_2_3_2_2Layout->addWidget( LineEdit_EjectMin, 0, 1 );

    textLabel2_4_2_2_2_2 = new QLabel( groupBox5_2_3_2_2, "textLabel2_4_2_2_2_2" );
    QFont textLabel2_4_2_2_2_2_font(  textLabel2_4_2_2_2_2->font() );
    textLabel2_4_2_2_2_2_font.setBold( FALSE );
    textLabel2_4_2_2_2_2->setFont( textLabel2_4_2_2_2_2_font ); 

    groupBox5_2_3_2_2Layout->addWidget( textLabel2_4_2_2_2_2, 0, 4 );

    Dlg_AdvancedTerrainLayout->addMultiCellWidget( groupBox5_2_3_2_2, 6, 6, 0, 2 );
    spacer3 = new QSpacerItem( 398, 16, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Dlg_AdvancedTerrainLayout->addMultiCell( spacer3, 8, 8, 0, 1 );

    pushButton_Ok = new QPushButton( this, "pushButton_Ok" );

    Dlg_AdvancedTerrainLayout->addWidget( pushButton_Ok, 8, 2 );

    groupBox4 = new QGroupBox( this, "groupBox4" );
    QFont groupBox4_font(  groupBox4->font() );
    groupBox4_font.setBold( TRUE );
    groupBox4->setFont( groupBox4_font ); 
    groupBox4->setColumnLayout(0, Qt::Vertical );
    groupBox4->layout()->setSpacing( 6 );
    groupBox4->layout()->setMargin( 11 );
    groupBox4Layout = new QGridLayout( groupBox4->layout() );
    groupBox4Layout->setAlignment( Qt::AlignTop );

    textLabel1_2 = new QLabel( groupBox4, "textLabel1_2" );
    textLabel1_2->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    QFont textLabel1_2_font(  textLabel1_2->font() );
    textLabel1_2_font.setBold( FALSE );
    textLabel1_2->setFont( textLabel1_2_font ); 
    textLabel1_2->setProperty( "alignment", int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    groupBox4Layout->addMultiCellWidget( textLabel1_2, 0, 1, 0, 0 );

    LineEdit_AnMin = new CMaskedLineEdit( groupBox4, "LineEdit_AnMin" );
    LineEdit_AnMin->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, LineEdit_AnMin->sizePolicy().hasHeightForWidth() ) );
    LineEdit_AnMin->setProperty( "minimumSize", QSize( 69, 0 ) );
    QFont LineEdit_AnMin_font(  LineEdit_AnMin->font() );
    LineEdit_AnMin_font.setBold( FALSE );
    LineEdit_AnMin->setFont( LineEdit_AnMin_font ); 
    LineEdit_AnMin->setProperty( "focusPolicy", "StrongFocus" );
    LineEdit_AnMin->setProperty( "carMask", 32 );

    groupBox4Layout->addMultiCellWidget( LineEdit_AnMin, 0, 1, 1, 1 );

    LineEdit_AnMax = new CMaskedLineEdit( groupBox4, "LineEdit_AnMax" );
    QFont LineEdit_AnMax_font(  LineEdit_AnMax->font() );
    LineEdit_AnMax_font.setBold( FALSE );
    LineEdit_AnMax->setFont( LineEdit_AnMax_font ); 
    LineEdit_AnMax->setProperty( "focusPolicy", "StrongFocus" );
    LineEdit_AnMax->setProperty( "carMask", 32 );

    groupBox4Layout->addWidget( LineEdit_AnMax, 2, 1 );

    textLabel2 = new QLabel( groupBox4, "textLabel2" );
    textLabel2->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    QFont textLabel2_font(  textLabel2->font() );
    textLabel2_font.setBold( FALSE );
    textLabel2->setFont( textLabel2_font ); 

    groupBox4Layout->addMultiCellWidget( textLabel2, 0, 1, 2, 2 );

    textLabel2_3 = new QLabel( groupBox4, "textLabel2_3" );
    textLabel2_3->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2_3->sizePolicy().hasHeightForWidth() ) );
    QFont textLabel2_3_font(  textLabel2_3->font() );
    textLabel2_3_font.setBold( FALSE );
    textLabel2_3->setFont( textLabel2_3_font ); 

    groupBox4Layout->addWidget( textLabel2_3, 2, 2 );

    LineEdit_MoisMin = new CMaskedLineEdit( groupBox4, "LineEdit_MoisMin" );
    LineEdit_MoisMin->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, LineEdit_MoisMin->sizePolicy().hasHeightForWidth() ) );
    LineEdit_MoisMin->setProperty( "minimumSize", QSize( 70, 0 ) );
    QFont LineEdit_MoisMin_font(  LineEdit_MoisMin->font() );
    LineEdit_MoisMin_font.setBold( FALSE );
    LineEdit_MoisMin->setFont( LineEdit_MoisMin_font ); 
    LineEdit_MoisMin->setProperty( "focusPolicy", "StrongFocus" );
    LineEdit_MoisMin->setProperty( "carMask", 32 );

    groupBox4Layout->addMultiCellWidget( LineEdit_MoisMin, 0, 1, 3, 3 );

    LineEdit_MoisMax = new CMaskedLineEdit( groupBox4, "LineEdit_MoisMax" );
    QFont LineEdit_MoisMax_font(  LineEdit_MoisMax->font() );
    LineEdit_MoisMax_font.setBold( FALSE );
    LineEdit_MoisMax->setFont( LineEdit_MoisMax_font ); 
    LineEdit_MoisMax->setProperty( "focusPolicy", "StrongFocus" );
    LineEdit_MoisMax->setProperty( "carMask", 32 );

    groupBox4Layout->addWidget( LineEdit_MoisMax, 2, 3 );

    textLabel2_2_2 = new QLabel( groupBox4, "textLabel2_2_2" );
    QFont textLabel2_2_2_font(  textLabel2_2_2->font() );
    textLabel2_2_2_font.setBold( FALSE );
    textLabel2_2_2->setFont( textLabel2_2_2_font ); 

    groupBox4Layout->addWidget( textLabel2_2_2, 2, 4 );

    textLabel2_2 = new QLabel( groupBox4, "textLabel2_2" );
    QFont textLabel2_2_font(  textLabel2_2->font() );
    textLabel2_2_font.setBold( FALSE );
    textLabel2_2->setFont( textLabel2_2_font ); 

    groupBox4Layout->addMultiCellWidget( textLabel2_2, 0, 1, 4, 6 );

    comboBoxAgeMin = new QComboBox( FALSE, groupBox4, "comboBoxAgeMin" );
    comboBoxAgeMin->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, comboBoxAgeMin->sizePolicy().hasHeightForWidth() ) );
    comboBoxAgeMin->setProperty( "maximumSize", QSize( 32767, 16 ) );
    QFont comboBoxAgeMin_font(  comboBoxAgeMin->font() );
    comboBoxAgeMin_font.setPointSize( 9 );
    comboBoxAgeMin_font.setBold( FALSE );
    comboBoxAgeMin->setFont( comboBoxAgeMin_font ); 

    groupBox4Layout->addMultiCellWidget( comboBoxAgeMin, 0, 1, 7, 7 );

    comboBoxAgeMax = new QComboBox( FALSE, groupBox4, "comboBoxAgeMax" );
    comboBoxAgeMax->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, comboBoxAgeMax->sizePolicy().hasHeightForWidth() ) );
    comboBoxAgeMax->setProperty( "maximumSize", QSize( 32767, 16 ) );
    QFont comboBoxAgeMax_font(  comboBoxAgeMax->font() );
    comboBoxAgeMax_font.setPointSize( 9 );
    comboBoxAgeMax_font.setBold( FALSE );
    comboBoxAgeMax->setFont( comboBoxAgeMax_font ); 

    groupBox4Layout->addWidget( comboBoxAgeMax, 2, 7 );
    spacer1 = new QSpacerItem( 10, 10, QSizePolicy::Expanding, QSizePolicy::Minimum );
    groupBox4Layout->addItem( spacer1, 1, 6 );
    spacer2 = new QSpacerItem( 10, 10, QSizePolicy::Expanding, QSizePolicy::Minimum );
    groupBox4Layout->addMultiCell( spacer2, 2, 2, 5, 6 );

    Dlg_AdvancedTerrainLayout->addMultiCellWidget( groupBox4, 0, 0, 0, 2 );

    groupBox5_3 = new QGroupBox( this, "groupBox5_3" );
    QFont groupBox5_3_font(  groupBox5_3->font() );
    groupBox5_3_font.setBold( TRUE );
    groupBox5_3->setFont( groupBox5_3_font ); 
    groupBox5_3->setColumnLayout(0, Qt::Vertical );
    groupBox5_3->layout()->setSpacing( 6 );
    groupBox5_3->layout()->setMargin( 11 );
    groupBox5_3Layout = new QGridLayout( groupBox5_3->layout() );
    groupBox5_3Layout->setAlignment( Qt::AlignTop );

    textLabel1_4 = new QLabel( groupBox5_3, "textLabel1_4" );
    textLabel1_4->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_4->sizePolicy().hasHeightForWidth() ) );
    QFont textLabel1_4_font(  textLabel1_4->font() );
    textLabel1_4_font.setBold( FALSE );
    textLabel1_4->setFont( textLabel1_4_font ); 
    textLabel1_4->setProperty( "alignment", int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    groupBox5_3Layout->addWidget( textLabel1_4, 0, 0 );

    textLabel1_3_3 = new QLabel( groupBox5_3, "textLabel1_3_3" );
    textLabel1_3_3->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_3_3->sizePolicy().hasHeightForWidth() ) );
    QFont textLabel1_3_3_font(  textLabel1_3_3->font() );
    textLabel1_3_3_font.setBold( FALSE );
    textLabel1_3_3->setFont( textLabel1_3_3_font ); 
    textLabel1_3_3->setProperty( "alignment", int( QLabel::AlignCenter ) );

    groupBox5_3Layout->addWidget( textLabel1_3_3, 0, 2 );

    LineEdit_PoidsMax = new CMaskedLineEdit( groupBox5_3, "LineEdit_PoidsMax" );
    LineEdit_PoidsMax->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, LineEdit_PoidsMax->sizePolicy().hasHeightForWidth() ) );
    LineEdit_PoidsMax->setProperty( "minimumSize", QSize( 70, 0 ) );
    QFont LineEdit_PoidsMax_font(  LineEdit_PoidsMax->font() );
    LineEdit_PoidsMax_font.setBold( FALSE );
    LineEdit_PoidsMax->setFont( LineEdit_PoidsMax_font ); 
    LineEdit_PoidsMax->setProperty( "focusPolicy", "StrongFocus" );
    LineEdit_PoidsMax->setProperty( "carMask", 32 );

    groupBox5_3Layout->addWidget( LineEdit_PoidsMax, 0, 3 );

    LineEdit_PoidsMin = new CMaskedLineEdit( groupBox5_3, "LineEdit_PoidsMin" );
    LineEdit_PoidsMin->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, LineEdit_PoidsMin->sizePolicy().hasHeightForWidth() ) );
    LineEdit_PoidsMin->setProperty( "minimumSize", QSize( 70, 0 ) );
    QFont LineEdit_PoidsMin_font(  LineEdit_PoidsMin->font() );
    LineEdit_PoidsMin_font.setBold( FALSE );
    LineEdit_PoidsMin->setFont( LineEdit_PoidsMin_font ); 
    LineEdit_PoidsMin->setProperty( "focusPolicy", "StrongFocus" );
    LineEdit_PoidsMin->setProperty( "carMask", 32 );

    groupBox5_3Layout->addWidget( LineEdit_PoidsMin, 0, 1 );

    textLabel2_4_3 = new QLabel( groupBox5_3, "textLabel2_4_3" );
    QFont textLabel2_4_3_font(  textLabel2_4_3->font() );
    textLabel2_4_3_font.setBold( FALSE );
    textLabel2_4_3->setFont( textLabel2_4_3_font ); 

    groupBox5_3Layout->addWidget( textLabel2_4_3, 0, 4 );

    Dlg_AdvancedTerrainLayout->addMultiCellWidget( groupBox5_3, 1, 1, 0, 2 );

    groupBox5_2_3 = new QGroupBox( this, "groupBox5_2_3" );
    QFont groupBox5_2_3_font(  groupBox5_2_3->font() );
    groupBox5_2_3_font.setBold( TRUE );
    groupBox5_2_3->setFont( groupBox5_2_3_font ); 
    groupBox5_2_3->setProperty( "alignment", int( QGroupBox::AlignLeft ) );
    groupBox5_2_3->setProperty( "flat", QVariant( FALSE, 0 ) );
    groupBox5_2_3->setColumnLayout(0, Qt::Vertical );
    groupBox5_2_3->layout()->setSpacing( 6 );
    groupBox5_2_3->layout()->setMargin( 11 );
    groupBox5_2_3Layout = new QHBoxLayout( groupBox5_2_3->layout() );
    groupBox5_2_3Layout->setAlignment( Qt::AlignTop );

    textLabelGrossesseEntre = new QLabel( groupBox5_2_3, "textLabelGrossesseEntre" );
    textLabelGrossesseEntre->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabelGrossesseEntre->sizePolicy().hasHeightForWidth() ) );
    QFont textLabelGrossesseEntre_font(  textLabelGrossesseEntre->font() );
    textLabelGrossesseEntre_font.setBold( FALSE );
    textLabelGrossesseEntre->setFont( textLabelGrossesseEntre_font ); 
    textLabelGrossesseEntre->setProperty( "alignment", int( QLabel::AlignVCenter | QLabel::AlignRight ) );
    groupBox5_2_3Layout->addWidget( textLabelGrossesseEntre );

    LineEdit_GrossesseMin = new CMaskedLineEdit( groupBox5_2_3, "LineEdit_GrossesseMin" );
    LineEdit_GrossesseMin->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, LineEdit_GrossesseMin->sizePolicy().hasHeightForWidth() ) );
    LineEdit_GrossesseMin->setProperty( "minimumSize", QSize( 70, 0 ) );
    QFont LineEdit_GrossesseMin_font(  LineEdit_GrossesseMin->font() );
    LineEdit_GrossesseMin_font.setBold( FALSE );
    LineEdit_GrossesseMin->setFont( LineEdit_GrossesseMin_font ); 
    LineEdit_GrossesseMin->setProperty( "focusPolicy", "StrongFocus" );
    LineEdit_GrossesseMin->setProperty( "carMask", 32 );
    groupBox5_2_3Layout->addWidget( LineEdit_GrossesseMin );

    textLabel_GrossesseEt = new QLabel( groupBox5_2_3, "textLabel_GrossesseEt" );
    textLabel_GrossesseEt->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel_GrossesseEt->sizePolicy().hasHeightForWidth() ) );
    QFont textLabel_GrossesseEt_font(  textLabel_GrossesseEt->font() );
    textLabel_GrossesseEt_font.setBold( FALSE );
    textLabel_GrossesseEt->setFont( textLabel_GrossesseEt_font ); 
    textLabel_GrossesseEt->setProperty( "alignment", int( QLabel::AlignCenter ) );
    groupBox5_2_3Layout->addWidget( textLabel_GrossesseEt );

    LineEdit_GrossesseMax = new CMaskedLineEdit( groupBox5_2_3, "LineEdit_GrossesseMax" );
    LineEdit_GrossesseMax->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, LineEdit_GrossesseMax->sizePolicy().hasHeightForWidth() ) );
    LineEdit_GrossesseMax->setProperty( "minimumSize", QSize( 70, 0 ) );
    QFont LineEdit_GrossesseMax_font(  LineEdit_GrossesseMax->font() );
    LineEdit_GrossesseMax_font.setBold( FALSE );
    LineEdit_GrossesseMax->setFont( LineEdit_GrossesseMax_font ); 
    LineEdit_GrossesseMax->setProperty( "focusPolicy", "StrongFocus" );
    LineEdit_GrossesseMax->setProperty( "carMask", 32 );
    groupBox5_2_3Layout->addWidget( LineEdit_GrossesseMax );

    comboBox_UnitGrossesse = new QComboBox( FALSE, groupBox5_2_3, "comboBox_UnitGrossesse" );
    comboBox_UnitGrossesse->setProperty( "maximumSize", QSize( 32767, 16 ) );
    QFont comboBox_UnitGrossesse_font(  comboBox_UnitGrossesse->font() );
    comboBox_UnitGrossesse_font.setPointSize( 9 );
    comboBox_UnitGrossesse_font.setBold( FALSE );
    comboBox_UnitGrossesse->setFont( comboBox_UnitGrossesse_font ); 
    groupBox5_2_3Layout->addWidget( comboBox_UnitGrossesse );

    Dlg_AdvancedTerrainLayout->addWidget( groupBox5_2_3, 2, 0 );

    groupBox5_2 = new QGroupBox( this, "groupBox5_2" );
    groupBox5_2->setProperty( "maximumSize", QSize( 32767, 32767 ) );
    QFont groupBox5_2_font(  groupBox5_2->font() );
    groupBox5_2_font.setBold( TRUE );
    groupBox5_2->setFont( groupBox5_2_font ); 
    groupBox5_2->setColumnLayout(0, Qt::Vertical );
    groupBox5_2->layout()->setSpacing( 6 );
    groupBox5_2->layout()->setMargin( 11 );
    groupBox5_2Layout = new QGridLayout( groupBox5_2->layout() );
    groupBox5_2Layout->setAlignment( Qt::AlignTop );

    textLabel_EntreClearence = new QLabel( groupBox5_2, "textLabel_EntreClearence" );
    textLabel_EntreClearence->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel_EntreClearence->sizePolicy().hasHeightForWidth() ) );
    QFont textLabel_EntreClearence_font(  textLabel_EntreClearence->font() );
    textLabel_EntreClearence_font.setBold( FALSE );
    textLabel_EntreClearence->setFont( textLabel_EntreClearence_font ); 
    textLabel_EntreClearence->setProperty( "alignment", int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    groupBox5_2Layout->addWidget( textLabel_EntreClearence, 0, 0 );

    textLabel_EtClearence = new QLabel( groupBox5_2, "textLabel_EtClearence" );
    textLabel_EtClearence->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel_EtClearence->sizePolicy().hasHeightForWidth() ) );
    QFont textLabel_EtClearence_font(  textLabel_EtClearence->font() );
    textLabel_EtClearence_font.setBold( FALSE );
    textLabel_EtClearence->setFont( textLabel_EtClearence_font ); 
    textLabel_EtClearence->setProperty( "alignment", int( QLabel::AlignCenter ) );

    groupBox5_2Layout->addWidget( textLabel_EtClearence, 0, 2 );

    LineEdit_ClearenceMax = new CMaskedLineEdit( groupBox5_2, "LineEdit_ClearenceMax" );
    LineEdit_ClearenceMax->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, LineEdit_ClearenceMax->sizePolicy().hasHeightForWidth() ) );
    LineEdit_ClearenceMax->setProperty( "minimumSize", QSize( 70, 0 ) );
    QFont LineEdit_ClearenceMax_font(  LineEdit_ClearenceMax->font() );
    LineEdit_ClearenceMax_font.setBold( FALSE );
    LineEdit_ClearenceMax->setFont( LineEdit_ClearenceMax_font ); 
    LineEdit_ClearenceMax->setProperty( "focusPolicy", "StrongFocus" );
    LineEdit_ClearenceMax->setProperty( "carMask", 32 );

    groupBox5_2Layout->addWidget( LineEdit_ClearenceMax, 0, 3 );

    LineEdit_ClearenceMin = new CMaskedLineEdit( groupBox5_2, "LineEdit_ClearenceMin" );
    LineEdit_ClearenceMin->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, LineEdit_ClearenceMin->sizePolicy().hasHeightForWidth() ) );
    LineEdit_ClearenceMin->setProperty( "minimumSize", QSize( 70, 0 ) );
    QFont LineEdit_ClearenceMin_font(  LineEdit_ClearenceMin->font() );
    LineEdit_ClearenceMin_font.setBold( FALSE );
    LineEdit_ClearenceMin->setFont( LineEdit_ClearenceMin_font ); 
    LineEdit_ClearenceMin->setProperty( "focusPolicy", "StrongFocus" );
    LineEdit_ClearenceMin->setProperty( "carMask", 32 );

    groupBox5_2Layout->addWidget( LineEdit_ClearenceMin, 0, 1 );

    textLabel_UnitClearence = new QLabel( groupBox5_2, "textLabel_UnitClearence" );
    QFont textLabel_UnitClearence_font(  textLabel_UnitClearence->font() );
    textLabel_UnitClearence_font.setBold( FALSE );
    textLabel_UnitClearence->setFont( textLabel_UnitClearence_font ); 

    groupBox5_2Layout->addWidget( textLabel_UnitClearence, 0, 4 );

    comboBox_Hemodialyse = new QComboBox( FALSE, groupBox5_2, "comboBox_Hemodialyse" );
    comboBox_Hemodialyse->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, comboBox_Hemodialyse->sizePolicy().hasHeightForWidth() ) );
    comboBox_Hemodialyse->setProperty( "maximumSize", QSize( 32767, 16 ) );
    QFont comboBox_Hemodialyse_font(  comboBox_Hemodialyse->font() );
    comboBox_Hemodialyse_font.setPointSize( 9 );
    comboBox_Hemodialyse_font.setBold( FALSE );
    comboBox_Hemodialyse->setFont( comboBox_Hemodialyse_font ); 

    groupBox5_2Layout->addWidget( comboBox_Hemodialyse, 0, 5 );

    Dlg_AdvancedTerrainLayout->addMultiCellWidget( groupBox5_2, 3, 3, 0, 2 );

    groupBox_Creat = new QGroupBox( this, "groupBox_Creat" );
    QFont groupBox_Creat_font(  groupBox_Creat->font() );
    groupBox_Creat_font.setBold( TRUE );
    groupBox_Creat->setFont( groupBox_Creat_font ); 
    groupBox_Creat->setColumnLayout(0, Qt::Vertical );
    groupBox_Creat->layout()->setSpacing( 6 );
    groupBox_Creat->layout()->setMargin( 11 );
    groupBox_CreatLayout = new QGridLayout( groupBox_Creat->layout() );
    groupBox_CreatLayout->setAlignment( Qt::AlignTop );

    textLabel1 = new QLabel( groupBox_Creat, "textLabel1" );
    textLabel1->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    QFont textLabel1_font(  textLabel1->font() );
    textLabel1_font.setBold( FALSE );
    textLabel1->setFont( textLabel1_font ); 
    textLabel1->setProperty( "alignment", int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    groupBox_CreatLayout->addWidget( textLabel1, 0, 0 );

    textLabel1_3 = new QLabel( groupBox_Creat, "textLabel1_3" );
    textLabel1_3->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_3->sizePolicy().hasHeightForWidth() ) );
    QFont textLabel1_3_font(  textLabel1_3->font() );
    textLabel1_3_font.setBold( FALSE );
    textLabel1_3->setFont( textLabel1_3_font ); 
    textLabel1_3->setProperty( "alignment", int( QLabel::AlignCenter ) );

    groupBox_CreatLayout->addWidget( textLabel1_3, 0, 2 );

    LineEdit_CreatMax = new CMaskedLineEdit( groupBox_Creat, "LineEdit_CreatMax" );
    LineEdit_CreatMax->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, LineEdit_CreatMax->sizePolicy().hasHeightForWidth() ) );
    LineEdit_CreatMax->setProperty( "minimumSize", QSize( 70, 0 ) );
    QFont LineEdit_CreatMax_font(  LineEdit_CreatMax->font() );
    LineEdit_CreatMax_font.setBold( FALSE );
    LineEdit_CreatMax->setFont( LineEdit_CreatMax_font ); 
    LineEdit_CreatMax->setProperty( "focusPolicy", "StrongFocus" );
    LineEdit_CreatMax->setProperty( "carMask", 32 );

    groupBox_CreatLayout->addWidget( LineEdit_CreatMax, 0, 3 );

    LineEdit_CreatMin = new CMaskedLineEdit( groupBox_Creat, "LineEdit_CreatMin" );
    LineEdit_CreatMin->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, LineEdit_CreatMin->sizePolicy().hasHeightForWidth() ) );
    LineEdit_CreatMin->setProperty( "minimumSize", QSize( 70, 0 ) );
    QFont LineEdit_CreatMin_font(  LineEdit_CreatMin->font() );
    LineEdit_CreatMin_font.setBold( FALSE );
    LineEdit_CreatMin->setFont( LineEdit_CreatMin_font ); 
    LineEdit_CreatMin->setProperty( "focusPolicy", "StrongFocus" );
    LineEdit_CreatMin->setProperty( "carMask", 32 );

    groupBox_CreatLayout->addWidget( LineEdit_CreatMin, 0, 1 );

    textLabel2_4 = new QLabel( groupBox_Creat, "textLabel2_4" );
    QFont textLabel2_4_font(  textLabel2_4->font() );
    textLabel2_4_font.setBold( FALSE );
    textLabel2_4->setFont( textLabel2_4_font ); 

    groupBox_CreatLayout->addWidget( textLabel2_4, 0, 4 );

    Dlg_AdvancedTerrainLayout->addMultiCellWidget( groupBox_Creat, 4, 4, 0, 2 );

    textBrowser_ResultView = new QTextBrowser( this, "textBrowser_ResultView" );
    textBrowser_ResultView->setProperty( "paletteForegroundColor", QColor( 0, 0, 255 ) );
    textBrowser_ResultView->setProperty( "paletteBackgroundColor", QColor( 170, 255, 255 ) );

    Dlg_AdvancedTerrainLayout->addMultiCellWidget( textBrowser_ResultView, 7, 7, 0, 2 );

    groupBox5_2_2 = new QGroupBox( this, "groupBox5_2_2" );
    groupBox5_2_2->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, groupBox5_2_2->sizePolicy().hasHeightForWidth() ) );
    QFont groupBox5_2_2_font(  groupBox5_2_2->font() );
    groupBox5_2_2_font.setBold( TRUE );
    groupBox5_2_2->setFont( groupBox5_2_2_font ); 
    groupBox5_2_2->setColumnLayout(0, Qt::Vertical );
    groupBox5_2_2->layout()->setSpacing( 6 );
    groupBox5_2_2->layout()->setMargin( 11 );
    groupBox5_2_2Layout = new QGridLayout( groupBox5_2_2->layout() );
    groupBox5_2_2Layout->setAlignment( Qt::AlignTop );

    comboBox_Allaitement = new QComboBox( FALSE, groupBox5_2_2, "comboBox_Allaitement" );
    comboBox_Allaitement->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, comboBox_Allaitement->sizePolicy().hasHeightForWidth() ) );
    comboBox_Allaitement->setProperty( "maximumSize", QSize( 32767, 16 ) );
    QFont comboBox_Allaitement_font(  comboBox_Allaitement->font() );
    comboBox_Allaitement_font.setPointSize( 9 );
    comboBox_Allaitement_font.setBold( FALSE );
    comboBox_Allaitement->setFont( comboBox_Allaitement_font ); 

    groupBox5_2_2Layout->addWidget( comboBox_Allaitement, 0, 0 );

    Dlg_AdvancedTerrainLayout->addMultiCellWidget( groupBox5_2_2, 2, 2, 1, 2 );
    languageChange();
    resize( QSize(693, 565).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( comboBox_Allaitement, SIGNAL( activated(const QString&) ), this, SLOT( comboBox_Allaitement_activated(const QString&) ) );
    connect( comboBox_UnitGrossesse, SIGNAL( activated(const QString&) ), this, SLOT( comboBox_UnitGrossesse_activated(const QString&) ) );
    connect( pushButton_Ok, SIGNAL( clicked() ), this, SLOT( pushButton_Ok_clicked() ) );
    connect( comboBox_Hemodialyse, SIGNAL( activated(const QString&) ), this, SLOT( comboBox_Hemodialyse_activated(const QString&) ) );

    // tab order
    setTabOrder( LineEdit_AnMin, LineEdit_MoisMin );
    setTabOrder( LineEdit_MoisMin, comboBoxAgeMin );
    setTabOrder( comboBoxAgeMin, LineEdit_AnMax );
    setTabOrder( LineEdit_AnMax, LineEdit_MoisMax );
    setTabOrder( LineEdit_MoisMax, comboBoxAgeMax );
    setTabOrder( comboBoxAgeMax, LineEdit_PoidsMin );
    setTabOrder( LineEdit_PoidsMin, LineEdit_PoidsMax );
    setTabOrder( LineEdit_PoidsMax, LineEdit_GrossesseMin );
    setTabOrder( LineEdit_GrossesseMin, LineEdit_GrossesseMax );
    setTabOrder( LineEdit_GrossesseMax, comboBox_UnitGrossesse );
    setTabOrder( comboBox_UnitGrossesse, comboBox_Allaitement );
    setTabOrder( comboBox_Allaitement, LineEdit_ClearenceMin );
    setTabOrder( LineEdit_ClearenceMin, LineEdit_ClearenceMax );
    setTabOrder( LineEdit_ClearenceMax, comboBox_Hemodialyse );
    setTabOrder( comboBox_Hemodialyse, LineEdit_CreatMin );
    setTabOrder( LineEdit_CreatMin, LineEdit_CreatMax );
    setTabOrder( LineEdit_CreatMax, LineEdit_BiliMin );
    setTabOrder( LineEdit_BiliMin, LineEdit_BiliMax );
    setTabOrder( LineEdit_BiliMax, LineEdit_EjectMin );
    setTabOrder( LineEdit_EjectMin, LineEdit_EjectMax );
    setTabOrder( LineEdit_EjectMax, textBrowser_ResultView );
    setTabOrder( textBrowser_ResultView, pushButton_Ok );

    // buddies
    textLabel1_2->setBuddy( LineEdit_AnMin );
    textLabel2->setBuddy( LineEdit_MoisMin );
    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
Dlg_AdvancedTerrain::~Dlg_AdvancedTerrain()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Dlg_AdvancedTerrain::languageChange()
{
    setProperty( "caption", trUtf8( "\x44\xc3\xa9\x66\x69\x6e\x69\x74\x69\x6f\x6e\x20\x64\x75\x20\x74\x65\x72\x72\x61\x69"
    "\x6e" ) );
    groupBox5_2_3_2->setProperty( "title", trUtf8( "\x49\x6e\x74\x65\x72\x76\x61\x6c\x6c\x65\x20\x64\x65\x20\x62\x69\x6c\x69\x62\x69\x72"
    "\x75\x62\x69\x6e\xc3\xa9\x6d\x69\x65\x20\x70\x6f\x75\x72\x20\x6c\x65\x71\x75\x65"
    "\x6c\x20\x63\x65\x74\x74\x65\x20\x70\x6f\x73\x6f\x6c\x6f\x67\x69\x65\x20\x73\x27"
    "\x61\x70\x70\x6c\x69\x71\x75\x65" ) );
    textLabel1_5_2_2->setProperty( "text", tr( "Entre : " ) );
    textLabel1_3_2_2_2->setProperty( "text", tr( "et" ) );
    LineEdit_BiliMax->setProperty( "control", tr( "GGGGGGGGGG" ) );
    LineEdit_BiliMax->setProperty( "mask", tr( "__________" ) );
    LineEdit_BiliMax->setProperty( "text", QString::null );
    LineEdit_BiliMin->setProperty( "control", tr( "GGGGGGGGGG" ) );
    LineEdit_BiliMin->setProperty( "mask", tr( "__________" ) );
    LineEdit_BiliMin->setProperty( "text", QString::null );
    textLabel2_4_2_2_2->setProperty( "text", tr( "mg/L" ) );
    groupBox5_2_3_2_2->setProperty( "title", trUtf8( "\x49\x6e\x74\x65\x72\x76\x61\x6c\x6c\x65\x20\x64\x65\x20\x66\x72\x61\x63\x74\x69\x6f"
    "\x6e\x20\x64\x27\xc3\xa9\x6a\x65\x63\x74\x69\x6f\x6e\x20\x70\x6f\x75\x72\x20\x6c"
    "\x65\x71\x75\x65\x6c\x20\x63\x65\x74\x74\x65\x20\x70\x6f\x73\x6f\x6c\x6f\x67\x69"
    "\x65\x20\x73\x27\x61\x70\x70\x6c\x69\x71\x75\x65" ) );
    textLabel1_5_2_2_2->setProperty( "text", tr( "Entre : " ) );
    textLabel1_3_2_2_2_2->setProperty( "text", tr( "et" ) );
    LineEdit_EjectMax->setProperty( "control", tr( "GGGGGGGGGG" ) );
    LineEdit_EjectMax->setProperty( "mask", tr( "__________" ) );
    LineEdit_EjectMax->setProperty( "text", QString::null );
    LineEdit_EjectMin->setProperty( "control", tr( "GGGGGGGGGG" ) );
    LineEdit_EjectMin->setProperty( "mask", tr( "__________" ) );
    LineEdit_EjectMin->setProperty( "text", QString::null );
    textLabel2_4_2_2_2_2->setProperty( "text", tr( "ml/mn" ) );
    pushButton_Ok->setProperty( "text", tr( "&Valider" ) );
    pushButton_Ok->setProperty( "accel", QKeySequence( tr( "Alt+V" ) ) );
    groupBox4->setProperty( "title", trUtf8( "\x20\x49\x6e\x74\x65\x72\x76\x61\x6c\x6c\x65\x20\x64\x27\xc3\xa2\x67\x65\x20\x70\x6f"
    "\x75\x72\x20\x6c\x65\x71\x75\x65\x6c\x20\x63\x65\x74\x74\x65\x20\x70\x6f\x73\x6f"
    "\x6c\x6f\x67\x69\x65\x20\x73\x27\x61\x70\x70\x6c\x69\x71\x75\x65\x20" ) );
    textLabel1_2->setProperty( "text", trUtf8( "\x26\xc3\x82\x67\x65\x20\x65\x6e\x74\x72\x65\x20\x3a\x20" ) );
    LineEdit_AnMin->setProperty( "control", tr( "GGGGGGGGGG" ) );
    LineEdit_AnMin->setProperty( "mask", tr( "__________" ) );
    LineEdit_AnMin->setProperty( "text", QString::null );
    LineEdit_AnMax->setProperty( "control", tr( "GGGGGGGGGG" ) );
    LineEdit_AnMax->setProperty( "mask", tr( "__________" ) );
    LineEdit_AnMax->setProperty( "text", QString::null );
    textLabel2->setProperty( "text", tr( "&an(s) et" ) );
    textLabel2_3->setProperty( "text", tr( "an(s) et" ) );
    LineEdit_MoisMin->setProperty( "control", tr( "GGGGGGGGGG" ) );
    LineEdit_MoisMin->setProperty( "mask", tr( "__________" ) );
    LineEdit_MoisMin->setProperty( "text", QString::null );
    LineEdit_MoisMax->setProperty( "control", tr( "GGGGGGGGGG" ) );
    LineEdit_MoisMax->setProperty( "mask", tr( "__________" ) );
    LineEdit_MoisMax->setProperty( "text", QString::null );
    textLabel2_2_2->setProperty( "text", tr( "mois Maximum" ) );
    textLabel2_2->setProperty( "text", trUtf8( "\x6d\x6f\x69\x73\x20\x4d\x69\x6e\x69\x6d\x75\x6d\x20\xc3\xa0" ) );
    comboBoxAgeMin->clear();
    comboBoxAgeMin->insertItem( trUtf8( "\x4e\x6f\x75\x76\x65\x61\x75\x20\x6e\xc3\xa9" ) );
    comboBoxAgeMin->insertItem( tr( "Nourrisson" ) );
    comboBoxAgeMin->insertItem( tr( "Enfant" ) );
    comboBoxAgeMin->insertItem( tr( "Adolescent" ) );
    comboBoxAgeMin->insertItem( tr( "Adulte" ) );
    comboBoxAgeMin->insertItem( trUtf8( "\x50\x65\x72\x73\x6f\x6e\x6e\x65\x20\xc3\xa2\x67\xc3\xa9\x65" ) );
    comboBoxAgeMin->insertItem( tr( "Vieillard" ) );
    comboBoxAgeMax->clear();
    comboBoxAgeMax->insertItem( trUtf8( "\x4e\x6f\x75\x76\x65\x61\x75\x20\x6e\xc3\xa9" ) );
    comboBoxAgeMax->insertItem( tr( "Nourisson" ) );
    comboBoxAgeMax->insertItem( tr( "Enfant" ) );
    comboBoxAgeMax->insertItem( tr( "Adolescent" ) );
    comboBoxAgeMax->insertItem( tr( "Adulte" ) );
    comboBoxAgeMax->insertItem( trUtf8( "\x50\x65\x72\x73\x6f\x6e\x6e\x65\x20\xc3\xa2\x67\xc3\xa9\x65" ) );
    comboBoxAgeMax->insertItem( tr( "Vieillard" ) );
    groupBox5_3->setProperty( "title", tr( "Intervalle de poids pour lequel cette posologie s'applique" ) );
    textLabel1_4->setProperty( "text", tr( "Entre : " ) );
    textLabel1_3_3->setProperty( "text", tr( "et" ) );
    LineEdit_PoidsMax->setProperty( "control", tr( "GGGGGGGGGG" ) );
    LineEdit_PoidsMax->setProperty( "mask", tr( "__________" ) );
    LineEdit_PoidsMax->setProperty( "text", QString::null );
    LineEdit_PoidsMin->setProperty( "control", tr( "GGGGGGGGGG" ) );
    LineEdit_PoidsMin->setProperty( "mask", tr( "__________" ) );
    LineEdit_PoidsMin->setProperty( "text", QString::null );
    textLabel2_4_3->setProperty( "text", tr( "kg" ) );
    groupBox5_2_3->setProperty( "title", tr( "Intervalle de mois de grossesse pour lequel cette posologie s'applique" ) );
    textLabelGrossesseEntre->setProperty( "text", tr( "Entre : " ) );
    LineEdit_GrossesseMin->setProperty( "control", tr( "GGGGGGGGGG" ) );
    LineEdit_GrossesseMin->setProperty( "mask", tr( "__________" ) );
    LineEdit_GrossesseMin->setProperty( "text", QString::null );
    textLabel_GrossesseEt->setProperty( "text", tr( "et" ) );
    LineEdit_GrossesseMax->setProperty( "control", tr( "GGGGGGGGGG" ) );
    LineEdit_GrossesseMax->setProperty( "mask", tr( "__________" ) );
    LineEdit_GrossesseMax->setProperty( "text", QString::null );
    comboBox_UnitGrossesse->clear();
    comboBox_UnitGrossesse->insertItem( tr( "trimestre(s)" ) );
    comboBox_UnitGrossesse->insertItem( tr( "mois" ) );
    comboBox_UnitGrossesse->insertItem( tr( "En cours" ) );
    groupBox5_2->setProperty( "title", trUtf8( "\x49\x6e\x74\x65\x72\x76\x61\x6c\x6c\x65\x20\x64\x65\x20\x63\x6c\x65\x61\x72\x61\x6e"
    "\x63\x65\x20\x64\x65\x20\x6c\x61\x20\x63\x72\xc3\xa9\x61\x74\x69\x6e\x69\x6e\x65"
    "\x20\x70\x6f\x75\x72\x20\x6c\x65\x71\x75\x65\x6c\x20\x63\x65\x74\x74\x65\x20\x70"
    "\x6f\x73\x6f\x6c\x6f\x67\x69\x65\x20\x73\x27\x61\x70\x70\x6c\x69\x71\x75\x65" ) );
    textLabel_EntreClearence->setProperty( "text", tr( "Entre : " ) );
    textLabel_EtClearence->setProperty( "text", tr( "et" ) );
    LineEdit_ClearenceMax->setProperty( "control", tr( "GGGGGGGGGG" ) );
    LineEdit_ClearenceMax->setProperty( "mask", tr( "__________" ) );
    LineEdit_ClearenceMax->setProperty( "text", QString::null );
    LineEdit_ClearenceMin->setProperty( "control", tr( "GGGGGGGGGG" ) );
    LineEdit_ClearenceMin->setProperty( "mask", tr( "__________" ) );
    LineEdit_ClearenceMin->setProperty( "text", QString::null );
    textLabel_UnitClearence->setProperty( "text", tr( "ml/mn" ) );
    comboBox_Hemodialyse->clear();
    comboBox_Hemodialyse->insertItem( trUtf8( "\x48\xc3\xa9\x6d\x6f\x64\x69\x61\x6c\x79\x73\xc3\xa9" ) );
    comboBox_Hemodialyse->insertItem( trUtf8( "\x49\x6e\x73\x75\x66\x66\x69\x73\x61\x6e\x74\x20\x72\xc3\xa9\x6e\x61\x6c" ) );
    groupBox_Creat->setProperty( "title", trUtf8( "\x49\x6e\x74\x65\x72\x76\x61\x6c\x6c\x65\x20\x64\x65\x20\x63\x72\xc3\xa9\x61\x74\x69"
    "\x6e\x69\x6e\xc3\xa9\x6d\x69\x65\x20\x70\x6f\x75\x72\x20\x6c\x65\x71\x75\x65\x6c"
    "\x20\x63\x65\x74\x74\x65\x20\x70\x6f\x73\x6f\x6c\x6f\x67\x69\x65\x20\x73\x27\x61"
    "\x70\x70\x6c\x69\x71\x75\x65" ) );
    textLabel1->setProperty( "text", tr( "Entre : " ) );
    textLabel1_3->setProperty( "text", tr( "et" ) );
    LineEdit_CreatMax->setProperty( "control", tr( "GGGGGGGGGG" ) );
    LineEdit_CreatMax->setProperty( "mask", tr( "__________" ) );
    LineEdit_CreatMax->setProperty( "text", QString::null );
    LineEdit_CreatMin->setProperty( "control", tr( "GGGGGGGGGG" ) );
    LineEdit_CreatMin->setProperty( "mask", tr( "__________" ) );
    LineEdit_CreatMin->setProperty( "text", QString::null );
    textLabel2_4->setProperty( "text", tr( "mg/L" ) );
    groupBox5_2_2->setProperty( "title", tr( "Allaitement" ) );
    comboBox_Allaitement->clear();
    comboBox_Allaitement->insertItem( tr( "En cours" ) );
    comboBox_Allaitement->insertItem( tr( "Non en cours" ) );
}

