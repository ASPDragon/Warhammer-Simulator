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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/iocaster/GitHub/Warhammer-Simulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/iocaster/GitHub/Warhammer-Simulator/build

# Include any dependencies generated for this target.
include CMakeFiles/Warhammer-Simulator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Warhammer-Simulator.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Warhammer-Simulator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Warhammer-Simulator.dir/flags.make

CMakeFiles/Warhammer-Simulator.dir/src/datasheet.cpp.o: CMakeFiles/Warhammer-Simulator.dir/flags.make
CMakeFiles/Warhammer-Simulator.dir/src/datasheet.cpp.o: /Users/iocaster/GitHub/Warhammer-Simulator/src/datasheet.cpp
CMakeFiles/Warhammer-Simulator.dir/src/datasheet.cpp.o: CMakeFiles/Warhammer-Simulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/iocaster/GitHub/Warhammer-Simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Warhammer-Simulator.dir/src/datasheet.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Warhammer-Simulator.dir/src/datasheet.cpp.o -MF CMakeFiles/Warhammer-Simulator.dir/src/datasheet.cpp.o.d -o CMakeFiles/Warhammer-Simulator.dir/src/datasheet.cpp.o -c /Users/iocaster/GitHub/Warhammer-Simulator/src/datasheet.cpp

CMakeFiles/Warhammer-Simulator.dir/src/datasheet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Warhammer-Simulator.dir/src/datasheet.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/iocaster/GitHub/Warhammer-Simulator/src/datasheet.cpp > CMakeFiles/Warhammer-Simulator.dir/src/datasheet.cpp.i

CMakeFiles/Warhammer-Simulator.dir/src/datasheet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Warhammer-Simulator.dir/src/datasheet.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/iocaster/GitHub/Warhammer-Simulator/src/datasheet.cpp -o CMakeFiles/Warhammer-Simulator.dir/src/datasheet.cpp.s

CMakeFiles/Warhammer-Simulator.dir/src/main.cpp.o: CMakeFiles/Warhammer-Simulator.dir/flags.make
CMakeFiles/Warhammer-Simulator.dir/src/main.cpp.o: /Users/iocaster/GitHub/Warhammer-Simulator/src/main.cpp
CMakeFiles/Warhammer-Simulator.dir/src/main.cpp.o: CMakeFiles/Warhammer-Simulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/iocaster/GitHub/Warhammer-Simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Warhammer-Simulator.dir/src/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Warhammer-Simulator.dir/src/main.cpp.o -MF CMakeFiles/Warhammer-Simulator.dir/src/main.cpp.o.d -o CMakeFiles/Warhammer-Simulator.dir/src/main.cpp.o -c /Users/iocaster/GitHub/Warhammer-Simulator/src/main.cpp

CMakeFiles/Warhammer-Simulator.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Warhammer-Simulator.dir/src/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/iocaster/GitHub/Warhammer-Simulator/src/main.cpp > CMakeFiles/Warhammer-Simulator.dir/src/main.cpp.i

CMakeFiles/Warhammer-Simulator.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Warhammer-Simulator.dir/src/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/iocaster/GitHub/Warhammer-Simulator/src/main.cpp -o CMakeFiles/Warhammer-Simulator.dir/src/main.cpp.s

CMakeFiles/Warhammer-Simulator.dir/src/weapon.cpp.o: CMakeFiles/Warhammer-Simulator.dir/flags.make
CMakeFiles/Warhammer-Simulator.dir/src/weapon.cpp.o: /Users/iocaster/GitHub/Warhammer-Simulator/src/weapon.cpp
CMakeFiles/Warhammer-Simulator.dir/src/weapon.cpp.o: CMakeFiles/Warhammer-Simulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/iocaster/GitHub/Warhammer-Simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Warhammer-Simulator.dir/src/weapon.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Warhammer-Simulator.dir/src/weapon.cpp.o -MF CMakeFiles/Warhammer-Simulator.dir/src/weapon.cpp.o.d -o CMakeFiles/Warhammer-Simulator.dir/src/weapon.cpp.o -c /Users/iocaster/GitHub/Warhammer-Simulator/src/weapon.cpp

CMakeFiles/Warhammer-Simulator.dir/src/weapon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Warhammer-Simulator.dir/src/weapon.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/iocaster/GitHub/Warhammer-Simulator/src/weapon.cpp > CMakeFiles/Warhammer-Simulator.dir/src/weapon.cpp.i

CMakeFiles/Warhammer-Simulator.dir/src/weapon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Warhammer-Simulator.dir/src/weapon.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/iocaster/GitHub/Warhammer-Simulator/src/weapon.cpp -o CMakeFiles/Warhammer-Simulator.dir/src/weapon.cpp.s

# Object files for target Warhammer-Simulator
Warhammer__Simulator_OBJECTS = \
"CMakeFiles/Warhammer-Simulator.dir/src/datasheet.cpp.o" \
"CMakeFiles/Warhammer-Simulator.dir/src/main.cpp.o" \
"CMakeFiles/Warhammer-Simulator.dir/src/weapon.cpp.o"

# External object files for target Warhammer-Simulator
Warhammer__Simulator_EXTERNAL_OBJECTS =

Warhammer-Simulator: CMakeFiles/Warhammer-Simulator.dir/src/datasheet.cpp.o
Warhammer-Simulator: CMakeFiles/Warhammer-Simulator.dir/src/main.cpp.o
Warhammer-Simulator: CMakeFiles/Warhammer-Simulator.dir/src/weapon.cpp.o
Warhammer-Simulator: CMakeFiles/Warhammer-Simulator.dir/build.make
Warhammer-Simulator: CMakeFiles/Warhammer-Simulator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/iocaster/GitHub/Warhammer-Simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Warhammer-Simulator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Warhammer-Simulator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Warhammer-Simulator.dir/build: Warhammer-Simulator
.PHONY : CMakeFiles/Warhammer-Simulator.dir/build

CMakeFiles/Warhammer-Simulator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Warhammer-Simulator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Warhammer-Simulator.dir/clean

CMakeFiles/Warhammer-Simulator.dir/depend:
	cd /Users/iocaster/GitHub/Warhammer-Simulator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/iocaster/GitHub/Warhammer-Simulator /Users/iocaster/GitHub/Warhammer-Simulator /Users/iocaster/GitHub/Warhammer-Simulator/build /Users/iocaster/GitHub/Warhammer-Simulator/build /Users/iocaster/GitHub/Warhammer-Simulator/build/CMakeFiles/Warhammer-Simulator.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Warhammer-Simulator.dir/depend
