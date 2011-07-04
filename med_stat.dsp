# Microsoft Developer Studio Project File - Name="" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86)  Application" 0x0101

CFG= - Win32 Debug
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
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD CPP -MD /W3 /I "..\..\Commercial" /I "$(QTDIR)\include" /I "..\..\MedinTuxTools\Calendar" /I "../../MedinTuxTools/Calendar" /I "..\..\MedinTuxTools" /I "../../MedinTuxTools" /I "." /I "moc" /I "C:\Qt\3.3.4\mkspecs\win32-msvc" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D UNICODE /D COMMERCIAL_VERSION /D QT_DLL /D QT_THREAD_SUPPORT /D "QT_NO_DEBUG" /FD /c -nologo -Zm200 -GX -O1 
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD LINK32  "qt-mt334.lib"  "qtmain.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"  "opengl32.lib"  "glu32.lib"  "delayimp.lib"   /NOLOGO /SUBSYSTEM:windows /LIBPATH:"$(QTDIR)\lib" delayimp.lib /DELAYLOAD:comdlg32.dll /DELAYLOAD:oleaut32.dll /DELAYLOAD:winmm.dll /DELAYLOAD:wsock32.dll /DELAYLOAD:winspool.dll 


!ELSEIF  "$(CFG)" == " - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "obj"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "obj"
# PROP Target_Dir ""
# ADD CPP -MDd /W3 /GZ /ZI /Od /I "..\..\Commercial" /I "$(QTDIR)\include" /I "..\..\MedinTuxTools\Calendar" /I "../../MedinTuxTools/Calendar" /I "..\..\MedinTuxTools" /I "../../MedinTuxTools" /I "." /I "moc" /I "C:\Qt\3.3.4\mkspecs\win32-msvc" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D UNICODE /D COMMERCIAL_VERSION /D QT_DLL /D QT_THREAD_SUPPORT /FD /c -nologo -Zm200 -GX -Zi  
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD LINK32  "qt-mt334.lib"  "qtmain.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"  "opengl32.lib"  "glu32.lib"  "delayimp.lib"   /NOLOGO /SUBSYSTEM:windows /LIBPATH:"$(QTDIR)\lib" /pdbtype:sept /DEBUG 


!ENDIF 

# Begin Target

# Name " - Win32 Release"
# Name " - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\Commercial\qtsingleapplication.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Commercial\qtsingleapplication_win.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Commercial\C_Cps.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Commercial\C_Vitale.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Commercial\CSesam_API_InfoGroupe.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Commercial\C_MUI_App.cpp
# End Source File
# Begin Source File

SOURCE=med_stat.cpp
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

SOURCE=..\..\MedinTuxTools\CGestIni.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CSetupBase.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CGenTools.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CMedicaBase.cpp
# End Source File
# Begin Source File

SOURCE=..\..\drtux\src\CMoteur_Base.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CHtmlTools.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CMaskedLineEdit.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\Calendar\MyDateTable.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\GestRPU.cpp
# End Source File
# Begin Source File

SOURCE=main.cpp
# End Source File
# Begin Source File

SOURCE=CApp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\cdlg_passwordget.cpp
# End Source File
# Begin Source File

SOURCE=CMetaField.cpp
# End Source File
# Begin Source File

SOURCE=CDenombre.cpp
# End Source File
# Begin Source File

SOURCE=CMetaFiltre.cpp
# End Source File
# Begin Source File

SOURCE=CDlg_newclassdenombre.cpp
# End Source File
# Begin Source File

SOURCE=CDlg_MetaFieldDefine.cpp
# End Source File
# Begin Source File

SOURCE=Wdg_User.ui.h
# End Source File
# Begin Source File

SOURCE=Wdg_Central.ui.h
# End Source File
# Begin Source File

SOURCE=DlgPassChange.ui.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\Calendar\Dlg_Calendar.ui.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\DlgGetString.ui.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\DlgMyMessageBox.ui.h
# End Source File
# Begin Source File

SOURCE=Dlg_GetCodePorteur.ui.h
# End Source File
# Begin Source File

SOURCE=Dlg_NewUser.ui.h
# End Source File
# Begin Source File

SOURCE=Dlg_MetaFieldDefine.ui.h
# End Source File

# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\..\Commercial\qtsingleapplication.h

USERDEP_=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing ..\..\Commercial\qtsingleapplication.h...
InputPath=.\..\..\Commercial\qtsingleapplication.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\Commercial\qtsingleapplication.h -o moc\moc_qtsingleapplication.cpp \

"moc\moc_qtsingleapplication.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing ..\..\Commercial\qtsingleapplication.h...
InputPath=.\..\..\Commercial\qtsingleapplication.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\Commercial\qtsingleapplication.h -o moc\moc_qtsingleapplication.cpp \

"moc\moc_qtsingleapplication.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\Commercial\C_Cps.h

# End Source File
# Begin Source File

SOURCE=..\..\Commercial\C_Vitale.h

# End Source File
# Begin Source File

SOURCE=..\..\Commercial\CSesam_API_InfoGroupe.h

# End Source File
# Begin Source File

SOURCE=..\..\Commercial\C_MUI_App.h

USERDEP_=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing ..\..\Commercial\C_MUI_App.h...
InputPath=.\..\..\Commercial\C_MUI_App.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\Commercial\C_MUI_App.h -o moc\moc_C_MUI_App.cpp \

"moc\moc_C_MUI_App.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing ..\..\Commercial\C_MUI_App.h...
InputPath=.\..\..\Commercial\C_MUI_App.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\Commercial\C_MUI_App.h -o moc\moc_C_MUI_App.cpp \

"moc\moc_C_MUI_App.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=med_stat.h

USERDEP_med_stat=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing med_stat.h...
InputPath=.\med_stat.h


BuildCmds= \
	$(QTDIR)\bin\moc med_stat.h -o moc\moc_med_stat.cpp \

"moc\moc_med_stat.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing med_stat.h...
InputPath=.\med_stat.h


BuildCmds= \
	$(QTDIR)\bin\moc med_stat.h -o moc\moc_med_stat.cpp \

"moc\moc_med_stat.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CPrtQListBoxItem.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CPrtQListViewItem.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\ThemePopup.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\Theme.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CGestIni.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CSetupBase.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CGenTools.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CMedicaBase.h

# End Source File
# Begin Source File

SOURCE=..\..\drtux\src\CMoteur_Base.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CHtmlTools.h

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

SOURCE=..\..\MedinTuxTools\GestRPU.h

# End Source File
# Begin Source File

SOURCE=CBigShrinker.h

USERDEP_CBigShrinker=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing CBigShrinker.h...
InputPath=.\CBigShrinker.h


BuildCmds= \
	$(QTDIR)\bin\moc CBigShrinker.h -o moc\moc_CBigShrinker.cpp \

"moc\moc_CBigShrinker.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing CBigShrinker.h...
InputPath=.\CBigShrinker.h


BuildCmds= \
	$(QTDIR)\bin\moc CBigShrinker.h -o moc\moc_CBigShrinker.cpp \

"moc\moc_CBigShrinker.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=CApp.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\cdlg_passwordget.h

USERDEP_=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\cdlg_passwordget.h...
InputPath=.\..\..\MedinTuxTools\cdlg_passwordget.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\cdlg_passwordget.h -o moc\moc_cdlg_passwordget.cpp \

"moc\moc_cdlg_passwordget.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\cdlg_passwordget.h...
InputPath=.\..\..\MedinTuxTools\cdlg_passwordget.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\cdlg_passwordget.h -o moc\moc_cdlg_passwordget.cpp \

"moc\moc_cdlg_passwordget.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=CMetaField.h

# End Source File
# Begin Source File

SOURCE=CDenombre.h

# End Source File
# Begin Source File

SOURCE=CMetaFiltre.h

# End Source File
# Begin Source File

SOURCE=CDlg_newclassdenombre.h

USERDEP_CDlg_newclassdenombre=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing CDlg_newclassdenombre.h...
InputPath=.\CDlg_newclassdenombre.h


BuildCmds= \
	$(QTDIR)\bin\moc CDlg_newclassdenombre.h -o moc\moc_CDlg_newclassdenombre.cpp \

"moc\moc_CDlg_newclassdenombre.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing CDlg_newclassdenombre.h...
InputPath=.\CDlg_newclassdenombre.h


BuildCmds= \
	$(QTDIR)\bin\moc CDlg_newclassdenombre.h -o moc\moc_CDlg_newclassdenombre.cpp \

"moc\moc_CDlg_newclassdenombre.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=CDlg_MetaFieldDefine.h

USERDEP_CDlg_MetaFieldDefine=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing CDlg_MetaFieldDefine.h...
InputPath=.\CDlg_MetaFieldDefine.h


BuildCmds= \
	$(QTDIR)\bin\moc CDlg_MetaFieldDefine.h -o moc\moc_CDlg_MetaFieldDefine.cpp \

"moc\moc_CDlg_MetaFieldDefine.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing CDlg_MetaFieldDefine.h...
InputPath=.\CDlg_MetaFieldDefine.h


BuildCmds= \
	$(QTDIR)\bin\moc CDlg_MetaFieldDefine.h -o moc\moc_CDlg_MetaFieldDefine.cpp \

"moc\moc_CDlg_MetaFieldDefine.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
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

SOURCE=Wdg_Monitor.ui
USERDEP_Wdg_Monitor.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing Wdg_Monitor.ui...
InputPath=.\Wdg_Monitor.ui

BuildCmds= \
	$(QTDIR)\bin\uic Wdg_Monitor.ui -o Wdg_Monitor.h \
	$(QTDIR)\bin\uic Wdg_Monitor.ui -i Wdg_Monitor.h -o Wdg_Monitor.cpp \
	$(QTDIR)\bin\moc  Wdg_Monitor.h -o moc\moc_Wdg_Monitor.cpp \

"Wdg_Monitor.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"Wdg_Monitor.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Wdg_Monitor.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing Wdg_Monitor.ui...
InputPath=.\Wdg_Monitor.ui

BuildCmds= \
	$(QTDIR)\bin\uic Wdg_Monitor.ui -o Wdg_Monitor.h \
	$(QTDIR)\bin\uic Wdg_Monitor.ui -i Wdg_Monitor.h -o Wdg_Monitor.cpp \
	$(QTDIR)\bin\moc  Wdg_Monitor.h -o moc\moc_Wdg_Monitor.cpp \

"Wdg_Monitor.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"Wdg_Monitor.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Wdg_Monitor.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=Wdg_User.ui
USERDEP_Wdg_User.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing Wdg_User.ui...
InputPath=.\Wdg_User.ui

BuildCmds= \
	$(QTDIR)\bin\uic Wdg_User.ui -o Wdg_User.h \
	$(QTDIR)\bin\uic Wdg_User.ui -i Wdg_User.h -o Wdg_User.cpp \
	$(QTDIR)\bin\moc  Wdg_User.h -o moc\moc_Wdg_User.cpp \

"Wdg_User.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"Wdg_User.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Wdg_User.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing Wdg_User.ui...
InputPath=.\Wdg_User.ui

BuildCmds= \
	$(QTDIR)\bin\uic Wdg_User.ui -o Wdg_User.h \
	$(QTDIR)\bin\uic Wdg_User.ui -i Wdg_User.h -o Wdg_User.cpp \
	$(QTDIR)\bin\moc  Wdg_User.h -o moc\moc_Wdg_User.cpp \

"Wdg_User.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"Wdg_User.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Wdg_User.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=Wdg_Central.ui
USERDEP_Wdg_Central.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing Wdg_Central.ui...
InputPath=.\Wdg_Central.ui

BuildCmds= \
	$(QTDIR)\bin\uic Wdg_Central.ui -o Wdg_Central.h \
	$(QTDIR)\bin\uic Wdg_Central.ui -i Wdg_Central.h -o Wdg_Central.cpp \
	$(QTDIR)\bin\moc  Wdg_Central.h -o moc\moc_Wdg_Central.cpp \

"Wdg_Central.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"Wdg_Central.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Wdg_Central.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing Wdg_Central.ui...
InputPath=.\Wdg_Central.ui

BuildCmds= \
	$(QTDIR)\bin\uic Wdg_Central.ui -o Wdg_Central.h \
	$(QTDIR)\bin\uic Wdg_Central.ui -i Wdg_Central.h -o Wdg_Central.cpp \
	$(QTDIR)\bin\moc  Wdg_Central.h -o moc\moc_Wdg_Central.cpp \

"Wdg_Central.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"Wdg_Central.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Wdg_Central.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=DlgPassChange.ui
USERDEP_DlgPassChange.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing DlgPassChange.ui...
InputPath=.\DlgPassChange.ui

BuildCmds= \
	$(QTDIR)\bin\uic DlgPassChange.ui -o DlgPassChange.h \
	$(QTDIR)\bin\uic DlgPassChange.ui -i DlgPassChange.h -o DlgPassChange.cpp \
	$(QTDIR)\bin\moc  DlgPassChange.h -o moc\moc_DlgPassChange.cpp \

"DlgPassChange.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"DlgPassChange.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DlgPassChange.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing DlgPassChange.ui...
InputPath=.\DlgPassChange.ui

BuildCmds= \
	$(QTDIR)\bin\uic DlgPassChange.ui -o DlgPassChange.h \
	$(QTDIR)\bin\uic DlgPassChange.ui -i DlgPassChange.h -o DlgPassChange.cpp \
	$(QTDIR)\bin\moc  DlgPassChange.h -o moc\moc_DlgPassChange.cpp \

"DlgPassChange.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"DlgPassChange.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DlgPassChange.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
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
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\Calendar\Dlg_Calendar.ui -o ..\..\MedinTuxTools\Calendar\Dlg_Calendar.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\Calendar\Dlg_Calendar.ui -i Dlg_Calendar.h -o ..\..\MedinTuxTools\Calendar\Dlg_Calendar.cpp \
	$(QTDIR)\bin\moc  ..\..\MedinTuxTools\Calendar\Dlg_Calendar.h -o moc\moc_Dlg_Calendar.cpp \

"..\..\MedinTuxTools\Calendar\Dlg_Calendar.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"..\..\MedinTuxTools\Calendar\Dlg_Calendar.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_Calendar.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\Calendar\Dlg_Calendar.ui...
InputPath=.\..\..\MedinTuxTools\Calendar\Dlg_Calendar.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\Calendar\Dlg_Calendar.ui -o ..\..\MedinTuxTools\Calendar\Dlg_Calendar.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\Calendar\Dlg_Calendar.ui -i Dlg_Calendar.h -o ..\..\MedinTuxTools\Calendar\Dlg_Calendar.cpp \
	$(QTDIR)\bin\moc  ..\..\MedinTuxTools\Calendar\Dlg_Calendar.h -o moc\moc_Dlg_Calendar.cpp \

"..\..\MedinTuxTools\Calendar\Dlg_Calendar.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"..\..\MedinTuxTools\Calendar\Dlg_Calendar.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_Calendar.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\DlgGetString.ui
USERDEP_..\..\MedinTuxTools\DlgGetString.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\DlgGetString.ui...
InputPath=.\..\..\MedinTuxTools\DlgGetString.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgGetString.ui -o ..\..\MedinTuxTools\DlgGetString.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgGetString.ui -i DlgGetString.h -o ..\..\MedinTuxTools\DlgGetString.cpp \
	$(QTDIR)\bin\moc  ..\..\MedinTuxTools\DlgGetString.h -o moc\moc_DlgGetString.cpp \

"..\..\MedinTuxTools\DlgGetString.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"..\..\MedinTuxTools\DlgGetString.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DlgGetString.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\DlgGetString.ui...
InputPath=.\..\..\MedinTuxTools\DlgGetString.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgGetString.ui -o ..\..\MedinTuxTools\DlgGetString.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgGetString.ui -i DlgGetString.h -o ..\..\MedinTuxTools\DlgGetString.cpp \
	$(QTDIR)\bin\moc  ..\..\MedinTuxTools\DlgGetString.h -o moc\moc_DlgGetString.cpp \

"..\..\MedinTuxTools\DlgGetString.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"..\..\MedinTuxTools\DlgGetString.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DlgGetString.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\DlgMyMessageBox.ui
USERDEP_..\..\MedinTuxTools\DlgMyMessageBox.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\DlgMyMessageBox.ui...
InputPath=.\..\..\MedinTuxTools\DlgMyMessageBox.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgMyMessageBox.ui -o ..\..\MedinTuxTools\DlgMyMessageBox.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgMyMessageBox.ui -i DlgMyMessageBox.h -o ..\..\MedinTuxTools\DlgMyMessageBox.cpp \
	$(QTDIR)\bin\moc  ..\..\MedinTuxTools\DlgMyMessageBox.h -o moc\moc_DlgMyMessageBox.cpp \

"..\..\MedinTuxTools\DlgMyMessageBox.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"..\..\MedinTuxTools\DlgMyMessageBox.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DlgMyMessageBox.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\DlgMyMessageBox.ui...
InputPath=.\..\..\MedinTuxTools\DlgMyMessageBox.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgMyMessageBox.ui -o ..\..\MedinTuxTools\DlgMyMessageBox.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgMyMessageBox.ui -i DlgMyMessageBox.h -o ..\..\MedinTuxTools\DlgMyMessageBox.cpp \
	$(QTDIR)\bin\moc  ..\..\MedinTuxTools\DlgMyMessageBox.h -o moc\moc_DlgMyMessageBox.cpp \

"..\..\MedinTuxTools\DlgMyMessageBox.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"..\..\MedinTuxTools\DlgMyMessageBox.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DlgMyMessageBox.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=Dlg_GetCodePorteur.ui
USERDEP_Dlg_GetCodePorteur.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing Dlg_GetCodePorteur.ui...
InputPath=.\Dlg_GetCodePorteur.ui

BuildCmds= \
	$(QTDIR)\bin\uic Dlg_GetCodePorteur.ui -o Dlg_GetCodePorteur.h \
	$(QTDIR)\bin\uic Dlg_GetCodePorteur.ui -i Dlg_GetCodePorteur.h -o Dlg_GetCodePorteur.cpp \
	$(QTDIR)\bin\moc  Dlg_GetCodePorteur.h -o moc\moc_Dlg_GetCodePorteur.cpp \

"Dlg_GetCodePorteur.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"Dlg_GetCodePorteur.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_GetCodePorteur.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing Dlg_GetCodePorteur.ui...
InputPath=.\Dlg_GetCodePorteur.ui

BuildCmds= \
	$(QTDIR)\bin\uic Dlg_GetCodePorteur.ui -o Dlg_GetCodePorteur.h \
	$(QTDIR)\bin\uic Dlg_GetCodePorteur.ui -i Dlg_GetCodePorteur.h -o Dlg_GetCodePorteur.cpp \
	$(QTDIR)\bin\moc  Dlg_GetCodePorteur.h -o moc\moc_Dlg_GetCodePorteur.cpp \

"Dlg_GetCodePorteur.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"Dlg_GetCodePorteur.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_GetCodePorteur.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=Dlg_NewUser.ui
USERDEP_Dlg_NewUser.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing Dlg_NewUser.ui...
InputPath=.\Dlg_NewUser.ui

BuildCmds= \
	$(QTDIR)\bin\uic Dlg_NewUser.ui -o Dlg_NewUser.h \
	$(QTDIR)\bin\uic Dlg_NewUser.ui -i Dlg_NewUser.h -o Dlg_NewUser.cpp \
	$(QTDIR)\bin\moc  Dlg_NewUser.h -o moc\moc_Dlg_NewUser.cpp \

"Dlg_NewUser.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"Dlg_NewUser.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_NewUser.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing Dlg_NewUser.ui...
InputPath=.\Dlg_NewUser.ui

BuildCmds= \
	$(QTDIR)\bin\uic Dlg_NewUser.ui -o Dlg_NewUser.h \
	$(QTDIR)\bin\uic Dlg_NewUser.ui -i Dlg_NewUser.h -o Dlg_NewUser.cpp \
	$(QTDIR)\bin\moc  Dlg_NewUser.h -o moc\moc_Dlg_NewUser.cpp \

"Dlg_NewUser.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"Dlg_NewUser.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_NewUser.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\Dlg_PasswordGet.ui
USERDEP_..\..\MedinTuxTools\Dlg_PasswordGet.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\Dlg_PasswordGet.ui...
InputPath=.\..\..\MedinTuxTools\Dlg_PasswordGet.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\Dlg_PasswordGet.ui -o ..\..\MedinTuxTools\Dlg_PasswordGet.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\Dlg_PasswordGet.ui -i Dlg_PasswordGet.h -o ..\..\MedinTuxTools\Dlg_PasswordGet.cpp \
	$(QTDIR)\bin\moc  ..\..\MedinTuxTools\Dlg_PasswordGet.h -o moc\moc_Dlg_PasswordGet.cpp \

"..\..\MedinTuxTools\Dlg_PasswordGet.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"..\..\MedinTuxTools\Dlg_PasswordGet.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_PasswordGet.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\Dlg_PasswordGet.ui...
InputPath=.\..\..\MedinTuxTools\Dlg_PasswordGet.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\Dlg_PasswordGet.ui -o ..\..\MedinTuxTools\Dlg_PasswordGet.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\Dlg_PasswordGet.ui -i Dlg_PasswordGet.h -o ..\..\MedinTuxTools\Dlg_PasswordGet.cpp \
	$(QTDIR)\bin\moc  ..\..\MedinTuxTools\Dlg_PasswordGet.h -o moc\moc_Dlg_PasswordGet.cpp \

"..\..\MedinTuxTools\Dlg_PasswordGet.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"..\..\MedinTuxTools\Dlg_PasswordGet.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_PasswordGet.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=Dlg_NewClassDenombre.ui
USERDEP_Dlg_NewClassDenombre.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing Dlg_NewClassDenombre.ui...
InputPath=.\Dlg_NewClassDenombre.ui

BuildCmds= \
	$(QTDIR)\bin\uic Dlg_NewClassDenombre.ui -o Dlg_NewClassDenombre.h \
	$(QTDIR)\bin\uic Dlg_NewClassDenombre.ui -i Dlg_NewClassDenombre.h -o Dlg_NewClassDenombre.cpp \
	$(QTDIR)\bin\moc  Dlg_NewClassDenombre.h -o moc\moc_Dlg_NewClassDenombre.cpp \

"Dlg_NewClassDenombre.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"Dlg_NewClassDenombre.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_NewClassDenombre.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing Dlg_NewClassDenombre.ui...
InputPath=.\Dlg_NewClassDenombre.ui

BuildCmds= \
	$(QTDIR)\bin\uic Dlg_NewClassDenombre.ui -o Dlg_NewClassDenombre.h \
	$(QTDIR)\bin\uic Dlg_NewClassDenombre.ui -i Dlg_NewClassDenombre.h -o Dlg_NewClassDenombre.cpp \
	$(QTDIR)\bin\moc  Dlg_NewClassDenombre.h -o moc\moc_Dlg_NewClassDenombre.cpp \

"Dlg_NewClassDenombre.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"Dlg_NewClassDenombre.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_NewClassDenombre.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=Dlg_MetaFieldDefine.ui
USERDEP_Dlg_MetaFieldDefine.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing Dlg_MetaFieldDefine.ui...
InputPath=.\Dlg_MetaFieldDefine.ui

BuildCmds= \
	$(QTDIR)\bin\uic Dlg_MetaFieldDefine.ui -o Dlg_MetaFieldDefine.h \
	$(QTDIR)\bin\uic Dlg_MetaFieldDefine.ui -i Dlg_MetaFieldDefine.h -o Dlg_MetaFieldDefine.cpp \
	$(QTDIR)\bin\moc  Dlg_MetaFieldDefine.h -o moc\moc_Dlg_MetaFieldDefine.cpp \

"Dlg_MetaFieldDefine.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"Dlg_MetaFieldDefine.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_MetaFieldDefine.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing Dlg_MetaFieldDefine.ui...
InputPath=.\Dlg_MetaFieldDefine.ui

BuildCmds= \
	$(QTDIR)\bin\uic Dlg_MetaFieldDefine.ui -o Dlg_MetaFieldDefine.h \
	$(QTDIR)\bin\uic Dlg_MetaFieldDefine.ui -i Dlg_MetaFieldDefine.h -o Dlg_MetaFieldDefine.cpp \
	$(QTDIR)\bin\moc  Dlg_MetaFieldDefine.h -o moc\moc_Dlg_MetaFieldDefine.cpp \

"Dlg_MetaFieldDefine.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"Dlg_MetaFieldDefine.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_MetaFieldDefine.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File

# End Group

# Begin Group "Translations"
# Prop Default_Filter "ts"
# Begin Source File

SOURCE=med_stat_fr.ts

# End Source File

# End Group





# Begin Group "Generated"
# Begin Source File

SOURCE=moc\moc_qtsingleapplication.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_C_MUI_App.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_med_stat.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CMaskedLineEdit.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_MyDateTable.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CBigShrinker.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_cdlg_passwordget.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CDlg_newclassdenombre.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CDlg_MetaFieldDefine.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_Wdg_Monitor.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_Wdg_User.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_Wdg_Central.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_DlgPassChange.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_Dlg_Calendar.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_DlgGetString.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_DlgMyMessageBox.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_Dlg_GetCodePorteur.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_Dlg_NewUser.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_Dlg_PasswordGet.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_Dlg_NewClassDenombre.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_Dlg_MetaFieldDefine.cpp
# End Source File

# Begin Source File

SOURCE=Wdg_Monitor.cpp
# End Source File
# Begin Source File

SOURCE=Wdg_User.cpp
# End Source File
# Begin Source File

SOURCE=Wdg_Central.cpp
# End Source File
# Begin Source File

SOURCE=DlgPassChange.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\Calendar\Dlg_Calendar.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\DlgGetString.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\DlgMyMessageBox.cpp
# End Source File
# Begin Source File

SOURCE=Dlg_GetCodePorteur.cpp
# End Source File
# Begin Source File

SOURCE=Dlg_NewUser.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\Dlg_PasswordGet.cpp
# End Source File
# Begin Source File

SOURCE=Dlg_NewClassDenombre.cpp
# End Source File
# Begin Source File

SOURCE=Dlg_MetaFieldDefine.cpp
# End Source File

# Begin Source File

SOURCE=Wdg_Monitor.h
# End Source File
# Begin Source File

SOURCE=Wdg_User.h
# End Source File
# Begin Source File

SOURCE=Wdg_Central.h
# End Source File
# Begin Source File

SOURCE=DlgPassChange.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\Calendar\Dlg_Calendar.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\DlgGetString.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\DlgMyMessageBox.h
# End Source File
# Begin Source File

SOURCE=Dlg_GetCodePorteur.h
# End Source File
# Begin Source File

SOURCE=Dlg_NewUser.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\Dlg_PasswordGet.h
# End Source File
# Begin Source File

SOURCE=Dlg_NewClassDenombre.h
# End Source File
# Begin Source File

SOURCE=Dlg_MetaFieldDefine.h
# End Source File




# Prop Default_Filter "moc"
# End Group
# End Target
# End Project

