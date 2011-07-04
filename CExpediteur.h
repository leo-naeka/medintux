/***************************************************************************
 *   Copyright (C) 2004 by Sevin Roland                                    *
 *   ro@vaio_ro                                                            *
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
#ifndef CEXPEDITEUR_H
#define CEXPEDITEUR_H

#include <qstring.h>
#include <qstringlist.h>

//================================================ CExpediteur ==============================================
class CExpediteur 
{       
 public:
     CExpediteur()
     {   m_nomOriginal      = "";
         m_codeExpediteur   = "";
         m_nomExpediteur    = "";
         m_codeDestinataire = "";
         m_nomDestinataire  = "";
         m_dateEmission     = "";
         m_heureEmission    = "";
     }
     CExpediteur(const char* hprim_line, QString &separator)
     {setFromHprimLine(hprim_line, separator);  
     }     
     	
     void setFromHprimLine(const char* hprim_line, QString &separator)
     {  QStringList list        = QStringList::split( separator[0] , hprim_line , true );
        m_nomOriginal           = (list[2].length()==0)           ? "" : (const char*)list[2];
	QStringList section     = QStringList::split( separator[1] , list[4] , true );
	m_codeExpediteur        = (section[0].length()==0)        ? "" : (const char*)section[0];
	m_nomExpediteur         = (section[1].length()==0)        ? "" : (const char*)section[1];
	section                 = QStringList::split( separator[1] , list[9] , true );
	m_codeDestinataire      = (section[0].length()==0)        ? "" : (const char*)section[0];
	m_nomDestinataire       = (section[1].length()==0)        ? "" : (const char*)section[1];
	m_dateEmission          = (list[13].left(8).length()==0)  ? "" : (const char*)(list[13].left(8));
	m_heureEmission         = (list[13].right(4).length()==0) ? "" : (const char*)(list[13].right(4));
     }
     
     QString m_nomOriginal;
     QString m_codeExpediteur;
     QString m_nomExpediteur;
     QString m_codeDestinataire;
     QString m_nomDestinataire;
     QString m_dateEmission;
     QString m_heureEmission;    
};


#endif 
//CEXPEDITEUR_H
