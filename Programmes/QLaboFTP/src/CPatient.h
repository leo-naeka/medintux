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
#ifndef CPATIENT_H
#define CPATIENT_H

#include <qstring.h>
#include <qstringlist.h>

//================================================ CPatient ==============================================
class CPatient 
{       
 public:
     CPatient()
     {  m_nom                   = "";
        m_prenom                = "";
        m_dateNaissance         = "";
        m_sexe                  = "";
	    m_dateExamen            = "";
        m_heureExamen           = "";
	    m_OBR_Ident             = "";
        m_Service               = "";
     }
     CPatient(const char* hprim_line, const QString &separator)
     {setFromHprimLine(hprim_line, separator);  
     }     
     
     void setFromHprimLine( const char* hprim_line, const QString &separator)
     {  QStringList list        = QStringList::split( separator[0] , hprim_line , true );
        QStringList section     = QStringList::split( separator[1] , list[5]    , true );
	    m_nom                   = (section[0].length()==0) ? "" : (const char*)section[0];
        m_prenom                = (section[1].length()==0) ? "" : (const char*)section[1];
        m_dateNaissance         = (list[7].length()==0)    ? "" : (const char*)list[7];
        m_sexe                  = (list[8].length()==0)    ? "" : (const char*)list[8];
	//section                 = QStringList::split( separator[2] , list[23] , true );
        //m_dateExamen            = (section[0].length()==0) ? "" : (const char*)section[0].left(8);
        //m_heureExamen           = (section[1].length()==0) ? "" : (const char*)section[1].mid(8);
	//section                 = QStringList::split( separator[2] , list[23] , true );
        m_dateExamen            = (list[23].length()==0) ? "" : (const char*)list[23].left(8);
        m_heureExamen           = (list[23].length()==0) ? "" : (const char*)list[23].mid(8);
	    section                 = QStringList::split( separator[1] , list[25]    , true );
        m_Service               = section[1];
	    m_Separator             = separator;
     }
     QString     m_Separator;
     QString     m_nom;
     QString     m_prenom;
     QString     m_dateNaissance;
     QString     m_sexe;
     QString     m_dateExamen;
     QString     m_heureExamen;  
     QString     m_Service;        // localisation   
     QString     m_OBR_Ident;
};


#endif 
//CPATIENT_H
