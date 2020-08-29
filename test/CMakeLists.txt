
add_executable(unit_test test.cpp )
target_link_libraries(unit_test ${GTEST_LIBRARIES} ${CPPCONLIB} pthread)

