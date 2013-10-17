/********************************* $FILE$ *****************************************

    Project: MedinTux
    Copyright (C) 2005 by Roland Sevin  and Data Medical Design
    E-Mail: mzdintux@medintux.org

    This program is free software; you can redistribute it and/or modify
    it under the terms of the CeCILL Version 1 du 21/06/2004
    License (GPL compatible)
                               http://www.cecill.info/
    as published by :

    Commissariat �l'Energie Atomique
    - CEA,
                             31-33 rue de la F��ation, 75752 PARIS cedex 15.
                             FRANCE
    Centre National de la Recherche Scientifique
    - CNRS,
                             3 rue Michel-Ange, 75794 Paris cedex 16.
                             FRANCE
    Institut National de Recherche en Informatique et en Automatique
    - INRIA,
                             Domaine de Voluceau, Rocquencourt, BP 105, 78153
                             FRANCE

          This program is distributed in the hope that it will be useful,
          but WITHOUT ANY WARRANTY; without even the implied warranty of
          MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
          CeCILL  License (GPL compatible) for more details.

 **********************************************************************************/

#ifndef  CTHERA_BASE_H
#define  CTHERA_BASE_H

#include <qsqldatabase.h>
#include <qobject.h>
#include <math.h>


#define SKIP_BLANK_CAR(a)     while( *(a) && (*(a)==' ' || *(a)=='\t' || *(a)== 96) ) (a)++
#define NEXT_LINE(a)          while( *(a) && *(a)!='\r' && *(a)!='\n')(a)++; while( *(a) && (*(a)=='\r'|| *(a)=='\n'))(a)++
#define TR  QObject::tr

//===================================== CMedicaBase ========================================================================
class CTheraBase
{
public:
   CTheraBase();
   CTheraBase(QString path_MedicaBase_ini,  QString path_MedicaBase_cfg);
   void Init_Base( QString &path_MedicaBase_ini,  QString &path_MedicaBase_cfg);
  ~CTheraBase();
  QSqlDatabase*  BaseConnect(const char* driver,        // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
                             const char* DataBaseName,  // nom de la base: si QODBC3 -> nom de la source de données (userDSN)
                             const char* user,          // = "root"
                             const char* pasword,       // = ""
                             const char* hostname,      // = "localhost"
                             const char* baseName,
                             QString*    errMess=0);
  int            SetConfBase(const char* confFile, QString err);
  char          *SetConfBase_SetProperties(char *pt, QString &propertie, const char *token, int *line , QString &err);
  int            OutSQL_error( const QSqlQuery &cur, const char *messFunc =0, const char *requete =0);
  int            GotoDebug();
  QString        Utf8_Query(QSqlQuery &cur, int field);

public:
  //......................................... DATA ........................................................

  //........................ MEDICA_TUX  Table index des produits .........................................
  //                         la structure d' l'index est commune
  //

  QString  m_MEDICA_INDEX_MED_TBL_NAME;         // nom  de la table index general des médicaments de medica
  QString  m_MEDICA_INDEX_DIET_TBL_NAME;        // nom  de la table index general des produits diététiques
  QString  m_MEDICA_INDEX_VETO_TBL_NAME;        // nom  de la table index general des produits vétérinaires
  QString  m_MEDICA_INDEX_PARA_TBL_NAME;        // nom  de la table index general des produits de parapharmacie
  QString  m_MEDICA_INDEX_ACCS_TBL_NAME;        // nom  de la table index general des produits TIPS et accessoires
  QString  m_MEDICA_INDEX_HERBO_TBL_NAME;       // nom  de la table index general des produits divers et herboristerie
  QString  m_MEDICA_INDEX_HOMEO_TBL_NAME;       // nom  de la table index general des produits homéopathiques
  QString  m_MEDICA_INDEX_PK;                   // Primary Key de la table
  QString  m_MEDICA_INDEX_LIBELLE;              // nom  du libelle (non du médicament)
  QString  m_MEDICA_INDEX_CIP;                  // code CIP  EST LA CLEF PRIMAIRE  !!
  //          si les 4 champs suivants sont vides alors le vidal n'est pas dispo
  //          chercher alors dans medica tux
  QString  m_MEDICA_INDEX_PK_T00;             // Vidal: reference de ce produit dans la table T00
  QString  m_MEDICA_INDEX_PK_T4B;             // Vidal: reference de ce produit dans la table T4B
  QString  m_MEDICA_INDEX_CD_PROD;            // Vidal: code Vidal PRODUIT
  QString  m_MEDICA_INDEX_CD_UV;              // Vidal: code Vidal Unite de vente
  QString  m_MEDICA_INDEX_IS_GENE;            // medicament generique ?
  QString  m_MEDICA_INDEX_IS_DISPO;           // produit disponible
  //........................ MEDICA_TUX  Table de SPECIFICATION .........................................
  QString  m_MEDICA_SPEC_TBL_NAME;           // nom de la table des specifications
  QString  m_MEDICA_SPEC_CIP;                // code CIP
  QString  m_MEDICA_SPEC_UP_UNIT;            // Primary Key de la table des formes et unites (comprimé ampoules etc ...)   UPUnit
  QString  m_MEDICA_SPEC_PA_UNIT;            // Unite    de principe actif  (mg ml etc...):                                PAUnit
  QString  m_MEDICA_SPEC_PA_QU;              // Quantite de principe actif par unité de prise:                             QPAbyUP
  QString  m_MEDICA_SPEC_SECABILITE;         // Secabilite:                                                                Secabilite
  QString  m_MEDICA_SPEC_IS_GENERIC;         // G  pour générique R pour réference d'un groupe ATC
  QString  m_MEDICA_SPEC_FORM_STRUC;         // Primary Key de la table des formes (solution buvable injectable etc ...)
  QString  m_MEDICA_SPEC_NB_FORME;           // Nb d'unite de prise (de forme) par boite
  QString  m_MEDICA_SPEC_PRIX_BOITE;         // prix de la boite
  QString  m_MEDICA_SPEC_REMBOURSEMENT;      // Remboursement secu
  QString  m_MEDICA_SPEC_TABLEAU;            // Tableau
  QString  m_MEDICA_SPEC_LABO;               // laboraoire pharmaceutique
  QString  m_MEDICA_SPEC_ATC;                // classe ATC
  //........................ MEDICA_TUX  Table des formes .........................................
  QString  m_MEDICA_FORME_UP_PERSO_TBL_NAME; // nom de la table des formes unite de prise personnelle
  QString  m_MEDICA_FORME_AD_PERSO_TBL_NAME; // nom de la table des forme des posologies  personnelle
  QString  m_MEDICA_FORME_UP_TBL_NAME;       // nom de la table des formes unite de prise
  QString  m_MEDICA_FORME_PA_TBL_NAME;       // nom de la table des formes principe actif (dosage)
  QString  m_MEDICA_FORME_ST_TBL_NAME;       // nom de la table des formes structurées
  QString  m_MEDICA_FORME_AD_TBL_NAME;       // nom de la table des forme des posologies
  QString  m_MEDICA_FORME_PK;                // Primary Key de la table des formes
  QString  m_MEDICA_FORME_LIBELLE;           // libelle de la forme
  //........................ MEDICA_TUX  Table des classes ATC .........................................
  QString  m_MEDICA_ATC_TBL_NAME;            // nom de la table des classes ATC
  QString  m_MEDICA_ATC_CODE;                // Code ATC
  QString  m_MEDICA_ATC_LIBELLE;             // libelle de la classe ATC
  //........................ MEDICA_TUX  Table des Posologies .........................................
  QString  m_MEDICA_POSO_PERSO_TBL_NAME;      // nom de la table des Posologies personnelle
  QString  m_MEDICA_POSO_TBL_NAME;            // nom de la table des Posologies
  QString  m_MEDICA_POSO_PK;                  // clef primaire
  QString  m_MEDICA_POSO_EXTRA_PK;            // si renseigné: clef primaire des données personnelles avec laquelle cette donnée a été créée
  QString  m_MEDICA_POSO_CIP;                 // code CIP
  QString  m_MEDICA_POSO_LIBELLE;             // Libelle précisant l'indication particulière au contexte
  QString  m_MEDICA_POSO_AGE_MIN;             // Age minimum d'application de la posologie
  QString  m_MEDICA_POSO_AGE_MAX;             // Age maximum d'application de la posologie
  QString  m_MEDICA_POSO_SEXE;                // Sexe d'application de la posologie
  QString  m_MEDICA_POSO_TERRAIN;             // chaine decrivant le terrain sous forme structurée
  QString  m_MEDICA_POSO_POIDS_MIN;           // Poids minimum d'application de la posologie
  QString  m_MEDICA_POSO_POIDS_MAX;           // Poids maximum d'application de la posologie
  QString  m_MEDICA_POSO_DOSE_MIN;            // dose minimum de la posologie pour cette indication
  QString  m_MEDICA_POSO_DOSE_MAX;            // dose maximum de la posologie pour cette indication
  QString  m_MEDICA_POSO_DOSE_UNIT;           // unite de la dose posologie pour cette indication
  QString  m_MEDICA_POSO_DOSE_LIMIT_MAX;      // dose maximum possible
  QString  m_MEDICA_POSO_FACT_CORP_QU;        // quantité d'unité de facteur corporel pour cette dose
  QString  m_MEDICA_POSO_FACT_CORP_UNIT;      // unité de facteur corporel pour cette dose
  QString  m_MEDICA_POSO_PERIODE;             // période en secondes pour lauqelle est exprimée cette posologie
  QString  m_MEDICA_POSO_EQUI_COEFF;          // coefficient pour transformer l'unite de prise 1 en unite de prise 2
  QString  m_MEDICA_POSO_UNIT_COEFF;          // unite deuxième forme de la dose posologie pour cette indication
  QString  m_MEDICA_POSO_NB_PRISES;           // nombre de prises conseillées
  QString  m_MEDICA_POSO_REPART_PRISES;       // description structurée de la répartition des prises
  QString  m_MEDICA_POSO_DIVERS;              // description structurée de la répartition des prises
  QString  m_MEDICA_POSO_PENDANT;             // durée de traitement conseillée par defaut
  QString  m_MEDICA_POSO_SECABILITE;          // secabilite

  //....données generales.........
  QString       m_DriverName ;
  QString       m_BaseName;
  QString       m_UserName;
  QString       m_PassWord;
  QString       m_HostName;

  //......................................... DATA ...............................................

  QSqlDatabase *m_DatasempBase;
  QSqlDatabase *m_DataGet_Base;
  QSqlDatabase *m_DatasempIndexBase;
  QSqlDatabase *m_DataIndexGet_Base;
  QString       m_ErrMess;
  bool          m_AllIsOk;
  //......................................... DATA ...............................................
  QString      m_IniParam;
};

#endif

