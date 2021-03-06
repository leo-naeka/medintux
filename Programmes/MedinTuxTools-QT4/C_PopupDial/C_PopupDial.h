#ifndef C_POPUPDIAL_H
#define C_POPUPDIAL_H
#include <QWidget>
#include <QFrame>
#include <QPropertyAnimation>


/*! \class C_PopupDial
 *  \brief class to display expandable animated widget.
 *  the principe is a widget with two state :
 *           deployed state wich shows the entire widget.
 *           initial replied state wich shows only a part of widget
 *  when mouse is on replied (or initial) rectangle, the widget
 *  is deployed with animation effect.
 *  when mouse is out the deployed rectangle, the widget returns
 *  to is initial rectangle with animation effect.
 *
 *  to use it with ui Qt Designers classes folows model thereafter.
 *  first create in your project a new Qt designer widget class.
 *  In this exemple : C_PopupDial_Widget
 *  the project compilation make :  ui_C_PopupDial_Widget.h class
 *  wich constructs all widgets.
 *
 *  in your project, change skeletons generated by Qtcreator :
 *           C_PopupDial_Widget.h
 *           C_PopupDial_Widget.cpp    as folows
 *
 *
 *------------ C_PopupDial_Widget.h -------------------------------------
 *     #ifndef C_POPUPDIAL_WIDGET_H
 *     #define C_POPUPDIAL_WIDGET_H
 *
 *     #include <QWidget>
 *     #include "../../MedinTuxTools-QT4/C_PopupDial/C_PopupDial.h"   // include animated properties
 *
 *     #include "ui_C_PopupDial_Widget.h"   // generated by Qtcreator from QT Designer file : C_PopupDial_Widget.ui
 *     namespace Ui {
 *                    class C_PopupDial_Widget;
 *                  }
 *     //========================== C_PopupDial_Widget ====================================
 *     class C_PopupDial_Widget : public C_PopupDial,                     // expandable animated base class
 *                                public Ui::ui_C_PopupDial_Widget        // class wich constructs all Qt designers widgets
 *     {
 *        Q_OBJECT
 *
 *      public:
 *           explicit C_PopupDial_Widget(       QWidget      *parent,           // parent widget
 *                                              const QColor &backGround,       // color background
 *                                              const QRect  &initialRect,      // initial rectangle  (allway visible)
 *                                              const QRect  &deployRect);      // deployed rectangle (deployed when mousse is on initial)
 *           ~C_PopupDial_Widget();
 *
 *      private:
 *                  // your private specifications
 *     };
 *
 *     #endif // C_POPUPDIAL_WIDGET_H
 *
 *------------ C_PopupDial_Widget.cpp -------------------------------------
 *     C_PopupDial_Widget::C_PopupDial_Widget(    QWidget      *parent,        // parent widget
 *                                                const QColor &backGround,    // color background
 *                                                const QRect  &initialRect,   // initial rectangle  (allway visible)
 *                                                const QRect  &deployRect) :  // deployed rectangle (deployed when mousse is on initial)
 *     C_PopupDial(parent, backGround, initialRect, deployRect)                 //
 *     {   setupUi(this);                            // set all Qt designers widgets
 *         setRectanngles( initialRect,              // set initial rectangle  (allway visible)
 *                         QRect( deployRect.x(),    // keep x deployed position
 *                                deployRect.y(),    // keep y deployed position
 *                                width(),           // adjust width  to Qt designer widget width
 *                                height()           // adjust height to Qt designer widget height
 *                              )
 *                       );
 *     }
 *
 *     C_PopupDial_Widget::~C_PopupDial_Widget()
 *     {
 *     }
 */

//======================== C_PopupDial =============================
class C_PopupDial : public QFrame  //, C_PosologieGrammar
{
    Q_OBJECT
public:
    enum mode     {   SLOW     = 0,
                      FAST     = 1
                   };

    C_PopupDial (QWidget      *parent,
                 const QColor &backGround,
                 const QRect  &initialRect,
                 const QRect  &deployRect
                );
    ~C_PopupDial(){}
    bool  isDeploy();
    void  setToInitialRect(int fast = C_PopupDial::SLOW);
    void  setToDeployRect (int fast = C_PopupDial::SLOW);
    void  setAlpha(int value){m_alpha = value;}
    void  setDuration(int value) {m_duration = value;}
    void  setGeometry(const QRect &rect);
    void  translateGeometry(int dx, int dy);
    void  setGeometry(const QRect &initialRect, const QRect &deployRect);
    void  setRectanngles(const QRect &initialRect, const QRect &deployRect);
    QRect  deployRect() {return m_deployRect;}
    QRect  initialRect(){return m_initialRect;}

protected:
    bool  event ( QEvent * ev );
    void  paintEvent ( QPaintEvent * event );
protected:
    QRect               m_deployRect;
    QRect               m_initialRect;

private:
    QColor              m_backGround;
    QPropertyAnimation *m_animation;
    int                 m_alpha;
    int                 m_duration;
    QString             m_direction;

public slots:
    void Slot_finished();
signals:
    void Sign_deployed(int &ok);
    void Sign_deployed(C_PopupDial *pC_PopupDial);
    void Sign_minimized(int &ok);
    void Sign_minimized(C_PopupDial *pC_PopupDial);
    void Sign_finished(const QString &direction);
};

#endif // C_POPUPDIAL_H
