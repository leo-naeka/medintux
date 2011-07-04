/********************************* CPrinter.cpp ***********************************
 *                                                                                *
 *   #include "CPrinter.h"                                                        *
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
#include "CPrinter.h" 
//====================================== CPageDef ===============================================================================


//--------------------------------- CPageDef ------------------------------------------------------------------------------------
CPageDef::CPageDef(float   cm_PageW        /* = 21.0 */ ,
                   float   cm_PageH        /* = 29.7 */ ,
                   float   cm_MrgLeft      /* = 1.0  */ ,
                   float   cm_MrgTop       /* = 1.0  */ ,
                   float   cm_MrgRight     /* = 1.0  */ ,
                   float   cm_MrgBottom    /* = 1.0  */ ,
                   float   cm_HeadH        /* = 3.0  */ ,
                   float   cm_FootH        /* = 2.0  */ ,
                   float   scale           /* = 0.3  */ ,
                   float   print_scale     /* = 0.7  */ ,
                   QPaintDevice * pd       /* = 0    */      // pour donner la resolution
                  )
{
    if (pd)
        {QPaintDeviceMetrics screen( pd );
         m_ScreenResX    = screen.logicalDpiX();
         m_ScreenResY    = screen.logicalDpiY();
        }
    else
       {m_ScreenResX    = 72;         // resolution par defaut au cas ou le periph d'entrée n'est pas donné
        m_ScreenResY    = 72;
       }
    m_Cm_PageW          = cm_PageW;
    m_Cm_PageH          = cm_PageH;
    m_Scale             = scale;     
    m_PrintScale        = print_scale;
    m_Cm_MrgLeft        = cm_MrgLeft;
    m_Cm_MrgTop         = cm_MrgTop;
    m_Cm_MrgRight       = cm_MrgRight;
    m_Cm_MrgBottom      = cm_MrgBottom;
    m_Cm_HeadH          = cm_HeadH;
    m_Cm_FootH          = cm_FootH; 
}

//--------------------------------- CPageDef ---------------------------------------------------------------------------------------
CPageDef::~CPageDef()
{ 
}

//--------------------------------- SetResolution ---------------------------------------------------------------------------------------
void CPageDef::SetResolution(int resol_X, int resol_Y)
{m_ScreenResX = resol_X;
 m_ScreenResY = resol_Y;  
}

//--------------------------------- GetResolutionX ---------------------------------------------------------------------------------------
int CPageDef::GetResolutionX()
{return (int)m_ScreenResX;
}

//--------------------------------- GetResolutionY ---------------------------------------------------------------------------------------
int CPageDef::GetResolutionY()
{return (int)m_ScreenResY;
}

//--------------------------------- GetScreenTextWorkSpaceWidth ------------------------------------------------------------------------------------
int CPageDef::GetScreenTextWorkSpaceWidth()
{ float reel_W =  m_Cm_PageW - m_Cm_MrgLeft - m_Cm_MrgRight;
  return     (int)(m_ScreenResX *reel_W      /2.54);        // in periph resolution pixels
}

//--------------------------------- GetScreenTextWorkSpaceHeightBody ------------------------------------------------------------------------------------
int CPageDef::GetScreenTextWorkSpaceHeightBody()    
{//........ hauteur page - marge haute et base - hauteur entete et pied de page
 float reel_H =  m_Cm_PageH - m_Cm_MrgTop - m_Cm_MrgBottom -  m_Cm_HeadH - m_Cm_FootH;
 return     (int)(m_ScreenResX *reel_H      /2.54);         // in periph resolution pixels
}

//--------------------------------- GetScreenTextWorkSpaceHeightHead ------------------------------------------------------------------------------------
int CPageDef::GetScreenTextWorkSpaceHeightHead()
{return     (int)(m_ScreenResX * m_Cm_HeadH      /2.54);    // in periph resolution pixels
}

//--------------------------------- GetScreenTextWorkSpaceHeightFoot ------------------------------------------------------------------------------------
int CPageDef::GetScreenTextWorkSpaceHeightFoot()
{return     (int)(m_ScreenResX * m_Cm_FootH      /2.54);    // in periph resolution pixels
}

//--------------------------------- GetScreenTextWorkSpaceHeight ------------------------------------------------------------------------------------
int CPageDef::GetScreenTextWorkSpaceHeight()
{float reel_H =  m_Cm_PageH - m_Cm_MrgTop - m_Cm_MrgBottom;
 return     (int)(m_ScreenResX *reel_H      /2.54);         // in periph resolution pixels
}



//====================================== CViewPageWidget =========================================================================

//--------------------------------- CViewPageWidget ------------------------------------------------------------------------------
 CViewPageWidget::CViewPageWidget(QWidget*         parent ,         /* = 0 */ 
                                  const char*      name ,           /* = 0 */
                                  WFlags           f,               /* = 0 */  
                                  QSimpleRichText* pRichTextBody,   /* = 0 */
                                  CPageDef*        pCPageDef,       /* = 0 */                                  
                                  QSimpleRichText* pRichTextHead,   /* = 0 */
                                  QSimpleRichText* pRichTextFoot    /* = 0 */
                                 )
    : QWidget( parent, name,   f  )   // important permet que le widget soit enfant du parent
{
 //............ si une definition de page donnée en entrée on l'utilise au lieu de celle par defaut ........................
 //             donnée par le constructeur de :  m_CPageDef  
 if (pCPageDef)  
     m_CPageDef  = *pCPageDef;  
 
 m_pRichTextHead = pRichTextHead;
 m_pRichTextBody = pRichTextBody;
 m_pRichTextFoot = pRichTextFoot;
 
 m_CurrentPage   = 1;
 
 if (parent)
    {QPaintDeviceMetrics screen( parent );
     m_ScreenResX    =  screen.logicalDpiX();
     m_ScreenResY    =  screen.logicalDpiY();
    }
 else
    {m_ScreenResX    = 72;         // resolution par defaut au cas ou le periph d'entrée n'est pas donné
     m_ScreenResY    = 72;
    }
 
 m_CPageDef.SetResolution(m_ScreenResX, m_ScreenResY);
 //brush ( ColorRole r ) 
 //setPaletteBackgroundColor (QColor(0xFF,0xFF,0xFF));
 // setPaletteBackgroundColor (colorGroup().background ());
  setPaletteBackgroundColor (colorGroup().base ());
}

//--------------------------------- CViewPageWidget ------------------------------------------------------------------------------------
// CViewPageWidget::~CViewPageWidget()
//{
//}
 
//--------------------------------- GetResolutionX ---------------------------------------------------------------------------------------
int CViewPageWidget::GetResolutionX()
{return m_ScreenResX;
}

//--------------------------------- GetResolutionY ---------------------------------------------------------------------------------------
int CViewPageWidget::GetResolutionY()
{return m_ScreenResY;
} 

//--------------------------------- SetResolution ---------------------------------------------------------------------------------------
void CViewPageWidget::SetResolution(int resol_X, int resol_Y)
{m_ScreenResX = resol_X;
 m_ScreenResY = resol_Y;
 m_CPageDef.SetResolution(resol_X, resol_Y);
}

//--------------------------------- SetBody ------------------------------------------------------------------------------------
void CViewPageWidget::SetBody(QSimpleRichText* pRichText)
{m_pRichTextBody = pRichText;

}

//--------------------------------- SetHead ------------------------------------------------------------------------------------
void CViewPageWidget::SetHead(QSimpleRichText* pRichText)
{m_pRichTextHead = pRichText;

}

//--------------------------------- SetFoot ------------------------------------------------------------------------------------
void CViewPageWidget::SetFoot(QSimpleRichText* pRichText)
{m_pRichTextFoot = pRichText;
 
}

//--------------------------------- GetWidgetWidth ------------------------------------------------------------------------------------
int CViewPageWidget::GetWidgetWidth()
{int w        =  (int)((m_ScreenResX * m_CPageDef.m_Cm_PageW      /2.54) * m_CPageDef.m_Scale) + 20;
 return w;
}

//--------------------------------- GetWidgetHeight ------------------------------------------------------------------------------------
int CViewPageWidget::GetWidgetHeight()
{int h        =  (int)((m_ScreenResY * m_CPageDef.m_Cm_PageH      /2.54) * m_CPageDef.m_Scale) + 20;
 return h;
}

//--------------------------------- GetPageW ------------------------------------------------------------------------------------
float CViewPageWidget:: GetPageW()
{return m_CPageDef.m_Cm_PageW;
}

//--------------------------------- GetPageH ------------------------------------------------------------------------------------
float CViewPageWidget:: GetPageH()
{return m_CPageDef.m_Cm_PageH;
}

//--------------------------------- GetLeftMarg ------------------------------------------------------------------------------------
float CViewPageWidget:: GetLeftMarg()
{return m_CPageDef.m_Cm_MrgLeft;
}

//--------------------------------- GetWidgetHeight ------------------------------------------------------------------------------------

float CViewPageWidget::GetTopMarg()
{return m_CPageDef.m_Cm_MrgTop;
}

//--------------------------------- GetRightMarg ------------------------------------------------------------------------------------

float CViewPageWidget::GetRightMarg()
{return m_CPageDef.m_Cm_MrgRight;
}

//--------------------------------- GetWidgetHeight ------------------------------------------------------------------------------------

float CViewPageWidget::GetBottomMarg()
{return m_CPageDef.m_Cm_MrgBottom;
}

//--------------------------------- GetHead_H ------------------------------------------------------------------------------------
float CViewPageWidget::GetHead_H()
{return m_CPageDef.m_Cm_HeadH;
}

//--------------------------------- GetFoot_H ------------------------------------------------------------------------------------
float CViewPageWidget::GetFoot_H()
{return m_CPageDef.m_Cm_FootH;
}

//--------------------------------- GetPrintScale ------------------------------------------------------------------------------------
float CViewPageWidget::GetPrintScale()
{return m_CPageDef.m_PrintScale;
}
   
//--------------------------------- SetLeftMarg ------------------------------------------------------------------------------------
float CViewPageWidget::SetLeftMarg(float value)
{float old_value            = m_CPageDef.m_Cm_MrgLeft;
 m_CPageDef.m_Cm_MrgLeft    = value;   
 return old_value;
}

//--------------------------------- SetTopMarg ------------------------------------------------------------------------------------
float CViewPageWidget::SetTopMarg(float value)
{float old_value            = m_CPageDef.m_Cm_MrgTop;
 m_CPageDef.m_Cm_MrgTop     = value;   
 return old_value;
}

//--------------------------------- SetRightMarg ------------------------------------------------------------------------------------
float CViewPageWidget::SetRightMarg(float value)
{float old_value           = m_CPageDef.m_Cm_MrgRight;
 m_CPageDef.m_Cm_MrgRight  = value;   
 return old_value;
}

//--------------------------------- SetBottomMarg ------------------------------------------------------------------------------------
float CViewPageWidget::SetBottomMarg(float value)
{float old_value            = m_CPageDef.m_Cm_MrgBottom;
 m_CPageDef.m_Cm_MrgBottom  = value;   
 return old_value;
}

//--------------------------------- SetHead_H ------------------------------------------------------------------------------------
float CViewPageWidget::SetHead_H(float value)
{float old_value          = m_CPageDef.m_Cm_HeadH;
 m_CPageDef.m_Cm_HeadH    = value;   
 return old_value;
}

//--------------------------------- SetFoot_H ------------------------------------------------------------------------------------
float CViewPageWidget::SetFoot_H(float value)
{float old_value          = m_CPageDef.m_Cm_FootH;
 m_CPageDef.m_Cm_FootH    = value;   
 return old_value;
}

//--------------------------------- SetPrintScale ------------------------------------------------------------------------------------
float CViewPageWidget::SetPrintScale(float value)
{float old_value          = m_CPageDef.m_PrintScale;
 m_CPageDef.m_PrintScale  = value;   
 return old_value;
}

//--------------------------------- GetRichHead_H ------------------------------------------------------------------------------------
float CViewPageWidget::GetRichHead_H()
{return m_pRichTextHead->height()*2.54/m_ScreenResY;
}

//--------------------------------- GetRichBody_H ------------------------------------------------------------------------------------
float CViewPageWidget::GetRichBody_H()
{return m_pRichTextBody->height()*2.54/m_ScreenResY;
}

//--------------------------------- GetRichFoot_H ------------------------------------------------------------------------------------
float CViewPageWidget::GetRichFoot_H()
{return m_pRichTextFoot->height()*2.54/m_ScreenResY; 
}

//--------------------------------- GetCurrentPage ------------------------------------------------------------------------------------
int  CViewPageWidget::GetCurrentPage()
{return m_CurrentPage;
}

//--------------------------------- SetCurrentPage ------------------------------------------------------------------------------------
int  CViewPageWidget::SetCurrentPage(int page)
{if (page < 1)             page = 1;
 if (page > GetNbPage())   page = GetNbPage();
 m_CurrentPage = page ;
 return page;
}

//--------------------------------- paintEvent ------------------------------------------------------------------------------------
void CViewPageWidget::paintEvent( QPaintEvent* )
{
 QPainter  p(this);
 PrintDoc(&p, m_CurrentPage, m_CPageDef.m_Scale, m_CPageDef.m_Scale);
 /*
 
 QRect ur = e->rect();            // rectangle to update
 QPixmap pix( ur.size() );        // Pixmap for double-buffering
 //pix.fill( this, ur.topLeft() );   // fill with widget background
 pix.fill(QColor(0xFF,0xFF,0xFF) );  // fill with widget background
 QPainter p( &pix );
 QFont    font( "Arial Narrow", 10 );
 p.setFont( font );                                               // when drawing on pixmap
 
 p.translate( -ur.x()+10, -ur.y()+10 );                           // use widget coordinate system + widget marge
 
 int x        = 0;
 int y        = 0;
 int w        =  (m_ScreenResX * m_CPageDef.m_Cm_PageW      /2.54);    // in periph resolution pixels
 int h        =  (m_ScreenResY * m_CPageDef.m_Cm_PageH      /2.54);    // in periph resolution pixels
 int left_M   =  (m_ScreenResX * m_CPageDef.m_Cm_MrgLeft    /2.54);    // in periph resolution pixels
 int top_M    =  (m_ScreenResY * m_CPageDef.m_Cm_MrgTop     /2.54);    // in periph resolution pixels
 int right_M  =  (m_ScreenResX * m_CPageDef.m_Cm_MrgRight   /2.54);    // in periph resolution pixels
 int bottom_M =  (m_ScreenResY * m_CPageDef.m_Cm_MrgBottom  /2.54);    // in periph resolution pixels
 int head_H   =  (m_ScreenResY * m_CPageDef.m_Cm_HeadH      /2.54);    // in periph resolution pixels
 int foot_H   =  (m_ScreenResY * m_CPageDef.m_Cm_FootH      /2.54);    // in periph resolution pixels
 
 p.scale (m_CPageDef.m_Scale, m_CPageDef.m_Scale );
 //........................................ entete ................................................................
 QRect head_rect ( (x + left_M)              ,                            //  X
                   (y + top_M )              ,                            //  Y
                   (w - left_M - right_M )   ,                            //  Largeur
                   (head_H )                                              //  Hauteur
                 );
 
 if (m_pRichTextHead)
    {m_pRichTextHead->setWidth( &p, w - left_M - right_M);                // in periph resolution pixels
     m_pRichTextHead->draw( &p,
                            head_rect.left(), 
                            head_rect.top(), 
                            head_rect,              // rectangle de clip de la dimension d'une page
                            colorGroup() );
    }
 
 //........................................ body ................................................................
 QRect body_rect( (x + left_M)               ,                           //  X
                  (y + top_M  + head_H)      ,                           //  Y
                  (w - left_M - right_M )                    ,           //  Largeur
                  (h - top_M  - bottom_M - head_H - foot_H)              //  Hauteur
                );
 
 if (m_pRichTextBody)
    {m_pRichTextBody->setWidth( &p, w - left_M - right_M);                // in periph resolution pixels
     m_pRichTextBody->draw( &p,
                            body_rect.left(), 
                            body_rect.top(), 
                            body_rect,              // rectangle de clip de la dimension d'une page
                            colorGroup() );
    }
 //........................................ foot ................................................................
 QRect foot_rect ( (x + left_M)                 ,                            //  X
                   (y + h - bottom_M - foot_H ) ,                            //  Y
                   (w - left_M - right_M )      ,                            //  Largeur
                   (foot_H )                                                 //  Hauteur
                 );
 
 if (m_pRichTextFoot)
    {m_pRichTextFoot->setWidth( &p, w - left_M - right_M);                // in periph resolution pixels
     m_pRichTextFoot->draw( &p,
                            foot_rect.left(), 
                            foot_rect.top(), 
                            foot_rect,              // rectangle de clip de la dimension d'une page
                            colorGroup() );
    }
 p.drawRect (x,y,w,h); 
 
 //  Qt::NoPen - no line at all. For example, QPainter::drawRect() fills but does not draw any boundary line. 
 //  Qt::SolidLine - a simple line. 
 //  Qt::DashLine - dashes separated by a few pixels. 
 //  Qt::DotLine - dots separated by a few pixels. 
 //  Qt::DashDotLine - alternate dots and dashes. 
 //  Qt::DashDotDotLine - one dash, two dots, one dash, two dots. 
 //  Qt::MPenStyle - mask of the pen styles. 

 //.................................. marges standard ......................................................................
 p.setPen ( QColor(96,164,168));
 //p.setPen (Qt::DotLine);
 p.drawLine (x + left_M,       y,                 x + left_M,       y + h);                          // marge gauche
 p.drawLine (x + w - right_M,  y,                 x + w - right_M,  y + h);                          // marge droite
 p.drawLine (x ,               y + top_M,         x + w,            y + top_M);                      // marge haute
 p.drawLine (x ,               y + h - bottom_M,  x + w,            y + h - bottom_M);               // marge basse
 //.................................. marges Header et Foot ................................................................
 int pos_y;
 p.setPen ( QColor(186,52,22));
 //p.setPen (Qt::DashDotLine);
 pos_y = y + top_M +        (m_ScreenResY * m_CPageDef.m_Cm_HeadH   /2.54);
 p.drawLine (x ,                          pos_y,                        x + w,                       pos_y);           // header 
 pos_y = y + h - bottom_M - (m_ScreenResY * m_CPageDef.m_Cm_FootH   /2.54);
 p.drawLine (x ,                          pos_y,                        x + w,                       pos_y);           // foot  
 
 
 p.setPen (Qt::SolidLine);
 p.end();

 bitBlt( this, ur.topLeft(), &pix );
 */
}

//---------------------------------- GetNbPage ---------------------------------------------------------------------------------
int CViewPageWidget::GetNbPage()
{QPainter  p(this);
 if (m_pRichTextBody==0) return 0;
 //............................. quelques conversions des Cm vers les pixels impression ...........................
 int w        =  (int)(m_ScreenResX * m_CPageDef.m_Cm_PageW      /2.54);    // in periph resolution pixels
 int h        =  (int)(m_ScreenResY * m_CPageDef.m_Cm_PageH      /2.54);    // in periph resolution pixels
 int left_M   =  (int)(m_ScreenResX * m_CPageDef.m_Cm_MrgLeft    /2.54);    // in periph resolution pixels
 int top_M    =  (int)(m_ScreenResY * m_CPageDef.m_Cm_MrgTop     /2.54);    // in periph resolution pixels
 int right_M  =  (int)(m_ScreenResX * m_CPageDef.m_Cm_MrgRight   /2.54);    // in periph resolution pixels
 int bottom_M =  (int)(m_ScreenResY * m_CPageDef.m_Cm_MrgBottom  /2.54);    // in periph resolution pixels
 int head_H   =  (int)(m_ScreenResY * m_CPageDef.m_Cm_HeadH      /2.54);    // in periph resolution pixels
 int foot_H   =  (int)(m_ScreenResY * m_CPageDef.m_Cm_FootH      /2.54);    // in periph resolution pixels
 
 //......................................... compter le Nb de page ...............................................
 m_pRichTextBody->setWidth( &p, w - left_M - right_M); 
 int body_H  = h - top_M  - bottom_M - head_H - foot_H;
 int docu_H  = m_pRichTextBody->height();
 if (body_H==0||docu_H==0) return 0;

 int nb_page = 0;
 while(docu_H>0)
    {docu_H -= body_H;
     ++nb_page;
    }
 return  nb_page;
}
//--------------------------------- PrintDoc ------------------------------------------------------------------------------------
int CViewPageWidget::PrintDoc(QPainter*  p, int page, float zoomX /* =1.0 */, float zoomY /* =1.0 */, int flag /*=1 */)
{return PrintDoc(p, page, zoomX, zoomY,  flag, m_ScreenResX, m_ScreenResY);
}

//--------------------------------- PrintDoc ---------------------------------------
/*! \brief Prépare le document à imprimer dans le QPainter p passé en paramètre.
 * \param p : QPainter qui reçoit le document page par page construit selon les paramètres passés à drtux en incluant entête et pied de page.
 * \param page : Prépare la page X du dit document
 * \param zoomX
 * \param zoomY
 * \param flag
 * \param resX : resolution en X
 * \param resY : resolution en Y
 * \param end=0 : =1 -> ne termine pas le QPainter (utilisé pour imprimer plusieurs pages dans un travail d'impression). =1 termine le QPainter.
*/
int CViewPageWidget::PrintDoc(QPainter*  p, int page, float zoomX , float zoomY , int flag , int resX, int resY, int end /*=0*/)
{
 //QFont     font( "Arial Narrow", 8 );
 
//enum ColorRole { Foreground, Button, Light, Midlight, Dark, Mid, Text, BrightText, ButtonText, Base, Background, Shadow, Highlight, HighlightedText, Link, LinkVisited, NColorRoles }
//const QColor & color ( ColorRole r ) const
//const QBrush & brush ( ColorRole r ) const
//void setColor ( ColorRole r, const QColor & c )
//void setBrush ( ColorRole r, const QBrush & b )
 //..................  toutes les couleurs par defaut du texte sur noir ......................
 QColorGroup sp_colorgroup (colorGroup());
 sp_colorgroup.setColor (QColorGroup::Text, QColor(0,0,0) );
 sp_colorgroup.setColor (QColorGroup::BrightText, QColor(0,0,0) );
 sp_colorgroup.setColor (QColorGroup::ButtonText, QColor(0,0,0) );
 sp_colorgroup.setColor (QColorGroup::HighlightedText, QColor(0,0,0) );
 
 //p->setFont( font );  
 //.............................. translater de 10 pour centrer cadre blanc .......................................
 //                     en effet le widget est de 20 pixels plus large que le document
 //                          soit 10 en haut et gauche et 10 en bas et droite
 if (flag) p->translate( 10, 10 );                           
 //............................. quelques conversions des Cm vers les pixels impression ...........................
 int x        = 0;
 int y        = 0;
 int w        =  (int)(resX * m_CPageDef.m_Cm_PageW      /2.54);    // in periph resolution pixels
 int h        =  (int)(resY * m_CPageDef.m_Cm_PageH      /2.54);    // in periph resolution pixels
 int left_M   =  (int)(resX * m_CPageDef.m_Cm_MrgLeft    /2.54);    // in periph resolution pixels
 int top_M    =  (int)(resY * m_CPageDef.m_Cm_MrgTop     /2.54);    // in periph resolution pixels
 int right_M  =  (int)(resX * m_CPageDef.m_Cm_MrgRight   /2.54);    // in periph resolution pixels
 int bottom_M =  (int)(resY * m_CPageDef.m_Cm_MrgBottom  /2.54);    // in periph resolution pixels
 int head_H   =  (int)(resY * m_CPageDef.m_Cm_HeadH      /2.54);    // in periph resolution pixels
 int foot_H   =  (int)(resY * m_CPageDef.m_Cm_FootH      /2.54);    // in periph resolution pixels
 
 //........................................ echelle ...............................................................
 p->scale (zoomX, zoomY );

 //........................................ entete ................................................................
 QRect head_rect ( (x + left_M)              ,                            //  X
                   (y + top_M )              ,                            //  Y
                   (w - left_M - right_M )   ,                            //  Largeur
                   (head_H )                                              //  Hauteur
                 );
 
 if (m_pRichTextHead)
    {m_pRichTextHead->setWidth( p, w - left_M - right_M);                // in periph resolution pixels

     m_pRichTextHead->draw( p,
                            head_rect.left(), 
                            head_rect.top(), 
                            head_rect,              // rectangle de clip de la dimension d'une page
                            sp_colorgroup);

    }
 
 //........................................ body ................................................................
 //p->drawLine (x ,     m_pRichTextHead->height()+top_M,      x + w,         m_pRichTextHead->height()+top_M);           // header richText.height()
 QRect body_rect( (x + left_M)               ,                           //  X
                  (y + top_M  + head_H)      ,                           //  Y
                  (w - left_M - right_M )                    ,           //  Largeur
                  (h - top_M  - bottom_M - head_H - foot_H)              //  Hauteur
                );
 
 QRect view_rect( body_rect );
 view_rect.moveBy( 0,     body_rect.height() * (page-1)  );
 p->translate(     0 , - (body_rect.height() * (page-1)) );
 if (m_pRichTextBody)
    {  m_pRichTextBody->setWidth( p, w - left_M - right_M);                // in periph resolution pixels
       /*
       for (int py= body_rect.top(); py<=body_rect.bottom(); ++py)
         { int lm = 20;
           if (!m_pRichTextBody->inText ( QPoint(20,py) ))
              {p->setPen ( QColor("blue") );     
               p->drawLine (20 ,      py,                 200,       py);                          // marge gauche
              }
           else 
              {p->setPen ( QColor("grey") );     
               p->drawLine (20 ,      py,                 200,       py);                          // marge gauche
              }
         }
         */
     m_pRichTextBody->draw( p,
                            body_rect.left(), 
                            body_rect.top(), 
                            view_rect,              // rectangle de clip de la dimension d'une page
                            sp_colorgroup );
     }
 p->translate(     0 ,   (body_rect.height() * (page-1)) );
 
 //........................................ foot ................................................................
 QRect foot_rect ( (x + left_M)                 ,                            //  X
                   (y + h - bottom_M - foot_H ) ,                            //  Y
                   (w - left_M - right_M )      ,                            //  Largeur
                   (foot_H )                                                 //  Hauteur
                 );
 
 if (m_pRichTextFoot)
    {m_pRichTextFoot->setWidth( p, w - left_M - right_M);                // in periph resolution pixels
     m_pRichTextFoot->draw( p,
                            foot_rect.left(), 
                            foot_rect.top(), 
                            foot_rect,              // rectangle de clip de la dimension d'une page
                            sp_colorgroup );
    }
 //......................... petit rappel sur les attributs de lignes .........................................................
 //                          (si couleur tout est en mode solide)
 //  Qt::NoPen - no line at all. For example, QPainter::drawRect() fills but does not draw any boundary line. 
 //  Qt::SolidLine - a simple line. 
 //  Qt::DashLine - dashes separated by a few pixels. 
 //  Qt::DotLine - dots separated by a few pixels. 
 //  Qt::DashDotLine - alternate dots and dashes. 
 //  Qt::DashDotDotLine - one dash, two dots, one dash, two dots. 
 //  Qt::MPenStyle - mask of the pen styles. 
 if (flag)
    {//................................ dessins des cadres et lignes ...........................................................
     p->drawRect (x,y,w,h); 
  
     //.................................. marges standard ......................................................................
     // p->setPen ( QColor(96,164,168));
     p->setPen ( colorGroup().button  ());
     
     p->drawLine (x + left_M,       y,                 x + left_M,       y + h);                          // marge gauche
     p->drawLine (x + w - right_M,  y,                 x + w - right_M,  y + h);                          // marge droite
     p->drawLine (x ,               y + top_M,         x + w,            y + top_M);                      // marge haute
     p->drawLine (x ,               y + h - bottom_M,  x + w,            y + h - bottom_M);               // marge basse
     //.................................. marges Header et Foot ................................................................
     int pos_y;
     p->setPen ( QColor(186,52,22));
     pos_y = y + top_M +        (int)(resY * m_CPageDef.m_Cm_HeadH   /2.54);
     p->drawLine (x ,     pos_y,      x + w,         pos_y);           // header
     
     pos_y = y + h - bottom_M - (int)(resY * m_CPageDef.m_Cm_FootH   /2.54);
     p->drawLine (x ,     pos_y,      x + w,         pos_y);           // foot      
    }   
 if (end) p->end();
 return 1;
}



