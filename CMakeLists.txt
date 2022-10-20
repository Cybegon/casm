cmake_minimum_required(VERSION 3.14)
project(casm C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(${CMAKE_SOURCE_DIR}/extlibs/Simple-Lexer)
add_subdirectory(src)

