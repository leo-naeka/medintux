#include "C_Patient.h"
//============================= C_Patient ================================================
//----------------------------- C_Patient ------------------------------------------------
C_Patient::C_Patient(QWidget *parent) :
    QFrame(parent)
{setExpand(TRUE);
}
//----------------------------- setExpand ------------------------------------------------
void C_Patient::setExpand(bool expandSate /*=TRUE*/ )
{m_IsExpand=expandSate;
}


//============================= C_PatientTask ================================================
//----------------------------- C_PatientTask ------------------------------------------------
C_PatientTask::C_PatientTask(C_Patient *parent) :
    QWidget(parent)
{setTaskState(tr("Waiting"));
}
//----------------------------- setTaskState ------------------------------------------------
void C_PatientTask::setTaskState(QString taskState /*=""*/)
{m_TaskState=taskState;
}
