if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.22)
endif ()
project(blp_0613_find)

# rm -rf build/ out/ && cmake -S . -B build -DCMAKE_PREFIX_PATH=../export/out/config/ &&  cmake --build build && ./build/blp_0613_find_main
# rm -rf build/ out/ && cmake -S . -B build -DCMAKE_PREFIX_PATH=../export/out/config/ -Dversion=1.3 &&  cmake --build build && ./build/blp_0613_find_main
file(WRITE main.cpp [=[
#include "slib.h"
#include <iostream>
using namespace std;
int main()
{
    cout << "In Main" << endl;
    SLib();
    return 0;
}
]=])
# rm -rf build/ out/ && cmake -S . -B build -DCMAKE_PREFIX_PATH=../0611_install_export_package/out/config/
if (NOT version)
    set(version 1.0)
endif ()
message("find_package ${version}")

# rm -rf build/ out/ && cmake -S . -B build -DCMAKE_PREFIX_PATH=../export/out/config/ -Dversion=1.2
find_package(slib ${version})
message("slib_FOUND =${slib_FOUND}")
if (slib_FOUND)
    message("find slib success!")
endif ()
add_executable(${PROJECT_NAME}_main main.cpp)
target_link_libraries(${PROJECT_NAME}_main slib)

# 头文件路径写在属性中
get_target_property(var slib INTERFACE_INCLUDE_DIRECTORIES)
message("INTERFACE_INCLUDE_DIRECTORIES = ${var}")