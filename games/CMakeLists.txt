include_directories(inc)

add_library(window_lib src/windowTest.c)
add_executable(prog src/windowTest.c)
target_link_libraries(prog X11)