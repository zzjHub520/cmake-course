if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.25)
endif ()

project(blp_ch02_part14_xlog)
include_directories("xlog")

#CMakeLists.txt路径
message("CMAKE_CURRENT_LIST_DIR = ${CMAKE_CURRENT_LIST_DIR}")
message("CMAKE_CURRENT_LIST_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")
# .so库输出路径 默认路径在-B build目录下
# 当前路径 src/109   lib/
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/../../lib")
#linux .so输出路径
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/lib")

#执行程序和dll 动态库pdb调试文件 输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/bin")

#归档输出路径 静态库 .lib 动态库.lib地址文件 linux静态库.a 静态库pdb调试文件
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/lib")

#添加xlog库编译 项目自带预处理变量 xlog_EXPORTS
#add_library(blp_ch02_part14_xlog SHARED xlog/xlog.cpp)

set(BUILD_SHARED_LIBS OFF) #静态库
#cmake传递变量给c++
add_definitions(-Dxlog_STATIC) #默认值1
add_library(blp_ch02_part14_xlog xlog/xlog.cpp)

# add_library(xlog_d SHARED xlog/xlog.cpp)

#执行文件
add_executable(blp_ch02_part14_test_xlog test_xlog/test_xlog.cpp)

#链接库
target_link_libraries(blp_ch02_part14_test_xlog blp_ch02_part14_xlog)