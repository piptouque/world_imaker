# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake.exe

# The command to remove a file.
RM = /usr/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/Pip/Documents/projets_gite/world_imaker/third-party/freeglut-3.2.1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/Pip/Documents/projets_gite/world_imaker/third-party/freeglut-3.2.1

# Include any dependencies generated for this target.
include CMakeFiles/Resizer_static.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Resizer_static.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Resizer_static.dir/flags.make

CMakeFiles/Resizer_static.dir/progs/demos/Resizer/Resizer.cpp.o: CMakeFiles/Resizer_static.dir/flags.make
CMakeFiles/Resizer_static.dir/progs/demos/Resizer/Resizer.cpp.o: progs/demos/Resizer/Resizer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Pip/Documents/projets_gite/world_imaker/third-party/freeglut-3.2.1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Resizer_static.dir/progs/demos/Resizer/Resizer.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Resizer_static.dir/progs/demos/Resizer/Resizer.cpp.o -c /cygdrive/c/Users/Pip/Documents/projets_gite/world_imaker/third-party/freeglut-3.2.1/progs/demos/Resizer/Resizer.cpp

CMakeFiles/Resizer_static.dir/progs/demos/Resizer/Resizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Resizer_static.dir/progs/demos/Resizer/Resizer.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Pip/Documents/projets_gite/world_imaker/third-party/freeglut-3.2.1/progs/demos/Resizer/Resizer.cpp > CMakeFiles/Resizer_static.dir/progs/demos/Resizer/Resizer.cpp.i

CMakeFiles/Resizer_static.dir/progs/demos/Resizer/Resizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Resizer_static.dir/progs/demos/Resizer/Resizer.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Pip/Documents/projets_gite/world_imaker/third-party/freeglut-3.2.1/progs/demos/Resizer/Resizer.cpp -o CMakeFiles/Resizer_static.dir/progs/demos/Resizer/Resizer.cpp.s

# Object files for target Resizer_static
Resizer_static_OBJECTS = \
"CMakeFiles/Resizer_static.dir/progs/demos/Resizer/Resizer.cpp.o"

# External object files for target Resizer_static
Resizer_static_EXTERNAL_OBJECTS =

bin/Resizer_static.exe: CMakeFiles/Resizer_static.dir/progs/demos/Resizer/Resizer.cpp.o
bin/Resizer_static.exe: CMakeFiles/Resizer_static.dir/build.make
bin/Resizer_static.exe: /usr/lib/libGLU.dll.a
bin/Resizer_static.exe: /usr/lib/libGL.dll.a
bin/Resizer_static.exe: /usr/lib/libX11.dll.a
bin/Resizer_static.exe: /usr/lib/libXrandr.dll.a
bin/Resizer_static.exe: /usr/lib/libXi.dll.a
bin/Resizer_static.exe: lib/libglut.a
bin/Resizer_static.exe: /usr/lib/libGL.dll.a
bin/Resizer_static.exe: /usr/lib/libX11.dll.a
bin/Resizer_static.exe: /usr/lib/libXrandr.dll.a
bin/Resizer_static.exe: /usr/lib/libXi.dll.a
bin/Resizer_static.exe: CMakeFiles/Resizer_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/Pip/Documents/projets_gite/world_imaker/third-party/freeglut-3.2.1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/Resizer_static.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Resizer_static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Resizer_static.dir/build: bin/Resizer_static.exe

.PHONY : CMakeFiles/Resizer_static.dir/build

CMakeFiles/Resizer_static.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Resizer_static.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Resizer_static.dir/clean

CMakeFiles/Resizer_static.dir/depend:
	cd /cygdrive/c/Users/Pip/Documents/projets_gite/world_imaker/third-party/freeglut-3.2.1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/Pip/Documents/projets_gite/world_imaker/third-party/freeglut-3.2.1 /cygdrive/c/Users/Pip/Documents/projets_gite/world_imaker/third-party/freeglut-3.2.1 /cygdrive/c/Users/Pip/Documents/projets_gite/world_imaker/third-party/freeglut-3.2.1 /cygdrive/c/Users/Pip/Documents/projets_gite/world_imaker/third-party/freeglut-3.2.1 /cygdrive/c/Users/Pip/Documents/projets_gite/world_imaker/third-party/freeglut-3.2.1/CMakeFiles/Resizer_static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Resizer_static.dir/depend
