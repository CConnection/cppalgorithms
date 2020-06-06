cmake_minimum_required(VERSION 3.16)
project(algorithms)

set(CMAKE_CXX_STANDARD 14)

add_executable(tests main.cpp)
target_link_libraries(tests Catch2::Catch2)