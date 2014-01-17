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
# ADD CPP -MD /W3 /I "..\src" /I "$(QTDIR)\include" /I "ui" /I "." /I "..\..\MedinTuxTools" /I "..\..\drtux\src" /I "." /I "moc" /I "C:\Qt3\3.3.4\mkspecs\win32-msvc" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D UNICODE /D FOR_MEDINTUX /D QLIGHTPAD /D QT_DLL /D QT_THREAD_SUPPORT /D "QT_NO_DEBUG" /FD /c -nologo -Zm200 -GX -O1 
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD LINK32  "qt-mt334.lib"  "qtmain.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"  "opengl32.lib"  "glu32.lib"  "delayimp.lib"   /NOLOGO /SUBSYSTEM:windows /LIBPATH:"$(QTDIR)\lib" delayimp.lib /DELAYLOAD:comdlg32.dll /DELAYLOAD:oleaut32.dll /DELAYLOAD:winmm.dll /DELAYLOAD:wsock32.dll /DELAYLOAD:winspool.dll  /out:"../bin/QLightPad.exe


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
# ADD CPP -MDd /W3 /GZ /ZI /Od /I "..\src" /I "$(QTDIR)\include" /I "ui" /I "." /I "..\..\MedinTuxTools" /I "..\..\drtux\src" /I "." /I "moc" /I "C:\Qt3\3.3.4\mkspecs\win32-msvc" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D UNICODE /D FOR_MEDINTUX /D QLIGHTPAD /D QT_DLL /D QT_THREAD_SUPPORT /FD /c -nologo -Zm200 -GX -Zi  
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD LINK32  "qt-mt334.lib"  "qtmain.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"  "opengl32.lib"  "glu32.lib"  "delayimp.lib"   /NOLOGO /SUBSYSTEM:windows /LIBPATH:"$(QTDIR)\lib" /pdbtype:sept /DEBUG  /out:"../bin/QLightPad.exe


!ENDIF 

# Begin Target

# Name " - Win32 Release"
# Name " - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=QLightPad.cpp
# End Source File
# Begin Source File

SOURCE=..\..\drtux\src\C_DlgListFieldMngr.cpp
# End Source File
# Begin Source File

SOURCE=main.cpp
# End Source File
# Begin Source File

SOURCE=MyEditText.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CGenTools.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CHtmlTools.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CCoolPopup.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CW_EditText.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CGestIni.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\ThemePopup.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\Theme.cpp
# End Source File
# Begin Source File

SOURCE=..\..\drtux\src\C_KeyPressEater.cpp
# End Source File
# Begin Source File

SOURCE=CMyTabWidget.cpp
# End Source File
# Begin Source File

SOURCE=DLG_InsertLink.ui.h
# End Source File
# Begin Source File

SOURCE=DLG_InsertAncre.ui.h
# End Source File
# Begin Source File

SOURCE=DLG_InsertEmail.ui.h
# End Source File
# Begin Source File

SOURCE=DLG_Browser.ui.h
# End Source File
# Begin Source File

SOURCE=DLG_BodyAttributs.ui.h
# End Source File
# Begin Source File

SOURCE=DLG_SaveRequest.ui.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\DLG_InsertList.ui.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\DlgListOff_Listes.ui.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\DlgGetString.ui.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\DlgMyMessageBox.ui.h
# End Source File
# Begin Source File

SOURCE=..\..\drtux\src\DlgListFieldMngr.ui.h
# End Source File
# Begin Source File

SOURCE=DLG_A_propos.ui.h
# End Source File

# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=MyEditText.h

USERDEP_MyEditText=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing MyEditText.h...
InputPath=.\MyEditText.h


BuildCmds= \
	$(QTDIR)\bin\moc MyEditText.h -o moc\moc_MyEditText.cpp \

"moc\moc_MyEditText.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing MyEditText.h...
InputPath=.\MyEditText.h


BuildCmds= \
	$(QTDIR)\bin\moc MyEditText.h -o moc\moc_MyEditText.cpp \

"moc\moc_MyEditText.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=QLightPad.h

USERDEP_QLightPad=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing QLightPad.h...
InputPath=.\QLightPad.h


BuildCmds= \
	$(QTDIR)\bin\moc QLightPad.h -o moc\moc_QLightPad.cpp \

"moc\moc_QLightPad.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing QLightPad.h...
InputPath=.\QLightPad.h


BuildCmds= \
	$(QTDIR)\bin\moc QLightPad.h -o moc\moc_QLightPad.cpp \

"moc\moc_QLightPad.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\drtux\src\C_DlgListFieldMngr.h

USERDEP_=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing ..\..\drtux\src\C_DlgListFieldMngr.h...
InputPath=.\..\..\drtux\src\C_DlgListFieldMngr.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\drtux\src\C_DlgListFieldMngr.h -o moc\moc_C_DlgListFieldMngr.cpp \

"moc\moc_C_DlgListFieldMngr.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing ..\..\drtux\src\C_DlgListFieldMngr.h...
InputPath=.\..\..\drtux\src\C_DlgListFieldMngr.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\drtux\src\C_DlgListFieldMngr.h -o moc\moc_C_DlgListFieldMngr.cpp \

"moc\moc_C_DlgListFieldMngr.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CGenTools.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CHtmlTools.h

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

SOURCE=..\..\MedinTuxTools\CW_EditText.h

USERDEP_=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\CW_EditText.h...
InputPath=.\..\..\MedinTuxTools\CW_EditText.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\CW_EditText.h -o moc\moc_CW_EditText.cpp \

"moc\moc_CW_EditText.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\CW_EditText.h...
InputPath=.\..\..\MedinTuxTools\CW_EditText.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\CW_EditText.h -o moc\moc_CW_EditText.cpp \

"moc\moc_CW_EditText.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CGestIni.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CPreview.h

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

SOURCE=..\..\drtux\src\C_KeyPressEater.h

USERDEP_=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing ..\..\drtux\src\C_KeyPressEater.h...
InputPath=.\..\..\drtux\src\C_KeyPressEater.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\drtux\src\C_KeyPressEater.h -o moc\moc_C_KeyPressEater.cpp \

"moc\moc_C_KeyPressEater.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing ..\..\drtux\src\C_KeyPressEater.h...
InputPath=.\..\..\drtux\src\C_KeyPressEater.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\drtux\src\C_KeyPressEater.h -o moc\moc_C_KeyPressEater.cpp \

"moc\moc_C_KeyPressEater.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=CMyTabWidget.h

USERDEP_CMyTabWidget=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing CMyTabWidget.h...
InputPath=.\CMyTabWidget.h


BuildCmds= \
	$(QTDIR)\bin\moc CMyTabWidget.h -o moc\moc_CMyTabWidget.cpp \

"moc\moc_CMyTabWidget.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing CMyTabWidget.h...
InputPath=.\CMyTabWidget.h


BuildCmds= \
	$(QTDIR)\bin\moc CMyTabWidget.h -o moc\moc_CMyTabWidget.cpp \

"moc\moc_CMyTabWidget.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=SaveRequest.h

# End Source File

# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group

# Begin Group "Forms"
# Prop Default_Filter "ui"
# Begin Source File

SOURCE=DLG_InsertLink.ui
USERDEP_DLG_InsertLink.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing DLG_InsertLink.ui...
InputPath=.\DLG_InsertLink.ui

BuildCmds= \
	$(QTDIR)\bin\uic DLG_InsertLink.ui -o ui\DLG_InsertLink.h \
	$(QTDIR)\bin\uic DLG_InsertLink.ui -i DLG_InsertLink.h -o ui\DLG_InsertLink.cpp \
	$(QTDIR)\bin\moc  ui\DLG_InsertLink.h -o moc\moc_DLG_InsertLink.cpp \

"ui\DLG_InsertLink.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DLG_InsertLink.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DLG_InsertLink.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing DLG_InsertLink.ui...
InputPath=.\DLG_InsertLink.ui

BuildCmds= \
	$(QTDIR)\bin\uic DLG_InsertLink.ui -o ui\DLG_InsertLink.h \
	$(QTDIR)\bin\uic DLG_InsertLink.ui -i DLG_InsertLink.h -o ui\DLG_InsertLink.cpp \
	$(QTDIR)\bin\moc  ui\DLG_InsertLink.h -o moc\moc_DLG_InsertLink.cpp \

"ui\DLG_InsertLink.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DLG_InsertLink.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DLG_InsertLink.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=DLG_InsertAncre.ui
USERDEP_DLG_InsertAncre.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing DLG_InsertAncre.ui...
InputPath=.\DLG_InsertAncre.ui

BuildCmds= \
	$(QTDIR)\bin\uic DLG_InsertAncre.ui -o ui\DLG_InsertAncre.h \
	$(QTDIR)\bin\uic DLG_InsertAncre.ui -i DLG_InsertAncre.h -o ui\DLG_InsertAncre.cpp \
	$(QTDIR)\bin\moc  ui\DLG_InsertAncre.h -o moc\moc_DLG_InsertAncre.cpp \

"ui\DLG_InsertAncre.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DLG_InsertAncre.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DLG_InsertAncre.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing DLG_InsertAncre.ui...
InputPath=.\DLG_InsertAncre.ui

BuildCmds= \
	$(QTDIR)\bin\uic DLG_InsertAncre.ui -o ui\DLG_InsertAncre.h \
	$(QTDIR)\bin\uic DLG_InsertAncre.ui -i DLG_InsertAncre.h -o ui\DLG_InsertAncre.cpp \
	$(QTDIR)\bin\moc  ui\DLG_InsertAncre.h -o moc\moc_DLG_InsertAncre.cpp \

"ui\DLG_InsertAncre.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DLG_InsertAncre.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DLG_InsertAncre.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=DLG_InsertEmail.ui
USERDEP_DLG_InsertEmail.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing DLG_InsertEmail.ui...
InputPath=.\DLG_InsertEmail.ui

BuildCmds= \
	$(QTDIR)\bin\uic DLG_InsertEmail.ui -o ui\DLG_InsertEmail.h \
	$(QTDIR)\bin\uic DLG_InsertEmail.ui -i DLG_InsertEmail.h -o ui\DLG_InsertEmail.cpp \
	$(QTDIR)\bin\moc  ui\DLG_InsertEmail.h -o moc\moc_DLG_InsertEmail.cpp \

"ui\DLG_InsertEmail.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DLG_InsertEmail.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DLG_InsertEmail.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing DLG_InsertEmail.ui...
InputPath=.\DLG_InsertEmail.ui

BuildCmds= \
	$(QTDIR)\bin\uic DLG_InsertEmail.ui -o ui\DLG_InsertEmail.h \
	$(QTDIR)\bin\uic DLG_InsertEmail.ui -i DLG_InsertEmail.h -o ui\DLG_InsertEmail.cpp \
	$(QTDIR)\bin\moc  ui\DLG_InsertEmail.h -o moc\moc_DLG_InsertEmail.cpp \

"ui\DLG_InsertEmail.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DLG_InsertEmail.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DLG_InsertEmail.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=DLG_Browser.ui
USERDEP_DLG_Browser.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing DLG_Browser.ui...
InputPath=.\DLG_Browser.ui

BuildCmds= \
	$(QTDIR)\bin\uic DLG_Browser.ui -o ui\DLG_Browser.h \
	$(QTDIR)\bin\uic DLG_Browser.ui -i DLG_Browser.h -o ui\DLG_Browser.cpp \
	$(QTDIR)\bin\moc  ui\DLG_Browser.h -o moc\moc_DLG_Browser.cpp \

"ui\DLG_Browser.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DLG_Browser.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DLG_Browser.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing DLG_Browser.ui...
InputPath=.\DLG_Browser.ui

BuildCmds= \
	$(QTDIR)\bin\uic DLG_Browser.ui -o ui\DLG_Browser.h \
	$(QTDIR)\bin\uic DLG_Browser.ui -i DLG_Browser.h -o ui\DLG_Browser.cpp \
	$(QTDIR)\bin\moc  ui\DLG_Browser.h -o moc\moc_DLG_Browser.cpp \

"ui\DLG_Browser.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DLG_Browser.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DLG_Browser.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=DLG_BodyAttributs.ui
USERDEP_DLG_BodyAttributs.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing DLG_BodyAttributs.ui...
InputPath=.\DLG_BodyAttributs.ui

BuildCmds= \
	$(QTDIR)\bin\uic DLG_BodyAttributs.ui -o ui\DLG_BodyAttributs.h \
	$(QTDIR)\bin\uic DLG_BodyAttributs.ui -i DLG_BodyAttributs.h -o ui\DLG_BodyAttributs.cpp \
	$(QTDIR)\bin\moc  ui\DLG_BodyAttributs.h -o moc\moc_DLG_BodyAttributs.cpp \

"ui\DLG_BodyAttributs.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DLG_BodyAttributs.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DLG_BodyAttributs.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing DLG_BodyAttributs.ui...
InputPath=.\DLG_BodyAttributs.ui

BuildCmds= \
	$(QTDIR)\bin\uic DLG_BodyAttributs.ui -o ui\DLG_BodyAttributs.h \
	$(QTDIR)\bin\uic DLG_BodyAttributs.ui -i DLG_BodyAttributs.h -o ui\DLG_BodyAttributs.cpp \
	$(QTDIR)\bin\moc  ui\DLG_BodyAttributs.h -o moc\moc_DLG_BodyAttributs.cpp \

"ui\DLG_BodyAttributs.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DLG_BodyAttributs.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DLG_BodyAttributs.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=DLG_SaveRequest.ui
USERDEP_DLG_SaveRequest.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing DLG_SaveRequest.ui...
InputPath=.\DLG_SaveRequest.ui

BuildCmds= \
	$(QTDIR)\bin\uic DLG_SaveRequest.ui -o ui\DLG_SaveRequest.h \
	$(QTDIR)\bin\uic DLG_SaveRequest.ui -i DLG_SaveRequest.h -o ui\DLG_SaveRequest.cpp \
	$(QTDIR)\bin\moc  ui\DLG_SaveRequest.h -o moc\moc_DLG_SaveRequest.cpp \

"ui\DLG_SaveRequest.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DLG_SaveRequest.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DLG_SaveRequest.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing DLG_SaveRequest.ui...
InputPath=.\DLG_SaveRequest.ui

BuildCmds= \
	$(QTDIR)\bin\uic DLG_SaveRequest.ui -o ui\DLG_SaveRequest.h \
	$(QTDIR)\bin\uic DLG_SaveRequest.ui -i DLG_SaveRequest.h -o ui\DLG_SaveRequest.cpp \
	$(QTDIR)\bin\moc  ui\DLG_SaveRequest.h -o moc\moc_DLG_SaveRequest.cpp \

"ui\DLG_SaveRequest.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DLG_SaveRequest.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DLG_SaveRequest.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\DLG_InsertList.ui
USERDEP_..\..\MedinTuxTools\DLG_InsertList.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\DLG_InsertList.ui...
InputPath=.\..\..\MedinTuxTools\DLG_InsertList.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DLG_InsertList.ui -o ui\DLG_InsertList.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DLG_InsertList.ui -i DLG_InsertList.h -o ui\DLG_InsertList.cpp \
	$(QTDIR)\bin\moc  ui\DLG_InsertList.h -o moc\moc_DLG_InsertList.cpp \

"ui\DLG_InsertList.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DLG_InsertList.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DLG_InsertList.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\DLG_InsertList.ui...
InputPath=.\..\..\MedinTuxTools\DLG_InsertList.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DLG_InsertList.ui -o ui\DLG_InsertList.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DLG_InsertList.ui -i DLG_InsertList.h -o ui\DLG_InsertList.cpp \
	$(QTDIR)\bin\moc  ui\DLG_InsertList.h -o moc\moc_DLG_InsertList.cpp \

"ui\DLG_InsertList.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DLG_InsertList.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DLG_InsertList.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\DlgListOff_Listes.ui
USERDEP_..\..\MedinTuxTools\DlgListOff_Listes.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\DlgListOff_Listes.ui...
InputPath=.\..\..\MedinTuxTools\DlgListOff_Listes.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgListOff_Listes.ui -o ui\DlgListOff_Listes.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgListOff_Listes.ui -i DlgListOff_Listes.h -o ui\DlgListOff_Listes.cpp \
	$(QTDIR)\bin\moc  ui\DlgListOff_Listes.h -o moc\moc_DlgListOff_Listes.cpp \

"ui\DlgListOff_Listes.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DlgListOff_Listes.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DlgListOff_Listes.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\DlgListOff_Listes.ui...
InputPath=.\..\..\MedinTuxTools\DlgListOff_Listes.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgListOff_Listes.ui -o ui\DlgListOff_Listes.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgListOff_Listes.ui -i DlgListOff_Listes.h -o ui\DlgListOff_Listes.cpp \
	$(QTDIR)\bin\moc  ui\DlgListOff_Listes.h -o moc\moc_DlgListOff_Listes.cpp \

"ui\DlgListOff_Listes.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DlgListOff_Listes.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DlgListOff_Listes.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
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
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgGetString.ui -o ui\DlgGetString.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgGetString.ui -i DlgGetString.h -o ui\DlgGetString.cpp \
	$(QTDIR)\bin\moc  ui\DlgGetString.h -o moc\moc_DlgGetString.cpp \

"ui\DlgGetString.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DlgGetString.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DlgGetString.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\DlgGetString.ui...
InputPath=.\..\..\MedinTuxTools\DlgGetString.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgGetString.ui -o ui\DlgGetString.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgGetString.ui -i DlgGetString.h -o ui\DlgGetString.cpp \
	$(QTDIR)\bin\moc  ui\DlgGetString.h -o moc\moc_DlgGetString.cpp \

"ui\DlgGetString.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DlgGetString.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
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
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgMyMessageBox.ui -o ui\DlgMyMessageBox.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgMyMessageBox.ui -i DlgMyMessageBox.h -o ui\DlgMyMessageBox.cpp \
	$(QTDIR)\bin\moc  ui\DlgMyMessageBox.h -o moc\moc_DlgMyMessageBox.cpp \

"ui\DlgMyMessageBox.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DlgMyMessageBox.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DlgMyMessageBox.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\DlgMyMessageBox.ui...
InputPath=.\..\..\MedinTuxTools\DlgMyMessageBox.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgMyMessageBox.ui -o ui\DlgMyMessageBox.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgMyMessageBox.ui -i DlgMyMessageBox.h -o ui\DlgMyMessageBox.cpp \
	$(QTDIR)\bin\moc  ui\DlgMyMessageBox.h -o moc\moc_DlgMyMessageBox.cpp \

"ui\DlgMyMessageBox.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DlgMyMessageBox.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DlgMyMessageBox.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\drtux\src\DlgListFieldMngr.ui
USERDEP_..\..\drtux\src\DlgListFieldMngr.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing ..\..\drtux\src\DlgListFieldMngr.ui...
InputPath=.\..\..\drtux\src\DlgListFieldMngr.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\drtux\src\DlgListFieldMngr.ui -o ui\DlgListFieldMngr.h \
	$(QTDIR)\bin\uic ..\..\drtux\src\DlgListFieldMngr.ui -i DlgListFieldMngr.h -o ui\DlgListFieldMngr.cpp \
	$(QTDIR)\bin\moc  ui\DlgListFieldMngr.h -o moc\moc_DlgListFieldMngr.cpp \

"ui\DlgListFieldMngr.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DlgListFieldMngr.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DlgListFieldMngr.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing ..\..\drtux\src\DlgListFieldMngr.ui...
InputPath=.\..\..\drtux\src\DlgListFieldMngr.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\drtux\src\DlgListFieldMngr.ui -o ui\DlgListFieldMngr.h \
	$(QTDIR)\bin\uic ..\..\drtux\src\DlgListFieldMngr.ui -i DlgListFieldMngr.h -o ui\DlgListFieldMngr.cpp \
	$(QTDIR)\bin\moc  ui\DlgListFieldMngr.h -o moc\moc_DlgListFieldMngr.cpp \

"ui\DlgListFieldMngr.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DlgListFieldMngr.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DlgListFieldMngr.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=DLG_A_propos.ui
USERDEP_DLG_A_propos.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing DLG_A_propos.ui...
InputPath=.\DLG_A_propos.ui

BuildCmds= \
	$(QTDIR)\bin\uic DLG_A_propos.ui -o ui\DLG_A_propos.h \
	$(QTDIR)\bin\uic DLG_A_propos.ui -i DLG_A_propos.h -o ui\DLG_A_propos.cpp \
	$(QTDIR)\bin\moc  ui\DLG_A_propos.h -o moc\moc_DLG_A_propos.cpp \

"ui\DLG_A_propos.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DLG_A_propos.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DLG_A_propos.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing DLG_A_propos.ui...
InputPath=.\DLG_A_propos.ui

BuildCmds= \
	$(QTDIR)\bin\uic DLG_A_propos.ui -o ui\DLG_A_propos.h \
	$(QTDIR)\bin\uic DLG_A_propos.ui -i DLG_A_propos.h -o ui\DLG_A_propos.cpp \
	$(QTDIR)\bin\moc  ui\DLG_A_propos.h -o moc\moc_DLG_A_propos.cpp \

"ui\DLG_A_propos.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DLG_A_propos.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DLG_A_propos.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File

# End Group

# Begin Group "Translations"
# Prop Default_Filter "ts"
# Begin Source File

SOURCE=QLightPad_fr.ts

# End Source File

# End Group





# Begin Group "Generated"
# Begin Source File

SOURCE=moc\moc_MyEditText.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_QLightPad.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_C_DlgListFieldMngr.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CCoolPopup.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CW_EditText.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_ThemePopup.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_C_KeyPressEater.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CMyTabWidget.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_DLG_InsertLink.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_DLG_InsertAncre.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_DLG_InsertEmail.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_DLG_Browser.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_DLG_BodyAttributs.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_DLG_SaveRequest.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_DLG_InsertList.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_DlgListOff_Listes.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_DlgGetString.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_DlgMyMessageBox.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_DlgListFieldMngr.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_DLG_A_propos.cpp
# End Source File

# Begin Source File

SOURCE=ui\DLG_InsertLink.cpp
# End Source File
# Begin Source File

SOURCE=ui\DLG_InsertAncre.cpp
# End Source File
# Begin Source File

SOURCE=ui\DLG_InsertEmail.cpp
# End Source File
# Begin Source File

SOURCE=ui\DLG_Browser.cpp
# End Source File
# Begin Source File

SOURCE=ui\DLG_BodyAttributs.cpp
# End Source File
# Begin Source File

SOURCE=ui\DLG_SaveRequest.cpp
# End Source File
# Begin Source File

SOURCE=ui\DLG_InsertList.cpp
# End Source File
# Begin Source File

SOURCE=ui\DlgListOff_Listes.cpp
# End Source File
# Begin Source File

SOURCE=ui\DlgGetString.cpp
# End Source File
# Begin Source File

SOURCE=ui\DlgMyMessageBox.cpp
# End Source File
# Begin Source File

SOURCE=ui\DlgListFieldMngr.cpp
# End Source File
# Begin Source File

SOURCE=ui\DLG_A_propos.cpp
# End Source File

# Begin Source File

SOURCE=ui\DLG_InsertLink.h
# End Source File
# Begin Source File

SOURCE=ui\DLG_InsertAncre.h
# End Source File
# Begin Source File

SOURCE=ui\DLG_InsertEmail.h
# End Source File
# Begin Source File

SOURCE=ui\DLG_Browser.h
# End Source File
# Begin Source File

SOURCE=ui\DLG_BodyAttributs.h
# End Source File
# Begin Source File

SOURCE=ui\DLG_SaveRequest.h
# End Source File
# Begin Source File

SOURCE=ui\DLG_InsertList.h
# End Source File
# Begin Source File

SOURCE=ui\DlgListOff_Listes.h
# End Source File
# Begin Source File

SOURCE=ui\DlgGetString.h
# End Source File
# Begin Source File

SOURCE=ui\DlgMyMessageBox.h
# End Source File
# Begin Source File

SOURCE=ui\DlgListFieldMngr.h
# End Source File
# Begin Source File

SOURCE=ui\DLG_A_propos.h
# End Source File




# Prop Default_Filter "moc"
# End Group
# End Target
# End Project

