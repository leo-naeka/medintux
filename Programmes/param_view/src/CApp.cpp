
/************************************** CManuApp.cpp *****************************
 *                                                                                *
 *   #include "CApp.h"                                                            *
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
#include <qtextcodec.h>
#include <qfileinfo.h>
#include "CApp.h"

CApp* G_pCApp = 0;  /*!< string which contains pointer on global instance of application */

//-------------------------------------------- GotoDebug --------------------------------------------------
int CApp::GotoDebug()
{return 0;
}

//-------------------------------------------- CApp -------------------------------------------------------
CApp::CApp(int & argc, char ** argv)
        : QApplication (  argc, argv ), CGestIni()
{ QTextCodec::setCodecForTr( QTextCodec::codecForName("utf8") );
  m_ApliName        =  APPLI_NAME;
  m_PathAppli       =  CGestIni::Construct_PathBin_Module(m_ApliName, QFileInfo (qApp->argv()[0]).dirPath (true));
  m_PathIni         =  m_PathAppli  + m_ApliName + ".ini";         // chemin du fichier de configuration
  m_PathRessources  =  m_PathAppli  + "Ressources/";               // repertoire es ressources
  m_PathExchg       =  ""; if (argc>=3)  m_PathExchg    = argv[3]; // chemin du fichierd'echange
  m_Param           =  "";                                         // contiendra les parametres du .ini

  CGestIni::Param_UpdateFromDisk(m_PathIni, m_Param );             // charger le fichier de configuration

  //............... initialiser le pointeur global de l'appli ............................
  G_pCApp = this;
}
