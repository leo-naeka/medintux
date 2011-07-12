#ifndef C_PATIENT_
#define C_PATIENT_

#include <QFrame>
//=================================== C_Patient ======================================
/*! \class C_Patient
 *  \brief class derived from QFrame.
 *  - this Class is the Patient representation whith tasks buttons,
 *    expand button, and cie
 @author Roland Sevin <roland-sevin@medintux.org>
 */

class C_Patient : public QFrame
{
    Q_OBJECT
public:
    //-------------- C_Patient -----------------------------------------------------
    /*! \brief class constructor
    *   \param parent         QWidget *     : parent widget pointer (must bee a C_Wdg_Box pointer)
    */
    explicit C_Patient(QWidget *parent = 0);

    //-------------- isExpand -----------------------------------------------------
    /*! \brief return expand state
    *   \return bool : expand state
    */
    bool isExpand() {return m_IsExpand;}

    //-------------- setExpand -----------------------------------------------------
    /*! \brief set object in expand or replied state
    *   \param expandSate     bool : if TRUE set object in expand state, if FALSE in replied state
    */
    void setExpand(bool expandSate=TRUE);

protected:
    bool m_IsExpand; /*!< expand replied state    */

signals:

public slots:

};

//=================================== C_PatientTask ======================================
/*! \class C_PatientTask
 *  \brief class derived from QWidget.
 *  - this Class is the Patient task representation whith states buttons,
 @author Roland Sevin <roland-sevin@medintux.org>
 */

class C_PatientTask : public QWidget
{
    Q_OBJECT
public:
    //-------------- C_PatientTask -----------------------------------------------------
    /*! \brief class constructor
    *   \param parent         QWidget *     : parent widget pointer (must bee a C_Patient pointer)
    */
    explicit C_PatientTask(C_Patient *parent = 0);

    //-------------- getTaskState -----------------------------------------------------
    /*! \brief return task state
    *   \return QString : task state
    */
    QString getTaskState() {return m_TaskState;}

    //-------------- setTaskState -----------------------------------------------------
    /*! \brief set task state
    *   \param taskState     QString : task state
    */
    void setTaskState(QString taskState="");

protected:
    QString m_TaskState; /*!< task state    */

signals:

public slots:

};
#endif // C_PATIENT_
