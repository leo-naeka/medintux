/****************************************************************************
** Form implementation generated from reading ui file 'Dlg_PosoManager.ui'
**
** Created: mer. mai 4 22:19:28 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "Dlg_PosoManager.h"

#include <qvariant.h>
#include <math.h>
#include <qmessagebox.h>
#include <../../MedinTuxTools/CMaskedLineEdit.h>
#include <qpushbutton.h>
#include <qframe.h>
#include <qlabel.h>
#include <qsplitter.h>
#include <qheader.h>
#include <qlistview.h>
#include <qgroupbox.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qslider.h>
#include <qtextbrowser.h>
#include <qradiobutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "DlgGetText.h"
#include "../Dlg_PosoManager.ui.h"

/*
 *  Constructs a Dlg_PosoManager as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
Dlg_PosoManager::Dlg_PosoManager( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setProperty( "name", "Dlg_PosoManager" );
    QFont f( font() );
    setFont( f ); 
    Dlg_PosoManagerLayout = new QGridLayout( this, 1, 1, 3, 1, "Dlg_PosoManagerLayout"); 

    layout19 = new QGridLayout( 0, 1, 1, 0, 0, "layout19"); 

    line1 = new QFrame( this, "line1" );
    line1->setProperty( "frameShape", "HLine" );
    line1->setProperty( "frameShadow", "Sunken" );
    line1->setProperty( "frameShape", QFrame::VLine );

    layout19->addWidget( line1, 0, 0 );

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    textLabel1_3->setProperty( "paletteForegroundColor", QColor( 0, 0, 255 ) );
    QFont textLabel1_3_font(  textLabel1_3->font() );
    textLabel1_3_font.setBold( TRUE );
    textLabel1_3->setFont( textLabel1_3_font ); 
    textLabel1_3->setProperty( "alignment", int( QLabel::AlignCenter ) );

    layout19->addWidget( textLabel1_3, 0, 1 );

    line1_2 = new QFrame( this, "line1_2" );
    line1_2->setProperty( "frameShape", "HLine" );
    line1_2->setProperty( "frameShadow", "Sunken" );
    line1_2->setProperty( "frameShape", QFrame::VLine );

    layout19->addWidget( line1_2, 0, 2 );

    Dlg_PosoManagerLayout->addLayout( layout19, 0, 0 );

    splitter1 = new QSplitter( this, "splitter1" );
    splitter1->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)4, 0, 0, splitter1->sizePolicy().hasHeightForWidth() ) );
    splitter1->setProperty( "maximumSize", QSize( 32767, 32767 ) );
    splitter1->setProperty( "frameShape", "NoFrame" );
    splitter1->setProperty( "orientation", "Horizontal" );
    splitter1->setProperty( "childrenCollapsible", QVariant( TRUE, 0 ) );

    QWidget* privateLayoutWidget = new QWidget( splitter1, "layout21" );
    layout21 = new QVBoxLayout( privateLayoutWidget, 11, 0, "layout21"); 

    listView_Produits = new QListView( privateLayoutWidget, "listView_Produits" );
    listView_Produits->addColumn( tr( "Produit" ) );
    listView_Produits->addColumn( tr( "CodeProduit" ) );
    listView_Produits->addColumn( tr( "Pk_t00" ) );
    listView_Produits->addColumn( tr( "pk_t4b" ) );
    listView_Produits->addColumn( tr( "CodeCIP" ) );
    listView_Produits->addColumn( tr( "CodeUV" ) );
    listView_Produits->addColumn( tr( "IsG" ) );
    listView_Produits->addColumn( tr( "IsD" ) );
    listView_Produits->addColumn( tr( "num" ) );
    listView_Produits->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)4, (QSizePolicy::SizeType)5, 0, 0, listView_Produits->sizePolicy().hasHeightForWidth() ) );
    listView_Produits->setProperty( "maximumSize", QSize( 32767, 32767 ) );
    QFont listView_Produits_font(  listView_Produits->font() );
    listView_Produits->setFont( listView_Produits_font ); 
    listView_Produits->setProperty( "resizePolicy", "Manual" );
    listView_Produits->setProperty( "showSortIndicator", QVariant( TRUE, 0 ) );
    layout21->addWidget( listView_Produits );

    layout20 = new QHBoxLayout( 0, 0, 6, "layout20"); 

    pushButtonListPosoCopier = new QPushButton( privateLayoutWidget, "pushButtonListPosoCopier" );
    pushButtonListPosoCopier->setProperty( "maximumSize", QSize( 32767, 20 ) );
    QFont pushButtonListPosoCopier_font(  pushButtonListPosoCopier->font() );
    pushButtonListPosoCopier->setFont( pushButtonListPosoCopier_font ); 
    layout20->addWidget( pushButtonListPosoCopier );
    spacer4 = new QSpacerItem( 26, 10, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout20->addItem( spacer4 );

    pushButtonListPosoColler = new QPushButton( privateLayoutWidget, "pushButtonListPosoColler" );
    pushButtonListPosoColler->setProperty( "minimumSize", QSize( 0, 20 ) );
    pushButtonListPosoColler->setProperty( "maximumSize", QSize( 32767, 20 ) );
    QFont pushButtonListPosoColler_font(  pushButtonListPosoColler->font() );
    pushButtonListPosoColler->setFont( pushButtonListPosoColler_font ); 
    layout20->addWidget( pushButtonListPosoColler );
    layout21->addLayout( layout20 );

    QWidget* privateLayoutWidget_2 = new QWidget( splitter1, "layout22" );
    layout22 = new QGridLayout( privateLayoutWidget_2, 1, 1, 11, 0, "layout22"); 

    layout19_2 = new QHBoxLayout( 0, 0, 6, "layout19_2"); 

    pushButtonDefPosoCopier = new QPushButton( privateLayoutWidget_2, "pushButtonDefPosoCopier" );
    pushButtonDefPosoCopier->setProperty( "maximumSize", QSize( 32767, 20 ) );
    QFont pushButtonDefPosoCopier_font(  pushButtonDefPosoCopier->font() );
    pushButtonDefPosoCopier->setFont( pushButtonDefPosoCopier_font ); 
    layout19_2->addWidget( pushButtonDefPosoCopier );
    spacer3_2 = new QSpacerItem( 121, 10, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout19_2->addItem( spacer3_2 );

    pushButtonDefPosoColler = new QPushButton( privateLayoutWidget_2, "pushButtonDefPosoColler" );
    pushButtonDefPosoColler->setProperty( "maximumSize", QSize( 32767, 20 ) );
    QFont pushButtonDefPosoColler_font(  pushButtonDefPosoColler->font() );
    pushButtonDefPosoColler->setFont( pushButtonDefPosoColler_font ); 
    layout19_2->addWidget( pushButtonDefPosoColler );

    layout22->addLayout( layout19_2, 1, 0 );

    listView_MedicaPoso = new QListView( privateLayoutWidget_2, "listView_MedicaPoso" );
    listView_MedicaPoso->addColumn( tr( "PrimKey" ) );
    listView_MedicaPoso->addColumn( tr( "Code CIP" ) );
    listView_MedicaPoso->addColumn( tr( "Libelle" ) );
    listView_MedicaPoso->addColumn( tr( "Poso Min" ) );
    listView_MedicaPoso->addColumn( tr( "Poso Max" ) );
    listView_MedicaPoso->addColumn( tr( "Posos Unit" ) );
    listView_MedicaPoso->addColumn( tr( "Fact Corp Qu" ) );
    listView_MedicaPoso->addColumn( tr( "Fact Corp Unit" ) );
    listView_MedicaPoso->addColumn( trUtf8( "\x50\xc3\xa9\x72\x69\x6f\x64\x65" ) );
    listView_MedicaPoso->addColumn( tr( "Coeff" ) );
    listView_MedicaPoso->addColumn( tr( "Coeff Unit" ) );
    listView_MedicaPoso->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)4, (QSizePolicy::SizeType)5, 0, 0, listView_MedicaPoso->sizePolicy().hasHeightForWidth() ) );
    listView_MedicaPoso->setProperty( "maximumSize", QSize( 32767, 32767 ) );
    QFont listView_MedicaPoso_font(  listView_MedicaPoso->font() );
    listView_MedicaPoso->setFont( listView_MedicaPoso_font ); 
    listView_MedicaPoso->setProperty( "showSortIndicator", QVariant( TRUE, 0 ) );

    layout22->addWidget( listView_MedicaPoso, 0, 0 );

    Dlg_PosoManagerLayout->addWidget( splitter1, 1, 0 );

    groupBox5_3 = new QGroupBox( this, "groupBox5_3" );
    groupBox5_3->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, groupBox5_3->sizePolicy().hasHeightForWidth() ) );
    groupBox5_3->setProperty( "paletteForegroundColor", QColor( 0, 0, 255 ) );
    QFont groupBox5_3_font(  groupBox5_3->font() );
    groupBox5_3_font.setBold( TRUE );
    groupBox5_3->setFont( groupBox5_3_font ); 
    groupBox5_3->setProperty( "frameShape", "GroupBoxPanel" );
    groupBox5_3->setProperty( "frameShadow", "Sunken" );
    groupBox5_3->setColumnLayout(0, Qt::Vertical );
    groupBox5_3->layout()->setSpacing( 0 );
    groupBox5_3->layout()->setMargin( 2 );
    groupBox5_3Layout = new QGridLayout( groupBox5_3->layout() );
    groupBox5_3Layout->setAlignment( Qt::AlignTop );

    layout69 = new QGridLayout( 0, 1, 1, 0, 6, "layout69"); 

    pushButtonAdvancedTerrain = new QPushButton( groupBox5_3, "pushButtonAdvancedTerrain" );
    QFont pushButtonAdvancedTerrain_font(  pushButtonAdvancedTerrain->font() );
    pushButtonAdvancedTerrain_font.setBold( FALSE );
    pushButtonAdvancedTerrain->setFont( pushButtonAdvancedTerrain_font ); 

    layout69->addWidget( pushButtonAdvancedTerrain, 0, 0 );

    lineEdit_Terrain = new QLineEdit( groupBox5_3, "lineEdit_Terrain" );
    QFont lineEdit_Terrain_font(  lineEdit_Terrain->font() );
    lineEdit_Terrain_font.setBold( FALSE );
    lineEdit_Terrain->setFont( lineEdit_Terrain_font ); 
    lineEdit_Terrain->setProperty( "frameShape", "LineEditPanel" );
    lineEdit_Terrain->setProperty( "frameShadow", "Sunken" );

    layout69->addWidget( lineEdit_Terrain, 0, 1 );

    groupBox5_3Layout->addMultiCellLayout( layout69, 1, 1, 0, 1 );

    layout30 = new QHBoxLayout( 0, 0, 6, "layout30"); 
    spacer3 = new QSpacerItem( 115, 16, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout30->addItem( spacer3 );

    textLabel2_4_2_2_3 = new QLabel( groupBox5_3, "textLabel2_4_2_2_3" );
    textLabel2_4_2_2_3->setProperty( "maximumSize", QSize( 60, 32767 ) );
    textLabel2_4_2_2_3->setProperty( "paletteForegroundColor", QColor( 0, 0, 0 ) );
    QFont textLabel2_4_2_2_3_font(  textLabel2_4_2_2_3->font() );
    textLabel2_4_2_2_3_font.setBold( FALSE );
    textLabel2_4_2_2_3->setFont( textLabel2_4_2_2_3_font ); 
    layout30->addWidget( textLabel2_4_2_2_3 );

    comboBox_Sexe = new QComboBox( FALSE, groupBox5_3, "comboBox_Sexe" );
    comboBox_Sexe->setProperty( "maximumSize", QSize( 100, 32767 ) );
    QFont comboBox_Sexe_font(  comboBox_Sexe->font() );
    comboBox_Sexe_font.setBold( FALSE );
    comboBox_Sexe->setFont( comboBox_Sexe_font ); 
    layout30->addWidget( comboBox_Sexe );

    layout28 = new QHBoxLayout( 0, 0, 6, "layout28"); 

    textLabel2_4_4 = new QLabel( groupBox5_3, "textLabel2_4_4" );
    textLabel2_4_4->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2_4_4->sizePolicy().hasHeightForWidth() ) );
    textLabel2_4_4->setProperty( "paletteForegroundColor", QColor( 0, 0, 0 ) );
    QFont textLabel2_4_4_font(  textLabel2_4_4->font() );
    textLabel2_4_4_font.setBold( FALSE );
    textLabel2_4_4->setFont( textLabel2_4_4_font ); 
    textLabel2_4_4->setProperty( "alignment", int( QLabel::AlignVCenter | QLabel::AlignRight ) );
    layout28->addWidget( textLabel2_4_4 );

    lineEdit_AgeMin = new CMaskedLineEdit( groupBox5_3, "lineEdit_AgeMin" );
    lineEdit_AgeMin->setProperty( "minimumSize", QSize( 50, 0 ) );
    lineEdit_AgeMin->setProperty( "maximumSize", QSize( 50, 32767 ) );
    QFont lineEdit_AgeMin_font(  lineEdit_AgeMin->font() );
    lineEdit_AgeMin->setFont( lineEdit_AgeMin_font ); 
    lineEdit_AgeMin->setProperty( "carMask", 32 );
    layout28->addWidget( lineEdit_AgeMin );

    textLabel2_4_2_4 = new QLabel( groupBox5_3, "textLabel2_4_2_4" );
    textLabel2_4_2_4->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2_4_2_4->sizePolicy().hasHeightForWidth() ) );
    textLabel2_4_2_4->setProperty( "paletteForegroundColor", QColor( 0, 0, 0 ) );
    QFont textLabel2_4_2_4_font(  textLabel2_4_2_4->font() );
    textLabel2_4_2_4_font.setPointSize( 10 );
    textLabel2_4_2_4_font.setBold( FALSE );
    textLabel2_4_2_4->setFont( textLabel2_4_2_4_font ); 
    layout28->addWidget( textLabel2_4_2_4 );

    lineEdit_AgeMax = new CMaskedLineEdit( groupBox5_3, "lineEdit_AgeMax" );
    lineEdit_AgeMax->setProperty( "minimumSize", QSize( 50, 0 ) );
    lineEdit_AgeMax->setProperty( "maximumSize", QSize( 50, 32767 ) );
    QFont lineEdit_AgeMax_font(  lineEdit_AgeMax->font() );
    lineEdit_AgeMax->setFont( lineEdit_AgeMax_font ); 
    lineEdit_AgeMax->setProperty( "carMask", 32 );
    layout28->addWidget( lineEdit_AgeMax );
    layout30->addLayout( layout28 );

    layout29 = new QHBoxLayout( 0, 0, 6, "layout29"); 

    textLabel2_5 = new QLabel( groupBox5_3, "textLabel2_5" );
    textLabel2_5->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2_5->sizePolicy().hasHeightForWidth() ) );
    textLabel2_5->setProperty( "paletteForegroundColor", QColor( 0, 0, 0 ) );
    QFont textLabel2_5_font(  textLabel2_5->font() );
    textLabel2_5_font.setBold( FALSE );
    textLabel2_5->setFont( textLabel2_5_font ); 
    textLabel2_5->setProperty( "alignment", int( QLabel::AlignVCenter | QLabel::AlignRight ) );
    layout29->addWidget( textLabel2_5 );

    lineEdit_EdPo_PoidsMin = new CMaskedLineEdit( groupBox5_3, "lineEdit_EdPo_PoidsMin" );
    lineEdit_EdPo_PoidsMin->setProperty( "minimumSize", QSize( 50, 0 ) );
    lineEdit_EdPo_PoidsMin->setProperty( "maximumSize", QSize( 50, 32767 ) );
    QFont lineEdit_EdPo_PoidsMin_font(  lineEdit_EdPo_PoidsMin->font() );
    lineEdit_EdPo_PoidsMin->setFont( lineEdit_EdPo_PoidsMin_font ); 
    lineEdit_EdPo_PoidsMin->setProperty( "carMask", 32 );
    layout29->addWidget( lineEdit_EdPo_PoidsMin );

    textLabel3_2 = new QLabel( groupBox5_3, "textLabel3_2" );
    textLabel3_2->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel3_2->sizePolicy().hasHeightForWidth() ) );
    textLabel3_2->setProperty( "paletteForegroundColor", QColor( 0, 0, 0 ) );
    QFont textLabel3_2_font(  textLabel3_2->font() );
    textLabel3_2_font.setPointSize( 10 );
    textLabel3_2_font.setBold( FALSE );
    textLabel3_2->setFont( textLabel3_2_font ); 
    layout29->addWidget( textLabel3_2 );

    lineEdit_EdPo_PoidsMax = new CMaskedLineEdit( groupBox5_3, "lineEdit_EdPo_PoidsMax" );
    lineEdit_EdPo_PoidsMax->setProperty( "minimumSize", QSize( 50, 0 ) );
    lineEdit_EdPo_PoidsMax->setProperty( "maximumSize", QSize( 50, 32767 ) );
    QFont lineEdit_EdPo_PoidsMax_font(  lineEdit_EdPo_PoidsMax->font() );
    lineEdit_EdPo_PoidsMax->setFont( lineEdit_EdPo_PoidsMax_font ); 
    lineEdit_EdPo_PoidsMax->setProperty( "carMask", 32 );
    layout29->addWidget( lineEdit_EdPo_PoidsMax );
    layout30->addLayout( layout29 );

    groupBox5_3Layout->addMultiCellLayout( layout30, 0, 0, 0, 1 );

    lineEdit_Indication = new QLineEdit( groupBox5_3, "lineEdit_Indication" );
    QFont lineEdit_Indication_font(  lineEdit_Indication->font() );
    lineEdit_Indication_font.setBold( FALSE );
    lineEdit_Indication->setFont( lineEdit_Indication_font ); 

    groupBox5_3Layout->addWidget( lineEdit_Indication, 2, 1 );

    textLabel2_4_2_2_2_3 = new QLabel( groupBox5_3, "textLabel2_4_2_2_2_3" );
    QFont textLabel2_4_2_2_2_3_font(  textLabel2_4_2_2_2_3->font() );
    textLabel2_4_2_2_2_3->setFont( textLabel2_4_2_2_2_3_font ); 
    textLabel2_4_2_2_2_3->setProperty( "frameShape", "LineEditPanel" );
    textLabel2_4_2_2_2_3->setProperty( "alignment", int( QLabel::AlignCenter ) );

    groupBox5_3Layout->addWidget( textLabel2_4_2_2_2_3, 2, 0 );

    Dlg_PosoManagerLayout->addWidget( groupBox5_3, 4, 0 );

    groupBox_UP = new QGroupBox( this, "groupBox_UP" );
    groupBox_UP->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, groupBox_UP->sizePolicy().hasHeightForWidth() ) );
    groupBox_UP->setProperty( "paletteForegroundColor", QColor( 0, 0, 255 ) );
    QFont groupBox_UP_font(  groupBox_UP->font() );
    groupBox_UP_font.setBold( TRUE );
    groupBox_UP->setFont( groupBox_UP_font ); 
    groupBox_UP->setColumnLayout(0, Qt::Vertical );
    groupBox_UP->layout()->setSpacing( 1 );
    groupBox_UP->layout()->setMargin( 2 );
    groupBox_UPLayout = new QGridLayout( groupBox_UP->layout() );
    groupBox_UPLayout->setAlignment( Qt::AlignTop );

    layout25 = new QHBoxLayout( 0, 0, 6, "layout25"); 

    slider_VarPoso = new QSlider( groupBox_UP, "slider_VarPoso" );
    slider_VarPoso->setProperty( "paletteForegroundColor", QColor( 170, 0, 0 ) );
    slider_VarPoso->setProperty( "minValue", 0 );
    slider_VarPoso->setProperty( "maxValue", 99 );
    slider_VarPoso->setProperty( "orientation", "Horizontal" );
    slider_VarPoso->setProperty( "tickmarks", "Above" );
    layout25->addWidget( slider_VarPoso );

    layout24 = new QHBoxLayout( 0, 0, 6, "layout24"); 

    textLabel2 = new QLabel( groupBox_UP, "textLabel2" );
    textLabel2->setProperty( "paletteForegroundColor", QColor( 0, 0, 0 ) );
    QFont textLabel2_font(  textLabel2->font() );
    textLabel2_font.setPointSize( 10 );
    textLabel2_font.setBold( FALSE );
    textLabel2->setFont( textLabel2_font ); 
    textLabel2->setProperty( "alignment", int( QLabel::AlignVCenter | QLabel::AlignRight ) );
    layout24->addWidget( textLabel2 );

    lineEditFactCorpQU = new CMaskedLineEdit( groupBox_UP, "lineEditFactCorpQU" );
    lineEditFactCorpQU->setProperty( "minimumSize", QSize( 100, 0 ) );
    lineEditFactCorpQU->setProperty( "maximumSize", QSize( 100, 20 ) );
    QFont lineEditFactCorpQU_font(  lineEditFactCorpQU->font() );
    lineEditFactCorpQU->setFont( lineEditFactCorpQU_font ); 
    lineEditFactCorpQU->setProperty( "carMask", 32 );
    layout24->addWidget( lineEditFactCorpQU );

    comboBoxFactCorpUnit = new QComboBox( FALSE, groupBox_UP, "comboBoxFactCorpUnit" );
    comboBoxFactCorpUnit->setProperty( "maximumSize", QSize( 32767, 20 ) );
    comboBoxFactCorpUnit->setProperty( "paletteForegroundColor", QColor( 0, 0, 255 ) );
    QFont comboBoxFactCorpUnit_font(  comboBoxFactCorpUnit->font() );
    comboBoxFactCorpUnit_font.setBold( FALSE );
    comboBoxFactCorpUnit->setFont( comboBoxFactCorpUnit_font ); 
    layout24->addWidget( comboBoxFactCorpUnit );
    layout25->addLayout( layout24 );

    groupBox_UPLayout->addMultiCellLayout( layout25, 2, 2, 0, 2 );

    layout20_2 = new QHBoxLayout( 0, 0, 6, "layout20_2"); 

    textLabel5 = new QLabel( groupBox_UP, "textLabel5" );
    textLabel5->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, textLabel5->sizePolicy().hasHeightForWidth() ) );
    textLabel5->setProperty( "paletteForegroundColor", QColor( 0, 0, 0 ) );
    QFont textLabel5_font(  textLabel5->font() );
    textLabel5_font.setBold( FALSE );
    textLabel5->setFont( textLabel5_font ); 
    textLabel5->setProperty( "frameShape", "LineEditPanel" );
    textLabel5->setProperty( "margin", 0 );
    layout20_2->addWidget( textLabel5 );

    layout26 = new QHBoxLayout( 0, 0, 6, "layout26"); 

    lineEditQUP1byUP2 = new CMaskedLineEdit( groupBox_UP, "lineEditQUP1byUP2" );
    lineEditQUP1byUP2->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)1, 0, 0, lineEditQUP1byUP2->sizePolicy().hasHeightForWidth() ) );
    lineEditQUP1byUP2->setProperty( "minimumSize", QSize( 100, 20 ) );
    lineEditQUP1byUP2->setProperty( "maximumSize", QSize( 100, 20 ) );
    lineEditQUP1byUP2->setProperty( "carMask", 32 );
    layout26->addWidget( lineEditQUP1byUP2 );

    textLabelCoeffResult = new QLabel( groupBox_UP, "textLabelCoeffResult" );
    textLabelCoeffResult->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, textLabelCoeffResult->sizePolicy().hasHeightForWidth() ) );
    textLabelCoeffResult->setProperty( "minimumSize", QSize( 0, 25 ) );
    textLabelCoeffResult->setProperty( "maximumSize", QSize( 32767, 25 ) );
    textLabelCoeffResult->setProperty( "paletteForegroundColor", QColor( 0, 0, 0 ) );
    QFont textLabelCoeffResult_font(  textLabelCoeffResult->font() );
    textLabelCoeffResult_font.setBold( FALSE );
    textLabelCoeffResult->setFont( textLabelCoeffResult_font ); 
    layout26->addWidget( textLabelCoeffResult );
    layout20_2->addLayout( layout26 );

    groupBox_UPLayout->addMultiCellLayout( layout20_2, 4, 4, 0, 2 );

    lineEdit_TailleTest = new CMaskedLineEdit( groupBox_UP, "lineEdit_TailleTest" );
    lineEdit_TailleTest->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)1, 0, 0, lineEdit_TailleTest->sizePolicy().hasHeightForWidth() ) );
    lineEdit_TailleTest->setProperty( "minimumSize", QSize( 100, 20 ) );
    lineEdit_TailleTest->setProperty( "maximumSize", QSize( 100, 20 ) );
    QFont lineEdit_TailleTest_font(  lineEdit_TailleTest->font() );
    lineEdit_TailleTest->setFont( lineEdit_TailleTest_font ); 
    lineEdit_TailleTest->setProperty( "carMask", 32 );

    groupBox_UPLayout->addWidget( lineEdit_TailleTest, 6, 1 );

    lineEdit_PoidsTest = new CMaskedLineEdit( groupBox_UP, "lineEdit_PoidsTest" );
    lineEdit_PoidsTest->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, lineEdit_PoidsTest->sizePolicy().hasHeightForWidth() ) );
    lineEdit_PoidsTest->setProperty( "minimumSize", QSize( 100, 20 ) );
    lineEdit_PoidsTest->setProperty( "maximumSize", QSize( 100, 20 ) );
    QFont lineEdit_PoidsTest_font(  lineEdit_PoidsTest->font() );
    lineEdit_PoidsTest->setFont( lineEdit_PoidsTest_font ); 
    lineEdit_PoidsTest->setProperty( "carMask", 32 );

    groupBox_UPLayout->addWidget( lineEdit_PoidsTest, 5, 1 );

    textBrowser_Result = new QTextBrowser( groupBox_UP, "textBrowser_Result" );
    textBrowser_Result->setProperty( "maximumSize", QSize( 32767, 50 ) );
    textBrowser_Result->setProperty( "paletteBackgroundColor", QColor( 170, 255, 255 ) );

    groupBox_UPLayout->addMultiCellWidget( textBrowser_Result, 5, 6, 2, 2 );

    textLabel2_2 = new QLabel( groupBox_UP, "textLabel2_2" );
    QFont textLabel2_2_font(  textLabel2_2->font() );
    textLabel2_2->setFont( textLabel2_2_font ); 
    textLabel2_2->setProperty( "alignment", int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    groupBox_UPLayout->addWidget( textLabel2_2, 5, 0 );

    textLabel1 = new QLabel( groupBox_UP, "textLabel1" );
    QFont textLabel1_font(  textLabel1->font() );
    textLabel1->setFont( textLabel1_font ); 
    textLabel1->setProperty( "alignment", int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    groupBox_UPLayout->addWidget( textLabel1, 6, 0 );

    layout20_3 = new QHBoxLayout( 0, 0, 6, "layout20_3"); 

    lineEdit_a_UP2_2 = new QLabel( groupBox_UP, "lineEdit_a_UP2_2" );
    lineEdit_a_UP2_2->setProperty( "minimumSize", QSize( 50, 0 ) );
    lineEdit_a_UP2_2->setProperty( "maximumSize", QSize( 50, 20 ) );
    lineEdit_a_UP2_2->setProperty( "paletteForegroundColor", QColor( 0, 0, 255 ) );
    QFont lineEdit_a_UP2_2_font(  lineEdit_a_UP2_2->font() );
    lineEdit_a_UP2_2->setFont( lineEdit_a_UP2_2_font ); 
    lineEdit_a_UP2_2->setProperty( "frameShape", "LineEditPanel" );
    lineEdit_a_UP2_2->setProperty( "alignment", int( QLabel::AlignCenter ) );
    layout20_3->addWidget( lineEdit_a_UP2_2 );

    lineEdit_QMin_UP2 = new QLineEdit( groupBox_UP, "lineEdit_QMin_UP2" );
    lineEdit_QMin_UP2->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, lineEdit_QMin_UP2->sizePolicy().hasHeightForWidth() ) );
    lineEdit_QMin_UP2->setProperty( "minimumSize", QSize( 100, 20 ) );
    lineEdit_QMin_UP2->setProperty( "maximumSize", QSize( 100, 20 ) );
    QFont lineEdit_QMin_UP2_font(  lineEdit_QMin_UP2->font() );
    lineEdit_QMin_UP2_font.setBold( FALSE );
    lineEdit_QMin_UP2->setFont( lineEdit_QMin_UP2_font ); 
    lineEdit_QMin_UP2->setProperty( "readOnly", QVariant( TRUE, 0 ) );
    layout20_3->addWidget( lineEdit_QMin_UP2 );

    lineEdit_a_UP2 = new QLabel( groupBox_UP, "lineEdit_a_UP2" );
    lineEdit_a_UP2->setProperty( "minimumSize", QSize( 40, 20 ) );
    lineEdit_a_UP2->setProperty( "maximumSize", QSize( 40, 20 ) );
    lineEdit_a_UP2->setProperty( "alignment", int( QLabel::AlignCenter ) );
    layout20_3->addWidget( lineEdit_a_UP2 );

    lineEdit_QMax_UP2 = new QLineEdit( groupBox_UP, "lineEdit_QMax_UP2" );
    lineEdit_QMax_UP2->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, lineEdit_QMax_UP2->sizePolicy().hasHeightForWidth() ) );
    lineEdit_QMax_UP2->setProperty( "minimumSize", QSize( 100, 20 ) );
    lineEdit_QMax_UP2->setProperty( "maximumSize", QSize( 100, 20 ) );
    QFont lineEdit_QMax_UP2_font(  lineEdit_QMax_UP2->font() );
    lineEdit_QMax_UP2_font.setBold( FALSE );
    lineEdit_QMax_UP2->setFont( lineEdit_QMax_UP2_font ); 
    lineEdit_QMax_UP2->setProperty( "readOnly", QVariant( TRUE, 0 ) );
    layout20_3->addWidget( lineEdit_QMax_UP2 );

    comboBoxUP_2 = new QComboBox( FALSE, groupBox_UP, "comboBoxUP_2" );
    comboBoxUP_2->setProperty( "minimumSize", QSize( 200, 0 ) );
    comboBoxUP_2->setProperty( "maximumSize", QSize( 200, 20 ) );
    QFont comboBoxUP_2_font(  comboBoxUP_2->font() );
    comboBoxUP_2_font.setBold( FALSE );
    comboBoxUP_2->setFont( comboBoxUP_2_font ); 
    comboBoxUP_2->setProperty( "editable", QVariant( FALSE, 0 ) );
    comboBoxUP_2->setProperty( "sizeLimit", 20 );
    comboBoxUP_2->setProperty( "autoCompletion", QVariant( TRUE, 0 ) );
    comboBoxUP_2->setProperty( "duplicatesEnabled", QVariant( FALSE, 0 ) );
    layout20_3->addWidget( comboBoxUP_2 );

    pushButtonNewUP2_Unit = new QPushButton( groupBox_UP, "pushButtonNewUP2_Unit" );
    pushButtonNewUP2_Unit->setProperty( "maximumSize", QSize( 32767, 20 ) );
    layout20_3->addWidget( pushButtonNewUP2_Unit );

    groupBox_UPLayout->addMultiCellLayout( layout20_3, 3, 3, 0, 2 );

    layout24_2 = new QHBoxLayout( 0, 0, 6, "layout24_2"); 

    textLabel3 = new QLabel( groupBox_UP, "textLabel3" );
    textLabel3->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    textLabel3->setProperty( "paletteForegroundColor", QColor( 0, 0, 0 ) );
    QFont textLabel3_font(  textLabel3->font() );
    textLabel3_font.setBold( FALSE );
    textLabel3->setFont( textLabel3_font ); 
    layout24_2->addWidget( textLabel3 );

    lineEdit_Periode = new CMaskedLineEdit( groupBox_UP, "lineEdit_Periode" );
    lineEdit_Periode->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)7, 0, 0, lineEdit_Periode->sizePolicy().hasHeightForWidth() ) );
    lineEdit_Periode->setProperty( "minimumSize", QSize( 100, 20 ) );
    lineEdit_Periode->setProperty( "maximumSize", QSize( 100, 20 ) );
    QFont lineEdit_Periode_font(  lineEdit_Periode->font() );
    lineEdit_Periode->setFont( lineEdit_Periode_font ); 
    lineEdit_Periode->setProperty( "carMask", 32 );
    layout24_2->addWidget( lineEdit_Periode );

    textLabel4 = new QLabel( groupBox_UP, "textLabel4" );
    textLabel4->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel4->sizePolicy().hasHeightForWidth() ) );
    textLabel4->setProperty( "paletteForegroundColor", QColor( 0, 0, 0 ) );
    QFont textLabel4_font(  textLabel4->font() );
    textLabel4_font.setBold( FALSE );
    textLabel4->setFont( textLabel4_font ); 
    layout24_2->addWidget( textLabel4 );

    comboBoxPeriode = new QComboBox( FALSE, groupBox_UP, "comboBoxPeriode" );
    comboBoxPeriode->setProperty( "maximumSize", QSize( 32767, 19 ) );
    QFont comboBoxPeriode_font(  comboBoxPeriode->font() );
    comboBoxPeriode_font.setBold( FALSE );
    comboBoxPeriode->setFont( comboBoxPeriode_font ); 
    layout24_2->addWidget( comboBoxPeriode );

    textLabel4_2 = new QLabel( groupBox_UP, "textLabel4_2" );
    textLabel4_2->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, textLabel4_2->sizePolicy().hasHeightForWidth() ) );
    textLabel4_2->setProperty( "maximumSize", QSize( 32767, 20 ) );
    textLabel4_2->setProperty( "paletteForegroundColor", QColor( 0, 0, 0 ) );
    QFont textLabel4_2_font(  textLabel4_2->font() );
    textLabel4_2_font.setBold( FALSE );
    textLabel4_2->setFont( textLabel4_2_font ); 
    layout24_2->addWidget( textLabel4_2 );

    lineEdit_UP1_Max = new CMaskedLineEdit( groupBox_UP, "lineEdit_UP1_Max" );
    lineEdit_UP1_Max->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, lineEdit_UP1_Max->sizePolicy().hasHeightForWidth() ) );
    lineEdit_UP1_Max->setProperty( "minimumSize", QSize( 100, 20 ) );
    lineEdit_UP1_Max->setProperty( "maximumSize", QSize( 100, 20 ) );
    QFont lineEdit_UP1_Max_font(  lineEdit_UP1_Max->font() );
    lineEdit_UP1_Max_font.setBold( FALSE );
    lineEdit_UP1_Max->setFont( lineEdit_UP1_Max_font ); 
    lineEdit_UP1_Max->setProperty( "carMask", 32 );
    layout24_2->addWidget( lineEdit_UP1_Max );

    groupBox_UPLayout->addMultiCellLayout( layout24_2, 0, 0, 0, 2 );

    layout23 = new QHBoxLayout( 0, 0, 6, "layout23"); 

    lineEdit_a_UP2_2_2 = new QLabel( groupBox_UP, "lineEdit_a_UP2_2_2" );
    lineEdit_a_UP2_2_2->setProperty( "minimumSize", QSize( 50, 0 ) );
    lineEdit_a_UP2_2_2->setProperty( "maximumSize", QSize( 50, 20 ) );
    lineEdit_a_UP2_2_2->setProperty( "paletteForegroundColor", QColor( 0, 0, 255 ) );
    QFont lineEdit_a_UP2_2_2_font(  lineEdit_a_UP2_2_2->font() );
    lineEdit_a_UP2_2_2->setFont( lineEdit_a_UP2_2_2_font ); 
    lineEdit_a_UP2_2_2->setProperty( "frameShape", "LineEditPanel" );
    lineEdit_a_UP2_2_2->setProperty( "alignment", int( QLabel::AlignCenter ) );
    layout23->addWidget( lineEdit_a_UP2_2_2 );

    lineEdit_QMin_UP1 = new CMaskedLineEdit( groupBox_UP, "lineEdit_QMin_UP1" );
    lineEdit_QMin_UP1->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, lineEdit_QMin_UP1->sizePolicy().hasHeightForWidth() ) );
    lineEdit_QMin_UP1->setProperty( "minimumSize", QSize( 100, 20 ) );
    lineEdit_QMin_UP1->setProperty( "maximumSize", QSize( 100, 20 ) );
    QFont lineEdit_QMin_UP1_font(  lineEdit_QMin_UP1->font() );
    lineEdit_QMin_UP1->setFont( lineEdit_QMin_UP1_font ); 
    lineEdit_QMin_UP1->setProperty( "carMask", 32 );
    layout23->addWidget( lineEdit_QMin_UP1 );

    pushButton_A = new QPushButton( groupBox_UP, "pushButton_A" );
    pushButton_A->setProperty( "minimumSize", QSize( 40, 20 ) );
    pushButton_A->setProperty( "maximumSize", QSize( 40, 20 ) );
    pushButton_A->setProperty( "paletteForegroundColor", QColor( 0, 0, 255 ) );
    pushButton_A->setProperty( "toggleButton", QVariant( TRUE, 0 ) );
    layout23->addWidget( pushButton_A );

    lineEdit_QMax_UP1 = new CMaskedLineEdit( groupBox_UP, "lineEdit_QMax_UP1" );
    lineEdit_QMax_UP1->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, lineEdit_QMax_UP1->sizePolicy().hasHeightForWidth() ) );
    lineEdit_QMax_UP1->setProperty( "minimumSize", QSize( 100, 20 ) );
    lineEdit_QMax_UP1->setProperty( "maximumSize", QSize( 100, 20 ) );
    QFont lineEdit_QMax_UP1_font(  lineEdit_QMax_UP1->font() );
    lineEdit_QMax_UP1->setFont( lineEdit_QMax_UP1_font ); 
    lineEdit_QMax_UP1->setProperty( "carMask", 32 );
    layout23->addWidget( lineEdit_QMax_UP1 );

    comboBoxUP_1 = new QComboBox( FALSE, groupBox_UP, "comboBoxUP_1" );
    comboBoxUP_1->setProperty( "minimumSize", QSize( 200, 0 ) );
    comboBoxUP_1->setProperty( "maximumSize", QSize( 200, 20 ) );
    QFont comboBoxUP_1_font(  comboBoxUP_1->font() );
    comboBoxUP_1_font.setBold( FALSE );
    comboBoxUP_1->setFont( comboBoxUP_1_font ); 
    comboBoxUP_1->setProperty( "editable", QVariant( FALSE, 0 ) );
    comboBoxUP_1->setProperty( "sizeLimit", 20 );
    comboBoxUP_1->setProperty( "autoCompletion", QVariant( TRUE, 0 ) );
    layout23->addWidget( comboBoxUP_1 );

    pushButtonNewUP1_Unit = new QPushButton( groupBox_UP, "pushButtonNewUP1_Unit" );
    pushButtonNewUP1_Unit->setProperty( "maximumSize", QSize( 32767, 20 ) );
    layout23->addWidget( pushButtonNewUP1_Unit );

    groupBox_UPLayout->addMultiCellLayout( layout23, 1, 1, 0, 2 );

    Dlg_PosoManagerLayout->addWidget( groupBox_UP, 2, 0 );

    groupBox16 = new QGroupBox( this, "groupBox16" );
    groupBox16->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, groupBox16->sizePolicy().hasHeightForWidth() ) );
    groupBox16->setProperty( "paletteForegroundColor", QColor( 0, 0, 255 ) );
    QFont groupBox16_font(  groupBox16->font() );
    groupBox16_font.setBold( TRUE );
    groupBox16->setFont( groupBox16_font ); 
    groupBox16->setColumnLayout(0, Qt::Vertical );
    groupBox16->layout()->setSpacing( 1 );
    groupBox16->layout()->setMargin( 2 );
    groupBox16Layout = new QGridLayout( groupBox16->layout() );
    groupBox16Layout->setAlignment( Qt::AlignTop );

    textLabel_Moment = new QLabel( groupBox16, "textLabel_Moment" );
    textLabel_Moment->setProperty( "paletteForegroundColor", QColor( 0, 0, 0 ) );
    QFont textLabel_Moment_font(  textLabel_Moment->font() );
    textLabel_Moment_font.setBold( FALSE );
    textLabel_Moment_font.setItalic( TRUE );
    textLabel_Moment->setFont( textLabel_Moment_font ); 
    textLabel_Moment->setProperty( "alignment", int( QLabel::AlignCenter ) );

    groupBox16Layout->addMultiCellWidget( textLabel_Moment, 0, 0, 0, 1 );

    comboBoxMoment = new QComboBox( FALSE, groupBox16, "comboBoxMoment" );
    comboBoxMoment->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, comboBoxMoment->sizePolicy().hasHeightForWidth() ) );
    QFont comboBoxMoment_font(  comboBoxMoment->font() );
    comboBoxMoment_font.setBold( FALSE );
    comboBoxMoment->setFont( comboBoxMoment_font ); 
    comboBoxMoment->setProperty( "sizeLimit", 20 );

    groupBox16Layout->addWidget( comboBoxMoment, 0, 2 );

    textLabel_Pendant = new QLabel( groupBox16, "textLabel_Pendant" );
    textLabel_Pendant->setProperty( "paletteForegroundColor", QColor( 0, 0, 0 ) );
    QFont textLabel_Pendant_font(  textLabel_Pendant->font() );
    textLabel_Pendant_font.setBold( FALSE );
    textLabel_Pendant_font.setItalic( TRUE );
    textLabel_Pendant->setFont( textLabel_Pendant_font ); 
    textLabel_Pendant->setProperty( "alignment", int( QLabel::AlignCenter ) );

    groupBox16Layout->addWidget( textLabel_Pendant, 0, 3 );

    comboBoxPendant = new QComboBox( FALSE, groupBox16, "comboBoxPendant" );
    comboBoxPendant->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, comboBoxPendant->sizePolicy().hasHeightForWidth() ) );
    QFont comboBoxPendant_font(  comboBoxPendant->font() );
    comboBoxPendant_font.setBold( FALSE );
    comboBoxPendant->setFont( comboBoxPendant_font ); 
    comboBoxPendant->setProperty( "editable", QVariant( TRUE, 0 ) );
    comboBoxPendant->setProperty( "sizeLimit", 18 );

    groupBox16Layout->addWidget( comboBoxPendant, 0, 4 );

    pushButton_PosoSchemaEx = new QPushButton( groupBox16, "pushButton_PosoSchemaEx" );
    pushButton_PosoSchemaEx->setProperty( "maximumSize", QSize( 200, 32767 ) );
    QFont pushButton_PosoSchemaEx_font(  pushButton_PosoSchemaEx->font() );
    pushButton_PosoSchemaEx_font.setBold( FALSE );
    pushButton_PosoSchemaEx->setFont( pushButton_PosoSchemaEx_font ); 

    groupBox16Layout->addWidget( pushButton_PosoSchemaEx, 0, 5 );

    layout23_2 = new QGridLayout( 0, 1, 1, 0, 6, "layout23_2"); 

    radioButtonSecable1 = new QRadioButton( groupBox16, "radioButtonSecable1" );
    radioButtonSecable1->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, radioButtonSecable1->sizePolicy().hasHeightForWidth() ) );
    radioButtonSecable1->setProperty( "paletteForegroundColor", QColor( 0, 0, 0 ) );
    QFont radioButtonSecable1_font(  radioButtonSecable1->font() );
    radioButtonSecable1_font.setBold( FALSE );
    radioButtonSecable1->setFont( radioButtonSecable1_font ); 

    layout23_2->addWidget( radioButtonSecable1, 0, 1 );

    radioButtonSecable4 = new QRadioButton( groupBox16, "radioButtonSecable4" );
    radioButtonSecable4->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, radioButtonSecable4->sizePolicy().hasHeightForWidth() ) );
    radioButtonSecable4->setProperty( "paletteForegroundColor", QColor( 0, 0, 0 ) );
    QFont radioButtonSecable4_font(  radioButtonSecable4->font() );
    radioButtonSecable4_font.setBold( FALSE );
    radioButtonSecable4->setFont( radioButtonSecable4_font ); 

    layout23_2->addWidget( radioButtonSecable4, 0, 3 );

    lineEdit_SpecPrise = new QLineEdit( groupBox16, "lineEdit_SpecPrise" );
    lineEdit_SpecPrise->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)0, 0, 0, lineEdit_SpecPrise->sizePolicy().hasHeightForWidth() ) );

    layout23_2->addWidget( lineEdit_SpecPrise, 0, 0 );

    radioButtonSecable2 = new QRadioButton( groupBox16, "radioButtonSecable2" );
    radioButtonSecable2->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, radioButtonSecable2->sizePolicy().hasHeightForWidth() ) );
    radioButtonSecable2->setProperty( "paletteForegroundColor", QColor( 0, 0, 0 ) );
    QFont radioButtonSecable2_font(  radioButtonSecable2->font() );
    radioButtonSecable2_font.setBold( FALSE );
    radioButtonSecable2->setFont( radioButtonSecable2_font ); 

    layout23_2->addWidget( radioButtonSecable2, 0, 2 );

    groupBox16Layout->addMultiCellLayout( layout23_2, 1, 1, 0, 5 );

    textLabel1_2 = new QLabel( groupBox16, "textLabel1_2" );
    textLabel1_2->setProperty( "paletteForegroundColor", QColor( 0, 0, 255 ) );
    QFont textLabel1_2_font(  textLabel1_2->font() );
    textLabel1_2->setFont( textLabel1_2_font ); 
    textLabel1_2->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignVCenter | QLabel::AlignLeft ) );

    groupBox16Layout->addWidget( textLabel1_2, 2, 0 );

    lineEdit_Note = new QLineEdit( groupBox16, "lineEdit_Note" );
    QFont lineEdit_Note_font(  lineEdit_Note->font() );
    lineEdit_Note_font.setBold( FALSE );
    lineEdit_Note->setFont( lineEdit_Note_font ); 

    groupBox16Layout->addMultiCellWidget( lineEdit_Note, 2, 2, 1, 5 );

    Dlg_PosoManagerLayout->addWidget( groupBox16, 3, 0 );

    layout20_4 = new QGridLayout( 0, 1, 1, 0, 6, "layout20_4"); 

    pushButton_RecordPoso = new QPushButton( this, "pushButton_RecordPoso" );

    layout20_4->addWidget( pushButton_RecordPoso, 0, 2 );

    pushButton_ErasePoso = new QPushButton( this, "pushButton_ErasePoso" );

    layout20_4->addWidget( pushButton_ErasePoso, 0, 1 );

    pushButton_AddPoso = new QPushButton( this, "pushButton_AddPoso" );
    pushButton_AddPoso->setProperty( "default", QVariant( TRUE, 0 ) );

    layout20_4->addWidget( pushButton_AddPoso, 0, 0 );

    pushButton_Quitter = new QPushButton( this, "pushButton_Quitter" );
    pushButton_Quitter->setProperty( "default", QVariant( FALSE, 0 ) );

    layout20_4->addWidget( pushButton_Quitter, 0, 3 );

    Dlg_PosoManagerLayout->addLayout( layout20_4, 5, 0 );
    languageChange();
    resize( QSize(807, 658).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( listView_MedicaPoso, SIGNAL( clicked(QListViewItem*) ), this, SLOT( listView_MedicaPoso_clicked(QListViewItem*) ) );
    connect( comboBoxFactCorpUnit, SIGNAL( activated(int) ), this, SLOT( comboBoxFactCorpUnit_activated(int) ) );
    connect( comboBoxUP_2, SIGNAL( activated(int) ), this, SLOT( comboBoxUP_2_activated(int) ) );
    connect( comboBoxUP_2, SIGNAL( textChanged(const QString&) ), this, SLOT( comboBoxUP_2_textChanged(const QString&) ) );
    connect( comboBoxUP_1, SIGNAL( textChanged(const QString&) ), this, SLOT( comboBoxUP_1_textChanged(const QString&) ) );
    connect( comboBoxUP_1, SIGNAL( activated(int) ), this, SLOT( comboBoxUP_1_activated(int) ) );
    connect( comboBoxPeriode, SIGNAL( activated(const QString&) ), this, SLOT( comboBoxPeriode_activated(const QString&) ) );
    connect( comboBoxMoment, SIGNAL( activated(const QString&) ), this, SLOT( comboBoxMoment_activated(const QString&) ) );
    connect( radioButtonSecable1, SIGNAL( clicked() ), this, SLOT( radioButtonSecable1_clicked() ) );
    connect( radioButtonSecable2, SIGNAL( clicked() ), this, SLOT( radioButtonSecable2_clicked() ) );
    connect( radioButtonSecable4, SIGNAL( clicked() ), this, SLOT( radioButtonSecable4_clicked() ) );
    connect( slider_VarPoso, SIGNAL( valueChanged(int) ), this, SLOT( slider_VarPoso_valueChanged(int) ) );
    connect( comboBoxPendant, SIGNAL( activated(const QString&) ), this, SLOT( comboBoxPendant_activated(const QString&) ) );
    connect( lineEdit_SpecPrise, SIGNAL( textChanged(const QString&) ), this, SLOT( lineEdit_SpecPrise_textChanged(const QString&) ) );
    connect( pushButtonNewUP1_Unit, SIGNAL( clicked() ), this, SLOT( pushButtonNewUP1_Unit_clicked() ) );
    connect( pushButtonNewUP2_Unit, SIGNAL( clicked() ), this, SLOT( pushButtonNewUP2_Unit_clicked() ) );
    connect( pushButton_AddPoso, SIGNAL( clicked() ), this, SLOT( pushButton_AddPoso_clicked() ) );
    connect( listView_MedicaPoso, SIGNAL( currentChanged(QListViewItem*) ), this, SLOT( listView_MedicaPoso_currentChanged(QListViewItem*) ) );
    connect( pushButton_RecordPoso, SIGNAL( clicked() ), this, SLOT( pushButton_RecordPoso_clicked() ) );
    connect( pushButton_ErasePoso, SIGNAL( clicked() ), this, SLOT( pushButton_ErasePoso_clicked() ) );
    connect( listView_Produits, SIGNAL( clicked(QListViewItem*) ), this, SLOT( listView_Produits_clicked(QListViewItem*) ) );
    connect( listView_Produits, SIGNAL( currentChanged(QListViewItem*) ), this, SLOT( listView_Produits_currentChanged(QListViewItem*) ) );
    connect( pushButtonAdvancedTerrain, SIGNAL( clicked() ), this, SLOT( pushButtonAdvancedTerrain_clicked() ) );
    connect( pushButtonListPosoCopier, SIGNAL( clicked() ), this, SLOT( pushButtonListPosoCopier_clicked() ) );
    connect( pushButtonListPosoColler, SIGNAL( clicked() ), this, SLOT( pushButtonListPosoColler_clicked() ) );
    connect( pushButtonDefPosoCopier, SIGNAL( clicked() ), this, SLOT( pushButtonDefPosoCopier_clicked() ) );
    connect( pushButtonDefPosoColler, SIGNAL( clicked() ), this, SLOT( pushButtonDefPosoColler_clicked() ) );
    connect( pushButton_A, SIGNAL( clicked() ), this, SLOT( pushButton_A_clicked() ) );

    // tab order
    setTabOrder( pushButton_PosoSchemaEx, lineEdit_Indication );
    setTabOrder( lineEdit_Indication, pushButtonAdvancedTerrain );
    setTabOrder( pushButtonAdvancedTerrain, lineEdit_Terrain );
    setTabOrder( lineEdit_Terrain, comboBox_Sexe );
    setTabOrder( comboBox_Sexe, radioButtonSecable1 );
    setTabOrder( radioButtonSecable1, radioButtonSecable2 );
    setTabOrder( radioButtonSecable2, radioButtonSecable4 );
    setTabOrder( radioButtonSecable4, comboBoxMoment );
    setTabOrder( comboBoxMoment, comboBoxPendant );
    setTabOrder( comboBoxPendant, lineEdit_SpecPrise );
    setTabOrder( lineEdit_SpecPrise, pushButton_AddPoso );
    setTabOrder( pushButton_AddPoso, pushButton_ErasePoso );
    setTabOrder( pushButton_ErasePoso, pushButton_RecordPoso );
    setTabOrder( pushButton_RecordPoso, slider_VarPoso );
    setTabOrder( slider_VarPoso, comboBoxFactCorpUnit );
    setTabOrder( comboBoxFactCorpUnit, textBrowser_Result );
    setTabOrder( textBrowser_Result, lineEdit_QMin_UP2 );
    setTabOrder( lineEdit_QMin_UP2, lineEdit_QMax_UP2 );
    setTabOrder( lineEdit_QMax_UP2, comboBoxUP_2 );
    setTabOrder( comboBoxUP_2, pushButtonNewUP2_Unit );
    setTabOrder( pushButtonNewUP2_Unit, comboBoxPeriode );
    setTabOrder( comboBoxPeriode, pushButton_A );
    setTabOrder( pushButton_A, comboBoxUP_1 );
    setTabOrder( comboBoxUP_1, pushButtonNewUP1_Unit );
    setTabOrder( pushButtonNewUP1_Unit, listView_Produits );
    setTabOrder( listView_Produits, pushButtonListPosoCopier );
    setTabOrder( pushButtonListPosoCopier, pushButtonListPosoColler );
    setTabOrder( pushButtonListPosoColler, pushButtonDefPosoCopier );
    setTabOrder( pushButtonDefPosoCopier, pushButtonDefPosoColler );
    setTabOrder( pushButtonDefPosoColler, listView_MedicaPoso );

    // buddies
    textLabel2_4_2_2_3->setBuddy( comboBox_Sexe );
    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
Dlg_PosoManager::~Dlg_PosoManager()
{
    destroy();
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Dlg_PosoManager::languageChange()
{
    setProperty( "caption", tr( "Gestion des posologies" ) );
    textLabel1_3->setProperty( "text", trUtf8( "\x50\x6f\x73\x6f\x6c\x6f\x67\x69\x65\x73\x20\x64\xc3\xa9\x6a\xc3\xa0\x20\x64\xc3\xa9"
    "\x66\x69\x6e\x69\x65\x73\x20\x70\x6f\x75\x72\x20\x63\x65\x20\x70\x72\x6f\x64\x75"
    "\x69\x74" ) );
    listView_Produits->header()->setLabel( 0, tr( "Produit" ) );
    listView_Produits->header()->setLabel( 1, tr( "CodeProduit" ) );
    listView_Produits->header()->setLabel( 2, tr( "Pk_t00" ) );
    listView_Produits->header()->setLabel( 3, tr( "pk_t4b" ) );
    listView_Produits->header()->setLabel( 4, tr( "CodeCIP" ) );
    listView_Produits->header()->setLabel( 5, tr( "CodeUV" ) );
    listView_Produits->header()->setLabel( 6, tr( "IsG" ) );
    listView_Produits->header()->setLabel( 7, tr( "IsD" ) );
    listView_Produits->header()->setLabel( 8, tr( "num" ) );
    pushButtonListPosoCopier->setProperty( "text", tr( "&Copier Liste Poso >>>" ) );
    pushButtonListPosoCopier->setProperty( "accel", QKeySequence( tr( "Alt+C" ) ) );
    pushButtonListPosoColler->setProperty( "text", tr( "C&oller " ) );
    pushButtonListPosoColler->setProperty( "accel", QKeySequence( tr( "Alt+O" ) ) );
    pushButtonDefPosoCopier->setProperty( "text", trUtf8( "\x43\x6f\x70\x69\x65\x72\x20\x75\x6e\x65\x20\x26\x64\xc3\xa9\x66\x69\x6e\x69\x74\x69"
    "\x6f\x6e\x20\x64\x65\x20\x70\x6f\x73\x6f\x6c\x6f\x67\x69\x65\x20\x20\x3e\x3e\x3e"
    "" ) );
    pushButtonDefPosoCopier->setProperty( "accel", QKeySequence( tr( "Alt+D" ) ) );
    pushButtonDefPosoColler->setProperty( "text", trUtf8( "\x43\x6f\x6c\x6c\x65\x72\x20\x6c\x61\x20\x64\xc3\xa9\x66\x69\x6e\x69\x74\x69\x6f\x6e"
    "\x20\x64\x65\x20\x26\x70\x6f\x73\x6f\x6c\x6f\x67\x69\x65\x20\x63\x69\x2d\x64\x65"
    "\x73\x73\x6f\x75\x73" ) );
    pushButtonDefPosoColler->setProperty( "accel", QKeySequence( tr( "Alt+P" ) ) );
    listView_MedicaPoso->header()->setLabel( 0, tr( "PrimKey" ) );
    listView_MedicaPoso->header()->setLabel( 1, tr( "Code CIP" ) );
    listView_MedicaPoso->header()->setLabel( 2, tr( "Libelle" ) );
    listView_MedicaPoso->header()->setLabel( 3, tr( "Poso Min" ) );
    listView_MedicaPoso->header()->setLabel( 4, tr( "Poso Max" ) );
    listView_MedicaPoso->header()->setLabel( 5, tr( "Posos Unit" ) );
    listView_MedicaPoso->header()->setLabel( 6, tr( "Fact Corp Qu" ) );
    listView_MedicaPoso->header()->setLabel( 7, tr( "Fact Corp Unit" ) );
    listView_MedicaPoso->header()->setLabel( 8, trUtf8( "\x50\xc3\xa9\x72\x69\x6f\x64\x65" ) );
    listView_MedicaPoso->header()->setLabel( 9, tr( "Coeff" ) );
    listView_MedicaPoso->header()->setLabel( 10, tr( "Coeff Unit" ) );
    groupBox5_3->setProperty( "title", tr( "Conditions d'application" ) );
    pushButtonAdvancedTerrain->setProperty( "text", trUtf8( "\x26\x54\x65\x72\x72\x61\x69\x6e\x20\x28\x61\x76\x61\x6e\x63\xc3\xa9\x29" ) );
    pushButtonAdvancedTerrain->setProperty( "accel", QKeySequence( tr( "Alt+T" ) ) );
    QToolTip::add( lineEdit_Terrain, trUtf8( "\x44\xc3\xa9\x66\x69\x6e\x69\x74\x69\x6f\x6e\x20\x73\x74\x72\x75\x63\x74\x75\x72\xc3"
    "\xa9\x65\x20\x64\x65\x73\x20\x73\x70\xc3\xa9\x63\x69\x66\x69\x63\x61\x74\x69\x6f"
    "\x6e\x73\x20\x64\x65\x20\x74\x65\x72\x72\x61\x69\x6e" ) );
    textLabel2_4_2_2_3->setProperty( "text", tr( "Se&xe " ) );
    comboBox_Sexe->clear();
    comboBox_Sexe->insertItem( trUtf8( "\x46\xc3\xa9\x6d\x69\x6e\x69\x6e" ) );
    comboBox_Sexe->insertItem( tr( "Masculin" ) );
    comboBox_Sexe->insertItem( trUtf8( "\x49\x6e\x64\x69\x66\x66\xc3\xa9\x72\x65\x6e\x74" ) );
    comboBox_Sexe->setProperty( "currentItem", 2 );
    textLabel2_4_4->setProperty( "text", trUtf8( "\xc3\x82\x67\x65\x20\x64\x65\x20\x28\x65\x6e\x20\x6d\x6f\x69\x73\x29\x20" ) );
    lineEdit_AgeMin->setProperty( "control", tr( "GGGGGGGGGG" ) );
    lineEdit_AgeMin->setProperty( "mask", tr( "__________" ) );
    lineEdit_AgeMin->setProperty( "text", QString::null );
    textLabel2_4_2_4->setProperty( "text", trUtf8( "\x20\xc3\xa0\x20" ) );
    lineEdit_AgeMax->setProperty( "control", tr( "GGGGGGGGGG" ) );
    lineEdit_AgeMax->setProperty( "mask", tr( "__________" ) );
    lineEdit_AgeMax->setProperty( "text", QString::null );
    textLabel2_5->setProperty( "text", tr( " Poids de " ) );
    lineEdit_EdPo_PoidsMin->setProperty( "control", tr( "GGGGGGGGGG" ) );
    lineEdit_EdPo_PoidsMin->setProperty( "mask", tr( "__________" ) );
    lineEdit_EdPo_PoidsMin->setProperty( "text", QString::null );
    textLabel3_2->setProperty( "text", trUtf8( "\x20\xc3\xa0\x20" ) );
    lineEdit_EdPo_PoidsMax->setProperty( "control", tr( "GGGGGGGGGG" ) );
    lineEdit_EdPo_PoidsMax->setProperty( "mask", tr( "__________" ) );
    lineEdit_EdPo_PoidsMax->setProperty( "text", QString::null );
    textLabel2_4_2_2_2_3->setProperty( "text", trUtf8( "\x49\x6e\x74\x69\x74\x75\x6c\xc3\xa9\x20\x64\x65\x20\x63\x65\x74\x74\x65\x20\x70\x6f"
    "\x73\x6f\x6c\x6f\x67\x69\x65\x20\x20\x2e" ) );
    groupBox_UP->setProperty( "title", trUtf8( "\x51\x75\x61\x6e\x74\x69\x74\xc3\xa9\x20\x64\x27\x75\x6e\x69\x74\xc3\xa9\x73\x20\x64"
    "\x65\x20\x70\x72\x69\x73\x65" ) );
    QToolTip::add( slider_VarPoso, tr( "Permet de tester avec les valeurs entre le minimum et le maximum" ) );
    textLabel2->setProperty( "text", tr( " par " ) );
    lineEditFactCorpQU->setProperty( "control", tr( "GGGGGGGGGG" ) );
    lineEditFactCorpQU->setProperty( "mask", tr( "__________" ) );
    lineEditFactCorpQU->setProperty( "text", QString::null );
    comboBoxFactCorpUnit->clear();
    comboBoxFactCorpUnit->insertItem( tr( "Kg de poids" ) );
    comboBoxFactCorpUnit->insertItem( tr( "m2 de surface corporelle" ) );
    comboBoxFactCorpUnit->insertItem( tr( "Pas de facteur corporel" ) );
    textLabel5->setProperty( "text", trUtf8( "\x3c\x75\x3e\x45\x78\x65\x6d\x70\x6c\x65\x3a\x3c\x2f\x75\x3e\x20\x20\x20\x3c\x62\x3e"
    "\x35\x30\x30\x20\x6d\x67\x20\x70\x61\x72\x20\x63\x6f\x6d\x70\x72\x69\x6d\xc3\xa9"
    "\x3c\x2f\x62\x3e\x20\x20\x65\x74\x20\x66\x61\x63\x74\x65\x75\x72\x20\x63\x6f\x72"
    "\x70\x6f\x72\x65\x6c\x20\x3d\x20\x3c\x62\x3e\x4b\x67\x20\x64\x65\x20\x70\x6f\x69"
    "\x64\x73\x3c\x2f\x62\x3e\x20\x20\x3c\x62\x72\x3e\x20\x20\x75\x6e\x69\x74\xc3\xa9"
    "\x20\x64\x65\x20\x55\x50\x31\x20\x3d\x20\x20\x3c\x62\x3e\x6d\x67\x3c\x2f\x62\x3e"
    "\x20\x20\x61\x76\x65\x63\x20\x20\x75\x6e\x69\x74\xc3\xa9\x20\x64\x65\x20\x55\x50"
    "\x32\x20\x3d\x20\x3c\x62\x3e\x63\x6f\x6d\x70\x72\x69\x6d\xc3\xa9\x3c\x2f\x62\x3e"
    "" ) );
    lineEditQUP1byUP2->setProperty( "control", tr( "GGGGGGGGGG" ) );
    lineEditQUP1byUP2->setProperty( "mask", tr( "__________" ) );
    lineEditQUP1byUP2->setProperty( "text", QString::null );
    QToolTip::add( lineEditQUP1byUP2, trUtf8( "\x51\x75\x61\x6e\x74\x69\x74\xc3\xa9\x20\x64\x65\x20\x6c\x27\x75\x6e\x69\x74\xc3\xa9"
    "\x20\x64\x65\x20\x70\x72\x69\x73\x65\x20\x31\x20\x28\x63\x69\x2d\x64\x65\x73\x73"
    "\x75\x73\x20\x6c\x69\x67\x6e\x65\x20\x3a\x20\x55\x50\x31\x20\x29\x20\x63\x6f\x6e"
    "\x74\x65\x6e\x75\x65\x20\x64\x61\x6e\x73\x20\x6c\x61\x20\x66\x6f\x72\x6d\x65\x20"
    "\x75\x73\x75\x65\x6c\x6c\x65\x20\x6f\x75\x20\x67\x61\x6c\xc3\xa9\x6e\x69\x71\x75"
    "\x65\x20\x64\x27\x75\x6e\x69\x74\xc3\xa9\x20\x64\x65\x20\x70\x72\x69\x73\x65\x20"
    "\x28\x20\x6c\x69\x67\x6e\x65\x20\x3a\x20\x55\x50\x32\x20\x29" ) );
    textLabelCoeffResult->setProperty( "text", trUtf8( "\x51\x75\x61\x6e\x74\x69\x74\xc3\xa9\x20\x64\x27\x75\x6e\x69\x74\xc3\xa9\x73\x20\x55"
    "\x50\x31\x20\x64\x61\x6e\x73\x20\x6c\x27\x75\x6e\x69\x74\xc3\xa9\x20\x55\x50\x32"
    "" ) );
    lineEdit_TailleTest->setProperty( "control", tr( "GGGGGGGGGG" ) );
    lineEdit_TailleTest->setProperty( "mask", tr( "__________" ) );
    lineEdit_TailleTest->setProperty( "text", QString::null );
    QToolTip::add( lineEdit_TailleTest, trUtf8( "\x49\x6e\x64\x69\x71\x75\x65\x7a\x20\x6c\x61\x20\x74\x61\x69\x6c\x6c\x65\x20\x64\x6f"
    "\x6e\x74\x20\x64\x6f\x69\x74\x20\x74\x65\x6e\x69\x72\x20\x63\x6f\x6d\x70\x74\x65"
    "\x20\x6c\x61\x20\x70\x6f\x73\x6f\x6c\x6f\x67\x69\x65\x20\x61\x66\x66\x69\x63\x68"
    "\xc3\xa9\x65\x20\xc3\xa0\x20\x64\x72\x6f\x69\x74\x65\x20\x63\x69\x2d\x63\x6f\x6e"
    "\x74\x72\x65\x28\x65\x6e\x20\x7a\x6f\x6e\x65\x20\x62\x6c\x65\x75\x20\x63\x6c\x61"
    "\x69\x72\x29" ) );
    lineEdit_PoidsTest->setProperty( "control", tr( "GGGGGGGGGG" ) );
    lineEdit_PoidsTest->setProperty( "mask", tr( "__________" ) );
    lineEdit_PoidsTest->setProperty( "text", QString::null );
    QToolTip::add( lineEdit_PoidsTest, trUtf8( "\x49\x6e\x64\x69\x71\x75\x65\x7a\x20\x6c\x65\x20\x70\x6f\x69\x64\x73\x20\x64\x6f\x6e"
    "\x74\x20\x64\x6f\x69\x74\x20\x74\x65\x6e\x69\x72\x20\x63\x6f\x6d\x70\x74\x65\x20"
    "\x6c\x61\x20\x70\x6f\x73\x6f\x6c\x6f\x67\x69\x65\x20\x61\x66\x66\x69\x63\x68\xc3"
    "\xa9\x65\x20\xc3\xa0\x20\x64\x72\x6f\x69\x74\x65\x20\x63\x69\x2d\x63\x6f\x6e\x74"
    "\x72\x65\x20\x20\x28\x65\x6e\x20\x7a\x6f\x6e\x65\x20\x62\x6c\x65\x75\x20\x63\x6c"
    "\x61\x69\x72\x29" ) );
    QToolTip::add( textBrowser_Result, trUtf8( "\x56\x75\x65\x20\x70\x72\xc3\xa9\x73\x65\x6e\x74\x61\x6e\x74\x20\x6c\x65\x20\x72\xc3"
    "\xa9\x73\x75\x6c\x74\x61\x74\x20\x64\x65\x73\x20\x64\x6f\x6e\x6e\xc3\xa9\x65\x73"
    "" ) );
    textLabel2_2->setProperty( "text", tr( "Poids de test " ) );
    textLabel1->setProperty( "text", tr( "Taille de test " ) );
    lineEdit_a_UP2_2->setProperty( "text", tr( "UP 2" ) );
    QToolTip::add( lineEdit_QMin_UP2, trUtf8( "\x51\x75\x61\x6e\x74\x69\x74\xc3\xa9\x20\x4d\x69\x6e\x69\x6d\x75\x6d\x20\x64\x27\x75"
    "\x6e\x69\x74\xc3\xa9\x73\x20\x64\x65\x20\x70\x72\x69\x73\x65\x2c\x20\x73\x6f\x75"
    "\x73\x20\x66\x6f\x72\x6d\x65\x20\x75\x74\x69\x6c\x65\x20\x28\x63\x6f\x6d\x70\x72"
    "\x69\x6d\xc3\xa9\x73\x2c\x20\x67\xc3\xa9\x6c\x75\x6c\x65\x73\x20\x65\x74\x63\x2e"
    "\x29" ) );
    lineEdit_a_UP2->setProperty( "text", trUtf8( "\xc3\xa0" ) );
    QToolTip::add( lineEdit_QMax_UP2, trUtf8( "\x51\x75\x61\x6e\x74\x69\x74\xc3\xa9\x20\x4d\x61\x78\x69\x6d\x75\x6d\x20\x64\x27\x75"
    "\x6e\x69\x74\xc3\xa9\x73\x20\x64\x65\x20\x70\x72\x69\x73\x65\x2c\x20\x73\x6f\x75"
    "\x73\x20\x66\x6f\x72\x6d\x65\x20\x75\x74\x69\x6c\x65\x20\x28\x63\x6f\x6d\x70\x72"
    "\x69\x6d\xc3\xa9\x73\x2c\x20\x67\xc3\xa9\x6c\x75\x6c\x65\x73\x20\x65\x74\x63\x2e"
    "\x29" ) );
    QToolTip::add( comboBoxUP_2, trUtf8( "\x55\x6e\x69\x74\xc3\xa9\x20\x64\x61\x6e\x73\x20\x6c\x61\x71\x75\x65\x6c\x6c\x65\x20"
    "\x73\x27\x65\x78\x70\x72\x69\x6d\x65\x20\x6c\x27\x75\x6e\x69\x74\xc3\xa9\x20\x64"
    "\x65\x20\x70\x72\x69\x73\x65" ) );
    pushButtonNewUP2_Unit->setProperty( "text", QString::null );
    QToolTip::add( pushButtonNewUP2_Unit, trUtf8( "\x41\x6a\x6f\x75\x74\x65\x72\x20\x65\x74\x20\x64\xc3\xa9\x66\x69\x6e\x69\x72\x20\x75"
    "\x6e\x65\x20\x6e\x6f\x75\x76\x65\x6c\x6c\x65\x20\x75\x6e\x69\x74\xc3\xa9" ) );
    textLabel3->setProperty( "text", trUtf8( "\x45\x78\x70\x72\x69\x6d\xc3\xa9\x65\x20\x70\x6f\x75\x72\x20\x75\x6e\x65\x20\x64\x75"
    "\x72\xc3\xa9\x65\x20\x64\x65\x20\x3a" ) );
    lineEdit_Periode->setProperty( "control", tr( "GGGGGGGGGG" ) );
    lineEdit_Periode->setProperty( "mask", tr( "__________" ) );
    lineEdit_Periode->setProperty( "text", QString::null );
    QToolTip::add( lineEdit_Periode, trUtf8( "\x50\xc3\xa9\x72\x69\x6f\x64\x65\x20\x70\x6f\x75\x72\x20\x6c\x61\x71\x75\x65\x6c\x6c"
    "\x65\x20\x65\x73\x74\x20\x64\xc3\xa9\x66\x69\x6e\x69\x65\x20\x6c\x61\x20\x70\x6f"
    "\x73\x6f\x6c\x6f\x67\x69\x65\x20\x28\x68\x61\x62\x69\x74\x75\x65\x6c\x6c\x65\x6d"
    "\x65\x6e\x74\x20\x31\x20\x6a\x6f\x75\x72\x29" ) );
    textLabel4->setProperty( "text", tr( "secondes (1 jour = 86400 secondes)" ) );
    comboBoxPeriode->clear();
    comboBoxPeriode->insertItem( tr( "1 jour" ) );
    comboBoxPeriode->insertItem( tr( "2 jours" ) );
    comboBoxPeriode->insertItem( tr( "3 jours" ) );
    comboBoxPeriode->insertItem( tr( "4 jours" ) );
    comboBoxPeriode->insertItem( tr( "5 jours" ) );
    comboBoxPeriode->insertItem( tr( "6 jours" ) );
    comboBoxPeriode->insertItem( tr( "7 jours" ) );
    comboBoxPeriode->insertItem( tr( "8 jours" ) );
    comboBoxPeriode->insertItem( tr( "9 jours" ) );
    comboBoxPeriode->insertItem( tr( "10 jours" ) );
    comboBoxPeriode->insertItem( tr( "11 jours" ) );
    comboBoxPeriode->insertItem( tr( "12 jours" ) );
    comboBoxPeriode->insertItem( tr( "13 jours" ) );
    comboBoxPeriode->insertItem( tr( "14 jours" ) );
    comboBoxPeriode->insertItem( tr( "15 jours" ) );
    comboBoxPeriode->insertItem( tr( "16 jours" ) );
    comboBoxPeriode->insertItem( tr( "17 jours" ) );
    comboBoxPeriode->insertItem( tr( "18 jours" ) );
    comboBoxPeriode->insertItem( tr( "19 jours" ) );
    comboBoxPeriode->insertItem( tr( "20 jours" ) );
    comboBoxPeriode->insertItem( tr( "21 jours" ) );
    comboBoxPeriode->insertItem( tr( "22 jours" ) );
    comboBoxPeriode->insertItem( tr( "23 jours" ) );
    comboBoxPeriode->insertItem( tr( "24 jours" ) );
    comboBoxPeriode->insertItem( tr( "25 jours" ) );
    comboBoxPeriode->insertItem( tr( "26 jours" ) );
    comboBoxPeriode->insertItem( tr( "27 jours" ) );
    comboBoxPeriode->insertItem( tr( "28 jours" ) );
    comboBoxPeriode->insertItem( tr( "29 jours" ) );
    comboBoxPeriode->insertItem( tr( "30 jours" ) );
    comboBoxPeriode->insertItem( tr( "31 jours" ) );
    comboBoxPeriode->insertItem( tr( "1 mois" ) );
    comboBoxPeriode->insertItem( tr( "2 mois" ) );
    comboBoxPeriode->insertItem( tr( "3 mois" ) );
    comboBoxPeriode->insertItem( tr( "4 mois" ) );
    comboBoxPeriode->insertItem( tr( "5 mois" ) );
    QToolTip::add( comboBoxPeriode, trUtf8( "\x4c\x69\x73\x74\x65\x20\x64\x65\x20\x76\x61\x6c\x65\x75\x72\x73\x20\x70\x6f\x73\x73"
    "\x69\x62\x6c\x65\x73\x20\x70\x6f\x75\x72\x20\x6c\x61\x20\x70\xc3\xa9\x72\x69\x6f"
    "\x64\x65\x20\x63\x69\x2d\x63\x6f\x6e\x74\x72\x65\x20\xc3\xa0\x20\x67\x61\x75\x63"
    "\x68\x65" ) );
    textLabel4_2->setProperty( "text", tr( " Maximum possible pour <font color=\"#0000ff\"><b>UP1</b></font>" ) );
    lineEdit_UP1_Max->setProperty( "control", tr( "GGGGGGGGGG" ) );
    lineEdit_UP1_Max->setProperty( "mask", tr( "__________" ) );
    lineEdit_UP1_Max->setProperty( "text", QString::null );
    QToolTip::add( lineEdit_UP1_Max, trUtf8( "\x50\xc3\xa9\x72\x69\x6f\x64\x65\x20\x70\x6f\x75\x72\x20\x6c\x61\x71\x75\x65\x6c\x6c"
    "\x65\x20\x65\x73\x74\x20\x64\xc3\xa9\x66\x69\x6e\x69\x65\x20\x6c\x61\x20\x70\x6f"
    "\x73\x6f\x6c\x6f\x67\x69\x65\x20\x28\x68\x61\x62\x69\x74\x75\x65\x6c\x6c\x65\x6d"
    "\x65\x6e\x74\x20\x31\x20\x6a\x6f\x75\x72\x29" ) );
    lineEdit_a_UP2_2_2->setProperty( "text", tr( "UP 1" ) );
    lineEdit_QMin_UP1->setProperty( "control", tr( "GGGGGGGGGG" ) );
    lineEdit_QMin_UP1->setProperty( "mask", tr( "__________" ) );
    lineEdit_QMin_UP1->setProperty( "text", QString::null );
    QToolTip::add( lineEdit_QMin_UP1, trUtf8( "\x51\x75\x61\x6e\x74\x69\x74\xc3\xa9\x20\x6d\x69\x6e\x69\x6d\x75\x6d\x20\x64\x27\x75"
    "\x6e\x69\x74\xc3\xa9\x73\x20\x64\x65\x20\x70\x72\x69\x73\x65\x20\x70\x6f\x75\x72"
    "\x20\x6c\x61\x20\x70\xc3\xa9\x72\x69\x6f\x64\x65\x20\x64\xc3\xa9\x66\x69\x6e\x69"
    "\x65\x20\x63\x69\x2d\x64\x65\x73\x73\x75\x73" ) );
    pushButton_A->setProperty( "text", trUtf8( "\xc3\xa0" ) );
    lineEdit_QMax_UP1->setProperty( "control", tr( "GGGGGGGGGG" ) );
    lineEdit_QMax_UP1->setProperty( "mask", tr( "__________" ) );
    lineEdit_QMax_UP1->setProperty( "text", QString::null );
    QToolTip::add( lineEdit_QMax_UP1, trUtf8( "\x51\x75\x61\x6e\x74\x69\x74\xc3\xa9\x20\x6d\x61\x78\x69\x6d\x75\x6d\x20\x64\x27\x75"
    "\x6e\x69\x74\xc3\xa9\x73\x20\x64\x65\x20\x70\x72\x69\x73\x65\x20\x70\x6f\x75\x72"
    "\x20\x6c\x61\x20\x70\xc3\xa9\x72\x69\x6f\x64\x65\x20\x64\xc3\xa9\x66\x69\x6e\x69"
    "\x65\x20\x63\x69\x2d\x64\x65\x73\x73\x75\x73" ) );
    QToolTip::add( comboBoxUP_1, trUtf8( "\x55\x6e\x69\x74\xc3\xa9\x20\x64\x61\x6e\x73\x20\x6c\x61\x71\x75\x65\x6c\x6c\x65\x20"
    "\x73\x27\x65\x78\x70\x72\x69\x6d\x65\x20\x6c\x27\x75\x6e\x69\x74\xc3\xa9\x20\x64"
    "\x65\x20\x70\x72\x69\x73\x65" ) );
    pushButtonNewUP1_Unit->setProperty( "text", QString::null );
    QToolTip::add( pushButtonNewUP1_Unit, trUtf8( "\x41\x6a\x6f\x75\x74\x65\x72\x20\x65\x74\x20\x64\xc3\xa9\x66\x69\x6e\x69\x72\x20\x75"
    "\x6e\x65\x20\x6e\x6f\x75\x76\x65\x6c\x6c\x65\x20\x75\x6e\x69\x74\xc3\xa9" ) );
    groupBox16->setProperty( "title", trUtf8( "\x53\x63\x68\xc3\xa9\x6d\x61\x20\x64\x65\x20\x70\x72\x69\x73\x65" ) );
    textLabel_Moment->setProperty( "text", trUtf8( "\x52\xc3\xa9\x70\x61\x72\x74\x69\x74\x69\x6f\x6e\x20\x64\x65\x20\x6c\x61\x20\x70\x72"
    "\x69\x73\x65" ) );
    comboBoxMoment->clear();
    comboBoxMoment->insertItem( tr( "(vide)" ) );
    comboBoxMoment->insertItem( tr( "1 fois par jour" ) );
    comboBoxMoment->insertItem( tr( "1 fois par jour, le matin                                                                      " ) );
    comboBoxMoment->insertItem( trUtf8( "\x31\x20\x66\x6f\x69\x73\x20\x70\x61\x72\x20\x6a\x6f\x75\x72\x2c\x20\xc3\xa0\x20\x6d"
    "\x69\x64\x69\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20" ) );
    comboBoxMoment->insertItem( tr( "1 fois par jour, le soir                                                                         " ) );
    comboBoxMoment->insertItem( tr( "1 fois par jour, le soir au coucher                                                             " ) );
    comboBoxMoment->insertItem( trUtf8( "\x31\x20\x66\x6f\x69\x73\x20\x70\x61\x72\x20\x6a\x6f\x75\x72\x2c\x20\x61\x75\x20\x70"
    "\x65\x74\x69\x74\x20\x64\xc3\xa9\x6a\x65\x75\x6e\x65\x72\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20" ) );
    comboBoxMoment->insertItem( tr( "1 fois par jour, au cours du repas de midi                                                     " ) );
    comboBoxMoment->insertItem( trUtf8( "\x31\x20\x66\x6f\x69\x73\x20\x70\x61\x72\x20\x6a\x6f\x75\x72\x2c\x20\x61\x75\x20\x63"
    "\x6f\x75\x72\x73\x20\x64\x75\x20\x64\xc3\xae\x6e\x65\x72\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20" ) );
    comboBoxMoment->insertItem( tr( "2 fois par jour, matin et soir                                                                   " ) );
    comboBoxMoment->insertItem( tr( "2 fois par jour, matin et midi                                                                  " ) );
    comboBoxMoment->insertItem( tr( "2 fois par jour, midi et soir                                                                  " ) );
    comboBoxMoment->insertItem( tr( "2 fois par jour, le matin et au coucher" ) );
    comboBoxMoment->insertItem( tr( "2 fois par jour, matin et soir au cours des repas                                             " ) );
    comboBoxMoment->insertItem( trUtf8( "\x32\x20\x66\x6f\x69\x73\x20\x70\x61\x72\x20\x6a\x6f\x75\x72\x2c\x20\x61\x75\x20\x70"
    "\x65\x74\x69\x74\x20\x64\xc3\xa9\x6a\x65\x75\x6e\x65\x72\x20\x65\x74\x20\x61\x75"
    "\x20\x72\x65\x70\x61\x73\x20\x64\x65\x20\x6d\x69\x64\x69\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20" ) );
    comboBoxMoment->insertItem( tr( "2 fois par jour, aux repas de midi et du soir                                                  " ) );
    comboBoxMoment->insertItem( tr( "3 fois par jour, matin, midi et soir                                                          " ) );
    comboBoxMoment->insertItem( tr( "3 fois par jour, matin, midi et soir au cours des repas                                       " ) );
    comboBoxMoment->insertItem( trUtf8( "\x34\x20\x66\x6f\x69\x73\x20\x70\x61\x72\x20\x6a\x6f\x75\x72\x2c\x20\x6d\x61\x74\x69"
    "\x6e\x2c\x20\x6d\x69\x64\x69\x2c\x20\x61\x70\x72\xc3\xa8\x73\x2d\x6d\x69\x64\x69"
    "\x20\x65\x74\x20\x73\x6f\x69\x72\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20" ) );
    comboBoxMoment->insertItem( trUtf8( "\x35\x20\x66\x6f\x69\x73\x20\x70\x61\x72\x20\x6a\x6f\x75\x72\x2c\x20\x6d\x61\x74\x69"
    "\x6e\x2c\x20\x6d\x69\x64\x69\x2c\x20\x61\x70\x72\xc3\xa8\x73\x2d\x6d\x69\x64\x69"
    "\x2c\x20\x73\x6f\x69\x72\x20\x65\x74\x20\x63\x6f\x75\x63\x68\x65\x72\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20" ) );
    QToolTip::add( comboBoxMoment, trUtf8( "\x4c\x69\x73\x74\x65\x20\x64\x65\x20\x71\x75\x65\x6c\x71\x75\x65\x73\x20\x73\x63\x68"
    "\xc3\xa9\x6d\x61\x73\x20\x64\x65\x20\x70\x72\x69\x73\x65\x20\x63\x6f\x6d\x6d\x75"
    "\x6e\x73" ) );
    textLabel_Pendant->setProperty( "text", tr( "Pendant" ) );
    comboBoxPendant->clear();
    comboBoxPendant->insertItem( tr( "(vide)" ) );
    comboBoxPendant->insertItem( tr( "1 jour" ) );
    comboBoxPendant->insertItem( tr( "2 jours" ) );
    comboBoxPendant->insertItem( tr( "3 Jours" ) );
    comboBoxPendant->insertItem( tr( "4 jours" ) );
    comboBoxPendant->insertItem( tr( "5 jours" ) );
    comboBoxPendant->insertItem( tr( "6 jours" ) );
    comboBoxPendant->insertItem( tr( "7 jours" ) );
    comboBoxPendant->insertItem( tr( "8 jours" ) );
    comboBoxPendant->insertItem( tr( "10 jours" ) );
    comboBoxPendant->insertItem( tr( "12 jours" ) );
    comboBoxPendant->insertItem( tr( "15 jours" ) );
    comboBoxPendant->insertItem( tr( "21 jours" ) );
    comboBoxPendant->insertItem( tr( "28 jours" ) );
    comboBoxPendant->insertItem( tr( "31 jours" ) );
    comboBoxPendant->insertItem( tr( "62 jours" ) );
    QToolTip::add( comboBoxPendant, trUtf8( "\x44\x75\x72\xc3\xa9\x65\x20\x64\x65\x20\x70\x72\x65\x73\x63\x72\x69\x70\x74\x69\x6f"
    "\x6e" ) );
    pushButton_PosoSchemaEx->setProperty( "text", trUtf8( "\x53\x63\x68\xc3\xa9\x6d\x61\x20\x64\x65\x20\x70\x72\x69\x73\x65\x20\x28\x61\x76\x61"
    "\x6e\x63\xc3\xa9\x29\x20\x2e\x2e\x2e" ) );
    QToolTip::add( pushButton_PosoSchemaEx, trUtf8( "\x50\x65\x72\x6d\x65\x74\x20\x64\x65\x20\x64\xc3\xa9\x66\x69\x6e\x69\x72\x20\x64\x65"
    "\x73\x20\x73\x63\x68\xc3\xa9\x6d\x61\x73\x20\x64\x65\x20\x70\x72\x69\x73\x65\x20"
    "\x63\x6f\x6d\x70\x6c\x65\x78\x65\x73" ) );
    radioButtonSecable1->setProperty( "text", trUtf8( "\x4e\x6f\x6e\x20\x73\xc3\xa9\x63\x61\x62\x6c\x65" ) );
    radioButtonSecable4->setProperty( "text", trUtf8( "\x53\xc3\xa9\x63\x61\x62\x6c\x65\x20\x65\x6e\x20\x34" ) );
    QToolTip::add( lineEdit_SpecPrise, trUtf8( "\x44\xc3\xa9\x66\x69\x6e\x69\x74\x69\x6f\x6e\x20\x73\x74\x72\x75\x63\x74\x75\x72\xc3"
    "\xa9\x65\x20\x64\x65\x73\x20\x73\x63\x68\xc3\xa9\x6d\x61\x73\x20\x64\x65\x20\x70"
    "\x72\x69\x73\x65" ) );
    radioButtonSecable2->setProperty( "text", trUtf8( "\x53\xc3\xa9\x63\x61\x62\x6c\x65\x20\x65\x6e\x20\x32" ) );
    textLabel1_2->setProperty( "text", tr( "Note :" ) );
    pushButton_RecordPoso->setProperty( "text", tr( "&Enregistrer les modifications" ) );
    pushButton_RecordPoso->setProperty( "accel", QKeySequence( tr( "Alt+E" ) ) );
    pushButton_ErasePoso->setProperty( "text", tr( "E&ffacer" ) );
    pushButton_ErasePoso->setProperty( "accel", QKeySequence( tr( "Alt+F" ) ) );
    pushButton_AddPoso->setProperty( "text", tr( "&Ajouter" ) );
    pushButton_AddPoso->setProperty( "accel", QKeySequence( tr( "Alt+A" ) ) );
    pushButton_Quitter->setProperty( "text", tr( "&Quitter" ) );
    pushButton_Quitter->setProperty( "accel", QKeySequence( QString::null ) );
}

