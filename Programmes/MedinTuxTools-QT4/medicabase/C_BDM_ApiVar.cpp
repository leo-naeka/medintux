/********************************* C_BDM_ApiVar.cpp ******************************
*  #include "C_BDM_ApiVar.h"                                                     *
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
*   Commissariat � l'Energie Atomique                                            *
*   - CEA,                                                                       *
*                            31-33 rue de la F�d�ration, 75752 PARIS cedex 15.   *
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

// C++ Interface: C_BDM_ApiVar.cpp
//
#include "C_BDM_ApiVar.h"
#define   SKIP_BLANK_CAR(a)        while( *(a) && (*(a)==' ' || *(a)=='\t' || *(a)== 96) ) ++(a)
#define   NEXT_LINE(a)             while( *(a) && *(a)!='\r' && *(a)!='\n')++(a); while( *(a) && (*(a)=='\r'|| *(a)=='\n'))++(a)

//-----------------------------------------------------  C_DBVar -------------------------------------------
C_BDM_ApiVar::C_BDM_ApiVar(  const QString& confData)
{m_LastError             = "";
if (confData.length()==0) {m_LastError +=  TR("\r\n Fichier de configuration des bases absent ou vide "); return;}
initValues(confData);
}

//-----------------------------------------------------  SetConfBase -------------------------------------------
int C_BDM_ApiVar::initValues( const QString& confData)
{
 QByteArray ba = confData.toAscii();
 QString   err = "";
 char     *deb = (char*)(const char *)ba;
 char      *pt = deb;
 int      line = 0;
   //........................ MEDICA_TUX  Table de la liste des drogues .........................................
   pt =  SetConfBase_SetProperties(pt , m_BDM_DRUGLIST_TBL_NAME,  "m_BDM_DRUGLIST_TBL_NAME",  &line , err); if (err.length())     goto SetConfBase_Error;  // 'bdm_druglist'  nom de la table de la liste des medicaments
   pt =  SetConfBase_SetProperties(pt , m_BDM_DRUGLIST_PK,        "m_BDM_DRUGLIST_PK",        &line , err); if (err.length())     goto SetConfBase_Error;  // 'bdm_pk'        clef primaire
   pt =  SetConfBase_SetProperties(pt , m_BDM_DRUGLIST_OWNER,     "m_BDM_DRUGLIST_OWNER",     &line , err); if (err.length())     goto SetConfBase_Error;  // 'bdm_owner'     Origine des donnees (AFSSAPS, Vidal, Theriaque Claude Bernard, perso...)
   pt =  SetConfBase_SetProperties(pt , m_BDM_DRUGLIST_LANG,      "m_BDM_DRUGLIST_LANG",      &line , err); if (err.length())     goto SetConfBase_Error;  // 'bdm_lang'      langue de la donnee (en fr etc...)
   pt =  SetConfBase_SetProperties(pt , m_BDM_DRUGLIST_ID,        "m_BDM_DRUGLIST_ID",        &line , err); if (err.length())     goto SetConfBase_Error;  // 'bdm_id'        identificateur unique du medicament
   pt =  SetConfBase_SetProperties(pt , m_BDM_DRUGLIST_TYPE_ID,   "m_BDM_DRUGLIST_TYPE_ID",   &line , err); if (err.length())     goto SetConfBase_Error;  // 'bdm_type_id'   type d'identificateur (CIP CIP7 CIS)
   pt =  SetConfBase_SetProperties(pt , m_BDM_DRUGLIST_ATC,       "m_BDM_DRUGLIST_ATC",       &line , err); if (err.length())     goto SetConfBase_Error;  // 'bdm_atc'       Code ATC
   pt =  SetConfBase_SetProperties(pt , m_BDM_DRUGLIST_LIBELLE,   "m_BDM_DRUGLIST_LIBELLE",   &line , err); if (err.length())     goto SetConfBase_Error;  // 'bdm_libelle'   libelle de la classe ATC
   pt =  SetConfBase_SetProperties(pt , m_BDM_DRUGLIST_DCI_1,     "m_BDM_DRUGLIST_DCI_1",     &line , err); if (err.length())     goto SetConfBase_Error;  // 'bdm_dci_1'     premiere  substance DCI (libelle ATC)
   pt =  SetConfBase_SetProperties(pt , m_BDM_DRUGLIST_DCI_2,     "m_BDM_DRUGLIST_DCI_2",     &line , err); if (err.length())     goto SetConfBase_Error;  // 'bdm_dci_2'     deuxieme  substance DCI (si produit compose)
   pt =  SetConfBase_SetProperties(pt , m_BDM_DRUGLIST_DCI_3,     "m_BDM_DRUGLIST_DCI_3",     &line , err); if (err.length())     goto SetConfBase_Error;  // 'bdm_dci_3'     troisieme substance DCI (si produit compose)
   pt =  SetConfBase_SetProperties(pt , m_BDM_DRUGLIST_UCD,       "m_BDM_DRUGLIST_UCD",       &line , err); if (err.length())     goto SetConfBase_Error;  // 'bdm_ucd'       code UCD
   pt =  SetConfBase_SetProperties(pt , m_BDM_DRUGLIST_UCD_PRICE, "m_BDM_DRUGLIST_UCD_PRICE", &line , err); if (err.length())     goto SetConfBase_Error;  // 'bdm_ucd_price' Prix UCD
   pt =  SetConfBase_SetProperties(pt , m_BDM_DRUGLIST_SPEC_FK,   "m_BDM_DRUGLIST_SPEC_FK",   &line , err); if (err.length())     goto SetConfBase_Error;  // 'bdm_pk_spec'   pointeur sur les specifications produits
 return 1;

SetConfBase_Error:
 m_LastError += err;
 return 0;
}

//--------------------------------------------- SetConfBase_SetProperties ------------------------------------------------
char  *C_BDM_ApiVar::SetConfBase_SetProperties(char *pt, QString &propertie, const char *token, int *line , QString &err)
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
