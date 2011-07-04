/********************************* C_Dlg_ParamView.h ************************************
\file C_Dlg_ParamView.h
\brief (put some short descripion here).

    #include ".h"
    Project: MedinTux
    Copyright (C) 2003 2004 2005 2006 2007
    by Sevin Roland  and Data Medical Design
    E-Mail: roland-sevin@medintux.org

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


#ifndef PLUG_PRM_VIEW_
#define PLUG_PRM_VIEW_




#endif


#ifndef C_DLG_PARAMVIEW_H
#define C_DLG_PARAMVIEW_H

#include "ui/Dlg_ParamView.h"

class C_Dlg_ParamView : public Dlg_ParamView
{
  Q_OBJECT

public:
  C_Dlg_ParamView(QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
  ~C_Dlg_ParamView();
  /*$PUBLIC_FUNCTIONS$*/

public slots:
  /*$PUBLIC_SLOTS$*/

protected:
  /*$PROTECTED_FUNCTIONS$*/

protected slots:
  /*$PROTECTED_SLOTS$*/
  virtual void          reject();
  virtual void          accept();

};

#endif

