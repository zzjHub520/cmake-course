cmake_minimum_required(VERSION 3.25)
project(CMAKE_CXX_COMPILER_ID_demo)

set(CMAKE_CXX_STANDARD 17)

add_executable(CMAKE_CXX_COMPILER_ID_demo main.cpp)



message("${CMAKE_CXX_COMPILER_ID}")
if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    message("Clang")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    message("GNU")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
    message("Intel")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    message("MSVC")
endif()

