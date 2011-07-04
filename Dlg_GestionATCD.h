/****************************************************************************
** Form interface generated from reading ui file 'Dlg_GestionATCD.ui'
**
** Created: mer. mai 4 22:17:01 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLG_GESTIONATCD_H
#define DLG_GESTIONATCD_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QSplitter;
class QTabWidget;
class QWidget;
class QListView;
class QListViewItem;
class QLabel;
class QLineEdit;
class QPushButton;
class QComboBox;
class QFrame;

class Dlg_GestionATCD : public QDialog
{
    Q_OBJECT

public:
    Dlg_GestionATCD( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~Dlg_GestionATCD();

    QSplitter* splitter5;
    QTabWidget* tabWidgetDicoATCD;
    QWidget* CIM_10;
    QListView* listViewCim10_Libelles;
    QLabel* textLabel3_2;
    QLineEdit* lineEditAutolcatorLibelle;
    QLabel* textLabel3_3;
    QLineEdit* lineEditAutolcatorLibelle_2;
    QWidget* CIM10_Chapitre;
    QListView* listViewCim10_rubriques;
    QWidget* Allergie;
    QLabel* textLabelStatut;
    QListView* listViewAllergies;
    QLabel* textLabel2;
    QLineEdit* lineEditNomAllergie;
    QListView* listView_Produits;
    QWidget* Thesaurus;
    QListView* listViewThesaurus;
    QLabel* textLabel3;
    QLineEdit* lineEditThesaurusFind1;
    QPushButton* pushButtonThesaurus_Edit;
    QPushButton* pushButtonThesaurusSave;
    QPushButton* pushButtonThesaurusDel;
    QLabel* textLabel1;
    QComboBox* m_Combo_Family;
    QComboBox* m_Combo_Genre;
    QPushButton* pushButtonFamilleGenreEdit;
    QPushButton* pushButtonThesaurusAdd;
    QPushButton* pushButtonThesaurusFreeAdd;
    QPushButton* pushButtonThesaurusExport;
    QPushButton* pushButtonThesaurusImport;
    QPushButton* buttonOk;
    QPushButton* buttonCancel;
    QLabel* textLabelChoix;
    QFrame* frame4;
    QPushButton* pushButtonRemoveFromChoix;
    QPushButton* pushButtonAddMedicament;
    QPushButton* pushButtonAddFreeToChoix;
    QPushButton* pushButton_AddToChoix;
    QPushButton* pushButton_AddToChoixFast;
    QLabel* textLabel1_3;
    QListView* listViewCim10_Choix;

protected:
    QGridLayout* Dlg_GestionATCDLayout;
    QGridLayout* layout13;
    QGridLayout* CIM_10Layout;
    QGridLayout* layout7;
    QGridLayout* layout8;
    QGridLayout* CIM10_ChapitreLayout;
    QGridLayout* AllergieLayout;
    QGridLayout* ThesaurusLayout;
    QHBoxLayout* layout9;
    QHBoxLayout* layout11;
    QHBoxLayout* layout12;
    QSpacerItem* spacer2;
    QGridLayout* layout11_2;
    QHBoxLayout* layout7_2;
    QGridLayout* layout10;
    QGridLayout* layout9_2;
    QGridLayout* frame4Layout;
    QSpacerItem* spacer3;

protected slots:
    virtual void languageChange();

};

#endif // DLG_GESTIONATCD_H
