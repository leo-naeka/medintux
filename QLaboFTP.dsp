# Microsoft Developer Studio Project File - Name="" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86)  Application" 0x0101

CFG= - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f ".mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f ".mak" CFG=" - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE " - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE " - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == " - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "obj"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "obj"
# PROP Target_Dir ""
# ADD CPP -MD /W3 /I "..\..\SesamVitale-QT3" /I "$(QTDIR)\include" /I "ui" /I "." /I "..\..\MedinTuxTools\Calendar" /I "." /I "moc" /I "C:\Qt3\3.3.4\mkspecs\win32-msvc" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D UNICODE /D SESAMVITALE_VERSION /D QT_DLL /D QT_THREAD_SUPPORT /D "QT_NO_DEBUG" /FD /c -nologo -Zm200 -GX -O1 
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD LINK32  "qt-mt334.lib"  "qtmain.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"  "opengl32.lib"  "glu32.lib"  "delayimp.lib"   /NOLOGO /SUBSYSTEM:windows /LIBPATH:"$(QTDIR)\lib" delayimp.lib /DELAYLOAD:comdlg32.dll /DELAYLOAD:oleaut32.dll /DELAYLOAD:winmm.dll /DELAYLOAD:wsock32.dll /DELAYLOAD:winspool.dll  /out:"../bin/QLaboFTP.exe


!ELSEIF  "$(CFG)" == " - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD CPP -MDd /W3 /GZ /ZI /Od /I "..\..\SesamVitale-QT3" /I "$(QTDIR)\include" /I "ui" /I "." /I "..\..\MedinTuxTools\Calendar" /I "." /I "moc" /I "C:\Qt3\3.3.4\mkspecs\win32-msvc" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D UNICODE /D SESAMVITALE_VERSION /D QT_DLL /D QT_THREAD_SUPPORT /FD /c -nologo -Zm200 -GX -Zi  
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD LINK32  "qt-mt334.lib"  "qtmain.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"  "opengl32.lib"  "glu32.lib"  "delayimp.lib"   /NOLOGO /SUBSYSTEM:windows /LIBPATH:"$(QTDIR)\lib" /pdbtype:sept /DEBUG  /out:"../bin/QLaboFTP.exe


!ENDIF 

# Begin Target

# Name " - Win32 Release"
# Name " - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\SesamVitale-QT3\qtsingleapplication.cpp
# End Source File
# Begin Source File

SOURCE=..\..\SesamVitale-QT3\qtsingleapplication_win.cpp
# End Source File
# Begin Source File

SOURCE=main.cpp
# End Source File
# Begin Source File

SOURCE=CAnalyse.cpp
# End Source File
# Begin Source File

SOURCE=MyFtp.cpp
# End Source File
# Begin Source File

SOURCE=CFtpInfo.cpp
# End Source File
# Begin Source File

SOURCE=CFtp.cpp
# End Source File
# Begin Source File

SOURCE=CFtpTools.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CPrtQListBoxItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CPrtQListViewItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\ThemePopup.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\Theme.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CMedinTuxApp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CMaskedLineEdit.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CCoolPopup.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CGestIni.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\Calendar\MyDateTable.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\Calendar\C_Horloge.cpp
# End Source File
# Begin Source File

SOURCE=CCheckListThread.cpp
# End Source File
# Begin Source File

SOURCE=CClickableLed.cpp
# End Source File
# Begin Source File

SOURCE=FeuillePrincipale.ui.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\Calendar\Dlg_Calendar.ui.h
# End Source File

# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\..\SesamVitale-QT3\qtsingleapplication.h

USERDEP_=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing ..\..\SesamVitale-QT3\qtsingleapplication.h...
InputPath=.\..\..\SesamVitale-QT3\qtsingleapplication.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\SesamVitale-QT3\qtsingleapplication.h -o moc\moc_qtsingleapplication.cpp \

"moc\moc_qtsingleapplication.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing ..\..\SesamVitale-QT3\qtsingleapplication.h...
InputPath=.\..\..\SesamVitale-QT3\qtsingleapplication.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\SesamVitale-QT3\qtsingleapplication.h -o moc\moc_qtsingleapplication.cpp \

"moc\moc_qtsingleapplication.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=CAnalyse.h

USERDEP_CAnalyse=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing CAnalyse.h...
InputPath=.\CAnalyse.h


BuildCmds= \
	$(QTDIR)\bin\moc CAnalyse.h -o moc\moc_CAnalyse.cpp \

"moc\moc_CAnalyse.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing CAnalyse.h...
InputPath=.\CAnalyse.h


BuildCmds= \
	$(QTDIR)\bin\moc CAnalyse.h -o moc\moc_CAnalyse.cpp \

"moc\moc_CAnalyse.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=MyFtp.h

USERDEP_MyFtp=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing MyFtp.h...
InputPath=.\MyFtp.h


BuildCmds= \
	$(QTDIR)\bin\moc MyFtp.h -o moc\moc_MyFtp.cpp \

"moc\moc_MyFtp.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing MyFtp.h...
InputPath=.\MyFtp.h


BuildCmds= \
	$(QTDIR)\bin\moc MyFtp.h -o moc\moc_MyFtp.cpp \

"moc\moc_MyFtp.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=CFtpInfo.h

# End Source File
# Begin Source File

SOURCE=Global.h

# End Source File
# Begin Source File

SOURCE=CPatient.h

# End Source File
# Begin Source File

SOURCE=CExpediteur.h

# End Source File
# Begin Source File

SOURCE=CFtpTools.h

USERDEP_CFtpTools=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing CFtpTools.h...
InputPath=.\CFtpTools.h


BuildCmds= \
	$(QTDIR)\bin\moc CFtpTools.h -o moc\moc_CFtpTools.cpp \

"moc\moc_CFtpTools.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing CFtpTools.h...
InputPath=.\CFtpTools.h


BuildCmds= \
	$(QTDIR)\bin\moc CFtpTools.h -o moc\moc_CFtpTools.cpp \

"moc\moc_CFtpTools.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=CFtp.h

USERDEP_CFtp=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing CFtp.h...
InputPath=.\CFtp.h


BuildCmds= \
	$(QTDIR)\bin\moc CFtp.h -o moc\moc_CFtp.cpp \

"moc\moc_CFtp.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing CFtp.h...
InputPath=.\CFtp.h


BuildCmds= \
	$(QTDIR)\bin\moc CFtp.h -o moc\moc_CFtp.cpp \

"moc\moc_CFtp.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CPrtQListBoxItem.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CPrtQListViewItem.h

USERDEP_=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\CPrtQListViewItem.h...
InputPath=.\..\..\MedinTuxTools\CPrtQListViewItem.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\CPrtQListViewItem.h -o moc\moc_CPrtQListViewItem.cpp \

"moc\moc_CPrtQListViewItem.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\CPrtQListViewItem.h...
InputPath=.\..\..\MedinTuxTools\CPrtQListViewItem.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\CPrtQListViewItem.h -o moc\moc_CPrtQListViewItem.cpp \

"moc\moc_CPrtQListViewItem.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\ThemePopup.h

USERDEP_=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\ThemePopup.h...
InputPath=.\..\..\MedinTuxTools\ThemePopup.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\ThemePopup.h -o moc\moc_ThemePopup.cpp \

"moc\moc_ThemePopup.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\ThemePopup.h...
InputPath=.\..\..\MedinTuxTools\ThemePopup.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\ThemePopup.h -o moc\moc_ThemePopup.cpp \

"moc\moc_ThemePopup.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\Theme.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CMedinTuxApp.h

USERDEP_=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\CMedinTuxApp.h...
InputPath=.\..\..\MedinTuxTools\CMedinTuxApp.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\CMedinTuxApp.h -o moc\moc_CMedinTuxApp.cpp \

"moc\moc_CMedinTuxApp.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\CMedinTuxApp.h...
InputPath=.\..\..\MedinTuxTools\CMedinTuxApp.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\CMedinTuxApp.h -o moc\moc_CMedinTuxApp.cpp \

"moc\moc_CMedinTuxApp.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CMaskedLineEdit.h

USERDEP_=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\CMaskedLineEdit.h...
InputPath=.\..\..\MedinTuxTools\CMaskedLineEdit.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\CMaskedLineEdit.h -o moc\moc_CMaskedLineEdit.cpp \

"moc\moc_CMaskedLineEdit.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\CMaskedLineEdit.h...
InputPath=.\..\..\MedinTuxTools\CMaskedLineEdit.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\CMaskedLineEdit.h -o moc\moc_CMaskedLineEdit.cpp \

"moc\moc_CMaskedLineEdit.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CCoolPopup.h

USERDEP_=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\CCoolPopup.h...
InputPath=.\..\..\MedinTuxTools\CCoolPopup.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\CCoolPopup.h -o moc\moc_CCoolPopup.cpp \

"moc\moc_CCoolPopup.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\CCoolPopup.h...
InputPath=.\..\..\MedinTuxTools\CCoolPopup.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\CCoolPopup.h -o moc\moc_CCoolPopup.cpp \

"moc\moc_CCoolPopup.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CGestIni.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\Calendar\MyDateTable.h

USERDEP_=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\Calendar\MyDateTable.h...
InputPath=.\..\..\MedinTuxTools\Calendar\MyDateTable.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\Calendar\MyDateTable.h -o moc\moc_MyDateTable.cpp \

"moc\moc_MyDateTable.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\Calendar\MyDateTable.h...
InputPath=.\..\..\MedinTuxTools\Calendar\MyDateTable.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\Calendar\MyDateTable.h -o moc\moc_MyDateTable.cpp \

"moc\moc_MyDateTable.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\Calendar\C_Horloge.h

USERDEP_=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\Calendar\C_Horloge.h...
InputPath=.\..\..\MedinTuxTools\Calendar\C_Horloge.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\Calendar\C_Horloge.h -o moc\moc_C_Horloge.cpp \

"moc\moc_C_Horloge.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\Calendar\C_Horloge.h...
InputPath=.\..\..\MedinTuxTools\Calendar\C_Horloge.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\Calendar\C_Horloge.h -o moc\moc_C_Horloge.cpp \

"moc\moc_C_Horloge.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=CCheckListThread.h

# End Source File
# Begin Source File

SOURCE=CClickableLed.h

USERDEP_CClickableLed=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing CClickableLed.h...
InputPath=.\CClickableLed.h


BuildCmds= \
	$(QTDIR)\bin\moc CClickableLed.h -o moc\moc_CClickableLed.cpp \

"moc\moc_CClickableLed.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing CClickableLed.h...
InputPath=.\CClickableLed.h


BuildCmds= \
	$(QTDIR)\bin\moc CClickableLed.h -o moc\moc_CClickableLed.cpp \

"moc\moc_CClickableLed.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File

# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group

# Begin Group "Forms"
# Prop Default_Filter "ui"
# Begin Source File

SOURCE=FeuillePrincipale.ui
USERDEP_FeuillePrincipale.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing FeuillePrincipale.ui...
InputPath=.\FeuillePrincipale.ui

BuildCmds= \
	$(QTDIR)\bin\uic FeuillePrincipale.ui -o ui\FeuillePrincipale.h \
	$(QTDIR)\bin\uic FeuillePrincipale.ui -i FeuillePrincipale.h -o ui\FeuillePrincipale.cpp \
	$(QTDIR)\bin\moc  ui\FeuillePrincipale.h -o moc\moc_FeuillePrincipale.cpp \

"ui\FeuillePrincipale.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\FeuillePrincipale.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_FeuillePrincipale.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing FeuillePrincipale.ui...
InputPath=.\FeuillePrincipale.ui

BuildCmds= \
	$(QTDIR)\bin\uic FeuillePrincipale.ui -o ui\FeuillePrincipale.h \
	$(QTDIR)\bin\uic FeuillePrincipale.ui -i FeuillePrincipale.h -o ui\FeuillePrincipale.cpp \
	$(QTDIR)\bin\moc  ui\FeuillePrincipale.h -o moc\moc_FeuillePrincipale.cpp \

"ui\FeuillePrincipale.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\FeuillePrincipale.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_FeuillePrincipale.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=DlgParamConnexion.ui
USERDEP_DlgParamConnexion.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing DlgParamConnexion.ui...
InputPath=.\DlgParamConnexion.ui

BuildCmds= \
	$(QTDIR)\bin\uic DlgParamConnexion.ui -o ui\DlgParamConnexion.h \
	$(QTDIR)\bin\uic DlgParamConnexion.ui -i DlgParamConnexion.h -o ui\DlgParamConnexion.cpp \
	$(QTDIR)\bin\moc  ui\DlgParamConnexion.h -o moc\moc_DlgParamConnexion.cpp \

"ui\DlgParamConnexion.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DlgParamConnexion.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DlgParamConnexion.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing DlgParamConnexion.ui...
InputPath=.\DlgParamConnexion.ui

BuildCmds= \
	$(QTDIR)\bin\uic DlgParamConnexion.ui -o ui\DlgParamConnexion.h \
	$(QTDIR)\bin\uic DlgParamConnexion.ui -i DlgParamConnexion.h -o ui\DlgParamConnexion.cpp \
	$(QTDIR)\bin\moc  ui\DlgParamConnexion.h -o moc\moc_DlgParamConnexion.cpp \

"ui\DlgParamConnexion.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DlgParamConnexion.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DlgParamConnexion.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\Calendar\Dlg_Calendar.ui
USERDEP_..\..\MedinTuxTools\Calendar\Dlg_Calendar.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\Calendar\Dlg_Calendar.ui...
InputPath=.\..\..\MedinTuxTools\Calendar\Dlg_Calendar.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\Calendar\Dlg_Calendar.ui -o ui\Dlg_Calendar.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\Calendar\Dlg_Calendar.ui -i Dlg_Calendar.h -o ui\Dlg_Calendar.cpp \
	$(QTDIR)\bin\moc  ui\Dlg_Calendar.h -o moc\moc_Dlg_Calendar.cpp \

"ui\Dlg_Calendar.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\Dlg_Calendar.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_Calendar.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\Calendar\Dlg_Calendar.ui...
InputPath=.\..\..\MedinTuxTools\Calendar\Dlg_Calendar.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\Calendar\Dlg_Calendar.ui -o ui\Dlg_Calendar.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\Calendar\Dlg_Calendar.ui -i Dlg_Calendar.h -o ui\Dlg_Calendar.cpp \
	$(QTDIR)\bin\moc  ui\Dlg_Calendar.h -o moc\moc_Dlg_Calendar.cpp \

"ui\Dlg_Calendar.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\Dlg_Calendar.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_Calendar.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File

# End Group

# Begin Group "Translations"
# Prop Default_Filter "ts"
# Begin Source File

SOURCE=QLaboFTP_fr.ts

# End Source File

# End Group





# Begin Group "Generated"
# Begin Source File

SOURCE=moc\moc_qtsingleapplication.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CAnalyse.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_MyFtp.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CFtpTools.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CFtp.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CPrtQListViewItem.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_ThemePopup.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CMedinTuxApp.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CMaskedLineEdit.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CCoolPopup.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_MyDateTable.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_C_Horloge.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CClickableLed.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_FeuillePrincipale.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_DlgParamConnexion.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_Dlg_Calendar.cpp
# End Source File
# Begin Source File

SOURCE=moc\CFtp.moc
USERDEP_moc_CFtp=".\CFtp.cpp" "$(QTDIR)\bin\moc.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing CFtp.cpp...
InputPath=.\moc\CFtp.moc

"moc\CFtp.moc" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc CFtp.cpp -o moc\CFtp.moc

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing CFtp.cpp...
InputPath=.\moc\CFtp.moc

"moc\CFtp.moc" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc CFtp.cpp -o moc\CFtp.moc

# End Custom Build

!ENDIF 

# End Source File

# Begin Source File

SOURCE=ui\FeuillePrincipale.cpp
# End Source File
# Begin Source File

SOURCE=ui\DlgParamConnexion.cpp
# End Source File
# Begin Source File

SOURCE=ui\Dlg_Calendar.cpp
# End Source File

# Begin Source File

SOURCE=ui\FeuillePrincipale.h
# End Source File
# Begin Source File

SOURCE=ui\DlgParamConnexion.h
# End Source File
# Begin Source File

SOURCE=ui\Dlg_Calendar.h
# End Source File




# Prop Default_Filter "moc"
# End Group
# End Target
# End Project

