
/**************************** C_BDM_Control.cpp ***************************
*  #include "C_BDM_Control.h"         QT4-ready                           *
* ........................................................................*
*   Project   :  MedinTux  (typographie made in france)                   *
*   Copyright :  (C) 2005-2006-2007-2008-2009-2010 and for the eternity   *
*   by        :  Sevin Roland     from   MedinTux project                 *
*   E-Mail    :  roland-sevin@medintux.org                                *
*   Web site  :  www.medintux.org                                         *
* ........................................................................*
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

#include "../../MedinTuxTools-QT4/medicabase/C_BDM_Control.h"
#include <QThread>


//=================== C_BDM_Control ===================================
/*! \class C_Gest_BDM_Pool
 *  \brief Class to maintain all the DB element for API
 */
//-------------------------------- C_BDM_Control ------------------------------------------------------
/*! \brief  the constructor intialize BDM structures (each thread must have separate QSqlDatabase)
 *  \param  const QString &pathAppli     general application path
 *  \param  const QString &pathIni       general configuration file application path
 *  \param  const QString &pathTheme     icones and pixmap folder
 *  \param  QObject *parent              parent object
 */

C_BDM_Control::C_BDM_Control(const QString &pathAppli       ,
                             const QString &pathIni         ,
                             const QString &pathTheme       ,
                             QObject *parent)
   : QObject(parent)
{   m_pathAppli   = pathAppli;
    m_pathIni     = pathIni;
    m_dataIni     = CGestIni::Param_UpdateFromDisk( m_pathIni );
    m_pathTheme   = pathTheme;
    m_lastMessage = "";
    m_pC_BDM_Api  = new C_BDM_Api( CGestIni::Param_UpdateFromDisk( m_pathAppli +"C_BDM_Api.cfg" ),
                                   "THREAD_",
                                   m_dataIni,
                                   m_pathTheme,
                                   m_pathAppli,
                                   m_dataIni,
                                   parent);
    if ( ! m_pC_BDM_Api->isValid() ) return;
    QString namePlugin = CGestIni::Param_ReadUniqueParam(m_dataIni.toLatin1(), "medicatux data source", "name");
    set_BDM_Plugin(namePlugin);
}

//-------------------------------- setPatientAndUserContexte ------------------------------------------------------
/*! \brief set user and patient context
 *  \param  C_PatientCtx *pC_PatientCtx pointer on patient context (must be persistant while C_BDM_Control exists)
 *  \param  C_UserCtx *pC_UserCtx       pointer on user context (must be persistant while C_BDM_Control exists)
 */
void C_BDM_Control::setPatientAndUserContexte(C_PatientCtx *pC_PatientCtx, C_UserCtx *pC_UserCtx)
{
 m_pC_BDM_Api->setPatientContexte(pC_PatientCtx);
 m_pC_BDM_Api->setUserContexte(pC_UserCtx);
}

//-------------------------------- set_BDM_Plugin ------------------------------------------------------
/*! \brief connect API to source datas via C_BDM_InitPluginI interface which provides data to  C_BDM_Api
 *  \param QString namePlugin of C_BDM_InitPluginI data source ( 'theriaque' 'datasemp')
 *  \return C_BDM_PluginI * pointer on plugin or zero if error
 */

C_BDM_PluginI *C_BDM_Control::set_BDM_Plugin(const QString &_namePlugin)   // theriaque datasemp
{   QTime debTime                 = QTime::currentTime();
    QTime debGTime                = QTime::currentTime();
    QString namePlugin            = _namePlugin.toUpper().trimmed();
    C_BDM_PluginI *pC_BDM_PluginI = 0;
    m_lastMessage                 = "";
    m_lastMessage += tr("=============== SET DATABASE '%1' =====================").arg(namePlugin );
    //.............. on cherche le plugin de base de donnee dans la liste.................
    QMap<QString, C_BDM_PluginI*>::const_iterator it = m_pC_BDM_PluginI_Map.find(namePlugin);
    //.............. si non trouve on initialise le plugin ...............................
    if (it == m_pC_BDM_PluginI_Map.constEnd() )  // si pas trouve le creer et le rajouter a la liste
       {    QString confData =   QString("[BDM_Configuration]\n"
                                         "     PathAppli     = %2\n"
                                         "     PathIni       = %3\n").arg( m_pathAppli , m_pathIni );
            if (namePlugin=="THERIAQUE")
               { debTime        = QTime::currentTime();
                 pC_BDM_PluginI = new C_BDM_TheriaquePlugin(confData,"THREAD_", 0, 0, 0);
                 m_lastMessage += tr("Database '%1' creation en : %2").arg(namePlugin,   QTime (0, 0, 0, 0 ).addMSecs(debTime.msecsTo(QTime::currentTime())).toString("mm:ss:zzz") );
               }
            else if (namePlugin=="DATASEMP")
               { debTime        = QTime::currentTime();
                 pC_BDM_PluginI =  new C_BDM_DatasempPlugin(confData,"THREAD_", 0, 0, 0);
                 m_lastMessage += tr("Database '%1' creation en : %2").arg(namePlugin,   QTime (0, 0, 0, 0 ).addMSecs(debTime.msecsTo(QTime::currentTime())).toString("mm:ss:zzz") );
               }
            else if (namePlugin.length()==0)
               { m_lastMessage += tr("failure in data source initialisation :  <b>empty plugin name</b>");
               }
            else
               { m_lastMessage += tr("failure in data source <b>%1</b> unknow name").arg(namePlugin);
               }

            //............................... CASSOS SI NOM INCONNU ................................
            if (pC_BDM_PluginI==0)  return 0;
            if (pC_BDM_PluginI->isInitialised())
               {  m_pC_BDM_PluginI_Map[namePlugin] = pC_BDM_PluginI;
               }
            else
               {  pC_BDM_PluginI = 0;
                  m_lastMessage += tr("failure in drug data source <b>%1</b> initialisation").arg(namePlugin);
               }
       }
    //.............. si trouve on prend le plugin ...............................
    else
      {pC_BDM_PluginI = it.value();
      }

    //....................... activer ce plugin dans tous les objets qui en dependent ..................
    if ( pC_BDM_PluginI && pC_BDM_PluginI->isInitialised() && m_pC_BDM_Api)
       {
          m_pC_BDM_Api->connectToDataSource( pC_BDM_PluginI );             // donner au controleur le plugin
          m_pC_BDM_Api->addOwner(pC_BDM_PluginI->owner());                 // n'est rajoute que si n'existe pas
       }
    else
       {pC_BDM_PluginI = 0;
       }
    m_lastMessage += tr("Database '%1' connectée en : %2").arg(namePlugin,   QTime (0, 0, 0, 0 ).addMSecs(debGTime.msecsTo(QTime::currentTime())).toString("mm:ss:zzz") );

    return pC_BDM_PluginI;
}


//============================= C_InteractionsThread ==============================================
//-------------------------------- C_InteractionsThread ------------------------------------------------------
/*! \brief  the constructor intialize BDM structures (each thread must have separate QSqlDatabase)
 *  \param  const QString &pathAppli     general application path
 *  \param  const QString &pathIni       general configuration file application path
 *  \param  const QString &pathTheme     icones and pixmap folder
 *  \param  QObject *parent              parent object
 */
C_InteractionsThread::C_InteractionsThread (  const QString &pathAppli       ,
                                              const QString &pathIni         ,
                                              const QString &pathTheme       ,
                                              QObject *parent
                                           )
    : QThread ( parent )
{ m_pC_BDM_Control      = new C_BDM_Control( pathAppli       ,
                                             pathIni         ,
                                             pathTheme       ,
                                             parent
                                           );
}
//-------------------------------- set_Thread_BDM_Plugin ------------------------------------------------------
/*! \brief set user BDM plugin interface (class interface for unified commercial database).
 *  \param  const QString &_namePlugin name of plugin (Datasemp, Theriaque ...)
 */
void C_InteractionsThread::set_Thread_BDM_Plugin(const QString &_namePlugin)
{ if (m_pC_BDM_Control==0) return;
   m_pC_BDM_Control->set_BDM_Plugin(_namePlugin);
}

//-------------------------------- setContext ------------------------------------------------------
/*! \brief set user and patient context
 *  \param  C_PatientCtx *pC_PatientCtx     pointer on patient context (must be persistant while C_BDM_Control exists)
 *  \param  C_UserCtx *pC_UserCtx           pointer on user context (must be persistant while C_BDM_Control exists)
 *  \param  const QStringList &grammarList  products list
 */
void C_InteractionsThread::setContext (C_PatientCtx *pC_PatientCtx, C_UserCtx *pC_UserCtx, const QStringList &grammarList)
{if (m_pC_BDM_Control==0) return;
 m_pC_BDM_Control->setPatientAndUserContexte(pC_PatientCtx, pC_UserCtx);
 m_grammarList = grammarList;
}

//------------------------------------ run --------------------------------------------------------------------
/*! \brief main methode called  when thread run
 */
void C_InteractionsThread::run()
{   m_HtmlResult = m_pC_BDM_Control->BDM_Api()->evaluateAllInteractions(m_grammarList);
}
//------------------------------------ html_result --------------------------------------------------------------------
/*! \brief   return  interaction result html
 *  \return  QString interaction result html
 */
QString C_InteractionsThread::html_result()
{   if ( isRunning() ) return tr("datas are not ready, work is in progress ...");
    return m_HtmlResult;
}

