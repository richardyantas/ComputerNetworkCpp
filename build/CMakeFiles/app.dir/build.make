# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/serendipita/Documents/ComputerNetworkCpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/serendipita/Documents/ComputerNetworkCpp/build

# Include any dependencies generated for this target.
include CMakeFiles/app.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/app.dir/flags.make

CMakeFiles/app.dir/server.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/server.cpp.o: ../server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/serendipita/Documents/ComputerNetworkCpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/app.dir/server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/server.cpp.o -c /home/serendipita/Documents/ComputerNetworkCpp/server.cpp

CMakeFiles/app.dir/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/serendipita/Documents/ComputerNetworkCpp/server.cpp > CMakeFiles/app.dir/server.cpp.i

CMakeFiles/app.dir/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/serendipita/Documents/ComputerNetworkCpp/server.cpp -o CMakeFiles/app.dir/server.cpp.s

CMakeFiles/app.dir/server.cpp.o.requires:

.PHONY : CMakeFiles/app.dir/server.cpp.o.requires

CMakeFiles/app.dir/server.cpp.o.provides: CMakeFiles/app.dir/server.cpp.o.requires
	$(MAKE) -f CMakeFiles/app.dir/build.make CMakeFiles/app.dir/server.cpp.o.provides.build
.PHONY : CMakeFiles/app.dir/server.cpp.o.provides

CMakeFiles/app.dir/server.cpp.o.provides.build: CMakeFiles/app.dir/server.cpp.o


CMakeFiles/app.dir/Socket.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/Socket.cpp.o: ../Socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/serendipita/Documents/ComputerNetworkCpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/app.dir/Socket.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/Socket.cpp.o -c /home/serendipita/Documents/ComputerNetworkCpp/Socket.cpp

CMakeFiles/app.dir/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/Socket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/serendipita/Documents/ComputerNetworkCpp/Socket.cpp > CMakeFiles/app.dir/Socket.cpp.i

CMakeFiles/app.dir/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/Socket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/serendipita/Documents/ComputerNetworkCpp/Socket.cpp -o CMakeFiles/app.dir/Socket.cpp.s

CMakeFiles/app.dir/Socket.cpp.o.requires:

.PHONY : CMakeFiles/app.dir/Socket.cpp.o.requires

CMakeFiles/app.dir/Socket.cpp.o.provides: CMakeFiles/app.dir/Socket.cpp.o.requires
	$(MAKE) -f CMakeFiles/app.dir/build.make CMakeFiles/app.dir/Socket.cpp.o.provides.build
.PHONY : CMakeFiles/app.dir/Socket.cpp.o.provides

CMakeFiles/app.dir/Socket.cpp.o.provides.build: CMakeFiles/app.dir/Socket.cpp.o


# Object files for target app
app_OBJECTS = \
"CMakeFiles/app.dir/server.cpp.o" \
"CMakeFiles/app.dir/Socket.cpp.o"

# External object files for target app
app_EXTERNAL_OBJECTS =

app: CMakeFiles/app.dir/server.cpp.o
app: CMakeFiles/app.dir/Socket.cpp.o
app: CMakeFiles/app.dir/build.make
app: CMakeFiles/app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/serendipita/Documents/ComputerNetworkCpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable app"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/app.dir/build: app

.PHONY : CMakeFiles/app.dir/build

CMakeFiles/app.dir/requires: CMakeFiles/app.dir/server.cpp.o.requires
CMakeFiles/app.dir/requires: CMakeFiles/app.dir/Socket.cpp.o.requires

.PHONY : CMakeFiles/app.dir/requires

CMakeFiles/app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/app.dir/cmake_clean.cmake
.PHONY : CMakeFiles/app.dir/clean

CMakeFiles/app.dir/depend:
	cd /home/serendipita/Documents/ComputerNetworkCpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/serendipita/Documents/ComputerNetworkCpp /home/serendipita/Documents/ComputerNetworkCpp /home/serendipita/Documents/ComputerNetworkCpp/build /home/serendipita/Documents/ComputerNetworkCpp/build /home/serendipita/Documents/ComputerNetworkCpp/build/CMakeFiles/app.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/app.dir/depend

