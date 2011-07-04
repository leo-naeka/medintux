 /*************
 * CAnalyse.h **********************************************************************************
* *************                                                                                *
* Classe : CAnalyse                                                                            *
* Créé   : Par Roland SEVIN et Sébastien SIVERA                                                *
*                                                                                              *
* Classe qui analyse les fichier HPRIM reçus et les stocke dans la base                        *
*                                                                                              *
***********************************************************************************************/

#include "CAnalyse.h"

#include <qobject.h>
#include <qsqlcursor.h>
#include <qsqlrecord.h>
#include <qsqlfield.h>
#include <qsqlerror.h>
#include <qvariant.h>

#define TEST_SEP      1
#define TEST_NAME     5
#define TEST_RESULT   7
#define TEST_UNIT     8
#define TEST_MINMAX   9

#include "images/LED_verte.xpm"
#include "images/LED_grise.xpm"
#include "images/LED_rouge.xpm"

//---------------------------------- CAnalyse() ------------------------------------------------
CAnalyse::CAnalyse(const QString &driver, const QString &base, const QString &user, const QString &password, const QString &hostname, const QString &port,
                   QObject * parent, const char * name /*= 0*/)
    : QObject(parent,name)
{   m_DataBase =  BaseConnect(driver,        // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
                              base,          // nom de la base: si QODBC3 -> nom de la source de données (userDSN)
                              user,          // = "root"
                              password,      // = ""
                              hostname,      // = "localhost"
                              port           // = "3306" 
                             );
    // connexion faite dans le cas ou on ne pourrait pas lire le fichier du premier coup
    connect(this, SIGNAL( newFileDownloaded( QString ) ) , this , SLOT( fileDownloaded( QString ) ) );
    m_SepVal    = 'a';
}

//---------------------------------- ~CAnalyse() ------------------------------------------------
CAnalyse::~CAnalyse()
{QSqlDatabase::removeDatabase ("QLABOFTP");
}

//-----------------------------------------------------  BaseConnect -------------------------------------------
QSqlDatabase*  CAnalyse::BaseConnect(const char* driver,        // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
                                     const char* DataBaseName,  // nom de la base: si QODBC3 -> nom de la source de données (userDSN)
                                     const char* user,          // = "root"
                                     const char* pasword,       // = ""
                                     const char* hostname,      // = "localhost"
                                     const char* port,          // = "3306"
                                     QString*    errMess)
    {

        QSqlDatabase *defaultDB = QSqlDatabase::addDatabase( driver , "QLABOFTP");
        if (defaultDB<=0) return 0;
        defaultDB->setDatabaseName( DataBaseName );
        defaultDB->setUserName(     user );
        defaultDB->setPassword(     pasword );
        defaultDB->setHostName(     hostname);
        defaultDB->setPort(         QString(port).toInt());
        
        if ( ! defaultDB->open() )
           {QString qstr = "";
            qstr += tr("Failed to open database: ") + QString(driver) + "  " + QString(DataBaseName) + "\r\n" +
                     defaultDB->lastError().driverText() + "\r\n" + defaultDB->lastError().databaseText();
            qWarning(qstr);
            if (errMess) *errMess = qstr;
            return 0;
           }
        return defaultDB;
    }

//---------------------------------- fileDownloaded() -------------------------------------------
// Interception du signal newFileDownloaded()
void CAnalyse::fileDownloaded( QString name)
{
    // Déclaration d'un index pour mémoriser le nom du fichier dans un QMap
    int i = findNewIndex();
    // on mémorise le nom du fichier dans le QMap
    m_Files.insert( i , name );
    // on demande l'analyse du fichier
    int result_analyse = analyseFile(i);

    switch ( result_analyse ) {
    case CAnalyse::Error: // si non analysé
        // on efface la référence du fichier dans le QMap
        m_Files.erase(i);
        // on emet le signal pour une ré-analyse du fichier
        // emit newFileDownloaded(name);
        emit newFileIznogood( name  );
        // Cassos
        return;
        break;
    case CAnalyse::Useless: // si il est inutile
        // on efface la référence du fichier dans le QMap
        m_Files.erase(i);
        emit fileUseless( name );
        break;
    case CAnalyse::Analysed: // si l'analyse est correcte
        // on efface la référence du fichier dans le QMap
        m_Files.erase(i);
        // on emet un signal de succés
        emit fileAnalysed( name );
        break;
    }
}

//----------------------------------- findNewIndex() --------------------------------------------
int CAnalyse::findNewIndex()
{
    // on part à zéro
    int index = 0;
    // tant qu'il existe une référence de même index dans le QMap
    while (m_Files.find(index) != m_Files.end()) {
        // on incrémente l'index
        index++;
    }
    // on retourne le premier index libre
    return index;
}

//------------------------------------ analyseFile() --------------------------------------------
int CAnalyse::analyseFile(int index)
{
    //....................... on initialise le resultat = faux .............................
    int result       = CAnalyse::Error /*0*/;
    //........................on recupère le nom du fichier à analyser ...................
    QString fileName = m_Files.find(index).data();
    //........................on créé un fichier virtuel du fichier ......................
    QFile file( fileName );
    //........................on test la taille du fichier : ...............................
    //                        si elle est égale à zéro on retourne sans analyser
    if (file.size() == 0) return CAnalyse::Useless/*1*/;
    // on ouvre le fichier en lecture
    if ( file.open( IO_ReadOnly ) ) { // si c'est possible
        //......... on crée un stream sur le fichier .....................................
        QTextStream stream ( &file );
        stream.setEncoding(QTextStream::Latin1);
        //.......... on déclare une variable pour le lire ligne à ligne ..................
        QString segment_line  = "";
        int     line_number   = 0;
        int             pos   = -1;
        QString  id_Patient("");
        QString segment_type("");
        QString separator("");
        //.............. tant que la fin du fichier n'est pas atteinte ...................
        // enum State { Error , Useless , IsPatient, IsExpediteur, IsResultData, IsResultHeader, IsEndOfFile };

        CExpediteur expediteur;    // expediteur courant
        CPatient    patient;       // patient courant
        while (!stream.atEnd())
           {//...........on lit une ligne ...............................................................
            segment_line    = stream.readLine().stripWhiteSpace();
            if (segment_line.length())  // peut y en avoir des vides !!!
               {line_number++;

                //........... entete du fichier on en extrait: .............................................
                //            l'expéditeur en cours, les separateurs
                //      H|~^\&|URG062.HPR||133002782~CASALTA||ORU|||MARURG~Marignane Urgence||P|H2.0|200410291528
                //
                if (line_number==1)
                   {if (segment_line[0] != 'H')                                        return result;
                    separator     = segment_line[1];
                    segment_type  = "H";
                    int end       = segment_line.find(separator[0], 2);
                    if (end != -1)  separator += segment_line.mid(2, end-pos-3);
                    expediteur.setFromHprimLine(segment_line, separator);
                   }
                else
                   {pos           = segment_line.find(separator[0]);  if  (pos==-1)    return result;
                    segment_type  = segment_line.left(pos);
                   }

                //........... entete de patient ............................................................
                //    P|0001||||LAGRECA~CALOGERA||19271207|F||~~~~|||||||||||||20041030^0928
                //
                if ( segment_type == "P" )            // definition d'un patient (tous les résultats placé à sa suite lui appartiennent)
                   { patient.setFromHprimLine(segment_line, separator);
                   }
                //........... entete de definion de resultat ...............................................
                //            doit être suivi immédiatement par une ligne d'OBX
                //   OBR|0001|041030MA1045~041030MA1045||N^PLQ^F^TP^TCK|R||200410300928|200410300928|||N||||200410300928|
                //
                else if ( segment_type == "OBR" )     // definition des resultats rendus (doit suivre après OBR une série d'OBX)
                   {patient.m_OBR_Ident = Get_Result_type(segment_line, separator[0].latin1());
                    id_Patient          = GetIDPatient(patient, expediteur);  // recherche ou creée le patient dans la base de données
                   }
                //.............. detail des examens .........................................................
                //    OBX|0001|TX|N    010~n u m e r a t i o n   g l o b||.||||||||                           type demande de lexamen
                //    OBX|0001|NM|N    020~globules blancs..............:||5960|/mm3|vr : 4 a  10000||||||    type rendu   de l'examen
                else if ( segment_type == "OBX" )
                   { QString type = Get_Result_type(segment_line, separator[0].latin1());
                     if  ( type == "NM" || type == "TX" ) recordResult (separator, segment_line, id_Patient);
                   }
                 else if ( segment_type == "L" )      // voila c'est la fin du fichier
                   {
                   }
             } //if (segment_line.length())
        }
        // on initialise le resultat = vrai
        result = CAnalyse::Analysed/*2*/;
    }
    // on renvoi le resultat
    return result;
}

//------------------------------------ Get_Result_type() --------------------------------------------
QString CAnalyse::Get_Result_type(QString &segment_line, char sep)
{//  OBX|0001|TX|N
 //  OBR|0001|041030MA1045~041030MA1045|N
 QString type ("");
 int pos      = segment_line.find(sep, 0)   + 1;         if (pos      == 0 )   return type;
     pos      = segment_line.find(sep, pos) + 1;         if (pos      == 0 )   return type;
 int end      = segment_line.find(sep, pos);             if (end      == -1 )  return type;
 return segment_line.mid(pos, end-pos);
}

//------------------------------------ Get_Result_testType() --------------------------------------------
QString CAnalyse::Get_Result_testType(QString &segment_line , int posToRetrieve)
{//  OBX|0001|TX|N
 //  OBR|0001|041030MA1045~041030MA1045|N
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

//------------------------------------ GetIDPatient() --------------------------------------------
// ACTION: recherche dans la base de donnée si il existe un patient déjà existant pour
//         l'expediteur donné dans                              : CExpediteur &expediteur
//         et pour les caractéristiques du patient données dans : CPatient    &patient
//         si il existe dèjà alors on retourne la clef primaire de l'enregistrement
//         Sinon on crée l'enregistrement et on retourne la clef primaire
//         chaque résultat aura pour réference la clef primaire d'un enregistrement de ce type
// RETOUR: clef primaire de l'enregistrement patient-expediteur

QString CAnalyse::GetIDPatient(CPatient &patient, CExpediteur &expediteur)
{QString pk = IsThisPatientExist(patient/*, expediteur*/);
 if (pk.length()) return pk;
 else             return CreateNewPatient(patient, expediteur);
}


//----------------------------------------------------- FusionneModeleWithInfosPatient ----------------------------------------------------------
QString CAnalyse::FusionneModeleWithInfosPatient(const QString &modele, CPatient &patient, CExpediteur &expediteur, QStringList &serviceList)
{//$DEB_ENTETE Résultats de: {{nom}} {{prenom}} en date du: {{date_examen}} à {{heure_examen}}
 //$FIN_ENTETE
 QString result("");
 int deb_bloc = modele.find("$DEB_ENTETE", 0);
 if (deb_bloc== -1) return result;
 deb_bloc += 11;
 int end_bloc = modele.find("$FIN_ENTETE", deb_bloc);
 if (end_bloc== -1) return QString (tr("Erreur de syntaxe : marqueur de fin d'entete: $FIN_ENTETE absent"));          // erreur de syntaxe
 result = modele.mid(deb_bloc, end_bloc - deb_bloc);

 result.replace("{{nom}}"           ,   patient.m_nom);
 result.replace("{{prenom}}"        ,   patient.m_prenom);
 result.replace("{{dateNaissance}}" ,   DateToString(patient.m_dateNaissance,"-") );
 result.replace("{{sexe}}"          ,   patient.m_sexe);
 result.replace("{{dateExamen}}"    ,   DateToString(patient.m_dateExamen,"-") );
 result.replace("{{heureExamen}}"   ,   HeureToString(patient.m_heureExamen,":") );
 result.replace("{{OBR_Ident}}"     ,   patient.m_OBR_Ident);
 result.replace("{{service}}"       ,   ServiceCodeToLibelle(patient.m_Service, serviceList) );
 QDate dateNss(patient.m_dateNaissance.left(4).toInt(),
               patient.m_dateNaissance.mid(4,2).toInt(),
                   patient.m_dateNaissance.mid(6,2).toInt()
                  );
 QString age = CalculeDiffAge(&dateNss); //QDate ( int y, int m, int d )
 result.replace("{{age}}" ,       age);

 result.replace("{{codeExpediteur}}" ,     expediteur.m_codeExpediteur);
 result.replace("{{nomExpediteur}}" ,      expediteur.m_nomExpediteur);
 result.replace("{{codeDestinataire}}" ,   expediteur.m_codeDestinataire);
 result.replace("{{nomDestinataire}}" ,    expediteur.m_nomDestinataire);
 result.replace("{{dateEmission}}" ,       DateToString(expediteur.m_dateEmission,"-"));
 result.replace("{{heureEmission}}" ,      HeureToString(expediteur.m_heureEmission,":") );

 return result;
}

//----------------------------------------------------- ServiceCodeToLibelle ----------------------------------------------------------
QString CAnalyse::ServiceCodeToLibelle(const QString &code, QStringList &serviceList)
{for ( QStringList::Iterator it = serviceList.begin(); it != serviceList.end(); ++it )
     {QString str = *it;
      int p       = str.findRev("=");
      if (p != -1)
         {if (str.mid(p+1).stripWhiteSpace() == code) return str.left(p).stripWhiteSpace();
         }
     }
 return tr("non précisé");
}

//----------------------------------------------------- DateToString ----------------------------------------------------------
QString CAnalyse::DateToString(const QString &date, const char* sep)
{QString result = date.mid(6,2)+sep+date.mid(4,2)+sep+date.mid(0,4);
 return result;
}

//----------------------------------------------------- HeureToString ----------------------------------------------------------
QString CAnalyse::HeureToString(const QString &heure, const char* sep)
{QString result = heure.left(2)+sep+heure.mid(2,2);
 return result;
}

//----------------------------------------------------- FusionneModeleWithResultList ----------------------------------------------------------
QString CAnalyse::FusionneModeleWithResultList(const QString &id_patient, QStringList &resultList, QString &modele, QStringList &serviceList)
{QString      result("");
 CPatient     patient;
 CExpediteur  expediteur;
 //............ recuperer patient et expediteur .......................................................
 if (GetPatientByPrimKey(id_patient, patient, expediteur) == 0) return result;
 //........................... faire les remplacements entete .........................................
 result = FusionneModeleWithInfosPatient(modele, patient, expediteur, serviceList);
 if (result.length()) result.replace("{{patientID}}", id_patient);
 //........................... faire les remplacements ................................................
 int group_deb       = modele.find("$DEB_GROUP=", 0);
 int group_end       = group_deb;
 int deb_bloc        = 0;
 int fin_bloc        = 0;
 long pos_title      = 0;
 long      nb_bloc   = 0;
 //.................recuperer separateur de valeur normales..................
 deb_bloc = modele.find("$SEP_VAL=", deb_bloc);    // deb_bloc utilisé provisoirement
 if (deb_bloc != -1) m_SepVal = ((const char*)modele.mid(deb_bloc+9,1))[0];
 //................ parser le masque d'afichage ...............................
 while (group_deb != -1)
       {
        group_end = modele.find("$FIN_GROUP", group_deb);
        if (group_end != -1)
           {QString titre = GetTitreGroup( group_deb,  group_end, modele);
            pos_title     = result.length();
            nb_bloc       = 0;
            deb_bloc      = modele.find("$DEB_BLOC", deb_bloc);
            while (deb_bloc   != -1 && deb_bloc < group_end)
               {deb_bloc  += 9;
                fin_bloc   = modele.find("$FIN_BLOC", deb_bloc);
                if (fin_bloc != -1)
                   {QString document("");
                    if (FusionneModeleBlocWithResultList(deb_bloc, fin_bloc, resultList, modele, document, patient))
                       {result += document;
                        ++nb_bloc;
                       }
                   }
                else return QString(tr("Erreur de syntaxe : $FIN_BLOC non trouvé"));
                deb_bloc   = modele.find("$DEB_BLOC", fin_bloc);
               }
            if (nb_bloc) result.insert (pos_title, titre);
           }
        else return QString(tr("Erreur de syntaxe : $FIN_GROUP   non trouvé"));
        group_deb       = modele.find("$DEB_GROUP=", group_end);
       }
 return result;
}

//----------------------------------------------------- FusionneModeleWithResultList ----------------------------------------------------------
QStringList CAnalyse::GetResultTypeListFromModele( const QString &modele)
{int  group_deb      = modele.find("$DEB_GROUP=", 0);
 int  group_end      = group_deb;
 int  end            = 0;
 long pos            = 0;
 long nb             = 0;
 QString testString  = "";
 QStringList testListMask;
 char *pt;
 //................ parser le masque d'afichage ...............................
 //                 pour recuperer liste des tests
 //                 le concernant
 while (group_deb != -1)
       {
        group_end = modele.find("$FIN_GROUP", group_deb);
        if (group_end != -1)
           {//................... rechercher pour ce groupe la liste des tests à afficher ......................
            pos = modele.find("$CODES_GROUP=", group_deb+11);
            if (pos==-1 || pos>group_end)             return 0;      // erreur syntaxe
            pos        += 7;
            end         = GotoEndOfLigne(modele, pos);
            pt          = pos + (char*)(const char*)modele;
            if (nb) testString += '|';
            testString += modele.mid(pos,end-pos).stripWhiteSpace();
            ++nb;
           }
        else return 0;
        group_deb       = modele.find("$DEB_GROUP=", group_end);
       }
 //...................... verifier si la liste du patient....................................
 //                       contient des tests demandés par
 //                       le masque d'affichage
 testListMask = QStringList::split('|',testString);
 testListMask.sort();
 return testListMask;
}

//------------------------------------ GotoDebug() --------------------------------------------
int CAnalyse::GotoDebug()
{return 1;
}

//------------------------------------ getNbResultForThisPatient() --------------------------------------------
int CAnalyse::getNbResultForThisPatient (const QString &id_patient ,  QStringList listResultToCheck)
{   int nb = 0;
    //................. Preparer la requete .....................................
    if (m_DataBase==0)                                            {qDebug(tr("CAnalyse::getDetailsTypeExamen(): m_DataBase = 0 (erreur lors creation) ")); return 0;}
    if (m_DataBase->isOpen()==FALSE && m_DataBase->open()==FALSE) {qDebug(tr("CAnalyse::getDetailsTypeExamen(): Echec de l'ouverture de la base"));        return 0; }
    //................. filtrer selon donnée d'entrée ..................................................
    //                  peut être limiter la requete ???
    QString requete("SELECT hprim_line FROM examens WHERE ref_prim_key_Patient = '" );
    requete       +=  id_patient + "'";

    QSqlQuery query (requete , m_DataBase );

    //.................. si la requète a un resultat ..............................................
    if (query.isActive())
       {
        while (query.next())
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

//------------------------------------ getDetailsExamenFromTypeList() --------------------------------------------
void CAnalyse::getDetailsExamenFromTypeList (const QString &id_patient , QStringList &examList, const QStringList &testListMask)
{   examList.clear();
    //................. Preparer la requete .....................................
    if (m_DataBase==0)                                            {qDebug(tr("CAnalyse::getDetailsTypeExamen(): m_DataBase = 0 (erreur lors creation) ")); return ;}
    if (m_DataBase->isOpen()==FALSE && m_DataBase->open()==FALSE) {qDebug(tr("CAnalyse::getDetailsTypeExamen(): Echec de l'ouverture de la base"));        return ; }
    //................. filtrer selon donnée d'entrée ..................................................
    //                  peut être limiter la requete ???
    QString requete("SELECT hprim_line FROM examens WHERE ref_prim_key_Patient = '" );
    requete       += id_patient + "'";

    QSqlQuery query(requete , m_DataBase );

    //.................. si la requète a un resultat ..............................................
    if (query.isActive())
       {while (query.next())
              {QString segment   =  query.value(0).toString();
               QString test_name = Get_Result_testType(segment, TEST_NAME);
               int           pos = test_name.find(segment[1]);
               if (pos != -1)
                  {test_name.truncate(pos);
                   if (testListMask.findIndex(test_name)) examList.append(segment);
                  }
              }
       }
    m_DataBase->close();
}

//----------------------------------------------------- GetTitreGroup -------------------------------------------------------------
QString CAnalyse::GetTitreGroup(long group_deb, long group_end, QString &modele)
{//$TITRE_GROUP=<b><u>Examens sanguins</b></u>
 int pos = modele.find("$TITRE_GROUP=", group_deb);
 if (pos == -1 || pos>group_end) return QString("");
 pos += 13;
 int end = GotoEndOfLigne(modele, pos);
 if (end == -1 || end>group_end) return QString("");
 return modele.mid(pos, end - pos).stripWhiteSpace();
}

//----------------------------------------------------- FillMapWhithTagEndDebTetsName -------------------------------------------------------------
int CAnalyse::FillMapWhithTagEndDebTetsName(HPRIM_MAP &hprimMap, long deb_bloc, long fin_bloc, QString &modele, const QString &token)
{QString tag, value;
 long pos = deb_bloc;
 long end = 0;
 int  nb  = 0;
 while(pos<fin_bloc && pos != -1)
       {pos = modele.find(token, pos);
        if (pos != -1 && pos<fin_bloc)
           {pos += 9;
            end = modele.find("=", pos);
            if (end != -1 && end<fin_bloc)
               {tag = modele.mid(pos,end-pos).stripWhiteSpace();
                pos = end + 1;
                end = GotoEndOfLigne(modele, pos);
                if (end != -1)  value = modele.mid(pos, end-pos);
                else            return -1;      // erreur syntaxe
                hprimMap.insert (tag, value);
                ++nb;
               }
           }
      }// while(pos<fin_bloc)
 return nb;
}

//----------------------------------------------------- GetMinMaxValue ----------------------------------------------------------
int  CAnalyse::GetMinMaxValue(const QString &test_name, const QString &sexe, QString &test_valMin, QString &test_valMax)
{   //................. Preparer la requete .....................................
    if (m_DataBase==0)                                            {qDebug(tr("CAnalyse::GetMinMaxValue(): m_DataBase = 0 (erreur lors creation) ")); return 0; }
    if (m_DataBase->isOpen()==FALSE && m_DataBase->open()==FALSE) {qDebug(tr("CAnalyse::GetMinMaxValue(): Echec de l'ouverture de la base"));        return 0; }

    QString requete("SELECT val_min, val_max FROM min_max WHERE test_name ='" );
    QSqlQuery query (requete + test_name + "' AND sexe ='"+sexe+"'", m_DataBase );
    //.................. si la requète a un resultat ..............................................
    if (query.isActive() && query.next())
       {test_valMin = query.value(0).toString();
        test_valMax = query.value(1).toString();
         m_DataBase->close();
        return 1;
       }
    m_DataBase->close();
    return 0;
}

//----------------------------------------------------- FusionneModeleBlocWithResultList ----------------------------------------------------------
int  CAnalyse::FusionneModeleBlocWithResultList(long deb_bloc, long fin_bloc, QStringList &examList, QString &modele, QString &document, const CPatient &patient)
{HPRIM_MAP map_err_deb, map_err_fin, map_test_hprim;
 QString tag;
 QString value;

 QStringList test_list;
 long pos = deb_bloc;
 long end = 0;
 document = "";
 //....................... relever les codes necessaires à ce bloc .........................................
 // $CODES=NV   020|FV   060|FV   020|FV   040|FV   080|FV   100
 pos = modele.find("$CODES=", deb_bloc);
 if (pos==-1 || pos>fin_bloc)                                          return 0;      // erreur syntaxe
 pos      += 7;
 end       = GotoEndOfLigne(modele, pos);
 value     = modele.mid(pos,end-pos).stripWhiteSpace();
 test_list = QStringList::split('|',value);
 if (MapTestWithSegmentHprim(test_list, map_test_hprim, examList)==0)  return 0;   // pas de resultat pour ce bloc
 int nb = 0;
 //........ relever les tag de debutet fin des erreurs pour chaque code de ce bloc ...............................
 // $DEB_ERR.TCK  020=<span style="font-weight:600;color:#550000">
 nb = FillMapWhithTagEndDebTetsName(map_err_deb, deb_bloc, fin_bloc,  modele, "$DEB_ERR.");
 if (nb==-1) return 0; // erreur syntaxe
 nb = FillMapWhithTagEndDebTetsName(map_err_fin, deb_bloc, fin_bloc,  modele, "$FIN_ERR.");
 if (nb==-1) return 0; // erreur syntaxe

 //........ relever les tag de debut de ligne de ce bloc...............................
 // $DEB_LIGNE=<br>
 QString tag_deb_ligne;
 pos = modele.find("$DEB_LIGNE=", pos);
 if (pos != -1 && pos<fin_bloc)
    {end           = GotoEndOfLigne(modele, pos);
     tag_deb_ligne = modele.mid(pos,end-pos).stripWhiteSpace();
     pos = tag_deb_ligne.find('=');
     if (pos != -1) tag_deb_ligne = tag_deb_ligne.mid(pos+1);
    }
 //........ relever les tag de fin de ligne de ce bloc...............................
 // $FIN_LIGNE=
 QString tag_fin_ligne;
 pos = modele.find("$FIN_LIGNE=", pos);
 if (pos != -1 && pos<fin_bloc)
    {end           = GotoEndOfLigne(modele, pos);
     tag_fin_ligne = modele.mid(pos,end-pos).stripWhiteSpace();
     pos = tag_fin_ligne.find('=');
     if (pos != -1) tag_fin_ligne = tag_fin_ligne.mid(pos+1);
    }

 //..................... s'occuper maintenant du texte ................................

 // $DEB_TEXTE={{IF=TCK  020}} &nbsp;&nbsp;&nbsp;&nbsp;<b>TCK:&nbsp;témoin</b>&nbsp;&nbsp;{{$DEB_ERR.TCK  020}}{{TCK  020}}{{$FIN_ERR.TCK  020}}
 //                            &nbsp;&nbsp;<b>patient:</b>&nbsp;&nbsp;{{$DEB_ERR.TCK  030}}{{TCK  030}}{{$FIN_ERR.TCK  030}}&nbsp;&nbsp;{{$UNIT.TCK  020}}
 //            {{/IF}}
 //            {{IF=TCK  040}} &nbsp;&nbsp;&nbsp;&nbsp;<b>TCA:&nbsp;patient/témoin</b>&nbsp;&nbsp;{{$DEB_ERR.TCK  040}}{{TCK  040}}{{$FIN_ERR.TCK  040}}
 //            {{/IF}}
 // $FIN_TEXTE
 pos = modele.find("$DEB_TEXTE=", deb_bloc);
 if (pos == -1  || pos>fin_bloc)           return 0;  // erreur syntaxe
 long deb_texte =  pos + 11;
 long end_texte =  modele.find("$FIN_TEXTE", deb_texte);
 if (end_texte== -1 || end_texte>fin_bloc) return 0;  // erreur syntaxe

 document = modele.mid(deb_texte, end_texte-deb_texte);
 document.prepend(tag_deb_ligne);
 QString      toReplace;
 QString      replaceBy;
 QString      test_name;
 QStringList  segmentList;
 QString      test_valMax = "";
 QString      test_valMin = "";
 int          erreur      = 0;
 int          pos_deb     = 0;
 int          pos_end     = 0;
 //........................... faire les remplacemenst ................................................
 pos_deb = document.find("{{", pos_end);
 while (pos_deb != -1)
       {pos_end = document.find("}}", pos_deb);
        if (pos_end != -1 &&  pos_deb != -1)
           {toReplace = document.mid(pos_deb, pos_end-pos_deb+2);
            //............. relever la liste des test concerné ..................................
            if (toReplace.left(5)=="{{IF=")
               {document.replace ( pos_deb, toReplace.length(), "");   // effacer le tag de debut {{IF= XXX}}
                pos_end      = document.find("{{/IF}}", pos_deb);      // reperer la fin de la ligne conditionnelle
                test_name    = toReplace.mid(5, toReplace.length()-7); // recuperer nom du test à afficher
                segmentList  = QStringList::split(map_test_hprim[test_name][0], map_test_hprim[test_name], TRUE);      // recuperer le segment de valeurs Hprim pour ce test
                test_valMax  = "";
                test_valMin  = "";
                erreur       = 0;
                replaceBy    = "";
                //................... si il y a un resultat pour ce test à afficher .........
                //                    recuperer les valeurs et tester depassements
                if (segmentList.count()>=TEST_MINMAX)
                   {replaceBy    = segmentList[TEST_RESULT];                                            // valeur Hprim du resultat
                    pos          = segmentList[TEST_MINMAX].find(m_SepVal);
                    if (pos != -1)
                       {test_valMax   = segmentList[TEST_MINMAX].mid(pos+1);
                        test_valMin   = segmentList[TEST_MINMAX].left(pos);
                        erreur        = TestMinMax(replaceBy, test_valMin, test_valMax);
                       }
                    else if (GetMinMaxValue(test_name, patient.m_sexe, test_valMin, test_valMax))
                      {erreur        = TestMinMax(replaceBy, test_valMin, test_valMax);
                      }
                   }
                if (replaceBy.length()==0)                                           // si valeur non présente ne pas inclure ce resultat et tout effacer
                   {document.replace ( pos_end, 7, "");                              // effacer {{/IF}}
                    document.replace ( pos_deb, pos_end - pos_deb, "");              // effacer de {{IF= XXX}} à  {{/IF}} (toute la ligne)
                   }
                else //................ en effaçant juste  {{IF= XXX}} et {{/IF}} ..................
                     //                 la ligne se place dans la config normale traitée dans le dernier: else
                   {document.replace ( pos_end, 7, "");                              // effacer {{/IF}}
                   }
               }

            else if (toReplace.left(6)=="{{$NL.")    // valeur max et min {{$NL.TP   020|(NL: de [min] à [max])|(NL: de 70 à 100 )}}
               {int Ok = 0;
                QString name = toReplace.mid(6,toReplace.length()-8);
                //........... recuperer les segments du tag .........................
                segmentList  = QStringList::split('|', name, TRUE);
                name         = segmentList[0];
                replaceBy    = Get_Result_testType(map_test_hprim[name], TEST_MINMAX);
                pos          = replaceBy.find(m_SepVal);
                //................. rechercher valeurs min et max ...................
                //                  directement dans le resultat du patient
                if (pos != -1)
                   {test_valMax   = toNumStr(replaceBy.mid(pos+1));
                    test_valMin   = toNumStr(replaceBy.left(pos));
                    if (test_valMax.length()||test_valMin.length()) Ok = 1;   // si au moins une des deux valeurs présentes c'est Ok
                   }
                //................. si pas trouvée chercher dans la base de données ................
                //                  des valeurs normales
                if ( Ok==0 )
                   {Ok =GetMinMaxValue(name, patient.m_sexe, test_valMin, test_valMax);
                   }
                if (Ok)
                   {replaceBy = segmentList[1];
                    replaceBy.replace("[min]",  test_valMin);
                    replaceBy.replace("[max]",  test_valMax);
                   }
                else
                   {replaceBy = segmentList[2].replace("}}","");
                   }
                document.replace ( pos_deb, toReplace.length(), replaceBy);
               }
            else if (toReplace.left(11)=="{{$DEB_ERR.")
               {if (erreur)
                   {QString name = toReplace.mid(11,toReplace.length()-13);
                    document.replace ( pos_deb, pos_end - pos_deb+2, map_err_deb[name]);
                   }
                else
                   {document.replace ( pos_deb, pos_end - pos_deb+2, "");
                   }
               }
            else if (toReplace.left(11)=="{{$FIN_ERR.")
               {if (erreur)
                   {QString name = toReplace.mid(11,toReplace.length()-13);
                    document.replace ( pos_deb, pos_end - pos_deb+2, map_err_fin[name]);
                   }
                else
                   {document.replace ( pos_deb, pos_end - pos_deb+2, "");
                   }
               }
            else if (toReplace.left(8)=="{{$UNIT.")
               {QString name = toReplace.mid(8,toReplace.length()-10);
                replaceBy    = Get_Result_testType(map_test_hprim[name], TEST_UNIT);
                document.replace ( pos_deb, toReplace.length(), replaceBy);
               }
            else     //   {{XXX}}    test name
               {QString name = toReplace.mid(2,toReplace.length()-4);
                replaceBy    = Get_Result_testType(map_test_hprim[name], TEST_RESULT);
                replaceBy.replace('>',"&gt;");
                replaceBy.replace('<',"&lt;");
                document.replace ( pos_deb, toReplace.length(), replaceBy);
                pos_deb  +=  replaceBy.length();
               }
           }
        pos_deb = document.find("{{", pos_deb);
       }
 return 1;
}

//------------------------------------------------- TestMinMax --------------------------------------------------------------------------
int CAnalyse::TestMinMax(const QString &sval, const QString &min, const QString &max)
{bool maxok, minok, valok;
 float val     = sval.toFloat(&valok);  if (valok==FALSE) return 0;
 float valMax  = toNumStr(max).toFloat(&maxok);
 float valMin  = toNumStr(min).toFloat(&minok);
 if (maxok==FALSE && minok==FALSE) return 0;
 if (maxok==FALSE && val<valMin)   return 1;
 if (minok==FALSE && val>valMax)   return 1;
 if (val>valMax || val<valMin)     return 1;
 return 0;
}

//----------------------------------------------------- toNumStr -----------------------------------------------------------------------
QString CAnalyse::toNumStr(const char *str)
{QString result("");
 char *pt = (char*) str;
 if (pt==0) return result;
 while (*pt)
    {char c = *pt;
     if (c==',') c='.';
     if ( (c>='0' && c<='9') || c=='.'|| c=='-'|| c=='+') result += c;
     ++pt;
    }
 return result;
}

//----------------------------------------------------- MapTestWithSegmentHprim----------------------------------------------------------
// ACTION: crée une QMap liste avec comme clef le nom de l'examen dont on va avoir besoin et comme valeur son segment HPRIM
//         au cas où il est présent dans la liste de resultats
int CAnalyse::MapTestWithSegmentHprim(QStringList &test_list, HPRIM_MAP &map_list, QStringList &resultList)
{int nb = 0;
 //OBX|0001|NM|N    020~globules blancs..............:||13570|/mm3|vr : 4 a  10000||||||
 for ( QStringList::Iterator it = resultList.begin(); it != resultList.end(); ++it )
     {QString test_name = Get_Result_testType(*it, TEST_NAME);
      int           pos = test_name.find( (*it)[1]);
      if (pos != -1)
         {test_name.truncate(pos);
          if (test_list.findIndex( test_name ) != -1)
             {map_list.insert(test_name, *it);
              ++nb;
             }
         }
     }
 return nb;
}

//----------------------------------------------------- GetPatientByPrimKey ----------------------------------------------------------
int  CAnalyse::GetPatientByPrimKey(const QString &primKey, CPatient &patient, CExpediteur &expediteur)
{   //................. Preparer la requete .....................................
    if (m_DataBase==0)
    {qDebug(tr("CAnalyse::GetMinMaxValue(): m_DataBase = 0 (erreur lors creation) ")); return 0; }
    if (m_DataBase->isOpen()==FALSE && m_DataBase->open()==FALSE)
    {qDebug(tr("CAnalyse::GetMinMaxValue(): Echec de l'ouverture de la base"));        return 0; }

    QString requete("SELECT nom, prenom, dateNaissance, sexe, dateExamen, heureExamen, definitionExamen, HprimSep, service, "
                    "codeExpediteur, nomExpediteur, codeDestinataire, nomDestinataire, dateEmission, heureEmission "
                    "FROM patients WHERE prim_key ='" );
    QSqlQuery query (requete + primKey + "'", m_DataBase );
    //.................. si la requète a un resultat ..............................................
    if (query.isActive() && query.next())
       {patient.m_nom           = query.value(0).toString();
        patient.m_prenom        = query.value(1).toString();
        patient.m_dateNaissance = query.value(2).toString();
        patient.m_sexe          = query.value(3).toString();
        patient.m_dateExamen    = query.value(4).toString();
        patient.m_heureExamen   = query.value(5).toString();
        patient.m_OBR_Ident     = query.value(6).toString();
        patient.m_Separator     = query.value(7).toString();
    patient.m_Service       = query.value(8).toString();
        //expediteur.m_nomOriginal      = query.value(7).toString();
        expediteur.m_codeExpediteur   = query.value(9).toString();
        expediteur.m_nomExpediteur    = query.value(10).toString();
        expediteur.m_codeDestinataire = query.value(11).toString();
        expediteur.m_nomDestinataire  = query.value(12).toString();
        expediteur.m_dateEmission     = query.value(13).toString();
        expediteur.m_heureEmission    = query.value(14).toString();
        m_DataBase->close();
        return 1;
       }
    m_DataBase->close();
    return 0;
}

//-----------------------------------------------------  IsThisPatientExist -------------------------------------------
QString CAnalyse::IsThisPatientExist(CPatient &patient/*, CExpediteur &expediteur*/)
{
 QString ret("");
  //................. Preparer la requete .....................................
  if (m_DataBase==0)                                               {qDebug(tr("CAnalyse::IsThisPatientExist(): m_DataBase = 0 (erreur lors creation) ")); return 0; }
  if (m_DataBase->isOpen()==FALSE && m_DataBase->open()==FALSE)    {qDebug(tr("CAnalyse::IsThisPatientExist(): Echec de l'ouverture de la base"));        return 0; }
  //................. filtrer selon donnée d'entrée ..................................................
  //                  peut être limiter la requete ???
  QString requete("SELECT " );
  requete       += "prim_key ";
  requete       += "FROM   patients  WHERE ";
  //requete       += "nom              = '"   + patient.m_nom                  + "' AND ";
  //requete       += "prenom           = '"   + patient.m_prenom               + "' AND ";
  //requete       += "dateNaissance    = '"   + patient.m_dateNaissance        + "' AND ";
  //requete       += "sexe             = '"   + patient.m_sexe                 + "' AND ";
  //requete       += "dateExamen       = '"   + patient.m_dateExamen           + "' AND ";
  //requete       += "heureExamen      = '"   + patient.m_heureExamen          + "' AND ";
  requete       += "definitionExamen = '"   + patient.m_OBR_Ident            + "'"; // "' AND ";
  //requete       += "codeExpediteur   = '"   + expediteur.m_codeExpediteur    + "' AND ";
  //requete       += "nomExpediteur    = '"   + expediteur.m_nomExpediteur     + "' AND ";
  //requete       += "codeDestinataire = '"   + expediteur.m_codeDestinataire  + "' AND ";
  //requete       += "nomDestinataire  = '"   + expediteur.m_nomDestinataire   + "'"; // "' AND ";


  QSqlQuery* pSqlQuery = new QSqlQuery(requete , m_DataBase );

  //.................. si la requète a un resultat ..............................................
  if (pSqlQuery && pSqlQuery->isActive() && pSqlQuery->next())
     {ret                    = pSqlQuery->value(0).toString();
     }
  if (pSqlQuery) delete  pSqlQuery;
  m_DataBase->close();
  return ret;
}

//-----------------------------------------------------  CreateNewPatient -------------------------------------------
QString CAnalyse::CreateNewPatient(CPatient &patient, CExpediteur &expediteur)
{ QString ret("");
  //................................. methode QSqlCursor .....................................
  //                         ne pose pas de PB avec valeur avec une apostrophe
  //............... ouvrir la base .......................................................
  if (m_DataBase->isOpen()==FALSE && m_DataBase->open()==FALSE)  return QString("");
  //............... crer un curseur SQL ..................................................
  QSqlCursor cur("patients", TRUE, m_DataBase);
  if ( !cur.canInsert ())                                        return QString("");
  //............... si OK on recupere le buffer et on le charge avec les données .........
  QSqlRecord *buffer = cur.primeInsert();                         // recuperer le buffer d'insertion
  buffer->setValue("HprimSep"             , patient.m_Separator            );
  buffer->setValue("nom"                  , patient.m_nom                  );
  buffer->setValue("prenom"               , patient.m_prenom               );
  buffer->setValue("dateNaissance"        , patient.m_dateNaissance        );
  buffer->setValue("sexe"                 , patient.m_sexe                 );
  buffer->setValue("dateExamen"           , patient.m_dateExamen           );
  buffer->setValue("heureExamen"          , patient.m_heureExamen          );
  buffer->setValue("definitionExamen"     , patient.m_OBR_Ident            );
  buffer->setValue("service"              , patient.m_Service              );

  buffer->setValue("codeExpediteur"       , expediteur.m_codeExpediteur    );
  buffer->setValue("nomExpediteur"        , expediteur.m_nomExpediteur     );
  buffer->setValue("codeDestinataire"     , expediteur.m_codeDestinataire  );
  buffer->setValue("nomDestinataire"      , expediteur.m_nomDestinataire   );
  buffer->setValue("heureEmission"        , expediteur.m_heureEmission     );
  buffer->setValue("dateEmission"         , expediteur.m_dateEmission      );
  if (!cur.insert()) OutSQL_error(cur, "CreateNewPatient()");

  cur.select( QString("definitionExamen = '") + patient.m_OBR_Ident + "'" );
  if ( cur.next() )        ret = cur.value("prim_key").toString();

  //......................... fermer la base ..............................................
  m_DataBase->close();
  return ret;
}
//-------------------------------------------------- OutSQL_error -----------------------------------------------
void CAnalyse::OutSQL_error(QSqlQuery &cur, const char *messFunc /*=0*/, const char *requete /*=0*/)
{    QSqlError error = cur.lastError();
     QString   qserr("");

     if (error.type() != QSqlError::None)
        {switch (error.type())
           { case    QSqlError::None:           qserr =tr(" - no error occurred: ")          ; break;
             case    QSqlError::Connection:     qserr =tr(" - connection error: ")           ; break;
             case    QSqlError::Statement:      qserr =tr(" - SQL statement syntax error: ") ; break;
             case    QSqlError::Transaction:    qserr =tr(" - transaction failed error: ")   ; break;
             case    QSqlError::Unknown:        qserr =tr(" - unknown error: ")              ; break;
             default:                           qserr =tr(" - unknown error: ")              ; break;
           }
         if (messFunc) qDebug(messFunc);
         qDebug(qserr + error.databaseText ());
         if (requete) qDebug(requete);
        }
//     qDebug(qserr + error.databaseText ());
}
//------------------------------------ recordResult() --------------------------------------------
// ACTION: enregistre dans la table des résultats une ligne de resultat avec l'id_Patient auquel il
//         appartient
int CAnalyse::recordResult(const QString &separator, QString &segment_line, QString &id_Patient)
{ //................................. methode QSqlCursor .....................................
  //                         ne pose pas de PB avec valeur avec une apostrophe
  int ok=0;
  //............... ouvrir la base .......................................................
  if (m_DataBase->isOpen()==FALSE && m_DataBase->open()==FALSE)  return ok;
  //............... crer un curseur SQL ..................................................
  QSqlCursor cur("examens", TRUE, m_DataBase);
  if ( !cur.canInsert ())                                        return ok;
  //............... si OK on recupere le buffer et on le charge avec les données .........
  QSqlRecord *buffer = cur.primeInsert();                         // recuperer le buffer d'insertion
  buffer->setValue("hprim_line"                   , separator + separator[0] + segment_line                );
  buffer->setValue("ref_prim_key_Patient"         , id_Patient                                             );
  if (cur.insert()) ok = 1;

  //......................... fermer la base ..............................................
  m_DataBase->close();
  return ok;
}

//
//------------------------------------ getPatientsList() --------------------------------------------
void CAnalyse::getPatientsList (const QString &debut , const QString &fin , const QString &nom, const QString &service, const QString &modele , QListView *listview)
{   int nb;
    listview->clear();
    QStringList listResultToCheck = GetResultTypeListFromModele(modele);
    //................. Preparer la requete .....................................
    if (m_DataBase==0)                                            {qDebug(tr("CAnalyse::getPatientsList(): m_DataBase = 0 (erreur lors creation) ")); return ; }
    if (m_DataBase->isOpen()==FALSE && m_DataBase->open()==FALSE) {qDebug(tr("CAnalyse::getPatientsList(): Echec de l'ouverture de la base"));        return ; }
    //................. filtrer selon donnée d'entrée ..................................................
    //                  peut être limiter la requete ???
    QString requete("SELECT prim_key , nom , prenom , dateExamen , heureExamen FROM patients WHERE " );
    if ( nom != "" )
       {requete       += "nom LIKE '" + nom + "%'";
       }
    if (debut != "" && fin != "")
       {if (nom != "") requete += " AND ";
            requete += "dateExamen >= '" + debut + "' AND dateExamen <= '" + fin + "'";
       }
    else if (debut != "")
       {if (nom != "") requete += " AND ";
            requete += "dateExamen = '" + debut + "'";
       }
    if ( service != "" && service != tr("Tous services"))
       {if (nom != "" || debut != "" || fin != "") requete += " AND ";
        requete       += "service = '" + service + "'";
       }
    QSqlQuery query(requete , m_DataBase );

    //.................. Recuperer la liste des patients ..............................................
    if ( query.isActive() )
       {while (query.next())
              {QString pk = query.value(0).toString();
               nb = getNbResultForThisPatient(pk, listResultToCheck);
               if (nb){QListViewItem *pQListViewItem = new QListViewItem (listview,
                                                                          query.value(1).toString(),  // nom          0
                                                                          query.value(2).toString(),  // prenom       1
                                                                          query.value(3).toString(),  // date         2
                                                                          query.value(4).toString(),  // heure        3
                                                                          pk,                         // ID           4
                                                                                  QString::number(nb));       // nb           5
                       if (pQListViewItem) pQListViewItem->setPixmap ( 0, QPixmap (LED_grise_xpm) );
                      }
              }
        }
    m_DataBase->close();
}

//------------------------------------ CompareListes() --------------------------------------------
int CAnalyse::CompareListes( QListView *listview, CPatientItemList &itemList )
{int same = 0;
 //................................... parcourir la listview et rechercher .........................
 //                               pour chaque item si il existe dans la liste des patients
 //                               si oui voir si nb examen est le meme et le signaler
 //                                  si different, et effacer cette item de la liste des patients
 QListViewItemIterator it( listview );
 while ( it.current() )
       {QListViewItem *pQListViewItem = *it;
        CPatientItem  *pCPatientItem  = GetCPatientItemByID(pQListViewItem->text(4), itemList );
        //.............. cet item de la listview  a été trouvé dans la nouvelle liste des .........................
        //               patients, alors comparer si meme nb d'examen et si c'est pas le cas
        //               le signaler
        if (pCPatientItem)
           {if (pCPatientItem->m_nbOBX  != pQListViewItem->text(5))
               {pQListViewItem->setText(5, pCPatientItem->m_nbOBX);
                pQListViewItem->setPixmap ( 0, QPixmap (LED_verte_xpm) ); // Patient déjà présent dans la liste avec nouveau resultat
                ++same;
               }
            else
               {//pQListViewItem->setPixmap ( 0, QPixmap (LED_grise_xpm) ); // Patient déjà présent dans la liste sans nouveau resultat
               }
            itemList.remove (pCPatientItem);   // ne plus évaluer ce patient donc l'effacer
           }
        ++it;
       }
 //......................... à ce stade les éléments restants sont de nouveaux patients .............................
 CPatientItem *item;
 for ( item = itemList.first(); item; item = itemList.next() )
    {QListViewItem *pQListViewItem = new QListViewItem (listview,
                                                        item->m_nom,         // nom          0
                                                        item->m_prenom,      // prenom       1
                                                        item->m_Date,        // date         2
                                                        item->m_Heure,       // heure        3
                                                        item->m_ID,          // ID           4
                                                        item->m_nbOBX        // nb           5
                                                       );
     if (pQListViewItem) pQListViewItem->setPixmap ( 0, QPixmap (LED_rouge_xpm) );
     ++same;
    }
 return same;
}

//------------------------------------ PatientItemSetPixmap() --------------------------------------------
void CAnalyse::PatientItemSetPixmap(QListViewItem *pQListViewItem, const QString &mode)
{if      (mode =="gray")   pQListViewItem->setPixmap ( 0, QPixmap (LED_grise_xpm) );
 else if (mode =="green")  pQListViewItem->setPixmap ( 0, QPixmap (LED_verte_xpm) );
 else                      pQListViewItem->setPixmap ( 0, QPixmap (LED_rouge_xpm) );
}

//------------------------------------ GetCPatientItemByID() --------------------------------------------
CPatientItem *CAnalyse::GetCPatientItemByID(QString id, CPatientItemList &itemList )
{CPatientItem *item;
 for ( item = itemList.first(); item; item = itemList.next() )
    {if (item->m_ID == id) return item;
    }
 return 0;
}

//------------------------------------ getDetailsExamens() --------------------------------------------
void CAnalyse::getDetailsExamens (const QString &id_patient , QStringList &examList)
{
    //................. Preparer la requete .....................................
    if (m_DataBase==0) {qDebug(tr("CAnalyse::IsThisPatientExist(): m_DataBase = 0 (erreur lors creation) "));                                     return ; }
    if (m_DataBase->isOpen()==FALSE && m_DataBase->open()==FALSE) {qDebug(tr("CAnalyse::IsThisPatientExist(): Echec de l'ouverture de la base")); return ;  }
    //................. filtrer selon donnée d'entrée ..................................................
    QString requete("SELECT hprim_line FROM examens WHERE ref_prim_key_Patient = '" );
    requete       +=  id_patient + "'";
    QSqlQuery query (requete , m_DataBase );

    //.................. si la requète a un resultat ..............................................
    if (query.isActive()) {
        examList.clear();
        while (query.next())
           { examList.append(query.value(0).toString());
           }
    }
    m_DataBase->close();
}

//------------------------------ GotoEndOfLigne -----------------------------------------
long CAnalyse::GotoEndOfLigne(const QString &txt, long i /*=0*/)
{long len = txt.length();
 const char *pt = (char*)(const char*) txt;
 pt += i;
 while (i<len)
    {     if ( i<len-1 && *pt=='\\'&&  pt[1]=='\\')         return i;
     else if ( i<len-1 && *pt=='\r'&&  pt[1]=='\n')         return i;
     else if ( i<len-1 && *pt=='\n'&&  pt[1]=='\r')         return i;
     else if ( *pt=='\n')                                   return i;
     else if ( *pt=='\r')                                   return i;
     else {++pt; ++i;}
    }
 return i;
}

//-----------------------------------------------------  CalculeDiffAge -------------------------------------------------
// ACTION: calcule l'age entre deux dates de début et de fin.
// ENTREE: QDate *pDebut: pointe sur une QDate de debut (exemple date de naissance)
//         QDate *pFin:   pointe sur une QDate de  fin (peut etre zero alors il sera pris la date en cours)
//         bool bTexte:   TRUE   alors la date sera exprimée comme: 4 ans 6 mois 3 jours
//                        FALSE  alors la date sera exprimée comme un chiffre
//         int bAbrege:   2  et alors seules les années seront sorties sous la forme: "0" ou "35" etc ...
//                        1  et alors seules les années seront sorties sous la forme: "0" ou "35" etc ...
//                        0  et alors les sorties seront detaillées avec si age<3 avec les mois et jours:
QString CAnalyse::CalculeDiffAge(QDate *pDebut, QDate *pFin/*=NULL*/, bool bTexte/*=TRUE*/, int bAbrege/*=1*/)
{
 char finMois[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 int an=0;
 int mois=0;
 int jour=0;
 int dayYearDebut;
 int dayYearFin;
 QString buffer;
 QString sRes("");
 bool bFinAlloue = FALSE;
 long lEtatDayYear;

 if (pDebut && pDebut->isValid ())
    {
     if (pFin==NULL)
        {pFin       = new QDate;
         *pFin      = QDate::currentDate ();
         bFinAlloue = TRUE;
        }//if

     if (pFin->isValid ())
        {
         //.........................................Partie calcul ..........................................
         //........Le jour de l'année .................
         dayYearDebut = pDebut->dayOfYear ();
         dayYearFin   = pFin->dayOfYear ();
         //................................ bisextiles and cie ..................................................
         //ATTENTION A L'ANNEE BISEXTILLE (sauf en l'an 1900, car les débuts de siecles ne sont pas bisextille sauf les débuts de millénaire
         //60eme jour => 29 Février
         if (pDebut->year()%4==0 && pDebut->year()%100 && pDebut->year()%1000    &&  dayYearDebut>60 )
             dayYearDebut--;
         if (pFin->year()%4==0   && pFin->year()%100   && pFin->year()%1000      &&  dayYearFin>60)
             dayYearFin--;

          //....................Position des jours l'un par rapport à l'autre ....................................
          if      (dayYearFin<dayYearDebut)     lEtatDayYear = -1;
          else if (dayYearFin>dayYearDebut)     lEtatDayYear =  1;
          else                                  lEtatDayYear =  0;

          //...................Calcul année (-1 si le jour de l'année en cour est <) .............................
          an = pFin->year() - pDebut->year() - (lEtatDayYear<0? 1 :0);

          if (lEtatDayYear!=0)
             {
              //.......................Calcul mois .....................................
              if (lEtatDayYear<0)
                  mois = 12 - pDebut->month() + pFin->month()   - (pFin->day()<pDebut->day()? 1 :0);
              else
                  mois = pFin->month()        - pDebut->month() - (pFin->day()<pDebut->day()? 1 :0);

              //...................... Calcul du jour ...................................
              if (pFin->day() < pDebut->day())
                  jour=(finMois[pFin->month()>1 ? pFin->month()-2 : 11] - pDebut->day()) + pFin->day();
              else
                  jour=pFin->day() - pDebut->day();
             } //if(lEtatDayYear!=0)

             //.............................................. Partie texte .........................................
          if (an)
             {
              if (bTexte)
                  //buffer.sprintf("%d an%s ", an, an>1 ? "s" : "");
                  buffer = QString::number(an) + tr(" an") + ((an>1) ? "s " : " ");
              else
                  buffer.sprintf("%d ", an);
              sRes = buffer;
             } //if (an)
          //.................... si bAbrege==2 alors on ne sort que les années .......................................
          if (bAbrege==2)
             {if (an==0) sRes="0";
              if(bFinAlloue)  delete pFin;
              return sRes;
             }
          if (!bAbrege || an < 3 /* || an<3*/) // age Inferieur à 3 ans et version detaillée
             {
              if (mois || !bTexte)
                 {
                  if (bTexte)
                      //buffer.sprintf("%d mois ", mois);  // en fançais " mois " à déjà un s en [4] donc ne pas rajouter si plusieurs
                     {QString ms = tr(" mois");  // va bien y avoir un dialecte où ça ne va pas marcher
                      buffer     = QString::number(mois)+ ms + ((mois>1&&ms[4]!='s') ? "s " : " ");
                     }
                  else
                      buffer.sprintf("%d ", mois);
                  sRes+=buffer;
                } // if (mois || !bTexte)

              if (jour || !bTexte)
                 {
                  if (bTexte)
                      //buffer.sprintf("%d jour%s ", jour, jour>1 ? "s" : "");
                      buffer = QString::number(jour) + tr(" jour") + ((jour>1) ? "s " : " ");
                  else
                      buffer.sprintf("%d ", jour);
                  sRes += buffer;
                 } // if  (jour || !bTexte)
              }// if (!bAbrege || an<3) //Inferieure à 3 ans
          }// if (pFin->m_status==COleDateTime::valid)
     }// if (pDebut && pDebut->m_status==COleDateTime::valid)

     if(bFinAlloue)  delete pFin;
     return sRes;
}
