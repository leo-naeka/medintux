#ifndef MYFTP_H
#define MYFTP_H

#include "CFtpTools.h"
#include "Global.h"
#include "CFtpInfo.h"
#include <qtimer.h>
#include <qobject.h>
#include <qfile.h>
#include <qstring.h>

class MyFtp : public QObject
{
    Q_OBJECT

public:

    MyFtp(QObject * parent, const char * name = 0, bool log = FALSE, bool remove = FALSE);
    ~MyFtp();
    void Log(bool log = FALSE);
    void removeDistantFile(bool remove = FALSE);
    void signalFileDownloaded( QString filename );
    void listFormatUnix( const QString &state);
    void disconnectFTP();

public slots :

    void removeFile( QString newName ); // connecté au signal CAnalyse::fileAnalysed()
    void uselessFile(QString newName ); // connecté au signal CAnalyse::fileUseless()
    void LetScanFTP();
    void toLog(QString stringlog);

protected slots:

    //void LetScanFTP();
    void checkDownload();
    void stateFTP_changed(int etat);
    void Finished(int id, bool error);
    void Started(int id);
    void ListChanged(const QUrlInfo &objet);
    void DownloadFile(CFtpInfo info);

signals:

    void newFileDownloaded( QString );
    // signal pour les changements d'état de la led
    void ftpStateChanged( QString );

private:

    QTimer    *m_ScanTimer;
    QTimer    *m_DownloadTimer;
    CFtpTools *m_FtpTools;
    QFile     *m_LogFile;
    CommandMap m_CommandMap;
    FileMap    m_FileMap;
    RemoveMap  m_RemoveMap;
    CFtpFileInfoList   m_FileList;
    CFtpFileInfoList   m_FileToDownload;
    CFtpFileInfoList   m_FileToAnalyse;
    CFtpFileInfoList   m_FileToRemove;
    bool       m_Log;
    bool       m_removeDistantFile;

    QString    commandToString(CFtp::Command command);
    QString    errorToString(CFtp::Error error);
    int        retrieveAncienNameFileToDownload(const QString &ancien_name);
    int        retrieveAncienNameFileList(const QString &ancien_name);
    int        retrieveAncienNameFileToAnalyse(const QString &ancien_name);
    CFtpInfo   retrieveFileToDownloadWithIndex(int index);
    CFtpInfo   retrieveFileToAnalyseWithNewName(const QString &new_name);
    CFtpInfo   retrieveFileToRemoveWithIndex(int index);

};

#endif //MYFTP_H


