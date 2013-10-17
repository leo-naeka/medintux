# Microsoft Developer Studio Project File - Name=" - Win32 Release" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG= - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "param_view.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "param_view.mak" CFG=" - Win32 Release"
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
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD CPP /nologo /MD /W3 /GX /O1 /I "$(QTDIR)\include" /I "." /I "C:\Qt\3.3.4\mkspecs\win32-msvc" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "UNICODE" /D "QT_DLL" /D "QT_THREAD_SUPPORT" /D "QT_NO_DEBUG" /FD -Zm200 /c
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x40c
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /machine:IX86
# ADD LINK32 "qt-mt334.lib" "qtmain.lib" "kernel32.lib" "user32.lib" "gdi32.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "imm32.lib" "winmm.lib" "wsock32.lib" "winspool.lib" "kernel32.lib" "user32.lib" "gdi32.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "imm32.lib" "winmm.lib" "wsock32.lib" "winspool.lib" "opengl32.lib" "glu32.lib" "delayimp.lib" delayimp.lib /nologo /subsystem:windows /machine:IX86 /out:"../bin/param_view.exe" /libpath:"$(QTDIR)\lib" /DELAYLOAD:comdlg32.dll /DELAYLOAD:oleaut32.dll /DELAYLOAD:winmm.dll /DELAYLOAD:wsock32.dll /DELAYLOAD:winspool.dll

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
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD CPP /nologo /MDd /W3 /GX /Zi /Od /I "$(QTDIR)\include" /I "." /I "C:\Qt\3.3.4\mkspecs\win32-msvc" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "UNICODE" /D "QT_DLL" /D "QT_THREAD_SUPPORT" /FD /GZ -Zm200 /c
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x40c
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /machine:IX86
# ADD LINK32 "qt-mt334.lib" "qtmain.lib" "kernel32.lib" "user32.lib" "gdi32.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "imm32.lib" "winmm.lib" "wsock32.lib" "winspool.lib" "kernel32.lib" "user32.lib" "gdi32.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "imm32.lib" "winmm.lib" "wsock32.lib" "winspool.lib" "opengl32.lib" "glu32.lib" "delayimp.lib" /nologo /subsystem:windows /debug /machine:IX86 /out:"../bin/param_view.exe" /pdbtype:sept /libpath:"$(QTDIR)\lib"

!ENDIF 

# Begin Target

# Name " - Win32 Release"
# Name " - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=C_Dlg_ParamView.cpp
# End Source File
# Begin Source File

SOURCE=CApp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CGestIni.cpp
# End Source File
# Begin Source File

SOURCE=main.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=C_Dlg_ParamView.h

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__C_DLG=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing C_Dlg_ParamView.h...
InputPath=C_Dlg_ParamView.h

"moc_C_Dlg_ParamView.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc C_Dlg_ParamView.h -o moc_C_Dlg_ParamView.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__C_DLG=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing C_Dlg_ParamView.h...
InputPath=C_Dlg_ParamView.h

"moc_C_Dlg_ParamView.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc C_Dlg_ParamView.h -o moc_C_Dlg_ParamView.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=CApp.h

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__CAPP_=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing CApp.h...
InputPath=CApp.h

"moc_CApp.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc CApp.h -o moc_CApp.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__CAPP_=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing CApp.h...
InputPath=CApp.h

"moc_CApp.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc CApp.h -o moc_CApp.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CGestIni.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Group "Forms"

# PROP Default_Filter "ui"
# Begin Source File

SOURCE=Dlg_ParamView.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__DLG_P="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing Dlg_ParamView.ui...
InputPath=Dlg_ParamView.ui

BuildCmds= \
	$(QTDIR)\bin\uic Dlg_ParamView.ui -o Dlg_ParamView.h \
	$(QTDIR)\bin\uic Dlg_ParamView.ui -i Dlg_ParamView.h -o Dlg_ParamView.cpp \
	$(QTDIR)\bin\moc  Dlg_ParamView.h -o moc_Dlg_ParamView.cpp \
	

"Dlg_ParamView.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"Dlg_ParamView.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc_Dlg_ParamView.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__DLG_P="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing Dlg_ParamView.ui...
InputPath=Dlg_ParamView.ui

BuildCmds= \
	$(QTDIR)\bin\uic Dlg_ParamView.ui -o Dlg_ParamView.h \
	$(QTDIR)\bin\uic Dlg_ParamView.ui -i Dlg_ParamView.h -o Dlg_ParamView.cpp \
	$(QTDIR)\bin\moc  Dlg_ParamView.h -o moc_Dlg_ParamView.cpp \
	

"Dlg_ParamView.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"Dlg_ParamView.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc_Dlg_ParamView.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Generated"

# PROP Default_Filter ""
# Begin Source File

SOURCE=Dlg_ParamView.cpp
# End Source File
# Begin Source File

SOURCE=Dlg_ParamView.h
# End Source File
# Begin Source File

SOURCE=moc_C_Dlg_ParamView.cpp
# End Source File
# Begin Source File

SOURCE=moc_CApp.cpp
# End Source File
# Begin Source File

SOURCE=moc_Dlg_ParamView.cpp
# End Source File
# End Group
# End Target
# End Project
