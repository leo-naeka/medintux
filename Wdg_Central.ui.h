/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you wish to add, delete or rename functions or slots use
** Qt Designer which will update this file, preserving your code. Create an
** init() function in place of a constructor, and a destroy() function in
** place of a destructor.
*****************************************************************************/

#include <qtextcodec.h>
#include <qiconset.h>
#include <qdatetimeedit.h>
//.................. index des champs .......................................
#define LIST_NOM       0
#define LIST_PRENOM    1
#define LIST_ID_KEY    2
#define LIST_GUID      3

#define F_GUID         0

#define NEW_IDENTITE 1
#define MODE_SAISIE_EN_COURS      1
#define MODE_SAISIE_NON_EN_COURS  0
#include "CDlg_MetaFieldDefine.h"
#include "CMetaFiltre.h"

//----------------------------------------- init ----------------------------------------------------------------------
void Wdg_Central::init()
{   m_pCMoteurBase      = G_pCApp->m_pCMoteurBase;
    m_ID_Doss           = "";
    m_pCGestRPU         = 0;
    m_pQtimerCheckState = 0;
    m_pQPopupMenu       = 0;
    m_MonitorIsInit     = 0;
    m_IdentIsClear      = 1;
    listView_Sql_IdentFields->setSorting ( -1 );
    listView_Def_MetaFields->setSorting ( -1 );
    listView_Sql_MetaFields->setSorting ( -1 );
    listView_DenombreTest->setSorting ( -1 );

    m_CDenombreList.setAutoDelete ( TRUE );
    m_CMetaFieldList.setAutoDelete ( TRUE );

    m_PAGE_EPP    = tr("Evaluation Statistique");
    m_PAGE_RPU    = tr("Elaboration Fichers RPU");

    m_PAGE_EPP  = tabWidgetTypeEvaluation->tabLabel ( tabWidgetTypeEvaluation->page(1) );  //"P&rescription";
    m_PAGE_RPU  = tabWidgetTypeEvaluation->tabLabel ( tabWidgetTypeEvaluation->page(0) );  //"&Monographie";
    tabWidgetTypeEvaluation->setCurrentPage( 1 );
    tabWidget_Dossiers->setCurrentPage( 1 );
    //................................ connexion .........................................................
    connect( mle_deb,      SIGNAL( Sig_FocusOut()),           this,     SLOT(   OnOutFocusDateHeure())  );
    connect( mle_fin,      SIGNAL( Sig_FocusOut()),           this,     SLOT(   OnOutFocusDateHeure())  );
    connect( mle_HeureDeb, SIGNAL( Sig_FocusOut()),           this,     SLOT(   OnOutFocusDateHeure())  );
    connect( mle_HeureFin, SIGNAL( Sig_FocusOut()),           this,     SLOT(   OnOutFocusDateHeure())  );

    //.................. images des boutons ..............................................................
    QString path_img = G_pCApp->m_PathAppli + "Images/";

    pushButton_MaskListSqlField->setPixmap ( QPixmap(path_img +"DownLitle.png") );
    pushButton_AddListIdentField->setPixmap ( QPixmap(path_img +"Plus.png") );
    pushButton_DelListIdentField->setPixmap ( QPixmap(path_img +"Moins.png") );

    pushButton_MaskListMetaField->setPixmap ( QPixmap(path_img +"DownLitle.png") );
    pushButton_AddListMetaField->setPixmap ( QPixmap(path_img +"Plus.png") );
    pushButton_DelListMetaField->setPixmap ( QPixmap(path_img +"Moins.png") );

    pushButton_AddDefMetaField->setPixmap ( QPixmap(path_img +"Plus.png") );
    pushButton_DelDefMetaField->setPixmap ( QPixmap(path_img +"Moins.png") );

    pushButton_UpDefMetaField->setPixmap ( QPixmap(path_img +"Haut.png") );
    pushButton_DownDefMetaField->setPixmap ( QPixmap(path_img +"Bas.png") );

    pushButton_MaskListClassDenombre->setPixmap ( QPixmap(path_img +"DownLitle.png") );
    pushButton_AddClassField->setPixmap ( QPixmap(path_img +"Plus.png") );
    pushButton_DelClassField->setPixmap ( QPixmap(path_img +"Moins.png") );

    pushButton_AddTestClassDenombre->setPixmap ( QPixmap(path_img +"Plus.png") );
    pushButton_DelTestClassDenombre->setPixmap ( QPixmap(path_img +"Moins.png") );

    //....................................... texte d'information..............................................................
    QString txt;
    textBrowserInfoPerms->mimeSourceFactory()->setExtensionType("html", "text/xml;charset=UTF-8");
    textBrowserInfoPerms->mimeSourceFactory()->addFilePath (G_pCApp->m_PathAppli + "/Images" );
    textBrowserInfoPerms->setSource (G_pCApp->m_PathAppli + "/Images/InfoMetaChamps.html" );
    CGestIni::Param_UpdateFromDisk(G_pCApp->m_PathAppli + "/Images/InfoMetaChamps.html", txt);
    txt.replace("meta name=\"qrichtext\" content=\"charset=utf-8\"",    "meta name=\"qrichtext\" content=\"1\"");
    textBrowserInfoPerms->setText(txt);
    //initFieldsList();

    /////////////////////////////////////////////////// INIT ONGLET IDENTIFICATION ////////////////////////////////////


    //.................................................................................................................
    ///////////////////////////////////////////////////INIT ONGLET STATISTIQUES //////////////////////////////////////
    //........................ images des differents gadjets.................................

    m_GoDatePopup.setPixmap (QPixmap(path_img +"DownExpandArrow.xpm"),    QIconSet::Automatic);
    m_Cadenas.setPixmap (QPixmap(path_img +"Cadenas.png"),                QIconSet::Automatic);
    m_Standard.setPixmap (QPixmap(path_img +"standards.png"),             QIconSet::Automatic);

    //........................ dates et heure des stat.................................
    QDate dateDeb(QDate::currentDate());
    QDate dateFin(QDate::currentDate());
    dateDeb = dateDeb.addDays (-1);
    //dateFin   = dateFin.addDays (1);
    mle_deb->setText(dateDeb.toString("ddMMyyyy"));
    mle_fin->setText(dateFin.toString("ddMMyyyy"));
    mle_HeureDeb->setText("0800");
    mle_HeureFin->setText("0800");
    pushButtonDateFin->setIconSet (m_GoDatePopup);
    pushButtonDateDeb->setIconSet (m_GoDatePopup);
    //.................................................................................................................
    ///////////////////////////////////////////////////INIT ONGLET MONITEUR //////////////////////////////////////
    //........................ dates et heure du moniteur patient.................................
    QDate dateDeb_Mon(QDate::currentDate());
    QDate dateFin_Mon(QDate::currentDate());
    dateFin_Mon = dateFin_Mon.addDays (1);
    mle_deb_Mon->setText(dateDeb_Mon.toString("ddMMyyyy"));
    mle_fin_Mon->setText(dateFin_Mon.toString("ddMMyyyy"));
    mle_HeureDeb_Mon->setText("0800");
    mle_HeureFin_Mon->setText("0800");
    pushButtonDateFin_Mon->setIconSet (m_GoDatePopup);
    pushButtonDateDeb_Mon->setIconSet (m_GoDatePopup);

    /*
  QWidget *w = tabWidget_Cenral->page ( 0 ) ;
  QPixmap pixmap (path_img +"Marbre.jpg");
  if (w>0)
     {w->setPaletteBackgroundPixmap ( pixmap );
     }
  groupBoxPatient->setPaletteBackgroundPixmap ( pixmap );
  groupBoxAssure->setPaletteBackgroundPixmap ( pixmap  );
  w = tabWidgetNotes->page ( 0 ) ;
  if (w>0)
     {w->setPaletteBackgroundPixmap ( pixmap  );
     }
   */
    //............................ creer le timer de verification .................................
    // [Monitor]
    //     Rafraichissement = 120
    //spinBoxRafraichInterval->setMaxValue(3000);
    QString mode;
    if (CGestIni::Param_ReadParam(m_LocalParam, "Monitor", tr("Rafraichissement"), &mode)==0)   // = zero si pas d'erreur
       {spinBoxRafraichInterval->setValue (mode.toInt());
       }
    else spinBoxRafraichInterval->setValue (5);
    m_pQtimerCheckState = new QTimer;
    connect( m_pQtimerCheckState, SIGNAL(timeout()), this, SLOT(CheckState()) );
    m_pQtimerCheckState->start(3*1000, FALSE);
    //............................ Placer le spliter dans la bonne position .................................

    QValueList <int> list;
    list.append(60);
    list.append(height()-60);
    //splitter3->setSizes(list);
    list.clear();
    list.append(150);
    list.append(width()-150);
    //splitter3->setSizes(list);
    SetInterfaceOnDroits(G_pCApp->m_Droits, MODE_SAISIE_NON_EN_COURS);
}

//------------------------------------------- getCurrentPageID_ByTitle ------------------------------------------------------------------------
int Wdg_Central::getCurrentPageID_ByTitle(QTabWidget *pQTabWidget, const QString &title)
{int nb = pQTabWidget->count();
 for ( int i=0; i<nb; ++i)
     {if (pQTabWidget->label(i) == title) return i;
     }
 return -1;
}

//--------------------------------- SetInterfaceOnMode -----------------------------------------------------------------------
//    #define MODE_SAISIE_EN_COURS      1
//    #define MODE_SAISIE_NON_EN_COURS  0
void  Wdg_Central::SetInterfaceOnMode(const QString &droits, int mode)
{if (G_pCApp->IsThisDroitExist(droits, "idv"))
    {
    }
}

//--------------------------------- SetInterfaceOnDroits -----------------------------------------------------------------------
//    #define MODE_SAISIE_EN_COURS      1
//    #define MODE_SAISIE NON_EN COURS  0
void  Wdg_Central::SetInterfaceOnDroits(const QString &droits, int mode)
{//-idv-idc-idg
 if (G_pCApp->IsThisDroitExist(droits, "idv"))
    {
    }

 SetInterfaceOnMode(droits,  mode);
}
//----------------------------------------- setButtonOnContexte ----------------------------------------------------------------------
void Wdg_Central::setButtonOnContexte(int mode )
{
}
//----------------------------------------- destroy ----------------------------------------------------------------------
void Wdg_Central::destroy()
{if (m_pCGestRPU)            delete m_pCGestRPU;
    if (m_pQtimerCheckState) delete m_pQtimerCheckState;
}

//----------------------------------------- tabWidget_Central_currentChanged ----------------------------------------------------------------------
void Wdg_Central::tabWidget_Central_currentChanged( QWidget *pageWidget )
{if (pageWidget==0) return;
    if (tabWidget_Central->tabLabel(pageWidget) == tr("&Moniteur"))
    {//qDebug(tabWidget_Central->tabLabel(pageWidget));
     if (m_MonitorIsInit == 0)
        {m_MonitorIsInit=1;
         CheckState( );
       }
    }
 else
    {m_MonitorIsInit = 0;
    }
}
    //=======================================================================================================================================
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////// ONGLET MONITEUR /////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //=======================================================================================================================================
    /*................. relever les dates de debut et fin ..................................*/
    /*
    QDate dateDeb  (QDate::currentDate());
    QDate dateFin  (QDate::currentDate());

    int jour, mois, annee;
    QString text = mle_debut_Mon->text();
    jour  = text.mid(0,2).toInt();
    mois  = text.mid(2,2).toInt();
    annee = text.mid(4,4).toInt();
    if (QDate::isValid ( annee, mois, jour ) ) dateDeb.setYMD (annee , mois  , jour);
    mle_debut_Mon->setText(dateDeb.toString("ddMMyyyy"));
    text  = mle_fin_Mon->text();
    jour  = text.mid(0,2).toInt();
    mois  = text.mid(2,2).toInt();
    annee = text.mid(4,4).toInt();
    if (QDate::isValid ( annee, mois, jour ) ) dateFin_Mon.setYMD (annee , mois  , jour);
    mle_fin->setText(dateFin_Mon.toString("ddMMyyyy"));

    //........................ la requete .....................................................................
    // les dates de la requete sont volontairement placées un jour avant et apres la fourchette de selection
    // car il peut arriver que certains dossiers soient créés après la garde et donc les heures strictement concernées
    // par la garde peuvent ne plus s'appliquer: exemple je vois le patient à 7h45 et apres la fin de garde (8h00)
    // par exemple à 9h je crée le dossier. Donc le test entre 8h la veille et 8h en fin de garde ne fonctionnerai
    // pas.
    QDate reqDateDeb = dateDeb.addDays(-1); QString reqDateDebStr = reqDateDeb.toString("yyyyMMdd");
    QDate reqDateFin = dateFin.addDays(+1); QString reqDateFinStr = reqDateFin.toString("yyyyMMdd");
    */
    //............... requete utilisant la base virtuelle .....................................................
    /*
 //................. DOSS_RUB_HEAD ............................
 QString      m_DOSS_RUB_HEAD_TBL_NAME;        // nom de la table de l'header des RUBRIQUES
 QString      m_DOSS_RUB_HEAD_PRIMKEY;         // clef primaire de cet enregistrement
 QString      m_DOSS_RUB_HEAD_GUID;            // GUID du dossier auquel l'enregistrement fait reference
 QString      m_DOSS_RUB_HEAD_REF_DOSS_PK;     // Clef primaire du dossier auquel l'enregistrement fait reference (doublon avec m_DOSS_RUB_HEAD_GUID)
 QString      m_DOSS_RUB_HEAD_NOM_DATE;        // Court texte descriptif de l'enregistrement.
 QString      m_DOSS_RUB_HEAD_DATE;            // date de l'enregistrement
 QString      m_DOSS_RUB_HEAD_DUREE;           // duree de l'enregistrement
 QString      m_DOSS_RUB_HEAD_TYPE;            // Type de rubrique
 QString      m_DOSS_RUB_HEAD_USER;            // utilisateur associé à rubrique

 //................. DOSS_RUB_DATA ............................
 QString      m_DOSS_RUB_DATA_TBL_NAME;        // nom de la table des données des RUBRIQUES
 QString      m_DOSS_RUB_DATA_PRIMKEY;         // clef primaire de cet enregistrement  (le meme que le header)
 QString      m_DOSS_RUB_DATA_BLOB;            // données binaires
 *//*
    if (m_pCMoteurBase->m_DataBase->isOpen()==FALSE && m_pCMoteurBase->m_DataBase->open()==FALSE)  return ;  // si point = erreur d'ouverture de la base
    QString requete("SELECT ");
    requete +=  m_pCMoteurBase->m_DOSS_RUB_HEAD_GUID     + "," +        // 0
                m_pCMoteurBase->m_DOSS_RUB_HEAD_PRIMKEY  + "," +        // 1
                m_pCMoteurBase->m_DOSS_RUB_HEAD_USER     + "," +        // 2
                m_pCMoteurBase->m_DOSS_RUB_HEAD_DATE     + " FROM  " +  // 3
                m_pCMoteurBase->m_DOSS_RUB_HEAD_TBL_NAME + " WHERE " +
                //m_pCMoteurBase->m_DOSS_RUB_HEAD_TYPE     + " = '20030000'";
                m_pCMoteurBase->m_DOSS_RUB_HEAD_TYPE     + " = '20030000' AND " +
                m_pCMoteurBase->m_DOSS_RUB_HEAD_DATE     + " >= '" + reqDateDebStr + "' AND " + m_pCMoteurBase->m_DOSS_RUB_HEAD_DATE + "<= '" + reqDateFinStr + "'";
    QSqlQuery query(requete , m_pCMoteurBase->m_DataBase );
    long  nbRecord       = 0;
    long  nbRecordTotal  = 0;

    */
//----------------------------------- pushButtonDateDeb_Mon_clicked() ----------------------------------
void Wdg_Central::pushButtonDateDeb_Mon_clicked()
    {   Dlg_Calendar          *dlg  = new Dlg_Calendar(this, "Calendar_Dial", FALSE);
        if (dlg ==0)                                                   return;
        dlg->setCaption(tr("Date de début"));
        dlg->move ( QCursor::pos().x(), QCursor::pos().y() );
        dlg->setMenuPreselectDateOn();
        dlg->Month_setIcon(    QPixmap(G_pCApp->m_PathAppli + "Images/Left_Blue.png") ,  QPixmap(G_pCApp->m_PathAppli + "Images/Right_Blue.png") );
        dlg->Year_setIcon(     QPixmap(G_pCApp->m_PathAppli + "Images/Left_Yelow.png") , QPixmap(G_pCApp->m_PathAppli + "Images/Right_Yelow.png") );
        dlg->DateMenu_setIcon( QPixmap(G_pCApp->m_PathAppli + "Images/DatePreselect.png"));
        QStringList  preselectList;
        if (GetPreselectDateList(preselectList))  dlg->setMenuPreSelectDate(preselectList);

        QString text = mle_deb_Mon->text();
        int jour, mois, annee;
        jour  = text.mid(0,2).toInt();
        mois  = text.mid(2,2).toInt();
        annee = text.mid(4,4).toInt();
        if (QDate::isValid ( annee, mois, jour ) )
           {dlg->setDate(QDate(annee, mois, jour));
           }
        if (dlg->exec()== QDialog::Accepted )
           {mle_deb_Mon->setText(dlg->getDate().toString("ddMMyyyy"));
            mle_HeureDeb_Mon->setText(dlg->timeEdit_Heure->time ().toString("hhmm"));
           }
        delete dlg;
    }

//----------------------------------- pushButtonDateFin_Mon_clicked() ----------------------------------
void Wdg_Central::pushButtonDateFin_Mon_clicked()
{       Dlg_Calendar          *dlg  = new Dlg_Calendar(this, "Calendar_Dial", FALSE);
        if (dlg ==0)                                                   return;
        dlg->setCaption(tr("Date de fin"));
        dlg->move ( QCursor::pos().x(), QCursor::pos().y() );
        dlg->setMenuPreselectDateOn();
        dlg->Month_setIcon(    QPixmap(G_pCApp->m_PathAppli + "Images/Left_Blue.png") ,  QPixmap(G_pCApp->m_PathAppli + "Images/Right_Blue.png") );
        dlg->Year_setIcon(     QPixmap(G_pCApp->m_PathAppli + "Images/Left_Yelow.png") , QPixmap(G_pCApp->m_PathAppli + "Images/Right_Yelow.png") );
        dlg->DateMenu_setIcon( QPixmap(G_pCApp->m_PathAppli + "Images/DatePreselect.png"));
        QStringList  preselectList;
        if (GetPreselectDateList(preselectList))  dlg->setMenuPreSelectDate(preselectList);
        QString text = mle_fin_Mon->text();
        int jour, mois, annee;
        jour  = text.mid(0,2).toInt();
        mois  = text.mid(2,2).toInt();
        annee = text.mid(4,4).toInt();
        if (QDate::isValid ( annee, mois, jour ) )
           {dlg->setDate(QDate(annee, mois, jour));
           }
        if (dlg->exec()== QDialog::Accepted )
        {mle_fin_Mon->setText(dlg->getDate().toString("ddMMyyyy"));
         mle_HeureFin_Mon->setText(dlg->timeEdit_Heure->time ().toString("hhmm"));
        }
        delete dlg;
    }

//----------------------------------------- NaturalToSqlDate ------------------------------------------------------------------------
QString Wdg_Central::NaturalToSqlDate(const QString &inDate )    // 05061956
{char    *pt = (char*)(const char*) inDate;
 QString ret = "";
 if (pt)
    { while ( *pt )  {if (*pt>='0'&&*pt<='9')  {ret += *pt;} ++pt; }  // eliminer tout ce qui n'est pas numérique '-' et autre '/'
      ret = ret.mid(4,4) + ret.mid(2,2) + ret.mid(0,2);
    }
 return ret;
}
//----------------------------------------- SqlDateToNatural ------------------------------------------------------------------------
QString Wdg_Central::SqlDateToNatural(const QString &inDate ) // 19560506
{ char    *pt = (char*)(const char*) inDate;
 QString ret = "";
 if (pt)
    { while ( *pt )  {if (*pt>='0'&&*pt<='9')  {ret += *pt;} ++pt; }  // eliminer tout ce qui n'est pas numérique '-' et autre '/'
      ret= ret.mid(6,2) + ret.mid(4,2) + ret.mid(0,4);
    }
 return ret;
}

//----------------------------------------- pushButtonRaffraichir_clicked ------------------------------------------------------------------------
void Wdg_Central::pushButtonRaffraichir_clicked()
{makeListeMonitor();
}


//----------------------------------------- CheckState ------------------------------------------------------------------------
void Wdg_Central::CheckState( )
{    //...................... si page Moniteur active ...................................
     m_MonitorIsInit += 3;    // le timer est regle sur trois secondes
     if (m_MonitorIsInit >= spinBoxRafraichInterval->value () * 60)
        {if (checkBoxAutomaticRebuild->isChecked ()) makeListeMonitor();
         m_MonitorIsInit = 1;
        }
}

//----------------------------------------------- makeListeMonitor ---------------------------------------------------
void Wdg_Central::makeListeMonitor()
{        //QWidget *pageWidget =  tabWidget_Central->currentPage ();
         QString requete ="SELECT IndexNomPrenom.FchGnrl_NomDos, "
                          "IndexNomPrenom.FchGnrl_Prenom, "
                          "IndexNomPrenom.ID_PrimKey,"
                          "IndexNomPrenom.FchGnrl_IDDos"
                          " FROM RubriquesHead INNER JOIN IndexNomPrenom ON RubriquesHead.RbDate_IDDos=IndexNomPrenom.FchGnrl_IDDos WHERE RbDate_Date >= " +
                          NaturalToSqlDate(mle_deb_Mon->text())                     +
                          " AND RbDate_Date <= "                                    +
                          NaturalToSqlDate(mle_fin_Mon->text())                     +
                          " AND RbDate_TypeRub='20030000' AND RbDate_CreateUser= '" +
                          m_UserName                                                +
                          "' ORDER BY RbDate_Date";

            if (m_pCMoteurBase->m_DataBase->isOpen()==TRUE && m_pCMoteurBase->m_DataBase->open()==TRUE)
               {QSqlQuery query(requete , m_pCMoteurBase->m_DataBase );
                if (query.isActive())
                   {ListView_MonitorPatient->clear();
                    while (query.next())
                           {new QListViewItem (ListView_MonitorPatient,
                                               CGestIni::Utf8_Query(query, 0 ),
                                               CGestIni::Utf8_Query(query, 1 ),
                                               CGestIni::Utf8_Query(query, 2 ),
                                               CGestIni::Utf8_Query(query, 3 )
                                              );
                           }
                  }
                else
                  {m_pCMoteurBase->OutSQL_error(query, "CheckState( )" , requete /*=0*/);
                  }
                m_pCMoteurBase->m_DataBase->close();
               }
}

//----------------------------------------------- ListView_MonitorPatient_doubleClicked ---------------------------------------------------
void Wdg_Central::ListView_MonitorPatient_doubleClicked( QListViewItem *pQListViewItem, const QPoint &, int )
{   if (G_pCApp->IsThisDroitExist(G_pCApp->m_Droits, "idg")==0)
      {QMessageBox::warning ( this, tr("Lancement de dossier :"),
                                     tr( "Vos droits sont insuffisants pour lancer un dossier"),
                                     tr("&Annuler"),0, 0,
                                     1, 1
                                     );
       return;
      }
    if ( pQListViewItem == 0) return;
    AccederDossier(pQListViewItem->text(0),    // Nom assuré
                   pQListViewItem->text(1),    // Prenom assuré
                   pQListViewItem->text(2),    // numero PrimKey
                   pQListViewItem->text(3),    // GUID dossier
                   G_pCApp->m_User,            // login de l'utilisateur en cours
                   G_pCApp->m_SignUser);       // login de l'utilisateur signataire en cours

}

//-----------------------------------mle_debut_Mon_lostFocus()----------------------------------
void Wdg_Central::mle_debut_Mon_lostFocus()
{
        int jour, mois, annee;
        QDate dateDebut;

        if (mle_deb->text().length() == 8) {
            jour  = mle_deb->text().mid(0,2).toInt();
            mois  = mle_deb->text().mid(2,2).toInt();
            annee = mle_deb->text().mid(4,4).toInt();
            if ( dateDebut.setYMD( annee , mois , jour ) != true) {
                QMessageBox mb( tr("Date incohérente"),
                                tr("La date de début n'est pas correcte\n"),
                                QMessageBox::Critical,
                                QMessageBox::Ok | QMessageBox::Default,0,0);
                mb.exec();
                mle_deb->setFocus();
            } else {
                //lanceRecherche();
            }
        } else {
            //lanceRecherche();
        }
}


//-----------------------------------mle_fin_Mon_lostFocus()----------------------------------
void Wdg_Central::mle_fin_Mon_lostFocus()
{
        int jour, mois, annee;
        QDate dateFin;

        if (mle_fin->text().length() == 8) {
            jour  = mle_fin->text().mid(0,2).toInt();
            mois  = mle_fin->text().mid(2,2).toInt();
            annee = mle_fin->text().mid(4,4).toInt();
            if ( dateFin.setYMD( annee , mois , jour ) != true) {
                QMessageBox mb( tr("Date incohérente"),
                                tr("La date de fin n'est pas correcte\n"),
                                QMessageBox::Critical,
                                QMessageBox::Ok | QMessageBox::Default,0,0);
                mb.exec();
                mle_fin->setFocus();
            } else {
                //lanceRecherche();
            }
        } else {
            //lanceRecherche();
        }
}

//=======================================================================================================================================
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////// ONGLET IDENTIFICATION ///////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//=======================================================================================================================================

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////// LISTE PATIENT ///////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//----------------------------------------- setUser ------------------------------------------------------------------------
void Wdg_Central::setUser( const QString &userName, const QString &signUser)
{m_UserName = userName;
 m_SignUser = signUser;
}

//----------------------------------------------- closeEvent -------------------------------------------------------------
void Wdg_Central::closeEvent( QCloseEvent* ce )
{   //ce->accept();
    ce->ignore();

}





//--------------------------------- ClearDialog -------------------------------------------------------------------------------------------
void Wdg_Central::ClearDialog()
{   //.......................... effacer dossier en cours ...........................
    G_pCApp->m_LastNom     ="";
    G_pCApp->m_LastPrenom  ="";
    G_pCApp->m_LastGUID    ="";
    G_pCApp->m_LastPK      ="";
    G_pCApp->m_LastTel     ="";

}

//--------------------------------- ToNum ---------------------------------------------------------------------------------
QString Wdg_Central::ToNum(QString in)
{for(uint i=0; i<in.length(); )
    {if (in.at(i)<'0' || in.at(i)>'9') in.remove(i,1);
        else ++i;
    }
    return in;
}


//--------------------------------- DoPopupList ----------------------------------------------------------------------
QString Wdg_Central::DoPopupList(QStringList &list)
{   m_CurrentPopupItem = "";
    m_RetPopupItem     = "";
    if (m_pQPopupMenu) return m_RetPopupItem;
    m_pQPopupMenu      = new QPopupMenu(0, "MyPopupMenu" );
    if (m_pQPopupMenu==0)       return m_RetPopupItem;
    //............................... chercher une zone de liste deroulante (bleue) .....................
    for ( QStringList::Iterator it =list.begin(); it != list.end(); ++it )
    {m_pQPopupMenu->insertItem( *(it),    this, SLOT( GetPopupItem()),  CTRL+Key_L );
    }
    //................. connecter le menu .................................................................
    connect( m_pQPopupMenu, SIGNAL( activated( int)),
             this,          SLOT(OnMenuActivated( int))
             );

    m_pQPopupMenu->exec(QCursor::pos());
    delete  m_pQPopupMenu;
    m_pQPopupMenu = 0;
    return  m_RetPopupItem;
}

//--------------------------------- OnMenuActivated  -------------------------------------------------------------
void Wdg_Central::OnMenuActivated (int id)
{if (id != -1 && m_pQPopupMenu)
    {m_CurrentPopupItem = m_pQPopupMenu->text(id);
    }
}

//--------------------------------- GetPopupItem  -------------------------------------------------------------
void Wdg_Central::GetPopupItem ()
{m_RetPopupItem  = m_CurrentPopupItem;
}



//--------------------------------- AccederDossier -----------------------------------------------------------------------------
void Wdg_Central::AccederDossier( QString nom,  QString prenom, const QString &primKey, const QString &guid, const QString &user, const QString &sign_user)
{  if (G_pCApp->IsThisDroitExist(G_pCApp->m_Droits, "idg")==0)
      {QMessageBox::warning ( this, tr("Lancement de dossier :"),
                                     tr( "Vos droits sont insuffisants pour lancer un dossier"),
                                     tr("&Annuler"),0, 0,
                                     1, 1
                                     );
       return;
      }

    // pDrTux = new DrTux(argv[1],       // utilisateur
    //                    argv[2],       // num_doss (GUID dossier)
    //                    argv[3],       // ID_Doss (fchgnrl2002_nom_prenom WHERE ID_PrimKey = ID_Doss)
    //                    argv[4],       // nom dossier
    //                    argv[5]        // prenom dossier
    //                   );
    QString usedBy;
    if ( m_pCMoteurBase->IsDossierVerrouille( guid, usedBy ))
    {//.............. si l'utilisateur du dossier est le même que celui du poste de travail...................................
        //               alors le dossier est déjà lancé sur le poste de travail local
        //               on le lance et alors il se met en premier plan (car gère comme cela l'instance unique)
        // sinon on demande si l'on veut lancer le dossier présent sur un autre poste avec avertisement des
        // conséquences
        if (m_pCMoteurBase->m_UserName + "@" + m_pCMoteurBase->m_HostName != usedBy &&
            AlertVerrou(usedBy, nom, prenom)!=0)
           {return;
           }
    }
    //................ Lancer le process .................................................................
    QProcess  proc;
    QString pathExe  = CGestIni::Construct_Name_Exe("drtux",QFileInfo (qApp->argv()[0]).dirPath (true));
    proc.addArgument( pathExe );
    proc.addArgument( user);                                        // login de l'utilisateur
    proc.addArgument( sign_user );                                  // login du signataire
    proc.addArgument( guid );                                       // GUID dossier
    proc.addArgument( primKey);                                     // numero PrimKey
    proc.addArgument( nom.replace("'","~@~") );                                        // Nom assuré
    proc.addArgument( prenom.replace("'","~@~") );                                     // Prenom assuré
    /*
    QStringList arg_lst = proc.arguments ();
    for ( QStringList::Iterator it = arg_lst.begin(); it != arg_lst.end(); ++it )
        { qDebug( *it );
        }
    */
    QString str = CGestIni::Construct_Name_File_Ini("Manager",QFileInfo (qApp->argv()[0]).dirPath (true), "");
    proc.addArgument(str );
    // fichier ini
    str = CGestIni::Construct_Name_File_Ini("Manager",QFileInfo (qApp->argv()[0]).dirPath (true), "DataBase.cfg");
    proc.addArgument( str );
    // fichier cfgBase
    if ( !proc.start() )
       {qDebug("ListView_Patient_doubleClicked(): Echec de l'ouverture du process");
       }
   // pushButtonAcceder->setIconSet (m_Cadenas);

}

//--------------------------------------- AlertVerrou -------------------------------------------------------------------------------
int  Wdg_Central::AlertVerrou(const QString &userBy, const QString &dossNom, const QString &dossPrenom)
{   QString value;
    CGestIni::Param_ReadParam(m_LocalParam, "Gestion des dossiers", "Acces Concurrent", &value);   // path editeur de texte non défini
    if (value.lower() == tr("non possible"))
    {  QMessageBox::information( this, tr(  "OUVERTURE CONFLICTUELLE"),
                                 tr(  " <b><u>ATTENTION</b></u> ! Ce dossier <font color=\"#e80d0d\"><b>")          + dossNom     + " " + dossPrenom  +
                                 tr(  "</b></font> est déjà ouvert sur le poste suivant : <b>" )   + userBy  +
                                 tr(  "</b><br> Son accès n'est possible qu'en lecture seulement,<br>"
                                      "il se mettra automatiquement en mode écriture<br>"
                                      "dés qu'il sera disponible sur votre poste") ,
                                 //"&nbsp;&nbsp;&nbsp;&nbsp; ° <b>Quitter pour <u>Annuler</u></b> l'opération en cours" ) ,
                                 tr("Annu&ler"),0 , 0,
                                 1, 1 );
        return 1;
    }
    return QMessageBox::information( this, tr("OUVERTURE CONFLICTUELLE"),
                                     tr ( " <b><u>ATTENTION</b></u> ! Ce dossier <b>")          + dossNom     + " " + dossPrenom  +
                                     tr(  "</b> est déjà ouvert sur le poste suivant : <b>" )   + userBy  +
                                     tr(  "</b><br> Faut-il tenter tout de même l'ouverture ?<br>") ,
                                     //"&nbsp;&nbsp;&nbsp;&nbsp; ° <b>Quitter pour <u>Annuler</u></b> l'opération en cours" ) ,   1111b0
                                     tr("&Ouvrir"), tr("Annu&ler"), 0,
                                     1, 1 );
}

//=======================================================================================================================================
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////// ONGLET STATISTIQUES /////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//=======================================================================================================================================

//----------------------------------- GetPreselectDateList ----------------------------------
int Wdg_Central::GetPreselectDateList(QStringList & rQStringList)
{QString      preselectStr;
 CGestIni::Param_UpdateFromDisk(G_pCApp->m_PathAppli + "/Images/PreselectDates.txt", preselectStr);
 if (preselectStr.length()==0) return 0;
 preselectStr = preselectStr.stripWhiteSpace();
 preselectStr = preselectStr.remove("\r");
 preselectStr = preselectStr.remove("\n");
 rQStringList = QStringList::split (';', preselectStr);
 return rQStringList.count();
}

//----------------------------------- pushButtonDateDeb_clicked() ----------------------------------
void Wdg_Central::pushButtonDateDeb_clicked()
{   Dlg_Calendar          *dlg  = new Dlg_Calendar(this, "Calendar_Dial", FALSE);
    if (dlg ==0)                                                   return;
    dlg->setCaption(tr("Date de début"));
    dlg->move ( QCursor::pos().x(), QCursor::pos().y() );
    dlg->setMenuPreselectDateOn();
    dlg->Month_setIcon(    QPixmap(G_pCApp->m_PathAppli + "Images/Left_Blue.png") ,  QPixmap(G_pCApp->m_PathAppli + "Images/Right_Blue.png") );
    dlg->Year_setIcon(     QPixmap(G_pCApp->m_PathAppli + "Images/Left_Yelow.png") , QPixmap(G_pCApp->m_PathAppli + "Images/Right_Yelow.png") );
    dlg->DateMenu_setIcon( QPixmap(G_pCApp->m_PathAppli + "Images/DatePreselect.png"));
    QStringList  preselectList;
    if (GetPreselectDateList(preselectList))  dlg->setMenuPreSelectDate(preselectList);
    QString text = mle_deb->text();
    int jour, mois, annee;
    jour  = text.mid(0,2).toInt();
    mois  = text.mid(2,2).toInt();
    annee = text.mid(4,4).toInt();
    if (QDate::isValid ( annee, mois, jour ) )
    {dlg->setDate(QDate(annee, mois, jour));
    }
    if (dlg->exec()== QDialog::Accepted )
    {mle_deb->setText(dlg->getDate().toString("ddMMyyyy"));
     mle_HeureDeb->setText(dlg->timeEdit_Heure->time ().toString("hhmm"));
    }
    delete dlg;
    QString tab_name = tabWidgetTypeEvaluation->tabLabel ( tabWidgetTypeEvaluation->currentPage () );
    if      (tab_name==m_PAGE_EPP) textEdit_Sql_IdentSelect->setText(ConstructRequeteIdentSelect());
}


//----------------------------------- pushButtonDateFin_clicked() ----------------------------------
void Wdg_Central::pushButtonDateFin_clicked()
{   Dlg_Calendar          *dlg  = new Dlg_Calendar(this, "Calendar_Dial", FALSE);
    if (dlg ==0)                                                   return;
    dlg->setCaption(tr("Date de fin"));
    dlg->move ( QCursor::pos().x(), QCursor::pos().y() );
    dlg->setMenuPreselectDateOn();
    dlg->Month_setIcon(    QPixmap(G_pCApp->m_PathAppli + "Images/Left_Blue.png") ,  QPixmap(G_pCApp->m_PathAppli + "Images/Right_Blue.png") );
    dlg->Year_setIcon(     QPixmap(G_pCApp->m_PathAppli + "Images/Left_Yelow.png") , QPixmap(G_pCApp->m_PathAppli + "Images/Right_Yelow.png") );
    dlg->DateMenu_setIcon( QPixmap(G_pCApp->m_PathAppli + "Images/DatePreselect.png"));
    QStringList  preselectList;
    if (GetPreselectDateList(preselectList))  dlg->setMenuPreSelectDate(preselectList);

    QString text = mle_fin->text();
    int jour, mois, annee;
    jour  = text.mid(0,2).toInt();
    mois  = text.mid(2,2).toInt();
    annee = text.mid(4,4).toInt();
    if (QDate::isValid ( annee, mois, jour ) )
    {dlg->setDate(QDate(annee, mois, jour));
    }
    if (dlg->exec()== QDialog::Accepted )
    {mle_fin->setText(dlg->getDate().toString("ddMMyyyy"));
     mle_HeureFin->setText(dlg->timeEdit_Heure->time ().toString("hhmm"));
    }
    delete dlg;
    QString tab_name = tabWidgetTypeEvaluation->tabLabel ( tabWidgetTypeEvaluation->currentPage () );
    if      (tab_name==m_PAGE_EPP) textEdit_Sql_IdentSelect->setText(ConstructRequeteIdentSelect());

}

//-----------------------------------mle_debut_lostFocus()----------------------------------
void Wdg_Central::mle_debut_lostFocus()
{
    int jour, mois, annee;
    QDate dateDebut;

    if (mle_deb->text().length() == 8) {
        jour  = mle_deb->text().mid(0,2).toInt();
        mois  = mle_deb->text().mid(2,2).toInt();
        annee = mle_deb->text().mid(4,4).toInt();
        if ( dateDebut.setYMD( annee , mois , jour ) != true) {
            QMessageBox mb( tr("Date incohérente"),
                            tr("La date de début n'est pas correcte\n"),
                            QMessageBox::Critical,
                            QMessageBox::Ok | QMessageBox::Default,0,0);
            mb.exec();
            mle_deb->setFocus();
        } else {
            //lanceRecherche();
        }
    } else {
        //lanceRecherche();
    }
}


//-----------------------------------mle_fin_lostFocus()----------------------------------
void Wdg_Central::mle_fin_lostFocus()
{
    int jour, mois, annee;
    QDate dateFin;

    if (mle_fin->text().length() == 8) {
        jour  = mle_fin->text().mid(0,2).toInt();
        mois  = mle_fin->text().mid(2,2).toInt();
        annee = mle_fin->text().mid(4,4).toInt();
        if ( dateFin.setYMD( annee , mois , jour ) != true) {
            QMessageBox mb( tr("Date incohérente"),
                            tr("La date de fin n'est pas correcte\n"),
                            QMessageBox::Critical,
                            QMessageBox::Ok | QMessageBox::Default,0,0);
            mb.exec();
            mle_fin->setFocus();
        } else {
            //lanceRecherche();
        }
    } else {
        //lanceRecherche();
    }
}


//----------------------------------------- pushButtonRunStat_clicked -----------------------------------------------------
void Wdg_Central::pushButtonRunStat_clicked()
{// TODO: Add your control notification handler code here
    //m_pCMoteurBase->GotoDebug();
    QString tab_name = tabWidgetTypeEvaluation->tabLabel ( tabWidgetTypeEvaluation->currentPage () );
    if      (tab_name==m_PAGE_EPP) EPP_Do();
    else if (tab_name==m_PAGE_RPU) RPU_Do();
}
//----------------------------------------- RPU_Do -----------------------------------------------------
void Wdg_Central::RPU_Do()
{
    QString        mess = tr("Veuillez prendre note des erreurs suivantes :");
    int             sel = comboBoxUrgType->currentItem()+1;
    int             err = 0;

    int hdeb, mdeb, hfin, mfin;
    //.................. relever qualification du service ............................
    if ( sel>2 || sel<0)
    {mess += tr("\r\n--> Qualification du service : SAU ou POSU ou UPATOU non indiquée !!");
        err|=1;
    }
    //................... numero finess .............................................
    QString finess = cMaskedLineEditNumFiness->text() + "                  ";
    finess         = finess.left(9);
    if (finess == "         ")
    {mess += tr("\r\n--> Numéro de Finess non valide !!!!");
        err|=2;
    }
    //.................... Heures de Départ et D'arrivée du test ....................................
    if (mle_HeureDeb->text().length()!=4)
    {mess += tr("\r\n--> Saisie de l'heure de début incomplète !");
        err|=4;
    }
    if (mle_HeureFin->text().length()!=4)
    {mess += tr("\r\n--> Saisie de l'heure de fin incomplète !");
        err|=8;
    }
    long val = mle_HeureDeb->text().left(2).toLong();
    if ( !(err&4) && (val<0 || val>23))
    {mess += tr("\r\n--> L'Heure de début est supérieure à 23h ou négative");
        err|=16;
    }
    else hdeb = (int)val;
    val = mle_HeureDeb->text().mid(2).toLong();
    if ( !(err&4) && (val<0 || val>59))
    {mess += tr("\r\n--> Les minutes de début sont supérieures à 59 mn ou négatives");
        err|=32;
    }
    else mdeb = (int)val;
    val = mle_HeureFin->text().left(2).toLong();
    if ( !(err&8) && (val<0 || val>23))
    {mess += tr("\r\n--> L'heure de fin est supérieure à 23 h ou négative");
        err|=64;
    }
    else hfin = (int)val;
    val = mle_HeureFin->text().mid(2).toLong();
    if ( !(err&4) && (val<0 || val>59))
    {mess += tr("\r\n--> Les minutes de fin sont supérieures à 59 mn ou négatives");
        err|=128;
    }
    else mfin = (int)val;
    if (err)
    {QMessageBox::warning ( this, tr("Statistiques :"), mess ,
                            tr("Annu&ler"), 0, 0,
                            1, 1
                            );
        return;
    }
    //.................à ce stade les infos de la boite de dialogue devraient être correctes............................................
    QApplication::setOverrideCursor( QCursor( Qt::WaitCursor ) );

    /*................. relever les dates de debut et fin ..................................*/
    QDate dateDeb  (QDate::currentDate());
    QDate dateFin  (QDate::currentDate());

    int jour, mois, annee;
    QString text = mle_deb->text();
    jour  = text.mid(0,2).toInt();
    mois  = text.mid(2,2).toInt();
    annee = text.mid(4,4).toInt();
    if (QDate::isValid ( annee, mois, jour ) ) dateDeb.setYMD (annee , mois  , jour);
    mle_deb->setText(dateDeb.toString("ddMMyyyy"));
    text  = mle_fin->text();
    jour  = text.mid(0,2).toInt();
    mois  = text.mid(2,2).toInt();
    annee = text.mid(4,4).toInt();
    if (QDate::isValid ( annee, mois, jour ) ) dateFin.setYMD (annee , mois  , jour);
    mle_fin->setText(dateFin.toString("ddMMyyyy"));

    //........................ la requete .....................................................................
    // les dates de la requete sont volontairement placées un jour avant et apres la fourchette de selection
    // car il peut arriver que certains dossiers soient créés après la garde et donc les heures strictement concernées
    // par la garde peuvent ne plus s'appliquer: exemple je vois le patient à 7h45 et apres la fin de garde (8h00)
    // par exemple à 9h je crée le dossier. Donc le test entre 8h la veille et 8h en fin de garde ne fonctionnerai
    // pas.
    QDate reqDateDeb = dateDeb.addDays(-1); QString reqDateDebStr = reqDateDeb.toString("yyyyMMdd");
    QDate reqDateFin = dateFin.addDays(+1); QString reqDateFinStr = reqDateFin.toString("yyyyMMdd");
    //............... requete utilisant la base virtuelle .....................................................
    /*
 //................. DOSS_RUB_HEAD ............................
 QString      m_DOSS_RUB_HEAD_TBL_NAME;        // nom de la table de l'header des RUBRIQUES
 QString      m_DOSS_RUB_HEAD_PRIMKEY;         // clef primaire de cet enregistrement
 QString      m_DOSS_RUB_HEAD_GUID;            // GUID du dossier auquel l'enregistrement fait reference
 QString      m_DOSS_RUB_HEAD_REF_DOSS_PK;     // Clef primaire du dossier auquel l'enregistrement fait reference (doublon avec m_DOSS_RUB_HEAD_GUID)
 QString      m_DOSS_RUB_HEAD_NOM_DATE;        // Court texte descriptif de l'enregistrement.
 QString      m_DOSS_RUB_HEAD_DATE;            // date de l'enregistrement
 QString      m_DOSS_RUB_HEAD_DUREE;           // duree de l'enregistrement
 QString      m_DOSS_RUB_HEAD_TYPE;            // Type de rubrique
 QString      m_DOSS_RUB_HEAD_USER;            // utilisateur associé à rubrique

 //................. DOSS_RUB_DATA ............................
 QString      m_DOSS_RUB_DATA_TBL_NAME;        // nom de la table des données des RUBRIQUES
 QString      m_DOSS_RUB_DATA_PRIMKEY;         // clef primaire de cet enregistrement  (le meme que le header)
 QString      m_DOSS_RUB_DATA_BLOB;            // données binaires
 */
    if (m_pCMoteurBase->m_DataBase->isOpen()==FALSE && m_pCMoteurBase->m_DataBase->open()==FALSE)  return ;  // si point = erreur d'ouverture de la base
    QString requete("SELECT ");
    requete +=  m_pCMoteurBase->m_DOSS_RUB_HEAD_GUID     + "," +        // 0
                m_pCMoteurBase->m_DOSS_RUB_HEAD_PRIMKEY  + "," +        // 1
                m_pCMoteurBase->m_DOSS_RUB_HEAD_USER     + "," +        // 2
                m_pCMoteurBase->m_DOSS_RUB_HEAD_DATE     + " FROM  " +  // 3
                m_pCMoteurBase->m_DOSS_RUB_HEAD_TBL_NAME + " WHERE " +
                //m_pCMoteurBase->m_DOSS_RUB_HEAD_TYPE     + " = '20030000'";
                m_pCMoteurBase->m_DOSS_RUB_HEAD_TYPE     + " = '20030000' AND " +
                m_pCMoteurBase->m_DOSS_RUB_HEAD_DATE     + " >= '" + reqDateDebStr + "' AND " + m_pCMoteurBase->m_DOSS_RUB_HEAD_DATE + "<= '" + reqDateFinStr + "'";
    QSqlQuery query(requete , m_pCMoteurBase->m_DataBase );
    long  nbRecord       = 0;
    long  nbRecordTotal  = 0;
    //.................. Recuperer la liste des observations ..........................................
    //                   filtrée grossièrement sur les dates (1 jr avant 1 jour après)
    //................. initialiser classe d'analyse des dossiers .................................
    if (m_pCGestRPU) delete m_pCGestRPU;
    m_pCGestRPU = new CGestRPU(dateDeb,   hdeb , mdeb,
                               dateFin,   hfin , mfin,
                               G_pCApp->m_PathAppli , "ErreurStat.log",
                               G_pCApp->m_PathAppli , "Test_FILE.log",
                               G_pCApp->m_PathAppli , "RPU_FILE.log",
                               ALL_RPU_TEST    ,
                               (char)sel       ,
                               finess
                               );
    if ( query.isActive() )
    {
        QByteArray qByteArray;
        bool ok              = TRUE;
        SSignal patientInfos;
        QDate   dateRub;
        while (query.next())
        {ok         = TRUE;
            ++nbRecordTotal;
            //............... recuperer date cette observation ....................................
            //                verifier si dans bonne fourchette
            //                (pas la peine avec requete cela baigne)
            /*
            QString dtRub = query.value(3).toString();  // 1999-10-08 09:12:47
            dateRub.setYMD (  dtRub.left(4 ).toInt(),
                              dtRub.mid(5,2).toInt(),
                              dtRub.mid(8,2).toInt() );
            if (! (dateRub>=reqDateDeb && dateRub<=reqDateFin) ) ok = FALSE;
            */
            //............... recuperer infos patients de cette observation .......................
            if (patientInfos.setFromGUID(query.value(0).toString(), m_pCMoteurBase))
            {//............ calcul et filtrer selon age patient ................................
             //................ recuperer les données de l'observation ...........................
                if (ok && m_pCMoteurBase->GetDataFromRub(qByteArray, query.value(1).toString()))  // query.value(1).toByteArray() -> m_DOSS_RUB_HEAD_PRIMKEY
                   {char *ptr  = qByteArray.data();
                    long len   = qByteArray.size()-4;
                    QString observation;
                    if (ptr && len>6)
                       {
                        if (strncmp(ptr, "<html>", 6))
                           { observation = CMoteurBase::RTF_ToASCII(ptr+4, len);
                           }
                        else
                           {
                            observation = QString::fromUtf8 ( ptr, len + 4);
                            CHtmlTools::HtmlToAscii(observation, CHtmlTools::StrictASCII);
                           }
                        m_pCGestRPU->RPU_TesteRecord(&patientInfos, observation , observation.length(), query.value(2).toString()); //query.value(2).toString() Medecin
                        ++nbRecord;
                    } //endif (ptr && len>6)
                } //endif (ok && m_pCMoteurBase->G
            } // endif (patientInfos.setFromGUID(query.value(1).toString()));
        } // end while (query.next())
        PlaceListErrorInListCtrl(m_pCGestRPU);
    } //endif ( query.isActive() )

    //............................ afficher les comptes ......................................................

    if (checkBoxRPUFile->isChecked())
    {textLabelResDestNbrRPU->setText(QString::number(m_pCGestRPU->m_NbFicWrited));
    }
    if (checkBoxCCMU->isChecked())
    {textLabel_ResCCMU_I->setText(QString::number(m_pCGestRPU->m_CCMU.ccmu1 ));
        textLabel_ResCCMU_II->setText(QString::number(m_pCGestRPU->m_CCMU.ccmu2 ));
        textLabel_ResCCMU_III->setText(QString::number(m_pCGestRPU->m_CCMU.ccmu3 ));
        textLabel_ResCCMU_IV->setText(QString::number(m_pCGestRPU->m_CCMU.ccmu4 ));
        textLabel_ResCCMU_V->setText(QString::number(m_pCGestRPU->m_CCMU.ccmu5 ));
        textLabel_ResCCMU_Err->setText(QString::number(m_pCGestRPU->m_CCMU.ccmu0));

    }
    if (checkBoxGEMSA->isChecked())
    {textLabel_ResGemsa_1->setText(QString::number(m_pCGestRPU->m_GEMSA.gemsa_1 ));
        textLabel_ResGemsa_2->setText(QString::number(m_pCGestRPU->m_GEMSA.gemsa_2 ));
        textLabel_ResGemsa_3->setText(QString::number(m_pCGestRPU->m_GEMSA.gemsa_3 ));
        textLabel_ResGemsa_4->setText(QString::number(m_pCGestRPU->m_GEMSA.gemsa_4 ));
        textLabel_ResGemsa_5->setText(QString::number(m_pCGestRPU->m_GEMSA.gemsa_5 ));
        textLabel_ResGemsa_6->setText(QString::number(m_pCGestRPU->m_GEMSA.gemsa_6 ));
        textLabel_ResGemsa_Err->setText(QString::number(m_pCGestRPU->m_GEMSA.gemsa_I ));
    }
    if (checkBoxDESTCLIN->isChecked())
    {textLabel_ResDestClinTotal->setText(QString::number(m_pCGestRPU->m_DEST.hospi ));
        textLabel_ResDestRetClinExterne->setText(QString::number(m_pCGestRPU->m_DEST.exter ));
        textLabel_ResDestClinHospi->setText(QString::number(m_pCGestRPU->m_DEST.trans ));
        textLabel_ResDestClin_Err->setText(QString::number(m_pCGestRPU->m_DEST.indeter ));
    }
    if (checkBoxRPU->isChecked())
    {textLabel_ResDestDeces->setText(QString::number(m_pCGestRPU->m_DIVERS.Deces ));
        textLabel_ResDestRetDom->setText(QString::number(m_pCGestRPU->m_DIVERS.RetDom ));
        textLabel_ResDestHospi->setText(QString::number(m_pCGestRPU->m_DIVERS.Hosp ));
        textLabel_ResDest_Err->setText(QString::number(m_pCGestRPU->m_DIVERS.Ind ));
    }
    mess  = QString::number(m_pCGestRPU->m_RPU_Record);
    mess  = mess + tr(" dossiers analysés ");
    mess  = mess + QString::number(m_pCGestRPU->m_NbErr);
    mess  = mess + tr(" erreur(s) trouvée(s)");
    textLabel_StateListError->setText(mess);
    QApplication::restoreOverrideCursor();
    return;
}

//----------------------------------------- ListView_PatientRejetes_doubleClicked -----------------------------------------------------
void Wdg_Central::ListView_PatientRejetes_doubleClicked( QListViewItem *pQListViewItem )
{if ( pQListViewItem == 0) return;
    QString guid = pQListViewItem->text(5);
    AccederDossier(pQListViewItem->text(0),                           // Nom assuré
                   pQListViewItem->text(1),                           // Prenom assuré
                   m_pCMoteurBase->GetDossPrimKeyFromGUID(guid ),     // numero PrimKey
                   guid ,                                             // GUID dossier
                   pQListViewItem->text(3),                           // Nom de l'utilisateur
                   G_pCApp->m_SignUser);                              // Nom de l'utilisateur signataire
}


//----------------------------------------- ListView_PatientRejetes_returnPressed -----------------------------------------------------
void Wdg_Central::ListView_PatientRejetes_returnPressed( QListViewItem *pQListViewItem )
{ListView_PatientRejetes_doubleClicked( pQListViewItem );
}


//----------------------------------------- ListView_PatientRejetes_spacePressed -----------------------------------------------------
void Wdg_Central::ListView_PatientRejetes_spacePressed( QListViewItem *pQListViewItem )
{ListView_PatientRejetes_doubleClicked( pQListViewItem );
}

//----------------------------------------- checkBoxWarning_stateChanged -----------------------------------------------------
void Wdg_Central::checkBoxWarning_stateChanged( int )
{   QString tab_name = tabWidgetTypeEvaluation->tabLabel ( tabWidgetTypeEvaluation->currentPage () );
    if      (tab_name==m_PAGE_EPP) return;
    // else if (tab_name==m_PAGE_RPU) RPU_Do();
    PlaceListErrorInListCtrl(m_pCGestRPU);
}

//----------------------------------------- PlaceListErrorInListCtrl --------------------------------------------------------
void Wdg_Central::PlaceListErrorInListCtrl( CGestRPU *pCGestRPU)
{   // TODO: Add your control notification handler code here



    ListView_PatientRejetes->clear();
    ERR_RPU  *errRPU;
    for (errRPU = pCGestRPU->m_ErrRpuList.first(); errRPU; errRPU = pCGestRPU->m_ErrRpuList.next() )
    {if ( !checkBoxWarning->isChecked() && errRPU->Message[0]==':' && errRPU->Message[1]==':' )
        {
        }
        else
        {new QListViewItem (ListView_PatientRejetes,
                            errRPU->Nom,
                            errRPU->Prenom,
                            errRPU->Date,
                            errRPU->Medecin,
                            errRPU->Message,
                            errRPU->ID
                            );
        }
    }
}

////////////////////////////////////////////////////// Définition du SQL-filtre //////////////////////////////////////////////////////
//----------------------------------------- pushButton_MaskListSqlField_clicked ---------------------------------------------------------
void Wdg_Central::pushButton_MaskListSqlField_clicked()
{if (pushButton_AddListIdentField->isVisible())
    {pushButton_AddListIdentField->hide();
     pushButton_DelListIdentField->hide();
     pushButton_DelAllListIdentField->hide();
     comboBox_RequetesLib->hide();
     listView_Sql_IdentFields->hide();
     pushButton_EPP_Charger->hide();
     pushButton_EPP_Enregistrer->hide();
     textEdit_Sql_IdentSelect->hide();
     pushButton_MaskListSqlField->setPixmap ( QPixmap(G_pCApp->m_PathAppli + "Images/LeftLitle.png"  ));
    }
 else
    {pushButton_AddListIdentField->show();
     pushButton_DelListIdentField->show();
     pushButton_DelAllListIdentField->show();
     comboBox_RequetesLib->show();
     listView_Sql_IdentFields->show();
     pushButton_EPP_Charger->show();
     pushButton_EPP_Enregistrer->show();
     textEdit_Sql_IdentSelect->show();
     pushButton_MaskListSqlField->setPixmap ( QPixmap(G_pCApp->m_PathAppli + "Images/DownLitle.png"  ));
    }

}
//----------------------------------------- listView_Sql_IdentFields_rightButtonPressed ---------------------------------------------------------
void Wdg_Central::listView_Sql_IdentFields_rightButtonPressed( QListViewItem *, const QPoint &, int )
{

}

//----------------------------------------- listView_Sql_IdentFields_contextMenuRequested ---------------------------------------------------------
void Wdg_Central::listView_Sql_IdentFields_contextMenuRequested( QListViewItem *pQListViewItem, const QPoint &, int pos)
{SetListeChamp(listView_Sql_IdentFields, pQListViewItem, pos);
 textEdit_Sql_IdentSelect->setText(ConstructRequeteIdentSelect());
}


void Wdg_Central::listView_Sql_IdentFields_doubleClicked( QListViewItem *, const QPoint &, int )
{

}
//----------------------------------------- listView_Sql_IdentFields_mouseButtonClicked ---------------------------------------------------------
void Wdg_Central::listView_Sql_IdentFields_mouseButtonClicked( int, QListViewItem *pQListViewItem, const QPoint &pts, int pos)
{

}


//------------------------------------ GetFieldType --------------------------------------------
// retourne le type possible du champ passe en entree
QVariant::Type Wdg_Central::GetFieldType( const QString &fieldName)
{QVariant::Type ret = QVariant::Invalid;
 ret = TestFieldsType(fieldName, m_pCMoteurBase->m_DOSS_INDEX_TBL_NAME);
 if (ret != QVariant::Invalid) return ret;
 ret = TestFieldsType(fieldName, m_pCMoteurBase->m_DOSS_IDENT_TBL_NAME);
 if (ret != QVariant::Invalid) return ret;
 ret = TestFieldsType(fieldName, m_pCMoteurBase->m_DOSS_RUB_HEAD_TBL_NAME);
 if (ret != QVariant::Invalid) return ret;
 ret = TestFieldsType(fieldName, m_pCMoteurBase->m_DOSS_RUB_DATA_TBL_NAME);
 if (ret != QVariant::Invalid) return ret;
 return ret;
}

//------------------------------------ TestFieldsType --------------------------------------------
QVariant::Type Wdg_Central::TestFieldsType(const QString &fieldName, const QString &tableName)
{
 QVariant::Type ret = QVariant::Invalid;
 int               i = 0;
 int       nb_fields = 0;
 if (m_pCMoteurBase->m_DataBase->isOpen()==FALSE && m_pCMoteurBase->m_DataBase->open()==FALSE) return ret;
 QSqlCursor *pQSqlCursor = new QSqlCursor(tableName, TRUE, m_pCMoteurBase->m_DataBase );
 if (pQSqlCursor)
    {nb_fields = pQSqlCursor->count();
     for (i=0; i<nb_fields; ++i) if (pQSqlCursor->fieldName ( i ) == fieldName) ret = pQSqlCursor->field(i)->type();
     delete pQSqlCursor;
    }
 m_pCMoteurBase->m_DataBase->close();
 return ret;
}

//------------------------------------ initFieldsList --------------------------------------------
void Wdg_Central::initFieldsList()
{m_FieldsList_IndexList.clear();
 GetFieldsList(m_FieldsList_IndexList,     m_pCMoteurBase->m_DOSS_INDEX_TBL_NAME);

 m_FieldsList_FicheIdent.clear();
 GetFieldsList(m_FieldsList_FicheIdent,    m_pCMoteurBase->m_DOSS_IDENT_TBL_NAME);

 m_FieldsList_DossHeader.clear();
 GetFieldsList(m_FieldsList_DossHeader,    m_pCMoteurBase->m_DOSS_RUB_HEAD_TBL_NAME);

 m_FieldsList_DossData.clear();
 GetFieldsList(m_FieldsList_DossData,      m_pCMoteurBase->m_DOSS_RUB_DATA_TBL_NAME);

 //GetFieldsList(m_FieldsList_Note,          const QString &tableName);
 //GetFieldsList(m_FieldsList_Intervenants,  const QString &tableName);
}

//------------------------------------ GetFieldsList --------------------------------------------
void Wdg_Central::GetFieldsList(QStringList &fieldList, const QString &tableName)
{if (m_pCMoteurBase->m_DataBase->isOpen()==FALSE && m_pCMoteurBase->m_DataBase->open()==FALSE)  return ;
 int         i = 0;
 int nb_fields = 0;
 QSqlCursor *pQSqlCursor = new QSqlCursor(tableName, TRUE, m_pCMoteurBase->m_DataBase );
 if (pQSqlCursor)
    {nb_fields = pQSqlCursor->count();
     for (i=0; i<nb_fields; ++i)  fieldList.append (pQSqlCursor->fieldName ( i ));
     delete pQSqlCursor;
    }
 m_pCMoteurBase->m_DataBase->close();
}

//------------------------------------ OnOutFocusDateHeure --------------------------------------------
void Wdg_Central::OnOutFocusDateHeure()
{   QString tab_name = tabWidgetTypeEvaluation->tabLabel ( tabWidgetTypeEvaluation->currentPage () );
    if      (tab_name==m_PAGE_EPP) ConstructRequeteIdentSelect();
    //else if (tab_name==m_PAGE_RPU) RPU_Do();
}
//------------------------------------ ConstructRequeteIdentSelect --------------------------------------------
QString Wdg_Central::ConstructRequeteIdentSelect()
{   QDate dateDeb  (QDate::currentDate());
    QDate dateFin  (QDate::currentDate());

    int jour, mois, annee;
    QString text = mle_deb->text();
    jour  = text.mid(0,2).toInt();
    mois  = text.mid(2,2).toInt();
    annee = text.mid(4,4).toInt();
    if (QDate::isValid ( annee, mois, jour ) ) dateDeb.setYMD (annee , mois  , jour);
    mle_deb->setText(dateDeb.toString("ddMMyyyy"));
    text  = mle_fin->text();
    jour  = text.mid(0,2).toInt();
    mois  = text.mid(2,2).toInt();
    annee = text.mid(4,4).toInt();
    if (QDate::isValid ( annee, mois, jour ) ) dateFin.setYMD (annee , mois  , jour);
    mle_fin->setText(dateFin.toString("ddMMyyyy"));

    //........................ la requete .....................................................................
    // les dates de la requete sont volontairement placées un jour avant et apres la fourchette de selection
    // car il peut arriver que certains dossiers soient créés après la garde et donc les heures strictement concernées
    // par la garde peuvent ne plus s'appliquer: exemple je vois le patient à 7h45 et apres la fin de garde (8h00)
    // par exemple à 9h je crée le dossier. Donc le test entre 8h la veille et 8h en fin de garde ne fonctionnerai
    // pas.
    //QDate reqDateDeb = dateDeb.addDays(-1); QString reqDateDebStr = reqDateDeb.toString("yyyyMMdd");
    //QDate reqDateFin = dateFin.addDays(+1); QString reqDateFinStr = reqDateFin.toString("yyyyMMdd");

    QString reqDateDebStr = dateDeb.toString("yyyyMMdd");
    QString reqDateFinStr = dateFin.toString("yyyyMMdd");

    QString requete  = "SELECT * FROM ";
            requete += m_pCMoteurBase->m_DOSS_RUB_HEAD_TBL_NAME + " INNER JOIN " +
                       m_pCMoteurBase->m_DOSS_INDEX_TBL_NAME    + " ON "         +
                       m_pCMoteurBase->m_DOSS_RUB_HEAD_TBL_NAME + "." +m_pCMoteurBase->m_DOSS_RUB_HEAD_GUID          + "=" + m_pCMoteurBase->m_DOSS_INDEX_TBL_NAME    +"."+m_pCMoteurBase->m_DOSS_INDEX_GUID          + " INNER JOIN " +
                       m_pCMoteurBase->m_DOSS_IDENT_TBL_NAME    + " ON "         +
                       m_pCMoteurBase->m_DOSS_RUB_HEAD_TBL_NAME + "." +m_pCMoteurBase->m_DOSS_RUB_HEAD_GUID          + "=" + m_pCMoteurBase->m_DOSS_IDENT_TBL_NAME    +"."+m_pCMoteurBase->m_DOSS_IDENT_GUID          + " INNER JOIN " +
                       m_pCMoteurBase->m_DOSS_RUB_DATA_TBL_NAME + " ON "         +
                       m_pCMoteurBase->m_DOSS_RUB_HEAD_TBL_NAME + "." +m_pCMoteurBase->m_DOSS_RUB_HEAD_REF_BLOBS_PK  + "=" + m_pCMoteurBase->m_DOSS_RUB_DATA_TBL_NAME +"."+m_pCMoteurBase->m_DOSS_RUB_DATA_PRIMKEY    + " WHERE "      +
                       m_pCMoteurBase->m_DOSS_RUB_HEAD_DATE     + " >= '" + reqDateDebStr  + mle_HeureDeb->text() +"00' AND " + m_pCMoteurBase->m_DOSS_RUB_HEAD_DATE + "<= '" + reqDateFinStr + mle_HeureFin->text()+"00'";
            requete += listView_Sql_IdentFieldsToSQL();
 return requete;
}
//"SELECT * FROM RubriquesHead INNER JOIN IndexNomPrenom ON RubriquesHead.RbDate_IDDos=IndexNomPrenom.FchGnrl_IDDos INNER JOIN
// RubriquesBlobs ON RubriquesHead.RbDate_RefBlobs_PrimKey=RubriquesBlobs.RbDate_PrimKey
// WHERE RbDate_Date >= '$debut' AND RbDate_Date <= '$fin' AND RbDate_TypeRub='20030000' AND RbDate_CreateUser='$user' AND CAST(RubriquesBlobs.RbDate_DataRub AS CHAR) LIKE '%s' ORDER BY RbDate_Date"

//----------------------------------- listView_Sql_IdentFieldsToSQL ------------------------------------------------------------------------
// popItem.append(tr("  ) "));
// popItem.append(tr("  ( "));
// popItem.append(tr("  ) et ("));
// popItem.append(tr("  ) ou ("));

QString Wdg_Central::listView_Sql_IdentFieldsToSQL()
{QString                      result = "";
 QString                      str    = "";
 QListViewItem *pQListViewItemBefore = 0;
 if (listView_Sql_IdentFields->childCount() <= 0) return result +  " ORDER BY " + m_pCMoteurBase->m_DOSS_RUB_HEAD_TBL_NAME + "." +m_pCMoteurBase->m_DOSS_RUB_HEAD_GUID + " ;";
 result = " AND ";
 QListViewItem *last_pQListViewItem =  listView_Sql_IdentFields->lastItem();
 QListViewItemIterator it( listView_Sql_IdentFields );
 while ( it.current() )
    { QListViewItem *pQListViewItem = it.current();
      //........ traiter premier séparateur .............
      str = pQListViewItem->text(0);
      // #define DELIMITER_TYPE_LIST  "  Vide #  ) #  ( #  ) et (#  ) ou ("
      switch(CMetaFiltre::GetDelimiterList_ID(str))
         {case 1:        //     )
               result += tr(")");
               return result +  " ORDER BY " + m_pCMoteurBase->m_DOSS_RUB_HEAD_TBL_NAME + "." +m_pCMoteurBase->m_DOSS_RUB_HEAD_GUID + " ;";
               //break;
          case 2:        //     (
               result += tr("(`")       + pQListViewItem->text(1) + "`" + interpreteOperateurComparaison(pQListViewItem->text(2), valueInterprete(pQListViewItem->text(1), pQListViewItem->text(3)))+interpreteOperateurEtOu(pQListViewItem->text(4));
               break;
          case 3:        //     ) et (
               result += tr(") AND (`") + pQListViewItem->text(1) + "`" + interpreteOperateurComparaison(pQListViewItem->text(2), valueInterprete(pQListViewItem->text(1), pQListViewItem->text(3)))+interpreteOperateurEtOu(pQListViewItem->text(4));
               break;
          case 4:       //      ) ou (
               result += tr(") OR (`")  + pQListViewItem->text(1) + "`" + interpreteOperateurComparaison(pQListViewItem->text(2), valueInterprete(pQListViewItem->text(1), pQListViewItem->text(3)))+interpreteOperateurEtOu(pQListViewItem->text(4));
               break;
          default:
               if (pQListViewItemBefore && (pQListViewItemBefore->text(4).contains(tr("et"),FALSE) != -1 || pQListViewItemBefore->text(4).contains(tr("ou"),FALSE) != -1))
                  {result += "`"        + pQListViewItem->text(1) + "`" + interpreteOperateurComparaison(pQListViewItem->text(2), valueInterprete(pQListViewItem->text(1), pQListViewItem->text(3)))+interpreteOperateurEtOu(pQListViewItem->text(4));
                  }
               break;
        }
      pQListViewItemBefore = pQListViewItem;
      ++it;
    }
 return result;
}

//----------------------------------- valueInterprete ------------------------------------------------------------------------
QString Wdg_Central::valueInterprete(const QString &fieldName, const QString &value)
{if (fieldName==m_pCMoteurBase->m_DOSS_RUB_HEAD_TYPE) return CMetaField::RubNameToRubType(value);
 else                                                 return value;
}

//----------------------------------- GetItemBefore ------------------------------------------------------------------------
QListViewItem * Wdg_Central::GetItemBefore(QListView *pQListView, QListViewItem *pQListViewItemToCheck)
{QListViewItem *pQListViewItemBefore = 0;
 QListViewItemIterator it( pQListView );
 while ( it.current() )
    { QListViewItem *pQListViewItem = it.current();
      if (pQListViewItem == pQListViewItemToCheck) return pQListViewItemBefore;
      pQListViewItemBefore = pQListViewItem;
      ++it;
    }
 return pQListViewItemBefore;
}
//----------------------------------- interpreteOperateurComparaison ------------------------------------------------------------------------
//           popItem.append(tr("  >               "));
//           popItem.append(tr("  <               "));
//           popItem.append(tr("  <=              "));
//           popItem.append(tr("  >=              "));
//           popItem.append(tr(" est égal à       "));
//           popItem.append(tr(" contient         "));
//           popItem.append(tr(" est différent de "));
//           popItem.append(tr(" ne contient pas  "));
//           #define OPERATEUR_LIST "Vide#>#<#<=#">=#est égal#contient#commence par#finit par#est différent de#ne contient pas"
QString Wdg_Central::interpreteOperateurComparaison(const QString &op, const QString &val)
{
      QString result = "";
      switch(CMetaField::GetListOperateur_ID(op))
         { case 0:           // Vide
                break;
           case 1:           // >
                result += tr(" > '") + val + "' ";
                break;
           case 2:           // <
                result += tr(" < '") + val + "' ";
                break;
           case 3:           // <=
                result += tr(" <= '") + val + "' ";
                break;
           case 4:           // >=
                result += tr(" >= '") + val + "' ";
                break;
           case 5:           // est égal
                result += tr(" = '") + val + "' ";
                break;
           case 6:           // contient
                result += tr(" LIKE '%") + val + "%' ";
                break;
           case 7:           // commence par
                result += tr(" LIKE '%") + val + "' ";
                break;
           case 8:           // finit par
                result += tr(" LIKE '") + val + "%' ";
                break;
           case 9:           // est différent de
                result += tr(" <> '") + val + "' ";
                break;
           case 10:          // ne contient pas
                result += tr(" NOT LIKE '%") + val + "%' ";
                break;
         }
 return result;
}

//----------------------------------- interpreteOperateurEtOu ------------------------------------------------------------------------
// popItem.append(tr("  ) "));
// popItem.append(tr("  ( "));
// popItem.append(tr("  ) et ("));
// popItem.append(tr("  ) ou ("));
// #define LOGIC_OP_LIST        "  Vide #  et               #  ou               #  sans             "
QString Wdg_Central::interpreteOperateurEtOu(const QString &op)
{     int id = CMetaFiltreLine::GetListLogicOper_ID(op);
      QString result = "";
      switch(id)
         {case 1: result += tr(" AND "); break;
          case 2: result += tr(" OR  "); break;
         }
      return result;
}

//-------------------------------------------- pushButton_AddListIdentField_clicked -------------------------------------------------------
void Wdg_Central::pushButton_AddListIdentField_clicked()
{pushButton_AddListField_clicked(listView_Sql_IdentFields);
 textEdit_Sql_IdentSelect->setText(ConstructRequeteIdentSelect());
}

//----------------------------------------- pushButton_DelAllListIdentField_clicked ---------------------------------------------------------
void Wdg_Central::pushButton_DelAllListIdentField_clicked()
{listView_Sql_IdentFields->clear();
 textEdit_Sql_IdentSelect->setText(ConstructRequeteIdentSelect());
}

////////////////////////////////////////////////////// Définition du méta-filtre //////////////////////////////////////////////////////
//----------------------------------------- pushButton_MaskListMetaField_clicked ---------------------------------------------------------
void Wdg_Central::pushButton_MaskListMetaField_clicked()
{if (pushButton_AddListMetaField->isVisible())
    {pushButton_AddListMetaField->hide();
     pushButton_DelListMetaField->hide();
     pushButton_DelAllListMetaField->hide();
     listView_Sql_MetaFields->hide();
     pushButton_AddDefMetaField->hide();
     pushButton_DelDefMetaField->hide();
     pushButton_DelAllDefMetaField->hide();
     pushButton_UpDefMetaField->hide();
     pushButton_DownDefMetaField->hide();
     listView_Def_MetaFields->hide();
     pushButton_MaskListMetaField->setPixmap ( QPixmap(G_pCApp->m_PathAppli + "Images/LeftLitle.png"  ));
    }
 else
    {pushButton_AddListMetaField->show();
     pushButton_DelListMetaField->show();
     pushButton_DelAllListMetaField->show();
     listView_Sql_MetaFields->show();
     pushButton_AddDefMetaField->show();
     pushButton_DelDefMetaField->show();
     pushButton_DelAllDefMetaField->show();
     pushButton_UpDefMetaField->show();
     pushButton_DownDefMetaField->show();
     listView_Def_MetaFields->show();
     pushButton_MaskListMetaField->setPixmap ( QPixmap(G_pCApp->m_PathAppli + "Images/DownLitle.png"  ));
    }
}
//----------------------------------------- listView_Sql_MetaFields_contextMenuRequested ---------------------------------------------------------
void Wdg_Central::listView_Sql_MetaFields_contextMenuRequested( QListViewItem *pQListViewItem, const QPoint &, int pos )
{SetListeChamp(listView_Sql_MetaFields, pQListViewItem, pos);
}



void Wdg_Central::listView_Sql_MetaFields_rightButtonPressed( QListViewItem *, const QPoint &, int )
{

}
//----------------------------------------- listView_Sql_MetaFields_mouseButtonClicked ---------------------------------------------------------
void Wdg_Central::listView_Sql_MetaFields_mouseButtonClicked( int, QListViewItem *pQListViewItem, const QPoint &pts, int pos )
{
}

//----------------------------------------- GetMetaFieldsList ---------------------------------------------------------
void Wdg_Central::GetMetaFieldsList(QStringList &list)
{
 QListViewItemIterator it( listView_Def_MetaFields );
 while ( it.current() )
    { QListViewItem *pQListViewItem = it.current();
     list.append( pQListViewItem->text(0) );
      ++it;
    }
}

//----------------------------------------- pushButton_AddListMetaField_clicked ---------------------------------------------------------
void Wdg_Central::pushButton_AddListMetaField_clicked()
{pushButton_AddListField_clicked(listView_Sql_MetaFields);
}

//----------------------------------------- pushButton_DelListMetaField_clicked ---------------------------------------------------------
void Wdg_Central::pushButton_DelListMetaField_clicked()
{QListViewItem *pQListViewItem = listView_Sql_MetaFields->currentItem ();
 if (pQListViewItem == 0) return;
 delete pQListViewItem ;
}

//----------------------------------------- pushButton_DelAllListMetaField_clicked ---------------------------------------------------------
void Wdg_Central::pushButton_DelAllListMetaField_clicked()
{listView_Sql_MetaFields->clear();
}

////////////////////////////////////////////////////// Définition des méta-champs //////////////////////////////////////////////////////////////
//----------------------------------------- listView_Def_MetaFields_rightButtonPressed ---------------------------------------------------------
void Wdg_Central::listView_Def_MetaFields_rightButtonPressed( QListViewItem *, const QPoint &, int )
{

}
//----------------------------------------- listView_Def_MetaFields_contextMenuRequested ---------------------------------------------------------
void Wdg_Central::listView_Def_MetaFields_contextMenuRequested( QListViewItem *pQListViewItem, const QPoint &, int pos )
{QStringList popItem;
 QString     popRet;
 int created = CDlg_MetaFieldDefine::modify;
 //.............................. notons que si il y a création d'un meta-champ .............................
 //                               avec  pQListViewItem(1) et pQListViewItem(2) vide
 //                               c'est qu'il est nouvellement cree
 if (pQListViewItem<=0)
    {pQListViewItem = AddDefMetaField();
     created        = CDlg_MetaFieldDefine::create;
    }

QString rubrique =  pQListViewItem->text(1);
CDlg_MetaFieldDefine *dlg = new CDlg_MetaFieldDefine(listView_Def_MetaFields, pQListViewItem ,  this, "CDlg_MetaFieldDefine");
if (dlg==0)            return;
if (dlg->exec()== QDialog::Accepted )
   {
   }
else
   {if (created==CDlg_MetaFieldDefine::create) delete pQListViewItem;
   }
listView_Def_MetaFields->setSorting ( 1 );
listView_Def_MetaFields->setSortColumn (1) ;
listView_Def_MetaFields->sort();
listView_Def_MetaFields->setSorting ( -1 );

}

//----------------------------------------- listView_Def_MetaFields_mouseButtonClicked ---------------------------------------------------------
void Wdg_Central::listView_Def_MetaFields_mouseButtonClicked( int, QListViewItem *, const QPoint &pts, int pos )
{
}

//----------------------------------------- pushButton_AddDefMetaField_clicked ---------------------------------------------------------
void Wdg_Central::pushButton_AddDefMetaField_clicked()
{QPoint pt;
 listView_Def_MetaFields_contextMenuRequested( 0, pt, 0 );
}

//----------------------------------------------------- AddDefMetaField ---------------------------------------------------------
QListViewItem * Wdg_Central::AddDefMetaField()
{QListViewItem *last_pQListViewItem =  listView_Def_MetaFields->lastItem();
 QListViewItem *pQListViewItem      = 0;
 QString texte;
 if (last_pQListViewItem)
    {texte           = last_pQListViewItem->text(0);
     texte           = incrementeStr(texte);
    }
 else
    {texte          = tr("Méta_champ_1 ");
    }
 if (last_pQListViewItem)
    {pQListViewItem = new QListViewItem(listView_Def_MetaFields, last_pQListViewItem, texte);
    }
 else
    {pQListViewItem = new QListViewItem(listView_Def_MetaFields, texte);
    }
 if (pQListViewItem) {listView_Def_MetaFields->setCurrentItem (pQListViewItem );
                      listView_Def_MetaFields->setSelected (pQListViewItem , TRUE);
                     }
 return pQListViewItem;
}

//----------------------------------------- incrementeStr ---------------------------------------------------------
QString Wdg_Central::incrementeStr(QString texte)
{QRegExp rx( "[0-9]" );
 int len = 0;
 int pos = rx.match ( texte, 0, &len );
 if (pos == -1) return texte;
 QString str  = texte.mid(pos,len);
 texte = texte.left(pos) + QString::number( str.toInt()+1);
 return texte;
}

//----------------------------------------- pushButton_DelDefMetaField_clicked ---------------------------------------------------------
void Wdg_Central::pushButton_DelDefMetaField_clicked()
{QListViewItem *pQListViewItem = listView_Def_MetaFields->currentItem ();
 if (pQListViewItem == 0) return;
 delete pQListViewItem ;
}


//----------------------------------------- pushButton_DelAllDefMetaField_clicked ---------------------------------------------------------
void Wdg_Central::pushButton_DelAllDefMetaField_clicked()
{listView_Def_MetaFields->clear();
}


//----------------------------------------- pushButton_UpDefMetaField_clicked ---------------------------------------------------------
void Wdg_Central::pushButton_UpDefMetaField_clicked()
{

}

//----------------------------------------- pushButton_DownDefMetaField_clicked ---------------------------------------------------------
void Wdg_Central::pushButton_DownDefMetaField_clicked()
{

}

////////////////////////////////////////////////////// Définition des Classes de comptage //////////////////////////////////////////////////////

//----------------------------------------- pushButton_MaskListMetaField_clicked ---------------------------------------------------------
void Wdg_Central::pushButton_MaskListClassDenombre_clicked()
{if (pushButton_AddClassField->isVisible())
    {pushButton_AddClassField->hide();
     pushButton_DelClassField->hide();
     pushButton_DelAllClassField->hide();
     listView_ClassDenombreList->hide();
     textBrowserInfoPerms->hide();
     pushButton_AddTestClassDenombre->hide();
     pushButton_DelTestClassDenombre->hide();
     pushButton_DelAllListDenombreTest->hide();
     listView_DenombreTest->hide();
     textEdit_SelectDossiers->hide();
     pushButton_MaskListClassDenombre->setPixmap ( QPixmap(G_pCApp->m_PathAppli + "Images/LeftLitle.png"  ));
    }
 else
    {pushButton_AddClassField->show();
     pushButton_DelClassField->show();
     pushButton_DelAllClassField->show();
     listView_ClassDenombreList->show();
     textBrowserInfoPerms->show();
     pushButton_AddTestClassDenombre->show();
     pushButton_DelTestClassDenombre->show();
     pushButton_DelAllListDenombreTest->show();
     listView_DenombreTest->show();
     textEdit_SelectDossiers->show();
     pushButton_MaskListClassDenombre->setPixmap ( QPixmap(G_pCApp->m_PathAppli + "Images/DownLitle.png"  ));
    }

}
//----------------------------------------- listView_ClassDenombreList_rightButtonPressed ---------------------------------------------------------
void Wdg_Central::listView_ClassDenombreList_rightButtonPressed( QListViewItem *, const QPoint &, int )
{
}

//----------------------------------------- listView_ClassDenombreList_contextMenuRequested ---------------------------------------------------------
void Wdg_Central::listView_ClassDenombreList_contextMenuRequested( QListViewItem *pQListViewItem, const QPoint &, int )
{//QListViewItem *pQListViewItem      =  listView_ClassDenombreList->currentItem ();
 QListViewItem *last_pQListViewItem =  listView_ClassDenombreList->lastItem();

 QString                  nom   = "";
 QString                  champ = "";
 bool                      ok   = TRUE;
 if (pQListViewItem )    {nom   = pQListViewItem->text(0);
                          champ = pQListViewItem->text(1);
                         }
 CDenombre          *pCDenombre = CDenombreGetByName(nom);       // reperer la classe initiale qui va être modifiée (selon son nom)
 CDlg_NewClassDenombre* dlg = new CDlg_NewClassDenombre(&nom, &champ, listView_Def_MetaFields ,this, "CDlg_NewClassDenombre");
 if (dlg==0)            return;
 if (dlg->exec()== QDialog::Accepted && nom.length() && champ.length())
    { //.................................... si modification d'une classe déjà existante .......................
      CDenombre          *pCDenombreMod = CDenombreGetByName(nom);   // verifier si le nouveau nom n'exite pas déjà
      if (pQListViewItem && pCDenombre)
         {if (pCDenombreMod && pCDenombre != pCDenombreMod)               // on en a trouvé une avec le meme nom et c'est pas la meme alors ne pas toucher
             {QMessageBox::critical (0, QObject::tr("Mofifier une classe de dénombrement"),
                               QObject::tr("Cette classe de dénombrement existe déjà\r\nVeuillez recommencer avec d'autres valeurs"),
                               QMessageBox::Abort, QMessageBox::NoButton, QMessageBox::NoButton );
              ok = FALSE;
             }
          if (ok)
             {pCDenombre->SetName( nom ) ;
              pCDenombre->SetFieldName( champ );
              pQListViewItem->setText(0,nom);
              pQListViewItem->setText(1,champ);
             }
         }
     else  //.................................... si création d'une classe .......................
         {if (pCDenombreMod)               // on en a trouvé une avec le meme nom et c'est pas la meme alors ne pas toucher
             {QMessageBox::critical (0, QObject::tr("Créer une classe de dénombrement"),
                               QObject::tr("Cette classe de dénombrement existe déjà\r\nVeuillez recommencer avec d'autres valeurs"),
                               QMessageBox::Abort, QMessageBox::NoButton, QMessageBox::NoButton );
             }
          else
             { if (last_pQListViewItem)
                  {pQListViewItem = new QListViewItem(listView_ClassDenombreList, last_pQListViewItem, nom, champ);
                  }
               else
                  {pQListViewItem = new QListViewItem(listView_ClassDenombreList, nom, champ);
                  }
               if (pQListViewItem) {listView_ClassDenombreList->setCurrentItem (pQListViewItem );
                                    listView_ClassDenombreList->setSelected (pQListViewItem , TRUE);
                                    m_CDenombreList.append(new CDenombre(nom, champ));
                                   }
             }
         }
    }
 delete dlg;

}

//----------------------------------------- listView_ClassDenombreList_mouseButtonClicked ---------------------------------------------------------
void Wdg_Central::listView_ClassDenombreList_mouseButtonClicked( int, QListViewItem * , const QPoint &, int )
{
}
//----------------------------------------- pushButton_AddClassField_clicked ---------------------------------------------------------
void Wdg_Central::pushButton_AddClassField_clicked()
{QPoint pt;
 listView_ClassDenombreList_contextMenuRequested(0, pt, 0);
}
//----------------------------------------- pushButton_DelClassField_clicked ---------------------------------------------------------
void Wdg_Central::pushButton_DelClassField_clicked()
{QListViewItem *pQListViewItem  =  listView_ClassDenombreList->currentItem ();
 if (pQListViewItem==0) return;
 CDenombre          *pCDenombre = CDenombreGetByName(pQListViewItem->text(0));
 if (pCDenombre == 0)
    {QMessageBox::critical (0, QObject::tr("Effacer une classe de dénombrement"),
                               QObject::tr("Cette classe de dénombrement n'existe pas\r\n désynchronisation de l'affichage et des données"),
                               QMessageBox::Abort, QMessageBox::NoButton, QMessageBox::NoButton );
    }
 else
    {m_CDenombreList.removeRef ( pCDenombre );
    }
 delete pQListViewItem;      // synchro ou pas il faut la virer
}

//----------------------------------------- pushButton_DelAllClassField ---------------------------------------------------------
void Wdg_Central::pushButton_DelAllClassField_clicked()
{m_CDenombreList.clear();
 listView_ClassDenombreList->clear();
 listView_DenombreTest->clear();
}

//----------------------------------------- listView_ClassDenombreList_selectionChanged ---------------------------------------------------------
void Wdg_Central::listView_ClassDenombreList_selectionChanged( QListViewItem * )
{
}


//----------------------------------------- listView_ClassDenombreList_currentChanged ---------------------------------------------------------
void Wdg_Central::listView_ClassDenombreList_currentChanged( QListViewItem *pQListViewItem )
{if (pQListViewItem==0) return;
 ClassDenombreListToListViewTest( listView_DenombreTest, CDenombreGetByName(pQListViewItem->text(0)) );
}

//----------------------------------------- GetCurrentClassDenombre ---------------------------------------------------------
CDenombre * Wdg_Central::GetCurrentClassDenombre()
{QListViewItem *pQListViewItem  =  listView_ClassDenombreList->currentItem ();
 if (pQListViewItem==0) return 0;
 return  CDenombreGetByName(pQListViewItem->text(0));
}

////////////////////////////////////////////////////// Définition des tests des Classes de comptage //////////////////////////////////////////////////////
void Wdg_Central::listView_DenombreTest_rightButtonPressed( QListViewItem *, const QPoint &, int )
{

}


void Wdg_Central::listView_DenombreTest_rightButtonClicked( QListViewItem *, const QPoint &, int )
{

}


//----------------------------------------- listView_DenombreTest_contextMenuRequested ---------------------------------------------------------
void Wdg_Central::listView_DenombreTest_contextMenuRequested( QListViewItem *pQListViewItem, const QPoint &, int pos)
{QStringList popItem;
 QString     popRet;
 QListViewItem *last_pQListViewItem =  listView_DenombreTest->lastItem();
 CDenombre*              pCDenombre = GetCurrentClassDenombre();
 if (pCDenombre==0)     return;

 if (pQListViewItem<=0)
    {if (last_pQListViewItem ) pQListViewItem = new QListViewItem(listView_DenombreTest, last_pQListViewItem, "");
     else                      pQListViewItem = new QListViewItem(listView_DenombreTest, "");
     pos = 0;
    }
 switch(pos)
   {
    case 0:          // test validant
         {/*
          popItem.append(tr("  >               "));
          popItem.append(tr("  <               "));
          popItem.append(tr("  <=              "));
          popItem.append(tr("  >=              "));
          popItem.append(tr(" est égal à       "));
          popItem.append(tr(" contient         "));
          popItem.append(tr(" commence par     "));
          popItem.append(tr(" finit par        "));
          popItem.append(tr(" est différent de "));
          popItem.append(tr(" ne contient pas  "));
          */
          popItem           = CDenombreValidTest::GetPossiblesTestList();
          QString popRet    = DoPopupList(popItem);
          if (popRet.length())    pQListViewItem->setText(pos, popRet);
         }
         break;
    case 1:          // valeur
         {QString            texte =  pQListViewItem->text(pos);
          if (CGenTools::DialogGetString(this, tr("Saisir la valeur qui sera évaluée par l'opérateur : ") + pQListViewItem->text(0), texte,QCursor::pos().x(), QCursor::pos().y()) == QDialog::Accepted)
             { pQListViewItem->setText(pos, texte );
             }
         }
         break;
    case 2:          // expr regulière
         {QString            texte =  pQListViewItem->text(pos);
          if (CGenTools::DialogGetString(this, tr("Saisir une expression régulière (facultative) ") , texte,QCursor::pos().x(), QCursor::pos().y()) == QDialog::Accepted)
             { pQListViewItem->setText(pos, texte );
             }
         }
      break;
    case 3:          // opérateur logique
         {/*
          popItem.append(tr("  Vide "            ));
          popItem.append(tr("  et               "));
          popItem.append(tr("  ou               "));
          popItem.append(tr("  sans             "));
          */
          CMetaFiltreLine::GetListLogicOper(popItem);
          QString popRet       = DoPopupList(popItem);
          if (popRet == tr("  Vide ")) pQListViewItem->setText(pos, "");
          else if (popRet.length())    pQListViewItem->setText(pos, popRet);
         }
      break;
   }
 ListViewTest_To_ClassDenombreList( listView_DenombreTest, pCDenombre );
}

//----------------------------------------- ClassDenombreList_To_ListViewTest ---------------------------------------------------------
void Wdg_Central::ClassDenombreListToListViewTest( QListView *pQListView, CDenombre  *pCDenombre )
{if (pCDenombre == 0)   return;
 CDenombreValidTest *pCDenombreValidTest = 0;
 QListViewItem      *pQListViewItem      = 0;
 QListViewItem      *last_pQListViewItem = 0;
 pQListView->clear();
 for ( pCDenombreValidTest = pCDenombre->m_ValidTestList.first(); pCDenombreValidTest; pCDenombreValidTest = pCDenombre->m_ValidTestList.next() )
     {
      if (last_pQListViewItem)
         {pQListViewItem = new QListViewItem(pQListView, last_pQListViewItem, pCDenombreValidTest->m_Test,
                                                                              pCDenombreValidTest->m_RefValue,
                                                                              pCDenombreValidTest->m_RegExp,
                                                                              pCDenombreValidTest->m_LogicOp);
         }
      else
         {pQListViewItem = new QListViewItem(pQListView, pCDenombreValidTest->m_Test,
                                                         pCDenombreValidTest->m_RefValue,
                                                         pCDenombreValidTest->m_RegExp,
                                                         pCDenombreValidTest->m_LogicOp);
         }
      last_pQListViewItem = pQListViewItem;
     }
 if (pQListViewItem)
    {pQListView->setCurrentItem (pQListViewItem );
     pQListView->setSelected (pQListViewItem , TRUE);
    }
}

//----------------------------------------- ListViewTest_To_ClassDenombreList ---------------------------------------------------------
void Wdg_Central::ListViewTest_To_ClassDenombreList( QListView *pQListView, CDenombre  *pCDenombre )
{if (pCDenombre == 0)   return;
 pCDenombre->m_ValidTestList.clear();
 QListViewItemIterator it( pQListView );
 while ( it.current() )
    { QListViewItem *pQListViewItem = it.current();
      CDenombreValidTest *pCDenombreValidTest = new CDenombreValidTest(pQListViewItem->text(0),
                                                                       pQListViewItem->text(1),
                                                                       pQListViewItem->text(2),
                                                                       pQListViewItem->text(3)
                                                                      );
      if (pCDenombreValidTest && pCDenombreValidTest->isValid())  pCDenombre->m_ValidTestList.append(pCDenombreValidTest);
      ++it;
    }
}

//----------------------------------------- listView_DenombreTest_mouseButtonClicked ---------------------------------------------------------
void Wdg_Central::listView_DenombreTest_mouseButtonClicked( int, QListViewItem *, const QPoint &, int )
{

}
//----------------------------------------- pushButton_AddTestClassDenombre_clicked ---------------------------------------------------------
void Wdg_Central::pushButton_AddTestClassDenombre_clicked()
{

}


//----------------------------------------- pushButton_DelTestClassDenombre_clicked ---------------------------------------------------------
void Wdg_Central::pushButton_DelTestClassDenombre_clicked()
{

}


//----------------------------------------- pushButton_DelAllListDenombreTest_clicked ---------------------------------------------------------
void Wdg_Central::pushButton_DelAllListDenombreTest_clicked()
{

}

//----------------------------------------- CDenombreGetByName ---------------------------------------------------------
CDenombre* Wdg_Central::CDenombreGetByName(const QString &name)
{CDenombre *pCDenombre;
 for ( pCDenombre = m_CDenombreList.first(); pCDenombre; pCDenombre = m_CDenombreList.next() )
     {if (pCDenombre->GetName() == name) return pCDenombre;
     }
 return 0;
}

////////////////////////////////////////////////////// Parties communes aux deux listes de champs //////////////////////////////////////
//---------------------------------------------------- SetListeChamp -------------------------------------------------------------------
void Wdg_Central::SetListeChamp(QListView* pQListView, QListViewItem *pQListViewItem, int pos )
{QStringList popItem;
 QString     popRet;
 if (pQListViewItem<=0) return;
 switch(pos)
   {case 0:          // Operateur de delimitation
         {CMetaFiltre::GetDelimiterList(popItem);
          QString popRet       = DoPopupList(popItem);
          if (popRet == tr("  Vide ")) pQListViewItem->setText(pos, "");
          else if (popRet.length())    pQListViewItem->setText(pos, popRet);
         }
         break;
    case 1:          // champ
      if (IfAjoutListePossible(pQListView))
         {if (pQListView==listView_Sql_MetaFields)
             {GetMetaFieldsList(popItem);
             }
          else
             {popItem.append(m_pCMoteurBase->m_DOSS_INDEX_NOM);
              popItem.append(m_pCMoteurBase->m_DOSS_INDEX_PRENOM);
              popItem.append(m_pCMoteurBase->m_DOSS_IDENT_NSS);
              popItem.append(m_pCMoteurBase->m_DOSS_IDENT_SEX);
              popItem.append(m_pCMoteurBase->m_DOSS_IDENT_JFNOM);
              popItem.append(m_pCMoteurBase->m_DOSS_IDENT_NB_ENF);
              popItem.append(m_pCMoteurBase->m_DOSS_IDENT_RUE);
              popItem.append(m_pCMoteurBase->m_DOSS_IDENT_CODE_POST);
              popItem.append(m_pCMoteurBase->m_DOSS_IDENT_VILLE);
              popItem.append(m_pCMoteurBase->m_DOSS_IDENT_CEDEX);
              popItem.append(m_pCMoteurBase->m_DOSS_IDENT_PAYS);
              popItem.append(m_pCMoteurBase->m_DOSS_IDENT_TEL1);
              popItem.append(m_pCMoteurBase->m_DOSS_IDENT_TEL2);
              popItem.append(m_pCMoteurBase->m_DOSS_IDENT_TEL3);
              popItem.append(m_pCMoteurBase->m_DOSS_IDENT_TEL1_TYP);
              popItem.append(m_pCMoteurBase->m_DOSS_IDENT_TEL2_TYP);
              popItem.append(m_pCMoteurBase->m_DOSS_IDENT_TEL3_TYP);
              popItem.append(m_pCMoteurBase->m_DOSS_IDENT_EMAIL);
              popItem.append(m_pCMoteurBase->m_DOSS_IDENT_NUMSS);
              popItem.append(m_pCMoteurBase->m_DOSS_IDENT_IS_ASS);
              popItem.append(m_pCMoteurBase->m_DOSS_IDENT_NOM_ASS);
              popItem.append(m_pCMoteurBase->m_DOSS_IDENT_PRENOM_ASS);
              popItem.append(m_pCMoteurBase->m_DOSS_IDENT_PROF);
              popItem.append(m_pCMoteurBase->m_DOSS_IDENT_TITRE);
              popItem.append(m_pCMoteurBase->m_DOSS_RUB_HEAD_NOM_DATE);        // Court texte descriptif de l'enregistrement.
              popItem.append(m_pCMoteurBase->m_DOSS_RUB_HEAD_DATE);            // date de l'enregistrement
              popItem.append(m_pCMoteurBase->m_DOSS_RUB_HEAD_FIN);             // date de fin de l'enregistrement
              popItem.append(m_pCMoteurBase->m_DOSS_RUB_HEAD_TYPE);            // Type de rubrique
              popItem.append(m_pCMoteurBase->m_DOSS_RUB_HEAD_USER);            // utilisateur associé � rubrique
              popItem.append(m_pCMoteurBase->m_DOSS_RUB_HEAD_SIGN_USER);       // utilisateur associé signataire de la rubrique
              popItem.append(m_pCMoteurBase->m_DOSS_INDEX_GUID);
             }
          QString popRet       = DoPopupList(popItem);
          if (popRet.length()) pQListViewItem->setText(pos, popRet);
         }
         break;
    case 2:          // Operateur
      if (IfAjoutListePossible(pQListView))
         {GetListOperateur(popItem);
          QString popRet  = DoPopupList(popItem);
          if (popRet == tr("  Vide ")) pQListViewItem->setText(pos, "");
          else if (popRet.length())    pQListViewItem->setText(pos, popRet);
         }
         break;
    case 3:          // valeur
      if (IfAjoutListePossible(pQListView))
         {QString            texte =  pQListViewItem->text(pos);
          QVariant::Type field_Typ = GetFieldType( pQListViewItem->text(1) );
          if (field_Typ == QVariant::DateTime )
             {GetDateTime( texte );
              pQListViewItem->setText(pos, texte );
             }
          else if ( field_Typ == QVariant::Date)
             {GetDateTime( texte );
              pQListViewItem->setText(pos, texte );
             }
          else if (pQListViewItem->text(1)==m_pCMoteurBase->m_DOSS_RUB_HEAD_TYPE)
             {popItem         = CMetaField::GetPossiblesRubTypesList(1);
              QString popRet  = DoPopupList(popItem);
              if (popRet.length()) pQListViewItem->setText(pos, CMetaField::RubNameToRubType(popRet) );
             }
          else if (CGenTools::DialogGetString(this, tr("Saisir la valeur qui sera évaluée par l'opérateur : ") + pQListViewItem->text(2), texte,QCursor::pos().x(), QCursor::pos().y()) == QDialog::Accepted)
             { pQListViewItem->setText(pos, texte );
             }
         }
         break;
    case 4:          // et ou
      if (IfAjoutListePossible(pQListView))
         {CMetaFiltreLine::GetListLogicOper(popItem);
          QString popRet       = DoPopupList(popItem);
          if (popRet == tr("  Vide ")) pQListViewItem->setText(pos, "");
          else if (popRet.length())    pQListViewItem->setText(pos, popRet);
         }
      break;
    case 5:          // type
      if (IfAjoutListePossible(pQListView))
         {CMetaFiltreLine::GetListConversion(popItem);
          QString popRet       = DoPopupList(popItem);
          if (popRet.length())    pQListViewItem->setText(pos, popRet);
         }
         break;
   }
}

//------------------------------------------------------------ GetListOperateur_ID-------------------------------------------------------
int Wdg_Central::GetListOperateur_ID(QString operateur)
{return CMetaField::GetListOperateur_ID(operateur);
}

//------------------------------------------------------------ GetListOperateur-------------------------------------------------------
void Wdg_Central::GetListOperateur(QStringList &opList)
{CMetaField::GetListOperateur(opList);
}

//-------------------------------------------- pushButton_AddListField_clicked -------------------------------------------------------
void Wdg_Central::pushButton_AddListField_clicked(QListView* pQListView)
{//m_pCMoteurBase->GotoDebug();
 QListViewItem *last_pQListViewItem =  pQListView->lastItem();
 QListViewItem *pQListViewItem      = 0;
 QString                   str      = "";
 if (last_pQListViewItem )
    { if (IfAjoutListePossible(last_pQListViewItem))
         {int id = CMetaFiltreLine::GetListLogicOper_ID(last_pQListViewItem->text(4));
          if (id>0)  // si pas vide
             { str = "N";
             }
          else
             { QStringList popItem;
               CMetaFiltre::GetDelimiterList(popItem);
               str       = DoPopupList(popItem);
             }
         if (str.length())
            { if (str =="N") str = "";
              pQListViewItem = new QListViewItem(pQListView,last_pQListViewItem,str);
            }
        }
    }
 else
    {pQListViewItem = new QListViewItem(pQListView,"  ( ");
    }
 if (pQListViewItem) {pQListView->setCurrentItem (pQListViewItem );
                      pQListView->setSelected (pQListViewItem , TRUE);
                     }
}

//----------------------------------------- IfAjoutListePossible ---------------------------------------------------------
int Wdg_Central::IfAjoutListePossible(QListView* pQListView)
{QListViewItem *last_pQListViewItem =  pQListView->lastItem();
 QListViewItem *pQListViewItem      =  pQListView->currentItem();

 if (pQListViewItem && last_pQListViewItem && last_pQListViewItem == pQListViewItem)
    return IfAjoutListePossible(last_pQListViewItem);
 else
    return 1;
}

//----------------------------------------- IfAjoutListePossible ---------------------------------------------------------
int Wdg_Central::IfAjoutListePossible(QListViewItem* last_pQListViewItem)
{if (last_pQListViewItem && last_pQListViewItem->text(0)==tr("  ) "))
    {QMessageBox::critical (0, QObject::tr("Ajouter un champ à la liste"),
                               QObject::tr("Ajout impossible car cette liste est close par une parenthèse fermante \")\""),
                               QMessageBox::Abort, QMessageBox::NoButton, QMessageBox::NoButton );
     return 0;
    }
 return 1;
}

//----------------------------------------- pushButton_DelListIdentField_clicked ---------------------------------------------------------
void Wdg_Central::pushButton_DelListIdentField_clicked()
{QListViewItem *pQListViewItem = listView_Sql_IdentFields-> currentItem ();
 if (pQListViewItem == 0) return;
 delete pQListViewItem ;
 if (listView_Sql_IdentFields->childCount() <= 0) textEdit_Sql_IdentSelect->setText("");
 else                                             textEdit_Sql_IdentSelect->setText(ConstructRequeteIdentSelect());
}

//----------------------------------- GetDateTime -----------------------------------------------------------------------------------------
void Wdg_Central::GetDateTime(QString &dateTime)
    {   Dlg_Calendar          *dlg  = new Dlg_Calendar(this, "Calendar_Dial", FALSE);
        if (dlg ==0)                                                   return;
        dlg->setDateTimeNumeric_yyyyMMjj_Order(dateTime );
        dlg->setCaption(tr("Choix dans la date"));
        dlg->move ( QCursor::pos().x(), QCursor::pos().y() );
        if (dlg->exec()== QDialog::Accepted )
           {dateTime = dlg->get_SQL_DateTime();
           }
        delete dlg;
    }

//////////////////////////////////////////////////////   ENREGISTRER   CHARGER   ////////////////////////////////////////////////////////
//----------------------------------------- pushButton_EPP_Enregistrer_clicked ---------------------------------------------------------
void Wdg_Central::pushButton_EPP_Enregistrer_clicked()
{   QString fn = G_pCApp->m_PathAppli + "/Modeles";
    QFileDialog *fd = new QFileDialog (fn,
                                       tr( " Fichiers de texte (*.TXT *.txt *.STAT *.stat);;"
                                           " Tous les fichiers (*)"),
                                       this,
                                       "SaveDlg"
                                      ) ;
    if (fd==0)                                             return;
    fd->setMode(QFileDialog::AnyFile );    // selection multiple
    if ( fd->exec() == QDialog::Accepted )
       {QString fn = fd->selectedFile();
        if ( !fn.isEmpty() )
           {CGestIni::Param_UpdateToDisk(fn, EPP_Serialize(" "));
           }
       }
    delete fd;
}

//----------------------------------------- pushButton_EPP_Charger_clicked ---------------------------------------------------------
void Wdg_Central::pushButton_EPP_Charger_clicked()
{
    QString      fn = G_pCApp->m_PathAppli + "/Modeles";
    QFileDialog *fd = new QFileDialog (fn,
                                       tr( "Fichiers texte (*.TXT *.txt *.STAT *.stat);;"
                                           "Tous les fichiers (*)" ),
                                       this,
                                       "OuvrirDlg"
                                      ) ;
    if (fd==0)                                             return;
    if ( fd->exec() == QDialog::Accepted )
       {QString fn = fd->selectedFile();
        QString data;
        CGestIni::Param_UpdateFromDisk(fn, data);
        //m_pCMoteurBase->GotoDebug();
        EPP_UnSerialize(data);
       }
    delete fd;
}

//----------------------------------------- ListView_DossiersRetenus_doubleClicked ---------------------------------------------------------
void Wdg_Central::ListView_DossiersRetenus_doubleClicked( QListViewItem *pQListViewItem, const QPoint &pt, int pos )
{ListView_MonitorPatient_doubleClicked(pQListViewItem, pt, pos);
}

/////////////////////////////////////////////   SERIALISATION DESERIALISATION   ////////////////////////////////////////////////////////
//----------------------------------------- EPP_Serialize ------------------------------------------------------------------------------
QString Wdg_Central::EPP_Serialize(const QString &in_ofset)
{QString result = "";
 QString  ofset = in_ofset;
          ofset = ofset.prepend("\n");
        result += QListView_Serialize(listView_Sql_IdentFields, "  ", "Filtre_SQL");
        result += ofset + "<Sql_Result_Data>" + CDenombre::StrStringToXML(textEdit_Sql_IdentSelect->text())       + "</Sql_Result_Data>";
        result += QListView_Serialize(listView_Sql_MetaFields,  "  ", "Filtre_Meta");
        result += QListView_Serialize(listView_Def_MetaFields,  "  ", "MetaFieldDef");
        result += PRT_LIST_CDenombreSerialize("  ");
        result += DateSerialize("  ");

 return result;
}

//----------------------------------------- EPP_UnSerialize ---------------------------------------------------------
int Wdg_Central::EPP_UnSerialize(const QString &data)
{int          pos = 0;
 QString strToGet = "";
 pos = QListView_UnSerialize(listView_Sql_IdentFields, data, "Filtre_SQL",  pos);
 pos = GetXMLValue(data, "<Sql_Result_Data>", strToGet, pos);textEdit_Sql_IdentSelect->setText( XMLToStrString(strToGet));
 pos = QListView_UnSerialize(listView_Sql_MetaFields, data, "Filtre_Meta",  pos);
 pos = QListView_UnSerialize(listView_Def_MetaFields, data, "MetaFieldDef", pos);
 pos = PRT_LIST_CDenombreUnSerialize(data, pos);
 //pos = DateUnSerialize(data, pos);
 //........................ reactualiser les affichages ................................................................
 QListViewItem *pQListViewItem =  listView_ClassDenombreList->firstChild ();
 if (pQListViewItem) {listView_ClassDenombreList->setCurrentItem (pQListViewItem );
                      listView_ClassDenombreList->setSelected (pQListViewItem , TRUE);
                      ClassDenombreListToListViewTest( listView_DenombreTest, CDenombreGetByName(pQListViewItem->text(0)) );
                     }
 return pos;
}

//----------------------------------------- DateSerialize ---------------------------------------------------------
QString Wdg_Central::DateSerialize(const QString &in_ofset)
{QString  result   = "";
 QString   ofset   = in_ofset;
           ofset   = ofset.prepend("\n");
           result += ofset + "<Date Heure>";
           result += ofset + "  <Date de debut>"  + mle_deb->text()      +  "</Date de debut>";
           result += ofset + "  <Date de fin>"    + mle_fin->text()      +  "</Date de fin>";
           result += ofset + "  <Heure de debut>" + mle_HeureDeb->text() +  "</Heure de debut>";
           result += ofset + "  <Heure de fin>"   + mle_HeureFin->text() +  "</Heure de fin>";
           result += ofset + "</Date Heure>";
 return result;
}

//----------------------------------------- QListView_UnSerialize ---------------------------------------------------------
int Wdg_Central::DateUnSerialize(const QString &xmlData, int pos_bloc)
{int          pos       = 0;
 QString xmlTag         = "";
 QString strToGet       = "";
 QString  dataToExamine = "";
 xmlTag = "<Date Heure>";
 if ( (pos_bloc = GetXMLValue(xmlData, xmlTag,     dataToExamine, pos_bloc))  ==-1 )             // tenter avec curseur
    { if ( (pos_bloc = GetXMLValue(xmlData, xmlTag, dataToExamine, 0 )) ==-1 ) {m_LastError = " ERREUR DateUnSerialize() : donnée \"" +xmlTag + "\" non retrouvée.";  return -1;}     // si echec tenter du d�ut
    }
 xmlTag = "<Date de debut>";
 if ( (pos = GetXMLValue(dataToExamine, xmlTag, strToGet, pos))==-1 ) {m_LastError = " ERREUR DateUnSerialize() : donnée \"" +xmlTag + "\" non retrouvée.";           return -1;}     // si echec tenter du d�ut
 mle_deb->setText(strToGet);
 xmlTag = "<Date de fin>";
 if ( (pos = GetXMLValue(dataToExamine, xmlTag, strToGet, pos))==-1 ) {m_LastError = " ERREUR DateUnSerialize() : donnée \"" +xmlTag + "\" non retrouvée.";           return -1;}     // si echec tenter du d�ut
 mle_fin->setText(strToGet);
 xmlTag = "<Heure de debut>";
 if ( (pos = GetXMLValue(dataToExamine, xmlTag, strToGet, pos))==-1 ) {m_LastError = " ERREUR DateUnSerialize() : donnée \"" +xmlTag + "\" non retrouvée.";           return -1;}     // si echec tenter du d�ut
 mle_HeureDeb->setText(strToGet);
 xmlTag = "<Heure de fin>";
 if ( (pos = GetXMLValue(dataToExamine, xmlTag, strToGet, pos))==-1 ) {m_LastError = " ERREUR DateUnSerialize() : donnée \"" +xmlTag + "\" non retrouvée.";           return -1;}     // si echec tenter du d�ut
 mle_HeureFin->setText(strToGet);
 return pos;
}

//----------------------------------------- QListView_Serialize ---------------------------------------------------------
QString Wdg_Central::QListView_Serialize(QListView *pQListView, const QString &in_ofset, const QString &prefix_Name)
{QString  result = "";
 QString   ofset = in_ofset;
           ofset = ofset.prepend("\n");
 int     nb_item = pQListView->childCount();
         result += ofset + "<" + prefix_Name + "_List>";
         result += ofset + "  <" + prefix_Name + "_List_count>"+ QString::number( nb_item ) + "</" + prefix_Name + "_List_count>";
 int     nb_col  = pQListView->header ()->count();
         result += ofset + "  <" + prefix_Name + "_List_NbCol>"+ QString::number(nb_col )   + "</" + prefix_Name + "_List_NbCol>";

 int        nb   = 0;
 QListViewItemIterator it( pQListView );
 while ( it.current() )
    { QListViewItem *pQListViewItem = it.current();
      result += ofset + "  <" + prefix_Name + "_List_Line>";
      for (int i = 0; i<nb_col; ++i)
          {QString tag_deb = "<" + prefix_Name + "_Item" + QString::number(nb) + "_Col" + QString::number(i) + ">";
           QString tag_end = tag_deb; tag_end.insert(1,"/");
           result += ofset + "    " + tag_deb + CDenombre::StrStringToXML(pQListViewItem->text(i)) + tag_end;
          }
      result += ofset + "  </" + prefix_Name + "_List_Line>";
      ++it;
      ++nb;
    }
 result += ofset + "</" + prefix_Name + "_List>";
 return result;
}

//----------------------------------------- QListView_UnSerialize ---------------------------------------------------------
int Wdg_Central::QListView_UnSerialize(QListView *pQListView,  const QString &xmlData, const QString &prefix_Name, int pos_bloc)
{          m_LastError = "";
 QString        xmlTag = "";
 QString dataToExamine = "";
 QString   strToGet    = "";
 int       pos         = 0;

 xmlTag = "<" + prefix_Name + "_List>";
 if ( (pos_bloc = GetXMLValue(xmlData, xmlTag,     dataToExamine, pos_bloc))  ==-1 )             // tenter avec curseur
    { if ( (pos_bloc = GetXMLValue(xmlData, xmlTag, dataToExamine, 0 )) ==-1 ) {m_LastError = " ERREUR QListView_UnSerialize() : donnée \"" +xmlTag + "\" non retrouvée.";  return -1;}     // si echec tenter du d�ut
    }

 xmlTag = "<" + prefix_Name + "_List_count>";
 if ( (pos = GetXMLValue(dataToExamine, xmlTag, strToGet, pos))==-1 ) {m_LastError = " ERREUR QListView_UnSerialize() : donnée \"" +xmlTag + "\" non retrouvée.";  return -1;}     // si echec tenter du d�ut
 int nb_item  = strToGet.toInt();

 xmlTag = "<" + prefix_Name + "_List_NbCol>";
 if ( (pos = GetXMLValue(dataToExamine, xmlTag, strToGet, pos))==-1 ) {m_LastError = " ERREUR QListView_UnSerialize() : donnée \"" +xmlTag + "\" non retrouvée.";  return -1;}     // si echec tenter du d�ut
 int nb_col    = strToGet.toInt();          // nombre de colonnes indiquées dans la structure XML
 int nb_col_LV = pQListView->columns();     // nombre de colonnes indiquées de la listview à charger
 pQListView->clear();
 QListViewItem *pQListViewItem       = 0;
 QListViewItem *pQListViewItemAfter  = 0;
 for (int nb=0; nb<nb_item; ++nb)
     {if (nb == 0)   pQListViewItem = new QListViewItem ( pQListView );
      else           pQListViewItem = new QListViewItem ( pQListView,  pQListViewItemAfter);
      pQListViewItemAfter = pQListViewItem;

      for (int i = 0; i<nb_col; ++i)
          {xmlTag = "<" + prefix_Name + "_Item" + QString::number(nb) + "_Col" + QString::number(i) + ">";
           if ( (pos = GetXMLValue(dataToExamine, xmlTag, strToGet, pos))==-1 ) {m_LastError = " ERREUR QListView_UnSerialize() : donn� \"" +xmlTag + "\" non retrouv�.";  return -1;}     // si echec tenter du d�ut
           if (pQListViewItem && i<nb_col_LV) pQListViewItem->setText(i, XMLToStrString(strToGet) );
          }
     }
 return pos_bloc;
}

//----------------------------------------- PRT_LIST_CDenombreSerialize ---------------------------------------------------------
QString Wdg_Central::PRT_LIST_CDenombreSerialize(const QString &in_ofset)
{QString result = "";
 QString  ofset = in_ofset;
          ofset = ofset.prepend("\n");
 CDenombre *pCDenombre;
      result    += ofset + "<CDenombre_List>";
      result    += ofset + "  <CDenombre_List_count>" + QString::number(m_CDenombreList.count() ) +  "</CDenombre_List_count>";
 for ( pCDenombre = m_CDenombreList.first(); pCDenombre; pCDenombre = m_CDenombreList.next() )
     {result    += ofset + "  <CDenombre_List_data>";
      result    += ofset +   pCDenombre->Serialize(in_ofset+"    ");
      result    += ofset + "  </CDenombre_List_data>";
     }
      result    += ofset + "</CDenombre_List>";
 return result;
}

//----------------------------------------- PRT_LIST_CDenombreUnSerialize ---------------------------------------------------------
int Wdg_Central::PRT_LIST_CDenombreUnSerialize(const QString &data, int pos_bloc)
{          m_LastError = "";
 QString        xmlTag = "";
 QString dataToExamine = "";
 QString   strToGet    = "";
 int       pos         = 0;
 m_CDenombreList.clear();
 xmlTag = "<CDenombre_List>";
 if ( (pos_bloc = GetXMLValue(data, xmlTag,     dataToExamine, pos_bloc))  ==-1 )             // tenter avec curseur
    { if ( (pos_bloc = GetXMLValue(data, xmlTag, dataToExamine, 0 )) ==-1 ) {m_LastError = " ERREUR PRT_LIST_CDenombreUnSerialize() : donnée \"" +xmlTag + "\" non retrouvée.";  return -1;}     // si echec tenter du d�ut
    }

 xmlTag = "<CDenombre_List_count>";
 if ( (pos = GetXMLValue(dataToExamine, xmlTag, strToGet, pos))==-1 ) {m_LastError = " ERREUR PRT_LIST_CDenombreUnSerialize() : donnée \"" +xmlTag + "\" non retrouvée.";  return -1;}     // si echec tenter du d�ut
 int nb_item  = strToGet.toInt();

 listView_ClassDenombreList->clear();
 QListViewItem *pQListViewItem       = 0;
 QListViewItem *pQListViewItemAfter  = 0;
 for (int nb=0; nb<nb_item; ++nb)
     {QString xmlDef_CDenombre;
      if ( (pos = GetXMLValue(dataToExamine, "<CDenombre_List_data>", xmlDef_CDenombre, pos))==-1 ) {m_LastError = " ERREUR PRT_LIST_CDenombreUnSerialize() : donnée \"<CDenombre_List_data>\" non retrouvée.";  return -1;}     // si echec tenter du d�ut
      CDenombre *pCDenombre = new CDenombre(xmlDef_CDenombre);
      if (pCDenombre->isValid())
         { m_CDenombreList.append(pCDenombre);
           if (nb == 0)   pQListViewItem = new QListViewItem ( listView_ClassDenombreList, pCDenombre->GetName(), pCDenombre->GetFieldName() );
           else           pQListViewItem = new QListViewItem ( listView_ClassDenombreList,  pQListViewItemAfter,  pCDenombre->GetName(), pCDenombre->GetFieldName());
           pQListViewItemAfter = pQListViewItem;
         }
     }
 return pos_bloc;
}

//------------------------------------------------ GetXMLValue --------------------------------------------------------
// ACTION extrait la valeur contenue entre deux balises XML
// ENTREE : const QString &dataToExamine : texte a analyser
//          const QString &xmlToken : token de la balise XML doit �re de  la forme : "<xxxxxxxxxx>"
//          QString &valueToGet     : QString dans laquelle d�oser le r�ultat
//          int pos /* = -1 */   : position �laquelle rechercher la recherche si -1 (valeur par d�aut) la recherche se fait �partir du d�ut
//                                 si l'on est certain que les tokens sont ordonn� alors l'on peut se servr du retour de la fonction
//                                 pour positionner pos de fa�n �acc��er le traitement.
// RETOUR : int position situ� apr� le token fermant, permet d'avancer sur le token suivant.

int  Wdg_Central::GetXMLValue(const QString &dataToExamine, const QString &xmlToken_in, QString &valueToGet, int pos /* = -1 */)
{valueToGet       = "";
 QString xmlToken = xmlToken_in;
 int deb = dataToExamine.find(xmlToken, pos);
 if (deb == -1) {m_LastError = TR("ERREUR Wdg_Central::GetXMLValue() Mention de début manquante : \"" + xmlToken + "\""); return -1;}
 deb += xmlToken.length();
 int end = dataToExamine.find(xmlToken.insert(1,"/"), deb);
 if (end == -1) {m_LastError = TR("ERREUR Wdg_Central::GetXMLValue() Mention de  fin  manquante : \"" + xmlToken +"\"");  return -1;}

 valueToGet = dataToExamine.mid(deb , end - deb );
 return end + xmlToken.length();
}

//---------------------------------- StrStringToXML ---------------------------------------------------------------------------
QString Wdg_Central::StrStringToXML( const QString &txt_in)
{QString txt = txt_in;
 txt.replace(">", "&gt;");
 txt.replace("<", "&lt;");
 return txt;
}
//---------------------------------- XMLToStrString ---------------------------------------------------------------------------
QString Wdg_Central::XMLToStrString( QString &txt)
{txt.replace("&gt;",">");
 txt.replace("&lt;","<");
 return txt;
}

////////////////////////////////////////////////// COMPTAGE ///////////////////////////////////////////////////////////
//------------------------------------ initFieldsList -----------------------------------------------------------------
void Wdg_Central::initFieldsList(QStringList &list)
{GetFieldsList(list,      m_pCMoteurBase->m_DOSS_RUB_HEAD_TBL_NAME);
 GetFieldsList(list,      m_pCMoteurBase->m_DOSS_INDEX_TBL_NAME);
 GetFieldsList(list,      m_pCMoteurBase->m_DOSS_IDENT_TBL_NAME);
 GetFieldsList(list,      m_pCMoteurBase->m_DOSS_RUB_DATA_TBL_NAME);

 //GetFieldsList(m_FieldsList_Note,          const QString &tableName);
 //GetFieldsList(m_FieldsList_Intervenants,  const QString &tableName);
}

//---------------------------------- EPP_Do ---------------------------------------------------------------------------
void Wdg_Central::EPP_Do()
{   //.............. recuperer la liste des champs pour ...............................................................
    //               avoir leur indice pour recuperer value
    QStringList sqlFieldList;
    initFieldsList(sqlFieldList);
    CMetaField *pCMetaField;

        //........................ executer la requete SQL ..............................................................
    if (m_pCMoteurBase->m_DataBase->isOpen()==FALSE && m_pCMoteurBase->m_DataBase->open()==FALSE)  return ;  // si point = erreur d'ouverture de la base
    QString requete = textEdit_Sql_IdentSelect->text();
    QSqlQuery query(requete , m_pCMoteurBase->m_DataBase );


    //........................ créer la liste des meta-field à partir de la list-view .................................
    //                         des définitions de métafield
    m_CMetaFieldList.clear();
    QListViewItemIterator it( listView_Def_MetaFields );
    while ( it.current() )
          { QListViewItem *pQListViewItem = it.current();
            pCMetaField = new CMetaField(pQListViewItem->text(0),
                                         pQListViewItem->text(1),
                                         pQListViewItem->text(2),
                                         G_pCApp->m_pCMedicaBase
                                        );
            if (pCMetaField && pCMetaField->isValid() != -1)
               {m_CMetaFieldList.append(pCMetaField);
               }
           ++it;
         }
    m_pCMoteurBase->GotoDebug();
    //........................ créer le MetaFiltre avec la listes des meta-champs et de la liste view ...............
    //                         de definition du meta-filtre
    CMetaFiltre metaFiltre(&m_CMetaFieldList, listView_Sql_MetaFields);


    //.......................... relier les classes de dénombrage avec les meta-champs...........................
    //                           ou les indices de champ SQL pour permettre l'extraction future
    //                           des données.
    CDenombre *pCDenombre;
    for ( pCDenombre   = m_CDenombreList.first(); pCDenombre; pCDenombre = m_CDenombreList.next() )
        {pCDenombre->m_mapResultCount.clear();
         QString field_name = pCDenombre->m_FieldWork.mid(2);
         if (pCDenombre->m_FieldWork[0]=='*')
            {for ( pCMetaField   = m_CMetaFieldList.first(); pCMetaField; pCMetaField = m_CMetaFieldList.next() )
                 {if (pCMetaField->m_Name == field_name)
                     {pCDenombre->m_pCMetaField = pCMetaField;
                      pCDenombre->m_Field_ID    = -1;
                     }
                 } // endp for (CMetaField   = m_CMetaFieldList.first() ...
            }
         else
            {pCDenombre->m_Field_ID    = sqlFieldList.findIndex (pCDenombre->m_FieldWork.mid(2));
             pCDenombre->m_pCMetaField = 0;
            }
        }


    //........................ executer la requete SQL ..............................................................
    //    if (m_pCMoteurBase->m_DataBase->isOpen()==FALSE && m_pCMoteurBase->m_DataBase->open()==FALSE)  return ;  // si point = erreur d'ouverture de la base
    //    QString requete = textEdit_Sql_IdentSelect->text();
    //    QSqlQuery query(requete , m_pCMoteurBase->m_DataBase );
    //........................ recuperer index des champs dans la query ................................
    //                        dont on va avoir besoin pour créer la liste
    if (checkBox_DossiersRetenus->isChecked()) ListView_DossiersRetenus->clear();
    if (checkBox_DossiersRejetes->isChecked()) ListView_PatientRejetes->clear();
    int   id_Nom         = sqlFieldList.findIndex ("FchGnrl_NomDos");
    int   id_Prenom      = sqlFieldList.findIndex ("FchGnrl_Prenom");
    int   id_GUID        = sqlFieldList.findIndex ("FchGnrl_IDDos");
    int   id_Pk          = sqlFieldList.findIndex ("ID_PrimKey");
    int   id_Blobs       = sqlFieldList.findIndex ("RbDate_DataRub");
    int   id_RubType     = sqlFieldList.findIndex ("RbDate_TypeRub");
    int   id_DtNss       = sqlFieldList.findIndex ("FchPat_Nee");
    int   id_User        = sqlFieldList.findIndex ("RbDate_CreateUser");
    int   id_DateRub     = sqlFieldList.findIndex ("RbDate_Date");
    long  nbRecord       = 0;
    long  nbRecordTotal  = 0;
    QString        texte = "";
    QString     lastGUID = "";
    QString      curGUID = "";
    textEdit_SelectDossiers->setText("");

    //.................. Recuperer la liste de la requete ..........................................
    if ( query.isActive() )
    {
        QByteArray qByteArray;
        while (query.next())
        {   ++nbRecordTotal;
            curGUID      = query.value(id_GUID).toString();
            //.................................. SI CHANGEMENT DE DOSSIER .........................................................
            //                                   alors tous les metachamps devraient etre renseignes
            //                                   alors on peut filtrer et eventuellement compter
            if (curGUID != lastGUID)
               { if (lastGUID.length())     // si pas la première fois
                    { //...................... les métachamps charges, actionner le meta-filtre ..................................
                      // PB : les premières rubriques sont des prescriptions pour lesquelles les metachamps sont renseignés
                      //       et doivent etre evalues, mais le filtre d'inclusion se fait sur un métachamp de la rubrique
                      //       observation, non encore renseigné du fait quelle arrive après, le test d'inclusion ne peut donc
                      //       se faire et les éléments de la rubrique presccription ne  sont pas evalues.
                      // IDEE : Les blobs sont tries de facon à ce qu'ils soient tous pour le meme patient à la suite
                      //        les uns des autres, on detecte les changements de dossier avec : curGUID != lastGUID
                      //        et alors l'on traite le meta filtre et on compte.
                      //        le filtre s'opere donc sur un dossier dont tous les blobs auront au préalable renseigné
                      //        tous les méta champs.
                       bool ret_metaFiltre =  metaFiltre.DoTest();
                       //................ si liste de dossiers retenus à remplir la renseigner ....................................
                       if (checkBox_DossiersRetenus->isChecked() && ret_metaFiltre /*&& lastGUID != curGUID */)
                          {new QListViewItem ( ListView_DossiersRetenus,
                                               CGestIni::Utf8_Query(query, id_Nom ),
                                               CGestIni::Utf8_Query(query, id_Prenom ),
                                               query.value(id_Pk).toString(),
                                               lastGUID
                                            );
                          }
                      //................ si le metafiltre autorise à traiter ......................................................
                      //                 actionner les denombrements pour compter
                      if (ret_metaFiltre)
                         {for ( pCDenombre   = m_CDenombreList.first(); pCDenombre; pCDenombre = m_CDenombreList.next() )
                               {pCDenombre->DoResult(query);
                               }
                         }
                    }// endif (currentID.length())
                 for ( pCMetaField   = m_CMetaFieldList.first(); pCMetaField; pCMetaField = m_CMetaFieldList.next() )
                     { pCMetaField->m_ResultList.clear();
                     }
                 lastGUID = curGUID;
               }
            //.................... recuperer le blobs que si le type de rubrique .........................................................
            //                     que query presente existe dans un des meta-champ
            QByteArray qByteArray;
            //bool isBlobsNotRead  = TRUE;
            char *ptr            = 0;
            long len             = 0;
            QString rub_type     = query.value(id_RubType).toString();
            int         curs_pos = 0;

            //...................... CHARGER LES META CHAMPS (SI CONCERNES) AVEC LES VALEURS DE CE BLOB ....................................................
            //                       passer en revue tous les meta-champs pour trouver celui corespondant au blobs
            //                      si trouve charger le blobs et extraire les données de ce blobs correspondant aux meta-champs
            //                      et charger tous les meta-champs corespondant au type avec les données du blobs
            for ( pCMetaField   = m_CMetaFieldList.first(); pCMetaField; pCMetaField = m_CMetaFieldList.next() )
                {bool err = FALSE;
                 if (pCMetaField->m_Rubrique == "99900000")      // Age Patient
                    {QDate     tmp_dt = query.value(id_DtNss).toDate();
                     pCMetaField->GetValue(QString::number(CMoteurBase::CalculeDiffAge_Num(&tmp_dt)),curs_pos);
                     if (pCMetaField->m_LastError[0]=='W')               {if (checkBoxWarning->isChecked())           err = TRUE; }
                     else if      ( pCMetaField->m_LastError.length()>0) {if (checkBox_DossiersRejetes->isChecked())  err = TRUE; }
                     ++nbRecord;
                    }
                 else if (rub_type == pCMetaField->m_Rubrique)                                                                 // on a trouve le premier meta-champ associé à ce blobs
                    { //.................. lire le blobs si pas deja fait..........................................
                      if (ptr==0 )            // on lit le blobs si pas déjà fait
                         {qByteArray = query.value(id_Blobs).toByteArray();
                          ptr        = qByteArray.data();
                          len        = qByteArray.size()-4;
                          texte      = "";
                         } // end if (texte.length()==0 )
                      if (ptr && len>6)
                         { if (strncmp(ptr, "<htm", 4)==0 )     // <?xm  [Ant <htm
                              {if (CGestIni::IsUtf8( ptr )) texte = QString::fromUtf8 ( ptr , len + 4);
                               else                         texte = ptr;
                               CHtmlTools::HtmlToAscii(texte, CHtmlTools::StrictASCII);
                              }
                           else if (strncmp(ptr, "<?xm", 4)==0 || strncmp(ptr, "[Ant", 4)==0)
                              {if (CGestIni::IsUtf8( ptr )) texte = QString::fromUtf8 ( ptr , len + 4);
                               else                         texte = ptr;
                              }
                           else
                              { texte = CMoteurBase::RTF_ToASCII(ptr+4, len);
                              }
                         } //end if (ptr && len>6)

                      //.................. pour ce blobs remplir le meta-champ .......................................
                      pCMetaField->GetValue(texte, curs_pos);  // recuperer la valeur de ce meta-champ
                      if (pCMetaField->m_LastError[0]=='W')               {if (checkBoxWarning->isChecked())           err = TRUE; }
                      else if      ( pCMetaField->m_LastError.length()>0) {if (checkBox_DossiersRejetes->isChecked())  err = TRUE; }

                      ++nbRecord;
                    } //endif (rub_type == pCMetaField->m_Rubrique)
                 else
                    {//pCMetaField->m_ResultList.clear();
                    }
                 if ( err )
                    { new QListViewItem (ListView_PatientRejetes,
                                         CGestIni::Utf8_Query(query, id_Nom ),
                                         CGestIni::Utf8_Query(query, id_Prenom ),
                                         query.value(id_DateRub).toString().left(10),
                                         query.value( id_User ).toString(),
                                         pCMetaField->m_LastError,
                                         query.value(id_GUID).toString()
                                        );
                    }//endif (pCMetaField->m_LastError.length()>0)
                } // endfor ( pCMetaField   = m_CMetaFieldList.first();
        } // end while (query.next())
     //................................. ne pas oublier le DERNIER DOSSIER ..................................
     if (lastGUID.length())     // si pas la première fois (les méta champs ne sont pas renseignés cas aucun query valide)
        { //...................... les métachamps charges, actionner le meta-filtre ..................................
          query.last();
          bool ret_metaFiltre =  metaFiltre.DoTest();
          //................ si liste de dossiers retenus à remplir la renseigner ....................................
          if (checkBox_DossiersRetenus->isChecked() && ret_metaFiltre /*&& lastGUID != curGUID */)
             {new QListViewItem ( ListView_DossiersRetenus,
                                  CGestIni::Utf8_Query(query, id_Nom ),
                                  CGestIni::Utf8_Query(query, id_Prenom ),
                                  query.value(id_Pk).toString(),
                                  lastGUID
                                );
              }
          //................ si le metafiltre autorise à traiter ......................................................
          //                 actionner les denombrements pour compter
          if (ret_metaFiltre)
             {for ( pCDenombre   = m_CDenombreList.first(); pCDenombre; pCDenombre = m_CDenombreList.next() )
                  { pCDenombre->DoResult(query);
                  }
             }
         }// endif (currentID.length())
    } //endif ( query.isActive() )
 //.................................. sortir les resultats ......................................
 textEdit_SelectDossiers->clear();
 for ( pCDenombre   = m_CDenombreList.first(); pCDenombre; pCDenombre = m_CDenombreList.next() )
     {texte = pCDenombre->OutResult();
      textEdit_SelectDossiers->append ( texte );
     }
 m_pCMoteurBase->m_DataBase->close();
}
















