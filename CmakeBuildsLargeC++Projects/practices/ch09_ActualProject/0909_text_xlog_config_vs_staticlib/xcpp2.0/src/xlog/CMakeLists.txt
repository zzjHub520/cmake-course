#xcpp/src/xlog/CMakeLists.txt
# xlog库编译
cmake_minimum_required(VERSION 3.22)

project(xlog)

include(${CMAKE_CURRENT_LIST_DIR}/../../cmake/common.cmake)

cpp_library(${PROJECT_NAME})

# 生成c++代码，传递命名空间
configure_file(xconfig.h.in ${CMAKE_CURRENT_LIST_DIR}/include/xconfig.h)


