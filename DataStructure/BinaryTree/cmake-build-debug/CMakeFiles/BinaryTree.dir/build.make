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
CMAKE_SOURCE_DIR = D:\05code\2022\code-road\DataStructure\BinaryTree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\05code\2022\code-road\DataStructure\BinaryTree\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BinaryTree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BinaryTree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BinaryTree.dir/flags.make

CMakeFiles/BinaryTree.dir/main.c.obj: CMakeFiles/BinaryTree.dir/flags.make
CMakeFiles/BinaryTree.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\05code\2022\code-road\DataStructure\BinaryTree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/BinaryTree.dir/main.c.obj"
	"D:\Program Files\JetBrains\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\BinaryTree.dir\main.c.obj   -c D:\05code\2022\code-road\DataStructure\BinaryTree\main.c

CMakeFiles/BinaryTree.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BinaryTree.dir/main.c.i"
	"D:\Program Files\JetBrains\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\05code\2022\code-road\DataStructure\BinaryTree\main.c > CMakeFiles\BinaryTree.dir\main.c.i

CMakeFiles/BinaryTree.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BinaryTree.dir/main.c.s"
	"D:\Program Files\JetBrains\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\05code\2022\code-road\DataStructure\BinaryTree\main.c -o CMakeFiles\BinaryTree.dir\main.c.s

CMakeFiles/BinaryTree.dir/Queue.c.obj: CMakeFiles/BinaryTree.dir/flags.make
CMakeFiles/BinaryTree.dir/Queue.c.obj: ../Queue.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\05code\2022\code-road\DataStructure\BinaryTree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/BinaryTree.dir/Queue.c.obj"
	"D:\Program Files\JetBrains\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\BinaryTree.dir\Queue.c.obj   -c D:\05code\2022\code-road\DataStructure\BinaryTree\Queue.c

CMakeFiles/BinaryTree.dir/Queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BinaryTree.dir/Queue.c.i"
	"D:\Program Files\JetBrains\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\05code\2022\code-road\DataStructure\BinaryTree\Queue.c > CMakeFiles\BinaryTree.dir\Queue.c.i

CMakeFiles/BinaryTree.dir/Queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BinaryTree.dir/Queue.c.s"
	"D:\Program Files\JetBrains\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\05code\2022\code-road\DataStructure\BinaryTree\Queue.c -o CMakeFiles\BinaryTree.dir\Queue.c.s

# Object files for target BinaryTree
BinaryTree_OBJECTS = \
"CMakeFiles/BinaryTree.dir/main.c.obj" \
"CMakeFiles/BinaryTree.dir/Queue.c.obj"

# External object files for target BinaryTree
BinaryTree_EXTERNAL_OBJECTS =

BinaryTree.exe: CMakeFiles/BinaryTree.dir/main.c.obj
BinaryTree.exe: CMakeFiles/BinaryTree.dir/Queue.c.obj
BinaryTree.exe: CMakeFiles/BinaryTree.dir/build.make
BinaryTree.exe: CMakeFiles/BinaryTree.dir/linklibs.rsp
BinaryTree.exe: CMakeFiles/BinaryTree.dir/objects1.rsp
BinaryTree.exe: CMakeFiles/BinaryTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\05code\2022\code-road\DataStructure\BinaryTree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable BinaryTree.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BinaryTree.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BinaryTree.dir/build: BinaryTree.exe

.PHONY : CMakeFiles/BinaryTree.dir/build

CMakeFiles/BinaryTree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BinaryTree.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BinaryTree.dir/clean

CMakeFiles/BinaryTree.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\05code\2022\code-road\DataStructure\BinaryTree D:\05code\2022\code-road\DataStructure\BinaryTree D:\05code\2022\code-road\DataStructure\BinaryTree\cmake-build-debug D:\05code\2022\code-road\DataStructure\BinaryTree\cmake-build-debug D:\05code\2022\code-road\DataStructure\BinaryTree\cmake-build-debug\CMakeFiles\BinaryTree.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BinaryTree.dir/depend
