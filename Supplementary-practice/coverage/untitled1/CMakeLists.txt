cmake_minimum_required(VERSION 3.25)
project(untitled1)

set(CMAKE_CXX_STANDARD 17)
include(cmake/SimpleExportCompileCommads.cmake)
include(cmake/coverage.cmake)

add_subdirectory(add)
add_subdirectory(sub)
add_subdirectory(test)


EndCoverage()