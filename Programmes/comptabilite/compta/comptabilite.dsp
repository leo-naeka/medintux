# Microsoft Developer Studio Project File - Name=" - Win32 Debug" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG= - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "comptabilite.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "comptabilite.mak" CFG=" - Win32 Release"
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
# ADD CPP /nologo /MD /W3 /GR /GX /O1 /I "$(QTDIR)\include" /I "ui" /I "g_ui" /I "." /I "moc" /I "C:\Qt\3.3.4\mkspecs\win32-msvc" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "UNICODE" /D "QT_DLL" /D "QT_THREAD_SUPPORT" /D "QT_NO_DEBUG" /FD -Zm200 /c
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x40c
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /machine:IX86
# ADD LINK32 "qt-mt334.lib" "qtmain.lib" "kernel32.lib" "user32.lib" "gdi32.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "imm32.lib" "winmm.lib" "wsock32.lib" "winspool.lib" "kernel32.lib" "user32.lib" "gdi32.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "imm32.lib" "winmm.lib" "wsock32.lib" "winspool.lib" "opengl32.lib" "glu32.lib" "delayimp.lib" delayimp.lib /nologo /subsystem:windows /machine:IX86 /libpath:"$(QTDIR)\lib" /DELAYLOAD:comdlg32.dll /DELAYLOAD:oleaut32.dll /DELAYLOAD:winmm.dll /DELAYLOAD:wsock32.dll /DELAYLOAD:winspool.dll

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
# ADD CPP /nologo /MDd /W3 /GR /GX /Zi /Od /I "$(QTDIR)\include" /I "ui" /I "g_ui" /I "." /I "moc" /I "C:\Qt\3.3.4\mkspecs\win32-msvc" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "UNICODE" /D "QT_DLL" /D "QT_THREAD_SUPPORT" /FD /GZ -Zm200 /c
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x40c
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /machine:IX86
# ADD LINK32 "qt-mt334.lib" "qtmain.lib" "kernel32.lib" "user32.lib" "gdi32.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "imm32.lib" "winmm.lib" "wsock32.lib" "winspool.lib" "kernel32.lib" "user32.lib" "gdi32.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "imm32.lib" "winmm.lib" "wsock32.lib" "winspool.lib" "opengl32.lib" "glu32.lib" "delayimp.lib" /nologo /subsystem:windows /debug /machine:IX86 /pdbtype:sept /libpath:"$(QTDIR)\lib"

!ENDIF 

# Begin Target

# Name " - Win32 Release"
# Name " - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=g_ui\acte_modif.ui.h
# End Source File
# Begin Source File

SOURCE=g_ui\acte_selection.ui.h
# End Source File
# Begin Source File

SOURCE=Actes_ui.cpp
# End Source File
# Begin Source File

SOURCE=g_ui\banque_view.ui.h
# End Source File
# Begin Source File

SOURCE=CApp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CGestIni.cpp
# End Source File
# Begin Source File

SOURCE=CMDI_Actes.cpp
# End Source File
# Begin Source File

SOURCE=CMDI_Cmu.cpp
# End Source File
# Begin Source File

SOURCE=CMDI_Daf.cpp
# End Source File
# Begin Source File

SOURCE=CMDI_Depots.cpp
# End Source File
# Begin Source File

SOURCE=CMDI_Honoraires.cpp
# End Source File
# Begin Source File

SOURCE=CMDI_Livres.cpp
# End Source File
# Begin Source File

SOURCE=CMDI_Mouvements.cpp
# End Source File
# Begin Source File

SOURCE=CMDI_Param.cpp
# End Source File
# Begin Source File

SOURCE=CMDI_Releve.cpp
# End Source File
# Begin Source File

SOURCE=g_ui\cmu_view.ui.h
# End Source File
# Begin Source File

SOURCE=compta.cpp
# End Source File
# Begin Source File

SOURCE=ComptaMoteurBase.cpp
# End Source File
# Begin Source File

SOURCE=g_ui\cpts_add.ui.h
# End Source File
# Begin Source File

SOURCE=g_ui\daf_view.ui.h
# End Source File
# Begin Source File

SOURCE=Depots.cpp
# End Source File
# Begin Source File

SOURCE=g_ui\depots_validation.ui.h
# End Source File
# Begin Source File

SOURCE=EspecesCalculator.cpp
# End Source File
# Begin Source File

SOURCE=g_ui\filtre_hono.ui.h
# End Source File
# Begin Source File

SOURCE=FirstUse.cpp
# End Source File
# Begin Source File

SOURCE=g_ui\FormFirstUse.ui.h
# End Source File
# Begin Source File

SOURCE=g_ui\FormLinkTux.ui.h
# End Source File
# Begin Source File

SOURCE=g_ui\FormListMenu.ui.h
# End Source File
# Begin Source File

SOURCE=g_ui\FormPlugins.ui.h
# End Source File
# Begin Source File

SOURCE=g_ui\FormSelectionUser.ui.h
# End Source File
# Begin Source File

SOURCE=g_ui\hono_view.ui.h
# End Source File
# Begin Source File

SOURCE=g_ui\hono_visualisation.ui.h
# End Source File
# Begin Source File

SOURCE=g_ui\immobilisations_add.ui.h
# End Source File
# Begin Source File

SOURCE=Listes.cpp
# End Source File
# Begin Source File

SOURCE=g_ui\livres.ui.h
# End Source File
# Begin Source File

SOURCE=main.cpp
# End Source File
# Begin Source File

SOURCE=g_ui\mvts_add.ui.h
# End Source File
# Begin Source File

SOURCE=g_ui\mvts_ui.ui.h
# End Source File
# Begin Source File

SOURCE=g_ui\mvts_visualisation.ui.h
# End Source File
# Begin Source File

SOURCE=g_ui\param_view.ui.h
# End Source File
# Begin Source File

SOURCE=Tools.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=g_ui\acte_selection.ui.h
# End Source File
# Begin Source File

SOURCE=Actes_ui.h

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__ACTES=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing Actes_ui.h...
InputPath=Actes_ui.h

"moc\moc_Actes_ui.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc Actes_ui.h -o moc\moc_Actes_ui.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__ACTES=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing Actes_ui.h...
InputPath=Actes_ui.h

"moc\moc_Actes_ui.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc Actes_ui.h -o moc\moc_Actes_ui.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=CApp.h

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__CAPP_=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing CApp.h...
InputPath=CApp.h

"moc\moc_CApp.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc CApp.h -o moc\moc_CApp.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__CAPP_=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing CApp.h...
InputPath=CApp.h

"moc\moc_CApp.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc CApp.h -o moc\moc_CApp.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CGestIni.h
# End Source File
# Begin Source File

SOURCE=CMDI_Actes.h

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__CMDI_=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing CMDI_Actes.h...
InputPath=CMDI_Actes.h

"moc\moc_CMDI_Actes.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc CMDI_Actes.h -o moc\moc_CMDI_Actes.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__CMDI_=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing CMDI_Actes.h...
InputPath=CMDI_Actes.h

"moc\moc_CMDI_Actes.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc CMDI_Actes.h -o moc\moc_CMDI_Actes.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=CMDI_Cmu.h

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__CMDI_C=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing CMDI_Cmu.h...
InputPath=CMDI_Cmu.h

"moc\moc_CMDI_Cmu.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc CMDI_Cmu.h -o moc\moc_CMDI_Cmu.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__CMDI_C=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing CMDI_Cmu.h...
InputPath=CMDI_Cmu.h

"moc\moc_CMDI_Cmu.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc CMDI_Cmu.h -o moc\moc_CMDI_Cmu.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=CMDI_Daf.h

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__CMDI_D=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing CMDI_Daf.h...
InputPath=CMDI_Daf.h

"moc\moc_CMDI_Daf.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc CMDI_Daf.h -o moc\moc_CMDI_Daf.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__CMDI_D=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing CMDI_Daf.h...
InputPath=CMDI_Daf.h

"moc\moc_CMDI_Daf.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc CMDI_Daf.h -o moc\moc_CMDI_Daf.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=CMDI_Depots.h

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__CMDI_DE=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing CMDI_Depots.h...
InputPath=CMDI_Depots.h

"moc\moc_CMDI_Depots.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc CMDI_Depots.h -o moc\moc_CMDI_Depots.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__CMDI_DE=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing CMDI_Depots.h...
InputPath=CMDI_Depots.h

"moc\moc_CMDI_Depots.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc CMDI_Depots.h -o moc\moc_CMDI_Depots.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=CMDI_Generic.h

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__CMDI_G=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing CMDI_Generic.h...
InputPath=CMDI_Generic.h

"moc\moc_CMDI_Generic.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc CMDI_Generic.h -o moc\moc_CMDI_Generic.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__CMDI_G=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing CMDI_Generic.h...
InputPath=CMDI_Generic.h

"moc\moc_CMDI_Generic.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc CMDI_Generic.h -o moc\moc_CMDI_Generic.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=CMDI_Honoraires.h

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__CMDI_H=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing CMDI_Honoraires.h...
InputPath=CMDI_Honoraires.h

"moc\moc_CMDI_Honoraires.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc CMDI_Honoraires.h -o moc\moc_CMDI_Honoraires.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__CMDI_H=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing CMDI_Honoraires.h...
InputPath=CMDI_Honoraires.h

"moc\moc_CMDI_Honoraires.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc CMDI_Honoraires.h -o moc\moc_CMDI_Honoraires.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=CMDI_Livres.h

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__CMDI_L=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing CMDI_Livres.h...
InputPath=CMDI_Livres.h

"moc\moc_CMDI_Livres.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc CMDI_Livres.h -o moc\moc_CMDI_Livres.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__CMDI_L=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing CMDI_Livres.h...
InputPath=CMDI_Livres.h

"moc\moc_CMDI_Livres.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc CMDI_Livres.h -o moc\moc_CMDI_Livres.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=CMDI_Mouvements.h

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__CMDI_M=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing CMDI_Mouvements.h...
InputPath=CMDI_Mouvements.h

"moc\moc_CMDI_Mouvements.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc CMDI_Mouvements.h -o moc\moc_CMDI_Mouvements.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__CMDI_M=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing CMDI_Mouvements.h...
InputPath=CMDI_Mouvements.h

"moc\moc_CMDI_Mouvements.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc CMDI_Mouvements.h -o moc\moc_CMDI_Mouvements.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=CMDI_Param.h

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__CMDI_P=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing CMDI_Param.h...
InputPath=CMDI_Param.h

"moc\moc_CMDI_Param.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc CMDI_Param.h -o moc\moc_CMDI_Param.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__CMDI_P=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing CMDI_Param.h...
InputPath=CMDI_Param.h

"moc\moc_CMDI_Param.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc CMDI_Param.h -o moc\moc_CMDI_Param.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=CMDI_Releve.h

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__CMDI_R=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing CMDI_Releve.h...
InputPath=CMDI_Releve.h

"moc\moc_CMDI_Releve.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc CMDI_Releve.h -o moc\moc_CMDI_Releve.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__CMDI_R=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing CMDI_Releve.h...
InputPath=CMDI_Releve.h

"moc\moc_CMDI_Releve.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc CMDI_Releve.h -o moc\moc_CMDI_Releve.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=g_ui\cmu_view.ui.h
# End Source File
# Begin Source File

SOURCE=compta.h

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__COMPT=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing compta.h...
InputPath=compta.h

"moc\moc_compta.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc compta.h -o moc\moc_compta.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__COMPT=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing compta.h...
InputPath=compta.h

"moc\moc_compta.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc compta.h -o moc\moc_compta.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=ComptaMoteurBase.h
# End Source File
# Begin Source File

SOURCE=g_ui\cpts_add.ui.h
# End Source File
# Begin Source File

SOURCE=g_ui\daf_view.ui.h
# End Source File
# Begin Source File

SOURCE=Defines.h
# End Source File
# Begin Source File

SOURCE=Depots.h

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__DEPOT=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing Depots.h...
InputPath=Depots.h

"moc\moc_Depots.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc Depots.h -o moc\moc_Depots.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__DEPOT=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing Depots.h...
InputPath=Depots.h

"moc\moc_Depots.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc Depots.h -o moc\moc_Depots.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=g_ui\depots_validation.ui.h
# End Source File
# Begin Source File

SOURCE=EspecesCalculator.h

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__ESPEC=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing EspecesCalculator.h...
InputPath=EspecesCalculator.h

"moc\moc_EspecesCalculator.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc EspecesCalculator.h -o moc\moc_EspecesCalculator.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__ESPEC=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing EspecesCalculator.h...
InputPath=EspecesCalculator.h

"moc\moc_EspecesCalculator.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc EspecesCalculator.h -o moc\moc_EspecesCalculator.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=g_ui\filtre_hono.ui.h
# End Source File
# Begin Source File

SOURCE=FirstUse.h

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__FIRST=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing FirstUse.h...
InputPath=FirstUse.h

"moc\moc_FirstUse.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc FirstUse.h -o moc\moc_FirstUse.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__FIRST=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing FirstUse.h...
InputPath=FirstUse.h

"moc\moc_FirstUse.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc FirstUse.h -o moc\moc_FirstUse.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=g_ui\FormFirstUse.ui.h
# End Source File
# Begin Source File

SOURCE=g_ui\FormLinkTux.ui.h
# End Source File
# Begin Source File

SOURCE=g_ui\FormListMenu.ui.h
# End Source File
# Begin Source File

SOURCE=g_ui\FormPlugins.ui.h
# End Source File
# Begin Source File

SOURCE=g_ui\FormSelectionUser.ui.h
# End Source File
# Begin Source File

SOURCE=g_ui\hono_view.ui.h
# End Source File
# Begin Source File

SOURCE=g_ui\hono_visualisation.ui.h
# End Source File
# Begin Source File

SOURCE=icones.h
# End Source File
# Begin Source File

SOURCE=g_ui\immobilisations_add.ui.h
# End Source File
# Begin Source File

SOURCE=Listes.h
# End Source File
# Begin Source File

SOURCE=g_ui\livres.ui.h
# End Source File
# Begin Source File

SOURCE=g_ui\mvts_add.ui.h
# End Source File
# Begin Source File

SOURCE=g_ui\mvts_ui.ui.h
# End Source File
# Begin Source File

SOURCE=g_ui\mvts_visualisation.ui.h
# End Source File
# Begin Source File

SOURCE=Tools.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Group "Forms"

# PROP Default_Filter "ui"
# Begin Source File

SOURCE=g_ui\a_propos.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__A_PRO="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\a_propos.ui...
InputPath=g_ui\a_propos.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\a_propos.ui -o ui\a_propos.h \
	$(QTDIR)\bin\uic g_ui\a_propos.ui -i a_propos.h -o ui\a_propos.cpp \
	$(QTDIR)\bin\moc  ui\a_propos.h -o moc\moc_a_propos.cpp \
	

"ui\a_propos.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\a_propos.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_a_propos.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__A_PRO="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\a_propos.ui...
InputPath=g_ui\a_propos.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\a_propos.ui -o ui\a_propos.h \
	$(QTDIR)\bin\uic g_ui\a_propos.ui -i a_propos.h -o ui\a_propos.cpp \
	$(QTDIR)\bin\moc  ui\a_propos.h -o moc\moc_a_propos.cpp \
	

"ui\a_propos.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\a_propos.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_a_propos.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=g_ui\acte_modif.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__ACTE_="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\acte_modif.ui...
InputPath=g_ui\acte_modif.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\acte_modif.ui -o ui\acte_modif.h \
	$(QTDIR)\bin\uic g_ui\acte_modif.ui -i acte_modif.h -o ui\acte_modif.cpp \
	$(QTDIR)\bin\moc  ui\acte_modif.h -o moc\moc_acte_modif.cpp \
	

"ui\acte_modif.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\acte_modif.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_acte_modif.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__ACTE_="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\acte_modif.ui...
InputPath=g_ui\acte_modif.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\acte_modif.ui -o ui\acte_modif.h \
	$(QTDIR)\bin\uic g_ui\acte_modif.ui -i acte_modif.h -o ui\acte_modif.cpp \
	$(QTDIR)\bin\moc  ui\acte_modif.h -o moc\moc_acte_modif.cpp \
	

"ui\acte_modif.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\acte_modif.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_acte_modif.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=g_ui\acte_selection.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__ACTE_S="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\acte_selection.ui...
InputPath=g_ui\acte_selection.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\acte_selection.ui -o ui\acte_selection.h \
	$(QTDIR)\bin\uic g_ui\acte_selection.ui -i acte_selection.h -o ui\acte_selection.cpp \
	$(QTDIR)\bin\moc  ui\acte_selection.h -o moc\moc_acte_selection.cpp \
	

"ui\acte_selection.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\acte_selection.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_acte_selection.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__ACTE_S="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\acte_selection.ui...
InputPath=g_ui\acte_selection.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\acte_selection.ui -o ui\acte_selection.h \
	$(QTDIR)\bin\uic g_ui\acte_selection.ui -i acte_selection.h -o ui\acte_selection.cpp \
	$(QTDIR)\bin\moc  ui\acte_selection.h -o moc\moc_acte_selection.cpp \
	

"ui\acte_selection.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\acte_selection.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_acte_selection.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=g_ui\banque_view.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__BANQU="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\banque_view.ui...
InputPath=g_ui\banque_view.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\banque_view.ui -o ui\banque_view.h \
	$(QTDIR)\bin\uic g_ui\banque_view.ui -i banque_view.h -o ui\banque_view.cpp \
	$(QTDIR)\bin\moc  ui\banque_view.h -o moc\moc_banque_view.cpp \
	

"ui\banque_view.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\banque_view.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_banque_view.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__BANQU="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\banque_view.ui...
InputPath=g_ui\banque_view.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\banque_view.ui -o ui\banque_view.h \
	$(QTDIR)\bin\uic g_ui\banque_view.ui -i banque_view.h -o ui\banque_view.cpp \
	$(QTDIR)\bin\moc  ui\banque_view.h -o moc\moc_banque_view.cpp \
	

"ui\banque_view.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\banque_view.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_banque_view.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=g_ui\cmu_view.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__CMU_V="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\cmu_view.ui...
InputPath=g_ui\cmu_view.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\cmu_view.ui -o ui\cmu_view.h \
	$(QTDIR)\bin\uic g_ui\cmu_view.ui -i cmu_view.h -o ui\cmu_view.cpp \
	$(QTDIR)\bin\moc  ui\cmu_view.h -o moc\moc_cmu_view.cpp \
	

"ui\cmu_view.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\cmu_view.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_cmu_view.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__CMU_V="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\cmu_view.ui...
InputPath=g_ui\cmu_view.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\cmu_view.ui -o ui\cmu_view.h \
	$(QTDIR)\bin\uic g_ui\cmu_view.ui -i cmu_view.h -o ui\cmu_view.cpp \
	$(QTDIR)\bin\moc  ui\cmu_view.h -o moc\moc_cmu_view.cpp \
	

"ui\cmu_view.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\cmu_view.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_cmu_view.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=g_ui\cpts_add.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__CPTS_="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\cpts_add.ui...
InputPath=g_ui\cpts_add.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\cpts_add.ui -o ui\cpts_add.h \
	$(QTDIR)\bin\uic g_ui\cpts_add.ui -i cpts_add.h -o ui\cpts_add.cpp \
	$(QTDIR)\bin\moc  ui\cpts_add.h -o moc\moc_cpts_add.cpp \
	

"ui\cpts_add.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\cpts_add.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_cpts_add.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__CPTS_="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\cpts_add.ui...
InputPath=g_ui\cpts_add.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\cpts_add.ui -o ui\cpts_add.h \
	$(QTDIR)\bin\uic g_ui\cpts_add.ui -i cpts_add.h -o ui\cpts_add.cpp \
	$(QTDIR)\bin\moc  ui\cpts_add.h -o moc\moc_cpts_add.cpp \
	

"ui\cpts_add.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\cpts_add.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_cpts_add.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=g_ui\daf_view.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__DAF_V="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\daf_view.ui...
InputPath=g_ui\daf_view.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\daf_view.ui -o ui\daf_view.h \
	$(QTDIR)\bin\uic g_ui\daf_view.ui -i daf_view.h -o ui\daf_view.cpp \
	$(QTDIR)\bin\moc  ui\daf_view.h -o moc\moc_daf_view.cpp \
	

"ui\daf_view.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\daf_view.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_daf_view.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__DAF_V="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\daf_view.ui...
InputPath=g_ui\daf_view.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\daf_view.ui -o ui\daf_view.h \
	$(QTDIR)\bin\uic g_ui\daf_view.ui -i daf_view.h -o ui\daf_view.cpp \
	$(QTDIR)\bin\moc  ui\daf_view.h -o moc\moc_daf_view.cpp \
	

"ui\daf_view.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\daf_view.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_daf_view.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=g_ui\depots_validation.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__DEPOTS="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\depots_validation.ui...
InputPath=g_ui\depots_validation.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\depots_validation.ui -o ui\depots_validation.h \
	$(QTDIR)\bin\uic g_ui\depots_validation.ui -i depots_validation.h -o ui\depots_validation.cpp \
	$(QTDIR)\bin\moc  ui\depots_validation.h -o moc\moc_depots_validation.cpp \
	

"ui\depots_validation.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\depots_validation.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_depots_validation.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__DEPOTS="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\depots_validation.ui...
InputPath=g_ui\depots_validation.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\depots_validation.ui -o ui\depots_validation.h \
	$(QTDIR)\bin\uic g_ui\depots_validation.ui -i depots_validation.h -o ui\depots_validation.cpp \
	$(QTDIR)\bin\moc  ui\depots_validation.h -o moc\moc_depots_validation.cpp \
	

"ui\depots_validation.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\depots_validation.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_depots_validation.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=g_ui\Dlg_LoginPass_Medintux.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__DLG_L="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\Dlg_LoginPass_Medintux.ui...
InputPath=g_ui\Dlg_LoginPass_Medintux.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\Dlg_LoginPass_Medintux.ui -o ui\Dlg_LoginPass_Medintux.h \
	$(QTDIR)\bin\uic g_ui\Dlg_LoginPass_Medintux.ui -i Dlg_LoginPass_Medintux.h -o ui\Dlg_LoginPass_Medintux.cpp \
	$(QTDIR)\bin\moc  ui\Dlg_LoginPass_Medintux.h -o moc\moc_Dlg_LoginPass_Medintux.cpp \
	

"ui\Dlg_LoginPass_Medintux.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\Dlg_LoginPass_Medintux.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_Dlg_LoginPass_Medintux.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__DLG_L="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\Dlg_LoginPass_Medintux.ui...
InputPath=g_ui\Dlg_LoginPass_Medintux.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\Dlg_LoginPass_Medintux.ui -o ui\Dlg_LoginPass_Medintux.h \
	$(QTDIR)\bin\uic g_ui\Dlg_LoginPass_Medintux.ui -i Dlg_LoginPass_Medintux.h -o ui\Dlg_LoginPass_Medintux.cpp \
	$(QTDIR)\bin\moc  ui\Dlg_LoginPass_Medintux.h -o moc\moc_Dlg_LoginPass_Medintux.cpp \
	

"ui\Dlg_LoginPass_Medintux.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\Dlg_LoginPass_Medintux.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_Dlg_LoginPass_Medintux.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=g_ui\filtre_hono.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__FILTR="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\filtre_hono.ui...
InputPath=g_ui\filtre_hono.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\filtre_hono.ui -o ui\filtre_hono.h \
	$(QTDIR)\bin\uic g_ui\filtre_hono.ui -i filtre_hono.h -o ui\filtre_hono.cpp \
	$(QTDIR)\bin\moc  ui\filtre_hono.h -o moc\moc_filtre_hono.cpp \
	

"ui\filtre_hono.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\filtre_hono.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_filtre_hono.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__FILTR="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\filtre_hono.ui...
InputPath=g_ui\filtre_hono.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\filtre_hono.ui -o ui\filtre_hono.h \
	$(QTDIR)\bin\uic g_ui\filtre_hono.ui -i filtre_hono.h -o ui\filtre_hono.cpp \
	$(QTDIR)\bin\moc  ui\filtre_hono.h -o moc\moc_filtre_hono.cpp \
	

"ui\filtre_hono.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\filtre_hono.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_filtre_hono.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=g_ui\FormFirstUse.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__FORMF="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\FormFirstUse.ui...
InputPath=g_ui\FormFirstUse.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\FormFirstUse.ui -o ui\FormFirstUse.h \
	$(QTDIR)\bin\uic g_ui\FormFirstUse.ui -i FormFirstUse.h -o ui\FormFirstUse.cpp \
	$(QTDIR)\bin\moc  ui\FormFirstUse.h -o moc\moc_FormFirstUse.cpp \
	

"ui\FormFirstUse.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\FormFirstUse.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_FormFirstUse.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__FORMF="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\FormFirstUse.ui...
InputPath=g_ui\FormFirstUse.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\FormFirstUse.ui -o ui\FormFirstUse.h \
	$(QTDIR)\bin\uic g_ui\FormFirstUse.ui -i FormFirstUse.h -o ui\FormFirstUse.cpp \
	$(QTDIR)\bin\moc  ui\FormFirstUse.h -o moc\moc_FormFirstUse.cpp \
	

"ui\FormFirstUse.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\FormFirstUse.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_FormFirstUse.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=g_ui\FormLinkTux.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__FORML="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\FormLinkTux.ui...
InputPath=g_ui\FormLinkTux.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\FormLinkTux.ui -o ui\FormLinkTux.h \
	$(QTDIR)\bin\uic g_ui\FormLinkTux.ui -i FormLinkTux.h -o ui\FormLinkTux.cpp \
	$(QTDIR)\bin\moc  ui\FormLinkTux.h -o moc\moc_FormLinkTux.cpp \
	

"ui\FormLinkTux.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\FormLinkTux.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_FormLinkTux.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__FORML="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\FormLinkTux.ui...
InputPath=g_ui\FormLinkTux.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\FormLinkTux.ui -o ui\FormLinkTux.h \
	$(QTDIR)\bin\uic g_ui\FormLinkTux.ui -i FormLinkTux.h -o ui\FormLinkTux.cpp \
	$(QTDIR)\bin\moc  ui\FormLinkTux.h -o moc\moc_FormLinkTux.cpp \
	

"ui\FormLinkTux.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\FormLinkTux.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_FormLinkTux.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=g_ui\FormListMenu.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__FORMLI="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\FormListMenu.ui...
InputPath=g_ui\FormListMenu.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\FormListMenu.ui -o ui\FormListMenu.h \
	$(QTDIR)\bin\uic g_ui\FormListMenu.ui -i FormListMenu.h -o ui\FormListMenu.cpp \
	$(QTDIR)\bin\moc  ui\FormListMenu.h -o moc\moc_FormListMenu.cpp \
	

"ui\FormListMenu.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\FormListMenu.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_FormListMenu.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__FORMLI="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\FormListMenu.ui...
InputPath=g_ui\FormListMenu.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\FormListMenu.ui -o ui\FormListMenu.h \
	$(QTDIR)\bin\uic g_ui\FormListMenu.ui -i FormListMenu.h -o ui\FormListMenu.cpp \
	$(QTDIR)\bin\moc  ui\FormListMenu.h -o moc\moc_FormListMenu.cpp \
	

"ui\FormListMenu.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\FormListMenu.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_FormListMenu.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=g_ui\FormPlugins.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__FORMP="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\FormPlugins.ui...
InputPath=g_ui\FormPlugins.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\FormPlugins.ui -o ui\FormPlugins.h \
	$(QTDIR)\bin\uic g_ui\FormPlugins.ui -i FormPlugins.h -o ui\FormPlugins.cpp \
	$(QTDIR)\bin\moc  ui\FormPlugins.h -o moc\moc_FormPlugins.cpp \
	

"ui\FormPlugins.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\FormPlugins.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_FormPlugins.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__FORMP="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\FormPlugins.ui...
InputPath=g_ui\FormPlugins.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\FormPlugins.ui -o ui\FormPlugins.h \
	$(QTDIR)\bin\uic g_ui\FormPlugins.ui -i FormPlugins.h -o ui\FormPlugins.cpp \
	$(QTDIR)\bin\moc  ui\FormPlugins.h -o moc\moc_FormPlugins.cpp \
	

"ui\FormPlugins.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\FormPlugins.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_FormPlugins.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=g_ui\FormSelectionUser.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__FORMS="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\FormSelectionUser.ui...
InputPath=g_ui\FormSelectionUser.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\FormSelectionUser.ui -o ui\FormSelectionUser.h \
	$(QTDIR)\bin\uic g_ui\FormSelectionUser.ui -i FormSelectionUser.h -o ui\FormSelectionUser.cpp \
	$(QTDIR)\bin\moc  ui\FormSelectionUser.h -o moc\moc_FormSelectionUser.cpp \
	

"ui\FormSelectionUser.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\FormSelectionUser.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_FormSelectionUser.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__FORMS="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\FormSelectionUser.ui...
InputPath=g_ui\FormSelectionUser.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\FormSelectionUser.ui -o ui\FormSelectionUser.h \
	$(QTDIR)\bin\uic g_ui\FormSelectionUser.ui -i FormSelectionUser.h -o ui\FormSelectionUser.cpp \
	$(QTDIR)\bin\moc  ui\FormSelectionUser.h -o moc\moc_FormSelectionUser.cpp \
	

"ui\FormSelectionUser.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\FormSelectionUser.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_FormSelectionUser.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=g_ui\hono_view.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__HONO_="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\hono_view.ui...
InputPath=g_ui\hono_view.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\hono_view.ui -o ui\hono_view.h \
	$(QTDIR)\bin\uic g_ui\hono_view.ui -i hono_view.h -o ui\hono_view.cpp \
	$(QTDIR)\bin\moc  ui\hono_view.h -o moc\moc_hono_view.cpp \
	

"ui\hono_view.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\hono_view.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_hono_view.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__HONO_="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\hono_view.ui...
InputPath=g_ui\hono_view.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\hono_view.ui -o ui\hono_view.h \
	$(QTDIR)\bin\uic g_ui\hono_view.ui -i hono_view.h -o ui\hono_view.cpp \
	$(QTDIR)\bin\moc  ui\hono_view.h -o moc\moc_hono_view.cpp \
	

"ui\hono_view.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\hono_view.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_hono_view.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=g_ui\hono_visualisation.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__HONO_V="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\hono_visualisation.ui...
InputPath=g_ui\hono_visualisation.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\hono_visualisation.ui -o ui\hono_visualisation.h \
	$(QTDIR)\bin\uic g_ui\hono_visualisation.ui -i hono_visualisation.h -o ui\hono_visualisation.cpp \
	$(QTDIR)\bin\moc  ui\hono_visualisation.h -o moc\moc_hono_visualisation.cpp \
	

"ui\hono_visualisation.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\hono_visualisation.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_hono_visualisation.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__HONO_V="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\hono_visualisation.ui...
InputPath=g_ui\hono_visualisation.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\hono_visualisation.ui -o ui\hono_visualisation.h \
	$(QTDIR)\bin\uic g_ui\hono_visualisation.ui -i hono_visualisation.h -o ui\hono_visualisation.cpp \
	$(QTDIR)\bin\moc  ui\hono_visualisation.h -o moc\moc_hono_visualisation.cpp \
	

"ui\hono_visualisation.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\hono_visualisation.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_hono_visualisation.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=g_ui\immobilisations_add.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__IMMOB="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\immobilisations_add.ui...
InputPath=g_ui\immobilisations_add.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\immobilisations_add.ui -o ui\immobilisations_add.h \
	$(QTDIR)\bin\uic g_ui\immobilisations_add.ui -i immobilisations_add.h -o ui\immobilisations_add.cpp \
	$(QTDIR)\bin\moc  ui\immobilisations_add.h -o moc\moc_immobilisations_add.cpp \
	

"ui\immobilisations_add.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\immobilisations_add.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_immobilisations_add.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__IMMOB="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\immobilisations_add.ui...
InputPath=g_ui\immobilisations_add.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\immobilisations_add.ui -o ui\immobilisations_add.h \
	$(QTDIR)\bin\uic g_ui\immobilisations_add.ui -i immobilisations_add.h -o ui\immobilisations_add.cpp \
	$(QTDIR)\bin\moc  ui\immobilisations_add.h -o moc\moc_immobilisations_add.cpp \
	

"ui\immobilisations_add.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\immobilisations_add.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_immobilisations_add.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=g_ui\livres.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__LIVRE="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\livres.ui...
InputPath=g_ui\livres.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\livres.ui -o ui\livres.h \
	$(QTDIR)\bin\uic g_ui\livres.ui -i livres.h -o ui\livres.cpp \
	$(QTDIR)\bin\moc  ui\livres.h -o moc\moc_livres.cpp \
	

"ui\livres.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\livres.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_livres.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__LIVRE="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\livres.ui...
InputPath=g_ui\livres.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\livres.ui -o ui\livres.h \
	$(QTDIR)\bin\uic g_ui\livres.ui -i livres.h -o ui\livres.cpp \
	$(QTDIR)\bin\moc  ui\livres.h -o moc\moc_livres.cpp \
	

"ui\livres.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\livres.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_livres.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=g_ui\mvts_add.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__MVTS_="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\mvts_add.ui...
InputPath=g_ui\mvts_add.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\mvts_add.ui -o ui\mvts_add.h \
	$(QTDIR)\bin\uic g_ui\mvts_add.ui -i mvts_add.h -o ui\mvts_add.cpp \
	$(QTDIR)\bin\moc  ui\mvts_add.h -o moc\moc_mvts_add.cpp \
	

"ui\mvts_add.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\mvts_add.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_mvts_add.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__MVTS_="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\mvts_add.ui...
InputPath=g_ui\mvts_add.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\mvts_add.ui -o ui\mvts_add.h \
	$(QTDIR)\bin\uic g_ui\mvts_add.ui -i mvts_add.h -o ui\mvts_add.cpp \
	$(QTDIR)\bin\moc  ui\mvts_add.h -o moc\moc_mvts_add.cpp \
	

"ui\mvts_add.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\mvts_add.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_mvts_add.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=g_ui\mvts_ui.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__MVTS_U="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\mvts_ui.ui...
InputPath=g_ui\mvts_ui.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\mvts_ui.ui -o ui\mvts_ui.h \
	$(QTDIR)\bin\uic g_ui\mvts_ui.ui -i mvts_ui.h -o ui\mvts_ui.cpp \
	$(QTDIR)\bin\moc  ui\mvts_ui.h -o moc\moc_mvts_ui.cpp \
	

"ui\mvts_ui.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\mvts_ui.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_mvts_ui.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__MVTS_U="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\mvts_ui.ui...
InputPath=g_ui\mvts_ui.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\mvts_ui.ui -o ui\mvts_ui.h \
	$(QTDIR)\bin\uic g_ui\mvts_ui.ui -i mvts_ui.h -o ui\mvts_ui.cpp \
	$(QTDIR)\bin\moc  ui\mvts_ui.h -o moc\moc_mvts_ui.cpp \
	

"ui\mvts_ui.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\mvts_ui.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_mvts_ui.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=g_ui\mvts_visualisation.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__MVTS_V="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\mvts_visualisation.ui...
InputPath=g_ui\mvts_visualisation.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\mvts_visualisation.ui -o ui\mvts_visualisation.h \
	$(QTDIR)\bin\uic g_ui\mvts_visualisation.ui -i mvts_visualisation.h -o ui\mvts_visualisation.cpp \
	$(QTDIR)\bin\moc  ui\mvts_visualisation.h -o moc\moc_mvts_visualisation.cpp \
	

"ui\mvts_visualisation.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\mvts_visualisation.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_mvts_visualisation.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__MVTS_V="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\mvts_visualisation.ui...
InputPath=g_ui\mvts_visualisation.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\mvts_visualisation.ui -o ui\mvts_visualisation.h \
	$(QTDIR)\bin\uic g_ui\mvts_visualisation.ui -i mvts_visualisation.h -o ui\mvts_visualisation.cpp \
	$(QTDIR)\bin\moc  ui\mvts_visualisation.h -o moc\moc_mvts_visualisation.cpp \
	

"ui\mvts_visualisation.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\mvts_visualisation.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_mvts_visualisation.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=g_ui\param_view.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__PARAM="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\param_view.ui...
InputPath=g_ui\param_view.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\param_view.ui -o ui\param_view.h \
	$(QTDIR)\bin\uic g_ui\param_view.ui -i param_view.h -o ui\param_view.cpp \
	$(QTDIR)\bin\moc  ui\param_view.h -o moc\moc_param_view.cpp \
	

"ui\param_view.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\param_view.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_param_view.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__PARAM="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing g_ui\param_view.ui...
InputPath=g_ui\param_view.ui

BuildCmds= \
	$(QTDIR)\bin\uic g_ui\param_view.ui -o ui\param_view.h \
	$(QTDIR)\bin\uic g_ui\param_view.ui -i param_view.h -o ui\param_view.cpp \
	$(QTDIR)\bin\moc  ui\param_view.h -o moc\moc_param_view.cpp \
	

"ui\param_view.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ui\param_view.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_param_view.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Translations"

# PROP Default_Filter "ts"
# Begin Source File

SOURCE=fr.ts
# End Source File
# End Group
# Begin Group "Generated"

# PROP Default_Filter ""
# Begin Source File

SOURCE=ui\a_propos.cpp
# End Source File
# Begin Source File

SOURCE=ui\a_propos.h
# End Source File
# Begin Source File

SOURCE=ui\acte_modif.cpp
# End Source File
# Begin Source File

SOURCE=ui\acte_modif.h
# End Source File
# Begin Source File

SOURCE=ui\acte_selection.cpp
# End Source File
# Begin Source File

SOURCE=ui\acte_selection.h
# End Source File
# Begin Source File

SOURCE=ui\banque_view.cpp
# End Source File
# Begin Source File

SOURCE=ui\banque_view.h
# End Source File
# Begin Source File

SOURCE=ui\cmu_view.cpp
# End Source File
# Begin Source File

SOURCE=ui\cmu_view.h
# End Source File
# Begin Source File

SOURCE=ui\cpts_add.cpp
# End Source File
# Begin Source File

SOURCE=ui\cpts_add.h
# End Source File
# Begin Source File

SOURCE=ui\daf_view.cpp
# End Source File
# Begin Source File

SOURCE=ui\daf_view.h
# End Source File
# Begin Source File

SOURCE=ui\depots_validation.cpp
# End Source File
# Begin Source File

SOURCE=ui\depots_validation.h
# End Source File
# Begin Source File

SOURCE=ui\Dlg_LoginPass_Medintux.cpp
# End Source File
# Begin Source File

SOURCE=ui\Dlg_LoginPass_Medintux.h
# End Source File
# Begin Source File

SOURCE=ui\filtre_hono.cpp
# End Source File
# Begin Source File

SOURCE=ui\filtre_hono.h
# End Source File
# Begin Source File

SOURCE=ui\FormFirstUse.cpp
# End Source File
# Begin Source File

SOURCE=ui\FormFirstUse.h
# End Source File
# Begin Source File

SOURCE=ui\FormLinkTux.cpp
# End Source File
# Begin Source File

SOURCE=ui\FormLinkTux.h
# End Source File
# Begin Source File

SOURCE=ui\FormListMenu.cpp
# End Source File
# Begin Source File

SOURCE=ui\FormListMenu.h
# End Source File
# Begin Source File

SOURCE=ui\FormPlugins.cpp
# End Source File
# Begin Source File

SOURCE=ui\FormPlugins.h
# End Source File
# Begin Source File

SOURCE=ui\FormSelectionUser.cpp
# End Source File
# Begin Source File

SOURCE=ui\FormSelectionUser.h
# End Source File
# Begin Source File

SOURCE=ui\hono_view.cpp
# End Source File
# Begin Source File

SOURCE=ui\hono_view.h
# End Source File
# Begin Source File

SOURCE=ui\hono_visualisation.cpp
# End Source File
# Begin Source File

SOURCE=ui\hono_visualisation.h
# End Source File
# Begin Source File

SOURCE=ui\immobilisations_add.cpp
# End Source File
# Begin Source File

SOURCE=ui\immobilisations_add.h
# End Source File
# Begin Source File

SOURCE=ui\livres.cpp
# End Source File
# Begin Source File

SOURCE=ui\livres.h
# End Source File
# Begin Source File

SOURCE=moc\moc_a_propos.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_acte_modif.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_acte_selection.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_Actes_ui.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_banque_view.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CApp.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CMDI_Actes.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CMDI_Cmu.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CMDI_Daf.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CMDI_Depots.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CMDI_Generic.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CMDI_Honoraires.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CMDI_Livres.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CMDI_Mouvements.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CMDI_Param.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CMDI_Releve.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_cmu_view.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_compta.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_cpts_add.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_daf_view.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_Depots.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_depots_validation.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_Dlg_LoginPass_Medintux.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_EspecesCalculator.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_filtre_hono.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_FirstUse.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_FormFirstUse.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_FormLinkTux.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_FormListMenu.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_FormPlugins.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_FormSelectionUser.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_hono_view.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_hono_visualisation.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_immobilisations_add.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_livres.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_mvts_add.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_mvts_ui.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_mvts_visualisation.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_param_view.cpp
# End Source File
# Begin Source File

SOURCE=ui\mvts_add.cpp
# End Source File
# Begin Source File

SOURCE=ui\mvts_add.h
# End Source File
# Begin Source File

SOURCE=ui\mvts_ui.cpp
# End Source File
# Begin Source File

SOURCE=ui\mvts_ui.h
# End Source File
# Begin Source File

SOURCE=ui\mvts_visualisation.cpp
# End Source File
# Begin Source File

SOURCE=ui\mvts_visualisation.h
# End Source File
# Begin Source File

SOURCE=ui\param_view.cpp
# End Source File
# Begin Source File

SOURCE=ui\param_view.h
# End Source File
# End Group
# End Target
# End Project
