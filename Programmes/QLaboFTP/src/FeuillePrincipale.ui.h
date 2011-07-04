/***************************************************************************
 *   Copyright (C) 2004 by Sébastien SIVERA & Sevin Roland                 *
 *   upsis@club-internet.fr                                                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
//*************************************
//*    INIT DE FEUILLE PRINCIPALE     *
//*************************************
extern QString       Global_PathIni;
extern QString       Global_ParamData;

//------------------------------------------------------ init -----------------------------------------------------------------
void FeuillePrincipale::init()
{   m_pCCoolPopup       = 0;
    m_pCCheckListThread = 0;
    m_pThreadQTimer     = 0;
    m_ResultCheckTimer  = 0;
    m_CouCouEnabled     = 0;
    m_DataBase          = 0;
    m_ItemList.setAutoDelete ( TRUE );   // lors d'un clear les objets pointés seront détruits
    //.......................  Initialisation de la Classe MyFtp .......................
    m_MyFtp            = 0;
    m_autoConnect      = FALSE;
    m_FtpState         = "";
    m_timerAutoConnect = 0;
    m_timerAutoConnect = new QTimer(this);
    connect( m_timerAutoConnect , SIGNAL( timeout() ) , this , SLOT( timerAutoConnectDone() ) );

    m_killMyFtp        = 0;
    m_killMyFtp        = new QTimer(this);
    connect( m_killMyFtp , SIGNAL( timeout() ) , this , SLOT( timerkillMyFtpDone() ) );

    //............................ creer le timer de verification .................................
    m_ResultCheckTimer   = new QTimer;
    connect( m_ResultCheckTimer, SIGNAL(timeout()), this, SLOT(CheckForNewResult()) );
    m_ResultCheckTimer->start(120*1000, FALSE);

    ReadConfig();
    // .................  Initialisation de la Classe d'analyse et de découpage des fichiers .................
    m_CAnalyse = 0;
    // .......................  Création des connections ......................................
    initConnections();

    //.................... essai de mon QWidget LED ...........................................
    m_MyLed = new CClickableLed(this);
    m_MyLed->setText(tr("Etat de la connexion"));
    m_MyLed->adjustSize();
    statusBar()->addWidget( m_MyLed , 0 , TRUE );
    connect( m_MyLed , SIGNAL( clicked() ) , this , SLOT( MyLed_clicked() ) );
    //.................... QWidget LED Check new result.........................................
    m_CheckNewResultLed = new CClickableLed(this);
    m_CheckNewResultLed ->setText(tr("Résultats"));
    m_CheckNewResultLed ->adjustSize();
    statusBar()->addWidget( m_CheckNewResultLed  , 0 , TRUE );
    connect( m_CheckNewResultLed  , SIGNAL( clicked() ) , this , SLOT( CheckNewResultLedclicked() ) );
    //.................... Le bouton de copie.........................................
    m_ButtonCopy = new CClickableLed(this);
    m_ButtonCopy->setText(tr("copier"));
    m_ButtonCopy->setLedPixmap ( GlobalPathAppli + "Images/editraise.png" );
    m_ButtonCopy->adjustSize();
    statusBar()->addWidget( m_ButtonCopy  , 0 , TRUE );
    connect( m_ButtonCopy  , SIGNAL( clicked() ) , this , SLOT( m_ButtonCopyclicked() ) );
    // .................... rend le filtre sur les dates actif .............................
    cbox_filtreDate->setChecked(TRUE);
    le_nom->setMixMode(1);
    le_nom->setText("");
    connect( mle_debut, SIGNAL( returnPressed ()),
             this,      SLOT(   OnSign_DateReturnPressed())
           );
    connect( mle_fin,   SIGNAL( returnPressed ()),
             this,      SLOT(   OnSign_DateReturnPressed())
           );
    connect( le_nom,   SIGNAL( Sig_KeyDown ()),
             this,      SLOT(   OnSign_NomKeyDown())
           );
    connect( le_nom,   SIGNAL( Sig_KeyUp ()),
               this,      SLOT(    OnSign_NomKeyUp())
           );
    connect( le_nom,   SIGNAL(   textChanged (const QString&)),
               this,      SLOT(    le_nom_textChanged(const QString&))
           );
  QString path_img = GlobalPathAppli + "Images/";
  m_GoDatePopup.setPixmap (QPixmap(path_img +"DownExpandArrow.xpm"),    QIconSet::Automatic);
  pushButtonDateFin->setIconSet (m_GoDatePopup);
  pushButtonDateDeb->setIconSet (m_GoDatePopup);

  //..................................... ajuster spliter ...........................................................
  //............................ Placer le spliter dans la bonne position .................................
  QValueList <int> list;
  list.append(50);
  list.append(width()-50);
  CheckForNewResult();
  splitterCentral->setSizes (list );
}
//-------------------------------------- SlotMakeVisible ----------------------------------------------------------------------
void FeuillePrincipale::SlotMakeVisible(const QString&)
{showMinimized () ;
 qApp->processEvents();qApp->processEvents();qApp->processEvents();qApp->processEvents();qApp->processEvents();qApp->processEvents();
 setWindowState(windowState() & ~WindowMinimized | WindowActive);
}

//-------------------------------------- comboBox_ServiceInit ----------------------------------------------------------------------
void FeuillePrincipale::comboBox_ServiceInit()
{//.................................... Combo des services .........................................................
  comboBox_Service->clear();
  m_ServicesList.clear();
  comboBox_Service->insertItem ( tr("Tous services"));
  m_ServicesList.append(tr("Tous services"));
  //................................ recuperer Liste des services ..............................................................
  QString services;
  CGestIni::Param_UpdateFromDisk(GlobalPathAppli + "Modeles/Services.txt", services);
  if (services.length()==0) return;
  char *pt  = (char*)(const char*)services;
  char *deb = pt;
  char *end = pt + services.length();
  while (pt<end)
        { if (pt[0]=='\r' || pt[0]=='\n')
             {QString str = QString::fromLatin1 (deb, pt-deb );
              comboBox_Service->insertItem(str);
              m_ServicesList.append(str);
              while ( (pt[0]=='\r' || pt[0]=='\n') && pt<end) ++pt;
              deb=pt;
             }
          else
             {
              ++pt;
             }
        }
}

//-------------------------------------- comboBox_Service_activated ------------------------------------------------------------------
void FeuillePrincipale::comboBox_Service_activated( const QString &str )
{lv_patient->clear();
 CheckForNewResult(FALSE);
 CGestIni::Param_WriteParam(&Global_ParamData, "Interface", "Service", str);
 CGestIni::Param_UpdateToDisk(Global_PathIni, Global_ParamData);
}

//-------------------------------------- GetService -------------------------------------------------------------------------------
QString FeuillePrincipale::GetService()
{QString str    = comboBox_Service->currentText();
 int p          = str.findRev("=");
 if (p!=-1) str = str.mid(p+1).stripWhiteSpace();
 return str;
}

//-------------------------------------- lv_patient_doubleClicked ------------------------------------------------------------------
void FeuillePrincipale::lv_patient_doubleClicked( QListViewItem * )
{m_ButtonCopyclicked();
}

//-------------------------------------- m_ButtonCopyclicked ------------------------------------------------------------------
void FeuillePrincipale::m_ButtonCopyclicked()
{QString result = tb_detailExamen->text();
 CGestIni::Param_UpdateToDisk(GlobalPathAppli + "ResultHTML.txt", result );
 showMinimized();
}

//-------------------------------------- ReadConfig()------------------------------------------------------------------
void FeuillePrincipale::ReadConfig()
{
    if (m_DataBase)
       {if (m_DataBase->isOpen()) m_DataBase->close();
        QSqlDatabase::removeDatabase (m_DataBase);
       }
    //.................................... recuperation des parametres de connexion ...................................
    if (CGestIni::Param_ReadParam(Global_ParamData, "Connexion", "Parametres", &m_driver, &m_base, &m_user, &m_password, &m_hostname, &m_port)!=0)
       {m_driver   = "QMYSQL3";          // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
        m_base     = "QLaboFTP";         // nom de la base: si QODBC3 -> nom de la source de données (userDSN)
        m_user     =  "root";            // = "root"
        m_password =  "";                // = ""
        m_hostname =  "";                // = "localhost"
        m_port     =  "3306";
       }
    m_DataBase = BaseConnect(m_driver,        // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
                             m_base,          // nom de la base: si QODBC3 -> nom de la source de données (userDSN)
                             m_user,          // = "root"
                             m_password,      // = ""
                             m_hostname,       // = "localhost"
                             m_port,
                             0
                            );
    //.................................... mode de reponse de l'autolocator ...................................
    //                                     de la listViewPatient
    if (CGestIni::Param_ReadParam(Global_ParamData, "AutoLocator", "Liste patients", &m_ListViewPatientMode)!=0)
       {m_ListViewPatientMode = "noRebuilt";
       }
    m_ListViewPatientMode = m_ListViewPatientMode.left(2).lower();
    //.......................... texte du popup ..............................................................
    if (CGestIni::Param_ReadParam(Global_ParamData, "Interface", "Popup message", &m_PopupMessage)!=0)
       {m_PopupMessage = tr("<center><b><u>De nouveaux<br>résultats<br>sont arrivés</u></b></center>");
       }
    if (CGestIni::Param_ReadParam(Global_ParamData, "Interface", "Popup message text param",
                                          &m_PopupMessage_W, &m_PopupMessage_H,
                                          &m_PopupMessage_ForeColor, &m_PopupMessage_BackColor) !=0)
       {m_PopupMessage_W         = "130";
        m_PopupMessage_H         = "30";
        m_PopupMessage_ForeColor = "#0000ff";
        m_PopupMessage_BackColor = "#f8ffa0";
       }
    //...................................... fce verification ds resultats .....................................
    QString fce;
    if (CGestIni::Param_ReadParam(Global_ParamData, "Interface", "Frequence verification", &fce)!=0)
       {fce = "120";
       }
    if (m_ResultCheckTimer) m_ResultCheckTimer->changeInterval ( fce.toInt()*1000);
    //................................ recuperer masque ..............................................................
    CGestIni::Param_UpdateFromDisk(GlobalPathAppli + "Modeles/resultat.txt", m_ResultMasque);
    //............................... combo services ..................................................................
    QString service("");
    if (CGestIni::Param_ReadParam(Global_ParamData, "Interface", "Service", &service)!=0)
       {service = tr("Tous services");
       }
    comboBox_ServiceInit();
    SetComboBoxOnValue(comboBox_Service, service);
}
//-----------------------------------------------------  BaseConnect --------------------------------------------------
QSqlDatabase*  FeuillePrincipale::BaseConnect(const char* driver,        // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
                                              const char* DataBaseName,  // nom de la base: si QODBC3 -> nom de la source de données (userDSN)
                                              const char* user,          // = "root"
                                              const char* pasword,       // = ""
                                              const char* hostname,      // = "localhost"
                                              const char* port,          // = "3306"
                                              QString*    errMess)
    {

        QSqlDatabase *defaultDB = QSqlDatabase::addDatabase( driver , "QLABOFTP_T");
        if (defaultDB<=0) return 0;
        defaultDB->setDatabaseName( DataBaseName );
        defaultDB->setUserName(     user );
        defaultDB->setPassword(     pasword );
        defaultDB->setHostName(     hostname);
        defaultDB->setPort(         QString(port).toInt());
        if ( ! defaultDB->open() )
           {QString qstr = "";
            qstr += tr("Failed to open database: ") + QString(driver) + "  " + QString(DataBaseName) + "\r\n" +
                     defaultDB->lastError().driverText() + "\r\n" + defaultDB->lastError().databaseText();
            qWarning(qstr);
            if (errMess) *errMess = qstr;
            return 0;
           }
        return defaultDB;
    }

//----------------------------------------- SetComboBoxOnValue -----------------------------------------
int FeuillePrincipale::SetComboBoxOnValue(QComboBox *pcombo, const QString &value)
{int nb = pcombo->count();
 for (int i=0; i<nb; ++i)
     {if ( pcombo->text(i) ==  value)
         { pcombo->setCurrentItem (i);
           return i;
         }
     }
 return -1;
}

void FeuillePrincipale::fileNew()
{

}


void FeuillePrincipale::fileOpen()
{

}


void FeuillePrincipale::fileSave()
{

}


void FeuillePrincipale::fileSaveAs()
{

}


void FeuillePrincipale::filePrint()
{

}


void FeuillePrincipale::fileExit()
{

}


void FeuillePrincipale::editUndo()
{

}


void FeuillePrincipale::editRedo()
{

}


void FeuillePrincipale::editCut()
{

}


void FeuillePrincipale::editCopy()
{

}


void FeuillePrincipale::editPaste()
{

}


void FeuillePrincipale::editFind()
{//-------------------------------------- OnSign_NomKeyDown()------------------------------------


}


void FeuillePrincipale::helpIndex()
{

}


void FeuillePrincipale::helpContents()
{

}

void FeuillePrincipale::helpAbout()
{

}
//-------------------------------------- OnSign_NomKeyDown()------------------------------------
void FeuillePrincipale::OnSign_NomKeyDown()
{QListViewItem *pQListViewItem =  lv_patient->currentItem ();
 if ( pQListViewItem == 0)                 return;
 if ( pQListViewItem->itemBelow () ==0 )   return;
 pQListViewItem =  pQListViewItem->itemBelow ();
 lv_patient->setCurrentItem (pQListViewItem );
 lv_patient->ensureItemVisible ( pQListViewItem );
 m_CAnalyse->PatientItemSetPixmap(pQListViewItem, "gray");
}

//-------------------------------------- OnSign_NomKeyUp()------------------------------------
void FeuillePrincipale::OnSign_NomKeyUp()
{QListViewItem *pQListViewItem =  lv_patient->currentItem ();
 if ( pQListViewItem == 0 )                return;
 if ( pQListViewItem->itemAbove () ==0 )   return;
 pQListViewItem = pQListViewItem->itemAbove ();
 lv_patient->setCurrentItem (pQListViewItem );
 lv_patient->ensureItemVisible ( pQListViewItem );
 m_CAnalyse->PatientItemSetPixmap(pQListViewItem, "gray");
}


//--------------------------------------closeEvent()------------------------------------
void FeuillePrincipale::closeEvent(QCloseEvent *e)
{  int ret = QMessageBox::information( this, tr("Quitter QLaboFTP"),
                                        tr ( "Vous voulez vraiment quitter QLaboFTP ?\n"
                                             "ou simplement le réduire ?"
                                           ) ,
                                             tr("Quitter"), tr("Réduire"), tr("Annuler"),
                                             1, 1 );
       if      (ret== 1) {showMinimized();  e->ignore(); return;}
       else if (ret==2)  {                  e->ignore(); return;}
    StopCheckListThread();
    if (m_ResultCheckTimer)
       {delete m_ResultCheckTimer;
        m_ResultCheckTimer = 0;   // parano
       }
    if (m_pCCoolPopup) {
        delete m_pCCoolPopup;
        m_pCCoolPopup = 0;
    }
    if (m_MyFtp) {
        delete m_MyFtp;
        m_MyFtp = 0;
    }
    if (m_CAnalyse) {
        delete m_CAnalyse;
        m_CAnalyse = 0;
    }
    if (m_DataBase)
       {if (m_DataBase->isOpen()) m_DataBase->close();
        QSqlDatabase::removeDatabase (m_DataBase);
       }
    e->accept();
}

//--------------------------------------OnSign_DateReturnPressed()--------------------------------------------
void FeuillePrincipale::OnSign_DateReturnPressed()
{le_nom->setFocus();
}

//--------------------------------------initConnections()------------------------------------------------------
// Connecteur qui créé les Classes CAnalyse et MyFtp pour les différentes connections
void FeuillePrincipale::initConnections()
{
    if (m_CAnalyse == 0) {
        m_CAnalyse = new CAnalyse(m_driver, m_base, m_user, m_password, m_hostname, m_port, this,0);
        // si aucune connection n'est en cours alors on se connecte, en créant une nouvelle
        // instance de la classe MyFtp
        connectFTP();
    }
}

//-----------------------------------connectFTP()---------------------------------------------------------------
void FeuillePrincipale::connectFTP()
{
    QString etat;
    if (CGestIni::Param_ReadParam(Global_ParamData, "Interface", "ClientFTP", &etat)==0) {
        if ( etat.lower() == "oui" ) {
            QString log, remove;
            bool b_log = FALSE;
            bool b_remove = FALSE;
            if (CGestIni::Param_ReadParam(Global_ParamData, "ConnexionFTP", "Log", &log)==0) {
                if ( log.stripWhiteSpace().lower() == "oui") b_log = TRUE;
            }
            if (CGestIni::Param_ReadParam(Global_ParamData, "ConnexionFTP", "EffacementDistant", &remove)==0) {
                if ( remove.lower() == "oui") b_remove = TRUE;
            }
            if (m_MyFtp == 0) {
                m_MyFtp = new MyFtp(this,0,b_log,b_remove);
                m_autoConnect = TRUE;
                // gestin de la couleur de led
                connect( m_MyFtp ,    SIGNAL( ftpStateChanged( QString ) ) , this , SLOT( changeLed( QString ) ) );
                connect( m_MyFtp ,    SIGNAL( newFileDownloaded( QString ) ) , m_CAnalyse , SLOT( fileDownloaded( QString ) ) );
                connect( m_CAnalyse , SIGNAL( fileAnalysed( QString ) ) ,      m_MyFtp ,    SLOT( removeFile( QString ) ) );
                connect( m_CAnalyse , SIGNAL( fileUseless( QString ) ) ,       m_MyFtp ,    SLOT( uselessFile( QString ) ) );
                connect( m_CAnalyse , SIGNAL( newFileIznogood( QString ) ) ,      this ,    SLOT( OnNewFileIznogood( QString ) ) );

            }
        }
    }
}

//----------------------------------- OnNewFileIznogood ----------------------------------
void FeuillePrincipale::OnNewFileIznogood( QString file)
{m_MyFtp->removeFile( file );
 bool     b_log = FALSE;
 QString    log = "";
 if (CGestIni::Param_ReadParam(Global_ParamData, "ConnexionFTP", "Log", &log)==0 && log.stripWhiteSpace().lower() == "oui") b_log = TRUE;
 if (b_log)
    {Copy_File( file, GlobalPathAppli + "NonConformes" , 0);
    }
 QString date = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm");
 m_MyFtp->toLog(tr("Fichier non conforme    : ") + file + "   le : " + date);
}

//---------------------------------- Copy_File --------------------------------------------------------------
// ENTREE: const QString &fileSrc: fichier source chemin+file
//         const QString &pathDst: chemin de destination sans separateur de fin.
//         QString *file_name : nom du fichier de destination (si zero il sera extrait de celui source)
QString FeuillePrincipale::Copy_File(const QString &fileSrc, const QString &pathDst, QString *file_name /*=0*/)
{
//................. choisir le fichier image src �  insérer .................................................

  QString fileName = "";
  QFile* pfileSrc = new QFile( fileSrc );
  if (pfileSrc==0)                                                              return fileName;
  if (file_name) fileName  = *file_name;
  else           fileName  = QFileInfo( *pfileSrc ).fileName();
  QFile* pfileDst = new QFile( pathDst + QDir::separator() +  fileName);
  if (pfileDst==0)                       {delete pfileSrc;                      return fileName;}

  //.................... si le dossier src n'est pas egal au dossier dst .......................
  //                     alors copier l'image src dans le dossier destination
  //                     sinon l'image s'y trouve forcémént
  if (pathDst != QFileInfo( *pfileSrc ).dirPath ( TRUE ))
     {char *buffer = new char[32000];
      Q_LONG        len_read;
      if (buffer==0)                         {delete pfileSrc; delete pfileDst; return fileName;}
      QFile::remove ( pathDst + QDir::separator() + fileName);   // eventuellement effacer un  du même nom

      if ( !pfileSrc->open( IO_ReadOnly ) )  {delete pfileSrc; delete pfileDst; return fileName;}
      if ( !pfileDst->open( IO_WriteOnly ) ) {delete pfileDst; pfileSrc->close(); delete pfileSrc; return fileName;}

      do{
         len_read = pfileSrc->readBlock (buffer, 32000 );
         if (len_read!=-1) pfileDst->writeBlock (buffer , len_read);
        } while (len_read == 32000);

      pfileSrc->close ();
      pfileDst->close ();
      delete[] buffer;
     }
 return fileName;
}
//-----------------------------------outilsFentre_de_TestAction_activated()----------------------------------
void FeuillePrincipale::outilsFentre_de_TestAction_activated()
{
     CouCouStop(m_pCCoolPopup);
     QFileDialog *fd = new QFileDialog (GlobalPathAppli +  TEMP_FOLDER,
                                       tr( "HPRIM-Files (*.hpr );;"
                                           "All Files (*)" ),
                                       this,
                                       "OuvrirDlg"
                                      ) ;
    if (fd==0)                                             return;
    fd->setMode(QFileDialog::ExistingFiles);    // selection multiple
    if ( fd->exec() == QDialog::Accepted )
       {QStringList listFile = fd->selectedFiles ();
        for ( QStringList::Iterator it = listFile.begin(); it != listFile.end(); ++it )
            {//m_CAnalyse->GotoDebug();
             if ( !(*(it)).isEmpty() ) m_CAnalyse->fileDownloaded( *(it));
             //if ( !(*(it)).isEmpty() )m_MyFtp->signalFileDownloaded( *(it) );
            }
        CheckForNewResult();
       }
    delete fd;
}

//-----------------------------------cbox_filtreDate_stateChanged()----------------------------------
void FeuillePrincipale::cbox_filtreDate_stateChanged( int actived)
{
    if (actived) {
        mle_debut->setEnabled(true);
        mle_fin->setEnabled(true);
    } else {
        mle_debut->setEnabled(false);
        mle_fin->setEnabled(false);
    }
    //lanceRecherche();
    lv_patient->clear();
    StopCheckListThread();
    CheckForNewResult(FALSE);
    mle_debut->setFocus();
}

//-----------------------------------lv_patient_selectionChanged()----------------------------------
void FeuillePrincipale::lv_patient_selectionChanged( QListViewItem *item)
{displayPatientResults(item);
 m_CAnalyse->PatientItemSetPixmap(item, "gray");
}

//----------------------------------- displayPatientResults() ----------------------------------
void FeuillePrincipale::displayPatientResults( QListViewItem *item )
{   QString     modele;
    QStringList examList;

    if (m_CAnalyse)
       {m_CAnalyse->getDetailsExamens(item->text(4) , examList);
        if (examList.count()==0) return;

        QString result = QString("<html><head><meta name=\"qrichtext\" content=\"1\" />"
                                 "<title>Prescription</title>"
                                 "</head>"
                                 "<body style=\"font-size:10pt;font-family:Arial Narrow\"><left>")+
                         m_CAnalyse->FusionneModeleWithResultList(item->text(4), examList, m_ResultMasque, m_ServicesList)  +
                         "<br></left></body></html>";
        tb_detailExamen->setText(result);
       }
}

//-----------------------------------mle_debut_lostFocus()----------------------------------
void FeuillePrincipale::mle_debut_lostFocus()
{
    int jour, mois, annee;
    QDate dateDebut;

    if (mle_debut->text().length() == 8) {
        jour  = mle_debut->text().mid(0,2).toInt();
        mois  = mle_debut->text().mid(2,2).toInt();
        annee = mle_debut->text().mid(4,4).toInt();
        if ( dateDebut.setYMD( annee , mois , jour ) != true) {
            QMessageBox mb( tr("Date incohérente"),
                            tr("La date de début n'est pas correcte\n"),
                            QMessageBox::Critical,
                            QMessageBox::Ok | QMessageBox::Default,0,0);
            mb.exec();
            mle_debut->setFocus();
        } else {
            //lanceRecherche();
        }
    } else {
        //lanceRecherche();
    }
}


//-----------------------------------mle_fin_lostFocus()----------------------------------
void FeuillePrincipale::mle_fin_lostFocus()
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

//-----------------------------------lanceRecherche()----------------------------------
// Ne devrait plus être appelée depuis que le thread est au point
void FeuillePrincipale::lanceRecherche()
{
    QDate dateDebut(QDate::currentDate());
    QDate dateFin(QDate::currentDate());
    dateDebut.addDays (-1);
    dateFin.addDays (1);
    if ( cbox_filtreDate->isChecked() )
       {int jour, mois, annee;
        QString text = mle_debut->text();
        jour  = text.mid(0,2).toInt();
        mois  = text.mid(2,2).toInt();
        annee = text.mid(4,4).toInt();
        if (QDate::isValid ( annee, mois, jour ) ) dateDebut.setYMD (annee , mois  , jour);
        mle_debut->setText(dateDebut.toString("ddMMyyyy"));
        text  = mle_fin->text();
        jour  = text.mid(0,2).toInt();
        mois  = text.mid(2,2).toInt();
        annee = text.mid(4,4).toInt();
        if (QDate::isValid ( annee, mois, jour ) ) dateFin.setYMD (annee , mois  , jour);
        mle_fin->setText(dateFin.toString("ddMMyyyy"));
       }

    QString Nom = le_nom->text();

    if (m_CAnalyse)
       {QApplication::setOverrideCursor( QCursor( Qt::WaitCursor ) );
        m_CAnalyse->getPatientsList( dateDebut.toString("yyyyMMdd") , dateFin.toString("yyyyMMdd") , Nom , GetService(), m_ResultMasque, lv_patient );
        if (lv_patient->firstChild())
           {lv_patient->setSelected(lv_patient->firstChild(),true);
           }
        QApplication::restoreOverrideCursor();
       }
}

//----------------------------------- pushButtonDateDeb_clicked() ----------------------------------
void FeuillePrincipale::pushButtonDateDeb_clicked()
{Dlg_Calendar          *dlg  = new Dlg_Calendar(this, "Calendar_Dial", TRUE, WStyle_Customize | WStyle_NormalBorder | WStyle_Title |WStyle_MinMax | WStyle_SysMenu);
 if (dlg ==0)                                                   return;
 dlg->setCaption(tr("Date de début"));
 dlg->move ( QCursor::pos().x(), QCursor::pos().y() );
 QString text = mle_debut->text();
 int jour, mois, annee;
 jour  = text.mid(0,2).toInt();
 mois  = text.mid(2,2).toInt();
 annee = text.mid(4,4).toInt();
 if (QDate::isValid ( annee, mois, jour ) )
    {dlg->setDate(QDate(annee, mois, jour));
    }
 if (dlg->exec()== QDialog::Accepted )
    {mle_debut->setText(dlg->getDate().toString("ddMMyyyy"));
     if (cbox_filtreDate->isChecked()){
                                         //lanceRecherche();
                                         lv_patient->clear();
                                         StopCheckListThread();
                                         CheckForNewResult(FALSE);
                                       }
     else                               cbox_filtreDate->setChecked(TRUE);
     le_nom->setFocus();
    }
 delete dlg;
}


//----------------------------------- pushButtonDateFin_clicked() ----------------------------------
void FeuillePrincipale::pushButtonDateFin_clicked()
{Dlg_Calendar          *dlg  = new Dlg_Calendar(this, "Calendar_Dial", TRUE, WStyle_Customize | WStyle_NormalBorder | WStyle_Title |WStyle_MinMax | WStyle_SysMenu);
 if (dlg ==0)                                                   return;
 dlg->setCaption(tr("Date de fin"));
 dlg->move ( QCursor::pos().x(), QCursor::pos().y() );
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
     if (cbox_filtreDate->isChecked()){
                                         //lanceRecherche();
                                         lv_patient->clear();
                                         StopCheckListThread();
                                         CheckForNewResult(FALSE);
                                       }
     else                               cbox_filtreDate->setChecked(TRUE);
     le_nom->setFocus();
    }
 delete dlg;
}

//---------------------------------------- changeLed() ---------------------------------------------
void FeuillePrincipale::changeLed( QString state )
{
    m_FtpState = state;
    if (state == tr("Transfert en cours")) {
        //pushButtonConnexion->setIconSet (m_IconConnexionGet);
        m_MyLed->setLedColor(CClickableLed::Red);
    }

    if (state == tr("Utilisateur connecté")) {
        //pushButtonConnexion->setIconSet (m_IconConnexionUp);
        m_MyLed->setLedColor(CClickableLed::Green);
        outilsConnecter_le_FTPAction->setText( tr("Déconnecter le FTP") );
        if (m_timerAutoConnect->isActive()) {
            m_timerAutoConnect->stop();
        }
        if (m_killMyFtp->isActive()) {
            m_killMyFtp->stop();
        }
    }

    if (state == tr("Deconnecté")) {
        //pushButtonConnexion->setIconSet (m_IconConnexionDown);
        m_MyLed->setLedColor(CClickableLed::Gray);
        outilsConnecter_le_FTPAction->setText( tr("Connecter le FTP") );
        if (m_killMyFtp->isActive()) {
            m_killMyFtp->stop();
        }

        if (m_MyFtp) {
            delete m_MyFtp;
            m_MyFtp = 0;
        }

        if (m_autoConnect) {
            //m_timerAutoConnect->start(30000); // 2 minutes
            m_timerAutoConnect->changeInterval(30000); // 2 minutes
        }
    }

    if (state == /*"Recherche de l'hote" ||*/ tr("Connexion en cours") /*|| "Connecté"*/) {
        if (m_timerAutoConnect->isActive()) {
            m_timerAutoConnect->stop();
        }
        if (m_killMyFtp->isActive()) {
            m_killMyFtp->stop();
        }
        //m_killMyFtp->start(10000);
        m_killMyFtp->changeInterval(10000);
    }
}

//-------------------------------- Connecter_le_FTP_clicked() --------------------------------------
void FeuillePrincipale::Connecter_le_FTP_clicked()
{
    QString libelle = outilsConnecter_le_FTPAction->text();
    if (libelle == tr("Connecter le FTP")) {
        if (m_CAnalyse) {
            connectFTP();
        }
    }
    if (libelle == tr("Déconnecter le FTP")) {
        m_autoConnect = FALSE;
        m_MyFtp->disconnectFTP();

    }
}

//------------------------------------- timerAutoConnectDone() -------------------------------------
void FeuillePrincipale::timerAutoConnectDone()
{
    if (m_CAnalyse) {
        connectFTP();
    }
}

//-------------------------------------- timerkillMyFtpDone() --------------------------------------
void FeuillePrincipale::timerkillMyFtpDone()
{
    changeLed(tr("Deconnecté"));
}

//----------------------------------------- MyLed_clicked() ----------------------------------------
void FeuillePrincipale::MyLed_clicked()
{
    if (m_MyFtp && (m_FtpState == tr("Utilisateur connecté"))) {
        m_MyFtp->LetScanFTP();
    }
}
//-----------------------------------le_nom_textChanged()----------------------------------
void FeuillePrincipale::le_nom_textChanged( const QString &text )
{   if (m_ListViewPatientMode=="re")                              // reconstruire
       {lv_patient->clear();
        StopCheckListThread();
        CheckForNewResult(FALSE);
       }
    else if (m_ListViewPatientMode=="th")          // ThreadOff
       {lanceRecherche();
       }
    else
       {QListViewItem *pQListViewItem;
        if ( (pQListViewItem = lv_patient->findItem ( text, 0, Qt::BeginsWith)) != 0)
           {lv_patient->setCurrentItem ( pQListViewItem );
            lv_patient->setSelected ( pQListViewItem , TRUE );
            lv_patient->ensureItemVisible (pQListViewItem );
           }
       }
}

//----------------------------------------- CheckNewResultLedclicked() ----------------------------------------
void FeuillePrincipale::CheckNewResultLedclicked()
{ Global_pCGestIni->Param_UpdateFromDisk(Global_PathIni, Global_ParamData);
  ReadConfig();
  CheckForNewResult();
}

//---------------------------------------- CheckForNewResult ----------------------------------------------------------
//  N'efface pas la liste auparavant et met à jour juste les nouveautés avec popup activé
void FeuillePrincipale::CheckForNewResult()
{  StopCheckListThread();
   CheckForNewResult(TRUE);
}

//---------------------------------------- CheckForNewResult ----------------------------------------------------------
void FeuillePrincipale::CheckForNewResult(bool coucouEnabled)
{
 if (m_CAnalyse == 0)                                          return;
 //.................. cassos si thread pas fini .......................................
 //                   le laisser finir
 if (m_pCCheckListThread)                                      return;

 m_CouCouEnabled = coucouEnabled;
 //....................... verifier dates .............................................
 QDate dateDeb  (QDate::currentDate());
 QDate dateFin  (QDate::currentDate());
 if ( cbox_filtreDate->isChecked() )
    {int jour, mois, annee;
     QString text = mle_debut->text();
     jour  = text.mid(0,2).toInt();
     mois  = text.mid(2,2).toInt();
     annee = text.mid(4,4).toInt();
     if (QDate::isValid ( annee, mois, jour ) ) dateDeb.setYMD (annee , mois  , jour);
     mle_debut->setText(dateDeb.toString("ddMMyyyy"));
     text  = mle_fin->text();
     jour  = text.mid(0,2).toInt();
     mois  = text.mid(2,2).toInt();
     annee = text.mid(4,4).toInt();
     if (QDate::isValid ( annee, mois, jour ) ) dateFin.setYMD (annee , mois  , jour);
     mle_fin->setText(dateFin.toString("ddMMyyyy"));
    }
 //........................... recuperer liste des codes analyse présents dans ............
 //                            le modele de presentation des données
 m_ResultListToCheck =  m_CAnalyse->GetResultTypeListFromModele(m_ResultMasque);

 //.................. créer thread de verification ........................................
 //                   de la liste

 QString name = "";
 if (m_ListViewPatientMode=="re" || m_ListViewPatientMode=="th") name = le_nom->text();
 m_pCCheckListThread  = new CCheckListThread( m_DataBase,
                                              &m_ItemList, dateDeb.toString("yyyyMMdd") ,
                                              dateFin.toString("yyyyMMdd") , name, GetService(),
                                              m_ResultListToCheck);
 if (m_pCCheckListThread  ==0)  return;                                // si echec création du thread cassos

 //................. si creation et initialisation du thread OK ........................
 if (m_pCCheckListThread->IsReady())
    {m_CheckNewResultLed->setLedColor(CClickableLed::Red);
     QApplication::setOverrideCursor( QCursor( Qt::WaitCursor ) );
     m_pCCheckListThread->start();                   // lancer le  thread
      //.......... et un petit timer qui verifiera régulièrement si le thread a fini son job ...........
     m_pThreadQTimer= new QTimer(this);
     if (m_pThreadQTimer)
        {connect(m_pThreadQTimer, SIGNAL(timeout()), this, SLOT(timerCheckListThreadDone()) );
         m_pThreadQTimer->start(400, FALSE);
        }
    }
 //................. si echec initialisation thread ......................................
 //                  on fait le ménage
 else
    {StopCheckListThread();
    }
}

//---------------------------------------- timerCheckListThreadDone ---------------------------------------------
void FeuillePrincipale::timerCheckListThreadDone()
{if (m_pCCheckListThread==0) return;
 if (m_pCCheckListThread->IsFini())
    {StopCheckListThread();
     if (m_CAnalyse->CompareListes( lv_patient, m_ItemList ) && m_CouCouEnabled) CouCou();     //  ya du nouveau
     m_ItemList.clear();          // n'en a plus besoin
     m_CouCouEnabled = FALSE;     // par defaut pas de popup si du nouveau
     //............ reafficher l'item courant ..........................
     QListViewItem *pQListViewItem = lv_patient->currentItem ();
     if (pQListViewItem)
        {displayPatientResults(pQListViewItem);
         lv_patient->setSelected ( pQListViewItem , TRUE );
         lv_patient->ensureItemVisible (pQListViewItem );
        }
     return;
    }
}

//---------------------------------------- StopCheckListThread() ---------------------------------------------
void FeuillePrincipale::StopCheckListThread()
{if (m_pThreadQTimer)
    { m_pThreadQTimer->stop();
      delete m_pThreadQTimer;
      m_pThreadQTimer = 0;
    }
 if (m_pCCheckListThread==0) return;
 m_pCCheckListThread->stop();
 //m_pCCheckListThread->wait();                // pas glop
 while (m_pCCheckListThread->running() ) ;     // ça a l'air de fonctionner
 delete m_pCCheckListThread;
 m_pCCheckListThread = 0;
 QApplication::restoreOverrideCursor();
 m_CheckNewResultLed->setLedColor(CClickableLed::Gray);

}
//------------------------------------------------- CouCou ----------------------------------------------------------------
void FeuillePrincipale::CouCou()
{if (m_pCCoolPopup) delete m_pCCoolPopup;
 m_pCCoolPopup = new     CCoolPopup (GlobalPathAppli + "Images/Popup4.xpm"            ,
                                     0             ,
                                     9             ,
                                     1             ,
                                     m_PopupMessage_W.toInt()          ,
                                     m_PopupMessage_H.toInt()          ,
                                     m_PopupMessage                    ,
                                     QColor(m_PopupMessage_ForeColor)  ,
                                     QColor(m_PopupMessage_BackColor)
                                    );
 if (m_pCCoolPopup==0) return;
 m_pCCoolPopup->setIcon(GlobalPathAppli + "Images/MoleculeMod00.png");
 m_pCCoolPopup->setCaption(tr("Nouveaux résultats"));
 connect( m_pCCoolPopup,        SIGNAL( Sign_PopupUp(CCoolPopup *) ),
          this,                 SLOT(CouCouUp (CCoolPopup *))
        );
 connect( m_pCCoolPopup,        SIGNAL( Sign_PopupDown(CCoolPopup *) ),
          this,                 SLOT(CouCouStop(CCoolPopup *))
        );
 connect( m_pCCoolPopup,        SIGNAL( Sign_Clicked() ),
          this,                 SLOT(CouCouClicked())
        );
}

//--------------------------------------- CouCouClicked ------------------------------------------------------------------------
void FeuillePrincipale::CouCouClicked()
{if (m_pCCoolPopup == 0) return;
 CouCouStop(m_pCCoolPopup);
 setActiveWindow ();
 showNormal();
 //pCCoolPopup->Disappear();
}

//--------------------------------------- CouCouUp ------------------------------------------------------------------------
void FeuillePrincipale::CouCouUp(CCoolPopup * /*pCCoolPopup*/)
{//pCCoolPopup->Disappear();
}

//--------------------------------------- CouCouStop ------------------------------------------------------------------------
void FeuillePrincipale::CouCouStop(CCoolPopup * pCCoolPopup)
{if (m_pCCoolPopup == 0) return;
 if (m_pCCoolPopup==pCCoolPopup)
    {pCCoolPopup->disconnect( SIGNAL(Sign_PopupUp(CCoolPopup *)) );
     pCCoolPopup->disconnect( SIGNAL(Sign_PopupDown(CCoolPopup *)) );
     QTimer::singleShot(0, this, SLOT(CouCouDestroy()) );
    }
}

//--------------------------------------- CouCouDestroy ------------------------------------------------------------------------
void FeuillePrincipale::CouCouDestroy()
{if (m_pCCoolPopup) delete m_pCCoolPopup;
 m_pCCoolPopup = 0;
}





