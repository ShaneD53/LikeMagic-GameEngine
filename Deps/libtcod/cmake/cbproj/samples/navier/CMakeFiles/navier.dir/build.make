# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Programming\CMake 2.8\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Programming\CMake 2.8\bin\cmake.exe" -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = "D:\Programming\CMake 2.8\bin\cmake-gui.exe"

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Code\dropecho\libtcod-1.5.1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Code\dropecho\libtcod-1.5.1\cmake\cbproj

# Include any dependencies generated for this target.
include samples/navier/CMakeFiles/navier.dir/depend.make

# Include the progress variables for this target.
include samples/navier/CMakeFiles/navier.dir/progress.make

# Include the compile flags for this target's objects.
include samples/navier/CMakeFiles/navier.dir/flags.make

samples/navier/CMakeFiles/navier.dir/main.cpp.obj: samples/navier/CMakeFiles/navier.dir/flags.make
samples/navier/CMakeFiles/navier.dir/main.cpp.obj: ../../samples/navier/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report D:\Code\dropecho\libtcod-1.5.1\cmake\cbproj\CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object samples/navier/CMakeFiles/navier.dir/main.cpp.obj"
	cd D:\Code\dropecho\libtcod-1.5.1\cmake\cbproj\samples\navier && C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles\navier.dir\main.cpp.obj -c D:\Code\dropecho\libtcod-1.5.1\samples\navier\main.cpp

samples/navier/CMakeFiles/navier.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/navier.dir/main.cpp.i"
	cd D:\Code\dropecho\libtcod-1.5.1\cmake\cbproj\samples\navier && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E D:\Code\dropecho\libtcod-1.5.1\samples\navier\main.cpp > CMakeFiles\navier.dir\main.cpp.i

samples/navier/CMakeFiles/navier.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/navier.dir/main.cpp.s"
	cd D:\Code\dropecho\libtcod-1.5.1\cmake\cbproj\samples\navier && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S D:\Code\dropecho\libtcod-1.5.1\samples\navier\main.cpp -o CMakeFiles\navier.dir\main.cpp.s

samples/navier/CMakeFiles/navier.dir/main.cpp.obj.requires:
.PHONY : samples/navier/CMakeFiles/navier.dir/main.cpp.obj.requires

samples/navier/CMakeFiles/navier.dir/main.cpp.obj.provides: samples/navier/CMakeFiles/navier.dir/main.cpp.obj.requires
	$(MAKE) -f samples\navier\CMakeFiles\navier.dir\build.make samples/navier/CMakeFiles/navier.dir/main.cpp.obj.provides.build
.PHONY : samples/navier/CMakeFiles/navier.dir/main.cpp.obj.provides

samples/navier/CMakeFiles/navier.dir/main.cpp.obj.provides.build: samples/navier/CMakeFiles/navier.dir/main.cpp.obj

# Object files for target navier
navier_OBJECTS = \
"CMakeFiles/navier.dir/main.cpp.obj"

# External object files for target navier
navier_EXTERNAL_OBJECTS =

samples/navier/navier.exe: samples/navier/CMakeFiles/navier.dir/main.cpp.obj
samples/navier/navier.exe: src/libtcod-mingw.dll.a
samples/navier/navier.exe: samples/navier/CMakeFiles/navier.dir/build.make
samples/navier/navier.exe: samples/navier/CMakeFiles/navier.dir/objects1.rsp
samples/navier/navier.exe: samples/navier/CMakeFiles/navier.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable navier.exe"
	cd D:\Code\dropecho\libtcod-1.5.1\cmake\cbproj\samples\navier && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\navier.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
samples/navier/CMakeFiles/navier.dir/build: samples/navier/navier.exe
.PHONY : samples/navier/CMakeFiles/navier.dir/build

samples/navier/CMakeFiles/navier.dir/requires: samples/navier/CMakeFiles/navier.dir/main.cpp.obj.requires
.PHONY : samples/navier/CMakeFiles/navier.dir/requires

samples/navier/CMakeFiles/navier.dir/clean:
	cd D:\Code\dropecho\libtcod-1.5.1\cmake\cbproj\samples\navier && $(CMAKE_COMMAND) -P CMakeFiles\navier.dir\cmake_clean.cmake
.PHONY : samples/navier/CMakeFiles/navier.dir/clean

samples/navier/CMakeFiles/navier.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Code\dropecho\libtcod-1.5.1 D:\Code\dropecho\libtcod-1.5.1\samples\navier D:\Code\dropecho\libtcod-1.5.1\cmake\cbproj D:\Code\dropecho\libtcod-1.5.1\cmake\cbproj\samples\navier D:\Code\dropecho\libtcod-1.5.1\cmake\cbproj\samples\navier\CMakeFiles\navier.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : samples/navier/CMakeFiles/navier.dir/depend

