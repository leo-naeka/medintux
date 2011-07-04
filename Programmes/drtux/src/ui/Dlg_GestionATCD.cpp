/****************************************************************************
** Form implementation generated from reading ui file 'Dlg_GestionATCD.ui'
**
** Created: mer. mai 4 22:19:18 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "Dlg_GestionATCD.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qsplitter.h>
#include <qtabwidget.h>
#include <qwidget.h>
#include <qheader.h>
#include <qlistview.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qframe.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "../Dlg_GestionATCD.ui.h"

/*
 *  Constructs a Dlg_GestionATCD as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
Dlg_GestionATCD::Dlg_GestionATCD( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setProperty( "name", "Dlg_GestionATCD" );
    setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)1, 0, 0, sizePolicy().hasHeightForWidth() ) );
    setProperty( "sizeGripEnabled", QVariant( TRUE, 0 ) );
    setProperty( "modal", QVariant( FALSE, 0 ) );
    Dlg_GestionATCDLayout = new QGridLayout( this, 1, 1, 15, 0, "Dlg_GestionATCDLayout"); 

    splitter5 = new QSplitter( this, "splitter5" );
    splitter5->setProperty( "orientation", "Horizontal" );

    QWidget* privateLayoutWidget = new QWidget( splitter5, "layout13" );
    layout13 = new QGridLayout( privateLayoutWidget, 1, 1, 0, 2, "layout13"); 

    tabWidgetDicoATCD = new QTabWidget( privateLayoutWidget, "tabWidgetDicoATCD" );
    tabWidgetDicoATCD->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)7, 0, 0, tabWidgetDicoATCD->sizePolicy().hasHeightForWidth() ) );
    tabWidgetDicoATCD->setProperty( "maximumSize", QSize( 32767, 32767 ) );
    tabWidgetDicoATCD->setProperty( "tabShape", "Rounded" );

    CIM_10 = new QWidget( tabWidgetDicoATCD, "CIM_10" );
    CIM_10Layout = new QGridLayout( CIM_10, 1, 1, 0, 0, "CIM_10Layout"); 

    listViewCim10_Libelles = new QListView( CIM_10, "listViewCim10_Libelles" );
    listViewCim10_Libelles->addColumn( trUtf8( "\x4c\x69\x62\x65\x6c\x6c\xc3\xa9\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20" ) );
    listViewCim10_Libelles->addColumn( tr( "Code" ) );
    listViewCim10_Libelles->addColumn( tr( "SID" ) );
    listViewCim10_Libelles->setProperty( "rootIsDecorated", QVariant( FALSE, 0 ) );

    CIM_10Layout->addWidget( listViewCim10_Libelles, 2, 0 );

    layout7 = new QGridLayout( 0, 1, 1, 0, 6, "layout7"); 

    textLabel3_2 = new QLabel( CIM_10, "textLabel3_2" );
    textLabel3_2->setProperty( "minimumSize", QSize( 100, 0 ) );

    layout7->addWidget( textLabel3_2, 0, 0 );

    lineEditAutolcatorLibelle = new QLineEdit( CIM_10, "lineEditAutolcatorLibelle" );
    lineEditAutolcatorLibelle->setProperty( "frameShape", "LineEditPanel" );
    lineEditAutolcatorLibelle->setProperty( "frameShadow", "Sunken" );

    layout7->addWidget( lineEditAutolcatorLibelle, 0, 1 );

    CIM_10Layout->addLayout( layout7, 0, 0 );

    layout8 = new QGridLayout( 0, 1, 1, 0, 6, "layout8"); 

    textLabel3_3 = new QLabel( CIM_10, "textLabel3_3" );
    textLabel3_3->setProperty( "minimumSize", QSize( 100, 0 ) );

    layout8->addWidget( textLabel3_3, 0, 0 );

    lineEditAutolcatorLibelle_2 = new QLineEdit( CIM_10, "lineEditAutolcatorLibelle_2" );
    lineEditAutolcatorLibelle_2->setProperty( "frameShape", "LineEditPanel" );
    lineEditAutolcatorLibelle_2->setProperty( "frameShadow", "Sunken" );

    layout8->addWidget( lineEditAutolcatorLibelle_2, 0, 1 );

    CIM_10Layout->addLayout( layout8, 1, 0 );
    tabWidgetDicoATCD->insertTab( CIM_10, QString::fromLatin1("") );

    CIM10_Chapitre = new QWidget( tabWidgetDicoATCD, "CIM10_Chapitre" );
    CIM10_ChapitreLayout = new QGridLayout( CIM10_Chapitre, 1, 1, 0, 0, "CIM10_ChapitreLayout"); 

    listViewCim10_rubriques = new QListView( CIM10_Chapitre, "listViewCim10_rubriques" );
    listViewCim10_rubriques->addColumn( trUtf8( "\x4c\x69\x62\x65\x6c\x6c\xc3\xa9\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20" ) );
    listViewCim10_rubriques->addColumn( tr( "Code" ) );
    listViewCim10_rubriques->addColumn( tr( "SID" ) );
    listViewCim10_rubriques->setProperty( "rootIsDecorated", QVariant( TRUE, 0 ) );

    CIM10_ChapitreLayout->addWidget( listViewCim10_rubriques, 0, 0 );
    tabWidgetDicoATCD->insertTab( CIM10_Chapitre, QString::fromLatin1("") );

    Allergie = new QWidget( tabWidgetDicoATCD, "Allergie" );
    AllergieLayout = new QGridLayout( Allergie, 1, 1, 0, 0, "AllergieLayout"); 

    textLabelStatut = new QLabel( Allergie, "textLabelStatut" );
    textLabelStatut->setProperty( "frameShape", "MenuBarPanel" );

    AllergieLayout->addMultiCellWidget( textLabelStatut, 4, 4, 0, 1 );

    listViewAllergies = new QListView( Allergie, "listViewAllergies" );
    listViewAllergies->addColumn( tr( "Substance allergique                           " ) );
    listViewAllergies->addColumn( tr( "Code" ) );
    listViewAllergies->setProperty( "rootIsDecorated", QVariant( TRUE, 0 ) );

    AllergieLayout->addMultiCellWidget( listViewAllergies, 1, 1, 0, 1 );

    textLabel2 = new QLabel( Allergie, "textLabel2" );
    textLabel2->setProperty( "maximumSize", QSize( 150, 32767 ) );

    AllergieLayout->addWidget( textLabel2, 0, 0 );

    lineEditNomAllergie = new QLineEdit( Allergie, "lineEditNomAllergie" );

    AllergieLayout->addWidget( lineEditNomAllergie, 0, 1 );

    listView_Produits = new QListView( Allergie, "listView_Produits" );
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

    AllergieLayout->addMultiCellWidget( listView_Produits, 3, 3, 0, 1 );
    tabWidgetDicoATCD->insertTab( Allergie, QString::fromLatin1("") );

    Thesaurus = new QWidget( tabWidgetDicoATCD, "Thesaurus" );
    ThesaurusLayout = new QGridLayout( Thesaurus, 1, 1, 1, 2, "ThesaurusLayout"); 

    listViewThesaurus = new QListView( Thesaurus, "listViewThesaurus" );
    listViewThesaurus->addColumn( trUtf8( "\x4c\x69\x62\x65\x6c\x6c\xc3\xa9\x20\x75\x73\x75\x65\x6c\x20\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20" ) );
    listViewThesaurus->addColumn( tr( "Famille" ) );
    listViewThesaurus->addColumn( tr( "Code" ) );
    listViewThesaurus->addColumn( trUtf8( "\x4c\x69\x62\x65\x6c\x6c\xc3\xa9\x20\x6c\x6f\x6e\x67" ) );
    listViewThesaurus->addColumn( tr( "id" ) );
    listViewThesaurus->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, listViewThesaurus->sizePolicy().hasHeightForWidth() ) );
    listViewThesaurus->setProperty( "selectionMode", "Extended" );
    listViewThesaurus->setProperty( "rootIsDecorated", QVariant( FALSE, 0 ) );
    listViewThesaurus->setProperty( "defaultRenameAction", "Accept" );

    ThesaurusLayout->addWidget( listViewThesaurus, 2, 0 );

    layout9 = new QHBoxLayout( 0, 0, 2, "layout9"); 

    textLabel3 = new QLabel( Thesaurus, "textLabel3" );
    textLabel3->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)4, (QSizePolicy::SizeType)5, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout9->addWidget( textLabel3 );

    lineEditThesaurusFind1 = new QLineEdit( Thesaurus, "lineEditThesaurusFind1" );
    layout9->addWidget( lineEditThesaurusFind1 );

    pushButtonThesaurus_Edit = new QPushButton( Thesaurus, "pushButtonThesaurus_Edit" );
    pushButtonThesaurus_Edit->setProperty( "maximumSize", QSize( 22, 22 ) );
    pushButtonThesaurus_Edit->setProperty( "flat", QVariant( TRUE, 0 ) );
    layout9->addWidget( pushButtonThesaurus_Edit );

    pushButtonThesaurusSave = new QPushButton( Thesaurus, "pushButtonThesaurusSave" );
    pushButtonThesaurusSave->setProperty( "maximumSize", QSize( 22, 22 ) );
    pushButtonThesaurusSave->setProperty( "flat", QVariant( TRUE, 0 ) );
    layout9->addWidget( pushButtonThesaurusSave );

    pushButtonThesaurusDel = new QPushButton( Thesaurus, "pushButtonThesaurusDel" );
    pushButtonThesaurusDel->setProperty( "maximumSize", QSize( 22, 22 ) );
    pushButtonThesaurusDel->setProperty( "flat", QVariant( TRUE, 0 ) );
    layout9->addWidget( pushButtonThesaurusDel );

    ThesaurusLayout->addLayout( layout9, 0, 0 );

    layout11 = new QHBoxLayout( 0, 0, 2, "layout11"); 

    textLabel1 = new QLabel( Thesaurus, "textLabel1" );
    layout11->addWidget( textLabel1 );

    m_Combo_Family = new QComboBox( FALSE, Thesaurus, "m_Combo_Family" );
    m_Combo_Family->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, m_Combo_Family->sizePolicy().hasHeightForWidth() ) );
    layout11->addWidget( m_Combo_Family );

    m_Combo_Genre = new QComboBox( FALSE, Thesaurus, "m_Combo_Genre" );
    m_Combo_Genre->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, m_Combo_Genre->sizePolicy().hasHeightForWidth() ) );
    layout11->addWidget( m_Combo_Genre );

    pushButtonFamilleGenreEdit = new QPushButton( Thesaurus, "pushButtonFamilleGenreEdit" );
    pushButtonFamilleGenreEdit->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)2, (QSizePolicy::SizeType)4, 0, 0, pushButtonFamilleGenreEdit->sizePolicy().hasHeightForWidth() ) );
    pushButtonFamilleGenreEdit->setProperty( "maximumSize", QSize( 22, 22 ) );
    pushButtonFamilleGenreEdit->setProperty( "flat", QVariant( TRUE, 0 ) );
    layout11->addWidget( pushButtonFamilleGenreEdit );

    ThesaurusLayout->addLayout( layout11, 1, 0 );
    tabWidgetDicoATCD->insertTab( Thesaurus, QString::fromLatin1("") );

    layout13->addWidget( tabWidgetDicoATCD, 1, 0 );

    layout12 = new QHBoxLayout( 0, 0, 6, "layout12"); 

    pushButtonThesaurusAdd = new QPushButton( privateLayoutWidget, "pushButtonThesaurusAdd" );
    pushButtonThesaurusAdd->setProperty( "minimumSize", QSize( 26, 26 ) );
    pushButtonThesaurusAdd->setProperty( "flat", QVariant( TRUE, 0 ) );
    layout12->addWidget( pushButtonThesaurusAdd );

    pushButtonThesaurusFreeAdd = new QPushButton( privateLayoutWidget, "pushButtonThesaurusFreeAdd" );
    pushButtonThesaurusFreeAdd->setProperty( "minimumSize", QSize( 26, 26 ) );
    pushButtonThesaurusFreeAdd->setProperty( "flat", QVariant( TRUE, 0 ) );
    layout12->addWidget( pushButtonThesaurusFreeAdd );

    pushButtonThesaurusExport = new QPushButton( privateLayoutWidget, "pushButtonThesaurusExport" );
    pushButtonThesaurusExport->setProperty( "minimumSize", QSize( 26, 26 ) );
    pushButtonThesaurusExport->setProperty( "flat", QVariant( TRUE, 0 ) );
    layout12->addWidget( pushButtonThesaurusExport );

    pushButtonThesaurusImport = new QPushButton( privateLayoutWidget, "pushButtonThesaurusImport" );
    pushButtonThesaurusImport->setProperty( "minimumSize", QSize( 26, 26 ) );
    pushButtonThesaurusImport->setProperty( "flat", QVariant( TRUE, 0 ) );
    layout12->addWidget( pushButtonThesaurusImport );
    spacer2 = new QSpacerItem( 80, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout12->addItem( spacer2 );

    layout13->addLayout( layout12, 0, 0 );

    QWidget* privateLayoutWidget_2 = new QWidget( splitter5, "layout11" );
    layout11_2 = new QGridLayout( privateLayoutWidget_2, 1, 1, 11, 6, "layout11_2"); 

    layout7_2 = new QHBoxLayout( 0, 0, 6, "layout7_2"); 

    buttonOk = new QPushButton( privateLayoutWidget_2, "buttonOk" );
    buttonOk->setProperty( "autoDefault", QVariant( TRUE, 0 ) );
    buttonOk->setProperty( "default", QVariant( TRUE, 0 ) );
    layout7_2->addWidget( buttonOk );

    buttonCancel = new QPushButton( privateLayoutWidget_2, "buttonCancel" );
    buttonCancel->setProperty( "autoDefault", QVariant( TRUE, 0 ) );
    layout7_2->addWidget( buttonCancel );

    layout11_2->addLayout( layout7_2, 2, 0 );

    textLabelChoix = new QLabel( privateLayoutWidget_2, "textLabelChoix" );
    textLabelChoix->setProperty( "frameShape", "MenuBarPanel" );
    textLabelChoix->setProperty( "alignment", int( QLabel::AlignCenter ) );

    layout11_2->addWidget( textLabelChoix, 0, 0 );

    layout10 = new QGridLayout( 0, 1, 1, 0, 6, "layout10"); 

    layout9_2 = new QGridLayout( 0, 1, 1, 0, 6, "layout9_2"); 

    frame4 = new QFrame( privateLayoutWidget_2, "frame4" );
    frame4->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)2, 0, 0, frame4->sizePolicy().hasHeightForWidth() ) );
    frame4->setProperty( "frameShape", "MenuBarPanel" );
    frame4->setProperty( "frameShadow", "Raised" );
    frame4->setProperty( "margin", 0 );
    frame4Layout = new QGridLayout( frame4, 1, 1, 6, 6, "frame4Layout"); 

    pushButtonRemoveFromChoix = new QPushButton( frame4, "pushButtonRemoveFromChoix" );
    pushButtonRemoveFromChoix->setProperty( "minimumSize", QSize( 32, 32 ) );
    pushButtonRemoveFromChoix->setProperty( "maximumSize", QSize( 32, 32767 ) );
    pushButtonRemoveFromChoix->setProperty( "flat", QVariant( TRUE, 0 ) );

    frame4Layout->addWidget( pushButtonRemoveFromChoix, 5, 0 );

    pushButtonAddMedicament = new QPushButton( frame4, "pushButtonAddMedicament" );
    pushButtonAddMedicament->setProperty( "minimumSize", QSize( 32, 32 ) );
    pushButtonAddMedicament->setProperty( "maximumSize", QSize( 32, 32767 ) );
    pushButtonAddMedicament->setProperty( "flat", QVariant( TRUE, 0 ) );

    frame4Layout->addWidget( pushButtonAddMedicament, 4, 0 );
    spacer3 = new QSpacerItem( 20, 55, QSizePolicy::Minimum, QSizePolicy::Preferred );
    frame4Layout->addItem( spacer3, 3, 0 );

    pushButtonAddFreeToChoix = new QPushButton( frame4, "pushButtonAddFreeToChoix" );
    pushButtonAddFreeToChoix->setProperty( "minimumSize", QSize( 32, 32 ) );
    pushButtonAddFreeToChoix->setProperty( "maximumSize", QSize( 32, 32767 ) );
    pushButtonAddFreeToChoix->setProperty( "flat", QVariant( TRUE, 0 ) );

    frame4Layout->addWidget( pushButtonAddFreeToChoix, 2, 0 );

    pushButton_AddToChoix = new QPushButton( frame4, "pushButton_AddToChoix" );
    pushButton_AddToChoix->setProperty( "minimumSize", QSize( 32, 32 ) );
    pushButton_AddToChoix->setProperty( "maximumSize", QSize( 32, 32767 ) );
    pushButton_AddToChoix->setProperty( "flat", QVariant( TRUE, 0 ) );

    frame4Layout->addWidget( pushButton_AddToChoix, 0, 0 );

    pushButton_AddToChoixFast = new QPushButton( frame4, "pushButton_AddToChoixFast" );
    pushButton_AddToChoixFast->setProperty( "minimumSize", QSize( 32, 32 ) );
    pushButton_AddToChoixFast->setProperty( "maximumSize", QSize( 32, 32767 ) );
    pushButton_AddToChoixFast->setProperty( "flat", QVariant( TRUE, 0 ) );

    frame4Layout->addWidget( pushButton_AddToChoixFast, 1, 0 );

    layout9_2->addWidget( frame4, 1, 0 );

    textLabel1_3 = new QLabel( privateLayoutWidget_2, "textLabel1_3" );
    textLabel1_3->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)4, 0, 0, textLabel1_3->sizePolicy().hasHeightForWidth() ) );
    textLabel1_3->setProperty( "maximumSize", QSize( 40, 32767 ) );
    textLabel1_3->setProperty( "frameShape", "Box" );
    textLabel1_3->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignCenter ) );

    layout9_2->addWidget( textLabel1_3, 0, 0 );

    layout10->addLayout( layout9_2, 0, 0 );

    listViewCim10_Choix = new QListView( privateLayoutWidget_2, "listViewCim10_Choix" );
    listViewCim10_Choix->addColumn( trUtf8( "\x4c\x69\x62\x65\x6c\x6c\xc3\xa9\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20" ) );
    listViewCim10_Choix->addColumn( tr( "Famille" ) );
    listViewCim10_Choix->addColumn( trUtf8( "\xc3\x89\x74\x61\x74" ) );
    listViewCim10_Choix->addColumn( tr( "Commentaire" ) );
    listViewCim10_Choix->addColumn( tr( "Date" ) );
    listViewCim10_Choix->addColumn( tr( "ALD" ) );
    listViewCim10_Choix->addColumn( tr( "Code" ) );
    listViewCim10_Choix->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, listViewCim10_Choix->sizePolicy().hasHeightForWidth() ) );
    listViewCim10_Choix->setProperty( "maximumSize", QSize( 32767, 32767 ) );
    listViewCim10_Choix->setProperty( "rootIsDecorated", QVariant( FALSE, 0 ) );

    layout10->addWidget( listViewCim10_Choix, 0, 1 );

    layout11_2->addLayout( layout10, 1, 0 );

    Dlg_GestionATCDLayout->addWidget( splitter5, 0, 0 );
    languageChange();
    resize( QSize(878, 561).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // buddies
    textLabel3_2->setBuddy( lineEditAutolcatorLibelle );
    textLabel3_3->setBuddy( lineEditAutolcatorLibelle_2 );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Dlg_GestionATCD::~Dlg_GestionATCD()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Dlg_GestionATCD::languageChange()
{
    setProperty( "caption", trUtf8( "\x47\x65\x73\x74\x69\x6f\x6e\x20\x64\x65\x73\x20\x61\x6e\x74\xc3\xa9\x63\xc3\xa9\x64"
    "\x65\x6e\x74\x73" ) );
    listViewCim10_Libelles->header()->setLabel( 0, trUtf8( "\x4c\x69\x62\x65\x6c\x6c\xc3\xa9\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20" ) );
    listViewCim10_Libelles->header()->setLabel( 1, tr( "Code" ) );
    listViewCim10_Libelles->header()->setLabel( 2, tr( "SID" ) );
    textLabel3_2->setProperty( "text", tr( "Contient : " ) );
    QToolTip::add( lineEditAutolcatorLibelle, trUtf8( "\x50\x72\x65\x6d\x69\x65\x72\x20\x63\x72\x69\x74\xc3\xa8\x72\x65\x20\x64\x65\x20\x72"
    "\x65\x63\x68\x65\x72\x63\x68\x65" ) );
    textLabel3_3->setProperty( "text", tr( "et contient :" ) );
    QToolTip::add( lineEditAutolcatorLibelle_2, trUtf8( "\x44\x65\x75\x78\x69\xc3\xa8\x6d\x65\x20\x63\x72\x69\x74\xc3\xa8\x72\x65\x20\x64\x65"
    "\x20\x72\x65\x63\x68\x65\x72\x63\x68\x65" ) );
    tabWidgetDicoATCD->changeTab( CIM_10, tr( "Cim 10" ) );
    listViewCim10_rubriques->header()->setLabel( 0, trUtf8( "\x4c\x69\x62\x65\x6c\x6c\xc3\xa9\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20" ) );
    listViewCim10_rubriques->header()->setLabel( 1, tr( "Code" ) );
    listViewCim10_rubriques->header()->setLabel( 2, tr( "SID" ) );
    tabWidgetDicoATCD->changeTab( CIM10_Chapitre, trUtf8( "\x63\x68\x61\x70\x69\x74\x72\xc3\xa9\x65" ) );
    listViewAllergies->header()->setLabel( 0, tr( "Substance allergique                           " ) );
    listViewAllergies->header()->setLabel( 1, tr( "Code" ) );
    textLabel2->setProperty( "text", tr( "Produit :" ) );
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
    tabWidgetDicoATCD->changeTab( Allergie, tr( "Allergies" ) );
    listViewThesaurus->header()->setLabel( 0, trUtf8( "\x4c\x69\x62\x65\x6c\x6c\xc3\xa9\x20\x75\x73\x75\x65\x6c\x20\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20" ) );
    listViewThesaurus->header()->setLabel( 1, tr( "Famille" ) );
    listViewThesaurus->header()->setLabel( 2, tr( "Code" ) );
    listViewThesaurus->header()->setLabel( 3, trUtf8( "\x4c\x69\x62\x65\x6c\x6c\xc3\xa9\x20\x6c\x6f\x6e\x67" ) );
    listViewThesaurus->header()->setLabel( 4, tr( "id" ) );
    textLabel3->setProperty( "text", tr( "Contient : " ) );
    pushButtonThesaurus_Edit->setProperty( "text", QString::null );
    QToolTip::add( pushButtonThesaurus_Edit, trUtf8( "\x45\x64\x69\x74\x65\x72\x20\x6c\x65\x20\x66\x61\x76\x6f\x72\x69\x73\x20\x73\xc3\xa9"
    "\x6c\x65\x63\x74\x69\x6f\x6e\x6e\xc3\xa9" ) );
    QWhatsThis::add( pushButtonThesaurus_Edit, trUtf8( "\x45\x64\x69\x74\x65\x72\x20\x6c\x65\x20\x66\x61\x76\x6f\x72\x69\x73\x20\x73\xc3\xa9"
    "\x6c\x65\x63\x74\x69\x6f\x6e\x6e\xc3\xa9" ) );
    pushButtonThesaurusSave->setProperty( "text", QString::null );
    QToolTip::add( pushButtonThesaurusSave, tr( "Enregistrer les favoris" ) );
    QWhatsThis::add( pushButtonThesaurusSave, tr( "Enregistrer les favoris" ) );
    pushButtonThesaurusDel->setProperty( "text", QString::null );
    QToolTip::add( pushButtonThesaurusDel, trUtf8( "\x45\x66\x66\x61\x63\x65\x72\x20\x6c\x65\x73\x20\xc3\xa9\x6c\xc3\xa9\x6d\x65\x6e\x74"
    "\x73\x20\x73\xc3\xa9\x6c\x65\x63\x74\x69\x6f\x6e\x6e\xc3\xa9\x73\x20\x64\x61\x6e"
    "\x73\x20\x6c\x61\x20\x6c\x69\x73\x74\x65\x20\x64\x65\x73\x20\x66\x61\x76\x6f\x72"
    "\x69\x73" ) );
    QWhatsThis::add( pushButtonThesaurusDel, trUtf8( "\x45\x66\x66\x61\x63\x65\x72\x20\x6c\x65\x73\x20\xc3\xa9\x6c\xc3\xa9\x6d\x65\x6e\x74"
    "\x73\x20\x73\xc3\xa9\x6c\x65\x63\x74\x69\x6f\x6e\x6e\xc3\xa9\x73\x20\x64\x61\x6e"
    "\x73\x20\x6c\x61\x20\x6c\x69\x73\x74\x65\x20\x64\x65\x73\x20\x66\x61\x76\x6f\x72"
    "\x69\x73" ) );
    textLabel1->setProperty( "text", tr( "Famille" ) );
    pushButtonFamilleGenreEdit->setProperty( "text", QString::null );
    QToolTip::add( pushButtonFamilleGenreEdit, tr( "Cliquez ici pour modifier les listes des familles et genres" ) );
    QWhatsThis::add( pushButtonFamilleGenreEdit, tr( "Cliquez ici pour modifier les listes des familles et genres" ) );
    tabWidgetDicoATCD->changeTab( Thesaurus, tr( "Favoris" ) );
    pushButtonThesaurusAdd->setProperty( "text", QString::null );
    QToolTip::add( pushButtonThesaurusAdd, trUtf8( "\x41\x6a\x6f\x75\x74\x65\x72\x20\x6c\x27\x69\x74\x65\x6d\x20\x73\xc3\xa9\x6c\x65\x63"
    "\x74\x69\x6f\x6e\x6e\xc3\xa9\x20\x61\x75\x78\x20\x66\x61\x76\x6f\x72\x69\x73\x2e"
    "" ) );
    QWhatsThis::add( pushButtonThesaurusAdd, trUtf8( "\x41\x6a\x6f\x75\x74\x65\x72\x20\x6c\x27\x69\x74\x65\x6d\x20\x73\xc3\xa9\x6c\x65\x63"
    "\x74\x69\x6f\x6e\x6e\xc3\xa9\x20\x61\x75\x78\x20\x66\x61\x76\x6f\x72\x69\x73\x2e"
    "" ) );
    pushButtonThesaurusFreeAdd->setProperty( "text", QString::null );
    QToolTip::add( pushButtonThesaurusFreeAdd, tr( "Ajouter un texte libre aux favoris." ) );
    QWhatsThis::add( pushButtonThesaurusFreeAdd, tr( "Ajouter un texte libre aux favoris." ) );
    pushButtonThesaurusExport->setProperty( "text", QString::null );
    QToolTip::add( pushButtonThesaurusExport, tr( "Exporter les favoris dans un fichier texte." ) );
    QWhatsThis::add( pushButtonThesaurusExport, tr( "Exporter les favoris dans un fichier texte." ) );
    pushButtonThesaurusImport->setProperty( "text", QString::null );
    QToolTip::add( pushButtonThesaurusImport, trUtf8( "\x49\x6d\x70\x6f\x72\x74\x65\x72\x20\x6c\x65\x73\x20\x66\x61\x76\x6f\x72\x69\x73\x20"
    "\xc3\xa0\x20\x70\x61\x72\x74\x69\x72\x20\x64\x27\x75\x6e\x20\x66\x69\x63\x68\x69"
    "\x65\x72\x20\x74\x65\x78\x74\x65\x2e" ) );
    QWhatsThis::add( pushButtonThesaurusImport, trUtf8( "\x49\x6d\x70\x6f\x72\x74\x65\x72\x20\x6c\x65\x73\x20\x66\x61\x76\x6f\x72\x69\x73\x20"
    "\xc3\xa0\x20\x70\x61\x72\x74\x69\x72\x20\x64\x27\x75\x6e\x20\x66\x69\x63\x68\x69"
    "\x65\x72\x20\x74\x65\x78\x74\x65\x2e" ) );
    buttonOk->setProperty( "text", tr( "Valider" ) );
    buttonOk->setProperty( "accel", QKeySequence( QString::null ) );
    buttonCancel->setProperty( "text", tr( "Annu&ler" ) );
    buttonCancel->setProperty( "accel", QKeySequence( tr( "Alt+L" ) ) );
    textLabelChoix->setProperty( "text", trUtf8( "\x4c\x69\x73\x74\x65\x20\x64\x65\x73\x20\x61\x6e\x74\xc3\xa9\x63\xc3\xa9\x64\x65\x6e"
    "\x74\x73\x20\x64\x75\x20\x70\x61\x74\x69\x65\x6e\x74" ) );
    pushButtonRemoveFromChoix->setProperty( "text", QString::null );
    QToolTip::add( pushButtonRemoveFromChoix, tr( "Retirer un item de la liste de droite" ) );
    QWhatsThis::add( pushButtonRemoveFromChoix, tr( "Retirer un item de la liste de droite" ) );
    pushButtonAddMedicament->setProperty( "text", QString::null );
    QToolTip::add( pushButtonAddMedicament, trUtf8( "\x41\x6a\x6f\x75\x74\x65\x72\x20\x75\x6e\x20\x6d\x65\x64\x69\x63\x61\x6d\x65\x6e\x74"
    "\x20\x63\x6f\x6d\x6d\x65\x20\x61\x6e\x74\xc3\xa9\x63\xc3\xa9\x64\x65\x6e\x74\x20"
    "\x61\x6c\x6c\x65\x72\x67\x69\x71\x75\x65" ) );
    QWhatsThis::add( pushButtonAddMedicament, trUtf8( "\x41\x6a\x6f\x75\x74\x65\x72\x20\x75\x6e\x20\x6d\x65\x64\x69\x63\x61\x6d\x65\x6e\x74"
    "\x20\x63\x6f\x6d\x6d\x65\x20\x61\x6e\x74\xc3\xa9\x63\xc3\xa9\x64\x65\x6e\x74\x20"
    "\x61\x6c\x6c\x65\x72\x67\x69\x71\x75\x65" ) );
    pushButtonAddFreeToChoix->setProperty( "text", QString::null );
    QToolTip::add( pushButtonAddFreeToChoix, trUtf8( "\x41\x6a\x6f\x75\x74\x65\x72\x20\x75\x6e\x20\x61\x6e\x74\xc3\xa9\x63\xc3\xa9\x64\x65"
    "\x6e\x74\x20\x65\x6e\x20\x74\x65\x78\x74\x65\x20\x6c\x69\x62\x72\x65" ) );
    QWhatsThis::add( pushButtonAddFreeToChoix, trUtf8( "\x41\x6a\x6f\x75\x74\x65\x72\x20\x75\x6e\x20\x61\x6e\x74\xc3\xa9\x63\xc3\xa9\x64\x65"
    "\x6e\x74\x20\x65\x6e\x20\x74\x65\x78\x74\x65\x20\x6c\x69\x62\x72\x65" ) );
    pushButton_AddToChoix->setProperty( "text", QString::null );
    pushButton_AddToChoix->setProperty( "accel", QKeySequence( QString::null ) );
    QToolTip::add( pushButton_AddToChoix, trUtf8( "\x50\x6c\x61\x63\x65\x72\x20\x6c\x27\x69\x74\x65\x6d\x20\x73\xc3\xa9\x6c\x65\x63\x74"
    "\x69\x6f\x6e\x6e\xc3\xa9\x20\x64\x61\x6e\x73\x20\x6c\x61\x20\x6c\x69\x73\x74\x65"
    "\x20\x64\x65\x20\x67\x61\x75\x63\x68\x65\x20\x64\x61\x6e\x73\x20\x63\x65\x6c\x6c"
    "\x65\x20\x64\x65\x20\x64\x72\x6f\x69\x74\x65" ) );
    QWhatsThis::add( pushButton_AddToChoix, trUtf8( "\x50\x6c\x61\x63\x65\x72\x20\x6c\x27\x69\x74\x65\x6d\x20\x73\xc3\xa9\x6c\x65\x63\x74"
    "\x69\x6f\x6e\x6e\xc3\xa9\x20\x64\x61\x6e\x73\x20\x6c\x61\x20\x6c\x69\x73\x74\x65"
    "\x20\x64\x65\x20\x67\x61\x75\x63\x68\x65\x20\x64\x61\x6e\x73\x20\x63\x65\x6c\x6c"
    "\x65\x20\x64\x65\x20\x64\x72\x6f\x69\x74\x65" ) );
    pushButton_AddToChoixFast->setProperty( "text", QString::null );
    pushButton_AddToChoixFast->setProperty( "accel", QKeySequence( tr( "Ctrl+=, F7" ) ) );
    QToolTip::add( pushButton_AddToChoixFast, trUtf8( "\x41\x6a\x6f\x75\x74\x20\x72\x61\x70\x69\x64\x65\x20\x28\x6e\x65\x20\x70\x61\x73\x73"
    "\x65\x20\x70\x61\x73\x20\x70\x61\x72\x20\x6c\x65\x20\x64\x69\x61\x6c\x6f\x67\x75"
    "\x65\x20\x64\x65\x20\x70\x72\x6f\x70\x72\x69\xc3\xa9\x74\xc3\xa9\x73\x29" ) );
    QWhatsThis::add( pushButton_AddToChoixFast, trUtf8( "\x41\x6a\x6f\x75\x74\x20\x72\x61\x70\x69\x64\x65\x20\x28\x6e\x65\x20\x70\x61\x73\x73"
    "\x65\x20\x70\x61\x73\x20\x70\x61\x72\x20\x6c\x65\x20\x64\x69\x61\x6c\x6f\x67\x75"
    "\x65\x20\x64\x65\x20\x70\x72\x6f\x70\x72\x69\xc3\xa9\x74\xc3\xa9\x73\x29" ) );
    textLabel1_3->setProperty( "text", tr( "<font size=\"-1\"><b>Retirer\n"
"Ajouter</b></font>" ) );
    listViewCim10_Choix->header()->setLabel( 0, trUtf8( "\x4c\x69\x62\x65\x6c\x6c\xc3\xa9\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
    "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20" ) );
    listViewCim10_Choix->header()->setLabel( 1, tr( "Famille" ) );
    listViewCim10_Choix->header()->setLabel( 2, trUtf8( "\xc3\x89\x74\x61\x74" ) );
    listViewCim10_Choix->header()->setLabel( 3, tr( "Commentaire" ) );
    listViewCim10_Choix->header()->setLabel( 4, tr( "Date" ) );
    listViewCim10_Choix->header()->setLabel( 5, tr( "ALD" ) );
    listViewCim10_Choix->header()->setLabel( 6, tr( "Code" ) );
}

