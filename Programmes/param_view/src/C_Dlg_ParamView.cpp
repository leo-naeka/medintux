/********************************* C_Dlg_ParamView.cpp **********************************
\file C_Dlg_ParamView.cpp
\brief (put some short descripion here).

    #include "C_Dlg_ParamView.h"
    Project: MedinTux
    Copyright (C) 2003 2004 2005 2006 2007
    by Sevin Roland  and Data Medical Design
    E-Mail: medintux@medintux.org

*   This program is free software; you can redistribute it and/or modify         *
*   it under the terms of the CeCILL Version 1 du 21/06/2004                     *
*   License (GPL compatible)                                                     *
*                              http://www.cecill.info/                           *
*   as published by :                                                            *
*                                                                                *
*   Commissariat a l'Energie Atomique                                            *
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


#include <qtextbrowser.h>
#include "C_Dlg_ParamView.h"
#include "CApp.h"
//------------------------------------------ C_Dlg_ParamView --------------------------------------
C_Dlg_ParamView::C_Dlg_ParamView(QWidget* parent, const char* name, bool modal, WFlags fl)
    : Dlg_ParamView(parent,name, modal,fl)
{
 QString text;
 for ( int i = 0; i < G_pCApp->argc(); i++ )  // a.argc() == argc
     {text += tr("<b>Paramètre N° " ) + QString::number(i) + "</b>";
      switch(i)
       {case 0  :  text += tr("&nbsp;<i>(chemin et nom du plugin lui même) </i><br>");                           break;
        case 1  :  text += tr("&nbsp;<i>(chemin d'un éventuel fichier ini ou \"****\" si absent) </i><br>");     break;
        case 2  :  text += tr("&nbsp;<i>(chemin et nom du programme appelant (parent)) </i><br>");               break;
        case 3  :  text += tr("&nbsp;<i>(chemin et nom du fichier où le résultat doit être retourné) </i><br>"); break;
        case 4  :  text += tr("&nbsp;<i>(GUID identificateur unique du dossier en cours) </i><br>");             break;
        case 5  :  text += tr("&nbsp;<i>(clef primaire de l'observation en cours) </i><br>");                    break;
        case 6  :  text += tr("&nbsp;<i>(clef primaire du terrain en cours) </i><br>");                          break;
        case 7  :  text += tr("&nbsp;<i>(clef primaire de la prescription en cours) </i><br>");                  break;
        case 8  :  text += tr("&nbsp;<i>(clef primaire de l'utilisateur en cours) </i><br>");                    break;
        case 9  :  text += tr("&nbsp;<i>(reservé pour un usage futur) </i><br>");                                break;
        case 10 :  text += tr("&nbsp;<i>(reservé pour un usage futur) </i><br>");                                break;
        case 11 :  text += tr("&nbsp;<i>(reservé pour un usage futur) </i><br>");                                break;
        case 12 :  text += tr("&nbsp;<i>(nb (Nombre des paramètres suivants) </i><br>");                        break;
        default :  text += tr("&nbsp;<i>(paramètre specifique N° : ")+QString::number(i-13)+")</i><br>";
       }
      text = text + "<font color=\"#e80d0d\">" + G_pCApp->argv()[i] + "</font><hr>";
     }
 textBrowser_View->setText(text);
}

//------------------------------------------ ~C_Dlg_ParamView --------------------------------------
C_Dlg_ParamView::~C_Dlg_ParamView()
{}

/*$SPECIALIZATION$*/
//------------------------------------------ reject --------------------------------------
void C_Dlg_ParamView::reject()
{
  QDialog::reject();
}

//------------------------------------------ accept --------------------------------------
void C_Dlg_ParamView::accept()
{
  QDialog::accept();
}



