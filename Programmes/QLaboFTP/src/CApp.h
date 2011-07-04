/********************************* CApp.h *****************************************
 *                                                                                *
 *   #include "CApp.h"                                                            *
 *   Project: MedinTux                                                            *
 *   Copyright (C) 2003 2004 2005 by Sevin Roland  and Data Medical Design        *
 *   E-Mail: data.medical.design@club-internet.fr                                 *
 *                                                                                *
 *   This program is free software; you can redistribute it and/or modify         *
 *   it under the terms of the CeCILL Version 1 du 21/06/2004                     *
 *   License (GPL compatible)                                                     *
 *                              http://www.cecill.info/                           *
 *   as published by :                                                            *
 *                                                                                *
 *   Commissariat à l'Energie Atomique                                            *
 *   - CEA,                                                                       *
 *                            31-33 rue de la Fédération, 75752 PARIS cedex 15.   *
 *                            FRANCE                                              *
 *   Centre National de la Recherche Scientifique                                 *
 *   - CNRS,                                                                      *
 *                            3 rue Michel-Ange, 75794 Paris cedex 16.            *
 *                            FRANCE                                              *
 *   Institut National de Recherche en Informatique et en Automatique             *
 *   - INRIA,                                                                     *
 *                            Domaine de Voluceau, Rocquencourt, BP 105, 78153    *
 *                            FRANCE                                              *
 *                                                                                *
 *         This program is distributed in the hope that it will be useful,        *
 *         but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *         MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                   *
 *         CeCILL  License (GPL compatible) for more details.                     *
 *                                                                                *
 **********************************************************************************/

#ifndef C_APP_H
#define C_APP_H

#include <qobject.h>
#include <qstring.h>
#include "../../MedinTuxTools/CMedicaBase.h"
#include "../../MedinTuxTools/CW_EditText.h"
#include "../../MedinTuxTools/CSetupBase.h"
#include "../../MedinTuxTools/CMedicaBase.h"

#include "CGetDatasempAppCtx.h"
#include <qapplication.h>
#include <qsqldatabase.h>
#include <qtextedit.h>
#include <qprogressbar.h>
#include <qprogressdialog.h>
#include <qthread.h>




//================================================= CApp ==============================================================
class CApp : public QApplication , public CGetDatasempAppCtx, public CSetupBase
{
 public:

 enum UPDATE_MODE
    {   NoMode              = 0,
        Remove              = 1,
        Insert              = 2,
        Update              = 4,
        MajFiles            = 7,
        SqlFiles            = 8,
        AllUpdate           = 15,
        Force               = 16

    };
    CApp(int & argc, char ** argv);
    ~CApp();
    QSqlDatabase*  SetOneBase(        QString driver,              // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
                                      QString dataBaseName,        // nom de la base: si QODBC3 -> nom de la source de données (userDSN)
                                      QString user,                // = "root"
                                      QString passWord,            // = ""
                                      QString hostName,            // = "localhost"
                                      CW_EditText  *logWidget,     // QEdit pour afficher les logs
                                      QProgressBar *pQProgressBar, // progress_barr
                                      long enr_tot = 340535        // = 340535
                               );
    QSqlDatabase*  SetBase( QString driver,        // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
                            QString dataBaseName,    // nom de la base: si QODBC3 -> nom de la source de données (userDSN)
                            QString user,            // = "root"
                            QString passWord,        // = ""
                            QString hostName,        // = "localhost"
                            CW_EditText  *logWidget,
                            QProgressBar *pQProgressBar,
                            long enr_tot = 340535
                          );
    QSqlDatabase*  GetMySQL_DataBase(QString user, QString hostName, CW_EditText  *logWidget);
    void RemoveAllDesignerVersion(const  QString &path);
    void RemoveDesignerVersion(QString &txt);
    void InsertData(QSqlDatabase *dataBase, const QString &fname,      QProgressBar *pQProgressBar=0);
    void ParseSQL_Dump(QSqlDatabase *dataBase, const QString &fname,   QProgressBar *pQProgressBar=0, CW_EditText *logWidget=0 );
    void ParseSQL_InsertInto(QString &text, long &line_number, QSqlDatabase *dataBase, QProgressBar *pQProgressBar  = 0, CW_EditText *logWidget  = 0 );
    int  ExecSQL_File(QSqlDatabase *dataBase, const QString & fname,   QProgressBar *pQProgressBar=0);
    int  CreationTables(QSqlDatabase *dataBase, const QString & fname, QProgressBar *pQProgressBar=0);
    int  OutSQL_error( const QSqlQuery &cur, const char *messFunc =0, const char *requete =0);
    void convertBinBlobsGG(QString &text);
    int  JumpToEndDataBloc(int pos, QString &text);
    void SetProgressPosition(long pos){m_position=pos;};
    long GetProgressPosition(){return m_position;};
    //................... fonctions d'installation et mise à jour Datasemp .............................................
    QSqlDatabase*    Datasemp_CreateBases(  QString driver,              // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
                                            QString dataBaseName,        // nom de la base: si QODBC3 -> nom de la source de données (userDSN)
                                            QString user,                // = "root"
                                            QString passWord,            // = ""
                                            QString hostName,            // = "localhost"
                                            CW_EditText *logWidget,
                                            int         *isThisBaseExist
                                          );
    void             Datasemp_OutMessage( CW_EditText *logWidget, const QString &mess);
    QString          Datasemp_GetBaseVersion(QSqlDatabase* dataBase, QString *numEdition=0, QString *packBCArrete=0, QString *packIRArrete=0);
    long             Datasemp_Maj_Update(QSqlDatabase* pDataBase, const QString &srcPath, const QString &baseODS, UPDATE_MODE mode=CApp::NoMode, CW_EditText *logWidget=0);
    QString          Datasemp_Maj_Update(const QString &fname,
                                     long &nb_sqlLine,
                                     UPDATE_MODE mode        = CApp::AllUpdate,     // = CApp::AllUpdate ,
                                     QSqlDatabase* pDataBase = 0,                   // = 0  si pas egal zero alors les requetes SQL de mise à jour seront executées
                                     const char* fileOut     = 0                    // = 0  si pas egal zero alors le fichier SQL de mise à jour sera ecrit
                                    );
    long             Datasemp_Maj_GetMajList(const QString &srcPath, const QString &baseVersion, QStringList &list);
    QString          Datasemp_Maj_ExtractValue(char* &pt, const char* end, const char * sep_str="@[~\0x00\0x00");
    QString          Datasemp_Maj_GetDiskVersion(const QString &fname);
    QString          Datasemp_Maj_UpdateInTable(char* &ptIn, char* end, const QString &table, int doIt, long &nb_sqlLine, QSqlDatabase* pDataBase);
    QString          Datasemp_Maj_InsertInTable(char* &ptIn, char* end, const QString &table, int doIt, long &nb_sqlLine, QSqlDatabase* pDataBase);
    QString          Datasemp_Maj_DeleteInTable(char* &ptIn, char* end, const QString &table, int doIt, long &nb_sqlLine, QSqlDatabase* pDataBase);
    QString          Datasemp_Maj_DecodeSpecialCar(const QString &val);



private:
    long          m_position;
    QSqlDatabase *m_MySQL_DataBase;
};

extern CApp* G_pCApp;

#endif

