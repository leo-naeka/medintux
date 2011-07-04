#ifndef C_BASECOMMON_H
#define C_BASECOMMON_H
#include <QString>
#include <QObject>
#include <QStringList>
#include "C_Utils_Log.h"

class QSqlQuery;
class QSqlError;
class QSqlDatabase;
class QTimer;
class QTextEdit;
class QProgressBar;
class QFile;
class QProgressBar;
class QLabel;

class C_BaseCommon: public QObject, public C_Log
{

Q_OBJECT


public:
    enum flags  {WhereMustBeAdd = 0,
                 WhereAlreadyIn = 1
                };


    C_BaseCommon(QObject *parent);
    ~C_BaseCommon();
    bool               BaseConnect(const QString &param, const QString &baseLabel,const QString &dataBase="", QString * errMess = 0);
    QSqlDatabase       database();
    //............ utilities .............................
    QString     isThisValueLikeInTable(       const QString &tableName, const QString &fieldName, const QString &value,     const QString fieldToRetrieve = "" );
    QStringList isThisValueLikeInTable_ToList(const QString &tableName, const QString &fieldName, const QString &value,     const QString fieldToRetrieve = "" );
    QString     isThisValueInTable(       const QString &tableName, const QString &fieldName, const QString &value,     const QString fieldToRetrieve = "" );
    QStringList isThisValueInTable_ToList(const QString &tableName, const QString &fieldName, const QString &value,     const QString fieldToRetrieve = "" );


    //------------------------------------------- signalisateurs graphiques -------------------------------------------
    void         setStatusWidget(QLabel *statusWidget);                   // statusWidget
    QLabel      *statusWidget();
    void         statusWidgetSetText(const QString & text);
    //void         setLogWidget(QTextEdit *logWidget);              //  logWidget
    //QTextEdit   *logWidget();
    void         setProgressWidget(QProgressBar *pQProgressBar);  //progressWidget
    QProgressBar *progressWidget();

    long        countRecords(const QString & tableName);
    //............... insertion SQL .......................................
    unsigned long  readLine(QFile *pQFile, char *buffer, QString &outParam, unsigned long nbMax);
    void           executeSQL( const QString &fname, QProgressBar *pQProgressBar  = 0 , QTextEdit *logWidget  = 0 );
    void           parseSQL_InsertInto(QString &text, QTextEdit *logWidget);

    int         dropTable(const QString &tableName);
    int         createTable(const QString &requete);
    int         eraseTable(const QString &tableName);
    int         posFirstNonSpace(const QString &line);
    int         posLastEnclosedSymbol(const QString &str,   const QString &symbolOuvrant, const QString &symbolFermant, int *posFermant_out=0);
    QString     getLastPrimaryKey(    const QString &table, const QString &pk_field_name);
    QString     getLastError();
    //............ gestion des owner ......................
    QStringList ownerList();
    QString     ownersSelectMention( const QString &tableName,  C_BaseCommon::flags = C_BaseCommon::WhereAlreadyIn );
    bool        isInOwnerList(const QString &owner);
    void        addOwner     (const QString &owner);
protected:
    long          m_position;
    QLabel       *m_StatusWidget;
    QProgressBar *m_pQProgressBar;
private:
    void        setLastError(const QString &error);

private:
    QStringList   m_ownerList;
    QString       m_BaseLabel;
    QString       m_LastError;
    int           m_LineNum;
    QTimer       *m_pReconnectTimer;

private slots:
    void Slot_ReconnectTimerDone();
};

#endif // C_BASECOMMON_H
