# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sagi/Desktop/vscode/Automated-FRC-Scouting

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sagi/Desktop/vscode/Automated-FRC-Scouting

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/sagi/Desktop/vscode/Automated-FRC-Scouting/CMakeFiles /home/sagi/Desktop/vscode/Automated-FRC-Scouting//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/sagi/Desktop/vscode/Automated-FRC-Scouting/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named main

# Build rule for target.
main: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 main
.PHONY : main

# fast build rule for target.
main/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/build
.PHONY : main/fast

c++/src/field.o: c++/src/field.cpp.o
.PHONY : c++/src/field.o

# target to build an object file
c++/src/field.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/c++/src/field.cpp.o
.PHONY : c++/src/field.cpp.o

c++/src/field.i: c++/src/field.cpp.i
.PHONY : c++/src/field.i

# target to preprocess a source file
c++/src/field.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/c++/src/field.cpp.i
.PHONY : c++/src/field.cpp.i

c++/src/field.s: c++/src/field.cpp.s
.PHONY : c++/src/field.s

# target to generate assembly for a file
c++/src/field.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/c++/src/field.cpp.s
.PHONY : c++/src/field.cpp.s

c++/src/main.o: c++/src/main.cpp.o
.PHONY : c++/src/main.o

# target to build an object file
c++/src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/c++/src/main.cpp.o
.PHONY : c++/src/main.cpp.o

c++/src/main.i: c++/src/main.cpp.i
.PHONY : c++/src/main.i

# target to preprocess a source file
c++/src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/c++/src/main.cpp.i
.PHONY : c++/src/main.cpp.i

c++/src/main.s: c++/src/main.cpp.s
.PHONY : c++/src/main.s

# target to generate assembly for a file
c++/src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/c++/src/main.cpp.s
.PHONY : c++/src/main.cpp.s

c++/src/robot.o: c++/src/robot.cpp.o
.PHONY : c++/src/robot.o

# target to build an object file
c++/src/robot.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/c++/src/robot.cpp.o
.PHONY : c++/src/robot.cpp.o

c++/src/robot.i: c++/src/robot.cpp.i
.PHONY : c++/src/robot.i

# target to preprocess a source file
c++/src/robot.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/c++/src/robot.cpp.i
.PHONY : c++/src/robot.cpp.i

c++/src/robot.s: c++/src/robot.cpp.s
.PHONY : c++/src/robot.s

# target to generate assembly for a file
c++/src/robot.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/c++/src/robot.cpp.s
.PHONY : c++/src/robot.cpp.s

c++/src/test2.o: c++/src/test2.cpp.o
.PHONY : c++/src/test2.o

# target to build an object file
c++/src/test2.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/c++/src/test2.cpp.o
.PHONY : c++/src/test2.cpp.o

c++/src/test2.i: c++/src/test2.cpp.i
.PHONY : c++/src/test2.i

# target to preprocess a source file
c++/src/test2.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/c++/src/test2.cpp.i
.PHONY : c++/src/test2.cpp.i

c++/src/test2.s: c++/src/test2.cpp.s
.PHONY : c++/src/test2.s

# target to generate assembly for a file
c++/src/test2.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/c++/src/test2.cpp.s
.PHONY : c++/src/test2.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... main"
	@echo "... c++/src/field.o"
	@echo "... c++/src/field.i"
	@echo "... c++/src/field.s"
	@echo "... c++/src/main.o"
	@echo "... c++/src/main.i"
	@echo "... c++/src/main.s"
	@echo "... c++/src/robot.o"
	@echo "... c++/src/robot.i"
	@echo "... c++/src/robot.s"
	@echo "... c++/src/test2.o"
	@echo "... c++/src/test2.i"
	@echo "... c++/src/test2.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

