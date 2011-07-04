#ifndef C_BASEDATASEMP_H
#define C_BASEDATASEMP_H
#include "../C_BaseCommon.h"
#include "C_DSVar.h"

class QDomElement;
//====================================== C_BaseDatasemp =====================================
class C_BaseDatasemp : public C_BaseCommon, C_DSVar
{
    Q_OBJECT

public:
    explicit  C_BaseDatasemp(const QString &param , QString& confData, QObject *parent);
    QString   getLastError();
    QString   Datasemp_GetMonographieFromCIP(const QString &code_CIP);
private:
    void      setLastError(const QString &error);
    void      Datasemp_SetHTMLFontProperty(const QString &family, const QString &titleSize, const QString &chapitreSize, const QString &paragraphSize, const QString &normalText);
    QString   Datasemp_GetMonographie(const QString &code_UV, const QString &pkt4B);
    void      Datasemp_Xml_to_html( QString& input, QString  name  );
    void      Datasemp_Xml_ListChild(QString& input, const QDomElement &parentElement, int &xmlDepth );
    QString   Datasemp_GetField (const QString &table,  const QString &testField, const  QString &testValue, const QString &fieldToGet, QString *pk  = 0 );  // SELECT fieldToGet FROM table WHERE testField = testValue
private:
       QString      m_LastError;
       QString      m_FontFamily;
       QString      m_FontTitleSize;
       QString      m_FontchapitreSize;
       QString      m_FontparagraphSize;
       QString      m_FontnormalTextSize;

};

#endif // C_BASEDATASEMP_H
