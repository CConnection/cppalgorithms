cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 14)

add_executable(tests main.cpp datastructures/binarytree.spec.cpp datastructures/binarynode.spec.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2 src)