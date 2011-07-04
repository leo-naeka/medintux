/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you want to add, delete, or rename functions or slots, use
** Qt Designer to update this file, preserving your code.
**
** You should not define a constructor or destructor in this file.
** Instead, write your code in functions called init() and destroy().
** These will automatically be called by the form's constructor and
** destructor.
*****************************************************************************/

#define TR	QObject::tr
#include "CApp.h"
#include <qdatetime.h>
#include <qdatetimeedit.h>
#include <qlistbox.h>
#include "../../MedinTuxTools/CGestIni.h"
#include "../../MedinTuxTools/CMaskedLineEdit.h"
#include "ui/Dlg_Calendar.h"
#include "../../MedinTuxTools/Theme.h"  // Gestion du thème de l'appli


#include "C_Dlg_FamilleGenre.h"
//--------------------------------- init -------------------------------------------------------------
void DlgAtcd_txt::init()
{ // initialise le combo des années
 setDateObserv(QDate::currentDate());
 m_ATCD_FamilyList.clear();
 m_ATCD_GenreList.clear();
 m_toViewOnly             = FALSE;
 m_isFamilleGenreModified = FALSE;
 pushButtonFamilleGenreEdit->setPixmap(Theme::getIcon( "16x16/configure.png"));
 line1->setFrameStyle ( QFrame::HLine );
 line1->setFrameShadow (QFrame::Sunken );
 m_LineEdit_Libelle->setFocus();
 CGestIni::Param_UpdateFromDisk(G_pCApp->m_PathAppli + "Ressources/MenuATCD.txt", m_structStr);
 connect( m_Combo_Family, SIGNAL( highlighted(const QString & ) ), this,    SLOT( comboBox_Family_highlighted(const QString &) ) );
 connect( pushButtonFamilleGenreEdit,  SIGNAL( clicked() ),        this,    SLOT( Slot_pushButtonFamilleGenreEdit() ) );
 setComboFamilyGenre();
 textLabel_Libelle_Long->hide();
 m_LineEdit_Libelle_Long->hide();
 pushButtonDateDlg->setIconSet( Theme::getIconSet("16x16/calendrierDeb.png"));
 connect( pushButtonDateDlg, SIGNAL( clicked()),  this,  SLOT  ( Slot_pushButtonDateDlg())  );
}

//------------------------------- Slot_pushButtonDateDlg -------------------------------------
void DlgAtcd_txt::Slot_pushButtonDateDlg()
{
        Dlg_Calendar          *dlg  = new Dlg_Calendar(this, "Calendar_Dial", FALSE);
        if (dlg ==0)                                                   return;
        dlg->setCaption(tr("Date et heure"));
        if ( ! dlg->setDateTimeNatural_jjMMyyyy_Order(cMaskedLineDateAtcd->text() + "00:00:00" ))
           {dlg->setDate  (QDate::currentDate());
           }
        dlg->hideHeure();
        if (dlg->exec()== QDialog::Accepted )
           {cMaskedLineDateAtcd->setText(dlg->getDate().toString("ddMMyyyy"));
           }
        delete dlg;
}

//--------------------------------- Slot_pushButtonFamilleGenreEdit -------------------------------------------------------------
bool DlgAtcd_txt::isFamilleGenreModified()
{return m_isFamilleGenreModified;
}

//--------------------------------- Slot_pushButtonFamilleGenreEdit -------------------------------------------------------------
void DlgAtcd_txt::Slot_pushButtonFamilleGenreEdit()
{ C_Dlg_FamilleGenre *pC_Dlg_FamilleGenre = new C_Dlg_FamilleGenre(&m_structStr, this); if (pC_Dlg_FamilleGenre==0) return;
  pC_Dlg_FamilleGenre->exec();
  if (pC_Dlg_FamilleGenre->isModified())
     {setComboFamilyGenre();
      m_isFamilleGenreModified = TRUE;
     }
  delete pC_Dlg_FamilleGenre;
}

//--------------------------------- setDialogForAddToThesaurus -------------------------------------------------------------
void DlgAtcd_txt::setDialogForAddToThesaurus()
{lbl_Titre->setText(tr("<b>Définir le libellé usuel, la famille et le genre</b>"));
 textLabel_Libelle->setText(tr("Libellé usuel "));
 chkDate->hide();
 textLabel_date->hide();
 cMaskedLineDateAtcd->hide();
 pushButtonDateDlg->hide();
 textLabel_Commentaire->hide();
 m_LineEdit_Commentaire->hide();
 checkBox_IsALD->hide();
 checkBox_IsActif->hide();
 textLabel_Libelle_Long->show();
 m_LineEdit_Libelle_Long->show();
 setCaption (tr("Ajouter un élément au thésaurus"));
}

//--------------------------------- setComboOnValue -------------------------------------------------------------
void DlgAtcd_txt::setComboOnValue(QComboBox *pQComboBox, const QString &value)
{if (value.length() == 0)                                                                              return;
 QListBox     *pQListBox      = pQComboBox->listBox ();                        if (pQListBox     == 0) return;
 QListBoxItem *pQListBoxItem  = pQListBox->findItem ( value, Qt::ExactMatch ); if (pQListBoxItem == 0) return;

 pQListBox->setCurrentItem ( pQListBoxItem );
 pQComboBox->setCurrentItem ( pQListBox->index ( pQListBoxItem) );
}
//--------------------------------- isALD -------------------------------------------------------------
bool DlgAtcd_txt::isALD()
{return checkBox_IsALD->isChecked();
}

//--------------------------------- GetALD -------------------------------------------------------------
QString DlgAtcd_txt::GetALD()
{return (isALD() ? QString("ALD"):QString(""));
}

//--------------------------------- isActif -------------------------------------------------------------
bool DlgAtcd_txt::isActif()
{return checkBox_IsActif->isChecked();
}
//--------------------------------- getEtatGueriActif -------------------------------------------------------------
QString DlgAtcd_txt::getEtatGueriActif()
{return (checkBox_IsActif->isChecked() ? tr("Actif"):tr("Passé"));
}
//--------------------------------- setComboFamilyGenre -------------------------------------------------------------
void DlgAtcd_txt::setComboFamilyGenre()
{m_ATCD_FamilyList.clear();
 QString menuStr        = m_structStr;
 QString section        = "";
 int posDebSection      = -1;
 int posEndSection      = 0;
 while ( (posDebSection = menuStr.find("[",posEndSection)) != -1 )
    {++posDebSection;
     if ( (posEndSection = menuStr.find("]",posDebSection)) != -1 )
        {section = menuStr.mid(posDebSection,posEndSection-posDebSection).stripWhiteSpace();
         if (section.length())
            {m_ATCD_FamilyList<<section;
            }
        }
    }
 m_Combo_Family->clear();
 m_Combo_Family->setCurrentItem(0);
 m_Combo_Family->insertStringList(  m_ATCD_FamilyList );
 comboBox_Family_highlighted(       m_Combo_Family->text ( 0 )  );
}

//--------------------------------- setATCD_toView -------------------------------------------------------------
void DlgAtcd_txt::setATCD_toView(Atcd_Code* /*pAtcd_Code*/, Atcd_Element* atcd)
{ m_toViewOnly = TRUE;
  lbl_Titre->setText("<b>"+TR("Visualisation d'un antécédent")+"</b>");
  m_LineEdit_Libelle->setText( atcd->m_Libelle );
  m_LineEdit_Libelle->setReadOnly(TRUE);
  m_LineEdit_Commentaire->setText ( atcd->m_Commentaire );
  m_LineEdit_Commentaire->setReadOnly(TRUE);
  if ( atcd->m_Date.isValid() )
     { chkDate->setChecked(TRUE);
       setDateObserv( atcd->m_Date );
     }
  // Reste à gérer les rubriques
  setFamilyGenre(atcd->m_Rubrique.stripWhiteSpace());
  m_Combo_Family->setEnabled(FALSE);
  m_Combo_Genre->setEnabled(FALSE);

  if (atcd->m_ald=="ALD") checkBox_IsALD->setChecked(TRUE);
  else                    checkBox_IsALD->setChecked(FALSE);
  checkBox_IsALD->setEnabled(FALSE);
  checkBox_IsActif->setChecked( atcd->m_Etat);
  checkBox_IsActif->setEnabled(FALSE);
  chkDate->setEnabled(FALSE);
}

//--------------------------------- setFamilyGenre -------------------------------------------------------------
void DlgAtcd_txt::setFamilyGenre(QString familyGenre)
{ bool isComboSet  = FALSE;
  familyGenre = familyGenre.stripWhiteSpace();
  if (familyGenre.length())
     {   QString genre  = "";
         int posDeb     = familyGenre.find("(");
         int posEnd     = posDeb;
         if (posDeb    != -1)
            { ++posDeb;
              posEnd    = familyGenre.find(")",posDeb);
              if (posEnd != -1)
                  {genre       = familyGenre.mid(posDeb,posEnd-posDeb).stripWhiteSpace();
                   familyGenre = familyGenre.left(posDeb-1).stripWhiteSpace();
                   setComboOnValue(m_Combo_Family , familyGenre);
                   //CGestIni::Param_GetList(m_structStr, familyGenre, "",  m_ATCD_GenreList , 1);
                   //m_ATCD_GenreList.prepend(familyGenre);
                   //m_Combo_Genre->clear();
                   //m_Combo_Genre->insertStringList( m_ATCD_GenreList );
                   setComboOnValue(m_Combo_Genre,   genre);
                   isComboSet = TRUE;
                  }
            }
         if (isComboSet  == FALSE)  setComboOnValue(m_Combo_Family , familyGenre);
     }
 else
     {setComboOnValue(m_Combo_Family,tr("Médicaux"));
     }
}

//--------------------------------- setToUpdate -------------------------------------------------------------
void DlgAtcd_txt::setToUpdate(bool b)
{ if (!b) {m_toViewOnly=TRUE; return;}
  m_toViewOnly=FALSE;
  lbl_Titre->setText("<b>"+TR("Modification d'un antécédent")+"</b>");
  m_LineEdit_Libelle->setReadOnly(FALSE);
  m_LineEdit_Commentaire->setReadOnly(FALSE);
  m_Combo_Family->setEnabled(TRUE);
  m_Combo_Genre->setEnabled(TRUE);
  chkDate->setEnabled(TRUE);
  cMaskedLineDateAtcd->setEnabled(TRUE);
  pushButtonDateDlg->setEnabled(TRUE);
  checkBox_IsALD->setEnabled(TRUE);
  checkBox_IsActif->setEnabled(TRUE);
}

//--------------------------------- getInfos -------------------------------------------------------------
void DlgAtcd_txt::getInfos(QString& libelle, QString& family, QString& date, QString& commentaire)
{ libelle     = m_LineEdit_Libelle->text();
  commentaire = m_LineEdit_Commentaire->text();
  family      = getFamilleGenre();
  if ( chkDate->isChecked() )	date = getDateObserv_ISODate();
  else				date = "";
}
//--------------------------------- getFamilleGenre -------------------------------------------------------------
QString DlgAtcd_txt::getFamilleGenre()
{ QString family =  m_Combo_Family->currentText();
  QString genre  =  m_Combo_Genre->currentText();
  if (family  != genre) family += " ("+m_Combo_Genre->currentText()+")";
  return family;
}
////////////////////////////////////////////////////////////////////////////
//////////////////////////   GESTION DATES  ////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//--------------------------------- getDate -------------------------------------------------------------
QString DlgAtcd_txt::getDate()
{ if ( !chkDate->isChecked() )	return QString("");
 QString tmp = cMaskedLineDateAtcd->text ();        // 15092009
 return tmp.mid(0,2) + "-" + tmp.mid(2,2) + "-" + tmp.mid(4,4);
}

//--------------------------------- getDateObserv -------------------------------------------------------------
/*! \brief A tout moment, retourne la date de l'honoraire au format string : "dd-MM-yyyy"
 */
QString DlgAtcd_txt::getDateObserv()
{  return cMaskedLineDateAtcd->getMixText ();
}

//--------------------------------- getDateObserv_ISODate -------------------------------------------------------------
/*! \brief A tout moment, retourne la date de l'honoraire au format string : "yyyy-MM-dd"
 */
QString DlgAtcd_txt::getDateObserv_ISODate()
{   QString tmp = cMaskedLineDateAtcd->text ();        // 15092009
    return tmp.mid(4,4) + "-" + tmp.mid(2,2) + "-" +  tmp.mid(0,2) ;
}

//--------------------------------- setDateObserv -------------------------------------------------------------
/*!\brief A tout moment, met les combobox de la date aux bonnes valeurs. La date est passée en paramètre au format "dd-MM-yyyy".
 */
void DlgAtcd_txt::setDateObserv(QString /*dt_str*/)
{}

//--------------------------------- setDateObserv -------------------------------------------------------------
/*! \brief A tout moment, met les combobox de la date aux bonnes valeurs. La date est passée en paramètre au format "dd-MM-yyyy".
 */
void DlgAtcd_txt::setDateObserv(QDate dt)
{ cMaskedLineDateAtcd->setText(dt.toString("ddMMyyyy"));
}

//--------------------------------- but_Valider_clicked -------------------------------------------------------------
void DlgAtcd_txt::but_Valider_clicked()
{ accept();
}

//--------------------------------- but_Annuler_clicked -------------------------------------------------------------
void DlgAtcd_txt::but_Annuler_clicked()
{ reject();
}

//--------------------------------- comboBox_Family_highlighted -------------------------------------------------------------
void DlgAtcd_txt::comboBox_Family_highlighted( const QString& section )
{m_ATCD_GenreList.clear();
 CGestIni::Param_GetList(m_structStr, section, "",  m_ATCD_GenreList , 1);
 m_ATCD_GenreList.prepend(section);
 m_Combo_Genre->clear();
 m_Combo_Genre->insertStringList( m_ATCD_GenreList );
}

//--------------------------------- combo_Family_activated -------------------------------------------------------------
void DlgAtcd_txt::combo_Family_activated( int )
{//m_Combo_Family->setCurrentItem(0);
}

//--------------------------------- combo_Genre_activated -------------------------------------------------------------
void DlgAtcd_txt::combo_Genre_activated( int )
{//m_Combo_Genre->setCurrentItem(0);
}

//--------------------------------- chkDate_clicked -------------------------------------------------------------
void DlgAtcd_txt::chkDate_clicked()
{ if ( chkDate->isChecked() )
    { cMaskedLineDateAtcd->setEnabled(TRUE);
      pushButtonDateDlg->setEnabled(TRUE);
    }
  else
    { cMaskedLineDateAtcd->setEnabled(FALSE);
      pushButtonDateDlg->setEnabled(FALSE);
    }
}
