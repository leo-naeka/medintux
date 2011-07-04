#!/bin/bash
LD_LIBRARY_PATH=/opt/qtsdk-2010.04/lib/qtcreator:
PATH=/opt/qtsdk-2010.04/qt/bin:/usr/bin:/bin:/usr/X11R6/bin/:
QTDIR=/opt/qtsdk-2010.04/qt
QT_PLUGIN_PATH=/opt/qtsdk-2010.04/qt/plugins
PWD=/opt/qtsdk-2010.04/bin
export QT_PLUGIN_PATH
export PWD
export QTDIR
export PATH
export LD_LIBRARY_PATH
qmake Manager.pro
make clean
make
make clean
strip -s ../bin/Manager
