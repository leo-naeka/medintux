 /********************************* Theme.cpp *************************************
 *  #include "Theme.h"                                                            *
 * ...............................................................................*
 *   Project   :  MedinTux  (typographie made in france)                          *
 *   Copyright : (C) 2004-2005-2006-2007-2008-2009-2010 and for the eternity      *
 *   by        :  Sevin Roland     from   MedinTux project                        *
 *                from Eric MAEKER <eric.maeker.fr> original code                 *
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

#include "Theme.h"
#include <qdir.h>
//Added by qt3to4:
#include <QPixmap>

/*! \class Theme
 * Cette classe est entièrement statique. Avant d'accéder aux fonction de récupération des icones, il faut définir le chemin vers le répertoire de thème par la fonction setPath(). Celui-ci est structuré de la sorte :
 * racine : les icones de taille mal définie
 * 16x16 : répertoire pour les icones visualisables dans les Popup et les ListView
 * 22x22 : pour les icones des bouttons
 * 32x32 : pour les listBox des fenêtres de paramètre.
 * dans le répertoire racine existe un fichier Theme.ini qui contient les informations sur les couleurs, polices...

 *  Cette classe peut être utilisée par toutes les applications de MedinTux.

 *  Pour limiter l'utilisation massive du CPU au démarrage de l'application les icones sont chargés au moment de leur demande par les fonctions getIcon....().
*/

// Faut tout initialiser avant d'utiliser la classe.
QString   Theme::m_Path = "";
QString   Theme::m_ThemeIni = "";
int       Theme::m_FontSize_Popups = -1;
int       Theme::m_FontSize_Menus  = -1;
bool      Theme::m_FontSize_Popups_Defined  = FALSE;
bool      Theme::m_FontSize_Menus_Defined   = FALSE;


QIcon Theme::getIconSet(const QString iconeFile)
{return QIcon(getIcon(iconeFile));
}

QPixmap  Theme::getIcon(const QString iconeFile)
{return QPixmap(m_Path + iconeFile);
}

QColor Theme::getFromIniFile(const char* section, const char* var, bool& finded, QColor& color)
{ // gagner du temps process
  if (finded) return color;
  if (m_ThemeIni=="") return color;
  // Récupère la couleur dans le Ini
  QString r,g,b;
  r=""; g=""; b="";
  if (CGestIni::Param_ReadParam(m_ThemeIni.toAscii(), section, var, &r, &g, &b) != QString::null)
  { return color; }

  if ((r!="") && (g!="") && (b!=""))
  { color = QColor(r.toInt(), g.toInt(), b.toInt() );
    finded = TRUE;
    return color; // valeur du ini
  }
  else
  { finded = TRUE;
    return color; // valeur par défaut
  }
}

int Theme::getFromIniFile(const char* section, const char* var, bool& finded, int& value)
{ // gagner du temps process
  if (finded) return value;
  if (m_ThemeIni=="") return value;
  // Récupère la couleur dans le Ini
  QString val = "";
  if (CGestIni::Param_ReadParam(m_ThemeIni.toAscii(), section, var, &val) != QString::null)
  { return value; }

  if (val!="")
  { value = val.toInt();
    finded = TRUE;
    return value; // valeur du ini
  }
  else
  { finded = TRUE;
    return value; // valeur par défaut
  }
}


int Theme::getFontSize_Popups()
{  return getFromIniFile("FontSize", "PopupMenus",
                 m_FontSize_Popups_Defined, m_FontSize_Popups);
}

void Theme::setFontSize_Menu(int fntSize)
{ m_FontSize_Popups_Defined = m_FontSize_Menus_Defined = TRUE;
  m_FontSize_Popups         = m_FontSize_Menus         = fntSize;
}

int Theme::getFontSize_Menus()
{  return getFromIniFile("FontSize", "Menus",
                 m_FontSize_Menus_Defined, m_FontSize_Menus);
}

/*! \brief Renvoie le répertoire de thème en cours. */
QString  Theme::getPath(bool withSeparator)
{if (withSeparator==FALSE)
    {if (m_Path.endsWith("/")) return m_Path.left(m_Path.length()-1);
    }
 return m_Path;
}

/*! \brief Définit le répertoire de thème �  utiliser. Fonction OBLIGATOIRE avant toute autre pour définir le répertoire sinon risque de plantage. */
void Theme::setPath(const QString p)
{ m_Path = p;
  QString pathIni = p + "/Theme.ini";
  pathIni = QDir:: cleanPath(pathIni);
  // Récupère au passage le fichier ini du theme qui contient les codes couleur
  if (!QFile(pathIni).exists())
  { createDefaultIniFile();
  }
  CGestIni::Param_UpdateFromDisk(pathIni, m_ThemeIni);
}

/*! \brief Crée le fichier de toute pièce pour le thème par défaut. */
void Theme::createDefaultIniFile()
{ QString pathIni = m_Path + "/Theme.ini";
  pathIni = QDir:: cleanPath(pathIni);
  m_ThemeIni = "[RapidAccess]\r\n";
  CGestIni::Param_WriteParam(&m_ThemeIni, "FontSize", "PopupMenus", "9");
  CGestIni::Param_WriteParam(&m_ThemeIni, "FontSize", "Menus", "9");
  CGestIni::Param_UpdateToDisk(pathIni, m_ThemeIni);
}
