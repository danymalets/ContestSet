# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_SOURCE_DIR = /Users/danielmalec/Desktop/CLion

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/danielmalec/Desktop/CLion/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/main2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main2.dir/flags.make

CMakeFiles/main2.dir/main2.cpp.o: CMakeFiles/main2.dir/flags.make
CMakeFiles/main2.dir/main2.cpp.o: ../main2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danielmalec/Desktop/CLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main2.dir/main2.cpp.o"
	/usr/local/Cellar/gcc/11.2.0/bin/c++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main2.dir/main2.cpp.o -c /Users/danielmalec/Desktop/CLion/main2.cpp

CMakeFiles/main2.dir/main2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main2.dir/main2.cpp.i"
	/usr/local/Cellar/gcc/11.2.0/bin/c++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/danielmalec/Desktop/CLion/main2.cpp > CMakeFiles/main2.dir/main2.cpp.i

CMakeFiles/main2.dir/main2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main2.dir/main2.cpp.s"
	/usr/local/Cellar/gcc/11.2.0/bin/c++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/danielmalec/Desktop/CLion/main2.cpp -o CMakeFiles/main2.dir/main2.cpp.s

# Object files for target main2
main2_OBJECTS = \
"CMakeFiles/main2.dir/main2.cpp.o"

# External object files for target main2
main2_EXTERNAL_OBJECTS =

main2: CMakeFiles/main2.dir/main2.cpp.o
main2: CMakeFiles/main2.dir/build.make
main2: CMakeFiles/main2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/danielmalec/Desktop/CLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable main2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main2.dir/build: main2

.PHONY : CMakeFiles/main2.dir/build

CMakeFiles/main2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main2.dir/clean

CMakeFiles/main2.dir/depend:
	cd /Users/danielmalec/Desktop/CLion/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/danielmalec/Desktop/CLion /Users/danielmalec/Desktop/CLion /Users/danielmalec/Desktop/CLion/cmake-build-debug /Users/danielmalec/Desktop/CLion/cmake-build-debug /Users/danielmalec/Desktop/CLion/cmake-build-debug/CMakeFiles/main2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main2.dir/depend
