#include "C_PopupDialCorpoFact.h"
#include "ui_C_PopupDialCorpoFact.h"
#include "../../MedinTuxTools-QT4/Theme/ThemePopup.h"

//----------------------------------- C_PopupDialCorpoFact -------------------------------------------
C_PopupDialCorpoFact::C_PopupDialCorpoFact( C_Frm_PosologieHitList  *pC_Frm_PosologieHitList,
                                            const QColor    &backGround,
                                            const QRect     &initialRect,
                                            const QRect     &deployRect
                                           ) :
    C_PopupDial(pC_Frm_PosologieHitList, backGround, initialRect, deployRect)
{   m_pC_Frm_PosologieHitList     =  pC_Frm_PosologieHitList;
    m_cur_grammar                 =  m_pC_Frm_PosologieHitList->grammar();
    setupUi(this);
    setFont(m_pC_Frm_PosologieHitList->font());

    //grammarToInterface(m_cur_grammar);
    setPoids();
    //................ le menu des unite de facteur corporel ...............
    QMenu *pQMenu = new QMenu(pushButton_UFC); pQMenu->setFont(m_fGrd);

    pQMenu->setObjectName("HitList : pushButton_UPA menu ");
    ThemePopup::addOptionMenu(pQMenu,tr("1 - par Kg de poids corporel"));
    ThemePopup::addOptionMenu(pQMenu,tr("2 - par cm2 de surface corporelle "));
    pushButton_UFC->setMenu ( pQMenu );
    connect( pQMenu, SIGNAL( triggered ( QAction *  )  ),    this , SLOT( Slot_pushButton_UFC_MenuTriggered( QAction *  ) ));

    //............... deploiement/repliement ..........................
    QRect dRect = QRect (m_pC_Frm_PosologieHitList->width()-width()-2,
                         deployRect.y(),
                         width(),
                         height());

    setRectanngles(initialRect, dRect);
    setToInitialRect(C_PopupDial::FAST);
    connect( this, SIGNAL( Sign_deployed (int&)),     this , SLOT( Slot_DialCorpoFactDeployed(int&) ));
}
//------------------------------------ Slot_pushButton_UFC_MenuTriggered ----------------------------------------------------------------------
void C_PopupDialCorpoFact::Slot_pushButton_UFC_MenuTriggered( QAction *pQAction  )
{   QString idMenu      = pQAction->data().toString();
    switch(idMenu.toInt())
      { case 1: pushButton_UFC->setText(tr("Kg"));  break;
        case 2: pushButton_UFC->setText(tr("cm2")); break;
      }
}

//------------------------------------ setText ----------------------------------------------------------------------
void C_PopupDialCorpoFact::setPoids()
{   C_PatientCtx *pat_ctxt = m_pC_Frm_PosologieHitList->c_bdm_api()->patientContexte();
    if (pat_ctxt) setPoids(pat_ctxt->poids());
}

//------------------------------------ setPoids ----------------------------------------------------------------------
void C_PopupDialCorpoFact::setPoids(const QString &poids)
{ lineEdit_poids->setText(poids);
}

//------------------------------------ grammarToInterface ----------------------------------------------------------------------
/*
                "<gph>\n"                          // -- DEBUT du header d'une ligne prescriptive ---
                " <gph_html></gph_html>\n"         //        contenu html (accelere l'affichage)
                " <gph_ald></gph_ald>\n"           //        prescrit en ALD "ALD"  sans ALD ""
                " <gph_id></gph_id>\n"             //        id (cip)
                " <gph_it></gph_it>\n"             //        id_type
                " <gph_dr></gph_dr>\n"             //        date et heure de la redaction de la prescription    format dd-MM-yyyy hh:mm:ss
                " <gph_dt></gph_dt>\n"             //        date et heure du debut de prise de la prescription format dd-MM-yyyy hh:mm:ss // la date de fin est calculee avec <gph_cy>
                " <gph_df></gph_df>\n"             //        date et heure de fin de prise de la prescription format dd-MM-yyyy hh:mm:ss // la date de fin est calculee avec <gph_cy>
                " <gph_na></gph_na>\n"             //        nom commercial et usuel du produit
                " <gph_dcl>\n"                     //        - debut de la liste des dci composant le produit
                "  <gph_dc>\n"                     //        -- debut du premier element de la liste des dci
                "    <gph_dcn></gph_dcn>\n"        //        --- nom   du premier element de la liste des dci
                "    <gph_dcp></gph_dcp>\n"        //        --- dose  du premier element de la liste des dci
                "    <gph_dcu></gph_dcu>\n"        //        --- unite du premier element de la liste des dci
                "  </gph_dc>\n"                    //        --fin du premier element de la liste des dci
                " </gph_dcl>\n"                    //        - fin de la liste des dci composant le produit
                " <gph_cy></gph_cy>\n"             //        duree totale de toutes les sequences (J15  S10 M10   M3R2) 'J' pour jours  ou 'S' pour semaines  ou 'M' pour mois  suivi du nbr et falcutatif 'R' pour renouvelable suivi du nbr
                " <gph_sb></gph_sb>\n"             //        substituable 0 = non substituable  1 = substituable
                " <gph_dci></gph_dci>\n"           //        affichage libelle produit : 3=que dci  2=dci+commercial 1=commercial+dci 0=que commercial (par defaut si vide c'est 3)
                " <gph_uf></gph_uf>\n"             //        forme de l'unite de prise
                " <gph_voie></gph_voie>\n"         //        voie d'administration
                " <gph_fmin></gph_fmin>\n"         //        frequence minimum
                " <gph_fmax></gph_fmax>\n"         //        frequence maximum
                " <gph_funit></gph_funit>\n"       //        frequence unite
                " <gph_pmin></gph_pmin>\n"         //        posologie minimum
                " <gph_pmax></gph_pmax>\n"         //        posologie maximum
                " <gph_punit></gph_punit>\n"       //        posologie unite
                " <gph_pfc></gph_pfc>\n"           //        posologie facteur corporel qu de gph_punit par facteur corporel
                " <gph_pfcunit></gph_pfcunit>\n"   //        posologie facteur corporel unite Kg cm
                " <gph_pqbyuf></gph_pqbyuf>\n"     //        quantite d'unite posologique par unite de forme de gph_punit par gph_uf
                " <gph_dmin></gph_dmin>\n"         //        duree minimum
                " <gph_dmax></gph_dmax>\n"         //        duree maximum
                " <gph_dunit></gph_dunit>\n"       //        duree unite
                " <gph_nm></gph_nm>\n"             //        conversion mode en mode numerique UP_QUANTITE MOMENT_MEAL ALL_LITERAL (on se sert de celui-ci car plus rapide a interpreter)
                " <gph_cm></gph_cm>\n"             //        conversion mode en mode literal pour information lisible de celui du mode numerique  UP_QUANTITE MOMENT_MEAL ALL_LITERAL on a pas peur des redondances ! (vive la memoire vive et les HD)
                " <gph_in>\n"                      //        liste des indications
                "  <gph_il></gph_il>\n"            //        premier element de la liste des indications
                " </gph_in>\n"                     //        fin de la liste des indications <gph_il> </gph_il>
                " <gph_co></gph_co>\n"             //        commentaire global en fin de prescription
                "</gph>\n"                         // -- FIN du header d'une ligne prescriptive ---
                "<gps>\n"                          // -- DEBUT de la liste des sequences pescriptives
                " <gpp></gpp>\n"                   //        premiere sequence prescriptive
                "</gps>\n"                         // -- FIN de la liste des sequences pescriptives
                "<gpi_engine></gpi_engine>\n"      //        systeme de donnees a l'origine de cette ligne prescriptive
                "<gpi_user></gpi_user>\n"          //        utilisateur a l'origine de cette ligne prescriptive
*/

void C_PopupDialCorpoFact::grammarToInterface(const QString &grammar)
{
    int  nextPos                      = 0;
    QString unitForme                 = CGestIni::getXmlData("gph_uf",      grammar, &nextPos);  // comprime injection
    QString qPA_min_By_FactCorp       = CGestIni::getXmlData("gph_pmin",    grammar, &nextPos);
    QString qPA_max_By_FactCorp       = CGestIni::getXmlData("gph_pmax",    grammar, &nextPos);
    QString unitePoso                 = CGestIni::getXmlData("gph_punit",   grammar, &nextPos);  // mg
    QString facteurCorpo              = CGestIni::getXmlData("gph_pfc",     grammar, &nextPos);  // 10
    QString unite_facteurCorpo        = CGestIni::getXmlData("gph_pfcunit", grammar, &nextPos);  // kg m2
    QString qPA_ByUnitPrise           = CGestIni::getXmlData("gph_pqbyuf",  grammar, &nextPos);  // 500 mg (par comprime)

    QString qPA_ByFactCorpo           = qPA_min_By_FactCorp;
    if (qPA_max_By_FactCorp.length() && qPA_min_By_FactCorp != qPA_max_By_FactCorp) qPA_ByFactCorpo += "-" + qPA_max_By_FactCorp;

    if (unite_facteurCorpo.length()==0) unite_facteurCorpo = tr("Kg");

    label_kg_x->setText(qPA_ByFactCorpo.replace("-",tr(" à "))+" "+unitePoso+" x ");            // __(10)  __(mg) par
    label_unit_FactCorpo->setText(unite_facteurCorpo);
                                                 // Quantite ___ ___de principe actif par ___ ___unite (Kg M2) de facteur corporel
                                                 //           ^   ^                        ^   ^
    lineEdit_QPA->setText(qPA_ByFactCorpo);      //___________|   |                        |   |
    pushButton_UPA->setText(unitePoso);          //_______________|                        |   |
    lineEdit_QFC->setText(facteurCorpo);         //________________________________________|   |
    pushButton_UFC->setText(unite_facteurCorpo); //____________________________________________|

    lineEdit_QPA_by_UP->setText(qPA_ByUnitPrise);
    label_QPA_by_UP_1->setText(QApplication::translate("C_PopupDialCorpoFact", "par %1", 0, QApplication::UnicodeUTF8).arg(unitForme));
}
//------------------------------------ get_QuPA_by_FC ----------------------------------------------------------------------
QString C_PopupDialCorpoFact::get_QuPA_by_FC()        // 10
{return lineEdit_QPA->text();
}
//------------------------------------ get_QuPA_by_FC_Unit ----------------------------------------------------------------------
QString C_PopupDialCorpoFact::get_QuPA_by_FC_Unit()   // mg
{return pushButton_UPA->text();
}
//------------------------------------ get_QuFC ----------------------------------------------------------------------
QString C_PopupDialCorpoFact::get_QuFC()              // 3
{return lineEdit_QFC->text();
}
//------------------------------------ get_QuFC_Unit ----------------------------------------------------------------------
QString C_PopupDialCorpoFact::get_QuFC_Unit()         // Kg           --> 10 mg par 3 kg de poids
{return pushButton_UFC->text();
}
//------------------------------------ get_QuPA_by_UP ----------------------------------------------------------------------
QString C_PopupDialCorpoFact::get_QuPA_by_UP()        // 500 mg par comprime
{return lineEdit_QPA_by_UP->text();
}

//------------------------------------ Slot_DialDateDeployed ----------------------------------------------------------------------
void C_PopupDialCorpoFact::Slot_DialCorpoFactDeployed(int &ok)
{   ok=1;

 QPoint pos = mapFromGlobal (QCursor::pos());
 if (pos.x() < m_initialRect.width() - 30)      // si sur la zone edition ne pas deployer
    { ok=0;
     return;
    }
 ok = 1;
}
//------------------------------------ setFont --------------------------------------------------------
void C_PopupDialCorpoFact::setFont(const QFont &fnt)
{
 C_PopupDial::setFont(fnt);
 m_fGrd  =  fnt;
 label_unit_FactCorpo->setFont(m_fGrd);
 lineEdit_poids->setFont(m_fGrd);
 label_kg_x->setFont(m_fGrd);
 pushButton_UPA->setFont(m_fGrd);
 pushButton_UFC->setFont(m_fGrd);
 label_QPA->setFont(m_fGrd);
 label_QFC->setFont(m_fGrd);
 label_QPA_by_UP_0->setFont(m_fGrd);
 label_QPA_by_UP_1->setFont(m_fGrd);
 lineEdit_QPA_by_UP->setFont(m_fGrd);
}
//----------------------------------- ~C_PopupDialCorpoFact -------------------------------------------
C_PopupDialCorpoFact::~C_PopupDialCorpoFact()
{
}
