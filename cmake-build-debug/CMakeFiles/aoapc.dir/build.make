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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/hliangzhao/Documents/GitHub/aoapc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hliangzhao/Documents/GitHub/aoapc/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/aoapc.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/aoapc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/aoapc.dir/flags.make

CMakeFiles/aoapc.dir/p2-2.cpp.o: CMakeFiles/aoapc.dir/flags.make
CMakeFiles/aoapc.dir/p2-2.cpp.o: ../p2-2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hliangzhao/Documents/GitHub/aoapc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/aoapc.dir/p2-2.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aoapc.dir/p2-2.cpp.o -c /Users/hliangzhao/Documents/GitHub/aoapc/p2-2.cpp

CMakeFiles/aoapc.dir/p2-2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aoapc.dir/p2-2.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hliangzhao/Documents/GitHub/aoapc/p2-2.cpp > CMakeFiles/aoapc.dir/p2-2.cpp.i

CMakeFiles/aoapc.dir/p2-2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aoapc.dir/p2-2.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hliangzhao/Documents/GitHub/aoapc/p2-2.cpp -o CMakeFiles/aoapc.dir/p2-2.cpp.s

# Object files for target aoapc
aoapc_OBJECTS = \
"CMakeFiles/aoapc.dir/p2-2.cpp.o"

# External object files for target aoapc
aoapc_EXTERNAL_OBJECTS =

aoapc: CMakeFiles/aoapc.dir/p2-2.cpp.o
aoapc: CMakeFiles/aoapc.dir/build.make
aoapc: CMakeFiles/aoapc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/hliangzhao/Documents/GitHub/aoapc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable aoapc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/aoapc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/aoapc.dir/build: aoapc
.PHONY : CMakeFiles/aoapc.dir/build

CMakeFiles/aoapc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/aoapc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/aoapc.dir/clean

CMakeFiles/aoapc.dir/depend:
	cd /Users/hliangzhao/Documents/GitHub/aoapc/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hliangzhao/Documents/GitHub/aoapc /Users/hliangzhao/Documents/GitHub/aoapc /Users/hliangzhao/Documents/GitHub/aoapc/cmake-build-debug /Users/hliangzhao/Documents/GitHub/aoapc/cmake-build-debug /Users/hliangzhao/Documents/GitHub/aoapc/cmake-build-debug/CMakeFiles/aoapc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/aoapc.dir/depend

