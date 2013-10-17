/***************************** C_Universal_Ident.h ************************
*  #include "C_Universal_Ident.h"        QT4-ready                        *
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

#ifndef C_UNIVERSAL_IDENT_H
#define C_UNIVERSAL_IDENT_H

#include "../../C_PatientBase/C_PatientBase.h"
#include <QDate>
class QString;
//========================== C_Universal_Ident ========================================================
/*! \class  C_Universal_Ident
 *  \brief  one universal thing must be have a unique Id and designation and falcutative designation name
 */

class C_Universal_Ident
{
  public:
    C_Universal_Ident( const QString &guid       = "",
                       const QString &usual_name = "Anonymous",
                       const QString &forename   = ""
                     );
    void init( const QString &guid       = ""          ,
               const QString &usual_name = "Anonymous" ,
               const QString &forename   = ""
             );
    void           set_guid (const QString &value);
    QString        get_guid ();
    void           set_usual_name (const QString &value);
    QString        get_usual_name();
    void           set_forename (const QString &value);
    QString        get_forename();

  private:
    QString        m_guid;
    QString        m_usual_name;
    QString        m_forename;

};
//========================== C_Human_Properties ========================================================
/*! \class  C_Human_Properties
 *  \brief  one Human base identification add several things to  C_Universal_Ident : forename, young_name, sex, ageOrDateOfBirth
 *  \note   date of birth is sometimes unknown. So it is always possible to determine aproximative or precise age. So when date of birth is unknown,
 *          age is used and date of birth set to invalid date (to indicate that only age is known)
 */
class C_Human_Properties
{
  public:
    C_Human_Properties( //............ C_Human_Ident .......................
                        const QString &young_name        = "",
                        const QString &sexe              = "I",            //M male  I indetermined F female
                        const QString &ageOrDateOfBirth  = "",
                        const QString &dateFormat        = "dd-MM-yyyy"
                      );

    void                     init         ( const QString &Young_name          =  "" ,
                                            const QString &Sexe                =  "I" ,
                                            const QString &AgeOrDateOfBirth    =  ""  ,
                                            const QString &DateFormat          =  "dd-MM-yyyy"
                                          );
    void    set_young_name (const QString &value);
    QString get_young_name();
    void    set_sexe (const QString &value);
    QString get_sexe();
    void    set_ageOrDateOfBirth (const QString &ageOrDateOfBirth, const QString &dateFormat = "dd-MM-yyyy");
    void    set_ageOrDateOfBirth (const QDate &dateOfBirth);
    QDate   get_dateOfBirth();
    QString get_dateOfBirth(const QString& dateFormat);
    QString set_age(const QString &age, int keepOldAgeIfDateValid=1);
    QString get_age(int type  = 0  );

  private:
    QString m_young_name;
    QString m_sexe;
    QDate   m_dateOfBirth;
    QString m_age;
};
//========================== C_Human_Ident ========================================================
/*! \class  C_Human_Ident
 *  \brief  one Human base identification add several things to  C_Universal_Ident : forename, young_name, sex, ageOrDateOfBirth
 *  \note   date of birth is sometimes unknown. So it is always possible to determine aproximative or precise age. So when date of birth is unknown,
 *          age is used and date of birth set to invalid date (to indicate that only age is known)
 */
class C_Human_Ident : public C_Universal_Ident, public C_Human_Properties
{
  public:
    C_Human_Ident(     //............ C_Universal_Ident .......................
                       const QString &guid              = "",
                       const QString &usual_name        = "Anonymous",
                       const QString &forename          = "",

                       //............ C_Human_Ident .......................
                       const QString &young_name        = "",
                       const QString &sexe              = "I",            //M male  I indetermined F female
                       const QString &ageOrDateOfBirth  = "",
                       const QString &dateFormat        = "dd-MM-yyyy"  );

    void                     init         (const QString &Guid                =  "" ,
                                           const QString &Usual_name          =  "Anonymous" ,
                                           const QString &Forename            =  "" ,
                                           const QString &Young_name          =  "" ,
                                           const QString &Sexe                =  "I" ,
                                           const QString &AgeOrDateOfBirth    =  ""  ,
                                           const QString &DateFormat          =  "dd-MM-yyyy"
                                          );
};
//========================== C_Universal_DB_Ident ========================================================
/*! \class  C_Universal_Ident
 *  \brief  one universal thing must be have a unique Id and designation and falcutative designation name
 */

class C_Universal_DB_Ident : public C_Universal_Ident
{
  public:
    C_Universal_DB_Ident( C_PatientBase *pC_PatientBase,
                          const QString &guid       = "",
                          const QString &usual_name = "Anonymous",
                          const QString &Forename   = ""
                         );

    void init( C_PatientBase *pC_PatientBase,
               const QString &guid       = ""          ,
               const QString &usual_name = "Anonymous" ,
               const QString &Forename   = ""
             );
    QString        get_pk ();
    void           set_pk (const QString &value);
    void           set_pC_PatientBase(C_PatientBase *value);
    C_PatientBase* get_pC_PatientBase();
    C_PatientBase* gBD();
  private:
    QString        m_pk;
    C_PatientBase *m_pC_PatientBase;
};

//========================== C_Human_DB_Ident ========================================================
/*! \class  C_Human_Base_Ident
 *  \brief  one Human base identification add several things to  C_Universal_Ident : forename, young_name, sex, ageOrDateOfBirth
 *  \note   date of birth is sometimes unknown. So it is always possible to determine aproximative or precise age. So when date of birth is unknown,
 *          age is used and date of birth set to invalid date (to indicate that only age is known)
 */

class C_Human_DB_Ident : public C_Universal_DB_Ident, C_Human_Properties
{
  public:
    C_Human_DB_Ident(  //............ C_Universal_DB_Ident .......................
                       C_PatientBase *pC_PatientBase     ,
                       const QString &guid               ,
                       const QString &usual_name         ,
                       const QString &forename           ,
                       //............ C_Human_Base_Ident .......................
                       const QString &young_name         ,
                       const QString &sexe               ,            //M male  I indetermined F female
                       const QString &ageOrDateOfBirth   ,
                       const QString &dateFormat         = "yyyy-MM-dd"
                    );

    void                     init        ( //............ C_Universal_DB_Ident .......................
                                           C_PatientBase *pC_PatientBase,
                                           const QString &Guid                = "" ,
                                           const QString &Usual_name          =  "Anonymous" ,
                                           const QString &Forename            =  "" ,
                                           //............ C_Human_Base_Ident .......................
                                           const QString &Young_name          =  "" ,
                                           const QString &Sexe                =  "I" ,
                                           const QString &AgeOrDateOfBirth    =  ""  ,
                                           const QString &DateFormat          =  "dd-MM-yyyy"
                                          );
};
#endif // C_UNIVERSAL_IDENT_H
