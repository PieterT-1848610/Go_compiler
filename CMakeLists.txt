
cmake_minimum_required(VERSION 3.20)
project(Go_compiler )




set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wno-writable-strings")

include_directories(includes)

find_package(BISON)
find_package(FLEX)


BISON_TARGET(MyParser ../includes/Parser/parse.y ../src/Parser/parser.cpp)


include_directories(include ${FLEX_INCLUDE} ${BISON_INCLUDE})
file(GLOB src src/*.c src/*.cpp src/*/*.cpp src/*/*.c)


add_executable(Go_compiler
        ${src} src/Lexer/lex.yy.c src/Parser/parser.cpp)
