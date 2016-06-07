# Microsoft Developer Studio Project File - Name="stuff" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=stuff - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE
!MESSAGE NMAKE /f "stuff.mak".
!MESSAGE
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "stuff.mak" CFG="stuff - Win32 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "stuff - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "stuff - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
BSC32=bscmake.exe
LINK32=link.exe

!IF  "$(CFG)" == "stuff - Win32 Release"

# PROP BASE Use_Debug_Libraries 0
# PROP Use_Debug_Libraries 0
# PROP BASE Use_MFC 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release\stuff"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release\stuff"
# PROP Target_Dir ""
# PROP Ignore_Export_Lib 0

# ADD BASE CPP /nologo /W3 /GX /GR /O2 /YX /FD /D "WIN32" /D "NDEBUG" /D "_MBCS" /YX /FD /c /MD /D "_WINDOWS" /I "."
# ADD CPP /nologo /W3 /GX /GR /O2 /YX /FD /D "WIN32" /D "NDEBUG" /D "_MBCS" /c /MD /D "_WINDOWS" /I "."
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo 
# ADD BASE LINK32 /nologo /subsystem:windows /lib /machine:I386
# ADD LINK32 /nologo /subsystem:windows /lib /incremental:yes /machine:I386

!ELSEIF  "$(CFG)" == "stuff - Win32 Debug"

# PROP BASE Use_Debug_Libraries 1
# PROP Use_Debug_Libraries 1
# PROP BASE Use_MFC 0
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug\stuff"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug\stuff"
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

# Name "stuff - Win32 Release"
# Name "stuff - Win32 Debug"


# Begin Source File

SOURCE =.\apps\utils\args.cpp
# End Source File
# Begin Source File

SOURCE =.\apps\utils\args.h
# End Source File
# Begin Source File

SOURCE =.\apps\utils\tokeniser.cpp
# End Source File
# Begin Source File

SOURCE =.\apps\utils\tokeniser.h
# End Source File
# Begin Source File

SOURCE =.\apps\utils\init_val.h
# End Source File
# End Target
# End Project
