 /********************************* ThemePopup.cpp ********************************
 *  #include "ThemePopup.h"                                                       *
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
#include <QCursor>
#include <QMenu>
#include "ThemePopup.h"

//--------------------------------- ThemePopup -----------------------------------------------------
ThemePopup::ThemePopup(QWidget * parent/*=0*/ , const QString & style /*=""*/)
 : QMenu(parent)
{if (style.length()) setStyleSheet(style);
 if (Theme::getPath()!="")
  { QFont f = QMenu::font();
    int size = Theme::getFontSize_Popups();
    if (size != -1)
       {f.setPointSize( Theme::getFontSize_Popups() );
        QMenu::setFont( f );
       }
  }
}

//--------------------------------- ThemePopup -----------------------------------------------------
ThemePopup::ThemePopup(QStringList &list, QWidget * parent/*=0*/ , const QString & style /*=""*/, const QString& sep /*= "|"*/, int toMask /*= 0*/ )
 : QMenu(parent)
{if (style.length()) setStyleSheet(style);
 if (Theme::getPath()!="")
  { QFont f  = QMenu::font();
    int size = Theme::getFontSize_Popups();
    if (size != -1)
       {f.setPointSize( Theme::getFontSize_Popups() );
        QMenu::setFont( f );
       }
  }
 //............................... chercher une zone de liste deroulante (bleue) .....................
 //       resolution du probleme des icones sous ubuntu 10.10
 // I found out from fedora documentation that Gnome >= 2.28 does not display menu icons as a default.
 // These commands fixed the issue:
 // gconftool-2 --type boolean --set /desktop/gnome/interface/buttons_have_icons true
 // gconftool-2 --type boolean --set /desktop/gnome/interface/menus_have_icons true

 for ( QStringList::Iterator it =list.begin(); it != list.end(); ++it )
     { QString toInsert    = *(it);
       QAction *pQAction   = 0;
       QString identifiant = "";
       if (sep.length())        // si chaque item de la liste est composée de plusieurs termes separes par un separateur
          {if (toMask > 0)      // si l'on doit masquer les champs situes apres toMask
              {int   i = 0;
               int pos = 0;
               while ( i<toMask && (pos = toInsert.indexOf(sep, pos + sep.length())) != -1)
                 {++i;
                 };
               if (pos != -1) toInsert = toInsert.left(pos);
             }
           identifiant = *(it);
           toInsert    = toInsert.replace(sep," ");   // on ne va pas afficher les separateurs dans le menu
         }
       if (toInsert[0]=='=')
          {int pc = toInsert.indexOf('=',1);
           if (pc != -1)
              {identifiant = toInsert.mid(1,pc-1);
               toInsert    = toInsert.mid(pc+1);
              }
          }

       if (toInsert[0]=='$') setTitle(toInsert.mid(1));
       else if (toInsert.left(4) == "----")
               {pQAction = addSeparator();
               }
       else if (toInsert[0]=='#')
               {int pc = toInsert.indexOf('#',1);
                if (pc != -1)
                   {pQAction  = addAction(Theme::getIconSet(toInsert.mid(1,pc-1)), toInsert.mid(pc+1));
                   }
                else pQAction = addAction( toInsert );
               }
       else    {pQAction = addAction( toInsert );
               }
       if (pQAction && identifiant.length()) pQAction->setData ( identifiant );
     }
}

//--------------------------------- DoPopupList -----------------------------------------------------
QString ThemePopup::DoPopupList(const QString & style/*=""*/)
{
 if (style.length()) setStyleSheet(style);
 QAction *pQAction  =  exec( QCursor::pos() /* mapToGlobal (  QPoint ( x, y) )*/ );
 if (pQAction)
    {QString identifiant = pQAction->data().toString();
     if (identifiant.length()) return identifiant;
     else                      return pQAction->text();
    }
 else          return QString::null;
}

