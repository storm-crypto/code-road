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
CMAKE_SOURCE_DIR = D:\05code\2022\code-road\C_Language\text_7_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\05code\2022\code-road\C_Language\text_7_1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/text_7_1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/text_7_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/text_7_1.dir/flags.make

CMakeFiles/text_7_1.dir/main.c.obj: CMakeFiles/text_7_1.dir/flags.make
CMakeFiles/text_7_1.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\05code\2022\code-road\C_Language\text_7_1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/text_7_1.dir/main.c.obj"
	"D:\Program Files\JetBrains\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\text_7_1.dir\main.c.obj   -c D:\05code\2022\code-road\C_Language\text_7_1\main.c

CMakeFiles/text_7_1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/text_7_1.dir/main.c.i"
	"D:\Program Files\JetBrains\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\05code\2022\code-road\C_Language\text_7_1\main.c > CMakeFiles\text_7_1.dir\main.c.i

CMakeFiles/text_7_1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/text_7_1.dir/main.c.s"
	"D:\Program Files\JetBrains\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\05code\2022\code-road\C_Language\text_7_1\main.c -o CMakeFiles\text_7_1.dir\main.c.s

# Object files for target text_7_1
text_7_1_OBJECTS = \
"CMakeFiles/text_7_1.dir/main.c.obj"

# External object files for target text_7_1
text_7_1_EXTERNAL_OBJECTS =

text_7_1.exe: CMakeFiles/text_7_1.dir/main.c.obj
text_7_1.exe: CMakeFiles/text_7_1.dir/build.make
text_7_1.exe: CMakeFiles/text_7_1.dir/linklibs.rsp
text_7_1.exe: CMakeFiles/text_7_1.dir/objects1.rsp
text_7_1.exe: CMakeFiles/text_7_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\05code\2022\code-road\C_Language\text_7_1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable text_7_1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\text_7_1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/text_7_1.dir/build: text_7_1.exe

.PHONY : CMakeFiles/text_7_1.dir/build

CMakeFiles/text_7_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\text_7_1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/text_7_1.dir/clean

CMakeFiles/text_7_1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\05code\2022\code-road\C_Language\text_7_1 D:\05code\2022\code-road\C_Language\text_7_1 D:\05code\2022\code-road\C_Language\text_7_1\cmake-build-debug D:\05code\2022\code-road\C_Language\text_7_1\cmake-build-debug D:\05code\2022\code-road\C_Language\text_7_1\cmake-build-debug\CMakeFiles\text_7_1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/text_7_1.dir/depend

