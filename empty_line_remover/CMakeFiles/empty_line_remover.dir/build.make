# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /home/yegor/clion-2024.2.1/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /home/yegor/clion-2024.2.1/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yegor/Github/petits_c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yegor/Github/petits_c

# Include any dependencies generated for this target.
include empty_line_remover/CMakeFiles/empty_line_remover.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include empty_line_remover/CMakeFiles/empty_line_remover.dir/compiler_depend.make

# Include the progress variables for this target.
include empty_line_remover/CMakeFiles/empty_line_remover.dir/progress.make

# Include the compile flags for this target's objects.
include empty_line_remover/CMakeFiles/empty_line_remover.dir/flags.make

empty_line_remover/CMakeFiles/empty_line_remover.dir/main.c.o: empty_line_remover/CMakeFiles/empty_line_remover.dir/flags.make
empty_line_remover/CMakeFiles/empty_line_remover.dir/main.c.o: empty_line_remover/main.c
empty_line_remover/CMakeFiles/empty_line_remover.dir/main.c.o: empty_line_remover/CMakeFiles/empty_line_remover.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yegor/Github/petits_c/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object empty_line_remover/CMakeFiles/empty_line_remover.dir/main.c.o"
	cd /home/yegor/Github/petits_c/empty_line_remover && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT empty_line_remover/CMakeFiles/empty_line_remover.dir/main.c.o -MF CMakeFiles/empty_line_remover.dir/main.c.o.d -o CMakeFiles/empty_line_remover.dir/main.c.o -c /home/yegor/Github/petits_c/empty_line_remover/main.c

empty_line_remover/CMakeFiles/empty_line_remover.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/empty_line_remover.dir/main.c.i"
	cd /home/yegor/Github/petits_c/empty_line_remover && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yegor/Github/petits_c/empty_line_remover/main.c > CMakeFiles/empty_line_remover.dir/main.c.i

empty_line_remover/CMakeFiles/empty_line_remover.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/empty_line_remover.dir/main.c.s"
	cd /home/yegor/Github/petits_c/empty_line_remover && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yegor/Github/petits_c/empty_line_remover/main.c -o CMakeFiles/empty_line_remover.dir/main.c.s

# Object files for target empty_line_remover
empty_line_remover_OBJECTS = \
"CMakeFiles/empty_line_remover.dir/main.c.o"

# External object files for target empty_line_remover
empty_line_remover_EXTERNAL_OBJECTS =

empty_line_remover/empty_line_remover: empty_line_remover/CMakeFiles/empty_line_remover.dir/main.c.o
empty_line_remover/empty_line_remover: empty_line_remover/CMakeFiles/empty_line_remover.dir/build.make
empty_line_remover/empty_line_remover: empty_line_remover/CMakeFiles/empty_line_remover.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/yegor/Github/petits_c/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable empty_line_remover"
	cd /home/yegor/Github/petits_c/empty_line_remover && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/empty_line_remover.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
empty_line_remover/CMakeFiles/empty_line_remover.dir/build: empty_line_remover/empty_line_remover
.PHONY : empty_line_remover/CMakeFiles/empty_line_remover.dir/build

empty_line_remover/CMakeFiles/empty_line_remover.dir/clean:
	cd /home/yegor/Github/petits_c/empty_line_remover && $(CMAKE_COMMAND) -P CMakeFiles/empty_line_remover.dir/cmake_clean.cmake
.PHONY : empty_line_remover/CMakeFiles/empty_line_remover.dir/clean

empty_line_remover/CMakeFiles/empty_line_remover.dir/depend:
	cd /home/yegor/Github/petits_c && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yegor/Github/petits_c /home/yegor/Github/petits_c/empty_line_remover /home/yegor/Github/petits_c /home/yegor/Github/petits_c/empty_line_remover /home/yegor/Github/petits_c/empty_line_remover/CMakeFiles/empty_line_remover.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : empty_line_remover/CMakeFiles/empty_line_remover.dir/depend

