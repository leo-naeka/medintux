#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QProcess>

#define QNETCOPY_USAGE_COMMAND_LINE_ERROR               -11
#define QNETCOPY_SOURCE_FILE_NOT_EXIST_OR_UNREACHABLE   -12
#define QNETCOPY_TARGET_PATH_NOT_EXIST_OR_UNREACHABLE   -13
#define QNETCOPY_FAILED_COPY_FROM_WINDOWS               -14
#define QNETCOPY_FAILED_COPY_FROM_LINUX                 -15
#define QNETCOPY_CANNOT_DELETE_SOURCE_FILE              -16
#define QNETCOPY_FAILED_COPY_FROM_MAC                   -17
#define QNETCOPY_SMBCLIENT_NOT_FOUND                    -18

int main(int argc, char *argv[])
{
    QCoreApplication l_app(argc, argv);

    // get used arguments
    QString l_strFullSourceFilePath;
    QString l_strFullTargetPath;
    bool l_bIsSourceFileDeletedAfterCopy = false;
    if (argc == 3)
    {
        l_strFullSourceFilePath = (QString(argv[1]));
        l_strFullTargetPath     = (QString(argv[2]));
    }
    else if (argc == 4)
    {
        l_strFullSourceFilePath         = (QString(argv[1]));
        l_strFullTargetPath             = (QString(argv[2]));
        l_bIsSourceFileDeletedAfterCopy = (QString(argv[3]).compare("--delete-source-file", Qt::CaseInsensitive) == 0) ? true : false;
    }
    else
    {
        qCritical() << "** Critical Error **\nUsage : QNetCopy <FullSourceFilePath> <FullTargetPath>\nDon't forget double quotes if path contains space chars !";
        exit(QNETCOPY_USAGE_COMMAND_LINE_ERROR);
    }

    // check full source file path existence
    QFileInfo l_flinfFullSourceFilePath(l_strFullSourceFilePath);
    if (!l_flinfFullSourceFilePath.exists())
    {
        qCritical() << QObject::tr("** Critical Error **\nSpecified full source file path (\"%1\") does not exist or is unreachable.\nPlease verify access to this file !").arg(l_strFullSourceFilePath);
        exit(QNETCOPY_SOURCE_FILE_NOT_EXIST_OR_UNREACHABLE);
    }

#ifdef Q_OS_WIN32
    // check target path existence
    QFileInfo l_flinfFullTargetPath(l_strFullTargetPath);
    if (!l_flinfFullTargetPath.exists())
    {
        qCritical() << QObject::tr("** Critical Error **\nSpecified full target path (\"%1\") does not exist or is unreachable.\nPlease verify access to this path !").arg(l_strFullTargetPath);
        exit(QNETCOPY_TARGET_PATH_NOT_EXIST_OR_UNREACHABLE);
    }

    // For Windows, simply copy file from source to target
    QString l_strFullTargetFilePath = QObject::tr("%1%2%3").arg(l_flinfFullTargetPath.absolutePath()).arg(QDir::separator()).arg(l_flinfFullSourceFilePath.fileName());
    QFile l_flFullSourceFile(l_flinfFullSourceFilePath.absoluteFilePath());
    if (!l_flFullSourceFile.copy(l_strFullTargetFilePath))
    {
        qCritical() << QObject::tr("** Critical Error **\nCopy (from Windows platform) has failed with following error : %1 !").arg(l_flFullSourceFile.errorString());
        exit(QNETCOPY_FAILED_COPY_FROM_WINDOWS);
    }
#endif

#ifdef Q_OS_LINUX
    // For Linux, simply invoke smbclient with right parameters
    QProcess    l_procSmbClient;
    QStringList l_lstParams;
    l_lstParams << l_strFullTargetPath << "-N" << "-d0" << QObject::tr("-c put \"%1\" \"%2\"").arg(l_flinfFullSourceFilePath.absoluteFilePath()).arg(l_flinfFullSourceFilePath.fileName());
    if (l_procSmbClient.execute("smbclient", l_lstParams) != 0)
    {
        qCritical() << QObject::tr("** Critical Error **\nCopy (from Linux platform) has failed !");
        exit(QNETCOPY_FAILED_COPY_FROM_LINUX);
    }
#endif
	
#ifdef  Q_OS_MAC
    QString pathExe = "";
    if (QFile::exists("/opt/local/bin/smbclient"))      pathExe = "/opt/local/bin/smbclient";   // SmbUp (lion)
    else if (QFile::exists("/usr/bin/smbclient"))       pathExe = "/usr/bin/smbclient";         // leopard
    else {
           qWarning() << "** Warning Error **\nsmbclient not found !";
           exit( QNETCOPY_SMBCLIENT_NOT_FOUND );
         }
    // For mac, Osx lion simply invoke smbclient with right parameters
	// remove source file if specified
    QProcess l_procSmbClient;
    QStringList l_lstParams;
    l_lstParams << l_strFullTargetPath << "-N" << "-d0" << QObject::tr("-c put \"%1\" \"%2\"").arg(l_flinfFullSourceFilePath.absoluteFilePath()).arg(l_flinfFullSourceFilePath.fileName());
    if (l_procSmbClient.execute(pathExe, l_lstParams) != 0)
    {
        qCritical() << QObject::tr("** Critical Error **\nCopy (from mac platform) has failed !");
        exit(QNETCOPY_FAILED_COPY_FROM_LINUX);
    }
#endif

    if (l_bIsSourceFileDeletedAfterCopy)
    {
        if (!QFile::remove(l_flinfFullSourceFilePath.absoluteFilePath()))
        {
            qWarning() << "** Warning Error **\nSource file cannot be deleted !";
            exit(QNETCOPY_CANNOT_DELETE_SOURCE_FILE);
        }
    }

    // everything is ok !
    return 0;
}
