/**************************** Global.h *************************************
 *   Copyright (C) 2004 by Sébastien SIVERA & Sevin Roland                 *
 *   upsis@club-internet.fr                                                *
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

#ifndef  CGLOBAL_H
#define  CGLOBAL_H

//=============================================== INCLUDES ===================================================================

#include <qstring.h>
#include <qmap.h>
#include <qfile.h>
#include <qvaluelist.h>
#include "CFtpInfo.h"
#include "../../MedinTuxTools/CGestIni.h"

//=============================================== VARIABLES ==================================================================
#ifdef Q_WS_X11
    #define NAME_APPLI        "QLaboFTP"
    #define NAME_APPLI_EXT    ""
#ifdef Q_OS_MACX
    #define NAME_APPLI        "QLaboFTP"
    #define NAME_APPLI_EXT    ""
#endif	
#else
    #define NAME_APPLI        "QLaboFTP"
    #define NAME_APPLI_EXT    ".exe"
#endif

#define TEMP_FOLDER "Temp"
#define LOG_FOLDER  "Log"

//........................... structure pour stocker les références des fichiers ............................................

typedef QMap < int , QFile* > FileMap;
typedef QMap < int , QString > DistantMap;
typedef QMap < int , QString > LocalMap;
typedef QMap < int , QString > RemoveMap;
typedef QValueList < CFtpInfo > CFtpFileInfoList;



//..................................... structures pour les commandes ....................................................
/*
typedef struct _COMMAND
    {QString m_dateDebut;
     QString m_Command;
     QString m_dateFin;
     QString m_Resultat;
     QString m_nomFichier;
    }COMMAND;

typedef QMap < int , COMMAND* > CommandMap;
*/

extern QString       GlobalPathAppli;
extern CGestIni*     Global_pCGestIni;
extern int           Global_ServiceIndex;                 // index du champ P indiquant le service destination


#endif //CGLOBAL_H
