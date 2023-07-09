if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.22)
endif ()
project(test_xlog)
include(${CMAKE_CURRENT_LIST_DIR}/../../../cmake/common.cmake)


cpp_execute(${PROJECT_NAME} xlog)
target_include_directories(${PROJECT_NAME} PRIVATE "../../xlog/include")


