 /*********************************** CGestIni.cpp *************************
 *  #include "CGestIni.h"        QT4-ready                                 *
 * ........................................................................*
 *   Project   :  MedinTux  (typographie made in france)                   *
 *   Copyright :  (C) 2005-2006-2007-2008-2009-2010 and for the eternity   *
 *   by        :  Sevin Roland     from   MedinTux project                 *
 *   E-Mail    :  roland-sevin@medintux.org                                *
 *   Web site  :  www.medintux.org                                         *
 * ........................................................................*
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef  CGESTINI_H
#define  CGESTINI_H

//=============================================== INCLUDES ===================================================================
#include <QString>
#include <QStringList>
#include <QVariant>

class QSqlQuery;
//================================================= CForSleep ==============================================================
#ifdef Q_WS_MAC
    #include <qthread.h>
    class CForSleep : public QThread
          {public:
                CForSleep(){};
                ~CForSleep(){};
                static void sleep(unsigned long secs){QThread::sleep(secs);};
                virtual void   run(){};
          };
    #define SLEEP(a) CForSleep::sleep((a))
#endif
#ifdef Q_WS_WIN

    #include <qthread.h>
    class CForSleep : public QThread
          {public:
                CForSleep(){};
                ~CForSleep(){};
                static void sleep(unsigned long secs){QThread::sleep(secs);};
                virtual void   run(){};
          };
     #define SLEEP(a) CForSleep::sleep((a))

    // #define SLEEP(a) QTest::qWait((a)*1000);
#endif
#ifdef Q_WS_X11
     #define SLEEP(a) sleep((a))
#endif

//===================================== CGestIni =============================================================================
class CGestIni
{
 //............................... METHODES .........................................................................
public:
     CGestIni();
    ~CGestIni(){}
  static int            findFermant(const QString *ptext, int pos_deb, int pos_max, const QString &ouvrant, const QString &fermant);
  static int            findFermant(const QString *ptext, int pos_deb, int pos_max, const QString &ouvrant, const QString &fermant, int &isWithToken);
  static void           Param_UpdateToDisk(const QString &file_ini, const QString &inParam);
  //-----------------------------------------------------  Param_UpdateToDisk --------------------------
  /*! \brief sauvegarde un QByteArray dans un fichier
   *  \todo Attention le fichier n'est pas ferme ???...
  */
  static void           Param_UpdateToDisk(const QString &file_ini, const QByteArray &ba);
  static QString        Param_UpdateFromDisk(const QString &file_ini,  int *isUtf8_ret  =0 );
  static QByteArray&    Param_UpdateFromDisk(const QString &file_ini, QByteArray &ba, int *isUtf8_ret  =0 );
  static long           Param_UpdateFromDisk(const QString &file_ini, QString &outParam, int *isUtf8 = 0 );
  static QString        Param_WriteParam(QString *pQstr, const char *section, const char  *variable,
                                         const char *val1=0, const char *val2=0, const char *val3=0, const char *val4=0, const char *val5=0,
                                         const char *val6=0, const char *val7=0, const char *val8=0, const char *val9=0, const char *val10=0);
  static char          *Param_ExtraireValeurs(const char* txt,
                                              QString *val1, QString *val2, QString *val3, QString *val4, QString *val5,
                                              QString *val6, QString *val7, QString *val8, QString *val9, QString *val10);
  static QString        Param_ReadUniqueParam(const char* txt, const char *section, const char  *variable);
  static QString        Param_ReadParam(const char* txt, const char *section, const char  *variable,
                                        QString *val1=0, QString *val2=0, QString *val3=0, QString *val4=0, QString *val5=0,
                                        QString *val6=0, QString *val7=0, QString *val8=0, QString *val9=0, QString *val10=0);
  static char          *Param_GotoNextSection(char *pt, const char* section=0, QString *pQsection=0);
  static char          *Param_ExtraireNextValeurs(char* pt, QString &var_name,
                                           QString *val1=0, QString *val2=0, QString *val3=0, QString *val4=0, QString *val5=0,
                                           QString *val6=0, QString *val7=0, QString *val8=0, QString *val9=0, QString *val10=0);

  static char          *Param_ExtraireNextValeurs(char* pt, QString &var_name, char**pt_lgn, long *len,
                                           QString *val1=0, QString *val2=0, QString *val3=0, QString *val4=0, QString *val5=0,
                                           QString *val6=0, QString *val7=0, QString *val8=0, QString *val9=0, QString *val10=0);
  static char *         GotoNextDebLigne(const char* txt);
  static char *         GotoEndOfLigne(const char* txt);
  static  QString       Construct_Name_Exe(QString module, QString start_Argv, const QString &alternateExecName="");
  static  QString       Construct_Name_File_Ini(QString module, QString start_Argv, QString nom_Fichier_Alternatif=QString::null );
  static  QString       Construct_PathBin_Module(const QString &module, const QString &ref_dir);
  static  int           IsUtf8(const  QString & txt );
  static  int           IsUtf8(const  char *txt);
  static  QString       utf8Conv(const char* deb, long len);
  static  QString       CharStrToQStringUtf8( const  char *ptr );
  static  QString       Utf8_Query(QSqlQuery &cur, int field);
  static  void          Param_GetList(QString &outParam, const QString &sectionToRetrieve, const QString &varToRetrieve,  QStringList &lst , int isToStrip =0);
  static  void          Param_GetList(const QString &file_ini, const QString &sectionToRetrieve, QStringList &lst, const QString &varToRetrieve="",  int isToStrip =1, int *isUtf8 =0);
  static  QString       Param_RemoveSection(QString &param, QString section);
  static  QString       AbsoluteToRelativePath(QString pathRef, QString pathToConvert);
  static  QString       formatStringForParam(QString &str);
  static  QString       retrieveStringForParam(QString &str);
  static  QStringList   listDirectory(QString start_dir, const QString &filterExt="", const QString &filterName="", const QString &sep=";", bool listWithoutExt=FALSE);
  static  quint16       HexToUINT( const char *str);
  static  QString       UINTtoHex( quint16 val);
  static  QString       PassWordDecode(QString str_to_decode);
  static  QString       PassWordEncode(QString &pass);
  //---------------------------------------------- fromMyUTF8 ------------------------------------------------
  /*! \brief converti l'UTF8 avec une methode qui fonctionne en attendant de resoudre le PB par un moyen plus propre
   *  \param ptr : const char* chaine codée en UTF8
   *  \return QString convertie
   */

  static QString        fromMyUTF8(const char* ptr);

 //............................... DATA .............................................................................
public:

};

#endif

