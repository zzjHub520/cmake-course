cmake_minimum_required(VERSION 3.25)
project(untitled1)

set(CMAKE_CXX_STANDARD 17)
include(cmake/SimpleExportCompileCommads.cmake)
include(cmake/coverage.cmake)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

add_subdirectory(add)
add_subdirectory(sub)
add_subdirectory(test)

message("$CACHE{TEST_TGTS}")

EndCoverage()