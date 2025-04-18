include_directories(
    inc
    ${CMAKE_HOME_DIRECTORY}/dataStructures/inc
)

add_library(algos_lib src/algos.c)
target_link_libraries(
    algos_lib
    PRIVATE
        slist_lib)