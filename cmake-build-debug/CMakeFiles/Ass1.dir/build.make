# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /media/hungdao1311/Other/Linux/clion-2017.2.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /media/hungdao1311/Other/Linux/clion-2017.2.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hungdao1311/Desktop/Ass1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hungdao1311/Desktop/Ass1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Ass1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Ass1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Ass1.dir/flags.make

CMakeFiles/Ass1.dir/dbLib.cpp.o: CMakeFiles/Ass1.dir/flags.make
CMakeFiles/Ass1.dir/dbLib.cpp.o: ../dbLib.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hungdao1311/Desktop/Ass1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Ass1.dir/dbLib.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Ass1.dir/dbLib.cpp.o -c /home/hungdao1311/Desktop/Ass1/dbLib.cpp

CMakeFiles/Ass1.dir/dbLib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ass1.dir/dbLib.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hungdao1311/Desktop/Ass1/dbLib.cpp > CMakeFiles/Ass1.dir/dbLib.cpp.i

CMakeFiles/Ass1.dir/dbLib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ass1.dir/dbLib.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hungdao1311/Desktop/Ass1/dbLib.cpp -o CMakeFiles/Ass1.dir/dbLib.cpp.s

CMakeFiles/Ass1.dir/dbLib.cpp.o.requires:

.PHONY : CMakeFiles/Ass1.dir/dbLib.cpp.o.requires

CMakeFiles/Ass1.dir/dbLib.cpp.o.provides: CMakeFiles/Ass1.dir/dbLib.cpp.o.requires
	$(MAKE) -f CMakeFiles/Ass1.dir/build.make CMakeFiles/Ass1.dir/dbLib.cpp.o.provides.build
.PHONY : CMakeFiles/Ass1.dir/dbLib.cpp.o.provides

CMakeFiles/Ass1.dir/dbLib.cpp.o.provides.build: CMakeFiles/Ass1.dir/dbLib.cpp.o


CMakeFiles/Ass1.dir/eventLib.cpp.o: CMakeFiles/Ass1.dir/flags.make
CMakeFiles/Ass1.dir/eventLib.cpp.o: ../eventLib.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hungdao1311/Desktop/Ass1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Ass1.dir/eventLib.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Ass1.dir/eventLib.cpp.o -c /home/hungdao1311/Desktop/Ass1/eventLib.cpp

CMakeFiles/Ass1.dir/eventLib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ass1.dir/eventLib.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hungdao1311/Desktop/Ass1/eventLib.cpp > CMakeFiles/Ass1.dir/eventLib.cpp.i

CMakeFiles/Ass1.dir/eventLib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ass1.dir/eventLib.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hungdao1311/Desktop/Ass1/eventLib.cpp -o CMakeFiles/Ass1.dir/eventLib.cpp.s

CMakeFiles/Ass1.dir/eventLib.cpp.o.requires:

.PHONY : CMakeFiles/Ass1.dir/eventLib.cpp.o.requires

CMakeFiles/Ass1.dir/eventLib.cpp.o.provides: CMakeFiles/Ass1.dir/eventLib.cpp.o.requires
	$(MAKE) -f CMakeFiles/Ass1.dir/build.make CMakeFiles/Ass1.dir/eventLib.cpp.o.provides.build
.PHONY : CMakeFiles/Ass1.dir/eventLib.cpp.o.provides

CMakeFiles/Ass1.dir/eventLib.cpp.o.provides.build: CMakeFiles/Ass1.dir/eventLib.cpp.o


CMakeFiles/Ass1.dir/main.cpp.o: CMakeFiles/Ass1.dir/flags.make
CMakeFiles/Ass1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hungdao1311/Desktop/Ass1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Ass1.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Ass1.dir/main.cpp.o -c /home/hungdao1311/Desktop/Ass1/main.cpp

CMakeFiles/Ass1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ass1.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hungdao1311/Desktop/Ass1/main.cpp > CMakeFiles/Ass1.dir/main.cpp.i

CMakeFiles/Ass1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ass1.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hungdao1311/Desktop/Ass1/main.cpp -o CMakeFiles/Ass1.dir/main.cpp.s

CMakeFiles/Ass1.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Ass1.dir/main.cpp.o.requires

CMakeFiles/Ass1.dir/main.cpp.o.provides: CMakeFiles/Ass1.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Ass1.dir/build.make CMakeFiles/Ass1.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Ass1.dir/main.cpp.o.provides

CMakeFiles/Ass1.dir/main.cpp.o.provides.build: CMakeFiles/Ass1.dir/main.cpp.o


CMakeFiles/Ass1.dir/processData.cpp.o: CMakeFiles/Ass1.dir/flags.make
CMakeFiles/Ass1.dir/processData.cpp.o: ../processData.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hungdao1311/Desktop/Ass1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Ass1.dir/processData.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Ass1.dir/processData.cpp.o -c /home/hungdao1311/Desktop/Ass1/processData.cpp

CMakeFiles/Ass1.dir/processData.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ass1.dir/processData.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hungdao1311/Desktop/Ass1/processData.cpp > CMakeFiles/Ass1.dir/processData.cpp.i

CMakeFiles/Ass1.dir/processData.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ass1.dir/processData.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hungdao1311/Desktop/Ass1/processData.cpp -o CMakeFiles/Ass1.dir/processData.cpp.s

CMakeFiles/Ass1.dir/processData.cpp.o.requires:

.PHONY : CMakeFiles/Ass1.dir/processData.cpp.o.requires

CMakeFiles/Ass1.dir/processData.cpp.o.provides: CMakeFiles/Ass1.dir/processData.cpp.o.requires
	$(MAKE) -f CMakeFiles/Ass1.dir/build.make CMakeFiles/Ass1.dir/processData.cpp.o.provides.build
.PHONY : CMakeFiles/Ass1.dir/processData.cpp.o.provides

CMakeFiles/Ass1.dir/processData.cpp.o.provides.build: CMakeFiles/Ass1.dir/processData.cpp.o


# Object files for target Ass1
Ass1_OBJECTS = \
"CMakeFiles/Ass1.dir/dbLib.cpp.o" \
"CMakeFiles/Ass1.dir/eventLib.cpp.o" \
"CMakeFiles/Ass1.dir/main.cpp.o" \
"CMakeFiles/Ass1.dir/processData.cpp.o"

# External object files for target Ass1
Ass1_EXTERNAL_OBJECTS =

Ass1: CMakeFiles/Ass1.dir/dbLib.cpp.o
Ass1: CMakeFiles/Ass1.dir/eventLib.cpp.o
Ass1: CMakeFiles/Ass1.dir/main.cpp.o
Ass1: CMakeFiles/Ass1.dir/processData.cpp.o
Ass1: CMakeFiles/Ass1.dir/build.make
Ass1: CMakeFiles/Ass1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hungdao1311/Desktop/Ass1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Ass1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Ass1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Ass1.dir/build: Ass1

.PHONY : CMakeFiles/Ass1.dir/build

CMakeFiles/Ass1.dir/requires: CMakeFiles/Ass1.dir/dbLib.cpp.o.requires
CMakeFiles/Ass1.dir/requires: CMakeFiles/Ass1.dir/eventLib.cpp.o.requires
CMakeFiles/Ass1.dir/requires: CMakeFiles/Ass1.dir/main.cpp.o.requires
CMakeFiles/Ass1.dir/requires: CMakeFiles/Ass1.dir/processData.cpp.o.requires

.PHONY : CMakeFiles/Ass1.dir/requires

CMakeFiles/Ass1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Ass1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Ass1.dir/clean

CMakeFiles/Ass1.dir/depend:
	cd /home/hungdao1311/Desktop/Ass1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hungdao1311/Desktop/Ass1 /home/hungdao1311/Desktop/Ass1 /home/hungdao1311/Desktop/Ass1/cmake-build-debug /home/hungdao1311/Desktop/Ass1/cmake-build-debug /home/hungdao1311/Desktop/Ass1/cmake-build-debug/CMakeFiles/Ass1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Ass1.dir/depend

