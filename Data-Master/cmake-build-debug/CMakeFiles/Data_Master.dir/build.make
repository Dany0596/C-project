# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\danie\Desktop\Data-Master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\danie\Desktop\Data-Master\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Data_Master.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Data_Master.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Data_Master.dir/flags.make

CMakeFiles/Data_Master.dir/main.cpp.obj: CMakeFiles/Data_Master.dir/flags.make
CMakeFiles/Data_Master.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\danie\Desktop\Data-Master\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Data_Master.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Data_Master.dir\main.cpp.obj -c C:\Users\danie\Desktop\Data-Master\main.cpp

CMakeFiles/Data_Master.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Data_Master.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\danie\Desktop\Data-Master\main.cpp > CMakeFiles\Data_Master.dir\main.cpp.i

CMakeFiles/Data_Master.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Data_Master.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\danie\Desktop\Data-Master\main.cpp -o CMakeFiles\Data_Master.dir\main.cpp.s

# Object files for target Data_Master
Data_Master_OBJECTS = \
"CMakeFiles/Data_Master.dir/main.cpp.obj"

# External object files for target Data_Master
Data_Master_EXTERNAL_OBJECTS =

Data_Master.exe: CMakeFiles/Data_Master.dir/main.cpp.obj
Data_Master.exe: CMakeFiles/Data_Master.dir/build.make
Data_Master.exe: CMakeFiles/Data_Master.dir/linklibs.rsp
Data_Master.exe: CMakeFiles/Data_Master.dir/objects1.rsp
Data_Master.exe: CMakeFiles/Data_Master.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\danie\Desktop\Data-Master\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Data_Master.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Data_Master.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Data_Master.dir/build: Data_Master.exe

.PHONY : CMakeFiles/Data_Master.dir/build

CMakeFiles/Data_Master.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Data_Master.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Data_Master.dir/clean

CMakeFiles/Data_Master.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\danie\Desktop\Data-Master C:\Users\danie\Desktop\Data-Master C:\Users\danie\Desktop\Data-Master\cmake-build-debug C:\Users\danie\Desktop\Data-Master\cmake-build-debug C:\Users\danie\Desktop\Data-Master\cmake-build-debug\CMakeFiles\Data_Master.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Data_Master.dir/depend
