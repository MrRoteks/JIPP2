# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\rotko\CLionProjects\JIPP2\Lab5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\rotko\CLionProjects\JIPP2\Lab5\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ZajeciaApp.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/ZajeciaApp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ZajeciaApp.dir/flags.make

CMakeFiles/ZajeciaApp.dir/zajecia.cpp.obj: CMakeFiles/ZajeciaApp.dir/flags.make
CMakeFiles/ZajeciaApp.dir/zajecia.cpp.obj: ../zajecia.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\rotko\CLionProjects\JIPP2\Lab5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ZajeciaApp.dir/zajecia.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ZajeciaApp.dir\zajecia.cpp.obj -c C:\Users\rotko\CLionProjects\JIPP2\Lab5\zajecia.cpp

CMakeFiles/ZajeciaApp.dir/zajecia.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ZajeciaApp.dir/zajecia.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\rotko\CLionProjects\JIPP2\Lab5\zajecia.cpp > CMakeFiles\ZajeciaApp.dir\zajecia.cpp.i

CMakeFiles/ZajeciaApp.dir/zajecia.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ZajeciaApp.dir/zajecia.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\rotko\CLionProjects\JIPP2\Lab5\zajecia.cpp -o CMakeFiles\ZajeciaApp.dir\zajecia.cpp.s

# Object files for target ZajeciaApp
ZajeciaApp_OBJECTS = \
"CMakeFiles/ZajeciaApp.dir/zajecia.cpp.obj"

# External object files for target ZajeciaApp
ZajeciaApp_EXTERNAL_OBJECTS =

ZajeciaApp.exe: CMakeFiles/ZajeciaApp.dir/zajecia.cpp.obj
ZajeciaApp.exe: CMakeFiles/ZajeciaApp.dir/build.make
ZajeciaApp.exe: CMakeFiles/ZajeciaApp.dir/linklibs.rsp
ZajeciaApp.exe: CMakeFiles/ZajeciaApp.dir/objects1.rsp
ZajeciaApp.exe: CMakeFiles/ZajeciaApp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\rotko\CLionProjects\JIPP2\Lab5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ZajeciaApp.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ZajeciaApp.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ZajeciaApp.dir/build: ZajeciaApp.exe
.PHONY : CMakeFiles/ZajeciaApp.dir/build

CMakeFiles/ZajeciaApp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ZajeciaApp.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ZajeciaApp.dir/clean

CMakeFiles/ZajeciaApp.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\rotko\CLionProjects\JIPP2\Lab5 C:\Users\rotko\CLionProjects\JIPP2\Lab5 C:\Users\rotko\CLionProjects\JIPP2\Lab5\cmake-build-debug C:\Users\rotko\CLionProjects\JIPP2\Lab5\cmake-build-debug C:\Users\rotko\CLionProjects\JIPP2\Lab5\cmake-build-debug\CMakeFiles\ZajeciaApp.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ZajeciaApp.dir/depend

