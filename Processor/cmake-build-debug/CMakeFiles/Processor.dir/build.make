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
CMAKE_SOURCE_DIR = /home/farid/ILab/Processor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/farid/ILab/Processor/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Processor.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Processor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Processor.dir/flags.make

CMakeFiles/Processor.dir/Stack/main.cpp.o: CMakeFiles/Processor.dir/flags.make
CMakeFiles/Processor.dir/Stack/main.cpp.o: ../Stack/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/farid/ILab/Processor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Processor.dir/Stack/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Processor.dir/Stack/main.cpp.o -c /home/farid/ILab/Processor/Stack/main.cpp

CMakeFiles/Processor.dir/Stack/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Processor.dir/Stack/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/farid/ILab/Processor/Stack/main.cpp > CMakeFiles/Processor.dir/Stack/main.cpp.i

CMakeFiles/Processor.dir/Stack/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Processor.dir/Stack/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/farid/ILab/Processor/Stack/main.cpp -o CMakeFiles/Processor.dir/Stack/main.cpp.s

CMakeFiles/Processor.dir/Stack/interface.cpp.o: CMakeFiles/Processor.dir/flags.make
CMakeFiles/Processor.dir/Stack/interface.cpp.o: ../Stack/interface.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/farid/ILab/Processor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Processor.dir/Stack/interface.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Processor.dir/Stack/interface.cpp.o -c /home/farid/ILab/Processor/Stack/interface.cpp

CMakeFiles/Processor.dir/Stack/interface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Processor.dir/Stack/interface.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/farid/ILab/Processor/Stack/interface.cpp > CMakeFiles/Processor.dir/Stack/interface.cpp.i

CMakeFiles/Processor.dir/Stack/interface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Processor.dir/Stack/interface.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/farid/ILab/Processor/Stack/interface.cpp -o CMakeFiles/Processor.dir/Stack/interface.cpp.s

CMakeFiles/Processor.dir/Stack/stack.cpp.o: CMakeFiles/Processor.dir/flags.make
CMakeFiles/Processor.dir/Stack/stack.cpp.o: ../Stack/stack.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/farid/ILab/Processor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Processor.dir/Stack/stack.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Processor.dir/Stack/stack.cpp.o -c /home/farid/ILab/Processor/Stack/stack.cpp

CMakeFiles/Processor.dir/Stack/stack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Processor.dir/Stack/stack.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/farid/ILab/Processor/Stack/stack.cpp > CMakeFiles/Processor.dir/Stack/stack.cpp.i

CMakeFiles/Processor.dir/Stack/stack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Processor.dir/Stack/stack.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/farid/ILab/Processor/Stack/stack.cpp -o CMakeFiles/Processor.dir/Stack/stack.cpp.s

# Object files for target Processor
Processor_OBJECTS = \
"CMakeFiles/Processor.dir/Stack/main.cpp.o" \
"CMakeFiles/Processor.dir/Stack/interface.cpp.o" \
"CMakeFiles/Processor.dir/Stack/stack.cpp.o"

# External object files for target Processor
Processor_EXTERNAL_OBJECTS =

Processor: CMakeFiles/Processor.dir/Stack/main.cpp.o
Processor: CMakeFiles/Processor.dir/Stack/interface.cpp.o
Processor: CMakeFiles/Processor.dir/Stack/stack.cpp.o
Processor: CMakeFiles/Processor.dir/build.make
Processor: CMakeFiles/Processor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/farid/ILab/Processor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Processor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Processor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Processor.dir/build: Processor

.PHONY : CMakeFiles/Processor.dir/build

CMakeFiles/Processor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Processor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Processor.dir/clean

CMakeFiles/Processor.dir/depend:
	cd /home/farid/ILab/Processor/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/farid/ILab/Processor /home/farid/ILab/Processor /home/farid/ILab/Processor/cmake-build-debug /home/farid/ILab/Processor/cmake-build-debug /home/farid/ILab/Processor/cmake-build-debug/CMakeFiles/Processor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Processor.dir/depend
