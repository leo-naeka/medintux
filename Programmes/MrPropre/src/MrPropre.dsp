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
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD CPP -MD /W3 /I "$(QTDIR)\include" /I "." /I "C:\Qt3\3.3.4\mkspecs\win32-msvc" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D UNICODE /D QT_DLL /D QT_THREAD_SUPPORT /D "QT_NO_DEBUG" /FD /c -nologo -Zm200 -GX -O1 
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD LINK32  "qt-mt334.lib"  "qtmain.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"  "opengl32.lib"  "glu32.lib"  "delayimp.lib"   /NOLOGO /SUBSYSTEM:windows /LIBPATH:"$(QTDIR)\lib" delayimp.lib /DELAYLOAD:comdlg32.dll /DELAYLOAD:oleaut32.dll /DELAYLOAD:winmm.dll /DELAYLOAD:wsock32.dll /DELAYLOAD:winspool.dll  /out:"../bin/MrPropre.exe


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
# ADD CPP -MDd /W3 /GZ /ZI /Od /I "$(QTDIR)\include" /I "." /I "C:\Qt3\3.3.4\mkspecs\win32-msvc" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D UNICODE /D QT_DLL /D QT_THREAD_SUPPORT /FD /c -nologo -Zm200 -GX -Zi  
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD LINK32  "qt-mt334.lib"  "qtmain.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"  "opengl32.lib"  "glu32.lib"  "delayimp.lib"   /NOLOGO /SUBSYSTEM:windows /LIBPATH:"$(QTDIR)\lib" /pdbtype:sept /DEBUG  /out:"../bin/MrPropre.exe


!ENDIF 

# Begin Target

# Name " - Win32 Release"
# Name " - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=main.cpp
# End Source File
# Begin Source File

SOURCE=C_Dlg_MainDialog.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CGestIni.cpp
# End Source File

# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=C_Dlg_MainDialog.h

USERDEP_C_Dlg_MainDialog=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing C_Dlg_MainDialog.h...
InputPath=.\C_Dlg_MainDialog.h


BuildCmds= \
	$(QTDIR)\bin\moc C_Dlg_MainDialog.h -o moc_C_Dlg_MainDialog.cpp \

"moc_C_Dlg_MainDialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing C_Dlg_MainDialog.h...
InputPath=.\C_Dlg_MainDialog.h


BuildCmds= \
	$(QTDIR)\bin\moc C_Dlg_MainDialog.h -o moc_C_Dlg_MainDialog.cpp \

"moc_C_Dlg_MainDialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

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
# Prop Default_Filter "ui"
# Begin Source File

SOURCE=Dlg_MainDialog.ui
USERDEP_Dlg_MainDialog.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing Dlg_MainDialog.ui...
InputPath=.\Dlg_MainDialog.ui

BuildCmds= \
	$(QTDIR)\bin\uic Dlg_MainDialog.ui -o Dlg_MainDialog.h \
	$(QTDIR)\bin\uic Dlg_MainDialog.ui -i Dlg_MainDialog.h -o Dlg_MainDialog.cpp \
	$(QTDIR)\bin\moc  Dlg_MainDialog.h -o moc_Dlg_MainDialog.cpp \

"Dlg_MainDialog.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"Dlg_MainDialog.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc_Dlg_MainDialog.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing Dlg_MainDialog.ui...
InputPath=.\Dlg_MainDialog.ui

BuildCmds= \
	$(QTDIR)\bin\uic Dlg_MainDialog.ui -o Dlg_MainDialog.h \
	$(QTDIR)\bin\uic Dlg_MainDialog.ui -i Dlg_MainDialog.h -o Dlg_MainDialog.cpp \
	$(QTDIR)\bin\moc  Dlg_MainDialog.h -o moc_Dlg_MainDialog.cpp \

"Dlg_MainDialog.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"Dlg_MainDialog.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc_Dlg_MainDialog.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File

# End Group






# Begin Group "Generated"
# Begin Source File

SOURCE=moc_C_Dlg_MainDialog.cpp
# End Source File
# Begin Source File

SOURCE=moc_Dlg_MainDialog.cpp
# End Source File

# Begin Source File

SOURCE=Dlg_MainDialog.cpp
# End Source File

# Begin Source File

SOURCE=Dlg_MainDialog.h
# End Source File




# Prop Default_Filter "moc"
# End Group
# End Target
# End Project

