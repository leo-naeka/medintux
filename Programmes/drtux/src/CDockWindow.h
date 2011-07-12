/* Copyright (C) 2003 MySQL AB & Jorge del Conde

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU Library General Public
  License as published by the Free Software Foundation; either
  version 2 of the License, or (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Library General Public License for more details.
    
  You should have received a copy of the GNU Library General Public
  License along with this library; if not, write to the Free
  Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
  MA 02111-1307, USA 
*/
#ifndef CDOCKWINDOW_H
#define CDOCKWINDOW_H
//=============================================== INCLUDES ==========================================================

#include <qdockwindow.h>
#include <qtabwidget.h>
//===================================== CDockWindow =================================================================
class CDockWindow : public QDockWindow
{
  Q_OBJECT
    
public:
  CDockWindow(Place p = InDock, QWidget * parent = 0, const char * name = 0, WFlags f = 0);
  virtual void setCaption(const QString &s);

protected:
  virtual void closeEvent(QCloseEvent * e);
};


//===================================== CMessageWindow =================================================================
class CMessageWindow : public CDockWindow
{
  Q_OBJECT

public:
  CMessageWindow (Place p = InDock, QWidget * parent = 0, const char * name = 0, WFlags f = 0) ;
  void setCarriageReturn(const QString &s);
  void addPanel(QWidget *panel);
  void setTabEnabled(QWidget * w, bool enable);
  void setActivePanel(int t);
  QTabWidget *tabWidget() const { return Tabs; }

private slots:
  void tab_changed(QWidget *);

private:
  QTabWidget* Tabs;
  
};

#endif