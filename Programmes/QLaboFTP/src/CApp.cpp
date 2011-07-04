/********************************* CApp.cpp ***************************************
 *                                                                                *
 *   #include CApp.h"                                                             *
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
//
//    mysqldump --quote-name --compatible=mysql323 CCAMTest | gzip > /home/ro/CCAMTest.gz
//    Les spectatrices ne veulent pas qu'on les ennuie dans la file.
#include <qdir.h>
#include <qfileinfo.h>
#include <qmessagebox.h>
#include <qtextstream.h>
#include <qsqlquery.h>
#include <qsqlcursor.h>
#include <qcursor.h>
#include <qtextcodec.h>

#include "CApp.h"


CApp* G_pCApp = 0;  // contiendra l'instance globale de l'application
//--------------------------------------------- CApp -------------------------------------------------------------------
CApp::CApp(int & argc, char ** argv)
    : QApplication (  argc, argv ), CGetDatasempAppCtx(  argc, argv ), CSetupBase(), m_MySQL_DataBase(0)
{QTextCodec::setCodecForTr( QTextCodec::codecForName("utf8") );
 G_pCApp          = this;
}

//--------------------------------------------- CApp -------------------------------------------------------------------
CApp::~CApp()
{G_pCApp          = 0;
    if (m_MySQL_DataBase)
    {if (m_MySQL_DataBase->isOpen()) m_MySQL_DataBase->close();
        QSqlDatabase::removeDatabase (m_MySQL_DataBase);
    }
}

//--------------------------------------------------- GetMySQL_DataBase ------------------------------------------------
QSqlDatabase*  CApp::GetMySQL_DataBase(QString user , QString hostName, CW_EditText  *logWidget)
{
 if (m_MySQL_DataBase) return m_MySQL_DataBase;
     QString errMess ;
     int     errNum ;
     //..................... ouvrir la base mysql ...............................................................
     m_MySQL_DataBase = BaseConnect("QMYSQL3", "mysql", user, "", hostName, "TestBase", &errMess, &errNum);
     if (m_MySQL_DataBase==0)
     {   QString outMess  =     QObject::tr("============== Échec de la connexion à la base MySQLl =============================================\n") ;
         outMess         +=     errMess + " " + QString::number(errNum) ;
         Datasemp_OutMessage(logWidget, outMess) ;
         return 0;
     }
     return m_MySQL_DataBase;
}

//-----------------------------------------------------  SetOneBase -------------------------------------------
QSqlDatabase*  CApp::SetOneBase(      QString driver,              // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
                                      QString dataBaseName,        // nom de la base: si QODBC3 -> nom de la source de données (userDSN)
                                      QString user,                // = "root"
                                      QString passWord,            // = ""
                                      QString hostName,            // = "localhost"
                                      CW_EditText  *logWidget,     // QEdit pour afficher les logs
                                      QProgressBar *pQProgressBar, // progress_barr
                                      long enr_tot                 // = 340535
                                      )
{m_position                 = 0;
    pQProgressBar->setTotalSteps(enr_tot);
    QString        baseToSet  = dataBaseName;
    QString          outMess  = "";
    QString          errMess  = "";
    int               errNum  = 0;
    char                 *pt  = (char*)(const char*) m_ParamData;
    int            ret_create = FALSE;
    QString            nb_pas = "";
    QString   dataBaseConName = "SetupTest";
    QSqlDatabase* dataBase    = 0;
    QSqlDatabase* mysql_base  = GetMySQL_DataBase(user, hostName, logWidget);       // base MySQL pour creer les bases
    if (mysql_base ==0) return 0;


    while((pt = CGestIni::Param_GotoNextSection(pt, 0, &dataBaseName)) && *pt)     // recupere le nom de la section dans  dataBaseName
    {if (dataBaseName.mid(3)== baseToSet)
        {dataBaseName = baseToSet;
            if (G_pCApp->Param_ReadParam( dataBaseName, "Connexion", &driver, &dataBaseName, &user, &passWord, &hostName) ==0 // zero = pas d'erreur
                )
            {ret_create = CreationBase(mysql_base, dataBaseName, &errMess, 0, driver, user, passWord, hostName);
            }
            //if (G_pCApp->Param_ReadParam( dataBaseName, "nb_progress", &nb_pas) ==0 ) enr_tot = nb_pas.toLong();
            if ( ret_create != 1 )
            {outMess = QObject::tr(" La base  ")+ dataBaseName +QObject::tr(" n'a pu être créée (elle existe probablement déjà) \n");
                Datasemp_OutMessage(logWidget, outMess) ;
                ret_create =  QMessageBox::information( 0,    QObject::tr(  " MedinTux Setup "),
                                                              QObject::tr ( "La base : <b>") + dataBaseName +
                                                              QObject::tr ( "</b><br> semble déjà exister <br>"
                                                                            "faut-il l'effacer et la recréer <br>"
                                                                            "ou annuler l'opération en cours ?<br>") ,
                                                              QObject::tr("Annu&ler"), QObject::tr("&Recréer"), 0,
                                                        1, 1 ) ;
                if (ret_create==1)
                {if (!DropBase(mysql_base, dataBaseName, &outMess, &errNum ))
                    {outMess.prepend(QObject::tr("============== Échec de l'effacement de la base  ")+ dataBaseName +QObject::tr(" ======================================\n"));
                        Datasemp_OutMessage(logWidget, outMess);
                        ret_create = 0;
                    }
                    else
                    {ret_create = CreationBase(mysql_base, dataBaseName, &errMess, &errNum);
                        if ( ret_create == 1 ) outMess = QObject::tr("============== Succès de l'effacement de la base ")+ dataBaseName +QObject::tr(" ======================================\n");
                        Datasemp_OutMessage(logWidget, outMess);
                    }
                }
            } //end if else(dataBase ==0 )
            if ( ret_create == 1 )   // si la creation de la base s'est passée normalement
            {        //............... Ouverture de la base et remplissage....................................
                outMess  =      QObject::tr("============== Création de la base ")+ dataBaseName +QObject::tr(" ============================================\n") ;
                Datasemp_OutMessage(logWidget, outMess) ;
                // on se connecte à la nouvelle base
                dataBase =  BaseConnect( driver  ,        // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
                                         dataBaseName,    // nom de la base: si QODBC3 -> nom de la source de données (userDSN)
                                         user,            // = "root"
                                         passWord,        // = ""
                                         hostName,        // = "localhost"
                                         dataBaseConName+dataBaseName,
                                         &errMess,
                                         &errNum );
                if (dataBase==0)
                { outMess  = QObject::tr("============== Échec de la création de la base ")+ dataBaseName +QObject::tr(" ======================================\n") ;
                    outMess += errMess + " " + QString::number(errNum) ;
                    Datasemp_OutMessage(logWidget, outMess) ;
                }
                else
                {QApplication::setOverrideCursor( QCursor( Qt::WaitCursor ) );
                    //............... Ok la base a bien été créée ....................................
                    outMess  = QObject::tr("La base de données ")+ dataBaseName +QObject::tr(" a été créée avec succès \n");
                    Datasemp_OutMessage(logWidget, outMess) ;
                    //............... Création des tables ............................................
                    QString file, var_name;
                    while (*pt && *pt != '[')
                    {pt = CGestIni::Param_ExtraireNextValeurs(pt, var_name, &file);
                        if (var_name=="CreateTable")
                        {Datasemp_OutMessage(logWidget,QObject::tr(" Création de la table :   ")+ file +" en cours....");
                            CreationTables(dataBase, m_PathAppli + QDir::separator()+ "SqlCreateTable" + QDir::separator() + file, pQProgressBar);
                        }
                        if (var_name=="InsertData")
                        {Datasemp_OutMessage(logWidget,QObject::tr(" Insertion de données dans la table :   ")+ file +" en cours....");
                            InsertData(dataBase,   m_PathAppli + QDir::separator()+ "SqlCreateTable" + QDir::separator() + file, pQProgressBar);
                        }
                        if (var_name=="ParseSQL_Dump")
                        {Datasemp_OutMessage(logWidget,QObject::tr(" Exécution du fichier de requêtes SQL   ")+ file +" en cours....");
                            ParseSQL_Dump(dataBase,  m_PathAppli + QDir::separator()+ "SqlCreateTable" + QDir::separator() + file, pQProgressBar, logWidget);
                        }
                        var_name = "";
                    } // end while (*pt && *pt != '[')
                    QApplication::restoreOverrideCursor();
                } // end else if if (dataBase==0)
            }  //end if (dataBase ==0 )
            else
            {outMess = QObject::tr(" Opération annulée : la base ")+ dataBaseName +QObject::tr(" n'a pu être créée (elle existe probablement déjà) \n");
                Datasemp_OutMessage(logWidget, outMess) ;
            } //end if else(dataBase ==0 )
        } // end if (dataBaseName.left(3)=="DB_")
        dataBaseName = "";
    } //end while((pt = CGestIni::Param_GotoNextSection(pt, 0, &dataBaseName)) && *pt)
    outMess  = QObject::tr("  Analyse de : ")+ QString::number(m_position) +QObject::tr(" lignes effectuée \n");
    Datasemp_OutMessage(logWidget, outMess) ;
    return dataBase;
}

//-----------------------------------------------------  SetBase -------------------------------------------
QSqlDatabase*  CApp::SetBase(      QString driver,              // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
                                   QString dataBaseName,        // nom de la base: si QODBC3 -> nom de la source de données (userDSN)
                                   QString user,                // = "root"
                                   QString passWord,            // = ""
                                   QString hostName,            // = "localhost"
                                   CW_EditText  *logWidget,     // QEdit pour afficher les logs
                                   QProgressBar *pQProgressBar, // progress_barr
                                   long enr_tot                 // = 340535
                                   )
{m_position                 = 0;
    pQProgressBar->setTotalSteps(enr_tot);
    QString          outMess  = "";
    QString          errMess  = "";
    int               errNum  = 0;
    char                 *pt  = (char*)(const char*) m_ParamData;
    int            ret_create = FALSE;
    QString   dataBaseConName = "SetupTest";
    QSqlDatabase* dataBase    = 0;
    QSqlDatabase* mysql_base  = GetMySQL_DataBase(user, hostName,logWidget);       // base MySQL pour creer les bases
    if (mysql_base ==0) return 0;


    while((pt = CGestIni::Param_GotoNextSection(pt, 0, &dataBaseName)) && *pt)     // recupere le nom de la section dans  dataBaseName
    {if (dataBaseName.left(3)=="DB_")
        {dataBaseName = dataBaseName.mid(3);
            if (G_pCApp->Param_ReadParam( dataBaseName, "Connexion", &driver, &dataBaseName, &user, &passWord, &hostName) ==0 // zero = pas d'erreur
                )
            {ret_create = CreationBase(mysql_base, dataBaseName, &errMess, &errNum);
            }

            if ( ret_create == 1 )   // si la creation de la base s'est passée normalement
            {        //............... Ouverture de la base et remplissage....................................
                outMess  =      QObject::tr("============== Création de la base ")+ dataBaseName +QObject::tr(" ============================================\n") ;
                Datasemp_OutMessage(logWidget, outMess) ;
                // on se connecte à la nouvelle base
                dataBase =  BaseConnect( driver  ,        // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
                                         dataBaseName,    // nom de la base: si QODBC3 -> nom de la source de données (userDSN)
                                         user,            // = "root"
                                         passWord,        // = ""
                                         hostName,        // = "localhost"
                                         dataBaseConName+dataBaseName,
                                         &errMess,
                                         &errNum );
                if (dataBase==0)
                { outMess  = QObject::tr("============== Échec de la création de la base ")+ dataBaseName +QObject::tr(" ======================================\n") ;
                    outMess += errMess + " " + QString::number(errNum) ;
                    Datasemp_OutMessage(logWidget, outMess) ;
                }
                else
                {//............... Ok la base a bien été créée ....................................
                    outMess  = QObject::tr("  La base de données ")+ dataBaseName +QObject::tr(" a été créée avec succès \n");
                    Datasemp_OutMessage(logWidget, outMess) ;
                    //............... Création des tables ............................................
                    QString file, var_name;
                    while (*pt && *pt != '[')
                    {pt = CGestIni::Param_ExtraireNextValeurs(pt, var_name, &file);
                        if (var_name=="CreateTable")
                        {Datasemp_OutMessage(logWidget,QObject::tr(" Création de la table  ")+ file +" en cours....");
                            CreationTables(dataBase, m_PathAppli + QDir::separator()+ "SqlCreateTable" + QDir::separator() + file, pQProgressBar);
                        }
                        if (var_name=="InsertData")
                        {Datasemp_OutMessage(logWidget,QObject::tr(" Insertion de données dans la table  ")+ file +" en cours....");
                            InsertData(dataBase,   m_PathAppli + QDir::separator()+ "SqlCreateTable" + QDir::separator() + file, pQProgressBar);
                        }
                        if (var_name=="ParseSQL_Dump")
                        {Datasemp_OutMessage(logWidget,QObject::tr(" Exécution du fichier de requêtes SQL   ")+ file +" en cours....");
                            ParseSQL_Dump(dataBase,  m_PathAppli + QDir::separator()+ "SqlCreateTable" + QDir::separator() + file, pQProgressBar, logWidget);
                        }
                        var_name = "";
                    } // end while (*pt && *pt != '[')
                } // end else if if (dataBase==0)
            }  //end if (dataBase ==0 )
            else
            {outMess = QObject::tr(" Opération annulée : la base ")+ dataBaseName +QObject::tr(" n'a pu être créée (elle existe probablement déjà) \n");
                Datasemp_OutMessage(logWidget, outMess) ;
            } //end if else(dataBase ==0 )
        } // end if (dataBaseName.left(3)=="DB_")
        dataBaseName = "";
    } //end while((pt = CGestIni::Param_GotoNextSection(pt, 0, &dataBaseName)) && *pt)
    outMess  = QObject::tr("  Analyse de : ")+ QString::number(m_position) +QObject::tr(" lignes effectuée \n");
    Datasemp_OutMessage(logWidget, outMess) ;
    return dataBase;
}

//-----------------------------------------------------  RemoveDesignerVersion -------------------------------------------
void  CApp::RemoveDesignerVersion(QString &txt)
{   int deb = txt.find("version=\"");
    if (deb == -1) return;
    int end =  txt.find("\"", deb+9);
    if (end == -1) return;
    txt.replace(deb, end+1-deb, "version=\"0.0\"");
}

//-----------------------------------------------------  RemoveAllDesignerVersion -------------------------------------------
void  CApp::RemoveAllDesignerVersion(const QString &path_in)
{   QString    path(path_in);
    QDir       qDir;
    int        i = 0;
    qDir.setPath ( path );
    qDir.convertToAbs();
    path = qDir.path();
    qDir.setFilter( QDir::All | QDir::NoSymLinks );

    //............ exploration de la liste ......................
    const QFileInfoList * pQFileInfoList = qDir.entryInfoList();
    if (pQFileInfoList==0) return ;
    QFileInfoListIterator it( *pQFileInfoList );
    QFileInfo     *fi;
    while ( (fi = it.current()) != 0 )
    {QString fname = fi->fileName().latin1();
        if      (fname == "..")
        {
        }
        else if (fi->isDir() && fname != "." )
        {
        }
        else if (fi->isFile())
        {QString file_buffer;
            if (fname.right(3).lower()==".ui")
            {   fname.prepend(path_in+QDir::separator());
                Param_UpdateFromDisk(fname, file_buffer);
                RemoveDesignerVersion(file_buffer);
                Param_UpdateToDisk(fname, file_buffer);
            }
        }
        ++it;
        ++i;
    }
}

//-----------------------------------------------------  ParseSQL_Dump -------------------------------------------
void  CApp::ParseSQL_Dump(QSqlDatabase *dataBase, const QString &fname, QProgressBar *pQProgressBar /* = 0 */, CW_EditText *logWidget /* = 0 */)
{   //....................... ouvrir le fichier en mode QTextStream ...........................
    if ( !QFile::exists( fname ) )   return;
    QFile file( fname );
    if ( !file.open( IO_ReadOnly ) ) return;
    QTextStream stream ( &file );
    //.......... on déclare une variable pour lire le fichier ligne à ligne ..................
    char *pt;
    QString requete       = "";
    QString table_name    = "";
    QString line          = "";
    long    line_number   = 0;
    QSqlQuery query(QString::null, dataBase);

    while (!stream.atEnd())
    {   line  = stream.readLine().stripWhiteSpace();
        ++line_number;
        //.................creation de la table .....................
        if (line.left(12).upper()=="CREATE TABLE")
        {if (pQProgressBar) pQProgressBar->setProgress(++m_position);
            int pos = line.find("(",12);
            if ( pos != -1 )
               {table_name = line.mid(12, pos-12);
                Datasemp_OutMessage(logWidget, QObject::tr("Création de la table ") + table_name + QObject::tr(" en cours....")) ;
               }
            requete = line;
            while (!stream.atEnd())
            {   if (pQProgressBar) pQProgressBar->setProgress(++m_position);
                line     = stream.readLine().stripWhiteSpace();
                ++line_number;
                requete += line;
                if (line.left(13) == ") TYPE=MyISAM" || line.left(15) == ") ENGINE=MyISAM" )  // ne surtout pas inclure ';' dans la comparaison
                {   query.exec(QString( "DROP TABLE IF EXISTS " + table_name + ";"));
                    OutSQL_error(query, "ERREUR DROP TABLE:   ParseSQL_Dump()", table_name );
                    query.exec(requete);
                    OutSQL_error(query, "ERREUR CREATE TABLE: ParseSQL_Dump()", requete );
                    break;
                }
            }
        }
// INSERT INTO `RubriquesHead` VALUES (1,'30DC82DD-7632-2C46-9DC3-BC1AC0ECD20A',20030000,'Asthme sai','2004-12-08 19:23:41','admin',0,0);
// INSERT INTO `RubriquesHead` VALUES (2,'30DC82DD-7632-2C46-9DC3-BC1AC0ECD20A',20020200,'Bilan labo complet','2004-12-08 19:23:41','admin',0,0);
// INSERT INTO `ACCES2` VALUES ('A','à foyer ouvert'),('A','par ... abord '),('A','par dissection ...');
// INSERT INTO `codes_postaux` (`id`,`code_postal`,`ville`) VALUES
//                             (26662,62153,'ABLAIN ST NAZAIRE'),
//                             (35076,80320,'ABLAINCOURT PRESSOIR');

        else if (line.left(11).upper()=="INSERT INTO")
        {   if (pQProgressBar) pQProgressBar->setProgress(++m_position);
            long len_line;
            requete   = "";
            //..................... isoler les données à inserer ............................................
            do
             {
              len_line = line.length();
              pt       = (char*)(const char*)line;
              if (len_line>2 && line.mid(len_line-2) == ");")  // ne surtout pas inclure ';' dans la comparaison
                 {//convertBinBlobsGG(line);
                  requete += line;
                  ParseSQL_InsertInto(requete, line_number, dataBase, pQProgressBar, logWidget );
                  break;
                 }
              requete += line;
              line     = stream.readLine().stripWhiteSpace();
              ++line_number;
              if (pQProgressBar) pQProgressBar->setProgress(++m_position);
             } while (!stream.atEnd());
        }
    }
}

//------------------------- convertBinBlobsGG -------------------------------------------------------------
// Y a un mec en france médecin comme moi, qui s'appelle Gérard Delafond, une espèce de pingouin quoi ;) qui pour
// convertir les données de son logiciel pour MedinTux a produit de curieux SQL Dump avec ce style d'insertion
// binaire en format hexa, une fois précédée de l'apostrophe, parfois introduite brutalement sans appostrophe
// bref il a fallu faire cette routine que pour lui !!!
//
//  INSERT INTO `rubriquesblobs` (`RbDate_PrimKey`,`RbDate_DataRub`) VALUES
//   (3, 0x5B416E74E963E9640A00),
//   (18,0x3C3F786DD0A00);
//  INSERT INTO `rubriquesblobs` (`RbDate_PrimKey`,`RbDate_DataRub`) VALUES
//   (3, `0x5B416E74E963E9646560D0A00`),
//   (18,`0x3C3F786D6C2076657273696F6E3D2231200`);
//
void  CApp::convertBinBlobsGG(QString &text)
{int        deb = 0;
 int        fin = 0;
 char       sep = 0;

 if       ((deb=text.find("'0x",0))!=-1) sep = ' ';
 else if  ((deb=text.find("`0x",0))!=-1) sep = ',';
 else if  ((deb=text.find(",0x",0))!=-1) sep = ',';

 if  (sep)
     {if ((fin = text.find(")",deb))!=-1)
         {char       car = 0;
          char        c0 = 0;
          char        c1 = 0;
          char       *pt = (char*)(const char*)text+deb+3;
          QString result = QString(QChar(sep)) + "\'";
          while (pt[0]!=')')
                {//....................... eviter la casse .................................
                 c0 = pt[0] | 32;         // minusculer le poids fort
                 c1 = pt[1] | 32;         // minusculer le poids faible
                 //....................... Hexa to numérique ...............................
                 if      (c0>='a'&& c0<= 'f')  car  = (c0-'W')<<4;  // a (97) - W (87) --> 10
                 else                          car  = (c0-'0')<<4;  // 0 (48) - 0 (48) --> 0
                 if      (c1>='a'&& c1<= 'f')  car += (c1-'W');     // a (97) - W (87) --> 10
                 else                          car += (c1-'0');     // 0 (48) - 0 (48) --> 0

                 //....................... passer au nombre suivant ........................
                 if (pt[2]=='0'&&pt[3]=='0')    pt += 4;      // si zero suit alors ASCII sous deux octets unicodes
                 else                           pt += 2;      // si non  alors ASCII tout court

                 //....................... insérer et echapper au pire ........................
                 if (car=='\'')             result += "\\\'";   // echapper au pire
                 else if (car==')')         result += "\\0X29"; // echapper au pire
                 else if (car=='(')         result += "\\0X28"; // echapper au pire
                 else if (car=='\"')        result += "\\\"";   // echapper au pire
                 else                       result += car;      // insérer le caractère tel quel
                }
          result.append('\'');
          result.replace("\\\\\'","__");
          text.replace(deb, fin-deb, result);
         }
     }
}

//-----------------------------------------------------  ParseSQL_InsertInto -------------------------------------------
// INSERT INTO `RubriquesHead` VALUES (1,'30DC82DD-7632-2C46-9DC3-BC1AC0ECD20A',20030000,'Asthme sai','2004-12-08 19:23:41','admin',0,0);
// INSERT INTO `RubriquesHead` VALUES (2,'30DC82DD-7632-2C46-9DC3-BC1AC0ECD20A',20020200,'Bilan labo complet','2004-12-08 19:23:41','admin',0,0);
// INSERT INTO `ACCES2` VALUES ('A','à foyer ouvert'),('A','par ... abord '),('A','par dissection ...');
// INSERT INTO `codes_postaux` (`id`,`code_postal`,`ville`) VALUES
//  (26662,62153,'ABLAIN ST NAZAIRE'),
//  (35076,80320,'ABLAINCOURT PRESSOIR');
void  CApp::ParseSQL_InsertInto(QString &text, long &line_number, QSqlDatabase *dataBase, QProgressBar *pQProgressBar /* = 0 */, CW_EditText *logWidget /* = 0 */)
{   QSqlQuery query(QString::null, dataBase);
    int deb = text.find("INSERT INTO");
    int pos = text.find("VALUES");
    if (pos ==-1 || deb==-1)
    {if (pos==-1) Datasemp_OutMessage(logWidget,QObject::tr(" Erreur de syntaxe  INSERT INTO VALUES : ligne  ")+ QString::number(line_number) + " mention \'VALUES\' non trouvée");
     else         Datasemp_OutMessage(logWidget,QObject::tr(" Erreur de syntaxe  INSERT INTO VALUES : ligne  ")+ QString::number(line_number) + " mention \'INSERT INTO\' non trouvée");
     return;
    }
    //............ isoler le verbe .................................................................
    pos         += 6;
    QString verb = text.mid(deb, pos-deb) + " ";  // "INSERT INTO `ACCES2` VALUES "
    //............ parser le reste pour les valeurs ................................................
    long end = pos;

    //....................... parser .............................................................................
    do
    {   //...................... se mettre sur premiere parenthese de données ....................................
        if ( (deb = text.find("(", end) )==-1 )
         {  Datasemp_OutMessage(logWidget,QObject::tr(" Erreur de syntaxe  INSERT INTO VALUES : ligne ")+ QString::number(line_number)  + " début de bloc '(' non trouvé");
            return;
         }
        //.................. fin data .............................................................................
        end = JumpToEndDataBloc(deb, text);
        //........................ si données valides les insérer ...................................................
        if (end != -1)
        {   QString line = verb + text.mid(deb, end-deb);
            query.exec(line);
            OutSQL_error(query, "ERREUR INSERT INTO : ParseSQL_Dump()", line );
            if (pQProgressBar) pQProgressBar->setProgress(++m_position);
            deb = end ;
        }
       else
        {   Datasemp_OutMessage(logWidget,QObject::tr(" Erreur de syntaxe  INSERT INTO VALUES : ligne ") + QString::number(line_number) + " fin de bloc ')' non trouvé");
            return;
        }
    } while (text.at(end) !=';');
}

//-----------------------------------------------------  JumpToEndDataBloc -------------------------------------------
// ACTION : recherche la parenthèse de fin de bloc de données
// ENTREE : int pos pointe sur une parenthèse ouvrante d'un bloc de données
//                     INSERT INTO `ACCES2` VALUES ('A','à foyer ouvert'),('A','par ... abord  '),('A','par dissection ...');
//                                                ^
//                                                |________ pos sur parenthèse ouvrante (début de bloc)
//
// SORTIE ; un int  qui pointe apres la parenthèse fermante d'un bloc de données
//                  si pointe sur ';'  c'est que fin des données
//                     INSERT INTO `ACCES2` VALUES ('A','à foyer ouvert'),('A','par ... abord  '),('A','par dissection ...');
//                                                                      ^                                                  ^
//                                                                      |_______ int de sortie (fin de bloc)_______________|
// on assume le fait que pos est au moins à +1 du début de text

int CApp::JumpToEndDataBloc(int pos, QString &sql_text)
{char       *deb     = (char*)(const char*)sql_text;
 char       *end     = deb + sql_text.length();
 char       *pt      = deb + pos;
 int        in_Quote = 0;
 while (pt<end )
       {if ( pt[0] =='\''  &&  pt[-1] != '\\' ) in_Quote ^= 1;          // bascule binaire
        if ( ! in_Quote    &&  pt[ 0] == ')'  ) return pt - deb + 1;    // si hors zone guillemets ' ' et fin de bloc
        ++pt;
       }
 return -1;
}

//-----------------------------------------------------  InsertData -------------------------------------------
void  CApp::InsertData(QSqlDatabase *dataBase, const QString &fname, QProgressBar *pQProgressBar)
{//....................... ouvrir le fichier en mode QTextStream ...........................
    if ( !QFile::exists( fname ) ) return;
    QFile file( fname );
    if ( !file.open( IO_ReadOnly ) ) return;
    QTextStream stream ( &file );
    //.......... on déclare une variable pour lire le fichier ligne à ligne ..................
    QString requete       = "";
    int     line_number   = 0;
    while (!stream.atEnd())
    {line_number++;
        if (pQProgressBar) pQProgressBar->setProgress(m_position++);
        requete    = stream.readLine().stripWhiteSpace();
        if (requete.left(11).upper()=="INSERT INTO")
        {   QSqlQuery query(QString::null, dataBase);
            query.exec(requete);
            OutSQL_error(query, tr("ERREUR : ExecSQL_File()"), requete );
            line_number++;
        }
    }
}

//-----------------------------------------------------  ExecSQL_File -------------------------------------------
int  CApp::ExecSQL_File(QSqlDatabase *dataBase, const QString &fname, QProgressBar *pQProgressBar /* = 0 */)
{//....................... ouvrir le fichier en mode QTextStream ...........................
    if ( !QFile::exists( fname ) )   return -1;
    QFile file( fname );
    if ( !file.open( IO_ReadOnly ) ) return -2;
    QTextStream stream ( &file );
    //.......... on déclare une variable pour lire le fichier ligne à ligne ..................
    QString   buffer("");
    QSqlQuery query(QString::null, dataBase);
    while (!stream.atEnd())
    {buffer    += stream.readLine().stripWhiteSpace();
        long len   = buffer.length();
        if (  buffer.at(len-1L)==';' &&
             (buffer.at(len-2L)==')' ||
             (len>7 &&  buffer.mid(len-7) == "MyISAM;" ) ) )
        {   query.exec(buffer);
            OutSQL_error(query, tr("ERREUR : ExecSQL_File()"), buffer );
            buffer = "";
            ++m_position;
            if (pQProgressBar) pQProgressBar->setProgress(m_position);
        }
    }
    return m_position;
}

//-----------------------------------------------------  CreationTables -------------------------------------------
int  CApp::CreationTables(QSqlDatabase *dataBase, const QString &f_name, QProgressBar *pQProgressBar /* = 0 */)
{if ( !QFile::exists( f_name ) )  return 0;
    QFile file( f_name );
    if ( !file.open( IO_ReadOnly ) ) return 0;

    QString requete( QTextStream ( &file ).read());
    QStringList list = QStringList::split(';',requete);

    QSqlQuery query(QString::null, dataBase);
    for ( QStringList::Iterator it = list.begin(); it != list.end(); ++it )
    {requete = (*it).stripWhiteSpace();
        if (requete.length())
        {query.exec(requete);
            if (OutSQL_error(query, f_name, requete ) != QSqlError::None) return 0;
            ++m_position;
        }
    }
    if (pQProgressBar) pQProgressBar->setProgress(m_position);
    return m_position;
}




//------------------------------------------------ Datasemp_CreateBases --------------------------------------------
QSqlDatabase*  CApp::Datasemp_CreateBases( QString driver,        // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
                                           QString dataBaseName,  // nom de la base: si QODBC3 -> nom de la source de données (userDSN)
                                           QString user,          // = "root"
                                           QString passWord,      // = ""
                                           QString hostName,      // = "localhost"
                                           CW_EditText *logWidget,
                                           int         *isThisBaseExist
                                           )
{*isThisBaseExist = 0;
    QString          outMess  = "";
    QString          errMess  = "";
    int               errNum  = 0;
    QSqlDatabase* mysql_base  = 0;
    QSqlDatabase* dataBase    = 0;
    dataBase   = BaseConnect(   driver  ,        // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
                                dataBaseName,    // nom de la base: si QODBC3 -> nom de la source de données (userDSN)
                                user,            // = "root"
                                passWord,        // = ""
                                hostName,        // = "localhost"
                                "Datasemp",
                                &errMess,
                                &errNum);



    if (dataBase == 0 )
    {
        if (errNum != 1049 && errNum != -1 && errNum != 0)
        { // La base existe mais problème de connection
            outMess  =          QObject::tr("============== La base ") + dataBaseName + QObject::tr(" existe mais connexion impossible ==========================\n") ;
            outMess += errMess + " " + QString::number(errNum) ;
            Datasemp_OutMessage(logWidget, outMess);
        }
        else
        {outMess    =        QObject::tr("============== La base : ")+ dataBaseName +QObject::tr(" n'existe pas ================================================\n") ;
            outMess   += errMess + " " + QString::number(errNum) ;
            Datasemp_OutMessage(logWidget, outMess);
            if (mysql_base==0) mysql_base = BaseConnect("QMYSQL3", "mysql", user, "", "localhost", "TestBase", &errMess, &errNum);
            if (mysql_base==0)
            { outMess  =     QObject::tr("============== Échec de la connexion à la base MySql ==================================================\n") ;
                outMess += errMess + " " + QString::number(errNum) ;
                Datasemp_OutMessage(logWidget, outMess);
            }
            else
            {//............... Création de la base ....................................
                outMess  =      QObject::tr("============== Création de la base ")+ dataBaseName +QObject::tr(" =================================================\n") ;
                Datasemp_OutMessage(logWidget, outMess);
                CreationBase(mysql_base, dataBaseName);
                // on se connecte à la nouvelle base
                dataBase =  BaseConnect( driver  ,        // nom du driver: "QODBC3" "QMYSQL3" "QPSQL7"
                                         dataBaseName,    // nom de la base: si QODBC3 -> nom de la source de données (userDSN)
                                         user,            // = "root"
                                         passWord,        // = ""
                                         hostName,        // = "localhost"
                                         "DatasempTest",
                                         &errMess,
                                         &errNum);
                if (dataBase==0)
                { outMess  = QObject::tr("============== Échec de la création de la base : ")+ dataBaseName +QObject::tr(" ===========================================\n") ;
                    outMess += errMess + " " + QString::number(errNum) ;
                    Datasemp_OutMessage(logWidget, outMess);
                }
                else
                {//............... Ok la base a bien été créée ....................................
                    outMess  = QObject::tr("  La base de données ")+ dataBaseName +QObject::tr(" a été créée avec succès \n");
                    Datasemp_OutMessage(logWidget, outMess);
                    return dataBase;
                }
            }
        }
    }
    else
    {outMess +=             QObject::tr("============== la base : ") + dataBaseName + QObject::tr(" existe déjà ===============================================\n") ;
        //outMess += errMess + " " + QString::number(errNum) ;
        Datasemp_OutMessage(logWidget, outMess);
        *isThisBaseExist = 1;
        return dataBase;
    }
    return 0;
}

//----------------------------------------------- Datasemp_GetBaseVersion ---------------------------------------------------------------------
QString CApp::Datasemp_GetBaseVersion(QSqlDatabase* dataBase, QString *numEdition, QString *packBCArrete, QString *packIRArrete)
{   QString ods("");
    QString value("");
    //................. Preparer la requete .....................................
    if (dataBase->isOpen()==FALSE && dataBase->open()==FALSE)              return ods;
    QSqlQuery query(QString::null, dataBase );
    query.exec("SELECT f0,f1 FROM tFB ");
    //.................. si la requète a un resultat ..............................................
    if (query.isActive())
    {while (query.next())
        { value = query.value(0).toString();
            if      (packBCArrete && value=="ARRETE PACK BC") *packBCArrete = query.value(1).toString().mid(1);
            else if (packIRArrete && value=="ARRETE PACK IR") *packIRArrete = query.value(1).toString().mid(1);
            else if (numEdition   && value=="EDITION NUMERO") *numEdition   = query.value(1).toString().mid(1);
            else if (value=="ODS")                             ods          = query.value(1).toString().mid(1);
        }
    }
    else
    {OutSQL_error( query, tr("Erreur : Datasemp_GetBaseVersion()"));
    }
    return ods.remove("#00");
}

//----------------------------------------------- Datasemp_Maj_GetDiskVersion ---------------------------------------------------------------------
QString CApp::Datasemp_Maj_GetDiskVersion(const QString &fname)
{   QString ods("");
    //............ ouverture fichier ..................................
    if ( !QFile::exists( fname ) )                     return ods;
    QFile file( fname );
    if ( !file.open( IO_ReadOnly ) )                   return ods;

    //............ creation buffer de lecture ..........................
    long len_buffer_c = 36;
    char *buffer_c    = new char[len_buffer_c];
    if (buffer_c==0)                                   return ods;
    long nb_read = file.readBlock ( buffer_c, len_buffer_c);
    file.close();
    if (nb_read!=len_buffer_c)       {delete buffer_c; return ods;}
    ods.setLatin1(buffer_c+20,16);
    delete buffer_c;
    return ods;
}

//----------------------------------------------- Datasemp_Maj_GetMajList ---------------------------------------------------------------------
long CApp::Datasemp_Maj_GetMajList(const QString &srcPath, const QString &baseVersion, QStringList &list)
{ long nb(0);
    list.clear();
    QDir dir (srcPath+"maj");
    dir.convertToAbs();
    dir.setFilter( QDir::All | QDir::NoSymLinks );
    const QFileInfoList * pQFileInfoList = dir.entryInfoList();
    if (pQFileInfoList==0)  return 0;

    QFileInfoListIterator it( *pQFileInfoList );
    QFileInfo     *fi;
    QString        diskVersion;
    while ( (fi = it.current()) != 0 )
    {QString fname = fi->fileName().latin1();
        if (fi->isFile())
        {diskVersion = Datasemp_Maj_GetDiskVersion(srcPath+"maj" + QDir::separator() + fname);
            //..................... verifier si mise à jour concerne notre base .................
            if (fname.mid(fname.findRev('.')+1)=="maj")
            {if (diskVersion==baseVersion)
                {list.append(QString("+ ") + fname);
                    ++nb;
                }
                else
                {list.append(QString("- ") + fname);
                }
            }
        }
        ++it;
    }
    return nb;
}

//----------------------------------------------- Datasemp_Maj_Update ---------------------------------------------------------------------
long CApp::Datasemp_Maj_Update(QSqlDatabase* pDataBase, const QString &srcPath, const QString &baseODS, UPDATE_MODE mode, CW_EditText *logWidget)
{   QString outMess = logWidget->text();
    if ( (int)(mode&CApp::MajFiles)==0 && (int)(mode&CApp::SqlFiles)==0 )
    {Datasemp_OutMessage(logWidget,  QObject::tr(" Mise à jour non effectuée car aucune option de mise à jour positionnée  " ));
        return 0;
    }
    long nb(0);
    long nb_sqlLine(0);
    QDir dir (srcPath+"maj");
    dir.convertToAbs();
    dir.setFilter( QDir::All | QDir::NoSymLinks );
    const QFileInfoList * pQFileInfoList = dir.entryInfoList();
    if (pQFileInfoList==0)
    {Datasemp_OutMessage(logWidget,  QObject::tr("  Aucun fichier de mise à jour trouvé dans ce repertoire !!!! " ));
        return 0;
    }
    QFileInfoListIterator it( *pQFileInfoList );
    QFileInfo     *fi;
    QString        diskVersion;
    //................. fichier de sortie .........................................
    // FilesOut           = Out_Remove.txt , Out_Insert.txt  ,  Out_Update.txt
    QString out_Remove(""), out_Insert(""), out_Update("");
    G_pCApp->Param_ReadParam( "Datasemp", "FilesOut", &out_Remove, &out_Insert, &out_Update);
    if (out_Remove.length()) out_Remove.prepend(m_PathAppli);
    if (out_Insert.length()) out_Insert.prepend(m_PathAppli);
    if (out_Update.length()) out_Update.prepend(m_PathAppli);
    while ( (fi = it.current()) != 0 )
    {QString fname = fi->fileName().latin1();
        if (fi->isFile())
        {diskVersion = Datasemp_Maj_GetDiskVersion(srcPath+"maj" + QDir::separator() + fname);
            //..................... verifier si mis à jour concerne notre base ............
            if (mode&CApp::MajFiles && fname.mid(fname.findRev('.')+1)=="maj" && (diskVersion==baseODS||mode&CApp::Force))
            {//............... Remove en cours ....................................
                Datasemp_OutMessage(logWidget,  QObject::tr("  Mise à jour Datasemp livraison : ") + diskVersion + QObject::tr("    effacement des données en cours ....")) ;
                Datasemp_Maj_Update(srcPath+"maj"+QDir::separator()+fname, nb_sqlLine, CApp::Remove, pDataBase, out_Remove);
                //............... Insert en cours ....................................
                Datasemp_OutMessage(logWidget,  QObject::tr("  Mise à jour Datasemp livraison : ") + diskVersion + QObject::tr("    insertion des données en cours .... " ));
                Datasemp_Maj_Update(srcPath+"maj"+QDir::separator()+fname, nb_sqlLine, CApp::Insert, pDataBase, out_Insert);
                //............... Update en cours ....................................
                Datasemp_OutMessage(logWidget,  QObject::tr("  Mise à jour Datasemp livraison : ") + diskVersion + QObject::tr("    mise à jour des données en cours ....")) ;
                Datasemp_Maj_Update(srcPath+"maj"+QDir::separator()+fname, nb_sqlLine, CApp::Update, pDataBase, out_Update);
                ++nb;
            }// end if (fname.mid(fname.findRev('.')+1)=="maj" && (diskVersion==baseODS||mode==CApp::Force))
            else if (mode&CApp::SqlFiles && fname.mid(fname.findRev('.')+1)=="sql")
            {//............... Execution SQL en cours ....................................
                Datasemp_OutMessage(logWidget,  QObject::tr("  Mise à jour Datasemp : fichier SQL :  ") + QObject::tr("    en cours d'exécution....")) ;
                ExecSQL_File(pDataBase, srcPath+"maj"+QDir::separator()+fname);
                ++nb;
            }
        } // end if (fi->isFile())
        ++it;
    }
    if (nb) Datasemp_OutMessage( logWidget,  QObject::tr("  Mise à jour Datasemp terminée de : " ) + QString::number(nb_sqlLine) + QObject::tr(" enregistrements"));
    else    Datasemp_OutMessage( logWidget,  QObject::tr("  Pas de fichier de mise à jour trouvés : " ));
    return nb_sqlLine;
}

//----------------------------------------------- Datasemp_OutMessage ---------------------------------------------------------------------
void  CApp::Datasemp_OutMessage( CW_EditText *logWidget, const QString &mess)
{if (logWidget==0)  return;
    logWidget->append( mess );
    logWidget->moveCursor(QTextEdit::MoveEnd);
    qApp->processEvents();qApp->processEvents();qApp->processEvents();qApp->processEvents();qApp->processEvents();qApp->processEvents();
}

//----------------------------------------------- Datasemp_Maj_Update ---------------------------------------------------------------------
QString CApp::Datasemp_Maj_Update(const QString &fname,
                                  long &nb_sqlLine,
                                  UPDATE_MODE mode,          // = CMedicaBase::AllUpdate
                                  QSqlDatabase* pDataBase,   // = 0  si pas egal zero alors les requetes SQL de mise à jour seront executées
                                  const char* fileOut        // = 0  si pas egal zero alors le fichier SQL de mise à jour sera ecrit
                                  )
{long nb_read = 0;
    QString table;
    QString sql("");
    char *end;
    char *pt;

    //............ ouverture fichier ..................................
    if ( !QFile::exists( fname ) )                     return sql;
    QFile file( fname );
    if ( !file.open( IO_ReadOnly ) )                   return sql;

    //............ creation buffer de lecture ..........................
    long len_buffer_c = file.size();
    char *buffer_c = new char[len_buffer_c];
    if (buffer_c==0)                                   return sql;
    nb_read = file.readBlock ( buffer_c, len_buffer_c);
    file.close();
    if (nb_read==0)                  {delete buffer_c; return sql;}

    //................. lire l'entete ..................................
    QString head("");
    head.setLatin1(buffer_c, 68);
    //................. parser le fichier ..............................

    end = buffer_c + len_buffer_c - 93;      // - 93 bloc de fin
    pt  = buffer_c + 68;
    while (pt<end)
    {switch(pt[0])
     {case'[':
      table.setLatin1(pt + 1, 2);  table.prepend("t");
            pt += 15;
            break;
        case '~':
            pt += 2;
            if      (pt[-1]=='M') sql += Datasemp_Maj_UpdateInTable(pt, end, table, mode & CApp::Update, nb_sqlLine, pDataBase);
            else if (pt[-1]=='C') sql += Datasemp_Maj_InsertInTable(pt, end, table, mode & CApp::Insert, nb_sqlLine, pDataBase);
            else if (pt[-1]=='S') sql += Datasemp_Maj_DeleteInTable(pt, end, table, mode & CApp::Remove, nb_sqlLine, pDataBase);
            break;
        default: ++pt;
        }
    }
    if (fileOut)
    {QFile fileW(fileOut);
        if ( !fileW.open( IO_WriteOnly ) )    {delete buffer_c; return sql;}
        fileW.writeBlock (sql , sql.length());
        fileW.close();
    }
    delete buffer_c;
    //.......... on déclare une variable pour le lire ligne à ligne ..................
    return sql;
}

//----------------------------------------------- Datasemp_Maj_UpdateInTable ---------------------------------------------------------------------
// ENTREE: ptIn  pointe sur le signe $  ( celui de  ~M$ )
QString CApp::Datasemp_Maj_UpdateInTable(char* &pt, char* end, const QString &table, int doIt, long &nb_sqlLine, QSqlDatabase* pDataBase)
{if (doIt==0)
    {while (pt < end && *pt != '~' && *pt != '[') ++pt;
        return QString("");
    }
    //................... extraire valeur de la clef ......................................
    QString key        = QString("f") + pt[1];    pt+=2;
    QString key_value  = Datasemp_Maj_ExtractValue(pt, end);
    QString data_sql   = QString("UPDATE ") + table + " SET  ";

    //................... extraire autres valeurs ..........................................
    int     n   = 0;
    while (pt < end && *pt != '~' && *pt != '[')
    {//                          @1345   Premiére valeur apres le @ est le N°champ,
        //                                  la deuxième jusqu'à fin (@ autre champ ou ~ fin des champs) est la valeur du champ
        if (*pt == '@')
        {if (n++) data_sql += " , ";     // rajouter virgule de separation si besoin
            data_sql    += QString("f") + pt[1];  pt+=2;
            data_sql    += "='" + Datasemp_Maj_ExtractValue(pt, end).replace('\'','`') + "'";
        }
    }
    data_sql += "  WHERE ( " + key + "='" + key_value + "' );\r\n";
    if (pDataBase)
    { QSqlQuery query(QString::null, pDataBase);
        query.exec(data_sql);
        OutSQL_error( query, tr("Erreur : Datasemp_Maj_UpdateInTable()"), data_sql);         //8EBREPD0212005271
    }
    ++nb_sqlLine;
    return data_sql;
}

//----------------------------------------------- Datasemp_Maj_DeleteInTable ---------------------------------------------------------------------
// ENTREE: ptIn  pointe sur le signe $  ( celui de  ~S$ )
QString CApp::Datasemp_Maj_DeleteInTable(char* &pt, char* end, const QString &table, int doIt, long &nb_sqlLine, QSqlDatabase* pDataBase)
{if (doIt==0)
    {while (pt < end && *pt != '~' && *pt != '[') ++pt;
        return QString("");
    }
    //............................... la commence le truc ......................................
    QString data_sql = QString("DELETE FROM ") + table + " WHERE ( ";
    int n            = 0;
    while (pt < end && *pt != '~' && *pt != '[')
    {//                          @1345   Premiére valeur apres le @ est le N°champ,
        //                                  la deuxième jusqu'à fin (@ autre champ ou ~ fin des champs) est la valeur du champ
        if (n++) data_sql += " AND ";    // rajouter virgule de separation si besoin
        data_sql          += QString("f") + pt [1] + "='"; pt+=2;
        while (pt < end && *pt != '~' && *pt != '[' && *pt != '$' && *pt==' ') ++pt;
        data_sql += Datasemp_Maj_ExtractValue(pt, end, "$[~\0x00\0x00")+ "'";
    }
    data_sql +=  " );\r\n";
    if (pDataBase)
    {QSqlQuery query(QString::null, pDataBase);
        query.exec(data_sql);
        OutSQL_error( query, tr("Erreur : Datasemp_Maj_DeleteInTable()"), data_sql);
    }
    ++nb_sqlLine;
    return data_sql;
}

//----------------------------------------------- Datasemp_Maj_InsertInTable ---------------------------------------------------------------------
// ENTREE: ptIn  pointe sur le signe $  ( celui de  ~C$ )
//         [4G0200000000053~C$0C00510$1C03234~C$    peut aussi exister si f0 et f1 font partie de la clef     !!!!
//         [4G0200000000053~C$0C00510@1C03234~C$    peut aussi exister si f0 fait partie de la clef et pas f1 !!!!
QString CApp::Datasemp_Maj_InsertInTable(char* &pt, char* end, const QString &table, int doIt, long &nb_sqlLine, QSqlDatabase* pDataBase)
{if (doIt==0)
    {while (pt < end && *pt != '~' && *pt != '[') ++pt;
        return QString("");
    }
    //............................... la commence le truc ......................................
    QString data_sql   = QString("INSERT INTO ") + table + " ( ";
    int  n             = 0;
    QString field_list = "";
    QString value_list = "'";
    while (pt < end && *pt != '~' && *pt != '[')
    {//                          @1345   Premiére valeur apres le @ est le N°champ,
        //                                  la deuxième jusqu'à fin (@ autre champ ou ~ fin des champs) est la valeur du champ
        if (n++) {field_list += " , ";  value_list += " , '";}   // rajouter virgule de separation si besoin

        field_list      += QString("f") + pt[1];  pt+=2;
        while (pt < end && *pt != '~' && *pt != '[' && *pt != '$' && *pt==' ') ++pt;       // passer espaces inutiles
        value_list  += Datasemp_Maj_ExtractValue(pt, end, "$@[~\0x00").replace('\'','`') + "'";
    }
    data_sql += field_list + " ) VALUES ( " + value_list + " );\r\n";
    if (pDataBase)
    {  QSqlQuery query(QString::null, pDataBase);
        query.exec(data_sql);
        OutSQL_error( query, tr("Erreur : Datasemp_Maj_InsertInTable()"), data_sql);
    }
    ++nb_sqlLine;
    return data_sql;
}

//----------------------------------------------- Datasemp_Maj_ExtractValue ---------------------------------------------------------------------
QString CApp::Datasemp_Maj_ExtractValue(char* &pt, const char* end, const char* sep_str)
{char   *deb = pt;
    QString key_value("");
    while (pt < end &&  *pt != sep_str[0] && *pt != sep_str[1] && *pt != sep_str[2] && *pt != sep_str[3])
    {if (*pt=='#')
        {key_value += QString::fromLatin1(deb, pt-deb);
            ++pt;
            key_value += Datasemp_Maj_DecodeSpecialCar(QString::fromLatin1(pt, 2));
            pt += 2;
            deb = pt;
        }
        else
        {++pt;
        }
    }
    key_value += QString::fromLatin1(deb, pt-deb);
    return key_value;
}

//----------------------------------------------- Datasemp_Maj_DecodeSpecialCar ---------------------------------------------------------------------
QString CApp::Datasemp_Maj_DecodeSpecialCar(const QString &val)
{   QString ret;
    //  0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F      00
    char DECODE_TBL[256] = {  0, '?', '?', '?', '?', '?', '?', '?', '?',   9,'\n', '?', '?','\r', '?', '?',\
                              // 10   11   12   13   14   15   16   17   18   19   1A   1B   1C   1D   1E   1F      01
                              '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?',\
                              // 20   21   22   23   24   25   26   27   28   29   2A   2B   1C   2D   2E   2F      02
                              '?', '?','\"', '#', '$', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?',\
                              // 30   31   32   33   34   35   36   37   38   39   3A   3B   3C   3D   3E   3F      03
                              '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?',\
                              // 40   41   42   43   44   45   46   47   48   49   4A   4B   4C   4D   4E   4F      04
                              '@', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?',\
                              // 50   51   52   53   54   55   56   57   58   59   5A   5B   5C   5D   5E   5F      05
                              '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '[','\\', ']', '^', '_',\
                              // 60   61   62   63   64   65   66   67   68   69   6A   6B   6C   6D   6E   6F      06
                              '\'', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?',\
                              // 70   71   72   73   74   75   76   77   78   79   7A   7B   7C   7D   7E   7F      07
                              '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '{', '|', '}', '~', '?',\
                              // 80   81   82   83   84   85   86   87   88   89   8A   8B   8C   8D   8E   8F      08
                              '?', '?', ',', '§','\"', '_', '¡', '?', '^', '?', '?', '«', '?', '?', '?', '?',\
                              // 90   91   92   93   94   95   96   97   98   99   9A   9B   9C   9D   9E   9F      09
                              '?', '?','\'','\"','\"', '·', '-', '-', '~', '?', 's', '»', 'æ', '?', '?', 'ÿ',\
                              // A0   A1   A2   A3   A4   A5   A6   A7   A8   A9   AA   AB   AC   AD   AE   AF      0A
                              '?', '¡', '?', '£', '?', '¥', '?', '§', '?', '©', 'ª', '«', '¬', '-', '®', '-',\
                              // B0   B1   B2   B3   B4   B5   B6   B7   B8   B9   BA   BB   BC   BD   BE   BF      0B
                              '°', '±', '²', '³', '?', 'µ', '¶', '·', '?', '¹', 'º', '»', '?', '?', '?', '¿',\
                              // C0   C1   C2   C3   C4   C5   C6   C7   C8   C9   CA   CB   CC   CD   CE   CF      0C
                              'À', 'Á', 'Â', 'Ã', 'Ä', 'Å', 'Æ', 'Ç', 'È', 'É', 'Ê', 'Ë', 'Ì', 'Í', 'Î', 'Ï',\
                              // D0   D1   D2   D3   D4   D5   D6   D7   D8   D9   DA   DB   DC   DD   DE   DF      0D
                              'Ð', 'Ñ', 'Ò', 'Ó', 'Ô', 'Õ', 'Ö', '×', 'Ø', 'Ù', 'Ú', 'Û', 'Ü', 'Ý', 'Þ', 'ß',\
                              // E0   E1   E2   E3   E4   E5   E6   E7   E8   E9   EA   EB   EC   ED   EE   EF      OE
                              'à', 'à', 'â', 'ã', 'ä', 'å', 'æ', 'ç', 'è', 'é', 'ê', 'ë', 'ì', 'í', 'î', 'ï',\
                              // F0   F1   F2   F3   F4   F5   F6   F7   F8   F9   FA   FB   FC   FD   FE   FF      0F
                              'ð', 'ñ', 'ò', 'ó', 'ô', 'õ', 'ö', '÷', 'ø', 'ù', 'ú', 'û', 'ü', 'ý', 'þ', 'ÿ'
                          };
    if       (  val ==  "EU") ret = "euro";
    else if  (  val ==  "9C") ret = "oe"; 
    else if  (  val ==  "8C") ret = "OE";
    else if  (  val ==  "85") ret = "...";
    else if  (  val ==  "89") ret = "°/oo";
    else if  (  val ==  "99") ret = "TM";
    else if  (  val ==  "00") ret = "";
    else                      ret = DECODE_TBL[val.toInt(0,16)];
    return ret;
}


//-------------------------------------------------- OutSQL_error -----------------------------------------------
int CApp::OutSQL_error( const QSqlQuery &cur, const char *messFunc /*=0*/, const char *requete /*=0*/)
{    QSqlError error = cur.lastError();
    QString   qserr("");

    if (error.type() != QSqlError::None)
    {switch (error.type())
     { case    QSqlError::None:                 qserr = tr(" - no error occurred: ")          ; break;
             case    QSqlError::Connection:     qserr = tr(" - connection error: ")          ; break;
             case    QSqlError::Statement:      qserr = tr(" - SQL statement syntax error: ") ; break;
             case    QSqlError::Transaction:    qserr = tr(" - transaction failed error: ")   ; break;
             case    QSqlError::Unknown:        qserr = tr(" - unknown error: " )             ; break;
             default:                           qserr = tr(" - unknown error: ")              ; break;
             }
        if (messFunc) qDebug(messFunc);
        qDebug(qserr + error.databaseText ());
        if (requete) qDebug(requete);
    }
    //     qDebug(qserr + error.databaseText ());
    return error.type();
}
