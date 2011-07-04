#include "C_BaseDatasemp.h"
#include <QDomElement>
#include <QDomNode>
#include <QSqlQuery>
#include <QVariant>

#include "C_DSVar.h"
#include "../../MedinTuxTools-QT4/CGestIni.h"

//--------------------------- C_BaseDatasemp ---------------------------------------------------------
C_BaseDatasemp::C_BaseDatasemp(const QString &param , QString& confData, QObject *parent) : C_BaseCommon(parent) , C_DSVar( confData)
{if (!C_DSVar::areFieldsNamesValids())                       C_BaseDatasemp::setLastError(C_DSVar::getLastError());
 if (!BaseConnect(param,"BaseDataSemp","DatasempTest"))      C_BaseDatasemp::setLastError(C_BaseCommon::getLastError());
  Datasemp_SetHTMLFontProperty("Arial","24","18","16","16");
}

//--------------------------- setLastError -----------------------------------------------------------
void       C_BaseDatasemp::setLastError(const QString &error){ m_LastError = error;}

//--------------------------- getLastError -----------------------------------------------------------
QString    C_BaseDatasemp::getLastError(){return m_LastError;}

//-----------------------------------------------------  Datasemp_SetHTMLFontProperty -------------------------------------------
void C_BaseDatasemp::Datasemp_SetHTMLFontProperty(const QString &family, const QString &titleSize, const QString &chapitreSize, const QString &paragraphSize, const QString &normalText)
{  m_FontFamily         = family;
   m_FontTitleSize      = titleSize;
   m_FontchapitreSize   = chapitreSize;
   m_FontparagraphSize  = paragraphSize;
   m_FontnormalTextSize = normalText;
}

//-----------------------------------------------------  Datasemp_GetMonographieFromCIP -------------------------------------------
QString    C_BaseDatasemp::Datasemp_GetMonographieFromCIP(const QString &code_CIP)
{ QString pkt4B("");
  QString requete("");
  // 2  PrimaryKey ________________
  // 1  Code unite de vente ___    |
  // 0  code produit    ___    |   |
  //                       |   |   |
  requete +=       "SELECT f0, f1, ge FROM t00 WHERE f2 = '" + code_CIP + "'";
  QSqlQuery query(requete , database() );
  if (! (query.isActive() && query.next()))                             return QString::null;
  QString codePD ( query.value(0).toString() );
  QString codeUV ( query.value(1).toString() );
  Datasemp_GetField("t4B", "f0",  codePD, "f2", &pkt4B);
  return Datasemp_GetMonographie( codeUV, pkt4B );
}

//-----------------------------------------------------  Datasemp_GetMonographie -------------------------------------------
//                  la norme vidal est que les noms des images des mononographies sont en majuscules : src="IMAGES/B00/C01/D35.GIF"
QString   C_BaseDatasemp::Datasemp_GetMonographie(const QString &code_UV, const QString &pkt4B)
{ QString  name("");
  QString  codeMonographie("");
  QString  result("");
  int f = -1;
  //................. chercher si existe une  monographie vidal pour ce produit...................................................
  //                              recuperer code document de la monographie
  QSqlQuery query (QString("SELECT f1 FROM t5D WHERE f0 ='") + code_UV + "'" , database() );
  if (query.isActive() && query.next()) codeMonographie    = query.value(0).toString();

  query.exec(QString("SELECT f3 FROM t5C WHERE f0 ='") + codeMonographie + "'");
  if (query.isActive() &&query.next())         result     =  query.value(0).toString();
  if ( (f=result.indexOf("<html",0, Qt::CaseInsensitive)) > 0)   result.remove (0, f );
  if (result != "") return result;

  //................. si pas de monographie vidal pour ce produit...................................................
  //                  creer une page html à partir des infos XML
  query.exec(QString("SELECT f5, f2 FROM t4B WHERE ge =") + pkt4B );
  if (query.isActive() && query.next())
     {result = query.value(0).toString();
      name   = query.value(1).toString();
     }
  if (result!="")
     {Datasemp_Xml_to_html(result, name);
     }
  return result;
}

//-------------------------------------- Datasemp_Xml_to_html -------------------------------------------------------
void C_BaseDatasemp::Datasemp_Xml_to_html( QString& input, QString  name  /* = QString::null */ )
{
 int xmlDepth      = -1;
 //................ convertir les retours chariot en trucs non XML (ne doivent pas etres interprétés) ................
 input.replace("<BR/>","{{@}}");
 QDomDocument doc( "mydocument" );
 if ( !doc.setContent( input ) ) return;

 input =  "<html><head><meta name=\"qrichtext\" content=\"1\" /></head>"
          "<body style=\"font-size:16pt;font-family:Arial\">";

 if (name != QString::null)
    {input += "<p align=\"center\"><span style=\"font-family:"+m_FontFamily+";font-size:"+m_FontTitleSize+"pt;font-style:italic;font-weight:600;color:#AA0000\">";
     input += name  +  "</span></p> <hr size=\"2\" />";
    }
 Datasemp_Xml_ListChild(input, doc.documentElement(), xmlDepth );
 input     += "</body></html>";
 input.replace("’","\'");
}

//-------------------------------------- Datasemp_Xml_ListChild -------------------------------------------------------
void C_BaseDatasemp::Datasemp_Xml_ListChild(QString& input, const QDomElement &parentElement, int &xmlDepth )
{   ++xmlDepth;
    QString ofset = "";
    for (int i=0; i<xmlDepth; i++) ofset += "\t";
    QDomNode node = parentElement.firstChild();
    while ( !node.isNull() )
       {if ( node.isElement() /* && node.nodeName() == "outline" */)
           {QDomElement e   = node.toElement();
            QString text    = e.text();
            QString tagName = e.tagName();
            QString title   = e.attribute("TITRE");
            int         tag = 1;
            if (tagName=="RUBRIQUE")
               {input +=  ofset + "<br /><span style=\"font-family:"+m_FontFamily+";font-size:"+m_FontTitleSize+"pt;font-weight:600;text-decoration:underline;color:#AA0000\">";
                input +=  title + "</span><br />";
               }
            else if (tagName=="SSRUBR")
               {title.replace(">", "&gt;");
                title.replace("<", "&lt;");
                input += ofset + "<span style=\"font-family:"+m_FontFamily+";font-size:"+m_FontchapitreSize+"pt;font-weight:600;text-decoration:underline;color:#000000\">";
                input += title + "</span><br />";
               }
            else if (tagName=="CAS")
               {title.replace(">", "&gt;");
                title.replace("<", "&lt;");
                input += ofset + "<span style=\"font-family:"+m_FontFamily+";font-size:"+m_FontparagraphSize+"pt;font-weight:600;color:#0000FF\">";
                input += title + "</span><br />";
               }
            else tag=0;
            if (tag && text!="")
               {text.replace(">", "&gt;");
                text.replace("<", "&lt;");
                text.replace("{{@}}", " <br>" + ofset); // replacer les retours chariots normaux
                input += ofset + "<span style=\"font-family:"+m_FontFamily+";font-size:"+m_FontnormalTextSize+"pt;color:#00007F\">";
                input += text  + "</span><br />";
               }
            //........... APPEL RECURSIF ...........
            Datasemp_Xml_ListChild( input, node.toElement(), xmlDepth );
           }
        node = node.nextSibling();
       }
    --xmlDepth;
}

//----------------------------------------------- Datasemp_GetField ---------------------------------------------------
QString C_BaseDatasemp::Datasemp_GetField(const  QString &table,             // SELECT fieldToGet FROM table WHERE testField = testValue
                                          const  QString &testField,
                                          const  QString &testValue,
                                          const  QString &fieldToGet,
                                          QString    *pk /* = 0 */)
{ QString result = "";
  int          i = 0;
  //................. SI un nom ou prenom est donné en entrée alors filtrer selon ...................
  QString requete = "SELECT ";
  if (pk) requete = requete + fieldToGet + ", ge FROM " + table + " WHERE " + testField  + "= \"" + testValue + "\"";
  else    requete = requete + fieldToGet + " FROM "     + table + " WHERE " + testField  + "= \"" + testValue + "\"";
  QSqlQuery query(requete , database() );
  if (query.isActive())
     {result = "";
      while (query.next())
         {if (i)
             {result = result   + "|@|\n";     // s?arer par |@| si plusieurs valeurs et r?onses retourn?s
              if (pk) *pk = *pk + "|@|\n";     // s?arer par |@| si plusieurs valeurs et r?onses retourn?s
             }
          result     += CGestIni::Utf8_Query(query,0);     // CGestIni::Utf8_Query(query, 1)
          if (pk) *pk = query.value(1).toString();
          ++i;
         }
     }
  return result;
}
