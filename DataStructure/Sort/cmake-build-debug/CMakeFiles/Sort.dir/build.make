# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\05code\2022\code-road\DataStructure\Sort

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\05code\2022\code-road\DataStructure\Sort\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Sort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Sort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Sort.dir/flags.make

CMakeFiles/Sort.dir/main.c.obj: CMakeFiles/Sort.dir/flags.make
CMakeFiles/Sort.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\05code\2022\code-road\DataStructure\Sort\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Sort.dir/main.c.obj"
	"D:\Program Files\JetBrains\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Sort.dir\main.c.obj   -c D:\05code\2022\code-road\DataStructure\Sort\main.c

CMakeFiles/Sort.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Sort.dir/main.c.i"
	"D:\Program Files\JetBrains\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\05code\2022\code-road\DataStructure\Sort\main.c > CMakeFiles\Sort.dir\main.c.i

CMakeFiles/Sort.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Sort.dir/main.c.s"
	"D:\Program Files\JetBrains\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\05code\2022\code-road\DataStructure\Sort\main.c -o CMakeFiles\Sort.dir\main.c.s

CMakeFiles/Sort.dir/Sort.c.obj: CMakeFiles/Sort.dir/flags.make
CMakeFiles/Sort.dir/Sort.c.obj: ../Sort.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\05code\2022\code-road\DataStructure\Sort\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Sort.dir/Sort.c.obj"
	"D:\Program Files\JetBrains\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Sort.dir\Sort.c.obj   -c D:\05code\2022\code-road\DataStructure\Sort\Sort.c

CMakeFiles/Sort.dir/Sort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Sort.dir/Sort.c.i"
	"D:\Program Files\JetBrains\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\05code\2022\code-road\DataStructure\Sort\Sort.c > CMakeFiles\Sort.dir\Sort.c.i

CMakeFiles/Sort.dir/Sort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Sort.dir/Sort.c.s"
	"D:\Program Files\JetBrains\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\05code\2022\code-road\DataStructure\Sort\Sort.c -o CMakeFiles\Sort.dir\Sort.c.s

CMakeFiles/Sort.dir/Stack.c.obj: CMakeFiles/Sort.dir/flags.make
CMakeFiles/Sort.dir/Stack.c.obj: ../Stack.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\05code\2022\code-road\DataStructure\Sort\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Sort.dir/Stack.c.obj"
	"D:\Program Files\JetBrains\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Sort.dir\Stack.c.obj   -c D:\05code\2022\code-road\DataStructure\Sort\Stack.c

CMakeFiles/Sort.dir/Stack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Sort.dir/Stack.c.i"
	"D:\Program Files\JetBrains\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\05code\2022\code-road\DataStructure\Sort\Stack.c > CMakeFiles\Sort.dir\Stack.c.i

CMakeFiles/Sort.dir/Stack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Sort.dir/Stack.c.s"
	"D:\Program Files\JetBrains\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\05code\2022\code-road\DataStructure\Sort\Stack.c -o CMakeFiles\Sort.dir\Stack.c.s

# Object files for target Sort
Sort_OBJECTS = \
"CMakeFiles/Sort.dir/main.c.obj" \
"CMakeFiles/Sort.dir/Sort.c.obj" \
"CMakeFiles/Sort.dir/Stack.c.obj"

# External object files for target Sort
Sort_EXTERNAL_OBJECTS =

Sort.exe: CMakeFiles/Sort.dir/main.c.obj
Sort.exe: CMakeFiles/Sort.dir/Sort.c.obj
Sort.exe: CMakeFiles/Sort.dir/Stack.c.obj
Sort.exe: CMakeFiles/Sort.dir/build.make
Sort.exe: CMakeFiles/Sort.dir/linklibs.rsp
Sort.exe: CMakeFiles/Sort.dir/objects1.rsp
Sort.exe: CMakeFiles/Sort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\05code\2022\code-road\DataStructure\Sort\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable Sort.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Sort.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Sort.dir/build: Sort.exe

.PHONY : CMakeFiles/Sort.dir/build

CMakeFiles/Sort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Sort.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Sort.dir/clean

CMakeFiles/Sort.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\05code\2022\code-road\DataStructure\Sort D:\05code\2022\code-road\DataStructure\Sort D:\05code\2022\code-road\DataStructure\Sort\cmake-build-debug D:\05code\2022\code-road\DataStructure\Sort\cmake-build-debug D:\05code\2022\code-road\DataStructure\Sort\cmake-build-debug\CMakeFiles\Sort.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Sort.dir/depend

