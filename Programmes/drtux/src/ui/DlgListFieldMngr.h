/****************************************************************************
** Form interface generated from reading ui file 'DlgListFieldMngr.ui'
**
** Created: mer. mai 4 22:17:01 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FORMDLGLISTFIELDMNGR_H
#define FORMDLGLISTFIELDMNGR_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qdialog.h>
#include "Global.h"
#include "../../MedinTuxTools/ThemePopup.h"
#include "../../MedinTuxTools/Theme.h"

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class CW_EditText;
class QSplitter;
class QLineEdit;
class QListView;
class QListViewItem;
class QButtonGroup;
class QPushButton;
class QComboBox;

class FormDlgListFieldMngr : public QDialog
{
    Q_OBJECT

public:
    FormDlgListFieldMngr( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~FormDlgListFieldMngr();

    QSplitter* splitterMedian;
    QLineEdit* lineEditFindItem;
    QListView* listViewList;
    QButtonGroup* buttonGroupJustif;
    QPushButton* pushButtonRight;
    QPushButton* pushButtonCenter;
    QPushButton* pushButtonLeft;
    QButtonGroup* buttonGroupTools;
    QPushButton* pushButtonSave;
    QPushButton* pushButtonSetMasque;
    QPushButton* pushButtonImportMenu;
    QPushButton* pushButtonImportMenuLocalize;
    QPushButton* pushButtonSetTextField;
    QPushButton* pushButtonColor;
    QPushButton* pushButtonUnderline;
    QPushButton* pushButtonItalique;
    QPushButton* pushButtonBold;
    QPushButton* pushButton_InsertImage;
    QComboBox* comboBoxSize;
    QPushButton* pushButton_Quitter;
    QPushButton* pushButton_Ok;
    QComboBox* comboBoxFont;
    CW_EditText* textEditField;

    QListViewItem *m_pQListViewItem;
    QListViewItem* m_OldpQlistViewItem;
    QString m_PathListes;
    QString m_PathDrTux;
    QString m_PathGlossaire;
    QString *m_pRet;
    QString m_PathMenuLib;
    QString m_DrTuxParam;

    virtual QString Slot_ImportMenuModulesLocalize( QString path_in );
    virtual QString GetPathItem( QListViewItem * qlistViewItem );
    virtual QListViewItem * FindDepthItem( QString name, int depth );
    virtual bool IsThisFileNameCompatible( const QString & qsName );
    virtual int DeleteListContent( QString path, QString name_ref );
    virtual bool IsThisFolderExist( const char * path, const char * folderName );
    virtual bool IsThisFileExist( const char * path );
    virtual QListViewItem * FindApproximativeList( const QString & name, int depth );
    virtual QString HtmlToAscii( QString str );

public slots:
    virtual void setReturnVal( QString * ret );
    virtual void setReturnValList( QString * ret );
    virtual void selectAndOpenItem( QString itemName );
    virtual void pushButtonImportMenuLocalize_clicked();
    virtual void pushButtonImportMenu_clicked();
    virtual void initDialog( const QString & drTuxParam, const QString & pathGlossaire, const QString & pathDrTux );
    virtual void accept();
    virtual void reject();
    virtual void setFontEdit( QFont & font );
    virtual void doConnections( QTextEdit * e );
    virtual void fontChanged( const QFont & f );
    virtual void colorChanged( const QColor & c );
    virtual void alignmentChanged( int a );
    virtual void pushButtonUnderline_toggled( bool state );
    virtual void pushButtonItalique_toggled( bool state );
    virtual void pushButtonBold_toggled( bool state );
    virtual void textSize( const QString & p );
    virtual void pushButtonColor_clicked();
    virtual void buttonGroupJustif_pressed( int id );
    virtual void pushButton_InsertImage_clicked();
    virtual void AddSubFolder( QListViewItem * qlistViewItem, QString list_name );
    virtual void MenuActionModifier();
    virtual void listViewList_doubleClicked( QListViewItem * qlistViewItem );
    virtual void textEditField_textChanged();
    virtual void On_lineEditFindItem_F2_Pressed();
    virtual void On_lineEditFindItem_F6_Pressed();
    virtual void listViewList_contextMenuRequested( QListViewItem * qlistViewItem, const QPoint & pos, int v );
    virtual void listViewList_rightButtonClicked( QListViewItem * qlistViewItem, const QPoint & pos, int );
    virtual void MenuActionGotoListe();
    virtual void Slot_RestaureConnection();
    virtual void MenuActionListOffRef();
    virtual void MenuActionNewListe();
    virtual void MenuActionNewRef();
    virtual void ActionNewRef( QString & qsName );
    virtual void ActionCreateNewRef( QString & qsName );
    virtual void MenuActionNewSimple();
    virtual int MenuActionCreateNewSimple( QString qsName, const QString & dirSrc );
    virtual void MenuActionDelete();
    virtual void MenuActionRename();
    virtual void MenuActionIsExist();
    virtual void listViewList_clicked( int button, QListViewItem * qlistViewItem, const QPoint & pos, int c );
    virtual void listViewList_returnPressed( QListViewItem * qlistViewItem );
    virtual void pushButtonSave_clicked();
    virtual bool saveTextIfModified();
    virtual void saveFile( QString path, QString text, QListViewItem * qlistViewItem );
    virtual void lineEditFindItem_textChanged( const QString & qtxt );
    virtual void pushButtonSetMasque_clicked();
    virtual void MenuActionListGet();
    virtual void MenuActionInsertField();
    virtual void MakeInsertFieldList( const char * path, QStringList & fieldList, int mustBeClear );
    virtual void MenuActionListNewRef();
    virtual void listViewList_spacePressed( QListViewItem * pQListViewItem );
    virtual void pushButtonSetTextField_clicked();
    virtual void lineEditFindItem_returnPressed();
    virtual void pushButton_Quitter_clicked();
    virtual void pushButton_Ok_clicked();

protected:
    QGridLayout* FormDlgListFieldMngrLayout;
    QGridLayout* layout6;
    QGridLayout* layout8;
    QGridLayout* layout6_2;
    QGridLayout* buttonGroupJustifLayout;
    QGridLayout* buttonGroupToolsLayout;
    QGridLayout* layout11;
    QSpacerItem* spacer2_2;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;
    QPixmap image1;

    void init();
    void destroy();

};

#endif // FORMDLGLISTFIELDMNGR_H
