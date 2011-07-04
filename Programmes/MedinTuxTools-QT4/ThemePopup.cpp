//
// C++ Implementation: ThemePopup
//
// Description: 
//
//
// Author: Roland Sevin <data.medical.design@club-internet.fr>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include <qcursor.h> 
//Added by qt3to4:
#include <QMenu>
#include "ThemePopup.h"

//--------------------------------- ThemePopup -----------------------------------------------------
ThemePopup::ThemePopup(QWidget * parent )
 : QMenu(parent)
{ if (Theme::getPath()!="")
  { QFont f = QMenu::font();
    int size = Theme::getFontSize_Popups();
    if (size != -1) 
       {f.setPointSize( Theme::getFontSize_Popups() );
        QMenu::setFont( f );
       }
  }
}

//--------------------------------- ThemePopup -----------------------------------------------------
ThemePopup::ThemePopup(QStringList &list, QWidget * parent )
 : QMenu(parent)
{ if (Theme::getPath()!="")
  { QFont f  = QMenu::font();
    int size = Theme::getFontSize_Popups();
    if (size != -1) 
       {f.setPointSize( Theme::getFontSize_Popups() );
        QMenu::setFont( f );
       }
  }
 //............................... chercher une zone de liste deroulante (bleue) .....................
 for ( QStringList::Iterator it =list.begin(); it != list.end(); ++it )
     { QString str = *(it);
       QAction *pQAction;
       if (str.left(4) == "----")
               {pQAction = addSeparator();
               }
       else if (str[0]=='#')
               {int pc = str.indexOf('#',1);
                if (pc != -1)
                   {QString icone = str.mid(1,pc-1);
                    pQAction      = addAction(Theme::getIconSet(icone), str.mid(pc+1));
                   }
                else pQAction = addAction( str );
               }
       else    {pQAction = addAction( str );
               }
     }
}

//--------------------------------- DoPopupList -----------------------------------------------------
QString ThemePopup::DoPopupList()
{QAction *pQAction  =  exec( QCursor::pos() /* mapToGlobal (  QPoint ( x, y) )*/ );
 if (pQAction) return pQAction->text();
 else          return QString::null;
}

