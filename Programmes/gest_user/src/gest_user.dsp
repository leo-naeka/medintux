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
# ADD CPP -MD /W3 /I "..\..\SesamVitale-QT3" /I "..\src" /I "$(QTDIR)\include" /I "..\..\MedinTuxTools" /I "../../MedinTuxTools" /I "." /I "moc" /I "C:\Qt3\3.3.4\mkspecs\win32-msvc" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D _GEST_USER /D SESAMVITALE_VERSION /D QT_DLL /D QT_THREAD_SUPPORT /D "QT_NO_DEBUG" /FD /c -nologo -Zm200 -GX -O1 
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD LINK32  "qt-mt334.lib"  "qtmain.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"  "opengl32.lib"  "glu32.lib"  "delayimp.lib"   /NOLOGO /SUBSYSTEM:windows /LIBPATH:"$(QTDIR)\lib" delayimp.lib /DELAYLOAD:comdlg32.dll /DELAYLOAD:oleaut32.dll /DELAYLOAD:winmm.dll /DELAYLOAD:wsock32.dll /DELAYLOAD:winspool.dll  /out:"../bin/gest_user.exe


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
# ADD CPP -MDd /W3 /GZ /ZI /Od /I "..\..\SesamVitale-QT3" /I "..\src" /I "$(QTDIR)\include" /I "..\..\MedinTuxTools" /I "../../MedinTuxTools" /I "." /I "moc" /I "C:\Qt3\3.3.4\mkspecs\win32-msvc" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D _GEST_USER /D SESAMVITALE_VERSION /D QT_DLL /D QT_THREAD_SUPPORT /FD /c -nologo -Zm200 -GX -Zi  
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD LINK32  "qt-mt334.lib"  "qtmain.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"  "opengl32.lib"  "glu32.lib"  "delayimp.lib"   /NOLOGO /SUBSYSTEM:windows /LIBPATH:"$(QTDIR)\lib" /pdbtype:sept /DEBUG  /out:"../bin/gest_user.exe


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

SOURCE=..\..\SesamVitale-QT3\C_Cps.cpp
# End Source File
# Begin Source File

SOURCE=..\..\SesamVitale-QT3\CSesam_API_InfoGroupe.cpp
# End Source File
# Begin Source File

SOURCE=..\..\SesamVitale-QT3\C_Vitale.cpp
# End Source File
# Begin Source File

SOURCE=gest_user.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CMaskedLineEdit.cpp
# End Source File
# Begin Source File

SOURCE=main.cpp
# End Source File
# Begin Source File

SOURCE=FormOngletRubrique.cpp
# End Source File
# Begin Source File

SOURCE=MyEditText.cpp
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

SOURCE=..\..\drtux\src\CMoteur_Base.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CHtmlTools.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CGestIni.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CSetupBase.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CMedinTuxApp.cpp
# End Source File
# Begin Source File

SOURCE=CApp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\cdlg_passwordget.cpp
# End Source File
# Begin Source File

SOURCE=CDlg_IntervList.cpp
# End Source File
# Begin Source File

SOURCE=DockFormUserList.ui.h
# End Source File
# Begin Source File

SOURCE=DockFormUserListDoc.ui.h
# End Source File
# Begin Source File

SOURCE=RubIdentite.ui.h
# End Source File
# Begin Source File

SOURCE=DlgPassChange.ui.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\DLG_InsertList.ui.h
# End Source File
# Begin Source File

SOURCE=Dlg_PermsUserChoice.ui.h
# End Source File
# Begin Source File

SOURCE=Dlg_PermsDefine.ui.h
# End Source File
# Begin Source File

SOURCE=Dlg_Appartenance.ui.h
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

SOURCE=..\..\SesamVitale-QT3\C_Cps.h

# End Source File
# Begin Source File

SOURCE=..\..\SesamVitale-QT3\CSesam_API_InfoGroupe.h

# End Source File
# Begin Source File

SOURCE=..\..\SesamVitale-QT3\C_Vitale.h

# End Source File
# Begin Source File

SOURCE=gest_user.h

USERDEP_gest_user=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing gest_user.h...
InputPath=.\gest_user.h


BuildCmds= \
	$(QTDIR)\bin\moc gest_user.h -o moc\moc_gest_user.cpp \

"moc\moc_gest_user.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing gest_user.h...
InputPath=.\gest_user.h


BuildCmds= \
	$(QTDIR)\bin\moc gest_user.h -o moc\moc_gest_user.cpp \

"moc\moc_gest_user.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
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

SOURCE=FormOngletRubrique.h

USERDEP_FormOngletRubrique=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing FormOngletRubrique.h...
InputPath=.\FormOngletRubrique.h


BuildCmds= \
	$(QTDIR)\bin\moc FormOngletRubrique.h -o moc\moc_FormOngletRubrique.cpp \

"moc\moc_FormOngletRubrique.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing FormOngletRubrique.h...
InputPath=.\FormOngletRubrique.h


BuildCmds= \
	$(QTDIR)\bin\moc FormOngletRubrique.h -o moc\moc_FormOngletRubrique.cpp \

"moc\moc_FormOngletRubrique.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
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

SOURCE=Rubriques.h

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

SOURCE=..\..\drtux\src\CMoteur_Base.h

USERDEP_=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing ..\..\drtux\src\CMoteur_Base.h...
InputPath=.\..\..\drtux\src\CMoteur_Base.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\drtux\src\CMoteur_Base.h -o moc\moc_CMoteur_Base.cpp \

"moc\moc_CMoteur_Base.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing ..\..\drtux\src\CMoteur_Base.h...
InputPath=.\..\..\drtux\src\CMoteur_Base.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\drtux\src\CMoteur_Base.h -o moc\moc_CMoteur_Base.cpp \

"moc\moc_CMoteur_Base.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CHtmlTools.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CGestIni.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CSetupBase.h

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

SOURCE=..\..\MedinTuxTools\CPreview.h

# End Source File
# Begin Source File

SOURCE=CApp.h

USERDEP_CApp=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing CApp.h...
InputPath=.\CApp.h


BuildCmds= \
	$(QTDIR)\bin\moc CApp.h -o moc\moc_CApp.cpp \

"moc\moc_CApp.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing CApp.h...
InputPath=.\CApp.h


BuildCmds= \
	$(QTDIR)\bin\moc CApp.h -o moc\moc_CApp.cpp \

"moc\moc_CApp.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=DlgPassChangeDefine.h

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

SOURCE=CDlg_IntervList.h

USERDEP_CDlg_IntervList=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing CDlg_IntervList.h...
InputPath=.\CDlg_IntervList.h


BuildCmds= \
	$(QTDIR)\bin\moc CDlg_IntervList.h -o moc\moc_CDlg_IntervList.cpp \

"moc\moc_CDlg_IntervList.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing CDlg_IntervList.h...
InputPath=.\CDlg_IntervList.h


BuildCmds= \
	$(QTDIR)\bin\moc CDlg_IntervList.h -o moc\moc_CDlg_IntervList.cpp \

"moc\moc_CDlg_IntervList.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
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

SOURCE=DockFormUserList.ui
USERDEP_DockFormUserList.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing DockFormUserList.ui...
InputPath=.\DockFormUserList.ui

BuildCmds= \
	$(QTDIR)\bin\uic DockFormUserList.ui -o DockFormUserList.h \
	$(QTDIR)\bin\uic DockFormUserList.ui -i DockFormUserList.h -o DockFormUserList.cpp \
	$(QTDIR)\bin\moc  DockFormUserList.h -o moc\moc_DockFormUserList.cpp \

"DockFormUserList.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"DockFormUserList.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DockFormUserList.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing DockFormUserList.ui...
InputPath=.\DockFormUserList.ui

BuildCmds= \
	$(QTDIR)\bin\uic DockFormUserList.ui -o DockFormUserList.h \
	$(QTDIR)\bin\uic DockFormUserList.ui -i DockFormUserList.h -o DockFormUserList.cpp \
	$(QTDIR)\bin\moc  DockFormUserList.h -o moc\moc_DockFormUserList.cpp \

"DockFormUserList.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"DockFormUserList.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DockFormUserList.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=DockFormUserListDoc.ui
USERDEP_DockFormUserListDoc.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing DockFormUserListDoc.ui...
InputPath=.\DockFormUserListDoc.ui

BuildCmds= \
	$(QTDIR)\bin\uic DockFormUserListDoc.ui -o DockFormUserListDoc.h \
	$(QTDIR)\bin\uic DockFormUserListDoc.ui -i DockFormUserListDoc.h -o DockFormUserListDoc.cpp \
	$(QTDIR)\bin\moc  DockFormUserListDoc.h -o moc\moc_DockFormUserListDoc.cpp \

"DockFormUserListDoc.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"DockFormUserListDoc.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DockFormUserListDoc.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing DockFormUserListDoc.ui...
InputPath=.\DockFormUserListDoc.ui

BuildCmds= \
	$(QTDIR)\bin\uic DockFormUserListDoc.ui -o DockFormUserListDoc.h \
	$(QTDIR)\bin\uic DockFormUserListDoc.ui -i DockFormUserListDoc.h -o DockFormUserListDoc.cpp \
	$(QTDIR)\bin\moc  DockFormUserListDoc.h -o moc\moc_DockFormUserListDoc.cpp \

"DockFormUserListDoc.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"DockFormUserListDoc.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DockFormUserListDoc.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=RubIdentite.ui
USERDEP_RubIdentite.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing RubIdentite.ui...
InputPath=.\RubIdentite.ui

BuildCmds= \
	$(QTDIR)\bin\uic RubIdentite.ui -o RubIdentite.h \
	$(QTDIR)\bin\uic RubIdentite.ui -i RubIdentite.h -o RubIdentite.cpp \
	$(QTDIR)\bin\moc  RubIdentite.h -o moc\moc_RubIdentite.cpp \

"RubIdentite.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"RubIdentite.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_RubIdentite.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing RubIdentite.ui...
InputPath=.\RubIdentite.ui

BuildCmds= \
	$(QTDIR)\bin\uic RubIdentite.ui -o RubIdentite.h \
	$(QTDIR)\bin\uic RubIdentite.ui -i RubIdentite.h -o RubIdentite.cpp \
	$(QTDIR)\bin\moc  RubIdentite.h -o moc\moc_RubIdentite.cpp \

"RubIdentite.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"RubIdentite.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_RubIdentite.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=FormRubOrdo.ui
USERDEP_FormRubOrdo.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing FormRubOrdo.ui...
InputPath=.\FormRubOrdo.ui

BuildCmds= \
	$(QTDIR)\bin\uic FormRubOrdo.ui -o FormRubOrdo.h \
	$(QTDIR)\bin\uic FormRubOrdo.ui -i FormRubOrdo.h -o FormRubOrdo.cpp \
	$(QTDIR)\bin\moc  FormRubOrdo.h -o moc\moc_FormRubOrdo.cpp \

"FormRubOrdo.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"FormRubOrdo.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_FormRubOrdo.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing FormRubOrdo.ui...
InputPath=.\FormRubOrdo.ui

BuildCmds= \
	$(QTDIR)\bin\uic FormRubOrdo.ui -o FormRubOrdo.h \
	$(QTDIR)\bin\uic FormRubOrdo.ui -i FormRubOrdo.h -o FormRubOrdo.cpp \
	$(QTDIR)\bin\moc  FormRubOrdo.h -o moc\moc_FormRubOrdo.cpp \

"FormRubOrdo.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"FormRubOrdo.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_FormRubOrdo.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=FormRubCertificat.ui
USERDEP_FormRubCertificat.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing FormRubCertificat.ui...
InputPath=.\FormRubCertificat.ui

BuildCmds= \
	$(QTDIR)\bin\uic FormRubCertificat.ui -o FormRubCertificat.h \
	$(QTDIR)\bin\uic FormRubCertificat.ui -i FormRubCertificat.h -o FormRubCertificat.cpp \
	$(QTDIR)\bin\moc  FormRubCertificat.h -o moc\moc_FormRubCertificat.cpp \

"FormRubCertificat.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"FormRubCertificat.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_FormRubCertificat.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing FormRubCertificat.ui...
InputPath=.\FormRubCertificat.ui

BuildCmds= \
	$(QTDIR)\bin\uic FormRubCertificat.ui -o FormRubCertificat.h \
	$(QTDIR)\bin\uic FormRubCertificat.ui -i FormRubCertificat.h -o FormRubCertificat.cpp \
	$(QTDIR)\bin\moc  FormRubCertificat.h -o moc\moc_FormRubCertificat.cpp \

"FormRubCertificat.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"FormRubCertificat.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_FormRubCertificat.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=FormRubObservation.ui
USERDEP_FormRubObservation.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing FormRubObservation.ui...
InputPath=.\FormRubObservation.ui

BuildCmds= \
	$(QTDIR)\bin\uic FormRubObservation.ui -o FormRubObservation.h \
	$(QTDIR)\bin\uic FormRubObservation.ui -i FormRubObservation.h -o FormRubObservation.cpp \
	$(QTDIR)\bin\moc  FormRubObservation.h -o moc\moc_FormRubObservation.cpp \

"FormRubObservation.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"FormRubObservation.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_FormRubObservation.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing FormRubObservation.ui...
InputPath=.\FormRubObservation.ui

BuildCmds= \
	$(QTDIR)\bin\uic FormRubObservation.ui -o FormRubObservation.h \
	$(QTDIR)\bin\uic FormRubObservation.ui -i FormRubObservation.h -o FormRubObservation.cpp \
	$(QTDIR)\bin\moc  FormRubObservation.h -o moc\moc_FormRubObservation.cpp \

"FormRubObservation.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"FormRubObservation.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_FormRubObservation.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=FormRubParam.ui
USERDEP_FormRubParam.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing FormRubParam.ui...
InputPath=.\FormRubParam.ui

BuildCmds= \
	$(QTDIR)\bin\uic FormRubParam.ui -o FormRubParam.h \
	$(QTDIR)\bin\uic FormRubParam.ui -i FormRubParam.h -o FormRubParam.cpp \
	$(QTDIR)\bin\moc  FormRubParam.h -o moc\moc_FormRubParam.cpp \

"FormRubParam.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"FormRubParam.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_FormRubParam.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing FormRubParam.ui...
InputPath=.\FormRubParam.ui

BuildCmds= \
	$(QTDIR)\bin\uic FormRubParam.ui -o FormRubParam.h \
	$(QTDIR)\bin\uic FormRubParam.ui -i FormRubParam.h -o FormRubParam.cpp \
	$(QTDIR)\bin\moc  FormRubParam.h -o moc\moc_FormRubParam.cpp \

"FormRubParam.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"FormRubParam.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_FormRubParam.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
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

SOURCE=..\..\MedinTuxTools\DLG_InsertList.ui
USERDEP_..\..\MedinTuxTools\DLG_InsertList.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\DLG_InsertList.ui...
InputPath=.\..\..\MedinTuxTools\DLG_InsertList.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DLG_InsertList.ui -o ..\..\MedinTuxTools\DLG_InsertList.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DLG_InsertList.ui -i DLG_InsertList.h -o ..\..\MedinTuxTools\DLG_InsertList.cpp \
	$(QTDIR)\bin\moc  ..\..\MedinTuxTools\DLG_InsertList.h -o moc\moc_DLG_InsertList.cpp \

"..\..\MedinTuxTools\DLG_InsertList.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"..\..\MedinTuxTools\DLG_InsertList.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DLG_InsertList.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\DLG_InsertList.ui...
InputPath=.\..\..\MedinTuxTools\DLG_InsertList.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DLG_InsertList.ui -o ..\..\MedinTuxTools\DLG_InsertList.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DLG_InsertList.ui -i DLG_InsertList.h -o ..\..\MedinTuxTools\DLG_InsertList.cpp \
	$(QTDIR)\bin\moc  ..\..\MedinTuxTools\DLG_InsertList.h -o moc\moc_DLG_InsertList.cpp \

"..\..\MedinTuxTools\DLG_InsertList.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"..\..\MedinTuxTools\DLG_InsertList.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DLG_InsertList.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=Dlg_PermsUserChoice.ui
USERDEP_Dlg_PermsUserChoice.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing Dlg_PermsUserChoice.ui...
InputPath=.\Dlg_PermsUserChoice.ui

BuildCmds= \
	$(QTDIR)\bin\uic Dlg_PermsUserChoice.ui -o Dlg_PermsUserChoice.h \
	$(QTDIR)\bin\uic Dlg_PermsUserChoice.ui -i Dlg_PermsUserChoice.h -o Dlg_PermsUserChoice.cpp \
	$(QTDIR)\bin\moc  Dlg_PermsUserChoice.h -o moc\moc_Dlg_PermsUserChoice.cpp \

"Dlg_PermsUserChoice.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"Dlg_PermsUserChoice.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_PermsUserChoice.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing Dlg_PermsUserChoice.ui...
InputPath=.\Dlg_PermsUserChoice.ui

BuildCmds= \
	$(QTDIR)\bin\uic Dlg_PermsUserChoice.ui -o Dlg_PermsUserChoice.h \
	$(QTDIR)\bin\uic Dlg_PermsUserChoice.ui -i Dlg_PermsUserChoice.h -o Dlg_PermsUserChoice.cpp \
	$(QTDIR)\bin\moc  Dlg_PermsUserChoice.h -o moc\moc_Dlg_PermsUserChoice.cpp \

"Dlg_PermsUserChoice.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"Dlg_PermsUserChoice.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_PermsUserChoice.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
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

SOURCE=Dlg_PermsDefine.ui
USERDEP_Dlg_PermsDefine.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing Dlg_PermsDefine.ui...
InputPath=.\Dlg_PermsDefine.ui

BuildCmds= \
	$(QTDIR)\bin\uic Dlg_PermsDefine.ui -o Dlg_PermsDefine.h \
	$(QTDIR)\bin\uic Dlg_PermsDefine.ui -i Dlg_PermsDefine.h -o Dlg_PermsDefine.cpp \
	$(QTDIR)\bin\moc  Dlg_PermsDefine.h -o moc\moc_Dlg_PermsDefine.cpp \

"Dlg_PermsDefine.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"Dlg_PermsDefine.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_PermsDefine.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing Dlg_PermsDefine.ui...
InputPath=.\Dlg_PermsDefine.ui

BuildCmds= \
	$(QTDIR)\bin\uic Dlg_PermsDefine.ui -o Dlg_PermsDefine.h \
	$(QTDIR)\bin\uic Dlg_PermsDefine.ui -i Dlg_PermsDefine.h -o Dlg_PermsDefine.cpp \
	$(QTDIR)\bin\moc  Dlg_PermsDefine.h -o moc\moc_Dlg_PermsDefine.cpp \

"Dlg_PermsDefine.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"Dlg_PermsDefine.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_PermsDefine.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=Dlg_Appartenance.ui
USERDEP_Dlg_Appartenance.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing Dlg_Appartenance.ui...
InputPath=.\Dlg_Appartenance.ui

BuildCmds= \
	$(QTDIR)\bin\uic Dlg_Appartenance.ui -o Dlg_Appartenance.h \
	$(QTDIR)\bin\uic Dlg_Appartenance.ui -i Dlg_Appartenance.h -o Dlg_Appartenance.cpp \
	$(QTDIR)\bin\moc  Dlg_Appartenance.h -o moc\moc_Dlg_Appartenance.cpp \

"Dlg_Appartenance.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"Dlg_Appartenance.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_Appartenance.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing Dlg_Appartenance.ui...
InputPath=.\Dlg_Appartenance.ui

BuildCmds= \
	$(QTDIR)\bin\uic Dlg_Appartenance.ui -o Dlg_Appartenance.h \
	$(QTDIR)\bin\uic Dlg_Appartenance.ui -i Dlg_Appartenance.h -o Dlg_Appartenance.cpp \
	$(QTDIR)\bin\moc  Dlg_Appartenance.h -o moc\moc_Dlg_Appartenance.cpp \

"Dlg_Appartenance.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"Dlg_Appartenance.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_Appartenance.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=Dlg_IntervList.ui
USERDEP_Dlg_IntervList.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing Dlg_IntervList.ui...
InputPath=.\Dlg_IntervList.ui

BuildCmds= \
	$(QTDIR)\bin\uic Dlg_IntervList.ui -o Dlg_IntervList.h \
	$(QTDIR)\bin\uic Dlg_IntervList.ui -i Dlg_IntervList.h -o Dlg_IntervList.cpp \
	$(QTDIR)\bin\moc  Dlg_IntervList.h -o moc\moc_Dlg_IntervList.cpp \

"Dlg_IntervList.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"Dlg_IntervList.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_IntervList.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing Dlg_IntervList.ui...
InputPath=.\Dlg_IntervList.ui

BuildCmds= \
	$(QTDIR)\bin\uic Dlg_IntervList.ui -o Dlg_IntervList.h \
	$(QTDIR)\bin\uic Dlg_IntervList.ui -i Dlg_IntervList.h -o Dlg_IntervList.cpp \
	$(QTDIR)\bin\moc  Dlg_IntervList.h -o moc\moc_Dlg_IntervList.cpp \

"Dlg_IntervList.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"Dlg_IntervList.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_IntervList.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File

# End Group

# Begin Group "Translations"
# Prop Default_Filter "ts"
# Begin Source File

SOURCE=gest_user_fr.ts

# End Source File

# End Group





# Begin Group "Generated"
# Begin Source File

SOURCE=moc\moc_qtsingleapplication.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_gest_user.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CMaskedLineEdit.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_FormOngletRubrique.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_MyEditText.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CPrtQListViewItem.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_ThemePopup.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CMoteur_Base.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CMedinTuxApp.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CApp.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_cdlg_passwordget.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CDlg_IntervList.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_DockFormUserList.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_DockFormUserListDoc.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_RubIdentite.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_FormRubOrdo.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_FormRubCertificat.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_FormRubObservation.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_FormRubParam.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_DlgPassChange.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_DLG_InsertList.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_Dlg_PermsUserChoice.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_Dlg_PasswordGet.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_Dlg_PermsDefine.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_Dlg_Appartenance.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_Dlg_IntervList.cpp
# End Source File

# Begin Source File

SOURCE=DockFormUserList.cpp
# End Source File
# Begin Source File

SOURCE=DockFormUserListDoc.cpp
# End Source File
# Begin Source File

SOURCE=RubIdentite.cpp
# End Source File
# Begin Source File

SOURCE=FormRubOrdo.cpp
# End Source File
# Begin Source File

SOURCE=FormRubCertificat.cpp
# End Source File
# Begin Source File

SOURCE=FormRubObservation.cpp
# End Source File
# Begin Source File

SOURCE=FormRubParam.cpp
# End Source File
# Begin Source File

SOURCE=DlgPassChange.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\DLG_InsertList.cpp
# End Source File
# Begin Source File

SOURCE=Dlg_PermsUserChoice.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\Dlg_PasswordGet.cpp
# End Source File
# Begin Source File

SOURCE=Dlg_PermsDefine.cpp
# End Source File
# Begin Source File

SOURCE=Dlg_Appartenance.cpp
# End Source File
# Begin Source File

SOURCE=Dlg_IntervList.cpp
# End Source File

# Begin Source File

SOURCE=DockFormUserList.h
# End Source File
# Begin Source File

SOURCE=DockFormUserListDoc.h
# End Source File
# Begin Source File

SOURCE=RubIdentite.h
# End Source File
# Begin Source File

SOURCE=FormRubOrdo.h
# End Source File
# Begin Source File

SOURCE=FormRubCertificat.h
# End Source File
# Begin Source File

SOURCE=FormRubObservation.h
# End Source File
# Begin Source File

SOURCE=FormRubParam.h
# End Source File
# Begin Source File

SOURCE=DlgPassChange.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\DLG_InsertList.h
# End Source File
# Begin Source File

SOURCE=Dlg_PermsUserChoice.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\Dlg_PasswordGet.h
# End Source File
# Begin Source File

SOURCE=Dlg_PermsDefine.h
# End Source File
# Begin Source File

SOURCE=Dlg_Appartenance.h
# End Source File
# Begin Source File

SOURCE=Dlg_IntervList.h
# End Source File




# Prop Default_Filter "moc"
# End Group
# End Target
# End Project

