# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /snap/clion/121/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/121/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tal/CLionProjects/chat-app/client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tal/CLionProjects/chat-app/client/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/client.dir/flags.make

CMakeFiles/client.dir/src/Client.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/src/Client.cpp.o: ../src/Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tal/CLionProjects/chat-app/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/client.dir/src/Client.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/src/Client.cpp.o -c /home/tal/CLionProjects/chat-app/client/src/Client.cpp

CMakeFiles/client.dir/src/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/src/Client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tal/CLionProjects/chat-app/client/src/Client.cpp > CMakeFiles/client.dir/src/Client.cpp.i

CMakeFiles/client.dir/src/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/src/Client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tal/CLionProjects/chat-app/client/src/Client.cpp -o CMakeFiles/client.dir/src/Client.cpp.s

CMakeFiles/client.dir/src/TCPClient.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/src/TCPClient.cpp.o: ../src/TCPClient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tal/CLionProjects/chat-app/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/client.dir/src/TCPClient.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/src/TCPClient.cpp.o -c /home/tal/CLionProjects/chat-app/client/src/TCPClient.cpp

CMakeFiles/client.dir/src/TCPClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/src/TCPClient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tal/CLionProjects/chat-app/client/src/TCPClient.cpp > CMakeFiles/client.dir/src/TCPClient.cpp.i

CMakeFiles/client.dir/src/TCPClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/src/TCPClient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tal/CLionProjects/chat-app/client/src/TCPClient.cpp -o CMakeFiles/client.dir/src/TCPClient.cpp.s

CMakeFiles/client.dir/src/UDPClient.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/src/UDPClient.cpp.o: ../src/UDPClient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tal/CLionProjects/chat-app/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/client.dir/src/UDPClient.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/src/UDPClient.cpp.o -c /home/tal/CLionProjects/chat-app/client/src/UDPClient.cpp

CMakeFiles/client.dir/src/UDPClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/src/UDPClient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tal/CLionProjects/chat-app/client/src/UDPClient.cpp > CMakeFiles/client.dir/src/UDPClient.cpp.i

CMakeFiles/client.dir/src/UDPClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/src/UDPClient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tal/CLionProjects/chat-app/client/src/UDPClient.cpp -o CMakeFiles/client.dir/src/UDPClient.cpp.s

CMakeFiles/client.dir/src/app.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/src/app.cpp.o: ../src/app.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tal/CLionProjects/chat-app/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/client.dir/src/app.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/src/app.cpp.o -c /home/tal/CLionProjects/chat-app/client/src/app.cpp

CMakeFiles/client.dir/src/app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/src/app.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tal/CLionProjects/chat-app/client/src/app.cpp > CMakeFiles/client.dir/src/app.cpp.i

CMakeFiles/client.dir/src/app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/src/app.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tal/CLionProjects/chat-app/client/src/app.cpp -o CMakeFiles/client.dir/src/app.cpp.s

# Object files for target client
client_OBJECTS = \
"CMakeFiles/client.dir/src/Client.cpp.o" \
"CMakeFiles/client.dir/src/TCPClient.cpp.o" \
"CMakeFiles/client.dir/src/UDPClient.cpp.o" \
"CMakeFiles/client.dir/src/app.cpp.o"

# External object files for target client
client_EXTERNAL_OBJECTS =

client: CMakeFiles/client.dir/src/Client.cpp.o
client: CMakeFiles/client.dir/src/TCPClient.cpp.o
client: CMakeFiles/client.dir/src/UDPClient.cpp.o
client: CMakeFiles/client.dir/src/app.cpp.o
client: CMakeFiles/client.dir/build.make
client: libs/socket-wrapper-1.0.8/libsocket-wrapper.so
client: CMakeFiles/client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tal/CLionProjects/chat-app/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/client.dir/build: client

.PHONY : CMakeFiles/client.dir/build

CMakeFiles/client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/client.dir/clean

CMakeFiles/client.dir/depend:
	cd /home/tal/CLionProjects/chat-app/client/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tal/CLionProjects/chat-app/client /home/tal/CLionProjects/chat-app/client /home/tal/CLionProjects/chat-app/client/cmake-build-debug /home/tal/CLionProjects/chat-app/client/cmake-build-debug /home/tal/CLionProjects/chat-app/client/cmake-build-debug/CMakeFiles/client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/client.dir/depend

