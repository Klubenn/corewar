# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/student/corewar

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/student/corewar/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/corewar.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/corewar.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/corewar.dir/flags.make

CMakeFiles/corewar.dir/src/to_bytecode.c.o: CMakeFiles/corewar.dir/flags.make
CMakeFiles/corewar.dir/src/to_bytecode.c.o: ../src/to_bytecode.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/student/corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/corewar.dir/src/to_bytecode.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar.dir/src/to_bytecode.c.o   -c /Users/student/corewar/src/to_bytecode.c

CMakeFiles/corewar.dir/src/to_bytecode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar.dir/src/to_bytecode.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/student/corewar/src/to_bytecode.c > CMakeFiles/corewar.dir/src/to_bytecode.c.i

CMakeFiles/corewar.dir/src/to_bytecode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar.dir/src/to_bytecode.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/student/corewar/src/to_bytecode.c -o CMakeFiles/corewar.dir/src/to_bytecode.c.s

CMakeFiles/corewar.dir/src/op.c.o: CMakeFiles/corewar.dir/flags.make
CMakeFiles/corewar.dir/src/op.c.o: ../src/op.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/student/corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/corewar.dir/src/op.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar.dir/src/op.c.o   -c /Users/student/corewar/src/op.c

CMakeFiles/corewar.dir/src/op.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar.dir/src/op.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/student/corewar/src/op.c > CMakeFiles/corewar.dir/src/op.c.i

CMakeFiles/corewar.dir/src/op.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar.dir/src/op.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/student/corewar/src/op.c -o CMakeFiles/corewar.dir/src/op.c.s

CMakeFiles/corewar.dir/other/print_file.c.o: CMakeFiles/corewar.dir/flags.make
CMakeFiles/corewar.dir/other/print_file.c.o: ../other/print_file.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/student/corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/corewar.dir/other/print_file.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar.dir/other/print_file.c.o   -c /Users/student/corewar/other/print_file.c

CMakeFiles/corewar.dir/other/print_file.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar.dir/other/print_file.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/student/corewar/other/print_file.c > CMakeFiles/corewar.dir/other/print_file.c.i

CMakeFiles/corewar.dir/other/print_file.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar.dir/other/print_file.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/student/corewar/other/print_file.c -o CMakeFiles/corewar.dir/other/print_file.c.s

CMakeFiles/corewar.dir/src/asm.c.o: CMakeFiles/corewar.dir/flags.make
CMakeFiles/corewar.dir/src/asm.c.o: ../src/asm.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/student/corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/corewar.dir/src/asm.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar.dir/src/asm.c.o   -c /Users/student/corewar/src/asm.c

CMakeFiles/corewar.dir/src/asm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar.dir/src/asm.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/student/corewar/src/asm.c > CMakeFiles/corewar.dir/src/asm.c.i

CMakeFiles/corewar.dir/src/asm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar.dir/src/asm.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/student/corewar/src/asm.c -o CMakeFiles/corewar.dir/src/asm.c.s

CMakeFiles/corewar.dir/src/champ_exec_code.c.o: CMakeFiles/corewar.dir/flags.make
CMakeFiles/corewar.dir/src/champ_exec_code.c.o: ../src/champ_exec_code.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/student/corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/corewar.dir/src/champ_exec_code.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar.dir/src/champ_exec_code.c.o   -c /Users/student/corewar/src/champ_exec_code.c

CMakeFiles/corewar.dir/src/champ_exec_code.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar.dir/src/champ_exec_code.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/student/corewar/src/champ_exec_code.c > CMakeFiles/corewar.dir/src/champ_exec_code.c.i

CMakeFiles/corewar.dir/src/champ_exec_code.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar.dir/src/champ_exec_code.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/student/corewar/src/champ_exec_code.c -o CMakeFiles/corewar.dir/src/champ_exec_code.c.s

CMakeFiles/corewar.dir/other/sample_t_struct.c.o: CMakeFiles/corewar.dir/flags.make
CMakeFiles/corewar.dir/other/sample_t_struct.c.o: ../other/sample_t_struct.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/student/corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/corewar.dir/other/sample_t_struct.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar.dir/other/sample_t_struct.c.o   -c /Users/student/corewar/other/sample_t_struct.c

CMakeFiles/corewar.dir/other/sample_t_struct.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar.dir/other/sample_t_struct.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/student/corewar/other/sample_t_struct.c > CMakeFiles/corewar.dir/other/sample_t_struct.c.i

CMakeFiles/corewar.dir/other/sample_t_struct.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar.dir/other/sample_t_struct.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/student/corewar/other/sample_t_struct.c -o CMakeFiles/corewar.dir/other/sample_t_struct.c.s

CMakeFiles/corewar.dir/src/labels.c.o: CMakeFiles/corewar.dir/flags.make
CMakeFiles/corewar.dir/src/labels.c.o: ../src/labels.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/student/corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/corewar.dir/src/labels.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar.dir/src/labels.c.o   -c /Users/student/corewar/src/labels.c

CMakeFiles/corewar.dir/src/labels.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar.dir/src/labels.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/student/corewar/src/labels.c > CMakeFiles/corewar.dir/src/labels.c.i

CMakeFiles/corewar.dir/src/labels.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar.dir/src/labels.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/student/corewar/src/labels.c -o CMakeFiles/corewar.dir/src/labels.c.s

# Object files for target corewar
corewar_OBJECTS = \
"CMakeFiles/corewar.dir/src/to_bytecode.c.o" \
"CMakeFiles/corewar.dir/src/op.c.o" \
"CMakeFiles/corewar.dir/other/print_file.c.o" \
"CMakeFiles/corewar.dir/src/asm.c.o" \
"CMakeFiles/corewar.dir/src/champ_exec_code.c.o" \
"CMakeFiles/corewar.dir/other/sample_t_struct.c.o" \
"CMakeFiles/corewar.dir/src/labels.c.o"

# External object files for target corewar
corewar_EXTERNAL_OBJECTS =

corewar: CMakeFiles/corewar.dir/src/to_bytecode.c.o
corewar: CMakeFiles/corewar.dir/src/op.c.o
corewar: CMakeFiles/corewar.dir/other/print_file.c.o
corewar: CMakeFiles/corewar.dir/src/asm.c.o
corewar: CMakeFiles/corewar.dir/src/champ_exec_code.c.o
corewar: CMakeFiles/corewar.dir/other/sample_t_struct.c.o
corewar: CMakeFiles/corewar.dir/src/labels.c.o
corewar: CMakeFiles/corewar.dir/build.make
corewar: ../libft/libft.a
corewar: CMakeFiles/corewar.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/student/corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable corewar"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/corewar.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/corewar.dir/build: corewar

.PHONY : CMakeFiles/corewar.dir/build

CMakeFiles/corewar.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/corewar.dir/cmake_clean.cmake
.PHONY : CMakeFiles/corewar.dir/clean

CMakeFiles/corewar.dir/depend:
	cd /Users/student/corewar/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/student/corewar /Users/student/corewar /Users/student/corewar/cmake-build-debug /Users/student/corewar/cmake-build-debug /Users/student/corewar/cmake-build-debug/CMakeFiles/corewar.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/corewar.dir/depend

