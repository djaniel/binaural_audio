# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/danielsg/dev/lihsa/binauralplayer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/danielsg/dev/lihsa/binauralplayer/build

# Include any dependencies generated for this target.
include SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/compiler_depend.make

# Include the progress variables for this target.
include SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/progress.make

# Include the compile flags for this target's objects.
include SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/flags.make

SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/src/ambi_drc/ambi_drc_internal.c.o: SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/flags.make
SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/src/ambi_drc/ambi_drc_internal.c.o: ../SDKs/Spatial_Audio_Framework/examples/src/ambi_drc/ambi_drc_internal.c
SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/src/ambi_drc/ambi_drc_internal.c.o: SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danielsg/dev/lihsa/binauralplayer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/src/ambi_drc/ambi_drc_internal.c.o"
	cd /home/danielsg/dev/lihsa/binauralplayer/build/SDKs/Spatial_Audio_Framework/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/src/ambi_drc/ambi_drc_internal.c.o -MF CMakeFiles/saf_example_ambi_drc.dir/src/ambi_drc/ambi_drc_internal.c.o.d -o CMakeFiles/saf_example_ambi_drc.dir/src/ambi_drc/ambi_drc_internal.c.o -c /home/danielsg/dev/lihsa/binauralplayer/SDKs/Spatial_Audio_Framework/examples/src/ambi_drc/ambi_drc_internal.c

SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/src/ambi_drc/ambi_drc_internal.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/saf_example_ambi_drc.dir/src/ambi_drc/ambi_drc_internal.c.i"
	cd /home/danielsg/dev/lihsa/binauralplayer/build/SDKs/Spatial_Audio_Framework/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/danielsg/dev/lihsa/binauralplayer/SDKs/Spatial_Audio_Framework/examples/src/ambi_drc/ambi_drc_internal.c > CMakeFiles/saf_example_ambi_drc.dir/src/ambi_drc/ambi_drc_internal.c.i

SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/src/ambi_drc/ambi_drc_internal.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/saf_example_ambi_drc.dir/src/ambi_drc/ambi_drc_internal.c.s"
	cd /home/danielsg/dev/lihsa/binauralplayer/build/SDKs/Spatial_Audio_Framework/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/danielsg/dev/lihsa/binauralplayer/SDKs/Spatial_Audio_Framework/examples/src/ambi_drc/ambi_drc_internal.c -o CMakeFiles/saf_example_ambi_drc.dir/src/ambi_drc/ambi_drc_internal.c.s

SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/src/ambi_drc/ambi_drc.c.o: SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/flags.make
SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/src/ambi_drc/ambi_drc.c.o: ../SDKs/Spatial_Audio_Framework/examples/src/ambi_drc/ambi_drc.c
SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/src/ambi_drc/ambi_drc.c.o: SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danielsg/dev/lihsa/binauralplayer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/src/ambi_drc/ambi_drc.c.o"
	cd /home/danielsg/dev/lihsa/binauralplayer/build/SDKs/Spatial_Audio_Framework/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/src/ambi_drc/ambi_drc.c.o -MF CMakeFiles/saf_example_ambi_drc.dir/src/ambi_drc/ambi_drc.c.o.d -o CMakeFiles/saf_example_ambi_drc.dir/src/ambi_drc/ambi_drc.c.o -c /home/danielsg/dev/lihsa/binauralplayer/SDKs/Spatial_Audio_Framework/examples/src/ambi_drc/ambi_drc.c

SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/src/ambi_drc/ambi_drc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/saf_example_ambi_drc.dir/src/ambi_drc/ambi_drc.c.i"
	cd /home/danielsg/dev/lihsa/binauralplayer/build/SDKs/Spatial_Audio_Framework/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/danielsg/dev/lihsa/binauralplayer/SDKs/Spatial_Audio_Framework/examples/src/ambi_drc/ambi_drc.c > CMakeFiles/saf_example_ambi_drc.dir/src/ambi_drc/ambi_drc.c.i

SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/src/ambi_drc/ambi_drc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/saf_example_ambi_drc.dir/src/ambi_drc/ambi_drc.c.s"
	cd /home/danielsg/dev/lihsa/binauralplayer/build/SDKs/Spatial_Audio_Framework/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/danielsg/dev/lihsa/binauralplayer/SDKs/Spatial_Audio_Framework/examples/src/ambi_drc/ambi_drc.c -o CMakeFiles/saf_example_ambi_drc.dir/src/ambi_drc/ambi_drc.c.s

# Object files for target saf_example_ambi_drc
saf_example_ambi_drc_OBJECTS = \
"CMakeFiles/saf_example_ambi_drc.dir/src/ambi_drc/ambi_drc_internal.c.o" \
"CMakeFiles/saf_example_ambi_drc.dir/src/ambi_drc/ambi_drc.c.o"

# External object files for target saf_example_ambi_drc
saf_example_ambi_drc_EXTERNAL_OBJECTS =

SDKs/Spatial_Audio_Framework/examples/libsaf_example_ambi_drc.a: SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/src/ambi_drc/ambi_drc_internal.c.o
SDKs/Spatial_Audio_Framework/examples/libsaf_example_ambi_drc.a: SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/src/ambi_drc/ambi_drc.c.o
SDKs/Spatial_Audio_Framework/examples/libsaf_example_ambi_drc.a: SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/build.make
SDKs/Spatial_Audio_Framework/examples/libsaf_example_ambi_drc.a: SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/danielsg/dev/lihsa/binauralplayer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libsaf_example_ambi_drc.a"
	cd /home/danielsg/dev/lihsa/binauralplayer/build/SDKs/Spatial_Audio_Framework/examples && $(CMAKE_COMMAND) -P CMakeFiles/saf_example_ambi_drc.dir/cmake_clean_target.cmake
	cd /home/danielsg/dev/lihsa/binauralplayer/build/SDKs/Spatial_Audio_Framework/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/saf_example_ambi_drc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/build: SDKs/Spatial_Audio_Framework/examples/libsaf_example_ambi_drc.a
.PHONY : SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/build

SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/clean:
	cd /home/danielsg/dev/lihsa/binauralplayer/build/SDKs/Spatial_Audio_Framework/examples && $(CMAKE_COMMAND) -P CMakeFiles/saf_example_ambi_drc.dir/cmake_clean.cmake
.PHONY : SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/clean

SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/depend:
	cd /home/danielsg/dev/lihsa/binauralplayer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/danielsg/dev/lihsa/binauralplayer /home/danielsg/dev/lihsa/binauralplayer/SDKs/Spatial_Audio_Framework/examples /home/danielsg/dev/lihsa/binauralplayer/build /home/danielsg/dev/lihsa/binauralplayer/build/SDKs/Spatial_Audio_Framework/examples /home/danielsg/dev/lihsa/binauralplayer/build/SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : SDKs/Spatial_Audio_Framework/examples/CMakeFiles/saf_example_ambi_drc.dir/depend

