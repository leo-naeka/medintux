#ifndef C_APPCORE_H
#define C_APPCORE_H

#include <QObject>
#include <QProcess>
#include <QtGui/QApplication>
#include <QtGui/QApplication>
#include <qtsingleapplication.h>
#include <QKeyEvent>
#include <QNetworkInterface>

#ifdef Q_WS_WIN
   #define F_EXE ".exe"
#else
   #define F_EXE ""
#endif

#define TR QObject::tr


//================================================= CApp ==============================================================
/*! \class C_AppCore
 *  \brief Main base class derived from QApplication.
 *  - this Class must be derived and derived classe instancied in main.cpp in first position
 *    when this class is instancied a global pointer  CApp* G_pCApp will be created.
 *    if fatal error in class initialisation occured  CApp::pCApp()==0
 *    so all publics functions will be accessibles by CApp::pCApp()->publicFonctions().
 */

class C_AppCore: public QtSingleApplication //QApplication
{
   Q_OBJECT
public:
     C_AppCore(QString mui_name, int & argc, char ** argv);
    ~C_AppCore();

    static C_AppCore     *instance();               /*!< retourne l'instance de l'application*/
    static C_AppCore     *appCore();                /*!< variante retourne l'instance de l'application*/
    QString pathTheme()   {return m_PathTheme;}     /*!< retourne le chemin du theme*/
    QString pathAppli(int cutLastSlash=0)
                     {if (cutLastSlash==-1 && m_PathAppli.endsWith('/')) return m_PathAppli.left(m_PathAppli.length()-1);
                      return m_PathAppli;
                     }     /*!< retourne le chemin de l'application*/
    QString pathIni()     {return m_PathIni;}       /*!< retourne le chemin du fichier ini  de parametrage trouve*/
    QString iniParam()    {return m_IniParam;}      /*!< retourne le contenu du fichier ini de parametrage */
    void    updateIniParamToDisk();                 /*!< ecrit le contenu du fichier ini sur le disque */
    QString writeParam(const char *section, const char  *variable,
                       const char *val1=0,  const char *val2=0, const char *val3=0, const char *val4=0, const char *val5=0,
                       const char *val6=0,  const char *val7=0, const char *val8=0, const char *val9=0, const char *val10=0);  /*!< ecrit une serie de valeurs dans la variable de parametrage */
    QString readParam (const char *section, const char  *variable,
                       QString *val1=0, QString *val2=0, QString *val3=0, QString *val4=0, QString *val5=0,
                       QString *val6=0, QString *val7=0, QString *val8=0, QString *val9=0, QString *val10=0); /*!< lit une serie de valeurs dans la variable de parametrage */
    QString readUniqueParam(const QString &section, const QString &variable);    /*!< lit une valeur dans la variable de parametrage */
    QString readUniqueParam(const char *section, const char  *variable);         /*!< lit une valeur dans la variable de parametrage */
    //--------------------------------------------- getParamList -------------------------------------------------------------------
    /*! \brief retourne une liste de parametres dans le .ini
     *  \param sectionToRetrieve : section contenant les variables dont il faut faire une liste
     *  \param varToRetrieve     : variable dont il faut faire une liste (si vide alors toutes les donnees de la section apres le signe = seront retenues)
     *                             si terminee par * alors on prend toutes les variables commencant par ce qui est avant le * de varToRetrieve
     *                             si commence par * alors on prend toutes les variables terminees  par ce qui est apres le * de varToRetrieve
     *                             si vide alors toutes les lignes de la section seront retenues, alors entireDataLine est un ou deux  (ne s'arrete pas à la premiere valeur entre = et virgule)
     *  \param lst :        liste a initialiser et construire
     *  \param isToStrip :  isToStrip a zero par defaut si a un, chaque element de la liste sera nettoye des espaces de debut et fin
     *  \param entireDataLine :  entireDataLine a zero par defaut seule la premiere valeur apres le signe egal et avant la premiere virgule sera retenue.
     *                           si a un,   toutes les donnees apres le signe = seront retenues
     *                           si a deux, toutes les donnees de la ligne seront retenues y compris ce qui est avant le signe =
    */
    void    getParamList(const QString &sectionToRetrieve, const QString &varToRetrieve,  QStringList &lst , int isToStrip =0, int entireDataLine =0);
    //--------------------------------------------- getParamList -------------------------------------------------------------------
    /*! \brief retourne une liste de parametres dans le .ini
     *  \param sectionToRetrieve : section contenant les variables dont il faut faire une liste
     *  \param varToRetrieve     : variable dont il faut faire une liste (si vide alors toutes les donnees de la section apres le signe = seront retenues)
     *                             si terminee par * alors on prend toutes les variables commencant par ce qui est avant le * de varToRetrieve
     *                             si commence par * alors on prend toutes les variables terminees  par ce qui est apres le * de varToRetrieve
     *                             si vide alors toutes les lignes de la section seront retenues, alors entireDataLine est un ou deux  (ne s'arrete pas à la premiere valeur entre = et virgule)
     *  \param isToStrip :  isToStrip a zero par defaut si a un, chaque element de la liste sera nettoye des espaces de debut et fin
     *  \param entireDataLine :  entireDataLine a zero par defaut seule la premiere valeur apres le signe egal et avant la premiere virgule sera retenue.
     *                           si a un,   toutes les donnees apres le signe = seront retenues
     *                           si a deux, toutes les donnees de la ligne seront retenues y compris ce qui est avant le signe =
    */
    QStringList    getParamList(const QString &sectionToRetrieve, const QString &varToRetrieve, int isToStrip =0, int entireDataLine =0);
    //----------------------------------------- replaceList ------------------------------------------------------------------------
    /*! \brief replace a variables list in section parameters by datas from QStringList
     *  \param outParam : parameters data document destination.
     *  \param QStringList &list list data sources to place.
     *  \param const QString &sectionToSet section where to find list of variables to replace
     *  \param const QString &varToSet  variable name of each list elements to replace
     */
    void replaceList(const QString &sectionToSet, const QString &varToSet,  const QStringList &list);

    //--------------------------------------------- readLine -------------------------------------------------------------------
    /*! \brief retourne si l'instance de l'appication doit etre unique ou non.
    */
    bool    instanceMustBeUnique() { if (m_UniqueInstance==0)     return false;
                                     if (sendMessage("Wake up!")) return true;
                                     else                         return false;
                                   }
    //--------------------------------------------- readLine -------------------------------------------------------------------
    /*! \brief lit les donnees situees apres le signe egal d'une variable donnee pour une section donnee.
    */
    QString readLine(const char *section, const char  *variable);         /*!< lit une valeur dans la variable de parametrage */
    //--------------------------------------------- initSettingVar -------------------------------------------------------------------
    /*! \brief met a jour le fichier de parametrage la ou il veut.
    */
    void initSettingVar(const QString &var);
    //--------------------------------------------- criptedToUncripted -------------------------------------------------------------------
    /*! \brief met en clair le terme presente dans cripted
    */
    static QString criptedToUnCripted(const QString &cripted);
    //--------------------------------------------- unCriptedTocripted -------------------------------------------------------------------
    /*! \brief met en code le terme presente dans uncripted
    */
    static QString unCriptedToCripted(const QString &uncripted, const QString &prefix="");
    //--------------------------------------------- removeSectionParam -------------------------------------------------------------------
    /*! \brief retire une section du fichier de configurtion
    */
    QString removeSectionParam(QString section);
    //--------------------------------------------- ApplicationAndQtVersion -------------------------------------------------------------------
    /*! \brief return the Application version
    */
    QString ApplicationVersion(){return m_Version;}
    //--------------------------------------------- ApplicationAndQtVersion -------------------------------------------------------------------
    /*! \brief return the Application version number and Qt Version
    */
    QString ApplicationAndQtVersion(const QString &version_suffix="");
    //--------------------------------------------- getAsyncModifiers -------------------------------------------------------------------
    /*! \brief return the state of capital key
    */
    static Qt::KeyboardModifiers getAsyncModifiers(int *capitalState=0 );
    //--------------------------------------------- get_Current_HW_Adr -------------------------------------------------------------------
    /*! \brief return the current mac hardware adress
    */
    static QString get_Current_HW_Adr();
    //--------------------------------------------- get_Current_IP_Adr -------------------------------------------------------------------
    /*! \brief return the current Ip adr
    */
    static QString get_Current_IP_Adr(QString *pMacAdr = 0);
    //--------------------------------------------- networkInterfaceFlagToString -------------------------------------------------------------------
    /*! \brief return the state of network interface in readables strings from QNetworkInterface::InterfaceFlags flags
         "the network interface is active ;"
         "the network interface has resources allocated ;"
         "the network interface works in broadcast mode ;"
         "the network interface is a loopback interface: that is, it's a virtual interface whose destination is the host computer itself ;"
         "the network interface is a point-to-point interface: that is, there is one, single other address that can be directly reached by it. ;"
         "the network interface supports multicasting ;"
    */
    static QString networkInterfaceFlagToString (QNetworkInterface::InterfaceFlags flags);

protected :
    QString             localizePathIni();
    //................... les objets suivants sont relatifs au contexte de l'application..............................................
    QString              m_NameAppli;           /*!< Nom de l'applicatif */
    QString              m_PathAppli;           /*!< chemin du repertoire de l'applicatif (termine par /) */
    QString              m_Version;             /*!< numero de version du module pour lequel afficher l'info */
    QString              m_PathTheme;           /*!< chemin du repertoire de themes */
    QString              m_PathIni;             /*!< chemin du fichier de configuration */
    QString              m_IniParam;            /*!< contenu du fichier de configuration */
    bool                 m_UniqueInstance;      /*!< vrai si l'instance doit etre unique */
};

#endif // C_APPCORE_H

