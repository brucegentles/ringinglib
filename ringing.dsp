# Microsoft Developer Studio Project File - Name="ringing" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=ringing - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE
!MESSAGE NMAKE /f "ringing.mak".
!MESSAGE
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "ringing.mak" CFG="ringing - Win32 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "ringing - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "ringing - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
BSC32=bscmake.exe
LINK32=link.exe

!IF  "$(CFG)" == "ringing - Win32 Release"

# PROP BASE Use_Debug_Libraries 0
# PROP Use_Debug_Libraries 0
# PROP BASE Use_MFC 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release\ringing"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release\ringing"
# PROP Target_Dir ""
# PROP Ignore_Export_Lib 0

# ADD BASE CPP /nologo /W3 /GX /GR /O2 /YX /FD /D "WIN32" /D "NDEBUG" /D "_MBCS" /YX /FD /c /MD /D "_WINDOWS" /I "."
# ADD CPP /nologo /W3 /GX /GR /O2 /YX /FD /D "WIN32" /D "NDEBUG" /D "_MBCS" /c /MD /D "_WINDOWS" /I "."
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo 
# ADD BASE LINK32 /nologo /subsystem:windows /lib /machine:I386
# ADD LINK32 /nologo /subsystem:windows /lib /incremental:yes /machine:I386

!ELSEIF  "$(CFG)" == "ringing - Win32 Debug"

# PROP BASE Use_Debug_Libraries 1
# PROP Use_Debug_Libraries 1
# PROP BASE Use_MFC 0
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug\ringing"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug\ringing"
# PROP Target_Dir ""
# PROP Ignore_Export_Lib 0

# ADD BASE CPP /nologo /W3 /Gm /GX /GR /Od /YX /FD /D "WIN32" /D "_DEBUG" /D "_MBCS" /MDd /D "_WINDOWS" /c /I "."
# ADD CPP /nologo /W3 /Gm /GX /GR /Od /YX /FD /D "WIN32" /D "_DEBUG" /D "_MBCS" /MDd /D "_WINDOWS" /c /I "."
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
# ADD BASE LINK32 /nologo /subsystem:windows /lib /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /lib /debug /machine:I386 /pdbtype:sept

!ENDIF

# Begin Target

# Name "ringing - Win32 Release"
# Name "ringing - Win32 Debug"


# Begin Source File

SOURCE =.\ringing\mslib.cpp
# End Source File
# Begin Source File

SOURCE =.\ringing\cclib.cpp
# End Source File
# Begin Source File

SOURCE =.\ringing\proof.cpp
# End Source File
# Begin Source File

SOURCE =.\ringing\music.cpp
# End Source File
# Begin Source File

SOURCE =.\ringing\print.cpp
# End Source File
# Begin Source File

SOURCE =.\ringing\print_ps.cpp
# End Source File
# Begin Source File

SOURCE =.\ringing\dimension.cpp
# End Source File
# Begin Source File

SOURCE =.\ringing\touch.cpp
# End Source File
# Begin Source File

SOURCE =.\ringing\printm.cpp
# End Source File
# Begin Source File

SOURCE =.\ringing\print_pdf.cpp
# End Source File
# Begin Source File

SOURCE =.\ringing\pdf_fonts.cpp
# End Source File
# Begin Source File

SOURCE =.\ringing\extent.cpp
# End Source File
# Begin Source File

SOURCE =.\ringing\falseness.cpp
# End Source File
# Begin Source File

SOURCE =.\ringing\search_base.cpp
# End Source File
# Begin Source File

SOURCE =.\ringing\basic_search.cpp
# End Source File
# Begin Source File

SOURCE =.\ringing\multtab.cpp
# End Source File
# Begin Source File

SOURCE =.\ringing\table_search.cpp
# End Source File
# Begin Source File

SOURCE =.\ringing\streamutils.cpp
# End Source File
# Begin Source File

SOURCE =.\ringing\falseness.dat
# End Source File
# Begin Source File

SOURCE =.\ringing\group.cpp
# End Source File
# Begin Source File

SOURCE =.\ringing\row.cpp
# End Source File
# Begin Source File

SOURCE =.\ringing\method.cpp
# End Source File
# Begin Source File

SOURCE =.\ringing\library.cpp
# End Source File
# Begin Source File

SOURCE =.\ringing\libfacet.cpp
# End Source File
# Begin Source File

SOURCE =.\ringing\libout.cpp
# End Source File
# Begin Source File

SOURCE =.\ringing\stl.cpp
# End Source File
# Begin Source File

SOURCE =.\ringing\xmllib.cpp
# End Source File
# Begin Source File

SOURCE =.\ringing\xmlout.cpp
# End Source File
# Begin Source File

SOURCE =.\ringing\peal.cpp
# End Source File
# End Target
# End Project
