/****************************************************************************
** Form implementation generated from reading ui file 'DlgPrint.ui'
**
** Created: mer. mai 4 22:19:21 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "DlgPrint.h"

#include <qvariant.h>
#include <stdlib.h>
#include <qframe.h>
#include <qgroupbox.h>
#include <qslider.h>
#include <qlineedit.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qcheckbox.h>
#include <qcombobox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "../../MedinTuxTools/CPrtQListBoxItem.h"
#include "CDevilCrucible.h"
#include "drtux.h"
#include "CApp.h"
#include "../../MedinTuxTools/CHtmlTools.h"
#include "../DlgPrint.ui.h"

/*
 *  Constructs a DlgPrint as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
DlgPrint::DlgPrint( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setProperty( "name", "DlgPrint" );

    frameToolBar = new QFrame( this, "frameToolBar" );
    frameToolBar->setProperty( "geometry", QRect( 490, 5, 220, 650 ) );
    frameToolBar->setProperty( "frameShape", "StyledPanel" );
    frameToolBar->setProperty( "frameShadow", "Raised" );

    groupBox1 = new QGroupBox( frameToolBar, "groupBox1" );
    groupBox1->setProperty( "geometry", QRect( 5, 45, 210, 360 ) );

    frame4 = new QFrame( groupBox1, "frame4" );
    frame4->setProperty( "geometry", QRect( 10, 25, 190, 45 ) );
    frame4->setProperty( "frameShape", "StyledPanel" );
    frame4->setProperty( "frameShadow", "Raised" );

    slider_Marg_Top = new QSlider( frame4, "slider_Marg_Top" );
    slider_Marg_Top->setProperty( "geometry", QRect( 5, 26, 180, 16 ) );
    QFont slider_Marg_Top_font(  slider_Marg_Top->font() );
    slider_Marg_Top->setFont( slider_Marg_Top_font ); 
    slider_Marg_Top->setProperty( "orientation", "Horizontal" );
    slider_Marg_Top->setProperty( "tickmarks", "NoMarks" );

    lineEdit_Marg_Top = new QLineEdit( frame4, "lineEdit_Marg_Top" );
    lineEdit_Marg_Top->setProperty( "geometry", QRect( 120, 5, 65, 21 ) );

    textLabel1_ = new QLabel( frame4, "textLabel1_" );
    textLabel1_->setProperty( "geometry", QRect( 5, 4, 100, 21 ) );

    frame6 = new QFrame( groupBox1, "frame6" );
    frame6->setProperty( "geometry", QRect( 10, 75, 190, 45 ) );
    frame6->setProperty( "frameShape", "StyledPanel" );
    frame6->setProperty( "frameShadow", "Raised" );

    slider_Head_H = new QSlider( frame6, "slider_Head_H" );
    slider_Head_H->setProperty( "geometry", QRect( 5, 25, 180, 16 ) );
    slider_Head_H->setProperty( "paletteBackgroundColor", QColor( 170, 0, 0 ) );
    slider_Head_H->setProperty( "orientation", "Horizontal" );

    lineEdit_Head_H = new QLineEdit( frame6, "lineEdit_Head_H" );
    lineEdit_Head_H->setProperty( "geometry", QRect( 120, 5, 66, 21 ) );

    textLabel1__2 = new QLabel( frame6, "textLabel1__2" );
    textLabel1__2->setProperty( "geometry", QRect( 5, 5, 110, 17 ) );

    frame7 = new QFrame( groupBox1, "frame7" );
    frame7->setProperty( "geometry", QRect( 10, 125, 190, 45 ) );
    frame7->setProperty( "frameShape", "StyledPanel" );
    frame7->setProperty( "frameShadow", "Raised" );

    slider_Marg_Left = new QSlider( frame7, "slider_Marg_Left" );
    slider_Marg_Left->setProperty( "geometry", QRect( 5, 25, 180, 16 ) );
    slider_Marg_Left->setProperty( "orientation", "Horizontal" );

    lineEdit_Marg_Left = new QLineEdit( frame7, "lineEdit_Marg_Left" );
    lineEdit_Marg_Left->setProperty( "geometry", QRect( 120, 5, 66, 21 ) );

    textLabel1__2_2_3 = new QLabel( frame7, "textLabel1__2_2_3" );
    textLabel1__2_2_3->setProperty( "geometry", QRect( 5, 5, 110, 21 ) );

    frame9 = new QFrame( groupBox1, "frame9" );
    frame9->setProperty( "geometry", QRect( 10, 175, 190, 45 ) );
    frame9->setProperty( "frameShape", "StyledPanel" );
    frame9->setProperty( "frameShadow", "Raised" );

    slider_Marg_Right = new QSlider( frame9, "slider_Marg_Right" );
    slider_Marg_Right->setProperty( "geometry", QRect( 5, 25, 180, 16 ) );
    slider_Marg_Right->setProperty( "orientation", "Horizontal" );

    lineEdit_Marg_Right = new QLineEdit( frame9, "lineEdit_Marg_Right" );
    lineEdit_Marg_Right->setProperty( "geometry", QRect( 120, 5, 66, 21 ) );

    textLabel1__2_2_3_2 = new QLabel( frame9, "textLabel1__2_2_3_2" );
    textLabel1__2_2_3_2->setProperty( "geometry", QRect( 5, 5, 110, 21 ) );

    frame11 = new QFrame( groupBox1, "frame11" );
    frame11->setProperty( "geometry", QRect( 10, 275, 190, 45 ) );
    frame11->setProperty( "frameShape", "StyledPanel" );
    frame11->setProperty( "frameShadow", "Raised" );

    slider_Marg_Bottom = new QSlider( frame11, "slider_Marg_Bottom" );
    slider_Marg_Bottom->setProperty( "geometry", QRect( 5, 25, 180, 16 ) );
    slider_Marg_Bottom->setProperty( "orientation", "Horizontal" );

    lineEdit_Marg_Bottom = new QLineEdit( frame11, "lineEdit_Marg_Bottom" );
    lineEdit_Marg_Bottom->setProperty( "geometry", QRect( 120, 5, 66, 21 ) );

    textLabel1__2_2_2 = new QLabel( frame11, "textLabel1__2_2_2" );
    textLabel1__2_2_2->setProperty( "geometry", QRect( 5, 5, 110, 21 ) );

    frame10 = new QFrame( groupBox1, "frame10" );
    frame10->setProperty( "geometry", QRect( 10, 225, 190, 45 ) );
    frame10->setProperty( "frameShape", "StyledPanel" );
    frame10->setProperty( "frameShadow", "Raised" );

    slider_Foot_H = new QSlider( frame10, "slider_Foot_H" );
    slider_Foot_H->setProperty( "geometry", QRect( 5, 25, 180, 16 ) );
    slider_Foot_H->setProperty( "paletteBackgroundColor", QColor( 170, 0, 0 ) );
    slider_Foot_H->setProperty( "orientation", "Horizontal" );

    lineEdit_Foot_H = new QLineEdit( frame10, "lineEdit_Foot_H" );
    lineEdit_Foot_H->setProperty( "geometry", QRect( 120, 5, 66, 21 ) );

    textLabel1__2_2 = new QLabel( frame10, "textLabel1__2_2" );
    textLabel1__2_2->setProperty( "geometry", QRect( 5, 5, 110, 17 ) );

    lineEditResoX = new QLineEdit( groupBox1, "lineEditResoX" );
    lineEditResoX->setProperty( "geometry", QRect( 130, 323, 40, 17 ) );
    QFont lineEditResoX_font(  lineEditResoX->font() );
    lineEditResoX_font.setPointSize( 7 );
    lineEditResoX->setFont( lineEditResoX_font ); 

    lineEditResoY = new QLineEdit( groupBox1, "lineEditResoY" );
    lineEditResoY->setProperty( "geometry", QRect( 130, 340, 40, 17 ) );
    QFont lineEditResoY_font(  lineEditResoY->font() );
    lineEditResoY_font.setPointSize( 7 );
    lineEditResoY->setFont( lineEditResoY_font ); 

    textLabel1__2_2_2_2_2 = new QLabel( groupBox1, "textLabel1__2_2_2_2_2" );
    textLabel1__2_2_2_2_2->setProperty( "geometry", QRect( 175, 325, 25, 30 ) );
    QFont textLabel1__2_2_2_2_2_font(  textLabel1__2_2_2_2_2->font() );
    textLabel1__2_2_2_2_2_font.setPointSize( 7 );
    textLabel1__2_2_2_2_2->setFont( textLabel1__2_2_2_2_2_font ); 
    textLabel1__2_2_2_2_2->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignCenter ) );

    textLabel1__2_2_2_2 = new QLabel( groupBox1, "textLabel1__2_2_2_2" );
    textLabel1__2_2_2_2->setProperty( "geometry", QRect( 50, 325, 55, 30 ) );
    QFont textLabel1__2_2_2_2_font(  textLabel1__2_2_2_2->font() );
    textLabel1__2_2_2_2_font.setPointSize( 7 );
    textLabel1__2_2_2_2->setFont( textLabel1__2_2_2_2_font ); 
    textLabel1__2_2_2_2->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignVCenter ) );

    textLabel1__2_2_2_2_3_2 = new QLabel( groupBox1, "textLabel1__2_2_2_2_3_2" );
    textLabel1__2_2_2_2_3_2->setProperty( "geometry", QRect( 105, 325, 20, 17 ) );
    QFont textLabel1__2_2_2_2_3_2_font(  textLabel1__2_2_2_2_3_2->font() );
    textLabel1__2_2_2_2_3_2_font.setPointSize( 7 );
    textLabel1__2_2_2_2_3_2->setFont( textLabel1__2_2_2_2_3_2_font ); 
    textLabel1__2_2_2_2_3_2->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignCenter ) );

    textLabel1__2_2_2_2_3 = new QLabel( groupBox1, "textLabel1__2_2_2_2_3" );
    textLabel1__2_2_2_2_3->setProperty( "geometry", QRect( 105, 340, 20, 17 ) );
    QFont textLabel1__2_2_2_2_3_font(  textLabel1__2_2_2_2_3->font() );
    textLabel1__2_2_2_2_3_font.setPointSize( 7 );
    textLabel1__2_2_2_2_3->setFont( textLabel1__2_2_2_2_3_font ); 
    textLabel1__2_2_2_2_3->setProperty( "alignment", int( QLabel::WordBreak | QLabel::AlignCenter ) );

    pushButtonSave = new QPushButton( groupBox1, "pushButtonSave" );
    pushButtonSave->setProperty( "geometry", QRect( 7, 325, 30, 30 ) );
    pushButtonSave->setProperty( "maximumSize", QSize( 32, 32767 ) );

    textLabel_NbPage = new QLabel( frameToolBar, "textLabel_NbPage" );
    textLabel_NbPage->setProperty( "geometry", QRect( 45, 10, 135, 25 ) );
    textLabel_NbPage->setProperty( "frameShape", "ToolBarPanel" );
    textLabel_NbPage->setProperty( "alignment", int( QLabel::AlignCenter ) );

    groupBox2 = new QGroupBox( frameToolBar, "groupBox2" );
    groupBox2->setProperty( "geometry", QRect( 5, 480, 210, 125 ) );

    textLabel1__2_2_3_3_2 = new QLabel( groupBox2, "textLabel1__2_2_3_3_2" );
    textLabel1__2_2_3_3_2->setProperty( "geometry", QRect( 155, 40, 30, 21 ) );

    lineEditZoom = new QLineEdit( groupBox2, "lineEditZoom" );
    lineEditZoom->setProperty( "geometry", QRect( 75, 40, 70, 20 ) );

    lineEdit_PageDeb = new QLineEdit( groupBox2, "lineEdit_PageDeb" );
    lineEdit_PageDeb->setProperty( "geometry", QRect( 100, 95, 35, 21 ) );

    lineEdit_PageFin = new QLineEdit( groupBox2, "lineEdit_PageFin" );
    lineEdit_PageFin->setProperty( "geometry", QRect( 160, 95, 35, 21 ) );

    textLabel_2 = new QLabel( groupBox2, "textLabel_2" );
    textLabel_2->setProperty( "geometry", QRect( 10, 95, 85, 20 ) );

    textLabel_2_2 = new QLabel( groupBox2, "textLabel_2_2" );
    textLabel_2_2->setProperty( "geometry", QRect( 140, 95, 20, 20 ) );

    textLabel1__2_2_3_3 = new QLabel( groupBox2, "textLabel1__2_2_3_3" );
    textLabel1__2_2_3_3->setProperty( "geometry", QRect( 27, 40, 45, 21 ) );

    pushButtonPrint_2 = new QPushButton( groupBox2, "pushButtonPrint_2" );
    pushButtonPrint_2->setProperty( "geometry", QRect( 105, 60, 35, 30 ) );
    pushButtonPrint_2->setProperty( "autoDefault", QVariant( TRUE, 0 ) );
    pushButtonPrint_2->setProperty( "default", QVariant( TRUE, 0 ) );

    pushButtonPrint_2_2 = new QPushButton( groupBox2, "pushButtonPrint_2_2" );
    pushButtonPrint_2_2->setProperty( "geometry", QRect( 140, 60, 35, 30 ) );
    pushButtonPrint_2_2->setProperty( "autoDefault", QVariant( TRUE, 0 ) );
    pushButtonPrint_2_2->setProperty( "default", QVariant( TRUE, 0 ) );

    pushButtonConfigurer = new QPushButton( groupBox2, "pushButtonConfigurer" );
    pushButtonConfigurer->setProperty( "geometry", QRect( 20, 15, 170, 20 ) );

    pushButtonPrint = new QPushButton( groupBox2, "pushButtonPrint" );
    pushButtonPrint->setProperty( "geometry", QRect( 15, 60, 90, 30 ) );
    pushButtonPrint->setProperty( "autoDefault", QVariant( TRUE, 0 ) );
    pushButtonPrint->setProperty( "default", QVariant( TRUE, 0 ) );

    checkBox_Duplicata = new QCheckBox( frameToolBar, "checkBox_Duplicata" );
    checkBox_Duplicata->setProperty( "geometry", QRect( 10, 415, 200, 16 ) );

    checkBox_PrintDuplicata = new QCheckBox( frameToolBar, "checkBox_PrintDuplicata" );
    checkBox_PrintDuplicata->setProperty( "geometry", QRect( 10, 435, 200, 16 ) );

    pushButtonPrevious = new QPushButton( frameToolBar, "pushButtonPrevious" );
    pushButtonPrevious->setProperty( "geometry", QRect( 5, 5, 36, 35 ) );

    pushButtonNext = new QPushButton( frameToolBar, "pushButtonNext" );
    pushButtonNext->setProperty( "geometry", QRect( 180, 5, 36, 35 ) );

    comboBox_TypeDoc = new QComboBox( FALSE, frameToolBar, "comboBox_TypeDoc" );
    comboBox_TypeDoc->setProperty( "geometry", QRect( 5, 455, 210, 28 ) );
    comboBox_TypeDoc->setProperty( "minimumSize", QSize( 0, 22 ) );
    comboBox_TypeDoc->setProperty( "maximumSize", QSize( 250, 28 ) );
    QFont comboBox_TypeDoc_font(  comboBox_TypeDoc->font() );
    comboBox_TypeDoc->setFont( comboBox_TypeDoc_font ); 

    pushButtonQuitter = new QPushButton( frameToolBar, "pushButtonQuitter" );
    pushButtonQuitter->setProperty( "geometry", QRect( 5, 610, 210, 35 ) );
    languageChange();
    resize( QSize(711, 698).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( slider_Marg_Top, SIGNAL( sliderMoved(int) ), this, SLOT( slider_Marg_Top_sliderMoved(int) ) );
    connect( slider_Head_H, SIGNAL( sliderMoved(int) ), this, SLOT( slider_Head_H_sliderMoved(int) ) );
    connect( slider_Marg_Left, SIGNAL( sliderMoved(int) ), this, SLOT( slider_Marg_Left_sliderMoved(int) ) );
    connect( slider_Marg_Right, SIGNAL( sliderMoved(int) ), this, SLOT( slider_Marg_Right_sliderMoved(int) ) );
    connect( slider_Foot_H, SIGNAL( sliderMoved(int) ), this, SLOT( slider_Foot_H_sliderMoved(int) ) );
    connect( slider_Marg_Bottom, SIGNAL( sliderMoved(int) ), this, SLOT( slider_Marg_Bottom_sliderMoved(int) ) );
    connect( pushButtonPrint, SIGNAL( clicked() ), this, SLOT( pushButtonPrint_clicked() ) );
    connect( pushButtonQuitter, SIGNAL( clicked() ), this, SLOT( pushButtonQuitter_clicked() ) );
    connect( pushButtonConfigurer, SIGNAL( clicked() ), this, SLOT( pushButtonConfigurer_clicked() ) );
    connect( pushButtonPrevious, SIGNAL( clicked() ), this, SLOT( pushButtonPrevious_clicked() ) );
    connect( pushButtonNext, SIGNAL( clicked() ), this, SLOT( pushButtonNext_clicked() ) );
    connect( comboBox_TypeDoc, SIGNAL( activated(const QString&) ), this, SLOT( comboBox_TypeDoc_activated(const QString&) ) );
    connect( checkBox_Duplicata, SIGNAL( stateChanged(int) ), this, SLOT( checkBox_Duplicata_stateChanged(int) ) );
    connect( pushButtonSave, SIGNAL( clicked() ), this, SLOT( pushButtonSave_clicked() ) );
    connect( pushButtonPrint_2, SIGNAL( clicked() ), this, SLOT( pushButtonPrint_2_clicked() ) );
    connect( pushButtonPrint_2_2, SIGNAL( clicked() ), this, SLOT( pushButtonPrint_2_2_clicked() ) );

    // tab order
    setTabOrder( pushButtonPrevious, pushButtonNext );
    setTabOrder( pushButtonNext, lineEdit_Marg_Top );
    setTabOrder( lineEdit_Marg_Top, slider_Marg_Top );
    setTabOrder( slider_Marg_Top, lineEdit_Head_H );
    setTabOrder( lineEdit_Head_H, slider_Head_H );
    setTabOrder( slider_Head_H, lineEdit_Marg_Left );
    setTabOrder( lineEdit_Marg_Left, slider_Marg_Left );
    setTabOrder( slider_Marg_Left, lineEdit_Marg_Right );
    setTabOrder( lineEdit_Marg_Right, slider_Marg_Right );
    setTabOrder( slider_Marg_Right, lineEdit_Foot_H );
    setTabOrder( lineEdit_Foot_H, slider_Foot_H );
    setTabOrder( slider_Foot_H, lineEdit_Marg_Bottom );
    setTabOrder( lineEdit_Marg_Bottom, slider_Marg_Bottom );
    setTabOrder( slider_Marg_Bottom, pushButtonSave );
    setTabOrder( pushButtonSave, lineEditResoX );
    setTabOrder( lineEditResoX, lineEditResoY );
    setTabOrder( lineEditResoY, checkBox_Duplicata );
    setTabOrder( checkBox_Duplicata, comboBox_TypeDoc );
    setTabOrder( comboBox_TypeDoc, pushButtonConfigurer );
    setTabOrder( pushButtonConfigurer, lineEditZoom );
    setTabOrder( lineEditZoom, pushButtonPrint );
    setTabOrder( pushButtonPrint, lineEdit_PageDeb );
    setTabOrder( lineEdit_PageDeb, lineEdit_PageFin );
    setTabOrder( lineEdit_PageFin, pushButtonQuitter );

    // buddies
    textLabel1_->setBuddy( lineEdit_Marg_Top );
    textLabel1__2->setBuddy( lineEdit_Head_H );
    textLabel1__2_2_3->setBuddy( lineEdit_Marg_Left );
    textLabel1__2_2_3_2->setBuddy( lineEdit_Marg_Right );
    textLabel1__2_2_2->setBuddy( lineEdit_Marg_Bottom );
    textLabel1__2_2->setBuddy( lineEdit_Foot_H );
    textLabel1__2_2_2_2_3_2->setBuddy( lineEditResoX );
    textLabel1__2_2_2_2_3->setBuddy( lineEditResoY );
    textLabel_2->setBuddy( lineEdit_PageDeb );
    textLabel_2_2->setBuddy( lineEdit_PageFin );
    textLabel1__2_2_3_3->setBuddy( lineEditZoom );
    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
DlgPrint::~DlgPrint()
{
    destroy();
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void DlgPrint::languageChange()
{
    setProperty( "caption", tr( "Impression" ) );
    groupBox1->setProperty( "title", tr( "Mise en page" ) );
    textLabel1_->setProperty( "text", tr( "Marge &haute" ) );
    textLabel1__2->setProperty( "text", trUtf8( "\x48\x61\x75\x74\x65\x75\x72\x20\x65\x6e\x2d\x26\x74\xc3\xaa\x74\x65" ) );
    textLabel1__2_2_3->setProperty( "text", tr( "Marge &gauche" ) );
    textLabel1__2_2_3_2->setProperty( "text", tr( "Marge &droite" ) );
    textLabel1__2_2_2->setProperty( "text", tr( "Marge &basse" ) );
    textLabel1__2_2->setProperty( "text", tr( "Hauteur du &pied" ) );
    lineEditResoX->setProperty( "text", tr( "96" ) );
    lineEditResoY->setProperty( "text", tr( "96" ) );
    textLabel1__2_2_2_2_2->setProperty( "text", tr( "DPI" ) );
    textLabel1__2_2_2_2->setProperty( "text", trUtf8( "\x52\xc3\xa9\x73\x6f\x6c\x75\x74\x69\x6f\x6e\x20\x20\x69\x6d\x70\x72\x69\x6d\x61\x6e"
    "\x74\x65" ) );
    textLabel1__2_2_2_2_3_2->setProperty( "text", tr( "&X" ) );
    textLabel1__2_2_2_2_3->setProperty( "text", tr( "&Y" ) );
    pushButtonSave->setProperty( "text", QString::null );
    QToolTip::add( pushButtonSave, trUtf8( "\x50\x65\x72\x6d\x65\x74\x20\x64\x27\x65\x6e\x72\x65\x67\x69\x73\x74\x72\x65\x72\x20"
    "\x6c\x65\x73\x20\x6d\x6f\x64\x69\x66\x69\x63\x61\x74\x69\x6f\x6e\x73\x20\x64\x65"
    "\x73\x20\x70\x61\x72\x61\x6d\xc3\xa8\x74\x72\x65\x73\x20\x64\x27\x69\x6d\x70\x72"
    "\x65\x73\x73\x69\x6f\x6e" ) );
    QWhatsThis::add( pushButtonSave, trUtf8( "\x50\x65\x72\x6d\x65\x74\x20\x64\x27\x65\x6e\x72\x65\x67\x69\x73\x74\x72\x65\x72\x20"
    "\x6c\x65\x73\x20\x6d\x6f\x64\x69\x66\x69\x63\x61\x74\x69\x6f\x6e\x73\x20\x64\x65"
    "\x73\x20\x70\x61\x72\x61\x6d\xc3\xa8\x74\x72\x65\x73\x20\x64\x27\x69\x6d\x70\x72"
    "\x65\x73\x73\x69\x6f\x6e" ) );
    groupBox2->setProperty( "title", tr( "Impression" ) );
    textLabel1__2_2_3_3_2->setProperty( "text", tr( "%" ) );
    lineEdit_PageDeb->setProperty( "text", QString::null );
    lineEdit_PageFin->setProperty( "text", QString::null );
    textLabel_2->setProperty( "text", tr( "D&e la page :" ) );
    textLabel_2_2->setProperty( "text", trUtf8( "\x26\xc3\xa0\x20\x3a" ) );
    textLabel1__2_2_3_3->setProperty( "text", tr( "&Taille" ) );
    pushButtonPrint_2->setProperty( "text", tr( "X &1" ) );
    pushButtonPrint_2->setProperty( "accel", QKeySequence( tr( "Alt+1" ) ) );
    QToolTip::add( pushButtonPrint_2, tr( "Imprimer un exemplaire" ) );
    QWhatsThis::add( pushButtonPrint_2, tr( "Imprimer un exemplaire" ) );
    pushButtonPrint_2_2->setProperty( "text", tr( "X &2" ) );
    pushButtonPrint_2_2->setProperty( "accel", QKeySequence( tr( "Alt+2" ) ) );
    QToolTip::add( pushButtonPrint_2_2, tr( "Imprimer deux exemplaires" ) );
    QWhatsThis::add( pushButtonPrint_2_2, tr( "Imprimer deux exemplaires" ) );
    pushButtonConfigurer->setProperty( "text", tr( "&Configurer" ) );
    pushButtonConfigurer->setProperty( "accel", QKeySequence( tr( "Alt+C" ) ) );
    QToolTip::add( pushButtonConfigurer, trUtf8( "\x43\x6f\x6e\x66\x69\x67\x75\x72\x65\x72\x20\x71\x75\x65\x6c\x71\x75\x65\x73\x20\x70"
    "\x61\x72\x61\x6d\xc3\xa8\x74\x72\x65\x73\x20\x64\x27\x69\x6d\x70\x72\x65\x73\x73"
    "\x69\x6f\x6e\x2e" ) );
    pushButtonPrint->setProperty( "text", tr( "&Imprimer" ) );
    pushButtonPrint->setProperty( "accel", QKeySequence( tr( "Alt+I" ) ) );
    QToolTip::add( pushButtonPrint, trUtf8( "\x49\x6d\x70\x72\x69\x6d\x65\x72\x20\x61\x76\x65\x63\x20\x6c\x65\x20\x6e\x6f\x6d\x62"
    "\x72\x65\x20\x64\x27\x65\x78\x65\x6d\x70\x6c\x61\x69\x72\x65\x73\x20\x70\x61\x72"
    "\x20\x64\xc3\xa9\x66\x61\x75\x74\x20\x28\x62\x6f\x75\x74\x6f\x6e\x20\x43\x6f\x6e"
    "\x66\x69\x67\x75\x72\x65\x72\x29" ) );
    QWhatsThis::add( pushButtonPrint, trUtf8( "\x49\x6d\x70\x72\x69\x6d\x65\x72\x20\x61\x76\x65\x63\x20\x6c\x65\x20\x6e\x6f\x6d\x62"
    "\x72\x65\x20\x64\x27\x65\x78\x65\x6d\x70\x6c\x61\x69\x72\x65\x73\x20\x70\x61\x72"
    "\x20\x64\xc3\xa9\x66\x61\x75\x74\x20\x28\x62\x6f\x75\x74\x6f\x6e\x20\x43\x6f\x6e"
    "\x66\x69\x67\x75\x72\x65\x72\x29" ) );
    checkBox_Duplicata->setProperty( "text", tr( "&Voir le duplicata" ) );
    checkBox_Duplicata->setProperty( "accel", QKeySequence( tr( "Alt+V" ) ) );
    checkBox_PrintDuplicata->setProperty( "text", tr( "Imprimer le d&uplicata" ) );
    checkBox_PrintDuplicata->setProperty( "accel", QKeySequence( tr( "Alt+U" ) ) );
    pushButtonPrevious->setProperty( "text", QString::null );
    QToolTip::add( pushButtonPrevious, trUtf8( "\x56\x69\x73\x75\x61\x6c\x69\x73\x65\x72\x20\x6c\x61\x20\x70\x61\x67\x65\x20\x70\x72"
    "\xc3\xa9\x63\xc3\xa9\x64\x65\x6e\x74\x65\x2e" ) );
    pushButtonNext->setProperty( "text", QString::null );
    QToolTip::add( pushButtonNext, tr( "Visualiser la page suivante." ) );
    QToolTip::add( comboBox_TypeDoc, trUtf8( "\x53\xc3\xa9\x6c\x65\x63\x74\x69\x6f\x6e\x6e\x65\x72\x20\x75\x6e\x20\x65\x6e\x2d\x74"
    "\xc3\xaa\x74\x65\x20\x65\x74\x20\x70\x69\x65\x64\x20\x64\x65\x20\x70\x61\x67\x65"
    "\x2e" ) );
    pushButtonQuitter->setProperty( "text", tr( "&Quitter" ) );
    pushButtonQuitter->setProperty( "accel", QKeySequence( tr( "Alt+Q" ) ) );
    QToolTip::add( pushButtonQuitter, tr( "Quitter sans imprimer." ) );
}

