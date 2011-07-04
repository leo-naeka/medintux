#ifndef C_APPCORE_H
#define C_APPCORE_H

#include <QObject>
#include <QProcess>
#include <QtGui/QApplication>

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

class C_AppCore: public QApplication
{
   Q_OBJECT
public:

     C_AppCore(QString mui_name, int & argc, char ** argv);
    ~C_AppCore();

    static C_AppCore     *instance();               /*!< retourne l'instance de l'application*/
    static C_AppCore     *appCore();                /*!< variante retourne l'instance de l'application*/
    QString pathTheme()   {return m_PathTheme;}     /*!< retourne le chemin du theme*/
    QString pathAppli()   {return m_PathAppli;}     /*!< retourne le chemin de l'application*/
    QString pathIni()     {return m_PathIni;}       /*!< retourne le chemin du fichier ini  de parametrage trouve*/
    QString iniParam()    {return m_IniParam;}      /*!< retourne le contenu du fichier ini de parametrage */
    void    updateIniParamToDisk();                 /*!< ecrit le contenu du fichier ini sur le disque */
    QString writeParam(const char *section, const char  *variable,
                       const char *val1=0,  const char *val2=0, const char *val3=0, const char *val4=0, const char *val5=0,
                       const char *val6=0,  const char *val7=0, const char *val8=0, const char *val9=0, const char *val10=0);  /*!< ecrit une serie de valeurs dans la variable de parametrage */
    QString readParam (const char *section, const char  *variable,
                       QString *val1=0, QString *val2=0, QString *val3=0, QString *val4=0, QString *val5=0,
                       QString *val6=0, QString *val7=0, QString *val8=0, QString *val9=0, QString *val10=0); /*!< lit une serie de valeurs dans la variable de parametrage */
    QString readUniqueParam(const char *section, const char  *variable);         /*!< lit une valeur dans la variable de parametrage */
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
protected :
    QString             localizePathIni();
    //................... les objets suivants sont relatifs au contexte de l'application..............................................
    QString              m_NameAppli;           /*!< Nom de l'applicatif */
    QString              m_PathAppli;           /*!< chemin du repertoire de l'applicatif (termine par /) */
    QString              m_Version;             /*!< numero de version du module pour lequel afficher l'info */
    QString              m_PathTheme;           /*!< chemin du repertoire de themes */
    QString              m_PathIni;             /*!< chemin du fichier de configuration */
    QString              m_IniParam;            /*!< contenu du fichier de configuration */
};

#endif // C_APPCORE_H

