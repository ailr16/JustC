#cmake -Bbuild
#cmake --build build

cmake_minimum_required(VERSION 3.22)
project("Gtest CXX")

find_package(GTest REQUIRED)

include_directories(inc)
add_subdirectory(src)
add_subdirectory(tests)

add_executable(justc main.c)
target_link_libraries(justc PRIVATE justclib)

add_executable(justcTEST TEST.c)
target_link_libraries(justcTEST PRIVATE ${GTEST_LIBRARIES} justclib testlib)

#ctest
enable_testing()
add_test(add justcTEST)