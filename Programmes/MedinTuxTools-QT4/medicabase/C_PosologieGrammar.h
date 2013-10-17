#ifndef C_POSOLOGIEGRAMMAR_H
#define C_POSOLOGIEGRAMMAR_H

#include<QStringList>
#include<QMap>
#include<QColor>

#include "../../MedinTuxTools-QT4/CGestIni.h"
#include "../../MedinTuxTools-QT4/medicabase/C_WordGenrePair.h"


//=================== C_PosologieGrammar ===================================
/*! \class C_PosologieGrammar
*  \brief Class to set and interpret posologie grammar.
*/

class C_PosologieGrammar
         {
          public:
                     enum flags  {NOT_LITERAL        = 0,
                                  UP_QUANTITE        = 1,
                                  UP_JUST_FRACTION   = 2,
                                  DURATION           = 4,
                                  SEQUENCE_HOUR      = 8,
                                  MOMENT_MEAL        = 16,
                                  INDICATION_LIST    = 32,
                                  INDICATION_CODE    = 64,
                                  INDICATION_TYPE    = 128,
                                  ALL_LITERAL        = 31
                                 };
                     enum indicFlag  { CODE       = 0,
                                       CODE_TYPE  = 1,
                                       LIBELLE    = 2,
                                       ALL_INDIC  = 3
                                     };
                     enum numAdjust  { NO_DECIMAL       = 0,
                                       FRACT_25         = 1,
                                       FRACT_50         = 2
                                     };
                     enum seqAdjust  { JUST_ADJUST_TOTAL_AMOUNT  = 0,
                                       ADJUST_SEQUENCES          = 1
                                     };

          //---------------------------- set_QMapGenre ----------------------------------------------
          /*! \brief intialise  QMap<QString, C_WordGenrePair> m_WordGenreMap  values to allow corect according genre and plural of a word
           *  \param const QString &textData :   data as follows : singular word 1 | plural word 1 | plural word 1f\n
           *                                                       singular word 2 | plural word 2 |m\n
           *                                     and so...
           *  \return the size of static  QMap m_WordGenreMap.
          */
  static int set_QMapGenre( const QString & path);

        //---------------------------- get_AccordedWord ----------------------------------------------
        /*! \brief intialise  QMap<QString, C_WordGenrePair>  values to allow corect according genre and plural of a word
         *  \param const QString &singularWord :  key word (not accorded)
         *  \param QString &sexe :  returned sexe for this key word
         *  \return the accorded word.
         */
  static QString get_AccordedWord(  int isPlural, const QString &key_word,  char &sexeToReturn);

         //---------------------------- setGrammar ----------------------------------------------
         /*! \brief set the literal grammar string. if empty a empty skeleton grammar  is set
         *  the grammar string is updated whith flags contents indications
         *  \param const QString &grammar_expression :   grammar string to set
         *  \return the grammar string.
         */
  static QString   setGrammar(const QString &grammar_expression);

          //---------------------------- get_indicationsList [static] ------------------------------------------------
          /*! \brief return indication list from grammar string
           *  \param const QString &grammar_expression :     grammar input string as
           *  \return list code if present as 'code'|'typCode'|'libelle'
           */
  static QStringList get_indicationsList(const QString &grammar_expression);
          //---------------------------- get_indication [static] ------------------------------------------------
          /*! \brief return indication from posologie grammar.  [static]
           *  \param const QString &grammar_expression :     grammar input string which must be modified
           *  \param , int index :     index of indication to retrieve
           *  \return indication expression as 'code'|'typCode'|'libelle'
          */
   static QString get_indication(const QString &grammar_expression, int index, int flag = C_PosologieGrammar::ALL_INDIC);
          //---------------------------- literalFlagToString [static] ------------------------------------------------
          /*! \brief return a literal string from int flag.  [static]
           *  \param int must_be_literal :    int flag
           *  \return literal string.
          */
   static QString literalFlagToString(int must_be_literal);
          //---------------------------- literalStringToFlag [static] ------------------------------------------------
          /*! \brief return the literal flag from literal string.  [static]
           *  \param const QString &conv_mod :  literal string to convert in flag
           *  \return literal flag.
           */
   static int literalStringToFlag(const QString &conv_mod);

          //---------------------------- empty_skeleton_grammar [static] ------------------------------------------------
          /*! \brief return a empty grammar string.  [static]
           *  \return empty grammar string.
          */
   static QString empty_skeleton_grammar();

          //---------------------------- setId [static] ------------------------------------------------
          /*! \brief set id code in posologie grammar.  [static]
           *  \param const QString &grammar_expression :     grammar input string which must be modified
           *  \param const QString &id :     id code to set  (usualy CIP code)
           *  \return modified grammar expression.
          */
   static QString setId(QString &grammar_expression, const QString &id);

          //---------------------------- id [static] ------------------------------------------------
          /*! \brief return the id code string from posologie grammar. If not present return "" [static]
           *  \param const QString &grammar_expression :     grammar input string as
           *  \return id code if present  (usualy CIP code).
          */
   static QString id (const QString &grammar_expression);
         //---------------------------- pk [static] ------------------------------------------------
         /*! \brief return the pk code string from posologie grammar. If not present return "" [static]
          *  \param const QString &grammar_expression :     grammar input string as
          *  \return pk code if present.
          */
   static QString pk (const QString &grammar_expression);

          //---------------------------- setIdType [static] ------------------------------------------------
          /*! \brief set setIdType code in posologie grammar.  [static]
           *  \param const QString &grammar_expression :     grammar input string which must be modified
           *  \param const QString &setIdType :     setIdType code to set
           *  \return modified grammar expression.
          */
   static QString setIdType(QString &grammar_expression, const QString &id_type);

          //---------------------------- idType [static] ------------------------------------------------
          /*! \brief return the idTyp code string from posologie grammar. If not present return "" [static]
           *  \param const QString &grammar_expression :     grammar input string as
           *  \return idTyp code if present.
           */
   static QString idType (const QString &grammar_expression);
          //---------------------------- setAld [static] ------------------------------------------------
          /*! \brief set ALD code in posologie grammar.  [static]
           *  \param const QString &grammar_expression :     grammar input string which must be modified
           *  \param const QString &ald :     ald code to set  (empty is not ALD   "ALD" is ALD).
           *  \return modified grammar expression.
          */
   static QString setAld(QString &grammar_expression, const QString &ald);

          //---------------------------- ald [static] ------------------------------------------------
          /*! \brief return the idTyp code string from posologie grammar. If not present return "" [static]
           *  \param const QString &grammar_expression :     grammar input string as
           *  \return ald code if present  (empty is not ALD   "ALD" is ALD).
           */
   static QString ald (const QString &grammar_expression);

          //---------------------------- setDrugRoute [static] ------------------------------------------------
          /*! \brief set the drug route string in posologie grammar.  [static]
          *  \param const QString &grammar_expression :     grammar input string which must be modified
          *  \param const QString &drugRoute :    drug route to set
          *  \return modified grammar expression.
         */
   static QString setDrugRoute(QString &grammar_expression, const QString &drugRoute);

         //---------------------------- drugRoute [static] ------------------------------------------------
         /*! \brief return drug route string from posologie grammar. If not present return "" [static]
          *  \param const QString &grammar_expression :     grammar input string
          *  \return the voie if present.
          */
   static QString drugRoute(const QString &grammar_expression);

         //---------------------------- setUnitPriseForm [static] ------------------------------------------------
         /*! \brief set the unit prise form string in posologie grammar.  [static]
          *  \param const QString &grammar_expression :     grammar input string which must be modified
          *  \param const QString &unitUPForm :     unit prise form to set
          *  \return modified grammar expression.
          */
   static QString setUnitPriseForm(QString &grammar_expression, const QString &unitUPForm);

         //---------------------------- unitPriseForm [static] ------------------------------------------------
         /*! \brief return the unit prise form string from posologie grammar. If not present return "" [static]
          *  \param const QString &grammar_expression :     grammar input string as
          *  \return the unit prise form if present.
          */
   static QString unitPriseForm(const QString &grammar_expression);
          //---------------------------- toMinMax_UP ------------------------------------------------
         /*! \brief  retrieve frequence of UP, minimum and maximum amount of UP  by grammar
          *  \param  const QStringList &seqList list of sequences to analyze
          *  \param  QString &q_min minimum amount of UP from this sequence
          *  \param  QString &q_max maximum amount of UP from this sequence
          *  \param  QString &q_max maximum amount of UP from this sequence
          *  \param  QString &up_formes_min_max_period return result as comprime|2|4|1440\ncomprime|1|2|1440
          *  \return QString the maximum frequence of UP by grammar
          */
   static int toMinMax_UP(const QStringList &seqList, double &q_min,  double &q_max, QString &up_formes_min_max_period);
         //---------------------------- sequence_timeToMinMax_UP ------------------------------------------------
         /*! \brief  retrieve frequence of UP, minimum and maximum amount of UP  by sequence
          *  \param  const QString &seq_time to analyze as  <b>0.5;m|1;d15r|2;sr30|3;h10-13</b>
          *  \param  QString &q_min minimum amount of UP from this sequence
          *  \param  QString &q_max maximum amount of UP from this sequence
          *  \return QString the frequence of UP by sequence
         */
   static   QString sequence_timeToMinMax_UP(const QString &seq_time,  QString &q_min,  QString &q_max);

         //---------------------------- sequence_timeToMinMax_UP [static]------------------------------------------------
         /*! \brief  retrieve frequence of UP, minimum and maximum amount of UP  by sequence
          *  \param  const QString &seq_time to analyze as  <b>0.5;m|1;d15r|2;sr30|3;h10-13</b>
          *  \param  double &q_min minimum amount of UP from this sequence
          *  \param  double &q_max maximum amount of UP from this sequence
          *  \return double the frequence of UP by sequence
          */
   static int sequence_timeToMinMax_UP(const QString &seq_time,  double &q_min,  double &q_max);

         //---------------------------- sequence_daysToUnitPeriodInMinutes ------------------------------------------------
         /*! \brief  compute a rough unit period of this prescription sequence (if one day by week --> 1440 (day) is returned)
          *  \param  const QString &seq_days to analyze as   J8 or M12
          *  \return int the period of this  UP's sequence in minute
          */
   static int sequence_daysToUnitPeriodInMinutes(const QString &seq_days);

         //---------------------------- adjustGrammarSequencesToCorporalFactor ------------------------------------------------
         /*! \brief  adjust number of UP (dosage-unit in french Prise Unit) in sequences, from corporal factor (Kg M2)
          *  \param  const QString &grammar grammar to analyze
          *  \param  double poids   Corporal Factor weight
          *  \param  double surface Corporal Factor surface
          *  \param  QString &sequencesXml XML description of sequences list
          *  \param  int doNotAdjustXMLSequences if 1/return only the minimum and maximum total amount dosage-uni otherwise 0/sequencesXml is adjusted
          *  \return QString the minimum and maximum total amount dosage-unit (in french Unit Prise UP) minimum-maximum as 2-6
         */
   static  QString adjustGrammarSequencesToCorporalFactor( const QString &grammar, double poids, double surface,  QString &sequencesXml , int doNotAdjustXMLSequence  );

         //---------------------------- totalDurationInDaysFromGrammar ------------------------------------------------
         /*! \brief compute the total duration of a prescription in days
          *  \param  const QString &grammar grammar to analyze
          *  \param  int withRepeat compute with repeat mention.
          *  \return number of days
         */
     static  double totalDurationInDaysFromGrammar( const QString &grammar , int withRepeat);

         //---------------------------- totalDurationInDays ------------------------------------------------
         /*! \brief compute the total duration of a prescription in days
          *  \param  QString duration sequence to analyze
          *  \param  int withRepeat compute with repeat mention.
          *  \return number of days
         */
   static  double totalDurationInDays( QString duration , int withRepeat);

         //---------------------------- adjustFractionalPart ------------------------------------------------
         /*! \brief return adjust decimal part to near 00,25,50,75 number value
          *  \param const QString &value to adjusted string
          *  \return the adjust value.
         */
   static QString   adjustFractionalPart(const QString& value, int mode = C_PosologieGrammar::NO_DECIMAL);

          //---------------------------- toString [static] ------------------------------------------------
          /*! \brief return human readable string from posologie grammar.
          *  \param const QString &grammar_expression     xml grammar input string as
          *      <gph>
          *         <gph_id>301546</gph_id>
          *         <gph_it>CIP</gph_it>
          *         <gph_pk>123</gph_pk>
          *         <gph_cy>M3</gph_cy>
          *         <gph_uf>comprimé</gph_uf>
          *         <gph_nm>5</gph_nm>                        // conversion mode en mode numerique UP_QUANTITE MOMENT_MEAL ALL_LITERAL (on se sert de celui-ci car plus rapide a interpreter)
          *         <gph_cm>UP_QUANTITE DURATION</gph_cm>     // traduction textuelle de <gph_nm>5</gph_nm> information lisible de celle numerique  UP_QUANTITE DURATION on a pas peur des redondances ! (vive la memoire vive et les HD)
          *         <gph_in>
          *             <gph_il>I13.1|CIP|insuffisance rénale et cardiopathie hypertensive</gph_il>
          *            <gph_il>P96.0|CIP|insuffisance rénale congénitale</gph_il>
          *         </gph_in>
          *         <gph_co>à prendre avec un grand verre d'eau sans respirer pendant 30 minutes</gph_co>
          *      </gph>
          *      <gps>
          *         <gpp>[1;m|2;M|4;s]J8</gpp>
          *         <gpp>[0.5;m|1;M15r|2;sr30|3;h10-13]J4\</gpp>
          *         <gpp>[0.5;m|1;s]J3</gpp>
          *      </gps>
          *  \param int must_be_literal  undefined if -1 (the grammar string try to be used for this and if not possible it's defined to C_PosologieGrammar::NOT_LITERAL)
          *         otherwise it's must be a combination of : C_PosologieGrammar::UP_QUANTITE
          *                                                   C_PosologieGrammar::UP_JUST_FRACTION   //  conversion uniquement de 0.25 en un quart 0.5 en un demi 0.75 en trois quart
          *                                                   C_PosologieGrammar::DURATION
          *                                                   C_PosologieGrammar::SEQUENCE_HOUR
          *                                                   C_PosologieGrammar::MOMENT_MEAL
          *                                                   C_PosologieGrammar::INDICATION_LIST   indications list must be showed
          *                                                   C_PosologieGrammar::INDICATION_CODE   indications code must be showed
          *                                                   C_PosologieGrammar::INDICATION_TYPE   indications code typ (CIP CISP etc.) must be showed
          *         this parameter define how numerics values must be converted in literal string.
          *  \param QString &_up_forme      if == "" the grammar string try to be used to define, this parameter is the drug unit form.
          *  \return a french human readable string (for other langs the source code is there after ...)
          */
   static QString   toHtml(           const QString &grammar_expression,
                                      const QString &substituableImgPath    = "",
                                      const QString &css                    = "" ,
                                      const QColor  &background             = QColor(Qt::black),
                                      const QString num_Ordre               = ""
                          );
   static QString   fuse  (           const QString &grammar_expression,
                                      QString        mask                         ,
                                      const QString &substituableImgPath     = "" ,
                                      const QString num_Ordre                = ""
                          );
   static QString   numberToLiteral( int number,     char sexe  = 'm' );

private:
   static QString   sequenceToString(int numSeq, const QString &sequence,                            int must_be_literal  = false, const QString &_up_form="" );
   static QString   dureeTotaleRenouvToString(QString  duration_syntax,                              int must_be_literal  = false );
   static QString   dureeTotaleToString(const QString &duration_syntax,                              int must_be_literal  = false );
   static QString   sequence_daysToString(int numSeq, const QString &seq_days,                       int must_be_literal  = false );
   static QString   sequence_timeToString(const QString &seq_time,                                   int must_be_literal  = false , const QString &_up_forme="" );
   static QString   numberToLiteral( QString number, QString &up_forme , int justOneFraction  = false );
   static QString   adjustPlurielUpForme(int nb, const QString &_up_forme, char &sexe);
   static QString   adjustUniteToSexe(const QString &unite, char sexe );

};



#endif // C_POSOLOGIEGRAMMAR_H
