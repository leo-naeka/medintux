#include "C_AppCore.h"
//#include "CApp.h"

#include <QFileInfo>
#include <QFile>

#include <QStringList>
#include <QTextStream>
#include <QIODevice>
#include <QProcess>
#include <QDateTime>
#include <QTextCodec>
#include <QMessageBox>
#include <QCoreApplication>
#include <QDebug>
#include "Theme/Theme.h"
#include "CGestIni.h"


static C_AppCore* G_AppCore = 0;  // contiendra l'instance globale de l'application accessible avec CApp::pCApp()

//--------------------------------------------- C_AppCore -------------------------------------------------------------------
C_AppCore::~C_AppCore()
{writeParam((m_NameAppli+" session").toAscii(),"closed", QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss:zzz").toAscii());
 updateIniParamToDisk();
}

//--------------------------------------------- C_AppCore -------------------------------------------------------------------
C_AppCore::C_AppCore(QString mui_name, int & argc, char ** argv)
:QApplication(argc,argv), m_NameAppli(mui_name)
{   QTextCodec::setCodecForTr( QTextCodec::codecForName("utf8") );
    //.............................. recuperer le numer de version du .pro ..........................................
    //                               le mettre dans un tableau static tagué pour
    //                               qu'il soit repérable dans le binaire
    static char NUMTAB_VERSION[]     = "==##@@=="NUM_VERSION"==@@##==";    // defini dans le .pro
    Q_UNUSED(NUMTAB_VERSION);
    //................ initialisation de quelques repères .........................
    setApplicationName    ( m_NameAppli );         //qDebug (QString("NomAppli : %1").arg(m_NameAppli).toLatin1());
    setApplicationVersion ( NUM_VERSION );         //qDebug (QString("NumVersion : %1").arg(NUM_VERSION).toLatin1());
    setOrganizationDomain ( NAME_ORGANISATION );   //qDebug (QString("NomOrganisation : %1").arg(NAME_ORGANISATION).toLatin1());
    setOrganizationName   ( NAME_DOMAINE );        //qDebug (QString("NomDomaine : %1").arg(NAME_DOMAINE).toLatin1());

    m_Version            = applicationVersion () + "  Qt : " + QT_VERSION_STR;

    //.................... recuperer path de demarrage de l'appli ...........................
    QFileInfo qfi(argv[0]);
    m_PathAppli          = CGestIni::Construct_PathBin_Module(m_NameAppli, qfi.path ());
    //................... fabriquer le .ini ..................................................
    m_PathIni            = localizePathIni();
    QString  dateSession = QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss:zzz");
    if (!QFile::exists(m_PathIni))
       {m_IniParam = "["+ m_NameAppli +" session]"
                        "\n  started = " + dateSession;
       }
    else
       {m_IniParam    = CGestIni::Param_UpdateFromDisk(m_PathIni);
        CGestIni::Param_WriteParam(&m_IniParam, (m_NameAppli+" session").toAscii(),"started", dateSession.toAscii());
       }
    updateIniParamToDisk();
    //.............................. initialiser le theme ..........................................
    m_PathTheme     =  "../../Themes/Default/";
    if (CGestIni::Param_ReadParam( m_IniParam.toAscii(), "Theme", "Path", &m_PathTheme) != QString::null )  // zero = pas d'erreur
        { m_PathTheme     =  "../../Themes/Default";                                   // valeur par dÃ©faut si pas de theme explicite
        }
    if ( QDir(m_PathTheme).isRelative()) {m_PathTheme.prepend(m_PathAppli); m_PathTheme = QDir::cleanPath(m_PathTheme) + "/";}
    if (!QDir(m_PathTheme).exists())      m_PathTheme     =  "../../Themes/Default/";        // valeur par defaut
    Theme::setPath(m_PathTheme);

    //qDebug (QString("NomAppli : %1").arg(applicationName()).toLatin1());
    //qDebug (QString("NumVersion : %1").arg(applicationVersion()).toLatin1());
    //qDebug (QString("NomOrganisation : %1").arg(organizationDomain()).toLatin1());
    //qDebug (QString("NomDomaine : %1").arg(organizationName()).toLatin1());
    G_AppCore           =    this;
}

//--------------------------------------------- initSettingVar -------------------------------------------------------------------
/*! \brief met ? jour le fichier de parametrage la ou il veut.
*/
void C_AppCore::initSettingVar(const QString &var)
{m_IniParam = var;
}

//--------------------------------------------- updateIniParamToDisk -------------------------------------------------------------------
/*! \brief met à jour le fichier de parametrage sur le disque.
*/
void C_AppCore::updateIniParamToDisk()
{CGestIni::Param_UpdateToDisk(m_PathIni, m_IniParam);
}
//--------------------------------------------- updateIniParamToDisk -------------------------------------------------------------------
/*! \brief ecrit une serie de valeurs dans la variable de configuration
*/

QString C_AppCore::writeParam(const char *section, const char  *variable,
                              const char *val1, const char *val2, const char *val3, const char *val4, const char *val5,
                              const char *val6, const char *val7, const char *val8, const char *val9, const char *val10)
{ return CGestIni::Param_WriteParam(&m_IniParam, section, variable, val1, val2, val3, val4, val5, val6, val7, val8, val9, val10);
}
//--------------------------------------------- criptedToUnCripted -------------------------------------------------------------------
/*! \brief met en clair le terme presente dans cripted
*/
QString C_AppCore::criptedToUnCripted(const QString &cripted)
{   QString str = cripted;
    str = CGestIni::PassWordDecode(str);
    return  str;
}
//--------------------------------------------- unCriptedToCripted -------------------------------------------------------------------
/*! \brief met en code le terme presente dans uncripted
*/
QString C_AppCore::unCriptedToCripted(const QString &uncripted, const QString &prefix /* ="" */ )
{   QString str = uncripted;
    str = CGestIni::PassWordEncode(str);
    return str.prepend(prefix);
}
//--------------------------------------------- readParam -------------------------------------------------------------------
/*! \brief lit une serie de valeurs dans la variable de configuration
*/

QString C_AppCore::readParam(const char *section, const char  *variable,
                             QString *val1, QString *val2, QString *val3, QString *val4, QString *val5,
                             QString *val6, QString *val7, QString *val8, QString *val9, QString *val10)
{ return CGestIni::Param_ReadParam(m_IniParam.toAscii(), section, variable, val1, val2, val3, val4, val5, val6, val7, val8, val9, val10);
}
//--------------------------------------------- readUniqueParam -------------------------------------------------------------------
/*! \brief lit une valeur valeurs dans la variable de configuration
*/
QString C_AppCore::readUniqueParam(const char *section, const char  *variable)
{ return CGestIni::Param_ReadUniqueParam(m_IniParam.toAscii(),section, variable);
}
//--------------------------------------------- removeSectionParam -------------------------------------------------------------------
/*! \brief retire une section du fichier de configurtion
*/
QString C_AppCore::removeSectionParam(QString section)
{return CGestIni::Param_RemoveSection(m_IniParam, section);
}
//--------------------------------------------- appCore -------------------------------------------------------------------
/*! \brief retourne l'instance de l'application. est a zero tant que l'initialisation n'est pas finie.
*/
C_AppCore* C_AppCore::appCore()
{return G_AppCore;
}

//--------------------------------------------- instance -------------------------------------------------------------------
/*! \brief retourne l'instance de l'application. est a zero tant que l'initialisation n'est pas finie.
*/
C_AppCore* C_AppCore::instance()
{return G_AppCore;
}

//--------------------------------------------- localizePathIni -------------------------------------------------------------------
/*! \brief cherche le fichier de configuration au niveau de : l'applicatif,$home/.Data Medical Design/MedinTux/applicatif.ini, la racine de MedinTux dans repertoire config, la racine de MedinTux.
*/

QString C_AppCore::localizePathIni()
{QString data;
 QFileInfo qfi(argv()[0]);
 QString nameAppli = applicationName();
 QString pathAppli = CGestIni::Construct_PathBin_Module(nameAppli, qfi.path ());
 QString path      = pathAppli + nameAppli + ".ini";
 if (QFile::exists(path))
    {QString redirectPath;
     data          = CGestIni::Param_UpdateFromDisk(path);
     redirectPath  = CGestIni::Param_ReadUniqueParam( data.toLatin1(), "PathIni", "Path");
     if (redirectPath.length())
        {if ( QDir(redirectPath).isRelative()){ redirectPath.prepend(pathAppli); redirectPath = QDir::cleanPath(redirectPath); }
         if (QFile::exists(redirectPath)) return redirectPath;
        }
     return path;
    }
 path = QDir::cleanPath(m_PathAppli + "../../../config" + nameAppli + ".ini");
 if (QFile::exists(path)) return path;
 path = QDir::homePath()+"/."+ organizationName() + "/" + organizationDomain()+"/"+nameAppli+".ini";
 if (QFile::exists(path)) return path;
 path = QDir::cleanPath(pathAppli + "../../../config/MedinTuxGlobal.ini");
 if (QFile::exists(path)) return path;
 path = QDir::homePath()+"/."+ organizationName() + "/" + organizationDomain()+"/MedinTuxGlobal.ini";
 if (QFile::exists(path)) return path;
 path = QDir::cleanPath(pathAppli + "../../../MedinTuxGlobal.ini");
 return path;
}
