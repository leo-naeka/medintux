#ifndef C_UTILS_HTML_H
#define C_UTILS_HTML_H


#include <QObject>
#include <QtNetwork>
#include <QNetworkCookieJar>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QByteArray>

#include "C_Utils_Log.h"



class QTextEdit;
class QStringList;
class QProgressBar;
//============================================== CookieJar ==============================================
class CookieJar : public QNetworkCookieJar, public C_Log
{


      public:
          CookieJar (QString path, QObject *parent = 0, QTextEdit *pQTextEditLog = 0);  //constructeur, implémentera le chargement des cookies
         ~CookieJar ();  //destructeur, implémente la sauvegarde des cookies
         QList<QNetworkCookie> cookiesForUrl ( const QUrl & url ) const; //on ne touche pas
         bool setCookiesFromUrl ( const QList<QNetworkCookie> & cookieList, const QUrl & url ); //on ne touche pas
      private:
         QString m_file; //pour retenir où l'on doit sauvagarder les cookies
};


//============================================== C_Utils_Html ==============================================
class C_Utils_Html : public QObject, public C_Log
{
         Q_OBJECT

public:
    enum AttributChange  {SetAllJustDir        = 0,
                          SetAllData           = 1,
                          StopAfterFirstChange = 2,
                          StopAfterFirstDir    = 4
                         };
    enum flags
           {   NoMode              = 0,
               StrictASCII         = 2,
               KeepBR              = 4,
               commaProtect        = 8,
               withoutSpaces       = 16
           };
    //---------------------------------- C_Utils_Html ---------------------------------------------------------------------------
    explicit C_Utils_Html(QObject *parent=0, QNetworkAccessManager *pm_pQNetworkAccessManager=0, QTextEdit *pQTextEditLog =0 );

    //------------------------------------ setQNetworkAccessManager -------------------------------
    /*! \brief set the QNetworkAccessManager
     *  \param pQNetworkAccessManager pointer on QNetworkAccessManager to set
     */
    void setQNetworkAccessManager(QNetworkAccessManager *pQNetworkAccessManager){m_pQNetworkAccessManager = pQNetworkAccessManager;}

    //------------------------------------ getQNetworkAccessManager -------------------------------
    /*! \brief get the QNetworkAccessManager
     *  \return pQNetworkAccessManager pointer on QNetworkAccessManager who was set
     */
    QNetworkAccessManager *getQNetworkAccessManager(){return m_pQNetworkAccessManager;}

    //------------------------------------ setQProgressBar -------------------------------
    /*! \brief set the QProgressBar
     *  \param pQProgressBar pointer on QProgressBar to set
     */
    void setQProgressBar(QProgressBar *pQProgressBar){m_pQProgressBar = pQProgressBar;}

    //------------------------------------ saveImagesFromTag -------------------------------
    /*! \brief download alls distants datas from tag and attribut tag where attributs datas represents url
     *  \param const QString& html :     page to analyse where find tags and attributs
     *  \param const QString& url :      base page url
     *  \param const QString &imageDir : directory where datas must be downloaded
     *  \param const QString &tag :      tag to find
     *  \param const QString &attribut : attribut of the tag where is data url
     *  \return   number of data found
     */
    int saveImagesFromTag(const QString& html, const QString& url, const QString &imageDir, const QString &tag, const QString &attribut);

    //---------------------------------- setTagAttributeValue ---------------------------------------------------------------------------
    /*! \brief extract alls tags from a thml text
     *  \param QString &txt:                 text to examine
     *  \param const QString &tag            tag to find
     *  \param const QString attribut        attribut where is data value to set
     *  \param const QString value           value to place
     *  \param C_Utils_Html::AttributChange  if AllData the entire data of attribut will be replaced by contents of value else if SetAllJustDir just to change origin string before image.name)
     *  \param long  from:                   position to begin
     *  \return   if negative error or not image tag, if not negative, next position (after tag)
     */
    long               setTagAttributeValue( QString &txt,
                                             const QString &tag,
                                             const QString &attribut,
                                             const QString &value,
                                             C_Utils_Html::AttributChange = StopAfterFirstChange,
                                             long from  = 0
                                           );
    //---------------------------------- getTagList ---------------------------------------------------------------------------
    /*! \brief extract alls tags from a thml text
     *  \param QString &txt:                text to examine
     *  \param const QString &tag           tag to find
     *  \param QStringList &imgList         list to fill
     *  \param long from:                   position to begin
     *  \param const QString &newImgOrigin  is just for img tag (to change origin string before image.name )
     *  \param const QString &attribut      attribut where image name is (to change origin string before image.name )
     *  \param int   replaceAll             if one the entire data of attribut will be replaced by contents of newImgOrigin else just to change origin string before image.name)
     *  \return   if negative error or not image tag, if not negative, next position (after tag)
     */
    long getTagList(       QString   &txt,
                     const QString   &tag,
                     QStringList     *imgList,
                     long             from             = 0 ,
                     const QString   &newImgOrigin     = "",
                     const QString   &attribut         = "" ,
                     C_Utils_Html::AttributChange flag = SetAllJustDir);

    //------------------------------------------ indexOfTag ------------------------------------------------------
    /*! \brief analyse a tag and if a image tag return it's url in (QString *fileName if not zero)
     *  \param QString &txt:               text to examine
     *  \param const QString &tag          tag to find
     *  \param long from:                  position to begin (at function end changed in position after tag)
     *  \param const QString value  is just for img tag (to change origin string before image.name )
     *  \param const QString attribut      attribut where image name is (to change origin string before image.name )
     *  \param int   replaceAll            if one the entire data of attribut will be replaced by contents of newImgOrigin else just to change origin string before image.name)
     *  \return   if negative: error or not tag, if not negative: start position of the tag.
     */
    long indexOfTag(      QString         &txt,
                    const QString         &tag,
                    long                  &from ,
                    const QString         &value ,
                    const QString         &attribut,
                    C_Utils_Html::AttributChange flag );

    //------------------------------------------ getDataFromUrl ------------------------------------------------------
    /*! \brief download distants datas from url
     *  \param const QString &url :                                url where get data
     *  \param QNetworkAccessManager *pQNetworkAccessManager :     manager
     *  \return   data in a QByteArray
     */
    QByteArray  getDataFromUrl (const QString &url,  const QStringList &rawHeaders, QNetworkAccessManager *pQNetworkAccessManager = 0);

    //---------------------------------------  postDataFromUrl ---------------------------------------------------------
    /*! \brief uploag and post distants datas from url
     *  \param const QString &url :                                url where post data
     *  \param const QString &postData :                           data to post
     *  \param QNetworkAccessManager *pQNetworkAccessManager :     manager
     *  \return   data in a QByteArray
     */
    bool        postDataFromUrl(const QString &url, const QString &postData,  const QStringList &rawHeaders, QNetworkAccessManager *pQNetworkAccessManager  = 0);

    //---------------------------------------  breakHttpProcess ---------------------------------------------------------
    /*! \brief break a Http Process
     */
    void        breakHttpProcess(){m_Wait_HttpProcess = 0;}

    //---------------------------------------  setWaitHttpProcess ---------------------------------------------------------
    /*! \brief set max loops before break a Http Process (time out)
     *  \param quint64 endWaitHttpProcess : number of loops
     */
    void        setWaitHttpProcess(quint64 endWaitHttpProcess){m_EndWaitHttpProcess = endWaitHttpProcess;}


    //'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    //                                 STATIC FUNCTIONS
    //'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    //--------------------- removeHtmlTag -----------------
    /*! \brief  remove html tags from a string
     *  \param  const QString &txt   text to compute
     *  \return the string without html tags.
     */
    static QString  removeHtmlTag(const QString text);

    //---------------------------------- getImagesList ---------------------------------------------------------------------------
    /*! \brief extract alls images tags from a thml text
     *  \param QString &txt:           text to examine
     *  \param const QString &tag      tag to find
     *  \param const QString attribut  attribut where image name is (to change origin string before image.name )
     *  \param QStringList &imgList    list to fill
     *  \param long from:              position to begin
     *  \return   if negative error or not image tag, if not negative, next position (after tag)
     */
    static long getImagesList( const QString &txt, const QString &tag, const QString attribut, QStringList &imgList, long from  = 0 );

    //------------------------------------------ isThisTagImage ------------------------------------------------------
    /*! \brief analyse a tag and if a image tag return it's url in (QString *fileName if not zero)
     *  \param QString &txt:           text to examine
     *  \param const QString &tag      tag to find
     *  \param const QString attribut  attribut where image name is (to change origin string before image.name )
     *  \param long from:              position to begin
     *  \param QString *fileName:      if not zero, image url is returned in the QString pointed
     *  \param int *w:                 if not zero, image width is returned in the int pointed
     *  \param int *h:                 if not zero, image height is returned in the int pointed
     *  \return   if negative error or not image tag, if not negative, next position (after tag)
     */
    static long isThisTagImage(const QString &txt, const QString &tag, const QString attribut, long &from , QString *fileName  = 0  , int *w  = 0 , int *h  = 0 );

    //------------------------------------------ indexOfAttribut ------------------------------------------------------
    /*! \brief find the next attribut whith specific name in a tag
     *  \param QString &txt:                    text to examine
     *  \param const QString &attribut          attribut to find
     *  \param long from:                       position to begin
     *  \param long end:                        position to ended
     *  \return   if negative: error or not tag, if not negative: start position of the attribut.
     */
    static long  indexOfAttribut(QString &txt,
                                       const QString &attribut,
                                       long &from,
                                       long   end);
    //------------------------------------------ htmlFind ------------------------------------------------------
    /*! \brief find a text patern in a html document
     *  \param text :      const QString & html document where find text patern
     *  \param patern :    QString & text patern to find. If text patern == "FinDeLigne" or "EOL" the first end line tag is searched
     *  \param pos :       long &pos position where begin action
     *  \param debMotif :  long * pointer on long in which (if not egal zero) position at start patern will be returned (-1 if not found)
     *  \return -1 if not found, just after patern position if found.
    */
    static long          htmlFind(const QString &text, QString patern, long pos = 0, long *debMotif =0, C_Utils_Html::flags mode  = C_Utils_Html::withoutSpaces );

    //------------------------------------------ ifHtmlTagJumpIt ------------------------------------------------------
    /*! \brief jump a html tag in a html document
     *  \param text :      const QString & html document
     *  \param pos :       long &pos position where begin action must be just before the < start symbol tag
     *  \return position just after > end tag (if not found return position after last caracter of the text).
    */
    static long          ifHtmlTagJumpIt(const QString &text, long pos);

    //------------------------------------------ htmlToAscii ------------------------------------------------------
    /*! \brief html text to text without html tag
     *  \param text :      const QString & html document
     *  \param mode :      conversion mode  StrictASCII  C_Utils_Html::KeepBR('\\n\\n' --> '<p>' and '\\n' --> '<br>') C_Utils_Html::commaProtect(',' --> '\\,')
     *  \return  text modified
    */
    static QString       htmlToAscii(QString &text, C_Utils_Html::flags mode = C_Utils_Html::NoMode);

    //-------------------------------------------------- unProtectSymbolByAntiSlash -----------------------------------------------------------------
    /*! \brief unprotect a caracter by antislash in a text (if already protected nothing append)
     *  \param text :      const QString & html document
     *  \return text modified
    */
    static QString       unProtectSymbolByAntiSlash(const QString &text);
    //-------------------------------------------------- protectSymbolByAntiSlash -----------------------------------------------------------------
    /*! \brief protect a caracter by antislash in a text (if already protected nothing append)
     *  \param text :      const QString & html document
     *  \param symbol :    symbol to protect
     *  \return text modified
    */
    static QString       protectSymbolByAntiSlash(const QString &text, const QChar &symbol=',');

    //------------------------------------------ toNum -----------------------------------------
    /*! \brief ne retient d'une chaine de caracteres que les valeurs numeriques et le point (au passage les virgules seront transformees en point).
     *  \param text           const QString & texte a convertir en numerique
     *  \param cutFirstStr_in const QString & mode de conversion numerique :\
     SI   contient $stopIfNotNum la conversion s'arrete au premier caractere non numerique.
     SI   contient $allString tous les caracteres numeriques de la chaine seront retenus.
     SI   contient $toInt la conversion ne conservera que la partie entiere.
     SI   toute autre valeur, la conversion s'arretera a la premiere occurence de cette valeur.
     *  \return une QString resultat du traitement
     */
    static QString toNum(const QString &text, const QString &cutFirstStr_in = "");

private:
    //......... methodes .......
    void        beginGet_FromUrl(const QString &url,  const QStringList &rawHeaders);
    void        beginPost_FromUrl(const QString &url, const QString &postData, const QStringList& rawHeaders);

    //......... datas ..........
    QNetworkAccessManager *m_pQNetworkAccessManager;
    QByteArray             m_QByteArray;
    QString                m_LastError;
    quint64                m_Wait_HttpProcess;
    quint64                m_EndWaitHttpProcess;
    QProgressBar          *m_pQProgressBar;
    long                   m_position;
private slots:
    void   Slot_DataLoadFinished(QNetworkReply *pQNetworkReply);
    void   Slot_DataPostFinished(QNetworkReply *pQNetworkReply);

};

#endif // C_UTILS_HTML_H
