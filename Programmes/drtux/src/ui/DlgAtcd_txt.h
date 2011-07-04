/****************************************************************************
** Form interface generated from reading ui file 'DlgAtcd_txt.ui'
**
** Created: mer. mai 4 22:17:01 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLGATCD_TXT_H
#define DLGATCD_TXT_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qdialog.h>
#include <qdatetime.h>
#include <qstringlist.h>
#include "Global.h"
#include "C_Atcd.h"

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class CMaskedLineEdit;
class QFrame;
class QLabel;
class QPushButton;
class QCheckBox;
class QLineEdit;
class QComboBox;
class Atcd_Element;
class Atcd_Code;

class DlgAtcd_txt : public QDialog
{
    Q_OBJECT

public:
    DlgAtcd_txt( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~DlgAtcd_txt();

    QFrame* line1;
    QLabel* lbl_Titre;
    QPushButton* but_Annuler;
    QPushButton* but_Valider;
    QCheckBox* checkBox_IsALD;
    QCheckBox* checkBox_IsActif;
    QLineEdit* m_LineEdit_Commentaire;
    QLabel* textLabel_Commentaire;
    QCheckBox* chkDate;
    QLabel* textLabel_Libelle;
    QLineEdit* m_LineEdit_Libelle;
    QLabel* textLabel_Libelle_Long;
    QLineEdit* m_LineEdit_Libelle_Long;
    QLabel* textLabel3_2;
    QPushButton* pushButtonFamilleGenreEdit;
    QLabel* textLabel3;
    QComboBox* m_Combo_Family;
    QComboBox* m_Combo_Genre;
    QLabel* textLabel_date;
    CMaskedLineEdit* cMaskedLineDateAtcd;
    QPushButton* pushButtonDateDlg;

    bool m_toViewOnly;
    QStringList m_ATCD_FamilyList;
    QStringList m_ATCD_GenreList;
    QString m_structStr;

    virtual bool isFamilleGenreModified();
    virtual void setComboOnValue( QComboBox * pQComboBox, const QString & value );
    virtual bool isALD();
    virtual QString GetALD();
    virtual bool isActif();
    virtual QString getEtatGueriActif();
    virtual QString getFamilleGenre();
    virtual QString getDateObserv();
    virtual QString getDateObserv_ISODate();

public slots:
    virtual void Slot_pushButtonDateDlg();
    virtual void Slot_pushButtonFamilleGenreEdit();
    virtual void setDialogForAddToThesaurus();
    virtual void setComboFamilyGenre();
    virtual void setATCD_toView( Atcd_Code * pAtcd_Code, Atcd_Element * atcd );
    virtual void setFamilyGenre( QString familyGenre );
    virtual void setToUpdate( bool b );
    virtual void getInfos( QString & libelle, QString & family, QString & date, QString & commentaire );
    virtual QString getDate();
    virtual void setDateObserv( QString dt_str );
    virtual void setDateObserv( QDate dt );
    virtual void but_Valider_clicked();
    virtual void but_Annuler_clicked();
    virtual void comboBox_Family_highlighted( const QString & section );
    virtual void combo_Family_activated( int );
    virtual void combo_Genre_activated( int );
    virtual void chkDate_clicked();

protected:
    bool m_isFamilleGenreModified;

    QGridLayout* DlgAtcd_txtLayout;
    QGridLayout* layout6;
    QSpacerItem* spacer1;
    QGridLayout* layout6_2;
    QGridLayout* layout18;
    QGridLayout* layout21;
    QGridLayout* layout21_2;
    QGridLayout* layout9;
    QHBoxLayout* layout8;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;

    void init();

};

#endif // DLGATCD_TXT_H
