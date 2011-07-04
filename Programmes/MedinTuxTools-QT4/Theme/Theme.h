 /********************************* Theme.h ***************************************
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

#ifndef Theme_H
#define Theme_H

#include <qstring.h>
#include <qpainter.h>
#include <qcolor.h>
#include <qpixmap.h>
#include <qicon.h>
#include <qdir.h>

#include "../CGestIni.h"

class Theme
{

public:
//     Theme ();
//    ~Theme() { }
        enum m_Mode {WithNoSeparator = 0,
                     WithSeparator   = 1
                    };
        static QString         getPath(bool withSeparator = Theme::WithSeparator);
        static void            setPath(const QString p);

	////////////////////////////////////////////
	///////////////  METHODES  /////////////////
	////////////////////////////////////////////

        static QIcon        getIconSet(const QString iconeFile);
        static QPixmap      getIcon(const QString iconeFile);

        // Couleurs du fichier Ini
        static void   createDefaultIniFile();
        static QColor getFromIniFile(const char* section, const char* var, bool& finded, QColor& color);
        static int    getFromIniFile(const char* section, const char* var, bool& finded, int& value);

        static QColor getRapidAccess_LighterBackground();
        static QColor getRapidAccess_DarkerBackground();
        static QColor getRapidAccess_HighLightColor();
        static QColor getRapidAccess_FontColor_Ident();
        static QColor getRapidAccess_FontColor_Terrain();
        static QColor getRapidAccess_FontColor_Obs();
        static QColor getRapidAccess_FontColor_Prescr();
        static QColor getRapidAccess_FontColor_Doc();

        static void   setFontSize_Menu(int fntSize);
        static int    getFontSize_Popups();
        static int    getFontSize_Menus();


	////////////////////////////////////////////
	///////////////   DONNES   /////////////////
	////////////////////////////////////////////
public:
    static QString        m_Path;	/*!< Contient le Répertoire dans lequel se trouve le Theme */
    static QString        m_ThemeIni;	/*!< Contient le fichier Theme.ini qui se trouve dans ce même répertoire */
    static int            m_FontSize_Popups;
    static int            m_FontSize_Menus;


   static bool
                  m_FontSize_Popups_Defined,
                  m_FontSize_Menus_Defined;

};

#endif
