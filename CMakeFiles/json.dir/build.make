# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lennygarnier/Delivery/Global-Game-Jam-

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lennygarnier/Delivery/Global-Game-Jam-

# Include any dependencies generated for this target.
include CMakeFiles/json.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/json.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/json.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/json.dir/flags.make

CMakeFiles/json.dir/src/game.cpp.o: CMakeFiles/json.dir/flags.make
CMakeFiles/json.dir/src/game.cpp.o: src/game.cpp
CMakeFiles/json.dir/src/game.cpp.o: CMakeFiles/json.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lennygarnier/Delivery/Global-Game-Jam-/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/json.dir/src/game.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/json.dir/src/game.cpp.o -MF CMakeFiles/json.dir/src/game.cpp.o.d -o CMakeFiles/json.dir/src/game.cpp.o -c /home/lennygarnier/Delivery/Global-Game-Jam-/src/game.cpp

CMakeFiles/json.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/json.dir/src/game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lennygarnier/Delivery/Global-Game-Jam-/src/game.cpp > CMakeFiles/json.dir/src/game.cpp.i

CMakeFiles/json.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/json.dir/src/game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lennygarnier/Delivery/Global-Game-Jam-/src/game.cpp -o CMakeFiles/json.dir/src/game.cpp.s

CMakeFiles/json.dir/src/main.cpp.o: CMakeFiles/json.dir/flags.make
CMakeFiles/json.dir/src/main.cpp.o: src/main.cpp
CMakeFiles/json.dir/src/main.cpp.o: CMakeFiles/json.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lennygarnier/Delivery/Global-Game-Jam-/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/json.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/json.dir/src/main.cpp.o -MF CMakeFiles/json.dir/src/main.cpp.o.d -o CMakeFiles/json.dir/src/main.cpp.o -c /home/lennygarnier/Delivery/Global-Game-Jam-/src/main.cpp

CMakeFiles/json.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/json.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lennygarnier/Delivery/Global-Game-Jam-/src/main.cpp > CMakeFiles/json.dir/src/main.cpp.i

CMakeFiles/json.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/json.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lennygarnier/Delivery/Global-Game-Jam-/src/main.cpp -o CMakeFiles/json.dir/src/main.cpp.s

CMakeFiles/json.dir/src/player.cpp.o: CMakeFiles/json.dir/flags.make
CMakeFiles/json.dir/src/player.cpp.o: src/player.cpp
CMakeFiles/json.dir/src/player.cpp.o: CMakeFiles/json.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lennygarnier/Delivery/Global-Game-Jam-/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/json.dir/src/player.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/json.dir/src/player.cpp.o -MF CMakeFiles/json.dir/src/player.cpp.o.d -o CMakeFiles/json.dir/src/player.cpp.o -c /home/lennygarnier/Delivery/Global-Game-Jam-/src/player.cpp

CMakeFiles/json.dir/src/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/json.dir/src/player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lennygarnier/Delivery/Global-Game-Jam-/src/player.cpp > CMakeFiles/json.dir/src/player.cpp.i

CMakeFiles/json.dir/src/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/json.dir/src/player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lennygarnier/Delivery/Global-Game-Jam-/src/player.cpp -o CMakeFiles/json.dir/src/player.cpp.s

CMakeFiles/json.dir/src/window.cpp.o: CMakeFiles/json.dir/flags.make
CMakeFiles/json.dir/src/window.cpp.o: src/window.cpp
CMakeFiles/json.dir/src/window.cpp.o: CMakeFiles/json.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lennygarnier/Delivery/Global-Game-Jam-/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/json.dir/src/window.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/json.dir/src/window.cpp.o -MF CMakeFiles/json.dir/src/window.cpp.o.d -o CMakeFiles/json.dir/src/window.cpp.o -c /home/lennygarnier/Delivery/Global-Game-Jam-/src/window.cpp

CMakeFiles/json.dir/src/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/json.dir/src/window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lennygarnier/Delivery/Global-Game-Jam-/src/window.cpp > CMakeFiles/json.dir/src/window.cpp.i

CMakeFiles/json.dir/src/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/json.dir/src/window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lennygarnier/Delivery/Global-Game-Jam-/src/window.cpp -o CMakeFiles/json.dir/src/window.cpp.s

# Object files for target json
json_OBJECTS = \
"CMakeFiles/json.dir/src/game.cpp.o" \
"CMakeFiles/json.dir/src/main.cpp.o" \
"CMakeFiles/json.dir/src/player.cpp.o" \
"CMakeFiles/json.dir/src/window.cpp.o"

# External object files for target json
json_EXTERNAL_OBJECTS =

json: CMakeFiles/json.dir/src/game.cpp.o
json: CMakeFiles/json.dir/src/main.cpp.o
json: CMakeFiles/json.dir/src/player.cpp.o
json: CMakeFiles/json.dir/src/window.cpp.o
json: CMakeFiles/json.dir/build.make
json: /usr/lib64/libjsoncpp.so.1.9.5
json: /usr/lib64/libsfml-graphics.so.2.5.1
json: /usr/lib64/libsfml-network.so.2.5.1
json: /usr/lib64/libsfml-audio.so.2.5.1
json: /usr/lib64/libsfml-window.so.2.5.1
json: /usr/lib64/libsfml-system.so.2.5.1
json: CMakeFiles/json.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lennygarnier/Delivery/Global-Game-Jam-/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable json"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/json.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/json.dir/build: json
.PHONY : CMakeFiles/json.dir/build

CMakeFiles/json.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/json.dir/cmake_clean.cmake
.PHONY : CMakeFiles/json.dir/clean

CMakeFiles/json.dir/depend:
	cd /home/lennygarnier/Delivery/Global-Game-Jam- && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lennygarnier/Delivery/Global-Game-Jam- /home/lennygarnier/Delivery/Global-Game-Jam- /home/lennygarnier/Delivery/Global-Game-Jam- /home/lennygarnier/Delivery/Global-Game-Jam- /home/lennygarnier/Delivery/Global-Game-Jam-/CMakeFiles/json.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/json.dir/depend
