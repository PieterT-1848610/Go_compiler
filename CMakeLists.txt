cmake_minimum_required(VERSION 3.20)
project(Go_compiler C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Go_compiler
        ${src} src/Lexer/lex.yy.c src/Parser/parser.cpp)
