/********************************* C_DlgApropos.cpp *********************************
*  #include "C_DlgApropos.h"                                                        *
* ...............................................................................*
*   Project   :  MedinTux  (typographie made in france)                          *
*   Copyright : (C) 2004-2005-2006-2007-2008-2009-2010 and for the eternity      *
*   by        :  Sevin Roland     from   MedinTux project                        *
*   E-Mail    : roland-sevin@medintux.org                                        *
*   Web site  : www.medintux.org                                                 *
* ...............................................................................*
*                                                                                *
*   This program is free software; you can redistribute it and/or modify         *
*   it under the terms of the CeCILL Version 1 du 21/06/2004                     *
*   License (GPL compatible)                                                     *
*                              http://www.cecill.info/                           *
*   as published by :                                                            *
*                                                                                *
*   Commissariat �  l'Energie Atomique                                            *
*   - CEA,                                                                       *
*                            31-33 rue de la Fédération, 75752 PARIS cedex 15.   *
*                            FRANCE                                              *
*   Centre National de la Recherche Scientifique                                 *
*   - CNRS,                                                                      *
*                            3 rue Michel-Ange, 75794 Paris cedex 16.            *
*                            FRANCE                                              *
*   Institut National de Recherche en Informatique et en Automatique             *
*   - INRIA,                                                                     *
*                            Domaine de Voluceau, Rocquencourt, BP 105, 78153    *
*                            FRANCE                                              *
*                                                                                *
*         This program is distributed in the hope that it will be useful,        *
*         but WITHOUT ANY WARRANTY; without even the implied warranty of         *
*         MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                   *
*         CeCILL  License (GPL compatible) for more details.                     *
*                                                                                *
**********************************************************************************/

#include <QFile>
#include <QFileDialog>
#include <QByteArray>
#include <QPrintDialog>
#include <QPrinter>
#include <QDir>
#include <QMessageBox>
#include <QDataStream>
#include <QWebSettings>
#include <QCoreApplication>
#include <QDesktopServices>
#include <QProcess>
#include <QList>

#include "C_DlgApropos.h"
#include "ui_C_DlgApropos.h"
#include "../../MedinTuxTools-QT4/CGestIni.h"
#include "../../MedinTuxTools-QT4/Theme/Theme.h"

#ifdef Q_WS_WIN
   #define F_EXE ".exe"
#else
   #define F_EXE ""
#endif
//-----------------------------------------------------  C_DlgApropos -------------------------------------------
C_DlgApropos::C_DlgApropos(QWidget *parent,
                           const QString &pathAppli,
                           const QString& module,
                           const QString& description,
                           const QString& version,
                           const QString &pathChangements,
                           const QString &pathIcone,
                           const QString &pathHelp,
                           const QString &pathApropos) :
    QDialog(parent),  ui(new Ui::C_DlgApropos)
{ ui->setupUi(this);
  m_PathAppli       =   pathAppli;
  m_PathPageHelp    =   "";
  m_Wdg_Apropos     =	ui->tabWidget->widget ( 0 );
  m_Wdg_Licence     =	ui->tabWidget->widget ( 1 );
  m_Wdg_Changements =	ui->tabWidget->widget ( 2 );
  m_Wdg_Help        =   ui->tabWidget->widget ( 3 );

  QWebSettings::globalSettings()->setAttribute(QWebSettings::JavascriptCanOpenWindows,TRUE);
  QWebSettings::globalSettings()->setAttribute(QWebSettings::JavascriptCanAccessClipboard,TRUE);
  ui->webView_Help->page()->setLinkDelegationPolicy ( QWebPage::DelegateAllLinks );      //QWebPage::DelegateAllLinks
  ui->webView_Apropos->page()->setLinkDelegationPolicy ( QWebPage::DelegateAllLinks );   //QWebPage::DelegateAllLinks

#if   defined(Q_WS_WIN)
   if (!QFile::exists("C:/MedinTuxRo.txt"))                  ui->tabWidget->removeTab (2);
#elif defined(Q_WS_X11)
   if (!QFile::exists(QDir::homePath ()+"/MedinTuxRo.txt"))  ui->tabWidget->removeTab (2);
#elif defined(Q_WS_MAC)
   if (!QFile::exists(QDir::homePath ()+"/MedinTuxRo.txt"))  ui->tabWidget->removeTab (2);
#endif

  QString title = "";


  if (qApp->arguments().size() > 1 ) ui->groupBox_readNumVers->hide();
  connect( ui->pushButtonClose,          SIGNAL(clicked()), this, SLOT(accept()));
  connect( ui->pushButton_GetNumVersion, SIGNAL(clicked()), this, SLOT(Slot_GetNumVersionFromBin()));
  connect( ui->pushButton_Changements,   SIGNAL(clicked()), this, SLOT(Slot_ShowChangements()));

  //........... enregistrement numero de version ...................................
  ui->pushButtonrecordNumVers->setEnabled(FALSE);
  //........... web tools ...................................
  ui->pushButton_Home->setIcon  ( Theme::getIcon("22x22/home.png") ) ;
  ui->pushButton_Print->setIcon ( Theme::getIcon("22x22/fileprint.png") ) ;
  ui->pushButton_find->setIcon  ( Theme::getIcon("22x22/edit-find.png") ) ;
  ui->pushButton_Back->setIcon    ( ui->webView_Help->pageAction(QWebPage::Back)->icon() ) ;
  ui->pushButton_Reload->setIcon  ( ui->webView_Help->pageAction(QWebPage::Reload)->icon() ) ;
  ui->pushButton_Forward->setIcon ( ui->webView_Help->pageAction(QWebPage::Forward)->icon() ) ;
  ui->pushButton_Stop->setIcon    ( ui->webView_Help->pageAction(QWebPage::Stop)->icon() ) ;

  connect( ui->lineEdit_url,            SIGNAL(returnPressed()),                      this, SLOT(Slot_LocationEdit_returnPressed()));
  connect( ui->lineEdit_find,           SIGNAL(returnPressed()),                      this, SLOT(Slot_WebFindEdit_returnPressed()));
  connect( ui->lineEdit_find,           SIGNAL(textChanged ( const QString &  ) ),    this, SLOT(Slot_WebFindEdit_textChanged (const QString & )) );
  connect( ui->webView_Help,            SIGNAL(urlChanged (  const QUrl &  )),        this, SLOT(Slot_webView_urlChanged ( const QUrl &  )));
  connect( ui->webView_Help,            SIGNAL(linkClicked ( const QUrl &  )),        this, SLOT(Slot_webView_linkClicked ( const QUrl &  )));  // marche po
  connect( ui->webView_Apropos,         SIGNAL(linkClicked ( const QUrl &  )),        this, SLOT(Slot_webView_Apropos_linkClicked ( const QUrl &  )));  // marche po

  connect( ui->pushButton_Home,         SIGNAL(clicked ( bool )),                   this, SLOT(Slot_actionWebHome  (bool)) );
  connect( ui->pushButton_Print,        SIGNAL(clicked ( bool )),                   this, SLOT(Slot_actionWebPrint (bool)) );
  connect( ui->pushButton_find,         SIGNAL(clicked ( bool )),                   this, SLOT(Slot_actionWebFind  (bool)) );

  connect( ui->pushButton_Back,         SIGNAL(clicked ( bool )),       ui->webView_Help, SLOT(back ()) );
  connect( ui->pushButton_Reload,       SIGNAL(clicked ( bool )),       ui->webView_Help, SLOT(reload ()) );
  connect( ui->pushButton_Forward,      SIGNAL(clicked ( bool )),       ui->webView_Help, SLOT(forward ()) );
  connect( ui->pushButton_Stop,         SIGNAL(clicked ( bool )),       ui->webView_Help, SLOT(stop ()) );


  connect( ui->webView_Help,            SIGNAL(loadStarted (  )),       this,             SLOT(Slot_On_webView_Help_loadStarted ()) );
  connect( ui->webView_Help,            SIGNAL(loadProgress (int)),     this,             SLOT(Slot_On_webView_Help_loadProgress (int)) );
  connect( ui->webView_Help,            SIGNAL(loadFinished (bool  )),  this,             SLOT(Slot_On_webView_Help_loadFinished (bool)) );
  connect( ui->webView_Help,            SIGNAL(statusBarMessage(const QString &)),this,   SLOT(Slot_On_webView_Help_statusBarMessage (const QString &)) );

  //void	loadProgress ( int progress )
  //void	loadStarted ()
  //void	loadFinished ( bool ok )
  //void	selectionChanged ()
  //void	statusBarMessage ( const QString & text )
  //void	titleChanged ( const QString & title )
  //void	urlChanged ( const QUrl & url )

  connect( ui->pushButtonrecordNumVers, SIGNAL(clicked ( bool )),       this, SLOT(Slot_pushButtonrecordNumVers_clicked (bool)));

  ui->progressBarWebView->hide();
  ui->label_Status->hide();
  if (module.indexOf("BrowserOnly") !=-1 )
     {title = tr("Navigateur pour MedinTux");
      setPageChangements(CGestIni::Param_UpdateFromDisk(pathChangements));
      ui->tabWidget->setTabText (ui->tabWidget->indexOf (m_Wdg_Help ), title );
      setWindowTitle(tr("Navigateur pour MedinTux"));
      ui->tabWidget->removeTab  (ui->tabWidget->indexOf (m_Wdg_Licence ));
      ui->tabWidget->removeTab  (ui->tabWidget->indexOf (m_Wdg_Apropos ));
      m_PathPageHelp = description;
     }
  else
     {title = tr("A propos de ")+ module;
      if (pathHelp.length()==0 || !QFile::exists(pathHelp))
         {ui->tabWidget->removeTab  (ui->tabWidget->indexOf (m_Wdg_Help ));
         }
      QString text = CGestIni::Param_UpdateFromDisk(pathApropos);
      text.replace("{{NUM_VERSION}}", version);
      text.replace("{{MODULE}}",      module);
      text.replace("{{DESCRIPTION}}", description);
      text.replace("{{ICONE}}",       pathIcone);
      CGestIni::Param_UpdateToDisk(pathAppli + "Ressources/~A_propos.html", text);
      setPageAPropos(pathAppli  + "Ressources/~A_propos.html" );
      setPageLicence(pathAppli  + "Ressources/Licence.html");
      setPageChangements(CGestIni::Param_UpdateFromDisk(pathChangements));
      m_PathPageHelp = pathHelp;
     }
  setWindowTitle(title);
  setPageHelp(m_PathPageHelp);
  ui->pushButtonClose->setFocus();
  setWindowState(windowState() & ~Qt::WindowMinimized);
  show();
  activateWindow();
  raise();
  //QStringList argList = QCoreApplication::arguments () ;
  //QString argum = "";
  //for (int i=0; i<argList.count();++i)
  //    {argum += QString("Argument N�%1 : %2<br>").arg(QString::number(i),argList[i]);
  //    }
  //ui->textBrowser_Changements->setText(argum);

}

//-----------------------------------------------------  ~C_DlgApropos -------------------------------------------
C_DlgApropos::~C_DlgApropos()
{   QFile::remove(m_PathAppli+"Ressources/~A_propos.html");
    delete ui;
}
//--------------------------------- toPDF -----------------------------------------------------------------------
void C_DlgApropos::toPDF(QString path, QString destPdfFile)
{
#ifndef QT_NO_PRINTER

 QWebView *pQWebView = new QWebView(0); if (pQWebView==0)   return;
 pQWebView->load(QUrl(path));

 QPrinter printer(QPrinter::HighResolution);
 printer.setOutputFormat(QPrinter::PdfFormat);
 QFileInfo fi(path);

 if (destPdfFile.length()==0) destPdfFile = fi.path()+"/"+fi.baseName()+".pdf";                // name = "archive.tar.gz"
 printer.setOutputFileName (destPdfFile);
 //pQWebView->show();
 if (QFile::exists(destPdfFile)) QFile::remove(destPdfFile);

 QPrintDialog *printDialog = new QPrintDialog(&printer, pQWebView);
 if (printDialog->exec() == QDialog::Accepted)
    {pQWebView->print ( &printer );
    }
 delete pQWebView;
#endif // QT_NO_PRINTER
 }

//--------------------------------- Slot_webView_linkClicked -----------------------------------------------------------------------
void C_DlgApropos::Slot_webView_linkClicked ( const QUrl & url )
{if (URL_ExecSpecialSyntax ( url.toString().trimmed() ,m_PathAppli)) return;
 ui->webView_Help->load (url );
}
//--------------------------------- Slot_webView_Apropos_linkClicked -----------------------------------------------------------------------
void C_DlgApropos::Slot_webView_Apropos_linkClicked ( const QUrl & url )
{ if (URL_ExecSpecialSyntax ( url.toString().trimmed() ,m_PathAppli)) return;
  ui->webView_Apropos->load (url );
}

//--------------------------------- URL_ExecSpecialSyntax -----------------------------------------------------------------------
int  C_DlgApropos::URL_ExecSpecialSyntax ( QString urlStr , const QString &pathAppli)
{   if (urlStr.startsWith("exec:"))
       {urlStr = urlStr.mid(5);
        QStringList argList = urlStr.split("||");
        urlStr = argList[0]; if (!argList.isEmpty()) argList.removeAt(0);
        if ( QDir(urlStr).isRelative()) urlStr.prepend(pathAppli);
        urlStr = QDir::cleanPath(urlStr) + F_EXE;
#ifdef Q_WS_MAC
        QString module = urlStr;
        int     posDeb = module.lastIndexOf("/");
        if (posDeb != -1)
           { ++posDeb;
             module = module.mid(posDeb);
           }
        urlStr += ".app/Contents/MacOS/" + module;
#endif
        QProcess::startDetached(urlStr, argList);
        return 1;
       }
    else if (urlStr.startsWith("mailto:"))
       {urlStr      = urlStr.mid(7);
        int posArg  = urlStr.indexOf("?");                 //"mailto:%1?subject=%2&body=%3" la liste d'arguments commence apr�s '?' et sont separes par '&'
        if (posArg != -1)
           {++posArg;
            QString   argMailTo = urlStr.mid(posArg);
            QStringList argList = argMailTo.split("&");
            QString       token = "";
            QString       value = "";
            int           nbArg = argList.count();
            int               i = 0;
            urlStr              = urlStr.left(posArg);
            while( i<nbArg)
                {int posEgal  = argList[i].indexOf("=");
                 token        = "";
                 value        = "";
                 if (posEgal != -1)
                    {++posEgal;
                     token = argList[i].left(posEgal);
                     value = argList[i].mid(posEgal);
                    }
                 if (value.startsWith("file:")||value.startsWith("$File"))
                    {value = value.mid(5);
                     if ( QDir(value).isRelative()) value.prepend(pathAppli);
                     value = QDir::cleanPath(value);
                     value = CGestIni::Param_UpdateFromDisk(value);
                    }
                 urlStr += token+value;
                 ++i;
                 if (i<nbArg) urlStr += "&";
                }
            }
        QDesktopServices::openUrl (urlStr.prepend("mailto:") );
        return 1;
       }
    return 0;
}

//--------------------------------- Slot_On_webView_Help_statusBarMessage -----------------------------------------------------------------------
void C_DlgApropos::Slot_On_webView_Help_statusBarMessage (const QString &text)
{ui->label_Status->setText(text);
}

//--------------------------------- Slot_On_webView_Help_loadStarted -----------------------------------------------------------------------
void C_DlgApropos::Slot_On_webView_Help_loadStarted()
{ui->progressBarWebView->setValue(0);
 ui->progressBarWebView->show();
 ui->label_Status->show();
}

//--------------------------------- Slot_On_webView_Help_loadProgress -----------------------------------------------------------------------
void C_DlgApropos::Slot_On_webView_Help_loadProgress(int progress)
{ui->progressBarWebView->setValue(progress);
 ui->pushButton_Stop->setEnabled(TRUE);
 ui->progressBarWebView->show();
 ui->label_Status->show();
}

//--------------------------------- Slot_On_webView_Help_loadFinished -----------------------------------------------------------------------
void C_DlgApropos::Slot_On_webView_Help_loadFinished(bool )
{ui->progressBarWebView->hide();
 ui->label_Status->hide();
 ui->pushButton_Stop->setEnabled(FALSE);
}

//--------------------------------- Slot_LocationEdit_returnPressed -----------------------------------------------------------------------
void C_DlgApropos::Slot_LocationEdit_returnPressed()
{   QUrl url = QUrl(ui->lineEdit_url->text());
    ui->webView_Help->setUrl (QUrl(url));
}
//--------------------------------- Slot_WebFindEdit_returnPressed -----------------------------------------------------------------------
void C_DlgApropos::Slot_WebFindEdit_returnPressed()
{Slot_actionWebFind (true);
}

//--------------------------------- Slot_WebFindEdit_textChanged -----------------------------------------------------------------------
void C_DlgApropos::Slot_WebFindEdit_textChanged (const QString &text )
{ui->webView_Help->findText ("",   QWebPage::HighlightAllOccurrences );  // clear the selection
 ui->webView_Help->findText (text, QWebPage::HighlightAllOccurrences );
}

//--------------------------------- Slot_actionWebFind -----------------------------------------------------------------------
void C_DlgApropos::Slot_actionWebFind (bool)
{ui->webView_Help->findText (ui->lineEdit_find->text(), QWebPage::FindWrapsAroundDocument );
}
//--------------------------------- Slot_actionWebPrint -----------------------------------------------------------------------
void C_DlgApropos::Slot_actionWebPrint (bool)
{
 #ifndef QT_NO_PRINTER
     QPrinter printer(QPrinter::HighResolution);
     QPrintDialog *printDialog = new QPrintDialog(&printer, this);
     if (printDialog->exec() == QDialog::Accepted)
        {     ui->webView_Help->print ( &printer );
        }
 #endif // QT_NO_PRINTER
}

//--------------------------------- Slot_actionWebHome -----------------------------------------------------------------------
void C_DlgApropos::Slot_actionWebHome (bool)
{ui->webView_Help->setUrl (QUrl(m_PathPageHelp));
}

//--------------------------------- Slot_webView_urlChanged -----------------------------------------------------------------------
void C_DlgApropos::Slot_webView_urlChanged ( const QUrl &url  )
{ui->lineEdit_url->setText(url.toString());
}

//-----------------------------------------------------  Slot_ShowChangements -------------------------------------------
void C_DlgApropos::Slot_ShowChangements()
{ui->tabWidget->addTab ( m_Wdg_Changements,tr("Changements") );
 ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf (m_Wdg_Changements ));
}

//-----------------------------------------------------  Slot_GetNumVersionFromBin -------------------------------------------
void C_DlgApropos::Slot_GetNumVersionFromBin()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                     m_PathAppli,
                                                     tr("Binary (*)"));
    if (fileName.length()==0)                       return;
    QFile qFile(fileName );
    if (qFile.open( QIODevice::ReadOnly )==FALSE)   return;
    long file_len = qFile.size();
    QByteArray ba = qFile.readAll(); ba.resize(file_len+1); ba.data()[file_len]=0;
    qFile.close ();
    QString motif =  "==##@@";                  // ne pas passer le motif en dur car lors de la recherche sur lui meme va le trouver ici et non dans la variable de debut"
    int deb = ba.indexOf( motif+"==");
    if (deb==-1)                                    return;
    deb += 8;
    motif =  "==@@##";                          // ne pas passer le motif en dur car lors de la recherche sur lui meme va le trouver ici et non dans la variable de debut"
    int end = ba.indexOf( motif+"==",deb);
    if (end==-1)                                    return;
    QString numVers = ba.mid(deb,end-deb);
    if (numVers.length()==0)                        return;
    ui->label_FileName->setText(fileName);
    ui->lineEdit_NumVers->setText(numVers);
    ui->pushButtonrecordNumVers->setEnabled(TRUE);

}
//-----------------------------------------------------  Slot_pushButtonrecordNumVers_clicked -------------------------------------------
void C_DlgApropos::Slot_pushButtonrecordNumVers_clicked (bool)
{
    QString   numVers      = ui->lineEdit_NumVers->text();
    QString   oldNumVers   = ui->lineEdit_NumVers->text();
    QString  fileName      = ui->label_FileName->text();
    int    lenReplace      = 0;
    long file_len          = 0 ;
    if (numVers.length()==0)
       {QMessageBox::warning ( this, tr("Modifier un num\303\251ro de version"),
                                     tr("Le num\303\251ro de version saisi est vide"),
                                     QMessageBox::Ok );
                                                    return;
       }
    if (numVers.count(".")!=2)
       {QMessageBox::warning ( this, tr("Modifier un num\303\251ro de version"),
                                     tr("Le num\303\251ro de version saisi :<b>%1</b> est incorrect <br>le nombre de deux point n'est pas \303\251gal � deux.").arg(numVers),
                                     QMessageBox::Ok );
                                                    return;
       }

    if (fileName.length()==0)
       {QMessageBox::warning ( this, tr("Modifier un num\303\251ro de version"),
                                     tr("Le nom du fichier ex\303\251cutable est vide"),
                                     QMessageBox::Ok );
                                                    return;
       }
    //................  lire le fichier executable en memoire .......................
    QFile qFile(fileName );
    if (qFile.open( QIODevice::ReadOnly )==FALSE)
       {QMessageBox::warning ( this, tr("Modifier un num\303\251ro de version"),
                                     tr("Le fichier ex\303\251cutable :  <b>%1</b> <br>ne peut \303\252tre ouvert en lecture").arg(fileName),
                                     QMessageBox::Ok );
                                                    return;
       }

    file_len = qFile.size();
    QByteArray ba = qFile.readAll(); ba.resize(file_len+1); ba.data()[file_len]=0;
    qFile.close ();
    if (file_len==0)
       {QMessageBox::warning ( this, tr("Modifier un num\303\251ro de version"),
                                     tr("Le fichier ex\303\251cutable :  <b>%1</b> <br>contient z\303\251ro octet !").arg(fileName),
                                     QMessageBox::Ok );
                                                    return;
       }
    //............... chercher et modifier le num version .....................................
    QString motif =  "==##@@";                  // ne pas passer le motif en dur car lors de la recherche sur lui meme va le trouver ici et non dans la variable de debut"
    int deb = ba.indexOf( motif+"==");
    if (deb==-1)
       {QMessageBox::warning ( this, tr("Modifier un num\303\251ro de version"),
                                     tr("Le fichier ex\303\251cutable :  <b>%1</b> <br>ne comporte pas de num\303\251ro de version compatible avec MedinTux").arg(fileName),
                                     QMessageBox::Ok );
                                                    return;
       }
    deb += 8;
    motif =  "==@@##";                          // ne pas passer le motif en dur car lors de la recherche sur lui meme va le trouver ici et non dans la variable de debut"
    int end = ba.indexOf( motif+"==",deb);
    if (end==-1)
       {QMessageBox::warning ( this, tr("Modifier un num\303\251ro de version"),
                                     tr("Le fichier ex\303\251cutable :  <b>%1</b> <br>comporte une erreur dans son syst\303\250me de num\303\251ro de version<br>(motif de d�but trouv\303\251 mais pas celui de fin)").arg(fileName),
                                     QMessageBox::Ok );
                                                   return;
       }
    oldNumVers = ba.mid(deb,end-deb);
    int but = QMessageBox::question ( this, tr("Modifier un num\303\251ro de version"),
                                      tr("Changer le num\303\251ro de version :<b>%1</b><br> de l'ex\303\251cutable suivant :<b>%3</b><br> par celui-ci : <b>%2</b>").arg(oldNumVers,numVers, fileName),
                                            QMessageBox::Ok, QMessageBox::Cancel );
    if (but==QMessageBox::Cancel)                  return;

    lenReplace = end-deb;
    ba.remove(deb,lenReplace);
    ba.insert(deb,numVers.trimmed());
    //................  enregistrer le fichier executable sur disque .......................
    if (qFile.open( QIODevice::WriteOnly )==FALSE)
       {QMessageBox::warning ( this, tr("Modifier un num\303\251ro de version"),
                                     tr("Le fichier ex\303\251cutable :  <b>%1</b> <br>ne peut \303\252tre ouvert en \303\251criture").arg(fileName),
                                     QMessageBox::Ok );
                                                   return;
       }

    QDataStream out(&qFile);
    out.writeRawData (ba, ba.count()-1 );
    qFile.close ();
}

//-----------------------------------------------------  setPageHelp -------------------------------------------
void C_DlgApropos::setPageHelp(const QString &path)
{m_PathPageHelp = path;
 ui->webView_Help->setUrl (QUrl(m_PathPageHelp));
 ui->lineEdit_url->setText(m_PathPageHelp);
}

//-----------------------------------------------------  setPageAPropos -------------------------------------------
void C_DlgApropos::setPageAPropos(const QString &text)
{ui->webView_Apropos->setUrl (QUrl(text));
}
//-----------------------------------------------------  setPageLicence -------------------------------------------
void C_DlgApropos::setPageLicence(const QString &text)
{ui->webView_Licence->setUrl(QUrl(text));
}
//-----------------------------------------------------  setPageChangements -------------------------------------------
void C_DlgApropos::setPageChangements(const QString &text)
{ui->textBrowser_Changements->setText(text);
}
//-----------------------------------------------------  changeEvent -------------------------------------------
void C_DlgApropos::changeEvent(QEvent *e)
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
