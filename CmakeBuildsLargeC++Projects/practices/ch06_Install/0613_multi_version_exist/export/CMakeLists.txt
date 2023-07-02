if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.22)
endif ()
project(blp_0613_expirt)

# rm -rf build/ out/ && cmake -S . -B build -DCMAKE_INSTALL_PREFIX=out -Dversion=1.1 &&  cmake --build build && cmake --install build
if (NOT version)
    set(version 1.0)
endif ()

# cmake -S . -B build -DMAKE_INSTALL_PREFIX=/home/xcj/xcpp
file(WRITE include/slib.h "void SLib();")
file(WRITE slib.cpp.in [=[
#include <iostream>
#include "slib.h"
void SLib()
{
    std::cout << "${version} In SLib function!\n";
}
]=])

# 替换文件中的变量
configure_file(slib.cpp.in ${CMAKE_CURRENT_SOURCE_DIR}/slib.cpp)
add_library(slib STATIC slib.cpp)

# 需要导出头文件
set_target_properties(slib PROPERTIES PUBLIC_HEADER include/slib.h)

#[=[
Target "slib" INTERFACE_INCLUDE_DIRECTORIES property contains path:
        "/home/xcj/code/src/506export_my_package/include"
    which is prefixed in the source directory.
]=]
#target_include_directories(slib PUBLIC include)
# 路径被两次引用，1 编译slib库时 2 install export写入config时
target_include_directories(slib PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> # install时为空，只有编译时有值
        $<INSTALL_INTERFACE:${version}/include> # 只有install有值
        )

# -- Installing： /home/xcj/libslib.a
install(TARGETS slib
        EXPORT slib
        RUNTIME DESTINATION ${version}/bin
        LIBRARY DESTINATION ${version}/lib
        ARCHIVE DESTINATION ${version}/lib
        PUBLIC_HEADER DESTINATION ${version}/include
        )

# <PackageName>Config.cmake
# slibConfig.cmake  写入库路径 头文件路径
# /home/xcj/xcpp/lib/config
install(EXPORT slib FILE slibConfig.cmake DESTINATION config/slib-${version}/)


# 写入版本信息 slibConfigVersion.cmake
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        ${CMAKE_INSTALL_PREFIX}/config/slib-${version}/slibConfigVersion.cmake
        VERSION ${version}
        COMPATIBILITY SameMajorVersion # 版本兼容问题
)


