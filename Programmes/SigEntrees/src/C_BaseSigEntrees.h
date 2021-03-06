#ifndef C_BaseSigEntrees_H
#define C_BaseSigEntrees_H
#include "../../MedinTuxTools-QT4/C_BaseCommon.h"
#include "C_DSigemsVar.h"
class QDate;
class QTreeWidget;

#define DATE_NULLE "1111-11-11T11:11:11"
//================================================ CPatient ==============================================
class CPatient
{
 public:
     CPatient();
     CPatient(const QString& hprim_line, const QString &separator);
     CPatient(const QString& nom,
              const QString& prenom,
              const QString& dateNss,
              const QString& sexe,
              const QString& obrIdent,
              const QString& service,
              const QString& separator,
              const QString& dateExam,
              const QString& heureExam,
              const QString& pk           ="",
              const QString& nbObx        ="",
              const QString& fileNameRef  ="" );
     void setFromHprimLineH ( const QString& hprim_line, const QString &separator);
     void setFromHprimLine  ( const QString& hprim_line, const QString &separator);
     void setFromHprimLineAP( const QString& hprim_line, const QString &separator);
     //QString getOBRId();
     //void    setOBRId(const QString &value);
     QString getPkRecord();
     void    setPkRecord(const QString &value);
     QString getDateExam();
     void    setDateExam(const QString &value);
     QString getHeureExam();
     void    setHeureExam(const QString &value);
     QString getFileRef();
     void    setFileRef(const QString &value);
     QString getNbObx();
     void    setNbObx(const QString &value);
     QString     m_Separator;
     QString     m_nom;
     QString     m_prenom;
     QString     m_dateNaissance;
     QString     m_sexe;
     QString     m_GUID_Pat;
     QString     m_numSS;
     QString     m_dateEntree;
     QString     m_Blob_HPR;
     QString     m_numEntreeSigems;
     QString     m_Qualite;
     QString     m_Rang_geme;
     QString     m_num_pat_sigems;


private:
     QString     m_OBR_Ident;
     QString     m_dateExam;
     QString     m_heureExam;
     QString     m_pkRecord;
     QString     m_fileNameRef;
     QString     m_nbOBX;

};

//====================================== C_BaseSigEntrees =====================================
class C_BaseSigEntrees : public C_BaseCommon, C_DSigemsVar
{
    Q_OBJECT


public:
    enum State { Pdf, FileCanNotOpen, Not_Hprim, SeparatorNotFound, Error , Useless , Analysed  };

    explicit  C_BaseSigEntrees(const QString &param , QString& confData,  QObject *parent);
    bool      reConnect(const QString &param);
    QString   getVersionConfig();
    QString   getLastError();
    // int       fillPatientList(QTreeWidget* pQTreeWidget, const QString &debut ="", const QString &fin ="" , const QString &nom ="", const QString &service ="");
    int       fill_CPatientMap(QMap<QString, CPatient> &patientPk_CPatient_Map,
                               const QString &debut ,
                               const QString &fin ,
                               const QString &nom,
                               const QString &_service );
    int       getExamensListFromPatient  (const QString &id_patient , QStringList &examList);
 //   QString   FusionneModeleWithResultList(const QString &id_patient, QStringList &resultList, QString &modele, QStringList &serviceList);
    int       analyseFile(const QString &fileName);
//    int       setService(const QString &pk, const QString &service);

    void     addEntryIntreeWidget_Patients(CPatient &patient);
     void      MAJ_Patients_PrisEnCharge(  );
      QString   read_Blob_Hprim(QString pkEntree );

private:
    int         getNbResultForThisPatient (const QString &id_patient ,  QStringList listResultToCheck);
    QStringList setCodeHprimListFromTemplate( const QString &modele);
    int       recordHprimLineResult(const QString &separator, QString &segment_line, QString &id_Patient);

    QString   CreateNewEntry(CPatient &patient);


 //   QString   CreateNewPatient(CPatient &patient, CExpediteur &expediteur);
 //   QString   GetIDPatient(CPatient &patient, CExpediteur &expediteur);
    QString   IsThisPatientExist(CPatient &patient);
    QString   Get_Hprim_UniqueId(QString &segment_line, QString sep);
 //   QString   FusionneModeleWithInfosPatient(const QString &modele, CPatient &patient, CExpediteur &expediteur, QStringList &serviceList);
    QString   ServiceCodeToLibelle(const QString &code, QStringList &serviceList);
    QString   DateToString(const QString &date, const char* sep);
    QString   HeureToString(const QString &heure, const char* sep);
//    int       GetPatientByPrimKey(const QString &primKey, CPatient &patient, CExpediteur &expediteur);
    int       FusionneModeleBlocWithResultList(long deb_bloc, long fin_bloc, QStringList &examList, QString &modele, QString &document, const CPatient &patient);
    int       MapTestWithSegmentHprim(QStringList &test_list, QMap < QString , QString > &map_list, QStringList &resultList);
    int       FillMapWhithTagEndDebTetsName(QMap < QString , QString >  &hprimMap, long deb_bloc, long fin_bloc, QString &modele, const QString &token);
    QString   CalculeDiffAge(QDate *pDebut, QDate *pFin=NULL, bool bTexte=true, int bAbrege=1);
    long      GotoEndOfLigne(const QString &txt, int i=0);
    QString   GetTitreGroup(long group_deb, long group_end, QString &modele);
    QString   toNumStr(const QString &str);
    QString   getService(const QString & separator, const QString &segment_type, const QStringList &servicesDefs, const QStringList &servicesList,const QString &segment_line);
    int       TestMinMax(QString &val, const QString &min, const QString &max);
    int       GetMinMaxValue(const QString &test_name, const QString &sexe, QString &test_valMin, QString &test_valMax);
    QString   Get_Result_testType(const QString &segment_line , int posToRetrieve);
    void      setLastError(const QString &error);


private:
    QString      m_LastError;
    QString      m_SepVal;
    QStringList  m_HprimCodeList;   /*!< liste des codes hprim que le template exploite          */
};

#endif // C_BaseSigEntrees_H
