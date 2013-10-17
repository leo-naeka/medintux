/*********************************** C_GoogleAPI.h ************************
* #include "C_GoogleAPI.h"           QT4-ready                            *
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
#ifndef C_GOOGLEAPI_H
#define C_GOOGLEAPI_H

#include <QObject>
#include <QNetworkProxy>
#include "C_GoogleEvent.h"
#include "C_GoogleAuthentification.h"


//=============================== C_GoogleAPI ===============================
/*!
This class represents the  service necessary for accessing the google API.
The necessary documentation for using this
service can be found at Google:
http://code.google.com/intl/en/apis/calendar/data/2.0/reference.html
*/

class C_GoogleAPI : public QObject
{
    Q_OBJECT

    public:
      explicit C_GoogleAPI(QObject *parent = 0);
      virtual ~C_GoogleAPI();

      bool              isServiceAvailable();
      QString           getError();

      bool              login(QString mail, QString password);
      void              configureProxy(QNetworkProxy::ProxyType type, const QString &hostName = QString(), quint16 port = 0, const QString &user = QString(), const QString &password = QString());
      int               getEventsBetweenTwoDates(const QDate &newStartDate, const QDate &newEndDate);
      void              deleteAllEventsBetweenTwoDates(const QDate &newStartDate, const QDate &newEndDate);
      void              createSeveralEvents(const C_GoogleEventList &eventsList);

    signals:
    public slots:
    protected slots:
      virtual void Slot_getSessionDone();
      virtual void Slot_getEventsDone();
      virtual void Slot_createSeveralEventsDone();
      virtual void Slot_deleteEventsDone();
    protected:
      bool                      m_serviceWorking;
      QString                   m_error;
      QString                   m_session;
      QNetworkAccessManager    *m_netAccMan;
      QNetworkReply            *m_reply;
      QEventLoop               *m_loop;
      C_GoogleAuthentification *m_auth;
      bool getSession();
private:
      C_GoogleEventList         m_eventsList;
};

#endif // C_GOOGLEAPI_H

