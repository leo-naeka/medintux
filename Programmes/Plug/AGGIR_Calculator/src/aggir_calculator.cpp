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
#include "aggir_calculator.h"

AGGIR_Calculator::AGGIR_Calculator()
{ 
}


AGGIR_Calculator::~AGGIR_Calculator()
{
}



/*! \brief Renvoie le groupe GIR selon le Rang calculé par la fonction getGIR.
 * \return Groupe ISO Ressource GIR.
 */
int AGGIR_Calculator::getRang(int rang)
{  int GIR_calcule;
qWarning("rang = "+QString::number(rang));
  if (rang == 1){ GIR_calcule = 1; }
  if ((rang >= 2) && (rang <= 7)) { GIR_calcule = 2; }
  if ((rang >= 8) && (rang <= 9)) { GIR_calcule = 3; }
  if ((rang >= 10) && (rang <= 11)) { GIR_calcule = 4; }
  if (rang == 12) { GIR_calcule = 5; }
  if (rang == 13) { GIR_calcule = 6; }

  return GIR_calcule;
}


/*! \brief Calcul le rang correspondant au données de la grille GIR préalablement formatées.
 *  \return le groupe GIR.
 *  \param UneChaine = chaine de caractère contenant l'encodage exacte des items de la GIR. Cette varaible est construite par la fonction : getChaineGIR.
 */
int AGGIR_Calculator::getGIR(const char* UneChaine)
{ int rang;
  int groupe;
  QString chaineGIR = UneChaine;

  if (chaineGIR.length() < 8) { return 0; }

  rang = 0;

  // Teste UneChaine pour le groupe A
  groupe = 0;
  if (chaineGIR.mid( 0, 1) == "C") { groupe = 2000; }
  if (chaineGIR.mid( 1, 1) == "C") { groupe = groupe + 1200; }
  if (chaineGIR.mid( 2, 1) == "C") { groupe = groupe + 40; }
  if (chaineGIR.mid( 3, 1) == "C") { groupe = groupe + 40; }
  if (chaineGIR.mid( 4, 1) == "C") { groupe = groupe + 60; }
  if (chaineGIR.mid( 5, 1) == "C") { groupe = groupe + 100; }
  if (chaineGIR.mid( 6, 1) == "C") { groupe = groupe + 800; }
  if (chaineGIR.mid( 7, 1) == "C") { groupe = groupe + 200; }
  if (chaineGIR.mid( 2, 1) == "B") { groupe = groupe + 16; }
  if (chaineGIR.mid( 3, 1) == "B") { groupe = groupe + 16; }
  if (chaineGIR.mid( 4, 1) == "B") { groupe = groupe + 20; }
  if (chaineGIR.mid( 5, 1) == "B") { groupe = groupe + 16; }
  if (chaineGIR.mid( 6, 1) == "B") { groupe = groupe + 120; }
  if (chaineGIR.mid( 7, 1) == "B") { groupe = groupe + 32; }
  //' Rang groupe A
  if (groupe >= 4380 ) 
   { rang = 1; }
  else   if ((groupe >= 4140 ) && (groupe <= 4379))
   { rang = 2 ; }
  else if ((groupe >= 3390 ) && (groupe <= 4139))
     {  rang = 1 ;}
  if (rang != 0) 
   {  return getRang(rang);
   }

  //' Teste UneChaine pour le groupe B
  groupe = 0;
  if (chaineGIR.mid( 0, 1) == "C") { groupe = 1500; }
  if (chaineGIR.mid( 1, 1) == "C") { groupe = groupe + 1200; }
  if (chaineGIR.mid( 2, 1) == "C") { groupe = groupe + 40; }
  if (chaineGIR.mid( 3, 1) == "C") { groupe = groupe + 40; }
  if (chaineGIR.mid( 4, 1) == "C") { groupe = groupe + 60; }
  if (chaineGIR.mid( 5, 1) == "C") { groupe = groupe + 100; }
  if (chaineGIR.mid( 6, 1) == "C") { groupe = groupe + 800;  }
  if (chaineGIR.mid( 7, 1) == "C") { groupe = groupe - 80; }
  if (chaineGIR.mid( 0, 1) == "B") { groupe = groupe + 320; }
  if (chaineGIR.mid( 1, 1) == "B") { groupe = groupe + 120; }
  if (chaineGIR.mid( 2, 1) == "B") { groupe = groupe + 16; }
  if (chaineGIR.mid( 3, 1) == "B") { groupe = groupe + 16; }
  if (chaineGIR.mid( 4, 1) == "B") { groupe = groupe + 0; }
  if (chaineGIR.mid( 5, 1) == "B") { groupe = groupe + 16; }
  if (chaineGIR.mid( 6, 1) == "B") { groupe = groupe + 120; }
  if (chaineGIR.mid( 7, 1) == "B") { groupe = groupe - 40; }
  // ' Rang groupe B
  if (groupe >= 2016) 
  { rang = 4;
    return getRang(rang);
  }
  else  { rang = 0; }

  //' Teste UneChaine pour le groupe C
  groupe = 0;
  if (chaineGIR.mid( 2, 1) == "C") { groupe = groupe + 40; }
  if (chaineGIR.mid( 3, 1) == "C") { groupe = groupe + 40; }
  if (chaineGIR.mid( 4, 1) == "C") { groupe = groupe + 60; }
  if (chaineGIR.mid( 5, 1) == "C") { groupe = groupe + 160; }
  if (chaineGIR.mid( 6, 1) == "C") { groupe = groupe + 1000; }
  if (chaineGIR.mid( 7, 1) == "C") { groupe = groupe + 400; }
  if (chaineGIR.mid( 2, 1) == "B") { groupe = groupe + 16; }
  if (chaineGIR.mid( 3, 1) == "B") { groupe = groupe + 16; }
  if (chaineGIR.mid( 4, 1) == "B") { groupe = groupe + 20; }
  if (chaineGIR.mid( 5, 1) == "B") { groupe = groupe + 20; }
  if (chaineGIR.mid( 6, 1) == "B") { groupe = groupe + 200; }
  if (chaineGIR.mid( 7, 1) == "B") { groupe = groupe + 40; }
  //' Rang groupe C
  if (groupe >= 1700) { rang = 5; }
  if ((groupe >= 1432) && (groupe <= 1699)) { rang = 6; }
  if (rang != 0)
  	{ return getRang(rang); } 

  //' Teste UneChaine pour le groupe D
  groupe = 0;
  if (chaineGIR.mid( 4, 1) == "C") { groupe = groupe + 2000; }
  if (chaineGIR.mid( 5, 1) == "C") { groupe = groupe + 400; }
  if (chaineGIR.mid( 6, 1) == "C") { groupe = groupe + 2000; }
  if (chaineGIR.mid( 7, 1) == "C") { groupe = groupe + 200; }
  if (chaineGIR.mid( 4, 1) == "B") { groupe = groupe + 200; }
  if (chaineGIR.mid( 5, 1) == "B") { groupe = groupe + 200; }
  if (chaineGIR.mid( 6, 1) == "B") { groupe = groupe + 200; }
  //' Rang groupe D
  if (groupe >= 2400) 
   {  rang = 7;
      return getRang(rang);
   }
  else { rang = 0; }

  //' Teste UneChaine pour le groupe E
  groupe = 0;
  if (chaineGIR.mid( 0, 1) == "C") { groupe = 400; }
  if (chaineGIR.mid( 1, 1) == "C") { groupe = groupe + 400; }
  if (chaineGIR.mid( 2, 1) == "C") { groupe = groupe + 400; }
  if (chaineGIR.mid( 3, 1) == "C") { groupe = groupe + 400; }
  if (chaineGIR.mid( 4, 1) == "C") { groupe = groupe + 400; }
  if (chaineGIR.mid( 5, 1) == "C") { groupe = groupe + 800; }
  if (chaineGIR.mid( 6, 1) == "C") { groupe = groupe + 800; }
  if (chaineGIR.mid( 7, 1) == "C") { groupe = groupe + 200; }
  if (chaineGIR.mid( 2, 1) == "B") { groupe = groupe + 100; }
  if (chaineGIR.mid( 3, 1) == "B") { groupe = groupe + 100; }
  if (chaineGIR.mid( 4, 1) == "B") { groupe = groupe + 100; }
  if (chaineGIR.mid( 5, 1) == "B") { groupe = groupe + 100; }
  if (chaineGIR.mid( 6, 1) == "B") { groupe = groupe + 100; }
  //' Rang groupe E
  if (groupe >= 1200)
   { rang = 8;
     return getRang(rang);
   }
  else { rang = 0 ; }

  // ' Teste UneChaine pour le groupe F
  groupe = 0;
  if (chaineGIR.mid( 0, 1) == "C") { groupe = 200; }
  if (chaineGIR.mid( 1, 1) == "C") { groupe = groupe + 200; }
  if (chaineGIR.mid( 2, 1) == "C") { groupe = groupe + 500; }
  if (chaineGIR.mid( 3, 1) == "C") { groupe = groupe + 500; }
  if (chaineGIR.mid( 4, 1) == "C") { groupe = groupe + 500; }
  if (chaineGIR.mid( 5, 1) == "C") { groupe = groupe + 500; }
  if (chaineGIR.mid( 6, 1) == "C") { groupe = groupe + 500; }
  if (chaineGIR.mid( 7, 1) == "C") { groupe = groupe + 200; }
  if (chaineGIR.mid( 0, 1) == "B") { groupe = groupe + 100; }
  if (chaineGIR.mid( 1, 1) == "B") { groupe = groupe + 100; }
  if (chaineGIR.mid( 2, 1) == "B") { groupe = groupe + 100; }
  if (chaineGIR.mid( 3, 1) == "B") { groupe = groupe + 100; }
  if (chaineGIR.mid( 4, 1) == "B") { groupe = groupe + 100; }
  if (chaineGIR.mid( 5, 1) == "B") { groupe = groupe + 100; }
  if (chaineGIR.mid( 6, 1) == "B") { groupe = groupe + 100; }
  //' Rang groupe F
  if (groupe >= 800)
  {  rang = 9 ;
     return getRang(rang);
  }
  else { rang = 0; }

  //' Teste UneChaine pour le groupe G
  groupe = 0;
  if (chaineGIR.mid( 0, 1) == "C") { groupe = 150; }
  if (chaineGIR.mid( 1, 1) == "C") { groupe = groupe + 150; }
  if (chaineGIR.mid( 2, 1) == "C") { groupe = groupe + 300; }
  if (chaineGIR.mid( 3, 1) == "C") { groupe = groupe + 300; }
  if (chaineGIR.mid( 4, 1) == "C") { groupe = groupe + 500; }
  if (chaineGIR.mid( 5, 1) == "C") { groupe = groupe + 500; }
  if (chaineGIR.mid( 6, 1) == "C") { groupe = groupe + 400; }
  if (chaineGIR.mid( 7, 1) == "C") { groupe = groupe + 200; } 
  if (chaineGIR.mid( 2, 1) == "B") { groupe = groupe + 200; }
  if (chaineGIR.mid( 3, 1) == "B") { groupe = groupe + 200; }
  if (chaineGIR.mid( 4, 1) == "B") { groupe = groupe + 200; }
  if (chaineGIR.mid( 5, 1) == "B") { groupe = groupe + 200; }
  if (chaineGIR.mid( 6, 1) == "B") { groupe = groupe + 200; }
  if (chaineGIR.mid( 7, 1) == "B") { groupe = groupe + 100; }
  //' Rang groupe G
  if (groupe >= 650) 
  {  rang = 10;
     return getRang(rang);
  }
  else { rang = 0; }

  //' Teste UneChaine pour le groupe H
  groupe = 0; 
  if (chaineGIR.mid( 2, 1) == "C") { groupe = groupe + 3000; }
  if (chaineGIR.mid( 3, 1) == "C") { groupe = groupe + 3000; }
  if (chaineGIR.mid( 4, 1) == "C") { groupe = groupe + 3000; }
  if (chaineGIR.mid( 5, 1) == "C") { groupe = groupe + 3000; }
  if (chaineGIR.mid( 6, 1) == "C") { groupe = groupe + 1000; }
  if (chaineGIR.mid( 7, 1) == "C") { groupe = groupe + 1000; }
  if (chaineGIR.mid( 2, 1) == "B") { groupe = groupe + 2000; }
  if (chaineGIR.mid( 3, 1) == "B") { groupe = groupe + 2000; }
  if (chaineGIR.mid( 4, 1) == "B") { groupe = groupe + 2000; }
  if (chaineGIR.mid( 5, 1) == "B") { groupe = groupe + 2000; }
  if (chaineGIR.mid( 6, 1) == "B") { groupe = groupe + 2000; }
  if (chaineGIR.mid( 7, 1) == "B") { groupe = groupe + 1000; }
  //' Rang groupe H
  if (groupe >= 4000){ rang = 11; }
  if (groupe >= 2000 && groupe <= 3999) { rang = 12; }
  if (groupe < 2000) { rang = 13; }
  return getRang(rang);

}

/*! \brief Calcul le groupe GIR à partir des paramètres.
 *  \param toilette est l'addition des caractères de la toilette du haut et du bas. Exemple : toilette haut = "B" toilette Bas = "A" ; toilette = "BA"
 *  \param habillage idem avec les variables dans l'ordre haut + moyen + bas
 *  \param alimentation idem avec servir + manger
 *  \param elimination idem avec urinaire + fécale
 *  \return Groupe ISO Ressource GIR calculé.
*/
int AGGIR_Calculator::getChaineGIR(	const char* coherence,
					const char* orientation,
					const char* toilette,		// = toilette haut+bas
					const char* habillage,		// = habillage haut+moyen+bas
					const char* alimentation,	// = servir+manger
					const char* elimination,	// = urinaire+fécale
					const char* transferts,
					const char* interieur,
					const char* exterieur,
					const char* communication
				   )
{ QString chaine = "";  //' chaine = coherence + orientation + toilette + habillage + alimentation + elimination + transferts + interieur + exterieur + communication
  QString tmp = "";
  int aggir = 0;

  //' Cohérence et orientation
  chaine = coherence;
  chaine += orientation;

  //' Toilette AA=A CC=C autres=B
  tmp = toilette;
  tmp = tmp.upper();
  if (tmp == "AA") tmp = "A";
  else 
  { if (tmp == "CC") tmp = "C"; 
    else tmp = "B";
  }
 chaine += tmp;

  //'Habillage (HMB) AAA=A CCC=C Autres=B
  tmp = habillage;
  tmp = tmp.upper();
  if (tmp == "AAA") tmp = "A";
  else 
  { if (tmp == "CCC") tmp = "C";
    else tmp = "B";
  }
 chaine += tmp;

  //' Alimentation  SM  AA=A CC=C BC=C  CB=C Autres=B
  tmp = alimentation;
  tmp = tmp.upper();
  if (tmp == "AA") tmp = "A";
  else
  { if (tmp == "CC")  tmp = "C";
    else
    { if (tmp == "BC") tmp = "C";
      else
      { if (tmp == "CB") tmp = "C";
        else tmp = "B";
      }
    }
  }
 chaine += tmp;

  //' Continence  AA=A  CC=C BB=B  CB_BC=C AC=C  CA=C
  tmp = elimination;
  tmp = tmp.upper();
  if (tmp.find("C") != -1) tmp = "C";
  else
  { if (tmp == "AA") tmp = "A";
    else tmp = "B";
  }
  chaine += tmp;

  //' Transferts, déplacements et communication
  chaine += transferts;
  chaine += interieur;
  chaine += exterieur;
  chaine += communication;
  chaine = chaine.upper();

  aggir = getGIR(chaine);
  return aggir;
}
