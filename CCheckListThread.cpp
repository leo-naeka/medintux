/***************************************************************************
 *   Copyright (C) 2005 by Sevin Roland                                    *
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
#include <qobject.h>
#include "CCheckListThread.h"

//------------------------------------------------- CCheckListThread -----------------------------------------------------
CCheckListThread::CCheckListThread(QSqlDatabase *pQSqlDatabase,
                                   CPatientItemList *pItemList, const QString &dateDeb , const QString &dateFin , const QString &nom, const QString &service,
                                   const QStringList listResultToCheck)
        :QThread(0), m_Fini(FALSE), m_Ready(FALSE)
    {if (listResultToCheck.count()!=0)
        {m_pItemList         = pItemList;
         m_DateDeb           = dateDeb;
         m_DateFin           = dateFin;
         m_nom               = nom;
         m_Service           = service;
         m_listResultToCheck = listResultToCheck;
         m_DataBase          = pQSqlDatabase;
         pItemList->setAutoDelete ( TRUE );
         pItemList->clear();         
         if (m_DataBase) m_Ready = TRUE;
        }
    }
    
//------------------------------------------------- CCheckListThread -----------------------------------------------------
CCheckListThread::CCheckListThread(const QString &driver, const QString &base, const QString &user, const QString &password, const QString &hostname,                           
                                   CPatientItemList *pItemList, const QString &dateDeb , const QString &dateFin , const QString &nom, const QString &service,
                                   const QStringList listResultToCheck)
        :QThread(0), m_Fini(FALSE), m_Ready(FALSE)
    {if (listResultToCheck.count()!=0)
        {m_pItemList         = pItemList;
         m_DateDeb           = dateDeb;
         m_DateFin           = dateFin;
         m_nom               = nom;
         m_Service           = service;
         m_listResultToCheck = listResultToCheck;
         pItemList->setAutoDelete ( TRUE );
         pItemList->clear();
         m_DataBase =  BaseConnect(driver,         // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
                                   base,           // nom de la base: si QODBC3 -> nom de la source de données (userDSN)
                                   user,           // = "root"
                                   password,       // = ""
                                   hostname        // = "localhost"
                                  );
          if (m_DataBase) m_Ready = TRUE;
         }
    }

//-----------------------------------------------------  ~CCheckListThread -------------------------------------------
CCheckListThread::~CCheckListThread()
{//if (m_DataBase) QSqlDatabase::removeDatabase ("QLABOFTP_T"); 
}

//-----------------------------------------------------  BaseConnect --------------------------------------------------
QSqlDatabase*  CCheckListThread::BaseConnect(const char* driver,        // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
                                             const char* DataBaseName,  // nom de la base: si QODBC3 -> nom de la source de données (userDSN)
                                             const char* user,          // = "root"
                                             const char* pasword,       // = ""
                                             const char* hostname,      // = "localhost"
                                             QString*    errMess)
    {

        QSqlDatabase *defaultDB = QSqlDatabase::addDatabase( driver , "QLABOFTP_T");
        if (defaultDB<=0) return 0;
        defaultDB->setDatabaseName( DataBaseName );
        defaultDB->setUserName(     user );
        defaultDB->setPassword(     pasword );
        defaultDB->setHostName(     hostname);
        if ( ! defaultDB->open() ) 
           {QString qstr = "";
            qstr += QObject::tr("Failed to open database: ") + QString(driver) + "  " + QString(DataBaseName) + "\r\n" +
                     defaultDB->lastError().driverText() + "\r\n" + defaultDB->lastError().databaseText();
            qWarning(qstr);
            if (errMess) *errMess = qstr;
            return 0;
           }
        return defaultDB;
    }

//------------------------------------------------- checkList -----------------------------------------------------
void CCheckListThread::checkList()

{   int nb;    
    //................. Preparer la requete .....................................
    if (m_DataBase==0)                                            {qDebug(QObject::tr("CAnalyse::getPatientsList(): m_DataBase = 0 (erreur lors creation) ")); return ; }
    if (m_DataBase->isOpen()==FALSE && m_DataBase->open()==FALSE) {qDebug(QObject::tr("CAnalyse::getPatientsList(): Echec de l'ouverture de la base"));        return ; }
    //................. filtrer selon donnée d'entrée ..................................................
    QString requete("SELECT prim_key , nom , prenom , dateExamen , heureExamen FROM patients WHERE " ); 
    if ( m_nom != "" ) 
       {requete       += "nom LIKE '" + m_nom + "%'";
       }
    if (m_DateDeb != "" && m_DateFin != "") 
       {if (m_nom != "") requete += " AND ";
            requete += "dateExamen >= '" + m_DateDeb + "' AND dateExamen <= '" + m_DateFin + "'";
       } 
    else if (m_DateDeb != "") 
       {if (m_nom != "") requete += " AND ";
            requete += "dateExamen = '" + m_DateDeb + "'";
       }
    if ( m_Service != "" && m_Service != "Tous services") 
       {if (m_nom != "" || m_DateDeb != "" || m_DateFin != "") requete += " AND ";
        requete       += "service = '" + m_Service + "'";
       }
    //qDebug(requete);
    QSqlQuery query(requete , m_DataBase );
    
    //.................. Recuperer la liste des patients ..............................................  
    if ( query.isActive() ) 
       {while (!m_Fini && query.next()) 
              {QString pk = query.value(0).toString();
               nb = GetNbResultForThisPatient(pk, m_listResultToCheck);
               if (nb) m_pItemList->append(new CPatientItem(query.value(1).toString(),
                                                            query.value(2).toString(),
                                                            pk,
                                                            query.value(3).toString(),
                                                            query.value(4).toString(),
                                                            QString::number(nb))
                                           );
              }
        }
    m_DataBase->close();    
}

//------------------------------------ GetNbResultForThisPatient() --------------------------------------------
int CCheckListThread::GetNbResultForThisPatient (const QString &id_patient, QStringList listResultToCheck)
{   int nb = 0;
    //................. Preparer la requete .....................................
    if (m_DataBase==0)                                            {qDebug(QObject::tr("CAnalyse::getDetailsTypeExamen(): m_DataBase = 0 (erreur lors creation) ")); return 0;}
    if (m_DataBase->isOpen()==FALSE && m_DataBase->open()==FALSE) {qDebug(QObject::tr("CAnalyse::getDetailsTypeExamen(): Echec de l'ouverture de la base"));        return 0; }
    //................. filtrer selon donnée d'entrée ..................................................
    //                  peut être limiter la requete ???
    QString requete("SELECT hprim_line FROM examens WHERE ref_prim_key_Patient = '" ); 
    requete       +=   id_patient + "'";
    
    QSqlQuery  query(requete , m_DataBase );
    
    //.................. si la requète a un resultat ..............................................  
    if (query.isActive())
       {        
        while (!m_Fini && query.next())
              {QString segment   =  query.value(0).toString();
               QString test_name = Get_Result_testType(segment, TEST_NAME);
               int        pos    = test_name.find(segment[1]);
               if (pos != -1) 
                  {test_name.truncate(pos);
                   QStringList::Iterator ut = listResultToCheck.find ( test_name );
                   if (ut != listResultToCheck.end() )
                      {++nb;
                       listResultToCheck.remove(ut );
                      }
                  }
              }
       }    
    m_DataBase->close();    
    return nb;
}

//------------------------------------ Get_Result_testType() --------------------------------------------
QString CCheckListThread::Get_Result_testType(QString &segment_line , int posToRetrieve)
{// |¨^ç&|OBX|1|NM|CR   010¨CREATININEMIE.:¨L|1|58.1|mg/l|0.0a13.0|Z||A|F||||CHIMIE¨04¨CR¨11¨01¨ EXAMEN BIOCHIMIQUE DU SANG Par méthode cinétique de Jaffé .
 QChar sep  = segment_line[0];
 int   i    = 0;
 int end    = 0;
 int pos    = -2;   // pour passer le premier tour
 while (pos != 0)
       {if (pos == -2) pos = 0;
        end  = segment_line.find(sep, pos); 
        if      (end == -1 )            return segment_line.mid(pos);
        else if (i   == posToRetrieve ) return segment_line.mid(pos, end-pos);
        ++i;        
        pos = end + 1;
       }
 return QString("");
}

