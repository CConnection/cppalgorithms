set(HEADER_LIST "${PROJECT_SOURCE_DIR}/include/datastructures/binarytree.h" datastructures/binarynode.cpp)

add_library(src STATIC "datastructures/binarytree.cpp" ${HEADER_LIST})
target_include_directories(src PUBLIC ${PROJECT_SOURCE_DIR}/include)