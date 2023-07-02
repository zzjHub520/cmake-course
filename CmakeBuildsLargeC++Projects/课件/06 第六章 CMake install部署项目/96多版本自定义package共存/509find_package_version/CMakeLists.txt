# 507find_package/CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
project(findpkg)
file(WRITE main.cpp [=[
#include "slib.h"
#include <iostream>
using namespace std;
int main()
{
    cout<<"In Main"<<endl;
    SLib();
    return 0;
}
]=])
# cmake -S . -B build -DCMAKE_PREFIX_PATH=/home/xcj/xcpp/config
if(NOT version)
    set(version 1.0)
endif()
message("find_package ${version}")

# cmake -S . -B build -DCMAKE_PREFIX_PATH=/home/xcj/xcpp/config -Dversion=1.2
find_package(slib ${version})
message("slib_FOUND = ${slib_FOUND}")
if(slib_FOUND)
    message("find slib success!")
endif()
add_executable(main main.cpp)
target_link_libraries(main slib)

# 头文件路径写在属性中
get_target_property(inc slib INTERFACE_INCLUDE_DIRECTORIES)
message("INTERFACE_INCLUDE_DIRECTORIES = ${inc}")


