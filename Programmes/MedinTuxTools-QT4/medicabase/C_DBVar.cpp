 /********************************* C_DBVar.cpp ***********************************
 *  #include "C_DBVar.h"                                                          *
 * ...............................................................................*
 *   Project   :  MedinTux  (typographie made in france)                          *
 *   Copyright : (C) 2004-2005-2006-2007-2008-2009-2010 and for the eternity      *
 *   by        :  Sevin Roland     from   MedinTux project                        *
 *   E-Mail    : roland-sevin@medintux.org                                        *
 *   Web site  : www.medintux.org                                                 *
 * ...............................................................................*
 *                                                                                *
 *   This program is free software; you can redistribute it and/or modify         *
 *   it under the terms of the CeCILL Version 1 du 21/06/2004                     *
 *   License (GPL compatible)                                                     *
 *                              http://www.cecill.info/                           *
 *   as published by :                                                            *
 *                                                                                *
 *   Commissariat à l'Energie Atomique                                            *
 *   - CEA,                                                                       *
 *                            31-33 rue de la Fédération, 75752 PARIS cedex 15.   *
 *                            FRANCE                                              *
 *   Centre National de la Recherche Scientifique                                 *
 *   - CNRS,                                                                      *
 *                            3 rue Michel-Ange, 75794 Paris cedex 16.            *
 *                            FRANCE                                              *
 *   Institut National de Recherche en Informatique et en Automatique             *
 *   - INRIA,                                                                     *
 *                            Domaine de Voluceau, Rocquencourt, BP 105, 78153    *
 *                            FRANCE                                              *
 *                                                                                *
 *         This program is distributed in the hope that it will be useful,        *
 *         but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *         MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                   *
 *         CeCILL  License (GPL compatible) for more details.                     *
 *                                                                                *
 **********************************************************************************/

// C++ Interface: C_DBVar.cpp
//
#include "C_DBVar.h"
#define   SKIP_BLANK_CAR(a)        while( *(a) && (*(a)==' ' || *(a)=='\t' || *(a)== 96) ) ++(a)
#define   NEXT_LINE(a)             while( *(a) && *(a)!='\r' && *(a)!='\n')++(a); while( *(a) && (*(a)=='\r'|| *(a)=='\n'))++(a)

//-----------------------------------------------------  C_DBVar -------------------------------------------
C_DBVar::C_DBVar(  QString& confData)
{m_LastError             = "";
 if (confData.length()==0) {m_LastError +=  TR("\r\n Fichier de configuration des bases absent ou vide "); return;}
 initValues(confData);
}

//-----------------------------------------------------  SetConfBase -------------------------------------------
int C_DBVar::initValues( QString& confData)
{ QByteArray ba = confData.toAscii();
  QString   err = "";
  char     *deb = (char*)(const char *)ba;
  char      *pt = deb;
  int      line = 0;

    pt = SetConfBase_SetProperties(pt,  m_MEDICA_INDEX_MED_TBL_NAME,     "m_MEDICA_INDEX_MED_TBL_NAME",    &line , err); if (err.length())     goto SetConfBase_Error;
    pt = SetConfBase_SetProperties(pt,  m_MEDICA_INDEX_DIET_TBL_NAME,    "m_MEDICA_INDEX_DIET_TBL_NAME",   &line , err); if (err.length())     goto SetConfBase_Error;
    pt = SetConfBase_SetProperties(pt,  m_MEDICA_INDEX_VETO_TBL_NAME,    "m_MEDICA_INDEX_VETO_TBL_NAME",   &line , err); if (err.length())     goto SetConfBase_Error;
    pt = SetConfBase_SetProperties(pt,  m_MEDICA_INDEX_PARA_TBL_NAME,    "m_MEDICA_INDEX_PARA_TBL_NAME",   &line , err); if (err.length())     goto SetConfBase_Error;
    pt = SetConfBase_SetProperties(pt,  m_MEDICA_INDEX_ACCS_TBL_NAME,    "m_MEDICA_INDEX_ACCS_TBL_NAME",   &line , err); if (err.length())     goto SetConfBase_Error;
    pt = SetConfBase_SetProperties(pt,  m_MEDICA_INDEX_HERBO_TBL_NAME,   "m_MEDICA_INDEX_HERBO_TBL_NAME",  &line , err); if (err.length())     goto SetConfBase_Error;
    pt = SetConfBase_SetProperties(pt,  m_MEDICA_INDEX_HOMEO_TBL_NAME,   "m_MEDICA_INDEX_HOMEO_TBL_NAME",  &line , err); if (err.length())     goto SetConfBase_Error;


    pt = SetConfBase_SetProperties(pt , m_MEDICA_INDEX_PK,            "m_MEDICA_INDEX_PK",             &line , err); if (err.length())     goto SetConfBase_Error;
    pt = SetConfBase_SetProperties(pt , m_MEDICA_INDEX_LIBELLE,       "m_MEDICA_INDEX_LIBELLE",        &line , err); if (err.length())     goto SetConfBase_Error;
    pt = SetConfBase_SetProperties(pt , m_MEDICA_INDEX_CIP,           "m_MEDICA_INDEX_CIP",            &line , err); if (err.length())     goto SetConfBase_Error;
    pt = SetConfBase_SetProperties(pt , m_MEDICA_INDEX_PK_T00,        "m_MEDICA_INDEX_PK_T00",         &line , err); if (err.length())     goto SetConfBase_Error;
    pt = SetConfBase_SetProperties(pt , m_MEDICA_INDEX_PK_T4B,        "m_MEDICA_INDEX_PK_T4B",         &line , err); if (err.length())     goto SetConfBase_Error;
    pt = SetConfBase_SetProperties(pt , m_MEDICA_INDEX_CD_PROD,       "m_MEDICA_INDEX_CD_PROD",        &line , err); if (err.length())     goto SetConfBase_Error;
    pt = SetConfBase_SetProperties(pt , m_MEDICA_INDEX_CD_UV,         "m_MEDICA_INDEX_CD_UV",          &line , err); if (err.length())     goto SetConfBase_Error;
    pt = SetConfBase_SetProperties(pt , m_MEDICA_INDEX_IS_GENE,       "m_MEDICA_INDEX_IS_GENE",        &line , err); if (err.length())     goto SetConfBase_Error;
    pt = SetConfBase_SetProperties(pt , m_MEDICA_INDEX_IS_DISPO,      "m_MEDICA_INDEX_IS_DISPO",       &line , err); if (err.length())     goto SetConfBase_Error;
    pt = SetConfBase_SetProperties(pt , m_MEDICA_INDEX_RCP,           "m_MEDICA_INDEX_RCP",            &line , err); if (err.length())     goto SetConfBase_Error;
    pt = SetConfBase_SetProperties(pt , m_MEDICA_INDEX_CIS,           "m_MEDICA_INDEX_CIS",            &line , err); if (err.length())     goto SetConfBase_Error;

    pt = SetConfBase_SetProperties(pt , m_MEDICA_SPEC_TBL_NAME         , "m_MEDICA_SPEC_TBL_NAME",         &line , err); if (err.length())     goto SetConfBase_Error;
    pt = SetConfBase_SetProperties(pt , m_MEDICA_SPEC_CIP              , "m_MEDICA_SPEC_CIP",              &line , err); if (err.length())     goto SetConfBase_Error;
    pt = SetConfBase_SetProperties(pt , m_MEDICA_SPEC_UP_UNIT          , "m_MEDICA_SPEC_UP_UNIT",          &line , err); if (err.length())     goto SetConfBase_Error;
    pt = SetConfBase_SetProperties(pt , m_MEDICA_SPEC_PA_UNIT          , "m_MEDICA_SPEC_PA_UNIT",          &line , err); if (err.length())     goto SetConfBase_Error;
    pt = SetConfBase_SetProperties(pt , m_MEDICA_SPEC_PA_QU            , "m_MEDICA_SPEC_PA_QU",            &line , err); if (err.length())     goto SetConfBase_Error;
    pt = SetConfBase_SetProperties(pt , m_MEDICA_SPEC_SECABILITE       , "m_MEDICA_SPEC_SECABILITE",       &line , err); if (err.length())     goto SetConfBase_Error;
    pt = SetConfBase_SetProperties(pt , m_MEDICA_SPEC_IS_GENERIC       , "m_MEDICA_SPEC_IS_GENERIC",       &line , err); if (err.length())     goto SetConfBase_Error;
    pt = SetConfBase_SetProperties(pt , m_MEDICA_SPEC_FORM_STRUC       , "m_MEDICA_SPEC_FORM_STRUC",       &line , err); if (err.length())     goto SetConfBase_Error;
    pt = SetConfBase_SetProperties(pt , m_MEDICA_SPEC_NB_FORME         , "m_MEDICA_SPEC_NB_FORME",         &line , err); if (err.length())     goto SetConfBase_Error;
    pt = SetConfBase_SetProperties(pt , m_MEDICA_SPEC_PRIX_BOITE       , "m_MEDICA_SPEC_PRIX_BOITE",       &line , err); if (err.length())     goto SetConfBase_Error;
    pt = SetConfBase_SetProperties(pt , m_MEDICA_SPEC_REMBOURSEMENT    , "m_MEDICA_SPEC_REMBOURSEMENT",    &line , err); if (err.length())     goto SetConfBase_Error;
    pt = SetConfBase_SetProperties(pt , m_MEDICA_SPEC_TABLEAU          , "m_MEDICA_SPEC_TABLEAU",          &line , err); if (err.length())     goto SetConfBase_Error;
    pt = SetConfBase_SetProperties(pt , m_MEDICA_SPEC_LABO             , "m_MEDICA_SPEC_LABO",             &line , err); if (err.length())     goto SetConfBase_Error;
    pt = SetConfBase_SetProperties(pt , m_MEDICA_SPEC_ATC              , "m_MEDICA_SPEC_ATC",              &line , err); if (err.length())     goto SetConfBase_Error;

    pt =  SetConfBase_SetProperties(pt , m_MEDICA_FORME_UP_PERSO_TBL_NAME, "m_MEDICA_FORME_UP_PERSO_TBL_NAME",         &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_FORME_AD_PERSO_TBL_NAME, "m_MEDICA_FORME_AD_PERSO_TBL_NAME",         &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_FORME_UP_TBL_NAME,  "m_MEDICA_FORME_UP_TBL_NAME",         &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_FORME_PA_TBL_NAME,  "m_MEDICA_FORME_PA_TBL_NAME",         &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_FORME_ST_TBL_NAME,  "m_MEDICA_FORME_ST_TBL_NAME",         &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_FORME_AD_TBL_NAME,  "m_MEDICA_FORME_AD_TBL_NAME",         &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_FORME_PK,           "m_MEDICA_FORME_PK",                  &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_FORME_LIBELLE,      "m_MEDICA_FORME_LIBELLE",             &line , err); if (err.length())     goto SetConfBase_Error;

    pt =  SetConfBase_SetProperties(pt , m_MEDICA_ATC_TBL_NAME,        "m_MEDICA_ATC_TBL_NAME",          &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_ATC_CODE,            "m_MEDICA_ATC_CODE",              &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_ATC_LIBELLE,         "m_MEDICA_ATC_LIBELLE",           &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_ATC_LANG,            "m_MEDICA_ATC_LANG",              &line , err); if (err.length())     goto SetConfBase_Error;

    pt =  SetConfBase_SetProperties(pt , m_BIBLIO_H_TBL_NAME,          "m_BIBLIO_H_TBL_NAME",            &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_BIBLIO_H_PK,                "m_BIBLIO_H_PK",                  &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_BIBLIO_H_OWNER,             "m_BIBLIO_H_OWNER",               &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_BIBLIO_H_LANG,              "m_BIBLIO_H_LANG",                &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_BIBLIO_H_URL,               "m_BIBLIO_H_URL",                 &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_BIBLIO_H_ID,                "m_BIBLIO_H_ID",                  &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_BIBLIO_H_DATE,              "m_BIBLIO_H_DATE",                &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_BIBLIO_H_NOTE,              "m_BIBLIO_H_NOTE",                &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_BIBLIO_H_TYPE,              "m_BIBLIO_H_TYPE",                &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_BIBLIO_H_MIME,              "m_BIBLIO_H_MIME",                &line , err); if (err.length())     goto SetConfBase_Error;

    pt =  SetConfBase_SetProperties(pt , m_BIBLIO_B_TBL_NAME,          "m_BIBLIO_B_TBL_NAME",             &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_BIBLIO_B_PK,                "m_BIBLIO_B_PK",                   &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_BIBLIO_B_RPK,               "m_BIBLIO_B_RPK",                  &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_BIBLIO_B_OWNER,             "m_BIBLIO_B_OWNER",                &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_BIBLIO_B_BLOB,              "m_BIBLIO_B_BLOB",                 &line , err); if (err.length())     goto SetConfBase_Error;

    pt =  SetConfBase_SetProperties(pt , m_MEDICA_POSO_PERSO_TBL_NAME, "m_MEDICA_POSO_PERSO_TBL_NAME",    &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_POSO_TBL_NAME,       "m_MEDICA_POSO_TBL_NAME",          &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_POSO_PK,             "m_MEDICA_POSO_PK",                &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_POSO_EXTRA_PK,       "m_MEDICA_POSO_EXTRA_PK",          &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_POSO_CIP,            "m_MEDICA_POSO_CIP",               &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_POSO_LIBELLE,        "m_MEDICA_POSO_LIBELLE",           &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_POSO_AGE_MIN,        "m_MEDICA_POSO_AGE_MIN",           &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_POSO_AGE_MAX,        "m_MEDICA_POSO_AGE_MAX",           &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_POSO_SEXE,           "m_MEDICA_POSO_SEXE",              &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_POSO_TERRAIN,        "m_MEDICA_POSO_TERRAIN",           &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_POSO_POIDS_MIN,      "m_MEDICA_POSO_POIDS_MIN",         &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_POSO_POIDS_MAX,      "m_MEDICA_POSO_POIDS_MAX",         &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_POSO_DOSE_MIN,       "m_MEDICA_POSO_DOSE_MIN",          &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_POSO_DOSE_MAX,       "m_MEDICA_POSO_DOSE_MAX",          &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_POSO_DOSE_UNIT,      "m_MEDICA_POSO_DOSE_UNIT",         &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_POSO_DOSE_LIMIT_MAX, "m_MEDICA_POSO_DOSE_LIMIT_MAX",    &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_POSO_FACT_CORP_QU,   "m_MEDICA_POSO_FACT_CORP_QU",      &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_POSO_FACT_CORP_UNIT, "m_MEDICA_POSO_FACT_CORP_UNIT",    &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_POSO_PERIODE,        "m_MEDICA_POSO_PERIODE",           &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_POSO_EQUI_COEFF,     "m_MEDICA_POSO_EQUI_COEFF",        &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_POSO_UNIT_COEFF,     "m_MEDICA_POSO_UNIT_COEFF",        &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_POSO_NB_PRISES,      "m_MEDICA_POSO_NB_PRISES",         &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_POSO_REPART_PRISES,  "m_MEDICA_POSO_REPART_PRISES",     &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_POSO_DIVERS,         "m_MEDICA_POSO_DIVERS",            &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_POSO_PENDANT,        "m_MEDICA_POSO_PENDANT",           &line , err); if (err.length())     goto SetConfBase_Error;
    pt =  SetConfBase_SetProperties(pt , m_MEDICA_POSO_SECABILITE,     "m_MEDICA_POSO_SECABILITE",        &line , err); if (err.length())     goto SetConfBase_Error;
  return 1;

SetConfBase_Error:
  m_LastError += err;
  return 0;
}

//--------------------------------------------- SetConfBase_SetProperties ------------------------------------------------
char  *C_DBVar::SetConfBase_SetProperties(char *pt, QString &propertie, const char *token, int *line , QString &err)
{int nLine      = *line;
 err            = "";
 long len_token = strlen (token);
 while(*pt)
    {SKIP_BLANK_CAR(pt);
     if (strncmp(pt, token, len_token)==0)
        {//return pt+len_token;
         pt         += len_token;
         err         = "";
         propertie   = "";
         //............. chercher premier delimiteur ...............................
          while(*pt && *pt!='\r' && *pt !='\n' && *pt !='\'' ) pt++;
          if (*pt=='\'')         // si delimiteur pas trouve erreur
             {pt++;               // passer le delimiteur
              char *end = pt;
              //............. chercher deuxieme delimiteur ...............................
              while(*end && *end!='\r' && *end !='\n' && *end !='\'')end++;
              if (*end=='\'')
                { propertie= QString::fromAscii ( pt, end-pt );
                  if (line) *line = nLine;
                  return end +1;
                 }
              else
                {err  = TR("Syntax Error: SetConfBaseGetValue()\r\n End delimiter \"'\"  not find at line : ");
                 err += QString::number(nLine);
                 if (line) *line = nLine;
                 return 0;
                }
             }
           else
             {err  = TR("Syntax Error: SetConfBaseGetValue()\r\n Start delimiter \"'\"  not find at line : ");
              err += QString::number(nLine);
              if (line) *line = nLine;
              return 0;
             }
        } //endif (strncmp(pt, token, len_token)==0)
     NEXT_LINE(pt);
     ++nLine;
    }
 err  = TR("\nErreur de syntaxe : C_DBVar::SetConfBase_SetProperties()"
           "\nle fichier de configuration des bases 'DataBase.cfg'"
           "\ncomporte les erreurs suivantes : \n"
           "      ==> la mention %1 est non trouv\303\251e \303\240 la ligne : %2").arg(token, QString::number(nLine));
 if (line) *line = nLine;
 return pt;
}
