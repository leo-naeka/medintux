 /****************************************************************************
 **
 ** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
 ** Contact: Qt Software Information (qt-info@nokia.com)
 **
 ** This file is part of the example classes of the Qt Toolkit.
 **
 ** $QT_BEGIN_LICENSE:LGPL$
 ** Commercial Usage
 ** Licensees holding valid Qt Commercial licenses may use this file in
 ** accordance with the Qt Commercial License Agreement provided with the
 ** Software or, alternatively, in accordance with the terms contained in
 ** a written agreement between you and Nokia.
 **
 ** GNU Lesser General Public License Usage
 ** Alternatively, this file may be used under the terms of the GNU Lesser
 ** General Public License version 2.1 as published by the Free Software
 ** Foundation and appearing in the file LICENSE.LGPL included in the
 ** packaging of this file.  Please review the following information to
 ** ensure the GNU Lesser General Public License version 2.1 requirements
 ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
 **
 ** In addition, as a special exception, Nokia gives you certain
 ** additional rights. These rights are described in the Nokia Qt LGPL
 ** Exception version 1.0, included in the file LGPL_EXCEPTION.txt in this
 ** package.
 **
 ** GNU General Public License Usage
 ** Alternatively, this file may be used under the terms of the GNU
 ** General Public License version 3.0 as published by the Free Software
 ** Foundation and appearing in the file LICENSE.GPL included in the
 ** packaging of this file.  Please review the following information to
 ** ensure the GNU General Public License version 3.0 requirements will be
 ** met: http://www.gnu.org/copyleft/gpl.html.
 **
 ** If you are unsure which license is appropriate for your use, please
 ** contact the sales department at qt-sales@nokia.com.
 ** $QT_END_LICENSE$
 **
 ****************************************************************************/

 #include "C_QLineEdit.h"
 #include "C_QLineEditPlugin.h"

 #include <QtPlugin>

 C_QLineEditPlugin::C_QLineEditPlugin(QObject *parent)
     : QObject(parent)
 {
     initialized = false;
 }

 void C_QLineEditPlugin::initialize(QDesignerFormEditorInterface * /* core */)
 {
     if (initialized)
         return;

     initialized = true;
 }

 bool C_QLineEditPlugin::isInitialized() const
 {
     return initialized;
 }

 QWidget *C_QLineEditPlugin::createWidget(QWidget *parent)
 {
     return new C_QLineEdit(parent);
 }

 QString C_QLineEditPlugin::name() const
 {
     return "C_QLineEdit";
 }

 QString C_QLineEditPlugin::group() const
 {
     return "Display Widgets [Examples]";
 }

 QIcon C_QLineEditPlugin::icon() const
 {
     return QIcon();
 }

 QString C_QLineEditPlugin::toolTip() const
 {
     return "";
 }

 QString C_QLineEditPlugin::whatsThis() const
 {
     return "";
 }

 bool C_QLineEditPlugin::isContainer() const
 {
     return false;
 }

 QString C_QLineEditPlugin::domXml() const
 {
     return "<widget class=\"C_QLineEdit\" name=\"C_QLineEdit\">\n"
            " <property name=\"geometry\">\n"
            "  <rect>\n"
            "   <x>0</x>\n"
            "   <y>0</y>\n"
            "   <width>100</width>\n"
            "   <height>100</height>\n"
            "  </rect>\n"
            " </property>\n"
            " <property name=\"toolTip\" >\n"
            "  <string>my QLineEdit to use keyPressEvent()</string>\n"
            " </property>\n"
            " <property name=\"whatsThis\" >\n"
            "  <string>my QLineEdit to use keyPressEvent() "
            "for best control</string>\n"
            " </property>\n"
            "</widget>\n";
 }

 QString C_QLineEditPlugin::includeFile() const
 {
     return "../../../MedinTuxTools-QT4/C_QLineEdit/C_QLineEdit.h";
 }

 Q_EXPORT_PLUGIN2(customwidgetplugin, C_QLineEditPlugin)
