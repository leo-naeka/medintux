#ifndef C_POPUPDIALCORPOFACT_H
#define C_POPUPDIALCORPOFACT_H

#include <QWidget>
#include "../../MedinTuxTools-QT4/C_PopupDial/C_PopupDial.h"
#include "../../MedinTuxTools-QT4/medicabase/C_Frm_Prescription.h"
#include "ui_C_PopupDialCorpoFact.h"
namespace Ui {
               class C_PopupDialCorpoFact;
             }
//========================== C_PopupDialCorpoFact ====================================
class C_PopupDialCorpoFact : public C_PopupDial, public Ui::C_PopupDialCorpoFact
{
    Q_OBJECT

public:
    explicit C_PopupDialCorpoFact(C_Frm_PosologieHitList  *pC_Frm_PosologieHitList,
                                  const QColor    &backGround,
                                  const QRect     &initialRect,
                                  const QRect     &deployRect);
    ~C_PopupDialCorpoFact();
     void grammarToInterface(const QString &grammar);
     void setPoids();
     void setPoids(const QString &poids);

     QString get_QuPA_by_FC();        // 10
     QString get_QuPA_by_FC_Unit();   // mg
     QString get_QuFC();              // 3
     QString get_QuFC_Unit();         // Kg           --> 10 mg par 3 kg de poids
     QString get_QuPA_by_UP();        // 500 mg par comprime

protected:
    void setFont(const QFont &fnt);
private:
   C_Frm_PosologieHitList *m_pC_Frm_PosologieHitList;
   QFont                   m_fGrd;
   QString                 m_cur_grammar;
private slots:
   void Slot_pushButton_UFC_MenuTriggered( QAction *  );
   void Slot_DialCorpoFactDeployed(int &ok);
};

#endif // C_POPUPDIALCORPOFACT_H
