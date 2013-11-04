/********************************* CApp.cpp ***************************************
 *                                                                                *
 *   #include CApp.h"                                                             *
 *   Project: MedinTux                                                            *
 *   Copyright (C) for the eternity by Sevin Roland  and Data Medical Design      *
 *   E-Mail: data.medical.design@club-internet.fr                                 *
 *                                                                                *
 *   This program is free software; you can redistribute it and/or modify         *
 *   it under the terms of the CeCILL Version 1 du 21/06/2004                     *
 *   License (GPL compatible)                                                     *
 *                              http://www.cecill.info/                           *
 *   as published by :                                                            *
 *                                                                                *
 *   Commissariat Ã   l'Energie Atomique                                           *
 *   - CEA,                                                                       *
 *                            31-33 rue de la Federation, 75752 PARIS cedex 15.   *
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
//
//    mysqldump --quote-name --compatible=mysql323 CCAMTest | gzip > /home/ro/CCAMTest.gz
//    Les spectatrices ne veulent pas qu'on les ennuie dans la file.
//    Without deviation from the norm, progress is not possible. Frank Zappa (1940-1993)
#include "CApp.h"

#include <QFileInfo>
#include <QFile>

#include <QStringList>
#include <QTextStream>
#include <QIODevice>
#include <QProcess>
#include <QDateTime>
#include <QTextCodec>
#include <QMessageBox>
#include <QCoreApplication>
#include <QDebug>
#include "../../MedinTuxTools-QT4/Theme/Theme.h"
#include "../../MedinTuxTools-QT4/Theme/ThemePopup.h"                       // Gestion du theme de l'appli
#include "../../MedinTuxTools-QT4/CGestIni.h"
#include "../../MedinTuxTools-QT4/medicabase/C_UserCtx.h"

//#include "../../MedinTuxTools-QT4/C_BaseMedica.h"

static CApp* G_pCApp = 0;  // contiendra l'instance globale de l'application accessible avec CApp::pCApp()


//--------------------------------------------- C_App -------------------------------------------------------------------
CApp::~CApp()
{writeParam((m_NameAppli+" session").toAscii(),"closed", QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss:zzz").toAscii());
 updateIniParamToDisk();
}


//--------------------------------------------- CApp -------------------------------------------------------------------
CApp::CApp(QString mui_name, int & argc, char ** argv)
: C_AppCore( mui_name, argc, argv ), C_Macro(this)
{    QTextCodec::setCodecForTr( QTextCodec::codecForName("utf8") );
    //.............................. initialiser la base C_BaseMedica ..........................................
    m_PatientCtxFileName       =  (argc>1)?argv[1]:"";
    m_UserCtxFileName          =  (argc>2)?argv[2]:"";
    m_GrammarFileName          =  (argc>3)?argv[3]:"";
    qDebug()<< Q_FUNC_INFO<<" m_PatientCtxFileName      : "<< m_PatientCtxFileName;
    qDebug()<< Q_FUNC_INFO<<" m_UserCtxFileName : "        << m_UserCtxFileName;
    qDebug()<< Q_FUNC_INFO<<" m_GrammarFileName : "        << m_GrammarFileName;
    setQuitOnLastWindowClosed(TRUE);

    C_PosologieGrammar::set_QMapGenre( this->pathAppli()+"Ressources/GrammarGenreSexePlural.txt");
    G_pCApp           =    this;
    setWindowIcon (Theme::getIcon("medicatux/medicatux.png") );
}

//--------------------------------------------- pCApp -------------------------------------------------------------------
/*! \brief retourne l'instance de l'application. est a zero tant que l'initialisation n'est pas finie.
*/
CApp* CApp::pCApp()
{return G_pCApp;
}

//------------------------------------ waitForEndPageDisplay -------------------------------
/*! \brief wait while a web page finish display
 *  \param timeOut  long  loop number max
 *  \param pQWebView  QWebView * scroll to end
 *  \return number of loop out
 */
long CApp::waitForEndPageDisplay(long timeOut, QWebView *pQWebView /* =0 */)
{while(timeOut && isEndPageDisplay()==FALSE)
       {--timeOut;
        processEvents();
        if (pQWebView) pQWebView->scroll ( 0, pQWebView->height() );
       }
 return timeOut;
}
//------------------------------------ outMessage -------------------------------
/*! \brief output a message on std error out put and logwidget if defined
 *  \param mess  const QString  message to display
 *  \param file  const QString source file from where the message is display
 *  \param line  const QString source line in file from where the message is display
 *  \return message diplayed
 */
void   CApp::outMessage( const QString &mess, const QString &file /*  = "" */ , const int line  /* = -1 */)
{if (u_Html()) u_Html()->outMessage(mess, file, line);
 else          qDebug() << mess;
}

//------------------------------ loadContentsIfBeginByTokenFile --------------------------------------------------
/*! \brief Teste si la chaine arg commence par $File et si c'est le cas la charge avec le contenu du fichier.
 *  \param  QString& arg : argument a evaluer et eventuellement charger avec le contenu d'un fichier
*/
QString CApp::loadContentsIfBeginByTokenFile(QString &arg)
{if (arg.startsWith("$File"))
    {arg = resolvePath(arg.mid(5));
     arg = CGestIni::Param_UpdateFromDisk(arg);
    }
 return arg;
}

/*------------------------------ resolvePath --------------------------------------------------------------------*/
/*! \brief resoud un chemin comportant les eventuelles macros $Glossaire $Vigie $ToAbsPath $EndToAbsPath par le chemin absolu
 *  \param pathFile :  QString chemin d'entree
 *  \return Renvoie le chemin modifie absolutise si necessaire
*/
QString CApp::resolvePath(QString pathFile, const QString &pathGlossaire  /* = ""*/ )
{    pathFile = resolvePathKeyWord(pathFile, pathGlossaire);
     if ( QDir::isRelativePath ( pathFile ) ) pathFile  = QDir::cleanPath ( pathFile.prepend(m_PathAppli) );
     return pathFile;
}
/*------------------------------ resolvePathKeyWord --------------------------------------------------------------------*/
/*! \brief resoud un chemin comportant les eventuelles macros $Glossaire $Vigie $ToAbsPath $EndToAbsPath par le chemin absolu
 *  \param pathFile :  QString chemin d'entree
 *  \return Renvoie le chemin modifie absolutise que lors des mots clefs et UNIQUEMENT DANS CE CAS (utile lors arguments de programmes externes)
*/
QString CApp::resolvePathKeyWord(QString pathFile, const QString &pathGlossaire /* = "" */)
{    pathFile  = pathFile.trimmed().replace("$Glossaire", pathGlossaire);
     pathFile  = pathFile.replace("$Vigie", pathGlossaire + "Vigie");
     //if (pathFile[1]==':') pathFile  = pathFile.replace (1, 1, '|' ); //proteger le : de  C:
     //if (pathFile.startsWith("//")) pathFile = QString("**") + pathFile.mid(2);  // prot?ger les doubles "//" du debut (cas des repertoires reseaux)
     //pathFile.replace("//","/");    pathFile.replace("*","/"); pathFile.replace("|",":");
     //............. gestion des motsclefs ..........
     int pos     = -1;
     int deb     = -1;
     QString tmp = "";
     if ((pos = pathFile.lastIndexOf("$EndToAbsPath")) != -1)
        {do
          { if ( (deb     = pathFile.lastIndexOf("$ToAbsPath"),pos) != -1)
               { pathFile = pathFile.remove(pos,13);   // virer le $EndToAbsPath
                 tmp      = QDir::cleanPath (m_PathAppli + pathFile.mid(deb+10, pos - deb -10).trimmed());
                 pathFile = pathFile.replace (deb, pos - deb, tmp );
                 pos      = pathFile.lastIndexOf("$EndToAbsPath", deb);
               }
            else
               { pos = -1;
               }
          } while (pos != -1);
        }
     else if ( (pos = pathFile.indexOf("$ToAbsPath")) != -1)
        { pathFile = pathFile.left(pos) + QDir::cleanPath (m_PathAppli + pathFile.mid(pos+10).trimmed());
        }
     return pathFile;
}
//--------------------------------- DoPopupList -----------------------------------------------------
/*! \brief cree et active un popup menu apartir d'une liste d'items
 *  \param list : QStringList qui contient tous les item si icone associee du theme commence par #iconefile#reste du texte
 *  \return une QString qui contient le nom de l'item selectionne.
*/
QString CApp::DoPopupList(QStringList &list, const QString& sep /*= "|"*/, int posToHide /* = 0*/ )
{ThemePopup *pThemePopup = new ThemePopup(list,0, "", sep, posToHide);
 if (pThemePopup == 0)     return QString::null;
 QString ret = pThemePopup->DoPopupList();
 delete  pThemePopup;
 return  ret;
}
