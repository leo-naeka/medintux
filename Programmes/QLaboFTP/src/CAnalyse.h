 /*************
 * CAnalyse.h **********************************************************************************
* *************                                                                                *
* Classe : CAnalyse                                                                            *
* Créé   : Par Roland SEVIN et Sébastien SIVERA                                                *
*                                                                                              *
* Classe qui analyse les fichier HPRIM reçus et les stocke dans la base                        *
*                                                                                              *
***********************************************************************************************/
#ifndef CANALYSE_H
#define CANALYSE_H

#include <qobject.h>
#include <qlistview.h>
#include <qsqldatabase.h>
#include <qtextbrowser.h>
#include <qstringlist.h>

#include "Global.h"
#include "CExpediteur.h"
#include "CPatient.h"
#include "CCheckListThread.h"

typedef QMap < QString , QString > HPRIM_MAP;

//================================================ CAnalyse ==============================================
class CAnalyse : public QObject
{
    Q_OBJECT

public:

    CAnalyse(const QString &driver, const QString &base, const QString &user, const QString &password, const QString &hostname, const QString &port,
             QObject * parent, const char * name = 0);
    ~CAnalyse();

    enum State { Error , Useless , Analysed  };
    void          getPatientsList (const QString &debut, const QString &fin , const QString &nom, const QString &service , const QString &modele, QListView *listview);
    void          getDetailsExamens (const QString &id_patient , QStringList &examList);
    QString       FusionneModeleWithResultList(const QString &id_patient, QStringList &resultList, QString &modele, QStringList &serviceList);
    QString       FusionneModeleWithInfosPatient(const QString &modele, CPatient &patient, CExpediteur &expediteur, QStringList &serviceList);
    QStringList   GetResultTypeListFromModele( const QString &modele);
    long          GotoEndOfLigne(const QString &txt, long pos=0);
    QSqlDatabase *GetDataBase(){return m_DataBase;};
    int           GotoDebug();
    int           CompareListes( QListView *listview, CPatientItemList &itemList );
    CPatientItem *GetCPatientItemByID(QString id, CPatientItemList &itemList );
    void          PatientItemSetPixmap(QListViewItem *pQListViewItem, const QString &mode);

public slots:

    void fileDownloaded( QString name);

signals:

    void newFileDownloaded( QString );
    void newFileIznogood( QString );
    void fileAnalysed( QString );
    void fileUseless( QString );


private:
    //............................. METHODES ......................................
    QString        ServiceCodeToLibelle(const QString &code, QStringList &serviceList);
    void           OutSQL_error(QSqlQuery &cur, const char *messFunc =0, const char *requete =0);
    int            findNewIndex();
    int            analyseFile( int index );
    QString        Get_Result_type(QString &hprim_line, char sep);
    QString        Get_Result_testType(QString &segment_line, int posToRetrieve);
    QString        GetTitreGroup( long group_deb, long group_end, QString &modele);
    int            FusionneModeleBlocWithResultList(long deb_bloc, long fin_bloc, QStringList &examList, QString &modele, QString &document, const CPatient &patient);
    int            MapTestWithSegmentHprim(QStringList &test_list, HPRIM_MAP &map_list, QStringList &resultList);
    QString        GetIDPatient(CPatient &patient, CExpediteur &expediteur);
    int            GetPatientByPrimKey(const QString &primKey, CPatient &patient, CExpediteur &expediteur);
    int            GetMinMaxValue(const QString &test_name, const QString &sexe, QString &test_valMin, QString &test_valMax);
    QString        DateToString(const QString &date, const char* sep);
    QString        HeureToString(const QString &heure, const char* sep);
    QString        toNumStr(const char *str);
    QSqlDatabase*  BaseConnect(const char* driver,        // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
                                     const char* DataBaseName,      // nom de la base: si QODBC3 -> nom de la source de données (userDSN)
                                     const char* user,              // = "root"
                                     const char* pasword,           // = ""
                                     const char* hostname,          // = "localhost"
                                     const char* port,              // = "3306"
                                     QString*    errMess = 0);
    QString        CalculeDiffAge(QDate *pDebut, QDate *pFin=NULL, bool bTexte=TRUE, int bAbrege=1);
    QString        IsThisPatientExist(CPatient &patient/*, CExpediteur &expediteur*/);
    QString        CreateNewPatient(CPatient &patient, CExpediteur &expediteur);
    int            recordResult(const QString &separator, QString &hprim_line,  QString &id_Patient);
    int            TestMinMax(const QString &val, const QString &min, const QString &max);
    int            FillMapWhithTagEndDebTetsName(HPRIM_MAP &hprimMap, long deb_bloc, long fin_bloc, QString &modele, const QString &token);
    void           getDetailsExamenFromTypeList (const QString &id_patient , QStringList &examList, const QStringList &testListMask);
    int            getNbResultForThisPatient (const QString &id_patient , QStringList listResultToCheck);
    //int            recordRequest(QString &hprim_line, QString &id_Patient);
    //void           OutSQL_error(QSqlQuery &cur, const char *messFunc =0, const char *requete =0);
    //void           OutSQL_error(QSqlQuery *cur, const char *messFunc =0, const char *requete =0);
    //............................. DATA .............................................
    LocalMap      m_Files;
    char          m_SepVal;
    QSqlDatabase *m_DataBase;

};


#endif
//CANALYSE_H
