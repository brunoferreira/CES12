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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/bruno/codes/CES12/Balanced Tree"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/bruno/codes/CES12/Balanced Tree/build"

# Include any dependencies generated for this target.
include CMakeFiles/labTreetests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/labTreetests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/labTreetests.dir/flags.make

CMakeFiles/labTreetests.dir/test/testTree.cpp.o: CMakeFiles/labTreetests.dir/flags.make
CMakeFiles/labTreetests.dir/test/testTree.cpp.o: ../test/testTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/bruno/codes/CES12/Balanced Tree/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/labTreetests.dir/test/testTree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/labTreetests.dir/test/testTree.cpp.o -c "/home/bruno/codes/CES12/Balanced Tree/test/testTree.cpp"

CMakeFiles/labTreetests.dir/test/testTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/labTreetests.dir/test/testTree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/bruno/codes/CES12/Balanced Tree/test/testTree.cpp" > CMakeFiles/labTreetests.dir/test/testTree.cpp.i

CMakeFiles/labTreetests.dir/test/testTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/labTreetests.dir/test/testTree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/bruno/codes/CES12/Balanced Tree/test/testTree.cpp" -o CMakeFiles/labTreetests.dir/test/testTree.cpp.s

CMakeFiles/labTreetests.dir/src/IndexPointsAluno.cpp.o: CMakeFiles/labTreetests.dir/flags.make
CMakeFiles/labTreetests.dir/src/IndexPointsAluno.cpp.o: ../src/IndexPointsAluno.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/bruno/codes/CES12/Balanced Tree/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/labTreetests.dir/src/IndexPointsAluno.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/labTreetests.dir/src/IndexPointsAluno.cpp.o -c "/home/bruno/codes/CES12/Balanced Tree/src/IndexPointsAluno.cpp"

CMakeFiles/labTreetests.dir/src/IndexPointsAluno.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/labTreetests.dir/src/IndexPointsAluno.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/bruno/codes/CES12/Balanced Tree/src/IndexPointsAluno.cpp" > CMakeFiles/labTreetests.dir/src/IndexPointsAluno.cpp.i

CMakeFiles/labTreetests.dir/src/IndexPointsAluno.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/labTreetests.dir/src/IndexPointsAluno.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/bruno/codes/CES12/Balanced Tree/src/IndexPointsAluno.cpp" -o CMakeFiles/labTreetests.dir/src/IndexPointsAluno.cpp.s

# Object files for target labTreetests
labTreetests_OBJECTS = \
"CMakeFiles/labTreetests.dir/test/testTree.cpp.o" \
"CMakeFiles/labTreetests.dir/src/IndexPointsAluno.cpp.o"

# External object files for target labTreetests
labTreetests_EXTERNAL_OBJECTS =

labTreetests: CMakeFiles/labTreetests.dir/test/testTree.cpp.o
labTreetests: CMakeFiles/labTreetests.dir/src/IndexPointsAluno.cpp.o
labTreetests: CMakeFiles/labTreetests.dir/build.make
labTreetests: lib/libgtest.a
labTreetests: lib/libgtest_main.a
labTreetests: liblibLabTree.a
labTreetests: lib/libgtest.a
labTreetests: CMakeFiles/labTreetests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/bruno/codes/CES12/Balanced Tree/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable labTreetests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/labTreetests.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/cmake -D TEST_TARGET=labTreetests -D "TEST_EXECUTABLE=/home/bruno/codes/CES12/Balanced Tree/build/labTreetests" -D TEST_EXECUTOR= -D "TEST_WORKING_DIR=/home/bruno/codes/CES12/Balanced Tree/build" -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=labTreetests_TESTS -D "CTEST_FILE=/home/bruno/codes/CES12/Balanced Tree/build/labTreetests[1]_tests.cmake" -D TEST_DISCOVERY_TIMEOUT=5 -P /usr/share/cmake-3.16/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
CMakeFiles/labTreetests.dir/build: labTreetests

.PHONY : CMakeFiles/labTreetests.dir/build

CMakeFiles/labTreetests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/labTreetests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/labTreetests.dir/clean

CMakeFiles/labTreetests.dir/depend:
	cd "/home/bruno/codes/CES12/Balanced Tree/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/bruno/codes/CES12/Balanced Tree" "/home/bruno/codes/CES12/Balanced Tree" "/home/bruno/codes/CES12/Balanced Tree/build" "/home/bruno/codes/CES12/Balanced Tree/build" "/home/bruno/codes/CES12/Balanced Tree/build/CMakeFiles/labTreetests.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/labTreetests.dir/depend

