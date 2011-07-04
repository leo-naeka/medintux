//
// C++ Implementation: C_ListViewATCDManager
//
// Description:
//
//
// Author: Sevin Roland <upsis@club-internet.fr>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//


#include "C_ListViewATCDManager.h"
#include <qobject.h>
#include <qmessagebox.h>
#include "CApp.h"

//------------------------------------ C_ListViewATCDManager --------------------------------------------------
/*! \brief constructeur
*/
C_ListViewATCDManager::C_ListViewATCDManager(QObject * parent, const char * name , QListView*   pQListView, Atcd_Code* pAtcd_Code, int *pIsModified, int *pIsModifiable, QString *pTypeATCD_Selectionne)
: QObject ( parent, name )
{m_pQListView             = pQListView;
 m_pAtcd_Code             = pAtcd_Code;
 m_pIsModified            = pIsModified;
 m_pIsModifiable          = pIsModifiable;
 m_pTypeATCD_Selectionne  = pTypeATCD_Selectionne;
}

//------------------------------------ Add_popMenu_ATCD_Type --------------------------------------------------
/*! \brief Ajoute le menu de selection du type d'ant\303\251cedent �  un menu quelconque
*/
void C_ListViewATCDManager::Add_popMenu_ATCD_Type(QPopupMenu* pQPopupMenu)
{connect ( G_pCApp, SIGNAL(Sign_popup_HierarchOptionSelected()) , this, SLOT(ATCD_MenuActionSetFamilleGenre()));
 G_pCApp->addPopupHierarchique(G_pCApp->m_PathAppli + "Ressources/MenuATCD.txt", pQPopupMenu, m_pTypeATCD_Selectionne);
}

//------------------------------------ m_pQListView_contextMenuRequested --------------------------------------------------
/*! \brief action bouton droit sur la listeview ATCD
*/

   // 0 Libelle
   // 1 famille Genre
   // 2 etat Actif/gueri
   // 3 commentaire
   // 4 date
   // 5 ald
   // 6 code

void C_ListViewATCDManager::Slot_listView_ATCD_contextMenuRequested( QListViewItem *pQListViewItem, const QPoint &pos, int c )
{
 if (*m_pIsModifiable==0)   return;
*m_pTypeATCD_Selectionne    = "";
 ThemePopup *pQPopupMenu    = 0;
 QString ret                = "";
 QStringList optionList;
 switch(c)
 {case 0:  // libelle
     {
      ThemePopup *pThemePopup   = new ThemePopup((QWidget*)this->parent(), "MyPopupMenu" );
      //pThemePopup->insertItem(Theme::getIcon( "Cim10All_Icon.png"), tr("Ajouter un  Ant\303\251c\303\251dent CIM10"),                this, SLOT( ATCD_MenuActionNewCIM10()),       CTRL+Key_M );
      //pThemePopup->insertItem(G_pCApp->m_IconTherapeutique, tr("Ajouter une intol\303\251rance m\303\251dicamenteuse"),              this, SLOT( ATCD_MenuActionNewAllergie()),    CTRL+Key_N );
      pThemePopup->insertItem(Theme::getIconListItem(), tr("Ajouter un ant\303\251c\303\251dent texte libre"),                       this, SLOT( ATCD_MenuActionNewTexteLibre()),  CTRL+Key_T );
      if (pQListViewItem!=0)
        {// Construit le menu g\303\251n\303\251ral
         pThemePopup->insertSeparator ();
         pThemePopup->insertItem( Theme::getIconListDelete() , tr("Effacer les ant\303\251c\303\251dents s\303\251lectionn\303\251s"),             this, SLOT( ATCD_MenuActionMultiDel()),       CTRL+Key_F );
         pThemePopup->insertSeparator ();
         pThemePopup->insertItem( Theme::getIconListDateTime(),        tr("Modifier la date de cet Ant\303\251c\303\251dent"),       this, SLOT( ATCD_MenuActionSetDate()),        CTRL+Key_G );
         pThemePopup->insertItem( Theme::getIcon("16x16/timeDel.png"), tr("Effacer la date de cet Ant\303\251c\303\251dent"),        this, SLOT( ATCD_MenuActionDelDate()),        CTRL+Key_G );
         if (pQListViewItem->text(2)==tr("Pass\303\251"))
            {  pThemePopup->insertItem( Theme::getIcon("16x16/listok.png"),  tr("Gu\303\251ri (passer en Actif)"),           this, SLOT( ATCD_MenuActionChangeEtatActif()),    CTRL+Key_H );
            }
         else
            {  pThemePopup->insertItem( Theme::getIconListWarning(),  tr("Actif (passer en Gu\303\251ri)"),                   this, SLOT( ATCD_MenuActionChangeEtatGueri()),    CTRL+Key_H );
            }
         pThemePopup->insertSeparator ();
         Add_popMenu_ATCD_Type(pThemePopup);
         pThemePopup->insertSeparator ();
         if (pQListViewItem->text(3).length())
            { pThemePopup->insertItem( Theme::getIcon("16x16/commentaire.png"),  pQListViewItem->text(3),                   this, SLOT( ATCD_MenuActionSetCommentaire()), CTRL+Key_K );
            }
         else
            { pThemePopup->insertItem( Theme::getIcon("16x16/commentaire.png"),  tr("D\303\251finir un commentaire"),             this, SLOT( ATCD_MenuActionSetCommentaire()), CTRL+Key_K );
            }
        pThemePopup->insertSeparator ();
        pThemePopup->insertItem( Theme::getIcon("16x16/ald_on.png"),  tr("En rapport avec une pathologie ALD"),            this, SLOT( ATCD_setAldOn()),         CTRL+Key_L );
        pThemePopup->insertItem( Theme::getIcon("16x16/ald_off.png"), tr("Sans rapport avec une pathologie ALD"),          this, SLOT( ATCD_setAldOff()),        CTRL+Key_O );
        }
      pThemePopup->exec(pos);
      delete pThemePopup;
      //m_pQListViewItem = 0;
     }
     break;
  case 1:         // med/chir
     pQPopupMenu   = new ThemePopup((QWidget*)this->parent(), "MyPopupMenu" );
     Add_popMenu_ATCD_Type(pQPopupMenu);
     pQPopupMenu->exec(QCursor::pos());
     delete pQPopupMenu;
     break;
  case 2:         // etat passe transitoire
        pQPopupMenu   = new ThemePopup((QWidget*)this->parent(), "MyPopupMenu" );
        pQPopupMenu->insertItem( G_pCApp->m_Theme.getIcon("16x16/listok.png"),   tr("Gu\303\251ri (passer en Actif)"),  this, SLOT( ATCD_MenuActionChangeEtatActif()),    CTRL+Key_H );
        pQPopupMenu->insertItem( G_pCApp->m_Theme.getIconListWarning(),  tr("Actif (passer en Gu\303\251ri)"),          this, SLOT( ATCD_MenuActionChangeEtatGueri()),    SHIFT+Key_H );
        pQPopupMenu->exec(QCursor::pos());
     delete pQPopupMenu;
     break;
  case 3:         // commentaire
     ATCD_MenuActionSetCommentaire();
     break;
  case 4:         // date
     ATCD_MenuActionSetDate();
     break;
  case 5:         // ALD
     {ThemePopup *pThemePopup   = new ThemePopup((QWidget*)this->parent(), "MyPopupMenu" );
      pThemePopup->insertItem( Theme::getIcon("16x16/ald_on.png"),  tr("En rapport avec une pathologie ALD"),      this, SLOT( ATCD_setAldOn()),         CTRL+Key_L );
      pThemePopup->insertItem( Theme::getIcon("16x16/ald_off.png"), tr("Sans rapport avec une pathologie ALD"),    this, SLOT( ATCD_setAldOff()),        CTRL+Key_O );
      pThemePopup->exec(QCursor::pos());
      delete pThemePopup;
     }
     break;
  case 6:          // code de l'antecedent
     {listView_ATCD_doubleClicked( pQListViewItem);
     }
     break;

 }
}
//------------------------------------ ATCD_setAldOn --------------------------------------------------
/*! \brief positionne les ATCD selectionnes dans la listview des ATCD sur en rapport avec les ALD
*/
void C_ListViewATCDManager::ATCD_setAldOn()
{ATCD_setAldOnOff(tr("ALD"));
}
//------------------------------------ ATCD_setAldOff --------------------------------------------------
/*! \brief positionne les ATCD selectionnes dans la listview des ATCD sur sans rapport avec les ALD
*/
void C_ListViewATCDManager::ATCD_setAldOff()
{ATCD_setAldOnOff(tr(""));
}

//------------------------------------ ATCD_setAldOn --------------------------------------------------
/*! \brief positionne les ATCD selectionnes dans la listview des ATCD sur en/sans rapport avec les ALD selon le parametre state "":"ALD"
*/
void C_ListViewATCDManager::ATCD_setAldOnOff(const QString &state)
{QListViewItemIterator it( m_pQListView );
 while ( it.current() )
    {
      CPrtQListViewItem* pCPrt = (CPrtQListViewItem*)it.current();
      if (pCPrt->isSelected())
         {if (m_pAtcd_Code)
             { Atcd_Element* pAtcd_Element_Selected = m_pAtcd_Code->getAtcd_byID( pCPrt->get_ID_Rublist().toInt() );
               if (pAtcd_Element_Selected) m_pAtcd_Code->setALD(pAtcd_Element_Selected, state, Atcd_Code::sendNotModifMessage);
             }
          pCPrt->setText( 5,state );
          if (state.length()) pCPrt->setPixmap(1, Theme::getIcon("16x16/ald_on.png") );
          else                pCPrt->setPixmap(1, Theme::getIcon("16x16/ald_off.png") );
          *m_pIsModified = 1;
         }
      ++it;
    }
}

//------------------------------------ listView_ATCD_doubleClicked -------------------------------------------
/*! \brief Fonction qui appelle Atcd_Code::modifyAtcd() pour la modification de l'ant\303\251c\303\251dent s\303\251lectionn\303\251. Très efficace !
*/
void C_ListViewATCDManager::listView_ATCD_doubleClicked( QListViewItem * pQListViewItem)
{
 if (*m_pIsModifiable==0)        return;
 if (!m_pAtcd_Code)              return;
 m_pAtcd_Code->modifyAtcd((QWidget*)this, get_Selected_Atcd_Element((CPrtQListViewItem*)pQListViewItem));
}

//------------------------------------ ATCD_MenuActionSetDate --------------------------------------------------
/*! \brief Modifie la date de l'ATCD s\303\251lectionn\303\251 par le biais de la classe Atcd_Code
*/
void C_ListViewATCDManager::ATCD_MenuActionSetDate()
{
  if (*m_pIsModifiable==0)        return;
  if (!m_pAtcd_Code)              return;
  Atcd_Element        *pAtcd_Element      = get_Selected_Atcd_Element();
  CPrtQListViewItem   *pCPrtQListViewItem = get_CurrentItem();
  if (pCPrtQListViewItem == 0)    return;

  Dlg_Calendar* dlg  = new Dlg_Calendar((QWidget*)this->parent(), "Calendar_Dial", FALSE);
  if (dlg==0)                     return;
  dlg->setCaption(TR("Date de l'ant\303\251c\303\251dent"));
  int isInvalid     = 0;
  QDate          dt = CGenTools::setDate(pCPrtQListViewItem->text(4), isInvalid);
  if (isInvalid) dt = QDate::currentDate();
  dlg->setDate(dt);
  dlg->setComboAnOnDate_Offset(dt, 25,0);
  dlg->SelectDateAll();

  if (dlg->exec()== QDialog::Accepted )
     { if (pAtcd_Element)
          {m_pAtcd_Code->setDate(pAtcd_Element, dlg->getDate(), Atcd_Code::sendNotModifMessage);
          }
       pCPrtQListViewItem->setText(4, dlg->getDate().toString("dd-MM-yyyy"));
     }
 if (dlg) delete dlg;
}

//------------------------------------ ATCD_MenuActionDelDate --------------------------------------------------
/*! \brief Efface la date de l'ATCD s\303\251lectionn\303\251 par le biais de la classe Atcd_Code
*/
void C_ListViewATCDManager::ATCD_MenuActionDelDate()
{
  if (*m_pIsModifiable==0)     return;
  if (!m_pAtcd_Code)           return;
 //................. parcourir tous les items ............
 QListViewItemIterator it( m_pQListView );
 while ( it.current() )
    {
      CPrtQListViewItem* pCPrt = (CPrtQListViewItem*)it.current();
      if (pCPrt->isSelected())
         {if (m_pAtcd_Code)
              {Atcd_Element* pAtcd_Element_Selected = m_pAtcd_Code->getAtcd_byID( pCPrt->get_ID_Rublist().toInt() );
               if (pAtcd_Element_Selected) m_pAtcd_Code->deleteDate(pAtcd_Element_Selected, Atcd_Code::sendNotModifMessage);
              }
          pCPrt->setText( 4,"" );
          *m_pIsModified = 1;
         }
      ++it;
    }
}

//------------------------------------ ATCD_MenuActionNewCIM10 --------------------------------------------------
/*! \brief Ajoute un ATCD CIM 10 par le biais de Atcd_Code de CApp
*/
void C_ListViewATCDManager::ATCD_MenuActionNewCIM10()
{ if (*m_pIsModifiable==0) return;
  if (!m_pAtcd_Code)       return;
  m_pAtcd_Code->addATCD_CIM10();
}
//------------------------------------ ATCD_MenuActionNewAllergie ---------------------------------------------------
/*! \brief Ajoute un ATCD allergique par le biais de Atcd_Code de CApp
*/
void C_ListViewATCDManager::ATCD_MenuActionNewAllergie()
{ if (*m_pIsModifiable==0) return;
  if (!m_pAtcd_Code)       return;
  m_pAtcd_Code->addATCD_Allergie();
}
//------------------------------------ ATCD_MenuActionNewTexteLibre --------------------------------------------------
/*! \brief Ajoute un ATCD texte libre par le biais de Atcd_Code de CApp
*/
void C_ListViewATCDManager::ATCD_MenuActionNewTexteLibre()
{ if (*m_pIsModifiable==0)         return;
  if (!m_pAtcd_Code)               return;
  //......... si item atcd rajoute rajouter celui de la listView allant avec ......................
  Atcd_Element*        pAtcd_Element      = m_pAtcd_Code->get_lastElementAdded();
  if (pAtcd_Element==0)
     { CPrtQListViewItem* pCPrtQListViewItem  = new CPrtQListViewItem ( m_pQListView, 0,  "");
       ATCD_EditListViewItem(pCPrtQListViewItem);
    }
 else
    {  CPrtQListViewItem*   pCPrtQListViewItem = get_CurrentItem();
       if (pCPrtQListViewItem==0)       return;
       m_pAtcd_Code->addATCD_Textuel((QWidget*)this, Atcd_Code::sendNotModifMessage);    // siOK met a jour le dernier element rajoute
       m_pAtcd_Code->atcd_Element_To_ListViewItem(*pAtcd_Element, m_pQListView);
    }
}

//------------------------------------ ATCD_EditListViewItem --------------------------------------------------
/*! \brief Ajoute un ATCD texte libre par le biais de Atcd_Code de CApp
*/
int C_ListViewATCDManager::ATCD_EditListViewItem(CPrtQListViewItem* pCPrtQListViewItem)
{
       DlgAtcd_txt* pDlgAtcd_txt = new DlgAtcd_txt((QWidget*)this->parent());
       if (!pDlgAtcd_txt)          return 0;
       pDlgAtcd_txt->setComboOnValue(pDlgAtcd_txt->m_Combo_Family,tr("M\303\251dicaux"));
       pDlgAtcd_txt->exec();
       if (pDlgAtcd_txt->result() == QDialog::Accepted)
          { // R\303\251cupère les donn\303\251es du widget set_Atcd_Element(rubrique, libelle,  dt,  code, etat,  commentaire, ald,  -1);
            QString libelle, commentaire, familleGenre, etat, date, ald;
            QDate dt ;
            pDlgAtcd_txt->getInfos(libelle, familleGenre, date, commentaire);
            if (date != "") dt = QDate::fromString(date, Qt::TextDate);
            else            dt = QDate();
            ald  = pDlgAtcd_txt->GetALD();
            etat = pDlgAtcd_txt->getEtatGueriActif();
            pCPrtQListViewItem->setText(0,libelle);
            pCPrtQListViewItem->setText(1,familleGenre);
            pCPrtQListViewItem->setText(2,etat);
            pCPrtQListViewItem->setText(3,commentaire);
            pCPrtQListViewItem->setText(4,dt.toString("dd-MM-yyyy"));
            pCPrtQListViewItem->setText(5,ald);
            if (ald.length()) pCPrtQListViewItem->setPixmap(1, Theme::getIcon("16x16/ald_on.png") );
            else              pCPrtQListViewItem->setPixmap(1, Theme::getIcon("16x16/ald_off.png") );

            if (etat==tr("Actif")) pCPrtQListViewItem->setPixmap ( 2, G_pCApp->m_Theme.getIcon("16x16/warning.png") );
            else                   pCPrtQListViewItem->setPixmap ( 2, G_pCApp->m_Theme.getIcon("16x16/listok.png") );
            pCPrtQListViewItem->setPixmap (0, G_pCApp->m_Theme.getIcon( "16x16/item.png"));
            delete pDlgAtcd_txt;
            return 1;
          }
     delete pDlgAtcd_txt;
     return 0;
}

//------------------------------------ get_Selected_Atcd_Element --------------------------------------------------
/*! \brief recupere un ATCD a partir de l'item selectionne dans la listview
*/
Atcd_Element* C_ListViewATCDManager::get_Selected_Atcd_Element(CPrtQListViewItem *pCPrtQListViewItem /*=0*/)
{if (pCPrtQListViewItem==0) pCPrtQListViewItem = get_CurrentItem();
 if (pCPrtQListViewItem==0) return 0;
 Atcd_Element* pAtcd_Element_Selected = m_pAtcd_Code->getAtcd_byID( pCPrtQListViewItem->get_ID_Rublist().toInt() );
 return pAtcd_Element_Selected;
}
//------------------------------------ get_CurrentItem --------------------------------------------------
/*! \brief recuperel'item selectionne dans la listview
*/
CPrtQListViewItem * C_ListViewATCDManager::get_CurrentItem()
{CPrtQListViewItem *pCPrtQListViewItem =  (CPrtQListViewItem*) m_pQListView->currentItem ();
 if (pCPrtQListViewItem) return pCPrtQListViewItem;
 return  (CPrtQListViewItem*) m_pQListView->selectedItem ();
}

//------------------------------------ ATCD_MenuActionMultiDel --------------------------------------------------
/*! \brief Efface un ATCD par le biais de Atcd_Code de CApp
*/
void C_ListViewATCDManager::ATCD_MenuActionMultiDel()
{ATCD_MenuActionMultiDel( Atcd_Code::sendNotModifMessage);
}

//------------------------------------ ATCD_MenuActionMultiDel --------------------------------------------------
void C_ListViewATCDManager::ATCD_MenuActionMultiDel(int sendModifMessage)
{//m_pQListViewItem->setSelected (TRUE);   // reselectionner l'item au dessus duquel se retrouve la souris
 //............... liste des items � effacer..................................
 //                comme elle est autodelete ils s'effaceront automatiquement
 //                a la fin lors destruction de l'objet : listItemsToDelete
 //                avec le raffraichissement graphique qui va avec
 QPtrList<CPrtQListViewItem> listItemsToDelete;
 listItemsToDelete.setAutoDelete( TRUE );
 //............... le disconnect fait que le raffraichissement de la listview nous incombe .......................
 //                et ne sera pas fait par :  m_pAtcd_Code->eraseAtcd(pAtcd_Element_Selected);
 if (m_pAtcd_Code) disconnect(m_pAtcd_Code, SIGNAL( ATCD_Changed() ), this, SLOT( ATCD_HaveChanged() ));
 //................. parcourir tous les items ............
 QListViewItemIterator it( m_pQListView );
 while ( it.current() )
    {
      CPrtQListViewItem* pCPrt = (CPrtQListViewItem*)it.current();
      if (pCPrt->isSelected())
         {if (m_pAtcd_Code)
              {Atcd_Element* pAtcd_Element_Selected = m_pAtcd_Code->getAtcd_byID( pCPrt->get_ID_Rublist().toInt() );
               if (pAtcd_Element_Selected) m_pAtcd_Code->eraseAtcd(pAtcd_Element_Selected, sendModifMessage);
              }
          listItemsToDelete.append(pCPrt);
          *m_pIsModified = 1;
         }
      ++it;
    }
}

//------------------------------------ ATCD_MenuActionChangeEtatGueri --------------------------------------------------
/*! \brief Connecte avec Atcd_Code la modification de l'\303\251tat de l'ant\303\251c\303\251dent s\303\251lectionn\303\251.
*/
void C_ListViewATCDManager::ATCD_MenuActionChangeEtatGueri()
{ ATCD_MenuActionChangeEtat(0);
}

//------------------------------------ ATCD_MenuActionChangeEtatActif --------------------------------------------------
/*! \brief Connecte avec Atcd_Code la modification de l'\303\251tat de l'ant\303\251c\303\251dent s\303\251lectionn\303\251.
*/
void C_ListViewATCDManager::ATCD_MenuActionChangeEtatActif()
{ ATCD_MenuActionChangeEtat(1);
}

//------------------------------------ ATCD_MenuActionChangeEtat --------------------------------------------------
/*! \brief Connecte avec Atcd_Code la modification de l'\303\251tat de l'ant\303\251c\303\251dent s\303\251lectionn\303\251.
*/
void C_ListViewATCDManager::ATCD_MenuActionChangeEtat(int etat)
{if (*m_pIsModifiable==0)        return;
 if (!m_pAtcd_Code)              return;

 //................. parcourir tous les items ............
 QListViewItemIterator it( m_pQListView );
 while ( it.current() )
    {
      CPrtQListViewItem* pCPrt = (CPrtQListViewItem*)it.current();
      if (pCPrt->isSelected())
         {if (m_pAtcd_Code)
              {Atcd_Element* pAtcd_Element_Selected = m_pAtcd_Code->getAtcd_byID( pCPrt->get_ID_Rublist().toInt() );
               if (pAtcd_Element_Selected) m_pAtcd_Code->setEtat(pAtcd_Element_Selected, etat, Atcd_Code::sendNotModifMessage);
              }
          if (etat) { pCPrt->setPixmap(2,Theme::getIcon("16x16/warning.png"));pCPrt->setText( 2,tr("Actif") );}
          else      { pCPrt->setPixmap(2,Theme::getIcon("16x16/listok.png")); pCPrt->setText( 2,tr("Pass\303\251") );}
          *m_pIsModified = 1;
         }
      ++it;
    }
}

//------------------------------------ ATCD_MenuActionSetFamilleGenre --------------------------------------------------
/*! \brief Modifie la Famille et Genre d'un ATCD par le biais de la classe Atcd_Code.
*/
void C_ListViewATCDManager::ATCD_MenuActionSetFamilleGenre()
{if (*m_pIsModifiable==0)          return;
 if (!m_pAtcd_Code)                return;

 disconnect ( G_pCApp, SIGNAL(Sign_popup_HierarchOptionSelected()) , this, SLOT(ATCD_MenuActionSetFamilleGenre()));
 //................. parcourir tous les items ............
 QListViewItemIterator it( m_pQListView );
 while ( it.current() )
    {
      CPrtQListViewItem* pCPrt = (CPrtQListViewItem*)it.current();
      if (pCPrt->isSelected())
         {if (m_pAtcd_Code)
              {Atcd_Element* pAtcd_Element_Selected = m_pAtcd_Code->getAtcd_byID( pCPrt->get_ID_Rublist().toInt() );
               if (pAtcd_Element_Selected) m_pAtcd_Code->setRubrique(pAtcd_Element_Selected, *m_pTypeATCD_Selectionne, Atcd_Code::sendNotModifMessage);
              }
          pCPrt->setText( 1, *m_pTypeATCD_Selectionne);
          *m_pIsModified = 1;
         }
      ++it;
    }
}

//------------------------------------ ATCD_MenuActionSetCommentaire --------------------------------------------------
void C_ListViewATCDManager::ATCD_MenuActionSetCommentaire()
{if (*m_pIsModifiable==0)           return;
 if (!m_pAtcd_Code)                 return;
 CPrtQListViewItem* pCPrtQListViewItem = get_CurrentItem();
 if (pCPrtQListViewItem == 0)       return;
 QString         commentaire = pCPrtQListViewItem->text(3);
 Atcd_Element* pAtcd_Element = get_Selected_Atcd_Element();
 if (pAtcd_Element == 0)
    {  if (CGenTools::DialogGetString(0, TR("Saisir un commentaire (mode texte libre)") , commentaire) == QDialog::Accepted)
          {pCPrtQListViewItem->setText(3,commentaire);
          }
    }
 else
    { m_pAtcd_Code->changeCommentaire(pAtcd_Element, Atcd_Code::sendNotModifMessage);
      pCPrtQListViewItem->setText(3, pAtcd_Element->m_Commentaire);
    }
}

//------------------------------------ pushButtonDellAllATCD_clicked --------------------------------------------------
void C_ListViewATCDManager::dellAllSelectedATCD()
{if (*m_pIsModifiable==0) return;
 QStringList optList;
 optList.append(tr ("Effacer les ant\303\251c\303\251dents s\303\251lectionn\303\251s"));
 optList.append(tr ("Effacer tous les ant\303\251c\303\251dents"));
 QString result = G_pCApp->DoPopupList(optList);
 if (result.length() == 0) return;

 if (result.find("Effacer tous")!= -1)
    {int ret = QMessageBox::warning ( 0, tr ("Effacer tous les ant\303\251c\303\251dents "),
                                        tr ("Voulez vous vraiment effacer\r\n"
                                            "toutes les donn\303\251es des ant\303\251c\303\251dents\r\n"
                                            "CETTE ACTION EST IRREVERSIBLE"),
                                        tr ("&Effacer"), tr("Annu&ler"), 0,
                                  1, 1 );
     if (ret >=1 ) return;
     //................. parcourir tous les items et les selectionner ............
     QListViewItemIterator it( m_pQListView );
     while ( it.current() )
       {CPrtQListViewItem* pCPrt = (CPrtQListViewItem*)it.current();
        pCPrt->setSelected(TRUE);
        ++it;
       }
    }
 //........... effacer la selection ....................
 ATCD_MenuActionMultiDel();
}
