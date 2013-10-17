

#include <qmime.h>
#include <qimage.h>
#include <qlabel.h>
#include <qdir.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qpushbutton.h>
#include <qdatetime.h>
#include <qfile.h>
#include <qfileinfo.h>
#include <qobject.h>
#include <qmessagebox.h>
#include <qtextbrowser.h>

#include "ui/DlgMyMessageBox.h"
#include "ui/DlgGetString.h"
#include "CHtmlTools.h"
#include "CGestIni.h"
#include "CGenTools.h"

#define TR QObject::tr

//---------------------------------------------- FileToQString ------------------------------------------------------------
 void CGenTools::FileToQString(const char *path, QString  &dst, int mode /* = 1 */, int htmlHeader /* = 0 */)
{QString    qspath = path;
 QString    ext    = GetExtension(qspath, 4).lower();
 CGestIni::Param_UpdateFromDisk(path, dst);

 if (ext !=".htm")
    {if (ext ==".rtf")
        {QString temp = dst;
         CHtmlTools::RtfToQtextEdit_HTML(temp, temp.length(), dst, htmlHeader);     // 0 -> sans le header
        }
     else if (mode & 2 && ext==".txt")
       {QString temp = dst;
        Convert_CRLF_To_BR(temp, dst,1);
       }
    else if (mode)
      {QString temp = dst;
       Convert_CRLF_To_BR(temp, dst);
      }
   }
}
//------------------------------ get_FamilleGenreClasse --------------------------------------------------
/*! \brief Teste l'ATCD et renvoie le nom de la rubrique auquel il appartient.
 *  \param  Atcd_Element& pAtcd : reference sur l'antecedent
*/
QString CGenTools::get_FamilleGenreClasse( const QString &familleGenre, const QString &code )
{ // Teste compatiblité ancienne version de rubriques Méd/Chir
  QString token = familleGenre.left(3).lower();
  if (code[0] == '(')
     { return  TR("Allergies");
     }
  else if (token == TR("méd"))
     { return TR("Médicaux");
     }
  else if (token == TR("fam"))
     { return TR("Familliaux");
     }
  else if (token == TR("soci"))
     { return TR("Sociaux");
     }
 else if (token == TR("gyn")|| token == TR("obs"))
     { return TR("Gynéco-obstétriques");
     }
 else if (token == TR("cogn"))
     { return TR("Cognitifs");
     }
  else if (token == TR("chir"))
     { return TR("Chirurgicaux");
     }
  else if (token.stripWhiteSpace().length() == 0)
     { return TR("Médicaux et Chirurgicaux");
     }
  return familleGenre;
}
/*------------------------------ resolvePath --------------------------------------------------------------------*/
/*! \brief resoud un chemin comportant les eventuelles macros $Glossaire $Vigie $ToAbsPath $EndToAbsPath par le chemin absolu
 *  \param pathFile :  QString chemin d'entree
 *  \return Renvoie le chemin modifie absolutise si necessaire
*/
QString CGenTools::resolvePath(QString pathFile, const QString &pathAppli, const QString &pathGlossaire)
{    pathFile = resolvePathKeyWord(pathFile, pathAppli, pathGlossaire);
     if ( QDir::isRelativePath ( pathFile ) ) pathFile  = QDir::cleanDirPath ( pathFile.prepend(pathAppli) );
     return pathFile;
}
/*------------------------------ resolvePathKeyWord --------------------------------------------------------------------*/
/*! \brief resoud un chemin comportant les eventuelles macros $Glossaire $Vigie $ToAbsPath $EndToAbsPath par le chemin absolu
 *  \param pathFile :  QString chemin d'entree
 *  \return Renvoie le chemin modifie absolutise que lors des mots clefs et UNIQUEMENT DANS CE CAS (utile lors arguments de programmes externes)
*/
QString CGenTools::resolvePathKeyWord(QString pathFile, const QString &pathAppli, const QString &pathGlossaire)
{    pathFile  = pathFile.stripWhiteSpace().replace("$Glossaire",pathGlossaire);
     pathFile  = pathFile.replace("$Vigie", pathGlossaire + "Vigie");
     //if (pathFile[1]==':') pathFile  = pathFile.replace (1, 1, '|' ); //proteger le : de  C:
     //if (pathFile.startsWith("//")) pathFile = QString("**") + pathFile.mid(2);  // prot�ger les doubles "//" du debut (cas des repertoires reseaux)
     //pathFile.replace("//","/");    pathFile.replace("*","/"); pathFile.replace("|",":");
     //............. gestion des motsclefs ..........
     int pos     = -1;
     int deb     = -1;
     QString tmp = "";
     if ((pos = pathFile.findRev("$EndToAbsPath")) != -1)
        {do
          { if ( (deb     = pathFile.findRev("$ToAbsPath"),pos) != -1)
               { pathFile = pathFile.remove(pos,13);   // virer le $EndToAbsPath
                 tmp      = QDir::cleanDirPath (pathAppli + pathFile.mid(deb+10, pos - deb -10).stripWhiteSpace());
                 pathFile = pathFile.replace (deb, pos - deb, tmp );
                 pos      = pathFile.findRev("$EndToAbsPath", deb);
               }
            else
               { pos = -1;
               }
          } while (pos != -1);
        }
     else if ( (pos = pathFile.find("$ToAbsPath")) != -1)
        { pathFile = pathFile.left(pos) + QDir::cleanDirPath (pathAppli + pathFile.mid(pos+10).stripWhiteSpace());
        }
     return pathFile;
}

/*------------------------------ Convert_CRLF_To_BR --------------------------------------------------------------------*/
int CGenTools::Convert_CRLF_To_BR(const char *text, QString &dstQStr, int flag /*=0*/)
{int nb_ligne = 0;
 char     *pt = (char*) text;
 //rQTextEdit   = "<html>";
 dstQStr   = "";
 while (*pt)
    { if (*pt=='\r' || *pt=='\n')
         {if (flag==0) dstQStr += "\n";
          else         dstQStr += "<br />";
          if      (*pt=='\r' &&  pt[1]=='\n' ) pt+=2;
          else if (*pt=='\n' &&  pt[1]=='\r' ) pt+=2;
          else                                 ++pt;
          nb_ligne++;
         }
     else
         {dstQStr += pt[0];
          ++pt;
         }
    }
 //rQTextEdit   += "</html>";
 return nb_ligne;
}

/*------------------------------ GetExtension --------------------------------------------------------------------------*/
/*! \brief Get the file name extension, return
 *
 *  - this framework contains on left:
 *         -# Buttons of each windows.
 *         -# and the Glossaire.
 *  - this framework contains on midle:
 *         -# all the specifics window's rubrics.
 */

QString CGenTools::GetExtension(QString &file,  int cut_to /* = -1 */)
{ // int pos = file.findRev('.');
  // if (pos!=-1) return  file.mid(pos, cut_to);
  // else         return(QString(""));
  QString ext = QFileInfo(file).extension();
  if (ext.length() == 0)  return(QString(""));
  ext = ext.prepend(".");
  if (cut_to == -1 ) return ext;
  ext.truncate(cut_to);
  return ext ;
}


//---------------------------- DialogGetString -----------------------------------------------
int CGenTools::DialogGetString(QWidget * parent, const char* title, QString &string, int x/*=0*/, int y /*=0*/)
{return DialogGetString("", parent, title, string, "",  x,  y );
}
//---------------------------- DialogGetString -----------------------------------------------
int CGenTools::DialogGetString(QString message, QWidget * parent, const char* title, QString &string, QString mimeSourceFactoryPath /* = QString::null */, int x/*=0*/, int y /*=0*/)
{ int               ret = QDialog::Rejected;
  if (message.startsWith("$File"))
     {message = message.remove("$File");
      message = message.stripWhiteSpace();
      if (message.startsWith(":")) message = message.mid(1);
      if (mimeSourceFactoryPath.length()==0) mimeSourceFactoryPath = QFileInfo(message).dirPath();
      QString path = message;
      CGestIni::Param_UpdateFromDisk(path, message);
     }
 FormDlgGetString *dlg = new FormDlgGetString(parent,"GetString_Dial", TRUE);
 if (dlg ==0) return QDialog::Rejected;
 if (message.length()) {if (mimeSourceFactoryPath.length()) dlg->textBrowserInfo->mimeSourceFactory()->addFilePath(mimeSourceFactoryPath);
                        dlg->textBrowserInfo->setText(message);
                       }
 else                  {dlg->textBrowserInfo->hide();
                       }
 if (x && y)  dlg->move (  x, y );
 dlg->setCaption(title);
 dlg->lineEditString->setText(string);
 dlg->lineEditString->setFocus();
 ret = dlg->exec();
 if (ret == QDialog::Accepted)
    {string = dlg->lineEditString->text();
    }
 delete dlg;
 return ret;
}

//-------------------------------- MessageAlert -------------------------------------------------------------------------
int CGenTools::MessageAlert(QWidget * parent, const char* title, const char* message, const char* button1, const char* button2,const char* button3,const char* button4, int w , int h, const QString &mimeSourceFactoryPath )
{FormDlgMyMessageBox *dlg = new FormDlgMyMessageBox(parent,"Alert_Dial",TRUE);   // TRUE Pour modal
 if (dlg ==0) return -1;
 dlg->pushButton1->setShown(FALSE);
 dlg->pushButton2->setShown(FALSE);
 dlg->pushButton3->setShown(FALSE);
 dlg->pushButton4->setShown(FALSE);

 if (title)    dlg->setCaption(title);
 if (mimeSourceFactoryPath.length()) dlg->textEditMesage->mimeSourceFactory()->addFilePath(mimeSourceFactoryPath);
 if (message)  dlg->textEditMesage->setText(message);
 if (button1 && button1[0]) {dlg->pushButton1->setShown(TRUE);dlg->pushButton1->setText(button1);}
 if (button2 && button2[0]) {dlg->pushButton2->setShown(TRUE);dlg->pushButton2->setText(button2);}
 if (button3 && button3[0]) {dlg->pushButton3->setShown(TRUE);dlg->pushButton3->setText(button3);}
 if (button4 && button4[0]) {dlg->pushButton4->setShown(TRUE);dlg->pushButton4->setText(button4);}
 QSize s = dlg->size();   // store size
 if ( w == -1 )  w = 480;
 if ( h == -1 )  h = 230;

 dlg->resize(QSize(w,h));
 int ret = dlg->exec();

 delete dlg;
 return ret;
}
//-------------------------------- MyMessageAlert -------------------------------------------------------------------------
int CGenTools::MyMessageAlert(QWidget * parent, const char* title, const QString& mimeSourceFactoryPath, const char* message, const char* button1, const char* button2,const char* button3,const char* button4)
{FormDlgMyMessageBox *dlg = new FormDlgMyMessageBox(parent,"Alert_Dial",TRUE);   // TRUE Pour modal
 if (dlg ==0) return -1;
 dlg->pushButton1->setShown(FALSE);
 dlg->pushButton2->setShown(FALSE);
 dlg->pushButton3->setShown(FALSE);
 dlg->pushButton4->setShown(FALSE);

 if (title)    dlg->setCaption(title);
 if (mimeSourceFactoryPath.length()) dlg->textEditMesage->mimeSourceFactory()->addFilePath(mimeSourceFactoryPath);
 if (message)  dlg->textEditMesage->setText(message);
 if (button1) {dlg->pushButton1->setShown(TRUE);dlg->pushButton1->setText(button1);}
 if (button2) {dlg->pushButton2->setShown(TRUE);dlg->pushButton2->setText(button2);}
 if (button3) {dlg->pushButton3->setShown(TRUE);dlg->pushButton3->setText(button3);}
 if (button4) {dlg->pushButton4->setShown(TRUE);dlg->pushButton4->setText(button4);}

 int ret = dlg->exec();

 delete dlg;
 return ret;
}

//---------------------------- qstringLoad -------------------------------------------------
QString CGenTools::qstringLoad(const char *path, int flag/*=0*/, long *nb_ligne/*=0*/)
{QString string = "";
 QString text   = "";
 CGestIni::Param_UpdateFromDisk(path, text);
 if (text.length() <=0) return text;
 if (flag&CR_TO_HTML)
    {if (text.left(6) == "<html>") return text;
     char *pt=(char*)(const char*)text;
     while (*pt)
           { if (*pt=='\r' || *pt=='\n')
                {string += "\n";
                 if      (*pt=='\r' &&  pt[1]=='\n' ) pt+=2;
                 else if (*pt=='\n' &&  pt[1]=='\r' ) pt+=2;
                 else                                 ++pt;
                 if (nb_ligne) (*nb_ligne) ++;
                 string += "<br />";
                }
             else
                {string += pt[0];
                 ++pt;
                } //end if (*pt=='\r' || *pt=='\n')
           }
     return string;
    }
 else
    {return text;
    }
}

//---------------------------- NbLignes -------------------------------------------------
int  CGenTools::NbLignes(const char *txt)
{int nb_lignes = 0;
 char      *pt = (char*)txt;
 while (*pt)
    {if (*pt=='\r' || *pt=='\n')
         {if      (*pt=='\r' &&  pt[1]=='\n' ) pt+=2;
          else if (*pt=='\n' &&  pt[1]=='\r' ) pt+=2;
          else                                 ++pt;
          ++nb_lignes;
         }
     else
         {++pt;
         }
    }
 return nb_lignes;
}

//------------------------------------------ daysTo -------------------------------------------------
/*! \brief Retourne le nombre de jours entre la date1 et la date2 */
QString CGenTools::daysTo(const QString &date1, const QString &date2)
{QDate d2 = QDate::currentDate();
 if (date2.length()!=0) d2 = QDate::fromString (NormaliseDate(date2), Qt::ISODate );
 QDate d1 = QDate::fromString (NormaliseDate(date1), Qt::ISODate );
 return QString::number( d1.daysTo ( d2 ) );
}

//------------------------------------------ strToIsoStrDateTime -----------------------------
/*! \brief Retourne une chaine de la forme 12x09xx2007 à l'heure de 12h30 sous forme 2007-09-12T12:30:00 */
QString CGenTools::strToIsoStrDateTime(const QString &date, QString *pDate  /* =0 */, QString *pTime  /* =0 */)
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
 if (len <8 )   return TR("strToIsoStrDateTime() format invalide");
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
//------------------------------------------ NormaliseDate -----------------------------
/*! \brief Retourne une date de la forme 12x09xx2007 sous forme 2007-09-12 */
QDate CGenTools::dd_MM_yyyy_ToDate(const QString &date)
{return QDate::fromString(NormaliseDate(date), Qt::ISODate);
}
//------------------------------------------ NormaliseDate -----------------------------
/*! \brief Retourne une date de la forme 12x09xx2007 sous forme 2007-09-12 */
QString CGenTools::dd_MM_yyyy_ToIso(const QString &date)
{return NormaliseDate(date);
}
//------------------------------------------ NormaliseDate -----------------------------
/*! \brief Retourne une date de la forme 12x09xx2007 sous forme 2007-09-12 */
QString CGenTools::NormaliseDate(const QString &date)
{int end = date.length();
 int   i = -1;
 QString str;
 while (++i < end) {
                     if (  (date[i]>='0' && date[i]<='9') ) str += date[i];
                   }
 if (str.length() ==6 )  str.insert ( 4, "20" ); // date forme 011207 --> 01122007
 if (str.length() !=8 )  return TR("format invalide");

 return str.mid(4,4)+"-"+str.mid(2,2)+"-"+str.mid(0,2);
}

//---------------------------------------- setDateTimeNatural_jjMMyyyy_Order ---------------------------------------
QDateTime CGenTools::setQDateTime(const QString & dateTime , int &isValid)
{ int i= 0, len   = dateTime.length();
  isValid     = 0;
  QString str = "";
  for (i= 0; i<len; ++i)
      {if (dateTime.at(i)>='0' && dateTime.at(i)<='9') str += dateTime.at(i);
      }
  QString date  = str.left(8);
  QString heure = str.mid(8);
  return QDateTime (setDate( date ,  isValid) , setTime( heure , isValid));
}
//---------------------------------------- setDate ---------------------------------------
QDate CGenTools::setDate(const QString & date_in , int &isInvalid)
{ int i= 0, len = date_in.length();
  isInvalid  &= ~2;
  QString str = "";
  for (i= 0; i<len; ++i)
      {if (date_in.at(i)>='0' && date_in.at(i)<='9') str += date_in.at(i);
      }
  QString date  = str.left(8);
  int jour      = date.mid(0,2).toInt();
  int mois      = date.mid(2,2).toInt();
  int annee     = date.mid(4,4).toInt();
  if (QDate::isValid ( annee, mois, jour ) )
     {return QDate(annee, mois, jour);
     }
  isInvalid |= 2;
  return QDate::currentDate();
}
//---------------------------------------- setTime ---------------------------------------
QTime CGenTools::setTime(const QString & heure , int &isInvalid)
{ int h=0; int m=0; int s=0; int ms=0; int i= 0, len = heure.length();
  isInvalid &= ~1;
  QString str = "";
  for (i= 0; i<len; ++i)
      {if (heure.at(i)>='0' && heure.at(i)<='9') str += heure.at(i);
      }
  len = str.length();
  if (len>=2) h  = str.mid(0,2).toInt(); // hh
  if (len>=4) m  = str.mid(2,2).toInt();  // hhmm
  if (len>=6) s  = str.mid(4,2).toInt();  // hhmmss
  if (len>=9) ms = str.mid(6).toInt();    // hhmmss
  if (QTime::isValid ( h, m, s, ms  ) )
     { return QTime( h,  m,  s,  ms);
     }
  isInvalid |= 1;
  return QTime::currentTime ();
}
//------------------------------------------------ GetXMLValue --------------------------------------------------------
 /*! \brief retourne les donnees d'un tag XML */
   // ACTION extrait la valeur contenue entre deux balises XML
// ENTREE : const QString &dataToExamine : texte a analyser
//          const QString &xmlToken : token de la balise XML doit �re de  la forme : "<xxxxxxxxxx>"
//          QString &valueToGet     : QString dans laquelle d�oser le r�ultat
//          int pos /* = -1 */   : position �laquelle rechercher la recherche si -1 (valeur par d�aut) la recherche se fait �partir du d�ut
//                                 si l'on est certain que les tokens sont ordonn� alors l'on peut se servr du retour de la fonction
//                                 pour positionner pos de fa�n �acc��er le traitement.
// RETOUR : int position situ� apr� le token fermant, permet d'avancer sur le token suivant.

int  CGenTools::GetXMLValue(const QString &dataToExamine, const QString &xmlToken_in, QString &valueToGet, int pos , QString *p_LastErr /*=0*/)
{valueToGet       = "";
 QString xmlToken = xmlToken_in;
 int deb = dataToExamine.find(xmlToken, pos);
 if (deb == -1) {if(p_LastErr) *p_LastErr = TR("ERREUR CGenTools::GetXMLValue() Mention de début manquante : \"" + xmlToken + "\""); return -1;}
 deb += xmlToken.length();
 int end = dataToExamine.find(xmlToken.insert(1,"/"), deb);
 if (end == -1) {if(p_LastErr) *p_LastErr = TR("ERREUR CGenTools::GetXMLValue() Mention de  fin  manquante : \"" + xmlToken +"\"");  return -1;}
 valueToGet = dataToExamine.mid(deb , end - deb );
 return end + xmlToken.length();
}
