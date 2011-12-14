# -------------------------------------------------
# Project created by QtCreator 2010-06-03T10:21:40
# -------------------------------------------------
QT += network \
      webkit \
      sql

#........... make the binary name and version number available in c++ code using macro definition ................
TARGET       = APropos
NUM_VERS     = 2.14.004

DEFINES	    += "NUM_VERSION=\"\\\"$${NUM_VERS}\\\"\""
DEFINES	    += "NAME_APPLI=\"\\\"$${TARGET}\\\"\""

ROOT_PROJECT = $$PWD/../
SRC_DIR      = $${ROOT_PROJECT}/src/
DESTDIR      = $${ROOT_PROJECT}/bin
TEMPLATE     = app

SOURCES += main.cpp \
    ../../MedinTuxTools-QT4/C_DlgApropos/C_DlgApropos.cpp \
    CApp.cpp \
    ../../MedinTuxTools-QT4/CGestIni.cpp \
    ../../MedinTuxTools-QT4/Theme.cpp
HEADERS += ../../MedinTuxTools-QT4/C_DlgApropos/C_DlgApropos.h \
    CApp.h \
    ../../MedinTuxTools-QT4/Theme.h \
    ../../MedinTuxTools-QT4/CGestIni.h
FORMS       += ../../MedinTuxTools-QT4/C_DlgApropos/C_DlgApropos.ui
OTHER_FILES += ../bin/Ressources/Changements.html \
    android/src/org/kde/necessitas/ministro/IMinistroCallback.aidl \
    android/src/org/kde/necessitas/ministro/IMinistro.aidl \
    android/src/org/kde/necessitas/origo/QtActivity.java \
    android/src/org/kde/necessitas/origo/QtApplication.java \
    android/res/drawable-hdpi/icon.png \
    android/res/drawable-ldpi/icon.png \
    android/res/values-ro/strings.xml \
    android/res/values-rs/strings.xml \
    android/res/drawable/logo.png \
    android/res/drawable/icon.png \
    android/res/values-de/strings.xml \
    android/res/drawable-mdpi/icon.png \
    android/res/values/libs.xml \
    android/res/values/strings.xml \
    android/res/values-id/strings.xml \
    android/res/values-fr/strings.xml \
    android/res/values-et/strings.xml \
    android/res/values-ru/strings.xml \
    android/res/values-pl/strings.xml \
    android/res/values-it/strings.xml \
    android/res/values-ms/strings.xml \
    android/res/values-el/strings.xml \
    android/res/values-fa/strings.xml \
    android/res/values-nl/strings.xml \
    android/res/values-es/strings.xml \
    android/res/values-ja/strings.xml \
    android/res/values-pt-rBR/strings.xml \
    android/res/values-zh-rCN/strings.xml \
    android/res/values-zh-rTW/strings.xml \
    android/res/layout/splash.xml \
    android/res/values-nb/strings.xml \
    android/AndroidManifest.xml

# ......... define building path ..................
unix:OBJECTS_DIR  = $${SRC_DIR}/obj/unix
win32:OBJECTS_DIR = $${SRC_DIR}/obj/win32
mac:OBJECTS_DIR   = $${SRC_DIR}/obj/mac

UI_DIR   = $${SRC_DIR}/ui
MOC_DIR  = $${SRC_DIR}/moc
RCC_DIR  = $${SRC_DIR}/rcc

