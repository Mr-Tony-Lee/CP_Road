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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tony/CP_Road/Uva_record

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tony/CP_Road/Uva_record/UVA_4_star_question

# Include any dependencies generated for this target.
include CMakeFiles/count_3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/count_3.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/count_3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/count_3.dir/flags.make

CMakeFiles/count_3.dir/UVA_3_star_question/count_3.cpp.o: CMakeFiles/count_3.dir/flags.make
CMakeFiles/count_3.dir/UVA_3_star_question/count_3.cpp.o: /home/tony/CP_Road/Uva_record/UVA_3_star_question/count_3.cpp
CMakeFiles/count_3.dir/UVA_3_star_question/count_3.cpp.o: CMakeFiles/count_3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tony/CP_Road/Uva_record/UVA_4_star_question/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/count_3.dir/UVA_3_star_question/count_3.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/count_3.dir/UVA_3_star_question/count_3.cpp.o -MF CMakeFiles/count_3.dir/UVA_3_star_question/count_3.cpp.o.d -o CMakeFiles/count_3.dir/UVA_3_star_question/count_3.cpp.o -c /home/tony/CP_Road/Uva_record/UVA_3_star_question/count_3.cpp

CMakeFiles/count_3.dir/UVA_3_star_question/count_3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/count_3.dir/UVA_3_star_question/count_3.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tony/CP_Road/Uva_record/UVA_3_star_question/count_3.cpp > CMakeFiles/count_3.dir/UVA_3_star_question/count_3.cpp.i

CMakeFiles/count_3.dir/UVA_3_star_question/count_3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/count_3.dir/UVA_3_star_question/count_3.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tony/CP_Road/Uva_record/UVA_3_star_question/count_3.cpp -o CMakeFiles/count_3.dir/UVA_3_star_question/count_3.cpp.s

# Object files for target count_3
count_3_OBJECTS = \
"CMakeFiles/count_3.dir/UVA_3_star_question/count_3.cpp.o"

# External object files for target count_3
count_3_EXTERNAL_OBJECTS =

count_3: CMakeFiles/count_3.dir/UVA_3_star_question/count_3.cpp.o
count_3: CMakeFiles/count_3.dir/build.make
count_3: CMakeFiles/count_3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/tony/CP_Road/Uva_record/UVA_4_star_question/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable count_3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/count_3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/count_3.dir/build: count_3
.PHONY : CMakeFiles/count_3.dir/build

CMakeFiles/count_3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/count_3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/count_3.dir/clean

CMakeFiles/count_3.dir/depend:
	cd /home/tony/CP_Road/Uva_record/UVA_4_star_question && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tony/CP_Road/Uva_record /home/tony/CP_Road/Uva_record /home/tony/CP_Road/Uva_record/UVA_4_star_question /home/tony/CP_Road/Uva_record/UVA_4_star_question /home/tony/CP_Road/Uva_record/UVA_4_star_question/CMakeFiles/count_3.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/count_3.dir/depend

