# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/robespierre/git/textruder

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/robespierre/git/textruder

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running interactive CMake command-line interface..."
	/usr/bin/cmake -i .
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/robespierre/git/textruder/CMakeFiles /home/robespierre/git/textruder/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/robespierre/git/textruder/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named textruder

# Build rule for target.
textruder: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 textruder
.PHONY : textruder

# fast build rule for target.
textruder/fast:
	$(MAKE) -f CMakeFiles/textruder.dir/build.make CMakeFiles/textruder.dir/build
.PHONY : textruder/fast

#=============================================================================
# Target rules for targets named txtruder

# Build rule for target.
txtruder: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 txtruder
.PHONY : txtruder

# fast build rule for target.
txtruder/fast:
	$(MAKE) -f CMakeFiles/txtruder.dir/build.make CMakeFiles/txtruder.dir/build
.PHONY : txtruder/fast

#=============================================================================
# Target rules for targets named Feeder

# Build rule for target.
Feeder: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Feeder
.PHONY : Feeder

# fast build rule for target.
Feeder/fast:
	$(MAKE) -f Feeder/CMakeFiles/Feeder.dir/build.make Feeder/CMakeFiles/Feeder.dir/build
.PHONY : Feeder/fast

#=============================================================================
# Target rules for targets named Nozzle

# Build rule for target.
Nozzle: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Nozzle
.PHONY : Nozzle

# fast build rule for target.
Nozzle/fast:
	$(MAKE) -f Nozzle/CMakeFiles/Nozzle.dir/build.make Nozzle/CMakeFiles/Nozzle.dir/build
.PHONY : Nozzle/fast

Textruder.o: Textruder.cpp.o
.PHONY : Textruder.o

# target to build an object file
Textruder.cpp.o:
	$(MAKE) -f CMakeFiles/txtruder.dir/build.make CMakeFiles/txtruder.dir/Textruder.cpp.o
.PHONY : Textruder.cpp.o

Textruder.i: Textruder.cpp.i
.PHONY : Textruder.i

# target to preprocess a source file
Textruder.cpp.i:
	$(MAKE) -f CMakeFiles/txtruder.dir/build.make CMakeFiles/txtruder.dir/Textruder.cpp.i
.PHONY : Textruder.cpp.i

Textruder.s: Textruder.cpp.s
.PHONY : Textruder.s

# target to generate assembly for a file
Textruder.cpp.s:
	$(MAKE) -f CMakeFiles/txtruder.dir/build.make CMakeFiles/txtruder.dir/Textruder.cpp.s
.PHONY : Textruder.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/textruder.dir/build.make CMakeFiles/textruder.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/textruder.dir/build.make CMakeFiles/textruder.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/textruder.dir/build.make CMakeFiles/textruder.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... textruder"
	@echo "... txtruder"
	@echo "... Feeder"
	@echo "... Nozzle"
	@echo "... Textruder.o"
	@echo "... Textruder.i"
	@echo "... Textruder.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
