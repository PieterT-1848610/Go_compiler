# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Go_compiler.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Go_compiler.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Go_compiler.dir/flags.make

../src/Parser/parser.cpp: C:/Users/thomi/Documents/Master/Compilers/giti/includes/Parser/parse.y
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BISON][MyParser] Building parser with bison 2.4.1"
	C:\Users\thomi\Documents\makegnu\GnuWin32\bin\bison.exe -d -o ../src/Parser/parser.cpp C:/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/../includes/Parser/parse.y

../src/Parser/parser.hpp: ../src/Parser/parser.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate ..\src\Parser\parser.hpp

CMakeFiles/Go_compiler.dir/src/ASB/asb.cpp.obj: CMakeFiles/Go_compiler.dir/flags.make
CMakeFiles/Go_compiler.dir/src/ASB/asb.cpp.obj: CMakeFiles/Go_compiler.dir/includes_CXX.rsp
CMakeFiles/Go_compiler.dir/src/ASB/asb.cpp.obj: ../src/ASB/asb.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Go_compiler.dir/src/ASB/asb.cpp.obj"
	C:\MinGW\bin\g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Go_compiler.dir\src\ASB\asb.cpp.obj -c C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler\src\ASB\asb.cpp

CMakeFiles/Go_compiler.dir/src/ASB/asb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Go_compiler.dir/src/ASB/asb.cpp.i"
	C:\MinGW\bin\g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler\src\ASB\asb.cpp > CMakeFiles\Go_compiler.dir\src\ASB\asb.cpp.i

CMakeFiles/Go_compiler.dir/src/ASB/asb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Go_compiler.dir/src/ASB/asb.cpp.s"
	C:\MinGW\bin\g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler\src\ASB\asb.cpp -o CMakeFiles\Go_compiler.dir\src\ASB\asb.cpp.s

CMakeFiles/Go_compiler.dir/src/Lexer/lex.yy.c.obj: CMakeFiles/Go_compiler.dir/flags.make
CMakeFiles/Go_compiler.dir/src/Lexer/lex.yy.c.obj: CMakeFiles/Go_compiler.dir/includes_C.rsp
CMakeFiles/Go_compiler.dir/src/Lexer/lex.yy.c.obj: ../src/Lexer/lex.yy.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Go_compiler.dir/src/Lexer/lex.yy.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Go_compiler.dir\src\Lexer\lex.yy.c.obj -c C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler\src\Lexer\lex.yy.c

CMakeFiles/Go_compiler.dir/src/Lexer/lex.yy.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Go_compiler.dir/src/Lexer/lex.yy.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler\src\Lexer\lex.yy.c > CMakeFiles\Go_compiler.dir\src\Lexer\lex.yy.c.i

CMakeFiles/Go_compiler.dir/src/Lexer/lex.yy.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Go_compiler.dir/src/Lexer/lex.yy.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler\src\Lexer\lex.yy.c -o CMakeFiles\Go_compiler.dir\src\Lexer\lex.yy.c.s

CMakeFiles/Go_compiler.dir/src/Lexer/lexer.cpp.obj: CMakeFiles/Go_compiler.dir/flags.make
CMakeFiles/Go_compiler.dir/src/Lexer/lexer.cpp.obj: CMakeFiles/Go_compiler.dir/includes_CXX.rsp
CMakeFiles/Go_compiler.dir/src/Lexer/lexer.cpp.obj: ../src/Lexer/lexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Go_compiler.dir/src/Lexer/lexer.cpp.obj"
	C:\MinGW\bin\g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Go_compiler.dir\src\Lexer\lexer.cpp.obj -c C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler\src\Lexer\lexer.cpp

CMakeFiles/Go_compiler.dir/src/Lexer/lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Go_compiler.dir/src/Lexer/lexer.cpp.i"
	C:\MinGW\bin\g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler\src\Lexer\lexer.cpp > CMakeFiles\Go_compiler.dir\src\Lexer\lexer.cpp.i

CMakeFiles/Go_compiler.dir/src/Lexer/lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Go_compiler.dir/src/Lexer/lexer.cpp.s"
	C:\MinGW\bin\g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler\src\Lexer\lexer.cpp -o CMakeFiles\Go_compiler.dir\src\Lexer\lexer.cpp.s

CMakeFiles/Go_compiler.dir/src/lexer.c.obj: CMakeFiles/Go_compiler.dir/flags.make
CMakeFiles/Go_compiler.dir/src/lexer.c.obj: CMakeFiles/Go_compiler.dir/includes_C.rsp
CMakeFiles/Go_compiler.dir/src/lexer.c.obj: ../src/lexer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Go_compiler.dir/src/lexer.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Go_compiler.dir\src\lexer.c.obj -c C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler\src\lexer.c

CMakeFiles/Go_compiler.dir/src/lexer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Go_compiler.dir/src/lexer.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler\src\lexer.c > CMakeFiles\Go_compiler.dir\src\lexer.c.i

CMakeFiles/Go_compiler.dir/src/lexer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Go_compiler.dir/src/lexer.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler\src\lexer.c -o CMakeFiles\Go_compiler.dir\src\lexer.c.s

CMakeFiles/Go_compiler.dir/src/main.cpp.obj: CMakeFiles/Go_compiler.dir/flags.make
CMakeFiles/Go_compiler.dir/src/main.cpp.obj: CMakeFiles/Go_compiler.dir/includes_CXX.rsp
CMakeFiles/Go_compiler.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Go_compiler.dir/src/main.cpp.obj"
	C:\MinGW\bin\g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Go_compiler.dir\src\main.cpp.obj -c C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler\src\main.cpp

CMakeFiles/Go_compiler.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Go_compiler.dir/src/main.cpp.i"
	C:\MinGW\bin\g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler\src\main.cpp > CMakeFiles\Go_compiler.dir\src\main.cpp.i

CMakeFiles/Go_compiler.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Go_compiler.dir/src/main.cpp.s"
	C:\MinGW\bin\g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler\src\main.cpp -o CMakeFiles\Go_compiler.dir\src\main.cpp.s

CMakeFiles/Go_compiler.dir/src/Parser/parser.cpp.obj: CMakeFiles/Go_compiler.dir/flags.make
CMakeFiles/Go_compiler.dir/src/Parser/parser.cpp.obj: CMakeFiles/Go_compiler.dir/includes_CXX.rsp
CMakeFiles/Go_compiler.dir/src/Parser/parser.cpp.obj: ../src/Parser/parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Go_compiler.dir/src/Parser/parser.cpp.obj"
	C:\MinGW\bin\g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Go_compiler.dir\src\Parser\parser.cpp.obj -c C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler\src\Parser\parser.cpp

CMakeFiles/Go_compiler.dir/src/Parser/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Go_compiler.dir/src/Parser/parser.cpp.i"
	C:\MinGW\bin\g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler\src\Parser\parser.cpp > CMakeFiles\Go_compiler.dir\src\Parser\parser.cpp.i

CMakeFiles/Go_compiler.dir/src/Parser/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Go_compiler.dir/src/Parser/parser.cpp.s"
	C:\MinGW\bin\g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler\src\Parser\parser.cpp -o CMakeFiles\Go_compiler.dir\src\Parser\parser.cpp.s

# Object files for target Go_compiler
Go_compiler_OBJECTS = \
"CMakeFiles/Go_compiler.dir/src/ASB/asb.cpp.obj" \
"CMakeFiles/Go_compiler.dir/src/Lexer/lex.yy.c.obj" \
"CMakeFiles/Go_compiler.dir/src/Lexer/lexer.cpp.obj" \
"CMakeFiles/Go_compiler.dir/src/lexer.c.obj" \
"CMakeFiles/Go_compiler.dir/src/main.cpp.obj" \
"CMakeFiles/Go_compiler.dir/src/Parser/parser.cpp.obj"

# External object files for target Go_compiler
Go_compiler_EXTERNAL_OBJECTS =

Go_compiler.exe: CMakeFiles/Go_compiler.dir/src/ASB/asb.cpp.obj
Go_compiler.exe: CMakeFiles/Go_compiler.dir/src/Lexer/lex.yy.c.obj
Go_compiler.exe: CMakeFiles/Go_compiler.dir/src/Lexer/lexer.cpp.obj
Go_compiler.exe: CMakeFiles/Go_compiler.dir/src/lexer.c.obj
Go_compiler.exe: CMakeFiles/Go_compiler.dir/src/main.cpp.obj
Go_compiler.exe: CMakeFiles/Go_compiler.dir/src/Parser/parser.cpp.obj
Go_compiler.exe: CMakeFiles/Go_compiler.dir/build.make
Go_compiler.exe: CMakeFiles/Go_compiler.dir/linklibs.rsp
Go_compiler.exe: CMakeFiles/Go_compiler.dir/objects1.rsp
Go_compiler.exe: CMakeFiles/Go_compiler.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Go_compiler.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Go_compiler.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Go_compiler.dir/build: Go_compiler.exe
.PHONY : CMakeFiles/Go_compiler.dir/build

CMakeFiles/Go_compiler.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Go_compiler.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Go_compiler.dir/clean

CMakeFiles/Go_compiler.dir/depend: ../src/Parser/parser.cpp
CMakeFiles/Go_compiler.dir/depend: ../src/Parser/parser.hpp
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler\cmake-build-debug C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler\cmake-build-debug C:\Users\thomi\Documents\Master\Compilers\giti\Go_compiler\cmake-build-debug\CMakeFiles\Go_compiler.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Go_compiler.dir/depend
