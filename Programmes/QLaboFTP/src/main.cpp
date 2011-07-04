/***************************************************************************
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

#include <qapplication.h>
#include <qstring.h>
#include <qdir.h>
#include <qmessagebox.h>
#include <qtextcodec.h>
#include <qobject.h>

#include "../../MedinTuxTools/CMedinTuxApp.h"
#ifdef SESAMVITALE_VERSION
    #include "../../SesamVitale-QT3/qtsingleapplication.h"
#else
    #include "../../MedinTuxTools/CMedinTuxApp.h"
#endif

#include "../../MedinTuxTools/CGestIni.h"
#include "ui/FeuillePrincipale.h"

#define NAME_APPLI        "QLaboFTP"

//=============================================== VARIABLES GLOBALES FONDAMENTALES =====================================================
//                            à instanciation UNIQUE,  Pour les rendre accessibles de partout
//........................... Chemins Frequements utilisés ............................................................................
QString       GlobalPathAppli              = "";                // chemin de l'Applicatif
QString       Global_PathIni               = "";
QString       Global_ParamData             = "";
int           Global_ServiceIndex          = 0;                 // index du champ P indiquant le service destination
int main( int argc, char ** argv )
{
     #ifdef COMMERCIAL_VERSION
        QtSingleApplication a("QLaboFTP", argc, argv);
        qDebug ("Vital version");
     #else
        CMedinTuxApp        a("QLaboFTP", argc, argv);
        qDebug ("Free version");
     #endif
    QTextCodec::setCodecForTr( QTextCodec::codecForName("utf8") );

    if (a.sendMessage("Wake up!"))
	   {a.activateMainWidget ();
        return 0;
       }
    //............................... determiner le chemin de l'application ........................................
    GlobalPathAppli            = CGestIni::Construct_PathBin_Module( "QLaboFTP",QFileInfo (qApp->argv()[0]).dirPath (true));

    //............................... lire dans le .ini les paramètres de connexion ...............................
    if (argc > 1 && argv[1][0])         Global_PathIni = QString(argv[1]);
    if (Global_PathIni.length()==0)     Global_PathIni = GlobalPathAppli + NAME_APPLI + ".ini";
    //............... charger les parametres ...............................................................
    CGestIni::Param_UpdateFromDisk(Global_PathIni, Global_ParamData);

    FeuillePrincipale *w = new FeuillePrincipale(0 , "QLaboFTP",  Qt::WDestructiveClose  |
                                                                  Qt::WType_TopLevel     |
                                                                  Qt::WStyle_Customize   |
                                                                  Qt::WStyle_NormalBorder|
                                                                  Qt::WStyle_Title       |
                                                                  Qt::WStyle_MinMax      |
                                                                  Qt::WStyle_SysMenu     |
                                                                  Qt::WStyle_StaysOnTop);
    w->setCaption( QObject::tr("QLaboFTP by DATA MEDICAL DESIGN ©2004 ©2005 ©2006"));
    w->setIcon (GlobalPathAppli + "Images/MoleculeMod00.png" );
    w->show();
    a.initialize();
    a.connect( &a, SIGNAL( lastWindowClosed() ), &a, SLOT( quit() ) );
    a.connect( &a,    SIGNAL(messageReceived(const QString&)), w, SLOT(SlotMakeVisible(const QString&)));
    int ret = a.exec();
    //delete w; non car WDestructiveClose
    return ret;
}
