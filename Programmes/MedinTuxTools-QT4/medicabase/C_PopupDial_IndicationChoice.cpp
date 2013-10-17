#include "C_PopupDial_IndicationChoice.h"
#include "ui_C_PopupDial_IndicationChoice.h"
#include <QItemDelegate>
#include <QStyledItemDelegate>
#include <QTreeWidgetItem>
#include "../../MedinTuxTools-QT4/medicabase/C_LevelItemDelegate.h"

//----------------------------------- C_PopupDial_IndicationChoice -------------------------------------------
C_PopupDial_IndicationChoice::C_PopupDial_IndicationChoice(C_Frm_PosologieHitList *pC_Frm_PosologieHitList,
                                                           CMyQLineEdit           *pCMyQLineEdit,
                                                           const QColor            &backGround,
                                                           const QRect             &initialRect,
                                                           const QRect             &deployRect) :
   C_PopupDial(pC_Frm_PosologieHitList, backGround, initialRect, deployRect)
{   m_cur_grammar             = pC_Frm_PosologieHitList->grammar();
    m_pC_Frm_PosologieHitList = pC_Frm_PosologieHitList;
    m_pCMyQLineEdit           = pCMyQLineEdit;
    setupUi(this);

    checkBox_IndicationCIM10->hide();
    checkBox_IndicationBDM->hide();
    checkBox_SMR->hide();
    checkBox_ASMR->hide();

    setFont(pC_Frm_PosologieHitList->font());
    fillTreeWidgetIndications(pC_Frm_PosologieHitList->cip());

    QRect dRect = QRect (deployRect.x(),
                         deployRect.y(),
                         width(),
                         deployRect.height());

    setRectanngles(initialRect, dRect);
    setToInitialRect(C_PopupDial::FAST);
    connect( this, SIGNAL( Sign_deployed (int&)),     this , SLOT( Slot_Dial_IndicationChoiceDeployed(int&) ));
    connect( treeWidget_Indications, SIGNAL(itemClicked ( QTreeWidgetItem * , int  )),        this, SLOT(Slot_treeWidget_Indications_itemClicked ( QTreeWidgetItem * , int   )) );
    connect( treeWidget_Indications, SIGNAL(itemDoubleClicked ( QTreeWidgetItem * , int  )),  this, SLOT(Slot_treeWidget_Indications_itemDoubleClicked ( QTreeWidgetItem * , int   )) );

}
//--------------------------------------- Slot_treeWidget_Indications_itemClicked -------------------------------------------------------
void C_PopupDial_IndicationChoice::Slot_treeWidget_Indications_itemClicked ( QTreeWidgetItem *pQTreeWidgetItem , int   )
{if (m_pCMyQLineEdit  == 0) return;
 if (pQTreeWidgetItem == 0) return;
 if (pQTreeWidgetItem->text(3)=="SMR")
     m_pCMyQLineEdit->setText(pQTreeWidgetItem->text(1).mid(1)+"|SMR|"+pQTreeWidgetItem->text(0));
 else
     m_pCMyQLineEdit->setText(pQTreeWidgetItem->text(2)+"|"+pQTreeWidgetItem->text(3)+"|"+pQTreeWidgetItem->text(0));
}
//--------------------------------------- Slot_treeWidget_Indications_itemDoubleClicked -------------------------------------------------------
void C_PopupDial_IndicationChoice::Slot_treeWidget_Indications_itemDoubleClicked ( QTreeWidgetItem *pQTreeWidgetItem , int c   )
{Slot_treeWidget_Indications_itemClicked (pQTreeWidgetItem , c);
 setToInitialRect();
}
//--------------------------------------- fillTreeWidgetIndications -------------------------------------------------------
void C_PopupDial_IndicationChoice::fillTreeWidgetIndications(const QString &cip)
{
 QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
 QList <C_BDM_IndicationRecord>    retList = m_pC_Frm_PosologieHitList->c_bdm_api()->getIndicationsFromCIP( cip, C_BDM_PluginI::ALL_INDIC );
 QTreeWidgetItem                    *item  = 0;
 C_LevelItemDelegate *pC_LevelItemDelegate = 0;
 treeWidget_Indications->clear();
 if (retList.size())
    { for (int i = 0; i < retList.size(); ++i )
          { C_BDM_IndicationRecord indicationRecord   = retList.at(i);
            QString codeTyp                           = indicationRecord.codeTyp();
            QString niveau                            = indicationRecord.level();
            item                                      = new QTreeWidgetItem (treeWidget_Indications);
            pC_LevelItemDelegate                      = new C_LevelItemDelegate(treeWidget_Indications);
            treeWidget_Indications->setItemDelegate(pC_LevelItemDelegate);
            if      (indicationRecord.levelTyp()=="S") {codeTyp = "SMR"; }
            else if (indicationRecord.levelTyp()=="A") {codeTyp = "ASMR"; }
            item->setText(1,niveau);                          // niveau
            item->setText(0,indicationRecord.indication());   // libelle
            item->setText(2,indicationRecord.code());         // code
            item->setText(3,codeTyp);                         // codeTyp
            item->setText(4,indicationRecord.descriptif());   // commentaire
            if (codeTyp=="CIM")
               {item->setIcon(0, QPixmap(m_pC_Frm_PosologieHitList->bitMapCollection()->imagePath("CimItem.png")));
               }
            else if (codeTyp=="DS_I")
               {item->setIcon(0,QPixmap(m_pC_Frm_PosologieHitList->bitMapCollection()->imagePath("VidalItem.png")));
               }
            else if (codeTyp=="TH_I")
               {item->setIcon(0,QPixmap(m_pC_Frm_PosologieHitList->bitMapCollection()->imagePath("TheriaqueItem.png")));
               }
            else
               {item->setIcon(0,QPixmap(m_pC_Frm_PosologieHitList->bitMapCollection()->imagePath("HasItem.png")));
               }
          }
    }
 QApplication::restoreOverrideCursor();
}
//------------------------------------ setFont --------------------------------------------------------
void C_PopupDial_IndicationChoice::setFont(const QFont &fnt)
{
 C_PopupDial::setFont(fnt);
 m_fGrd  =  fnt;
 /*
 label_poids->setFont(m_fGrd);
 lineEdit_poids->setFont(m_fGrd);
 pushButton_cancel->setFont(m_fGrd);
 label_kg_x->setFont(m_fGrd);
 pushButton_UPA->setFont(m_fGrd);
 pushButton_UFC->setFont(m_fGrd);
 label_QPA->setFont(m_fGrd);
 label_QFC->setFont(m_fGrd);
 label_QPA_by_UP_0->setFont(m_fGrd);
 label_QPA_by_UP_1->setFont(m_fGrd);
 lineEdit_QPA_by_UP->setFont(m_fGrd);
 */
}
//----------------------------------- ~C_PopupDial_IndicationChoice -------------------------------------------
C_PopupDial_IndicationChoice::~C_PopupDial_IndicationChoice()
{
}
//------------------------------------------------------ Slot_DialDateDeployed ----------------------------------------------------------------------
void C_PopupDial_IndicationChoice::Slot_Dial_IndicationChoiceDeployed(int &ok)
{   ok=1;
 /*
 QPoint pos = mapFromGlobal (QCursor::pos());
 if (pos.x() < m_initialRect.width() - 30)      // si sur la zone edition ne pas deployer
    { ok=0;
     return;
    }

 ok = 1;
 */
}
