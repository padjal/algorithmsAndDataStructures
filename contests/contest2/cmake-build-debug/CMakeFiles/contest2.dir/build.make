# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /opt/clion-2021.2.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2021.2.1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/padjal/Documents/hse/2nd Year/algorithmsAndDataStructures/contests/contest2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/padjal/Documents/hse/2nd Year/algorithmsAndDataStructures/contests/contest2/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/contest2.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/contest2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/contest2.dir/flags.make

CMakeFiles/contest2.dir/main.cpp.o: CMakeFiles/contest2.dir/flags.make
CMakeFiles/contest2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/padjal/Documents/hse/2nd Year/algorithmsAndDataStructures/contests/contest2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/contest2.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/contest2.dir/main.cpp.o -c "/home/padjal/Documents/hse/2nd Year/algorithmsAndDataStructures/contests/contest2/main.cpp"

CMakeFiles/contest2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/contest2.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/padjal/Documents/hse/2nd Year/algorithmsAndDataStructures/contests/contest2/main.cpp" > CMakeFiles/contest2.dir/main.cpp.i

CMakeFiles/contest2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/contest2.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/padjal/Documents/hse/2nd Year/algorithmsAndDataStructures/contests/contest2/main.cpp" -o CMakeFiles/contest2.dir/main.cpp.s

# Object files for target contest2
contest2_OBJECTS = \
"CMakeFiles/contest2.dir/main.cpp.o"

# External object files for target contest2
contest2_EXTERNAL_OBJECTS =

contest2: CMakeFiles/contest2.dir/main.cpp.o
contest2: CMakeFiles/contest2.dir/build.make
contest2: CMakeFiles/contest2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/padjal/Documents/hse/2nd Year/algorithmsAndDataStructures/contests/contest2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable contest2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/contest2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/contest2.dir/build: contest2
.PHONY : CMakeFiles/contest2.dir/build

CMakeFiles/contest2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/contest2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/contest2.dir/clean

CMakeFiles/contest2.dir/depend:
	cd "/home/padjal/Documents/hse/2nd Year/algorithmsAndDataStructures/contests/contest2/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/padjal/Documents/hse/2nd Year/algorithmsAndDataStructures/contests/contest2" "/home/padjal/Documents/hse/2nd Year/algorithmsAndDataStructures/contests/contest2" "/home/padjal/Documents/hse/2nd Year/algorithmsAndDataStructures/contests/contest2/cmake-build-debug" "/home/padjal/Documents/hse/2nd Year/algorithmsAndDataStructures/contests/contest2/cmake-build-debug" "/home/padjal/Documents/hse/2nd Year/algorithmsAndDataStructures/contests/contest2/cmake-build-debug/CMakeFiles/contest2.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/contest2.dir/depend

