
/************************************** CDrTuxApp.cpp *****************************
 *                                                                                *
 *   #include "CDrTuxApp.h"                                                       *
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

#include "C_MUI_App.h" 
#include "CGestIni.h"

//-------------------------------------------- GotoDebug --------------------------------------------------
int C_MUI_App::GotoDebug()
{return 0;
}


//-------------------------------------------- C_MUI_App ---------------------------------------------
C_MUI_App::C_MUI_App(const QString &appName, int & argc, char ** argv)
    : QApplication (  argc, argv )
{
 //............... recuperer chemin global et nom de l'appli ............................
 // m_PathAppli = QFileInfo (argv[0]).dirPath (true) + QDir::separator(); 
 //m_PathAppli             = argv[0];
 //m_PathAppli = CGestIni::Construct_PathBin_Module("drtux",QFileInfo (qApp->argv()[0]).dirPath (true));
 //int                   i =  m_PathAppli.findRev (QDir::separator()) + 1; // si findRev == -1 -> i = 0 
 //m_NameAppli =  appName;    
 //m_PathAppli =  m_PathAppli.left(i);
 
 //............... initialiser le gestionnaire de fichier .ini ..........................
 //m_CGestIni.Param_Init( argv[0] );   // envoyer chemin complet du programme 
 //Param_Init( argv[0] );   // envoyer chemin complet du programme 
 //............... initialiser le pointeur global de l'appli ............................
 //G_pCDrTuxApp = this;
}

//-------------------------------------------- C_MUI_App ---------------------------------------------
C_MUI_App::C_MUI_App(int & argc, char ** argv)
	: QApplication (  argc, argv )
{//............... recuperer chemin global et nom de l'appli ............................
 // m_PathAppli = QFileInfo (argv[0]).dirPath (true) + QDir::separator(); 
 //m_PathAppli             = argv[0];
 //m_PathAppli = CGestIni::Construct_PathBin_Module("drtux",QFileInfo (qApp->argv()[0]).dirPath (true));

 //int                   i =  m_PathAppli.findRev (QDir::separator()) + 1; // si findRev == -1 -> i = 0 
 //m_NameAppli =  m_PathAppli.mid(i);    
 //m_PathAppli =  m_PathAppli.left(i);
 
 //............... initialiser le gestionnaire de fichier .ini ..........................
 //m_CGestIni.Param_Init( argv[0] );   // envoyer chemin complet du programme 
 //Param_Init( argv[0] );   // envoyer chemin complet du programme 
 //............... initialiser le pointeur global de l'appli ............................
 //G_pCDrTuxApp = this;
}
//-------------------------------------------- initialize --------------------------------------------------
void C_MUI_App::initialize( bool activate)
{return ;
}

//-------------------------------------------- sendMessage --------------------------------------------------
bool C_MUI_App::sendMessage( const QString &message, int timeout )
{return 0;
}

//-------------------------------------------- activateMainWidget --------------------------------------------------
void C_MUI_App::activateMainWidget()
{
    QWidget *wdg = mainWidget();
    if (wdg==0)    return;
    wdg->raise();
    wdg->setActiveWindow();
}


