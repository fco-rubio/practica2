# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fco-rubio/Uni/2/IA/practica2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fco-rubio/Uni/2/IA/practica2

# Include any dependencies generated for this target.
include CMakeFiles/practica2SG.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/practica2SG.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/practica2SG.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/practica2SG.dir/flags.make

CMakeFiles/practica2SG.dir/bin_src/juegoSG.cc.o: CMakeFiles/practica2SG.dir/flags.make
CMakeFiles/practica2SG.dir/bin_src/juegoSG.cc.o: bin_src/juegoSG.cc
CMakeFiles/practica2SG.dir/bin_src/juegoSG.cc.o: CMakeFiles/practica2SG.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/fco-rubio/Uni/2/IA/practica2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/practica2SG.dir/bin_src/juegoSG.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/practica2SG.dir/bin_src/juegoSG.cc.o -MF CMakeFiles/practica2SG.dir/bin_src/juegoSG.cc.o.d -o CMakeFiles/practica2SG.dir/bin_src/juegoSG.cc.o -c /home/fco-rubio/Uni/2/IA/practica2/bin_src/juegoSG.cc

CMakeFiles/practica2SG.dir/bin_src/juegoSG.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/practica2SG.dir/bin_src/juegoSG.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fco-rubio/Uni/2/IA/practica2/bin_src/juegoSG.cc > CMakeFiles/practica2SG.dir/bin_src/juegoSG.cc.i

CMakeFiles/practica2SG.dir/bin_src/juegoSG.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/practica2SG.dir/bin_src/juegoSG.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fco-rubio/Uni/2/IA/practica2/bin_src/juegoSG.cc -o CMakeFiles/practica2SG.dir/bin_src/juegoSG.cc.s

# Object files for target practica2SG
practica2SG_OBJECTS = \
"CMakeFiles/practica2SG.dir/bin_src/juegoSG.cc.o"

# External object files for target practica2SG
practica2SG_EXTERNAL_OBJECTS =

practica2SG: CMakeFiles/practica2SG.dir/bin_src/juegoSG.cc.o
practica2SG: CMakeFiles/practica2SG.dir/build.make
practica2SG: lib/libobj3DLib.a
practica2SG: lib/libmotorLib.a
practica2SG: lib/libmodelosBelkanLib.a
practica2SG: lib/libGLUILib.a
practica2SG: lib/libcomportamientosLib.a
practica2SG: /usr/lib/x86_64-linux-gnu/libGL.so
practica2SG: /usr/lib/x86_64-linux-gnu/libglut.so
practica2SG: lib/libobj3DLib.a
practica2SG: /usr/lib/x86_64-linux-gnu/libjpeg.so
practica2SG: /usr/lib/x86_64-linux-gnu/libGL.so
practica2SG: /usr/lib/x86_64-linux-gnu/libGLU.so
practica2SG: CMakeFiles/practica2SG.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/fco-rubio/Uni/2/IA/practica2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable practica2SG"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/practica2SG.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/practica2SG.dir/build: practica2SG
.PHONY : CMakeFiles/practica2SG.dir/build

CMakeFiles/practica2SG.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/practica2SG.dir/cmake_clean.cmake
.PHONY : CMakeFiles/practica2SG.dir/clean

CMakeFiles/practica2SG.dir/depend:
	cd /home/fco-rubio/Uni/2/IA/practica2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fco-rubio/Uni/2/IA/practica2 /home/fco-rubio/Uni/2/IA/practica2 /home/fco-rubio/Uni/2/IA/practica2 /home/fco-rubio/Uni/2/IA/practica2 /home/fco-rubio/Uni/2/IA/practica2/CMakeFiles/practica2SG.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/practica2SG.dir/depend

