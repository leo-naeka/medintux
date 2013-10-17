/***************************** C_Prescription.cpp *************************
*  #include "C_Prescription.h"        QT4-ready                           *
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

#include "C_Prescription.h"
#include "../univers/C_DateTools.h"

//--------------------------------- C_Prescription -----------------------------------------
C_Prescription::C_Prescription(C_BDM_Api* pC_BDM_Api, C_PatientCtx* pC_PatientCtx, QObject *parent) :
    QObject(parent)
{m_pC_BDM_Api            =  pC_BDM_Api;
 m_pC_PatientCtx         =  pC_PatientCtx;
}
//--------------------------------- setOrdonnance -----------------------------------------
void C_Prescription::setOrdonnance (QList <C_OrdoLineRecord> & ordoLineRecord_List)
     {m_OrdoLineRecordList = ordoLineRecord_List;
     }
//--------------------------------- getOrdonnance -----------------------------------------
QList <C_OrdoLineRecord> C_Prescription::getOrdonnance ()
     { return m_OrdoLineRecordList;
     }

//--------------------------------- savePrescription -----------------------------------------
int C_Prescription::savePrescription()
{ return 0;
}
//--------------------------------- getListMedicaments -----------------------------------------
QList < C_BDM_DrugListRecord > C_Prescription::getListMedicaments (const QString &texte, C_BDM_PluginI::flags fl)
{ QList < C_BDM_DrugListRecord > null_list;
  if (m_pC_BDM_Api ==0) return  null_list;
  return    m_pC_BDM_Api-> selectProductsList(texte, fl);
}

//--------------------------------- getListSchemasPrescriptifs -----------------------------------------
QStringList C_Prescription::getListSchemasPrescriptifs(const QString &id, const QString &id_type)
{
  Q_UNUSED(id);
  Q_UNUSED(id_type);
  QStringList lst;
  return lst;
}

//--------------------------------- setListSchemasPrescriptifs -----------------------------------------
void C_Prescription::setListSchemasPrescriptifs(const QString &id, const QString &id_type, const QStringList & schemasList)
{Q_UNUSED(id);
 Q_UNUSED(id_type);
 Q_UNUSED(schemasList);
}

//--------------------------------- getListIndications -----------------------------------------
QStringList C_Prescription::getListIndications (const QString &id, const QString &id_type, const QString &smrLevel)
{ Q_UNUSED(id);
  Q_UNUSED(id_type);
  Q_UNUSED(smrLevel);
  QStringList lst;
  return lst;
}
//--------------------------------- getListAlertes -----------------------------------------
QStringList C_Prescription::getListAlertes()
{ QStringList lst;
  return lst;
}


