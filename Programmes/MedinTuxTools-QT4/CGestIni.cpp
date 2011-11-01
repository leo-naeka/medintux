 /*********************************** CGestIni.h ***************************
 *  #include "CGestIni.h"         QT4-ready                                *
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

//=============================================== INCLUDES ===================================================================
#include  "CGestIni.h"
#include <QFile>
#include <QTextStream>
#include <QSqlQuery>
#include <QDir>
#include <QFileInfo>
#include <QByteArray>

#ifdef Q_OS_MACX
#define PATH_SPEC_MAC "../../../"
#define ARCHI_DEP_MAC ".app/Contents/MacOS/" + module
#else
#define PATH_SPEC_MAC ""
#define ARCHI_DEP_MAC ""
#endif
#ifdef Q_WS_WIN
#define F_EXT  ".exe"
#else
#define F_EXT ""
#endif

/*! \class CGestIni
 *  \brief Gestion des fichiers INI de la suite Medintux.
 * Gére le chargement des paramètres, leur recherche et l'écriture des fichiers paramètres.
 * Les paramètres sont sauvegardés de la sorte :
 * [SECTION]\\r\\n
 * Parametre = val1, val2, val3, val4, val5, val6, val7, val7, val8, val9, val10\\r\\n
 * Plusieurs sections peuvent cohabiter dans un même fichier et plusieurs paramètres peuvent être défini par section.
 * Cette classe gère la compatibilté Windows, Mac, Linux pour les fichiers INI
 * \todo Un seul fichier INI pour toute la suite dans le QDir::home() qui ne contient que les données de connexion �  la base de données. Les autres paramètres sont dans la base de données.
*/

//-----------------------------------------------------  CGestIni --------------------------------
/*! \brief constructeur de la classe. Initialise les variables m_ParamData et m_ParamPath.
*/
CGestIni::CGestIni()
{
}

//-----------------------------------------------------  Param_UpdateToDisk --------------------------
/*! \brief sauvegarde un QByteArray dans un fichier
 *  \todo Attention le fichier n'est pas ferme ???...
*/
void  CGestIni::Param_UpdateToDisk(const QString &file_ini, const QByteArray &ba)
{QFile file( file_ini);
 if ( !file.open( QIODevice::WriteOnly ) )    return;
 file.write( ba );
 file.close();
}

//-----------------------------------------------------  Param_UpdateToDisk --------------------------
/*! \brief sauvegarde les paramètres iniParam dans un fichier dont le chemin est spécifié.
 *  \todo Attention le fichier n'est pas ferme ???...
*/
void  CGestIni::Param_UpdateToDisk(const QString &file_ini, const QString &inParam)
{QFile file( file_ini);
 if ( !file.open( QIODevice::WriteOnly ) )    return;
 QTextStream ts( &file );
 ts << inParam;
 file.close();
}

//-----------------------------------------------------  findFermant -----------------------------
/*! \brief Trouve le motif fermant correspondant au motif ouvrant
 *  \param QString &text   texte ou doit se faire la recherche
 *  \param int pos_deb     position dans le texte ou commence la recherche doit etre apres l'ouvrant dont on cherche le fermant
 *  \param const QString &ouvrant       motif ouvrant
 *  \param const QString &fermant       motif fermant
 *  \return position sur le motif fermant.
*/
int  CGestIni::findFermant(const QString *ptext, int pos, int pos_max, const QString &ouvrant, const QString &fermant)
{int isWithToken;
 return findFermant(ptext, pos, pos_max, ouvrant, fermant, isWithToken);
}

//-----------------------------------------------------  indexOfFermant -----------------------------
/*! \brief Trouve le motif fermant correspondant au motif ouvrant
 *  \param QString &text   texte ou doit se faire la recherche
 *  \param int pos_deb     position dans le texte ou commence la recherche doit etre apres l'ouvrant dont on cherche le fermant
 *  \param const QString &ouvrant       motif ouvrant
 *  \param const QString &fermant       motif fermant
 *  \return position sur le motif fermant.
*/
int  CGestIni::findFermant(const QString *ptext, int pos, int pos_max, const QString &ouvrant, const QString &fermant, int &isWithToken)
{ int stack        = 1;
  int ouvrant_len  = ouvrant.length();
  int fermant_len  = fermant.length();
  isWithToken      = 0;
  while (stack && pos < pos_max)
    {if (ptext->at(pos)==ouvrant.at(0) && ptext->mid(pos, ouvrant_len) == ouvrant)
        {++   stack;
         pos += ouvrant_len;
         ++   isWithToken;
        }
     else if (ptext->at(pos)==fermant.at(0) && ptext->mid(pos, fermant_len) == fermant)
        {--   stack;
         pos += fermant_len;
        }
     else
        {++pos;
        }
   }
 return pos-fermant_len;    // - fermant_len pour pointer avant le fermant
}
//-----------------------------------------------------  Param_UpdateFromDisk ------------------------------
/*! \brief Lit le fichier file_ini et renvoie son contenu dans outParam. L'encodage est géré.
*/
QString  CGestIni::Param_UpdateFromDisk(const QString &file_ini,  int *isUtf8_ret /* =0 */)
{QString ret="";
 Param_UpdateFromDisk(file_ini, ret, isUtf8_ret);
 return ret;
}
//-----------------------------------------------------  Param_UpdateFromDisk ------------------------------
/*! \brief Lit le fichier file_ini et renvoie son contenu dans outParam. L'encodage est géré.
*/
QByteArray& CGestIni::Param_UpdateFromDisk(const QString &file_ini, QByteArray &ba, int *isUtf8_ret /* =0 */)
{        if (ba.size()>0) ba.data()[0]=0;
         QFile qFile(file_ini );
         if (qFile.open( QIODevice::ReadOnly )==FALSE)   return  ba;
         long file_len = qFile.size();
         ba = qFile.readAll(); ba.resize(file_len+1); ba.data()[file_len]=0;
         qFile.close ();
         int isUtf8 = IsUtf8(ba.constData());
         if ( isUtf8_ret ) *isUtf8_ret = isUtf8;
         if (isUtf8)
            {QString tmp =  QString::fromUtf8 ( ba );
             ba          =  tmp.toUtf8 ();
             QString ext =  QFileInfo(qFile).suffix ();
             if (ext.toLower() == "htm")
                {ba.replace("meta name=\"qrichtext\" content=\"charset=utf-8\"",   // obligé d'etre en content=\"1\" pour que les tabulations fonctionnent !!
                            "meta name=\"qrichtext\" content=\"1\"");
                }
             ba.replace("&nbsp;", " ");
            }
         return ba;
}
//-----------------------------------------------------  Param_UpdateFromDisk ------------------------------
/*! \brief Lit le fichier file_ini et renvoie son contenu dans outParam. L'encodage est géré.
*/
long  CGestIni::Param_UpdateFromDisk(const QString &file_ini, QString &outParam, int *isUtf8_ret /* =0 */)
{        //............ charger le fichier .ini ..........
         QFile qFile(file_ini );
         if (qFile.open( QIODevice::ReadOnly )==FALSE)   return  0;
         long file_len = qFile.size();
         QByteArray ba = qFile.readAll(); ba.resize(file_len+1); ba.data()[file_len]=0;
         qFile.close ();
         int isUtf8 = IsUtf8(ba.constData());
         if ( isUtf8_ret ) *isUtf8_ret = isUtf8;
         if (isUtf8)
            {outParam    =  QString::fromUtf8 ( ba ) ;
             QString ext =  QFileInfo(qFile).suffix ();
             if (ext.toLower() == "htm")
                {outParam.replace("meta name=\"qrichtext\" content=\"charset=utf-8\"",   // obligé d'etre en content=\"1\" pour que les tabulations fonctionnent !!
                                  "meta name=\"qrichtext\" content=\"1\"");
                }
             outParam.replace("&nbsp;", " ");
            }
         else
            {outParam = QString::fromLocal8Bit (ba);
            }
         //delete[]text;
         return file_len;
}

//-----------------------------------------------------  IsUtf8 --------------------------------------------
/*! \brief gestion de l'Utf8.
*/
QString CGestIni::CharStrToQStringUtf8( const  char *ptr)
{if (IsUtf8( ptr))
    {return QString::fromUtf8 ( ptr );
    }
 else
    {return QString(ptr) ;
    }
}

//-----------------------------------------------------  IsUtf8 -------------------------------------------------
/*! \brief gestion de l'Utf8.
*/
int CGestIni::IsUtf8( const  QString & txt )
{//QByteArray  cs    = txt.utf8 ();
 //const char *pt = cs;
 return IsUtf8( txt );
}

//-----------------------------------------------------  IsUtf8 -------------------------------------------------
/*! \brief gestion de l'Utf8.
*/
int CGestIni::IsUtf8( const  char *txt)
{char unsigned *pt   = (char unsigned*) txt;
 if (pt==0 || *pt==0) return 0;
 int nb_utf8_paterns = 0;

 while (*pt)
      { if      (*pt >= 128)
                {if ( (*pt&224)==192 && (pt[1]&192)==128)
                    { ++nb_utf8_paterns;
                      ++pt;
                    }
                 else if ( (*pt&240)==224 && (pt[1]&192)==128 && (pt[2]&192)==128)
                    { ++nb_utf8_paterns;
                      pt += 2;
                    }
                 else if ( (*pt&248)==240 && (pt[1]&192)==128 && (pt[2]&192)==128 && (pt[3]&192)==128)
                    { ++nb_utf8_paterns;
                      pt += 3;
                    }
                else return 0;    // si car >= 128 sans un des paterns sus jacents --> on est pas en UTF8
               }
        ++pt;
      }
 return nb_utf8_paterns;
}

//--------------------------------- Utf8_Query -----------------------------------
/*! \brief gestion de l'Utf8.
*/
QString CGestIni::Utf8_Query(QSqlQuery &cur, int field)
{QByteArray   ba  =  cur.value(field).toByteArray();
 char       *ptr  =  ba.data();
 return fromMyUTF8(ptr);
 /*
 if (IsUtf8( ptr ))
    {//return QString::fromUtf8 ( ptr );
     return fromMyUTF8(ptr);
    }
 else
    {return QString(ptr) ;
    }
 */
}
//---------------------------------------------- fromMyUTF8 ------------------------------------------------
/*! \brief converti l'UTF8 explosé venant des SqlQuery, avec une methode qui fonctionne �  peu près en attendant de resoudre le PB par un moyen plus propre
 *  \param ptr : const char* chaine codée en UTF8
 *  \return QString convertie
 * RAPPEL : 0xxx xxxx                                    // poids fort �  zéro --> US-ASCII
 *          110x xxxx   10xx xxxx                        // code UTF8 sur deux octets    de  8 �  11 bits
 *          1110 xxxx   10xx xxxx  10xx xxxx             // code UTF8 sur trois octets   de 12 �  16 bits
 *          1110 xxxx   10xx xxxx  10xx xxxx  10xx xxxx  // code UTF8 sur quatre octets  de 17 �  21 bits
*/

QString CGestIni::fromMyUTF8(const char* ptr)
{QString ret = "";
 char unsigned *pt   = (char unsigned*) ptr;
 if (pt==0 || *pt==0)           return ret;
 while (*pt)
      { if      (*pt >= 128)   //......... unicode possible .................
                {if ( (*pt&224)==192 && (pt[1]&192)==128)
                    { int code_deuze  = 0;
                      int code_first  = pt[0]&3;
                      code_first      = code_first<<6;
                      code_first     += pt[1]&63;
                      if (code_first==195 && (pt[2]&192)==192)
                         {code_deuze  = pt[2]&3;
                          code_deuze  = code_deuze<<6;
                          code_deuze += pt[3]&63;
                          pt += 2;
                          if (code_deuze>=142 && code_deuze<=195)
                             {ret += QChar (0x00CE + code_deuze-142);         // case 142: ret += QChar (0x00CE);       break;   // Î
                             }
                          else
                             {switch (code_deuze)
                                 {case 198: ret += QChar (0x00C8);       break;   // È
                                  case 130: ret += QChar (0x00C0); ++pt; break;   // À
                                  case 128: ret += QChar (0x00C9); ++pt; break;   // É
                                  case 96:  ret += QChar (0x00CA);       break;   // Ê
                                 }
                            }
                         }
                      else
                         {switch(code_first)
                             {case 232:  ret += QChar (0x00E8);       break;
                              case 233:  ret += QChar (0x00E9);       break;
                              default:   ret += QChar (code_first);
                             }
                         } // end if (code_first==195 && (pt[2]&192)==192)
                      pt += 2;
                    }
                 else if ( (*pt&240)==224 && (pt[1]&192)==128 && (pt[2]&192)==128)
                    { pt += 2;
                    }
                 else if ( (*pt&248)==240 && (pt[1]&192)==128 && (pt[2]&192)==128 && (pt[3]&192)==128)
                    { pt += 3;
                    }
                else
                    {int c =  *pt;
                     switch (c)
                        {case 194 : if (pt[1]=='?') {ret += QChar (0x0153);    ++pt;}   break;   // œ
                         case 195 : if (pt[1]=='?') {ret += QChar (0x0045);    ++pt;}   break;   // E
                         case 156 :                 {ret += QChar (0x0153);         }   break;   // œ
                         default  : ret += *pt;
                        }
                      ++pt;
                    }
               }
           else   //.......... US-ASCI .................
               { ret += *pt;
                 ++pt;
               }
      }
 return ret;
}

//-----------------------------------------------------  Param_WriteParam -----------------------------------
/*! \brief Ecrit dans la string des paramètres passée �  la fonction.
 *  \param param : String paramètres dans laquelle on va écrire. Elle sera modifiée.
 *  \param section : section dans laquelle on écrit
 *  \param variable : variable concernée
 *  \param val1 -> val10 : valeurs �  écrire.
 *  \return QString::null en cas d'erreur, sinon le String de paramètre au complet.
 * Si la variable n'est pas trouvée dans la section elle est ajoutée. Si la section n'existe pas elle est ajoutée en fin de fichier.
*/
QString CGestIni::Param_WriteParam(QString *pQstr, const char *section, const char  *variable,
                                      const char *val1, const char *val2, const char *val3, const char *val4, const char *val5,
                                      const char *val6, const char *val7, const char *val8, const char *val9, const char *val10)
{if (pQstr == 0        )    return QString::null;
 if (pQstr->length()==0 && section && *section)   *pQstr = QString("[")+section+"]\n" ;
 if (pQstr->length()==0)    return QString::null;

 QString result    = "";
 QString tmp       = "";

 QByteArray ba     = pQstr->toAscii ();
 char* txt         = ba.data();
 char *pt          = txt;
 char *deb         = 0;
 char *end         = 0;
 char *deb_lgn     = 0;
 char *end_lgn     = 0;
 long len_section  = 0;
 long len_variable = 0;
 long         pos  = 0;
 while (*pt)
 {switch (pt[0])
    {case '\r':
     case '\n':
     case ';':
          pt = GotoNextDebLigne(pt);
          break;
     case '\\':
          if      ( pt[1] =='\\') pt = GotoNextDebLigne(pt);
          else if ( pt[1] !=0 )   pt +=2;
          break;
     /*
     case '\"':
          while (*pt && *pt != '\"')
             { if (*pt=='\\' && pt[1] !=0 ) ++pt;
               ++pt;
             }
          break;
     */
     case '[': //....................debut de section: tester si c'est celle recherchée ...................
          ++pt;
          while (*pt && (*pt==' '||*pt=='\t'))  ++pt;                // enlever espaces de debut
          deb = pt;
          while (*pt && *pt != ']') ++pt;                            // chercher delimiteur de fin de nom de section
          end = pt;
          while (end>deb && (end[-1]==' '||end[-1]=='\t')) end--;    // enlever espaces de fin
          len_section = end - deb;
          if ((long)strlen(section)==len_section && strncmp(section, deb, len_section)==0)   // SI c'est la section recherchée
             {pt = GotoNextDebLigne(pt);                                               // aller ligne suivante

              while (*pt && *pt != '[')                                                // tant que pas fin de zone de section (debut d'une autre)
                 {
                  while (*pt && (*pt==' '||*pt=='\t'))  ++pt ;                               // sauter espaces de debut de ligne
                  if  (*pt==';' || *pt=='\n'|| *pt =='\r') pt = GotoNextDebLigne(pt) ;       // sauter les commentaires et retour ligne
                  deb = pt;                       // on devrait etre au debut du nom d'une variable
                  while (*pt && *pt!='=' && *pt !='\n' && *pt!='\r' && *pt!='[') ++pt;      // le signe '=' marque la fin de zone du nom de la variable

                  //................... fin de nom de variable trouvé ( signe egal) ...........................
                  if (*pt=='=')
                     {end = pt;
                      while (end>deb && (end[-1]==' '||end[-1]=='\t')) end-- ;   // enlever espaces de fin du nom de la variable
                      len_variable = end - deb;
                      //.......................... Est ce celle recherchée ...................................
                      if ((long)strlen(variable)==len_variable && strncmp(variable, deb, len_variable)==0)   // SI c'est la variable recherchée
                         {deb_lgn = deb;
                          end_lgn = end;
                          while (*end_lgn && *end_lgn !=';' && *end_lgn !='\n' && *end_lgn!='\r')      // aller jusqu'au prochain marqueur de fin des valeurs
                                {if (*end_lgn=='\\' && end_lgn[1] !=0 ) end_lgn++;                     // en sautant le caractère d'echapement et le suivant
                                 end_lgn++;
                                }
                          while (end_lgn> end && (end_lgn[-1] ==' ' || end_lgn[-1] =='\t')) end_lgn--;  // reculer j'usqu'�  la fin de la derniere valeur
                          //........................... maintenant on peut supprimer et remplacer ........
                          pos    = deb_lgn-txt;
                          result = pQstr->left(pos) + variable + " = ";
                          if (val1)     result = result +         val1;
                          if (val2)     result = result + " , " + val2;
                          if (val3)     result = result + " , " + val3;
                          if (val4)     result = result + " , " + val4;
                          if (val5)     result = result + " , " + val5;
                          if (val6)     result = result + " , " + val6;
                          if (val7)     result = result + " , " + val7;
                          if (val8)     result = result + " , " + val8;
                          if (val9)     result = result + " , " + val9;
                          if (val10)    result = result + " , " + val10;
                          result   += pQstr->mid(end_lgn-txt);
                          *pQstr    = result;
                          return result;
                         }  //end if (strlen(variable)==len_variable && strncmp(variable, deb, len_variable)==0)
                      pt = GotoNextDebLigne(pt);                                               // aller ligne suivante
                     } // end if (*pt=='=')
                 } // end while (*pt && *pt != '[')
               //.......................... fin de section atteinte sans avoir trouvé la variable .........
               //                           la section est trouvée mais pas la variable on la rajoute
               tmp = "";
               while (pt>txt && (pt[-1]=='\r'||pt[-1]=='\n' ||pt[-1]=='\t'||pt[-1]==' ')) pt--;  // nettoyer avant eliminer espaces et  CR/LF avant
               tmp = tmp + "\r\n";
               tmp = tmp + "  " + variable + " = ";
               if (val1)     tmp  = tmp +         val1;
               if (val2)     tmp  = tmp + " , " + val2;
               if (val3)     tmp  = tmp + " , " + val3;
               if (val4)     tmp  = tmp + " , " + val4;
               if (val5)     tmp  = tmp + " , " + val5;
               if (val6)     tmp  = tmp + " , " + val6;
               if (val7)     tmp  = tmp + " , " + val7;
               if (val8)     tmp  = tmp + " , " + val8;
               if (val9)     tmp  = tmp + " , " + val9;
               if (val10)    tmp  = tmp + " , " + val10;
               tmp     = tmp + "\r\n\r\n";
               pos     = pt-txt;
               result  = pQstr->left(pos) + tmp ;
               while (*pt && (*pt=='\r' || *pt=='\n' || *pt=='\t' || *pt==' ')) ++pt;           // nettoyer apres eliminer espaces et  CR/LF apres
               pos     = pt-txt;
               result += pQstr->mid(pos);
               *pQstr  = result;
               return result;
              } // end if (strlen(section)==len_section && strncmp(section, deb, len_section)==0)   // SI c'est la section recherchée
          break;
      default:
          ++pt;
     } // end switch (pt[0])
  } // end while (*pt)

 //................pas de section trouvée on la rajoute ...........................................
 tmp = "\r\n[";
 tmp = tmp + section + "]\r\n  " + variable + " = ";
 if (val1)     tmp  = tmp +         val1;
 if (val2)     tmp  = tmp + " , " + val2;
 if (val3)     tmp  = tmp + " , " + val3;
 if (val4)     tmp  = tmp + " , " + val4;
 if (val5)     tmp  = tmp + " , " + val5;
 if (val6)     tmp  = tmp + " , " + val6;
 if (val7)     tmp  = tmp + " , " + val7;
 if (val8)     tmp  = tmp + " , " + val8;
 if (val9)     tmp  = tmp + " , " + val9;
 if (val10)    tmp  = tmp + " , " + val10;
 tmp     =  tmp  + "\r\n";
 result  = *pQstr + tmp;
 *pQstr  = result;
 return result;
}
//-----------------------------------------------------  Param_ReadUniqueParam --------------------------------
/*! \brief lit une valeur dans un fichier de configuration.
 *  \param txt : String paramètres dans laquelle on va lire
 *  \param section : section dans laquelle on va lire
 *  \param variable : variable concernée
 *  \return QString::null la variable n'existe pas. sinon retourne la valeur
*/
QString CGestIni::Param_ReadUniqueParam(const char* txt, const char *section, const char  *variable)
{QString val;
 if (Param_ReadParam( txt, section, variable, &val)==QString::null) return val;
 else return QString::null;
}

//-----------------------------------------------------  Param_ReadParam --------------------------------
/*! \brief récupère les valeurs au sein du String paramètre passé �   la fonction.
 *  \param txt : String paramètres dans laquelle on va lire
 *  \param section : section dans laquelle on va lire
 *  \param variable : variable concernée
 *  \param val1 -> val10 : valeurs �  lire
 *  \return QString::null si tout OK. sinon retourne le message d'erreur
*/
QString CGestIni::Param_ReadParam(  const char* txt, const char *section, const char  *variable,
                                    QString *val1, QString *val2, QString *val3, QString *val4, QString *val5,
                                    QString *val6, QString *val7, QString *val8, QString *val9, QString *val10)

{if (txt==0)   return QObject::tr("Erreur de syntaxe: Fichier de paramètres vide");
 char *pt          = (char*) txt;
 char *deb         = 0;
 char *end         = 0;
 long len_section  = 0;
 long len_variable = 0;
 if (section==0)
    {QString str(QObject::tr("Erreur : pas de section dans l'appel de la fonction CGestIni::Param_ReadParam()"));
     //qDebug(str);
     return str;
    }
 while (*pt)
 {switch (pt[0])
    {case '\r':
     case '\n':
     case ';':
          pt = GotoNextDebLigne(pt);
          break;
     case '/':
          if      ( pt[1] =='/')  pt = GotoNextDebLigne(pt);
          else if ( pt[1] !=0 )   pt +=2;
          break;
     /*
     case '\"':
          while (*pt && *pt != '\"')
             { if (*pt=='\\' && pt[1] !=0 ) ++pt;
               ++pt;
             }
          break;
     */
     case '[': //....................debut de section: tester si c'est celle recherchée ...................
          ++pt;
          while (*pt && (*pt==' '||*pt=='\t'||*pt=='\a'))  ++pt;                // enlever espaces de debut
          deb = pt;
          while (*pt && *pt != ']') ++pt;                            // chercher delimiteur de fin de nom de section
          end = pt;
          while (end>deb && (end[-1]==' '||end[-1]=='\t'|| end[-1]=='\a')) end--;    // enlever espaces de fin
          len_section = end - deb;
          if ((long)strlen(section)==len_section && strncmp(section, deb, len_section)==0)   // SI c'est la section recherchée
             {pt = GotoNextDebLigne(pt);
              while (*pt && (*pt==' '||*pt=='\t'||*pt=='\r'||*pt=='\n'||*pt=='\a'))  ++pt ;                                                 // aller ligne suivante (zone des variables de section)
              while (*pt && *pt != '[')                                                      // tant que pas fin de zone de section (debut d'une autre ou fin)
                 {
                  while (*pt && (*pt==' '||*pt=='\t'||*pt=='\a'))  ++pt ;                                             // sauter espaces de debut de ligne
                  if  (*pt==';' || *pt=='\n'|| *pt =='\r'||*pt=='\a') { pt = GotoNextDebLigne(pt) ;                   // sauter les commentaires et retour ligne en allant ligne suivante
                                                             while (*pt && (*pt==' '||*pt=='\t'||*pt=='\a'))  ++pt ;  // ressauter espaces de debut de ligne
                                                           }
                  else if (*pt=='/'&& pt[1] =='/')         { pt = GotoNextDebLigne(pt);
                                                             while (*pt && (*pt==' '||*pt=='\t'||*pt=='\a'))  ++pt ;  // ressauter espaces de debut de ligne
                                                           }
                  deb = pt;                       // on devrait etre au debut du nom d'une variable
                  //while (*pt && *pt!='=')  ++pt;  // le signe '=' marque la fin de zone du nom de la variable
                  while (*pt && *pt!='=' && *pt!='[')
                        {if (*pt=='\\' && pt[1] !=0 ) pt += 2;
                         else ++pt;
                        }
                  if (*pt==0||*pt=='[') return QObject::tr("Signe = non trouvé dans la section : ") + section + QObject::tr(", variable recherchée : ") + variable ;
                  end = pt;
                  while (end>deb && (end[-1]==' '||end[-1]=='\t'|| end[-1]=='\a')) end-- ;   // enlever espaces de fin du nom de la vaiable
                  len_variable = end - deb;
                  if ((long)strlen(variable)==len_variable && strncmp(variable, deb, len_variable)==0)   // SI c'est la variable recherchée
                     {++pt;   // passer le signe egal
                      Param_ExtraireValeurs(pt, val1, val2, val3, val4, val5, val6, val7, val8, val9, val10);
                      return QString::null;
                     }
                  pt = GotoNextDebLigne(pt);                                               // aller ligne suivante
                 }
               //......... si on arrive ici c'est que ok pour la section mais pas de variable ..........................
               return QObject::tr("Pas de variable : ") + variable + QObject::tr("  pour la section : ") + section;
              } // end if (strlen(section)==len_section && strncmp(section, deb, len_section)==0)   // SI c'est la section recherchée
          break;
      default:
          ++pt;
     } // end switch (pt[0])
  } // end while (*pt)
 return QObject::tr("Erreur de syntaxe : Pas de section dans ce fichier");
}

//-----------------------------------------------------  ExtraireValeurs -----------------------------------
/*! \brief txt pointe sur un texte contenant differentes valeurs terminées par \r\n ou zero de fin, et separées par des virgules. Une valeur peut etre une chaine de caractères et si elle doit comporter une virgule ou point virgule ceux ci doivent etre annoncés par le caractere d'echapement qui est l'anti slash
*/
char *CGestIni::Param_ExtraireValeurs(  const char* txt,
                                        QString *val1, QString *val2, QString *val3, QString *val4, QString *val5,
                                        QString *val6, QString *val7, QString *val8, QString *val9, QString *val10)
{char *pt          = (char*) txt;
 int num_param     = 0;
 char *deb         = 0;
 char *end         = 0;
 long   len        = 0;

 if (val1)  *val1  = QString::null;
 if (val2)  *val2  = QString::null;
 if (val3)  *val3  = QString::null;
 if (val4)  *val4  = QString::null;
 if (val5)  *val5  = QString::null;
 if (val6)  *val6  = QString::null;
 if (val7)  *val7  = QString::null;
 if (val8)  *val8  = QString::null;
 if (val9)  *val9  = QString::null;
 if (val10) *val10 = QString::null;

 while (1)
   {while (*pt && *pt !='\r' && *pt !='\n' && *pt !=';' && (*pt==' '||*pt=='\t'))  ++pt;      // sauter espaces de debut
    if (*pt==0 || *pt =='\r' || *pt =='\n'|| *pt ==';') return pt;
    deb = pt;                                                                    // on devrait etre au debut du nom d'une valeur
    while (*pt && *pt !=',' && *pt !='\n' && *pt!='\r')                          // aller jusqu'a la prochaine virgule (fin de la valeur)
       {if (*pt=='\\' && pt[1] !=0 ) ++pt;                                       // sauter le caractère d'echapement et le suivant
        ++pt;
       }
    end = pt;
    while (end>deb && (end[-1]==' '||end[-1]=='\t')) end--;                      // enlever espaces de fin
    len    = end-deb;
    switch(num_param)
           {case 0: if (val1)  *val1  = utf8Conv(deb,len);  break;
            case 1: if (val2)  *val2  = utf8Conv(deb,len);  break;
            case 2: if (val3)  *val3  = utf8Conv(deb,len);  break;
            case 3: if (val4)  *val4  = utf8Conv(deb,len);  break;
            case 4: if (val5)  *val5  = utf8Conv(deb,len);  break;
            case 5: if (val6)  *val6  = utf8Conv(deb,len);  break;
            case 6: if (val7)  *val7  = utf8Conv(deb,len);  break;
            case 7: if (val8)  *val8  = utf8Conv(deb,len);  break;
            case 8: if (val9)  *val9  = utf8Conv(deb,len);  break;
            case 9: if (val10) *val10 = utf8Conv(deb,len); break;
           }
    if (*pt==',')  ++pt;      // on saute la virgule et on passe au param suivant
    num_param ++;
   }
 return pt;
}

//----------------------------------------- utf8Conv ---------------------------------------------
/*! \brief Récupère les valeurs d'une variables (varToRetrieve) d'une section (sectionToRetrieve) du string paramètre (outParam) dans une QStringList lst.
*/
QString CGestIni::utf8Conv(const char* deb, long len)
{if (IsUtf8( deb))
    {return fromMyUTF8(deb);
    }
  else
    {return QString::fromLatin1(deb,len);
    }
}

//------------------------------ Param_RemoveSection -----------------------------------------
/*! \brief enlève une section.
 *  \param param   : String parametres dans laquelle supprimer une section
 *  \param section : section a supprimer
*/
QString CGestIni::Param_RemoveSection(QString &param, QString section)
{    section.prepend("[");
     section.append("]");
     int pos_deb  = param.indexOf(section);
     int pos_end  = -1;
     if (pos_deb != -1)
        {pos_end = param.indexOf("[", pos_deb+section.length());
         //.............. eliminer tous les espaces rn tab  arrieres .......................
         while (pos_deb>0){QChar c=param[pos_deb-1];
                           if (c=='\t' || c=='\r'|| c=='\n'|| c==' ') --pos_deb;
                           else                                           break;
                          }
         if (pos_end != -1)
            { param = param.remove(pos_deb, pos_end-pos_deb);
              param = param.insert(pos_deb,"\n\n");
            }
         else
            { param.truncate(pos_deb);
            }
        }
    return param;
}

//----------------------------------------- Param_GetList ---------------------------------------------
/*! \brief Récupère les valeurs d'une variables (varToRetrieve) d'une section (sectionToRetrieve) du string paramètre (outParam) dans une QStringList lst.
 *  \param outParam : String parametres dans laquelle l'on va extraire une liste.
 *  \param sectionToRetrieve : section contenant les variables dont il faut faire une liste
 *  \param varToRetrieve     : variable dont il faut faire une liste (si vide alors toute la ligne apres le signe = sera retenue)
 *  \param lst :  liste a initialiser et construire
 *  \param isToStrip :  isToStrip a zero par defaut si a un, chaque element de la liste sera nettoye des espaces de debut et fin
*/
void CGestIni::Param_GetList(QString &outParam, const QString &sectionToRetrieve, const QString &varToRetrieve,  QStringList &lst , int isToStrip /*=0*/)
{
 QString        data    = "";
 QString      section   = "";
 QString     var_name   = "";
 QByteArray       ba    = outParam.toAscii ();
 char             *pt   = ba.data();
 //long             len   = ba.length();
 //char            *end   = pt + len;
 char             *deb  = 0;
 while((pt = Param_GotoNextSection(pt, 0, &section)) && *pt)
    {if (section == sectionToRetrieve)
        {lst.clear();
         while (*pt && *pt != '[')
                {data    = "";
                 if (varToRetrieve.length())
                    {pt      = Param_ExtraireNextValeurs(pt, var_name, &data);
                     if (data.length() && (varToRetrieve.length()==0 || varToRetrieve==var_name) )
                        {lst.append(data.trimmed());
                        }
                    }
                 else
                    {
                     while (*pt && (*pt==' '||*pt=='\t') )      ++pt ; // sauter espaces de debut de ligne
                     if  (*pt==';' || *pt=='\n'|| *pt =='\r')
                         {pt = GotoNextDebLigne(pt) ;                  // sauter les commentaires et retour ligne
                          while (*pt && (*pt==' '||*pt=='\t') ) ++pt ; // sauter espaces de debut de ligne
                         }
                     if  (*pt=='[') return;                            // si fin de section cassos
                     deb  = pt;                                        // on devrait etre au debut du nom d'une variable
                     pt   = GotoEndOfLigne(pt);
                     data = QString::fromLatin1 (deb, pt-deb).trimmed();
                     if (data.length())
                        {int pos = data.indexOf('=');
                         if (pos != -1) data = data.mid(pos+1);
                         if (isToStrip)   lst.append(data.trimmed());
                         else             lst.append(data);
                        }
                    }
                }
         break;
        }
     }
}

//----------------------------------------- Param_GetList ---------------------------------------------
/*! \brief Récupère les valeurs d'une variables (varToRetrieve) d'une section (sectionToRetrieve) du string paramètre (outParam) dans une QStringList lst.
 *  \param file_ini : nom du fichier ou l'on va extraire une liste.
 *  \param sectionToRetrieve : section contenant les variables dont il faut faire une liste
 *  \param lst :  liste a initialiser et construire
 *  \param varToRetrieve     :(par defaut "")  variable dont il faut faire une liste (si vide alors toute la ligne apres le signe = sera retenue)
 *  \param isToStrip :  isToStrip (a un par defaut) si a un, chaque element de la liste sera nettoye des espaces de debut et fin
 *  \param isUtf8 : pointeur sur un int (par defaut �  zero) qui si different de zero sera initialise a un si le fichier est en UTF8
*/

void CGestIni::Param_GetList(const QString &file_ini, const QString &sectionToRetrieve, QStringList &lst, const QString &varToRetrieve/*=""*/,  int isToStrip /*=0*/, int *isUtf8 /*=0*/)
{QString outParam;
 Param_UpdateFromDisk( file_ini,  outParam,  isUtf8 );
 Param_GetList( outParam, sectionToRetrieve, varToRetrieve, lst, isToStrip );
}

//------------------------------ Param_GotoNextSection -----------------------------------------
/*! \brief Passe �  la section suivante en débutant au pointeur pt.
*/
char *CGestIni::Param_GotoNextSection(char *pt, const char* section, QString *pQsection)
{char *deb         = 0;
 char *end         = 0;
 long len_section  = 0;
 while (*pt)
 {switch (pt[0])
    {case '\r':
     case '\n':
     case ';':
          pt = GotoNextDebLigne(pt);
          break;
     /*
     case '\"':
          while (*pt && *pt != '\"')
                { if (*pt=='\\' && pt[1] !=0 ) ++pt;
                  ++pt;
                }  // aller apres de guillemet fermant
          break;
     */
     case '\\':
          if ( pt[1] !=0 ) pt +=2;
          break;
     case '[': //....................debut de section: tester si c'est celle recherchée ...................
          ++pt;
          while (*pt && (*pt==' '||*pt=='\t'))  ++pt;                // enlever espaces de debut
          deb = pt;
          while (*pt && *pt != ']') ++pt;                            // chercher delimiteur de fin de nom de section
          if ( *pt != ']')    return  pt;                                     // y en a pas --> erreur (*pt == 0)
          end = pt;
          while (end>deb && (end[-1]==' '||end[-1]=='\t')) end--;    // enlever espaces de fin
          len_section = end - deb;
          if (len_section>0 && pQsection != 0)
             {*pQsection=QString::fromLatin1(deb, len_section);
             }
          if ( section == 0)  return  GotoNextDebLigne(pt);   // pas de section donnée, on s'arrete �  la première trouvée
          if ((long)strlen(section)==len_section && strncmp(section, deb, len_section)==0)             // SI c'est la section recherchée
             {                return  GotoNextDebLigne(pt);                            // aller ligne suivante
             } // end if (strlen(section)==len_section && strncmp(section, deb, len_section)==0)   // SI c'est la section recherchée
          break;
      default:
          ++pt;
     } // end switch (pt[0])
  } // end while (*pt)
 return pt;
}
//------------------------------ formatStringForParam ----------------------------------------
QString  CGestIni::formatStringForParam(QString &str)
{   str = str.prepend("$DEB$");
    str = str.replace("[","$|$");
    str = str.replace("]","$*$");
    str = str.replace(",","$.$");
    str = str.replace("\r","$r$");
    str = str.replace("\n","$n$");
    str = str.replace(";","$^$");
    str = str + "$END$";
    return str;
}

//------------------------------ retrieveStringForParam ----------------------------------------
QString  CGestIni::retrieveStringForParam(QString &str)
{           str = str.remove("$DEB$");
            str = str.remove("$END$");
            str = str.replace("$|$","[");
            str = str.replace("$*$","]");
            str = str.replace("$.$",",");
            str = str.replace("$r$","\r");
            str = str.replace("$n$","\n");
            str = str.replace("$^$",";");
            return str;
}

//------------------------------ Param_ExtraireNextValeurs ----------------------------------------
/*! \brief Extrait les valeurs d'une variable donnée.
*/
char *CGestIni::Param_ExtraireNextValeurs(char* pt, QString &var_name,
                                             QString *val1, QString *val2, QString *val3, QString *val4, QString *val5,
                                             QString *val6, QString *val7, QString *val8, QString *val9, QString *val10)
{return Param_ExtraireNextValeurs(pt, var_name, 0, 0, val1,  val2,  val3,  val4,  val5,  val6,  val7,  val8,  val9, val10);
}

//------------------------------ Param_ExtraireNextValeurs ----------------------------------------
/*! \brief Extrait les valeurs d'une variable donnée dans un string paramètre donné.
*/
char *CGestIni::Param_ExtraireNextValeurs(char* pt, QString &var_name, char**pt_lgn, long *len,
                                             QString *val1, QString *val2, QString *val3, QString *val4, QString *val5,
                                             QString *val6, QString *val7, QString *val8, QString *val9, QString *val10)
{char *deb         = 0;
 char *end         = 0;
 long len_variable = 0;

 while (*pt && (*pt==' '||*pt=='\t') )      ++pt ; // sauter espaces de debut de ligne
 if  (*pt==';' || *pt=='\n'|| *pt =='\r')
     {pt = GotoNextDebLigne(pt) ;                  // sauter les commentaires et retour ligne
      while (*pt && (*pt==' '||*pt=='\t') ) ++pt ; // sauter espaces de debut de ligne
     }
 if  (*pt=='[') return pt ;
 deb = pt;                                                                  // on devrait etre au debut du nom d'une variable
 while (*pt && *pt!='=')
       {if (*pt=='\\' && pt[1] !=0 ) pt += 2;
        else if (*pt == '[')  break;       // le signe '[' marque la fin de zone des variables de cette section
        else ++pt;
       }
 if (*pt==0)    return pt ;
 if (*pt=='[')  return pt ;
 end = pt;
 while (end>deb && (end[-1]==' '||end[-1]=='\t')) end-- ;   // enlever espaces de fin
 len_variable = end - deb;
 if (len_variable>0 )
    {var_name = QString::fromLatin1 (deb, len_variable).trimmed();
    }
 ++pt;   // passer le signe egal
 Param_ExtraireValeurs(pt, val1, val2, val3, val4, val5, val6, val7, val8, val9, val10);
 if (pt_lgn)
    {*pt_lgn = deb;
     pt      = GotoEndOfLigne(pt);
     if (*len) *len = (pt-deb);
    }
 return GotoNextDebLigne(pt);                                               // aller ligne suivante
}

//------------------------------ GotoNextDebLigne -----------------------------------------
/*! \brief déplace le pointeur jusqu'au début de la ligne suivante.
*/
char *CGestIni::GotoNextDebLigne(const char* txt)
{char *pt  = (char*) txt;
 while (*pt)
    {if      ( pt [0]=='\\'&& pt [1] !=0)            (pt+=2);
     else if ( pt [0]=='\r'&& pt [1] =='\n')  return (pt+=2);
     else if ( pt [0]=='\n'&& pt [1] =='\r')  return (pt+=2);
     else if ( pt [0]=='\n'|| pt [0] =='\r')  return (pt+1);
     else ++pt;
    }
 return pt;
}

//------------------------------ GotoEndOfLigne -----------------------------------------
/*! \brief déplace le pointeur jusqu'�  la fin de la ligne.
*/
char *CGestIni::GotoEndOfLigne(const char* txt)
{char *pt  = (char*) txt;
 while (*pt)
    {if      ( pt [0]=='\\'&& pt [1] !=0)            (pt+=2);
     else if ( pt [0]=='\r'&& pt [1] =='\n')  return pt;
     else if ( pt [0]=='\n'&& pt [1] =='\r')  return pt;
     else if ( pt [0]=='\n'|| pt [0] =='\r')  return pt;
     else ++pt;
    }
 return pt;
}

//------------------------------ Construct_Name_Exe -----------------------------------------
/*! \brief construit le chemin vers l'executable du module (module) de MendinTux. Gère la compatibilité Windows/Linux/Mac.
*/
QString CGestIni::Construct_Name_Exe(QString module, QString start_Argv, const QString &alternateExecName /*="" */)
{
/*      Signature :  String         X String                              --> String
                     nom du module  X Chemin complet de demarrage du proc --> nom  ini complet du module
    Permet la construction d'un nom complet de fichier executable en =
relation avec le module correspondant
*/

        QString path;
        QString exeName;
        if (alternateExecName.length()) exeName = alternateExecName;
        else                            exeName = module;
        //Création du nom de fichier
       if (module=="compta-plugins" || module=="check_dus"  || module=="comptabilite" )
          { path   = start_Argv + "/" + PATH_SPEC_MAC + "../../comptabilite/bin/" + exeName + F_EXT;
            module = exeName;
            path  +=  ARCHI_DEP_MAC;
          }
       else
          { path   = start_Argv + "/" + PATH_SPEC_MAC + "../../"+module+"/bin/"  + exeName + F_EXT;
            module = exeName;
            path  +=  ARCHI_DEP_MAC;
          }
        path = QDir::cleanPath (path);
        return path;

}


//------------------------------ Construct_Name_File_Ini -----------------------------------------
/*! \brief construit le chemin vers le fichier ini du module (module) de MendinTux. Gère la compatibilité Windows/Linux/Mac.
*/
QString CGestIni::Construct_Name_File_Ini(QString module, QString start_Argv, QString nom_Fichier_Alternatif ){
/*      Signature :  String         X String X String                                                   --> String
        nom du module  X Chemin complet proc demarrage X Nom du fichier ini alternatif      --> nom  ini complet du module
        avec en plus son chemin relatif
        au module en question
        ex : ccamview/bin/ccamview
        ici il renverra un nom de fichier
        du genre [chemin du module]/ccamview/bin/ccamview.ini
        Permet la construction d'un nom complet de fichier ini en relation =
        avec le module correspondant ou d'un fichier   alternatif
*/

        QString path;
        if (nom_Fichier_Alternatif.length()){
                path = start_Argv + "/" + PATH_SPEC_MAC + "../../" + module + "/bin/" + nom_Fichier_Alternatif;
        }else{
                path = start_Argv + "/" + PATH_SPEC_MAC + "../../" + module + "/bin/" + module + ".ini";
        }

        path = QDir::cleanPath (path);
        return path;
}

//------------------------------ Construct_PathBin_Module -----------------------------------------
/*! \brief Permet la construction d'un nom complet de fichier executable en  relation avec le module correspondant
 *  \param QString  module : nom du programme dont on cherche �  construire le chemin complet si egal �  "" alors le nom du chemin sera extrait de : start_Argv
 *  \param const QString & start_Argv : Chemin complet de demarrage du programme
 *  \param QString *base_name : adresse d'une QString qui dans laquelle si elle est différente de zero sera retourné le nom du programme SANS SON EXTENSION
 *  \return nom du module  avec le chemin complet de demarrage du proc --> nom  ini complet du module
*/
QString CGestIni::Construct_PathBin_Module(const QString  &module, const QString & ref_dir)
{ return  QDir::cleanPath (ref_dir + "/" + PATH_SPEC_MAC + "../../" + module + "/bin/")+ "/" ;
}

//------------------------------ AbsoluteToRelativePath -----------------------------------------
/*! \brief convertit un chemin absolu en chemin relatif par rapport a un chemin de reference, il est imperatif que les chemins d'entree soient tous en absolu.
 *  \param QString pathRef : chemin de reference par rapport auquel il faut relativiser
 *  \param QString pathToConvert : chemin � convertir
 *  \return chemin convertit en relatif
*/

QString CGestIni::AbsoluteToRelativePath(QString pathRef, QString pathToConvert)
{int      posR = -1;
 int      posC = -1;
 if (pathToConvert.length()>2 && pathToConvert.left(2)=="\\\\")  return pathToConvert;  // si reseau on ne peut pas relativiser
 pathRef       = pathRef.replace("\\","/");
 pathToConvert = pathToConvert.replace("\\","/");
 pathRef       = pathRef.replace("//","/");
 pathToConvert = pathToConvert.replace("//","/");
 //............ enlever l'�ventuel C: ...........................
 //             de facon � ce que les racines soient identiques : /xxxx/nnnnn/etc/
 posR           = pathRef.indexOf(':');
 posC           = pathToConvert.indexOf(':');
 if (posR !=-1 && posC !=-1 && pathRef[0] != pathToConvert[0]) return pathToConvert; // si les partitions sont differentes l'on ne peut pas relativiser
 if (posR !=-1) pathRef       = pathRef.mid(posR+1);
 if (posC !=-1) pathToConvert = pathToConvert.mid(posC+1);
 pathRef       = pathRef.trimmed();
 pathToConvert = pathToConvert.trimmed();
 //........................... rechercher jusqu'ou le debut des chemins est le meme ..............................
 int posRef      = pathRef.indexOf('/');
 int posDst      = pathToConvert.indexOf('/');
 int last_posRef = posRef;
 int last_posDst = posDst;
 int posToCut    = 0;
 QString cpRef   ="";
 QString cpDst   ="";
 while (posRef  != -1 && posDst != -1)    //   /xxxxx/ccccc/nnnn/     /xxxxx/ccccc/nnnn/uuuuuuu/mmmmmm/ppppppppp
    {cpRef = pathRef.mid(last_posRef, posRef-last_posRef);
     cpDst = pathToConvert.mid(last_posDst, posDst-last_posDst);
     if (cpRef == cpDst )
        {posToCut   = posRef;
        }
     else break;
     last_posRef = posRef;
     last_posDst = posDst;
     posRef      = pathRef.indexOf('/',last_posRef+1);
     posDst      = pathToConvert.indexOf('/',last_posDst+1);
    }
  //........................... couper les chemins ..............................
 pathToConvert = pathToConvert.mid(posToCut);
 pathRef       = pathRef.mid(posToCut);
 //............................ compter le nombre de ../ a mettre ...................
 int            n = pathRef.count( '/');
 QString relative = "";
 for (int i=1; i<n; ++i) relative += "../";
 relative   += pathToConvert;
 relative    = relative.replace("//","/");
 return relative;
}

//-------------------------- listDirectory -------------------------------------------
/*! \brief non documenté */
QStringList CGestIni::listDirectory(QString start_dir, const QString &filterExt_in/*=""*/, const QString &filterName/*=""*/, const QString &sep/*=";"*/, bool listWithoutExt/*=FALSE*/)
{   QStringList    ret;
    QString        filterExt = filterExt_in;
    QStringList filterList;
    QStringList extList;
    if (filterName.length())  filterList = filterName.split (sep);
    if (filterExt.length())   extList    = filterExt.remove('.').split ( sep);   //suffix() retourne l'extension sans le point

    //................ allons y  .....................................................
    QDir l_dir;
    l_dir.setPath ( start_dir );
    l_dir.makeAbsolute ();
    l_dir.setFilter( QDir::AllDirs | QDir::NoSymLinks | QDir::Files);

    //............ exploration de la liste ......................
    QFileInfoList qFileInfoList   = l_dir.entryInfoList();
    QList<QFileInfo>::iterator it = qFileInfoList.begin();
    QFileInfo            fi;
     while ( it != qFileInfoList.end() )
          {fi = *it;
           QString fname = fi.fileName();
           QString ext   = QFileInfo(fname).suffix().toLower();
           int ut;
           if      (fname == "..")
                   {
                   }
           else if (fi.isDir() && fname[0] != '.' )
                   {
                   }
           else if (fi.isFile() && fname[0] != '.')
                   {bool ok = TRUE;

                    if (extList.count())
                       {ok = FALSE;
                        ut = extList.indexOf(ext);
                        if (ut !=  -1) ok = TRUE;
                       }
                    if (ok && filterList.count())
                       {ok = FALSE;
                        for ( ut = 0; ut != filterList.count () && ok==FALSE; ++ut )
                            {if (fname.indexOf(filterList[ut]) != -1) ok = TRUE;
                            }
                       }
                    if (ok)
                       {if (listWithoutExt)    ret.append(fi.baseName());
                        else                   ret.append(fname);
                       }
                   }
           ++it;
          }
  return ret;
}
//-----------------------------------------------------  PassWordEncode --------------------------------------------------
// Algo minimal pour l'instant
// chaque octet tourne de sa position dans la chaine + 1, et Xor final avec le mot de passe en clair puis converti en hexa
// resultat final en hexa;
// les linges qui sechent mouillent les cordes
// brouiller les cartes

QString CGestIni::PassWordEncode(QString &pass)
{char encoded_car;
 char pt_magic_key[]    = "les linges qui sechent mouillent les cordes";
 QString encoded_str    = "";
 QByteArray       ba    = pass.toAscii ();
 char             *pt   = ba.data();
 int         len_pass   = ba.length();

 for (int i=0; i<len_pass;++i)
     {encoded_car  =  pt[i]^pt_magic_key[i];
      encoded_str += UINTtoHex(encoded_car);
     }
 return encoded_str;

 /*
 char str[34];
 INT16    val;
 int len         = pass.length();

 if (len>32)       return ERR_PASS_MAX;
 if (len==0)       return ERR_PASS_ZERO;
 strcpy(str , pass);
 pass = "";
 for (int i=0; i<len; ++i)
     { val   =  str[i];
       val   =  (val << ((i+1)&0x000F) )^val;
      pass  += UINTtoHex(val);
     }
 return ERR_PASS_OK;
 */

}

//-----------------------------------------------------  PassWordDecode --------------------------------------------------
// Algo minimal pour l'instant
//
QString CGestIni::PassWordDecode(QString str_to_decode)
{if (str_to_decode.startsWith("#")) str_to_decode = str_to_decode.mid(1);
 char decoded_car;
 char pt_magic_key[] = "les linges qui sechent mouillent les cordes";
 QString decoded_str = "";
 int len_pass        = str_to_decode.length();
 int      pos        = 0;
 while ( pos < len_pass)
     {decoded_car  = HexToUINT( str_to_decode.mid(pos,4).toAscii());
      decoded_car  =  decoded_car ^ pt_magic_key[pos/4];
      decoded_str += decoded_car;
      pos         += 4;
     }
 return decoded_str;

 /*
 char     buf[16];
 UINT16   val;
 if (str_to_decode == 0 || str_pass == 0) return ERR_PASS_MAX;
 int len_to_decode      = strlen(str_to_decode);
 if (len_to_decode==0)             return ERR_PASS_ZERO;
 int len_pass           = strlen(str_pass);
 if (len_pass != len_to_decode/4)  return ERR_PASS_MAX;
 QString result;
 int end = len_to_decode/4;
 buf[4 ] = 0;
 for (int i=0; i<end; ++i)
     {memcpy(buf, str_to_decode + i*4, 4);  // recuperer les 4 caractere hexa
      val = HexToUINT(buf);                 // les convertir en UINT16
      val = val ^ str_pass[i];              // xor avec le mot de passe
      val = val >> ((i+1)&0x000F);          // rotation inverse maxi de 8 et on devrait avoir le code ASCII
      if (val != str_pass[i])      return ERR_PASS_MAX;    // erreur si pas egal
     }
 return ERR_PASS_OK;
 */

}

//-----------------------------------------------------  UINTtoHex --------------------------------------------------------
QString CGestIni::UINTtoHex( quint16 val)
{char hex[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};   // lÃ  on peut mettre une table Bidon
 QString res="";
 res += hex[(val>>12)& 0x000F];
 res += hex[(val>>8) & 0x000F];
 res += hex[(val>>4) & 0x000F];
 res += hex[val&0x000F];
 return res;
}

//-----------------------------------------------------  HexToUINT --------------------------------------------------------
quint16 CGestIni::HexToUINT( const char *str)
{int i   = strlen(str);
 if (i==0) return 0;
 quint16 val = 0;
 int     dec = 0;
 while (i>0)
   {--i;
    unsigned char car = str[i] | 32;     // mettre en minuscules
    if      (car>='a'&& car<= 'f')  val  += (car-'W')<<dec;  //a (97) - W (87) --> 10
    else                            val  += (car-'0')<<dec;  //0 (48) - 0 (48) --> 0
    dec += 4;
   }
 return val;
}
