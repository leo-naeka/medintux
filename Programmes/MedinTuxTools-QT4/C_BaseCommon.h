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
#define   DB_TIME_TO_RECONNECT     3600000  //reconnexion toutes les heures
//=================================================== C_BaseCommon ====================================================
class C_BaseCommon: public QObject, public C_Log
{

Q_OBJECT


public:
    enum flags  {WhereMustBeAdd = 0,
                 WhereAlreadyIn = 1
                };
    enum GUID_Mode {
            byQT        = 0,        // algorithme de QT
            byMyself    = 1         // algorithme interne ? MedinTux
        };
    enum Create_Mode {
            DropIfExists     = 1,        //
            OnlyIfNotExits   = 0         //
        };

    C_BaseCommon(QObject *parent);
    ~C_BaseCommon();
    //---------------------------------------- BaseConnect -------------------------------------------------------
    bool               BaseConnect(const QString &param, const QString &baseLabel,const QString &dataBase="", QString * errMess = 0, const QString &section   = "Connexion" );
    bool               BaseConnect(const QString &baseLabel,    // 0
                                   const QString &driver,       // 1
                                   const QString &dataBase,     // 2
                                   const QString &user ,        // 3
                                   const QString &_password ,   // 4
                                   const QString &hostname ,    // 5
                                   int port,                    // 6
                                   int      timeToReconnect = DB_TIME_TO_RECONNECT,
                                   QString *errMess         = 0);

    //---------------------------------------- EncodePassword_InConnectionParam -------------------------------------------------------
    static bool        EncodePassword_InConnectionParam(const QString &param, const QString& section, QString *errMess=0);
    //---------------------------------------- EncodePassword_InConnectionParam -------------------------------------------------------

    //-----------------------------------------------------  isThisTableExist -------------------------------------------
     /*! \brief database().tables(QSql::Tables ); return all tables of all databases not just the tables list
      * of our connected database. The way is to see if table selection is possible.
      *  \param  table_name the table name
      *  \return 1/all is ok 0/table not exists
      */
    bool         isThisTableExist(const QString &table);
    //-----------------------------------------------------  tablesList -------------------------------------------
     /*! \brief database().tables(QSql::Tables ); return all tables of all databases not just the tables list
      *  of our connected database. A way is to see if table selection is possible. Its not very fast ...
      *  \return tablesList
      */
    QStringList   tablesList();

    QSqlDatabase  database();
    //............ utilities .............................
    QString     isThisValueLikeInTable(       const QString &tableName, const QString &fieldToTest, const QString &test_value,     const QString fieldToRetrieve = "" , const QString &wand  = "" );
    QStringList isThisValueLikeInTable_ToList(const QString &tableName, const QString &fieldToTest, const QString &test_value,     const QString fieldToRetrieve = "" , const QString &wand  = "");
    QString     isThisValueInTable(           const QString &tableName, const QString &fieldToTest, const QString &test_value,     const QString fieldToRetrieve = "" , const QString &wand  = "");
    QStringList isThisValueInTable_ToList(    const QString &tableName, const QString &fieldToTest, const QString &test_value,     const QString fieldToRetrieve = "" , int keepEmpty = 1, const QString &wand  = "");
    bool        updateValueInTable( const QString &tableName, const QString &fieldToUpdate, const QString &value, const QString &valueToTest, const QString &fieldToTest="" );
    bool        deleteRecordInTable(const QString &tableName, const QString &valueToTest,   const QString &fieldToTest="" );

    int         dropBase(const QString &baseName);
    int         createBase(const QString &baseName, int createMode = C_BaseCommon::OnlyIfNotExits);
    int         dropTable(const QString &tableName);
    int         createTable(const QString &requete);
    int         eraseTable(const QString &tableName);
    QString     getLastPrimaryKey(    const QString &table, const QString &pk_field_name, const QString &uniqueValue ="", const QString &fieldWhereIsUniqueValue ="");
    QString     getLastError();
    long        countRecords(const QString & tableName, const QString &whereMention = "" );
    C_BaseCommon::GUID_Mode get_GUID_CreateMode();
    QString       GUID_Create();
    //------------------------------------------- signalisateurs graphiques -------------------------------------------
    void         setStatusWidget(QLabel *statusWidget);                   // statusWidget
    QLabel      *statusWidget();
    void         statusWidgetSetText(const QString & text);
    void         setProgressWidget(QProgressBar *pQProgressBar);  //progressWidget
    QProgressBar *progressWidget();

    //............... insertion SQL .......................................
    unsigned long  readLine(QFile *pQFile, char *buffer, QString &outParam, unsigned long nbMax);
    void           executeSQL( const QString &fname, QProgressBar *pQProgressBar  = 0 , QTextEdit *logWidget  = 0 );
    void           parseSQL_InsertInto(QString &text, QTextEdit *logWidget);
    int            posFirstNonSpace(const QString &line);
    int            posLastEnclosedSymbol(const QString &str,   const QString &symbolOuvrant, const QString &symbolFermant, int *posFermant_out=0);
    //............ gestion des owner ......................
    QStringList ownerList();
    QString     ownersSelectMention( const QString &tableName,  C_BaseCommon::flags = C_BaseCommon::WhereAlreadyIn );
    bool        isInOwnerList(const QString &owner);
    void        addOwner     (const QString &owner);
    QString     addOwnerWandMention(QString &requete, const QString &tableName, const QString &wand);
protected:
    long          m_position;
    QLabel       *m_StatusWidget;
    QProgressBar *m_pQProgressBar;
    void          setLastError(const QString &error);

private:
    QStringList   m_ownerList;
    QString       m_BaseLabel;
    QString       m_LastError;
    int           m_LineNum;
    QTimer       *m_pReconnectTimer;
    GUID_Mode     m_GUID_CreateMode;

private slots:
    void Slot_ReconnectTimerDone();
};
#endif // C_BASECOMMON_H
