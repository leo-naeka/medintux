/*********************************** C_GoogleAPI.cpp **********************
* #include "C_GoogleAPI.h"           QT4-ready                            *
* .                                                                       *
*                                                                         *
* This file is part of CalendarGadget Copyright (C) 2010-2011 B.D. Mihai  *
* modified for MedinTux                                                   *
* Many thanks for  B.D. Mihai (CalendarGadget) to help me to understand   *
* Google API                                                              *
* ........................................................................*
*   Project   :  MedinTux  (typographie made in france)                   *
*   Copyright :  (C) 2005-2006-2007-2008-2009-2010 and for the eternity   *
*   by        :  Sevin Roland     from   MedinTux project                 *
*   E-Mail    :  roland-sevin@medintux.org                                *
*   Web site  :  www.medintux.org                                         *
* ........................................................................*
*                                                                         *
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
#include "C_GoogleAPI.h"

#include <QSslSocket>
#include <QNetworkRequest>
#include <QXmlStreamReader>
#include <QApplication>

#include "C_GoogleAPI.h"
#include "C_GoogleAPI.h"
//#include "../../MedinTuxTools-QT4/CGestIni.h"

//------------------------------------ C_GoogleAPI ---------------------------------------------
/*!
Create a new instance of the C_GoogleAPI class.
*/
C_GoogleAPI::C_GoogleAPI(QObject *parent) :
    QObject(parent)
{
  m_netAccMan      = new QNetworkAccessManager();
  m_auth           = new C_GoogleAuthentification(m_netAccMan, "cl");
  m_loop           = new QEventLoop();
  m_serviceWorking = false;
}
//------------------------------------ ~C_GoogleAPI ---------------------------------------------
/*!
Clean up.
*/
C_GoogleAPI::~C_GoogleAPI()
{ delete m_auth;
  delete m_loop;
  delete m_netAccMan;
}
//------------------------------------isServiceAvailable ---------------------------------------------
/*!
This function checks if the necessary conditions for using this service are
fulfilled.
*/
bool C_GoogleAPI::isServiceAvailable()
{return QSslSocket::supportsSsl();
}
//------------------------------------getError ---------------------------------------------
/*!
Get the error text if it is the case.
*/
QString C_GoogleAPI::getError()
{return m_error;
}
//------------------------------------configureProxy ---------------------------------------------
/*!
Configure the proxy used by the service.
*/
void C_GoogleAPI::configureProxy(QNetworkProxy::ProxyType type, const QString &hostName,
                                 quint16 port, const QString &user, const QString &password)
{ m_netAccMan->setProxy(QNetworkProxy(type, hostName, port, user, password));
}
//------------------------------------login ---------------------------------------------
/*!
This function try to login into the Google account and obtain the authentication
code for the calendar service ("cl"). The function will block until the request
is finalized.
\param mail the full mail address.
\param password the password for the provided mail account.
\return true if the login was performed successfully.
*/
bool C_GoogleAPI::login(QString mail, QString password)
{
  if (m_auth->google_login(mail, password))
     {m_error          = "";
      m_serviceWorking = getSession();
     }
  else
     {m_error          = m_auth->getError();
      m_serviceWorking = false;
     }
  return m_serviceWorking;
}
//------------------------------------getSession ---------------------------------------------
/*!
This function try to obtain a session id from Google in order to be able to
access the calendar without redirection.
The function will block until the request is finalized.
*/
bool C_GoogleAPI::getSession()
{
  QUrl address("http://www.google.com/calendar/feeds/default/private/full");

  QNetworkRequest request = QNetworkRequest();
  request.setUrl(address);
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

  QString authorization = QString("GoogleLogin auth=%1").arg(m_auth->getAuth()).toLatin1();
  request.setRawHeader("Authorization", authorization.toAscii());
  request.setRawHeader("GData-Version", "2.0");
  request.setRawHeader("X-If-No-Redirect", "1");

  m_reply = m_netAccMan->get(request);
  connect(m_reply, SIGNAL(finished()), this, SLOT(Slot_getSessionDone()));
  m_loop->exec();
  return m_error.isEmpty();
}
//------------------------------------Slot_getSessionDone ---------------------------------------------
/*!
This function handles the m_reply to the get session request.
*/
void C_GoogleAPI::Slot_getSessionDone()
{
  if (m_reply->hasRawHeader("X-Redirect-Location"))
     {m_session = m_reply->rawHeader("X-Redirect-Location");
      m_session = m_session.right(m_session.length() - m_session.indexOf('=') - 1);
     }
  else
     {if (m_reply->error()) m_error = m_reply->errorString();
     }
  m_reply->deleteLater();
  m_reply = 0;
  m_loop->exit();
}

//------------------------------------getEventsBetweenTwoDates ---------------------------------------------
/*!
This function starts the retrieval of all-day-events from the calendar
between two dates.
\param debDate is the start date.
\param endDate is the end date.
\return C_GoogleEventList whith all events between debDate and endDate .
*/
C_GoogleEventList C_GoogleAPI::getEventsBetweenTwoDates(const QDate &debDate, const QDate &endDate)
{ m_eventsList.clear();
  if (m_serviceWorking)
     {QString debDateStr = debDate.toString("yyyy-MM-dd")+"T00:00:00";
      QString endDateStr = endDate.toString("yyyy-MM-dd")+"T00:00:00";

      QUrl address("http://www.google.com/calendar/feeds/default/private/full");
      address.addQueryItem("gsessionid", m_session);
      address.addQueryItem("start-min", debDateStr);
      address.addQueryItem("start-max", endDateStr);
      QNetworkRequest request = QNetworkRequest();
      request.setUrl(address);
      request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
      QString authorization = QString("GoogleLogin auth=%1").arg(m_auth->getAuth()).toLatin1();
      request.setRawHeader("Authorization", authorization.toAscii());
      request.setRawHeader("GData-Version", "2.0");
      m_serviceWorking = false;
      m_reply          = m_netAccMan->get(request);
      connect(m_reply, SIGNAL(finished()), this, SLOT(Slot_getEventsDone()));
      while (m_serviceWorking == false) {qApp->processEvents();}
     }
  return m_eventsList;
}

//------------------------------------Slot_getEventsDone ---------------------------------------------
/*!
This function handles the m_reply to the get events request.
The events are decoded from the xml atom feed and after m_eventsList
is initialised to alls events
*/
void C_GoogleAPI::Slot_getEventsDone()
{
  if (!m_reply->error())
     {
      QString response = m_reply->readAll();
      //CGestIni::Param_UpdateToDisk("/home/ro/googleCalGet.xml", response);
      QXmlStreamReader xml(response);
      QString title;
      QString content;
      QString event_ID;
      QString startTime;
      QString endTime;
      QString etag;
      QString where;
      QString color;
      bool    isFromMedinTux = false;
      bool          readData = false;
      m_error                = "";
      while (!xml.atEnd())
            {
              xml.readNext();
              if (xml.isStartElement() && xml.name() == "entry")
                 { QXmlStreamAttributes attributes = xml.attributes();
                   if (attributes.hasAttribute("gd:etag"))
                       etag       = attributes.value("gd:etag").toString().simplified();
                   readData       = true;
                   isFromMedinTux = false;
                 }
              if (xml.isStartElement() && xml.name() == "title" && readData)
                 { title = xml.readElementText();
                 }
              if (xml.isStartElement() && xml.name() == "content" && readData)
                 { content = xml.readElementText();
                 }
              if (xml.isStartElement() && xml.name() == "id" && readData)
                 { event_ID = xml.readElementText();
                 }
              if (xml.isStartElement() && xml.qualifiedName() == "gd:extendedProperty" && readData )
                 { QXmlStreamAttributes attributes = xml.attributes();
                   QString  name = "";
                   QString value = "";
                   if (attributes.hasAttribute("name"))   name = attributes.value("name").toString().simplified();
                   if (attributes.hasAttribute("value")) value = attributes.value("value").toString().simplified();
                   if (name=="isFromMedinTux") isFromMedinTux = true;
                 }
              if (xml.isStartElement() && xml.qualifiedName() == "gd:where" && readData )
                 { QXmlStreamAttributes attributes = xml.attributes();
                   if (attributes.hasAttribute("valueString"))
                       where = attributes.value("valueString").toString().simplified();
                 }
              if (xml.isStartElement() && xml.qualifiedName() == "gd:color" && readData )
                 { QXmlStreamAttributes attributes = xml.attributes();
                  if (attributes.hasAttribute("value"))
                      color = attributes.value("value").toString().simplified();
                 }
              if (xml.isStartElement() && xml.qualifiedName() == "gd:when" && readData )
                 { QXmlStreamAttributes attributes = xml.attributes();
                   if (attributes.hasAttribute("startTime"))
                      startTime = attributes.value("startTime").toString().simplified();
                   if (attributes.hasAttribute("endTime"))
                      endTime   = attributes.value("endTime").toString().simplified();
                 }
              if (xml.isEndElement() && xml.name() == "entry")
                 { //if (content.startsWith("MedinTux :"))        // crees en dehors de MedinTux
                   if (isFromMedinTux)
                      { m_eventsList.append(C_GoogleEvent( title              ,
                                                           startTime.left(19) ,
                                                           endTime.left(19)   ,
                                                           content            ,
                                                           where              ,
                                                           "#5779db"          ,
                                                           etag               ,
                                                           event_ID
                                                         )
                                           );
                      }
                   readData       = false;
                 }
            } // end while (!xml.atEnd())
      if (xml.hasError())
         {m_error = xml.errorString();
         }
     } // end if (!m_reply->error())
  else
     {m_error = m_reply->errorString();
     }
  m_reply->deleteLater();
  m_reply = 0;
  m_serviceWorking = true;
}

//------------------------------------createSeveralEvents ---------------------------------------------
/*!
This function create events
\param startDate is the start date.
\param endDate is the end date.
*/
void C_GoogleAPI::createSeveralEvents(const C_GoogleEventList &eventsList)
{if (eventsList.size()<=0) return;
 //.............. batch mode for beter performance .............................
 C_GoogleEvent event;
 QString       data = "";
 for (int i = 0; i < eventsList.size(); ++i)
     {event    = eventsList[i];
      data    += QString("<entry>"
                         "<batch:id>Insert item%1</batch:id>"
                         "<batch:operation type='insert' />"
                         "<category scheme='http://schemas.google.com/g/2005#kind' term='http://schemas.google.com/g/2005#event' />"
                         "<title type='text'>%2</title>"
                         "<content type='text'>%3</content>"
                         "<gd:transparency value='http://schemas.google.com/g/2005#event.opaque'></gd:transparency>"
                         "<gd:eventStatus value='http://schemas.google.com/g/2005#event.confirmed'></gd:eventStatus>"
                         "<gd:where valueString='%4'></gd:where>"
                         "<gd:color value='%5'/>"
                         "<gd:when startTime='%6' endTime='%7'></gd:when>"
                         "<gd:extendedProperty name='isFromMedinTux' value='ok' />"
                         "</entry>").arg(  QString::number(i) ,                                                                                 // %1
                                           event.getTitle().replace("&NBSP;"," ").replace('>',"&gt;").replace('<',"&lt;") ,                     // %2
                                           event.getContent().replace("&NBSP;"," ").replace('>',"&gt;").replace('<',"&lt;") ,                   // %3
                                           event.getWhere().replace("&NBSP;"," ").replace("'","&#39;").replace('>',"&gt;").replace('<',"&lt;"), // %4
                                           event.getColor() ,                                                                                   // %5
                                           event.getDateDeb().toString("yyyy-MM-ddThh:mm:00.000Z"),                                             // %6
                                           event.getDateEnd().toString("yyyy-MM-ddThh:mm:00.000Z")                                              // %7
                                         );
     }
 data.prepend("<feed xmlns='http://www.w3.org/2005/Atom' xmlns:app='http://www.w3.org/2007/app' xmlns:batch='http://schemas.google.com/gdata/batch' xmlns:gCal='http://schemas.google.com/gCal/2005' xmlns:gd='http://schemas.google.com/g/2005'>"
              "<category scheme='http://schemas.google.com/g/2005#kind' term='http://schemas.google.com/g/2005#event' />");
 data      += "</feed>";
 //CGestIni::Param_UpdateToDisk("/home/ro/googleAdd.xml", data);
 if (m_serviceWorking)
    {
      QUrl address("http://www.google.com/calendar/feeds/default/private/full/batch");
      address.addQueryItem("gsessionid", m_session);
      QNetworkRequest request = QNetworkRequest();
      request.setUrl(address);
      request.setHeader(QNetworkRequest::ContentTypeHeader, "application/atom+xml; charset=UTF-8; type=entry"); //application/x-www-form-urlencoded
      QString authorization = QString("GoogleLogin auth=%1").arg(m_auth->getAuth()).toLatin1();
      request.setRawHeader("Authorization", authorization.toAscii());
      request.setRawHeader("GData-Version", "2.0");
      m_serviceWorking = false;
      m_reply          = m_netAccMan->post(request,data.toUtf8());
      connect(m_reply, SIGNAL(finished()), this, SLOT(Slot_createSeveralEventsDone()));
      while (m_serviceWorking == false) {qApp->processEvents();}
    }
}
//------------------------------------Slot_createSeveralEventsDone ---------------------------------------------
/*!
This function handles the m_reply to the createSeveralEvents request.
*/
void C_GoogleAPI::Slot_createSeveralEventsDone()
{if (!m_reply->error())
    {/*QString response = */m_reply->readAll();
    }
  else
    {m_error = m_reply->errorString();
    }
  m_reply->deleteLater();
  m_reply = 0;
  m_serviceWorking = true;
}

//------------------------------------deleteAllEventsBetweenTwoDates ---------------------------------------------
/*!
This function erase all events already presents between two dates
\param debDate is the start date.
\param endDate is the end date.
*/
void C_GoogleAPI::deleteAllEventsBetweenTwoDates(const QDate &debDate, const QDate &endDate)
{//............ retrieve list (m_eventsList) of all events ................................
 //                     between debDate and endDate
 getEventsBetweenTwoDates(debDate, endDate);   // initialize m_eventsList to all events
 if (m_eventsList.size()<=0) return;
 //.............. for each event put xml request .....................................................
 //               batch mode for beter performance
 QString data  = "";
 for (int i = 0; i < m_eventsList.size(); ++i)
     {data    += QString("<entry gd:etag='%1'>"
                         "<batch:id>Delete item%2</batch:id>"
                         "<batch:operation type='delete' />"
                         "<id>%3</id>"
                         "</entry>").arg(m_eventsList[i].getEtag(),QString::number(i),m_eventsList[i].getEvent_ID());
     }
 //............. add header and xml close mention ............................................
 data.prepend("<feed xmlns='http://www.w3.org/2005/Atom' xmlns:app='http://www.w3.org/2007/app' xmlns:batch='http://schemas.google.com/gdata/batch' xmlns:gCal='http://schemas.google.com/gCal/2005' xmlns:gd='http://schemas.google.com/g/2005'>"
              "<category scheme='http://schemas.google.com/g/2005#kind' term='http://schemas.google.com/g/2005#event' />"
             );
 data    +="</feed>";
 if (m_serviceWorking)
    {
      QUrl address("http://www.google.com/calendar/feeds/default/private/full/batch");
      address.addQueryItem("gsessionid", m_session);
      QNetworkRequest request = QNetworkRequest();
      request.setUrl(address);
      request.setHeader(QNetworkRequest::ContentTypeHeader, "application/atom+xml; charset=UTF-8; type=entry"); //application/x-www-form-urlencoded
      QString authorization = QString("GoogleLogin auth=%1").arg(m_auth->getAuth()).toLatin1();
      request.setRawHeader("Authorization", authorization.toAscii());
      request.setRawHeader("GData-Version", "2.0");
      m_serviceWorking = false;
      m_reply          = m_netAccMan->post(request,data.toUtf8());
      connect(m_reply, SIGNAL(finished()), this, SLOT(Slot_deleteEventsDone()));
      while (m_serviceWorking == false) {qApp->processEvents();}
    }
}
//------------------------------------Slot_deleteEventsDone ---------------------------------------------
/*!
This function handles the m_reply to the deleteEventsDone request.
*/
void C_GoogleAPI::Slot_deleteEventsDone()
{if (!m_reply->error())
    {/*QString response = */ m_reply->readAll();
    }
  else
    {m_error = m_reply->errorString();
    }
  m_reply->deleteLater();
  m_reply = 0;
  m_serviceWorking = true;
}

