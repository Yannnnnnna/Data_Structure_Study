cmake_minimum_required(VERSION 3.25)
project(01structStudy C)

set(CMAKE_C_STANDARD 11)

add_executable(01structStudy Liner/sqList/main.c)
add_subdirectory(Liner)
add_subdirectory(Tree)