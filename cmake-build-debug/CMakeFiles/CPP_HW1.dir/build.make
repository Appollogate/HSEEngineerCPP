# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/appollogate/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5080.54/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/appollogate/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5080.54/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/appollogate/Documents/CPP_Spec/Homeworks/HW1_NEW/CPP_HW1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/appollogate/Documents/CPP_Spec/Homeworks/HW1_NEW/CPP_HW1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CPP_HW1.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/CPP_HW1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CPP_HW1.dir/flags.make

CMakeFiles/CPP_HW1.dir/main.cpp.o: CMakeFiles/CPP_HW1.dir/flags.make
CMakeFiles/CPP_HW1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/appollogate/Documents/CPP_Spec/Homeworks/HW1_NEW/CPP_HW1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CPP_HW1.dir/main.cpp.o"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPP_HW1.dir/main.cpp.o -c /home/appollogate/Documents/CPP_Spec/Homeworks/HW1_NEW/CPP_HW1/main.cpp

CMakeFiles/CPP_HW1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPP_HW1.dir/main.cpp.i"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/appollogate/Documents/CPP_Spec/Homeworks/HW1_NEW/CPP_HW1/main.cpp > CMakeFiles/CPP_HW1.dir/main.cpp.i

CMakeFiles/CPP_HW1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPP_HW1.dir/main.cpp.s"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/appollogate/Documents/CPP_Spec/Homeworks/HW1_NEW/CPP_HW1/main.cpp -o CMakeFiles/CPP_HW1.dir/main.cpp.s

CMakeFiles/CPP_HW1.dir/src/BigInteger.cpp.o: CMakeFiles/CPP_HW1.dir/flags.make
CMakeFiles/CPP_HW1.dir/src/BigInteger.cpp.o: ../src/BigInteger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/appollogate/Documents/CPP_Spec/Homeworks/HW1_NEW/CPP_HW1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CPP_HW1.dir/src/BigInteger.cpp.o"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPP_HW1.dir/src/BigInteger.cpp.o -c /home/appollogate/Documents/CPP_Spec/Homeworks/HW1_NEW/CPP_HW1/src/BigInteger.cpp

CMakeFiles/CPP_HW1.dir/src/BigInteger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPP_HW1.dir/src/BigInteger.cpp.i"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/appollogate/Documents/CPP_Spec/Homeworks/HW1_NEW/CPP_HW1/src/BigInteger.cpp > CMakeFiles/CPP_HW1.dir/src/BigInteger.cpp.i

CMakeFiles/CPP_HW1.dir/src/BigInteger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPP_HW1.dir/src/BigInteger.cpp.s"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/appollogate/Documents/CPP_Spec/Homeworks/HW1_NEW/CPP_HW1/src/BigInteger.cpp -o CMakeFiles/CPP_HW1.dir/src/BigInteger.cpp.s

CMakeFiles/CPP_HW1.dir/tests/BigIntTests.cpp.o: CMakeFiles/CPP_HW1.dir/flags.make
CMakeFiles/CPP_HW1.dir/tests/BigIntTests.cpp.o: ../tests/BigIntTests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/appollogate/Documents/CPP_Spec/Homeworks/HW1_NEW/CPP_HW1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CPP_HW1.dir/tests/BigIntTests.cpp.o"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPP_HW1.dir/tests/BigIntTests.cpp.o -c /home/appollogate/Documents/CPP_Spec/Homeworks/HW1_NEW/CPP_HW1/tests/BigIntTests.cpp

CMakeFiles/CPP_HW1.dir/tests/BigIntTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPP_HW1.dir/tests/BigIntTests.cpp.i"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/appollogate/Documents/CPP_Spec/Homeworks/HW1_NEW/CPP_HW1/tests/BigIntTests.cpp > CMakeFiles/CPP_HW1.dir/tests/BigIntTests.cpp.i

CMakeFiles/CPP_HW1.dir/tests/BigIntTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPP_HW1.dir/tests/BigIntTests.cpp.s"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/appollogate/Documents/CPP_Spec/Homeworks/HW1_NEW/CPP_HW1/tests/BigIntTests.cpp -o CMakeFiles/CPP_HW1.dir/tests/BigIntTests.cpp.s

# Object files for target CPP_HW1
CPP_HW1_OBJECTS = \
"CMakeFiles/CPP_HW1.dir/main.cpp.o" \
"CMakeFiles/CPP_HW1.dir/src/BigInteger.cpp.o" \
"CMakeFiles/CPP_HW1.dir/tests/BigIntTests.cpp.o"

# External object files for target CPP_HW1
CPP_HW1_EXTERNAL_OBJECTS =

CPP_HW1: CMakeFiles/CPP_HW1.dir/main.cpp.o
CPP_HW1: CMakeFiles/CPP_HW1.dir/src/BigInteger.cpp.o
CPP_HW1: CMakeFiles/CPP_HW1.dir/tests/BigIntTests.cpp.o
CPP_HW1: CMakeFiles/CPP_HW1.dir/build.make
CPP_HW1: lib/libgtestd.a
CPP_HW1: CMakeFiles/CPP_HW1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/appollogate/Documents/CPP_Spec/Homeworks/HW1_NEW/CPP_HW1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable CPP_HW1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CPP_HW1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CPP_HW1.dir/build: CPP_HW1
.PHONY : CMakeFiles/CPP_HW1.dir/build

CMakeFiles/CPP_HW1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CPP_HW1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CPP_HW1.dir/clean

CMakeFiles/CPP_HW1.dir/depend:
	cd /home/appollogate/Documents/CPP_Spec/Homeworks/HW1_NEW/CPP_HW1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/appollogate/Documents/CPP_Spec/Homeworks/HW1_NEW/CPP_HW1 /home/appollogate/Documents/CPP_Spec/Homeworks/HW1_NEW/CPP_HW1 /home/appollogate/Documents/CPP_Spec/Homeworks/HW1_NEW/CPP_HW1/cmake-build-debug /home/appollogate/Documents/CPP_Spec/Homeworks/HW1_NEW/CPP_HW1/cmake-build-debug /home/appollogate/Documents/CPP_Spec/Homeworks/HW1_NEW/CPP_HW1/cmake-build-debug/CMakeFiles/CPP_HW1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CPP_HW1.dir/depend
