/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtGui>
#include <QFileInfo>
#include <QCursor>

#include "mainwindow.h"
#include "mdibox.h"
#include "C_Wdg_Box.h"
#include "CApp.h"
#include "../../MedinTuxTools-QT4/CGestIni.h"
#include "C_BaseSynoptux.h"
#include "C_Dlg_Changements.h"
#include "C_ClickableLed.h"
#define DB_DRTUX              CApp::pCApp()->getDB()->database()
#define DATA_BASE_SYNOPTUX    CApp::pCApp()->getDB()->database()
#define BASE_SYNOPTUX         CApp::pCApp()->getDB()
#define TACHES          "ST_taches"
#define ETATS           "ST_etats"
#define ETATS_TACHES    "ST_etats_taches"
#define ENCOURS         "ST_encours"
#define ENCOURS_TACHES  "ST_encours_taches"
#define BOX             "ST_box"
#define HISTORIQUE      "ST_historique"

//-----------------------------------------MainWindow---------------------------------------------
MainWindow::MainWindow()
{
    // Initialisation des variables globales
    m_timerClignote   = 0;
    m_timerAlarme     = 0;
    m_Apropos_Proc    = 0;
    m_notAction       = 0;
    m_popupTache      = 0;
    m_ResponsableSelectionne = "Tous";

    for (int i = 0; i < NB_BOX_MAX; i++) m_pC_Wdg_Box[i] = 0;

    //.................... indicateur d'action des timers ...........................................
    m_TimerStateIndicator = new C_ClickableLed(this);
    m_TimerStateIndicator->setText(tr("Etat de la connexion"));
    statusBar()->insertPermanentWidget(0, m_TimerStateIndicator);
    connect( m_TimerStateIndicator , SIGNAL( clicked() ) , this , SLOT( Slot_timerStateIndicator_clicked() ) );
    setTimerActionEnabled(TRUE);

    // Lecture des parametres dans le .ini
    if (!RecupInit())           sortieAppli();

    // Lecture de tous les styles dans le .css
    if (!LireleCSS())           sortieAppli();

    // Creation de la window de base
    creerActionsGene();
    creerMenusGene();
    // RIEN A METTRE POUR LE MOMENT createToolBars();
    createStatusBar();
    setWindowIcon(QIcon(":/images/CroixRouge.png"));
    setUnifiedTitleAndToolBarOnMac(true);

    m_mdiArea = new QMdiArea;
    m_mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    m_mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setCentralWidget(m_mdiArea);
    this->setAttribute(Qt::WA_AcceptTouchEvents); // ???????????

    // Creation des connexions parametrables Boutons et Menus
    m_BoxMapper = new QSignalMapper(this);
    connect(m_BoxMapper, SIGNAL(mapped(QWidget *)),       this, SLOT(rentrerUnPatient(QWidget *)));
    m_PatientMapper = new QSignalMapper(this);
    connect(m_PatientMapper, SIGNAL(mapped(QWidget *)),   this, SLOT(masquerNomPatient(QWidget *)));
    m_BougerMapper = new QSignalMapper(this);
    connect(m_BougerMapper, SIGNAL(mapped(QWidget *)),    this, SLOT(bougerLePatient(QWidget *)));
    m_TacheMapper = new QSignalMapper(this);
    connect(m_TacheMapper, SIGNAL(mapped(QWidget *)),     this, SLOT(Note_Tache(QWidget *)));
    m_AnnuleTacheMapper = new QSignalMapper(this);
    connect(m_AnnuleTacheMapper, SIGNAL(mapped(QWidget *)),this, SLOT(Annule_Tache(QWidget *)));
    m_RecapMapper = new QSignalMapper(this);
    connect(m_RecapMapper, SIGNAL(mapped(QWidget *)),     this, SLOT(Recap_Tache(QWidget *)));
    m_EtatMapper = new QSignalMapper(this);
    connect(m_EtatMapper, SIGNAL(mapped(QWidget *)),      this, SLOT(modif_Etat(QWidget *)));
    m_MenuMapper = new QSignalMapper(this);
    connect(m_MenuMapper, SIGNAL(mapped(QString )),       this, SLOT(modif_Etat_menu(QString)));
    m_ReplierMapper = new QSignalMapper(this);
    connect(m_ReplierMapper, SIGNAL(mapped(QWidget *)),   this, SLOT(PlierDeplier(QWidget *)));
    m_RespMapper = new QSignalMapper(this);
    connect(m_RespMapper, SIGNAL(mapped(QWidget *)),      this, SLOT(modif_Resp(QWidget *)));
    m_MenuSelectionRespMapper = new QSignalMapper(this);
    connect(m_MenuSelectionRespMapper, SIGNAL(mapped(QString)),      this, SLOT(selectionDunResponsable(QString)));
    m_MenuRespMapper = new QSignalMapper(this);
    connect(m_MenuRespMapper, SIGNAL(mapped(QString )),   this, SLOT(modif_Resp_menu(QString)));
    m_DrTuxMapper = new QSignalMapper(this);
    connect(m_DrTuxMapper, SIGNAL(mapped(QWidget *)),     this, SLOT(Lancer_DrTux(QWidget *)));

    creerActionsMdi();      // BOF NE SERT A RIEN
    creerMenusMdi();

    creerMenuSelectionResponsable();
    m_helpMenu = menuBar()->addMenu(tr("&Aide"));
    m_helpMenu->addAction(m_aboutAct);

    // Affichage des BOX avec leur occupation
    Afficher_Les_Box();

    // REVOIR AVEC LA CREATION DES BOX
    Recuperer_Positions();

    // Lancement du timer de contrele des entrees de patients
    if (m_Dossier_Entrees > 0)
       {m_timerEntrees = new QTimer(this);
        connect(m_timerEntrees, SIGNAL(timeout()), this, SLOT(Controle_Entrees()));
        m_timerEntrees->start(m_PeriodeEntrees * 1000);
       }
    // Lancement du timer de contrele des Taches en retard
    if (m_PeriodeAlarme > 0)
       {m_timerAlarme = new QTimer(this);
        connect(m_timerAlarme, SIGNAL(timeout()), this, SLOT(Controle_Alarmes()));
        m_timerAlarme->start(m_PeriodeAlarme * 1000);
       }

}
//-----------------------------------------closeEvent---------------------------------------------
void MainWindow::closeEvent(QCloseEvent *event)
{
    m_mdiArea->closeAllSubWindows();
    if (m_mdiArea->currentSubWindow()) {
        event->ignore();
    } else {
        event->accept();
    }
}
//----------------------------------Slot_timerStateIndicator_clicked()--------------------------------------------
void MainWindow::Slot_timerStateIndicator_clicked()
{setTimerActionEnabled(TRUE);
}
//----------------------------------setTimerActionEnabled--------------------------------------------
void MainWindow::setTimerActionEnabled(bool state /*=TRUE*/)
{if (state) m_notAction = 0;
 else       m_notAction = 1;
 setLedStateOnTimerState();
}

//----------------------------------setTimerActionOn--------------------------------------------
void MainWindow::setTimerActionOn()
{if (m_notAction>0) --m_notAction;
 setLedStateOnTimerState();
}
//----------------------------------setTimerActionOff--------------------------------------------
void MainWindow::setTimerActionOff()
{++m_notAction;
 setLedStateOnTimerState();
}
//----------------------------------setLedStateOnTimerState--------------------------------------------
void MainWindow::setLedStateOnTimerState()
{if (m_notAction>0) {m_TimerStateIndicator->setLedColor(C_ClickableLed::Red);   m_TimerStateIndicator->setText(tr("\303\251coute inactive : %1").arg(QString::number(m_notAction)));}
 else               {m_TimerStateIndicator->setLedColor(C_ClickableLed::Green); m_TimerStateIndicator->setText(tr("\303\251coute active "));}
}

//----------------------------------sortieAppli--------------------------------------------
void MainWindow::sortieAppli()
{

}

//----------------------------------RecupInit--------------------------------------------
bool MainWindow::RecupInit()
{
    // lecture du fichier synoptux.ini
    m_nomFicIni   = QApplication::applicationDirPath()+ "/synoptux.ini";
    m_settingsIni = new QSettings(m_nomFicIni, QSettings::IniFormat);
    m_settingsIni->setIniCodec ("ISO 8859-1");

    // Recup des parametres dossier entrees
    m_Dossier_Entrees = CApp::pCApp()->readUniqueParam("Interface", "Dossier_Entrees");
    if (QDir(m_Dossier_Entrees).isRelative()) m_Dossier_Entrees.prepend(CApp::pCApp()->pathAppli());
    //m_Dossier_Entrees        = m_settingsIni->value(tr("Interface/Dossier_Entrees")).toString();
    if (m_Dossier_Entrees.length() > 0)
        {if (!m_DirDossierEntree.cd(m_Dossier_Entrees) )
            {QMessageBox::warning(0, NAME_APPLI, tr("Le dossier de r\303\251ception des fichiers Entr\303\251es :<br>")
                                  + m_Dossier_Entrees + tr("<br>n'est pas accessible !"));
             return false;
            }
        }
    m_CodeBoxParDefaut          = m_settingsIni->value(tr("Interface/Code_Box_Par_Defaut")).toString();
    m_BoutonDrtux               = m_settingsIni->value(tr("Interface/Bouton_Acces_DrTux")).toString();
    m_ConfirmationSortie        = m_settingsIni->value(tr("Interface/Confirmation_Sortie_Definitive")).toString();

    // Recup de l'exe calendrier dans Medintux
    m_ExeCalendrier             = m_settingsIni->value(tr("Interface/Chemin_du_calendrier")).toString();
    // Recup des couleurs par defaut
    m_Couleur_Patients          = m_settingsIni->value(tr("Affichage/Couleur_Patients")).toString();
    m_Couleur_PatientsClignote  = m_settingsIni->value(tr("Affichage/Couleur_Patients_Clignote")).toString();
    m_Couleur_Comment_Patients  = m_settingsIni->value(tr("Affichage/Couleur_Commentaire_Patients")).toString();
    m_Couleur_BougerPatients    = m_settingsIni->value(tr("Affichage/Couleur_BougerPatients")).toString();
    m_Couleur_Medecins          = m_settingsIni->value(tr("Affichage/Couleur_Medecins")).toString();
    m_Couleur_HeuresEntree      = m_settingsIni->value(tr("Affichage/Couleur_HeuresEntree")).toString();
    m_Couleur_HeuresSortie      = m_settingsIni->value(tr("Affichage/Couleur_HeuresSortie")).toString();
    m_CouleurDesti              = m_settingsIni->value(tr("Affichage/Couleur_ChoixDestination")).toString();
    // Recup des tailles par defaut
    m_Hauteur_NomBox            = m_settingsIni->value(tr("Affichage/Hauteur_NomBox")).toInt();
    m_Largeur_Box               = m_settingsIni->value(tr("Affichage/Largeur_Box")).toInt();
    m_Hauteur_Box               = m_settingsIni->value(tr("Affichage/Hauteur_Box")).toInt();
    m_Hauteur_Taches            = m_settingsIni->value(tr("Affichage/Hauteur_Taches")).toInt();
    m_Hauteur_Medecins          = m_settingsIni->value(tr("Affichage/Hauteur_Medecins")).toInt();
    m_Hauteur_Heures            = m_settingsIni->value(tr("Affichage/Hauteur_Heures")).toInt();
    m_Largeur_Heures            = m_settingsIni->value(tr("Affichage/Largeur_Heures")).toInt();
    m_Largeur_Annule_Tache      = m_settingsIni->value(tr("Affichage/Largeur_Annule_Tache")).toInt();

    m_Hauteur_Patients          = m_settingsIni->value(tr("Affichage/Hauteur_Patients")).toInt();
    m_Hauteur_Comment_Patients  = m_settingsIni->value(tr("Affichage/Hauteur_Commentaire_Patients")).toInt();
    m_Largeur_Tache             = m_settingsIni->value(tr("Affichage/Largeur_Tache")).toInt();
    m_Largeur_Boutons           = m_settingsIni->value(tr("Affichage/Largeur_Boutons")).toInt();
    m_ModeAffichage             = m_settingsIni->value(tr("Affichage/Mode_Affichage")).toString();

    // Recup des positions des fenetres
    // REVOIR AVEC LA CREATION DES BOX
    Recuperer_Positions();

    // Titre de la fenetre principale
    setWindowTitle(m_settingsIni->value(tr("Affichage/Titre_Application")).toString());

    // Timers et alarmes
    m_PeriodeAlarme     = m_settingsIni->value(tr("Timer/Periodicite_controle_alarme_en_secondes")).toInt();
    m_PeriodeClignote   = m_settingsIni->value(tr("Timer/Periodicite_clignotement_en_secondes")).toInt();
    m_PeriodeEntrees    = m_settingsIni->value(tr("Timer/Periodicite_controle_des_entrees")).toInt();
    m_DelaiDeSortie     = m_settingsIni->value(tr("Timer/Delai_avant_suppression_des_sorties_en_mn")).toInt();

    return true;
}

//-----------------------------------Afficher_Les_Box------------------------------------
// Affichage de tous les box contenus dans la table box.
// Changement de methode :
// - On ne detruit plus tous les box pour les recreer.
// - On actualise les box existants (effacement des infos patients uniquement)
void MainWindow::Afficher_Les_Box()
{
    int nubox = 0;          // BUGBUG

    m_DernierPkencours         = 0;
    m_DernierPkencours_taches  = 0;
    m_ListePositions.clear();
    QString requete = "SELECT BO_Code, BO_Libelle, BO_CouleurBG, BO_CouleurTitre, BO_Nb_Maxi_Pat, BO_Type  FROM " BOX;
    QSqlQuery query(requete, DATA_BASE_SYNOPTUX);
    while (query.isActive() &&  query.next())
        { // au premier affichage, on cree les box et on stocke les pointeurs
        // DEB BUGBUG
        if (m_pC_Wdg_Box[nubox] == 0)
            {m_pC_Wdg_Box[nubox] = newBox(query.value(0).toString(),query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), query.value(4).toString(), query.value(5).toString());
            RemplirLeBox(m_pC_Wdg_Box[nubox], query.value(0).toString());
            }
        else // ensuite on reutilise les pointeurs sur les box existants.
            {ActualiserUnBox(m_pC_Wdg_Box[nubox]);
            }
        nubox ++;
        // FIN BUGBUG

        // TEST BUG C_Wdg_Box *pC_Wdg_Box = newBox(query.value(0).toString(),query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), query.value(4).toString(), query.value(5).toString());
        // TEST BUG RemplirLeBox(pC_Wdg_Box, query.value(0).toString());
        } // fin while table box

}
//-----------------------------------newBox------------------------------------------------------
// Cree une subWindow par box
C_Wdg_Box *MainWindow::newBox(QString codeBox, QString nomBox, QString couleurBox, QString couleurTitre, QString nbMaxiPat, QString typeBox)
{
    // C_Wdg_Box *pC_Wdg_Box = new C_Wdg_Box (this); TEST BUG
    C_Wdg_Box *pC_Wdg_Box = new C_Wdg_Box (m_mdiArea);
    Ui_Box       *pUi_Box = pC_Wdg_Box->ui;
    pUi_Box->label_BoxEnCours->setVisible(false);
    pUi_Box->label_Nb_Patients_Maxi->setVisible(false);
    pUi_Box->label_Nb_Patients_dans_Box->setVisible(false);
    pC_Wdg_Box->setAttribute(Qt::WA_DeleteOnClose);

    // formatage de la fenetre box
    pC_Wdg_Box->setWindowTitle(nomBox);
    pC_Wdg_Box->setMinimumSize(m_Largeur_Box, m_Hauteur_Box);
    pC_Wdg_Box->setObjectName(nomBox);
    pC_Wdg_Box->setAutoFillBackground(false);
    pC_Wdg_Box->setAccessibleDescription(typeBox);

    if (m_ModeAffichage == "Fenetre")
        m_mdiArea->addSubWindow(pC_Wdg_Box, Qt::SubWindow);
    else
        m_mdiArea->addSubWindow(pC_Wdg_Box, Qt::FramelessWindowHint);

    m_mdiArea->currentSubWindow()->setAccessibleName(codeBox);
    pUi_Box->scrollArea_Box->verticalScrollBar()->setStyleSheet(RecupStyle("Box_ScrollBar"));
    AppliquerUnStyle("A", pUi_Box->scrollArea_Box, "Box" , couleurBox);

    // Nom du box
    pUi_Box->pushButton_NomBox->setText(nomBox);
    pUi_Box->pushButton_NomBox->setMinimumHeight(m_Hauteur_NomBox);
    pUi_Box->pushButton_NomBox->setMinimumWidth(m_Largeur_Box);
    pUi_Box->label_BoxEnCours->setText(codeBox);
    pUi_Box->label_Nb_Patients_Maxi->setText(nbMaxiPat);
    // connexion pour la rentrer des patients sur toucher du nom
    connect(pUi_Box->pushButton_NomBox, SIGNAL(clicked()), m_BoxMapper, SLOT(map()));
    m_BoxMapper->setMapping(pUi_Box->pushButton_NomBox, pC_Wdg_Box);
    AppliquerUnStyle("B",pUi_Box->pushButton_NomBox, "Titre_Box" , couleurTitre);

    // inutile car la scrollarea masque completement le fond du box.
    QPalette palette =  pC_Wdg_Box->palette();
    palette.setColor(QPalette::Background, QColor(couleurBox));
    m_mdiArea->currentSubWindow()->setPalette(palette);

    // Repositionnement du Box avec les valeurs stockees dans .ini
    //m_settingsIni->beginGroup("Positions_Fenetres");
    QPoint pos  = m_settingsIni->value("Positions_Fenetres/Pos_"  + codeBox,  QPoint(100, 100)).toPoint();
    QSize  size = m_settingsIni->value("Positions_Fenetres/Size_" + codeBox,  QSize(250, 350)).toSize();
    //-------------------  test de mise en page ----deb  a virer ------------
    m_OnColleTout = false;
    if (m_OnColleTout)
       {
        // on essaie de coller la nelle fenetre a la fen la plus proche.
        for (int i=0; i < m_ListePositions.size(); i++)
            {
             if ((pos.x() > m_ListePositions.at(i)) && (pos.x() - m_ListePositions.at(i)) < 50 )
                 pos.setX( m_ListePositions.at(i) + 1);
            }
       }
    m_ListePositions << pos.x() + size.width();
    //---------------------- fin  a virer ---------------------
    m_mdiArea->currentSubWindow()->move(pos);
    m_mdiArea->currentSubWindow()->resize(size);
    return pC_Wdg_Box;
}
//-------------------------------------RemplirLeBox--------------------------------------
void MainWindow::RemplirLeBox(C_Wdg_Box *dlgBox, QString BoxEnCours)
{   setTimerActionOff();
    Ui_Box *pUi_Box = dlgBox->ui;

    // Recherche des patients occupants les box dans la table encours
    QString requeteEnCours = " SELECT EC_PK, EC_CodeBox, EC_NomPatient, EC_HeureEntree,"     // 0-1-2-3
                             " EC_Medecin, EC_Replier, EC_HeureSortie, EC_PrenomPatient, "  // 4-5-6-7
                             " EC_Commentaire, EC_Destination, EC_Anonyme "                 // 8-9-10
                             " FROM "ENCOURS" WHERE EC_CodeBox = '" + BoxEnCours + "'";
    if (m_ResponsableSelectionne != "Tous")
        requeteEnCours.append(" AND EC_Medecin = '" + m_ResponsableSelectionne + "'");

    QSqlQuery queryb(requeteEnCours, DATA_BASE_SYNOPTUX);
    while (queryb.isActive() &&  queryb.next())
        {
        QString numEnCours      = queryb.value(0).toString();
        QString nomPatient      = queryb.value(2).toString() + " " + queryb.value(7).toString();
        QString heureEntree     = queryb.value(3).toString();
        QString medecin         = queryb.value(4).toString();
        bool    statusReplier   = queryb.value(5).toBool();
        QString heureSortie     = queryb.value(6).toString().replace("T"," ");
        QString commentairePat  = queryb.value(8).toString();
        QString destination     = queryb.value(9).toString();
        bool    anonyme         = queryb.value(10).toBool();

        // On supprime les encours sortis depuis plus de x minutes (selon parametrage)
        if (heureSortie > "2000-00-00"  &&
            QDateTime::currentDateTime().operator >(QDateTime::fromString(heureSortie,"yyyy-MM-dd hh:mm:ss").addSecs(m_DelaiDeSortie * 60)))
            SortirLePatient(numEnCours);

        if (commentairePat.length() > 0 && destination.length() > 0)
            commentairePat.append(" - ");
        commentairePat.append(queryb.value(9).toString());
        //RemplirLeBox(m_dlgBox, BoxEnCours, numEnCours, nomPatient, heureEntree, heureSortie, medecin, statusReplier, commentairePat, anonyme);
        // on garde le dernier encours pour surveiller si une nelle entree et rafraichir
        if (m_DernierPkencours < numEnCours.toInt())
            m_DernierPkencours = numEnCours.toInt();

    // stockage des infos de base pour gestion
    pUi_Box->label_Nb_Patients_dans_Box->setText(QString::number(pUi_Box->label_Nb_Patients_dans_Box->text().toInt() + 1));

    // Nom Patient
    afficheNomPatient(dlgBox, pUi_Box, nomPatient, BoxEnCours, numEnCours, heureEntree, heureSortie, commentairePat, anonyme, statusReplier);

    // Nom Medecin
    afficheNomMedecin(dlgBox, BoxEnCours, numEnCours, statusReplier, medecin );

    // Affichage des taches en cours dans ce Box
    AfficherLesTaches(dlgBox, BoxEnCours, numEnCours, statusReplier );

    } // fin while table Encours
    setTimerActionOn();
}
void MainWindow::tilerLesW()
{
    m_mdiArea->setActivationOrder(QMdiArea::CreationOrder);
    m_mdiArea->tileSubWindows();
}
//---------------------------------------AfficherLesTaches-------------------------------------------------
// Affichage des taches en cours dans ce Box
// Deux possibilites selon parametre dans tache :
// - un bouton par etat (limite a 3 boutons)
// - un bouton etat avec un menu pour selectionner l'etat.
void MainWindow::AfficherLesTaches(C_Wdg_Box *dlgBox, QString /*codeBox*/, QString numEnCours, bool statusReplier )
{
 setTimerActionOff();
 QString requete, requeteEtat, style, dernierEtat;
 bool    boolTache;
 bool    premierEtat = false;
 QColor  qCouleurTache;

//  On affiche en priorite les taches non terminees, par ordre de priorite, par heure de debut prevue
    requete  = " SELECT EN_Num_tache, EN_Code_tache, EN_Comment, EN_Etat_en_cours, "         // 0-1-2-3
               " TA_Libelle_tache, TA_Couleur_tache, TA_Duree_maxi, TA_Couleur_alarme, "     // 4-5-6-7
               " TA_BoutonMenu, EN_HeureDebPrevue, EN_HeureFinPrevue, "                      // 8-9-10
               " EN_HeureDebut, EN_HeureFin, EN_Priorite, EN_Note_tache, "                   // 11-12-13-14
               " EN_PrimKey_blob, EN_NomFicNote "
               " FROM "ENCOURS_TACHES
               " INNER JOIN "TACHES" ON EN_Code_tache = TA_Code_tache "
               " WHERE EN_PK_encours = " + numEnCours +
               " ORDER BY  EN_HeureFin, EN_Priorite, EN_HeureDebPrevue";
    QSqlQuery query(requete, DATA_BASE_SYNOPTUX);
    while (query.isActive() &&  query.next())
        {
        QString codeTache   = query.value(1).toString();
        QString numTache    = query.value(0).toString();
        QString boutonMenu  = query.value(8).toString();
        QString etatEnCours = query.value(3).toString();
        if (m_DernierPkencours_taches < numTache.toInt())
            m_DernierPkencours_taches = numTache.toInt();

        QHBoxLayout *horizonLayoutTache   = new QHBoxLayout();   // pour le nom de la tache + les etats
        // QHBoxLayout *horizonLayoutTache   = new QHBoxLayout(dlgBox);  // BUGBUG // pour le nom de la tache + les etats
        horizonLayoutTache->setObjectName(dlgBox->objectName()+"-"+"horizonLayoutTache");
        // bouton annulation de tach
        QPushButton *bouttonAnnuleTache   = new QPushButton(dlgBox);    // annule-tache

        bouttonAnnuleTache->setIcon(QIcon(":/images/Annule_Tache.png"));
        qCouleurTache = QColor(query.value(5).toString());
        bouttonAnnuleTache->setMinimumHeight(m_Hauteur_Taches);
        bouttonAnnuleTache->setMinimumWidth(m_Largeur_Annule_Tache);
        bouttonAnnuleTache->setMaximumWidth(m_Largeur_Annule_Tache);
        bouttonAnnuleTache->setWhatsThis(numEnCours + "/" + numTache);
        bouttonAnnuleTache->setObjectName(dlgBox->objectName()+"-BouttonAnnuleTache");
        bouttonAnnuleTache->setAccessibleName(codeTache);
        if (statusReplier) bouttonAnnuleTache->setVisible(false);

        connect(bouttonAnnuleTache, SIGNAL(clicked()), m_AnnuleTacheMapper, SLOT(map()));
        m_AnnuleTacheMapper->setMapping(bouttonAnnuleTache, bouttonAnnuleTache);
        AppliquerUnStyle("B",bouttonAnnuleTache, "Bouton_Annule_Tache" , query.value(5).toString());
        horizonLayoutTache->addWidget(bouttonAnnuleTache);

        // Affiche le nom de la tache
        QPushButton *bouttonNomTache      = new QPushButton(query.value(4).toString(),dlgBox);    // libelle-tache
        if (query.value(2).toString().length() > 0)
            bouttonNomTache->setText(query.value(4).toString() + "\n" + query.value(2).toString());
        //s'il y a une note disponible on ajoute un icone.
       if ( query.value(14).toString().length() > 0 ||       // il y a une note dans l'encours
            query.value(15).toInt() > 0             ||       // il y a une cle de blob
            query.value(16).toString().length() > 0 )       // il y a un fichier PDF a lire
            bouttonNomTache->setIcon(QIcon(":/images/oeil.png"));
        qCouleurTache = QColor(query.value(5).toString());
        bouttonNomTache->setMinimumHeight(m_Hauteur_Taches);
        bouttonNomTache->setMinimumWidth(m_Largeur_Tache);
        bouttonNomTache->setWhatsThis(numEnCours + "/" + numTache);
        bouttonNomTache->setObjectName(dlgBox->objectName()+"-BouttonNomTache");
        bouttonNomTache->setAccessibleName(codeTache);
        bouttonNomTache->setAccessibleDescription(query.value(5).toString() + "/" +  // couleur orig
                                                  query.value(7).toString() + "/" +  // couleur alarme
                                                  query.value(6).toString());        // duree maxi
        if (statusReplier) bouttonNomTache->setVisible(false);
        connect(bouttonNomTache, SIGNAL(clicked()), m_TacheMapper, SLOT(map()));
        m_TacheMapper->setMapping(bouttonNomTache, bouttonNomTache);
        AppliquerUnStyle("B",bouttonNomTache, "Bouton_Nom_Tache" , query.value(5).toString());
        horizonLayoutTache->addWidget(bouttonNomTache);

        // Recherche des etats possibles de la tache en cours et creation de boutons
        int nbBouton = 0;
        dernierEtat  = "N";
        premierEtat  = false;
        QString couleurDefaut = "#FFFFFF";
        requeteEtat  = " SELECT ET_Libelle_etat, ET_Couleur_etat , ET_Tache_terminee"    // 0-1-2
                       " FROM " ETATS
                       " INNER JOIN "ETATS_TACHES" ON ST_Code_etat = ET_Code_etat "
                       " WHERE ST_Code_tache = '" + codeTache + "'"
                       " ORDER BY ST_Code_Etat";
        QSqlQuery queryb(requeteEtat, DATA_BASE_SYNOPTUX);
        boolTache =  queryb.isActive() &&  queryb.next();

        while ( boolTache || (nbBouton < 3 && boutonMenu == "B") )  //BUGBUG
            {
            nbBouton ++;
            if (boutonMenu == "B")
                { // on cree un bouton par etat.
                QPushButton *bouttonEtatTache      = new QPushButton(dlgBox);
                bouttonEtatTache->setObjectName(dlgBox->objectName()+"-bouttonEtatTache"); // BUGBUG
                //QString     nomEtatTache = "";
                //if (NbBouton == queryb.size())
                if (boolTache && queryb.value(2).toBool())        // c'est un etat qui termine la tache
                    dernierEtat = "O";

                bouttonEtatTache->setMinimumHeight(m_Hauteur_Taches);
                bouttonEtatTache->setMaximumWidth((m_Largeur_Box - m_Largeur_Tache ) / 3);
               // bouttonEtatTache->setAccessibleName(numEnCours + "/" + codeTache + "/" + numTache + "/" + boutonMenu + "/" + dernierEtat  + "/" + queryb.value(1).toString()); // BUGBUG

                bouttonEtatTache->setWhatsThis(numEnCours);
                if (statusReplier) bouttonEtatTache->setVisible(false);
                style = "Bouton_Etat_Tache";
                if (boolTache)
                   {
                   bouttonEtatTache->setAccessibleName(numEnCours + "/" + codeTache + "/" + numTache + "/" + boutonMenu + "/" + dernierEtat  + "/" + queryb.value(1).toString()); // BUGBUG
                   couleurDefaut = queryb.value(1).toString();
                   bouttonEtatTache->setText(queryb.value(0).toString());
                   if (queryb.value(0).toString() == etatEnCours) // ???
                     //  BoutonOpaque(BouttonEtatTache, 0, couleurDefaut);
                        style = "Bouton_Etat_Tache_EnCours";
                   connect(bouttonEtatTache, SIGNAL(clicked()), m_EtatMapper, SLOT(map()));
                   m_EtatMapper->setMapping(bouttonEtatTache, bouttonEtatTache);
                   }
                AppliquerUnStyle("B",bouttonEtatTache, style , couleurDefaut);
                horizonLayoutTache->addWidget(bouttonEtatTache);
                } // fin if boutons

            else // on gere les etats par un menu. On cree un bouton unique qui appelera le menu.
                {// ce bouton reprend le libelle de l'etat en cours au moment de l'affichage.
                style = "Menu_Etat_Tache_EnCours";
                if (etatEnCours.length() < 1)
                    {premierEtat = true;
                     etatEnCours = queryb.value(0).toString();
                     style = "Menu_Etat_Tache";
                    }
                if (etatEnCours == queryb.value(0).toString())
                    {
                    QPushButton *bouttonEtatTache      = new QPushButton(etatEnCours,dlgBox);
                    bouttonEtatTache->setObjectName(dlgBox->objectName()+"-bouttonEtatTache"); // BUGBUG

                    bouttonEtatTache->setAccessibleName(numEnCours + "/" + codeTache + "/" + numTache + "/" + boutonMenu + "/" + dernierEtat + "/" + queryb.value(1).toString());
                    bouttonEtatTache->setWhatsThis(numEnCours);
                    if (statusReplier) bouttonEtatTache->setVisible(false);
                    bouttonEtatTache->setMinimumHeight(m_Hauteur_Taches);
                    bouttonEtatTache->setMaximumWidth((m_Largeur_Box - m_Largeur_Tache )); // ???
                   // if (premierEtat) BoutonOpaque(BouttonEtatTache, 1, queryb.value(1).toString());
                    connect(bouttonEtatTache, SIGNAL(clicked()), m_EtatMapper, SLOT(map()));
                    m_EtatMapper->setMapping(bouttonEtatTache, bouttonEtatTache);
                    horizonLayoutTache->addWidget(bouttonEtatTache);
                    AppliquerUnStyle("B",bouttonEtatTache, style , queryb.value(1).toString());
                    }
                } // fin else menu
            boolTache =  queryb.isActive() &&  queryb.next();
            } // fin while y'a des etats
        // ajout de la tache et de ses boutons etats dans le box
        dlgBox->ui->verticalLayout_patients->addLayout(horizonLayoutTache);
        } // fin while table Encours_taches
    setTimerActionOn();
}
//-------------------------------AppliquerUnStyle-------------------------------------------------------
void MainWindow::AppliquerUnStyle(QString /*TypeDeTruc */, QWidget *Letruc, QString NomDuStyle, QString LaCouleurDuTruc)
{   setTimerActionOff();
    QString Style;
    Style = "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0"
    + LaCouleurDuTruc + ", stop: 1 " + QColor(LaCouleurDuTruc).lighter(180).name() + ");";
    Style.append( RecupStyle(NomDuStyle));
    Letruc->setStyleSheet(Style);
    setTimerActionOn();
}

//----------------------------------- Slot_pushButton_Apropos_clicked -----------------------------------------------------------------------
void MainWindow::Slot_pushButton_Apropos_clicked()
{        C_Dlg_Changements *dlg = new C_Dlg_Changements(this);
         if (dlg==0) return;
         CGestIni::Param_UpdateToDisk(CApp::pCApp()->pathAppli()+"Ressources/Changements.html", dlg->getText());
         QString pathExeAPropos     = CGestIni::Construct_Name_Exe("APropos", QFileInfo (qApp->argv()[0]).path());
         QString pathBinRessources  = CGestIni::Construct_PathBin_Module("APropos", QFileInfo (qApp->argv()[0]).path())+"Ressources/";
         QStringList argList;
         QProcess::ProcessState procState;
         //......................... completer les autres arguments .........................................
         argList << NAME_APPLI;                                                                                  // 1  nom du module
         argList << tr("Synoptique des actions en cours");                                                       // 2  description courte
         argList << CApp::pCApp()->applicationVersion() + "  Qt : " + QT_VERSION_STR;                            // 3  numero de version
         argList << CApp::pCApp()->pathAppli()+"Ressources/Changements.html";                                    // 4  fichiers decrivant les changements
         if (m_Apropos_Proc==0)
            {m_Apropos_Proc = new QProcess(this);
             m_Apropos_Proc->start(pathExeAPropos, argList);
             SLEEP(1);
             CApp::pCApp()->processEvents ();
             while ( (procState = m_Apropos_Proc->state())== QProcess::Running )
                   { QApplication::processEvents ( QEventLoop::WaitForMoreEvents );
                   }
             if (m_Apropos_Proc) delete m_Apropos_Proc;
             m_Apropos_Proc = 0;
             QFile::remove(pathBinRessources+"~A_propos.html");
            }
         delete dlg;
}
//----------------------------------creerActionsGene-----------------------------------------
// Creation des actions du menu principal
void MainWindow::creerActionsGene()
{
    m_boxAct = new QAction(QIcon(":/images/Box.png"), tr("&Box"), this);
    m_boxAct->setStatusTip(tr("Gestion des box"));
    connect(m_boxAct, SIGNAL(triggered()), this, SLOT(GestionBox()));

    m_tacheAct = new QAction(QIcon(":/images/Tache.png"), tr("&T\303\242ches"), this);
    m_tacheAct->setStatusTip(tr("Gestion des t\303\242ches"));
    connect(m_tacheAct, SIGNAL(triggered()), this, SLOT(GestionTaches()));

    m_etatAct = new QAction(QIcon(":/images/Etat.png"), tr("&Etats"), this);
    m_etatAct->setStatusTip(tr("Gestion des \303\251tats"));
    connect(m_etatAct, SIGNAL(triggered()), this, SLOT(GestionEtats()));

    m_respAct = new QAction(QIcon(":/images/Resp.png"), tr("&Responsables"), this);
    m_respAct->setStatusTip(tr("Gestion des responsables"));
    connect(m_respAct, SIGNAL(triggered()), this, SLOT(GestionResponsables()));

    m_cssAct = new QAction(QIcon(":/images/css.png"), tr("&Mise en forme (css)"), this);
    m_cssAct->setStatusTip(tr("Modification de la mise en forme (.css)"));
    connect(m_cssAct, SIGNAL(triggered()), this, SLOT(GestionCSS()));

    m_iniAct = new QAction(QIcon(":/images/ini.png"), tr("&Param\303\250trages (ini)"), this);
    m_iniAct->setStatusTip(tr("Param\303\250tres g\303\251n\303\251raux (.ini)"));
    connect(m_iniAct, SIGNAL(triggered()), this, SLOT(GestionINI()));


    m_sortieAct = new QAction(QIcon(":/images/Maison.png"), tr("Destinations de sorties"), this);
    m_sortieAct->setStatusTip(tr("Destinations de sorties"));
    connect(m_sortieAct, SIGNAL(triggered()), this, SLOT(GestionDestinationsSortie()));

    m_absenceAct = new QAction(QIcon(":/images/Absence.png"), tr("Destinations des absences"), this);
    m_absenceAct->setStatusTip(tr("Destinations des absences"));
    connect(m_absenceAct, SIGNAL(triggered()), this, SLOT(GestionDestinationsAbsence()));

    m_exitAct = new QAction(tr("&Quitter"), this);
    m_exitAct->setShortcuts(QKeySequence::Quit);
    m_exitAct->setStatusTip(tr("Quitter l'application"));
    connect(m_exitAct, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));

    m_RestaureBaseAct = new QAction(tr("&Restaurer la base"), this);
    QList<QKeySequence> lst; lst.append(QKeySequence(Qt::CTRL + Qt::Key_K));
    m_RestaureBaseAct->setShortcuts( lst);
    m_RestaureBaseAct->setStatusTip(tr("Restaure la base de donn\303\251es \303\240 partir d'un fichier SQL"));
    connect(m_RestaureBaseAct, SIGNAL(triggered()), this, SLOT(RestaureBase()));

    m_PosAct = new QAction(QIcon(":/images/enregistre.png"), tr("Enregistrer la position"), this);
    m_PosAct->setStatusTip(tr("Enregistrer la position des fen\303\252tres"));
    connect(m_PosAct, SIGNAL(triggered()), this, SLOT(Enregistrer_Positions()));

    m_ReafficherFenAct = new QAction(QIcon(":/images/fenetre.png"), tr("&Affichage mode fen\303\252tre"), this);
    m_ReafficherFenAct->setStatusTip(tr("R\303\251afficher en mode fen\303\252tre"));
    connect(m_ReafficherFenAct, SIGNAL(triggered()), this, SLOT(ActualiserFen()));

    m_ReafficherCadAct = new QAction(QIcon(":/images/carre.png"), tr("&Affichage mode cadre"), this);
    m_ReafficherCadAct->setStatusTip(tr("R\303\251afficher en mode fen\303\252tre"));
    connect(m_ReafficherCadAct, SIGNAL(triggered()), this, SLOT(ActualiserCad()));

    m_separatorAct = new QAction(this);
    m_separatorAct->setSeparator(true);

    m_aboutAct = new QAction(tr("&A propos"), this);
    m_aboutAct->setStatusTip(tr("A propos de l'application"));
    connect(m_aboutAct, SIGNAL(triggered()), this, SLOT(Slot_pushButton_Apropos_clicked()));
}

//---------------------------------RestaureBase----------------------------------------
// Creation actions pour la m_mdiArea
void MainWindow::RestaureBase()
{QString fileName =  QFileDialog::getOpenFileName ( this, tr("Choix d'un fichier Sql \303\240 restaurer"), CApp::pCApp()->pathAppli()+"Ressources", tr("Fichiers Sql (*.SQL *.sql *.Sql)"));
 if (fileName.length())
    {int ret = QMessageBox::question(0,NAME_APPLI,tr("Voulez-vous vraiment restaurer ce fichier en sachant que cela \303\251crasera toutes les donn\303\251es d\303\251j\303\240 saisies?"),"OUI","NON",0,1,1);
     if (ret == 0)
     CApp::pCApp()->getDB()->executeSQL(fileName, 0, 0);
    }
}

//---------------------------------creerActionsMdi----------------------------------------
// Creation actions pour la m_mdiArea
void MainWindow::creerActionsMdi()
{
    m_tileAct = new QAction(tr("&Tile"), this);
    m_tileAct->setStatusTip(tr("Tile the windows"));
    connect(m_tileAct, SIGNAL(triggered()), this, SLOT(tilerLesW()));

    m_cascadeAct = new QAction(tr("&Cascade"), this);
    m_cascadeAct->setStatusTip(tr("Cascade the windows"));
    connect(m_cascadeAct, SIGNAL(triggered()), m_mdiArea, SLOT(cascadeSubWindows()));
}

//----------------------------------creerMenuSelectionResponsable-----------------------------------------
// Creation d'un menu pour n'afficher que les encours d'un responsable
void MainWindow::creerMenuSelectionResponsable()
{
   QAction *actResp;
   QString strResp;

   m_SelectionResponsable = menuBar()->addMenu(tr("&Responsables"));
   strResp = "Tous/Tous les m\303\241decins/#ffffff";
   actResp = new QAction("Tous", this);
   connect(actResp, SIGNAL(triggered()), m_MenuSelectionRespMapper, SLOT(map()));
   m_MenuSelectionRespMapper->setMapping(actResp, strResp);
   m_SelectionResponsable->addAction(actResp);

   QSqlQuery queryb(makeRequeteMedResponsable(), DATA_BASE_SYNOPTUX);
   while (queryb.isActive() &&  queryb.next())
       {
       strResp = queryb.value(0).toString() + "/" + queryb.value(1).toString()+ "/" + queryb.value(2).toString();
       actResp = new QAction(queryb.value(1).toString(), this);
       connect(actResp, SIGNAL(triggered()), m_MenuSelectionRespMapper, SLOT(map()));
       m_MenuSelectionRespMapper->setMapping(actResp, strResp);
       m_SelectionResponsable->addAction(actResp);
       } // fin while etat
   m_SelectionResponsable->setStyleSheet(RecupStyle("Menu_Responsables"));
}
//---------------------------------creerMenusGene--------------------------------------------------------
void MainWindow::creerMenusGene()
{
    m_fileMenu = menuBar()->addMenu(tr("&Fichiers"));
    m_fileMenu->addAction(m_boxAct);
    m_fileMenu->addAction(m_tacheAct);
    m_fileMenu->addAction(m_etatAct);
    m_fileMenu->addAction(m_respAct);
    m_fileMenu->addAction(m_sortieAct);
    m_fileMenu->addAction(m_absenceAct);
    m_fileMenu->addSeparator();
    m_fileMenu->addAction(m_iniAct);
    m_fileMenu->addAction(m_cssAct);
    m_fileMenu->addSeparator();
    m_fileMenu->addAction(m_RestaureBaseAct);
    m_fileMenu->addSeparator();
    m_fileMenu->addAction(m_exitAct);
}
//-------------------------------------creerMenusMdi---------------------------------------
void MainWindow::creerMenusMdi()
{
    m_windowMenu = menuBar()->addMenu(tr("&Fen\303\252tres"));
    m_windowMenu->addAction(m_PosAct);
    m_windowMenu->addAction(m_ReafficherCadAct);
    m_windowMenu->addAction(m_ReafficherFenAct);
   // m_windowMenu->addAction(m_cascadeAct);        // ne marche pas si on force les positions
   // m_windowMenu->addAction(m_tileAct);           // ne sert a rien
}
//-------------------------------------createToolBars-----------------------------------------------
void MainWindow::createToolBars()
{
 //   m_fileToolBar = addToolBar(tr("Fichiers"));
}
//-------------------------------------createStatusBar-----------------------------------------------------
void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr(""));
}
//---------------------------------ActualiserFen------------------------------------------------
// Reafficher toute en mode fenetre
void MainWindow::ActualiserFen()
{   m_ModeAffichage = "Fenetre";
    Actualiser("TOTAL");
}
//---------------------------------ActualiserCad------------------------------------------------
// Reafficher toute en mode fenetre
void MainWindow::ActualiserCad()
{   m_ModeAffichage = "Cadre";
    Actualiser("TOTAL");
}
//---------------------------------Actualiser------------------------------------------------
// Reafficher toute la fenetre
void MainWindow::Actualiser(QString partielOUtotal)             // BUGBUG
{   setTimerActionOff();
    // Arret des timers
    if (m_timerClignote  != 0 && m_timerClignote->isActive())   m_timerClignote->stop();
    if (m_timerAlarme    != 0 && m_timerAlarme->isActive())     m_timerAlarme->stop();
    m_ListeBoutonsAlarme.clear();
    m_BoutonBougerEnCours = 0;
    m_BoxBougerEnCours    = 0;
    m_BoxEnCours          = "";
qDebug() << "PASSE ACTUALISER";
    if (partielOUtotal == "TOTAL")
        {
        for (int i = 0; i < NB_BOX_MAX; i++) m_pC_Wdg_Box[i] = 0;
        m_mdiArea->closeAllSubWindows();
        delete(m_mdiArea);
        m_mdiArea = new QMdiArea(this);
        m_mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        m_mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        setCentralWidget(m_mdiArea);
        Recuperer_Positions();
        }

    Afficher_Les_Box();
    m_timerAlarme->start();
    setTimerActionOn();
}
//---------------------------------ActualiserUnBox------------------------------------------------
//
void MainWindow::ActualiserUnBox(C_Wdg_Box *LeBox)
{   setTimerActionOff();
    // Arret des timers
    if (m_timerClignote != 0 && m_timerClignote->isActive())   m_timerClignote->stop();
    if (m_timerAlarme   != 0 && m_timerAlarme->isActive())     m_timerAlarme->stop();
    m_ListeBoutonsAlarme.clear();

    // On vire d'abord les layouts
    QList<QLayout *> listeLayouts = LeBox->ui->scrollAreaWidgetContents_box->findChildren<QLayout *>(); // BUGBUG

    for (int i=0; i< listeLayouts.size(); i++)
        { // On vire les layout superieurs , les autres layouts  sont vires par Qt
         if (listeLayouts.at(i)->objectName().left(LeBox->objectName().length()) != LeBox->objectName())
             continue; // BUGBUG
         if (listeLayouts.at(i)->objectName().contains("verticalLayoutPatCom") ||
             listeLayouts.at(i)->objectName().contains("horizonLayoutTache") ||
             listeLayouts.at(i)->objectName().contains("verticalLayoutPatCom") ||
             listeLayouts.at(i)->objectName().contains("horizonLayoutResp") )
            {
            delete listeLayouts.at(i);
            listeLayouts = LeBox->ui->scrollAreaWidgetContents_box->findChildren<QLayout *>();
            i = 0;
            }
        }

    QList<QObject *> listeWidgets = LeBox->ui->scrollAreaWidgetContents_box->findChildren<QObject *>(); // BUGBUG

    for (int i=0; i< listeWidgets.size(); i++)
        { // on ne garde que les objets lies au box. On vire ce qui est lie a un encours
        if (listeWidgets.at(i)->objectName().contains("label_Nb_Patients_dans_Box"))
           {LeBox->ui->label_Nb_Patients_dans_Box->setText("");
            continue;
           }
        if (listeWidgets.at(i)->objectName().left(LeBox->objectName().length()) != LeBox->objectName())
             continue; // BUGBUG
         /* BUGBUG
         if (listeWidgets.at(i)->objectName() == "pushButton_NomBox")    continue;
         if (listeWidgets.at(i)->objectName() == "label_BoxEnCours")  continue;
         if (listeWidgets.at(i)->objectName() == "label_Nb_Patients_Maxi") continue;
         BUGBUG */

         delete listeWidgets.at(i);
        }
    RemplirLeBox(LeBox, LeBox->ui->label_BoxEnCours->text());
    m_timerAlarme->start();
    setTimerActionOn();
}
//---------------------------------------GestionBox-----------------------------------------------
void MainWindow::GestionBox()
{
    DlgBox *dlg = new DlgBox(this);
    if(dlg==0) return;
    dlg->ChargeBox();
    dlg->exec();
    delete dlg;
}
//---------------------------------------GestionTaches---------------------------------------------------
void MainWindow::GestionTaches()
{
    DlgTache *dlg = new DlgTache(this);
    if(dlg==0) return;
    dlg->ChargeTache();
    dlg->exec();
    delete dlg;
}
//------------------------------------GestionEtats---------------------------------------------------
void MainWindow::GestionEtats()
{
    DlgEtat *dlg = new DlgEtat(this);
    if (dlg==0) return;
    dlg->ChargeEtat();
    dlg->exec();
    delete dlg;
}
//------------------------------------GestionResponsables-----------------------------------------------
void MainWindow::GestionResponsables()
{
    DlgResp* dlg = new DlgResp(this);
    if (dlg==0) return;
    dlg->ChargeResp();
    dlg->exec();
    delete dlg;
}
//----------------------------------GestionCSS--------------------------------------------------
void MainWindow::GestionCSS()
{    GestionParam("CSS");
}
//----------------------------------GestionINI--------------------------------------------------
void MainWindow::GestionINI()
{    GestionParam("INI");
}
//----------------------------------GestionParam--------------------------------------------------
void MainWindow::GestionParam(QString typeParam)
{
    DlgParam *dlg = new DlgParam(this);
    if (dlg ==0) return;
    dlg->ChargeParam(typeParam);
    dlg->exec();
    RecupInit();
    LireleCSS();
    Actualiser("TOTAL");
    delete dlg;
}

//------------------------------afficheNomPatient--------------------------------------------
void MainWindow::afficheNomPatient(C_Wdg_Box *dlgBox, Ui_Box *Box_ui, QString NomPatient, QString /*BoxEnCours*/, QString NumEnCours, QString DateEntree, QString DateSortie, QString CommentairePatient, bool Anonyme, bool StatusReplier )
{
    setTimerActionOff();
    QString style;
    QVBoxLayout *verticalLayoutPatCom   = new QVBoxLayout();
    // QVBoxLayout *verticalLayoutPatCom   = new QVBoxLayout(dlgBox); // BUGBUG
    verticalLayoutPatCom->setObjectName(dlgBox->objectName()+"-verticalLayoutPatCom");
    QHBoxLayout *horizonLayoutPat       = new QHBoxLayout();
    // QHBoxLayout *horizonLayoutPat       = new QHBoxLayout(dlgBox); // BUGBUG
    horizonLayoutPat->setObjectName(dlgBox->objectName()+"-horizonLayoutPat");

    // Creation du Bouton PlierDeplier
    QPushButton *bouttonPlierDeplier    = new QPushButton(dlgBox);
        if (StatusReplier )
        bouttonPlierDeplier->setIcon(QIcon(":/images/1downarrow.png"));
    else
        bouttonPlierDeplier->setIcon(QIcon(":/images/1rightarrow.png"));
    bouttonPlierDeplier->setAccessibleDescription(NomPatient);
    bouttonPlierDeplier->setObjectName(dlgBox->objectName()+"-BouttonPlierDeplier"); // BUGBUG
    bouttonPlierDeplier->setWhatsThis(NumEnCours);
    bouttonPlierDeplier->setMinimumHeight(m_Hauteur_Patients);
    bouttonPlierDeplier->setMinimumWidth(m_Largeur_Boutons);
    bouttonPlierDeplier->setMaximumWidth(m_Largeur_Boutons);
    AppliquerUnStyle("B",bouttonPlierDeplier, "Bouton_Plier_Deplier" , m_Couleur_Patients);
    connect(bouttonPlierDeplier, SIGNAL(clicked()), m_ReplierMapper, SLOT(map()));
    m_ReplierMapper->setMapping(bouttonPlierDeplier, bouttonPlierDeplier);
    horizonLayoutPat->addWidget(bouttonPlierDeplier);

    // Creation du Bouton nom du Patient
    QPushButton *bouttonNomPatient      = new QPushButton(NomPatient, dlgBox);
    if (Anonyme) bouttonNomPatient->setText("Anonyme");

    bouttonNomPatient->setAccessibleDescription(NomPatient);
    bouttonNomPatient->setObjectName(dlgBox->objectName()+ "-BouttonNomPatient"); // BUGBUG
    bouttonNomPatient->setWhatsThis(NumEnCours);
    bouttonNomPatient->setMinimumHeight(m_Hauteur_Patients);
    AppliquerUnStyle("B",bouttonNomPatient, "Bouton_Nom_Patient" , m_Couleur_Patients);

    connect(bouttonNomPatient, SIGNAL(clicked()), m_PatientMapper, SLOT(map()));
    m_PatientMapper->setMapping(bouttonNomPatient, bouttonNomPatient);
    horizonLayoutPat->addWidget(bouttonNomPatient);

    // Creation Label Heure de rentree et heure de sortie.
    QVBoxLayout *verticaLayoutHeure   = new QVBoxLayout();
    verticaLayoutHeure->setObjectName(dlgBox->objectName()+"-verticaLayoutHeure");
    QLabel *label_HeureE = new QLabel(dlgBox);
    label_HeureE->setObjectName(dlgBox->objectName()+ "-Heure_Entree"); // BUGBUG
    QLabel *label_HeureS = new QLabel(dlgBox);
    label_HeureS->setObjectName(dlgBox->objectName()+ "-Heure_Sortie"); // BUGBUG
    QString heure ;

    style = "background-color:" + m_Couleur_HeuresEntree  + ";" ;
    style.append( RecupStyle("Bouton_Heure_Entree"));
    label_HeureE->setStyleSheet(style);
    AppliquerUnStyle("L", label_HeureE, "Bouton_Heure_Entree" , m_Couleur_HeuresEntree);
    heure = DateEntree.mid(11,2)+"h"+DateEntree.mid(14,2);
    label_HeureE->setText(heure);
    label_HeureE->setMinimumHeight(m_Hauteur_Heures);
    label_HeureE->setMaximumWidth(m_Largeur_Heures);
    verticaLayoutHeure->addWidget(label_HeureE);
    style = "background-color:" + m_Couleur_HeuresSortie  + ";" ;
    style.append( RecupStyle("Bouton_Heure_Sortie"));
    heure = DateSortie.mid(11,2)+"h"+DateSortie.mid(14,2);
    if (heure.length() == 5)
        label_HeureS->setText(heure);
    label_HeureS->setMinimumHeight(m_Hauteur_Heures);
    label_HeureS->setMaximumWidth(m_Largeur_Heures);
    label_HeureS->setStyleSheet(style);
    verticaLayoutHeure->addWidget(label_HeureS);
    horizonLayoutPat->addLayout(verticaLayoutHeure);

    // mise en forme du bouton BouttonBougerPatient et connexion
    QPushButton *bouttonBougerPatient      = new QPushButton(dlgBox);
    bouttonBougerPatient->setIcon(QIcon(":/images/BougePatient.png"));
    bouttonBougerPatient->setAccessibleDescription(NomPatient);
    bouttonBougerPatient->setMinimumHeight(m_Hauteur_Patients);
    bouttonBougerPatient->setMinimumWidth(m_Largeur_Boutons);
    bouttonBougerPatient->setWhatsThis(NumEnCours);
    bouttonBougerPatient->setObjectName(dlgBox->objectName()+ "-BouttonBougerPatient"); // BUGBUG
    bouttonBougerPatient->setMaximumWidth(m_Largeur_Boutons);
    connect(bouttonBougerPatient, SIGNAL(clicked()), m_BougerMapper, SLOT(map()));
    m_BougerMapper->setMapping(bouttonBougerPatient, bouttonBougerPatient);
    AppliquerUnStyle("B", bouttonBougerPatient, "Bouton_Deplacer_Patient" , m_Couleur_BougerPatients);
    horizonLayoutPat->addWidget(bouttonBougerPatient);

    // Ajout de layout Patient dans le layout Groupe Pat
    verticalLayoutPatCom->addLayout(horizonLayoutPat);

    // Creation Layout pour commentaire
    QHBoxLayout *horizonLayoutComm       = new QHBoxLayout(); // BUGBUG??????????????????
    // QHBoxLayout *horizonLayoutComm       = new QHBoxLayout(dlgBox); // BUGBUG??????????????????
    horizonLayoutComm->setObjectName(dlgBox->objectName()+"-horizonLayoutComm");

    // Creation eventuel du bouton d'appel de drtux
    if (m_BoutonDrtux.toUpper() == "OUI")
       {
        QPushButton *bouttonDrTux      = new QPushButton(dlgBox);
        //BouttonCommentairePat->setAccessibleDescription(NomPatient);
        bouttonDrTux->setObjectName(dlgBox->objectName()+ "-Boutton_Appel_DrTux");
        bouttonDrTux->setWhatsThis(NumEnCours);
        bouttonDrTux->setMinimumHeight(m_Hauteur_Comment_Patients);
        bouttonDrTux->setMaximumWidth(20);
        // BouttonDrTux->setMaximumHeight(10); // ????????????????????????????????

        bouttonDrTux->setIcon(QIcon(":/images/DrTux.png"));
        AppliquerUnStyle("B", bouttonDrTux, "Boutton_Appel_DrTux" , m_Couleur_Comment_Patients);
        connect(bouttonDrTux, SIGNAL(clicked()), m_DrTuxMapper, SLOT(map()));
        m_DrTuxMapper->setMapping(bouttonDrTux, bouttonDrTux);
        horizonLayoutComm->addWidget(bouttonDrTux);
       }

    // Creation du Bouton comentaire dans le layout Groupe Pat
    QPushButton *bouttonCommentairePat      = new QPushButton(CommentairePatient,dlgBox);
    bouttonCommentairePat->setObjectName(dlgBox->objectName()+ "-BouttonCommentairePat");
    bouttonCommentairePat->setWhatsThis(NumEnCours);
    bouttonCommentairePat->setMinimumHeight(m_Hauteur_Comment_Patients);
    AppliquerUnStyle("B", bouttonCommentairePat, "Bouton_Commentaire_Patient" , m_Couleur_Comment_Patients);
    connect(bouttonCommentairePat, SIGNAL(clicked()), m_RecapMapper, SLOT(map()));
    m_RecapMapper->setMapping(bouttonCommentairePat, bouttonCommentairePat);
    horizonLayoutComm->addWidget(bouttonCommentairePat);
    verticalLayoutPatCom->addLayout(horizonLayoutComm);

    // Ajout du groupe d'objets d'un Patient dans le Layout du Box
    Box_ui->verticalLayout_patients->addLayout(verticalLayoutPatCom);
    setTimerActionOn();
}
//--------------------------------bougerLePatient------------------------------------------------------
void MainWindow::bougerLePatient(QWidget *UnWidget)
{
    setTimerActionOff();
    QPushButton *lebouton                    = qobject_cast<QPushButton *>(UnWidget);
    QObject     *scrollAreaWidgetContentsBox = lebouton->parent();
    QObject     *scroolAreaviewportBox       = scrollAreaWidgetContentsBox->parent();
    QObject     *scroolAreaBox               = scroolAreaviewportBox->parent();
    QObject     *patientParent               = scroolAreaBox->parent();
    C_Wdg_Box   *lebox                       = qobject_cast<C_Wdg_Box *>(patientParent);

    if (lebox->accessibleDescription() == "Sortie")
       {int ret = QMessageBox::question(0,NAME_APPLI,tr("Voulez-vous sortir ce patient d\303\251finitivement ?"),"OUI","NON",0,1,1);
        if (ret == 0)
           { SortirLePatient(lebouton->whatsThis());
             ActualiserUnBox(lebox);
             //QApplication::restoreOverrideCursor() ;
             setTimerActionOn();
             return;
           }
       }
    if ( m_BoxEnCours != "" && m_BoxEnCours != lebox->ui->label_BoxEnCours->text())
       { // On a clique 2 fois de suite sur la touche deplacer et un autre patient... On annule le premier.
         m_BoutonBougerEnCours->setIcon(QIcon(":/images/BougePatient.png"));
         setTimerActionOn();   // annuler celui d'avant
         QApplication::restoreOverrideCursor() ;
         //qDebug("On a clique 2 fois de suite sur la touche deplacer et un autre patient");

       }
    if (m_BoxEnCours == lebox->ui->label_BoxEnCours->text())
       { // On a clique 2 fois de suite sur la touche deplacer et le meme patient...
         statusBar()->clearMessage();
         m_BoutonBougerEnCours->setIcon(QIcon(":/images/BougePatient.png"));
         m_BoxBougerEnCours = 0;
         m_BoxEnCours = "";
         QApplication::restoreOverrideCursor() ;
         setTimerActionOn();
         setTimerActionOn();
         //qDebug("On a clique 2 fois de suite sur la touche deplacer et le meme patient");
         return;
       }
    QApplication::setOverrideCursor ( QCursor(Qt::PointingHandCursor) );
    lebouton->setIcon(QIcon(":/images/Roue.png"));
    m_BoxEnCours          = lebox->ui->label_BoxEnCours->text();
    m_PK_encours          = lebouton->whatsThis();                // stockage du NumEncours pour modif table
    m_BoutonBougerEnCours = lebouton;
    m_BoxBougerEnCours    = lebox;
    statusBar()->showMessage(tr("D\303\251placer le patient ") + lebouton->accessibleDescription() +
                             tr(". Veuillez s\303\251lectionner un box libre."));
    //setTimerActionOn();
}
//--------------------------------rentrerUnPatient------------------------------------------------------
void MainWindow::rentrerUnPatient(QWidget *UnWidget)
{
    QString miseAjourChamps;
    C_Wdg_Box *lebox = qobject_cast<C_Wdg_Box *>(UnWidget);

    if ( m_BoxEnCours == "" )    // aucun patient n'a ete selectionne en sortie
        return;
    if (lebox->ui->label_Nb_Patients_dans_Box->text().toInt() >=
        lebox->ui->label_Nb_Patients_Maxi->text().toInt())
       { // Le box n'est pas vide.
        QMessageBox::warning(this, tr("D\303\251placement d'un patient"),
                             tr("Le box s\303\251lectionn\303\251 est totalement occup\303\251.\n"
                             "Veuillez choisir un autre emplacement."));
       }
    else
       {
        // maj de la date de sortie qui est la date d'entree dans un box.
        // reecriture du code du nouveau box dans l'encours et reaffichage complet.
        miseAjourChamps = " EC_CodeBox = '" + lebox->ui->label_BoxEnCours->text() + "'," +
                          " EC_HeureSortie = '" + QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") ;
        // Mise a jour du flag Replier si box de sortie.
        if (lebox->accessibleDescription() == "Sortie" || lebox->accessibleDescription() == "Absence")
            miseAjourChamps.append("', EC_Replier       = '1");

        majTableEncours(m_PK_encours, miseAjourChamps ,  tr("D\303\251placement du patient"));

        // saisie de la destination en cas de sortie ou absence du patient du patient.
        if (lebox->accessibleDescription() == "Sortie" || lebox->accessibleDescription() == "Absence")
            saisieDestinationDuPatient(lebox->accessibleDescription(),"ListeSeule");
        // Reaffichage du box de depart
        ActualiserUnBox(m_BoxBougerEnCours);
        // Reaffichage du box destination
        ActualiserUnBox(lebox);
        m_BoxEnCours = "";

        statusBar()->clearMessage();
        while (QApplication::overrideCursor ()) QApplication::restoreOverrideCursor() ;
       }
    setTimerActionOn();
}
//------------------------------------GestionDestinationsSortie--------------------------------------------------
void MainWindow::GestionDestinationsSortie()
{    saisieDestinationDuPatient("Sortie","GestionDest");
}
//------------------------------------GestionDestinationsAbsence--------------------------------------------------
void MainWindow::GestionDestinationsAbsence()
{    saisieDestinationDuPatient("Absence","GestionDest");
}

//------------------------------------saisieDestinationDuPatient--------------------------------------------------
void MainWindow::saisieDestinationDuPatient(QString typeDeSortie, QString typeSaisie)
{
    DlgDesti *dlg       = new DlgDesti(this); if (dlg==0) return;
    dlg->dTypeDeSortie  = typeDeSortie;
    dlg->dTypeSaisie    = typeSaisie;
    dlg->dExeCalendrier = m_ExeCalendrier;
    if (typeDeSortie == tr("Absence") || typeSaisie == tr("GestionDest"))
        {
         dlg->ui->dateTimeEdit_HeureSortie->setVisible(false);
         dlg->ui->label_heuresortie->setVisible(false);
         dlg->ui->pushButton_modifHeure->setVisible(false);
        }
        if (typeSaisie == "ListeSeule")
        {dlg->ui->lineEdit_desti->setVisible(false);
        dlg->ui->pushButton_annuler->setVisible(false);
        dlg->ui->pushButton_quitter->setVisible(false);
        dlg->ui->pushButton_valider->setVisible(false);
        }
    dlg->ChargeDesti(m_PK_encours);
    dlg->setStyleSheet(RecupStyle("Fenetre_Destination"));
    dlg->exec();
    delete dlg;
}

//------------------------------------SortirLePatient--------------------------------------------------
void MainWindow::SortirLePatient(QString NumEnCours)
{
    majHistorique(NumEnCours, "", tr("Sortie d\303\251finitive."),""  );

    QString requete = "DELETE from "ENCOURS"  WHERE  EC_PK = " + NumEnCours ;
    QSqlQuery query (requete, DATA_BASE_SYNOPTUX);
    if (!query.exec())
       { QString zlastquery = query.lastQuery ();
         QString noerr;
         noerr.setNum(query.lastError().type());
         QMessageBox::warning ( this, tr("Annulation encours_taches"),
                  "<b>" + tr("Erreur lors de la mise \303\240 jour : ") +  "</b><br><br>"
                  "Erreur = (" +  noerr + ") " + query.lastError().text() + "<br>" + zlastquery );
       } // fin if erreur delete encours

    requete = "DELETE from "ENCOURS_TACHES" WHERE EN_PK_Encours = " + NumEnCours;
    QSqlQuery queryb (requete, DATA_BASE_SYNOPTUX);
    if (!queryb.exec())
       { QString zlastquery = queryb.lastQuery ();
         QString noerr;
         noerr.setNum(queryb.lastError().type());
         QMessageBox::warning ( this, tr("Annulation encours_taches"),
                  "<b>" + tr("Erreur lors de la mise \303\240 jour : ") +  "</b><br><br>"
                  "Erreur = (" +  noerr + ") " + queryb.lastError().text() + "<br>" + zlastquery );
       } // fin if erreur delete
}
//------------------------------------PlierDeplier--------------------------------------------------
void MainWindow::PlierDeplier(QWidget *UnWidget)
{
    QStringList infoBouton;
    bool        statusReplier=1;
    QPushButton             *lebouton = qobject_cast<QPushButton *>(UnWidget);
    QString                numEnCours = lebouton->whatsThis();
    QObject            *patientParent = lebouton->parent();
    QList<QPushButton *> listeBoutons = patientParent->findChildren<QPushButton *>();

    for (int i=0; i< listeBoutons.size(); i++)
        {
         infoBouton = listeBoutons.at(i)->whatsThis().split("/");
         if (infoBouton.at(0) != numEnCours) continue;
         if (listeBoutons.at(i)->objectName().contains("BouttonNomPatient"))     continue; //BUGBUG
         if (listeBoutons.at(i)->objectName().contains("BouttonPlierDeplier"))   continue; //BUGBUG
         if (listeBoutons.at(i)->objectName().contains("BouttonBougerPatient"))  continue; //BUGBUG
         if (listeBoutons.at(i)->objectName().contains("BouttonCommentairePat")) continue; //BUGBUG
         if (listeBoutons.at(i)->objectName().contains("Boutton_Appel_DrTux"))   continue; //BUGBUG

         listeBoutons.at(i)->setVisible(!listeBoutons.at(i)->isVisible());
         statusReplier = !listeBoutons.at(i)->isVisible();
        }
    if (statusReplier)
        lebouton->setIcon(QIcon(":/images/1downarrow.png"));
    else
        lebouton->setIcon(QIcon(":/images/1rightarrow.png"));

    // reecriture du status Plier ou Deplier dans la base.
    QString requete = "UPDATE "ENCOURS"  SET EC_Replier = " + QString::number(statusReplier) +
                      "  WHERE    EC_PK = " + numEnCours ;
    QSqlQuery query (requete, DATA_BASE_SYNOPTUX);
    if (!query.exec())
       {QString zlastquery = query.lastQuery ();
        QString noerr;
        noerr.setNum(query.lastError().type());
        QMessageBox::warning ( this, tr("Mise \303\240 jour table encours"),
                  "<b>" + tr("Erreur lors de la mise \303\240 jour : ") +  "</b><br><br>"
                  "Erreur = (" +  noerr + ") " + query.lastError().text() + "<br>" + zlastquery );
       } // fin if erreur exec update
}

//------------------------------------Lancer_DrTux--------------------------------------------------
void MainWindow::Lancer_DrTux(QWidget *UnWidget)
{
    QString      nomProg;
    QStringList  listArgs;
    QPushButton *lebouton   = qobject_cast<QPushButton *>(UnWidget);
    QString      numEnCours = lebouton->whatsThis();
    QString      requete    = " SELECT EC_ProgAnnexe, EC_ArgsAnnexe "   // 0-1
                              " FROM " ENCOURS
                              " WHERE EC_PK = '" + numEnCours + "'";
    QSqlQuery query(requete, DATA_BASE_SYNOPTUX);
    if (!query.isActive() ||  !query.next())
       {QMessageBox::warning(this,NAME_APPLI,"Les param\303\250tres de lancement ne peuvent \303\252tre lus !");
        return;
       }
    nomProg     = query.value(0).toString();
    listArgs    = query.value(1).toString().split("|");
    if ( QDir(nomProg).isRelative()) {nomProg = nomProg.prepend(CApp::pCApp()->pathAppli()); nomProg = QDir::cleanPath (nomProg);}
    statusBar()->showMessage(tr("Lancement de : %1").arg(nomProg));
#ifdef Q_OS_MACX
    QFileInfo fi(nomProg);
    QString   fname = fi.fileName();                // name = "archive.tar.gz"
    nomProg += ".app/Contents/MacOS/" + fname
#endif
#ifdef Q_WS_WIN
    nomProg += ".exe" ;  // BUGBUG
#endif


    QProcess::startDetached (nomProg, listArgs);
}

//-----------------------------------masquerNomPatient---------------------------------------------------
void MainWindow::masquerNomPatient(QWidget *UnWidget)
{
    QPushButton *nomPatient;
    QString     Anonyme;
    nomPatient = qobject_cast<QPushButton *>(UnWidget);
    nomPatient->parentWidget();
    if (nomPatient->text() == "Anonyme")
       {Anonyme = "0";
        nomPatient->setText(nomPatient->accessibleDescription());
       }
    else
       {Anonyme = "1";
        nomPatient->setText("Anonyme");
       }
    // mise à jour nom du flag anonyme dans la base pour réaffichage.
    majTableEncours(nomPatient->whatsThis(), "EC_Anonyme = '" + Anonyme , tr("Masquer le nom"));
}

//--------------------------------------Recap_Tache------------------------------------------------
void MainWindow::Recap_Tache(QWidget *UnWidget)
{
    QString     message, zz;
    QPushButton *leCommentaire  = qobject_cast<QPushButton *>(UnWidget);
    QString     numEnCours      = leCommentaire->whatsThis();
    bool        entete          = false;
    QString    requete          = QString (" SELECT HI_PK, HI_Code_box, HI_Nom_patient, HI_Code_resp,"           // 0-1-2-3
                                           " HI_Code_tache, HI_Date, HI_Libelle_tache, HI_Action, "              // 4-5-6-7
                                           " %1 , BO_Libelle, HI_Libelle_etat, HI_Commentaire, "                 // 8-9-10-11
                                           " HI_PrenomPatient "      // 12
                                           " FROM " HISTORIQUE
                                           " INNER JOIN %2     ON HI_Code_resp = %3 "
                                           " INNER JOIN "BOX"  ON HI_Code_box  = BO_Code "
                                           " WHERE HI_NumEncours = '%4'").arg(BASE_SYNOPTUX->m_SIGNER_NOM,BASE_SYNOPTUX->m_SIGNER_TBL_NAME, BASE_SYNOPTUX->m_SIGNER_CODE, numEnCours);
                                           // " WHERE HI_NumEncours = '%4'").arg(BASE_SYNOPTUX->m_SIGNER_NOM,BASE_SYNOPTUX->m_SIGNER_TBL_NAME, BASE_SYNOPTUX->m_SIGNER_PK, numEnCours); //BUGBUG
                                     //" ORDER BY HI_PK ASC ";

    QSqlQuery query(requete, DATA_BASE_SYNOPTUX);
    while (query.isActive() &&  query.next())
       {
        if (!entete)
           {entete = true;
           }
        zz = query.value(5).toString();                                 // date
        message.append( zz.mid(11,2) + "h" + zz.mid(14,2));             // heure
        message.append(" : ");
        zz = query.value(7).toString();
        if (zz.indexOf("Entr") >= 0)
            {message.append(zz + " - ");
             message.append(query.value(12).toString() + " " + query.value(2).toString());    //  Prenom + nom patient
             message.append("\n              - suivi par "   + query.value(8).toString());
             message.append(" (" + query.value(9).toString() + ")");   // libelle box
             if (query.value(11).toString().length() > 0)
                message.append("\n              - pour : " + query.value(11).toString());
            }
        if (zz.indexOf("responsable") > 0)
           {message.append(zz + " - ");
            message.append(query.value(8).toString());}
        if (zz.indexOf("T\303\242che") >= 0)
           {message.append(query.value(6).toString());                 // libelle tache
            message.append(" - ");
            message.append(query.value(10).toString());                 // libelle etat
            message.append(" - " + query.value(11).toString());         // commenatire etat
           }
        if (zz.indexOf("placement") > 0)
              {message.append(zz + " - ");
               message.append(query.value(9).toString());                  // libelle box
              }
           // MODIF_COM
           if (zz.indexOf("Commentaire") > 0)
              {message.append(zz + " - ");
               message.append(query.value(11).toString());                  // nouveau commentaire
              }
           message.append("\n");
          }
       // DEBUT MODIF_COM
       // PopUp_Tache(message,350, 450, "PopUp_Detail_Patient");

       if (m_popupTache) delete m_popupTache;
          m_popupTache = new QFrame(this, Qt::Popup | Qt::Window ); //| Qt::WA_DeleteOnClose
          m_popupTache->resize(350,450);
          QLineEdit *commentaireTache = new QLineEdit( m_popupTache );
          connect( commentaireTache, SIGNAL(returnPressed()), this, SLOT( Slot_modif_Comment_Tache() ) );
          commentaireTache->setGeometry(0,0, 350, 20);
          QString zcom = leCommentaire->text();
          if (zcom.indexOf(" - ") > 0)
              commentaireTache->setText(zcom.left(zcom.indexOf(" - ")));
          else
              commentaireTache->setText(leCommentaire->text());
          QTextEdit *detailTache = new QTextEdit( m_popupTache );
          connect( detailTache, SIGNAL(cursorPositionChanged()), m_popupTache, SLOT( close() ) );
          detailTache->setGeometry(0,20, 350, 430); // MODIF
          detailTache->setText(message);
          //detailTache->setStyleSheet(RecupStyle(NomStyle));
          detailTache->verticalScrollBar()->setStyleSheet(RecupStyle("PopUp_Detail_Patient"  "_ScrollBar"));
          commentaireTache->selectAll();
          commentaireTache->setFocus();
          m_popupTache->move(QCursor::pos());
          m_PK_encours = numEnCours;
          m_popupTache->show();
}
//--------------------------------------Slot_modif_Comment_Tache------------------------------------------------
void MainWindow::Slot_modif_Comment_Tache()
{
    QLineEdit *leCommentaire  = qobject_cast<QLineEdit *>(m_popupTache->children().at(0));
    majTableEncours(m_PK_encours, "EC_Commentaire = '" + leCommentaire->text()  ,  "Saisie Commentaire");
    m_popupTache->close();
    Actualiser("PARTIEL");
}
// FIN MODIF_COM
//--------------------------------------Note_Tache------------------------------------------------
void MainWindow::Note_Tache(QWidget *UnWidget)
{
    QPushButton *laTache;
    QStringList ListInfoTache;
    QString     Message, NumEnCours, NumTache, requete;

    laTache         = qobject_cast<QPushButton *>(UnWidget);
    ListInfoTache   = laTache->whatsThis().split("/");
    NumEnCours      = ListInfoTache.at(0);
    NumTache        = ListInfoTache.at(1);
    requete         = " SELECT EN_Code_tache, EN_Note_tache, EN_Comment, EN_HeureDebPrevue," //0-1-2-3
                      " EN_HeureFinPrevue, EN_Priorite, EC_NomPatient, EC_PrenomPatient, " // 4-5-6-7
                      " TA_Libelle_tache , EN_PrimKey_blob, EN_NomFicNote, EN_NomProgNote "  // 8-9-10-11
                      " FROM " ENCOURS_TACHES
                      " INNER JOIN "ENCOURS" ON EC_PK = EN_PK_encours "
                      " INNER JOIN "TACHES"  ON EN_Code_tache = TA_Code_tache "
                      " WHERE EN_PK_encours = " + NumEnCours +
                      " AND   EN_Num_tache  = " + NumTache;
    QSqlQuery query(requete, DATA_BASE_SYNOPTUX);
    if (!query.isActive() ||  !query.next())     return;   // Anormal ...
    // on a une note sous forme de fichier HTML dans l'encours.
    if (query.value(1).toString().length() > 1)
       {
        Message.append(tr("Patient : ")+ query.value(7).toString()+ " " + query.value(6).toString()+ "\n");
        Message.append(query.value(8).toString());                                          // libelle tache
        if (query.value(3).toString() > "2000.01.01")
            Message.append(tr(" - D\303\251but pr\303\251vu \303\240 ") + query.value(3).toString().mid(11,5).replace(":","h"));// heure deb prevue
        if (query.value(4).toString() > "2000.01.01")
            Message.append(tr(" - Fin pr\303\251vue \303\240 ") + query.value(4).toString().mid(11,5).replace(":","h"));       // heure fin prevue
        Message.append("\n\nCommentaire : ");
        Message.append(query.value(2).toString());                  // Commentaire
        Message.append("\n\nNote : ");
        Message.append(query.value(1).toString());                  // note Html
        PopUp_Tache(Message,600, 750, "PopUp_Note_Tache");
        return;
       }
    // on a une cle de blob contenu dans la base Medintux.
    if (query.value(9).toInt() > 0)
       {Message = lectureBlobDrtux(query.value(9).toInt());                  // note Html
        if (Message.length() > 0)
            PopUp_Tache(Message,600, 750, "PopUp_Note_Tache");
        return;
       }
    // on a un nom de fichier (PDF) et un programme de  lecture (ACrobate)
    if (query.value(10).toString().length() > 0 && query.value(11).toString().length() > 0)
       {QStringList argList;
        argList     << query.value(10).toString();
        QProcess::startDetached(query.value(11).toString(), argList);
       }
}
//--------------------------------------lectureBlobDrtux------------------------------------------------
QString MainWindow::lectureBlobDrtux(int primKeyBlob)
{

    QString requete = "SELECT RbDate_RefBlobs_PrimKey "           // 0
                          " FROM rubriqueshead "
                          " WHERE RbDate_PrimKey = '" + QString::number(primKeyBlob) + "'";
    QSqlQuery querye(requete, DB_DRTUX);
   if (!querye.isActive() ||  !querye.next())
       return "";
   requete = "SELECT RbDate_DataRub "           // 0
             " FROM rubriquesblobs "
             " WHERE RbDate_PrimKey = '" + querye.value(0).toString() + "'";
    QSqlQuery queryb(requete, DB_DRTUX);
   if (!queryb.isActive() ||  !queryb.next())
      return "";
   // retour du contenu du blob (HTML)
   // dans drtux les blobs sont stockes en UTF8
   QByteArray toto = queryb.value(0).toByteArray();
   return(QString::fromUtf8(toto));
}
//--------------------------------------Annule_Tache------------------------------------------------
void MainWindow::Annule_Tache(QWidget *UnWidget)
{
    QPushButton *annuleTache;
    QStringList listInfoTache;
    QString     numEnCours, numTache, requete;

    annuleTache     = qobject_cast<QPushButton *>(UnWidget);
    listInfoTache   = annuleTache->whatsThis().split("/");
    numEnCours      = listInfoTache.at(0);
    numTache        = listInfoTache.at(1);
    requete         = " DELETE FROM " ENCOURS_TACHES
                      " WHERE EN_PK_encours = " + numEnCours +
                      " AND   EN_Num_tache  = " + numTache;
    QSqlQuery query(requete, DATA_BASE_SYNOPTUX);
    if (!query.exec())
       { QString zlastquery = query.lastQuery ();
         QString noerr;
         noerr.setNum(query.lastError().type());
         QMessageBox::warning ( this, tr("Annulation table encours_tache"),
                  "<b>" + tr("Erreur lors de l'Annulation' : ") +  "</b><br><br>"
                  "Erreur = (" +  noerr + ") " + query.lastError().text() + "<br>" + zlastquery );
       } // fin if erreur exec Annulation
    Actualiser("PARTIEL");

}
//--------------------------------------modif_Etat------------------------------------------------
// Si changement etat par Bouton :
// ---> Mise a jour dans la base du debut de la tache si premier etat.
// ---> Mise a jour dans la base de l'historique de l'action
// ---> Mise a jour dans la base de l'etat en cours
// ---> Change la couleur du bouton etat.
// Si changement etat par par menu :
// ---> cree le menu constextuel avec les etats et lance le menu
void MainWindow::modif_Etat(QWidget *UnWidget)
{   setTimerActionOff();
    QString         numEnCours, codeTache, numTache,  boutonMenu, dernierEtat, couleurEtat;
    QStringList     accessibleNameEtat;

    m_BoutonEtat          = qobject_cast<QPushButton *>(UnWidget);
    accessibleNameEtat    = m_BoutonEtat->accessibleName().split("/");
    numEnCours            = accessibleNameEtat.at(0);
    codeTache             = accessibleNameEtat.at(1);
    numTache              = accessibleNameEtat.at(2);
    boutonMenu            = accessibleNameEtat.at(3);
    dernierEtat           = accessibleNameEtat.at(4);
    couleurEtat           = accessibleNameEtat.at(5);

    QObject *tacheParent  = m_BoutonEtat->parent();

    if (boutonMenu == "B")
        {   // on a un bouton par etat de la tache.
         QList<QPushButton *> listeBoutons = tacheParent->findChildren<QPushButton *>();
         for (int i=0; i< listeBoutons.size(); i++)
            {   // on met tous les boutons de la tache en normal.
            if ( listeBoutons.at(i)->accessibleDescription()!= "Bouton_Etat_Tache") continue;
            QStringList InfoBout = listeBoutons.at(i)->accessibleName().split("/");
            AppliquerUnStyle("B",listeBoutons.at(i), "Bouton_Etat_Tache" , InfoBout.at(5));

            }
        AppliquerUnStyle("B",m_BoutonEtat, "Bouton_Etat_Tache_EnCours" , couleurEtat);
        //BoutonOpaque(gBoutonEtat,0,couleurEtat );         // on met le bouton clique en non opaque
        majDeLaTache(numEnCours, numTache);
        if (dernierEtat == "O")
            majDateFinTache(numEnCours, numTache, "O");
        else
            majDateFinTache(numEnCours, numTache, "N");
         majHistorique(numEnCours, numTache, tr("T\303\242che"),m_BoutonEtat->text()  );
        }
    else
        {   // on a un bouton etat en cours et on cree un menu pour choisir l'etat.
         dernierEtat = "N";
         QMenu *pQMenu = new QMenu (this);
         // Recherche des etats possibles de la t\303\242che en cours
         QString requeteEtat = " SELECT ET_Libelle_etat, ET_Couleur_etat, ET_Tache_terminee "           // 0-1-2
                               " FROM " ETATS
                               " INNER JOIN "ETATS_TACHES" ON ST_Code_etat = ET_Code_etat "
                               " WHERE ST_Code_tache = '" + codeTache + "'";
         QSqlQuery queryb(requeteEtat, DATA_BASE_SYNOPTUX);
         while (queryb.isActive() &&  queryb.next())
           {//if ( ++NbEtats == queryb.size())
            if (queryb.value(2).toBool())        // c'est un etat qui termine la tache
                dernierEtat = "O";
            QAction *actEtat;
            QString strEtat = queryb.value(0).toString() + "/" + queryb.value(1).toString() + "/" + numEnCours + "/" + numTache + "/" + dernierEtat;
            actEtat = new QAction(queryb.value(0).toString(), pQMenu);
            connect(actEtat, SIGNAL(triggered()), m_MenuMapper, SLOT(map()));
            m_MenuMapper->setMapping(actEtat, strEtat);

            pQMenu->setMinimumHeight(10);
            pQMenu->addAction(actEtat);
           } // fin while etat
         pQMenu->setStyleSheet(RecupStyle("Menu_Etats"));
         pQMenu->exec(QCursor::pos());
         delete pQMenu;
        }
    setTimerActionOn();
}
//--------------------------------------modif_Etat_menu------------------------------------------------
void MainWindow::modif_Etat_menu(QString StrEtat)
{   setTimerActionOff();
    QStringList accessibleNameEtat = StrEtat.split("/");
    QString libelleEtat            = accessibleNameEtat.at(0);
    QString couleurEtat            = accessibleNameEtat.at(1);
    QString numEnCours             = accessibleNameEtat.at(2);
    QString numTache               = accessibleNameEtat.at(3);
    QString dernierEtat            = accessibleNameEtat.at(4);

    AppliquerUnStyle("B", m_BoutonEtat, "Menu_Etat_Tache_EnCours" , couleurEtat);
    m_BoutonEtat->setText(libelleEtat);
    majDeLaTache(numEnCours, numTache);
    if (dernierEtat == "O")
        majDateFinTache(numEnCours, numTache, "O");
    else
        majDateFinTache(numEnCours, numTache, "N");
    majHistorique(numEnCours, numTache, tr("T\303\242che"), libelleEtat);
    setTimerActionOn();
}
//------------------------------afficheNomMedecin--------------------------------------------
void MainWindow::afficheNomMedecin(C_Wdg_Box *dlgBox, QString /*CodeBox*/, QString NumEnCours, bool StatusReplier , QString Medecin)
{   setTimerActionOff();
    QString requete, nomResp, couleurResp;

    requete  = QString("SELECT %1, %2"            // 0-1   Nom Couleur
                       " FROM  %3 "               // Responsables
                       " WHERE %4 = '%5'").arg(BASE_SYNOPTUX->m_SIGNER_NOM, BASE_SYNOPTUX->m_SIGNER_COLOR, BASE_SYNOPTUX->m_SIGNER_TBL_NAME,BASE_SYNOPTUX->m_SIGNER_CODE, Medecin);
    QSqlQuery query(requete, DATA_BASE_SYNOPTUX);
    if (query.isActive() &&  query.next())
       { nomResp     = query.value(0).toString();
         couleurResp = query.value(1).toString();
       }
/****  BUGBUG
    if (query.isActive() &&  query.next())
        {nomResp     = query.value(0).toString();
         couleurResp = query.value(1).toString();
        }
 BUGBUG ***/
   // QHBoxLayout *horizonLayoutResp   = new QHBoxLayout(dlgBox);         // BUGBUG                 // pour le nom du responsable
     QHBoxLayout *horizonLayoutResp   = new QHBoxLayout();                          // pour le nom du responsable
     horizonLayoutResp->setObjectName(dlgBox->objectName()+"-"+"horizonLayoutResp"); // BUGBUG
     // Affiche le nom du responsable
    QPushButton *bouttonNomResp      = new QPushButton(nomResp, dlgBox);                 // libelle-tache
    AppliquerUnStyle("B", bouttonNomResp, "Bouton_Nom_Responsable" , couleurResp);
    bouttonNomResp->setObjectName(dlgBox->objectName()+"-"+"-bouttonNomResp"); // BUGBUG
    bouttonNomResp->setMinimumHeight(m_Hauteur_Medecins);
    //BouttonNomResp->setMinimumWidth(m_Largeur_Tache);
    bouttonNomResp->setWhatsThis(NumEnCours);
    if (StatusReplier) bouttonNomResp->setVisible(false);

    connect(bouttonNomResp, SIGNAL(clicked()), m_RespMapper, SLOT(map()));
    m_RespMapper->setMapping(bouttonNomResp, bouttonNomResp);

    horizonLayoutResp->addWidget(bouttonNomResp);
    dlgBox->ui->verticalLayout_patients->addLayout(horizonLayoutResp);
    setTimerActionOn();
}
//--------------------------------------modif_Resp------------------------------------------------
void MainWindow::modif_Resp(QWidget *UnWidget)
{  /*
    m_BoutonResp = qobject_cast<QPushButton *>(UnWidget);
    m_PK_encours = m_BoutonResp->whatsThis();

     // On cree un menu avec les noms des medecins responsables
    m_menuResp = new QMenu (this);
    QSqlQuery queryb(makeRequeteMedResponsable(), DATA_BASE_SYNOPTUX);
    while (queryb.isActive() &&  queryb.next())
        { QString strResp  = queryb.value(0).toString() + "/" + queryb.value(1).toString()+ "/" + queryb.value(2).toString();
          QAction *actResp = new QAction(queryb.value(1).toString(), m_menuResp);
          connect(actResp, SIGNAL(triggered()), m_MenuRespMapper, SLOT(map()));
          m_MenuRespMapper->setMapping(actResp, strResp);
          m_menuResp->setStyleSheet(RecupStyle("Menu_Responsables"));
          m_menuResp->addAction(actResp);
        } // fin while etat

    m_menuResp->exec(QCursor::pos());
  */
    setTimerActionOff();
    m_BoutonResp = qobject_cast<QPushButton *>(UnWidget);
    m_PK_encours = m_BoutonResp->whatsThis();

     // On cree un menu avec les noms des medecins responsables
    m_menuResp = new QMenu (this);
    QSqlQuery queryb(makeRequeteMedResponsable(), DATA_BASE_SYNOPTUX);
    while (queryb.isActive() &&  queryb.next())
        { QString strResp  = queryb.value(0).toString() + "/" + queryb.value(1).toString()+ "/" + queryb.value(2).toString();
          QAction *actResp = new QAction(queryb.value(1).toString(), m_menuResp);
          connect(actResp, SIGNAL(triggered()), m_MenuRespMapper, SLOT(map()));
          m_MenuRespMapper->setMapping(actResp, strResp);
          m_menuResp->setStyleSheet(RecupStyle("Menu_Responsables"));
          m_menuResp->addAction(actResp);
        } // fin while etat

    m_menuResp->exec(QCursor::pos());
    delete m_menuResp;
    setTimerActionOn();
}
//--------------------------------------makeRequeteMedResponsable------------------------------------------------
QString MainWindow::makeRequeteMedResponsable()
{QString requeteResp = QString(" SELECT %1, %2, %3 "           // 0 RE_Code -1 RE_Nom -2 RE_Couleur
                               " FROM %4 WHERE %5 LIKE '%6' AND %5 LIKE '%7'").arg(BASE_SYNOPTUX->m_SIGNER_CODE,
                                                                                   BASE_SYNOPTUX->m_SIGNER_NOM,
                                                                                   BASE_SYNOPTUX->m_SIGNER_COLOR,
                                                                                   BASE_SYNOPTUX->m_SIGNER_TBL_NAME,
                                                                                   BASE_SYNOPTUX->m_SIGNER_DROITS,"%med%","%sgn%");
 return requeteResp;
}

//--------------------------------------modif_Resp_menu------------------------------------------------
void MainWindow::modif_Resp_menu(QString StrResp)
{   setTimerActionOff();
    QStringList  listResp = StrResp.split("/");
    QString codeResp      = listResp.at(0);
    QString nomResp       = listResp.at(1);
    QString couleurResp   = listResp.at(2);

    AppliquerUnStyle("B", m_BoutonResp, "Bouton_Nom_Responsable" , couleurResp);
    m_BoutonResp->setText(nomResp);

    // mise a jour nom du responsable dans la base.
    majTableEncours(m_PK_encours, "EC_Medecin = '" + codeResp , tr("Changement de responsable"));
    setTimerActionOn();
}
//--------------------------------------selectionDunResponsable------------------------------------------------
void MainWindow::selectionDunResponsable(QString StrResp)
{
    QStringList  listResp = StrResp.split("/");
    m_ResponsableSelectionne = listResp.at(0);
    Actualiser("PARTIEL");
}
//------------------------------majTableEtatEncours--------------------------------------------
void MainWindow::majTableEtatEncours(QString NumEnCours, QString NumTache, QString ChampsMisaJour, QString /*Commentaire */)
{
    QString requete = " UPDATE "ENCOURS_TACHES"  SET " + ChampsMisaJour +
                      "  WHERE    EN_PK_Encours = " + NumEnCours +
                      "  AND      EN_Num_tache  = " + NumTache;
    QSqlQuery query (requete, DATA_BASE_SYNOPTUX);
    if (!query.exec())
       { QString zlastquery = query.lastQuery ();
         QString noerr;
         noerr.setNum(query.lastError().type());
         QMessageBox::warning ( this, tr("Mise \303\240 jour table encours_taches"),
                  "<b>" + tr("Erreur lors de la mise \303\240 jour : ") +  "</b><br><br>"
                  "Erreur = (" +  noerr + ") " + query.lastError().text() + "<br>" + zlastquery );
       } // fin if erreur exec update
}
//------------------------------majTableEncours--------------------------------------------
void MainWindow::majTableEncours(QString NumEnCours, QString ChampsMisaJour, QString Commentaire)
{
QString requete = "UPDATE "ENCOURS"  SET " + ChampsMisaJour +
                  "'  WHERE EC_PK = " + NumEnCours ;
    QSqlQuery query (requete, DATA_BASE_SYNOPTUX);
    if (!query.exec())
       {QString zlastquery = query.lastQuery ();
        QString noerr;
        noerr.setNum(query.lastError().type());
        QMessageBox::warning ( this, tr("Mise \303\240 jour table encours"),
                  "<b>" + tr("Erreur lors de la mise \303\240 jour : ") +  "</b><br><br>"
                  "Erreur = (" +  noerr + ") " + query.lastError().text() + "<br>" + zlastquery );
       } // fin if erreur exec update

    // mise a jour de l'historique
    majHistorique(NumEnCours, "", Commentaire, "");
}
//------------------------------majDeLaTache--------------------------------------------
// Mise a jour dans la table encours_taches :
// --> de l'etat qui vient d'etre selectionne, pour reaffichage.
// --> de la date debut de la tache, si c'est la premiere fois .
// --> de la date de fin prevue s'il y a une duree prevue et pas de date de fin prevue fournie
void MainWindow::majDeLaTache(QString NumEnCours, QString NumTache)
{
    // Preparation chaine de mej de la tache (etat + date debut + date fin prevue)
    QString strMAJ = "EN_Etat_en_cours = '" + m_BoutonEtat->text() + "'";

    // controle si la date de debut n'a pas deja ete maj
    QString requete = " SELECT EN_HeureDebut, EN_HeureFinPrevue, EN_Code_tache, TA_Duree_maxi "   // 0-1-2-3
                      " FROM " ENCOURS_TACHES
                       " INNER JOIN "TACHES" ON EN_Code_tache = TA_Code_tache "
                      " WHERE EN_PK_encours = " + NumEnCours +
                      " AND   EN_Num_tache  = " + NumTache ;
    QSqlQuery queryb(requete, DATA_BASE_SYNOPTUX);
    if (!queryb.isActive() ||  !queryb.next())  // Erreur pas possible ??
        return;

    if (queryb.value(0).toString() < "2000-00-00")      // la tache n'est pas commencee, il n'y a pas de date debut
       {// Preparation chaine de maj de l'heure en cours dans la Date debut de la tache
        strMAJ.append(", EN_HeureDebut = '" + QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") + "'");
       }
    // plus maj de l'heure de fin prevue si pas renseignee et duree prevue parametree
    // on ajoute la duree maxi prevue a l'heure actuelle.
    if ((queryb.value(1).toString() < "2000-00-00")  &&         // la date fin prevue n'est pas renseignee
        (queryb.value(3).toInt() > 0))                          // la duree maxi de la tache est renseignee
       {
        QDateTime dateFinPrevue = QDateTime::currentDateTime().addSecs(queryb.value(3).toInt() * 60);
        strMAJ.append(", EN_HeureFinPrevue = '" + dateFinPrevue.toString("yyyy-MM-dd hh:mm:ss") + "'");
       }
    majTableEtatEncours(NumEnCours, NumTache, strMAJ, tr("T\303\242che."));
}
//------------------------------majDateFinTache--------------------------------------------
void MainWindow::majDateFinTache(QString numEnCours, QString numTache, QString dernierEtat)
// S'il s'agit d'un etat "termine" on inscrit la date de fin
// sino on efface une eventuelle date fin deja inscrite
{
    QString strMAJ, dateMAJ, libMAJ;
    // controle si la date de debut n'a pas deja ete maj
    QString requete = " SELECT EN_HeureFin "   // 0
                      " FROM " ENCOURS_TACHES
                      " WHERE EN_PK_encours = " + numEnCours +
                      " AND   EN_Num_tache  = " + numTache ;
    QSqlQuery queryb(requete, DATA_BASE_SYNOPTUX);
    if (!queryb.isActive() ||  !queryb.next())  // Erreur pas possible ??
        return;

    if (dernierEtat == "N" && queryb.value(0).toString() < "2000-00-00")       // la tache n'est pas terminee et il y a une date fin
        return;
    else if (dernierEtat == "N" && queryb.value(0).toString() > "2000-00-00")  // la tache n'est pas terminee , il y a une date fin, on l'efface
       { dateMAJ = "1000-01-01 01:01:01";
         libMAJ = tr("Annulation Date fin");
       }
    else if (dernierEtat == "O" && queryb.value(0).toString() > "2000-00-00")  // la tache est terminee , il y a une date fin, on la laisse
        return;
    else                                                                       // la tache est deja terminee, il y n'a pas une date fin, on l'inscrit
       {dateMAJ = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        libMAJ = tr("Traitement termin\303\251");
       }
    strMAJ = "EN_HeureFin = '" + dateMAJ + "'";
    majTableEtatEncours(numEnCours, numTache, strMAJ, libMAJ);
}
//------------------------------majHistorique--------------------------------------------
void MainWindow::majHistorique(QString NumEnCours, QString NumTache, QString Action, QString LibelleEtat)
{
    QString requete;
    QString  CodeBox , NomPatient, CodeResp, CodeTache, LibelleTache, PrenomPatient, CommEncOuTache;
    QSqlQuery queryh (DATA_BASE_SYNOPTUX);

    requete = " SELECT EC_CodeBox, EC_NomPatient, EC_HeureEntree, EC_Medecin, "      // 0-1-2-3
              " EC_GUIDPatient, EC_HeureSortie, EC_PrenomPatient, EC_Commentaire "   // 4-5-6-7
              " FROM " ENCOURS
              " WHERE EC_PK = " + NumEnCours;
    QSqlQuery query (requete, DATA_BASE_SYNOPTUX);
    if (query.isActive() &&  query.next())
       {
        CodeBox       = query.value(0).toString();
        NomPatient    = query.value(1).toString();
        PrenomPatient = query.value(6).toString();
        CodeResp      = query.value(3).toString();
        CommEncOuTache= query.value(7).toString();
       }
    if (NumTache > 0)
       {
        requete = " SELECT EN_Code_tache, EN_Comment, EN_Etat_en_cours, EN_HeureDebPrevue, "     // 0-1-2-3
                  " EN_HeureFinPrevue, EN_HeureDebut, EN_HeureFin, EN_Priorite, "                // 4-5-6-7
                  " TA_Libelle_tache, EN_Comment "                                               // 8-9
                  " FROM " ENCOURS_TACHES
                  " INNER JOIN "TACHES" ON TA_Code_tache = EN_Code_Tache "
                  " WHERE   EN_PK_encours   = " + NumEnCours +
                  " AND     EN_Num_tache    = " + NumTache ;

        QSqlQuery queryb (requete, DATA_BASE_SYNOPTUX);
        while (queryb.isActive() &&  queryb.next())
            {
             CodeTache       = queryb.value(0).toString();
             LibelleTache    = queryb.value(8).toString();
             CommEncOuTache  = queryb.value(9).toString();
            }
       }
    requete = " INSERT INTO " HISTORIQUE
              " (HI_Code_box, HI_Nom_patient, HI_Code_resp, HI_Code_tache, "
              " HI_Date, HI_Action, HI_NumEncours, HI_Libelle_tache, HI_Libelle_etat,"
              " HI_PrenomPatient, HI_Commentaire)"
              " VALUES ('" +
              CodeBox + "','" + NomPatient + "','" + CodeResp + "','" + CodeTache + "','" +
              QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") + "','" + Action +
              "','" + NumEnCours + "','" + LibelleTache + "','" + LibelleEtat + "','" +
              PrenomPatient + "','" + CommEncOuTache + "')";
    queryh.prepare(requete);
    if (!queryh.exec())
       {QString zlastquery = queryh.lastQuery ();
        QString noerr;
        noerr.setNum(queryh.lastError().type());
        QMessageBox::warning ( this, tr("Mise \303\240 jour table historique"),
                  "<b>" + tr("Erreur lors de la mise \303\240 jour : ") +  "</b><br><br>"
                  "Erreur = (" +  noerr + ") " + queryh.lastError().text() + "<br>" + zlastquery );
       } // fin if erreur exec update
}

//--------------------------------- Enregistrer_Positions -----------------------------------------
void MainWindow::Enregistrer_Positions()
{
    m_settingsIni->beginGroup("Positions_fenetres") ;
    m_settingsIni->setValue("Pos_Window",  pos());
    m_settingsIni->setValue("Size_Window", size());
    foreach (QMdiSubWindow *box, m_mdiArea->subWindowList())
       {m_settingsIni->setValue("Pos_" + box->accessibleName(), box->pos());
        m_settingsIni->setValue("Size_"+ box->accessibleName(), box->size());
       }
   m_settingsIni->endGroup();
   m_settingsIni->sync();
   m_settingsIni->beginGroup("Affichage") ;
   m_settingsIni->setValue("Mode_Affichage", m_ModeAffichage);
   m_settingsIni->endGroup();
   m_settingsIni->sync();
   CApp::pCApp()->initSettingVar(CGestIni::Param_UpdateFromDisk(CApp::pCApp()->pathIni()));
  }

//------------------------------------ Recuperer_Positions ------------------------------------------------------------
void MainWindow::Recuperer_Positions()
{
  QPoint pos  = m_settingsIni->value("Positions_Fenetres/Pos_Window",  QPoint(10, 10)).toPoint();
  QSize  size = m_settingsIni->value("Positions_Fenetres/Size_Window", QSize(1024, 768)).toSize();
  move(pos);
  resize(size);
}
//------------------------------------Controle_Alarmes--------------------------------------------------
void MainWindow::Controle_Alarmes()
{if (m_notAction) return;
 QString requete, heurePrevue, heureReelle, messageAlarme;
 QString heureActuelle = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

    m_ListeBoutonsAlarme.clear();
    messageAlarme.clear();
    requete = " SELECT EN_PK_encours, EN_Num_tache, EN_Code_tache, EN_Comment, EN_Etat_en_cours," // 0-1-2-3-4
              " EN_HeureDebPrevue, EN_HeureFinPrevue, EN_HeureDebut, EN_HeureFin, "          // 5-6-7-8
              " TA_Libelle_tache, EC_CodeBox, BO_Libelle, EC_Replier "                       // 9-10-11-12
              " FROM " ENCOURS_TACHES
              " INNER JOIN "TACHES"  ON TA_Code_tache = EN_Code_tache "
              " INNER JOIN "ENCOURS" ON EC_PK         = EN_PK_encours "
              " INNER JOIN "BOX"     ON BO_Code       = EC_CodeBox "
              " WHERE EN_HeureFin IS NULL OR EN_HeureFin < '2000-00-00'" ;  // la tache n'est pas finie

    QSqlQuery query (requete, DATA_BASE_SYNOPTUX);
    while (query.isActive() &&  query.next())
        {
        // controle que la date de debut prevue n'est pas depassee.
        heurePrevue = query.value(5).toString().replace("T"," ");
        heureReelle = query.value(7).toString().replace("T"," ");
        if ((heurePrevue > "2000-00-00") &&       // il y a une date de debut prevue
            (heurePrevue > heureActuelle)&&       // l'heure prevue est depassee
            (heureReelle < "2000-00-00" ))        // la tache n'a pas commence. (date debut reelle non renseignee)
           {
            messageAlarme = query.value(11).toString() + " : La t\303\242che " + query.value(9).toString() + " aurait du d\303\251marrer \303\240 " + heurePrevue.mid(11,5).replace(":","h") + ".\n";
            Alarme (query.value(0).toString(),query.value(2).toString(), messageAlarme, query.value(12).toString());
           }
        // controle que la date de fin prevue n'est pas depassee.
        heurePrevue = query.value(6).toString().replace("T"," ");
        heureReelle = query.value(8).toString().replace("T"," ");
        if ((heurePrevue > "2000-00-00") &&       // il y a une date de fin prevue
            (heurePrevue < heureActuelle)&&       // l'heure prevue est depassee
            (heureReelle < "2000-00-00" ))        // la tache n'est pas terminee. (date fin reelle non renseignee)
           {
             messageAlarme = query.value(11).toString() + " : La t\303\242che " + query.value(9).toString() + " aurait du se terminer \303\240 " + heurePrevue.mid(11,5).replace(":","h") + ".\n";
             Alarme (query.value(0).toString(),query.value(2).toString(), messageAlarme, query.value(12).toString());
           }
        }
//    if (gMessageAlarme.length() > 1)
//        QMessageBox::warning(0,tr("Alerte sur les taches en retard"),gMessageAlarme);
// Mettre un affichage plus mieux bien

}
//------------------------------------Alarme--------------------------------------------------
void MainWindow::Alarme(QString NumEnCours, QString Code_Tache, QString MessAlarme, QString Replier)
{
QPushButton *leboutonEnAlarme;
QStringList  listInfoTache;
QString      numEnCoursTache;

    // recherche du bouton tache concerne pour declancher le clignotement.
    QList<QPushButton *> listeBoutons = m_mdiArea->findChildren<QPushButton *>();

    for (int i=0; i< listeBoutons.size(); i++)
        {
        listInfoTache        = listeBoutons.at(i)->whatsThis().split("/");
        numEnCoursTache      = listInfoTache.at(0);
        if (numEnCoursTache != NumEnCours)          continue;
        // si l'encours est "Replier" on fait clignoter le bouton "Nom du patient".
        // sinon on fait clignoter le bouton "Nom de la tache" concerne.
        leboutonEnAlarme = listeBoutons.at(i);
        if (Replier == "1")
           {
            if (leboutonEnAlarme->objectName()    != "BouttonNomPatient")   continue;
           }
        else
           {
            if (leboutonEnAlarme->objectName()    != "BouttonNomTache")     continue;
            if (leboutonEnAlarme->accessibleName()!= Code_Tache)            continue;
           }
        // Ajoute la tache dans le message general d'alerte
        m_MessageAlarme.append(MessAlarme + "\n");
        statusBar()->showMessage(m_MessageAlarme);

        // Ajoute le bouton dans la liste des boutons en Alarme
        m_ListeBoutonsAlarme << leboutonEnAlarme;

        // lancer un timer de clignotement
        if (m_timerClignote == 0)
           {m_timerClignote = new QTimer(this);
            connect(m_timerClignote, SIGNAL(timeout()), this, SLOT(FaireClignoterLaTache()));
           }
        if (!m_timerClignote->isActive())
            m_timerClignote->start(m_PeriodeClignote * 1000);
        }
}
//------------------------------------FaireClignoterLaTache--------------------------------------------------
//Format de la propriete accessibleDescription du bouton tache = #couleurOrig/#couleurAlarme/ALARME1/
void MainWindow::FaireClignoterLaTache()
{if (m_notAction) return;
 QPushButton *leboutonTacheEnAlarme;
 QString      couleurAlarme;

    if (m_ListeBoutonsAlarme.size() <= 0)    // il n'y a plus de boutons en alarme
        {m_timerClignote->stop();
        }
    for (int i=0; i< m_ListeBoutonsAlarme.size(); i++)
        {
        leboutonTacheEnAlarme = m_ListeBoutonsAlarme.at(i);
        if (leboutonTacheEnAlarme->objectName() == "BouttonNomPatient")
            {   // on fait clignoter le nom du patient
            QStringList listInfoTache   = leboutonTacheEnAlarme->accessibleName().split("/");
            QString     posAlarme       = listInfoTache.at(0);
            if (posAlarme == "ALARME1") // on est en couleur alarme
                {couleurAlarme = m_Couleur_Patients;
                 leboutonTacheEnAlarme->setAccessibleName("ALARME2");
                }
            else
                {couleurAlarme = m_Couleur_PatientsClignote;
                 leboutonTacheEnAlarme->setAccessibleName("ALARME1");
                }
            // Style.append( RecupStyle("Bouton_Nom_Patient"));
            // leboutonTacheEnAlarme->setStyleSheet(Style);
            AppliquerUnStyle("B", leboutonTacheEnAlarme, "Bouton_Nom_Patient" , couleurAlarme);
            }
        else
            {   // on fait clignoter le nom de la tache
            QStringList listInfoTache   = leboutonTacheEnAlarme->accessibleDescription().split("/");
            QString     couleurOrig     = listInfoTache.at(0);
            QString     couleurAlar     = listInfoTache.at(1);
            QString     posAlarme       = listInfoTache.at(2);
            if (posAlarme == "ALARME1") // on est en couleur alarme
                {couleurAlarme = couleurOrig;
                 leboutonTacheEnAlarme->setAccessibleDescription(couleurOrig + "/" + couleurAlar + "/ALARME2");
                }
            else
                {couleurAlarme = couleurAlar ;
                leboutonTacheEnAlarme->setAccessibleDescription(couleurOrig + "/" + couleurAlar + "/ALARME1");
                }
            //Style.append( RecupStyle("Bouton_Nom_Tache"));
            //leboutonTacheEnAlarme->setStyleSheet(Style);
            AppliquerUnStyle("B", leboutonTacheEnAlarme, "Bouton_Nom_Tache" , couleurAlarme);
            }
        }
}
//------------------------------------Controle_Entrees--------------------------------------------------
//  Surveille l'arrivee d'un fichier xxxxxx.txt dans le repertoire DOSSIER_ENTREES
//  et cree un nouvel encours
void MainWindow::Controle_Entrees()
{
    if (m_notAction) return;
 QString    nomFicEntree, requete, DateDeb, DateFin, CodeBox, NomPatient, PrenomPatient, GuidPatient, CodeResp;
 QString    CodeTache, Priorite, Commentaire, HeureDeb, HeureFin, ProgAnnexe, ArgsAnnexe;
 QString    PrimKey_blob, NomFicNote, NomProgNote;
 QSqlQuery  queryEnc( DATA_BASE_SYNOPTUX);
 QSqlQuery  queryTac( DATA_BASE_SYNOPTUX);
 bool       IlFautActualiser = false;
 int        EC_PK ;

    QFileInfoList listeEntrees = m_DirDossierEntree.entryInfoList();
    for (int i=0; i < listeEntrees.size(); i++ )          // il y a au moins un fichier en attente.
        {
        QFileInfo   ficInfo = listeEntrees.at(i);
        nomFicEntree = ficInfo.absoluteFilePath();
        if (ficInfo.suffix().toUpper() != "TXT" || ficInfo.isHidden())
            continue;
        statusBar()->showMessage(tr("D\303\251tection du fichier "));

        // lecture des donnees recues dans le fichier ENTREES.txt
        QSettings   settingsEntree (nomFicEntree, QSettings::IniFormat);
        settingsEntree.setIniCodec ("ISO 8859-1");

        CodeBox        = settingsEntree.value("Entree/Code_Box").toString();
        NomPatient     = settingsEntree.value("Entree/Nom_Patient").toString();
        PrenomPatient  = settingsEntree.value("Entree/Prenom_Patient").toString();
        GuidPatient    = settingsEntree.value("Entree/GUID_Patient").toString();
        CodeResp       = settingsEntree.value("Entree/Code_Responsable").toString();
        Commentaire    = settingsEntree.value("Entree/Commentaire").toString().toLatin1();
        Priorite       = settingsEntree.value("Entree/Priorite").toString();
        ProgAnnexe     = settingsEntree.value("Entree/Programme_Annexe").toString();
        ArgsAnnexe     = settingsEntree.value("Entree/Arguments_Annexe").toString();

        // controle du code Box qui doit exister pour apparaitre.
        requete = "SELECT Code_Box FROM "BOX" WHERE BO_Code = '" + CodeBox + "'";
        QSqlQuery query (requete, DATA_BASE_SYNOPTUX);
        if (!query.isActive() ||  !query.next())
           { CodeBox = m_CodeBoxParDefaut;
           }

        // Controle de l'existence d'un encours pour le patient
        requete = "SELECT EC_PK FROM "ENCOURS" WHERE EC_GUIDPatient = '" + GuidPatient + "'";
        QSqlQuery queri (requete, DATA_BASE_SYNOPTUX);
        if (queri.isActive() &&  queri.next())
           { EC_PK = queri.value(0).toInt();
           }
        else
           {// il n'y a pas ce patient dans l'encours
            // Creation d'une entree dans table encours
            requete = " INSERT INTO " ENCOURS
                      " (EC_CodeBox, EC_NomPatient, EC_PrenomPatient, EC_Medecin, EC_GUIDPatient, EC_Replier, EC_Commentaire,"
                      " EC_HeureEntree, EC_ProgAnnexe, EC_ArgsAnnexe )"
                      " VALUES ('" +
                      CodeBox + "','" + NomPatient + "','" + PrenomPatient + "','" + CodeResp + "','" + GuidPatient + "','1','" + Commentaire + "','" +
                      QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") + "','" + ProgAnnexe + "','" + ArgsAnnexe +
                      "')";
            queryEnc.prepare(requete);
            if (!queryEnc.exec())
               {QString zlastquery = queryEnc.lastQuery ();
                QString noerr;
                noerr.setNum(queryEnc.lastError().type());
                QMessageBox::warning ( this, tr("Cr\303\251ation d'une entr\303\251e"),
                           "<b>" + tr("Erreur lors de la cr\303\251ation : ") +  "</b><br><br>"
                           "Erreur = (" +  noerr + ") " + queryEnc.lastError().text() + "<br>" + zlastquery );
                return;
               } // fin if erreur exec insert

            // recuperation de la primkey pour creer les lignes taches
            requete = "SELECT LAST_INSERT_ID() FROM "ENCOURS" WHERE EC_PK = LAST_INSERT_ID()" ;
            QSqlQuery query1(requete, DATA_BASE_SYNOPTUX);
            if (!query1.isActive() ||  !query1.next())
               { QMessageBox::warning(0, NAME_APPLI, tr("Cr\303\251ation de l'entr\303\251e. Erreur recherche derni\303\250re clef!"));
                 return;
               }
            EC_PK = query1.value(0).toInt();
           } // fin else pas d'encours pour ce patient

        // lecture des taches fournies  dans le fichier ENTREES.TXT et creation dans encours_taches
        for (int NumTache = 1; NumTache < 50 ; NumTache++)
            {QString zTache = "Tache_" + QString::number(NumTache) ;
             CodeTache   = settingsEntree.value(zTache + "/Code_Tache").toString();         // ex: ECG
             if (CodeTache.length() < 1) break;
             Priorite    = settingsEntree.value(zTache + "/Priorite").toString();           // ex: 2
             Commentaire = settingsEntree.value(zTache + "/Commentaire").toString().toLatin1();
             HeureDeb    = settingsEntree.value(zTache + "/Heure_Debut_Prevue").toString(); //ex: 10:20
             if (HeureDeb.length() != 5)                         // y'a pas de date de debut prevue
                 DateDeb = "1000-01-01 01:01";
             else
                 DateDeb = QDate::currentDate().toString("yyyy-MM-dd") + " " + HeureDeb.mid(0,2) + ":" + HeureDeb.mid(3,2);
             HeureFin    = settingsEntree.value(zTache + "/Heure_Fin_Prevue").toString();
             if (HeureFin.length() != 5)                         // y'a pas de date de debut prevue
                 DateFin = "1000-01-01 01:01";
             else
                 DateFin = QDate::currentDate().toString("yyyy-MM-dd") + " " + HeureFin.mid(0,2) + ":" + HeureFin.mid(3,2);

             PrimKey_blob = settingsEntree.value(zTache + "/PrimKey_Blob").toString();
             if (PrimKey_blob.length() == 0) PrimKey_blob = "0";
             NomFicNote   = settingsEntree.value(zTache + "/Nom_Fichier_Note").toString();
             NomProgNote  = settingsEntree.value(zTache + "/Nom_Lecteur_Note").toString();
             requete = " INSERT INTO " ENCOURS_TACHES
                       " (EN_PK_encours, EN_Code_tache, EN_Comment,"
                       "  EN_HeureDebPrevue, EN_HeureFinPrevue, EN_Priorite, "
                       "  EN_PrimKey_blob, EN_NomFicNote, EN_NomProgNote "
                       "  )"
                       " VALUES ('" +
                       // QString::number(EC_PK) + "','" + QString::number(NumTache) + "','" + CodeTache + "','" + Commentaire + "','" +
                       QString::number(EC_PK) + "','"  + CodeTache + "','" + Commentaire + "','" +
                       DateDeb        + "','" + DateFin      + "','" + Priorite      + "','" +
                       PrimKey_blob   + "','" + NomFicNote   + "','" + NomProgNote   +
                       "')";
             queryTac.prepare(requete);
             if (!queryTac.exec())
                {QString zlastquery = queryTac.lastQuery ();
                 QString noerr;
                 noerr.setNum(queryTac.lastError().type());
                 QMessageBox::warning ( this, tr("Cr\303\251ation des taches encours"),
                            "<b>" + tr("Erreur lors de la cr\303\251ation : ") +  "</b><br><br>"
                            "Erreur = (" +  noerr + ") " + queryTac.lastError().text() + "<br>" + zlastquery );
                } // fin if erreur exec update
            } // fin for Taches
        // suppression du fichier integre.
        QFile::remove(nomFicEntree);
        IlFautActualiser = true;

        // creation d'une trace dans l'historique
        majHistorique(QString::number(EC_PK), "", tr("Entr\303\251e du patient"),""  );
        } // fin for fichier

    // controle si un autre prog a fait une entree directe dans la base
    if (!IlFautActualiser)
       {
        requete = "SELECT MAX(EC_PK) FROM " ENCOURS ;
        QSqlQuery query1(requete, DATA_BASE_SYNOPTUX);
        if (!query1.isActive() ||  !query1.next())
           { QMessageBox::warning(0, NAME_APPLI, "Controle des entr\303\251es. Erreur recherche derni\303\250re clef");
             return;
           }
        if (m_DernierPkencours != query1.value(0).toInt())
            IlFautActualiser = true;
       }
    if (!IlFautActualiser)
       {
        requete = "SELECT MAX(EN_Num_tache) FROM " ENCOURS_TACHES ; // BUGBUG
        QSqlQuery query2(requete, DATA_BASE_SYNOPTUX);
        if (!query2.isActive() ||  !query2.next())
           { QMessageBox::warning(0, NAME_APPLI, "Controle des entr\303\251es. Erreur recherche derni\303\250re cl\303\251");
             return;
           }
/* BUGBUG POUR TESTER ACTUALISATION FREQUENTE - TEST A REMETTRE
        if (m_DernierPkencours_taches != query2.value(0).toInt())
BUGBUG */
            IlFautActualiser = true;
       }
    if (IlFautActualiser)
        Actualiser("PARTIEL");
}
//------------------------------------PopUp_Tache-------------------------------------------------
void MainWindow::PopUp_Tache(QString Message, int largeur, int hauteur, QString NomStyle)
{   if (m_popupTache) delete m_popupTache;
    m_popupTache = new QFrame(this, Qt::Popup | Qt::Window ); //| Qt::WA_DeleteOnClose
    m_popupTache->resize(largeur,hauteur);
    QTextEdit *detailTache = new QTextEdit( m_popupTache );
    connect( detailTache, SIGNAL(cursorPositionChanged()), m_popupTache, SLOT( close() ) );
    detailTache->setGeometry(0,0, largeur, hauteur);
    detailTache->setText(Message);
    //detailTache->setStyleSheet(RecupStyle(NomStyle));
    detailTache->verticalScrollBar()->setStyleSheet(RecupStyle(NomStyle + "_ScrollBar"));
    detailTache->setFocus();
    m_popupTache->move(QCursor::pos());
    m_popupTache->show();
}

//--------------------------------LireleCSS----------------------------------------------------
bool MainWindow::LireleCSS()
{
      QString     nomficCSS = QApplication::applicationDirPath()+ "/Ressources/synoptux.css";
      QFile      *fileCSS   = new QFile(nomficCSS); if (fileCSS==0) return false;
      if (!fileCSS->open(QIODevice::ReadOnly)) {
          QMessageBox::warning(0, NAME_APPLI, tr("Le fichier %1 ne peut pas \303\250tre ouvert !").arg(nomficCSS));
          delete fileCSS;
          return false;
          }
      m_FicCSS = fileCSS->readAll();
      fileCSS->close();
      delete fileCSS;
      return true;
}
//--------------------------------RecupStyle----------------------------------------------------
QString MainWindow::RecupStyle(QString TypeObjet)
{
    int pos,pos1,pos2;

    pos = m_FicCSS.indexOf(TypeObjet);
    if (pos >= 0)
        {pos1 = m_FicCSS.indexOf("{",pos);
        if (pos1 > 0)
            { // on teste si c'est un param pour un objet ou pour un ensmble
            if (m_FicCSS.mid(pos1,2) == "{{")
                {
                pos2 = m_FicCSS.indexOf("}}",pos1);
                if (pos2 > 0)
                    {return(m_FicCSS.mid (pos1 +2 , pos2 - pos1 -2));
                    }
                } // fin if on traite un ensemble
            else
                {
                pos2 = m_FicCSS.indexOf("}",pos1);
                if (pos2 > 0)
                    {return(m_FicCSS.mid (pos1 +1 , pos2 - pos1 -1));
                    }
                }
            } // fin else on traite un seul objet
        } // fin pos ok on a bien un parametrage
    QMessageBox::warning(0,"Recherche des styles", tr("Le param\303\250trage css pour %1 est incorrect.\nVeuillez v\303\251rifier le fichier CSS").arg(TypeObjet));
    return "";
}
//------------------------------------------fin-------------------------------------------------------------
