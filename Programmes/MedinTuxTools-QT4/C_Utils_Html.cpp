#include "C_Utils_Html.h"
#include <QNetworkCookie>
#include <QByteArray>
#include <QTextStream>
#include <QList>
#include <QTextEdit>
#include <QApplication>
#include <QObject>
#include <QDir>
#include <QFileInfo>
#include <QProgressBar>
#include <QStringList>

#include "C_Utils_Log.h"
#include "CGestIni.h"

#define   TR QObject::tr

  //===================================================== CookieJar ===================================================================================
  //---------------------------------------  CookieJar ---------------------------------------------------------
  CookieJar::CookieJar (QString path, QObject *parent /* = 0*/, QTextEdit *pQTextEditLog /*=0 */) : QNetworkCookieJar(parent), C_Log(pQTextEditLog)  //on preds en argument le nom du fichier ou l'on doit sauver/charger les cookies
  {   m_file      = path; //on stocke le nom de ce fichier
      QFile cookieFile(m_file);
      if (cookieFile.exists() && cookieFile.open(QIODevice::ReadOnly) )  //si on peut l'ouvrir...
      {
          outMessage( TR("Start -------- CookieJar List -------------"));
          QList<QNetworkCookie> list;  //on crée une liste vide de cookies
          QByteArray line; //on crée une ligne vide ( ça serviera de mémoire-tampon)
          while(!(line = cookieFile.readLine()).isNull()) //tant qu'on a pas tout lu dans notre fichier...
          {   QString str = line; str.replace('\r','\n'); if (str.endsWith("\n")) str.truncate(str.length()-1);  // virer le dernier retour chariot
              outMessage( TR(".   CookieJar <b>") +  str +  TR("</b>"));
              list.append(QNetworkCookie::parseCookies(line)); //on parse la ligne en cours pour en faire une cookie qu'on ajoute à notre liste
          }
          outMessage( TR("End -------- CookieJar List -------------"));
          setAllCookies(list); //et on charge notre liste <IMG src="http://s1.wp.com/wp-includes/images/smilies/icon_wink.gif?m=1235253170g" alt=";-)" class="wp-smiley">
      }
      else  //si on ne paut pas ouvrir le fichier...
      {
          outMessage( TR("WARNING : CookieJar:: can't open  <b>") +  m_file +  TR("</b> for reading cookies !"));
      }

  }

  //---------------------------------------  ~CookieJar ---------------------------------------------------------
  CookieJar::~CookieJar () //destructeur; sauvegarde les cookies
  {
          QList <QNetworkCookie> cookieList;  //on crée une liste de cookies...
          cookieList = allCookies();          //...et on la remplit de toutes nos cookies
          QFile file(m_file);

          if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
          {
                  outMessage( TR("WARNING : CookieJar:: can't open  <b> ") + m_file + TR(" for writing cookies !"));
                  return;
          }

          QTextStream out(&file); //sinon, on crée un flux à partir de notre fichier...

          for(int i = 0 ; i < cookieList.size() ; i++) //... et pour chaque cookie qu'on possède...
          {
                  QByteArray line =  cookieList.at(i).toRawForm(QNetworkCookie::Full); //...on récupère les données brutes de la cookie...
                  out << line << "\n"; //...et on les mets dans le fichier !
                  //NB: n'e pas oublier le \n pour sauter une ligne entre les cookies: sinon ça marche pas ! /
          }

          file.close(); //on ferme le fichier
  }

  //---------------------------------------  CookieJar ---------------------------------------------------------
  QList<QNetworkCookie> CookieJar::cookiesForUrl ( const QUrl & url ) const //est utilisé par le QNetworkManager
  {
      return QNetworkCookieJar::cookiesForUrl(url); //on ne touche pas
  }

  //---------------------------------------  CookieJar ---------------------------------------------------------
  bool   CookieJar::setCookiesFromUrl ( const QList<QNetworkCookie> & cookieList, const QUrl & url ) //est utilisé par le QNetworkManager
  {
      return QNetworkCookieJar::setCookiesFromUrl(cookieList, url); //on ne touche pas
  }


//================================================================ C_Utils_Html ==========================================================
//---------------------------------------  C_Utils_Html ---------------------------------------------------------
C_Utils_Html::C_Utils_Html(QObject *parent /* =0 */, QNetworkAccessManager *pQNetworkAccessManager /* =0 */, QTextEdit *pQTextEditLog /*=0 */ )
        : QObject(parent), C_Log(pQTextEditLog)
{m_LastError               = "";
 m_Wait_HttpProcess        = 0;
 m_position                = 0;
 m_pQProgressBar           = 0;
 //m_EndWaitHttpProcess      = 100000000;
 m_pQNetworkAccessManager  = pQNetworkAccessManager;
 m_QByteArray.clear();
}

//---------------------------------------  makeLinkList ---------------------------------------------------------
/*! \brief add link chapiter list to html text with structure
    as 1        for chapiter one
    as 1.1      for sub chapiter one
    as 1.1.1    for sub sub chapiter one  an so
 *  \param const QString txt input html text
 *  \param const QString prefix caracters before chapiter number line
 *  \param const QString endfix caracters after chapiter number line
 *  \return QString result whith anchor, links, and chapiters list link
 */

QString  C_Utils_Html::makeLinkList(const QString &txt, const QString prefix, const QString endfix, const QString idAnchor /* = "" */)
{   QStringList chapSegmt;
    int   i          =  0;
    int oldPos       =  0;
    int pos          =  0;
    int end          = -1;
    QString anchor   = "";
    QString line     = "";
    QString numChap  = "";
    QString linkList = "";
    QString result   = "";

    while ( (pos     = txt.indexOf(prefix , pos, Qt::CaseInsensitive)) != -1 )
    {i     = 0;
     pos  += prefix.length();
     if (endfix=="EOL")
        {end   = txt.indexOf('\n' , pos, Qt::CaseInsensitive);
         if (end==-1) end = txt.indexOf('\r' ,   pos, Qt::CaseInsensitive);
         if (end==-1) end = txt.indexOf("<br>" , pos, Qt::CaseInsensitive);
        }
     else
         {end   = txt.indexOf(endfix , pos, Qt::CaseInsensitive);
         }
     if (end==-1)                           continue;
     line = txt.mid(pos, end-pos).remove('\r').remove('\n').trimmed();
     if ( !((line[i]>='0' && line[i]<='9')|| line[i]=='*')) continue;            // si premier car n'est pas un chiffre reboucler
     if ( (i = line.indexOf(' '))==-1)      continue;            // avancer jusqu'au prochain espace et si pas trouve reboucler

     numChap = line.left(i);
     if (! (numChap.contains('.')|| numChap.contains('*')))            continue;            // si pas au moins 1 point on reboucle
     for (i=0;i<numChap.length();++i)                            // verifier si ne contient que . et 0 <--> 9
         {if ( ! (line[i]=='.' || (line[i]>='0' && line[i]<='9') || line[i]=='*') ) break;
         }
     if (i<numChap.length())                continue;            // si autre caractere que . et 0 <--> 9 reboucler

     //<a name="ancrage"></A>Point d'ancrage<br><br>
     //<a href="#ancrage">Vers le point d'ancre ci-dessus</A>
     chapSegmt  = numChap.split ('.', QString::SkipEmptyParts);
     result    += txt.mid(oldPos, pos-oldPos);
     anchor     = QString("<h%3 class=titre_resume><a name=\"%4_%1\">%2</a></h%3>\n").arg(line,line,QString::number(chapSegmt.count()),idAnchor);
     if (chapSegmt.count()==1) anchor = anchor.prepend("<b>").append("</b>");
     if (chapSegmt.count()==2) anchor = anchor.prepend("<b>").append("</b>");
     result    += anchor;
     linkList.append(QString("<a href=\"#%3_%1\">%2</a><br>").arg(line,line,idAnchor));      // <a name="smr0"></a>
     oldPos = end; while( oldPos<txt.length() && (txt[oldPos]=='\n'||txt[oldPos]=='\r') )++oldPos;       // on se place apres le titre
    }

    if(linkList.length())
      {result += txt.mid(oldPos);
       result  = result.prepend(linkList+"<hr>");
       return result;
      }
    else
      {return txt;
      }
}

//---------------------------------------  removeHtmlTag ---------------------------------------------------------
QString  C_Utils_Html::removeHtmlTag(const QString text){return C_Utils_Log::removeHtmlTag(text);}

//------------------------------------ saveImagesFromTag -------------------------------
/*! \brief download alls distants datas from tag and attribut tag where attributs datas represents url
 *  \param const QString& html :     page to analyse where find tags and attributs
 *  \param const QString& url :      base page url
 *  \param const QString &imageDir : directory where datas must be downloaded
 *  \param const QString &tag :      tag to find
 *  \param const QString &attribut : attribut of the tag where is data url
 *  \return   number of data found
 */
int C_Utils_Html::saveImagesFromTag(const QString& html, const QString& url_in, const QString &imageDir, const QString &tag, const QString &attribut)
{   int                   i = 0;
    QStringList      imgList;
    QByteArray            ba;
    QString          fileName = "";
    QString       distantFile = "";
    QString              url  = url_in; if ( (i=url.lastIndexOf('/'))!= -1) url.truncate(i);  // normaliser l'url au repertoire (cas ou elle donne avec nom de fichier)

    getImagesList( html, tag,attribut, imgList);
    for (i=0; i<imgList.count(); ++i)
        {//outMessage( TR("For tag :'%1' image : '%2'").arg("td",imgList[i]) );
         fileName = imageDir + QFileInfo(imgList[i]).fileName();
         if (!QFile::exists(fileName))
            {distantFile = url+"/"+imgList[i];
             if      (distantFile.startsWith("http://"))  distantFile = QString("http://")  + QDir::cleanPath(distantFile.mid(7));
             else if (distantFile.startsWith("https://")) distantFile = QString("https://") + QDir::cleanPath(distantFile.mid(8));
             QStringList rawHeadersList;
             ba = getDataFromUrl(distantFile, rawHeadersList);
              //outMessage( tr(".    Images distantes: %1").arg(url+"/"+imgList[i]));
              if (!ba.isEmpty())
                 {CGestIni::Param_UpdateToDisk(fileName, ba);
                  //outMessage( tr(".    Images locales: %1").arg(fileName));
                 }
            }
        }
 return i;
}
//---------------------------------------  postDataFromUrl ---------------------------------------------------------
/*! \brief uploag and post distants datas from url
 *  \param const QString &url :                                url where post data
 *  \param const QString &postData :                           data to post
 *  \param QNetworkAccessManager *pQNetworkAccessManager :     manager
 *  \return   data in a QByteArray
 */
bool C_Utils_Html::postDataFromUrl(const QString &url, const QString &postData,  const QStringList& rawHeaders, QNetworkAccessManager *pQNetworkAccessManager /* = 0*/)
{if (pQNetworkAccessManager) m_pQNetworkAccessManager = pQNetworkAccessManager;
 if (m_pQNetworkAccessManager == 0 ){outMessage( tr("ERREUR : postDataFromUrl() net work manager not initialized ")); return FALSE;}
 beginPost_FromUrl(url, postData, rawHeaders);
 while (m_Wait_HttpProcess){qApp->processEvents(); /*--m_Wait_HttpProcess;*/}
 return TRUE;
}
//--------------------------- beginPost_FromUrl -----------------------------------------------------------
void C_Utils_Html::beginPost_FromUrl(const QString &url, const QString &postData, const QStringList& rawHeaders)
{   m_Wait_HttpProcess = m_EndWaitHttpProcess;
    m_LastError   = "";
    if (m_pQProgressBar)   {m_position = 0;  m_pQProgressBar->setRange(0,0);  }
    disconnect(m_pQNetworkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(Slot_DataLoadFinished(QNetworkReply*)));
    connect(m_pQNetworkAccessManager,    SIGNAL(finished(QNetworkReply*)), this, SLOT(Slot_DataPostFinished(QNetworkReply*)));
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    for (int i=0; i<rawHeaders.count(); ++i)
        {QString     rawH = rawHeaders[i];
         QStringList list = rawH.split('|');
         request.setRawHeader(list[0].toAscii(), list[1].toAscii());
        }
    if (rawHeaders.count()==0) request.setRawHeader("User-Agent", "Free-for-all");
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    m_pQNetworkAccessManager->post(request, postData.toUtf8());
}
//--------------------------- Slot_DataPostFinished -----------------------------------------------------------
void   C_Utils_Html::Slot_DataPostFinished(QNetworkReply *pQNetworkReply) //QNetworkReply::NoError
{if (pQNetworkReply->error()!= QNetworkReply::NoError) m_LastError = pQNetworkReply->errorString();
 if (m_LastError.length()) outMessage( tr("ERREUR : postDataFromUrl() <br> %1 ").arg(m_LastError));
 disconnect(m_pQNetworkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(Slot_DataPostFinished(QNetworkReply*)));
 disconnect(m_pQNetworkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(Slot_DataLoadFinished(QNetworkReply*)));
 m_Wait_HttpProcess = 0;
 if (m_pQProgressBar)  {m_pQProgressBar->setRange(0,100); m_pQProgressBar->setValue(0); m_pQProgressBar->reset();}
}

//---------------------------------------  getDataFromUrl ---------------------------------------------------------
/*! \brief download distants datas from url
 *  \param const QString &url :                                url where get data
 *  \param QNetworkAccessManager *pQNetworkAccessManager :     manager
 *  \return   data in a QByteArray
 */
QByteArray  C_Utils_Html::getDataFromUrl(const QString &url, const QStringList& rawHeaders, QNetworkAccessManager *pQNetworkAccessManager /* = 0*/)
{ m_QByteArray.clear();
  if (pQNetworkAccessManager) m_pQNetworkAccessManager = pQNetworkAccessManager;
  if (m_pQNetworkAccessManager == 0 ){outMessage( tr("ERREUR : getDataFromUrl() net work manager not initialized ")); return m_QByteArray;}
  beginGet_FromUrl(url, rawHeaders);
  while (m_Wait_HttpProcess){qApp->processEvents(); /*--m_Wait_HttpProcess;*/}
  return m_QByteArray;
}
//---------------------------------------  beginGet_FromUrl ---------------------------------------------------------
void  C_Utils_Html::beginGet_FromUrl(const QString &url, const QStringList& rawHeaders)
{ m_Wait_HttpProcess = m_EndWaitHttpProcess;
  m_LastError   = "";
  if (m_pQProgressBar)   {m_position = 0;  m_pQProgressBar->setRange(0,0);  }
  m_QByteArray.clear();
  disconnect(m_pQNetworkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(Slot_DataPostFinished(QNetworkReply*)));
  connect(m_pQNetworkAccessManager,    SIGNAL(finished(QNetworkReply*)), this, SLOT(Slot_DataLoadFinished(QNetworkReply*)));
  QNetworkRequest request;
  request.setUrl(QUrl(url));
  for (int i=0; i<rawHeaders.count(); ++i)
      {QString     rawH = rawHeaders[i];
       QStringList list = rawH.split('|');
       request.setRawHeader(list[0].toAscii(), list[1].toAscii());
      }
  if (rawHeaders.count()==0) request.setRawHeader("User-Agent", "Free-for-all");
  m_pQNetworkAccessManager->get(request);
}
//--------------------------- Slot_DataLoadFinished -----------------------------------------------------------
void   C_Utils_Html::Slot_DataLoadFinished(QNetworkReply *pQNetworkReply)
{ if (pQNetworkReply->open(QIODevice::ReadOnly))
  if (pQNetworkReply->error()!= QNetworkReply::NoError) m_LastError = pQNetworkReply->errorString();
  if (m_LastError.length()) outMessage( tr("ERREUR : getDataFromUrl() <br> %1 ").arg(m_LastError));
  if (pQNetworkReply->open(QIODevice::ReadOnly))
     {m_QByteArray  = pQNetworkReply->readAll();
      pQNetworkReply->close();
      //CGestIni::Param_UpdateToDisk("/home/ro/array.html", m_QByteArray);   // ok encodage utf8 correct
     }
  disconnect(m_pQNetworkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(Slot_DataPostFinished(QNetworkReply*)));
  disconnect(m_pQNetworkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(Slot_DataLoadFinished(QNetworkReply*)));
  m_Wait_HttpProcess = 0;
  if (m_pQProgressBar)  {m_pQProgressBar->setRange(0,100); m_pQProgressBar->setValue(0); m_pQProgressBar->reset();}
}

//---------------------------------- getImagesList ---------------------------------------------------------------------------
/*! \brief extract alls images tags from a thml text
 *  \param QString &txt:           text to examine
 *  \param const QString &tag      tag to find
 *  \param const QString attribut  attribut where image name is (to change origin string before image.name )
 *  \param QStringList &imgList    list to fill
 *  \param long from:              position to begin
 *  \return   if negative error or not image tag, if not negative, next position (after tag)
 */

long C_Utils_Html::getImagesList( const QString &txt, const QString &tag, const QString attribut, QStringList &imgList, long from /* = 0 */)
{//<img align=BOTTOM border=0 height=48 name=Image1 src=ccam_view_icn.png width=48 >

 QString fileName;
 long      i   = 0;
 long deb_tag;
 while (from>=0 && from<(long)txt.length())
    {deb_tag     = isThisTagImage(txt, tag, attribut, from , &fileName ); // en entrée nameFind = "" car on recherche toutes les ancres
     if (deb_tag>=0)
        {fileName.replace("&gt;",">");
         fileName.replace("&lt;","<");
         fileName.replace("../","_._._/"); fileName.remove("./");fileName.replace("_._._/","../");
         imgList.append(fileName);
         ++i;
        }
    } //end while (from>=0 && from<txt.length())     essai2.html
 imgList.removeDuplicates();
 return i;
}

//------------------------------------------ isThisTagImage ------------------------------------------------------
/*! \brief analyse a tag and if a image tag return it's url in (QString *fileName if not zero)
 *  \param QString &txt:           text to examine
 *  \param const QString &tag      tag to find
 *  \param const QString attribut  attribut where image name is (to change origin string before image.name )
 *  \param long from:              position to begin
 *  \param QString *fileName:      if not zero, image url is returned in the QString pointed
 *  \param int *w:                 if not zero, image width is returned in the int pointed
 *  \param int *h:                 if not zero, image height is returned in the int pointed
 *  \return   if negative: error or not image tag, if not negative: next position (after tag)
 */
// <img align=BOTTOM border=0 height=48 name=Image1 src=ccam_view_icn.png width=48 >
long C_Utils_Html::isThisTagImage(const QString &txt, const QString &tag, const QString attribut, long &from , QString *fileName /* = 0 */ , int *w /* = 0 */, int *h /* = 0 */)
{long deb_file;
 long deb_tag;
 long end_tag;
 //char *pt_deb;
 //char *pt_end;
 //........... rechercher debut du tag .........................
 from     = txt.indexOf(QString("<")+tag+" " , from, Qt::CaseInsensitive);   // FALSE pour case insensitive
 if (from==-1)        {from = txt.length();        return -1;}
 deb_tag  = from;
 //........... rechercher fin du tag ...........................
 from    += tag.length()+2;    // passer < et le tag et l'espace
 end_tag  = txt.indexOf('>', from);
 if (end_tag==-1)                                  return -3;                    // erreur  -3 de syntaxe fin de tag '>' non trouvée

 int pos;
 //........... rechercher src ..................................
 if (fileName && (pos = txt.indexOf(attribut, from, Qt::CaseInsensitive)) != -1 && pos<end_tag)
    { //........... extraire nom du fichier image ...................
      pos += attribut.length();
      while (pos<end_tag && (txt.at(pos)==' ' || txt.at(pos)=='\t' || txt.at(pos)=='='))  ++pos;
      if (txt.at(pos)=='\"')
         {++pos;
          deb_file = pos;
          while (pos<end_tag &&  txt.at(pos)!='\"' && txt.at(pos)!=';')     ++pos;
         }
      else
         { deb_file = pos;
           while (pos<end_tag && txt.at(pos)!=' ' && txt.at(pos)!='\t' && txt.at(pos)!='\"' && txt.at(pos)!=';')     ++pos;
         }
      *fileName = txt.mid(deb_file, pos - deb_file);
    }
 //........... rechercher width ..................................
 if (w && (pos = txt.indexOf("width", from, Qt::CaseInsensitive)) != -1 && pos<end_tag)
    { //........... extraire nom du fichier image ...................
      pos += 5;
      while (pos<end_tag && (txt.at(from)==' ' || txt.at(from)=='\t'|| txt.at(pos)=='\"' || txt.at(pos)=='='))  ++pos;
      deb_file = pos;
      while (pos<end_tag && txt.at(pos)!=' ' && txt.at(pos)!='\t' && txt.at(pos)!='\"' && txt.at(pos)!=';')     ++pos;
      *w = txt.mid(deb_file, pos - deb_file).toInt();
    }
 //........... rechercher height ..................................
 if (h && (pos = txt.indexOf("height", from, Qt::CaseInsensitive)) != -1 && pos<end_tag)
    { //........... extraire nom du fichier image ...................
      pos += 6;
      while (pos<end_tag && (txt.at(from)==' ' || txt.at(from)=='\t'|| txt.at(pos)=='\"' || txt.at(pos)=='='))  ++pos;
      deb_file = pos;
      while (pos<end_tag && txt.at(pos)!=' ' && txt.at(pos)!='\t' && txt.at(pos)!='\"' && txt.at(pos)!=';')     ++pos;
      *h = txt.mid(deb_file, pos - deb_file).toInt();
    }
 from = end_tag+1;
 return deb_tag;
}

//---------------------------------- setTagAttributeValue ---------------------------------------------------------------------------
/*! \brief extract alls tags from a thml text
 *  \param QString &txt:                        text to examine
 *  \param const QString &tag                   tag to find
 *  \param const QString attribut               attribut where is data value to set
 *  \param const QString value                  value to place
 *  \param C_Utils_Html::AttributChange flag    if zero the entire data of attribut will be replaced by contents of value else just to change origin string before image.name)
 *  \param long  from:                          position to begin
 *  \return   if negative error or not image tag, if not negative, next position (after tag)
 */
long C_Utils_Html::setTagAttributeValue( QString &txt,
                                         const QString &tag,
                                         const QString &attribut,
                                         const QString &value,
                                         C_Utils_Html::AttributChange flag /* = 0 */,
                                         long from /* = 0 */
                                       )
{return getTagList(txt,tag,0, from , value ,attribut , flag);
}

//---------------------------------- getTagList ---------------------------------------------------------------------------
/*! \brief extract alls tags from a thml text
 *  \param QString &txt:               text to examine
 *  \param const QString &tag          tag to find
 *  \param QStringList &tagList        list to fill
 *  \param long from:                  position to begin
 *  \param const QString value         is just for img tag (to change origin string before image.name )
 *  \param const QString attribut      attribut where image name is (to change origin string before image.name )
 *  \param C_Utils_Html::AttributChange flag   if one the entire data of attribut will be replaced by contents of value else just to change origin string before image.name)
 *  \return   if negative error or not image tag, if not negative, next position (after tag)
 */
long C_Utils_Html::getTagList( QString &txt,
                               const QString &tag,
                               QStringList *tagList,
                               long from /* = 0 */,
                               const QString &value /*=""*/,
                               const QString &attribut /*=""*/ ,
                               C_Utils_Html::AttributChange flag /* = 0 */)
{//<img align=BOTTOM border=0 height=48 name=Image1 src=ccam_view_icn.png width=48 >

 QString tagData;
 long      i   = 0;
 long deb_tag;
 while (from>=0 && from<(long)txt.length())
    {deb_tag     = indexOfTag(txt, tag, from , value, attribut, flag);
     if (deb_tag>=0)
        {tagData = txt.mid(deb_tag,from-deb_tag);
         tagData.replace("&gt;",">");
         tagData.replace("&lt;","<");
         if (tagList) tagList->append(tagData);
         ++i;
        }
    } //end while (from>=0 && from<txt.length())     essai2.html
 if (tagList) tagList->removeDuplicates();
 return i;
}
//------------------------------------------ indexOfTag ------------------------------------------------------
/*! \brief analyse a tag and if a image tag return it's url in (QString *fileName if not zero)
 *  \param QString &txt:               text to examine
 *  \param const QString &tag          tag to find
 *  \param long from:                  position to begin (changed in position after tag at function end)
 *  \param const QString value         is just for img tag (to change origin string before image.name )
 *  \param const QString attribut      attribut where image name is (to change origin string before image.name )
 *  \param C_Utils_Html::AttributChange flag          if one the entire data of attribut will be replaced by contents of value else just to change origin string before image.name)
 *  \return   if negative: error or not tag, if not negative: start position of the tag.
 */
// <img align=BOTTOM border=0 height=48 name=Image1 src=ccam_view_icn.png width=48 >
long C_Utils_Html::indexOfTag(QString &txt,
                              const QString &tag,
                              long &from ,
                              const QString &value /*=""*/,
                              const QString &attribut  /*=""*/,
                              C_Utils_Html::AttributChange flag         /*=0 */)
{long deb_file;
 long deb_tag;
 long end_tag;
 QString strTag   = "";
 //........... rechercher debut du tag .........................
 from     = txt.indexOf(QString("<")+tag+" " , from, Qt::CaseInsensitive);   // FALSE pour case insensitive
 if (from==-1)        {from = txt.length();        return -1;}
 deb_tag  = from;
 //........... rechercher fin du tag ...........................
 from    += tag.length()+1;    // passer < et le tag et l'espace
 end_tag  = txt.indexOf('>', from);
 if (end_tag==-1)    {outMessage(tr("ERREUR in <b>'indexOfTag'<b> end symbol <b>'&gt;'</b> not found"), __FILE__, __LINE__);  return -3;}                    // erreur  -3 de syntaxe fin de tag '>' non trouvée
 ++end_tag;
 //................... filtrer selon tag (faut pas chipoter quand on trie) ................
 //                    traiter le cas particulier du changement du path de l'image

 if (value.length()==0)   return deb_tag;        // rien a relocaliser
 int           pos = -1;
 QString  fileName = "";
 QString  new_Name = "";
 int         delta = 0;
 strTag            = txt.mid(deb_tag, end_tag-deb_tag);
 if (    (pos = indexOfAttribut(txt, attribut, from, end_tag))    != -1 && pos<end_tag  )
    { //........... extraire nom du fichier image ...................
      pos += attribut.length();
      // outMessage(tr(" tag : ")+ strTag, __FILE__, __LINE__);
      while (pos<end_tag && (txt.at(pos)==' ' || txt.at(pos)=='\t' || txt.at(pos)=='='))  ++pos;
      if (txt.at(pos)=='\"')
         {deb_file = pos+1;
          pos      = C_Utils_Log::jumpEnclosedsSymbols(txt, pos, end_tag, "\"" )-1;   //-1 car faut pointer avant le guillemet
         }
      else
         { deb_file = pos;
           while (pos<end_tag && txt.at(pos)!=' ' && txt.at(pos)!='\t' && txt.at(pos)!='\"' && txt.at(pos)!=';')     ++pos;
         }
      fileName = txt.mid(deb_file, pos - deb_file);                  // recuperer l'ancien nom
      txt.remove(deb_file, pos - deb_file);                           // virer le nom

      if (flag==C_Utils_Html::SetAllJustDir)   new_Name = QFileInfo(fileName).fileName().prepend(value);  // calculer le nouveau nom de fichier
      else                                     new_Name = value;                                          // calculer la nouvelle valeur
      txt.insert(deb_file,new_Name);                                 // le mettre a la place de l'autre
      delta    = new_Name.length()-fileName.length();                // calcule du delta du nil
      // outMessage(tr(".        change : %1 in %2 ").arg(fileName, new_Name));
    }
 else
    { // outMessage(tr("Attribut <b>'%1'</b> not found in tag %3").arg(attribut,strTag), __FILE__, __LINE__);  return -4;
    }
 from = end_tag + delta;
 return deb_tag;
}

//------------------------------------------ indexOfAttribut ------------------------------------------------------
/*! \brief find the next attribut whith specific name in a tag
 *  \param QString &txt:                    text to examine
 *  \param const QString &attribut          attribut to find
 *  \param long from:                       position to begin
 *  \param long end:                        position to ended
 *  \return   if negative: error or not tag, if not negative: start position of the attribut.
 */
// <img align=BOTTOM border=0 height=48 name=Image1 src=ccam_view_icn.png width=48 >
long C_Utils_Html::indexOfAttribut(QString &txt,
                                   const QString &attribut,
                                   long &from,
                                   long   end)
{while(from<end)
    {QString toTest  = attribut.toUpper();
     long lenToTest  = toTest.length();
     if (txt.at(from)=='\"')
        {   from = C_Utils_Log::jumpEnclosedsSymbols(txt, from, end, "\"");
        }
     else if (txt.at(from)=='\\')
        {   from +=2;
        }
     else if ( txt.mid(from,lenToTest).toUpper()==toTest )
        {   return from;
        }
     ++from;
    }
 return -1;
}
//------------------------ htmlFind ------------------------------------------
/*! \brief find a text patern in a html document
 *  \param text :      const QString & html document where find text patern
 *  \param patern :    QString & text patern to find. If text patern == "FinDeLigne" or "EOL" the first end line tag is searched
 *  \param pos :       long &pos position where begin action
 *  \param debMotif :  long * pointer on long in which (if not egal zero) position after end patern will be returned (-1 if not found)
 *  \return -1 if not found, patern position if found.
*/
long C_Utils_Html::htmlFind(const QString &text, QString patern, long pos, long *debMotif /*=0*/, C_Utils_Html::flags flags /* = C_Utils_Html::withoutSpaces */)
{long len = text.length();
 if (len==0)        return -1;
 if (debMotif) *debMotif = -1;
 //.............. si il faut juste chercher la fin de la ligne ..................................
 if (patern=="FinDeLigne"||patern=="EOL")
    {while(pos<len)
           {if (text.at(pos)=='<' )
               {QChar c = text.at(pos+1).toUpper();  // premier caractere apres < (comme mis en majuscule et teste souvent on le fait ici)
                if (c=='B'&& text.at(pos+2).toUpper()=='R')
                   {int l = 0;
                    if (text.at(pos+3)=='>')                                             l = 4;  // variante
                    //else if (text[pos+3]==' '&& text[pos+4]=='/' && text[pos+5]=='>') l = 6;  // variante
                    if (l)
                       {if (debMotif) *debMotif = pos;
                        return         pos+l;
                       }
                   }
                else if (c=='P' && text.at(pos+2)=='>')               // <p>
                   {int l = 3;
                    if (l)
                       {if (debMotif) *debMotif = pos;
                        return         pos+l;
                       }
                   }
               }
            ++pos;
           }
     if (debMotif) *debMotif = pos;
     return pos;         // si pas de <br> ni <p> alors la fin de ligne est forcemeent la fin du texte
    }

 //.............. nettoyer le motif à comparer de tous les trucs non signifiant .................
 C_Utils_Html::htmlToAscii(patern);
 patern.remove((char)0xA0);
 if (flags==C_Utils_Html::withoutSpaces) patern.remove(' ');
 patern.remove('\t');
 patern.remove('\r');
 patern.remove('\n');
 int   carToCompareInMotif = 0;
 int   len_motif           =  patern.length();
 while (pos<len)
   {if (text.at(pos)=='<')
        {int l = 0;
         if (text.at(pos+1).toUpper()=='B'&& text.at(pos+2).toUpper()=='R')
            {if (text.at(pos+3)=='>')                                         l = 4;  // variante  <br>
             // if (text[pos+3]==' '&& text[pos+4]=='/' && text[pos+5]=='>')  l = 6;  // variante  <br />
            }
         if (text.at(pos+1).toUpper()=='P')
            {if (text.at(pos+2)=='>')                                         l = 3;  // variante  <p>
             //if (text[pos+2]==' '&& text[pos+3]=='/' && text[pos+4]=='>')  l = 5;  // variante  <p />
            }
         //.......... si tag  ou  la comparaison s'arrete car plus valide ...............................
         //           CAD on accepte des tags (exple couleur, fonte etc.) au milieu du texte a comparer
         //           ces tag doivent etre sautes sauf ceux de fin de ligne
         if (l)
            {pos                    += l;
             carToCompareInMotif     = 0;
             if (debMotif) *debMotif = -1;
            }
         else
         //.............. le tag est à sauter ...........................................................
            {pos = ifHtmlTagJumpIt(text,pos);          // sauter tag html
            }
        }
    else
        {QChar car = text.at(pos);
         if (car==0xA0) {car = 0x32; }
         if (car=='\r'||car=='\n'||car=='\t')                                      // sauter caractères non significatifs || car=='\t'
            {++pos;
            }
         if ( flags & C_Utils_Html::withoutSpaces && car==' ')                      // sauter les caractères non significatifs (ici les espaces ne sont pas evalues)
            {++pos;
            }
         else //................... là on peut comparer ...............................................
            {
                 if (debMotif && carToCompareInMotif==0) *debMotif = pos;
                 if (car=='&')   //............. convertir les caractères codés .........................
                    {if      (text.at(pos+1)=='g'&&text.at(pos+2)=='t'&&text.at(pos+3)==';')                                              {car = '>';          pos += 4;}
                     else if (text.at(pos+1)=='l'&&text.at(pos+2)=='t'&&text.at(pos+3)==';')                                              {car = '<';          pos += 4;}
                     else if (text.at(pos+1)=='a'&&text.at(pos+2)=='m'&&text.at(pos+3)=='p'&&text.at(pos+4)==';')                         {car = '&';          pos += 5;}
                     else if (text.at(pos+1)=='n'&&text.at(pos+2)=='b'&&text.at(pos+3)=='s'&&text.at(pos+4)=='p'&& text.at(pos+5)==';')   {car = ' ';          pos += 6;}
                     else if (text.at(pos+1)=='q'&&text.at(pos+2)=='u'&&text.at(pos+3)=='o'&&text.at(pos+4)=='t'&& text.at(pos+5)==';')   {car = '\"';         pos += 6;}
                     else                                                                                                                 {car = text.at(pos); pos += 1;}
                    }
                 else
                    {++pos;
                    }
                 if (car == patern[carToCompareInMotif])
                    {++carToCompareInMotif;
                     if (carToCompareInMotif >= len_motif) return pos;
                    }
                 else
                    {carToCompareInMotif     = 0;
                     if (debMotif) *debMotif = -1;
                    }
                }
        }
    }// end while (*pt && carToCompareInMotif < len_motif)
 return -1;
}

//------------------------------------------ ifHtmlTagJumpIt ------------------------------------------------------
/*! \brief jump a html tag in a html document
 *  \param text :      const QString & html document
 *  \param pos :       long &pos position where begin action must be just before the < start symbol tag
 *  \return position just after > end tag (if not found return position after last caracter of the text).
*/
long C_Utils_Html::ifHtmlTagJumpIt(const QString &text, long pos)
{long len = text.length();
 if (text.at(pos)=='<')
    {++pos;
     while (pos<len)
        {if (text.at(0)=='>') return pos+1;
         ++pos;
        }
    }
 return pos;
}

//-------------------------------------------------- htmlToAscii -----------------------------------------------------------------
/*! \brief html text to text without html tag
 *  \param text :      const QString & html document
 *  \param mode :      conversion mode  StrictASCII  C_Utils_Html::KeepBR('\\n\\n' --> '<p>' and '\\n' --> '<br>')
 *  \return text modified.
*/
QString C_Utils_Html::htmlToAscii(QString &text, C_Utils_Html::flags mode /* = C_Utils_Html::NoMode */)
{
 text.replace("<br>","\n");
 text.replace("<br />","\n");
 text.replace("&nbsp;"," ");
 text.replace("<br />","\n");
 text.replace("</p>","\n\n");
 text.replace("<p>","\n\n");
 text.replace("<li>","\t");
 text.replace("</li>","\n");
 text.replace("</ul>","\n");
 text.replace("</div>","\n");
 text.replace("</div>","\n");
 text.replace("&quot;","\"");
 text.replace("&amp;","&");

 int posDeb = 0;
 int posEnd = 0;
 do {if ( (posDeb = text.indexOf("<", posDeb)) != -1)
        {if ( (posEnd =  text.indexOf(">", posDeb+1)) != -1) text.remove(posDeb, posEnd-posDeb+1);
         else return QString (TR ("CHtmlTools::HtmlToAscii() Erreur de syntaxe tag html non fermé") );
        }
     else break;
    } while (1);
 text.replace("&lt;","<");
 text.replace("&gt;",">");
 if (mode & C_Utils_Html::KeepBR) text.replace("\n\n","<p>");
 if (mode & C_Utils_Html::KeepBR) text.replace("\n",  "<br>");
 return    text;
}
//-------------------------------------------------- unProtectSymbolByAntiSlash -----------------------------------------------------------------
/*! \brief unprotect a caracter by antislash in a text (if already protected nothing append)
 *  \param text :      const QString & html document
 *  \return text modified
*/
QString C_Utils_Html::unProtectSymbolByAntiSlash(const QString &text)
{   QString result = text;
    result     = result.replace("\\\\","-*@*-");
    result.remove("\\");
    result     = result.replace("-*@*-","\\\\");
    return result;
}



//-------------------------------------------------- protectSymbolByAntiSlash -----------------------------------------------------------------
/*! \brief protect a caracter by antislash in a text (if already protected nothing append)
 *  \param text :      const QString & html document
 *  \param symbol :    symbol to protect
 *  \return text modified
*/
QString C_Utils_Html::protectSymbolByAntiSlash(const QString &text, const QChar &symbol /*=','*/)
{long       pos = 0;
 long       len = text.length();
 QString result = "";

 while (pos < len)
     {QChar car = text.at(pos);
      if (car=='\\')                                  // something already protected, jump it
         {result += '\\' + text.at(pos+1);
          ++pos ;                                     // que +1 car ++pos de fin;
         }
      else if (car == symbol)
         { result += QString("\\") + car;
         }
      else
         { result += car;
         }
      ++pos;
     }
 return result;
}

//------------------------------------------ toNum -----------------------------------------
/*! \brief ne retient d'une chaine de caracteres que les valeurs numeriques et le point (au passage les virgules seront transformees en point).
 *  \param text           const QString & texte a convertir en numerique
 *  \param cutFirstStr_in const QString & mode de conversion numerique :
 SI   contient $keepSign     la conversion tient compte du signe.
 SI   contient $stopIfNotNum la conversion s'arrete au premier caractere non numerique.
 SI   contient $allString tous les caracteres numeriques de la chaine seront retenus.
 SI   contient $toInt la conversion ne conservera que la partie entiere.
 SI   toute autre valeur, la conversion s'arretera a la premiere occurence de cette valeur.
 *  \param int *pos si différent de zero alors la position dans la chaine après la valeur numerique
 *  \return une QString resultat du traitement
 */
QString C_Utils_Html::toNum(const QString &text, const QString &cutFirstStr_in /* = ""*/, int *next_pos /* = 0*/)
{if (next_pos)  *next_pos  = -1;
 QString str               = text.trimmed();
 QString cutFirstStr       = cutFirstStr_in;
 bool    cutFirstNonNum    = true;
 bool    keepSign          = (cutFirstStr.indexOf("$keepSign") != -1);
 if (keepSign) cutFirstStr =  cutFirstStr.remove("$keepSign");
 bool    toInt             = (cutFirstStr.indexOf("$toInt")    != -1);
 if (toInt) cutFirstStr    =  cutFirstStr.remove("$toInt");

 if (cutFirstStr.length())
    {
     if      (cutFirstStr.indexOf("$stopIfNotNum") != -1)    cutFirstNonNum = TRUE;
     else if (cutFirstStr.indexOf("$allString")    != -1)    cutFirstNonNum = FALSE;
     else {int pos = str.indexOf(cutFirstStr);
           if (pos != -1) str.truncate(pos);
          }
    }
 int     end = str.length();
 QString ret = "";
 int       i = 0;
 while (i<end)
     {if (str.at(i)>='0' && str[i]<='9')                      {ret += str.at(i);}
      else if (str.at(i)=='-' || str[i]=='+')                 { if (keepSign) ret += str.at(i);}
      else if (str.at(i)=='.')                                {ret += ".";   }
      else if (str.at(i)==',')                                {ret += ".";   }
      else if (cutFirstNonNum)                                {if (next_pos) *next_pos = i;   i = end;   }
      ++i;
     }
 if (next_pos && *next_pos==-1) *next_pos = i;
 if (toInt)
    {int pos  =     ret.indexOf(".");
     if (pos != -1) ret.truncate(pos);
    }
 return ret;
}
