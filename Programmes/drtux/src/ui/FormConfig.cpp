/****************************************************************************
** Form implementation generated from reading ui file 'FormConfig.ui'
**
** Created: mer. mai 4 22:19:50 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "FormConfig.h"

#include <qvariant.h>
#include <qdir.h>
#include <qfile.h>
#include <qtextstream.h>
#include <qfileinfo.h>
#include <qstring.h>
#include <qspinbox.h>
#include <qpushbutton.h>
#include <qlistbox.h>
#include <qwidgetstack.h>
#include <qwidget.h>
#include <qtextedit.h>
#include <qlineedit.h>
#include <qlabel.h>
#include <qframe.h>
#include <qcheckbox.h>
#include <qcombobox.h>
#include <qtabwidget.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>
#include <qheader.h>
#include <qlistview.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "../FormConfig.ui.h"

/*
 *  Constructs a FormConfig as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
FormConfig::FormConfig( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setProperty( "name", "FormConfig" );
    setProperty( "minimumSize", QSize( 800, 600 ) );
    setProperty( "sizeGripEnabled", QVariant( TRUE, 0 ) );
    FormConfigLayout = new QGridLayout( this, 1, 1, 11, 6, "FormConfigLayout"); 

    Layout1 = new QHBoxLayout( 0, 0, 6, "Layout1"); 

    buttonHelp = new QPushButton( this, "buttonHelp" );
    buttonHelp->setProperty( "autoDefault", QVariant( TRUE, 0 ) );
    Layout1->addWidget( buttonHelp );
    Horizontal_Spacing2 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout1->addItem( Horizontal_Spacing2 );

    buttonOk = new QPushButton( this, "buttonOk" );
    buttonOk->setProperty( "autoDefault", QVariant( TRUE, 0 ) );
    buttonOk->setProperty( "default", QVariant( TRUE, 0 ) );
    Layout1->addWidget( buttonOk );

    buttonCancel = new QPushButton( this, "buttonCancel" );
    buttonCancel->setProperty( "autoDefault", QVariant( TRUE, 0 ) );
    Layout1->addWidget( buttonCancel );

    FormConfigLayout->addMultiCellLayout( Layout1, 1, 1, 0, 1 );

    listBox = new QListBox( this, "listBox" );
    listBox->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, listBox->sizePolicy().hasHeightForWidth() ) );
    listBox->setProperty( "minimumSize", QSize( 100, 0 ) );
    listBox->setProperty( "maximumSize", QSize( 300, 32767 ) );
    listBox->setProperty( "paletteBackgroundColor", QColor( 255, 255, 255 ) );
    QFont listBox_font(  listBox->font() );
    listBox_font.setBold( TRUE );
    listBox->setFont( listBox_font ); 

    FormConfigLayout->addWidget( listBox, 0, 0 );

    m_WidgetStack = new QWidgetStack( this, "m_WidgetStack" );

    Analyse = new QWidget( m_WidgetStack, "Analyse" );
    AnalyseLayout = new QGridLayout( Analyse, 1, 1, 11, 6, "AnalyseLayout"); 

    msgConfig = new QTextEdit( Analyse, "msgConfig" );
    msgConfig->setProperty( "resizePolicy", "Manual" );
    msgConfig->setProperty( "hScrollBarMode", "AlwaysOff" );
    msgConfig->setProperty( "textFormat", "RichText" );
    msgConfig->setProperty( "wordWrap", "WidgetWidth" );
    msgConfig->setProperty( "readOnly", QVariant( TRUE, 0 ) );
    msgConfig->setProperty( "tabStopWidth", 1 );

    AnalyseLayout->addWidget( msgConfig, 0, 0 );
    m_WidgetStack->addWidget( Analyse, 0 );

    Repertoires = new QWidget( m_WidgetStack, "Repertoires" );
    RepertoiresLayout = new QGridLayout( Repertoires, 1, 1, 11, 6, "RepertoiresLayout"); 
    spacer39_3_4 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    RepertoiresLayout->addItem( spacer39_3_4, 4, 0 );
    spacer39_8 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    RepertoiresLayout->addItem( spacer39_8, 2, 0 );

    repTmpGeneral = new QLineEdit( Repertoires, "repTmpGeneral" );

    RepertoiresLayout->addWidget( repTmpGeneral, 2, 2 );

    but_RepGlossaire = new QPushButton( Repertoires, "but_RepGlossaire" );

    RepertoiresLayout->addMultiCellWidget( but_RepGlossaire, 3, 3, 3, 4 );

    lblRepGlossaire = new QLabel( Repertoires, "lblRepGlossaire" );

    RepertoiresLayout->addWidget( lblRepGlossaire, 3, 1 );

    lblRepTmpGeneral = new QLabel( Repertoires, "lblRepTmpGeneral" );
    lblRepTmpGeneral->setProperty( "backgroundMode", "PaletteBackground" );
    lblRepTmpGeneral->setProperty( "paletteBackgroundColor", QColor( 239, 239, 239 ) );
    lblRepTmpGeneral->setProperty( "textFormat", "RichText" );
    lblRepTmpGeneral->setProperty( "scaledContents", QVariant( TRUE, 0 ) );

    RepertoiresLayout->addWidget( lblRepTmpGeneral, 2, 1 );

    but_RepAide = new QPushButton( Repertoires, "but_RepAide" );

    RepertoiresLayout->addMultiCellWidget( but_RepAide, 4, 4, 3, 4 );
    spacer39_2_4 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    RepertoiresLayout->addItem( spacer39_2_4, 3, 0 );

    lblAide = new QLabel( Repertoires, "lblAide" );

    RepertoiresLayout->addWidget( lblAide, 4, 1 );

    Aide = new QLineEdit( Repertoires, "Aide" );

    RepertoiresLayout->addWidget( Aide, 4, 2 );

    but_tmpRepTmp = new QPushButton( Repertoires, "but_tmpRepTmp" );

    RepertoiresLayout->addMultiCellWidget( but_tmpRepTmp, 2, 2, 3, 4 );

    repGlossaire = new QLineEdit( Repertoires, "repGlossaire" );

    RepertoiresLayout->addWidget( repGlossaire, 3, 2 );

    line_repAppli = new QFrame( Repertoires, "line_repAppli" );
    line_repAppli->setProperty( "frameShape", "HLine" );
    line_repAppli->setProperty( "frameShadow", "Sunken" );
    line_repAppli->setProperty( "frameShape", QFrame::VLine );

    RepertoiresLayout->addMultiCellWidget( line_repAppli, 1, 1, 0, 4 );

    line_RepMask = new QFrame( Repertoires, "line_RepMask" );
    line_RepMask->setProperty( "frameShape", "HLine" );
    line_RepMask->setProperty( "frameShadow", "Sunken" );
    line_RepMask->setProperty( "frameShape", QFrame::VLine );

    RepertoiresLayout->addMultiCellWidget( line_RepMask, 6, 8, 0, 4 );
    spacer39_10 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    RepertoiresLayout->addItem( spacer39_10, 17, 0 );

    lblGestUser = new QLabel( Repertoires, "lblGestUser" );

    RepertoiresLayout->addWidget( lblGestUser, 18, 1 );

    GestContact = new QLineEdit( Repertoires, "GestContact" );

    RepertoiresLayout->addWidget( GestContact, 17, 2 );
    spacer39_2_6 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    RepertoiresLayout->addItem( spacer39_2_6, 18, 0 );

    GestUser = new QLineEdit( Repertoires, "GestUser" );

    RepertoiresLayout->addWidget( GestUser, 18, 2 );

    line_Contact = new QFrame( Repertoires, "line_Contact" );
    line_Contact->setProperty( "frameShape", "HLine" );
    line_Contact->setProperty( "frameShadow", "Sunken" );
    line_Contact->setProperty( "frameShape", QFrame::VLine );

    RepertoiresLayout->addMultiCellWidget( line_Contact, 14, 16, 0, 4 );

    textLabel2_3_2 = new QLabel( Repertoires, "textLabel2_3_2" );
    textLabel2_3_2->setProperty( "minimumSize", QSize( 0, 40 ) );
    textLabel2_3_2->setProperty( "maximumSize", QSize( 32767, 40 ) );
    QFont textLabel2_3_2_font(  textLabel2_3_2->font() );
    textLabel2_3_2_font.setBold( TRUE );
    textLabel2_3_2->setFont( textLabel2_3_2_font ); 
    textLabel2_3_2->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignBottom ) );

    RepertoiresLayout->addMultiCellWidget( textLabel2_3_2, 5, 5, 0, 4 );
    spacer39_2_5_3 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    RepertoiresLayout->addItem( spacer39_2_5_3, 11, 0 );

    titreGestUser = new QLabel( Repertoires, "titreGestUser" );
    titreGestUser->setProperty( "minimumSize", QSize( 0, 40 ) );
    titreGestUser->setProperty( "maximumSize", QSize( 32767, 40 ) );
    QFont titreGestUser_font(  titreGestUser->font() );
    titreGestUser_font.setBold( TRUE );
    titreGestUser->setFont( titreGestUser_font ); 
    titreGestUser->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignBottom ) );

    RepertoiresLayout->addMultiCellWidget( titreGestUser, 13, 13, 0, 4 );

    titreRep = new QLabel( Repertoires, "titreRep" );
    titreRep->setProperty( "minimumSize", QSize( 0, 40 ) );
    titreRep->setProperty( "maximumSize", QSize( 32767, 40 ) );
    QFont titreRep_font(  titreRep->font() );
    titreRep_font.setBold( TRUE );
    titreRep->setFont( titreRep_font ); 
    titreRep->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignBottom ) );

    RepertoiresLayout->addMultiCellWidget( titreRep, 0, 0, 0, 4 );
    spacer63 = new QSpacerItem( 20, 180, QSizePolicy::Minimum, QSizePolicy::Expanding );
    RepertoiresLayout->addItem( spacer63, 19, 2 );

    lblGestContact = new QLabel( Repertoires, "lblGestContact" );

    RepertoiresLayout->addMultiCellWidget( lblGestContact, 15, 17, 1, 1 );

    lblDefautVigie = new QLabel( Repertoires, "lblDefautVigie" );

    RepertoiresLayout->addWidget( lblDefautVigie, 11, 1 );

    defautVigie = new QLineEdit( Repertoires, "defautVigie" );

    RepertoiresLayout->addWidget( defautVigie, 11, 2 );

    but_MasqueVigie = new QPushButton( Repertoires, "but_MasqueVigie" );

    RepertoiresLayout->addMultiCellWidget( but_MasqueVigie, 11, 11, 3, 4 );

    but_AppliUtilisateur = new QPushButton( Repertoires, "but_AppliUtilisateur" );

    RepertoiresLayout->addMultiCellWidget( but_AppliUtilisateur, 16, 17, 4, 4 );

    but_AppliContact = new QPushButton( Repertoires, "but_AppliContact" );

    RepertoiresLayout->addWidget( but_AppliContact, 18, 4 );
    m_WidgetStack->addWidget( Repertoires, 1 );

    General = new QWidget( m_WidgetStack, "General" );
    GeneralLayout = new QGridLayout( General, 1, 1, 11, 6, "GeneralLayout"); 

    line_Themes = new QFrame( General, "line_Themes" );
    line_Themes->setProperty( "frameShape", "HLine" );
    line_Themes->setProperty( "frameShadow", "Sunken" );
    line_Themes->setProperty( "frameShape", QFrame::VLine );

    GeneralLayout->addMultiCellWidget( line_Themes, 12, 12, 0, 4 );

    textLabel3 = new QLabel( General, "textLabel3" );
    QFont textLabel3_font(  textLabel3->font() );
    textLabel3_font.setBold( TRUE );
    textLabel3->setFont( textLabel3_font ); 
    textLabel3->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignBottom | QLabel::AlignLeft ) );

    GeneralLayout->addMultiCellWidget( textLabel3, 11, 11, 0, 4 );
    spacer2_3_4 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    GeneralLayout->addItem( spacer2_3_4, 13, 0 );
    spacer2_2_2_2 = new QSpacerItem( 265, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    GeneralLayout->addItem( spacer2_2_2_2, 9, 4 );
    spacer2_3 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    GeneralLayout->addItem( spacer2_3, 8, 0 );
    spacer2 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    GeneralLayout->addItem( spacer2, 4, 0 );

    boxNouveauDossier = new QCheckBox( General, "boxNouveauDossier" );

    GeneralLayout->addMultiCellWidget( boxNouveauDossier, 8, 8, 1, 3 );

    line_Demarrage = new QFrame( General, "line_Demarrage" );
    line_Demarrage->setProperty( "frameShape", "HLine" );
    line_Demarrage->setProperty( "frameShadow", "Sunken" );
    line_Demarrage->setProperty( "frameShape", QFrame::VLine );

    GeneralLayout->addMultiCellWidget( line_Demarrage, 1, 3, 0, 4 );
    spacer2_3_2 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    GeneralLayout->addItem( spacer2_3_2, 9, 0 );

    m_Combo_Themes = new QComboBox( FALSE, General, "m_Combo_Themes" );

    GeneralLayout->addMultiCellWidget( m_Combo_Themes, 13, 13, 2, 3 );

    textLabel2 = new QLabel( General, "textLabel2" );
    QFont textLabel2_font(  textLabel2->font() );
    textLabel2_font.setBold( TRUE );
    textLabel2->setFont( textLabel2_font ); 
    textLabel2->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignBottom | QLabel::AlignLeft ) );

    GeneralLayout->addMultiCellWidget( textLabel2, 5, 5, 0, 4 );
    spacer2_2 = new QSpacerItem( 265, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    GeneralLayout->addMultiCell( spacer2_2, 2, 4, 4, 4 );

    boxConcurrent = new QCheckBox( General, "boxConcurrent" );

    GeneralLayout->addMultiCellWidget( boxConcurrent, 9, 9, 1, 3 );

    line_GestDoss = new QFrame( General, "line_GestDoss" );
    line_GestDoss->setProperty( "frameShape", "HLine" );
    line_GestDoss->setProperty( "frameShadow", "Sunken" );
    line_GestDoss->setProperty( "frameShape", QFrame::VLine );

    GeneralLayout->addMultiCellWidget( line_GestDoss, 6, 7, 0, 4 );
    spacer2_2_2_4 = new QSpacerItem( 265, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    GeneralLayout->addItem( spacer2_2_2_4, 13, 4 );

    textLabel1 = new QLabel( General, "textLabel1" );
    textLabel1->setProperty( "minimumSize", QSize( 0, 40 ) );
    textLabel1->setProperty( "maximumSize", QSize( 32767, 40 ) );
    QFont textLabel1_font(  textLabel1->font() );
    textLabel1_font.setBold( TRUE );
    textLabel1->setFont( textLabel1_font ); 
    textLabel1->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignBottom | QLabel::AlignLeft ) );

    GeneralLayout->addMultiCellWidget( textLabel1, 0, 0, 0, 4 );
    spacer2_3_3 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    GeneralLayout->addItem( spacer2_3_3, 10, 0 );
    spacer2_2_2 = new QSpacerItem( 265, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    GeneralLayout->addMultiCell( spacer2_2_2, 7, 8, 4, 4 );

    boxVerificationDossier = new QCheckBox( General, "boxVerificationDossier" );

    GeneralLayout->addMultiCellWidget( boxVerificationDossier, 10, 10, 1, 3 );

    textLabel7 = new QLabel( General, "textLabel7" );

    GeneralLayout->addWidget( textLabel7, 13, 1 );
    spacer2_2_2_3 = new QSpacerItem( 265, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    GeneralLayout->addItem( spacer2_2_2_3, 10, 4 );

    boxSplashScreen = new QCheckBox( General, "boxSplashScreen" );

    GeneralLayout->addMultiCellWidget( boxSplashScreen, 3, 4, 1, 3 );
    spacer25_6_2 = new QSpacerItem( 310, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    GeneralLayout->addItem( spacer25_6_2, 14, 4 );
    spacer12_2_2 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    GeneralLayout->addItem( spacer12_2_2, 14, 0 );
    spacer67 = new QSpacerItem( 20, 350, QSizePolicy::Minimum, QSizePolicy::Expanding );
    GeneralLayout->addItem( spacer67, 15, 2 );

    spinBox_menus_FontSize = new QSpinBox( General, "spinBox_menus_FontSize" );
    spinBox_menus_FontSize->setProperty( "maxValue", 32 );
    spinBox_menus_FontSize->setProperty( "minValue", 4 );
    spinBox_menus_FontSize->setProperty( "value", 9 );

    GeneralLayout->addWidget( spinBox_menus_FontSize, 14, 3 );

    textLabel_DefMenuFontSize = new QLabel( General, "textLabel_DefMenuFontSize" );
    textLabel_DefMenuFontSize->setProperty( "minimumSize", QSize( 0, 22 ) );
    textLabel_DefMenuFontSize->setProperty( "maximumSize", QSize( 32767, 22 ) );

    GeneralLayout->addMultiCellWidget( textLabel_DefMenuFontSize, 14, 14, 1, 2 );
    m_WidgetStack->addWidget( General, 2 );

    AccesRpide = new QWidget( m_WidgetStack, "AccesRpide" );
    AccesRpideLayout = new QGridLayout( AccesRpide, 1, 1, 11, 6, "AccesRpideLayout"); 

    tabRapidAccess = new QTabWidget( AccesRpide, "tabRapidAccess" );

    tab = new QWidget( tabRapidAccess, "tab" );
    tabLayout = new QGridLayout( tab, 1, 1, 11, 6, "tabLayout"); 
    spacer12_2 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    tabLayout->addItem( spacer12_2, 5, 0 );
    spacer13 = new QSpacerItem( 40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    tabLayout->addMultiCell( spacer13, 7, 7, 0, 1 );
    spacer13_2 = new QSpacerItem( 40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    tabLayout->addMultiCell( spacer13_2, 8, 8, 0, 1 );

    boxDockRapidAccess_Obs = new QCheckBox( tab, "boxDockRapidAccess_Obs" );

    tabLayout->addWidget( boxDockRapidAccess_Obs, 9, 2 );

    lblRepPDF_2 = new QLabel( tab, "lblRepPDF_2" );

    tabLayout->addMultiCellWidget( lblRepPDF_2, 6, 6, 1, 3 );

    boxDockRapidAccess_Terrain = new QCheckBox( tab, "boxDockRapidAccess_Terrain" );

    tabLayout->addMultiCellWidget( boxDockRapidAccess_Terrain, 8, 8, 2, 3 );
    spacer25_3 = new QSpacerItem( 300, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    tabLayout->addItem( spacer25_3, 9, 4 );
    spacer25_4 = new QSpacerItem( 300, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    tabLayout->addItem( spacer25_4, 10, 4 );
    spacer25_2 = new QSpacerItem( 300, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    tabLayout->addItem( spacer25_2, 8, 4 );
    spacer12_3 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    tabLayout->addItem( spacer12_3, 6, 0 );

    boxDockRapidAccess_Prescr = new QCheckBox( tab, "boxDockRapidAccess_Prescr" );

    tabLayout->addWidget( boxDockRapidAccess_Prescr, 10, 2 );

    line_MenAccRap = new QFrame( tab, "line_MenAccRap" );
    line_MenAccRap->setProperty( "frameShape", "HLine" );
    line_MenAccRap->setProperty( "frameShadow", "Sunken" );
    line_MenAccRap->setProperty( "frameShape", QFrame::VLine );

    tabLayout->addMultiCellWidget( line_MenAccRap, 1, 4, 0, 4 );

    textLabel_DockFntSize = new QLabel( tab, "textLabel_DockFntSize" );
    textLabel_DockFntSize->setProperty( "minimumSize", QSize( 0, 22 ) );
    textLabel_DockFntSize->setProperty( "maximumSize", QSize( 32767, 22 ) );

    tabLayout->addMultiCellWidget( textLabel_DockFntSize, 3, 5, 1, 2 );
    spacer13_3 = new QSpacerItem( 40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    tabLayout->addMultiCell( spacer13_3, 9, 9, 0, 1 );

    boxDockRapidAccess_Ident = new QCheckBox( tab, "boxDockRapidAccess_Ident" );

    tabLayout->addWidget( boxDockRapidAccess_Ident, 7, 2 );

    lblTitrePDF_1_2 = new QLabel( tab, "lblTitrePDF_1_2" );
    lblTitrePDF_1_2->setProperty( "minimumSize", QSize( 0, 40 ) );
    lblTitrePDF_1_2->setProperty( "maximumSize", QSize( 32767, 40 ) );
    QFont lblTitrePDF_1_2_font(  lblTitrePDF_1_2->font() );
    lblTitrePDF_1_2_font.setBold( TRUE );
    lblTitrePDF_1_2->setFont( lblTitrePDF_1_2_font ); 
    lblTitrePDF_1_2->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignBottom ) );

    tabLayout->addMultiCellWidget( lblTitrePDF_1_2, 0, 0, 0, 4 );
    spacer13_4 = new QSpacerItem( 40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    tabLayout->addMultiCell( spacer13_4, 10, 10, 0, 1 );

    spinBoxDockRapidAccess_FontSize = new QSpinBox( tab, "spinBoxDockRapidAccess_FontSize" );
    spinBoxDockRapidAccess_FontSize->setProperty( "maxValue", 32 );
    spinBoxDockRapidAccess_FontSize->setProperty( "minValue", 4 );
    spinBoxDockRapidAccess_FontSize->setProperty( "value", 9 );

    tabLayout->addMultiCellWidget( spinBoxDockRapidAccess_FontSize, 2, 5, 3, 3 );
    spacer25_6 = new QSpacerItem( 300, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    tabLayout->addMultiCell( spacer25_6, 4, 5, 4, 4 );
    spacer25 = new QSpacerItem( 300, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    tabLayout->addItem( spacer25, 7, 4 );
    spacer83 = new QSpacerItem( 20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding );
    tabLayout->addItem( spacer83, 23, 2 );
    spacer13_5_2_2_2 = new QSpacerItem( 40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    tabLayout->addMultiCell( spacer13_5_2_2_2, 21, 21, 0, 1 );
    spacer13_6 = new QSpacerItem( 40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    tabLayout->addMultiCell( spacer13_6, 14, 14, 0, 1 );
    spacer25_8 = new QSpacerItem( 300, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    tabLayout->addItem( spacer25_8, 14, 4 );

    boxDockRapidAccess_OpenDoc = new QCheckBox( tab, "boxDockRapidAccess_OpenDoc" );

    tabLayout->addWidget( boxDockRapidAccess_OpenDoc, 19, 2 );

    lblRepPDF_2_3 = new QLabel( tab, "lblRepPDF_2_3" );

    tabLayout->addMultiCellWidget( lblRepPDF_2_3, 13, 13, 1, 3 );
    spacer25_4_2 = new QSpacerItem( 300, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    tabLayout->addItem( spacer25_4_2, 18, 4 );
    spacer25_5_2_2 = new QSpacerItem( 300, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    tabLayout->addItem( spacer25_5_2_2, 20, 4 );
    spacer13_5_2 = new QSpacerItem( 40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    tabLayout->addMultiCell( spacer13_5_2, 19, 19, 0, 1 );
    spacer13_2_2 = new QSpacerItem( 40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    tabLayout->addMultiCell( spacer13_2_2, 15, 15, 0, 1 );
    spacer13_5_2_2 = new QSpacerItem( 40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    tabLayout->addMultiCell( spacer13_5_2_2, 20, 20, 0, 1 );

    boxDockRapidAccess_OpenVars = new QCheckBox( tab, "boxDockRapidAccess_OpenVars" );

    tabLayout->addMultiCellWidget( boxDockRapidAccess_OpenVars, 16, 16, 2, 3 );
    spacer13_5_2_2_2_2 = new QSpacerItem( 40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    tabLayout->addMultiCell( spacer13_5_2_2_2_2, 22, 22, 0, 1 );

    boxDockRapidAccess_OpenObs = new QCheckBox( tab, "boxDockRapidAccess_OpenObs" );

    tabLayout->addWidget( boxDockRapidAccess_OpenObs, 17, 2 );

    boxDockRapidAccess_OpenPrescr = new QCheckBox( tab, "boxDockRapidAccess_OpenPrescr" );

    tabLayout->addWidget( boxDockRapidAccess_OpenPrescr, 18, 2 );
    spacer13_5_2_2_3 = new QSpacerItem( 300, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    tabLayout->addItem( spacer13_5_2_2_3, 21, 4 );
    spacer12_3_2 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    tabLayout->addItem( spacer12_3_2, 13, 0 );
    spacer25_3_2 = new QSpacerItem( 300, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    tabLayout->addItem( spacer25_3_2, 17, 4 );
    spacer13_4_2 = new QSpacerItem( 40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    tabLayout->addMultiCell( spacer13_4_2, 18, 18, 0, 1 );

    boxDockRapidAccess_OpenIntervenants = new QCheckBox( tab, "boxDockRapidAccess_OpenIntervenants" );

    tabLayout->addMultiCellWidget( boxDockRapidAccess_OpenIntervenants, 22, 22, 2, 3 );

    boxDockRapidAccess_OpenIdent = new QCheckBox( tab, "boxDockRapidAccess_OpenIdent" );

    tabLayout->addWidget( boxDockRapidAccess_OpenIdent, 14, 2 );

    boxDockRapidAccess_OpenTerrain = new QCheckBox( tab, "boxDockRapidAccess_OpenTerrain" );

    tabLayout->addWidget( boxDockRapidAccess_OpenTerrain, 20, 2 );
    spacer13_5_2_2_3_2 = new QSpacerItem( 290, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    tabLayout->addItem( spacer13_5_2_2_3_2, 22, 4 );

    boxDockRapidAccess_OpenATCD = new QCheckBox( tab, "boxDockRapidAccess_OpenATCD" );

    tabLayout->addMultiCellWidget( boxDockRapidAccess_OpenATCD, 15, 15, 2, 3 );

    boxDockRapidAccess_OpenVisuNote = new QCheckBox( tab, "boxDockRapidAccess_OpenVisuNote" );

    tabLayout->addMultiCellWidget( boxDockRapidAccess_OpenVisuNote, 21, 21, 2, 3 );
    spacer13_2_2_2 = new QSpacerItem( 40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    tabLayout->addMultiCell( spacer13_2_2_2, 16, 16, 0, 1 );
    spacer25_5_2 = new QSpacerItem( 300, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    tabLayout->addItem( spacer25_5_2, 19, 4 );
    spacer25_2_2_2 = new QSpacerItem( 300, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    tabLayout->addItem( spacer25_2_2_2, 16, 4 );
    spacer25_2_2 = new QSpacerItem( 300, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    tabLayout->addItem( spacer25_2_2, 15, 4 );
    spacer13_3_2 = new QSpacerItem( 40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    tabLayout->addMultiCell( spacer13_3_2, 17, 17, 0, 1 );
    spacer13_5 = new QSpacerItem( 40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    tabLayout->addMultiCell( spacer13_5, 11, 11, 0, 1 );

    boxDockRapidAccess_Doc = new QCheckBox( tab, "boxDockRapidAccess_Doc" );

    tabLayout->addWidget( boxDockRapidAccess_Doc, 11, 2 );
    spacer25_5 = new QSpacerItem( 300, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    tabLayout->addItem( spacer25_5, 11, 4 );
    spacer25_5_3 = new QSpacerItem( 300, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    tabLayout->addItem( spacer25_5_3, 12, 4 );
    spacer13_5_3 = new QSpacerItem( 40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    tabLayout->addMultiCell( spacer13_5_3, 12, 12, 0, 1 );

    boxDockRapidAccessIntervenants = new QCheckBox( tab, "boxDockRapidAccessIntervenants" );

    tabLayout->addWidget( boxDockRapidAccessIntervenants, 12, 2 );
    tabRapidAccess->insertTab( tab, QString::fromLatin1("") );

    tab_2 = new QWidget( tabRapidAccess, "tab_2" );
    tabLayout_2 = new QGridLayout( tab_2, 1, 1, 11, 6, "tabLayout_2"); 
    spacer12_4_2 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    tabLayout_2->addItem( spacer12_4_2, 0, 0 );

    lblRepPDF_2_3_2 = new QLabel( tab_2, "lblRepPDF_2_3_2" );
    lblRepPDF_2_3_2->setProperty( "minimumSize", QSize( 0, 40 ) );
    lblRepPDF_2_3_2->setProperty( "maximumSize", QSize( 32767, 40 ) );
    lblRepPDF_2_3_2->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignBottom ) );

    tabLayout_2->addWidget( lblRepPDF_2_3_2, 0, 1 );
    spacer84 = new QSpacerItem( 20, 120, QSizePolicy::Minimum, QSizePolicy::Expanding );
    tabLayout_2->addItem( spacer84, 7, 1 );

    lblRepPDF_2_2 = new QLabel( tab_2, "lblRepPDF_2_2" );
    lblRepPDF_2_2->setProperty( "minimumSize", QSize( 0, 40 ) );
    lblRepPDF_2_2->setProperty( "maximumSize", QSize( 32767, 40 ) );
    lblRepPDF_2_2->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignBottom ) );

    tabLayout_2->addWidget( lblRepPDF_2_2, 4, 1 );

    textLabel2_2 = new QLabel( tab_2, "textLabel2_2" );
    textLabel2_2->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignVCenter ) );

    tabLayout_2->addWidget( textLabel2_2, 2, 1 );

    boxDockRapidAccess_Glossaire = new QCheckBox( tab_2, "boxDockRapidAccess_Glossaire" );

    tabLayout_2->addWidget( boxDockRapidAccess_Glossaire, 6, 1 );
    spacer12_4 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    tabLayout_2->addItem( spacer12_4, 4, 0 );

    buttonGroup1 = new QButtonGroup( tab_2, "buttonGroup1" );
    buttonGroup1->setColumnLayout(0, Qt::Vertical );
    buttonGroup1->layout()->setSpacing( 6 );
    buttonGroup1->layout()->setMargin( 11 );
    buttonGroup1Layout = new QGridLayout( buttonGroup1->layout() );
    buttonGroup1Layout->setAlignment( Qt::AlignTop );

    radioOpenCMDI = new QRadioButton( buttonGroup1, "radioOpenCMDI" );

    buttonGroup1Layout->addWidget( radioOpenCMDI, 0, 0 );

    radioOpenParent = new QRadioButton( buttonGroup1, "radioOpenParent" );

    buttonGroup1Layout->addWidget( radioOpenParent, 1, 0 );

    tabLayout_2->addWidget( buttonGroup1, 3, 1 );
    spacer12_3_2_2 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    tabLayout_2->addItem( spacer12_3_2_2, 6, 0 );

    line_FoncGlo = new QFrame( tab_2, "line_FoncGlo" );
    line_FoncGlo->setProperty( "frameShape", "HLine" );
    line_FoncGlo->setProperty( "frameShadow", "Sunken" );
    line_FoncGlo->setProperty( "frameShape", QFrame::VLine );

    tabLayout_2->addMultiCellWidget( line_FoncGlo, 5, 5, 0, 1 );

    line_RubAct = new QFrame( tab_2, "line_RubAct" );
    line_RubAct->setProperty( "frameShape", "HLine" );
    line_RubAct->setProperty( "frameShadow", "Sunken" );
    line_RubAct->setProperty( "frameShape", QFrame::VLine );

    tabLayout_2->addMultiCellWidget( line_RubAct, 1, 1, 0, 1 );
    tabRapidAccess->insertTab( tab_2, QString::fromLatin1("") );

    AccesRpideLayout->addWidget( tabRapidAccess, 0, 0 );
    m_WidgetStack->addWidget( AccesRpide, 3 );

    ListeMenus = new QWidget( m_WidgetStack, "ListeMenus" );
    ListeMenusLayout = new QGridLayout( ListeMenus, 1, 1, 11, 6, "ListeMenusLayout"); 

    but_MenuImages = new QPushButton( ListeMenus, "but_MenuImages" );

    ListeMenusLayout->addWidget( but_MenuImages, 6, 3 );

    textLabel2_3 = new QLabel( ListeMenus, "textLabel2_3" );
    textLabel2_3->setProperty( "minimumSize", QSize( 0, 40 ) );
    textLabel2_3->setProperty( "maximumSize", QSize( 32767, 40 ) );
    QFont textLabel2_3_font(  textLabel2_3->font() );
    textLabel2_3_font.setBold( TRUE );
    textLabel2_3->setFont( textLabel2_3_font ); 
    textLabel2_3->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignBottom ) );

    ListeMenusLayout->addMultiCellWidget( textLabel2_3, 0, 0, 0, 3 );

    menuImage = new QLineEdit( ListeMenus, "menuImage" );

    ListeMenusLayout->addWidget( menuImage, 6, 2 );

    line_DocList = new QFrame( ListeMenus, "line_DocList" );
    line_DocList->setProperty( "frameShape", "HLine" );
    line_DocList->setProperty( "frameShadow", "Sunken" );
    line_DocList->setProperty( "frameShape", QFrame::VLine );

    ListeMenusLayout->addMultiCellWidget( line_DocList, 1, 2, 0, 3 );

    lblMenuImages = new QLabel( ListeMenus, "lblMenuImages" );

    ListeMenusLayout->addWidget( lblMenuImages, 6, 1 );
    spacer34_4_2 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    ListeMenusLayout->addItem( spacer34_4_2, 6, 0 );

    layout2 = new QGridLayout( 0, 1, 1, 0, 6, "layout2"); 
    spacer34_4 = new QSpacerItem( 425, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    layout2->addItem( spacer34_4, 1, 0 );

    pushButtonAddRubrique = new QPushButton( ListeMenus, "pushButtonAddRubrique" );

    layout2->addWidget( pushButtonAddRubrique, 1, 1 );

    listViewRubParameters = new QListView( ListeMenus, "listViewRubParameters" );
    listViewRubParameters->addColumn( tr( "Rubrique" ) );
    listViewRubParameters->addColumn( tr( "Valeur" ) );
    listViewRubParameters->setProperty( "rootIsDecorated", QVariant( TRUE, 0 ) );

    layout2->addMultiCellWidget( listViewRubParameters, 0, 0, 0, 1 );

    ListeMenusLayout->addMultiCellLayout( layout2, 7, 7, 0, 3 );
    m_WidgetStack->addWidget( ListeMenus, 4 );

    Docks = new QWidget( m_WidgetStack, "Docks" );
    DocksLayout = new QGridLayout( Docks, 1, 1, 11, 6, "DocksLayout"); 

    boxDockRapidAccess = new QCheckBox( Docks, "boxDockRapidAccess" );

    DocksLayout->addWidget( boxDockRapidAccess, 3, 2 );

    line_MenuGlo = new QFrame( Docks, "line_MenuGlo" );
    line_MenuGlo->setProperty( "frameShape", "HLine" );
    line_MenuGlo->setProperty( "frameShadow", "Sunken" );
    line_MenuGlo->setProperty( "frameShape", QFrame::VLine );

    DocksLayout->addMultiCellWidget( line_MenuGlo, 5, 5, 0, 3 );
    spacer25_7 = new QSpacerItem( 499, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    DocksLayout->addItem( spacer25_7, 3, 3 );

    line_MenuAccesRapide = new QFrame( Docks, "line_MenuAccesRapide" );
    line_MenuAccesRapide->setProperty( "frameShape", "HLine" );
    line_MenuAccesRapide->setProperty( "frameShadow", "Sunken" );
    line_MenuAccesRapide->setProperty( "frameShape", QFrame::VLine );

    DocksLayout->addMultiCellWidget( line_MenuAccesRapide, 1, 1, 0, 3 );
    spacer12 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    DocksLayout->addMultiCell( spacer12, 2, 3, 0, 0 );

    lblTitrePDF_1_2_3 = new QLabel( Docks, "lblTitrePDF_1_2_3" );
    lblTitrePDF_1_2_3->setProperty( "minimumSize", QSize( 0, 40 ) );
    lblTitrePDF_1_2_3->setProperty( "maximumSize", QSize( 32767, 40 ) );
    QFont lblTitrePDF_1_2_3_font(  lblTitrePDF_1_2_3->font() );
    lblTitrePDF_1_2_3_font.setBold( TRUE );
    lblTitrePDF_1_2_3->setFont( lblTitrePDF_1_2_3_font ); 
    lblTitrePDF_1_2_3->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignBottom ) );

    DocksLayout->addMultiCellWidget( lblTitrePDF_1_2_3, 0, 0, 0, 3 );
    spacer25_7_2 = new QSpacerItem( 499, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    DocksLayout->addItem( spacer25_7_2, 6, 3 );
    spacer12_4_3 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    DocksLayout->addItem( spacer12_4_3, 6, 0 );

    lblTitrePDF_1_2_2 = new QLabel( Docks, "lblTitrePDF_1_2_2" );
    lblTitrePDF_1_2_2->setProperty( "minimumSize", QSize( 0, 40 ) );
    lblTitrePDF_1_2_2->setProperty( "maximumSize", QSize( 32767, 40 ) );
    QFont lblTitrePDF_1_2_2_font(  lblTitrePDF_1_2_2->font() );
    lblTitrePDF_1_2_2_font.setBold( TRUE );
    lblTitrePDF_1_2_2->setFont( lblTitrePDF_1_2_2_font ); 
    lblTitrePDF_1_2_2->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignBottom ) );

    DocksLayout->addMultiCellWidget( lblTitrePDF_1_2_2, 4, 4, 0, 3 );

    boxDockGlossaire = new QCheckBox( Docks, "boxDockGlossaire" );

    DocksLayout->addWidget( boxDockGlossaire, 6, 2 );
    spacer62 = new QSpacerItem( 20, 120, QSizePolicy::Minimum, QSizePolicy::Expanding );
    DocksLayout->addItem( spacer62, 14, 3 );

    lblTitrePDF_1_2_2_2 = new QLabel( Docks, "lblTitrePDF_1_2_2_2" );
    lblTitrePDF_1_2_2_2->setProperty( "minimumSize", QSize( 0, 40 ) );
    lblTitrePDF_1_2_2_2->setProperty( "maximumSize", QSize( 32767, 40 ) );
    QFont lblTitrePDF_1_2_2_2_font(  lblTitrePDF_1_2_2_2->font() );
    lblTitrePDF_1_2_2_2_font.setBold( TRUE );
    lblTitrePDF_1_2_2_2->setFont( lblTitrePDF_1_2_2_2_font ); 
    lblTitrePDF_1_2_2_2->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignBottom ) );

    DocksLayout->addMultiCellWidget( lblTitrePDF_1_2_2_2, 7, 7, 0, 3 );

    line_MenuRub = new QFrame( Docks, "line_MenuRub" );
    line_MenuRub->setProperty( "frameShape", "HLine" );
    line_MenuRub->setProperty( "frameShadow", "Sunken" );
    line_MenuRub->setProperty( "frameShape", QFrame::VLine );

    DocksLayout->addMultiCellWidget( line_MenuRub, 8, 8, 0, 3 );
    spacer12_4_4 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    DocksLayout->addMultiCell( spacer12_4_4, 9, 10, 0, 0 );
    spacer25_7_3 = new QSpacerItem( 499, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    DocksLayout->addItem( spacer25_7_3, 10, 3 );
    spacer12_4_4_2 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    DocksLayout->addItem( spacer12_4_4_2, 13, 0 );
    spacer25_7_3_2 = new QSpacerItem( 335, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    DocksLayout->addItem( spacer25_7_3_2, 13, 3 );

    lblTitrePDF_1_2_2_2_2 = new QLabel( Docks, "lblTitrePDF_1_2_2_2_2" );
    lblTitrePDF_1_2_2_2_2->setProperty( "minimumSize", QSize( 0, 40 ) );
    lblTitrePDF_1_2_2_2_2->setProperty( "maximumSize", QSize( 32767, 40 ) );
    QFont lblTitrePDF_1_2_2_2_2_font(  lblTitrePDF_1_2_2_2_2->font() );
    lblTitrePDF_1_2_2_2_2_font.setBold( TRUE );
    lblTitrePDF_1_2_2_2_2->setFont( lblTitrePDF_1_2_2_2_2_font ); 
    lblTitrePDF_1_2_2_2_2->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignBottom ) );

    DocksLayout->addMultiCellWidget( lblTitrePDF_1_2_2_2_2, 11, 11, 0, 3 );

    boxDockBarreOnglets = new QCheckBox( Docks, "boxDockBarreOnglets" );

    DocksLayout->addMultiCellWidget( boxDockBarreOnglets, 13, 13, 1, 2 );

    boxDockRubriques = new QCheckBox( Docks, "boxDockRubriques" );

    DocksLayout->addMultiCellWidget( boxDockRubriques, 9, 10, 1, 2 );

    line_MenuRub_Onglet = new QFrame( Docks, "line_MenuRub_Onglet" );
    line_MenuRub_Onglet->setProperty( "frameShape", "HLine" );
    line_MenuRub_Onglet->setProperty( "frameShadow", "Sunken" );
    line_MenuRub_Onglet->setProperty( "frameShape", QFrame::VLine );

    DocksLayout->addMultiCellWidget( line_MenuRub_Onglet, 12, 12, 0, 3 );
    m_WidgetStack->addWidget( Docks, 5 );

    CCAM = new QWidget( m_WidgetStack, "CCAM" );
    CCAMLayout = new QGridLayout( CCAM, 1, 1, 11, 6, "CCAMLayout"); 

    but_CCAMExe = new QPushButton( CCAM, "but_CCAMExe" );

    CCAMLayout->addWidget( but_CCAMExe, 10, 3 );

    lblCCAMExe = new QLabel( CCAM, "lblCCAMExe" );

    CCAMLayout->addWidget( lblCCAMExe, 10, 1 );
    spacer39_3_2 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    CCAMLayout->addItem( spacer39_3_2, 4, 0 );

    line_Exemple = new QFrame( CCAM, "line_Exemple" );
    line_Exemple->setProperty( "frameShape", "HLine" );
    line_Exemple->setProperty( "frameShadow", "Sunken" );
    line_Exemple->setProperty( "frameShape", QFrame::VLine );

    CCAMLayout->addMultiCellWidget( line_Exemple, 7, 7, 0, 3 );
    spacer39_6 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    CCAMLayout->addItem( spacer39_6, 2, 0 );

    lblCCAMPrefixe_2 = new QLabel( CCAM, "lblCCAMPrefixe_2" );

    CCAMLayout->addWidget( lblCCAMPrefixe_2, 4, 1 );
    spacer64 = new QSpacerItem( 20, 85, QSizePolicy::Minimum, QSizePolicy::Expanding );
    CCAMLayout->addItem( spacer64, 12, 2 );

    CCAMExe = new QLineEdit( CCAM, "CCAMExe" );

    CCAMLayout->addWidget( CCAMExe, 10, 2 );
    spacer39_7 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    CCAMLayout->addItem( spacer39_7, 8, 0 );

    CCAMCodePrefixe = new QLineEdit( CCAM, "CCAMCodePrefixe" );

    CCAMLayout->addMultiCellWidget( CCAMCodePrefixe, 4, 4, 2, 3 );

    CCAMPrefixe = new QLineEdit( CCAM, "CCAMPrefixe" );

    CCAMLayout->addMultiCellWidget( CCAMPrefixe, 2, 2, 2, 3 );

    lblCCAMPrefixe = new QLabel( CCAM, "lblCCAMPrefixe" );

    CCAMLayout->addWidget( lblCCAMPrefixe, 2, 1 );

    textLabel2_2_2_4 = new QLabel( CCAM, "textLabel2_2_2_4" );
    textLabel2_2_2_4->setProperty( "minimumSize", QSize( 0, 40 ) );
    textLabel2_2_2_4->setProperty( "maximumSize", QSize( 32767, 40 ) );
    QFont textLabel2_2_2_4_font(  textLabel2_2_2_4->font() );
    textLabel2_2_2_4_font.setBold( TRUE );
    textLabel2_2_2_4->setFont( textLabel2_2_2_4_font ); 
    textLabel2_2_2_4->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignBottom ) );

    CCAMLayout->addMultiCellWidget( textLabel2_2_2_4, 0, 0, 0, 3 );

    lblCCAMPostfixe = new QLabel( CCAM, "lblCCAMPostfixe" );

    CCAMLayout->addWidget( lblCCAMPostfixe, 3, 1 );
    spacer39_2_3 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    CCAMLayout->addItem( spacer39_2_3, 9, 0 );

    CCAMIni = new QLineEdit( CCAM, "CCAMIni" );

    CCAMLayout->addWidget( CCAMIni, 11, 2 );
    spacer39_3_3 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    CCAMLayout->addItem( spacer39_3_3, 10, 0 );
    spacer39_2_2 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    CCAMLayout->addItem( spacer39_2_2, 3, 0 );
    spacer39_4_2 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    CCAMLayout->addItem( spacer39_4_2, 5, 0 );

    CCAMPanneau = new QComboBox( FALSE, CCAM, "CCAMPanneau" );

    CCAMLayout->addMultiCellWidget( CCAMPanneau, 9, 9, 2, 3 );

    lblCCAMIni = new QLabel( CCAM, "lblCCAMIni" );

    CCAMLayout->addWidget( lblCCAMIni, 11, 1 );

    but_CCAMConfig = new QPushButton( CCAM, "but_CCAMConfig" );

    CCAMLayout->addWidget( but_CCAMConfig, 11, 3 );

    lblCCAMPostfixe_2 = new QLabel( CCAM, "lblCCAMPostfixe_2" );

    CCAMLayout->addWidget( lblCCAMPostfixe_2, 5, 1 );

    textLabel2_2_2_4_2 = new QLabel( CCAM, "textLabel2_2_2_4_2" );
    textLabel2_2_2_4_2->setProperty( "minimumSize", QSize( 0, 40 ) );
    textLabel2_2_2_4_2->setProperty( "maximumSize", QSize( 32767, 40 ) );
    QFont textLabel2_2_2_4_2_font(  textLabel2_2_2_4_2->font() );
    textLabel2_2_2_4_2_font.setBold( TRUE );
    textLabel2_2_2_4_2->setFont( textLabel2_2_2_4_2_font ); 
    textLabel2_2_2_4_2->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignBottom ) );

    CCAMLayout->addMultiCellWidget( textLabel2_2_2_4_2, 6, 6, 0, 3 );

    line_PresCCAM = new QFrame( CCAM, "line_PresCCAM" );
    line_PresCCAM->setProperty( "frameShape", "HLine" );
    line_PresCCAM->setProperty( "frameShadow", "Sunken" );
    line_PresCCAM->setProperty( "frameShape", QFrame::VLine );

    CCAMLayout->addMultiCellWidget( line_PresCCAM, 1, 1, 0, 3 );
    spacer39_4_3 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    CCAMLayout->addItem( spacer39_4_3, 11, 0 );

    lblCCAMPanneau = new QLabel( CCAM, "lblCCAMPanneau" );

    CCAMLayout->addWidget( lblCCAMPanneau, 9, 1 );

    CCAMPostfixe = new QLineEdit( CCAM, "CCAMPostfixe" );

    CCAMLayout->addMultiCellWidget( CCAMPostfixe, 3, 3, 2, 3 );

    textCCAMView = new QTextEdit( CCAM, "textCCAMView" );
    textCCAMView->setProperty( "vScrollBarMode", "Auto" );
    textCCAMView->setProperty( "hScrollBarMode", "AlwaysOff" );
    textCCAMView->setProperty( "textFormat", "AutoText" );
    textCCAMView->setProperty( "readOnly", QVariant( TRUE, 0 ) );

    CCAMLayout->addMultiCellWidget( textCCAMView, 8, 8, 1, 3 );

    CCAMCodePostfixe = new QLineEdit( CCAM, "CCAMCodePostfixe" );

    CCAMLayout->addMultiCellWidget( CCAMCodePostfixe, 5, 5, 2, 3 );
    m_WidgetStack->addWidget( CCAM, 6 );

    PDF = new QWidget( m_WidgetStack, "PDF" );
    PDFLayout = new QGridLayout( PDF, 1, 1, 11, 6, "PDFLayout"); 
    spacer65 = new QSpacerItem( 20, 158, QSizePolicy::Minimum, QSizePolicy::Expanding );
    PDFLayout->addItem( spacer65, 9, 2 );

    repDefautPDF = new QLineEdit( PDF, "repDefautPDF" );

    PDFLayout->addWidget( repDefautPDF, 2, 2 );

    but_AppliPdftk = new QPushButton( PDF, "but_AppliPdftk" );

    PDFLayout->addWidget( but_AppliPdftk, 4, 3 );

    but_RepDesPDF = new QPushButton( PDF, "but_RepDesPDF" );

    PDFLayout->addWidget( but_RepDesPDF, 2, 3 );

    lblRepPDFTmp = new QLabel( PDF, "lblRepPDFTmp" );

    PDFLayout->addWidget( lblRepPDFTmp, 3, 1 );
    spacer39_3 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    PDFLayout->addItem( spacer39_3, 4, 0 );

    appliPDF = new QLineEdit( PDF, "appliPDF" );

    PDFLayout->addWidget( appliPDF, 5, 2 );

    line_Appli = new QFrame( PDF, "line_Appli" );
    line_Appli->setProperty( "frameShape", "HLine" );
    line_Appli->setProperty( "frameShadow", "Sunken" );
    line_Appli->setProperty( "frameShape", QFrame::VLine );

    PDFLayout->addMultiCellWidget( line_Appli, 1, 1, 0, 3 );

    but_VisuPDF = new QPushButton( PDF, "but_VisuPDF" );

    PDFLayout->addWidget( but_VisuPDF, 5, 3 );

    lblRepPdftk = new QLabel( PDF, "lblRepPdftk" );

    PDFLayout->addWidget( lblRepPdftk, 4, 1 );

    lblAppliPDF = new QLabel( PDF, "lblAppliPDF" );

    PDFLayout->addWidget( lblAppliPDF, 5, 1 );

    repPdftk = new QLineEdit( PDF, "repPdftk" );

    PDFLayout->addWidget( repPdftk, 4, 2 );

    but_RepTmpPDF = new QPushButton( PDF, "but_RepTmpPDF" );

    PDFLayout->addWidget( but_RepTmpPDF, 3, 3 );

    lblInfoPDF = new QLabel( PDF, "lblInfoPDF" );
    lblInfoPDF->setProperty( "lineWidth", 1 );
    lblInfoPDF->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignTop ) );

    PDFLayout->addMultiCellWidget( lblInfoPDF, 8, 8, 1, 3 );
    spacer39_2 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    PDFLayout->addItem( spacer39_2, 3, 0 );

    line_Info = new QFrame( PDF, "line_Info" );
    line_Info->setProperty( "frameShape", "HLine" );
    line_Info->setProperty( "frameShadow", "Sunken" );
    line_Info->setProperty( "frameShape", QFrame::VLine );

    PDFLayout->addMultiCellWidget( line_Info, 7, 7, 0, 3 );

    lblTitrePDF_2 = new QLabel( PDF, "lblTitrePDF_2" );
    lblTitrePDF_2->setProperty( "minimumSize", QSize( 0, 40 ) );
    lblTitrePDF_2->setProperty( "maximumSize", QSize( 32767, 40 ) );
    QFont lblTitrePDF_2_font(  lblTitrePDF_2->font() );
    lblTitrePDF_2_font.setBold( TRUE );
    lblTitrePDF_2->setFont( lblTitrePDF_2_font ); 
    lblTitrePDF_2->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignBottom ) );

    PDFLayout->addMultiCellWidget( lblTitrePDF_2, 6, 6, 0, 3 );

    lblRepPDF = new QLabel( PDF, "lblRepPDF" );

    PDFLayout->addWidget( lblRepPDF, 2, 1 );

    lblTitrePDF_1 = new QLabel( PDF, "lblTitrePDF_1" );
    lblTitrePDF_1->setProperty( "minimumSize", QSize( 0, 40 ) );
    lblTitrePDF_1->setProperty( "maximumSize", QSize( 32767, 40 ) );
    QFont lblTitrePDF_1_font(  lblTitrePDF_1->font() );
    lblTitrePDF_1_font.setBold( TRUE );
    lblTitrePDF_1->setFont( lblTitrePDF_1_font ); 
    lblTitrePDF_1->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignBottom ) );

    PDFLayout->addMultiCellWidget( lblTitrePDF_1, 0, 0, 0, 3 );
    spacer39 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    PDFLayout->addItem( spacer39, 2, 0 );

    repPDFTmp = new QLineEdit( PDF, "repPDFTmp" );

    PDFLayout->addWidget( repPDFTmp, 3, 2 );
    spacer39_4 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    PDFLayout->addItem( spacer39_4, 5, 0 );
    spacer39_5 = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    PDFLayout->addItem( spacer39_5, 8, 0 );
    m_WidgetStack->addWidget( PDF, 7 );

    FormConfigLayout->addWidget( m_WidgetStack, 0, 1 );
    languageChange();
    resize( QSize(915, 738).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( buttonCancel, SIGNAL( clicked() ), this, SLOT( reject() ) );
    connect( buttonHelp, SIGNAL( clicked() ), this, SLOT( buttonHelp_clicked() ) );
    connect( buttonOk, SIGNAL( clicked() ), this, SLOT( buttonOk_clicked() ) );
    connect( listBox, SIGNAL( highlighted(int) ), this, SLOT( listBox_highlighted(int) ) );
    connect( but_tmpRepTmp, SIGNAL( clicked() ), this, SLOT( but_tmpRepTmp_clicked() ) );
    connect( but_RepGlossaire, SIGNAL( clicked() ), this, SLOT( but_RepGlossaire_clicked() ) );
    connect( but_RepAide, SIGNAL( clicked() ), this, SLOT( but_RepAide_clicked() ) );
    connect( but_AppliContact, SIGNAL( clicked() ), this, SLOT( but_AppliContact_clicked() ) );
    connect( but_AppliUtilisateur, SIGNAL( clicked() ), this, SLOT( but_AppliUtilisateur_clicked() ) );
    connect( but_MenuImages, SIGNAL( clicked() ), this, SLOT( but_MenuImages_clicked() ) );
    connect( but_CCAMExe, SIGNAL( clicked() ), this, SLOT( but_CCAMExe_clicked() ) );
    connect( but_CCAMConfig, SIGNAL( clicked() ), this, SLOT( but_CCAMConfig_clicked() ) );
    connect( but_RepDesPDF, SIGNAL( clicked() ), this, SLOT( but_RepDesPDF_clicked() ) );
    connect( but_RepTmpPDF, SIGNAL( clicked() ), this, SLOT( but_RepTmpPDF_clicked() ) );
    connect( but_AppliPdftk, SIGNAL( clicked() ), this, SLOT( but_AppliPdftk_clicked() ) );
    connect( but_VisuPDF, SIGNAL( clicked() ), this, SLOT( but_VisuPDF_clicked() ) );
    connect( but_MasqueVigie, SIGNAL( clicked() ), this, SLOT( but_MasqueVigie_clicked() ) );
    connect( listViewRubParameters, SIGNAL( doubleClicked(QListViewItem*,const QPoint&,int) ), this, SLOT( listViewRubParameters_doubleClicked(QListViewItem*,const QPoint&,int) ) );
    connect( pushButtonAddRubrique, SIGNAL( clicked() ), this, SLOT( pushButtonAddRubrique_clicked() ) );

    // tab order
    setTabOrder( listBox, msgConfig );
    setTabOrder( msgConfig, repTmpGeneral );
    setTabOrder( repTmpGeneral, repGlossaire );
    setTabOrder( repGlossaire, GestContact );
    setTabOrder( GestContact, buttonHelp );
    setTabOrder( buttonHelp, buttonOk );
    setTabOrder( buttonOk, buttonCancel );
    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
FormConfig::~FormConfig()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void FormConfig::languageChange()
{
    setProperty( "caption", trUtf8( "\x43\x6f\x6e\x66\x69\x67\x75\x72\x61\x74\x69\x6f\x6e\x20\x47\xc3\xa9\x6e\xc3\xa9\x72"
    "\x61\x6c\x65" ) );
    buttonHelp->setProperty( "text", trUtf8( "\x56\xc3\xa9\x26\x72\x69\x66\x69\x65\x72\x20\x6c\x65\x73\x20\x64\x6f\x6e\x6e\xc3\xa9"
    "\x65\x73" ) );
    buttonHelp->setProperty( "accel", QKeySequence( tr( "Alt+R" ) ) );
    buttonOk->setProperty( "text", tr( "Sauvegarder les &modifications" ) );
    buttonOk->setProperty( "accel", QKeySequence( tr( "Alt+M" ) ) );
    buttonCancel->setProperty( "text", tr( "&Annuler" ) );
    buttonCancel->setProperty( "accel", QKeySequence( tr( "Alt+A" ) ) );
    listBox->clear();
    listBox->insertItem( tr( "analyse" ) );
    listBox->insertItem( tr( "gene" ) );
    listBox->insertItem( tr( "rep" ) );
    listBox->insertItem( tr( "rapidaccess" ) );
    listBox->insertItem( tr( "docks" ) );
    listBox->insertItem( tr( "cccam" ) );
    listBox->insertItem( tr( "pdf" ) );
    msgConfig->setProperty( "text", QString::null );
    but_RepGlossaire->setProperty( "text", tr( "Choisir" ) );
    lblRepGlossaire->setProperty( "text", trUtf8( "\x52\xc3\xa9\x70\x65\x72\x74\x6f\x69\x72\x65\x20\x70\x6f\x75\x72\x20\x6c\x65\x20\x47"
    "\x6c\x6f\x73\x73\x61\x69\x72\x65" ) );
    lblRepTmpGeneral->setProperty( "text", trUtf8( "\x52\xc3\xa9\x70\x65\x72\x74\x6f\x69\x72\x65\x20\x74\x65\x6d\x70\x6f\x72\x61\x69\x72"
    "\x65\x20\x67\xc3\xa9\x6e\xc3\xa9\x72\x61\x6c" ) );
    but_RepAide->setProperty( "text", tr( "Choisir" ) );
    lblAide->setProperty( "text", tr( "Chemin vers les fichiers d'aide" ) );
    but_tmpRepTmp->setProperty( "text", tr( "Choisir" ) );
    lblGestUser->setProperty( "text", tr( "Chemin : gestion des utilisateurs" ) );
    textLabel2_3_2->setProperty( "text", trUtf8( "\x3c\x62\x3e\x4d\x61\x73\x71\x75\x65\x73\x20\x70\x61\x72\x20\x64\xc3\xa9\x66\x61\x75"
    "\x74\x20\x28\x56\x69\x67\x69\x65\x29\x3c\x2f\x62\x3e" ) );
    titreGestUser->setProperty( "text", tr( "<b>Chemin vers l'application de gestion des contacts</b>" ) );
    titreRep->setProperty( "text", trUtf8( "\x3c\x62\x3e\x52\xc3\xa9\x70\x65\x72\x74\x6f\x69\x72\x65\x73\x20\x64\x65\x20\x6c\x27"
    "\x61\x70\x70\x6c\x69\x63\x61\x74\x69\x6f\x6e\x3c\x2f\x62\x3e" ) );
    lblGestContact->setProperty( "text", tr( "Chemin : gestion des contacts" ) );
    lblDefautVigie->setProperty( "text", tr( "Vigie" ) );
    but_MasqueVigie->setProperty( "text", tr( "Choisir" ) );
    but_AppliUtilisateur->setProperty( "text", tr( "Choisir" ) );
    but_AppliContact->setProperty( "text", tr( "Choisir" ) );
    textLabel3->setProperty( "text", trUtf8( "\x3c\x62\x3e\x54\x68\xc3\xa8\x6d\x65\x73\x3c\x2f\x62\x3e" ) );
    boxNouveauDossier->setProperty( "text", trUtf8( "\x44\x72\x54\x75\x78\x20\x70\x65\x75\x74\x20\x63\x72\xc3\xa9\x65\x72\x20\x64\x65\x20"
    "\x6e\x6f\x75\x76\x65\x61\x75\x78\x20\x64\x6f\x73\x73\x69\x65\x72\x73\x20\x6f\x75"
    "\x20\x6c\x65\x73\x20\x64\xc3\xa9\x74\x72\x75\x69\x72\x65" ) );
    textLabel2->setProperty( "text", tr( "<b>Gestion des dossiers patients</b>" ) );
    boxConcurrent->setProperty( "text", tr( "Autoriser la gestion concurrente depuis Manager" ) );
    textLabel1->setProperty( "text", trUtf8( "\x3c\x62\x3e\x44\xc3\xa9\x6d\x61\x72\x72\x61\x67\x65\x3c\x2f\x62\x3e" ) );
    boxVerificationDossier->setProperty( "text", trUtf8( "\x56\xc3\xa9\x72\x69\x66\x69\x65\x72\x20\x6c\x65\x73\x20\x64\x6f\x73\x73\x69\x65\x72"
    "\x73" ) );
    textLabel7->setProperty( "text", trUtf8( "\x53\xc3\xa9\x6c\x65\x63\x74\x69\x6f\x6e\x6e\x65\x7a\x20\x6c\x65\x20\x74\x68\xc3\xa8"
    "\x6d\x65" ) );
    boxSplashScreen->setProperty( "text", trUtf8( "\x41\x66\x66\x69\x63\x68\x65\x72\x20\x6c\x65\x20\x53\x70\x6c\x61\x73\x68\x20\x53\x63"
    "\x72\x65\x65\x6e\x20\x61\x75\x20\x64\xc3\xa9\x6d\x61\x72\x72\x61\x67\x65" ) );
    textLabel_DefMenuFontSize->setProperty( "text", trUtf8( "\x54\x61\x69\x6c\x6c\x65\x20\x64\x65\x20\x6c\x61\x20\x70\x6f\x6c\x69\x63\x65\x20\x64"
    "\x65\x20\x63\x61\x72\x61\x63\x74\xc3\xa8\x72\x65\x20\x64\x65\x73\x20\x6d\x65\x6e"
    "\x75\x73" ) );
    boxDockRapidAccess_Obs->setProperty( "text", trUtf8( "\x4c\x65\x73\x20\x63\x69\x6e\x71\x20\x64\x65\x72\x6e\x69\xc3\xa8\x72\x65\x73\x20\x6f"
    "\x62\x73\x65\x72\x76\x61\x74\x69\x6f\x6e\x73" ) );
    lblRepPDF_2->setProperty( "text", trUtf8( "\x3c\x62\x3e\x49\x74\x65\x6d\x73\x20\xc3\xa0\x20\x61\x66\x66\x69\x63\x68\x65\x72\x20"
    "\x64\x61\x6e\x73\x20\x6c\x65\x20\x6d\x65\x6e\x75\x3c\x2f\x62\x3e" ) );
    boxDockRapidAccess_Terrain->setProperty( "text", trUtf8( "\x4c\x65\x73\x20\x74\x65\x72\x72\x61\x69\x6e\x73\x20\x61\x76\x65\x63\x20\x6c\x65\x73"
    "\x20\x61\x6e\x74\xc3\xa9\x63\xc3\xa9\x64\x65\x6e\x74\x73\x20\x65\x74\x20\x6c\x65"
    "\x73\x20\x76\x61\x72\x69\x61\x62\x6c\x65\x73" ) );
    boxDockRapidAccess_Prescr->setProperty( "text", trUtf8( "\x4c\x65\x73\x20\x63\x69\x6e\x71\x20\x64\x65\x72\x6e\x69\xc3\xa8\x72\x65\x73\x20\x70"
    "\x72\x65\x73\x63\x72\x69\x70\x74\x69\x6f\x6e\x73" ) );
    textLabel_DockFntSize->setProperty( "text", trUtf8( "\x54\x61\x69\x6c\x6c\x65\x20\x64\x65\x20\x6c\x61\x20\x70\x6f\x6c\x69\x63\x65\x20\x64"
    "\x65\x20\x63\x61\x72\x61\x63\x74\xc3\xa8\x72\x65" ) );
    boxDockRapidAccess_Ident->setProperty( "text", trUtf8( "\x49\x64\x65\x6e\x74\x69\x74\xc3\xa9" ) );
    lblTitrePDF_1_2->setProperty( "text", trUtf8( "\x3c\x62\x3e\x4d\x65\x6e\x75\x20\x64\x27\x61\x63\x63\xc3\xa8\x73\x20\x72\x61\x70\x69"
    "\x64\x65\x3c\x2f\x62\x3e" ) );
    boxDockRapidAccess_OpenDoc->setProperty( "text", tr( "Les cinq derniers documents" ) );
    lblRepPDF_2_3->setProperty( "text", trUtf8( "\x3c\x62\x3e\x49\x74\x65\x6d\x73\x20\x73\x79\x73\x74\xc3\xa9\x6d\x61\x74\x69\x71\x75"
    "\x65\x6d\x65\x6e\x74\x20\x6f\x75\x76\x65\x72\x74\x73\x3c\x2f\x62\x3e" ) );
    boxDockRapidAccess_OpenVars->setProperty( "text", tr( "Les variables" ) );
    boxDockRapidAccess_OpenObs->setProperty( "text", trUtf8( "\x4c\x65\x73\x20\x63\x69\x6e\x71\x20\x64\x65\x72\x6e\x69\xc3\xa8\x72\x65\x73\x20\x6f"
    "\x62\x73\x65\x72\x76\x61\x74\x69\x6f\x6e\x73" ) );
    boxDockRapidAccess_OpenPrescr->setProperty( "text", trUtf8( "\x4c\x65\x73\x20\x63\x69\x6e\x71\x20\x64\x65\x72\x6e\x69\xc3\xa8\x72\x65\x73\x20\x70"
    "\x72\x65\x73\x63\x72\x69\x70\x74\x69\x6f\x6e\x73" ) );
    boxDockRapidAccess_OpenIntervenants->setProperty( "text", tr( "La liste des correspondants" ) );
    boxDockRapidAccess_OpenIdent->setProperty( "text", trUtf8( "\x49\x64\x65\x6e\x74\x69\x74\xc3\xa9" ) );
    boxDockRapidAccess_OpenTerrain->setProperty( "text", tr( "Les cinq derniers terrains" ) );
    boxDockRapidAccess_OpenATCD->setProperty( "text", trUtf8( "\x4c\x65\x73\x20\x61\x6e\x74\xc3\xa9\x63\xc3\xa9\x64\x65\x6e\x74\x73" ) );
    boxDockRapidAccess_OpenVisuNote->setProperty( "text", trUtf8( "\x46\x65\x6e\xc3\xaa\x74\x72\x65\x20\x64\x75\x20\x63\x6f\x6d\x6d\x65\x6e\x74\x61\x69"
    "\x72\x65\x20\x69\x64\x65\x6e\x74\x69\x74\xc3\xa9" ) );
    boxDockRapidAccess_Doc->setProperty( "text", tr( "Les cinq derniers documents" ) );
    boxDockRapidAccessIntervenants->setProperty( "text", tr( "La liste des correspondants" ) );
    tabRapidAccess->changeTab( tab, tr( "Visuel" ) );
    lblRepPDF_2_3_2->setProperty( "text", tr( "<b>Activation des rubriques</b>" ) );
    lblRepPDF_2_2->setProperty( "text", tr( "<b>Fonction Glossaire</b>" ) );
    textLabel2_2->setProperty( "text", trUtf8( "\x4c\x6f\x72\x73\x71\x75\x65\x20\x6c\x27\x6f\x6e\x20\x63\x6c\x69\x71\x75\x65\x20\x73"
    "\x75\x72\x20\x75\x6e\x20\x69\x74\x65\x6d\x20\x64\x65\x20\x64\xc3\xa9\x62\x75\x74"
    "\x20\x64\x65\x20\x6c\x69\x73\x74\x65\x20\x28\x43\x6f\x6f\x72\x64\x6f\x6e\x6e\xc3"
    "\xa9\x65\x73\x2c\x20\x41\x6e\x74\xc3\xa9\x63\xc3\xa9\x64\x65\x6e\x74\x73\x2c\x20"
    "\x56\x61\x72\x69\x61\x62\x6c\x65\x73\x2c\x20\x4f\x62\x73\x65\x72\x76\x61\x74\x69"
    "\x6f\x6e\x73\x2e\x2e\x2e\x29\x20\x3a" ) );
    boxDockRapidAccess_Glossaire->setProperty( "text", tr( "Autoriser l'utilisation du Glossaire" ) );
    buttonGroup1->setProperty( "title", trUtf8( "\x52\xc3\xa9\x61\x63\x74\x69\x6f\x6e" ) );
    radioOpenCMDI->setProperty( "text", trUtf8( "\x4f\x75\x76\x72\x65\x20\x6c\x61\x20\x66\x65\x6e\xc3\xaa\x74\x72\x65\x20\x63\x6f\x72"
    "\x72\x65\x73\x70\x6f\x6e\x64\x61\x6e\x74\x65\x20\x64\x61\x6e\x73\x20\x6c\x27\x65"
    "\x73\x70\x61\x63\x65\x20\x64\x65\x20\x74\x72\x61\x76\x61\x69\x6c" ) );
    radioOpenParent->setProperty( "text", tr( "Affiche ou cache la liste de documents disponibles" ) );
    tabRapidAccess->changeTab( tab_2, trUtf8( "\x46\x6f\x6e\x63\x74\x69\x6f\x6e\x6e\x61\x6c\x69\x74\xc3\xa9\x73" ) );
    but_MenuImages->setProperty( "text", tr( "Choisir" ) );
    textLabel2_3->setProperty( "text", tr( "<b>Listes des documents (observations, prescriptions, documents)</b>" ) );
    lblMenuImages->setProperty( "text", tr( "Menu des Images" ) );
    pushButtonAddRubrique->setProperty( "text", tr( "Ajouter une rubrique" ) );
    listViewRubParameters->header()->setLabel( 0, tr( "Rubrique" ) );
    listViewRubParameters->header()->setLabel( 1, tr( "Valeur" ) );
    boxDockRapidAccess->setProperty( "text", trUtf8( "\x4d\x65\x74\x74\x72\x65\x20\xc3\xa0\x20\x6c\x27\xc3\xa9\x63\x72\x61\x6e" ) );
    lblTitrePDF_1_2_3->setProperty( "text", trUtf8( "\x3c\x62\x3e\x4d\x65\x6e\x75\x20\x64\x27\x61\x63\x63\xc3\xa8\x73\x20\x72\x61\x70\x69"
    "\x64\x65\x3c\x2f\x62\x3e" ) );
    lblTitrePDF_1_2_2->setProperty( "text", tr( "<b>Menu Glossaire</b>" ) );
    boxDockGlossaire->setProperty( "text", trUtf8( "\x4d\x65\x74\x74\x72\x65\x20\xc3\xa0\x20\x6c\x27\xc3\xa9\x63\x72\x61\x6e" ) );
    lblTitrePDF_1_2_2_2->setProperty( "text", tr( "<b>Menu Rubriques</b>" ) );
    lblTitrePDF_1_2_2_2_2->setProperty( "text", tr( "<b>Barre d'onglets  des rubriques</b>" ) );
    boxDockBarreOnglets->setProperty( "text", trUtf8( "\x4d\x65\x74\x74\x72\x65\x20\xc3\xa0\x20\x6c\x27\xc3\xa9\x63\x72\x61\x6e" ) );
    boxDockRubriques->setProperty( "text", trUtf8( "\x4d\x65\x74\x74\x72\x65\x20\xc3\xa0\x20\x6c\x27\xc3\xa9\x63\x72\x61\x6e" ) );
    but_CCAMExe->setProperty( "text", tr( "Choisir" ) );
    lblCCAMExe->setProperty( "text", tr( "Chemin vers l'executable" ) );
    lblCCAMPrefixe_2->setProperty( "text", trUtf8( "\x50\x72\xc3\xa9\x66\x69\x78\x65\x20\x70\x6f\x75\x72\x20\x6c\x65\x20\x63\x6f\x64\x65"
    "\x20\x64\x65\x73\x20\x61\x63\x74\x65\x73\x20\x43\x43\x41\x4d" ) );
    lblCCAMPrefixe->setProperty( "text", trUtf8( "\x50\x72\xc3\xa9\x66\x69\x78\x65\x20\x70\x6f\x75\x72\x20\x6c\x65\x20\x6c\x69\x62\x65"
    "\x6c\x6c\xc3\xa9\x20\x64\x65\x73\x20\x61\x63\x74\x65\x73\x20\x43\x43\x41\x4d" ) );
    textLabel2_2_2_4->setProperty( "text", trUtf8( "\x3c\x62\x3e\x50\x72\xc3\xa9\x73\x65\x6e\x74\x61\x74\x69\x6f\x6e\x20\x64\x65\x20\x6c"
    "\x61\x20\x43\x43\x41\x4d\x3c\x2f\x62\x3e" ) );
    lblCCAMPostfixe->setProperty( "text", trUtf8( "\x50\x6f\x73\x74\x66\x69\x78\x65\x20\x70\x6f\x75\x72\x20\x6c\x65\x20\x6c\x69\x62\x65"
    "\x6c\x6c\xc3\xa9\x20\x64\x65\x73\x20\x61\x63\x74\x65\x73\x20\x43\x43\x41\x4d" ) );
    CCAMPanneau->clear();
    CCAMPanneau->insertItem( tr( "&Thesaurus" ) );
    CCAMPanneau->insertItem( tr( "&Code CCAM" ) );
    CCAMPanneau->insertItem( tr( "&Recherche Patient" ) );
    lblCCAMIni->setProperty( "text", tr( "Chemin vers le fichier de configuration" ) );
    but_CCAMConfig->setProperty( "text", tr( "Choisir" ) );
    lblCCAMPostfixe_2->setProperty( "text", tr( "Postfixe pour le code des actes CCAM" ) );
    textLabel2_2_2_4_2->setProperty( "text", tr( "<b>Exemple</b>" ) );
    lblCCAMPanneau->setProperty( "text", trUtf8( "\x50\x61\x6e\x6e\x65\x61\x75\x20\xc3\xa0\x20\x61\x63\x74\x69\x76\x65\x72" ) );
    but_AppliPdftk->setProperty( "text", tr( "Choisir" ) );
    but_RepDesPDF->setProperty( "text", tr( "Choisir" ) );
    lblRepPDFTmp->setProperty( "text", trUtf8( "\x52\xc3\xa9\x70\x65\x72\x74\x6f\x69\x72\x65\x20\x74\x65\x6d\x70\x6f\x72\x61\x69\x72"
    "\x65\x20\x70\x6f\x75\x72\x20\x6c\x65\x73\x20\x50\x44\x46" ) );
    but_VisuPDF->setProperty( "text", tr( "Choisir" ) );
    lblRepPdftk->setProperty( "text", tr( "Chemin vers l'application <b>pdftk</b>" ) );
    lblAppliPDF->setProperty( "text", tr( "Chemin vers l'application : visualisation des PDF" ) );
    but_RepTmpPDF->setProperty( "text", tr( "Choisir" ) );
    lblInfoPDF->setProperty( "text", trUtf8( "\x44\x72\x20\x54\x75\x78\x20\x76\x6f\x75\x73\x20\x70\x65\x72\x6d\x65\x74\x20\x64\x65"
    "\x20\x72\x65\x6d\x70\x6c\x69\x72\x20\x6c\x65\x73\x20\x66\x6f\x72\x6d\x75\x6c\x61"
    "\x69\x72\x65\x73\x20\x50\x44\x46\x20\x66\x6f\x75\x72\x6e\x69\x73\x20\x70\x61\x72"
    "\x20\x6c\x61\x20\x73\xc3\xa9\x63\x75\x72\x69\x74\xc3\xa9\x20\x73\x6f\x63\x69\x61"
    "\x6c\x65\x20\x66\x72\x61\x6e\xc3\xa7\x61\x69\x73\x65\x20\x3a\xa\x2d\x20\x44"
    "\xc3\xa9\x63\x6c\x61\x72\x61\x74\x69\x6f\x6e\x20\x64\x75\x20\x6d\xc3\xa9\x64\x65"
    "\x63\x69\x6e\x20\x74\x72\x61\x69\x74\x61\x6e\x74\x2c\xa\x2d\x20\x50\x72\x6f"
    "\x74\x6f\x63\x6f\x6c\x65\x20\x64\x65\x20\x73\x6f\x69\x6e\x73\x20\x41\x4c\x44\x2e"
    "\xa\xa\x56\x6f\x75\x73\x20\x70\x6f\x75\x76\x65\x7a\x20\x74\xc3\xa9\x6c"
    "\xc3\xa9\x63\x68\x61\x72\x67\x65\x72\x20\x63\x65\x73\x20\x64\x6f\x63\x75\x6d\x65"
    "\x6e\x74\x73\x20\x76\x69\x65\x72\x67\x65\x73\x20\x73\x75\x72\x20\x6c\x65\x20\x73"
    "\x69\x74\x65\x20\x64\x27\x61\x6d\xc3\xa9\x6c\x69\x65\x20\x3a\xa\x68\x74\x74"
    "\x70\x3a\x2f\x2f\x77\x77\x77\x2e\x61\x6d\x65\x6c\x69\x2e\x66\x72\x2f\xa"
    "\xa\x50\x6f\x75\x72\x20\x75\x74\x69\x6c\x69\x73\x65\x72\x20\x63\x65\x74\x74\x65"
    "\x20\x66\x6f\x6e\x63\x74\x69\x6f\x6e\x2c\x20\x72\x65\x6e\x73\x65\x69\x67\x6e\x65"
    "\x7a\x20\x6c\x65\x73\x20\xc3\xa9\x6c\xc3\xa9\x6d\x65\x6e\x74\x73\x20\x64\x65\x20"
    "\x63\x65\x74\x74\x65\x20\x70\x61\x67\x65\x2e" ) );
    lblTitrePDF_2->setProperty( "text", tr( "<b>Informations</b>" ) );
    lblRepPDF->setProperty( "text", trUtf8( "\x52\xc3\xa9\x70\x65\x72\x74\x6f\x69\x72\x65\x20\x63\x6f\x6e\x74\x65\x6e\x61\x6e\x74"
    "\x20\x6c\x65\x73\x20\x66\x69\x63\x68\x69\x65\x72\x73\x20\x50\x44\x46\x20\xc3\xa0"
    "\x20\x72\x65\x6d\x70\x6c\x69\x72" ) );
    lblTitrePDF_1->setProperty( "text", trUtf8( "\x3c\x62\x3e\x52\xc3\xa9\x70\x65\x72\x74\x6f\x69\x72\x65\x73\x20\x64\x65\x20\x6c\x27"
    "\x61\x70\x70\x6c\x69\x63\x61\x74\x69\x6f\x6e\x3c\x2f\x62\x3e" ) );
}

