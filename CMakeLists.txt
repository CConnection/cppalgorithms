cmake_minimum_required(VERSION 3.16)
project(algorithms)

set(CMAKE_CXX_STANDARD 14)
add_executable(tests library.h library.cpp)
add_library(algorithms library.cpp library.h tests/dosomething.cpp tests/dosomething.h)