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
CMAKE_SOURCE_DIR = C:\Users\rotko\CLionProjects\JIPP2\Lab4\Struktury\Przyklad

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\rotko\CLionProjects\JIPP2\Lab4\Struktury\Przyklad\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/strukturyApp.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/strukturyApp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/strukturyApp.dir/flags.make

CMakeFiles/strukturyApp.dir/strukturyApp.cpp.obj: CMakeFiles/strukturyApp.dir/flags.make
CMakeFiles/strukturyApp.dir/strukturyApp.cpp.obj: ../strukturyApp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\rotko\CLionProjects\JIPP2\Lab4\Struktury\Przyklad\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/strukturyApp.dir/strukturyApp.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\strukturyApp.dir\strukturyApp.cpp.obj -c C:\Users\rotko\CLionProjects\JIPP2\Lab4\Struktury\Przyklad\strukturyApp.cpp

CMakeFiles/strukturyApp.dir/strukturyApp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/strukturyApp.dir/strukturyApp.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\rotko\CLionProjects\JIPP2\Lab4\Struktury\Przyklad\strukturyApp.cpp > CMakeFiles\strukturyApp.dir\strukturyApp.cpp.i

CMakeFiles/strukturyApp.dir/strukturyApp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/strukturyApp.dir/strukturyApp.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\rotko\CLionProjects\JIPP2\Lab4\Struktury\Przyklad\strukturyApp.cpp -o CMakeFiles\strukturyApp.dir\strukturyApp.cpp.s

# Object files for target strukturyApp
strukturyApp_OBJECTS = \
"CMakeFiles/strukturyApp.dir/strukturyApp.cpp.obj"

# External object files for target strukturyApp
strukturyApp_EXTERNAL_OBJECTS =

strukturyApp.exe: CMakeFiles/strukturyApp.dir/strukturyApp.cpp.obj
strukturyApp.exe: CMakeFiles/strukturyApp.dir/build.make
strukturyApp.exe: CMakeFiles/strukturyApp.dir/linklibs.rsp
strukturyApp.exe: CMakeFiles/strukturyApp.dir/objects1.rsp
strukturyApp.exe: CMakeFiles/strukturyApp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\rotko\CLionProjects\JIPP2\Lab4\Struktury\Przyklad\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable strukturyApp.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\strukturyApp.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/strukturyApp.dir/build: strukturyApp.exe
.PHONY : CMakeFiles/strukturyApp.dir/build

CMakeFiles/strukturyApp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\strukturyApp.dir\cmake_clean.cmake
.PHONY : CMakeFiles/strukturyApp.dir/clean

CMakeFiles/strukturyApp.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\rotko\CLionProjects\JIPP2\Lab4\Struktury\Przyklad C:\Users\rotko\CLionProjects\JIPP2\Lab4\Struktury\Przyklad C:\Users\rotko\CLionProjects\JIPP2\Lab4\Struktury\Przyklad\cmake-build-debug C:\Users\rotko\CLionProjects\JIPP2\Lab4\Struktury\Przyklad\cmake-build-debug C:\Users\rotko\CLionProjects\JIPP2\Lab4\Struktury\Przyklad\cmake-build-debug\CMakeFiles\strukturyApp.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/strukturyApp.dir/depend

