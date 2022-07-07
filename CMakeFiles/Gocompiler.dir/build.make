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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler

# Include any dependencies generated for this target.
include CMakeFiles/Gocompiler.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Gocompiler.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Gocompiler.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Gocompiler.dir/flags.make

src/Parser/parser.cpp: includes/Parser/parse.y
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BISON][MyParser] Building parser with bison 3.5.1"
	/usr/bin/bison -d -o src/Parser/parser.cpp /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y

src/Parser/parser.hpp: src/Parser/parser.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate src/Parser/parser.hpp

src/Lexer/lexer.cpp: src/Lexer/go.l
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "[FLEX][MyScanner] Building scanner with flex 2.6.4"
	/usr/bin/flex -o/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/src/Lexer/lexer.cpp /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/src/Lexer/go.l

CMakeFiles/Gocompiler.dir/src/ASB/asb.cpp.o: CMakeFiles/Gocompiler.dir/flags.make
CMakeFiles/Gocompiler.dir/src/ASB/asb.cpp.o: src/ASB/asb.cpp
CMakeFiles/Gocompiler.dir/src/ASB/asb.cpp.o: CMakeFiles/Gocompiler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Gocompiler.dir/src/ASB/asb.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Gocompiler.dir/src/ASB/asb.cpp.o -MF CMakeFiles/Gocompiler.dir/src/ASB/asb.cpp.o.d -o CMakeFiles/Gocompiler.dir/src/ASB/asb.cpp.o -c /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/src/ASB/asb.cpp

CMakeFiles/Gocompiler.dir/src/ASB/asb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Gocompiler.dir/src/ASB/asb.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/src/ASB/asb.cpp > CMakeFiles/Gocompiler.dir/src/ASB/asb.cpp.i

CMakeFiles/Gocompiler.dir/src/ASB/asb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Gocompiler.dir/src/ASB/asb.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/src/ASB/asb.cpp -o CMakeFiles/Gocompiler.dir/src/ASB/asb.cpp.s

CMakeFiles/Gocompiler.dir/src/ASB/declaration.cpp.o: CMakeFiles/Gocompiler.dir/flags.make
CMakeFiles/Gocompiler.dir/src/ASB/declaration.cpp.o: src/ASB/declaration.cpp
CMakeFiles/Gocompiler.dir/src/ASB/declaration.cpp.o: CMakeFiles/Gocompiler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Gocompiler.dir/src/ASB/declaration.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Gocompiler.dir/src/ASB/declaration.cpp.o -MF CMakeFiles/Gocompiler.dir/src/ASB/declaration.cpp.o.d -o CMakeFiles/Gocompiler.dir/src/ASB/declaration.cpp.o -c /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/src/ASB/declaration.cpp

CMakeFiles/Gocompiler.dir/src/ASB/declaration.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Gocompiler.dir/src/ASB/declaration.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/src/ASB/declaration.cpp > CMakeFiles/Gocompiler.dir/src/ASB/declaration.cpp.i

CMakeFiles/Gocompiler.dir/src/ASB/declaration.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Gocompiler.dir/src/ASB/declaration.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/src/ASB/declaration.cpp -o CMakeFiles/Gocompiler.dir/src/ASB/declaration.cpp.s

CMakeFiles/Gocompiler.dir/src/ASB/expression.cpp.o: CMakeFiles/Gocompiler.dir/flags.make
CMakeFiles/Gocompiler.dir/src/ASB/expression.cpp.o: src/ASB/expression.cpp
CMakeFiles/Gocompiler.dir/src/ASB/expression.cpp.o: CMakeFiles/Gocompiler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Gocompiler.dir/src/ASB/expression.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Gocompiler.dir/src/ASB/expression.cpp.o -MF CMakeFiles/Gocompiler.dir/src/ASB/expression.cpp.o.d -o CMakeFiles/Gocompiler.dir/src/ASB/expression.cpp.o -c /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/src/ASB/expression.cpp

CMakeFiles/Gocompiler.dir/src/ASB/expression.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Gocompiler.dir/src/ASB/expression.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/src/ASB/expression.cpp > CMakeFiles/Gocompiler.dir/src/ASB/expression.cpp.i

CMakeFiles/Gocompiler.dir/src/ASB/expression.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Gocompiler.dir/src/ASB/expression.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/src/ASB/expression.cpp -o CMakeFiles/Gocompiler.dir/src/ASB/expression.cpp.s

CMakeFiles/Gocompiler.dir/src/ASB/statment.cpp.o: CMakeFiles/Gocompiler.dir/flags.make
CMakeFiles/Gocompiler.dir/src/ASB/statment.cpp.o: src/ASB/statment.cpp
CMakeFiles/Gocompiler.dir/src/ASB/statment.cpp.o: CMakeFiles/Gocompiler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Gocompiler.dir/src/ASB/statment.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Gocompiler.dir/src/ASB/statment.cpp.o -MF CMakeFiles/Gocompiler.dir/src/ASB/statment.cpp.o.d -o CMakeFiles/Gocompiler.dir/src/ASB/statment.cpp.o -c /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/src/ASB/statment.cpp

CMakeFiles/Gocompiler.dir/src/ASB/statment.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Gocompiler.dir/src/ASB/statment.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/src/ASB/statment.cpp > CMakeFiles/Gocompiler.dir/src/ASB/statment.cpp.i

CMakeFiles/Gocompiler.dir/src/ASB/statment.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Gocompiler.dir/src/ASB/statment.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/src/ASB/statment.cpp -o CMakeFiles/Gocompiler.dir/src/ASB/statment.cpp.s

CMakeFiles/Gocompiler.dir/src/ASB/types.cpp.o: CMakeFiles/Gocompiler.dir/flags.make
CMakeFiles/Gocompiler.dir/src/ASB/types.cpp.o: src/ASB/types.cpp
CMakeFiles/Gocompiler.dir/src/ASB/types.cpp.o: CMakeFiles/Gocompiler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Gocompiler.dir/src/ASB/types.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Gocompiler.dir/src/ASB/types.cpp.o -MF CMakeFiles/Gocompiler.dir/src/ASB/types.cpp.o.d -o CMakeFiles/Gocompiler.dir/src/ASB/types.cpp.o -c /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/src/ASB/types.cpp

CMakeFiles/Gocompiler.dir/src/ASB/types.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Gocompiler.dir/src/ASB/types.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/src/ASB/types.cpp > CMakeFiles/Gocompiler.dir/src/ASB/types.cpp.i

CMakeFiles/Gocompiler.dir/src/ASB/types.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Gocompiler.dir/src/ASB/types.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/src/ASB/types.cpp -o CMakeFiles/Gocompiler.dir/src/ASB/types.cpp.s

CMakeFiles/Gocompiler.dir/src/Lexer/lexer.cpp.o: CMakeFiles/Gocompiler.dir/flags.make
CMakeFiles/Gocompiler.dir/src/Lexer/lexer.cpp.o: src/Lexer/lexer.cpp
CMakeFiles/Gocompiler.dir/src/Lexer/lexer.cpp.o: src/Parser/parser.hpp
CMakeFiles/Gocompiler.dir/src/Lexer/lexer.cpp.o: CMakeFiles/Gocompiler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Gocompiler.dir/src/Lexer/lexer.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Gocompiler.dir/src/Lexer/lexer.cpp.o -MF CMakeFiles/Gocompiler.dir/src/Lexer/lexer.cpp.o.d -o CMakeFiles/Gocompiler.dir/src/Lexer/lexer.cpp.o -c /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/src/Lexer/lexer.cpp

CMakeFiles/Gocompiler.dir/src/Lexer/lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Gocompiler.dir/src/Lexer/lexer.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/src/Lexer/lexer.cpp > CMakeFiles/Gocompiler.dir/src/Lexer/lexer.cpp.i

CMakeFiles/Gocompiler.dir/src/Lexer/lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Gocompiler.dir/src/Lexer/lexer.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/src/Lexer/lexer.cpp -o CMakeFiles/Gocompiler.dir/src/Lexer/lexer.cpp.s

CMakeFiles/Gocompiler.dir/src/main.cpp.o: CMakeFiles/Gocompiler.dir/flags.make
CMakeFiles/Gocompiler.dir/src/main.cpp.o: src/main.cpp
CMakeFiles/Gocompiler.dir/src/main.cpp.o: CMakeFiles/Gocompiler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Gocompiler.dir/src/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Gocompiler.dir/src/main.cpp.o -MF CMakeFiles/Gocompiler.dir/src/main.cpp.o.d -o CMakeFiles/Gocompiler.dir/src/main.cpp.o -c /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/src/main.cpp

CMakeFiles/Gocompiler.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Gocompiler.dir/src/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/src/main.cpp > CMakeFiles/Gocompiler.dir/src/main.cpp.i

CMakeFiles/Gocompiler.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Gocompiler.dir/src/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/src/main.cpp -o CMakeFiles/Gocompiler.dir/src/main.cpp.s

CMakeFiles/Gocompiler.dir/src/Parser/parser.cpp.o: CMakeFiles/Gocompiler.dir/flags.make
CMakeFiles/Gocompiler.dir/src/Parser/parser.cpp.o: src/Parser/parser.cpp
CMakeFiles/Gocompiler.dir/src/Parser/parser.cpp.o: CMakeFiles/Gocompiler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Gocompiler.dir/src/Parser/parser.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Gocompiler.dir/src/Parser/parser.cpp.o -MF CMakeFiles/Gocompiler.dir/src/Parser/parser.cpp.o.d -o CMakeFiles/Gocompiler.dir/src/Parser/parser.cpp.o -c /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/src/Parser/parser.cpp

CMakeFiles/Gocompiler.dir/src/Parser/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Gocompiler.dir/src/Parser/parser.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/src/Parser/parser.cpp > CMakeFiles/Gocompiler.dir/src/Parser/parser.cpp.i

CMakeFiles/Gocompiler.dir/src/Parser/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Gocompiler.dir/src/Parser/parser.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/src/Parser/parser.cpp -o CMakeFiles/Gocompiler.dir/src/Parser/parser.cpp.s

# Object files for target Gocompiler
Gocompiler_OBJECTS = \
"CMakeFiles/Gocompiler.dir/src/ASB/asb.cpp.o" \
"CMakeFiles/Gocompiler.dir/src/ASB/declaration.cpp.o" \
"CMakeFiles/Gocompiler.dir/src/ASB/expression.cpp.o" \
"CMakeFiles/Gocompiler.dir/src/ASB/statment.cpp.o" \
"CMakeFiles/Gocompiler.dir/src/ASB/types.cpp.o" \
"CMakeFiles/Gocompiler.dir/src/Lexer/lexer.cpp.o" \
"CMakeFiles/Gocompiler.dir/src/main.cpp.o" \
"CMakeFiles/Gocompiler.dir/src/Parser/parser.cpp.o"

# External object files for target Gocompiler
Gocompiler_EXTERNAL_OBJECTS =

Gocompiler: CMakeFiles/Gocompiler.dir/src/ASB/asb.cpp.o
Gocompiler: CMakeFiles/Gocompiler.dir/src/ASB/declaration.cpp.o
Gocompiler: CMakeFiles/Gocompiler.dir/src/ASB/expression.cpp.o
Gocompiler: CMakeFiles/Gocompiler.dir/src/ASB/statment.cpp.o
Gocompiler: CMakeFiles/Gocompiler.dir/src/ASB/types.cpp.o
Gocompiler: CMakeFiles/Gocompiler.dir/src/Lexer/lexer.cpp.o
Gocompiler: CMakeFiles/Gocompiler.dir/src/main.cpp.o
Gocompiler: CMakeFiles/Gocompiler.dir/src/Parser/parser.cpp.o
Gocompiler: CMakeFiles/Gocompiler.dir/build.make
Gocompiler: CMakeFiles/Gocompiler.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable Gocompiler"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Gocompiler.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Gocompiler.dir/build: Gocompiler
.PHONY : CMakeFiles/Gocompiler.dir/build

CMakeFiles/Gocompiler.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Gocompiler.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Gocompiler.dir/clean

CMakeFiles/Gocompiler.dir/depend: src/Lexer/lexer.cpp
CMakeFiles/Gocompiler.dir/depend: src/Parser/parser.cpp
CMakeFiles/Gocompiler.dir/depend: src/Parser/parser.hpp
	cd /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler /mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/CMakeFiles/Gocompiler.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Gocompiler.dir/depend

