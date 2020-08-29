cmake_minimum_required(VERSION 2.6)

find_package(GTest REQUIRED)

set( ${CPPCONINC} /usr/include/conn  )
set( ${CPPCONLIB} /usr/lib/x86_64-linux-gnu/libmysqlcppconn.so )
include_directories(${GTEST_INCLUDE_DIRS} ${CPPCONINC} ./engine/ )

# file(GLOB_RECURSE engine_src engine/*.cpp)
# file(GLOB_RECURSE test_src test/*.cpp)

add_subdirectory(engine)
add_subdirectory(test)



