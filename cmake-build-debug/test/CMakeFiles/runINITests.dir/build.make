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
CMAKE_COMMAND = /home/niccolo/Scaricati/clion-2018.1.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/niccolo/Scaricati/clion-2018.1.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/niccolo/CLionProjects/Uni_INI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/niccolo/CLionProjects/Uni_INI/cmake-build-debug

# Include any dependencies generated for this target.
include test/CMakeFiles/runINITests.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/runINITests.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/runINITests.dir/flags.make

test/CMakeFiles/runINITests.dir/runAllTests.cpp.o: test/CMakeFiles/runINITests.dir/flags.make
test/CMakeFiles/runINITests.dir/runAllTests.cpp.o: ../test/runAllTests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/niccolo/CLionProjects/Uni_INI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/runINITests.dir/runAllTests.cpp.o"
	cd /home/niccolo/CLionProjects/Uni_INI/cmake-build-debug/test && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runINITests.dir/runAllTests.cpp.o -c /home/niccolo/CLionProjects/Uni_INI/test/runAllTests.cpp

test/CMakeFiles/runINITests.dir/runAllTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runINITests.dir/runAllTests.cpp.i"
	cd /home/niccolo/CLionProjects/Uni_INI/cmake-build-debug/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/niccolo/CLionProjects/Uni_INI/test/runAllTests.cpp > CMakeFiles/runINITests.dir/runAllTests.cpp.i

test/CMakeFiles/runINITests.dir/runAllTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runINITests.dir/runAllTests.cpp.s"
	cd /home/niccolo/CLionProjects/Uni_INI/cmake-build-debug/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/niccolo/CLionProjects/Uni_INI/test/runAllTests.cpp -o CMakeFiles/runINITests.dir/runAllTests.cpp.s

test/CMakeFiles/runINITests.dir/runAllTests.cpp.o.requires:

.PHONY : test/CMakeFiles/runINITests.dir/runAllTests.cpp.o.requires

test/CMakeFiles/runINITests.dir/runAllTests.cpp.o.provides: test/CMakeFiles/runINITests.dir/runAllTests.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/runINITests.dir/build.make test/CMakeFiles/runINITests.dir/runAllTests.cpp.o.provides.build
.PHONY : test/CMakeFiles/runINITests.dir/runAllTests.cpp.o.provides

test/CMakeFiles/runINITests.dir/runAllTests.cpp.o.provides.build: test/CMakeFiles/runINITests.dir/runAllTests.cpp.o


test/CMakeFiles/runINITests.dir/INITest.cpp.o: test/CMakeFiles/runINITests.dir/flags.make
test/CMakeFiles/runINITests.dir/INITest.cpp.o: ../test/INITest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/niccolo/CLionProjects/Uni_INI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/runINITests.dir/INITest.cpp.o"
	cd /home/niccolo/CLionProjects/Uni_INI/cmake-build-debug/test && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runINITests.dir/INITest.cpp.o -c /home/niccolo/CLionProjects/Uni_INI/test/INITest.cpp

test/CMakeFiles/runINITests.dir/INITest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runINITests.dir/INITest.cpp.i"
	cd /home/niccolo/CLionProjects/Uni_INI/cmake-build-debug/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/niccolo/CLionProjects/Uni_INI/test/INITest.cpp > CMakeFiles/runINITests.dir/INITest.cpp.i

test/CMakeFiles/runINITests.dir/INITest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runINITests.dir/INITest.cpp.s"
	cd /home/niccolo/CLionProjects/Uni_INI/cmake-build-debug/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/niccolo/CLionProjects/Uni_INI/test/INITest.cpp -o CMakeFiles/runINITests.dir/INITest.cpp.s

test/CMakeFiles/runINITests.dir/INITest.cpp.o.requires:

.PHONY : test/CMakeFiles/runINITests.dir/INITest.cpp.o.requires

test/CMakeFiles/runINITests.dir/INITest.cpp.o.provides: test/CMakeFiles/runINITests.dir/INITest.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/runINITests.dir/build.make test/CMakeFiles/runINITests.dir/INITest.cpp.o.provides.build
.PHONY : test/CMakeFiles/runINITests.dir/INITest.cpp.o.provides

test/CMakeFiles/runINITests.dir/INITest.cpp.o.provides.build: test/CMakeFiles/runINITests.dir/INITest.cpp.o


# Object files for target runINITests
runINITests_OBJECTS = \
"CMakeFiles/runINITests.dir/runAllTests.cpp.o" \
"CMakeFiles/runINITests.dir/INITest.cpp.o"

# External object files for target runINITests
runINITests_EXTERNAL_OBJECTS =

test/runINITests: test/CMakeFiles/runINITests.dir/runAllTests.cpp.o
test/runINITests: test/CMakeFiles/runINITests.dir/INITest.cpp.o
test/runINITests: test/CMakeFiles/runINITests.dir/build.make
test/runINITests: test/lib/googletest/libgtestd.a
test/runINITests: test/lib/googletest/libgtest_maind.a
test/runINITests: libcore.a
test/runINITests: test/lib/googletest/libgtestd.a
test/runINITests: test/CMakeFiles/runINITests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/niccolo/CLionProjects/Uni_INI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable runINITests"
	cd /home/niccolo/CLionProjects/Uni_INI/cmake-build-debug/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runINITests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/runINITests.dir/build: test/runINITests

.PHONY : test/CMakeFiles/runINITests.dir/build

test/CMakeFiles/runINITests.dir/requires: test/CMakeFiles/runINITests.dir/runAllTests.cpp.o.requires
test/CMakeFiles/runINITests.dir/requires: test/CMakeFiles/runINITests.dir/INITest.cpp.o.requires

.PHONY : test/CMakeFiles/runINITests.dir/requires

test/CMakeFiles/runINITests.dir/clean:
	cd /home/niccolo/CLionProjects/Uni_INI/cmake-build-debug/test && $(CMAKE_COMMAND) -P CMakeFiles/runINITests.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/runINITests.dir/clean

test/CMakeFiles/runINITests.dir/depend:
	cd /home/niccolo/CLionProjects/Uni_INI/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/niccolo/CLionProjects/Uni_INI /home/niccolo/CLionProjects/Uni_INI/test /home/niccolo/CLionProjects/Uni_INI/cmake-build-debug /home/niccolo/CLionProjects/Uni_INI/cmake-build-debug/test /home/niccolo/CLionProjects/Uni_INI/cmake-build-debug/test/CMakeFiles/runINITests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/runINITests.dir/depend

