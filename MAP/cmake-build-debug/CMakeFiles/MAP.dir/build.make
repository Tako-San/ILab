# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/farid/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.5662.56/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/farid/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.5662.56/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/farid/ILab/MAP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/farid/ILab/MAP/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MAP.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MAP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MAP.dir/flags.make

CMakeFiles/MAP.dir/map.cpp.o: CMakeFiles/MAP.dir/flags.make
CMakeFiles/MAP.dir/map.cpp.o: ../map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/farid/ILab/MAP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MAP.dir/map.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MAP.dir/map.cpp.o -c /home/farid/ILab/MAP/map.cpp

CMakeFiles/MAP.dir/map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MAP.dir/map.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/farid/ILab/MAP/map.cpp > CMakeFiles/MAP.dir/map.cpp.i

CMakeFiles/MAP.dir/map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MAP.dir/map.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/farid/ILab/MAP/map.cpp -o CMakeFiles/MAP.dir/map.cpp.s

CMakeFiles/MAP.dir/node.cpp.o: CMakeFiles/MAP.dir/flags.make
CMakeFiles/MAP.dir/node.cpp.o: ../node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/farid/ILab/MAP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MAP.dir/node.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MAP.dir/node.cpp.o -c /home/farid/ILab/MAP/node.cpp

CMakeFiles/MAP.dir/node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MAP.dir/node.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/farid/ILab/MAP/node.cpp > CMakeFiles/MAP.dir/node.cpp.i

CMakeFiles/MAP.dir/node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MAP.dir/node.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/farid/ILab/MAP/node.cpp -o CMakeFiles/MAP.dir/node.cpp.s

CMakeFiles/MAP.dir/tree.cpp.o: CMakeFiles/MAP.dir/flags.make
CMakeFiles/MAP.dir/tree.cpp.o: ../tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/farid/ILab/MAP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MAP.dir/tree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MAP.dir/tree.cpp.o -c /home/farid/ILab/MAP/tree.cpp

CMakeFiles/MAP.dir/tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MAP.dir/tree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/farid/ILab/MAP/tree.cpp > CMakeFiles/MAP.dir/tree.cpp.i

CMakeFiles/MAP.dir/tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MAP.dir/tree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/farid/ILab/MAP/tree.cpp -o CMakeFiles/MAP.dir/tree.cpp.s

CMakeFiles/MAP.dir/test.cpp.o: CMakeFiles/MAP.dir/flags.make
CMakeFiles/MAP.dir/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/farid/ILab/MAP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/MAP.dir/test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MAP.dir/test.cpp.o -c /home/farid/ILab/MAP/test.cpp

CMakeFiles/MAP.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MAP.dir/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/farid/ILab/MAP/test.cpp > CMakeFiles/MAP.dir/test.cpp.i

CMakeFiles/MAP.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MAP.dir/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/farid/ILab/MAP/test.cpp -o CMakeFiles/MAP.dir/test.cpp.s

# Object files for target MAP
MAP_OBJECTS = \
"CMakeFiles/MAP.dir/map.cpp.o" \
"CMakeFiles/MAP.dir/node.cpp.o" \
"CMakeFiles/MAP.dir/tree.cpp.o" \
"CMakeFiles/MAP.dir/test.cpp.o"

# External object files for target MAP
MAP_EXTERNAL_OBJECTS =

MAP: CMakeFiles/MAP.dir/map.cpp.o
MAP: CMakeFiles/MAP.dir/node.cpp.o
MAP: CMakeFiles/MAP.dir/tree.cpp.o
MAP: CMakeFiles/MAP.dir/test.cpp.o
MAP: CMakeFiles/MAP.dir/build.make
MAP: CMakeFiles/MAP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/farid/ILab/MAP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable MAP"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MAP.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MAP.dir/build: MAP

.PHONY : CMakeFiles/MAP.dir/build

CMakeFiles/MAP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MAP.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MAP.dir/clean

CMakeFiles/MAP.dir/depend:
	cd /home/farid/ILab/MAP/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/farid/ILab/MAP /home/farid/ILab/MAP /home/farid/ILab/MAP/cmake-build-debug /home/farid/ILab/MAP/cmake-build-debug /home/farid/ILab/MAP/cmake-build-debug/CMakeFiles/MAP.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MAP.dir/depend

