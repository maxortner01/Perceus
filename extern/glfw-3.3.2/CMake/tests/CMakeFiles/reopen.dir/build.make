# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Max\Desktop\Perceus\extern\glfw-3.3.2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Max\Desktop\Perceus\extern\glfw-3.3.2\CMake

# Include any dependencies generated for this target.
include tests/CMakeFiles/reopen.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/reopen.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/reopen.dir/flags.make

tests/CMakeFiles/reopen.dir/reopen.c.obj: tests/CMakeFiles/reopen.dir/flags.make
tests/CMakeFiles/reopen.dir/reopen.c.obj: tests/CMakeFiles/reopen.dir/includes_C.rsp
tests/CMakeFiles/reopen.dir/reopen.c.obj: ../tests/reopen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Max\Desktop\Perceus\extern\glfw-3.3.2\CMake\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/reopen.dir/reopen.c.obj"
	cd /d C:\Users\Max\Desktop\Perceus\extern\glfw-3.3.2\CMake\tests && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\reopen.dir\reopen.c.obj   -c C:\Users\Max\Desktop\Perceus\extern\glfw-3.3.2\tests\reopen.c

tests/CMakeFiles/reopen.dir/reopen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/reopen.dir/reopen.c.i"
	cd /d C:\Users\Max\Desktop\Perceus\extern\glfw-3.3.2\CMake\tests && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Max\Desktop\Perceus\extern\glfw-3.3.2\tests\reopen.c > CMakeFiles\reopen.dir\reopen.c.i

tests/CMakeFiles/reopen.dir/reopen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/reopen.dir/reopen.c.s"
	cd /d C:\Users\Max\Desktop\Perceus\extern\glfw-3.3.2\CMake\tests && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Max\Desktop\Perceus\extern\glfw-3.3.2\tests\reopen.c -o CMakeFiles\reopen.dir\reopen.c.s

tests/CMakeFiles/reopen.dir/__/deps/glad_gl.c.obj: tests/CMakeFiles/reopen.dir/flags.make
tests/CMakeFiles/reopen.dir/__/deps/glad_gl.c.obj: tests/CMakeFiles/reopen.dir/includes_C.rsp
tests/CMakeFiles/reopen.dir/__/deps/glad_gl.c.obj: ../deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Max\Desktop\Perceus\extern\glfw-3.3.2\CMake\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/CMakeFiles/reopen.dir/__/deps/glad_gl.c.obj"
	cd /d C:\Users\Max\Desktop\Perceus\extern\glfw-3.3.2\CMake\tests && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\reopen.dir\__\deps\glad_gl.c.obj   -c C:\Users\Max\Desktop\Perceus\extern\glfw-3.3.2\deps\glad_gl.c

tests/CMakeFiles/reopen.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/reopen.dir/__/deps/glad_gl.c.i"
	cd /d C:\Users\Max\Desktop\Perceus\extern\glfw-3.3.2\CMake\tests && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Max\Desktop\Perceus\extern\glfw-3.3.2\deps\glad_gl.c > CMakeFiles\reopen.dir\__\deps\glad_gl.c.i

tests/CMakeFiles/reopen.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/reopen.dir/__/deps/glad_gl.c.s"
	cd /d C:\Users\Max\Desktop\Perceus\extern\glfw-3.3.2\CMake\tests && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Max\Desktop\Perceus\extern\glfw-3.3.2\deps\glad_gl.c -o CMakeFiles\reopen.dir\__\deps\glad_gl.c.s

# Object files for target reopen
reopen_OBJECTS = \
"CMakeFiles/reopen.dir/reopen.c.obj" \
"CMakeFiles/reopen.dir/__/deps/glad_gl.c.obj"

# External object files for target reopen
reopen_EXTERNAL_OBJECTS =

tests/reopen.exe: tests/CMakeFiles/reopen.dir/reopen.c.obj
tests/reopen.exe: tests/CMakeFiles/reopen.dir/__/deps/glad_gl.c.obj
tests/reopen.exe: tests/CMakeFiles/reopen.dir/build.make
tests/reopen.exe: src/libglfw3.a
tests/reopen.exe: tests/CMakeFiles/reopen.dir/linklibs.rsp
tests/reopen.exe: tests/CMakeFiles/reopen.dir/objects1.rsp
tests/reopen.exe: tests/CMakeFiles/reopen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Max\Desktop\Perceus\extern\glfw-3.3.2\CMake\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable reopen.exe"
	cd /d C:\Users\Max\Desktop\Perceus\extern\glfw-3.3.2\CMake\tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\reopen.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/reopen.dir/build: tests/reopen.exe

.PHONY : tests/CMakeFiles/reopen.dir/build

tests/CMakeFiles/reopen.dir/clean:
	cd /d C:\Users\Max\Desktop\Perceus\extern\glfw-3.3.2\CMake\tests && $(CMAKE_COMMAND) -P CMakeFiles\reopen.dir\cmake_clean.cmake
.PHONY : tests/CMakeFiles/reopen.dir/clean

tests/CMakeFiles/reopen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Max\Desktop\Perceus\extern\glfw-3.3.2 C:\Users\Max\Desktop\Perceus\extern\glfw-3.3.2\tests C:\Users\Max\Desktop\Perceus\extern\glfw-3.3.2\CMake C:\Users\Max\Desktop\Perceus\extern\glfw-3.3.2\CMake\tests C:\Users\Max\Desktop\Perceus\extern\glfw-3.3.2\CMake\tests\CMakeFiles\reopen.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/reopen.dir/depend

