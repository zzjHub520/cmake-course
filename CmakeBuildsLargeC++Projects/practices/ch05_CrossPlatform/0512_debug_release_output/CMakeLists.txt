if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.22)
endif ()

project(blp_0512)

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
void SLib(){}
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

# 输出路径
set(OUT_LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(OUT_EXE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin) # 执行程序和dll

set_target_properties(${PROJECT_NAME}_slib PROPERTIES
        # 静态库和lib文件的输出
        ARCHIVE_OUTPUT_DIRECTORY ${OUT_LIB_PATH}
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${OUT_LIB_PATH}/debug
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${OUT_LIB_PATH}/release
#        ARCHIVE_OUTPUT_DIRECTORY_RELWITHDEBINFO ${OUT_LIB_PATH}/RelWithDebInfo
#        ARCHIVE_OUTPUT_DIRECTORY_MINSIZEREL ${OUT_LIB_PATH}/MinSizeRel
        )

################################################################################
# 动态库
file(WRITE include/dlib.h "
#ifndef _WIN32 //linux mac unix Android
    #define XCPP_API
#else //windows
    //动态库
    #ifdef ${PROJECT_NAME}_dlib_EXPORTS
        #define XCPP_API __declspec(dllexport) //库项目调用
    #else
        #define XCPP_API __declspec(dllimport) //调用库项目调用
    #endif
#endif

XCPP_API void DLib();")

file(WRITE src/dlib.cpp [=[
#include "dlib.h"
void DLib(){}
]=])

add_library(${PROJECT_NAME}_dlib SHARED src/dlib.cpp include/dlib.h)

target_include_directories(${PROJECT_NAME}_dlib PUBLIC include)

set_target_properties(${PROJECT_NAME}_dlib PROPERTIES
        # windows lib文件的输出
        ARCHIVE_OUTPUT_DIRECTORY ${OUT_LIB_PATH}
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${OUT_LIB_PATH}/debug
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${OUT_LIB_PATH}/release

        # Windows dll文件输出路径
        RUNTIME_OUTPUT_DIRECTORY ${OUT_EXE_PATH}
        RUNTIME_OUTPUT_DIRECTORY_DEBUG ${OUT_EXE_PATH}/debug
        RUNTIME_OUTPUT_DIRECTORY_RELEASE ${OUT_EXE_PATH}/release

        # Linux .so 和mac
        LIBRARY_OUTPUT_DIRECTORY ${OUT_LIB_PATH}
        LIBRARY_OUTPUT_DIRECTORY_DEBUG ${OUT_LIB_PATH}/debug
        LIBRARY_OUTPUT_DIRECTORY_RELEASE ${OUT_LIB_PATH}/release
        )

################################################################################
# 执行程序
file(WRITE src/main.cpp [=[
#include "dlib.h"
void SLib();
int main()
{
    DLib();
    SLib();
    return 0;
}
]=])

add_executable(${PROJECT_NAME}_main src/main.cpp)
target_link_libraries(${PROJECT_NAME}_main ${PROJECT_NAME}_slib ${PROJECT_NAME}_dlib)

set_target_properties(${PROJECT_NAME}_main PROPERTIES
        # Windows linux执行文件输出路径
        RUNTIME_OUTPUT_DIRECTORY ${OUT_EXE_PATH}
        RUNTIME_OUTPUT_DIRECTORY_DEBUG ${OUT_EXE_PATH}/debug
        RUNTIME_OUTPUT_DIRECTORY_RELEASE ${OUT_EXE_PATH}/release
        )










