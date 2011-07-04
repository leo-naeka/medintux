 /********************************* main.cpp **************************************
 *                               MEDINTUX PROJECT                                 *
 * ...............................................................................*
 *   Project   :  MedinTux  (typographie made in france)                          *
 *   Copyright : (C) 2004-2005-2006-2007-2008-2009-2010 and for the eternity      *
 *   by        :  Sevin Roland     from   MedinTux project                        *
 *   E-Mail    : roland-sevin@medintux.org                                        *
 *   Web site  : www.medintux.org                                                 *
 * ...............................................................................*
 *                                                                                *
 *   This program is free software; you can redistribute it and/or modify         *
 *   it under the terms of the CeCILL Version 1 du 21/06/2004                     *
 *   License (GPL compatible)                                                     *
 *                              http://www.cecill.info/                           *
 *   as published by :                                                            *
 *                                                                                *
 *   Commissariat �  l'Energie Atomique                                            *
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

#include <QtGui/QApplication>
#include <QLibraryInfo>
#include <QTranslator>
#include "C_Manager.h"
#include "CApp.h"

int main(int argc, char *argv[])
{   int ret = -1;
    CApp cApp("Manager", argc, argv);
    if (G_pCApp) // n'est postionnee qu'a la fin du constructeur 'CApp' lorsque tout est OK
       {
        QTranslator qtTranslator;
        qtTranslator.load("qt_" + QLocale::system().name(), QLibraryInfo::location(QLibraryInfo::TranslationsPath));
        cApp.installTranslator(&qtTranslator);

        QTranslator myappTranslator;
        myappTranslator.load(QString("Manager_")+ QLocale::system().name(),G_pCApp->m_PathAppli+"/lang");
        cApp.installTranslator(&myappTranslator);

        C_Manager* pC_Manager = new C_Manager(G_pCApp->m_pCMoteurBase);
        G_pCApp->setMainWidget (pC_Manager);
        pC_Manager->show();
        ret = G_pCApp->exec();
        delete  pC_Manager;
       }
    return ret;
}
