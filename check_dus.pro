SOURCES += ComptaMoteurBase.cpp \
main.cpp \
CApp_Dus.cpp \
../compta/Listes.cpp \
 ../compta/Tools.cpp \
 ../../MedinTuxTools/CGestIni.cpp
HEADERS += ComptaMoteurBase.h \
CApp_Dus.h \
../compta/Listes.h \
 ../compta/Tools.h \
 ../../MedinTuxTools/CGestIni.h
TEMPLATE = app


LANGUAGE = C++


TARGET = check_dus

DESTDIR = ../bin/

OBJECTS_DIR = obj
UI_DIR = ui
MOC_DIR = moc



CONFIG += warn_off

CONFIG -= warn_on

