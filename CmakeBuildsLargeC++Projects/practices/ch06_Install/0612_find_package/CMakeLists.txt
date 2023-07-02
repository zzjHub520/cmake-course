if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.22)
endif ()
project(blp_0612)

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
# rm -rf build/  && cmake -S . -B build -DCMAKE_PREFIX_PATH=../0611_install_export_package/out/config/ && cmake --build build/ &&  ./build/blp_0612_main
find_package(Demo)
message("Demo_FOUND =${Demo_FOUND}")
if (Demo_FOUND)
    message("find blp_0611_slib success!")
endif ()
add_executable(${PROJECT_NAME}_main main.cpp)
target_link_libraries(${PROJECT_NAME}_main Demo::blp_0611_slib)

# 头文件路径写在属性中
get_target_property(var Demo::blp_0611_slib INTERFACE_INCLUDE_DIRECTORIES)
message("INTERFACE_INCLUDE_DIRECTORIES = ${var}")
target_compile_definitions()