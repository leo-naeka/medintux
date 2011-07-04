/****************************************************************************
** Form implementation generated from reading ui file '../../MedinTuxTools/Form_Organiseur.ui'
**
** Created: mer. mai 4 22:19:17 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "Form_Organiseur.h"

#include <qvariant.h>
#include <../../MedinTuxTools/CMaskedLineEdit.h>
#include <qpushbutton.h>
#include <qframe.h>
#include <qheader.h>
#include <qlistview.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qcheckbox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a Form_Organiseur as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
Form_Organiseur::Form_Organiseur( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setProperty( "name", "Form_Organiseur" );
    setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)1, 0, 0, sizePolicy().hasHeightForWidth() ) );
    Form_OrganiseurLayout = new QGridLayout( this, 1, 1, 0, 0, "Form_OrganiseurLayout"); 

    Form_OrganiseurQFrame = new QFrame( this, "Form_OrganiseurQFrame" );
    Form_OrganiseurQFrame->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)2, 0, 0, Form_OrganiseurQFrame->sizePolicy().hasHeightForWidth() ) );
    Form_OrganiseurQFrame->setProperty( "frameShape", "PopupPanel" );
    Form_OrganiseurQFrame->setProperty( "frameShadow", "Sunken" );
    Form_OrganiseurQFrame->setProperty( "lineWidth", 1 );
    Form_OrganiseurQFrameLayout = new QGridLayout( Form_OrganiseurQFrame, 1, 1, 0, 0, "Form_OrganiseurQFrameLayout"); 

    but_ConfFiltre_HideShow = new QPushButton( Form_OrganiseurQFrame, "but_ConfFiltre_HideShow" );
    but_ConfFiltre_HideShow->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 20, 20, but_ConfFiltre_HideShow->sizePolicy().hasHeightForWidth() ) );
    but_ConfFiltre_HideShow->setProperty( "minimumSize", QSize( 10, 10 ) );
    but_ConfFiltre_HideShow->setProperty( "maximumSize", QSize( 10, 10 ) );
    but_ConfFiltre_HideShow->setProperty( "paletteForegroundColor", QColor( 255, 0, 0 ) );
    but_ConfFiltre_HideShow->setProperty( "paletteBackgroundColor", QColor( 255, 0, 0 ) );
    but_ConfFiltre_HideShow->setProperty( "toggleButton", QVariant( FALSE, 0 ) );
    but_ConfFiltre_HideShow->setProperty( "flat", QVariant( TRUE, 0 ) );

    Form_OrganiseurQFrameLayout->addWidget( but_ConfFiltre_HideShow, 0, 0 );

    layout12 = new QGridLayout( 0, 1, 1, 0, 0, "layout12"); 

    frame_ListView = new QFrame( Form_OrganiseurQFrame, "frame_ListView" );
    frame_ListView->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)3, 0, 0, frame_ListView->sizePolicy().hasHeightForWidth() ) );
    frame_ListView->setProperty( "minimumSize", QSize( 0, 50 ) );
    frame_ListView->setProperty( "frameShape", "StyledPanel" );
    frame_ListView->setProperty( "frameShadow", "Raised" );
    frame_ListViewLayout = new QGridLayout( frame_ListView, 1, 1, 0, 0, "frame_ListViewLayout"); 

    listView2 = new QListView( frame_ListView, "listView2" );
    listView2->addColumn( tr( "Column 1" ) );
    listView2->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)2, 0, 0, listView2->sizePolicy().hasHeightForWidth() ) );

    frame_ListViewLayout->addWidget( listView2, 0, 0 );

    layout12->addWidget( frame_ListView, 1, 0 );

    frame_ConfigHeader = new QFrame( Form_OrganiseurQFrame, "frame_ConfigHeader" );
    frame_ConfigHeader->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)2, (QSizePolicy::SizeType)4, 2, 0, frame_ConfigHeader->sizePolicy().hasHeightForWidth() ) );
    frame_ConfigHeader->setProperty( "frameShape", "StyledPanel" );
    frame_ConfigHeader->setProperty( "frameShadow", "Raised" );
    frame_ConfigHeader->setProperty( "lineWidth", 0 );
    frame_ConfigHeaderLayout = new QGridLayout( frame_ConfigHeader, 1, 1, 0, 0, "frame_ConfigHeaderLayout"); 

    layout15 = new QGridLayout( 0, 1, 1, 1, 0, "layout15"); 

    layout12_2 = new QHBoxLayout( 0, 1, 2, "layout12_2"); 

    layout25 = new QVBoxLayout( 0, 0, 6, "layout25"); 

    textLabel_Du = new QLabel( frame_ConfigHeader, "textLabel_Du" );
    textLabel_Du->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)5, 0, 0, textLabel_Du->sizePolicy().hasHeightForWidth() ) );
    layout25->addWidget( textLabel_Du );

    textLabel_De = new QLabel( frame_ConfigHeader, "textLabel_De" );
    textLabel_De->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)5, 0, 0, textLabel_De->sizePolicy().hasHeightForWidth() ) );
    layout25->addWidget( textLabel_De );
    layout12_2->addLayout( layout25 );

    layout22 = new QVBoxLayout( 0, 1, 0, "layout22"); 

    layout3 = new QHBoxLayout( 0, 0, 1, "layout3"); 

    mle_deb = new CMaskedLineEdit( frame_ConfigHeader, "mle_deb" );
    mle_deb->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)5, 0, 0, mle_deb->sizePolicy().hasHeightForWidth() ) );
    mle_deb->setProperty( "maximumSize", QSize( 80, 32767 ) );
    layout3->addWidget( mle_deb );

    pushButtonDateDeb = new QPushButton( frame_ConfigHeader, "pushButtonDateDeb" );
    pushButtonDateDeb->setProperty( "maximumSize", QSize( 16, 16 ) );
    pushButtonDateDeb->setProperty( "flat", QVariant( TRUE, 0 ) );
    layout3->addWidget( pushButtonDateDeb );
    layout22->addLayout( layout3 );

    mle_HeureDeb = new CMaskedLineEdit( frame_ConfigHeader, "mle_HeureDeb" );
    mle_HeureDeb->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)4, 0, 0, mle_HeureDeb->sizePolicy().hasHeightForWidth() ) );
    mle_HeureDeb->setProperty( "minimumSize", QSize( 0, 10 ) );
    mle_HeureDeb->setProperty( "maximumSize", QSize( 80, 32767 ) );
    layout22->addWidget( mle_HeureDeb );
    layout12_2->addLayout( layout22 );

    layout24 = new QVBoxLayout( 0, 0, 6, "layout24"); 

    textLabel_Au = new QLabel( frame_ConfigHeader, "textLabel_Au" );
    textLabel_Au->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)5, 0, 0, textLabel_Au->sizePolicy().hasHeightForWidth() ) );
    layout24->addWidget( textLabel_Au );

    textLabel_a = new QLabel( frame_ConfigHeader, "textLabel_a" );
    textLabel_a->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)5, 0, 0, textLabel_a->sizePolicy().hasHeightForWidth() ) );
    layout24->addWidget( textLabel_a );
    layout12_2->addLayout( layout24 );

    layout23 = new QVBoxLayout( 0, 0, 1, "layout23"); 

    layout4 = new QHBoxLayout( 0, 0, 1, "layout4"); 

    mle_fin = new CMaskedLineEdit( frame_ConfigHeader, "mle_fin" );
    mle_fin->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)5, 0, 0, mle_fin->sizePolicy().hasHeightForWidth() ) );
    mle_fin->setProperty( "maximumSize", QSize( 80, 32767 ) );
    layout4->addWidget( mle_fin );

    pushButtonDateFin = new QPushButton( frame_ConfigHeader, "pushButtonDateFin" );
    pushButtonDateFin->setProperty( "maximumSize", QSize( 16, 16 ) );
    pushButtonDateFin->setProperty( "flat", QVariant( TRUE, 0 ) );
    layout4->addWidget( pushButtonDateFin );
    layout23->addLayout( layout4 );

    mle_HeureFin = new CMaskedLineEdit( frame_ConfigHeader, "mle_HeureFin" );
    mle_HeureFin->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)4, 0, 0, mle_HeureFin->sizePolicy().hasHeightForWidth() ) );
    mle_HeureFin->setProperty( "minimumSize", QSize( 0, 10 ) );
    mle_HeureFin->setProperty( "maximumSize", QSize( 80, 32767 ) );
    layout23->addWidget( mle_HeureFin );
    layout12_2->addLayout( layout23 );

    layout15->addLayout( layout12_2, 0, 0 );

    layout13 = new QGridLayout( 0, 1, 1, 0, 1, "layout13"); 

    pushButtonRaffraichir = new QPushButton( frame_ConfigHeader, "pushButtonRaffraichir" );

    layout13->addWidget( pushButtonRaffraichir, 1, 0 );

    comboBox_Filtre = new QComboBox( FALSE, frame_ConfigHeader, "comboBox_Filtre" );

    layout13->addWidget( comboBox_Filtre, 0, 0 );

    layout15->addLayout( layout13, 0, 1 );

    frame_ConfigHeaderLayout->addLayout( layout15, 1, 0 );

    layout12_3 = new QGridLayout( 0, 1, 1, 0, 0, "layout12_3"); 

    but_ZoomDefault = new QPushButton( frame_ConfigHeader, "but_ZoomDefault" );
    but_ZoomDefault->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 20, 20, but_ZoomDefault->sizePolicy().hasHeightForWidth() ) );
    but_ZoomDefault->setProperty( "minimumSize", QSize( 20, 20 ) );
    but_ZoomDefault->setProperty( "maximumSize", QSize( 20, 20 ) );
    but_ZoomDefault->setProperty( "toggleButton", QVariant( FALSE, 0 ) );
    but_ZoomDefault->setProperty( "flat", QVariant( TRUE, 0 ) );

    layout12_3->addWidget( but_ZoomDefault, 0, 9 );

    but_ConfFiltre_Moins = new QPushButton( frame_ConfigHeader, "but_ConfFiltre_Moins" );
    but_ConfFiltre_Moins->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 20, 20, but_ConfFiltre_Moins->sizePolicy().hasHeightForWidth() ) );
    but_ConfFiltre_Moins->setProperty( "minimumSize", QSize( 20, 20 ) );
    but_ConfFiltre_Moins->setProperty( "maximumSize", QSize( 20, 20 ) );
    but_ConfFiltre_Moins->setProperty( "toggleButton", QVariant( FALSE, 0 ) );
    but_ConfFiltre_Moins->setProperty( "flat", QVariant( TRUE, 0 ) );

    layout12_3->addWidget( but_ConfFiltre_Moins, 0, 3 );

    checkBox_filtreActif = new QCheckBox( frame_ConfigHeader, "checkBox_filtreActif" );
    checkBox_filtreActif->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)4, 0, 0, checkBox_filtreActif->sizePolicy().hasHeightForWidth() ) );

    layout12_3->addWidget( checkBox_filtreActif, 0, 0 );

    but_ZoomMinus = new QPushButton( frame_ConfigHeader, "but_ZoomMinus" );
    but_ZoomMinus->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 20, 20, but_ZoomMinus->sizePolicy().hasHeightForWidth() ) );
    but_ZoomMinus->setProperty( "minimumSize", QSize( 20, 20 ) );
    but_ZoomMinus->setProperty( "maximumSize", QSize( 20, 20 ) );
    but_ZoomMinus->setProperty( "toggleButton", QVariant( FALSE, 0 ) );
    but_ZoomMinus->setProperty( "flat", QVariant( TRUE, 0 ) );

    layout12_3->addWidget( but_ZoomMinus, 0, 8 );

    but_ConfFiltre_Plus = new QPushButton( frame_ConfigHeader, "but_ConfFiltre_Plus" );
    but_ConfFiltre_Plus->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 20, 20, but_ConfFiltre_Plus->sizePolicy().hasHeightForWidth() ) );
    but_ConfFiltre_Plus->setProperty( "minimumSize", QSize( 20, 20 ) );
    but_ConfFiltre_Plus->setProperty( "maximumSize", QSize( 20, 20 ) );
    but_ConfFiltre_Plus->setProperty( "toggleButton", QVariant( FALSE, 0 ) );
    but_ConfFiltre_Plus->setProperty( "flat", QVariant( TRUE, 0 ) );

    layout12_3->addWidget( but_ConfFiltre_Plus, 0, 2 );

    but_LoadProfile = new QPushButton( frame_ConfigHeader, "but_LoadProfile" );
    but_LoadProfile->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 20, 20, but_LoadProfile->sizePolicy().hasHeightForWidth() ) );
    but_LoadProfile->setProperty( "minimumSize", QSize( 20, 20 ) );
    but_LoadProfile->setProperty( "maximumSize", QSize( 20, 20 ) );
    but_LoadProfile->setProperty( "toggleButton", QVariant( FALSE, 0 ) );
    but_LoadProfile->setProperty( "flat", QVariant( TRUE, 0 ) );

    layout12_3->addWidget( but_LoadProfile, 0, 5 );

    but_ZoomPlus = new QPushButton( frame_ConfigHeader, "but_ZoomPlus" );
    but_ZoomPlus->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 16, 16, but_ZoomPlus->sizePolicy().hasHeightForWidth() ) );
    but_ZoomPlus->setProperty( "minimumSize", QSize( 20, 20 ) );
    but_ZoomPlus->setProperty( "maximumSize", QSize( 20, 20 ) );
    but_ZoomPlus->setProperty( "toggleButton", QVariant( FALSE, 0 ) );
    but_ZoomPlus->setProperty( "flat", QVariant( TRUE, 0 ) );

    layout12_3->addWidget( but_ZoomPlus, 0, 7 );

    but_ConfFiltre = new QPushButton( frame_ConfigHeader, "but_ConfFiltre" );
    but_ConfFiltre->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 20, 20, but_ConfFiltre->sizePolicy().hasHeightForWidth() ) );
    but_ConfFiltre->setProperty( "minimumSize", QSize( 20, 20 ) );
    but_ConfFiltre->setProperty( "maximumSize", QSize( 20, 20 ) );
    but_ConfFiltre->setProperty( "toggleButton", QVariant( FALSE, 0 ) );
    but_ConfFiltre->setProperty( "flat", QVariant( TRUE, 0 ) );

    layout12_3->addWidget( but_ConfFiltre, 0, 4 );

    but_SaveProfile = new QPushButton( frame_ConfigHeader, "but_SaveProfile" );
    but_SaveProfile->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 20, 20, but_SaveProfile->sizePolicy().hasHeightForWidth() ) );
    but_SaveProfile->setProperty( "minimumSize", QSize( 20, 20 ) );
    but_SaveProfile->setProperty( "maximumSize", QSize( 20, 20 ) );
    but_SaveProfile->setProperty( "toggleButton", QVariant( FALSE, 0 ) );
    but_SaveProfile->setProperty( "flat", QVariant( TRUE, 0 ) );

    layout12_3->addWidget( but_SaveProfile, 0, 6 );

    comboBox_FiltreVisu = new QComboBox( FALSE, frame_ConfigHeader, "comboBox_FiltreVisu" );
    comboBox_FiltreVisu->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)0, 0, 0, comboBox_FiltreVisu->sizePolicy().hasHeightForWidth() ) );

    layout12_3->addWidget( comboBox_FiltreVisu, 0, 1 );

    frame_ConfigHeaderLayout->addLayout( layout12_3, 0, 0 );

    layout12->addWidget( frame_ConfigHeader, 0, 0 );

    Form_OrganiseurQFrameLayout->addLayout( layout12, 1, 0 );

    Form_OrganiseurLayout->addWidget( Form_OrganiseurQFrame, 0, 0 );
    languageChange();
    resize( QSize(599, 908).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Form_Organiseur::~Form_Organiseur()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Form_Organiseur::languageChange()
{
    setProperty( "caption", tr( "Organiseur" ) );
    but_ConfFiltre_HideShow->setProperty( "text", QString::null );
    QToolTip::add( but_ConfFiltre_HideShow, tr( "Affiche ou cache les outils" ) );
    listView2->header()->setLabel( 0, tr( "Column 1" ) );
    listView2->clear();
    QListViewItem * item = new QListViewItem( listView2, 0 );
    item->setText( 0, tr( "New Item" ) );

    textLabel_Du->setProperty( "text", tr( "Du" ) );
    textLabel_De->setProperty( "text", tr( "De" ) );
    mle_deb->setProperty( "control", tr( "GGGGGGGG" ) );
    mle_deb->setProperty( "mask", tr( "__/__/____" ) );
    pushButtonDateDeb->setProperty( "text", QString::null );
    QToolTip::add( pushButtonDateDeb, trUtf8( "\x44\xc3\xa9\x66\x69\x6e\x69\x72\x20\x6c\x61\x20\x64\x61\x74\x65\x20\x65\x74\x20\x68"
    "\x65\x75\x72\x65\x20\x64\x65\x73\x20\x63\x6c\x61\x73\x73\x65\x75\x72\x73\x20\xc3"
    "\xa0\x20\x76\x69\x73\x75\x61\x6c\x69\x73\x65\x72" ) );
    mle_HeureDeb->setProperty( "control", tr( "GGGG" ) );
    mle_HeureDeb->setProperty( "mask", tr( "__:__" ) );
    textLabel_Au->setProperty( "text", tr( "Au" ) );
    textLabel_a->setProperty( "text", trUtf8( "\x20\xc3\xa0\x20" ) );
    mle_fin->setProperty( "control", tr( "GGGGGGGG" ) );
    mle_fin->setProperty( "mask", tr( "__/__/____" ) );
    pushButtonDateFin->setProperty( "text", QString::null );
    QToolTip::add( pushButtonDateFin, trUtf8( "\x64\xc3\xa9\x66\x69\x6e\x69\x72\x20\x6c\x61\x20\x64\x61\x74\x65\x20\x64\x65\x20\x66"
    "\x69\x6e\x20\x65\x74\x20\x64\x65\x20\x63\x6c\x6f\x74\x75\x72\x65\x20\x64\x65\x73"
    "\x20\x63\x6c\x61\x73\x73\x65\x75\x72\x73\x20\xc3\xa0\x20\x76\x69\x73\x75\x61\x6c"
    "\x69\x73\x65\x72" ) );
    mle_HeureFin->setProperty( "control", tr( "GGGG" ) );
    mle_HeureFin->setProperty( "mask", tr( "__:__" ) );
    pushButtonRaffraichir->setProperty( "text", tr( "Rafraichir &la liste" ) );
    pushButtonRaffraichir->setProperty( "accel", QKeySequence( tr( "Alt+L" ) ) );
    comboBox_Filtre->clear();
    comboBox_Filtre->insertItem( tr( "Tous les patients" ) );
    comboBox_Filtre->insertItem( tr( "Dossier en cours" ) );
    QToolTip::add( comboBox_Filtre, tr( "Fitres d'affichage de la vigie" ) );
    but_ZoomDefault->setProperty( "text", QString::null );
    QToolTip::add( but_ZoomDefault, trUtf8( "\x7a\x6f\x6f\x6d\x20\x70\x61\x72\x20\x64\xc3\xa9\x66\x61\x75\x74" ) );
    but_ConfFiltre_Moins->setProperty( "text", QString::null );
    QToolTip::add( but_ConfFiltre_Moins, trUtf8( "\x53\x75\x70\x70\x72\x69\x6d\x65\x20\x6c\x65\x20\x66\x69\x6c\x74\x72\x65\x20\x61\x66"
    "\x66\x69\x63\x68\xc3\xa9\x20\x61\x63\x74\x75\x65\x6c\x6c\x65\x6d\x65\x6e\x74\x20"
    "\x64\x61\x6e\x73\x20\x6c\x61\x20\x6c\x69\x73\x74\x65\x20\x64\x65\x73\x20\x66\x6c"
    "\x74\x72\x65\x73\x20\x28\x73\x69\x74\x75\xc3\xa9\x65\x20\xc3\xa0\x20\x67\x61\x75"
    "\x63\x68\x65\x29" ) );
    checkBox_filtreActif->setProperty( "text", tr( "Filtres actifs" ) );
    but_ZoomMinus->setProperty( "text", QString::null );
    QToolTip::add( but_ZoomMinus, tr( "Diminue le zoom" ) );
    but_ConfFiltre_Plus->setProperty( "text", QString::null );
    QToolTip::add( but_ConfFiltre_Plus, trUtf8( "\x41\x6a\x6f\x75\x74\x65\x20\x75\x6e\x20\x66\x69\x6c\x74\x72\x65\x20\x64\x61\x6e\x73"
    "\x20\x6c\x61\x20\x6c\x69\x73\x74\x65\x20\x64\x65\x73\x20\x66\x69\x6c\x74\x72\x65"
    "\x73\x20\x28\x73\x69\x74\x75\xc3\xa9\x65\x20\xc3\xa0\x20\x67\x61\x75\x63\x68\x65"
    "\x29" ) );
    but_LoadProfile->setProperty( "text", QString::null );
    QToolTip::add( but_LoadProfile, trUtf8( "\x43\x68\x61\x72\x67\x65\x72\x20\x75\x6e\x20\x70\x72\x6f\x66\x69\x6c\x20\x28\x66\x69"
    "\x6c\x74\x72\x65\x20\x65\x74\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x61\x74\x69\x6f"
    "\x6e\x20\x69\x63\xc3\xb4\x6e\x65\x73\x2c\x20\x6f\x75\x76\x65\x72\x74\x75\x72\x65"
    "\x20\x65\x74\x63\x2e\x2e\x2e\x20\x64\x65\x73\x20\x63\x6c\x61\x73\x73\x65\x75\x72"
    "\x73\x29" ) );
    but_ZoomPlus->setProperty( "text", QString::null );
    QToolTip::add( but_ZoomPlus, tr( "Augmente le zoom" ) );
    but_ConfFiltre->setProperty( "text", QString::null );
    QToolTip::add( but_ConfFiltre, trUtf8( "\x43\x6f\x6e\x66\x69\x67\x75\x72\x65\x20\x6c\x65\x20\x66\x69\x6c\x74\x72\x65\x20\x61"
    "\x66\x66\x69\x63\x68\xc3\xa9\x20\x61\x63\x74\x75\x65\x6c\x6c\x65\x6d\x65\x6e\x74"
    "\x20\x64\x61\x6e\x73\x20\x6c\x61\x20\x6c\x69\x73\x74\x65\x20\x64\x65\x73\x20\x66"
    "\x69\x6c\x74\x72\x65\x73\x20\x28\x73\x69\x74\x75\xc3\xa9\x65\x20\xc3\xa0\x20\x67"
    "\x61\x75\x63\x68\x65\x29" ) );
    but_SaveProfile->setProperty( "text", QString::null );
    QToolTip::add( but_SaveProfile, tr( "Enregistrer un profil de filtres et configuration des classeurs" ) );
    QToolTip::add( comboBox_FiltreVisu, tr( "Filtres de visualisation des classurs" ) );
}

