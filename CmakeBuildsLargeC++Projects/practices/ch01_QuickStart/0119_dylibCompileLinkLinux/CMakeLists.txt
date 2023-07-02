if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.25)
endif ()
project(blp_ch01_part19_dylibCompileLinkLinux)

include_directories(xlog)
add_library(blp_ch01_part19_xlog SHARED xlog/xlog.cpp)
add_executable(blp_ch01_part19_test_xlog test_xlog/test_xlog.cpp)
target_link_libraries(blp_ch01_part19_test_xlog blp_ch01_part19_xlog)
