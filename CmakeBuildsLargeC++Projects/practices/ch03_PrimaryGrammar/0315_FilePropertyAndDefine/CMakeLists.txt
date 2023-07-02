if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.25)
endif ()
project(blp_ch03_part15_FilePropertyAndDefine)

add_subdirectory(sub1)

#目录属性
set_property(DIRECTORY . PROPERTY DIR1 "dir001")
get_property(var DIRECTORY . PROPERTY DIR1)
message("DIR1 = ${var}")
# 拿到子目录sub1的属性
get_property(var DIRECTORY . PROPERTY DIR1)
message("sub1 DIR1 = ${var}")

# 文件属性
set_property(SOURCE main.cpp PROPERTY S1 "s1 value")
get_property(var SOURCE main.cpp PROPERTY S1)
message("SOURCE S1 = ${var}")

# cmake 传递变量给C++
# CMakeRelated 预设属性 COMPILE_DEFINITONS 传递预设变量（宏变量） -DPARA1 1234
set_property(SOURCE main.cpp PROPERTY COMPILE_DEFINITIONS "PARA1=1234")

add_executable(${PROJECT_NAME} main.cpp)



















