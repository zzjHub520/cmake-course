if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.25)
endif ()

project(blp_0503)

# WRITE 写文件 清空原数据 如果文件不存在则创建
file(WRITE a.cpp [=[
void A(){}
]=])

add_library(${PROJECT_NAME} STATIC a.cpp)

#[[
target_include_directories(<target> [SYSTEM] [AFTER|BEFORE]
  <INTERFACE|PUBLIC|PRIVATE> [items1...]
  [<INTERFACE|PUBLIC|PRIVATE> [items2...] ...])
]]
# PUBLIC 改变INCLUDE_DIRECTORIES INTERFACE_INCLUDE_DIRECTORIES
# INCLUDE_DIRECTORIES 当前目标使用的属性
# INTERFACE_INCLUDE_DIRECTORIES 依赖当前目标所使用的属性
target_include_directories(${PROJECT_NAME} PUBLIC "/A_PUBLIC")
# INCLUDE_DIRECTORIES 当前目标使用的属性
target_include_directories(${PROJECT_NAME} PRIVATE "/A_PRIVATE")
# INTERFACE_INCLUDE_DIRECTORIES 依赖当前目标所使用的属性
target_include_directories(${PROJECT_NAME} INTERFACE "/A_INTERFACE")

#打印属性
include(CMakePrintHelpers)
cmake_print_properties(TARGETS ${PROJECT_NAME} PROPERTIES
        INCLUDE_DIRECTORIES
        INTERFACE_INCLUDE_DIRECTORIES
        )



















