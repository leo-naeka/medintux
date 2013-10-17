/********************************** CApp_Plug.h ****************************************
 *                                                                                *
 *   This program is free software; you can redistribute it and/or modify         *
 *   it under the terms of the CeCILL Version 2                     *
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
#ifndef CPLUGAPP_H
#define CPLUGAPP_H

#include <qapplication.h>
#include <qstring.h>
#include "../../../MedinTuxTools/CGestIni.h"
#include "ComptaMoteurBase.h"
#include "../compta/Listes.h"
#include <qfileinfo.h>
#include <qdir.h>
#include <qtextcodec.h>
#include <qstringlist.h>
#include <qdatetime.h>

#define TR QObject::tr

class ComptaMoteurBase;

//............................................. quelques définitions ..........................................................

/*! \brief Plugins de comptabilité pour MedinTux .
 */

//================================================= CApp_Plug ==============================================================
class CApp_Plug : public QApplication , public CGestIni
{

   Q_OBJECT

public:

    CApp_Plug(int & argc, char ** argv);
    ~CApp_Plug();
    void  setParam(QStringList &list);
    bool  getIniComptabilite();
    QDate setDateTimeNatural_jjMMyyyy_Order(const QString & dateIn);
    int   GotoDebug();

public slots:


signals:


public:
  QString m_AppelName;		/*!< Contient le nom de l'application */
  QString m_PathAppel;		/*!< Chemin vers l'application appelante  */
  QString m_PathAppelIni;	/*!< Fichier Ini de l'application appelante  */
  QString m_PathExchg;		/*!< Chemin vers le fichier d'échange */

  QString m_PathIni;		/*!< Chemin vers le fichier Ini de l'application de comptabilité */
  QString m_PathManagerIni;	/*!< Chemin vers le fichier Ini de l'application de comptabilité */
  QString m_Param;		/*!< Contenu du fichier Ini de l'application  de comptabilité */
  int     m_NbParam;		/*!< Nombre de paramètres passés à l'application */

  QString m_db_Driver;          /*!< Paramètres de la base de données de comptabilité : driver */
  QString m_db_Base;            /*!< Paramètres de la base de données de comptabilité : base de donnee*/
  QString m_db_User;            /*!< Paramètres de la base de données de comptabilité : Utilisateur */
  QString m_db_Pass;            /*!< Paramètres de la base de données de comptabilité : Password */
  QString m_db_Host;            /*!< Paramètres de la base de données de comptabilité : hostname */
  QString m_db_Port;            /*!< Paramètres de la base de données de comptabilité : port */

  QString m_PathAppli;		/*!< Chemin absolu vers l'executable du plugins */

  QString m_Param_Patient;	/*!< Nom de l'utilisateur passé en paramètre au plugins */
  int     m_Param_PrimKeyUser;	/*!< Clé primaire de l'utilisateur qui envoie l'honoraire */
  int     m_Param_DrTuxUsrPk;   /*!< Clé primaire de l'utilisateur qui envoie l'honoraire */
  QString m_Param_Praticien;	/*!< Nom de l'utilisateur passé en paramètre au plugins */
  QString m_Param_Date;		/*!< Date pour l'honoraire passée en paramètre au plugins */
  QDate   m_Param_QDate;		/*!< Date pour l'honoraire passée en paramètre au plugins */
  QString m_Param_GUID;		/*!< GUID du patient */
  QString m_Param_Acte;		/*!< Acte passé en paramètre */
  bool    m_Param_Tiers;	/*!< Tiers passé en paramètre = oui ou non  */
  QString m_Param_ModePaiement;	/*!< Mode de paiement passé en paramètre */

  QString m_AppliName;		/*!< Nom de cette application */
  QString m_LastError;		/*!< Message d'erreur à l'initialisation */

  QString m_msgToDrTux;		/*!< Texte à renvoyer à drtux */

  ComptaMoteurBase* m_ComptaBase; /*!< Pointeur vers la base de données de la comptabilité */
  Utilisateurs*     m_pUtilisateurs;    /*!< Utilisateur passé en paramètre au plugins */

};

extern CApp_Plug* G_pCApp_Plug;

#endif            // #define CPLUGAPP_H
