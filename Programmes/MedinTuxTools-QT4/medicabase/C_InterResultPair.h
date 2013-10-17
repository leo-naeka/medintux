#ifndef C_INTERRESULTPAIR_H
#define C_INTERRESULTPAIR_H
#include <QString>
//======================================================= C_InterResultPair ===================================
/*! \class C_InterResultPair
 *  \brief data class used whith drugs interaction
 */
/*! \brief return interactions xml results from a cip list.
 *  \param const QStringLits &cipList      drugs CIP codes list to test.
 *  \return QStringList where each line is a xml result interaction
 *   each interaction line is a xml structure where :
 *   <itli>           </itli> delimits each interaction line structured as follows.
 *   <itli_code1>     </itli_code1>       delimits first  term code (if exists)
 *   <itli_typcode1>  </itli_typcode1>    delimits first  term codetyp examples "CIP ATC CIM10 CISP NONE AL PO"
 *   <itli_terme1>    </itli_terme1>      delimits first  term libelle text
 *   <itli_code2>     </itli_code2>       delimits second term code (if exists)
 *   <itli_typcode2>  </itli_typcode2>    delimits second term codetyp examples "CIP ATC CIM10 CISP NONE"
 *   <itli_terme2>    </itli_terme2>      delimits second term libelle text
 *   <itli_terme2>    </itli_terme2>      delimits second term libelle text
 *   <itli_texte>     </itli_texte>       delimits text interaction information
 *   <itli_ityp>      </itli_ityp>        delimits interaction type (RESERVED)
 *   <itli_level>     </itli_level>       interraction level
 */
class C_InterResultPair
{
public:
     explicit C_InterResultPair() {}
     explicit C_InterResultPair(const QString &code1, const QString &codeTyp1,  const QString &term1,
                                const QString &code2, const QString &codeTyp2,  const QString &term2,
                                const QString &info,  const QString &typ,       const QString &level)
     {setDatas(code1, codeTyp1, term1,
               code2, codeTyp2,  term2,
               info,  typ, level);
     }

     void               setDatas(const QString &code1, const QString &codeTyp1,  const QString &term1,
                                 const QString &code2, const QString &codeTyp2,  const QString &term2,
                                 const QString &info,  const QString &typ,       const QString &level)
     {    m_Code1     = code1;
          m_CodeTyp1  = codeTyp1;  // CIP CIM CISP AGE
          m_Term1     = term1;
          m_Code2     = code2;     //
          m_CodeTyp2  = codeTyp2;
          m_Term2     = term2;
          m_Info      = info;
          m_Typ       = typ;
          m_Level     = level;
     }
      QString Code1()    const   {return m_Code1;}
      QString CodeTyp1() const   {return m_CodeTyp1;}
      QString Term1()    const   {return m_Term1;}
      QString Code2()    const   {return m_Code2;}
      QString CodeTyp2() const   {return m_CodeTyp2;}
      QString Term2()    const   {return m_Term2;}
      QString Info()     const   {return m_Info;}
      QString Typ()      const   {return m_Typ;}
      QString Level()    const   {return m_Level;}

private:
     QString m_Code1;
     QString m_CodeTyp1;
     QString m_Term1;
     QString m_Code2;
     QString m_CodeTyp2;
     QString m_Term2;
     QString m_Info;
     QString m_Typ;
     QString m_Level;
};
#endif // C_INTERRESULTPAIR_H
