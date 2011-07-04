/***************************************************************************
 *   Copyright (C) 2004 by Sébastien SIVERA & Sevin Roland                 *
 *   upsis@club-internet.fr                                                *
 *                                                                         *
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

#ifndef CCLICKABLELED_H
#define CCLICKABLELED_H

#include <qpixmap.h>
#include <qhbox.h> 
#include <qlabel.h>
//================================================================ CClickableLed =====================================================
class CClickableLed : public /*QWidget */QHBox
{
    Q_OBJECT
    
public:
    
    enum ledColor
    {   Red       = 0x0000,
        Gray      = 0x0001,
	Green     = 0x0002
    };
    
    CClickableLed( QWidget * parent = 0,
		   const char * name = 0,
		   WFlags f = WStyle_NoBorder | WDestructiveClose ,
		   ledColor color = Gray);
    ~CClickableLed();
    void    setLedPixmap(const QPixmap &pixmap);
    void    setLedPixmap(const QString &pixmapPath);
    void    setText(const QString &text);
    QString text();
    void    setLedColor(int color);
    //ledColor asLedColor();
private:
    QLabel *m_PixMapLabel;
    QLabel *m_TextLabel;
signals:
    
    void clicked();
    
protected:
    
    void mouseReleaseEvent ( QMouseEvent * e );
    
};

#endif //CCLICKABLELED_H

