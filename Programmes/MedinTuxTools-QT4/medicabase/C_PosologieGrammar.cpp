#include "../../MedinTuxTools-QT4/CGestIni.h"
#include "../../MedinTuxTools-QT4/medicabase/C_PosologieGrammar.h"
#include <QDateTime>
#include <QPixmap>
#include <float.h>
//=================== C_PosologieGrammar ===================================
/*! \class C_PosologieGrammar
 *  \brief Class to set and interpret posologie grammar.
 */
 static QMap<QString, C_WordGenrePair> m_WordGenreMap;	/*!< Contient le dictionnaire de mots */
//---------------------------- get_AccordedWord [static]----------------------------------------------
/*! \brief intialise  QMap<QString, C_WordGenrePair>  values to allow corect according genre and plural of a word
 *  \param const QString &textData :   data as follows :  key_word 1 | singular word 1 | plural word 1 | f \n
 *                                                        key_word 2 | singular word 2 | plural word 2 | m \n
 *                                     and so...
  *  \return the size correct accorded plural singular word and sexe genre
*/
QString C_PosologieGrammar::get_AccordedWord( int isPlural, const QString &key_word, char &sexe )
{
    QMap<QString, C_WordGenrePair>::const_iterator it = m_WordGenreMap.find( key_word );
    if ( it == m_WordGenreMap.end() )
       { sexe = 'm';
         return key_word;
       }
    C_WordGenrePair wordGenrePair = it.value();
    sexe                          = wordGenrePair.sexe();
    if (isPlural>1)  return wordGenrePair.plural_word();
    else             return wordGenrePair.singular_word();
}

//---------------------------- set_QMapGenre [static]----------------------------------------------
/*! \brief intialise  QMap<QString, C_WordGenrePair> m_WordGenreMap  values to allow corect according genre and plural of a word
 *  \param const QString &textData :   data as follows : key_word 1 | singular word 1 | plural word 1 | f \n
 *                                                       key_word 2 | singular word 2 | plural word 2 | m \n
 *                                     and so...
 *  \return the size of static  QMap m_WordGenreMap.
*/
int C_PosologieGrammar::set_QMapGenre( const QString & path)
{
    QString      textData = CGestIni::Param_UpdateFromDisk(path);
    if ( textData.length() ==0 )  return 0;
    textData.remove('\r');
    QStringList linesList = textData.split('\n');
    for (int i=0; i<linesList.size(); ++i)
        { QStringList    partsList = linesList[i].split('|');
          if (partsList.size()==4)
             { QString              key = partsList[0];
               m_WordGenreMap.insert (  key, C_WordGenrePair (   partsList[0].trimmed(),                 // orthographe approximative ( mot clef de recherche )
                                                                 partsList[1].trimmed(),                 // orthographe correcte singulier Masculin/Feminin
                                                                 partsList[2].trimmed(),                 // orthographe correcte pluriel   Masculin/Feminin
                                                                 partsList[3].trimmed()[0].toLatin1()    // sexe
                                                             )
                                     );
             }  // if (partsList.size()==4)
         }  // for (int i=0; i<linesList.size(); ++i)
    return m_WordGenreMap.size();
}

//---------------------------- literalFlagToString [static] ------------------------------------------------
/*! \brief return a literal string from int flag.  [static]
 *  \param int must_be_literal :    int flag
 *  \return literal string.
*/
QString C_PosologieGrammar::literalFlagToString(int must_be_literal)
{QString ret = "";
if (must_be_literal & C_PosologieGrammar::UP_QUANTITE)        ret += "UP_QUANTITE ";
if (must_be_literal & C_PosologieGrammar::DURATION)           ret += "DURATION ";
if (must_be_literal & C_PosologieGrammar::SEQUENCE_HOUR)      ret += "SEQUENCE_HOUR ";
if (must_be_literal & C_PosologieGrammar::MOMENT_MEAL)        ret += "MOMENT_MEAL ";
if (must_be_literal & C_PosologieGrammar::UP_JUST_FRACTION)   ret += "UP_JUST_FRACTION ";
return ret;
}
//---------------------------- literalStringToFlag [static] ------------------------------------------------
/*! \brief return the literal flag from literal string.  [static]
 *  \param const QString &conv_mod :  literal string to convert in flag
 *  \return literal flag.
*/
int C_PosologieGrammar::literalStringToFlag(const QString &conv_mod)
{int must_be_literal = 0;
 if (conv_mod.contains("UP_QUANTITE"))        must_be_literal |= C_PosologieGrammar::UP_QUANTITE;
 if (conv_mod.contains("DURATION"))           must_be_literal |= C_PosologieGrammar::DURATION;
 if (conv_mod.contains("SEQUENCE_HOUR"))      must_be_literal |= C_PosologieGrammar::SEQUENCE_HOUR;
 if (conv_mod.contains("MOMENT_MEAL"))        must_be_literal |= C_PosologieGrammar::MOMENT_MEAL;
 if (conv_mod.contains("ALL_LITERAL"))        must_be_literal  = C_PosologieGrammar::ALL_LITERAL;
 if (conv_mod.contains("NOT_LITERAL"))        must_be_literal  = C_PosologieGrammar::UP_JUST_FRACTION;
 if (conv_mod.contains("INDICATION_LIST"))    must_be_literal |= C_PosologieGrammar::INDICATION_LIST;
 if (conv_mod.contains("INDICATION_CODE"))    must_be_literal |= C_PosologieGrammar::INDICATION_CODE;
 if (conv_mod.contains("INDICATION_TYPE"))    must_be_literal |= C_PosologieGrammar::INDICATION_TYPE;
 return must_be_literal;
}
//---------------------------- empty_skeleton_grammar [static] ------------------------------------------------
/*! \brief return a empty grammar string.  [static]
 *  \return empty grammar string.
*/
QString C_PosologieGrammar::empty_skeleton_grammar()
{return QString(
                "<gph>\n"                          // -- DEBUT du header d'une ligne prescriptive ---
                " <status></status>\n"             //        proprietes type F/traitement de fond et autres a venir
                " <smr></smr>\n"                   //        niveau du service medical rendu
                " <smr_l></smr_l>\n"               //        libelle du service medical rendu
                " <gph_html></gph_html>\n"         //        cache du contenu html d'une ligne (accelere l'affichage lors reprise d'une ordo car ne passe pas par l'interpreteur)
                " <gph_ald></gph_ald>\n"           //        prescrit en ALD "ALD"  sans ALD ""
                " <gph_id></gph_id>\n"             //        id un code d'identification unique du produit (exemple : cip du medicament )
                " <gph_it></gph_it>\n"             //        id_type "CIP"  pour les medicaments CIP compatibles controle interaction "cip" pour les autees disposant d'un cip (accessoire veto etc..)
                " <gph_dr></gph_dr>\n"             //        date et heure de la redaction de la prescription    format dd-MM-yyyy hh:mm:ss
                " <gph_dt></gph_dt>\n"             //        date et heure du debut de prise de la prescription  format dd-MM-yyyy hh:mm:ss
                " <gph_df></gph_df>\n"             //        date et heure de fin de prise de la prescription    format dd-MM-yyyy hh:mm:ss (la date de fin peut etre calculee avec <gph_cy>)
                " <gph_na></gph_na>\n"             //        nom commercial et usuel du produit
                " <gph_dcl>\n"                     //        - debut de la liste des dci composant le produit
                "  <gph_dc>\n"                     //        -- debut du premier element de la liste des dci
                "    <gph_dcn></gph_dcn>\n"        //        --- nom   du premier element de la liste des dci
                "    <gph_dcp></gph_dcp>\n"        //        --- dose  du premier element de la liste des dci
                "    <gph_dcu></gph_dcu>\n"        //        --- unite du premier element de la liste des dci
                "  </gph_dc>\n"                    //        --fin du premier element de la liste des dci
                " </gph_dcl>\n"                    //        - fin de la liste des dci composant le produit
                " <gph_cy></gph_cy>\n"             //        duree totale de toutes les sequences (J15  S10 M10   M3R2) 'J' pour jours  ou 'S' pour semaines  ou 'M' pour mois  suivi du nbr et falcutatif 'R' pour renouvelable suivi du nbr
                " <gph_sb></gph_sb>\n"             //        substituable 0 = non substituable  1 = substituable
                " <gph_dci></gph_dci>\n"           //        affichage libelle produit : 3=que dci  2=dci+commercial 1=commercial+dci 0=que commercial (par defaut si vide c'est 3)
                " <gph_uf></gph_uf>\n"             //        forme galenique de l'unite de prise
                " <gph_voie></gph_voie>\n"         //        voie d'administration
                " <gph_fmin></gph_fmin>\n"         //        frequence minimum
                " <gph_fmax></gph_fmax>\n"         //        frequence maximum
                " <gph_funit></gph_funit>\n"       //        frequence unite
                " <gph_pmin></gph_pmin>\n"         //        posologie minimum
                " <gph_pmax></gph_pmax>\n"         //        posologie maximum
                " <gph_punit></gph_punit>\n"       //        posologie unite
                " <gph_pfc></gph_pfc>\n"           //        posologie facteur corporel qu de gph_punit par facteur corporel
                " <gph_pfcunit></gph_pfcunit>\n"   //        posologie facteur corporel unite Kg cm
                " <gph_pqbyuf></gph_pqbyuf>\n"     //        quantite d'unite  posologique par unite de forme de gph_punit par gph_uf
                " <gph_dmin></gph_dmin>\n"         //        duree minimum
                " <gph_dmax></gph_dmax>\n"         //        duree maximum
                " <gph_dunit></gph_dunit>\n"       //        duree unite
                " <gph_nm></gph_nm>\n"             //        conversion mode en mode numerique UP_QUANTITE MOMENT_MEAL ALL_LITERAL (on se sert de celui-ci car plus rapide a interpreter)
                " <gph_cm></gph_cm>\n"             //        conversion mode en mode literal pour information lisible de celui du mode numerique  UP_QUANTITE MOMENT_MEAL ALL_LITERAL on a pas peur des redondances ! (vive la memoire vive et les HD)
                " <gph_in>\n"                      //        liste des indications
                "  <gph_il></gph_il>\n"            //        premier element de la liste des indications
                " </gph_in>\n"                     //        fin de la liste des indications <gph_il> </gph_il>
                " <gph_co></gph_co>\n"             //        commentaire global en fin de prescription
                "</gph>\n"                         // -- FIN du header d'une ligne prescriptive ---
                "<gps>\n"                          // -- DEBUT de la liste des sequences prescriptives
                " <gpp></gpp>\n"                   //        premiere sequence prescriptive si plusieurs elle sont seront separees par le terme 'puis, ' dans le texte resultant
                "</gps>\n"                         // -- FIN de la liste des sequences prescriptives
                "<gpi_engine></gpi_engine>\n"      //        systeme de donnees a l'origine de cette ligne prescriptive
                "<gpi_user></gpi_user>\n"          //        utilisateur a l'origine de cette ligne prescriptive
                );
    //....................... les sequences prescriptives ..............................
    //  Une sequence prescriptive est le terme situe entre la balise <gpp> et </gpp>.
    //  Elle decrit la quantite et repartition d'une prescription sur une periode de temps.
    //  Il est possible d'en placer plusieurs (elles seront separees par le terme ', puis'
    //  lors de l'affichage de l'ordonnance).
    //  Cela permet d'etablir des prescriptions du type :
    //     2 comprimes pendant deux jours, puis 1 comprime les jours suivants pendant un mois
    //
    // une sequence prescriptive comporte quatre parties :
    //
    // 1 -- La forme galenique : avant le crochet ouvrant '[' peut etre indiquee
    //                      la forme galenique du produit, si indiquee elle surcharge
    //                      celle indiquee en global.
    //
    // 2 -- La grammaire prescriptive : entre crochets la grammaire prescriptive est composee de un ou plusieurs
    //           points de prise : si plusieurs points de prise ils sont separes par le caractere '|'
    //           chaque point de prise est en deux parties separees par le caractere ';'
    //           - ce qui est avant le point virgule est la quantite de la forme galenique a prendre.
    //                Si valeurs separees par un tiret alors il est indique une fourchette de deux valeurs
    //                exemple (la forme galenique etant 'comprime') : 1 --> 1 comprime    2-4  --> 2 a 4 comprimes
    //           - ce qui est apres le point virgule est le moment de la prise : compose,
    //                d'un caractere unique : 'm' pour matin      'd' pour midi
    //                                        'a' pour apres-midi 's' pour soir
    //                                        'c' pour coucher    'n' pour nuit
    //                du caractere 'h' suivi d'un nombre precisant l'horaire de prise
    //                                 exemple : h10 --> a 10 heures h10-12 --> entre 10 et 12 heures
    //
    // 3 -- La duree de la sequence : apres le crochet fermant ']' est indiquee la duree de la sequence
    //           - le premeier caractere peut etre :
    //             U pour prise unique
    //             J pour jous suivi du nombre de jours
    //             S pour semaine suivi du nombre de semaine
    //             M pour mois suivi du nombre de mois
    //             A pour an suivie du nombre d'annees
    //             I suivi des jours de la semaine (lmMjvsd) ou doit etre pris le traitement
    //               exemple : IlmMjv  --> a prendre le lundi mardi mercredi jeudi vendredi
    //             E suivi des jours de la semaine (lmMjvsd) ou ne doit pas etre pris le traitement
    //               exemple : Esd     --> sauf samedi et dimanche
    //
    // 4 -- Le commentaire est apres le crochet fermant ']' et apres la duree de sequence, introduit
    //      par le caractere !
    //
    // EXEMPLES :
    //
    //   <gpp>comprim\303\251[1;m|2;d|4;s]J8!a suspendre si malaise</gpp>  // 1 comprime le matin 2 comprimes a midi 4comprimes le soir pendant 8 jour a suspendre si malaise
    //   <gpp>mg[100-200;]U1!a la phase initiale en bolus</gpp>     // 100 \303\240 200 mg \303\240 ne faire q'une fois \303\240 la phase initiale en bolus
    //   <gpp>comprime[1;m]Esd</gpp>                                // 1 comprime le matin sauf samedi et dimanche
    //
}
//---------------------------- setDrugRoute [static] ------------------------------------------------
/*! \brief set the voie form string in posologie grammar.  [static]
 *  \param const QString &grammar_expression :     grammar input string which must be modified
 *  \param const QString &drugRoute :     drug route to set
 *  \return modified grammar expression.
*/
QString C_PosologieGrammar::setDrugRoute(QString &grammar_expression, const QString &drugRoute)
{ CGestIni::setXmlData("gph_voie", drugRoute.toAscii(),  grammar_expression);
  return   grammar_expression;
}

//---------------------------- drugRoute [static] ------------------------------------------------
/*! \brief return drugRoute form string from posologie grammar. If not present return "" [static]
 *  \param const QString &grammar_expression :     grammar input string
 *  \return the drug route if present.
 */
QString C_PosologieGrammar::drugRoute(const QString &grammar_expression)
{return   CGestIni::getXmlData("gph_voie", grammar_expression);
}

//---------------------------- setUnitPriseForm [static] ------------------------------------------------
/*! \brief set the unit prise form string in posologie grammar.  [static]
 *  \param const QString &grammar_expression :     grammar input string which must be modified
 *  \param const QString &unitUPForm :     unit prise form to set
 *  \return modified grammar expression.
*/
QString C_PosologieGrammar::setUnitPriseForm(QString &grammar_expression, const QString &unitUPForm)
{ CGestIni::setXmlData("gph_uf", unitUPForm.toAscii(),  grammar_expression);
  return   grammar_expression;
}

//---------------------------- unitPriseForm [static] ------------------------------------------------
/*! \brief return the unit prise form string from posologie grammar. If not present return "" [static]
 *  \param const QString &grammar_expression :     grammar input string as
 *  \return the unit prise form if present.
 */
QString C_PosologieGrammar::unitPriseForm(const QString &grammar_expression)
{return   CGestIni::getXmlData("gph_uf", grammar_expression);
}
//---------------------------- setId [static] ------------------------------------------------
/*! \brief set cip code in posologie grammar.  [static]
 *  \param const QString &grammar_expression :     grammar input string which must be modified
 *  \param const QString &id :     id code to set (usualy CIP code)
 *  \return modified grammar expression.
*/
QString C_PosologieGrammar::setId(QString &grammar_expression, const QString &id)
{ CGestIni::setXmlData("gph_id", id.toAscii(),  grammar_expression);
  return   grammar_expression;
}
//---------------------------- id [static] ------------------------------------------------
/*! \brief return the id code string from posologie grammar. If not present return "" [static]
 *  \param const QString &grammar_expression :     grammar input string as
 *  \return id code if present  (usualy CIP code).
*/
QString C_PosologieGrammar::id (const QString &grammar_expression)
{return   CGestIni::getXmlData("gph_id", grammar_expression);
}
//---------------------------- setAld [static] ------------------------------------------------
/*! \brief set ALD code in posologie grammar.  [static]
 *  \param const QString &grammar_expression :     grammar input string which must be modified
 *  \param const QString &ald :    ald code if present  (empty is not ALD   "ALD" is ALD).
 *  \return modified grammar expression.
*/
QString C_PosologieGrammar::setAld(QString &grammar_expression, const QString &ald)
{ CGestIni::setXmlData("gph_ald", ald.toAscii(),  grammar_expression);
  return   grammar_expression;
}
//---------------------------- ald [static] ------------------------------------------------
/*! \brief return the idTyp code string from posologie grammar. If not present return "" [static]
 *  \param const QString &grammar_expression :     grammar input string as
 *  \return ald code if present  (empty is not ALD   "ALD" is ALD).
 */
QString C_PosologieGrammar::ald (const QString &grammar_expression)
{return   CGestIni::getXmlData("gph_ald", grammar_expression);
}

//---------------------------- pk [static] ------------------------------------------------
/*! \brief return the pk code string from posologie grammar. If not present return "" [static]
 *  \param const QString &grammar_expression :     grammar input string as
 *  \return pk code if present.
 */
QString C_PosologieGrammar::pk (const QString &grammar_expression)
{return   CGestIni::getXmlData("gph_pk", grammar_expression);
}

//---------------------------- setIdType [static] ------------------------------------------------
/*! \brief set setIdType code in posologie grammar.  [static]
 *  \param const QString &grammar_expression :     grammar input string which must be modified
 *  \param const QString &setIdType :     setIdType code to set
 *  \return modified grammar expression.
*/
QString C_PosologieGrammar::setIdType(QString &grammar_expression, const QString &id_type)
{ CGestIni::setXmlData("gph_it", id_type.toAscii(),  grammar_expression);
  return   grammar_expression;
}

//---------------------------- idType [static] ------------------------------------------------
/*! \brief return the idTyp code string from posologie grammar. If not present return "" [static]
 *  \param const QString &grammar_expression :     grammar input string as
 *  \return idTyp code if present.
 */
QString C_PosologieGrammar::idType (const QString &grammar_expression)
{return   CGestIni::getXmlData("gph_it", grammar_expression);
}

//---------------------------- get_indicationsList [static] ------------------------------------------------
/*! \brief return indication list from grammar string [static]
 *  \param const QString &grammar_expression :     grammar input string as
 *  \return list code if present.
*/
QStringList C_PosologieGrammar::get_indicationsList(const QString &grammar_expression)
{QStringList list  = CGestIni::getXmlDataList("gph_il", grammar_expression);
 return list;
}

//---------------------------- get_indication [static] ------------------------------------------------
/*! \brief return indication from posologie grammar.  [static]
 *  \param const QString &grammar_expression :     grammar input string which must be modified
 *  \param , int index :     index of indication to retrieve
 *  \return indication expression 'code'|'typCode'|'libelle'
*/
QString C_PosologieGrammar::get_indication(const QString &grammar_expression, int index, int flag /*= C_PosologieGrammar::ALL_INDIC */)
{ QStringList list  = CGestIni::getXmlDataList("gph_il", grammar_expression);
  int nb = list.count();
  if (nb==0) return "";
  QString indication = list[qMin( nb-1, index)];
  list        = indication.split('|');
  indication  = "";
  nb          = list.count();
  if ( nb>=1 && flag & C_PosologieGrammar::CODE)      indication += list[0]+"|";
  if ( nb>=2 && flag & C_PosologieGrammar::CODE_TYPE) indication += list[1]+"|";
  if ( nb>=3 && flag & C_PosologieGrammar::LIBELLE)   indication += list[2]+"|";
  if (indication.length()==0 &&  nb>=1 && flag & C_PosologieGrammar::LIBELLE) indication = indication += list[0];
  if (indication.endsWith('|')) indication = indication.left(indication.length()-1);
  return indication;
}
//---------------------------- adjustFractionalPart ------------------------------------------------
/*! \brief return adjust decimal part to near 00,25,50,75 number value
 *  \param const QString &value to adjusted string
 *  \return the adjust value.
*/
QString C_PosologieGrammar::adjustFractionalPart(const QString& value, int mode /* = C_PosologieGrammar::NO_DECIMAL */)
{
    int pos = value.indexOf(".");
    if (pos==-1) return value;

    QString decimal_part = (value+"00").mid(pos+1,2);
    QString  entire_part = value.left(pos);
    int               vd = decimal_part.toInt();
    int               vi = entire_part.toInt();

    switch(mode)
    {default :
     case  C_PosologieGrammar::NO_DECIMAL:
          { if      (vd<50)             return entire_part;
            else                        return (QString::number(vi+1));
          }
     case C_PosologieGrammar::FRACT_25:
           { if (vd<25)                 return entire_part;
             else if (vd>=25 && vd<50)  return entire_part + ".25";
             else if (vd>=50 && vd<75)  return entire_part + ".50";
             else if (vd>=75 )          return entire_part + ".75";
           }
      case C_PosologieGrammar::FRACT_50:
          { if      (vd<50)            return entire_part;
            else if (vd>=50 && vd<75)  return entire_part + ".50";
            else                       return (QString::number(vi+1));
          }
    } // end switch
}
//---------------------------- totalDurationInDaysFromGrammar ------------------------------------------------
/*! \brief compute the total duration of a prescription in days
 *  \param  const QString &grammar grammar to analyze
 *  \param  int withRepeat compute with repeat mention.
 *  \return number of days
*/
double C_PosologieGrammar::totalDurationInDaysFromGrammar( const QString &grammar , int withRepeat)
{      return totalDurationInDays(  CGestIni::getXmlData("gph_cy", grammar) , withRepeat);
}
//---------------------------- totalDurationInDays ------------------------------------------------
/*! \brief  compute the total duration of a prescription in days
 *  \param  QString duration sequence to analyze
 *  \param  int withRepeat compute with repeat mention.
 *  \return number of days
*/
double C_PosologieGrammar::totalDurationInDays(  QString duration , int withRepeat)
{      if (duration.length()==0) return 0;
       double nb_j      = 0;
       int    cycle     = 0;
       int    pos       = duration.indexOf('R');
       if ( pos != -1 )
          { cycle       = duration.mid(  pos + 1 ).toInt();
            duration    = duration.left( pos );
          }
       if ( duration.length() )
          { switch (duration.toAscii()[0]|32)
                  {case 'j': nb_j  =    duration.mid(1).toDouble() * 1;      break;
                   case 's': nb_j  =    duration.mid(1).toDouble() * 7;      break;
                   case 'm': nb_j  =    duration.mid(1).toDouble() * 30.5;   break;
                   case 'a': nb_j  =    duration.mid(1).toDouble() * 365.25; break;
                  }
         }
       if (withRepeat && cycle) return nb_j * cycle;
       else                     return nb_j;
}

//---------------------------- adjustGrammarSequencesToCorporalFactor ------------------------------------------------
/*! \brief  adjust number of UP (dosage-unit in french Prise Unit) in sequences, from corporal factor (Kg M2)
 *  \param  const QString &grammar grammar to analyze
 *  \param  double poids   Corporal Factor weight
 *  \param  double surface Corporal Factor surface
 *  \param  QString &sequencesXml XML description of sequences list
 *  \param  int doNotAdjustXMLSequences if 1/return only the minimum and maximum total amount dosage-uni otherwise sequencesXml is adjusted
 *  \return QString the minimum and maximum total amount dosage-unit (in french Unit Prise UP) minimum-maximum as 2-6
*/
QString C_PosologieGrammar::adjustGrammarSequencesToCorporalFactor( const QString &grammar, double poids, double surface,  QString &sequencesXml , int doNotAdjustXMLSequences )
{   //............ ajuste les nombre d'unite de prise dans les sequences selon le poids ou surface .................................
    int           nextPos             = 0;
    QString qPA_min_By_FactCorp       = CGestIni::getXmlData("gph_pmin",    grammar, &nextPos);     // n       QPA_min  Quantite de Principe Actif minimum
    QString qPA_max_By_FactCorp       = CGestIni::getXmlData("gph_pmax",    grammar, &nextPos);     // N       QPA_max  Quantite de Principe Actif maximum
    // QString unitePoso                 = CGestIni::getXmlData("gph_punit",   grammar, &nextPos);  // mg      UPA      unite du principe actif
    QString facteurCorpo              = CGestIni::getXmlData("gph_pfc",     grammar, &nextPos);     // 10      QFC      quantite de facteur corporel
    //..................... si facteur corporel :ajuster la poso totale (en nombre UP)  selon le poids ou surface..........................
    //                      pour cela : on prend le poids ou surface X par la Qu par facteur corporel
    //                      divise par la QPA_by_UP (Quantite de Principe Actif) par UP (Unite de Prise)  pour obtenir la dose totale d'UP
    if (facteurCorpo.length()==0 || (qPA_min_By_FactCorp.length()==0 && qPA_max_By_FactCorp.length()==0 )) return "";     // >>>>  ON SE CASSE CAR NON EXPRIME EN FACTEUR CORPOREL
    QString unite_facteurCorpo        = CGestIni::getXmlData("gph_pfcunit", grammar, &nextPos);     // kg m2   UFC      unite du facteur corporel (kg, m2)  --> dose totale =  n a N mg par 10 kg ou M2
    QString qPA_ByUnitPrise           = CGestIni::getXmlData("gph_pqbyuf",  grammar, &nextPos);     // 500 mg  QPA_by_UP 500 mg par (par comprime)  (Quantite de Principe Actif) par UP (Unite de Prise)

    QString posoTotale                = "";
    double quFactCorp                 = 0;
    QStringList seqList               = CGestIni::getXmlDataList( "gpp",    sequencesXml);

    if ( unite_facteurCorpo.length() )
       { if ( unite_facteurCorpo.at(0).toUpper()=='K') quFactCorp = poids;
         else                                          quFactCorp = surface;
       }

    double nb_total_max = ( facteurCorpo.toDouble() * qPA_max_By_FactCorp.toDouble() * quFactCorp )/ qPA_ByUnitPrise.toDouble();
    double nb_total_min = ( facteurCorpo.toDouble() * qPA_min_By_FactCorp.toDouble() * quFactCorp )/ qPA_ByUnitPrise.toDouble();

    QString nbMax = QString::number(nb_total_max,'f',2); nbMax = C_PosologieGrammar::adjustFractionalPart(nbMax);
    QString nbMin = QString::number(nb_total_min,'f',2); nbMin = C_PosologieGrammar::adjustFractionalPart(nbMin);
    //............. ajuster la chaine de la dose totale a placer dans le widget .......................
    if      (qPA_min_By_FactCorp==qPA_max_By_FactCorp)                         posoTotale = nbMax;
    else if (qPA_min_By_FactCorp.length()==0 && qPA_max_By_FactCorp.length())  posoTotale = nbMax;
    else if (qPA_max_By_FactCorp.length()==0 && qPA_min_By_FactCorp.length())  posoTotale = nbMin;
    else                                                                       posoTotale = nbMin + "-" + nbMax;
    if (doNotAdjustXMLSequences == C_PosologieGrammar::JUST_ADJUST_TOTAL_AMOUNT)   return posoTotale;
    //................. on a le total Maximum et Minimum possible du nombre d'UP selon le poids ou surface....................................
    //                  il faut maintenant exploser les sequences, pour le repartir dans chacune des sequences
    //                  ne mollissons pas,  moi a pas peur et tout le fourbi, on va y arriver
    // <gpp>[1;m|2;d|4;s]J8!\303\240 la phase initiale en bolus</gpp>
    // <gpp>[100-200;]U1!\303\240 la phase initiale en bolus</gpp>   // 100 \303\240 200 mg \303\240 ne faire q'une fois \303\240 la phase initiale en bolus

    QString           sequence    = "";
    QString str_before_bracket    = "";
    QString str_after_bracket     = "";
    double  nb_prise_point        = 0;
    double  qu_by_point_min       = 0;
    double  qu_by_point_max       = 0;
    QString s_qu_by_point_min     = "";
    QString s_qu_by_point_max     = "";
    QString poso                  = "";
    QString  s_when               = "";
    QString  s_point              = "";
    double   mult_by              = 0;
    QString tmp_str               = "";
    int     s                     = 0;
    QStringList point_list;
    for ( s=0; s < seqList.size();  ++s)
        { s_point                     = "";
          mult_by                     = 0;
          sequence                    = seqList[s];
          int     pos_deb             = sequence.indexOf('[');
          if (pos_deb == -1 )        continue;
          str_before_bracket          = sequence.left(pos_deb);
          ++ pos_deb;
          sequence                    = sequence.mid ( pos_deb );
          int     pos_end             = sequence.indexOf(']');
          if (pos_end == -1 )        continue;
          str_after_bracket           = sequence.mid ( pos_end+1 );
          sequence                    = sequence.left( pos_end );
          //.......... la on a isole : 1;m|2;d|4;s .......................................
          //           on pinaille pas et soit on repartit egalement entre chaque point de prise deja presents.
          //           soit on utilise une methode de calcul indiquee sur chaque point de prise (pour l'instant un facteur multiplicatif)
          point_list                  = sequence.split("|", QString::SkipEmptyParts);
          nb_prise_point              = point_list.size();
          if ( point_list.at(0).length() )
             { //............. methode proportionnelle (un facteur multiplicatif de la QU totale est place sur chaque point de prise) ...................
               //              x0.5;m|x0.25;d|x0.25;s
               if (sequence.at(0).toLower()=='x')
                  { sequence    = "";
                    for ( int i = 0; i < point_list.size();  ++i)
                        { s_when   = "";
                          mult_by  = 1 ;
                          s_point  = point_list.at(0).mid(1);  // .mid(1) pour sauter le X
                          int   p  = s_point.indexOf(';');
                          if  ( p != -1)
                              { s_when  = s_point.mid  (p);
                                mult_by = s_point.left (p).toDouble();
                              }
                          qu_by_point_min    = nb_total_min * mult_by;
                          qu_by_point_max    = nb_total_max * mult_by;
                          s_qu_by_point_min  = C_PosologieGrammar::adjustFractionalPart(QString::number(qu_by_point_min, 'f', 2)) ;
                          s_qu_by_point_max  = C_PosologieGrammar::adjustFractionalPart(QString::number(qu_by_point_max, 'f', 2)) ;
                          //............. ajuster la chaine a placer comme quantite ...............................
                          //              soit valeur unique soit fourchette de valeurs
                          if      (qu_by_point_min    == qu_by_point_max)       poso = s_qu_by_point_max;
                          else if (qu_by_point_min==0 && qu_by_point_max)       poso = s_qu_by_point_max;
                          else if (qu_by_point_min    && qu_by_point_max==0)    poso = s_qu_by_point_min;
                          else                                                  poso = s_qu_by_point_min + "-" + s_qu_by_point_max;
                          sequence += poso + s_when +"|";
                        } // end for ( int i=0; i < point_list.size();  ++i)
                    if (sequence.endsWith('|')) sequence.chop(1);     // virer le dernier |
                  }  // end if (point_list.at(0).toLower()=='x')
               //............. methode equi valeur  (la QU totale est repartie uniformement entre chaque point de prise) ................................
               // 1;m|1;d|1;s    // quelque soit la valeur avant le ; elle sera remplacee par la QU totale / nb de prises
               else
                  { sequence           = "";
                    qu_by_point_min    = nb_total_min / nb_prise_point;
                    qu_by_point_max    = nb_total_max / nb_prise_point;
                    s_qu_by_point_min  = C_PosologieGrammar::adjustFractionalPart(QString::number(qu_by_point_min, 'f', 2)) ;
                    s_qu_by_point_max  = C_PosologieGrammar::adjustFractionalPart(QString::number(qu_by_point_max, 'f', 2)) ;
                    //............. ajuster la chaine a placer comme quantite ...............................
                    //              soit valeur unique soit fourchette de valeurs
                    if      (qu_by_point_min    == qu_by_point_max)             poso = s_qu_by_point_max;
                    else if (qu_by_point_min==0 && qu_by_point_max)             poso = s_qu_by_point_max;
                    else if (qu_by_point_min    && qu_by_point_max==0)          poso = s_qu_by_point_min;
                    else                                                        poso = s_qu_by_point_min + "-" + s_qu_by_point_max;
                    //.......... recontruire la sequence ...................................
                    for ( int i=0; i < point_list.size();  ++i)
                        { tmp_str  = point_list.at(i);
                          int   p  = tmp_str.indexOf(';');
                          if  ( p != -1)
                              { sequence += poso +tmp_str.mid(p)+"|"; // on garde l'ancienne specification du moment de prise  m/le matin d/a midi a/l'aprs midi s/le soir c/coucher n/nuit n/horaire
                              }
                        }  //end for ( int i=0; i < point_list.size();  ++i)
                  } //end else if (point_list.at(0).toLower()=='x')
               if (sequence.endsWith('|')) sequence.chop(1);     // virer le dernier |
             }
          seqList[s] = str_before_bracket + "[" + sequence + "]" + str_after_bracket;
        } // end for ( s=0; s < seqList.size();  ++s)
    //............. refaire le XML des sequences ......................................................
    //  "<gps>\n"                          // -- DEBUT de la liste des sequences pescriptives
    //  " <gpp></gpp>\n"                   //        premiere sequence prescriptive
    //  "</gps>\n"                         // -- FIN de la liste des sequences pescriptives
    sequencesXml = "\n";
    for ( s=0; s < seqList.size();  ++s)
        {sequencesXml += " <gpp>" + seqList.at(s) + "</gpp>\n";
        }
    return posoTotale;
}

//---------------------------- toMinMax_UP ------------------------------------------------
/*! \brief  retrieve frequence of UP, minimum and maximum amount of UP  by grammar
 *  \param  const QStringList &seqList list of sequences to analyze
 *  \param  QString &q_min minimum amount of UP from this sequence
 *  \param  QString &q_max maximum amount of UP from this sequence
 *  \param  QString &q_max maximum amount of UP from this sequence
 *  \param  QString &up_formes_min_max_period return result as comprime|2|4|1440\ncomprime|1|2|1440
 *  \return QString the maximum frequence of UP by grammar
*/
int C_PosologieGrammar::toMinMax_UP(const QStringList &seqList, double &q_min,  double &q_max, QString &up_formes_min_max_period)
{
    // <gpp>[1;m|2;d|4;s]J8!\303\240 la phase initiale en bolus</gpp>
    // <gpp>[100-200;]U1!\303\240 la phase initiale en bolus</gpp>   // 100 \303\240 200 mg \303\240 ne faire q'une fois \303\240 la phase initiale en bolus
    int up_frequency          = -1;
    double              d_min = 0;
    double              d_max = 0;
    int    d_by_UT_inMinutes  = -1;
    QString         sequence  = "";
    QString seq_days          = "";
    up_formes_min_max_period  = "";
    for ( int s=0; s < seqList.count();  ++s)       // < 1  car l'ancien systeme ne connait pas la crise des sequences multiples
        { //....... reperer si la sequence comporte une forme locale ..............
          //        et auquel cas l'utiliser
          sequence                    = seqList[s];
          int     pos_deb             = sequence.indexOf('[');
          if (pos_deb == -1 )         return -1;
          up_formes_min_max_period   += sequence.left( pos_deb ) + "|";
          sequence                    = sequence.mid ( pos_deb+1 );
          int     pos_end             = sequence.indexOf(']');
          if (pos_end == -1 )         return -1;
          seq_days                    = sequence.mid ( pos_end+1 );
          sequence                    = sequence.left( pos_end );
                  pos_end             = seq_days.indexOf('!');
          if (pos_end != -1 )seq_days = seq_days.left( pos_end );
          d_by_UT_inMinutes           = sequence_daysToUnitPeriodInMinutes( seq_days );
          up_frequency                = qMax( up_frequency , sequence_timeToMinMax_UP( sequence, d_min,  d_max ) );
          up_formes_min_max_period   += QString::number(d_min,'f',2) + "|" + QString::number(d_max,'f',2) + "|" + QString::number(d_by_UT_inMinutes) + "\n";
          q_min                       = qMin( qMin(d_min, d_max) , q_min);
          q_max                       = qMax( qMax(d_min, d_max) , q_max);
        }
    if (up_formes_min_max_period.endsWith("\n")) up_formes_min_max_period.chop(1);
    return up_frequency;
}
//---------------------------- sequence_daysToUnitPeriodInMinutes ------------------------------------------------
/*! \brief  compute a rough unit period of this prescription sequence (if one day by week --> 1440 (day) is returned)
 *  \param  const QString &seq_days to analyze as   J8 or M12
 *  \return int the period of this  UP's sequence in minute
*/
int C_PosologieGrammar::sequence_daysToUnitPeriodInMinutes(const QString &seq_days)
{if (seq_days.length()==0) return -1;
 char              t = seq_days.toAscii()[0]|32;
 switch(t)
 { case 'i':  return  1440;    // IlmMjvsd I comme Include
   case 'e':  return  1440;    // ElmMjvsd E comme Exclude
   case 'u':  return -1440;;   // one shoot
   case 'j':  return  1440;
   case 's':  return  1440 * 7;
   case 'm':  return  1440 * 30;
   case 'a':  return  1440 * 365;
   default :  return  -1;
 }
}

//---------------------------- sequence_timeToMinMax_UP ------------------------------------------------
/*! \brief  retrieve frequence of UP, minimum and maximum amount of UP  by sequence
 *  \param  const QString &seq_time to analyze as  <b>0.5;m|1;d15r|2;sr30|3;h10-13</b>
 *  \param  QString &q_min minimum amount of UP from this sequence
 *  \param  QString &q_max maximum amount of UP from this sequence
 *  \return QString the frequence of UP by sequence
*/
QString C_PosologieGrammar::sequence_timeToMinMax_UP(const QString &seq_time,  QString &q_min,  QString &q_max )
{double d_min;
 double d_max;
 double up_frequency = sequence_timeToMinMax_UP(seq_time,  d_min,  d_max);
 //......... preparer les sorties ...............
 if (d_min>0)          q_min  = QString::number(d_min,'f',2);
 else                  q_min  = "";
 if (d_max>0)          q_max  = QString::number(d_max,'f',2);
 else                  q_max  = "";
 return QString::number(up_frequency);
}

//---------------------------- sequence_timeToMinMax_UP [static]------------------------------------------------
/*! \brief  retrieve frequence of UP, minimum and maximum amount of UP  by sequence
 *  \param  const QString &seq_time to analyze as  <b>0.5;m|1;d15r|2;sr30|3;h10-13</b>
 *  \param  double &q_min minimum amount of UP from this sequence
 *  \param  double &q_max maximum amount of UP from this sequence
 *  \return double the frequence of UP by sequence
*/
int C_PosologieGrammar::sequence_timeToMinMax_UP(const QString &seq_time,  double &q_min,  double &q_max )
{QStringList seqTList = seq_time.split("|");    //  bool allowEmptyEntries
 QString          str = "";
 double         t_min = 0;
 double         t_max = 0;
 double         d_min = 0;
 double         d_max = 0;
 double         d_tmp = 0;
 int              pos = 0;
 bool    isFirstTime  = true;
 for (int i=0; i< (int)seqTList.count(); ++i)
    {str        = seqTList[i];
     pos        = str.indexOf(';');
     if (pos   != -1) str = str.left(pos);
     if (str.length()==0) continue;
     //.......... CMedicaBase::UP_QUANTITE la quantite d'unite de prise .....................
     pos       = str.indexOf ('-');
     if (pos != -1)                // cas ou 1-2   (un \303\240 deux)
        { t_min  = str.left ( pos ).toDouble();
          t_max  = str.mid  ( pos + 1).toDouble();
          if (t_min>t_max) {d_tmp = t_max; t_max = t_min; t_min = d_tmp;}
        }
     else
        { t_max  = str.toDouble();
        }
     if (isFirstTime)     // au premier passage on prend les valeurs
        { d_min = t_min;
          d_max = t_max;
        }
     else                    // aux passages suivant on additione les valeurs
        { d_min =  t_min + d_min ;
          d_max =  t_max + d_max ;
        }
     isFirstTime = false;
     //.......... on releve le max et min trouve ..........................
    }  // end for (int i=0; i<seqTList.count(); ++i)
 //......... preparer les sorties ...............
 q_min  = d_min;
 q_max  = d_max;
 return seqTList.size();
}

//---------------------------- fuse ------------------------------------------------
QString C_PosologieGrammar::fuse  (const QString &grammar_expression               ,
                                   QString mask                                   ,
                                   const QString &substituableImgPath    /* = "" */,
                                   const QString num_Ordre               /* = "" */
                                  )
{
        int nextPos              = 0;
        QString    s_dateRed     = CGestIni::getXmlData(     "gph_dr",    grammar_expression, &nextPos).left(10);
        QString    s_dateDeb     = CGestIni::getXmlData(     "gph_dt",    grammar_expression, &nextPos).left(10);
        QString commerialName    = CGestIni::getXmlData(     "gph_na",    grammar_expression, &nextPos);
        QString compoXmlParts    = CGestIni::getXmlData(     "gph_dcl",   grammar_expression, &nextPos);
        QString cycle            = CGestIni::getXmlData(     "gph_cy",    grammar_expression, &nextPos);
        QString substituable     = CGestIni::getXmlData(     "gph_sb",    grammar_expression, &nextPos);
        int     dciMode          = CGestIni::getXmlData(     "gph_dci",   grammar_expression, &nextPos).toInt();
        QString up_forme         = CGestIni::getXmlData(     "gph_uf",    grammar_expression, &nextPos);
        QString voie             = CGestIni::getXmlData(     "gph_voie",  grammar_expression, &nextPos);
        QString conv_mod_T       = CGestIni::getXmlData(     "gph_cm",    grammar_expression, &nextPos);
        QString conv_mod_N       = CGestIni::getXmlData(     "gph_nm",    grammar_expression, &nextPos);
        QString comment          = CGestIni::getXmlData(     "gph_co",    grammar_expression, &nextPos);
        QStringList seqList      = CGestIni::getXmlDataList( "gpp",       grammar_expression, &nextPos);
        int must_be_literal      = -1;
     //........ traiter le cas ou la definition de literalite est donnee dans la grammaire avant le signe = .........
     if (conv_mod_T.length())          // .......... si literalite definie dans grammaire l'utiliser que si parametre d'entree non defini ..............
        { if (conv_mod_N.length()) must_be_literal = conv_mod_N.toInt();                                    // court
          else                     must_be_literal = C_PosologieGrammar::literalStringToFlag(conv_mod_T);   // long
        }
     if (must_be_literal==-1)
        {  must_be_literal = C_PosologieGrammar::NOT_LITERAL;
        }
     //............. si forme definie en entree on l'utilise et elle surcharge celle de la grammaire .....................................
     //              sinon on tente d'utiliser celle d\303\251finie dans la grammaire
     nextPos              = 0;
     QString joinStr      = QObject::tr(", \npuis ");
     QString text         = "";
     for (int i=0; i<seqList.count(); ++i)
         { //....... reperer si la sequence comporte une forme locale ..............
           //        et auquel cas l'utiliser
           QString sequence        = seqList[i];
           int     pos_deb         = sequence.indexOf('[');
           if (pos_deb != -1 )
              { up_forme           = sequence.left(pos_deb);
                sequence           = sequence.mid(pos_deb+1);
              }
           text  += sequenceToString(i, sequence, must_be_literal, up_forme); text += joinStr;
         }
     text.chop(joinStr.length());    // on enleve le dernier "\npuis "
     mask.replace("{{posologie}}",     text);
     //...........  commencer le ..................................
     text           = "";
     if (s_dateRed != s_dateDeb)       text += QObject::tr(", \303\240 commencer le : ") + s_dateDeb.left(10);
     mask.replace("{{commencer_le}}",  text);
     //...........  duree totale ..................................
     text           = "";
     if (cycle.length())               text += dureeTotaleRenouvToString(cycle, must_be_literal );
     mask.replace("{{duree_totale}}",         text);
     //...........  commentaire ..................................
     mask.replace("{{commentaire}}",  comment);
     if (substituableImgPath.length()==0)     return mask;

     //................................... PARTIE AVEC HTML COMPLET ..................................................
    //.................. nom et composition DCI .....................................................................
    QString compositionDCI   = "";
    QStringList compoXmlList = CGestIni::getXmlDataList( "gph_dc",     compoXmlParts);
    char sexe;
    for (int i=0; i<compoXmlList.size();++i)
        {nextPos             = 0;
         QString compoXML    = compoXmlList.at(i);
         QString name        = CGestIni::getXmlData(     "gph_dcn", compoXML, &nextPos).trimmed();
         QString dose        = CGestIni::getXmlData(     "gph_dcp", compoXML, &nextPos);
         QString unit        = CGestIni::getXmlData(     "gph_dcu", compoXML, &nextPos);
         if (name.length()) compositionDCI     +=  name + "  "+ dose +" " +  C_PosologieGrammar::get_AccordedWord( dose.toInt(), unit, sexe) + " + ";
        }

    //................. gerer l'affichage nom / DCI ................................................................
    QString mainName       = "";
    QString optionnalName  = "";
    if (compositionDCI.length()==0)  dciMode = 0;              // si pas de compostion DCI on force le mode commecial
    else                             compositionDCI.chop(3);   // enlever le "+" de fin.
    switch (dciMode)
    {case 0: mainName     += commerialName; break;
     case 1: mainName     += commerialName;
             optionnalName = compositionDCI;
             break;
     case 2: mainName     += compositionDCI;
             optionnalName = commerialName;
             break;
     case 3: mainName     += compositionDCI;
             break;
    }
    mask.replace("{{main_name}}",   mainName);
    mask.replace("{{second_name}}", optionnalName);
    if (optionnalName.length()==0)  mask.remove("()");
    //................ substituable ................................................................................
    if (substituable=="0") substituable = QString("<img src=\"%1\" alt=\"jours\" height=\"16\" width=\"130\">").arg(substituableImgPath);
    else                   substituable = "";
    mask.replace("{{substituable}}", substituable);
    //................ forme voie ..................................................................................
    mask.replace("{{forme}}", up_forme);
    mask.replace("{{voie}}",  (voie.length() ? QObject::tr("par voie ") + voie : ""));
    //................ numero d'ordre ..................................................................................
    mask.replace("{{num_order}}", num_Ordre);
    return mask;
}

/*! \brief return human readable string from posologie grammar.
 *  \param const QString &grammar_expression     xml grammar input string as
 *      <gph>
 *         <gph_id>301546</gph_id>
 *         <gph_it>CIP</gph_it>
 *         <gph_pk>123</gph_pk>
 *         <gph_uf>comprim\303\251</gph_uf>
 *         <gph_nm>5</gph_nm>                        // conversion mode en mode numerique UP_QUANTITE MOMENT_MEAL ALL_LITERAL (on se sert de celui-ci car plus rapide a interpreter)
 *         <gph_cm>UP_QUANTITE DURATION</gph_cm>     // traduction textuelle de <gph_nm>5</gph_nm> information lisible de celle numerique  UP_QUANTITE DURATION on a pas peur des redondances ! (vive la memoire vive et les HD)
 *         <gph_in>
 *             <gph_il>I13.1|CIM|insuffisance r\303\251nale et cardiopathie hypertensive</gph_il>
 *             <gph_il>P96.0|CIM|insuffisance r\303\251nale cong\303\251nitale</gph_il>
 *         </gph_in>
 *         <gph_co>\303\240 prendre avec un grand verre d'eau sans respirer pendant 30 minutes</gph_co>
 *      </gph>
 *      <gps>
 *         <gpp>[1;m|2;d|4;s]J8</gpp>
 *         <gpp>[0.5;m|1;d15r|2;sr30|3;h10-13]J4\</gpp>
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

//---------------------------- toHtml ------------------------------------------------
QString C_PosologieGrammar::toHtml(const QString &grammar_expression,
                                   const QString &substituableImgPath   /* = "" */,
                                   const QString &css                   /* = "" */,
                                   const QColor &background             /* = QColor(Qt::black) */,
                                   const QString num_Ordre              /* = "" */
                                   )
{
        int nextPos              = 0;
        QString id               = CGestIni::getXmlData(     "gph_id",    grammar_expression, &nextPos);
        //QString id_type          = CGestIni::getXmlData(     "gph_it",  grammar_expression, &nextPos);
        //QString pk               = CGestIni::getXmlData(     "gph_pk",  grammar_expression, &nextPos);
        QString    s_dateRed     = CGestIni::getXmlData(     "gph_dr",    grammar_expression, &nextPos).left(10);
        QString    s_dateDeb     = CGestIni::getXmlData(     "gph_dt",    grammar_expression, &nextPos).left(10);
        QString commercialName   = CGestIni::getXmlData(     "gph_na",    grammar_expression, &nextPos);
        QString compoXmlParts    = CGestIni::getXmlData(     "gph_dcl",   grammar_expression, &nextPos);

        QString cycle            = CGestIni::getXmlData(     "gph_cy",    grammar_expression, &nextPos);
        QString substituable     = CGestIni::getXmlData(     "gph_sb",    grammar_expression, &nextPos);
        int     dciMode          = CGestIni::getXmlData(     "gph_dci",   grammar_expression, &nextPos).toInt();
        QString up_forme         = CGestIni::getXmlData(     "gph_uf",    grammar_expression, &nextPos);
        QString voie             = CGestIni::getXmlData(     "gph_voie",  grammar_expression, &nextPos);
        QString conv_mod_T       = CGestIni::getXmlData(     "gph_cm",    grammar_expression, &nextPos);
        QString conv_mod_N       = CGestIni::getXmlData(     "gph_nm",    grammar_expression, &nextPos);
        //QString indicStr         = CGestIni::getXmlData(     "gph_in",  grammar_expression, &nextPos);
        QString comment          = CGestIni::getXmlData(     "gph_co",    grammar_expression, &nextPos);
        QStringList seqList      = CGestIni::getXmlDataList( "gpp",       grammar_expression, &nextPos);
        int must_be_literal      = -1;
     //........ traiter le cas ou la definition de literalite est donnee dans la grammaire avant le signe = .........
     if (conv_mod_T.length())          // .......... si literalite definie dans grammaire l'utiliser que si parametre d'entree non defini ..............
        { if (conv_mod_N.length()) must_be_literal = conv_mod_N.toInt();                                    // court
          else                     must_be_literal = C_PosologieGrammar::literalStringToFlag(conv_mod_T);   // long
        }
     if (must_be_literal==-1)
        {  must_be_literal = C_PosologieGrammar::NOT_LITERAL;
        }
     //............. si forme definie en entree on l'utilise et elle surcharge celle de la grammaire .....................................
     //              sinon on tente d'utiliser celle d\303\251finie dans la grammaire
     nextPos              = 0;
     QString joinStr      = QObject::tr(", \npuis ");
     QString body         = "";

     for (int i=0; i<seqList.count(); ++i)
         { //....... reperer si la sequence comporte une forme locale ..............
           //        et auquel cas l'utiliser
           QString sequence        = seqList[i];
           int     pos_deb         = sequence.indexOf('[');
           if (pos_deb != -1 )
              { up_forme           = sequence.left (pos_deb);
                sequence           = sequence.mid  (pos_deb+1);
              }
           body  += sequenceToString(i, sequence, must_be_literal, up_forme); body += joinStr;
         }
     body.chop(joinStr.length());    // on enleve le dernier "\npuis "
     if (comment.length())                 body += " " + comment;
     if (s_dateRed != s_dateDeb)
        {                                  body += QObject::tr(", \303\240 commencer le : ") + s_dateDeb.left(10);
        }
     if (cycle.length())                   body += dureeTotaleRenouvToString(cycle, must_be_literal );
     if (substituableImgPath.length()==0)     return body;

    //................................... PARTIE AVEC HTML COMPLET ..................................................
    //.................................. le modele css par defaut .....................................................
    QString span    =
                     "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">"
                     "<html>"
                     "<head>"
                     "    <meta name=\"qrichtext\" content=\"1\" />"
                     "    <style type=\"text/css\">"
                     "        span.mainName {"
                     "         color:%1;"                                    // 1 color dci
                     "         font-family: arial, verdana, sans-serif;"
                     "         text-decoration: underline;"
                     "         font-size: 10px;"
                     "         font-weight: bold;"
                     "        }"
                     "        span.optionalName {"
                     "          color:%2;"                                   // 2 color commercial name
                     "          font-family: arial, verdana, sans-serif;"
                     "          font-style: italic;"
                     "          font-size: 10px;"
                     "        }"
                     "        span.texteNormal {"
                     "          color:%3;"                                   // 3 color text normal
                     "          font-family: arial, verdana, sans-serif;"
                     "          font-size: 10px;"
                     "        }"
                     "        span.numOrdre {"
                     "          color:%4;"                                   // 4 color num Ordre
                     "          font-family: arial, verdana, sans-serif;"
                     "          font-size: 10px;"
                     "          font-weight: bold;"
                     "        }"
                     "        span.drugForme {"
                     "          color:%5;"                                   // 5 color forme
                     "          font-family: arial, verdana, sans-serif;"
                     "          font-size: 10px;"
                     "          font-weight: bold;"
                     "        }"
                     "    </style>"
                     "</head>";
    QString text =
                     "<body>"
                     "<span class=\"numOrdre\">%1</span> "
                     "%6"                                   // mention substituable
                     "<span class=\"mainName\">%2</span> "
                     "<span class=\"optionalName\">%3</span> "
                     "<span class=\"drugForme\">%4</span> "
                     "<span class=\"texteNormal\">%5</span>"
                     "<br />"
                     "</body>"
                     "</html>";
    //.................. composition DCI .....................................................................
    QString compositionDCI   = "";
    QStringList compoXmlList = CGestIni::getXmlDataList( "gph_dc",     compoXmlParts);
    char sexe;
    for (int i=0; i<compoXmlList.size();++i)
        {nextPos             = 0;
         QString compoXML    = compoXmlList.at(i);
         QString name        = CGestIni::getXmlData(     "gph_dcn", compoXML, &nextPos).trimmed();
         QString dose        = CGestIni::getXmlData(     "gph_dcp", compoXML, &nextPos);
         QString unit        = CGestIni::getXmlData(     "gph_dcu", compoXML, &nextPos);
         if (name.length()) compositionDCI     +=  name + "  "+ dose +" " +  C_PosologieGrammar::get_AccordedWord( dose.toInt(), unit, sexe) + " + ";
        }

    //................. gerer l'affichage DCI ................................................................
    if (compositionDCI.length()==0) dciMode = 0;              // pas de DCI alors on force a rester en commercial
    else                            compositionDCI.chop(3);   // enlever le "+" de fin.
    QString mainName       = "";
    QString optionnalName  = "";
    switch (dciMode)
    {case 0: mainName     += commercialName; break;
     case 1: mainName     += commercialName;
             optionnalName = "("+ compositionDCI + ")";
             break;
     case 2: mainName     += compositionDCI;
             optionnalName = "("+ commercialName + ")";
             break;
     case 3: mainName     += compositionDCI;
             break;
    }

    //................ substituable ................................................................................
    if (substituable=="0") substituable = QString("<img src=\"%1\" alt=\"jours\" height=\"16\" width=\"130\">").arg(substituableImgPath);
    else                   substituable = "";
    //................ forme voie ..................................................................................
    QString forme =  up_forme + (voie.length() ? QObject::tr(" par voie ") + voie : "");
    //................ le reste ..................................................................................
    QString html  = "";
    if (css.length())
       {    html += css;               // on prend le css donne en entree
       }
    else                               // on prend le css par defaut
       {    html += span.arg ( background.darker(200).name(),                                               // 1 color dci
                               background.darker(120).name(),                                               // 2 color commercial name
                               background.darker(200).name(),                                               // 3 color text normal
                               "#FF0000",                                                                   // 4 color num Ordre  background.darker(200).name()
                               background.darker(200).name()                                                // 5 color drug forme
                             );
       }
    html += text.arg (  num_Ordre + ")" ,                                                                   // 1 numero d'ordre
                        mainName,                                                                           // 2 nom principal
                        optionnalName,                                                                      // 3 nom secondaire
                        forme+"<br />",                                                                     // 4 forme
                        body,                                                                               // 5 posologie
                        substituable                                                                        // 6 mention substituable
                     );
    return html;
}

//---------------------------- dureeTotaleRenouvToString ------------------------------------------------
// <gph_cy>S3R6</gph_cy>     // JSMA     exples J6 --> pour 6 jours S7 --> pour 7 semaines M3R6  pour 3 mois renouvelable 6 fois
QString C_PosologieGrammar::dureeTotaleRenouvToString(QString cycle, int must_be_literal /* = C_PosologieGrammar::NOT_LITERAL */)
{   if (cycle.length()==0) return "";
    QString duree        = "";
    QString        ret   = "";
    int            pos   = cycle.indexOf('R');
    if (pos != -1)
       { duree  = cycle.left(pos);
         cycle  = cycle.mid(pos+1);
       }
    else
      { duree = cycle;
        cycle = "";
      }
    if (duree.length() && duree.mid(1).toInt())   // si duree nulle ne pas mettre la mention
      { ret  = " " + dureeTotaleToString(duree, must_be_literal );
      }
    if (pos != -1)
       { int n = cycle.toInt();
         if (n) ret  += QObject::tr(" (renouvelable %1 fois)").arg(numberToLiteral(n,'f'));
       }
    if (ret.length()) ret = ", " + ret;
    return ret;
}
//---------------------------- dureeTotaleToString ------------------------------------------------
//  J2
QString C_PosologieGrammar::dureeTotaleToString(const QString &seq_days, int must_be_literal /* = C_PosologieGrammar::NOT_LITERAL */)
{if (seq_days.length()==0) return "";
 QString    introStr = QObject::tr("traitement \303\240 poursuivre pendant ");   //QObject::tr(". La dur\303\251e totale de cette prescription est de ")
 char              t = seq_days.toAscii()[0]|32;
 QString         ret = seq_days;
 QString str_nb      = ret.mid(1);
 int         nb      = str_nb.toInt();

 switch(t)
 {case 'j': return    introStr + ( (must_be_literal&C_PosologieGrammar::DURATION)?numberToLiteral(nb)     : str_nb) + QObject::tr(" jour")    + ((nb>1)?"s":"");
  case 's': return    introStr + ( (must_be_literal&C_PosologieGrammar::DURATION)?numberToLiteral(nb,'f') : str_nb) + QObject::tr(" semaine") + ((nb>1)?"s":"");
  case 'm': return    introStr + ( (must_be_literal&C_PosologieGrammar::DURATION)?numberToLiteral(nb)     : str_nb) + QObject::tr(" mois");
 }
 return ret;
}
//---------------------------- sequenceToString ------------------------------------------------
// <gpp>[1;m|2;d|4;s]J8!\303\240 la phase initiale en bolus</gpp>
// <gpp>[100-200;]U1!\303\240 la phase initiale en bolus</gpp>   // 100 \303\240 200 mg \303\240 ne faire q'une fois \303\240 la phase initiale en bolus
QString C_PosologieGrammar::sequenceToString(int numSeq, const QString &sequence, int must_be_literal /* = C_PosologieGrammar::NOT_LITERAL */, const QString &up_forme)
{
 int pos             = sequence.indexOf(']');
 if (pos==-1) return QString("");
 int pcom            = sequence.indexOf('!');
 int len             = -1;    // si pas de commentaire le mid prend tout
 QString commentaire = "";
 if (pcom != -1)
    { commentaire = sequence.mid(pcom+1);
      len = pcom-pos-1;
    }
 QString ret                       = "";
 QString seq_days                  = sequence.mid(pos + 1,len);
 QString seq_time                  = sequence.left(pos).remove("[").trimmed();
 QString result                    = sequence_timeToString(seq_time, must_be_literal, up_forme);
 if (result.endsWith(", ")) result = result.left(result.length()-2);
 ret                              += result;
 result                            = sequence_daysToString(numSeq, seq_days, must_be_literal );
 if (result.length())         ret += result;
 if (commentaire.length())    ret += " " + commentaire;
 return ret;
}

//---------------------------- sequence_daysToString ------------------------------------------------
//  J2
QString C_PosologieGrammar::sequence_daysToString(int numSeq, const QString &seq_days, int must_be_literal /* = C_PosologieGrammar::NOT_LITERAL */)
{if (seq_days.length()==0) return "";
 char              t = seq_days.toAscii()[0]|32;
 QString      str_nb = seq_days.mid(1);
 int              nb = str_nb.toInt();
 QString         ret = seq_days;
 switch(t)
 {case 'i':    // IlmMjvsd I comme Include
  case 'e':    // ElmMjvsd E comme Exclude
    {
     // const char *pt = str_nb.toAscii();    // le pt n'est pas fiable du tout et ne permet pas le parsing des que ++pt le contenu part dans les choux pourquoi ???
     int        len = str_nb.length();
     if (len ==0)       return "";
     if (t=='e') ret = QObject::tr(" sauf le");
     else        ret = QObject::tr(" \303\240 prendre le");
     for (int i=0; i<len;++i)
       { switch(str_nb.toLatin1()[i])
          { case 'l': ret += QObject::tr(" lundi,");    break;
            case 'm': ret += QObject::tr(" mardi,");    break;
            case 'M': ret += QObject::tr(" mercredi,"); break;
            case 'j': ret += QObject::tr(" jeudi,");    break;
            case 'v': ret += QObject::tr(" vendredi,"); break;
            case 's': ret += QObject::tr(" samedi,");   break;
            case 'd': ret += QObject::tr(" dimanche,"); break;
          }
       }
      if (ret .endsWith(",")) ret = ret.left(ret.length()-1);
    } break;
   case 'u':     // UJSMA
     { return          QObject::tr(" \303\240 ne faire ") +
                       ((nb>1)?QObject::tr("que "):"qu'") +
                       ((must_be_literal&C_PosologieGrammar::DURATION)?numberToLiteral(nb,((nb>1)?0:102)):str_nb) + QObject::tr(" fois");
     } break;
   case 'j':
    {if (numSeq==0) return ((nb==1) ? QObject::tr(" le premier jour") :
                                      QObject::tr(" les ") + ( (must_be_literal&C_PosologieGrammar::DURATION)?numberToLiteral(nb):str_nb) + QObject::tr(" premiers jours"));
     else           return ((nb==1) ? QObject::tr(" le jour suivant") :
                                      QObject::tr(" les ") + ( (must_be_literal&C_PosologieGrammar::DURATION)?numberToLiteral(nb):str_nb) + QObject::tr(" jours suivants"));
     // ret = QObject::tr("pendant ") + ( (must_be_literal&C_PosologieGrammar::DURATION)?numberToLiteral(nb):str_nb) +" " + periodUnit+ ((nb>1)?"s":"");
    } break;
  case 's':
    {if (numSeq==0) return ((nb==1) ? QObject::tr(" la premi\303\250re semaine") :
                                      QObject::tr(" les ") + ( (must_be_literal&C_PosologieGrammar::DURATION)?numberToLiteral(nb):str_nb) + QObject::tr(" premi\303\250res semaines"));
     else           return ((nb==1) ? QObject::tr(" la semaine suivante") :
                                      QObject::tr(" les ") + ( (must_be_literal&C_PosologieGrammar::DURATION)?numberToLiteral(nb):str_nb) + QObject::tr(" semaines suivantes"));
    // ret            = QObject::tr("pendant ") + ( (must_be_literal&C_PosologieGrammar::DURATION)?numberToLiteral(nb):str_nb) +" " + periodUnit+ ((nb>1)?"s":"");
    } break;
  case 'm':
    {if (numSeq==0) return ((nb==1) ? QObject::tr(" le premier mois") :
                                      QObject::tr(" les ") + ( (must_be_literal&C_PosologieGrammar::DURATION)?numberToLiteral(nb):str_nb) + QObject::tr(" premiers mois"));
     else           return ((nb==1) ? QObject::tr(" le mois suivant") :
                                      QObject::tr(" les ") + ( (must_be_literal&C_PosologieGrammar::DURATION)?numberToLiteral(nb):str_nb) + QObject::tr(" mois suivants"));
     // ret            = QObject::tr("pendant ") + ( (must_be_literal&C_PosologieGrammar::DURATION)?numberToLiteral(nb):str_nb) +" " + periodUnit;
    } break;
  case 'a':
    {if (numSeq==0) return ((nb==1) ? QObject::tr(" la premi\303\250re ann\303\251e") :
                                      QObject::tr(" les ") + ( (must_be_literal&C_PosologieGrammar::DURATION)?numberToLiteral(nb):str_nb) + QObject::tr(" premi\303\250res ann\303\251es"));
     else           return ((nb==1) ? QObject::tr(" l'ann\303\251e suivante") :
                                      QObject::tr(" les ") + ( (must_be_literal&C_PosologieGrammar::DURATION)?numberToLiteral(nb):str_nb) + QObject::tr(" ann\303\251es suivantes"));
     // ret            = QObject::tr("pendant ") + ( (must_be_literal&C_PosologieGrammar::DURATION)?numberToLiteral(nb):str_nb) +" " + periodUnit+ ((nb>1)?"s":"");
    } break;
 }
 return ret;
}
//---------------------------- sequence_timeToString ------------------------------------------------
// 0.5;m|1;d15r|2;sr30|3;h10-13
QString C_PosologieGrammar::sequence_timeToString(const QString &seq_time, int must_be_literal /* = C_PosologieGrammar::NOT_LITERAL */, const QString &_up_forme /* = "" */)
{QString     up_forme = "";
 QStringList  seqList = seq_time.split('|');
 QString          ret = "";
 QString          str = "";
 QString           qu = "";
 QString          qu2 = "";
 QString       qu_lit = "";
 QString      qu_lit2 = "";
 QString before       = "";
 QString after        = "";
 int     before_n     = 0;
 int     after_n      = 0;
 int              pos = 0;
 int               p  = 0;
 int               nb = 0;
 int                l = 0;
 for (int i=0; i<seqList.count(); ++i)
    {up_forme   = _up_forme;   // ne pas accorder sexe nombre plusieurs fois donc reinitialiser
     str        = seqList[i];
     pos        = str.indexOf(';');
     if (pos   != -1)
        {//.......... C_PosologieGrammar::UP_QUANTITE la quantite d'unite de prise .....................
         //           ici est traite le mode literal ou numerique
         qu     = str.left(pos);
         p      = qu.indexOf('-');
         if (p != -1)                // cas ou 1-2   (un \303\240 deux)
            { qu2 = qu.mid(p+1);
              qu  = qu.left(p);
            }

         if      (must_be_literal & C_PosologieGrammar::UP_QUANTITE)       // tout doit etre converti en lettre quelque soit le flag C_PosologieGrammar::UP_JUST_FRACTION
                 {qu_lit = numberToLiteral(qu, up_forme, 0);               // cet appel est toujours necessaire meme si pas de literal car met a jour orthographe et pluriel de up_forme
                  ret   += qu_lit;
                  if (qu2.length())
                     {qu_lit2 = numberToLiteral(qu2, up_forme, 0);
                      ret    += QObject::tr(" \303\240 ") + qu_lit2;
                     }
                 }
         else if (must_be_literal & C_PosologieGrammar::UP_JUST_FRACTION)  // seules les parties fractionnaires 0.25 0.30 0.75 --> un quart un demi  trois quart
                 {qu_lit = numberToLiteral(qu, up_forme, 1);               // cet appel est toujours necessaire meme si pas de literal car met a jour orthographe et pluriel de up_forme
                  ret   += qu_lit;
                  if (qu2.length())
                     {qu_lit2 = numberToLiteral(qu2, up_forme, 1);
                      ret    += QObject::tr(" \303\240 ") + qu_lit2;
                     }
                 }
         else                                                              // tout doit rester en numerique
                 {qu_lit = numberToLiteral(qu, up_forme, 0);               // cet appel est toujours necessaire meme si pas de literal car met a jour orthographe et pluriel de up_forme
                  ret   += qu;
                  if (qu2.length())
                     {qu_lit2 = numberToLiteral(qu2, up_forme, 1);
                      ret    += QObject::tr(" \303\240 ") + qu2;
                     }
                 }
         //.......... la forme (precedemment ajustee grammaticalement par l'appel numberToLiteral(qu, up_forme);) ..............
         ret   += " " + up_forme+" "; // + ((qu.toFloat()>1.0)?"s ":" ");
         //........... C_PosologieGrammar::SEQUENCE_HOUR  le moment ou prendre les medocs dans la journee .......................
         //            si specifie en heures, le mode literal
         //            ou numerique sera traite ici
         str    = str.mid(pos+1);   // prendre ce qu'il y a apres le point virgule
         l      = str.length();
         if (l==0)             // mention l apres le point virgule
            {ret   += QObject::tr(" par jour");          // sera remplac\303\251 par l'unite de temps de la periode (jour semaine mois etc...)
            }
         else
            { char t  = str.toAscii()[0]|32;    // relever le m d a s c n h
              str     = str.mid(1);
              switch (t)
              {    case 'm': ret += QObject::tr("le matin");     break;
                   case 'd': ret += QObject::tr("\303\240 midi");       break;
                   case 'a': ret += QObject::tr("l'apr\303\250s-midi"); break;
                   case 's': ret += QObject::tr("le soir");      break;
                   case 'c': ret += QObject::tr("au coucher");   break;
                   case 'n': ret += QObject::tr("la nuit");      break;
                   case 'h':  // mode horaire
                      {pos  = str.indexOf('-');
                       nb   = 0;                   // sera utilise pour le pluriel des heures
                       if (pos != -1)
                          {      before   = str.left(pos);
                                 after    = str.mid(pos+1);
                                 before_n = before.toInt();
                                 after_n  = after.toInt();
                                 nb       = qMax(before_n,after_n);  // reperer si le pluriel doit etre applique
                                 if (must_be_literal & C_PosologieGrammar::SEQUENCE_HOUR)
                                    {before  =  numberToLiteral(before_n);
                                     after   =  numberToLiteral(after_n);
                                    }
                                 ret   += QObject::tr("de ")+ before + QObject::tr(" \303\240 ") + after;
                          }
                       else
                          {      nb = str.toInt();
                                 if (must_be_literal & C_PosologieGrammar::SEQUENCE_HOUR)
                                    { str = numberToLiteral(nb);
                                    }
                                 ret   += QObject::tr("\303\240 ") + str;
                          }
                       ret += QObject::tr(" heure") + ((nb>1)?"s":"");
                      } break;
                  }
              //............ C_PosologieGrammar::MOMENT_MEAL le moment par rapport au repas .........................
              //             en minutes, le mode literal numerique sera traite ici
              pos  = str.indexOf('r');
              if  (pos != -1)
                  { before   = str.left(pos);
                    after    = str.mid(pos+1);
                    before_n = before.toInt();
                    after_n  = after.toInt();
                    if ( after=="0" && before=="0")
                       {ret +=  QObject::tr(" au cours du repas");
                       }
                    else if ( before=="0" )
                       {ret +=  QObject::tr(" avant le repas");
                       }
                    else if (after=="0")
                       {ret +=  QObject::tr(" apr\303\250s le repas");
                       }
                    else if (before_n==0 && after_n==0)
                       {ret +=  QObject::tr(" au cours du repas");
                       }
                    else //if (before_n||after_n)
                       {
                        if (must_be_literal & C_PosologieGrammar::MOMENT_MEAL)
                           { before = numberToLiteral(before.toInt());
                             after  = numberToLiteral(after.toInt());
                           }
                        if      (before.length()) ret += " " + before + QObject::tr(" minutes avant le repas");
                        else if (after.length() ) ret += " " + after  + QObject::tr(" minutes apr\303\250s le repas");
                        else                      ret += " " + QObject::tr("au cours du repas");
                       }
                  }
          } // if (str.length())
         ret += ", ";
        }
    }  // end for (int i=0; i<seqList.count(); ++i)
 return ret;
}
//---------------------------- numberToLiteral ------------------------------------------------
QString C_PosologieGrammar::numberToLiteral(QString number, QString &up_forme , int justOneFraction /* = false */)
{number.replace(',','.');
 QString       str  = "";
 int left_part_int  = 0;
 QString left_part  = "";
 QString right_part = "";
 char          sexe = 'm';
 int pos            = number.indexOf(".");
 if (pos != -1)               // UP_QUANTITE et UP_JUST_FRACTION ==>
    {//  0.75 1.75 789.75
     left_part         = number.left(pos);
     right_part        = number.mid (pos+1);
     left_part_int     = left_part.toInt();
     up_forme          = adjustPlurielUpForme(left_part_int, up_forme, sexe);

     if (left_part_int==0)  left_part  = "";
     else                   left_part  = numberToLiteral(left_part.toInt(), sexe);
     if      (right_part=="25")
             { if (left_part_int)
                  {if (justOneFraction ) return number;
                   else                  return left_part + " et un quart de";
                  }
               else                      return QString("un quart de");
             }
     else if (right_part=="50" || right_part=="5")
             { str = (sexe=='f')?"une demie":"un demi";
               if (left_part_int)
                  {if (justOneFraction) return number;
                   else                 return left_part + " et "+ str;
                  }
               else                     return str;
             }
     else if (right_part=="75")
             { if (left_part_int)
                  {if (justOneFraction) return number;
                   else                 return left_part + " et trois quarts de";
                  }
               else                     return QString("trois quarts de");
             }
     else    { if (justOneFraction)     return number;
               else  right_part = numberToLiteral(right_part.toInt(),sexe);
             }
     if (left_part_int==0) return QString("z\303\251ro virgule ") + right_part;
     else                  return left_part + " virgule "  + right_part;
    }
 left_part_int     = number.toInt();
 if (up_forme.endsWith("(s)"))up_forme.chop(3);
 up_forme          = adjustPlurielUpForme(left_part_int, up_forme, sexe);
 if (justOneFraction) return number;   // toujours executer adjustPlurielUpForme() car ajuste la forme au pluriel
 else                 return numberToLiteral(left_part_int,sexe);
}
//---------------------------- adjustPlurielUpForme ------------------------------------------------
QString C_PosologieGrammar::adjustPlurielUpForme(int nb, const QString &_up_forme, char &sexe)
{QString up_forme ="";
 //......... on essaie de trouver avec le dictionnaire de mots ..................
 up_forme = get_AccordedWord ( nb, _up_forme, sexe );
 if (up_forme.length()) return up_forme;

 up_forme = _up_forme;

 sexe = 'm';
 int pos = -1;
 if ( (pos=up_forme.indexOf("cuillere"))!=-1 )
 {sexe = 'f';
  return up_forme.replace("cuillere",(nb>1 && up_forme[pos+8] != 's')?"cuill\303\250res":"cuill\303\250re").replace(" a "," \303\240 ");
 }
 if ( (pos=up_forme.indexOf("cuill\303\250re"))!=-1 )
 {sexe = 'f';
  return up_forme.replace("cuill\303\250re",(nb>1 && up_forme[pos+8] != 's')?"cuill\303\250res":"cuill\303\250re").replace(" a "," \303\240 ");
 }
 else if( (pos=up_forme.indexOf("application"))!=-1 )
 {sexe = 'f';
  return up_forme.replace("application",(nb>1 && up_forme[pos+11] != 's')?"applications":"application");
 }
 else if( (pos=up_forme.indexOf("goutte"))!=-1 )
 {sexe = 'f';
  return up_forme.replace("goutte",(nb>1 && up_forme[pos+6] != 's')?"gouttes":"goutte");
 }
 else if( (pos=up_forme.indexOf("injection"))!=-1 )
 {sexe = 'f';
  return up_forme.replace("injection",(nb>1 && up_forme[pos+9] != 's')?"injections":"injection");
 }
 else if( (pos=up_forme.indexOf("inhalation"))!=-1 )
 {sexe = 'f';
  return up_forme.replace("inhalation",(nb>1 && up_forme[pos+10] != 's')?"inhalations":"inhalation");
 }
 else if( (pos=up_forme.indexOf("gelule"))!=-1 )
 {sexe = 'f';
  return up_forme.replace("gelule",(nb>1 && up_forme[pos+6] != 's')?"g\303\251lules":"g\303\251lule");
 }
 else if( (pos=up_forme.indexOf("g\303\251lule"))!=-1 )
 {sexe = 'f';
  return up_forme.replace("g\303\251lule",(nb>1 && up_forme[pos+6] != 's')?"g\303\251lules":"g\303\251lule");
 }
 else if( (pos=up_forme.indexOf("pulverisation"))!=-1 )
 {sexe = 'f';
  return up_forme.replace("pulverisation",(nb>1 && up_forme[pos+13] != 's')?"pulv\303\251risations":"pulv\303\251risation");
 }
 else if( (pos=up_forme.indexOf("pulv\303\251risation"))!=-1 )
 {sexe = 'f';
  return up_forme.replace("pulv\303\251risation",(nb>1 && up_forme[pos+13] != 's')?"pulv\303\251risations":"pulv\303\251risation");
 }
 else if( (pos=up_forme.indexOf("ampoule"))!=-1 )
 {sexe = 'f';
  return up_forme.replace("ampoule",(nb>1 && up_forme[pos+7] != 's')?"ampoules":"ampoule");
 }
 else if( (pos=up_forme.indexOf("capsule"))!=-1 )
 {sexe = 'f';
  return up_forme.replace("capsule",(nb>1 && up_forme[pos+7] != 's')?"capsules":"capsule");
 }
 else if( (pos=up_forme.indexOf("ml"))!=-1 )
 {sexe = 'm';
  return up_forme;
 }
 else if(up_forme.contains("mg"))
 {sexe = 'm';
  return up_forme;
 }
 else if(up_forme.contains("ui"))
 {sexe = 'f';
  return up_forme;
 }
 else if( (pos=up_forme.indexOf("comprime"))!=-1 )
 {sexe = 'm';
  return up_forme.replace("comprime",(nb>1 && up_forme[pos+8] != 's')?"comprim\303\251s":"comprim\303\251");
 }
 else if( (pos=up_forme.indexOf("comprim\303\251"))!=-1 )
 {sexe    = 'm';
  return up_forme.replace("comprim\303\251",(nb>1 && up_forme[pos+8] != 's')?"comprim\303\251s":"comprim\303\251");
 }
 else if( (pos=up_forme.indexOf("bouffee"))!=-1 )
 {sexe = 'f';
  return up_forme.replace("bouffee",(nb>1 && up_forme[pos+7] != 's')?"bouff\303\251es":"bouff\303\251e");
 }
 else if( (pos=up_forme.indexOf("bouff\303\251e"))!=-1 )
 {sexe    = 'f';
  return up_forme.replace("bouff\303\251e",(nb>1 && up_forme[pos+7] != 's')?"bouff\303\251es":"bouff\303\251e");
 }
 else if( (pos=up_forme.indexOf("gourde"))!=-1 )
 {sexe    = 'f';
  return up_forme.replace("gourde",(nb>1 && up_forme[pos+7] != 's')?"gourdes":"gourde");
 }

 return ((nb>1 && !up_forme.endsWith('s'))?up_forme+"s":up_forme);
}

//---------------------------- numberToLiteral ------------------------------------------------
QString C_PosologieGrammar::numberToLiteral(int nb, char sexe /* = 'm' */)
{
 QString ret = "";
 char nompart[10][10]={"dix","onze","douze","treize","quatorze","quinze","seize","dix-sept","dix-huit","dix-neuf"};
 char nomunite[10][10]={"","un","deux","trois","quatre","cinq","six","sept","huit","neuf"};
 char nomdizaine[8][17]={"vingt","trente","quarante","cinquante","soixante","soixante-","quatre-vingt","quatre-vingt-"};
 char nomspe[3][7]={"cent","-et-un","mille"};
 int milliers  = nb/1000;
     nb        = nb%1000;
 int centaines = nb/100;
 int unites    = nb%100;
 int dizaines  = unites/10;
 unites=unites%10;
 if (milliers>1 && milliers<10)       ret += adjustUniteToSexe(nomunite[milliers],sexe)  +" " + QString(nomspe[2])+" ";
 if (milliers==1)                     ret += QString(nomspe[2]) + " ";
 if (centaines>1)
    {                                 ret += adjustUniteToSexe(nomunite[centaines],sexe) +" " + QString(nomspe[0])+" ";
     if ( unites==0 && dizaines==0 )  ret  = ret.left(ret.length()-1);
    }
 if ( centaines==1 )                  ret += QString(nomspe[0]) + " ";
 if ( dizaines>1 && dizaines!=7 && dizaines!=9 )
    {                                 ret += QString(nomdizaine[dizaines-2]);
     if ( dizaines==8 && unites==0 )  ret += QString("s");
     if ( unites>1 )
        {                             ret += "-" + adjustUniteToSexe(nomunite[unites],sexe);
          unites=0;
        }
     if ( unites==1 )
        { unites=0;                   ret += adjustUniteToSexe(nomspe[1],sexe);
        }
    }
 if ( dizaines==1 || dizaines==7 || dizaines==9 )
    {
     if (dizaines==7 || dizaines==9)  ret += QString(nomdizaine[dizaines-2]);
     if (dizaines==7 && unites==1)
        { ret = ret.left(ret.length()-1);    ret += adjustUniteToSexe(nomspe[1],sexe);
          ret = ret.left(ret.length()-2);
        }
                                      ret += QString(nompart[unites]);
     unites=0;
    }
 if (dizaines!=0 && centaines!=0)     ret += " ";
                                      ret += adjustUniteToSexe(nomunite[unites],sexe);
 return ret.trimmed();
}
//---------------------------- adjustUniteToSexe ------------------------------------------------
QString C_PosologieGrammar::adjustUniteToSexe(const QString &unite, char sexe )
{if (unite.contains("un") && sexe=='f') return QString(unite).replace("un","une");
 return unite;
}

