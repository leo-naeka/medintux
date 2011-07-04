/****************************************************************************
** Form implementation generated from reading ui file 'RubIdentite.ui'
**
** Created: mer. mai 4 22:18:59 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "RubIdentite.h"

#include <qvariant.h>
#include <../../MedinTuxTools/CMaskedLineEdit.h>
#include <qpushbutton.h>
#include <qtabwidget.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qtextedit.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qheader.h>
#include <qlistview.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "../RubIdentite.ui.h"

/*
 *  Constructs a FormRubIdent as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
FormRubIdent::FormRubIdent( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setProperty( "name", "FormRubIdent" );
    setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, sizePolicy().hasHeightForWidth() ) );
    setProperty( "minimumSize", QSize( 480, 400 ) );
    FormRubIdentLayout = new QGridLayout( this, 1, 1, 0, 0, "FormRubIdentLayout"); 

    tabWidget_Ident = new QTabWidget( this, "tabWidget_Ident" );
    tabWidget_Ident->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, tabWidget_Ident->sizePolicy().hasHeightForWidth() ) );
    QFont tabWidget_Ident_font(  tabWidget_Ident->font() );
    tabWidget_Ident_font.setFamily( "Arial" );
    tabWidget_Ident->setFont( tabWidget_Ident_font ); 
    tabWidget_Ident->setProperty( "tabShape", "Triangular" );
    tabWidget_Ident->setProperty( "margin", 0 );

    tab_Administratif = new QWidget( tabWidget_Ident, "tab_Administratif" );
    tab_AdministratifLayout = new QGridLayout( tab_Administratif, 1, 1, 0, 0, "tab_AdministratifLayout"); 

    groupBox1 = new QGroupBox( tab_Administratif, "groupBox1" );
    groupBox1->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, groupBox1->sizePolicy().hasHeightForWidth() ) );
    groupBox1->setProperty( "frameShape", "GroupBoxPanel" );
    groupBox1->setProperty( "frameShadow", "Sunken" );
    groupBox1->setColumnLayout(0, Qt::Vertical );
    groupBox1->layout()->setSpacing( 1 );
    groupBox1->layout()->setMargin( 1 );
    groupBox1Layout = new QGridLayout( groupBox1->layout() );
    groupBox1Layout->setAlignment( Qt::AlignTop );

    layout32 = new QHBoxLayout( 0, 0, 6, "layout32"); 

    textLabel5 = new QLabel( groupBox1, "textLabel5" );
    QFont textLabel5_font(  textLabel5->font() );
    textLabel5->setFont( textLabel5_font ); 
    layout32->addWidget( textLabel5 );

    lineEdit_CdPostal = new CMaskedLineEdit( groupBox1, "lineEdit_CdPostal" );
    lineEdit_CdPostal->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, lineEdit_CdPostal->sizePolicy().hasHeightForWidth() ) );
    lineEdit_CdPostal->setProperty( "minimumSize", QSize( 0, 20 ) );
    lineEdit_CdPostal->setProperty( "maximumSize", QSize( 140, 32767 ) );
    QFont lineEdit_CdPostal_font(  lineEdit_CdPostal->font() );
    lineEdit_CdPostal->setFont( lineEdit_CdPostal_font ); 
    lineEdit_CdPostal->setProperty( "focusPolicy", "StrongFocus" );
    lineEdit_CdPostal->setProperty( "carMask", 32 );
    layout32->addWidget( lineEdit_CdPostal );

    textLabel6 = new QLabel( groupBox1, "textLabel6" );
    QFont textLabel6_font(  textLabel6->font() );
    textLabel6->setFont( textLabel6_font ); 
    layout32->addWidget( textLabel6 );

    lineEditVille = new CMaskedLineEdit( groupBox1, "lineEditVille" );
    lineEditVille->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, lineEditVille->sizePolicy().hasHeightForWidth() ) );
    lineEditVille->setProperty( "minimumSize", QSize( 0, 20 ) );
    QFont lineEditVille_font(  lineEditVille->font() );
    lineEditVille->setFont( lineEditVille_font ); 
    lineEditVille->setProperty( "focusPolicy", "StrongFocus" );
    lineEditVille->setProperty( "carMask", 32 );
    lineEditVille->setProperty( "mixMode", 1 );
    layout32->addWidget( lineEditVille );

    groupBox1Layout->addLayout( layout32, 4, 0 );

    layout16 = new QGridLayout( 0, 1, 1, 0, 6, "layout16"); 

    textLabel2 = new QLabel( groupBox1, "textLabel2" );
    QFont textLabel2_font(  textLabel2->font() );
    textLabel2->setFont( textLabel2_font ); 

    layout16->addWidget( textLabel2, 0, 2 );

    lineEdit_NomDossier = new CMaskedLineEdit( groupBox1, "lineEdit_NomDossier" );
    lineEdit_NomDossier->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, lineEdit_NomDossier->sizePolicy().hasHeightForWidth() ) );
    lineEdit_NomDossier->setProperty( "minimumSize", QSize( 0, 20 ) );
    QFont lineEdit_NomDossier_font(  lineEdit_NomDossier->font() );
    lineEdit_NomDossier->setFont( lineEdit_NomDossier_font ); 
    lineEdit_NomDossier->setProperty( "focusPolicy", "StrongFocus" );
    lineEdit_NomDossier->setProperty( "carMask", 32 );
    lineEdit_NomDossier->setProperty( "mixMode", 1 );

    layout16->addWidget( lineEdit_NomDossier, 0, 1 );

    lineEdit_PremomDossier = new CMaskedLineEdit( groupBox1, "lineEdit_PremomDossier" );
    lineEdit_PremomDossier->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, lineEdit_PremomDossier->sizePolicy().hasHeightForWidth() ) );
    lineEdit_PremomDossier->setProperty( "minimumSize", QSize( 0, 20 ) );
    QFont lineEdit_PremomDossier_font(  lineEdit_PremomDossier->font() );
    lineEdit_PremomDossier->setFont( lineEdit_PremomDossier_font ); 
    lineEdit_PremomDossier->setProperty( "focusPolicy", "StrongFocus" );
    lineEdit_PremomDossier->setProperty( "carMask", 32 );
    lineEdit_PremomDossier->setProperty( "mixMode", 1 );

    layout16->addWidget( lineEdit_PremomDossier, 0, 3 );

    textLabel2_2 = new QLabel( groupBox1, "textLabel2_2" );
    QFont textLabel2_2_font(  textLabel2_2->font() );
    textLabel2_2->setFont( textLabel2_2_font ); 

    layout16->addWidget( textLabel2_2, 0, 0 );

    groupBox1Layout->addLayout( layout16, 0, 0 );

    layout31 = new QHBoxLayout( 0, 0, 6, "layout31"); 

    layout30 = new QHBoxLayout( 0, 0, 6, "layout30"); 

    textLabel4 = new QLabel( groupBox1, "textLabel4" );
    QFont textLabel4_font(  textLabel4->font() );
    textLabel4->setFont( textLabel4_font ); 
    layout30->addWidget( textLabel4 );

    textEdit_Adresse = new QTextEdit( groupBox1, "textEdit_Adresse" );
    QFont textEdit_Adresse_font(  textEdit_Adresse->font() );
    textEdit_Adresse->setFont( textEdit_Adresse_font ); 
    textEdit_Adresse->setProperty( "tabChangesFocus", QVariant( TRUE, 0 ) );
    layout30->addWidget( textEdit_Adresse );
    layout31->addLayout( layout30 );

    layout29 = new QGridLayout( 0, 1, 1, 0, 2, "layout29"); 

    lineEdit_Tel3 = new CMaskedLineEdit( groupBox1, "lineEdit_Tel3" );
    lineEdit_Tel3->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, lineEdit_Tel3->sizePolicy().hasHeightForWidth() ) );
    lineEdit_Tel3->setProperty( "minimumSize", QSize( 0, 20 ) );
    lineEdit_Tel3->setProperty( "maximumSize", QSize( 32767, 32767 ) );
    QFont lineEdit_Tel3_font(  lineEdit_Tel3->font() );
    lineEdit_Tel3->setFont( lineEdit_Tel3_font ); 
    lineEdit_Tel3->setProperty( "focusPolicy", "StrongFocus" );
    lineEdit_Tel3->setProperty( "carMask", 95 );

    layout29->addWidget( lineEdit_Tel3, 2, 1 );

    lineEdit_Tel1 = new CMaskedLineEdit( groupBox1, "lineEdit_Tel1" );
    lineEdit_Tel1->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, lineEdit_Tel1->sizePolicy().hasHeightForWidth() ) );
    lineEdit_Tel1->setProperty( "minimumSize", QSize( 0, 20 ) );
    lineEdit_Tel1->setProperty( "maximumSize", QSize( 32767, 32767 ) );
    QFont lineEdit_Tel1_font(  lineEdit_Tel1->font() );
    lineEdit_Tel1->setFont( lineEdit_Tel1_font ); 
    lineEdit_Tel1->setProperty( "focusPolicy", "StrongFocus" );
    lineEdit_Tel1->setProperty( "carMask", 95 );

    layout29->addWidget( lineEdit_Tel1, 0, 1 );

    textLabel3_2_2_2 = new QLabel( groupBox1, "textLabel3_2_2_2" );
    QFont textLabel3_2_2_2_font(  textLabel3_2_2_2->font() );
    textLabel3_2_2_2->setFont( textLabel3_2_2_2_font ); 

    layout29->addWidget( textLabel3_2_2_2, 1, 0 );

    textLabel3_2_2_3 = new QLabel( groupBox1, "textLabel3_2_2_3" );
    QFont textLabel3_2_2_3_font(  textLabel3_2_2_3->font() );
    textLabel3_2_2_3->setFont( textLabel3_2_2_3_font ); 

    layout29->addWidget( textLabel3_2_2_3, 2, 0 );

    lineEdit_Tel2 = new CMaskedLineEdit( groupBox1, "lineEdit_Tel2" );
    lineEdit_Tel2->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, lineEdit_Tel2->sizePolicy().hasHeightForWidth() ) );
    lineEdit_Tel2->setProperty( "minimumSize", QSize( 0, 20 ) );
    lineEdit_Tel2->setProperty( "maximumSize", QSize( 32767, 32767 ) );
    QFont lineEdit_Tel2_font(  lineEdit_Tel2->font() );
    lineEdit_Tel2->setFont( lineEdit_Tel2_font ); 
    lineEdit_Tel2->setProperty( "focusPolicy", "StrongFocus" );
    lineEdit_Tel2->setProperty( "carMask", 95 );

    layout29->addWidget( lineEdit_Tel2, 1, 1 );

    textLabel3_2_2 = new QLabel( groupBox1, "textLabel3_2_2" );
    QFont textLabel3_2_2_font(  textLabel3_2_2->font() );
    textLabel3_2_2->setFont( textLabel3_2_2_font ); 

    layout29->addWidget( textLabel3_2_2, 0, 0 );
    layout31->addLayout( layout29 );

    groupBox1Layout->addLayout( layout31, 3, 0 );

    layout15 = new QGridLayout( 0, 1, 1, 0, 6, "layout15"); 

    lineEdit_DtNss = new CMaskedLineEdit( groupBox1, "lineEdit_DtNss" );
    lineEdit_DtNss->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, lineEdit_DtNss->sizePolicy().hasHeightForWidth() ) );
    lineEdit_DtNss->setProperty( "minimumSize", QSize( 100, 20 ) );
    lineEdit_DtNss->setProperty( "maximumSize", QSize( 32767, 32767 ) );
    QFont lineEdit_DtNss_font(  lineEdit_DtNss->font() );
    lineEdit_DtNss->setFont( lineEdit_DtNss_font ); 
    lineEdit_DtNss->setProperty( "focusPolicy", "StrongFocus" );
    lineEdit_DtNss->setProperty( "carMask", 95 );

    layout15->addWidget( lineEdit_DtNss, 0, 1 );

    lineEdit_RangGeme = new CMaskedLineEdit( groupBox1, "lineEdit_RangGeme" );
    lineEdit_RangGeme->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, lineEdit_RangGeme->sizePolicy().hasHeightForWidth() ) );
    lineEdit_RangGeme->setProperty( "minimumSize", QSize( 30, 20 ) );
    lineEdit_RangGeme->setProperty( "maximumSize", QSize( 30, 32767 ) );
    QFont lineEdit_RangGeme_font(  lineEdit_RangGeme->font() );
    lineEdit_RangGeme->setFont( lineEdit_RangGeme_font ); 
    lineEdit_RangGeme->setProperty( "focusPolicy", "StrongFocus" );
    lineEdit_RangGeme->setProperty( "carMask", 95 );

    layout15->addWidget( lineEdit_RangGeme, 0, 3 );

    textLabel3_3_2_2 = new QLabel( groupBox1, "textLabel3_3_2_2" );

    layout15->addWidget( textLabel3_3_2_2, 0, 2 );

    textLabel3_3 = new QLabel( groupBox1, "textLabel3_3" );
    QFont textLabel3_3_font(  textLabel3_3->font() );
    textLabel3_3->setFont( textLabel3_3_font ); 

    layout15->addWidget( textLabel3_3, 0, 6 );

    textLabel3 = new QLabel( groupBox1, "textLabel3" );
    QFont textLabel3_font(  textLabel3->font() );
    textLabel3->setFont( textLabel3_font ); 

    layout15->addWidget( textLabel3, 0, 0 );

    comboBoxSexe = new QComboBox( FALSE, groupBox1, "comboBoxSexe" );
    comboBoxSexe->setProperty( "editable", QVariant( TRUE, 0 ) );
    comboBoxSexe->setProperty( "autoCompletion", QVariant( TRUE, 0 ) );

    layout15->addWidget( comboBoxSexe, 0, 5 );

    textLabel1_2 = new QLabel( groupBox1, "textLabel1_2" );
    QFont textLabel1_2_font(  textLabel1_2->font() );
    textLabel1_2->setFont( textLabel1_2_font ); 

    layout15->addWidget( textLabel1_2, 0, 4 );

    lineEdit_Profession = new CMaskedLineEdit( groupBox1, "lineEdit_Profession" );
    lineEdit_Profession->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, lineEdit_Profession->sizePolicy().hasHeightForWidth() ) );
    lineEdit_Profession->setProperty( "minimumSize", QSize( 150, 20 ) );
    QFont lineEdit_Profession_font(  lineEdit_Profession->font() );
    lineEdit_Profession->setFont( lineEdit_Profession_font ); 
    lineEdit_Profession->setProperty( "focusPolicy", "StrongFocus" );
    lineEdit_Profession->setProperty( "carMask", 32 );
    lineEdit_Profession->setProperty( "mixMode", 1 );

    layout15->addWidget( lineEdit_Profession, 0, 7 );

    groupBox1Layout->addLayout( layout15, 2, 0 );

    layout15_2 = new QHBoxLayout( 0, 0, 6, "layout15_2"); 

    textLabel2_2_2 = new QLabel( groupBox1, "textLabel2_2_2" );
    QFont textLabel2_2_2_font(  textLabel2_2_2->font() );
    textLabel2_2_2->setFont( textLabel2_2_2_font ); 
    layout15_2->addWidget( textLabel2_2_2 );

    lineEdit_NomDeNss = new CMaskedLineEdit( groupBox1, "lineEdit_NomDeNss" );
    lineEdit_NomDeNss->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, lineEdit_NomDeNss->sizePolicy().hasHeightForWidth() ) );
    lineEdit_NomDeNss->setProperty( "minimumSize", QSize( 150, 20 ) );
    QFont lineEdit_NomDeNss_font(  lineEdit_NomDeNss->font() );
    lineEdit_NomDeNss->setFont( lineEdit_NomDeNss_font ); 
    lineEdit_NomDeNss->setProperty( "focusPolicy", "StrongFocus" );
    lineEdit_NomDeNss->setProperty( "carMask", 32 );
    lineEdit_NomDeNss->setProperty( "mixMode", 1 );
    layout15_2->addWidget( lineEdit_NomDeNss );

    textLabel2_2_2_2 = new QLabel( groupBox1, "textLabel2_2_2_2" );
    QFont textLabel2_2_2_2_font(  textLabel2_2_2_2->font() );
    textLabel2_2_2_2->setFont( textLabel2_2_2_2_font ); 
    layout15_2->addWidget( textLabel2_2_2_2 );

    lineEdit_Titre = new CMaskedLineEdit( groupBox1, "lineEdit_Titre" );
    lineEdit_Titre->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, lineEdit_Titre->sizePolicy().hasHeightForWidth() ) );
    lineEdit_Titre->setProperty( "minimumSize", QSize( 80, 20 ) );
    QFont lineEdit_Titre_font(  lineEdit_Titre->font() );
    lineEdit_Titre->setFont( lineEdit_Titre_font ); 
    lineEdit_Titre->setProperty( "focusPolicy", "StrongFocus" );
    lineEdit_Titre->setProperty( "carMask", 32 );
    lineEdit_Titre->setProperty( "mixMode", 1 );
    layout15_2->addWidget( lineEdit_Titre );

    groupBox1Layout->addLayout( layout15_2, 1, 0 );

    layout19 = new QGridLayout( 0, 1, 1, 0, 6, "layout19"); 

    lineEdit_Email = new QLineEdit( groupBox1, "lineEdit_Email" );
    QFont lineEdit_Email_font(  lineEdit_Email->font() );
    lineEdit_Email->setFont( lineEdit_Email_font ); 
    lineEdit_Email->setProperty( "frameShape", "LineEditPanel" );
    lineEdit_Email->setProperty( "frameShadow", "Sunken" );

    layout19->addWidget( lineEdit_Email, 0, 1 );

    textLabel_NumDoss = new QLineEdit( groupBox1, "textLabel_NumDoss" );
    QFont textLabel_NumDoss_font(  textLabel_NumDoss->font() );
    textLabel_NumDoss->setFont( textLabel_NumDoss_font ); 
    textLabel_NumDoss->setProperty( "frameShape", "Box" );
    textLabel_NumDoss->setProperty( "frameShadow", "Plain" );
    textLabel_NumDoss->setProperty( "lineWidth", 1 );
    textLabel_NumDoss->setProperty( "readOnly", QVariant( TRUE, 0 ) );

    layout19->addWidget( textLabel_NumDoss, 0, 3 );

    textLabelNumeroDoss = new QLabel( groupBox1, "textLabelNumeroDoss" );
    QFont textLabelNumeroDoss_font(  textLabelNumeroDoss->font() );
    textLabelNumeroDoss->setFont( textLabelNumeroDoss_font ); 

    layout19->addWidget( textLabelNumeroDoss, 0, 2 );

    textLabel10 = new QLabel( groupBox1, "textLabel10" );
    QFont textLabel10_font(  textLabel10->font() );
    textLabel10->setFont( textLabel10_font ); 

    layout19->addWidget( textLabel10, 0, 0 );

    groupBox1Layout->addLayout( layout19, 5, 0 );

    tab_AdministratifLayout->addWidget( groupBox1, 0, 0 );

    groupBox2 = new QGroupBox( tab_Administratif, "groupBox2" );
    groupBox2->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, groupBox2->sizePolicy().hasHeightForWidth() ) );
    QFont groupBox2_font(  groupBox2->font() );
    groupBox2->setFont( groupBox2_font ); 
    groupBox2->setProperty( "frameShape", "GroupBoxPanel" );
    groupBox2->setProperty( "frameShadow", "Sunken" );
    groupBox2->setColumnLayout(0, Qt::Vertical );
    groupBox2->layout()->setSpacing( 2 );
    groupBox2->layout()->setMargin( 4 );
    groupBox2Layout = new QGridLayout( groupBox2->layout() );
    groupBox2Layout->setAlignment( Qt::AlignTop );

    layout35 = new QHBoxLayout( 0, 0, 6, "layout35"); 

    textLabel9 = new QLabel( groupBox2, "textLabel9" );
    QFont textLabel9_font(  textLabel9->font() );
    textLabel9->setFont( textLabel9_font ); 
    layout35->addWidget( textLabel9 );

    lineEdit_PrenomAssure = new CMaskedLineEdit( groupBox2, "lineEdit_PrenomAssure" );
    lineEdit_PrenomAssure->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, lineEdit_PrenomAssure->sizePolicy().hasHeightForWidth() ) );
    lineEdit_PrenomAssure->setProperty( "minimumSize", QSize( 0, 20 ) );
    QFont lineEdit_PrenomAssure_font(  lineEdit_PrenomAssure->font() );
    lineEdit_PrenomAssure->setFont( lineEdit_PrenomAssure_font ); 
    lineEdit_PrenomAssure->setProperty( "focusPolicy", "StrongFocus" );
    lineEdit_PrenomAssure->setProperty( "carMask", 32 );
    lineEdit_PrenomAssure->setProperty( "mixMode", 1 );
    layout35->addWidget( lineEdit_PrenomAssure );

    groupBox2Layout->addLayout( layout35, 1, 1 );

    layout18 = new QGridLayout( 0, 1, 1, 0, 6, "layout18"); 

    lineEdit_DtNss_Assure = new CMaskedLineEdit( groupBox2, "lineEdit_DtNss_Assure" );
    lineEdit_DtNss_Assure->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, lineEdit_DtNss_Assure->sizePolicy().hasHeightForWidth() ) );
    lineEdit_DtNss_Assure->setProperty( "minimumSize", QSize( 100, 20 ) );
    lineEdit_DtNss_Assure->setProperty( "maximumSize", QSize( 32767, 32767 ) );
    QFont lineEdit_DtNss_Assure_font(  lineEdit_DtNss_Assure->font() );
    lineEdit_DtNss_Assure->setFont( lineEdit_DtNss_Assure_font ); 
    lineEdit_DtNss_Assure->setProperty( "focusPolicy", "StrongFocus" );
    lineEdit_DtNss_Assure->setProperty( "carMask", 95 );

    layout18->addWidget( lineEdit_DtNss_Assure, 0, 1 );

    lineEdit_NssClef_2 = new QLabel( groupBox2, "lineEdit_NssClef_2" );
    lineEdit_NssClef_2->setProperty( "minimumSize", QSize( 45, 20 ) );
    QFont lineEdit_NssClef_2_font(  lineEdit_NssClef_2->font() );
    lineEdit_NssClef_2->setFont( lineEdit_NssClef_2_font ); 
    lineEdit_NssClef_2->setProperty( "frameShape", "LineEditPanel" );

    layout18->addWidget( lineEdit_NssClef_2, 0, 0 );

    groupBox2Layout->addLayout( layout18, 1, 2 );

    layout17 = new QGridLayout( 0, 1, 1, 0, 6, "layout17"); 

    textLabel8 = new QLabel( groupBox2, "textLabel8" );
    QFont textLabel8_font(  textLabel8->font() );
    textLabel8->setFont( textLabel8_font ); 

    layout17->addWidget( textLabel8, 0, 0 );

    lineEdit_NomAssure = new CMaskedLineEdit( groupBox2, "lineEdit_NomAssure" );
    lineEdit_NomAssure->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, lineEdit_NomAssure->sizePolicy().hasHeightForWidth() ) );
    lineEdit_NomAssure->setProperty( "minimumSize", QSize( 0, 20 ) );
    QFont lineEdit_NomAssure_font(  lineEdit_NomAssure->font() );
    lineEdit_NomAssure->setFont( lineEdit_NomAssure_font ); 
    lineEdit_NomAssure->setProperty( "focusPolicy", "StrongFocus" );
    lineEdit_NomAssure->setProperty( "carMask", 32 );
    lineEdit_NomAssure->setProperty( "mixMode", 1 );

    layout17->addWidget( lineEdit_NomAssure, 0, 1 );

    groupBox2Layout->addLayout( layout17, 1, 0 );

    layout21 = new QGridLayout( 0, 1, 1, 0, 6, "layout21"); 

    textLabelNumeroDoss_2 = new QLabel( groupBox2, "textLabelNumeroDoss_2" );
    QFont textLabelNumeroDoss_2_font(  textLabelNumeroDoss_2->font() );
    textLabelNumeroDoss_2->setFont( textLabelNumeroDoss_2_font ); 
    textLabelNumeroDoss_2->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignCenter ) );

    layout21->addWidget( textLabelNumeroDoss_2, 0, 0 );

    comboBoxQualiteAyantDroit = new QComboBox( FALSE, groupBox2, "comboBoxQualiteAyantDroit" );
    comboBoxQualiteAyantDroit->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, comboBoxQualiteAyantDroit->sizePolicy().hasHeightForWidth() ) );
    comboBoxQualiteAyantDroit->setProperty( "editable", QVariant( FALSE, 0 ) );
    comboBoxQualiteAyantDroit->setProperty( "autoCompletion", QVariant( TRUE, 0 ) );

    layout21->addWidget( comboBoxQualiteAyantDroit, 1, 0 );

    groupBox2Layout->addMultiCellLayout( layout21, 0, 0, 1, 2 );

    layout23 = new QGridLayout( 0, 1, 1, 0, 6, "layout23"); 

    layout22 = new QGridLayout( 0, 1, 1, 0, 6, "layout22"); 

    lineEdit_NssClef = new QLabel( groupBox2, "lineEdit_NssClef" );
    lineEdit_NssClef->setProperty( "minimumSize", QSize( 45, 20 ) );
    QFont lineEdit_NssClef_font(  lineEdit_NssClef->font() );
    lineEdit_NssClef->setFont( lineEdit_NssClef_font ); 
    lineEdit_NssClef->setProperty( "frameShape", "LineEditPanel" );

    layout22->addWidget( lineEdit_NssClef, 0, 1 );

    lineEdit_NumSecu = new CMaskedLineEdit( groupBox2, "lineEdit_NumSecu" );
    lineEdit_NumSecu->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, lineEdit_NumSecu->sizePolicy().hasHeightForWidth() ) );
    lineEdit_NumSecu->setProperty( "minimumSize", QSize( 250, 20 ) );
    lineEdit_NumSecu->setProperty( "maximumSize", QSize( 32767, 32767 ) );
    QFont lineEdit_NumSecu_font(  lineEdit_NumSecu->font() );
    lineEdit_NumSecu->setFont( lineEdit_NumSecu_font ); 
    lineEdit_NumSecu->setProperty( "focusPolicy", "StrongFocus" );
    lineEdit_NumSecu->setProperty( "carMask", 32 );

    layout22->addWidget( lineEdit_NumSecu, 0, 0 );

    layout23->addLayout( layout22, 1, 0 );

    textLabel7 = new QLabel( groupBox2, "textLabel7" );
    QFont textLabel7_font(  textLabel7->font() );
    textLabel7->setFont( textLabel7_font ); 
    textLabel7->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignCenter ) );

    layout23->addWidget( textLabel7, 0, 0 );

    groupBox2Layout->addLayout( layout23, 0, 0 );

    tab_AdministratifLayout->addWidget( groupBox2, 1, 0 );

    tabWidgetNotes = new QTabWidget( tab_Administratif, "tabWidgetNotes" );
    tabWidgetNotes->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)4, 0, 0, tabWidgetNotes->sizePolicy().hasHeightForWidth() ) );
    tabWidgetNotes->setProperty( "tabShape", "Triangular" );
    tabWidgetNotes->setProperty( "margin", 0 );

    tab = new QWidget( tabWidgetNotes, "tab" );
    tabLayout = new QGridLayout( tab, 1, 1, 0, 0, "tabLayout"); 

    layout16_2 = new QGridLayout( 0, 1, 1, 0, 6, "layout16_2"); 

    layout14 = new QVBoxLayout( 0, 0, 6, "layout14"); 

    pushButton_AddMedTTT = new QPushButton( tab, "pushButton_AddMedTTT" );
    pushButton_AddMedTTT->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButton_AddMedTTT->sizePolicy().hasHeightForWidth() ) );
    QFont pushButton_AddMedTTT_font(  pushButton_AddMedTTT->font() );
    pushButton_AddMedTTT->setFont( pushButton_AddMedTTT_font ); 
    layout14->addWidget( pushButton_AddMedTTT );

    pushButton_DelMedTTT = new QPushButton( tab, "pushButton_DelMedTTT" );
    QFont pushButton_DelMedTTT_font(  pushButton_DelMedTTT->font() );
    pushButton_DelMedTTT->setFont( pushButton_DelMedTTT_font ); 
    layout14->addWidget( pushButton_DelMedTTT );

    layout16_2->addLayout( layout14, 0, 0 );

    listView_Praticiens = new QListView( tab, "listView_Praticiens" );
    listView_Praticiens->addColumn( trUtf8( "\x53\x70\xc3\xa9\x63\x69\x61\x6c\x69\x74\xc3\xa9\x20\x20\x20\x20\x20\x20\x20\x20" ) );
    listView_Praticiens->addColumn( tr( "Nom         " ) );
    listView_Praticiens->addColumn( trUtf8( "\x50\x72\xc3\xa9\x6e\x6f\x6d\x20\x20\x20\x20\x20" ) );
    listView_Praticiens->addColumn( trUtf8( "\x65\x6e\x20\x71\x75\x61\x6c\x69\x74\xc3\xa9\x20\x64\x65" ) );
    listView_Praticiens->addColumn( tr( "ID" ) );
    listView_Praticiens->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)7, 0, 0, listView_Praticiens->sizePolicy().hasHeightForWidth() ) );
    QFont listView_Praticiens_font(  listView_Praticiens->font() );
    listView_Praticiens->setFont( listView_Praticiens_font ); 

    layout16_2->addWidget( listView_Praticiens, 0, 1 );

    tabLayout->addLayout( layout16_2, 0, 0 );
    tabWidgetNotes->insertTab( tab, QString::fromLatin1("") );

    tab_2 = new QWidget( tabWidgetNotes, "tab_2" );
    tabLayout_2 = new QGridLayout( tab_2, 1, 1, 0, 0, "tabLayout_2"); 

    textEdit_Note = new QTextEdit( tab_2, "textEdit_Note" );

    tabLayout_2->addWidget( textEdit_Note, 0, 0 );
    tabWidgetNotes->insertTab( tab_2, QString::fromLatin1("") );

    tab_AdministratifLayout->addWidget( tabWidgetNotes, 2, 0 );

    layout27 = new QGridLayout( 0, 1, 1, 0, 6, "layout27"); 

    pushButtonCancel = new QPushButton( tab_Administratif, "pushButtonCancel" );
    pushButtonCancel->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonCancel->sizePolicy().hasHeightForWidth() ) );
    QFont pushButtonCancel_font(  pushButtonCancel->font() );
    pushButtonCancel->setFont( pushButtonCancel_font ); 

    layout27->addWidget( pushButtonCancel, 0, 5 );

    pushButtonCreate = new QPushButton( tab_Administratif, "pushButtonCreate" );
    pushButtonCreate->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonCreate->sizePolicy().hasHeightForWidth() ) );
    QFont pushButtonCreate_font(  pushButtonCreate->font() );
    pushButtonCreate->setFont( pushButtonCreate_font ); 

    layout27->addWidget( pushButtonCreate, 0, 1 );
    spacer4 = new QSpacerItem( 25, 16, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout27->addItem( spacer4, 0, 2 );
    spacer6 = new QSpacerItem( 21, 10, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout27->addItem( spacer6, 0, 0 );
    spacer7 = new QSpacerItem( 36, 11, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout27->addItem( spacer7, 0, 6 );
    spacer5 = new QSpacerItem( 25, 16, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout27->addItem( spacer5, 0, 4 );

    pushButtonSavModif = new QPushButton( tab_Administratif, "pushButtonSavModif" );
    pushButtonSavModif->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonSavModif->sizePolicy().hasHeightForWidth() ) );
    QFont pushButtonSavModif_font(  pushButtonSavModif->font() );
    pushButtonSavModif->setFont( pushButtonSavModif_font ); 

    layout27->addWidget( pushButtonSavModif, 0, 3 );

    tab_AdministratifLayout->addLayout( layout27, 3, 0 );
    tabWidget_Ident->insertTab( tab_Administratif, QString::fromLatin1("") );

    tab_Documents = new QWidget( tabWidget_Ident, "tab_Documents" );
    tab_DocumentsLayout = new QGridLayout( tab_Documents, 1, 1, 0, 0, "tab_DocumentsLayout"); 

    layoutBarreTexte = new QGridLayout( 0, 1, 1, 0, 0, "layoutBarreTexte"); 

    pushButtonExporter = new QPushButton( tab_Documents, "pushButtonExporter" );
    pushButtonExporter->setProperty( "maximumSize", QSize( 35, 30 ) );

    layoutBarreTexte->addWidget( pushButtonExporter, 0, 9 );

    pushButtonPrint = new QPushButton( tab_Documents, "pushButtonPrint" );
    pushButtonPrint->setProperty( "maximumSize", QSize( 35, 30 ) );

    layoutBarreTexte->addWidget( pushButtonPrint, 0, 6 );

    textLabel_UserName = new QLabel( tab_Documents, "textLabel_UserName" );
    textLabel_UserName->setProperty( "minimumSize", QSize( 100, 22 ) );
    textLabel_UserName->setProperty( "maximumSize", QSize( 115, 22 ) );
    QFont textLabel_UserName_font(  textLabel_UserName->font() );
    textLabel_UserName->setFont( textLabel_UserName_font ); 
    textLabel_UserName->setProperty( "frameShape", "StyledPanel" );
    textLabel_UserName->setProperty( "frameShadow", "Sunken" );
    textLabel_UserName->setProperty( "scaledContents", QVariant( FALSE, 0 ) );
    textLabel_UserName->setProperty( "alignment", int( QLabel::AlignCenter ) );

    layoutBarreTexte->addWidget( textLabel_UserName, 0, 4 );

    comboBox_RubName = new QComboBox( FALSE, tab_Documents, "comboBox_RubName" );
    comboBox_RubName->setProperty( "minimumSize", QSize( 200, 22 ) );
    comboBox_RubName->setProperty( "maximumSize", QSize( 32767, 22 ) );
    QFont comboBox_RubName_font(  comboBox_RubName->font() );
    comboBox_RubName->setFont( comboBox_RubName_font ); 
    comboBox_RubName->setProperty( "sizeLimit", 20 );

    layoutBarreTexte->addWidget( comboBox_RubName, 0, 1 );

    textLabel1 = new QLabel( tab_Documents, "textLabel1" );
    textLabel1->setProperty( "minimumSize", QSize( 55, 22 ) );
    textLabel1->setProperty( "maximumSize", QSize( 55, 22 ) );
    QFont textLabel1_font(  textLabel1->font() );
    textLabel1->setFont( textLabel1_font ); 

    layoutBarreTexte->addWidget( textLabel1, 0, 3 );

    pushButtonRubDateChange = new QPushButton( tab_Documents, "pushButtonRubDateChange" );
    pushButtonRubDateChange->setProperty( "minimumSize", QSize( 22, 22 ) );
    pushButtonRubDateChange->setProperty( "maximumSize", QSize( 22, 22 ) );

    layoutBarreTexte->addWidget( pushButtonRubDateChange, 0, 2 );

    pushButtonAdd = new QPushButton( tab_Documents, "pushButtonAdd" );
    pushButtonAdd->setProperty( "maximumSize", QSize( 35, 30 ) );

    layoutBarreTexte->addWidget( pushButtonAdd, 0, 8 );

    pushButtonSave = new QPushButton( tab_Documents, "pushButtonSave" );
    pushButtonSave->setProperty( "maximumSize", QSize( 35, 30 ) );

    layoutBarreTexte->addWidget( pushButtonSave, 0, 5 );

    pushButtonDelete = new QPushButton( tab_Documents, "pushButtonDelete" );
    pushButtonDelete->setProperty( "maximumSize", QSize( 35, 30 ) );

    layoutBarreTexte->addWidget( pushButtonDelete, 0, 7 );

    textLabel_NbRub = new QPushButton( tab_Documents, "textLabel_NbRub" );
    textLabel_NbRub->setProperty( "minimumSize", QSize( 22, 22 ) );
    textLabel_NbRub->setProperty( "maximumSize", QSize( 22, 22 ) );

    layoutBarreTexte->addWidget( textLabel_NbRub, 0, 0 );

    tab_DocumentsLayout->addLayout( layoutBarreTexte, 0, 0 );
    tabWidget_Ident->insertTab( tab_Documents, QString::fromLatin1("") );

    FormRubIdentLayout->addWidget( tabWidget_Ident, 0, 0 );
    languageChange();
    resize( QSize(612, 434).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // tab order
    setTabOrder( lineEdit_NomDossier, lineEdit_PremomDossier );
    setTabOrder( lineEdit_PremomDossier, lineEdit_NomDeNss );
    setTabOrder( lineEdit_NomDeNss, lineEdit_Titre );
    setTabOrder( lineEdit_Titre, lineEdit_DtNss );
    setTabOrder( lineEdit_DtNss, lineEdit_RangGeme );
    setTabOrder( lineEdit_RangGeme, comboBoxSexe );
    setTabOrder( comboBoxSexe, lineEdit_Profession );
    setTabOrder( lineEdit_Profession, textEdit_Adresse );
    setTabOrder( textEdit_Adresse, lineEdit_CdPostal );
    setTabOrder( lineEdit_CdPostal, lineEditVille );
    setTabOrder( lineEditVille, lineEdit_Tel1 );
    setTabOrder( lineEdit_Tel1, lineEdit_Tel2 );
    setTabOrder( lineEdit_Tel2, lineEdit_Tel3 );
    setTabOrder( lineEdit_Tel3, lineEdit_Email );
    setTabOrder( lineEdit_Email, lineEdit_NumSecu );
    setTabOrder( lineEdit_NumSecu, comboBoxQualiteAyantDroit );
    setTabOrder( comboBoxQualiteAyantDroit, lineEdit_NomAssure );
    setTabOrder( lineEdit_NomAssure, lineEdit_PrenomAssure );
    setTabOrder( lineEdit_PrenomAssure, pushButton_AddMedTTT );
    setTabOrder( pushButton_AddMedTTT, pushButton_DelMedTTT );
    setTabOrder( pushButton_DelMedTTT, pushButtonCreate );
    setTabOrder( pushButtonCreate, pushButtonSavModif );
    setTabOrder( pushButtonSavModif, pushButtonCancel );
    setTabOrder( pushButtonCancel, listView_Praticiens );
    setTabOrder( listView_Praticiens, tabWidget_Ident );
    setTabOrder( tabWidget_Ident, textLabel_NbRub );
    setTabOrder( textLabel_NbRub, comboBox_RubName );
    setTabOrder( comboBox_RubName, pushButtonRubDateChange );
    setTabOrder( pushButtonRubDateChange, pushButtonSave );
    setTabOrder( pushButtonSave, pushButtonPrint );
    setTabOrder( pushButtonPrint, pushButtonDelete );
    setTabOrder( pushButtonDelete, pushButtonAdd );
    setTabOrder( pushButtonAdd, pushButtonExporter );
}

/*
 *  Destroys the object and frees any allocated resources
 */
FormRubIdent::~FormRubIdent()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void FormRubIdent::languageChange()
{
    setProperty( "caption", tr( "FormRubIdent" ) );
    groupBox1->setProperty( "title", trUtf8( "\x50\x61\x74\x69\x65\x6e\x74\x20\x28\x62\xc3\xa9\x6e\xc3\xa9\x66\x69\x63\x69\x61\x69"
    "\x72\x65\x29" ) );
    textLabel5->setProperty( "text", tr( "Code Postal" ) );
    lineEdit_CdPostal->setProperty( "control", tr( "GGGGG" ) );
    lineEdit_CdPostal->setProperty( "mask", tr( "__  ___" ) );
    lineEdit_CdPostal->setProperty( "text", QString::null );
    textLabel6->setProperty( "text", tr( "Ville" ) );
    lineEditVille->setProperty( "control", tr( "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" ) );
    lineEditVille->setProperty( "mask", tr( "________________________________________________________________________________" ) );
    lineEditVille->setProperty( "text", QString::null );
    textLabel2->setProperty( "text", trUtf8( "\x50\x72\xc3\xa9\x6e\x6f\x6d" ) );
    lineEdit_NomDossier->setProperty( "control", tr( "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" ) );
    lineEdit_NomDossier->setProperty( "mask", tr( "________________________________________________________________________________" ) );
    lineEdit_NomDossier->setProperty( "text", QString::null );
    lineEdit_PremomDossier->setProperty( "control", tr( "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" ) );
    lineEdit_PremomDossier->setProperty( "mask", tr( "________________________________________________________________________________" ) );
    lineEdit_PremomDossier->setProperty( "text", QString::null );
    textLabel2_2->setProperty( "text", tr( "Nom" ) );
    textLabel4->setProperty( "text", tr( "Adresse" ) );
    textEdit_Adresse->setProperty( "text", tr( "textEdit_Adresse" ) );
    lineEdit_Tel3->setProperty( "control", tr( "GGGGGGGGGG" ) );
    lineEdit_Tel3->setProperty( "mask", tr( "__  __  __ __ __" ) );
    lineEdit_Tel3->setProperty( "text", QString::null );
    lineEdit_Tel1->setProperty( "control", tr( "GGGGGGGGGG" ) );
    lineEdit_Tel1->setProperty( "mask", tr( "__  __  __ __ __" ) );
    lineEdit_Tel1->setProperty( "text", QString::null );
    textLabel3_2_2_2->setProperty( "text", trUtf8( "\x54\xc3\xa9\x6c\x20\x32" ) );
    textLabel3_2_2_3->setProperty( "text", trUtf8( "\x54\xc3\xa9\x6c\x20\x33" ) );
    lineEdit_Tel2->setProperty( "control", tr( "GGGGGGGGGG" ) );
    lineEdit_Tel2->setProperty( "mask", tr( "__  __  __ __ __" ) );
    lineEdit_Tel2->setProperty( "text", QString::null );
    textLabel3_2_2->setProperty( "text", trUtf8( "\x54\xc3\xa9\x6c\x20\x31" ) );
    lineEdit_DtNss->setProperty( "control", tr( "GGGGGGGG" ) );
    lineEdit_DtNss->setProperty( "mask", tr( "__/__/____" ) );
    lineEdit_DtNss->setProperty( "text", QString::null );
    lineEdit_RangGeme->setProperty( "control", tr( "GG" ) );
    lineEdit_RangGeme->setProperty( "mask", tr( "__" ) );
    lineEdit_RangGeme->setProperty( "text", QString::null );
    QToolTip::add( lineEdit_RangGeme, trUtf8( "\x52\x61\x6e\x67\x20\x67\xc3\xa9\x6d\x65\x6c\x6c\x61\x69\x72\x65" ) );
    textLabel3_3_2_2->setProperty( "text", trUtf8( "\x52\x61\x6e\x67\x20\x47\xc3\xa9\x6d\x2e" ) );
    QToolTip::add( textLabel3_3_2_2, trUtf8( "\x52\x61\x6e\x67\x20\x67\xc3\xa9\x6d\x65\x6c\x6c\x61\x69\x72\x65" ) );
    textLabel3_3->setProperty( "text", tr( " Profession " ) );
    textLabel3->setProperty( "text", tr( "Date Nss" ) );
    comboBoxSexe->clear();
    comboBoxSexe->insertItem( tr( "Masculin" ) );
    comboBoxSexe->insertItem( trUtf8( "\x46\xc3\xa9\x6d\x69\x6e\x69\x6e" ) );
    comboBoxSexe->insertItem( trUtf8( "\x49\x6e\x64\xc3\xa9\x74\x65\x72\x6d\x69\x6e\xc3\xa9" ) );
    textLabel1_2->setProperty( "text", tr( "Sexe" ) );
    lineEdit_Profession->setProperty( "control", tr( "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMUUUUUUUUU" ) );
    lineEdit_Profession->setProperty( "mask", tr( "______________________________" ) );
    lineEdit_Profession->setProperty( "text", QString::null );
    textLabel2_2_2->setProperty( "text", tr( "Nom de naissance" ) );
    lineEdit_NomDeNss->setProperty( "control", tr( "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" ) );
    lineEdit_NomDeNss->setProperty( "mask", tr( "________________________________________________________________________________" ) );
    lineEdit_NomDeNss->setProperty( "text", QString::null );
    textLabel2_2_2_2->setProperty( "text", tr( "Titre" ) );
    lineEdit_Titre->setProperty( "control", tr( "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMUUUUUUUUU" ) );
    lineEdit_Titre->setProperty( "mask", tr( "______________________________" ) );
    lineEdit_Titre->setProperty( "text", QString::null );
    lineEdit_Email->setProperty( "text", tr( "lineEdit_Email" ) );
    textLabelNumeroDoss->setProperty( "text", trUtf8( "\x44\x6f\x73\x73\x2e\x20\x4e\xc2\xb0" ) );
    textLabel10->setProperty( "text", tr( "E mail" ) );
    groupBox2->setProperty( "title", trUtf8( "\x41\x73\x73\x75\x72\xc3\xa9" ) );
    textLabel9->setProperty( "text", trUtf8( "\x50\x72\xc3\xa9\x6e\x6f\x6d\x20\x41\x73\x73\x75\x72\xc3\xa9" ) );
    lineEdit_PrenomAssure->setProperty( "control", tr( "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" ) );
    lineEdit_PrenomAssure->setProperty( "mask", tr( "________________________________________________________________________________" ) );
    lineEdit_PrenomAssure->setProperty( "text", QString::null );
    lineEdit_DtNss_Assure->setProperty( "control", tr( "GGGGGGGG" ) );
    lineEdit_DtNss_Assure->setProperty( "mask", tr( "__/__/____" ) );
    lineEdit_DtNss_Assure->setProperty( "text", QString::null );
    lineEdit_NssClef_2->setProperty( "text", tr( "Date Nss" ) );
    textLabel8->setProperty( "text", trUtf8( "\x4e\x6f\x6d\x20\x41\x73\x73\x75\x72\xc3\xa9" ) );
    lineEdit_NomAssure->setProperty( "control", tr( "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" ) );
    lineEdit_NomAssure->setProperty( "mask", tr( "________________________________________________________________________________" ) );
    lineEdit_NomAssure->setProperty( "text", QString::null );
    textLabelNumeroDoss_2->setProperty( "text", trUtf8( "\x4c\x65\x20\x62\xc3\xa9\x6e\xc3\xa9\x66\x69\x63\x69\x61\x69\x72\x65\x20\x65\x73\x74"
    "\x20\x6c\x69\xc3\xa9\x20\xc3\xa0\x20\x6c\x27\x61\x73\x73\x75\x72\xc3\xa9\x20\x65"
    "\x6e\x20\x74\x61\x6e\x74\x20\x71\x75\x65\x2e\x2e\x2e" ) );
    QToolTip::add( comboBoxQualiteAyantDroit, trUtf8( "\x4c\x65\x20\x62\xc3\xa9\x6e\xc3\xa9\x66\x69\x63\x69\x61\x69\x72\x65\x20\x65\x73\x74"
    "\x20\x6c\x69\xc3\xa9\x20\xc3\xa0\x20\x6c\x27\x61\x73\x73\x75\x72\xc3\xa9\x20\x65"
    "\x6e\x20\x74\x61\x6e\x74\x20\x71\x75\x65\x20\x2e\x2e\x2e" ) );
    lineEdit_NssClef->setProperty( "text", trUtf8( "\x4e\xc2\xb0\x20\x53\x53" ) );
    lineEdit_NumSecu->setProperty( "control", tr( "GGGGGGGGGGGGG" ) );
    lineEdit_NumSecu->setProperty( "mask", tr( "_  __  __  __  ___  ___" ) );
    lineEdit_NumSecu->setProperty( "text", QString::null );
    textLabel7->setProperty( "text", trUtf8( "\x4e\x75\x6d\xc3\xa9\x72\x6f\x20\x64\x65\x20\x53\x53\x20\x64\x65\x20\x6c\x27\x61\x73"
    "\x73\x75\x72\xc3\xa9" ) );
    pushButton_AddMedTTT->setProperty( "text", tr( "&Ajouter un Intervenant" ) );
    pushButton_AddMedTTT->setProperty( "accel", QKeySequence( tr( "Alt+A" ) ) );
    pushButton_DelMedTTT->setProperty( "text", tr( "&Retirer un Intervenant" ) );
    pushButton_DelMedTTT->setProperty( "accel", QKeySequence( tr( "Alt+R" ) ) );
    listView_Praticiens->header()->setLabel( 0, trUtf8( "\x53\x70\xc3\xa9\x63\x69\x61\x6c\x69\x74\xc3\xa9\x20\x20\x20\x20\x20\x20\x20\x20" ) );
    listView_Praticiens->header()->setLabel( 1, tr( "Nom         " ) );
    listView_Praticiens->header()->setLabel( 2, trUtf8( "\x50\x72\xc3\xa9\x6e\x6f\x6d\x20\x20\x20\x20\x20" ) );
    listView_Praticiens->header()->setLabel( 3, trUtf8( "\x65\x6e\x20\x71\x75\x61\x6c\x69\x74\xc3\xa9\x20\x64\x65" ) );
    listView_Praticiens->header()->setLabel( 4, tr( "ID" ) );
    tabWidgetNotes->changeTab( tab, tr( "&Intervenants" ) );
    tabWidgetNotes->changeTab( tab_2, tr( "&Notes" ) );
    pushButtonCancel->setProperty( "text", tr( "Annu&ler" ) );
    pushButtonCancel->setProperty( "accel", QKeySequence( tr( "Alt+L" ) ) );
    pushButtonCreate->setProperty( "text", trUtf8( "\x26\x43\x72\xc3\xa9\x65\x72\x20\x6c\x65\x20\x64\x6f\x73\x73\x69\x65\x72\x20\x65\x74"
    "\x20\x79\x20\x61\x63\x63\xc3\xa9\x64\x65\x72" ) );
    pushButtonCreate->setProperty( "accel", QKeySequence( tr( "Alt+C" ) ) );
    pushButtonSavModif->setProperty( "text", tr( "&Enregistrer les modifications" ) );
    pushButtonSavModif->setProperty( "accel", QKeySequence( tr( "Alt+E" ) ) );
    tabWidget_Ident->changeTab( tab_Administratif, tr( "Administratif" ) );
    pushButtonExporter->setProperty( "text", QString::null );
    QToolTip::add( pushButtonExporter, tr( "Exporter cette image..." ) );
    pushButtonPrint->setProperty( "text", QString::null );
    QToolTip::add( pushButtonPrint, trUtf8( "\x49\x6d\x70\x72\x69\x6d\x65\x72\x20\x63\x65\x74\x74\x65\x20\x66\x65\x6e\xc3\xaa\x74"
    "\x72\x65" ) );
    textLabel_UserName->setProperty( "text", tr( "Utilisateur" ) );
    textLabel1->setProperty( "text", tr( "vu par :" ) );
    pushButtonRubDateChange->setProperty( "text", QString::null );
    QToolTip::add( pushButtonRubDateChange, trUtf8( "\x4d\x6f\x64\x69\x66\x69\x65\x72\x20\x6c\x61\x20\x64\x61\x74\x65\x20\x65\x74\x20\x6c"
    "\x27\x69\x6e\x74\x69\x74\x75\x6c\xc3\xa9\x20\x64\x75\x20\x64\x6f\x63\x75\x6d\x65"
    "\x6e\x74" ) );
    pushButtonAdd->setProperty( "text", QString::null );
    QToolTip::add( pushButtonAdd, tr( "Charger une image..." ) );
    pushButtonSave->setProperty( "text", QString::null );
    QToolTip::add( pushButtonSave, tr( "Enregistrer tout le dossier" ) );
    pushButtonDelete->setProperty( "text", QString::null );
    QToolTip::add( pushButtonDelete, trUtf8( "\x50\x6c\x61\x63\x65\x72\x20\x6c\x65\x20\x64\x6f\x63\x75\x6d\x65\x6e\x74\x20\x65\x6e"
    "\x20\x63\x6f\x75\x72\x73\x20\x63\x6f\x6d\x6d\x65\x20\x64\x6f\x63\x75\x6d\x65\x6e"
    "\x74\x20\xc3\xa0\x20\x65\x66\x66\x61\x63\x65\x72\x20\x28\x6e\x65\x20\x73\x65\x72"
    "\x61\x20\x65\x66\x66\x61\x63\xc3\xa9\x20\x71\x75\x27\x61\x70\x72\xc3\xa8\x73\x20"
    "\x65\x6e\x72\x65\x67\x69\x73\x74\x72\x65\x6d\x65\x6e\x74\x29" ) );
    textLabel_NbRub->setProperty( "text", QString::null );
    QToolTip::add( textLabel_NbRub, trUtf8( "\x4d\x6f\x64\x69\x66\x69\x65\x72\x20\x6c\x61\x20\x64\x61\x74\x65\x20\x65\x74\x20\x6c"
    "\x27\x69\x6e\x74\x69\x74\x75\x6c\xc3\xa9\x20\x64\x75\x20\x64\x6f\x63\x75\x6d\x65"
    "\x6e\x74" ) );
    tabWidget_Ident->changeTab( tab_Documents, trUtf8( "\x49\x6e\x66\x6f\x72\x6d\x61\x74\x69\x6f\x6e\x73\x20\x63\x6f\x6d\x70\x6c\xc3\xa9\x6d"
    "\x65\x6e\x74\x61\x69\x72\x65\x73\x2c\x20\x70\x68\x6f\x74\x6f\x73\x20\x65\x74\x20"
    "\x70\x6c\x75\x73\x20\x65\x6e\x63\x6f\x72\x65\x20\x2e\x2e\x2e" ) );
}

