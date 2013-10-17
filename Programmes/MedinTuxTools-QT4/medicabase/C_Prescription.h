/***************************** C_Prescription.h ***************************
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
#ifndef C_PRESCRIPTION_H
#define C_PRESCRIPTION_H

#include <QObject>
#include <QList>

#include "../../MedinTuxTools-QT4/medicabase/C_BDM_Api.h"
#include "../../MedinTuxTools-QT4/medicabase/C_PatientCtx.h"

class C_BDM_Api;
//===================================================== C_Prescription =====================================
class C_Prescription : public QObject
{
    Q_OBJECT
public:
    //--------------------------------- C_Prescription -----------------------------------------
    explicit C_Prescription( C_BDM_Api* pC_BDM_Api, C_PatientCtx *pC_PatientCtx, QObject *parent = 0);

    //--------------------------------- setOrdonnance -----------------------------------------
    void                         setOrdonnance (QList <C_OrdoLineRecord> & ordoLineRecord_List);
    //--------------------------------- getOrdonnance -----------------------------------------
    QList <C_OrdoLineRecord>     getOrdonnance ();
    //--------------------------------- savePrescription -----------------------------------------
    int                          savePrescription();
    //--------------------------------- getListMedicaments -----------------------------------------
    /*! \brief return list of drugs from free text.
     *  \param const QString &texte           free text
     *  \param C_BDM_Api::flags               filter flags
     *  \return QList <C_BDM_DrugListRecord>  drugs list
     */
    QList <C_BDM_DrugListRecord> getListMedicaments (const QString &texte, C_BDM_PluginI::flags);

    //--------------------------------- getListSchemasPrescriptifs -----------------------------------------
    /*! \brief return list of prescriptive grammar schemas from drug Id .
     *  \param const QString &id          value get by C_BDM_DrugListRecord.id()
     *  \param const QString &id_type     value get by C_BDM_DrugListRecord.id_type()
     *  \return QstringList               prescriptive grammar strings list as : [500-mg]1-2-3(10-12=1/4)(18-20=1/4)(23-24=1/2)x9#[250-mg]4-6-8(10-12=1/2)(18-20=1/2) x 16
     */
    QStringList                  getListSchemasPrescriptifs(const QString &id, const QString &id_type);

    //--------------------------------- setListSchemasPrescriptifs -----------------------------------------
    void                         setListSchemasPrescriptifs(const QString &id, const QString &id_type, const QStringList & schemasList);

    //--------------------------------- getListIndications -----------------------------------------
    QStringList                  getListIndications (const QString &id, const QString &id_type, const QString &smrLevel);
    //--------------------------------- getListAlertes -----------------------------------------
    QStringList                  getListAlertes();

private:
        C_BDM_Api*                m_pC_BDM_Api;
        C_PatientCtx*             m_pC_PatientCtx;
        QList <C_OrdoLineRecord>  m_OrdoLineRecordList;
signals:

public slots:

};

#endif // C_PRESCRIPTION_H
