cmake_minimum_required(VERSION 3.10)

project(JustC C CXX)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(dataStructures)
add_subdirectory(utils)
add_subdirectory(custom_libc)
add_subdirectory(algos)
add_subdirectory(games)
add_subdirectory(test)