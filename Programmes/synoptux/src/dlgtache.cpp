#include "dlgtache.h"
#include "ui_dlgtache.h"
#include <QtGui>
#include "CApp.h"
#include "C_BaseSynoptux.h"

#define TACHES          "taches"
#define ETATS           "etats"
#define ETATS_TACHES    "etats_taches"

DlgTache::DlgTache(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgTache)
{
    ui->setupUi(this);

    connect (ui->pushButton_QuitterTache,   SIGNAL(clicked()),   this, SLOT(accept()));
    connect (ui->pushButton_ValidTache,     SIGNAL(clicked()),   this, SLOT(ValideTache()));
    connect (ui->pushButton_annuler,        SIGNAL(clicked()),   this, SLOT(AnnuleTache()));
    connect (ui->pushButton_CouleurFond,    SIGNAL(clicked()),    this, SLOT(ChoixCouleurFond()));
    connect (ui->pushButton_CouleurAlarme,  SIGNAL(clicked()),    this, SLOT(ChoixCouleurAlarme()));
    connect (ui->treeWidget_Tache,          SIGNAL(itemClicked(QTreeWidgetItem*,int)),   this, SLOT (selectTache( QTreeWidgetItem * , int )));
    connect (ui->treeWidget_TacheEtats,     SIGNAL(itemClicked(QTreeWidgetItem*,int)),   this, SLOT (selectEtat( QTreeWidgetItem * , int )));

    ui->treeWidget_TacheEtats->setColumnHidden(0,true);
    ui->treeWidget_TacheEtats->setColumnHidden(2,true);
    ui->treeWidget_TacheEtats->setColumnHidden(3,true);

    ui->treeWidget_Tache->setColumnWidth(0,70);
    ui->treeWidget_Tache->setColumnWidth(1,150);
    //ui->treeWidget_Tache->setColumnWidth(2,50);


}

DlgTache::~DlgTache()
{
    delete ui;
}

void DlgTache::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
//-----------------------------------------selectTache----------------------------------------------------------------
void DlgTache::selectTache(QTreeWidgetItem * , int)
{
QTreeWidgetItem *item   = ui->treeWidget_Tache->currentItem();
QTreeWidgetItem *pItemEtat  = 0;
QColor color;
TacheEnCours = item->text(0);

QString requete;

requete = "SELECT   TA_Code_tache, TA_Libelle_tache, TA_Couleur_tache, TA_Couleur_alarme, "   // 0-1-2-3
          " TA_Duree_maxi, TA_BoutonMenu "                                       // 4-5
          " FROM    " TACHES
          " WHERE  TA_Code_tache = '" + TacheEnCours + "'" ;

    QSqlQuery query(requete, CApp::pCApp()->getDB()->database());
    while (query.isActive() &&  query.next())
        {ui->lineEdit_CodeTache->setText( query.value(0).toString());
        ui->lineEdit_NomTache->setText(   query.value(1).toString());
        ui->lineEdit_CouleurFondCode->setText(query.value(2).toString());
        ui->pushButton_CouleurFond->setStyleSheet("background-color:" + query.value(2).toString()  + ";");
        ui->lineEdit_CouleurAlarmeCode->setText(query.value(3).toString());
        ui->pushButton_CouleurAlarme->setStyleSheet("background-color:" + query.value(3).toString()  + ";");
        ui->lineEdit_DureeMaxi->setText(query.value(4).toString());
        if (query.value(5).toString() == "B")
          ui->radioButton_Bouton->setChecked(true);     // Bouton
        else
          ui->radioButton_Menu->setChecked(true);    // Menu
        }
    // affichage des taches associ�es
    ui->treeWidget_TacheEtats->clear();
    requete = "SELECT ET_Code_etat, ET_Libelle_etat, ET_Couleur_etat "   // 0-1-2
              " FROM    " ETATS
              " ORDER BY ET_Code_etat";

    QSqlQuery queryb(requete, CApp::pCApp()->getDB()->database());
    while (queryb.isActive() &&  queryb.next())
        { pItemEtat = new QTreeWidgetItem() ;
        pItemEtat->setText(0, queryb.value(0).toString());        // code tache
        pItemEtat->setText(1, queryb.value(1).toString());        // libelle tache
        pItemEtat->setText(2, queryb.value(2).toString());        // couleur

        requete = "SELECT ST_Code_tache"
                  " FROM    " ETATS_TACHES
                  " WHERE ST_Code_tache = '" + TacheEnCours + "'"
                  " AND   ST_Code_Etat  = '" + queryb.value(0).toString() + "'";
        QSqlQuery queryc(requete, CApp::pCApp()->getDB()->database());
        if (queryc.isActive() &&  queryc.next())
            {
            //pItemEtat->setSelected(true);
            color.setNamedColor(queryb.value(2).toString());
            pItemEtat->setBackgroundColor(1,color);
            pItemEtat->setText(3,"OK");
            }
        ui->treeWidget_TacheEtats->addTopLevelItem(pItemEtat);
        }
    //
    ui->pushButton_annuler->setEnabled(true);
    ui->pushButton_ValidTache->setEnabled(true);
    ui->lineEdit_CodeTache->setEnabled(false);
}
//-----------------------------------------selectEtat----------------------------------------------------------------
void DlgTache::selectEtat(QTreeWidgetItem * , int)
{
QTreeWidgetItem *itemEtat   = ui->treeWidget_TacheEtats->currentItem();
QColor color;

    if (itemEtat->text(3) == "OK")
        {itemEtat->setText(3,"");
        color.setNamedColor("#EAEFFF");
        }
    else
        {color.setNamedColor(itemEtat->text(2));
        itemEtat->setText(3,"OK");
        }
    itemEtat->setBackgroundColor(1,color);
    itemEtat->setSelected(false);
}
//-------------------------------ValideTache----------------------------------------------------
void DlgTache::ValideTache()
{
QString     requete;
QSqlQuery   query ( CApp::pCApp()->getDB()->database());

    if (TacheEnCours.length() == 0)            // on est en cr�ation ....
       {
        if (ui->lineEdit_CodeTache->text().length()== 0) return;
        TacheEnCours = ui->lineEdit_CodeTache->text();
//TA_Code_tache, TA_Libelle_tache, TA_Couleur_tache, TA_Duree_maxi, TA_Couleur_alarme, TA_BoutonMenu
        requete = "INSERT INTO " TACHES " ("
                  " TA_Code_tache, TA_Libelle_tache,   TA_Couleur_tache, TA_Couleur_alarme, "
                  " TA_Duree_maxi,   TA_BoutonMenu) "
                  " VALUES ("
                  " :TA_Code_tache, :TA_Libelle_tache,   :TA_Couleur_tache, :TA_Couleur_alarme, "
                  " :TA_Duree_maxi,   :TA_BoutonMenu ) ";

        query.prepare(requete);
        query.bindValue(":TA_Code_tache",     ui->lineEdit_CodeTache->text());
        query.bindValue(":TA_Libelle_tache",  ui->lineEdit_NomTache->text());
        query.bindValue(":TA_Couleur_tache",  ui->lineEdit_CouleurFondCode->text());
        query.bindValue(":TA_Couleur_alarme", ui->lineEdit_CouleurAlarmeCode->text());
        query.bindValue(":TA_Duree_maxi",     ui->lineEdit_DureeMaxi->text().toInt());
        if (ui->radioButton_Bouton->isChecked())
          query.bindValue(":TA_BoutonMenu",   "B");
        else
          query.bindValue(":TA_BoutonMenu",   "M");

        }
    else        // on est en modif de banque
        {
        requete = "UPDATE " TACHES " SET "
                  " TA_Libelle_tache    = :TA_Libelle_tache,"
                  " TA_Couleur_tache    = :TA_Couleur_tache,"
                  " TA_Couleur_alarme   = :TA_Couleur_alarme,"
                  " TA_Duree_maxi       = :TA_Duree_maxi, "
                  " TA_BoutonMenu       = :TA_BoutonMenu "
                  " WHERE TA_Code_tache = '" + TacheEnCours + "'";

        query.prepare(requete);
        } // fin else Modif
      query.bindValue(":TA_Libelle_tache",  ui->lineEdit_NomTache->text());
      query.bindValue(":TA_Couleur_tache",  ui->lineEdit_CouleurFondCode->text());
      query.bindValue(":TA_Couleur_alarme", ui->lineEdit_CouleurAlarmeCode->text());
      query.bindValue(":TA_Duree_maxi",     ui->lineEdit_DureeMaxi->text().toInt());
      if (ui->radioButton_Bouton->isChecked())
          query.bindValue(":TA_BoutonMenu",   "B");
      else
          query.bindValue(":TA_BoutonMenu",   "M");

    if (!query.exec() )
            {QString zbid = query.lastQuery ();
            QString noerr;
            noerr.setNum(query.lastError().type());
            QMessageBox::warning ( this, tr("Gestion des banques"),
                         "<b>" + tr("Erreur lors de la mise � jour de la table taches : ") + ui->lineEdit_CodeTache->text() +  "</b><br><br>" +
                         "Erreur = (" +  noerr + ") " + query.lastError().text());
            } // fin if erreur exec insert

    ValideEtats();
    ChargeTache();
    ClearFormulaire();
}
//-------------------------------ValideEtats----------------------------------------------------
void DlgTache::ValideEtats()
{
QString     requete;
QTreeWidgetItem *itemEtat;
QSqlQuery   query ( CApp::pCApp()->getDB()->database());
QSqlQuery   querye ( CApp::pCApp()->getDB()->database());

    // d'abord on vire tous les �tats en cours ....
    requete = "DELETE FROM " ETATS_TACHES " WHERE ST_Code_tache = '" + TacheEnCours + "'";
    query.prepare(requete);
    if (!query.exec() )
            {QString zbid = query.lastQuery ();
            QString noerr;
            noerr.setNum(query.lastError().type());
            QMessageBox::warning ( this, tr("Gestion des Etats"),
                         "<b>" + tr("Erreur lors de la mise � jour de la table etats_taches : ") + ui->lineEdit_CodeTache->text() +  "</b><br><br>" +
                         "Erreur = (" +  noerr + ") " + query.lastError().text());
            }


    // on recr�e un enreg pas etat s�lectionn�...
    for (int i=0; i< ui->treeWidget_TacheEtats->topLevelItemCount(); i++)
        {itemEtat = ui->treeWidget_TacheEtats->topLevelItem(i);
        if (itemEtat->text(3) != "OK") continue;

        requete = "INSERT INTO " ETATS_TACHES " ("
                  " ST_Code_tache, ST_Code_Etat) "
                  " VALUES ("
                  " :ST_Code_tache, :ST_Code_Etat ) ";

        querye.prepare(requete);
        querye.bindValue(":ST_Code_Etat",  itemEtat->text(0));
        querye.bindValue(":ST_Code_tache",  TacheEnCours);

        if (!querye.exec() )
            {QString noerr;
            noerr.setNum(querye.lastError().type());
            QMessageBox::warning ( this, tr("Gestion des etats d'une tache"),
                         "<b>" + tr("Erreur lors de la mise � jour de la table etats_taches : ") + ui->lineEdit_CodeTache->text() +  "</b><br><br>" +
                         "Erreur = (" +  noerr + ") " + querye.lastError().text());
            } // fin if erreur exec insert
        } // fin for etats
}

//-------------------------------AnnuleTache----------------------------------------------------
void DlgTache::AnnuleTache()
{
QString     requete;
QSqlQuery   query ( CApp::pCApp()->getDB()->database());

    requete = "DELETE FROM " TACHES " WHERE TA_Code_tache = '" + TacheEnCours + "'";
    query.prepare(requete);
    if (!query.exec() )
            {QString zbid = query.lastQuery ();
            QString noerr;
            noerr.setNum(query.lastError().type());
            QMessageBox::warning ( this, tr("Gestion des banques"),
                         "<b>" + tr("Erreur lors de la mise � jour de la table banque : ") + ui->lineEdit_CodeTache->text() +  "</b><br><br>" +
                         "Erreur = (" +  noerr + ") " + query.lastError().text());
            }
    ChargeTache();
    ClearFormulaire();
}
//-------------------------------------------------------------------------------------
void DlgTache::ClearFormulaire()
{

    ui->lineEdit_CodeTache->clear();
    ui->lineEdit_NomTache->clear();
    ui->pushButton_CouleurAlarme->setStyleSheet("background-color: white;");
    ui->pushButton_CouleurFond->setStyleSheet("background-color: white;");
    ui->lineEdit_CouleurAlarmeCode->clear();
    ui->lineEdit_CouleurFondCode->clear();
    ui->lineEdit_DureeMaxi->clear();

    //********************
    // affichage des taches associ�es
    ui->treeWidget_TacheEtats->clear();
    QTreeWidgetItem *pItemEtat;
    QString requete;
    requete = "SELECT ET_Code_etat, ET_Libelle_etat, ET_Couleur_etat "   // 0-1-2
              " FROM    " ETATS
              " ORDER BY ET_Code_etat";

    QSqlQuery queryb(requete, CApp::pCApp()->getDB()->database());
    while (queryb.isActive() &&  queryb.next())
        { pItemEtat = new QTreeWidgetItem() ;
        pItemEtat->setText(0, queryb.value(0).toString());        // code tache
        pItemEtat->setText(1, queryb.value(1).toString());        // libelle tache
        pItemEtat->setText(2, queryb.value(2).toString());        // couleur
        ui->treeWidget_TacheEtats->addTopLevelItem(pItemEtat);
        }



    //************************



}
//-------------------------------ChargeTache----------------------------------------------------
void DlgTache::ChargeTache()
{
    QString requete;
    QTreeWidgetItem *pItem = 0;

    ui->treeWidget_Tache->clear();

    requete = "SELECT   TA_Code_tache, TA_Libelle_tache, TA_Couleur_tache, TA_Couleur_alarme, "   // 0-1-2-3
              " TA_Duree_maxi, TA_BoutonMenu "                                                    // 4-5
              " FROM    " TACHES
              " ORDER BY TA_Code_tache";

    QSqlQuery query(requete, CApp::pCApp()->getDB()->database());
    while (query.isActive() &&  query.next())
        { pItem = new QTreeWidgetItem() ;
        pItem->setText(0, query.value(0).toString());
        pItem->setText(1, query.value(1).toString());
        ui->treeWidget_Tache->addTopLevelItem(pItem);
        }
    ui->pushButton_annuler->setEnabled(false);
    ui->lineEdit_CodeTache->setEnabled(true);
    TacheEnCours = "";
    ClearFormulaire();
}

void DlgTache::ChoixCouleurAlarme()
{
    QColor color;
    color.setNamedColor(ui->lineEdit_CouleurAlarmeCode->text());
    color = QColorDialog::getColor(color, this);
    if (color.isValid()) {
        ui->pushButton_CouleurAlarme->setStyleSheet("background-color:" + color.name() + ";");
        ui->lineEdit_CouleurAlarmeCode->setText(color.name());
        }
}
void DlgTache::ChoixCouleurFond()
{
    QColor color;
    color.setNamedColor(ui->lineEdit_CouleurFondCode->text());
    color = QColorDialog::getColor(color, this);
    if (color.isValid()) {
        ui->pushButton_CouleurFond->setStyleSheet("background-color:" + color.name()  + ";");
        ui->lineEdit_CouleurFondCode->setText(color.name());
        }
}
