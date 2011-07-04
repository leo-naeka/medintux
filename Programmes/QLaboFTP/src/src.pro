# Fichier généré par le module QMake de KDevelop. 
# -------------------------------------------------- 
# Sous dossier relatif au dossier principal du projet : ./src
# Cible : une application??:  ../bin/QLaboFTP

exists( ../../SesamVitale-QT3/qtsingleapplication.pri ){
    DEFINES += SESAMVITALE_VERSION
    message( "================== Commercial Licence version ===============" )
    include(../../SesamVitale-QT3/qtsingleapplication.pri)
}
else {    message(   "================== CeCILL Licence version ===================" )
}
message(         "|   QLaboFTP is a MedinTux software by Data Medical Design  |" )
message(         "=============================================================" )


FeuillePrincipale.ui.target = FeuillePrincipale.ui
DlgParamConnexion.ui.target = DlgParamConnexion.ui
MOC_DIR = moc 
OBJECTS_DIR = obj
UI_DIR = ui
TARGET = ../bin/QLaboFTP 
CONFIG += qt \
          thread \
          warn_off
TEMPLATE = app 
FORMS += FeuillePrincipale.ui \
         DlgParamConnexion.ui \
         ../../MedinTuxTools/Calendar/Dlg_Calendar.ui 
TRANSLATIONS += QLaboFTP_fr.ts 
HEADERS += CAnalyse.h \
           MyFtp.h \
           CFtpInfo.h \
           Global.h \
           CPatient.h \
           CExpediteur.h \
           CFtpTools.h \
           CFtp.h \
           ../../MedinTuxTools/CPrtQListBoxItem.h \
           ../../MedinTuxTools/CPrtQListViewItem.h \
           ../../MedinTuxTools/ThemePopup.h \
           ../../MedinTuxTools/Theme.h \
           ../../MedinTuxTools/CMedinTuxApp.h \
           ../../MedinTuxTools/CMaskedLineEdit.h \
           ../../MedinTuxTools/CCoolPopup.h \
           ../../MedinTuxTools/CGestIni.h \
           ../../MedinTuxTools/Calendar/MyDateTable.h \
           ../../MedinTuxTools/Calendar/C_Horloge.h \
           CCheckListThread.h \
           CClickableLed.h 
SOURCES += main.cpp \
           CAnalyse.cpp \
           MyFtp.cpp \
           CFtpInfo.cpp \
           CFtp.cpp \
           CFtpTools.cpp \
           ../../MedinTuxTools/CPrtQListBoxItem.cpp \
           ../../MedinTuxTools/CPrtQListViewItem.cpp \
           ../../MedinTuxTools/ThemePopup.cpp \
           ../../MedinTuxTools/Theme.cpp \
           ../../MedinTuxTools/CMedinTuxApp.cpp \
           ../../MedinTuxTools/CMaskedLineEdit.cpp \
           ../../MedinTuxTools/CCoolPopup.cpp \
           ../../MedinTuxTools/CGestIni.cpp \
           ../../MedinTuxTools/Calendar/MyDateTable.cpp \
           ../../MedinTuxTools/Calendar/C_Horloge.cpp \
           CCheckListThread.cpp \
           CClickableLed.cpp 


