# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nilxwam/workspace/gwam-simulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nilxwam/workspace/gwam-simulator/build

# Include any dependencies generated for this target.
include CMakeFiles/ncurses_example.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ncurses_example.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ncurses_example.dir/flags.make

CMakeFiles/ncurses_example.dir/src/ncurses_example.cpp.o: CMakeFiles/ncurses_example.dir/flags.make
CMakeFiles/ncurses_example.dir/src/ncurses_example.cpp.o: ../src/ncurses_example.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nilxwam/workspace/gwam-simulator/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ncurses_example.dir/src/ncurses_example.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ncurses_example.dir/src/ncurses_example.cpp.o -c /home/nilxwam/workspace/gwam-simulator/src/ncurses_example.cpp

CMakeFiles/ncurses_example.dir/src/ncurses_example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ncurses_example.dir/src/ncurses_example.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/nilxwam/workspace/gwam-simulator/src/ncurses_example.cpp > CMakeFiles/ncurses_example.dir/src/ncurses_example.cpp.i

CMakeFiles/ncurses_example.dir/src/ncurses_example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ncurses_example.dir/src/ncurses_example.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/nilxwam/workspace/gwam-simulator/src/ncurses_example.cpp -o CMakeFiles/ncurses_example.dir/src/ncurses_example.cpp.s

CMakeFiles/ncurses_example.dir/src/ncurses_example.cpp.o.requires:
.PHONY : CMakeFiles/ncurses_example.dir/src/ncurses_example.cpp.o.requires

CMakeFiles/ncurses_example.dir/src/ncurses_example.cpp.o.provides: CMakeFiles/ncurses_example.dir/src/ncurses_example.cpp.o.requires
	$(MAKE) -f CMakeFiles/ncurses_example.dir/build.make CMakeFiles/ncurses_example.dir/src/ncurses_example.cpp.o.provides.build
.PHONY : CMakeFiles/ncurses_example.dir/src/ncurses_example.cpp.o.provides

CMakeFiles/ncurses_example.dir/src/ncurses_example.cpp.o.provides.build: CMakeFiles/ncurses_example.dir/src/ncurses_example.cpp.o

# Object files for target ncurses_example
ncurses_example_OBJECTS = \
"CMakeFiles/ncurses_example.dir/src/ncurses_example.cpp.o"

# External object files for target ncurses_example
ncurses_example_EXTERNAL_OBJECTS =

ncurses_example: CMakeFiles/ncurses_example.dir/src/ncurses_example.cpp.o
ncurses_example: /usr/lib/libboost_thread-mt.so
ncurses_example: /usr/local/lib/libboost_python.so
ncurses_example: /usr/lib/libnative.so
ncurses_example: /usr/lib/libxenomai.so
ncurses_example: /usr/lib/librtdm.so
ncurses_example: /usr/lib/libpython2.7.so
ncurses_example: libconstants.a
ncurses_example: libsamlibs.a
ncurses_example: /usr/lib/x86_64-linux-gnu/libcurses.so
ncurses_example: /usr/lib/x86_64-linux-gnu/libform.so
ncurses_example: CMakeFiles/ncurses_example.dir/build.make
ncurses_example: CMakeFiles/ncurses_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ncurses_example"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ncurses_example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ncurses_example.dir/build: ncurses_example
.PHONY : CMakeFiles/ncurses_example.dir/build

CMakeFiles/ncurses_example.dir/requires: CMakeFiles/ncurses_example.dir/src/ncurses_example.cpp.o.requires
.PHONY : CMakeFiles/ncurses_example.dir/requires

CMakeFiles/ncurses_example.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ncurses_example.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ncurses_example.dir/clean

CMakeFiles/ncurses_example.dir/depend:
	cd /home/nilxwam/workspace/gwam-simulator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nilxwam/workspace/gwam-simulator /home/nilxwam/workspace/gwam-simulator /home/nilxwam/workspace/gwam-simulator/build /home/nilxwam/workspace/gwam-simulator/build /home/nilxwam/workspace/gwam-simulator/build/CMakeFiles/ncurses_example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ncurses_example.dir/depend

