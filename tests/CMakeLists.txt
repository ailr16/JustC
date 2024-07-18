add_library(testlib rbufferTEST.c)
target_link_libraries(testlib PRIVATE ${GTEST_LIBRARIES})