/****************************************************************************
** Form implementation generated from reading ui file 'DlgListFieldMngr.ui'
**
** Created: mer. mai 4 22:19:07 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "DlgListFieldMngr.h"

#include <qvariant.h>
#include <qfontdatabase.h>
#include <qcolordialog.h>
#include <qmessagebox.h>
#include <qcursor.h>
#include <qfiledialog.h>
#include <qtimer.h>
#include <qpushbutton.h>
#include <qsplitter.h>
#include <qlineedit.h>
#include <qheader.h>
#include <qlistview.h>
#include <qbuttongroup.h>
#include <qcombobox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "../../MedinTuxTools/CHtmlTools.h"
#include "CPreview.h"
#include "../../MedinTuxTools/CGenTools.h"
#include "ui/DlgListOff_Listes.h"
#include "../../MedinTuxTools/CGestIni.h"
#include "ui/DLG_InsertList.h"
#include "../../MedinTuxTools/CW_EditText.h"
#include "../DlgListFieldMngr.ui.h"
static const unsigned char image0_data[] = { 
    0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d,
    0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x18,
    0x08, 0x06, 0x00, 0x00, 0x00, 0xe0, 0x77, 0x3d, 0xf8, 0x00, 0x00, 0x01,
    0x2c, 0x49, 0x44, 0x41, 0x54, 0x48, 0x89, 0xed, 0x95, 0xa1, 0x4b, 0x43,
    0x51, 0x14, 0xc6, 0x7f, 0x67, 0x4e, 0xa6, 0x41, 0x59, 0x1e, 0xe8, 0x4c,
    0x16, 0xb1, 0x99, 0x5e, 0x18, 0x16, 0x93, 0xcd, 0x22, 0xea, 0xd2, 0x92,
    0x41, 0xf0, 0x2f, 0xb0, 0x1b, 0x95, 0x05, 0x93, 0xb3, 0x0c, 0x4c, 0x5a,
    0x64, 0xcb, 0x62, 0xb8, 0x18, 0x16, 0xdc, 0x8b, 0x32, 0xd8, 0x43, 0x51,
    0x83, 0x63, 0x2c, 0xac, 0x3c, 0x78, 0xbc, 0xbb, 0x20, 0x7b, 0x38, 0xd9,
    0x1b, 0xf7, 0xe1, 0x7b, 0x82, 0xe2, 0x89, 0x27, 0x7c, 0xbf, 0x73, 0xef,
    0xf7, 0xdd, 0x73, 0x45, 0x29, 0x45, 0x92, 0x95, 0x4a, 0x54, 0xfd, 0x27,
    0x00, 0xe9, 0x71, 0x4d, 0xcb, 0xb2, 0xf4, 0x77, 0x85, 0x95, 0x52, 0x12,
    0x0a, 0x00, 0xf0, 0x3c, 0x8f, 0x7e, 0xff, 0x8d, 0x4c, 0x66, 0xde, 0x58,
    0xd4, 0xf7, 0x3d, 0x3a, 0x9d, 0x57, 0xf2, 0xf9, 0xd5, 0xa0, 0x37, 0x01,
    0xe0, 0xd2, 0x6a, 0xd5, 0x80, 0x28, 0x87, 0x11, 0xda, 0xed, 0xd1, 0x5b,
    0x0f, 0x05, 0x74, 0xbb, 0x2f, 0xd8, 0xb6, 0x8b, 0xd6, 0xe6, 0x00, 0x11,
    0xc1, 0x71, 0xde, 0xcd, 0x00, 0xb9, 0xdc, 0xb2, 0xb1, 0xf0, 0x44, 0x68,
    0xd2, 0xef, 0xe0, 0x3f, 0x45, 0x5f, 0xea, 0x2f, 0xa6, 0x28, 0x00, 0x7c,
    0x36, 0x76, 0x68, 0x50, 0xac, 0x00, 0x80, 0xf2, 0xf6, 0x0a, 0x07, 0xfb,
    0x6b, 0x48, 0xdc, 0x29, 0x1a, 0x4e, 0x3f, 0x35, 0x9d, 0x82, 0xd9, 0x34,
    0xba, 0xb6, 0x83, 0x6c, 0x5e, 0xd2, 0xeb, 0x3d, 0xc7, 0x93, 0xa2, 0xad,
    0xc2, 0x22, 0x57, 0xc7, 0x1b, 0x1f, 0xcb, 0xdb, 0xd7, 0x30, 0x37, 0x83,
    0xae, 0xef, 0x22, 0xd9, 0x05, 0x1a, 0x8d, 0xb3, 0x08, 0x73, 0x87, 0xa4,
    0xe8, 0xfa, 0xee, 0x09, 0xb1, 0xce, 0xa9, 0xae, 0x2f, 0xb1, 0x77, 0x54,
    0x80, 0x9b, 0x47, 0xe4, 0xe4, 0x9e, 0x4a, 0xe5, 0x94, 0x66, 0xd3, 0x35,
    0x97, 0x0f, 0x4b, 0x91, 0x52, 0x4a, 0x02, 0x93, 0x2f, 0x1e, 0x90, 0xaa,
    0x0d, 0x40, 0xa9, 0x74, 0x18, 0x61, 0xfa, 0xf1, 0x35, 0x62, 0x72, 0xf1,
    0xd6, 0xa1, 0x48, 0xbc, 0x29, 0x4a, 0x7c, 0xd9, 0xfd, 0xfe, 0x4f, 0x7f,
    0x00, 0x6a, 0xfc, 0x8c, 0x5d, 0x89, 0xe8, 0x8b, 0xb9, 0x00, 0x00, 0x00,
    0x00, 0x49, 0x45, 0x4e, 0x44, 0xae, 0x42, 0x60, 0x82
};


/*
 *  Constructs a FormDlgListFieldMngr as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
FormDlgListFieldMngr::FormDlgListFieldMngr( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    QImage img;
    img.loadFromData( image0_data, sizeof( image0_data ), "PNG" );
    image0 = img;
    if ( !name )
	setProperty( "name", "FormDlgListFieldMngr" );
    setProperty( "icon", image0 );
    FormDlgListFieldMngrLayout = new QGridLayout( this, 1, 1, 2, 6, "FormDlgListFieldMngrLayout"); 

    splitterMedian = new QSplitter( this, "splitterMedian" );
    splitterMedian->setProperty( "orientation", "Horizontal" );

    QWidget* privateLayoutWidget = new QWidget( splitterMedian, "layout6" );
    layout6 = new QGridLayout( privateLayoutWidget, 1, 1, 11, 6, "layout6"); 

    lineEditFindItem = new QLineEdit( privateLayoutWidget, "lineEditFindItem" );
    lineEditFindItem->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, lineEditFindItem->sizePolicy().hasHeightForWidth() ) );
    lineEditFindItem->setProperty( "maximumSize", QSize( 32767, 32767 ) );
    lineEditFindItem->setProperty( "frameShape", "LineEditPanel" );
    lineEditFindItem->setProperty( "frameShadow", "Sunken" );

    layout6->addWidget( lineEditFindItem, 0, 0 );

    listViewList = new QListView( privateLayoutWidget, "listViewList" );
    listViewList->addColumn( tr( "Listes d'insertion                                                     " ) );
    listViewList->addColumn( tr( "Typ" ) );
    listViewList->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)7, 0, 0, listViewList->sizePolicy().hasHeightForWidth() ) );
    listViewList->setProperty( "maximumSize", QSize( 32767, 32767 ) );
    listViewList->setProperty( "rootIsDecorated", QVariant( TRUE, 0 ) );

    layout6->addWidget( listViewList, 1, 0 );

    QWidget* privateLayoutWidget_2 = new QWidget( splitterMedian, "layout8" );
    layout8 = new QGridLayout( privateLayoutWidget_2, 1, 1, 11, 6, "layout8"); 

    layout6_2 = new QGridLayout( 0, 1, 1, 0, 6, "layout6_2"); 

    buttonGroupJustif = new QButtonGroup( privateLayoutWidget_2, "buttonGroupJustif" );
    buttonGroupJustif->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, buttonGroupJustif->sizePolicy().hasHeightForWidth() ) );
    buttonGroupJustif->setProperty( "maximumSize", QSize( 32767, 40 ) );
    buttonGroupJustif->setProperty( "frameShape", "MenuBarPanel" );
    buttonGroupJustif->setProperty( "frameShadow", "Raised" );
    buttonGroupJustif->setProperty( "lineWidth", 0 );
    buttonGroupJustif->setProperty( "margin", 0 );
    buttonGroupJustif->setProperty( "midLineWidth", 0 );
    buttonGroupJustif->setProperty( "alignment", int( QButtonGroup::AlignVCenter ) );
    buttonGroupJustif->setProperty( "flat", QVariant( FALSE, 0 ) );
    buttonGroupJustif->setColumnLayout(0, Qt::Vertical );
    buttonGroupJustif->layout()->setSpacing( 1 );
    buttonGroupJustif->layout()->setMargin( 2 );
    buttonGroupJustifLayout = new QGridLayout( buttonGroupJustif->layout() );
    buttonGroupJustifLayout->setAlignment( Qt::AlignTop );

    pushButtonRight = new QPushButton( buttonGroupJustif, "pushButtonRight" );
    pushButtonRight->setProperty( "minimumSize", QSize( 32, 32 ) );
    pushButtonRight->setProperty( "maximumSize", QSize( 32, 32 ) );
    pushButtonRight->setProperty( "toggleButton", QVariant( TRUE, 0 ) );
    pushButtonRight->setProperty( "flat", QVariant( TRUE, 0 ) );
    buttonGroupJustif->insert( pushButtonRight, 2 );

    buttonGroupJustifLayout->addWidget( pushButtonRight, 0, 2 );

    pushButtonCenter = new QPushButton( buttonGroupJustif, "pushButtonCenter" );
    pushButtonCenter->setProperty( "minimumSize", QSize( 32, 32 ) );
    pushButtonCenter->setProperty( "maximumSize", QSize( 32, 32 ) );
    pushButtonCenter->setProperty( "toggleButton", QVariant( TRUE, 0 ) );
    pushButtonCenter->setProperty( "flat", QVariant( TRUE, 0 ) );
    buttonGroupJustif->insert( pushButtonCenter, 1 );

    buttonGroupJustifLayout->addWidget( pushButtonCenter, 0, 1 );

    pushButtonLeft = new QPushButton( buttonGroupJustif, "pushButtonLeft" );
    pushButtonLeft->setProperty( "minimumSize", QSize( 32, 32 ) );
    pushButtonLeft->setProperty( "maximumSize", QSize( 32, 32 ) );
    pushButtonLeft->setProperty( "toggleButton", QVariant( TRUE, 0 ) );
    pushButtonLeft->setProperty( "flat", QVariant( TRUE, 0 ) );
    buttonGroupJustif->insert( pushButtonLeft, 0 );

    buttonGroupJustifLayout->addWidget( pushButtonLeft, 0, 0 );

    layout6_2->addWidget( buttonGroupJustif, 0, 1 );

    buttonGroupTools = new QButtonGroup( privateLayoutWidget_2, "buttonGroupTools" );
    buttonGroupTools->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, buttonGroupTools->sizePolicy().hasHeightForWidth() ) );
    buttonGroupTools->setProperty( "maximumSize", QSize( 32767, 40 ) );
    buttonGroupTools->setProperty( "frameShape", "MenuBarPanel" );
    buttonGroupTools->setProperty( "frameShadow", "Raised" );
    buttonGroupTools->setProperty( "lineWidth", 0 );
    buttonGroupTools->setProperty( "margin", 0 );
    buttonGroupTools->setProperty( "midLineWidth", 0 );
    buttonGroupTools->setProperty( "alignment", int( QButtonGroup::AlignTop ) );
    buttonGroupTools->setProperty( "flat", QVariant( FALSE, 0 ) );
    buttonGroupTools->setProperty( "radioButtonExclusive", QVariant( FALSE, 0 ) );
    buttonGroupTools->setColumnLayout(0, Qt::Vertical );
    buttonGroupTools->layout()->setSpacing( 1 );
    buttonGroupTools->layout()->setMargin( 2 );
    buttonGroupToolsLayout = new QGridLayout( buttonGroupTools->layout() );
    buttonGroupToolsLayout->setAlignment( Qt::AlignTop );

    pushButtonSave = new QPushButton( buttonGroupTools, "pushButtonSave" );
    pushButtonSave->setProperty( "minimumSize", QSize( 32, 32 ) );
    pushButtonSave->setProperty( "maximumSize", QSize( 32, 32 ) );

    buttonGroupToolsLayout->addWidget( pushButtonSave, 0, 0 );

    pushButtonSetMasque = new QPushButton( buttonGroupTools, "pushButtonSetMasque" );
    pushButtonSetMasque->setProperty( "minimumSize", QSize( 32, 32 ) );
    pushButtonSetMasque->setProperty( "maximumSize", QSize( 32, 32 ) );

    buttonGroupToolsLayout->addWidget( pushButtonSetMasque, 0, 1 );

    pushButtonImportMenu = new QPushButton( buttonGroupTools, "pushButtonImportMenu" );
    pushButtonImportMenu->setProperty( "minimumSize", QSize( 32, 32 ) );
    pushButtonImportMenu->setProperty( "maximumSize", QSize( 32, 32767 ) );

    buttonGroupToolsLayout->addWidget( pushButtonImportMenu, 0, 2 );

    pushButtonImportMenuLocalize = new QPushButton( buttonGroupTools, "pushButtonImportMenuLocalize" );
    pushButtonImportMenuLocalize->setProperty( "minimumSize", QSize( 32, 32 ) );
    pushButtonImportMenuLocalize->setProperty( "maximumSize", QSize( 32, 32 ) );
    pushButtonImportMenuLocalize->setProperty( "toggleButton", QVariant( FALSE, 0 ) );
    pushButtonImportMenuLocalize->setProperty( "autoDefault", QVariant( FALSE, 0 ) );
    pushButtonImportMenuLocalize->setProperty( "flat", QVariant( TRUE, 0 ) );

    buttonGroupToolsLayout->addWidget( pushButtonImportMenuLocalize, 0, 3 );

    pushButtonSetTextField = new QPushButton( buttonGroupTools, "pushButtonSetTextField" );
    pushButtonSetTextField->setProperty( "minimumSize", QSize( 32, 32 ) );
    pushButtonSetTextField->setProperty( "maximumSize", QSize( 32, 32767 ) );

    buttonGroupToolsLayout->addWidget( pushButtonSetTextField, 0, 4 );

    pushButtonColor = new QPushButton( buttonGroupTools, "pushButtonColor" );
    pushButtonColor->setProperty( "minimumSize", QSize( 32, 32 ) );
    pushButtonColor->setProperty( "maximumSize", QSize( 32, 32 ) );
    QFont pushButtonColor_font(  pushButtonColor->font() );
    pushButtonColor_font.setBold( TRUE );
    pushButtonColor->setFont( pushButtonColor_font ); 
    pushButtonColor->setProperty( "flat", QVariant( FALSE, 0 ) );

    buttonGroupToolsLayout->addWidget( pushButtonColor, 0, 9 );

    pushButtonUnderline = new QPushButton( buttonGroupTools, "pushButtonUnderline" );
    pushButtonUnderline->setProperty( "minimumSize", QSize( 32, 32 ) );
    pushButtonUnderline->setProperty( "maximumSize", QSize( 32, 32 ) );
    pushButtonUnderline->setProperty( "toggleButton", QVariant( TRUE, 0 ) );
    pushButtonUnderline->setProperty( "autoDefault", QVariant( FALSE, 0 ) );
    pushButtonUnderline->setProperty( "flat", QVariant( TRUE, 0 ) );

    buttonGroupToolsLayout->addWidget( pushButtonUnderline, 0, 8 );

    pushButtonItalique = new QPushButton( buttonGroupTools, "pushButtonItalique" );
    pushButtonItalique->setProperty( "minimumSize", QSize( 32, 32 ) );
    pushButtonItalique->setProperty( "maximumSize", QSize( 32, 32 ) );
    pushButtonItalique->setProperty( "toggleButton", QVariant( TRUE, 0 ) );
    pushButtonItalique->setProperty( "autoDefault", QVariant( FALSE, 0 ) );
    pushButtonItalique->setProperty( "flat", QVariant( TRUE, 0 ) );

    buttonGroupToolsLayout->addWidget( pushButtonItalique, 0, 7 );

    pushButtonBold = new QPushButton( buttonGroupTools, "pushButtonBold" );
    pushButtonBold->setProperty( "minimumSize", QSize( 32, 32 ) );
    pushButtonBold->setProperty( "maximumSize", QSize( 32, 32 ) );
    pushButtonBold->setProperty( "toggleButton", QVariant( TRUE, 0 ) );
    pushButtonBold->setProperty( "autoDefault", QVariant( FALSE, 0 ) );
    pushButtonBold->setProperty( "flat", QVariant( TRUE, 0 ) );

    buttonGroupToolsLayout->addWidget( pushButtonBold, 0, 6 );

    pushButton_InsertImage = new QPushButton( buttonGroupTools, "pushButton_InsertImage" );
    pushButton_InsertImage->setProperty( "minimumSize", QSize( 32, 32 ) );
    pushButton_InsertImage->setProperty( "maximumSize", QSize( 32, 32 ) );
    pushButton_InsertImage->setProperty( "toggleButton", QVariant( FALSE, 0 ) );
    pushButton_InsertImage->setProperty( "autoDefault", QVariant( FALSE, 0 ) );
    pushButton_InsertImage->setProperty( "flat", QVariant( TRUE, 0 ) );

    buttonGroupToolsLayout->addWidget( pushButton_InsertImage, 0, 5 );

    layout6_2->addWidget( buttonGroupTools, 0, 0 );

    layout8->addMultiCellLayout( layout6_2, 0, 0, 0, 1 );

    comboBoxSize = new QComboBox( FALSE, privateLayoutWidget_2, "comboBoxSize" );
    comboBoxSize->setProperty( "maximumSize", QSize( 100, 32767 ) );
    QFont comboBoxSize_font(  comboBoxSize->font() );
    comboBoxSize->setFont( comboBoxSize_font ); 
    comboBoxSize->setProperty( "editable", QVariant( TRUE, 0 ) );

    layout8->addWidget( comboBoxSize, 1, 0 );

    layout11 = new QGridLayout( 0, 1, 1, 0, 6, "layout11"); 
    spacer2_2 = new QSpacerItem( 180, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout11->addItem( spacer2_2, 0, 0 );

    pushButton_Quitter = new QPushButton( privateLayoutWidget_2, "pushButton_Quitter" );

    layout11->addWidget( pushButton_Quitter, 0, 2 );

    pushButton_Ok = new QPushButton( privateLayoutWidget_2, "pushButton_Ok" );

    layout11->addWidget( pushButton_Ok, 0, 1 );

    layout8->addMultiCellLayout( layout11, 3, 3, 0, 1 );

    comboBoxFont = new QComboBox( FALSE, privateLayoutWidget_2, "comboBoxFont" );
    comboBoxFont->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)4, 0, 0, comboBoxFont->sizePolicy().hasHeightForWidth() ) );
    QFont comboBoxFont_font(  comboBoxFont->font() );
    comboBoxFont->setFont( comboBoxFont_font ); 
    comboBoxFont->setProperty( "editable", QVariant( TRUE, 0 ) );

    layout8->addWidget( comboBoxFont, 1, 1 );

    textEditField = new CW_EditText( privateLayoutWidget_2, "textEditField" );
    textEditField->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)2, (QSizePolicy::SizeType)7, 0, 0, textEditField->sizePolicy().hasHeightForWidth() ) );

    layout8->addMultiCellWidget( textEditField, 2, 2, 0, 1 );

    FormDlgListFieldMngrLayout->addWidget( splitterMedian, 0, 0 );
    languageChange();
    resize( QSize(945, 688).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // tab order
    setTabOrder( lineEditFindItem, listViewList );
    setTabOrder( listViewList, pushButtonSave );
    setTabOrder( pushButtonSave, pushButtonSetMasque );
    setTabOrder( pushButtonSetMasque, pushButton_InsertImage );
    setTabOrder( pushButton_InsertImage, pushButtonBold );
    setTabOrder( pushButtonBold, pushButtonItalique );
    setTabOrder( pushButtonItalique, pushButtonUnderline );
    setTabOrder( pushButtonUnderline, pushButtonLeft );
    setTabOrder( pushButtonLeft, pushButtonCenter );
    setTabOrder( pushButtonCenter, pushButtonRight );
    setTabOrder( pushButtonRight, pushButtonColor );
    setTabOrder( pushButtonColor, comboBoxFont );
    setTabOrder( comboBoxFont, comboBoxSize );
    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
FormDlgListFieldMngr::~FormDlgListFieldMngr()
{
    destroy();
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void FormDlgListFieldMngr::languageChange()
{
    setProperty( "caption", trUtf8( "\x47\x65\x73\x74\x69\x6f\x6e\x6e\x61\x69\x72\x65\x20\x64\x65\x20\x6c\x69\x73\x74\x65"
    "\x73\x20\x64\xc3\xa9\x72\x6f\x75\x6c\x61\x6e\x74\x65\x73" ) );
    QWhatsThis::add( this, QString::null );
    QWhatsThis::add( lineEditFindItem, trUtf8( "\x45\x6e\x74\x72\x65\x7a\x20\x6c\x65\x20\x6e\x6f\x6d\x20\x64\x27\x75\x6e\x65\x20\x6c"
    "\x69\x73\x74\x65\x20\x64\xc3\xa9\x72\x6f\x75\x6c\x61\x6e\x74\x65\x20\xc3\xa0\x20"
    "\x6d\x6f\x64\x69\x66\x69\x65\x72" ) );
    listViewList->header()->setLabel( 0, tr( "Listes d'insertion                                                     " ) );
    listViewList->header()->setLabel( 1, tr( "Typ" ) );
    buttonGroupJustif->setProperty( "title", QString::null );
    pushButtonRight->setProperty( "text", QString::null );
    pushButtonCenter->setProperty( "text", QString::null );
    pushButtonLeft->setProperty( "text", QString::null );
    buttonGroupTools->setProperty( "title", QString::null );
    pushButtonSave->setProperty( "text", QString::null );
    pushButtonSave->setProperty( "accel", QKeySequence( tr( "Ctrl+S" ) ) );
    QToolTip::add( pushButtonSave, tr( "Enregistrer les modifications" ) );
    pushButtonSetMasque->setProperty( "text", QString::null );
    pushButtonSetMasque->setProperty( "accel", QKeySequence( QString::null ) );
    pushButtonImportMenu->setProperty( "text", QString::null );
    pushButtonImportMenu->setProperty( "accel", QKeySequence( QString::null ) );
    QToolTip::add( pushButtonImportMenu, tr( "Gestion des librairies de menus, Importer un module de menu." ) );
    pushButtonImportMenuLocalize->setProperty( "text", QString::null );
    QToolTip::add( pushButtonImportMenuLocalize, trUtf8( "\x4c\x6f\x63\x61\x6c\x69\x73\x65\x72\x20\x6c\x61\x20\x62\x69\x62\x6c\x69\x6f\x74\x68"
    "\xc3\xa8\x71\x75\x65\x20\x64\x65\x20\x6d\x6f\x64\x75\x6c\x65\x73\x20\x64\x65\x20"
    "\x6d\x65\x6e\x75\x73" ) );
    pushButtonSetTextField->setProperty( "text", QString::null );
    pushButtonSetTextField->setProperty( "accel", QKeySequence( QString::null ) );
    pushButtonColor->setProperty( "text", tr( "O" ) );
    pushButtonUnderline->setProperty( "text", QString::null );
    pushButtonItalique->setProperty( "text", QString::null );
    pushButtonBold->setProperty( "text", QString::null );
    pushButton_InsertImage->setProperty( "text", QString::null );
    pushButton_Quitter->setProperty( "text", tr( "&Quitter" ) );
    pushButton_Quitter->setProperty( "accel", QKeySequence( tr( "Alt+Q" ) ) );
    pushButton_Ok->setProperty( "text", tr( "Confirmer" ) );
    QToolTip::add( comboBoxFont, QString::null );
}

