/***************************************************************************
 *   Copyright (C) 2008 by Eric MAEKER,,,   *
 *   eric@ubuntaz   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef AGGIR_CALCULATOR_H
#define AGGIR_CALCULATOR_H

#include <qstring.h>

/*! \file aggir_calculator.h
 *  \brief Fournit la classe AGGIR_Calculator qui permet à partir du codage de la GIR de calculer le groupe ISO Ressource GIR.
*/

/*! \Class AGGIR_Calculator
 *  \brief Fournit la classe AGGIR_Calculator qui permet à partir du codage de la GIR de calculer le groupe ISO Ressource GIR.
*/

/**
	@author Eric MAEKER http://www.ericmaeker.fr/  <eric.maeker@free.fr>
*/

class AGGIR_Calculator
{
public:
    AGGIR_Calculator();

    ~AGGIR_Calculator();

	int 	getRang		(int rang);
	int	getGIR		(const char* UneChaine);
	int 	getChaineGIR	(	const char* coherence,
					const char* orientation,
					const char* toilette,		// = toilette haut+bas
					const char* habillage,		// = habillage haut+moyen+bas
					const char* alimentation,	// = servir+manger
					const char* elimination,	// = urinaire+fécale
					const char* transferts,
					const char* interieur,
					const char* exterieur,
					const char* communication
				   );

};

#endif
