# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/carla/Desktop/T2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/carla/Desktop/T2

# Include any dependencies generated for this target.
include src/3dir/CMakeFiles/D3.dir/depend.make

# Include the progress variables for this target.
include src/3dir/CMakeFiles/D3.dir/progress.make

# Include the compile flags for this target's objects.
include src/3dir/CMakeFiles/D3.dir/flags.make

src/3dir/CMakeFiles/D3.dir/main3.cpp.o: src/3dir/CMakeFiles/D3.dir/flags.make
src/3dir/CMakeFiles/D3.dir/main3.cpp.o: src/3dir/main3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/carla/Desktop/T2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/3dir/CMakeFiles/D3.dir/main3.cpp.o"
	cd /home/carla/Desktop/T2/src/3dir && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/D3.dir/main3.cpp.o -c /home/carla/Desktop/T2/src/3dir/main3.cpp

src/3dir/CMakeFiles/D3.dir/main3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/D3.dir/main3.cpp.i"
	cd /home/carla/Desktop/T2/src/3dir && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/carla/Desktop/T2/src/3dir/main3.cpp > CMakeFiles/D3.dir/main3.cpp.i

src/3dir/CMakeFiles/D3.dir/main3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/D3.dir/main3.cpp.s"
	cd /home/carla/Desktop/T2/src/3dir && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/carla/Desktop/T2/src/3dir/main3.cpp -o CMakeFiles/D3.dir/main3.cpp.s

# Object files for target D3
D3_OBJECTS = \
"CMakeFiles/D3.dir/main3.cpp.o"

# External object files for target D3
D3_EXTERNAL_OBJECTS =

src/3dir/D3: src/3dir/CMakeFiles/D3.dir/main3.cpp.o
src/3dir/D3: src/3dir/CMakeFiles/D3.dir/build.make
src/3dir/D3: src/3dir/CMakeFiles/D3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/carla/Desktop/T2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable D3"
	cd /home/carla/Desktop/T2/src/3dir && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/D3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/3dir/CMakeFiles/D3.dir/build: src/3dir/D3

.PHONY : src/3dir/CMakeFiles/D3.dir/build

src/3dir/CMakeFiles/D3.dir/clean:
	cd /home/carla/Desktop/T2/src/3dir && $(CMAKE_COMMAND) -P CMakeFiles/D3.dir/cmake_clean.cmake
.PHONY : src/3dir/CMakeFiles/D3.dir/clean

src/3dir/CMakeFiles/D3.dir/depend:
	cd /home/carla/Desktop/T2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/carla/Desktop/T2 /home/carla/Desktop/T2/src/3dir /home/carla/Desktop/T2 /home/carla/Desktop/T2/src/3dir /home/carla/Desktop/T2/src/3dir/CMakeFiles/D3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/3dir/CMakeFiles/D3.dir/depend

