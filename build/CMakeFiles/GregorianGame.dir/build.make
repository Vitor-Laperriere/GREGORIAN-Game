# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.0/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/vitorlaperriere/Desktop/USp/GREGORIAN-Game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/vitorlaperriere/Desktop/USp/GREGORIAN-Game/build

# Include any dependencies generated for this target.
include CMakeFiles/GregorianGame.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/GregorianGame.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/GregorianGame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GregorianGame.dir/flags.make

CMakeFiles/GregorianGame.dir/main.cpp.o: CMakeFiles/GregorianGame.dir/flags.make
CMakeFiles/GregorianGame.dir/main.cpp.o: /Users/vitorlaperriere/Desktop/USp/GREGORIAN-Game/main.cpp
CMakeFiles/GregorianGame.dir/main.cpp.o: CMakeFiles/GregorianGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/vitorlaperriere/Desktop/USp/GREGORIAN-Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GregorianGame.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GregorianGame.dir/main.cpp.o -MF CMakeFiles/GregorianGame.dir/main.cpp.o.d -o CMakeFiles/GregorianGame.dir/main.cpp.o -c /Users/vitorlaperriere/Desktop/USp/GREGORIAN-Game/main.cpp

CMakeFiles/GregorianGame.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GregorianGame.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vitorlaperriere/Desktop/USp/GREGORIAN-Game/main.cpp > CMakeFiles/GregorianGame.dir/main.cpp.i

CMakeFiles/GregorianGame.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GregorianGame.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vitorlaperriere/Desktop/USp/GREGORIAN-Game/main.cpp -o CMakeFiles/GregorianGame.dir/main.cpp.s

CMakeFiles/GregorianGame.dir/gregorian_game.cpp.o: CMakeFiles/GregorianGame.dir/flags.make
CMakeFiles/GregorianGame.dir/gregorian_game.cpp.o: /Users/vitorlaperriere/Desktop/USp/GREGORIAN-Game/gregorian_game.cpp
CMakeFiles/GregorianGame.dir/gregorian_game.cpp.o: CMakeFiles/GregorianGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/vitorlaperriere/Desktop/USp/GREGORIAN-Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GregorianGame.dir/gregorian_game.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GregorianGame.dir/gregorian_game.cpp.o -MF CMakeFiles/GregorianGame.dir/gregorian_game.cpp.o.d -o CMakeFiles/GregorianGame.dir/gregorian_game.cpp.o -c /Users/vitorlaperriere/Desktop/USp/GREGORIAN-Game/gregorian_game.cpp

CMakeFiles/GregorianGame.dir/gregorian_game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GregorianGame.dir/gregorian_game.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vitorlaperriere/Desktop/USp/GREGORIAN-Game/gregorian_game.cpp > CMakeFiles/GregorianGame.dir/gregorian_game.cpp.i

CMakeFiles/GregorianGame.dir/gregorian_game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GregorianGame.dir/gregorian_game.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vitorlaperriere/Desktop/USp/GREGORIAN-Game/gregorian_game.cpp -o CMakeFiles/GregorianGame.dir/gregorian_game.cpp.s

# Object files for target GregorianGame
GregorianGame_OBJECTS = \
"CMakeFiles/GregorianGame.dir/main.cpp.o" \
"CMakeFiles/GregorianGame.dir/gregorian_game.cpp.o"

# External object files for target GregorianGame
GregorianGame_EXTERNAL_OBJECTS =

GregorianGame: CMakeFiles/GregorianGame.dir/main.cpp.o
GregorianGame: CMakeFiles/GregorianGame.dir/gregorian_game.cpp.o
GregorianGame: CMakeFiles/GregorianGame.dir/build.make
GregorianGame: /opt/homebrew/lib/libsfml-graphics.2.6.1.dylib
GregorianGame: /opt/homebrew/lib/libsfml-window.2.6.1.dylib
GregorianGame: /opt/homebrew/lib/libsfml-system.2.6.1.dylib
GregorianGame: CMakeFiles/GregorianGame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/vitorlaperriere/Desktop/USp/GREGORIAN-Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable GregorianGame"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GregorianGame.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GregorianGame.dir/build: GregorianGame
.PHONY : CMakeFiles/GregorianGame.dir/build

CMakeFiles/GregorianGame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GregorianGame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GregorianGame.dir/clean

CMakeFiles/GregorianGame.dir/depend:
	cd /Users/vitorlaperriere/Desktop/USp/GREGORIAN-Game/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/vitorlaperriere/Desktop/USp/GREGORIAN-Game /Users/vitorlaperriere/Desktop/USp/GREGORIAN-Game /Users/vitorlaperriere/Desktop/USp/GREGORIAN-Game/build /Users/vitorlaperriere/Desktop/USp/GREGORIAN-Game/build /Users/vitorlaperriere/Desktop/USp/GREGORIAN-Game/build/CMakeFiles/GregorianGame.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/GregorianGame.dir/depend

