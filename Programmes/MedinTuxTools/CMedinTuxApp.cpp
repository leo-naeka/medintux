/************************************** CMedinTuxApp.cpp **************************
 *                                                                                *
 *   #include "CMedinTuxApp.h"                                                    *
 *   Project: MedinTux                                                            *
 *   Copyright (C) 2003 2004 2005 by Sevin Roland  and Data Medical Design        *
 *   E-Mail: data.medical.design@club-internet.fr                                 *
 *                                                                                *
 *   This program is free software; you can redistribute it and/or modify         *
 *   it under the terms of the CeCILL Version 1 du 21/06/2004                     *
 *   License (GPL compatible)                                                     *
 *                              http://www.cecill.info/                           *
 *   as published by :                                                            *
 *                                                                                *
 *   Commissariat à l'Energie Atomique                                            *
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
#include <qstring.h>
#include <qdir.h>
#include <qfileinfo.h>

#include "CMedinTuxApp.h"
#include "CGestIni.h"

CMedinTuxApp* Global_pCMedinTuxApp = 0;  // contiendra l'instance globale de l'application



//-------------------------------------------- GotoDebug --------------------------------------------------
int CMedinTuxApp::GotoDebug()
{return 0;
}


//-------------------------------------------- CMedinTuxApp ---------------------------------------------
CMedinTuxApp::CMedinTuxApp(const QString &appName, int & argc, char ** argv)
    : QApplication (  argc, argv )
{
 //............... recuperer chemin global et nom de l'appli ............................
 // m_PathAppli = QFileInfo (argv[0]).dirPath (true) + QDir::separator();
 m_PathAppli = CGestIni::Construct_PathBin_Module("gest_user",  QFileInfo(argv[0]).dirPath (true));
 m_NameAppli = appName;
 m_PathIni   = m_PathAppli + "gest_user.ini";         /*!< Chemin vers le fichier gest_user.ini */
 //.......................Charger le fichier de parametrage .............................................
 CGestIni::Param_UpdateFromDisk(m_PathIni, m_DataParam);
 //............... initialiser le pointeur global de l'appli ............................
 Global_pCMedinTuxApp = this;
}

//-------------------------------------------- CMedinTuxApp ---------------------------------------------
CMedinTuxApp::CMedinTuxApp(int & argc, char ** argv)
	: QApplication (  argc, argv )
{//............... recuperer chemin global et nom de l'appli ............................
 // m_PathAppli = QFileInfo (argv[0]).dirPath (true) + QDir::separator();
 m_PathAppli = CGestIni::Construct_PathBin_Module("gest_user",  QFileInfo(argv[0]).dirPath (true));
 m_NameAppli = "gest_user";
 m_PathIni   = m_PathAppli + "gest_user.ini";         /*!< Chemin vers le fichier gest_user.ini */
 //.......................Charger le fichier de parametrage .............................................
 CGestIni::Param_UpdateFromDisk(m_PathIni, m_DataParam);

 //............... initialiser le pointeur global de l'appli ............................
 Global_pCMedinTuxApp = this;
}
//-------------------------------------------- initialize --------------------------------------------------
void CMedinTuxApp::initialize( bool activate)
{return ;
}

//-------------------------------------------- sendMessage --------------------------------------------------
bool CMedinTuxApp::sendMessage( const QString &message, int timeout )
{return 0;
}

//-------------------------------------------- activateMainWidget --------------------------------------------------
void CMedinTuxApp::activateMainWidget()
{
    QWidget *wdg = mainWidget();
    if (wdg==0)    return;
    wdg->raise();
    wdg->setActiveWindow();
}


