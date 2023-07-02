if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.25)
endif ()
project(blp_ch03_part17_property_print)
# cmake 传递变量给C++
# CMakeRelated 预设属性 COMPILE_DEFINITONS 传递预设变量（宏变量） -DPARA1 1234
set_property(SOURCE main.cpp PROPERTY COMPILE_DEFINITIONS "PARA1=1234")

add_executable(${PROJECT_NAME} main.cpp)

# cmake 目标属性 目标必须已经存在
set_property(TARGET ${PROJECT_NAME} PROPERTY TVAR "tval")
get_property(var TARGET ${PROJECT_NAME} PROPERTY TVAR)
message("TVAR = ${var}")

# 给C++传递宏
set_property(TARGET ${PROJECT_NAME} PROPERTY COMPILE_DEFINITIONS "PARA2=\"test_asdf\"")
set_property(TARGET ${PROJECT_NAME} APPEND_STRING PROPERTY COMPILE_DEFINITIONS "PARA3=\"test_qwer\"")

# 打印目标属性
include(CMakePrintHelpers)
cmake_print_properties(TARGETS ${PROJECT_NAME} PROPERTIES COMPILE_DEFINITIONS TVAR)





























