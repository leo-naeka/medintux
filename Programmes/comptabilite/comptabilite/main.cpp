/***************************************************************************
 *   Copyright (C) 2007, 2008 by Eric Maeker   *
 *   eric.maeker@free.fr   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Library General Public License as       *
 *   published by the Free Software Foundation; either version 2 of the    *
 *   License, or (at your option) any later version.                       *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this program; if not, write to the                 *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#include <qapplication.h>
#include "CApp.h"
#include "compta.h"

#define TR QObject::tr


int main( int argc, char ** argv )
{ QTextCodec::setCodecForTr( QTextCodec::codecForName("Utf8") );
  // Construit le pointeur général de l'appli et récupère les données

  CApp a ( argc, argv );
  
  if (G_pCApp && G_pCApp->m_pComptaMoteurBase)
     { if (G_pCApp->m_UsrPk != -1 )
          { Compta * mw = new Compta(G_pCApp->m_pComptaMoteurBase);
            mw->show();
            a.connect( &a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()) );
            return a.exec();
          }
     }
  else { return 1; }
 return 0;
}