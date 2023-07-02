if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.25)
endif ()
project(ch01_QuickStart)

add_subdirectory(0118_linkStaticLib)
add_subdirectory(0119_dylibCompileLinkLinux)
add_subdirectory(0120_dylibTest_Windows_mac)
