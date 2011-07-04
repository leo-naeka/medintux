/****************************************************************************
** Form interface generated from reading ui file '../../MedinTuxTools/Form_Organiseur.ui'
**
** Created: mer. mai 4 22:17:01 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FORM_ORGANISEUR_H
#define FORM_ORGANISEUR_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class CMaskedLineEdit;
class QFrame;
class QPushButton;
class QListView;
class QListViewItem;
class QLabel;
class QComboBox;
class QCheckBox;

class Form_Organiseur : public QWidget
{
    Q_OBJECT

public:
    Form_Organiseur( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Form_Organiseur();

    QFrame* Form_OrganiseurQFrame;
    QPushButton* but_ConfFiltre_HideShow;
    QFrame* frame_ListView;
    QListView* listView2;
    QFrame* frame_ConfigHeader;
    QLabel* textLabel_Du;
    QLabel* textLabel_De;
    CMaskedLineEdit* mle_deb;
    QPushButton* pushButtonDateDeb;
    CMaskedLineEdit* mle_HeureDeb;
    QLabel* textLabel_Au;
    QLabel* textLabel_a;
    CMaskedLineEdit* mle_fin;
    QPushButton* pushButtonDateFin;
    CMaskedLineEdit* mle_HeureFin;
    QPushButton* pushButtonRaffraichir;
    QComboBox* comboBox_Filtre;
    QPushButton* but_ZoomDefault;
    QPushButton* but_ConfFiltre_Moins;
    QCheckBox* checkBox_filtreActif;
    QPushButton* but_ZoomMinus;
    QPushButton* but_ConfFiltre_Plus;
    QPushButton* but_LoadProfile;
    QPushButton* but_ZoomPlus;
    QPushButton* but_ConfFiltre;
    QPushButton* but_SaveProfile;
    QComboBox* comboBox_FiltreVisu;

protected:
    QGridLayout* Form_OrganiseurLayout;
    QGridLayout* Form_OrganiseurQFrameLayout;
    QGridLayout* layout12;
    QGridLayout* frame_ListViewLayout;
    QGridLayout* frame_ConfigHeaderLayout;
    QGridLayout* layout15;
    QHBoxLayout* layout12_2;
    QVBoxLayout* layout25;
    QVBoxLayout* layout22;
    QHBoxLayout* layout3;
    QVBoxLayout* layout24;
    QVBoxLayout* layout23;
    QHBoxLayout* layout4;
    QGridLayout* layout13;
    QGridLayout* layout12_3;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;

};

#endif // FORM_ORGANISEUR_H
