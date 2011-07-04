/*********************************** C_Macro_Core.cpp *****************************
 *                                                                                *
 *   #include "C_Macro_Core.h"                                                    *
 *   Project: MedinTux                                                            *
 *   Copyright (C) for the eternity by Sevin Roland  and Data Medical Design      *
 *   E-Mail: data.medical.design@club-internet.fr                                 *
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

#include "C_Macro_Core.h"
#include "CGestIni.h"
#include "C_Utils_Log.h"

#include <QObject>
#include <QDate>
#include <QDateTime>
#include <QDir>
#define TR QObject::tr

//---------------------------- C_Macro_Core ----------------------------------------
C_Macro_Core::C_Macro_Core(KEY_MACRO_TAB_DEF *pMacroTab_List, VAR_MAP *pVAR_MAP /* = 0 */)
{m_MacroTab_List     = pMacroTab_List;
 m_logWidget         = 0;
 if (pVAR_MAP==0)
    {m_VariablesToDelete = TRUE;
     m_pVariables        = new VAR_MAP;
    }
 else
    {m_pVariables        = pVAR_MAP;
     m_VariablesToDelete = FALSE;
    }
}

//---------------------------- ~C_Macro_Core ----------------------------------------
C_Macro_Core::~C_Macro_Core()
{
 if (m_VariablesToDelete)   delete m_pVariables;
}

//----------------------------------------  run -------------------------------------------------
/*! \brief Fusionne les champs de fusion un document donnée en entrée par: QString &document cette fonction demande un contexte sur l'observation en cours afin de tenir compte de l'utilisateur ayant créé cette observation ainsi que des elements propres à l'observation: elements du contenu etc....
 * \return QString:  qui est l'utilisateur lié à ce document. En effet l'utilisateur du document peut etre différent de l'utilisateur en cours. Exemple je travaille sur ce patient, et j'edite un certificat créé auparavant sous un autre utilisateur.
 * NOTE:  la date de visite, et l'utilisateur createur du document à fusionner doivent etre imperativement à jour et sont recupérés dans: (*pRubList->at(idDoc)).m_Date et (*pRubList->at(idDoc)).m_User
 */
QString C_Macro_Core::run(QString *document)
{if (document==0) return QString::null;
 m_pDocument = document;
 m_pDocument->replace("{{\\<br>","{{");
 m_pDocument->replace("{{\\<br />","{{");
/*
 m_pDocument->replace("{{\\<p>","{{");
 m_pDocument->replace("{{\\<p />","{{");
 m_pDocument->replace("{{\\\n","{{");
 m_pDocument->replace("{{\\\r","{{");
*/
 m_pDocument->replace("}}\\<br>","}}");
 m_pDocument->replace("}}\\<br />","}}");
/*
 m_pDocument->replace("}}\\<p>","}}");
 m_pDocument->replace("}}\\<p />","}}");
 m_pDocument->replace("}}\\\n","}}");
 m_pDocument->replace("}}\\\r","}}");
*/
 run(0, m_pDocument->length());
 return *m_pDocument;
}
//----------------------------------------  setLogWidget -------------------------------------------------
/*! \brief positionne l'eventuel widget de log
 */
void C_Macro_Core::setLogWidget(QTextEdit *logWidget){m_logWidget = logWidget;}

//----------------------------------------------- outMessage ---------------------------------------------------------------------
/*! \brief  append a message in a log widget QTextEdit
 *  \param  const QString &mess                 message to append
 *  \param  const QString   &file               source file
 *  \param  const int       &line               source line number
 * \return  QString:  message.
*/
QString     C_Macro_Core::outMessage( const QString &mess, const QString &file /* = "" */, const int line /* = -1*/)
{        C_Utils_Log::outMessage(m_logWidget, mess, file, line );
         return mess;
}
//----------------------------------  run -------------------------------------------------
/*! \brief Idem que supra, mais en débutant au caractère pos_deb jusqu'au caractère pos_max du texte.
 * \return QString:  qui est l'utilisateur lié à ce document. En effet l'utilisateur du document peut etre différent de l'utilisateur en cours. Exemple je travaille sur ce patient, et j'edite un certificat créé auparavant sous un autre utilisateur.
 */
int C_Macro_Core::run(int pos_deb, int pos_max)
{//G_pCApp->m_VAR_MAP.insert("$SCRIPT_RUN","$TRUE");
 int isWithToken   =  0;
 int pos_end       =  0;
 //QString ptDeb;
 //QString ptEnd;

 pos_deb           =  m_pDocument->indexOf("{{", pos_deb);
 int pDeltaLen     =  0;
 int intialLen     =  m_pDocument->length();
 while (pos_deb   != -1 && pos_deb < pos_max)
       {pos_end        =  CGestIni::findFermant(m_pDocument, pos_deb+2, pos_max, "{{", "}}", isWithToken);
        //ptDeb = m_pDocument->mid(pos_deb,50);
        //ptEnd = m_pDocument->mid(pos_end,50);
        if (isWithToken)
           {pos_max   += run(pos_deb+2, pos_end);
           }
        else
           {
            replaceTokenByValue(*m_pDocument, pos_deb+2, pos_end - pos_deb-2 ,&pDeltaLen);
            //ptDeb = m_pDocument->mid(pos_deb,50);
            //ptEnd = m_pDocument->mid(pos_end,50);
            pos_max  += pDeltaLen;
            pos_deb   =  m_pDocument->indexOf("{{", pos_deb);
            //ptDeb     = *m_pDocument; ptDeb += pos_deb;
           }
       }
  //G_pCApp->m_VAR_MAP.insert("$SCRIPT_RUN","$FALSE");
  return m_pDocument->length() - intialLen;
}

//------------------------------------------ strToIsoStrDateTime -----------------------------
/*! \brief Retourne une chaine de la forme 12x09xx2007 à l'heure de 12h30 sous forme 2007-09-12T12:30:00 */
QString C_Macro_Core::strToIsoStrDateTime(const QString &date, QString *pDate  /* =0 */, QString *pTime  /* =0 */)
{int end = date.length();
 int   i = -1;
 QString str;
 QString hh,mm,ss,uu;
 while (++i < end)
       {if (  (date[i]>='0' && date[i]<='9') )
           {str += date[i];
           }
       }
 int len = str.length();
 if (len ==6 )  str.insert ( 4, "20" ); // date forme 011207 --> 01122007
 if (len <8 )   {return  TR("ERREUR : C_Macro_Core::strToIsoStrDateTime() format de date '%1' invalide").arg(date);}
 if (pTime)  *pTime = "";
 if (pDate)  *pDate = "";

 hh                 = str.mid (8,2);  if (hh.length()==0) hh="00";
 mm                 = str.mid (10,2); if (mm.length()==0) mm="00";
 ss                 = str.mid (12,2); if (ss.length()==0) ss="00";

 hh                 = hh+":"+mm+":"+ss;
 if (pTime)  *pTime = hh;
 str                = str.mid(4,4)+"-"+str.mid(2,2)+"-"+str.mid(0,2);
 if (pDate)  *pDate = str;
 return str+"T"+hh;
}

//------------------------------------------ daysTo -------------------------------------------------
/*! \brief Retourne le nombre de jours entre la date1 et la date2 */
QString C_Macro_Core::daysTo(const QString &date1, const QString &date2)
{QDate d2 = QDate::currentDate();
 if (date2.length()!=0) d2 = QDate::fromString (normaliseDate(date2), Qt::ISODate );
 QDate d1 = QDate::fromString (normaliseDate(date1), Qt::ISODate );
 return QString::number( d1.daysTo ( d2 ) );
}

//------------------------------------------ normaliseDate -----------------------------
/*! \brief Retourne une date de la forme 12x09xx2007 sous forme 2007-09-12 */
QString C_Macro_Core::normaliseDate(const QString &date)
{int end = date.length();
 int   i = -1;
 QString str;
 while (++i < end) {
                     if (  (date[i]>='0' && date[i]<='9') ) str += date[i];
                   }
 if (str.length() ==6 )  str.insert ( 4, "20" ); // date forme 011207 --> 01122007
 if (str.length() !=8 )  {return TR("ERREUR : C_Macro_Core::normaliseDate() format de date '%1' invalide").arg(date);}

 return str.mid(4,4)+"-"+str.mid(2,2)+"-"+str.mid(0,2);
}

//----------------- getVarValue --------------------------------------------------
/*! \brief return value of a variable.
 *  \param varName : const QString & var name
 *  \return : contents of this varName
 */
QString   C_Macro_Core::getVarValue(const QString &varName)
{if (m_pVariables->contains(varName)) return (*m_pVariables)[varName];
 return QString::null;
}

//----------------- replaceTokenByValue --------------------------------------------------
/*! \brief Lorsque le code a été trouvé et interprété, remplace dans le texte le code par son résultat.
 *  \param document : QString du texte entier
 *  \param pos_deb : caractère de départ du remplacement
 *  \param len : longueur
 *  \param pDeltaLen ??
*/
int C_Macro_Core:: replaceTokenByValue(QString &document, int pos_deb, int len , int *pDeltaLen /*=0*/)
{int      originalLen = document.length();
 QString  resolvToken = getResolvTokenValue(document, pos_deb,  len )  ;
 resolvToken.replace("SautDeLigne", "<br>");
 document.replace ( pos_deb-2, len+4, resolvToken);
 if (pDeltaLen) *pDeltaLen = document.length() - originalLen;
 return pos_deb-2+resolvToken.length();
}

//------------------------------ getResolvTokenValue ---------------------------------------
/*! \brief Analyse le texte scripté passé en paramètre et "compile" avec les données calculées.
 *  \return les données calculées
*/
QString C_Macro_Core::getResolvTokenValue(QString &document, int pos_deb, int len )
{//char insecSpace[2]={(char)0xa0,(char)0x00};
 QString  token = document.mid(pos_deb, len);
          token.replace((char)0xa0," ");
          token.replace("&gt;",">");
          token.replace("&lt;","<");
          token.replace("&amp;","&");
          token.replace("&nbsp;",QChar(0xa0));

 QString  resolvToken("");
 if (token.left(2)=="::")
    { resolvFunctionToken(resolvToken, token.mid(2));
    }
 else
    { resolvMacroToken(resolvToken, token);
    }
 return resolvToken;
}

//---------------------------- resolvMacroToken ----------------------------------------
/*! \brief Interpréteur des fonctions de scripts ().
 * Les fonctions de scripts permettent de faire des actions au sein du document passé en paramètre.
 * L'appel de fonctions de scripts se présente de la sorte :
 * \code {{:: FONCTION_DE_SCRIPT = Param1 }} \endcode
 * Appel la fonction exeFunction().
 * \sa exeFunction()
 */
int C_Macro_Core::resolvMacroToken(QString &resolvToken, QString token)
{ //............. separer eventuels arguments du token .................
  QStringList arg_list;
  int       ret = 0;
  resolvToken   = "";
  int       pos = token.indexOf('=');
  if (pos != -1)
     {arg_list.append(token.mid(pos+1));
      token = token.left(pos).trimmed();
     }
  token = token.replace(' ','_').toUpper();

  //................. batir la structure de comparaison .......................
  KEY_MACRO toTest;
            toTest.m_Token     = (char*)(const char*)token.toAscii();
  //        toTest.m_Function  = 0;

  //............... recuperer le tableau de fonctions correspondant à la première lettre du token.............................
  int i = (int)toTest.m_Token[0]-'A';
  if (i<0 || i>25)                   return ret;
  KEY_MACRO_TAB_DEF *p_MACRO_LIST = &m_MacroTab_List[i];

  //................. rechercher la fonction du token ...............................................................
  KEY_MACRO *pKEY_MACRO = (KEY_MACRO*) bsearch(&toTest, p_MACRO_LIST->m_MacroTab, p_MACRO_LIST->m_size , sizeof(KEY_MACRO), C_Macro_Core::comparatorMacro);
  if (pKEY_MACRO)
     {resolvToken = (*(pKEY_MACRO->m_Function))(arg_list); //.replace("(","\\(").replace(")","\\)");
      ret = 1;
     }
 return ret;
}



//---------------------------- resolvFunctionToken ----------------------------------------
/*! \brief Interpréteur des fonctions de scripts ().
 * Les fonctions de scripts permettent de faire des actions au sein du document passé en paramètre.
 * L'appel de fonctions de scripts se présente de la sorte :
 * \code {{:: FONCTION_DE_SCRIPT ( Param1, param2 ....) }} \endcode
 * Appel la fonction exeFunction().
 * \sa exeFunction()
 */
int C_Macro_Core::resolvFunctionToken(QString &resolvToken, QString token)
{resolvToken   = "";
 token = token.trimmed();
 //if (token[0] !='#')   C_HtmlTools::htmlToAscii(token);
 //else                  token.remove (0, 1);
 int pos_prem_p =  token.indexOf('(');
 if (pos_prem_p ==-1)  {outMessage (TR("C_Macro_Core::ResolvScriptTokenSyntax() Syntax Error first '(' not found in : ") + token ,__FILE__,__LINE__); return 0;}
 int pos_last_p =  findLastDelimiter(token, ')');
 if (pos_last_p ==-1)  {outMessage (TR("C_Macro_Core::ResolvScriptTokenSyntax() Syntax Error last  ')' not found in : ") + token ,__FILE__,__LINE__); return 0;}
 int ret = exeFunction(token.left(pos_prem_p).trimmed().toUpper(), token.mid(pos_prem_p + 1, pos_last_p-pos_prem_p - 1), resolvToken);
 return ret;
}

//-------------------------- exeFunction -------------------------------------------
int C_Macro_Core::exeFunction(QString token, const QString& args, QString &resolvToken)
{ QStringList arg_list;
  int       ret = 0;
  extractArgList(arg_list, args);
  token = token.replace(' ','_').toUpper();
  //................. batir la structure de comparaison .......................
  KEY_MACRO toTest;
            toTest.m_Token     = (char*)(const char*)token.toLatin1();

  //............... recuperer le tableau de fonctions correspondant à la première lettre du token.............................
  int i = (int)toTest.m_Token[0]-'A';
  if (i<0 || i>25)                   return ret;
  KEY_MACRO_TAB_DEF *p_MACRO_LIST = &m_MacroTab_List[i];

  //................. rechercher la fonction du token .........................
  KEY_MACRO *pKEY_MACRO = (KEY_MACRO*) bsearch(&toTest, p_MACRO_LIST->m_MacroTab, p_MACRO_LIST->m_size , sizeof(KEY_MACRO), C_Macro_Core::comparatorMacro);
  if (pKEY_MACRO)
     {resolvToken = (*(pKEY_MACRO->m_Function))(arg_list); //.replace("(","\\(").replace(")","\\)");
      ret = 1;
     }
  return ret;
}

//-------------------------- comparatorMacro -------------------------------------------
int C_Macro_Core::comparatorMacro (const void *a, const void *b)
{return strcmp(((KEY_MACRO*)a)->m_Token+1,((KEY_MACRO*)b)->m_Token+1);  // +1 car tri alphabérique déjà fait sur le premier caractère.
}

//-------------------------- extractArgList -------------------------------------------
/*! \brief non documenté */
long C_Macro_Core::extractArgList(QStringList &arg_list, const QString &arg_str)
{long len_t  = 0;
 long len    = arg_str.length();
 long pos    = 0;
 long deb    = 0;
 while(pos < len)
    {if (arg_str.at(pos) == '\\') pos += 2;
     else if (arg_str.at(pos) == ',')
        {
         len_t =  pos-deb;
         if (len_t==0) arg_list.append( "" );
         else
           {//QString s = QString::fromAscii(deb, len );
            //        s = s.replace("\\\\","!°!;:");
            //        s = s.remove("\\");
            //        s = s.replace("!°!;:","\\");
            arg_list.append( arg_str.mid(deb, len_t));
           }
         ++pos;
         deb = pos;
        }
     else
        {++pos;
        }
    }
 len_t =  pos-deb;
 if (len_t==0) arg_list.append( "" );
 else
    {//QString s = QString::fromAscii(deb, len );
     //        s = s.replace("\\\\","!°!;:");
     //        s = s.remove("\\");
     //        s = s.replace("!°!;:","\\");
     arg_list.append( arg_str.mid(deb,len_t));
    }
 return 1;
}

//----------------------------- findLastDelimiter -----------------------------------------------
/*! \brief Pour la récursivité. */
long C_Macro_Core::findLastDelimiter(const QString &str, const QChar delimiter)
{long len = str.length();
 long pos = 0;
 while(pos<len)
    {if (str.at(pos) == '\\') pos += 2;
     else
        {if (str.at(pos) == delimiter)      return pos;
         ++pos;
        }
    }
                                            return -1;
}

