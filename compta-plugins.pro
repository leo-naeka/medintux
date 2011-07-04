TEMPLATE = app

SOURCES += main.cpp \
../../MedinTuxTools/CGestIni.cpp \
../compta/Listes.cpp \
../compta/Tools.cpp \
 CApp_Plug.cpp \
 ComptaMoteurBase.cpp
HEADERS += ../../MedinTuxTools/CGestIni.h \
../compta/Listes.h \
../compta/Tools.h \
../compta/g_ui/acte_selection.ui.h \
../compta/Defines.h \
 CApp_Plug.h \
 ../compta/g_ui/FormPlugins.ui.h \
 ComptaMoteurBase.h
FORMS += ../compta/g_ui/acte_selection.ui \
 ../compta/g_ui/FormPlugins.ui
LANGAGE = C++
CONFIG += release \
qt \
thread \
 warn_off
TARGET = ../bin/compta-plugins

OBJECTS_DIR = obj
UI_DIR = ui
MOC_DIR = moc
CONFIG -= warn_on

