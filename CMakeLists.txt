cmake_minimum_required(VERSION 3.12)
project(pjc_1)

set(CMAKE_CXX_STANDARD 14)
add_compile_definitions(ENG)
add_compile_definitions(GETMAX)
add_compile_definitions(ZAD_4)

add_executable(pjc_1 main.cpp)