# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/sergio/Desktop/ProgrammingAssignment2 - Sergio Torres"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/sergio/Desktop/ProgrammingAssignment2 - Sergio Torres/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/ProgrammingAssignment2___Sergio_Torres.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ProgrammingAssignment2___Sergio_Torres.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProgrammingAssignment2___Sergio_Torres.dir/flags.make

CMakeFiles/ProgrammingAssignment2___Sergio_Torres.dir/main.c.o: CMakeFiles/ProgrammingAssignment2___Sergio_Torres.dir/flags.make
CMakeFiles/ProgrammingAssignment2___Sergio_Torres.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/sergio/Desktop/ProgrammingAssignment2 - Sergio Torres/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ProgrammingAssignment2___Sergio_Torres.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ProgrammingAssignment2___Sergio_Torres.dir/main.c.o   -c "/Users/sergio/Desktop/ProgrammingAssignment2 - Sergio Torres/main.c"

CMakeFiles/ProgrammingAssignment2___Sergio_Torres.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProgrammingAssignment2___Sergio_Torres.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/sergio/Desktop/ProgrammingAssignment2 - Sergio Torres/main.c" > CMakeFiles/ProgrammingAssignment2___Sergio_Torres.dir/main.c.i

CMakeFiles/ProgrammingAssignment2___Sergio_Torres.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProgrammingAssignment2___Sergio_Torres.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/sergio/Desktop/ProgrammingAssignment2 - Sergio Torres/main.c" -o CMakeFiles/ProgrammingAssignment2___Sergio_Torres.dir/main.c.s

# Object files for target ProgrammingAssignment2___Sergio_Torres
ProgrammingAssignment2___Sergio_Torres_OBJECTS = \
"CMakeFiles/ProgrammingAssignment2___Sergio_Torres.dir/main.c.o"

# External object files for target ProgrammingAssignment2___Sergio_Torres
ProgrammingAssignment2___Sergio_Torres_EXTERNAL_OBJECTS =

ProgrammingAssignment2___Sergio_Torres: CMakeFiles/ProgrammingAssignment2___Sergio_Torres.dir/main.c.o
ProgrammingAssignment2___Sergio_Torres: CMakeFiles/ProgrammingAssignment2___Sergio_Torres.dir/build.make
ProgrammingAssignment2___Sergio_Torres: CMakeFiles/ProgrammingAssignment2___Sergio_Torres.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/sergio/Desktop/ProgrammingAssignment2 - Sergio Torres/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ProgrammingAssignment2___Sergio_Torres"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ProgrammingAssignment2___Sergio_Torres.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProgrammingAssignment2___Sergio_Torres.dir/build: ProgrammingAssignment2___Sergio_Torres

.PHONY : CMakeFiles/ProgrammingAssignment2___Sergio_Torres.dir/build

CMakeFiles/ProgrammingAssignment2___Sergio_Torres.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ProgrammingAssignment2___Sergio_Torres.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ProgrammingAssignment2___Sergio_Torres.dir/clean

CMakeFiles/ProgrammingAssignment2___Sergio_Torres.dir/depend:
	cd "/Users/sergio/Desktop/ProgrammingAssignment2 - Sergio Torres/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/sergio/Desktop/ProgrammingAssignment2 - Sergio Torres" "/Users/sergio/Desktop/ProgrammingAssignment2 - Sergio Torres" "/Users/sergio/Desktop/ProgrammingAssignment2 - Sergio Torres/cmake-build-debug" "/Users/sergio/Desktop/ProgrammingAssignment2 - Sergio Torres/cmake-build-debug" "/Users/sergio/Desktop/ProgrammingAssignment2 - Sergio Torres/cmake-build-debug/CMakeFiles/ProgrammingAssignment2___Sergio_Torres.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ProgrammingAssignment2___Sergio_Torres.dir/depend

