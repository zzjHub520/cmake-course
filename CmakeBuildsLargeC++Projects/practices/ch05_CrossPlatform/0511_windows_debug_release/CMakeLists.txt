if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.22)
endif ()

project(blp_ch05_part11_windows_debug_release)

# 静态库
# src/
#   slib.cpp
#   dlib.cpp
#   main.cpp
# bin
#   debug
#       main
#       dlib.dll [windows]
#   release
# lib
#   debug
#       slib.lib [windows]
#       dlib.lib [windows]
#       dilb.so
#       slib.a
# release

file(WRITE src/slib.cpp [=[
void SLIB(){}
]=])

#[[
Debug
    -g
Release
    -O3
RelWithDebInfo
    -O2 -g
MinSizeRel
    -O3
1) Linux max 控制方法，VS项目不可用
    CMAKE_BUILD_TYPE
    linux默认为空，既不是Debug也不是release
    set(CMAKE_BUILD_TYPE Debug)

    -O3 -DNDEBUG
    cmake -S . -B build -D CMAKE_BUILD_TYPE=Release

    -O2 -g -DNDEBUG
    cmake -S . -B build -D CMAKE_BUILD_TYPE=RelWithDebInfo

    -Os -DNDEBUG
    cmake -S . -B build -D CMAKE_BUILD_TYPE=MinSizeRel

2) Windows VS nmake
    1.VS在生成阶段无法控制（自动生成4种）
    2.VS在编译阶段可以控制
        cmake --build ./build --config Debug
        cmake --build ./build --config Release
        cmake --build ./build --config RelWithDebInfo
        cmake --build ./build --config MinSizeRel
]]

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif ()

message("CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")

# 生成静态库
add_library(${PROJECT_NAME}_slib STATIC src/slib.cpp)





























