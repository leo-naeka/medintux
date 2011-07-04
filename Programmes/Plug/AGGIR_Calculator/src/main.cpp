 /********************************* $MODULE$.cpp **********************************
 \file $MODULE$.cpp
 \brief (put some short descripion here).
     Copyright (C) 2008 by Roland Sevin   *
     roland-sevin@medintux.org   *
     #include "$MODULE$.h"
     Project: MedinTux
     Copyright (C) 2003 2004 2005 2006 2007
 
     by Sevin Roland  and Data Medical Design
     E-Mail: medintux@medintux.org
     Copyright (C) 2008 by Roland Sevin   *
     roland-sevin@medintux.org

 *   This program is free software; you can redistribute it and/or modify         *
 *   it under the terms of the CeCILL Version 1 du 21/06/2004                     *
 *   License (GPL compatible)                                                     *
 *                              http://www.cecill.info/                           *
 *   as published by :                                                            *
 *                                                                                *
 *   Commissariat a l'Energie Atomique                                            *
 *   - CEA,                                                                       *
 *                            31-33 rue de la Federation, 75752 PARIS cedex 15.   *
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




#include <qapplication.h>
#include "aggir_calculator.h"

int main( int argc, char ** argv ) {
    QApplication a( argc, argv );
    AGGIR_Calculator * mw = new AGGIR_Calculator();
    mw->setCaption( "AGGIR_Calculator" );
    mw->show();
    a.connect( &a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()) );
    return a.exec();
}
