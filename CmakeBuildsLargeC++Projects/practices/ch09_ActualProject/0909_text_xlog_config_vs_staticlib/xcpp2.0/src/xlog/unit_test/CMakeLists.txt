#xcpp/src/xlog/unit_test/CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
project(unit_xlog)
include(${CMAKE_CURRENT_LIST_DIR}/../../../cmake/common.cmake)
cpp_test(${PROJECT_NAME})
target_compile_definitions(${PROJECT_NAME} PRIVATE "XLOG_STATIC")

enable_testing()