# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /home/guiviko/Programs/clion-2016.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/guiviko/Programs/clion-2016.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/guiviko/Projects/chrono

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/guiviko/Projects/chrono/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SFMLDemo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SFMLDemo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SFMLDemo.dir/flags.make

CMakeFiles/SFMLDemo.dir/main.cpp.o: CMakeFiles/SFMLDemo.dir/flags.make
CMakeFiles/SFMLDemo.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guiviko/Projects/chrono/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SFMLDemo.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SFMLDemo.dir/main.cpp.o -c /home/guiviko/Projects/chrono/main.cpp

CMakeFiles/SFMLDemo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SFMLDemo.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guiviko/Projects/chrono/main.cpp > CMakeFiles/SFMLDemo.dir/main.cpp.i

CMakeFiles/SFMLDemo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SFMLDemo.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guiviko/Projects/chrono/main.cpp -o CMakeFiles/SFMLDemo.dir/main.cpp.s

CMakeFiles/SFMLDemo.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/SFMLDemo.dir/main.cpp.o.requires

CMakeFiles/SFMLDemo.dir/main.cpp.o.provides: CMakeFiles/SFMLDemo.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/SFMLDemo.dir/build.make CMakeFiles/SFMLDemo.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/SFMLDemo.dir/main.cpp.o.provides

CMakeFiles/SFMLDemo.dir/main.cpp.o.provides.build: CMakeFiles/SFMLDemo.dir/main.cpp.o


CMakeFiles/SFMLDemo.dir/src/core/Engine.cpp.o: CMakeFiles/SFMLDemo.dir/flags.make
CMakeFiles/SFMLDemo.dir/src/core/Engine.cpp.o: ../src/core/Engine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guiviko/Projects/chrono/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SFMLDemo.dir/src/core/Engine.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SFMLDemo.dir/src/core/Engine.cpp.o -c /home/guiviko/Projects/chrono/src/core/Engine.cpp

CMakeFiles/SFMLDemo.dir/src/core/Engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SFMLDemo.dir/src/core/Engine.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guiviko/Projects/chrono/src/core/Engine.cpp > CMakeFiles/SFMLDemo.dir/src/core/Engine.cpp.i

CMakeFiles/SFMLDemo.dir/src/core/Engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SFMLDemo.dir/src/core/Engine.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guiviko/Projects/chrono/src/core/Engine.cpp -o CMakeFiles/SFMLDemo.dir/src/core/Engine.cpp.s

CMakeFiles/SFMLDemo.dir/src/core/Engine.cpp.o.requires:

.PHONY : CMakeFiles/SFMLDemo.dir/src/core/Engine.cpp.o.requires

CMakeFiles/SFMLDemo.dir/src/core/Engine.cpp.o.provides: CMakeFiles/SFMLDemo.dir/src/core/Engine.cpp.o.requires
	$(MAKE) -f CMakeFiles/SFMLDemo.dir/build.make CMakeFiles/SFMLDemo.dir/src/core/Engine.cpp.o.provides.build
.PHONY : CMakeFiles/SFMLDemo.dir/src/core/Engine.cpp.o.provides

CMakeFiles/SFMLDemo.dir/src/core/Engine.cpp.o.provides.build: CMakeFiles/SFMLDemo.dir/src/core/Engine.cpp.o


CMakeFiles/SFMLDemo.dir/src/windows/Context.cpp.o: CMakeFiles/SFMLDemo.dir/flags.make
CMakeFiles/SFMLDemo.dir/src/windows/Context.cpp.o: ../src/windows/Context.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guiviko/Projects/chrono/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SFMLDemo.dir/src/windows/Context.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SFMLDemo.dir/src/windows/Context.cpp.o -c /home/guiviko/Projects/chrono/src/windows/Context.cpp

CMakeFiles/SFMLDemo.dir/src/windows/Context.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SFMLDemo.dir/src/windows/Context.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guiviko/Projects/chrono/src/windows/Context.cpp > CMakeFiles/SFMLDemo.dir/src/windows/Context.cpp.i

CMakeFiles/SFMLDemo.dir/src/windows/Context.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SFMLDemo.dir/src/windows/Context.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guiviko/Projects/chrono/src/windows/Context.cpp -o CMakeFiles/SFMLDemo.dir/src/windows/Context.cpp.s

CMakeFiles/SFMLDemo.dir/src/windows/Context.cpp.o.requires:

.PHONY : CMakeFiles/SFMLDemo.dir/src/windows/Context.cpp.o.requires

CMakeFiles/SFMLDemo.dir/src/windows/Context.cpp.o.provides: CMakeFiles/SFMLDemo.dir/src/windows/Context.cpp.o.requires
	$(MAKE) -f CMakeFiles/SFMLDemo.dir/build.make CMakeFiles/SFMLDemo.dir/src/windows/Context.cpp.o.provides.build
.PHONY : CMakeFiles/SFMLDemo.dir/src/windows/Context.cpp.o.provides

CMakeFiles/SFMLDemo.dir/src/windows/Context.cpp.o.provides.build: CMakeFiles/SFMLDemo.dir/src/windows/Context.cpp.o


CMakeFiles/SFMLDemo.dir/src/windows/MainMenu.cpp.o: CMakeFiles/SFMLDemo.dir/flags.make
CMakeFiles/SFMLDemo.dir/src/windows/MainMenu.cpp.o: ../src/windows/MainMenu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guiviko/Projects/chrono/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SFMLDemo.dir/src/windows/MainMenu.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SFMLDemo.dir/src/windows/MainMenu.cpp.o -c /home/guiviko/Projects/chrono/src/windows/MainMenu.cpp

CMakeFiles/SFMLDemo.dir/src/windows/MainMenu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SFMLDemo.dir/src/windows/MainMenu.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guiviko/Projects/chrono/src/windows/MainMenu.cpp > CMakeFiles/SFMLDemo.dir/src/windows/MainMenu.cpp.i

CMakeFiles/SFMLDemo.dir/src/windows/MainMenu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SFMLDemo.dir/src/windows/MainMenu.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guiviko/Projects/chrono/src/windows/MainMenu.cpp -o CMakeFiles/SFMLDemo.dir/src/windows/MainMenu.cpp.s

CMakeFiles/SFMLDemo.dir/src/windows/MainMenu.cpp.o.requires:

.PHONY : CMakeFiles/SFMLDemo.dir/src/windows/MainMenu.cpp.o.requires

CMakeFiles/SFMLDemo.dir/src/windows/MainMenu.cpp.o.provides: CMakeFiles/SFMLDemo.dir/src/windows/MainMenu.cpp.o.requires
	$(MAKE) -f CMakeFiles/SFMLDemo.dir/build.make CMakeFiles/SFMLDemo.dir/src/windows/MainMenu.cpp.o.provides.build
.PHONY : CMakeFiles/SFMLDemo.dir/src/windows/MainMenu.cpp.o.provides

CMakeFiles/SFMLDemo.dir/src/windows/MainMenu.cpp.o.provides.build: CMakeFiles/SFMLDemo.dir/src/windows/MainMenu.cpp.o


CMakeFiles/SFMLDemo.dir/src/windows/ContextSwitcher.cpp.o: CMakeFiles/SFMLDemo.dir/flags.make
CMakeFiles/SFMLDemo.dir/src/windows/ContextSwitcher.cpp.o: ../src/windows/ContextSwitcher.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guiviko/Projects/chrono/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SFMLDemo.dir/src/windows/ContextSwitcher.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SFMLDemo.dir/src/windows/ContextSwitcher.cpp.o -c /home/guiviko/Projects/chrono/src/windows/ContextSwitcher.cpp

CMakeFiles/SFMLDemo.dir/src/windows/ContextSwitcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SFMLDemo.dir/src/windows/ContextSwitcher.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guiviko/Projects/chrono/src/windows/ContextSwitcher.cpp > CMakeFiles/SFMLDemo.dir/src/windows/ContextSwitcher.cpp.i

CMakeFiles/SFMLDemo.dir/src/windows/ContextSwitcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SFMLDemo.dir/src/windows/ContextSwitcher.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guiviko/Projects/chrono/src/windows/ContextSwitcher.cpp -o CMakeFiles/SFMLDemo.dir/src/windows/ContextSwitcher.cpp.s

CMakeFiles/SFMLDemo.dir/src/windows/ContextSwitcher.cpp.o.requires:

.PHONY : CMakeFiles/SFMLDemo.dir/src/windows/ContextSwitcher.cpp.o.requires

CMakeFiles/SFMLDemo.dir/src/windows/ContextSwitcher.cpp.o.provides: CMakeFiles/SFMLDemo.dir/src/windows/ContextSwitcher.cpp.o.requires
	$(MAKE) -f CMakeFiles/SFMLDemo.dir/build.make CMakeFiles/SFMLDemo.dir/src/windows/ContextSwitcher.cpp.o.provides.build
.PHONY : CMakeFiles/SFMLDemo.dir/src/windows/ContextSwitcher.cpp.o.provides

CMakeFiles/SFMLDemo.dir/src/windows/ContextSwitcher.cpp.o.provides.build: CMakeFiles/SFMLDemo.dir/src/windows/ContextSwitcher.cpp.o


CMakeFiles/SFMLDemo.dir/src/Characters/Character.cpp.o: CMakeFiles/SFMLDemo.dir/flags.make
CMakeFiles/SFMLDemo.dir/src/Characters/Character.cpp.o: ../src/Characters/Character.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guiviko/Projects/chrono/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SFMLDemo.dir/src/Characters/Character.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SFMLDemo.dir/src/Characters/Character.cpp.o -c /home/guiviko/Projects/chrono/src/Characters/Character.cpp

CMakeFiles/SFMLDemo.dir/src/Characters/Character.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SFMLDemo.dir/src/Characters/Character.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guiviko/Projects/chrono/src/Characters/Character.cpp > CMakeFiles/SFMLDemo.dir/src/Characters/Character.cpp.i

CMakeFiles/SFMLDemo.dir/src/Characters/Character.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SFMLDemo.dir/src/Characters/Character.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guiviko/Projects/chrono/src/Characters/Character.cpp -o CMakeFiles/SFMLDemo.dir/src/Characters/Character.cpp.s

CMakeFiles/SFMLDemo.dir/src/Characters/Character.cpp.o.requires:

.PHONY : CMakeFiles/SFMLDemo.dir/src/Characters/Character.cpp.o.requires

CMakeFiles/SFMLDemo.dir/src/Characters/Character.cpp.o.provides: CMakeFiles/SFMLDemo.dir/src/Characters/Character.cpp.o.requires
	$(MAKE) -f CMakeFiles/SFMLDemo.dir/build.make CMakeFiles/SFMLDemo.dir/src/Characters/Character.cpp.o.provides.build
.PHONY : CMakeFiles/SFMLDemo.dir/src/Characters/Character.cpp.o.provides

CMakeFiles/SFMLDemo.dir/src/Characters/Character.cpp.o.provides.build: CMakeFiles/SFMLDemo.dir/src/Characters/Character.cpp.o


CMakeFiles/SFMLDemo.dir/src/maps/Map.cpp.o: CMakeFiles/SFMLDemo.dir/flags.make
CMakeFiles/SFMLDemo.dir/src/maps/Map.cpp.o: ../src/maps/Map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guiviko/Projects/chrono/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/SFMLDemo.dir/src/maps/Map.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SFMLDemo.dir/src/maps/Map.cpp.o -c /home/guiviko/Projects/chrono/src/maps/Map.cpp

CMakeFiles/SFMLDemo.dir/src/maps/Map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SFMLDemo.dir/src/maps/Map.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guiviko/Projects/chrono/src/maps/Map.cpp > CMakeFiles/SFMLDemo.dir/src/maps/Map.cpp.i

CMakeFiles/SFMLDemo.dir/src/maps/Map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SFMLDemo.dir/src/maps/Map.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guiviko/Projects/chrono/src/maps/Map.cpp -o CMakeFiles/SFMLDemo.dir/src/maps/Map.cpp.s

CMakeFiles/SFMLDemo.dir/src/maps/Map.cpp.o.requires:

.PHONY : CMakeFiles/SFMLDemo.dir/src/maps/Map.cpp.o.requires

CMakeFiles/SFMLDemo.dir/src/maps/Map.cpp.o.provides: CMakeFiles/SFMLDemo.dir/src/maps/Map.cpp.o.requires
	$(MAKE) -f CMakeFiles/SFMLDemo.dir/build.make CMakeFiles/SFMLDemo.dir/src/maps/Map.cpp.o.provides.build
.PHONY : CMakeFiles/SFMLDemo.dir/src/maps/Map.cpp.o.provides

CMakeFiles/SFMLDemo.dir/src/maps/Map.cpp.o.provides.build: CMakeFiles/SFMLDemo.dir/src/maps/Map.cpp.o


CMakeFiles/SFMLDemo.dir/src/maps/town/Town.cpp.o: CMakeFiles/SFMLDemo.dir/flags.make
CMakeFiles/SFMLDemo.dir/src/maps/town/Town.cpp.o: ../src/maps/town/Town.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guiviko/Projects/chrono/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/SFMLDemo.dir/src/maps/town/Town.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SFMLDemo.dir/src/maps/town/Town.cpp.o -c /home/guiviko/Projects/chrono/src/maps/town/Town.cpp

CMakeFiles/SFMLDemo.dir/src/maps/town/Town.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SFMLDemo.dir/src/maps/town/Town.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guiviko/Projects/chrono/src/maps/town/Town.cpp > CMakeFiles/SFMLDemo.dir/src/maps/town/Town.cpp.i

CMakeFiles/SFMLDemo.dir/src/maps/town/Town.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SFMLDemo.dir/src/maps/town/Town.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guiviko/Projects/chrono/src/maps/town/Town.cpp -o CMakeFiles/SFMLDemo.dir/src/maps/town/Town.cpp.s

CMakeFiles/SFMLDemo.dir/src/maps/town/Town.cpp.o.requires:

.PHONY : CMakeFiles/SFMLDemo.dir/src/maps/town/Town.cpp.o.requires

CMakeFiles/SFMLDemo.dir/src/maps/town/Town.cpp.o.provides: CMakeFiles/SFMLDemo.dir/src/maps/town/Town.cpp.o.requires
	$(MAKE) -f CMakeFiles/SFMLDemo.dir/build.make CMakeFiles/SFMLDemo.dir/src/maps/town/Town.cpp.o.provides.build
.PHONY : CMakeFiles/SFMLDemo.dir/src/maps/town/Town.cpp.o.provides

CMakeFiles/SFMLDemo.dir/src/maps/town/Town.cpp.o.provides.build: CMakeFiles/SFMLDemo.dir/src/maps/town/Town.cpp.o


CMakeFiles/SFMLDemo.dir/src/utils/Logger.cpp.o: CMakeFiles/SFMLDemo.dir/flags.make
CMakeFiles/SFMLDemo.dir/src/utils/Logger.cpp.o: ../src/utils/Logger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guiviko/Projects/chrono/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/SFMLDemo.dir/src/utils/Logger.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SFMLDemo.dir/src/utils/Logger.cpp.o -c /home/guiviko/Projects/chrono/src/utils/Logger.cpp

CMakeFiles/SFMLDemo.dir/src/utils/Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SFMLDemo.dir/src/utils/Logger.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guiviko/Projects/chrono/src/utils/Logger.cpp > CMakeFiles/SFMLDemo.dir/src/utils/Logger.cpp.i

CMakeFiles/SFMLDemo.dir/src/utils/Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SFMLDemo.dir/src/utils/Logger.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guiviko/Projects/chrono/src/utils/Logger.cpp -o CMakeFiles/SFMLDemo.dir/src/utils/Logger.cpp.s

CMakeFiles/SFMLDemo.dir/src/utils/Logger.cpp.o.requires:

.PHONY : CMakeFiles/SFMLDemo.dir/src/utils/Logger.cpp.o.requires

CMakeFiles/SFMLDemo.dir/src/utils/Logger.cpp.o.provides: CMakeFiles/SFMLDemo.dir/src/utils/Logger.cpp.o.requires
	$(MAKE) -f CMakeFiles/SFMLDemo.dir/build.make CMakeFiles/SFMLDemo.dir/src/utils/Logger.cpp.o.provides.build
.PHONY : CMakeFiles/SFMLDemo.dir/src/utils/Logger.cpp.o.provides

CMakeFiles/SFMLDemo.dir/src/utils/Logger.cpp.o.provides.build: CMakeFiles/SFMLDemo.dir/src/utils/Logger.cpp.o


CMakeFiles/SFMLDemo.dir/src/core/Actions.cpp.o: CMakeFiles/SFMLDemo.dir/flags.make
CMakeFiles/SFMLDemo.dir/src/core/Actions.cpp.o: ../src/core/Actions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guiviko/Projects/chrono/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/SFMLDemo.dir/src/core/Actions.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SFMLDemo.dir/src/core/Actions.cpp.o -c /home/guiviko/Projects/chrono/src/core/Actions.cpp

CMakeFiles/SFMLDemo.dir/src/core/Actions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SFMLDemo.dir/src/core/Actions.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guiviko/Projects/chrono/src/core/Actions.cpp > CMakeFiles/SFMLDemo.dir/src/core/Actions.cpp.i

CMakeFiles/SFMLDemo.dir/src/core/Actions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SFMLDemo.dir/src/core/Actions.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guiviko/Projects/chrono/src/core/Actions.cpp -o CMakeFiles/SFMLDemo.dir/src/core/Actions.cpp.s

CMakeFiles/SFMLDemo.dir/src/core/Actions.cpp.o.requires:

.PHONY : CMakeFiles/SFMLDemo.dir/src/core/Actions.cpp.o.requires

CMakeFiles/SFMLDemo.dir/src/core/Actions.cpp.o.provides: CMakeFiles/SFMLDemo.dir/src/core/Actions.cpp.o.requires
	$(MAKE) -f CMakeFiles/SFMLDemo.dir/build.make CMakeFiles/SFMLDemo.dir/src/core/Actions.cpp.o.provides.build
.PHONY : CMakeFiles/SFMLDemo.dir/src/core/Actions.cpp.o.provides

CMakeFiles/SFMLDemo.dir/src/core/Actions.cpp.o.provides.build: CMakeFiles/SFMLDemo.dir/src/core/Actions.cpp.o


# Object files for target SFMLDemo
SFMLDemo_OBJECTS = \
"CMakeFiles/SFMLDemo.dir/main.cpp.o" \
"CMakeFiles/SFMLDemo.dir/src/core/Engine.cpp.o" \
"CMakeFiles/SFMLDemo.dir/src/windows/Context.cpp.o" \
"CMakeFiles/SFMLDemo.dir/src/windows/MainMenu.cpp.o" \
"CMakeFiles/SFMLDemo.dir/src/windows/ContextSwitcher.cpp.o" \
"CMakeFiles/SFMLDemo.dir/src/Characters/Character.cpp.o" \
"CMakeFiles/SFMLDemo.dir/src/maps/Map.cpp.o" \
"CMakeFiles/SFMLDemo.dir/src/maps/town/Town.cpp.o" \
"CMakeFiles/SFMLDemo.dir/src/utils/Logger.cpp.o" \
"CMakeFiles/SFMLDemo.dir/src/core/Actions.cpp.o"

# External object files for target SFMLDemo
SFMLDemo_EXTERNAL_OBJECTS =

SFMLDemo: CMakeFiles/SFMLDemo.dir/main.cpp.o
SFMLDemo: CMakeFiles/SFMLDemo.dir/src/core/Engine.cpp.o
SFMLDemo: CMakeFiles/SFMLDemo.dir/src/windows/Context.cpp.o
SFMLDemo: CMakeFiles/SFMLDemo.dir/src/windows/MainMenu.cpp.o
SFMLDemo: CMakeFiles/SFMLDemo.dir/src/windows/ContextSwitcher.cpp.o
SFMLDemo: CMakeFiles/SFMLDemo.dir/src/Characters/Character.cpp.o
SFMLDemo: CMakeFiles/SFMLDemo.dir/src/maps/Map.cpp.o
SFMLDemo: CMakeFiles/SFMLDemo.dir/src/maps/town/Town.cpp.o
SFMLDemo: CMakeFiles/SFMLDemo.dir/src/utils/Logger.cpp.o
SFMLDemo: CMakeFiles/SFMLDemo.dir/src/core/Actions.cpp.o
SFMLDemo: CMakeFiles/SFMLDemo.dir/build.make
SFMLDemo: /usr/lib/x86_64-linux-gnu/libsfml-system.so
SFMLDemo: /usr/lib/x86_64-linux-gnu/libsfml-window.so
SFMLDemo: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so
SFMLDemo: /usr/lib/x86_64-linux-gnu/libsfml-network.so
SFMLDemo: /usr/lib/x86_64-linux-gnu/libsfml-audio.so
SFMLDemo: CMakeFiles/SFMLDemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/guiviko/Projects/chrono/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable SFMLDemo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SFMLDemo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SFMLDemo.dir/build: SFMLDemo

.PHONY : CMakeFiles/SFMLDemo.dir/build

CMakeFiles/SFMLDemo.dir/requires: CMakeFiles/SFMLDemo.dir/main.cpp.o.requires
CMakeFiles/SFMLDemo.dir/requires: CMakeFiles/SFMLDemo.dir/src/core/Engine.cpp.o.requires
CMakeFiles/SFMLDemo.dir/requires: CMakeFiles/SFMLDemo.dir/src/windows/Context.cpp.o.requires
CMakeFiles/SFMLDemo.dir/requires: CMakeFiles/SFMLDemo.dir/src/windows/MainMenu.cpp.o.requires
CMakeFiles/SFMLDemo.dir/requires: CMakeFiles/SFMLDemo.dir/src/windows/ContextSwitcher.cpp.o.requires
CMakeFiles/SFMLDemo.dir/requires: CMakeFiles/SFMLDemo.dir/src/Characters/Character.cpp.o.requires
CMakeFiles/SFMLDemo.dir/requires: CMakeFiles/SFMLDemo.dir/src/maps/Map.cpp.o.requires
CMakeFiles/SFMLDemo.dir/requires: CMakeFiles/SFMLDemo.dir/src/maps/town/Town.cpp.o.requires
CMakeFiles/SFMLDemo.dir/requires: CMakeFiles/SFMLDemo.dir/src/utils/Logger.cpp.o.requires
CMakeFiles/SFMLDemo.dir/requires: CMakeFiles/SFMLDemo.dir/src/core/Actions.cpp.o.requires

.PHONY : CMakeFiles/SFMLDemo.dir/requires

CMakeFiles/SFMLDemo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SFMLDemo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SFMLDemo.dir/clean

CMakeFiles/SFMLDemo.dir/depend:
	cd /home/guiviko/Projects/chrono/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/guiviko/Projects/chrono /home/guiviko/Projects/chrono /home/guiviko/Projects/chrono/cmake-build-debug /home/guiviko/Projects/chrono/cmake-build-debug /home/guiviko/Projects/chrono/cmake-build-debug/CMakeFiles/SFMLDemo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SFMLDemo.dir/depend

