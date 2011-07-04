/****************************************************************************
** Form implementation generated from reading ui file 'Dlg_MedicaTux.ui'
**
** Created: mer. mai 4 22:19:35 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "Dlg_MedicaTux.h"

#include <qvariant.h>
#include <qdatetime.h>
#include <qdir.h>
#include <stdlib.h>
#include <qiconset.h>
#include <qpixmap.h>
#include <../../MedinTuxTools/CMaskedLineEdit.h>
#include <qpushbutton.h>
#include <qprogressbar.h>
#include <qsplitter.h>
#include <qlabel.h>
#include <qcheckbox.h>
#include <qcombobox.h>
#include <qtabwidget.h>
#include <qwidget.h>
#include <qwidgetstack.h>
#include <qheader.h>
#include <qlistview.h>
#include <qlineedit.h>
#include <qtextbrowser.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "Dlg_MedicaAdjustPoso.h"
#include "DlgGetText.h"
#include "Dlg_PosoManager.h"
#include "drtux.h"
#include "CApp.h"
#include "../../MedinTuxTools/CGestIni.h"
#include "../../MedinTuxTools/CPrtQListBoxItem.h"
#include "../Dlg_MedicaTux.ui.h"
static const unsigned char image0_data[] = { 
    0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d,
    0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00, 0x16,
    0x08, 0x06, 0x00, 0x00, 0x00, 0xc4, 0xb4, 0x6c, 0x3b, 0x00, 0x00, 0x02,
    0x62, 0x49, 0x44, 0x41, 0x54, 0x38, 0x8d, 0xad, 0x95, 0xcd, 0x4e, 0xd4,
    0x50, 0x14, 0xc7, 0x7f, 0x1d, 0x08, 0x12, 0xd1, 0x15, 0x5b, 0x17, 0x26,
    0x6e, 0x74, 0x3f, 0xab, 0xb3, 0x18, 0x1f, 0xc0, 0xc4, 0x37, 0x30, 0xba,
    0x86, 0xd5, 0x3c, 0x81, 0x4b, 0x1f, 0x60, 0x56, 0xd3, 0x37, 0x70, 0xa1,
    0x51, 0xf1, 0x63, 0xa1, 0x01, 0x6b, 0xe5, 0x0a, 0x62, 0x4c, 0x61, 0x2c,
    0x21, 0x24, 0x0e, 0x0b, 0x09, 0x88, 0x3a, 0xe2, 0x30, 0xcc, 0x77, 0x7b,
    0xaf, 0x8b, 0xe9, 0x90, 0xd2, 0x0f, 0x62, 0x22, 0x27, 0xe9, 0xa2, 0xbd,
    0xff, 0xf3, 0xbb, 0xa7, 0xf7, 0x9c, 0x7f, 0x6b, 0x29, 0xa5, 0x48, 0x86,
    0x88, 0x18, 0xa5, 0x94, 0x95, 0x5a, 0xc8, 0x88, 0x3c, 0x6d, 0x21, 0x4b,
    0x68, 0xe6, 0xe7, 0x11, 0x11, 0xf3, 0x2f, 0x50, 0x53, 0x2e, 0x67, 0x6a,
    0x0b, 0x49, 0xa1, 0xae, 0x54, 0xd0, 0x8d, 0x06, 0xc3, 0xe8, 0xfe, 0x2c,
    0xa8, 0xae, 0x56, 0xd1, 0xcd, 0x26, 0xe1, 0xd4, 0x54, 0x4a, 0x5b, 0x88,
    0x0b, 0xc3, 0x4a, 0x05, 0xed, 0x79, 0xe8, 0x8d, 0x0d, 0x42, 0x60, 0x3f,
    0x07, 0x2e, 0x22, 0x26, 0xb4, 0x6d, 0xf4, 0xfa, 0x3a, 0x7a, 0x6d, 0x8d,
    0xee, 0x60, 0xc0, 0x97, 0x84, 0xb6, 0x30, 0x16, 0xf6, 0xe7, 0xe6, 0x08,
    0x96, 0x97, 0x09, 0x56, 0x56, 0x08, 0x36, 0x37, 0xd1, 0xc0, 0x45, 0x60,
    0x37, 0x91, 0x20, 0x22, 0x66, 0x68, 0xdb, 0x04, 0x9e, 0x47, 0xe0, 0x38,
    0x04, 0xb5, 0x1a, 0xfb, 0xc0, 0x2a, 0x70, 0x3f, 0xa6, 0xb5, 0xc6, 0xcd,
    0x13, 0x11, 0xd3, 0x02, 0x0c, 0x10, 0xef, 0xc4, 0x10, 0xe8, 0x00, 0x57,
    0xa2, 0xfb, 0x81, 0x6d, 0xa3, 0x3d, 0x8f, 0xd0, 0x71, 0xd0, 0xbe, 0xcf,
    0x77, 0x60, 0x19, 0x58, 0x00, 0x1e, 0x01, 0xe3, 0x46, 0x5a, 0xf1, 0xa9,
    0x10, 0x11, 0xf3, 0x15, 0xb8, 0x0c, 0x4c, 0x46, 0x1b, 0x8c, 0x4b, 0x9d,
    0x2c, 0x16, 0x99, 0x28, 0x95, 0x30, 0x9d, 0x0e, 0xa1, 0xeb, 0x9e, 0x40,
    0x15, 0xf0, 0x02, 0x78, 0x1c, 0x83, 0x12, 0xe5, 0x9f, 0x84, 0x52, 0xca,
    0xba, 0x26, 0x62, 0xb6, 0x12, 0x70, 0x80, 0x70, 0x67, 0x87, 0x42, 0xbf,
    0x8f, 0x69, 0xb7, 0xd1, 0xf5, 0x3a, 0x07, 0x11, 0xf4, 0x15, 0xf0, 0x24,
    0x01, 0x4d, 0x55, 0x1c, 0xaf, 0x7c, 0x0b, 0xb8, 0x44, 0xc6, 0x3c, 0x02,
    0x87, 0xc0, 0x7b, 0xe0, 0x25, 0xf0, 0x34, 0x03, 0x4a, 0x4e, 0x1e, 0x4a,
    0x29, 0xeb, 0x3a, 0x60, 0x15, 0x8b, 0x84, 0xb3, 0xb3, 0x0c, 0xe1, 0xd4,
    0xd5, 0x02, 0x7e, 0x9d, 0x01, 0x4d, 0x1d, 0x45, 0x6a, 0xb1, 0x54, 0xa2,
    0xdb, 0xef, 0x13, 0x34, 0x1a, 0xa7, 0x9e, 0xcf, 0x00, 0x37, 0xce, 0x4a,
    0xcc, 0xab, 0x58, 0x44, 0x4c, 0xc3, 0xb6, 0x19, 0x76, 0x3a, 0x0c, 0xda,
    0xed, 0x54, 0xc5, 0x13, 0xc0, 0x55, 0xe0, 0x1d, 0xf9, 0x26, 0xca, 0xb4,
    0xf4, 0x0f, 0xdb, 0xe6, 0xd8, 0xf3, 0x68, 0xb9, 0x2e, 0xbd, 0x7a, 0x9d,
    0x9f, 0xc0, 0x37, 0xe0, 0x08, 0x18, 0x00, 0x41, 0x04, 0x9f, 0x01, 0x9c,
    0x1c, 0x78, 0xca, 0xd2, 0x07, 0xb6, 0x4d, 0xdb, 0xf3, 0x68, 0x39, 0x0e,
    0x5d, 0xdf, 0x67, 0x1f, 0xf8, 0x00, 0x2c, 0x01, 0xdb, 0x40, 0x3b, 0xaa,
    0x3a, 0x8c, 0x72, 0xa6, 0x81, 0xc5, 0x0c, 0xf8, 0x29, 0x4b, 0xef, 0x55,
    0xab, 0x1c, 0x79, 0x1e, 0x87, 0x8e, 0xc3, 0xb1, 0xef, 0xb3, 0x07, 0x7c,
    0x04, 0x5e, 0x03, 0x0f, 0x80, 0x3b, 0x8c, 0x26, 0xa2, 0x0b, 0xf4, 0xa3,
    0x0d, 0x74, 0x04, 0x79, 0x48, 0x8e, 0xa5, 0xb7, 0xcb, 0x65, 0x9a, 0xab,
    0xab, 0x34, 0x5d, 0x97, 0x8e, 0xef, 0x73, 0x00, 0x7c, 0x02, 0xde, 0x02,
    0x6f, 0x18, 0x75, 0x5f, 0x29, 0x65, 0xdd, 0x02, 0x9a, 0x31, 0x70, 0x08,
    0xfc, 0x89, 0xde, 0x66, 0x8e, 0x1c, 0x4b, 0x3b, 0xd3, 0xd3, 0x04, 0xbd,
    0x1e, 0xbf, 0x81, 0x1a, 0xa3, 0x59, 0x5d, 0x24, 0x3d, 0x52, 0x22, 0x62,
    0x9e, 0x01, 0x17, 0x18, 0x8d, 0xde, 0x76, 0x74, 0x5c, 0x0b, 0x31, 0xed,
    0xc9, 0x51, 0x28, 0xa5, 0xac, 0x9b, 0xbd, 0x1e, 0xbb, 0xc0, 0x67, 0xc0,
    0xcd, 0x81, 0x8e, 0xb5, 0xb7, 0x19, 0x7d, 0xfd, 0x6a, 0x8c, 0x1c, 0xb8,
    0x90, 0xd0, 0x16, 0x92, 0x09, 0x77, 0xa3, 0x84, 0xa5, 0x1c, 0x68, 0x5c,
    0x7b, 0x0f, 0xd8, 0x03, 0x9e, 0x67, 0x68, 0x73, 0x2d, 0xfd, 0xbf, 0xbf,
    0xa6, 0x4c, 0xf0, 0x79, 0x44, 0xa6, 0xf3, 0xce, 0x23, 0xfe, 0x02, 0xa0,
    0x71, 0x68, 0x14, 0x2a, 0xcf, 0xcb, 0xf9, 0x00, 0x00, 0x00, 0x00, 0x49,
    0x45, 0x4e, 0x44, 0xae, 0x42, 0x60, 0x82
};


/*
 *  Constructs a Dlg_MedicaTux as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
Dlg_MedicaTux::Dlg_MedicaTux( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    QImage img;
    img.loadFromData( image0_data, sizeof( image0_data ), "PNG" );
    image0 = img;
    if ( !name )
	setProperty( "name", "Dlg_MedicaTux" );
    Dlg_MedicaTuxLayout = new QGridLayout( this, 1, 1, 3, 6, "Dlg_MedicaTuxLayout"); 

    progressBar_EDMed = new QProgressBar( this, "progressBar_EDMed" );

    Dlg_MedicaTuxLayout->addWidget( progressBar_EDMed, 1, 0 );

    splitter3 = new QSplitter( this, "splitter3" );
    splitter3->setProperty( "orientation", "Horizontal" );

    QWidget* privateLayoutWidget = new QWidget( splitter3, "layout12" );
    layout12 = new QGridLayout( privateLayoutWidget, 1, 1, 11, 6, "layout12"); 

    layout16 = new QHBoxLayout( 0, 0, 6, "layout16"); 

    textLabel_CIP_Find = new QLabel( privateLayoutWidget, "textLabel_CIP_Find" );
    layout16->addWidget( textLabel_CIP_Find );

    lineEdit_EdMed__CIP_Find = new CMaskedLineEdit( privateLayoutWidget, "lineEdit_EdMed__CIP_Find" );
    lineEdit_EdMed__CIP_Find->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, lineEdit_EdMed__CIP_Find->sizePolicy().hasHeightForWidth() ) );
    lineEdit_EdMed__CIP_Find->setProperty( "maximumSize", QSize( 32767, 20 ) );
    lineEdit_EdMed__CIP_Find->setProperty( "carMask", 32 );
    layout16->addWidget( lineEdit_EdMed__CIP_Find );

    pushButton_CIP_Find = new QPushButton( privateLayoutWidget, "pushButton_CIP_Find" );
    layout16->addWidget( pushButton_CIP_Find );

    layout12->addLayout( layout16, 1, 0 );

    layout32 = new QVBoxLayout( 0, 0, 0, "layout32"); 

    checkBox_Dispo = new QCheckBox( privateLayoutWidget, "checkBox_Dispo" );
    checkBox_Dispo->setProperty( "checked", QVariant( TRUE, 0 ) );
    layout32->addWidget( checkBox_Dispo );

    checkBox_Generiques = new QCheckBox( privateLayoutWidget, "checkBox_Generiques" );
    layout32->addWidget( checkBox_Generiques );

    layout12->addLayout( layout32, 0, 0 );

    layout11 = new QGridLayout( 0, 1, 1, 0, 6, "layout11"); 

    pushButtonDown = new QPushButton( privateLayoutWidget, "pushButtonDown" );
    pushButtonDown->setProperty( "minimumSize", QSize( 2, 2 ) );
    pushButtonDown->setProperty( "maximumSize", QSize( 2, 2 ) );

    layout11->addWidget( pushButtonDown, 1, 0 );

    pushButtonDownProd = new QPushButton( privateLayoutWidget, "pushButtonDownProd" );
    pushButtonDownProd->setProperty( "minimumSize", QSize( 2, 2 ) );
    pushButtonDownProd->setProperty( "maximumSize", QSize( 2, 2 ) );

    layout11->addWidget( pushButtonDownProd, 1, 2 );

    comboBox_Specialites = new QComboBox( FALSE, privateLayoutWidget, "comboBox_Specialites" );
    comboBox_Specialites->setProperty( "maximumSize", QSize( 32767, 32767 ) );
    comboBox_Specialites->setProperty( "sizeLimit", 20 );

    layout11->addWidget( comboBox_Specialites, 1, 1 );

    tabWidgetSelect = new QTabWidget( privateLayoutWidget, "tabWidgetSelect" );

    tab = new QWidget( tabWidgetSelect, "tab" );
    tabLayout = new QGridLayout( tab, 1, 1, 0, 6, "tabLayout"); 

    comboBoxClassifications = new QComboBox( FALSE, tab, "comboBoxClassifications" );

    tabLayout->addWidget( comboBoxClassifications, 1, 0 );

    widgetStack_Classifications = new QWidgetStack( tab, "widgetStack_Classifications" );
    widgetStack_Classifications->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, widgetStack_Classifications->sizePolicy().hasHeightForWidth() ) );

    ATC = new QWidget( widgetStack_Classifications, "ATC" );
    ATCLayout = new QGridLayout( ATC, 1, 1, 0, 0, "ATCLayout"); 

    listView_EdMed_ATC = new QListView( ATC, "listView_EdMed_ATC" );
    listView_EdMed_ATC->addColumn( tr( "Classes ATC" ) );
    listView_EdMed_ATC->addColumn( tr( "Code ATC" ) );
    listView_EdMed_ATC->setProperty( "rootIsDecorated", QVariant( TRUE, 0 ) );

    ATCLayout->addWidget( listView_EdMed_ATC, 1, 0 );
    widgetStack_Classifications->addWidget( ATC, 0 );

    TherapVidal = new QWidget( widgetStack_Classifications, "TherapVidal" );
    TherapVidalLayout = new QGridLayout( TherapVidal, 1, 1, 0, 6, "TherapVidalLayout"); 

    listViewTherapClassVidal = new QListView( TherapVidal, "listViewTherapClassVidal" );
    listViewTherapClassVidal->addColumn( trUtf8( "\x43\x6c\x61\x73\x73\x65\x73\x20\x54\x68\xc3\xa9\x72\x61\x70\x65\x75\x74\x69\x71\x75"
    "\x65\x73\x20\x56\x69\x64\x61\x6c\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20" ) );
    listViewTherapClassVidal->addColumn( tr( "Code" ) );
    listViewTherapClassVidal->setProperty( "rootIsDecorated", QVariant( TRUE, 0 ) );

    TherapVidalLayout->addWidget( listViewTherapClassVidal, 0, 0 );
    widgetStack_Classifications->addWidget( TherapVidal, 1 );

    tabLayout->addWidget( widgetStack_Classifications, 2, 0 );

    lineEdit_Produit = new QLineEdit( tab, "lineEdit_Produit" );
    lineEdit_Produit->setProperty( "maximumSize", QSize( 32767, 32767 ) );
    lineEdit_Produit->setProperty( "frameShape", "LineEditPanel" );
    lineEdit_Produit->setProperty( "frameShadow", "Sunken" );

    tabLayout->addWidget( lineEdit_Produit, 0, 0 );
    tabWidgetSelect->insertTab( tab, QString::fromLatin1("") );

    tab_2 = new QWidget( tabWidgetSelect, "tab_2" );
    tabLayout_2 = new QGridLayout( tab_2, 1, 1, 11, 6, "tabLayout_2"); 

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    lineEdit_FindNomSubce = new QLineEdit( tab_2, "lineEdit_FindNomSubce" );
    lineEdit_FindNomSubce->setProperty( "frameShape", "LineEditPanel" );
    lineEdit_FindNomSubce->setProperty( "frameShadow", "Sunken" );
    layout6->addWidget( lineEdit_FindNomSubce );

    listView_Substance = new QListView( tab_2, "listView_Substance" );
    listView_Substance->addColumn( tr( "Substance (en minuscules)                                                 " ) );
    listView_Substance->addColumn( tr( "Code Sbce" ) );
    listView_Substance->setProperty( "rootIsDecorated", QVariant( FALSE, 0 ) );
    layout6->addWidget( listView_Substance );

    tabLayout_2->addLayout( layout6, 0, 0 );
    tabWidgetSelect->insertTab( tab_2, QString::fromLatin1("") );

    tab_3 = new QWidget( tabWidgetSelect, "tab_3" );
    tabLayout_3 = new QGridLayout( tab_3, 1, 1, 11, 6, "tabLayout_3"); 

    layout15 = new QVBoxLayout( 0, 0, 6, "layout15"); 

    lineEdit_Find_Indic = new QLineEdit( tab_3, "lineEdit_Find_Indic" );
    lineEdit_Find_Indic->setProperty( "frameShape", "LineEditPanel" );
    lineEdit_Find_Indic->setProperty( "frameShadow", "Sunken" );
    layout15->addWidget( lineEdit_Find_Indic );

    listView_IndicList = new QListView( tab_3, "listView_IndicList" );
    listView_IndicList->addColumn( tr( "Indications                                                 " ) );
    listView_IndicList->addColumn( tr( "Code_indic" ) );
    listView_IndicList->addColumn( tr( "Type" ) );
    listView_IndicList->setProperty( "rootIsDecorated", QVariant( FALSE, 0 ) );
    layout15->addWidget( listView_IndicList );

    tabLayout_3->addLayout( layout15, 0, 0 );
    tabWidgetSelect->insertTab( tab_3, QString::fromLatin1("") );

    layout11->addMultiCellWidget( tabWidgetSelect, 0, 0, 0, 1 );

    layout12->addLayout( layout11, 2, 0 );

    QWidget* privateLayoutWidget_2 = new QWidget( splitter3, "layout89" );
    layout89 = new QVBoxLayout( privateLayoutWidget_2, 11, 6, "layout89"); 

    textLabelLogo = new QLabel( privateLayoutWidget_2, "textLabelLogo" );
    textLabelLogo->setProperty( "paletteBackgroundColor", QColor( 255, 255, 255 ) );
    textLabelLogo->setProperty( "frameShape", "LineEditPanel" );
    textLabelLogo->setProperty( "lineWidth", 8 );
    textLabelLogo->setProperty( "scaledContents", QVariant( TRUE, 0 ) );
    layout89->addWidget( textLabelLogo );

    layout14 = new QHBoxLayout( 0, 0, 6, "layout14"); 

    pushButtonByPrincipe = new QPushButton( privateLayoutWidget_2, "pushButtonByPrincipe" );
    pushButtonByPrincipe->setProperty( "maximumSize", QSize( 32, 32767 ) );
    layout14->addWidget( pushButtonByPrincipe );
    spacer1 = new QSpacerItem( 55, 16, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout14->addItem( spacer1 );

    pushButtonByGenerique = new QPushButton( privateLayoutWidget_2, "pushButtonByGenerique" );
    pushButtonByGenerique->setProperty( "maximumSize", QSize( 32, 32767 ) );
    layout14->addWidget( pushButtonByGenerique );

    pushButtonByReferent = new QPushButton( privateLayoutWidget_2, "pushButtonByReferent" );
    pushButtonByReferent->setProperty( "maximumSize", QSize( 32, 32767 ) );
    layout14->addWidget( pushButtonByReferent );

    pushButtonByObsolete = new QPushButton( privateLayoutWidget_2, "pushButtonByObsolete" );
    pushButtonByObsolete->setProperty( "maximumSize", QSize( 32, 32767 ) );
    layout14->addWidget( pushButtonByObsolete );

    pushButtonByStandard = new QPushButton( privateLayoutWidget_2, "pushButtonByStandard" );
    pushButtonByStandard->setProperty( "maximumSize", QSize( 32, 32767 ) );
    layout14->addWidget( pushButtonByStandard );
    layout89->addLayout( layout14 );

    listView_Produits = new QListView( privateLayoutWidget_2, "listView_Produits" );
    listView_Produits->addColumn( tr( "Produit" ) );
    listView_Produits->addColumn( tr( "CodeProduit" ) );
    listView_Produits->addColumn( tr( "Pk_t00" ) );
    listView_Produits->addColumn( tr( "pk_t4b" ) );
    listView_Produits->addColumn( tr( "CodeCIP" ) );
    listView_Produits->addColumn( tr( "CodeUV" ) );
    listView_Produits->addColumn( tr( "IsG" ) );
    listView_Produits->addColumn( tr( "IsD" ) );
    listView_Produits->addColumn( tr( "num" ) );
    listView_Produits->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, listView_Produits->sizePolicy().hasHeightForWidth() ) );
    listView_Produits->setProperty( "maximumSize", QSize( 32767, 32767 ) );
    listView_Produits->setProperty( "resizePolicy", "Manual" );
    layout89->addWidget( listView_Produits );

    textLabel_Status = new QLabel( privateLayoutWidget_2, "textLabel_Status" );
    textLabel_Status->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)2, (QSizePolicy::SizeType)5, 0, 0, textLabel_Status->sizePolicy().hasHeightForWidth() ) );
    textLabel_Status->setProperty( "maximumSize", QSize( 32767, 25 ) );
    textLabel_Status->setProperty( "frameShape", "LineEditPanel" );
    textLabel_Status->setProperty( "frameShadow", "Plain" );
    layout89->addWidget( textLabel_Status );

    pushButtonQuit = new QPushButton( privateLayoutWidget_2, "pushButtonQuit" );
    layout89->addWidget( pushButtonQuit );

    tabWidget_Tables = new QTabWidget( splitter3, "tabWidget_Tables" );

    tab_4 = new QWidget( tabWidget_Tables, "tab_4" );
    tabLayout_4 = new QGridLayout( tab_4, 1, 1, 0, 1, "tabLayout_4"); 

    pushButtonEditPoso = new QPushButton( tab_4, "pushButtonEditPoso" );

    tabLayout_4->addWidget( pushButtonEditPoso, 1, 1 );

    splitter2 = new QSplitter( tab_4, "splitter2" );
    splitter2->setProperty( "orientation", "Vertical" );

    textBrowser_Posologies = new QTextBrowser( splitter2, "textBrowser_Posologies" );
    textBrowser_Posologies->setProperty( "paletteBackgroundColor", QColor( 106, 195, 170 ) );

    tabLayout_4->addMultiCellWidget( splitter2, 0, 0, 0, 1 );
    spacer3 = new QSpacerItem( 270, 16, QSizePolicy::Expanding, QSizePolicy::Minimum );
    tabLayout_4->addItem( spacer3, 1, 0 );
    tabWidget_Tables->insertTab( tab_4, QString::fromLatin1("") );

    tab_5 = new QWidget( tabWidget_Tables, "tab_5" );
    tabLayout_5 = new QGridLayout( tab_5, 1, 1, 0, 0, "tabLayout_5"); 

    textBrowser_Monographie = new QTextBrowser( tab_5, "textBrowser_Monographie" );
    QFont textBrowser_Monographie_font(  textBrowser_Monographie->font() );
    textBrowser_Monographie_font.setPointSize( 12 );
    textBrowser_Monographie->setFont( textBrowser_Monographie_font ); 

    tabLayout_5->addWidget( textBrowser_Monographie, 0, 0 );
    tabWidget_Tables->insertTab( tab_5, QString::fromLatin1("") );

    tab_6 = new QWidget( tabWidget_Tables, "tab_6" );
    tabLayout_6 = new QGridLayout( tab_6, 1, 1, 0, 0, "tabLayout_6"); 

    textBrowser_Prescription = new QTextBrowser( tab_6, "textBrowser_Prescription" );

    tabLayout_6->addWidget( textBrowser_Prescription, 1, 0 );

    layout10 = new QHBoxLayout( 0, 0, 6, "layout10"); 

    layout9 = new QVBoxLayout( 0, 0, 0, "layout9"); 

    textLabel_Poids = new QLabel( tab_6, "textLabel_Poids" );
    textLabel_Poids->setProperty( "minimumSize", QSize( 100, 0 ) );
    QFont textLabel_Poids_font(  textLabel_Poids->font() );
    textLabel_Poids->setFont( textLabel_Poids_font ); 
    textLabel_Poids->setProperty( "frameShape", "Panel" );
    textLabel_Poids->setProperty( "frameShadow", "Sunken" );
    layout9->addWidget( textLabel_Poids );

    textLabel_Taille = new QLabel( tab_6, "textLabel_Taille" );
    textLabel_Taille->setProperty( "minimumSize", QSize( 100, 0 ) );
    QFont textLabel_Taille_font(  textLabel_Taille->font() );
    textLabel_Taille->setFont( textLabel_Taille_font ); 
    textLabel_Taille->setProperty( "frameShape", "Panel" );
    textLabel_Taille->setProperty( "frameShadow", "Sunken" );
    layout9->addWidget( textLabel_Taille );
    layout10->addLayout( layout9 );
    spacer1_2 = new QSpacerItem( 16, 16, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout10->addItem( spacer1_2 );

    comboBoxPendant = new QComboBox( FALSE, tab_6, "comboBoxPendant" );
    QFont comboBoxPendant_font(  comboBoxPendant->font() );
    comboBoxPendant->setFont( comboBoxPendant_font ); 
    comboBoxPendant->setProperty( "editable", QVariant( TRUE, 0 ) );
    comboBoxPendant->setProperty( "sizeLimit", 18 );
    layout10->addWidget( comboBoxPendant );

    pushButtonALD_Off = new QPushButton( tab_6, "pushButtonALD_Off" );
    layout10->addWidget( pushButtonALD_Off );

    pushButtonALD = new QPushButton( tab_6, "pushButtonALD" );
    layout10->addWidget( pushButtonALD );

    pushButtonPrescErase = new QPushButton( tab_6, "pushButtonPrescErase" );
    pushButtonPrescErase->setProperty( "maximumSize", QSize( 32, 32767 ) );
    pushButtonPrescErase->setProperty( "iconSet", QIconSet( image0 ) );
    layout10->addWidget( pushButtonPrescErase );

    tabLayout_6->addLayout( layout10, 0, 0 );

    layout10_2 = new QHBoxLayout( 0, 0, 6, "layout10_2"); 
    spacer4 = new QSpacerItem( 201, 10, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout10_2->addItem( spacer4 );

    pushButton_Ok = new QPushButton( tab_6, "pushButton_Ok" );
    layout10_2->addWidget( pushButton_Ok );

    tabLayout_6->addLayout( layout10_2, 2, 0 );
    tabWidget_Tables->insertTab( tab_6, QString::fromLatin1("") );

    Dlg_MedicaTuxLayout->addWidget( splitter3, 0, 0 );
    languageChange();
    resize( QSize(996, 736).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( lineEdit_Produit, SIGNAL( textChanged(const QString&) ), this, SLOT( lineEdit_Produit_textChanged(const QString&) ) );
    connect( comboBoxClassifications, SIGNAL( activated(int) ), this, SLOT( comboBoxClassifications_activated(int) ) );
    connect( listView_Produits, SIGNAL( currentChanged(QListViewItem*) ), this, SLOT( listView_Produits_currentChanged(QListViewItem*) ) );
    connect( listView_Produits, SIGNAL( clicked(QListViewItem*) ), this, SLOT( listView_Produits_clicked(QListViewItem*) ) );
    connect( listViewTherapClassVidal, SIGNAL( clicked(QListViewItem*) ), this, SLOT( listViewTherapClassVidal_clicked(QListViewItem*) ) );
    connect( listView_EdMed_ATC, SIGNAL( clicked(QListViewItem*) ), this, SLOT( listView_EdMed_ATC_clicked(QListViewItem*) ) );
    connect( checkBox_Dispo, SIGNAL( stateChanged(int) ), this, SLOT( checkBox_Dispo_stateChanged(int) ) );
    connect( checkBox_Generiques, SIGNAL( stateChanged(int) ), this, SLOT( checkBox_Generiques_stateChanged(int) ) );
    connect( pushButtonByGenerique, SIGNAL( clicked() ), this, SLOT( pushButtonByGenerique_clicked() ) );
    connect( pushButtonByReferent, SIGNAL( clicked() ), this, SLOT( pushButtonByReferent_clicked() ) );
    connect( pushButtonByObsolete, SIGNAL( clicked() ), this, SLOT( pushButtonByObsolete_clicked() ) );
    connect( pushButtonByStandard, SIGNAL( clicked() ), this, SLOT( pushButtonByStandard_clicked() ) );
    connect( tabWidget_Tables, SIGNAL( currentChanged(QWidget*) ), this, SLOT( tabWidget_Tables_currentChanged(QWidget*) ) );
    connect( pushButton_CIP_Find, SIGNAL( clicked() ), this, SLOT( pushButton_CIP_Find_clicked() ) );
    connect( comboBox_Specialites, SIGNAL( activated(int) ), this, SLOT( comboBox_Specialites_activated(int) ) );
    connect( lineEdit_Find_Indic, SIGNAL( textChanged(const QString&) ), this, SLOT( lineEdit_Find_Indic_textChanged(const QString&) ) );
    connect( listView_IndicList, SIGNAL( clicked(QListViewItem*) ), this, SLOT( listView_IndicList_clicked(QListViewItem*) ) );
    connect( listView_Substance, SIGNAL( clicked(QListViewItem*) ), this, SLOT( listView_Substance_clicked(QListViewItem*) ) );
    connect( lineEdit_FindNomSubce, SIGNAL( textChanged(const QString&) ), this, SLOT( lineEdit_FindNomSubce_textChanged(const QString&) ) );
    connect( pushButtonByPrincipe, SIGNAL( clicked() ), this, SLOT( pushButtonByPrincipe_clicked() ) );
    connect( textBrowser_Posologies, SIGNAL( anchorClicked(const QString&,const QString&) ), this, SLOT( textBrowser_Posologies_anchorClicked(const QString&,const QString&) ) );
    connect( listView_Produits, SIGNAL( doubleClicked(QListViewItem*) ), this, SLOT( listView_Produits_doubleClicked(QListViewItem*) ) );
    connect( pushButtonPrescErase, SIGNAL( clicked() ), this, SLOT( pushButtonPrescErase_clicked() ) );
    connect( textBrowser_Prescription, SIGNAL( anchorClicked(const QString&,const QString&) ), this, SLOT( textBrowser_Prescription_anchorClicked(const QString&,const QString&) ) );
    connect( pushButtonEditPoso, SIGNAL( clicked() ), this, SLOT( pushButtonEditPoso_clicked() ) );
    connect( pushButton_Ok, SIGNAL( clicked() ), this, SLOT( pushButton_Ok_clicked() ) );
    connect( pushButtonALD_Off, SIGNAL( clicked() ), this, SLOT( pushButtonALD_Off_clicked() ) );
    connect( pushButtonALD, SIGNAL( clicked() ), this, SLOT( pushButtonALD_clicked() ) );
    connect( comboBoxPendant, SIGNAL( textChanged(const QString&) ), this, SLOT( comboBoxPendant_textChanged(const QString&) ) );
    connect( listView_Produits, SIGNAL( rightButtonClicked(QListViewItem*,const QPoint&,int) ), this, SLOT( listView_Produits_rightButtonClicked(QListViewItem*,const QPoint&,int) ) );
    connect( pushButtonQuit, SIGNAL( clicked() ), this, SLOT( close() ) );
    connect( pushButtonDown, SIGNAL( clicked() ), this, SLOT( pushButtonDown_clicked() ) );
    connect( comboBoxPendant, SIGNAL( activated(int) ), this, SLOT( comboBoxPendant_activated(int) ) );
    connect( pushButtonDownProd, SIGNAL( clicked() ), this, SLOT( pushButtonDownProd_clicked() ) );

    // tab order
    setTabOrder( checkBox_Dispo, checkBox_Generiques );
    setTabOrder( checkBox_Generiques, pushButton_CIP_Find );
    setTabOrder( pushButton_CIP_Find, tabWidgetSelect );
    setTabOrder( tabWidgetSelect, lineEdit_Produit );
    setTabOrder( lineEdit_Produit, comboBoxClassifications );
    setTabOrder( comboBoxClassifications, listViewTherapClassVidal );
    setTabOrder( listViewTherapClassVidal, comboBox_Specialites );
    setTabOrder( comboBox_Specialites, pushButtonByPrincipe );
    setTabOrder( pushButtonByPrincipe, pushButtonByGenerique );
    setTabOrder( pushButtonByGenerique, pushButtonByReferent );
    setTabOrder( pushButtonByReferent, pushButtonByObsolete );
    setTabOrder( pushButtonByObsolete, pushButtonByStandard );
    setTabOrder( pushButtonByStandard, listView_Produits );
    setTabOrder( listView_Produits, tabWidget_Tables );
    setTabOrder( tabWidget_Tables, comboBoxPendant );
    setTabOrder( comboBoxPendant, pushButtonALD_Off );
    setTabOrder( pushButtonALD_Off, pushButtonALD );
    setTabOrder( pushButtonALD, pushButtonPrescErase );
    setTabOrder( pushButtonPrescErase, textBrowser_Prescription );
    setTabOrder( textBrowser_Prescription, pushButton_Ok );
    setTabOrder( pushButton_Ok, listView_EdMed_ATC );
    setTabOrder( listView_EdMed_ATC, lineEdit_FindNomSubce );
    setTabOrder( lineEdit_FindNomSubce, listView_Substance );
    setTabOrder( listView_Substance, lineEdit_Find_Indic );
    setTabOrder( lineEdit_Find_Indic, listView_IndicList );
    setTabOrder( listView_IndicList, pushButtonEditPoso );
    setTabOrder( pushButtonEditPoso, textBrowser_Posologies );
    setTabOrder( textBrowser_Posologies, textBrowser_Monographie );
    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
Dlg_MedicaTux::~Dlg_MedicaTux()
{
    destroy();
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Dlg_MedicaTux::languageChange()
{
    setProperty( "caption", trUtf8( "\x54\x68\xc3\xa9\x72\x61\x70\x65\x75\x74\x69\x71\x75\x65" ) );
    textLabel_CIP_Find->setProperty( "text", tr( " CIP " ) );
    lineEdit_EdMed__CIP_Find->setProperty( "control", tr( "GGGGGGG" ) );
    lineEdit_EdMed__CIP_Find->setProperty( "mask", tr( "_______" ) );
    lineEdit_EdMed__CIP_Find->setProperty( "text", QString::null );
    pushButton_CIP_Find->setProperty( "text", tr( "&Chercher" ) );
    pushButton_CIP_Find->setProperty( "accel", QKeySequence( tr( "Alt+C" ) ) );
    checkBox_Dispo->setProperty( "text", tr( "Produits &disponibles seulement" ) );
    checkBox_Dispo->setProperty( "accel", QKeySequence( tr( "Alt+D" ) ) );
    checkBox_Generiques->setProperty( "text", trUtf8( "\x50\x72\x6f\x64\x75\x69\x74\x73\x20\x26\x67\xc3\xa9\x6e\xc3\xa9\x72\x69\x71\x75\x65"
    "\x73\x20\x73\x65\x75\x6c\x65\x6d\x65\x6e\x74" ) );
    checkBox_Generiques->setProperty( "accel", QKeySequence( tr( "Alt+G" ) ) );
    pushButtonDown->setProperty( "text", tr( "&w" ) );
    pushButtonDown->setProperty( "accel", QKeySequence( tr( "Alt+W" ) ) );
    pushButtonDownProd->setProperty( "text", tr( "&x" ) );
    pushButtonDownProd->setProperty( "accel", QKeySequence( tr( "Alt+X" ) ) );
    QToolTip::add( comboBox_Specialites, tr( "Les touches Alt + W  activent automatiquement les accessoires, et Alt + X  les produits." ) );
    comboBoxClassifications->clear();
    comboBoxClassifications->insertItem( tr( "Classes ATC" ) );
    comboBoxClassifications->insertItem( trUtf8( "\x43\x6c\x61\x73\x73\x65\x73\x20\x54\x68\xc3\xa9\x72\x61\x70\x65\x75\x74\x69\x71\x75"
    "\x65\x73\x20\x56\x69\x64\x61\x6c" ) );
    listView_EdMed_ATC->header()->setLabel( 0, tr( "Classes ATC" ) );
    listView_EdMed_ATC->header()->setLabel( 1, tr( "Code ATC" ) );
    listViewTherapClassVidal->header()->setLabel( 0, trUtf8( "\x43\x6c\x61\x73\x73\x65\x73\x20\x54\x68\xc3\xa9\x72\x61\x70\x65\x75\x74\x69\x71\x75"
    "\x65\x73\x20\x56\x69\x64\x61\x6c\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20" ) );
    listViewTherapClassVidal->header()->setLabel( 1, tr( "Code" ) );
    QToolTip::add( lineEdit_Produit, trUtf8( "\x53\xc3\xa9\x6c\x65\x63\x74\x69\x6f\x6e\x6e\x65\x72\x20\x75\x6e\x20\xc3\xa9\x6c\xc3"
    "\xa9\x6d\x65\x6e\x74\x20\x64\x65\x20\x6c\x61\x20\x6c\x69\x73\x74\x65\x20\x28\x25"
    "\x20\x70\x6f\x75\x72\x20\x70\x6f\x73\x69\x74\x69\x6f\x6e\x20\x76\x61\x72\x69\x61"
    "\x62\x6c\x65\x20\x64\x75\x20\x74\x65\x72\x6d\x65\x29" ) );
    tabWidgetSelect->changeTab( tab, tr( "Pr&oduits" ) );
    listView_Substance->header()->setLabel( 0, tr( "Substance (en minuscules)                                                 " ) );
    listView_Substance->header()->setLabel( 1, tr( "Code Sbce" ) );
    tabWidgetSelect->changeTab( tab_2, tr( "&Substance" ) );
    listView_IndicList->header()->setLabel( 0, tr( "Indications                                                 " ) );
    listView_IndicList->header()->setLabel( 1, tr( "Code_indic" ) );
    listView_IndicList->header()->setLabel( 2, tr( "Type" ) );
    tabWidgetSelect->changeTab( tab_3, tr( "&Indication" ) );
    textLabelLogo->setProperty( "text", QString::null );
    pushButtonByPrincipe->setProperty( "text", QString::null );
    QToolTip::add( pushButtonByPrincipe, trUtf8( "\x4c\x69\x73\x74\x65\x72\x20\x6c\x65\x73\x20\x73\x75\x62\x73\x74\x61\x6e\x63\x65\x73"
    "\x20\x64\x75\x20\x70\x72\x6f\x64\x75\x69\x74\x20\x73\xc3\xa9\x6c\x65\x63\x74\x69"
    "\x6f\x6e\x6e\xc3\xa9\x20\x64\x61\x6e\x73\x20\x6c\x61\x20\x6c\x69\x73\x74\x65" ) );
    pushButtonByGenerique->setProperty( "text", QString::null );
    QToolTip::add( pushButtonByGenerique, trUtf8( "\x54\x72\x69\x65\x72\x20\x70\x61\x72\x20\x6c\x65\x73\x20\x67\xc3\xa9\x6e\xc3\xa9\x72"
    "\x69\x71\x75\x65\x73" ) );
    pushButtonByReferent->setProperty( "text", QString::null );
    QToolTip::add( pushButtonByReferent, trUtf8( "\x54\x72\x69\x65\x72\x20\x70\x61\x72\x20\x6c\x65\x73\x20\x72\xc3\xa9\x66\xc3\xa9\x72"
    "\x65\x6e\x74\x73" ) );
    pushButtonByObsolete->setProperty( "text", QString::null );
    QToolTip::add( pushButtonByObsolete, tr( "Trier par les produits non disponibles" ) );
    pushButtonByStandard->setProperty( "text", QString::null );
    listView_Produits->header()->setLabel( 0, tr( "Produit" ) );
    listView_Produits->header()->setLabel( 1, tr( "CodeProduit" ) );
    listView_Produits->header()->setLabel( 2, tr( "Pk_t00" ) );
    listView_Produits->header()->setLabel( 3, tr( "pk_t4b" ) );
    listView_Produits->header()->setLabel( 4, tr( "CodeCIP" ) );
    listView_Produits->header()->setLabel( 5, tr( "CodeUV" ) );
    listView_Produits->header()->setLabel( 6, tr( "IsG" ) );
    listView_Produits->header()->setLabel( 7, tr( "IsD" ) );
    listView_Produits->header()->setLabel( 8, tr( "num" ) );
    QToolTip::add( listView_Produits, tr( "Double cliquez sur un produit pour afficher sa page de posologies" ) );
    pushButtonQuit->setProperty( "text", tr( "&Quitter" ) );
    pushButtonQuit->setProperty( "accel", QKeySequence( tr( "Alt+Q" ) ) );
    pushButtonEditPoso->setProperty( "text", tr( "Modifier les posologies" ) );
    tabWidget_Tables->changeTab( tab_4, tr( "&Posologies" ) );
    textBrowser_Monographie->setProperty( "text", tr( "<br><br><br><br><center><b>Les monographies ne sont disponibles qu'avec Vidal DataSemp</b></center>" ) );
    tabWidget_Tables->changeTab( tab_5, tr( "&Monographie" ) );
    textBrowser_Prescription->setProperty( "text", tr( "<br><br><br><br>\n"
"<center>Prescription vide</center><br><br><br><center>Veuillez choisir un produit dans la liste et valider une posologie dans l'onglet Posologies.</center>" ) );
    QToolTip::add( textLabel_Poids, trUtf8( "\x50\x6f\x69\x64\x73\x20\x64\x75\x20\x70\x61\x74\x69\x65\x6e\x74\x20\x65\x6e\x20\x4b"
    "\x67\x2c\x20\x73\x69\x20\x6e\x6f\x6e\x20\x72\x65\x6e\x73\x65\x69\x67\x6e\xc3\xa9"
    "\x20\x6c\x65\x20\x70\x6f\x69\x64\x73\x20\x64\x65\x20\x37\x30\x20\x6b\x67\x20\x65"
    "\x73\x74\x20\x75\x74\x69\x6c\x69\x73\xc3\xa9" ) );
    QToolTip::add( textLabel_Taille, trUtf8( "\x54\x61\x69\x6c\x6c\x65\x20\x64\x75\x20\x70\x61\x74\x69\x65\x6e\x74\x20\x28\x73\x69"
    "\x20\x6e\x6f\x6e\x20\x72\x65\x6e\x73\x65\x69\x67\x6e\xc3\xa9\x65\x20\x65\x6c\x6c"
    "\x65\x20\x65\x73\x74\x20\x64\xc3\xa9\x64\x75\x69\x74\x65\x20\x64\x65\x20\x6c\x61"
    "\x20\x66\x6f\x72\x6d\x75\x6c\x65\x20\x64\x65\x20\x4c\x6f\x72\x65\x6e\x74\x7a\x29"
    "" ) );
    comboBoxPendant->clear();
    comboBoxPendant->insertItem( tr( "(vide)" ) );
    comboBoxPendant->insertItem( tr( "1 jour" ) );
    comboBoxPendant->insertItem( tr( "2 jours" ) );
    comboBoxPendant->insertItem( tr( "3 jours" ) );
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
    pushButtonALD_Off->setProperty( "text", tr( "&Non ALD" ) );
    pushButtonALD_Off->setProperty( "accel", QKeySequence( tr( "Alt+N" ) ) );
    pushButtonALD->setProperty( "text", tr( "&Tout ALD" ) );
    pushButtonALD->setProperty( "accel", QKeySequence( tr( "Alt+T" ) ) );
    pushButtonPrescErase->setProperty( "text", QString::null );
    QToolTip::add( pushButtonPrescErase, tr( "Effacer cette prescription" ) );
    pushButton_Ok->setProperty( "text", tr( "&Valider cette prescription" ) );
    pushButton_Ok->setProperty( "accel", QKeySequence( tr( "Alt+V" ) ) );
    tabWidget_Tables->changeTab( tab_6, tr( "P&rescription" ) );
}

