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
CMAKE_SOURCE_DIR = D:\05code\2022\code-road\C_Language\Contact

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\05code\2022\code-road\C_Language\Contact\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Contact.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Contact.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Contact.dir/flags.make

CMakeFiles/Contact.dir/main.c.obj: CMakeFiles/Contact.dir/flags.make
CMakeFiles/Contact.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\05code\2022\code-road\C_Language\Contact\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Contact.dir/main.c.obj"
	"D:\Program Files\JetBrains\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Contact.dir\main.c.obj   -c D:\05code\2022\code-road\C_Language\Contact\main.c

CMakeFiles/Contact.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Contact.dir/main.c.i"
	"D:\Program Files\JetBrains\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\05code\2022\code-road\C_Language\Contact\main.c > CMakeFiles\Contact.dir\main.c.i

CMakeFiles/Contact.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Contact.dir/main.c.s"
	"D:\Program Files\JetBrains\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\05code\2022\code-road\C_Language\Contact\main.c -o CMakeFiles\Contact.dir\main.c.s

# Object files for target Contact
Contact_OBJECTS = \
"CMakeFiles/Contact.dir/main.c.obj"

# External object files for target Contact
Contact_EXTERNAL_OBJECTS =

Contact.exe: CMakeFiles/Contact.dir/main.c.obj
Contact.exe: CMakeFiles/Contact.dir/build.make
Contact.exe: CMakeFiles/Contact.dir/linklibs.rsp
Contact.exe: CMakeFiles/Contact.dir/objects1.rsp
Contact.exe: CMakeFiles/Contact.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\05code\2022\code-road\C_Language\Contact\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Contact.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Contact.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Contact.dir/build: Contact.exe

.PHONY : CMakeFiles/Contact.dir/build

CMakeFiles/Contact.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Contact.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Contact.dir/clean

CMakeFiles/Contact.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\05code\2022\code-road\C_Language\Contact D:\05code\2022\code-road\C_Language\Contact D:\05code\2022\code-road\C_Language\Contact\cmake-build-debug D:\05code\2022\code-road\C_Language\Contact\cmake-build-debug D:\05code\2022\code-road\C_Language\Contact\cmake-build-debug\CMakeFiles\Contact.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Contact.dir/depend

