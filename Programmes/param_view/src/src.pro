# Fichier g���par le module QMake de KDevelop. 
# -------------------------------------------------- 
# Sous dossier relatif au dossier principal du projet: ./src
# Cible: une application??:  ../bin/param_view

TARGET = ../bin/param_view
UI_DIR = ui
CONFIG += release \
          warn_on \
          qt \
          thread 
TEMPLATE = app 
FORMS += Dlg_ParamView.ui 
HEADERS += CApp.h \
           ../../MedinTuxTools/CGestIni.h \
           C_Dlg_ParamView.h 
SOURCES += main.cpp \
           CApp.cpp \
           ../../MedinTuxTools/CGestIni.cpp \
           C_Dlg_ParamView.cpp 
