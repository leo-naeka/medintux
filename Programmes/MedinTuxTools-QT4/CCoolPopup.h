 /********************************* CCoolPopup.h ***************************
 *  #include "CCoolPopup.h"           QT4-ready                            *
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

#ifndef CCOOLPOPUP_H
#define CCOOLPOPUP_H

#include <QTimer>
#include <QLabel>
#include <QWidget>
#include <QLabel>
#include <QPainter>
#include <QFont>
#include <QMouseEvent>
#include <QPaintEvent>

//================================================================ PopupWindow =====================================================
class CCoolPopup : public QWidget
{
    Q_OBJECT

public:

    enum
    {   NoAppearFlag         = 0x0000,
        AppearFlag           = 0x0001
    };
    enum
    {   WithFrame            = 0x0001,
        WithTransLabel       = 0x0002
    };

                  CCoolPopup( const QString pathImage = ""             ,
                              int             mode       = WithFrame      ,
                              int             textX      = 0              ,
                              int             textY      = 0              ,
                              int             textW      = 0              ,
                              int             textH      = 0              ,
                              const char*     text       = ""             ,
                              const QColor    textCol    = "#00F"         ,
                              const QColor    textBack   = "#FFF"         ,
                              long            tempo      = 20             ,
                              int             growBy     = 3              ,
                              const char     *name       = 0              ,
                              const QString  &styleSheet = ""             ,
			      Qt::WFlags        f         = Qt::WDestructiveClose |
                                                        Qt::WType_TopLevel    |
                                                        Qt::WStyle_Customize  |
                                                        Qt::WStyle_StaysOnTop |
                                                        Qt::WStyle_NoBorder
			  );
    ~CCoolPopup();
    void    setStyleSheet(const QString &styleSheet);
    QPixmap setImage(const QString path_image="", int mustAppear =0);
    void    setText(const QString& text, const QColor  textCol   = "#00F" , const QColor  textBack  = "#FFF"  );
    void    setTextGeometry(int textX , int textY , int textW = -1 , int textH = -1 );
    void    paintEvent( QPaintEvent *e );
public slots:
    void Appear();
    void Disappear();
    virtual void setFont ( const QFont &ft );
    virtual void setTextColor(const QColor &textCol);
signals:
    void Sign_Clicked();
    void Sign_Clicked(CCoolPopup*);
    void Sign_PopupDown(CCoolPopup* );
    void Sign_PopupUp(CCoolPopup* );

protected:
    void     mouseReleaseEvent( QMouseEvent *e );

    QTimer     *m_pDisplayTimer;
    QLabel     *m_QLabel_InfosXY;
    QLabel     *m_QLabel_Txt;
    QString  m_Text;
    int      m_Mode;
    int      m_GrowUp;
    int      m_ImgHeight;
    int      m_ImgWidth;
    long     m_Tempo;
    int      m_GrowBy;
    int      m_TextX;
    int      m_TextY;
    int      m_TextW;
    int      m_TextH;
    QColor   m_TextQColor;
private:
    QPixmap setLabelImage(const QString path_image="", int mustAppear =0);
    QPixmap setBackgroundImage(const QString path_image  = ""  , int mustAppear =0);
    QPoint  m_Screen;
    QPixmap m_Pixmap;
private slots:
    void timerDisplayDone();

};

#endif //CCOOLPOPUP_H
