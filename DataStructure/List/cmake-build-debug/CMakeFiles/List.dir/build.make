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
CMAKE_SOURCE_DIR = D:\05code\2022\code-road\DataStructure\List

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\05code\2022\code-road\DataStructure\List\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/List.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/List.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/List.dir/flags.make

CMakeFiles/List.dir/main.c.obj: CMakeFiles/List.dir/flags.make
CMakeFiles/List.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\05code\2022\code-road\DataStructure\List\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/List.dir/main.c.obj"
	"D:\Program Files\JetBrains\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\List.dir\main.c.obj   -c D:\05code\2022\code-road\DataStructure\List\main.c

CMakeFiles/List.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/List.dir/main.c.i"
	"D:\Program Files\JetBrains\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\05code\2022\code-road\DataStructure\List\main.c > CMakeFiles\List.dir\main.c.i

CMakeFiles/List.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/List.dir/main.c.s"
	"D:\Program Files\JetBrains\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\05code\2022\code-road\DataStructure\List\main.c -o CMakeFiles\List.dir\main.c.s

CMakeFiles/List.dir/SList.c.obj: CMakeFiles/List.dir/flags.make
CMakeFiles/List.dir/SList.c.obj: ../SList.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\05code\2022\code-road\DataStructure\List\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/List.dir/SList.c.obj"
	"D:\Program Files\JetBrains\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\List.dir\SList.c.obj   -c D:\05code\2022\code-road\DataStructure\List\SList.c

CMakeFiles/List.dir/SList.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/List.dir/SList.c.i"
	"D:\Program Files\JetBrains\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\05code\2022\code-road\DataStructure\List\SList.c > CMakeFiles\List.dir\SList.c.i

CMakeFiles/List.dir/SList.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/List.dir/SList.c.s"
	"D:\Program Files\JetBrains\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\05code\2022\code-road\DataStructure\List\SList.c -o CMakeFiles\List.dir\SList.c.s

# Object files for target List
List_OBJECTS = \
"CMakeFiles/List.dir/main.c.obj" \
"CMakeFiles/List.dir/SList.c.obj"

# External object files for target List
List_EXTERNAL_OBJECTS =

List.exe: CMakeFiles/List.dir/main.c.obj
List.exe: CMakeFiles/List.dir/SList.c.obj
List.exe: CMakeFiles/List.dir/build.make
List.exe: CMakeFiles/List.dir/linklibs.rsp
List.exe: CMakeFiles/List.dir/objects1.rsp
List.exe: CMakeFiles/List.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\05code\2022\code-road\DataStructure\List\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable List.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\List.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/List.dir/build: List.exe

.PHONY : CMakeFiles/List.dir/build

CMakeFiles/List.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\List.dir\cmake_clean.cmake
.PHONY : CMakeFiles/List.dir/clean

CMakeFiles/List.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\05code\2022\code-road\DataStructure\List D:\05code\2022\code-road\DataStructure\List D:\05code\2022\code-road\DataStructure\List\cmake-build-debug D:\05code\2022\code-road\DataStructure\List\cmake-build-debug D:\05code\2022\code-road\DataStructure\List\cmake-build-debug\CMakeFiles\List.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/List.dir/depend

