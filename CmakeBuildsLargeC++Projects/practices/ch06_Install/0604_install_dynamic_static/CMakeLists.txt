if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.22)
endif ()
project(blp_0604)

####################################################
### 静态库 导出 .lib .a

# 公开头文件
file(WRITE include/slib.h "void SLib();")

# 私有头文件
file(WRITE include/slib_pri.h "#define PRI")

file(WRITE slib.cpp "void SLib(){}")
add_library(${PROJECT_NAME}_slib STATIC slib.cpp include/slib.h include/slib_pri.h)

set_target_properties(${PROJECT_NAME}_slib PROPERTIES PUBLIC_HEADER include/slib.h)
set_target_properties(${PROJECT_NAME}_slib PROPERTIES PRIVATE_HEADER include/slib_pri.h)
#############################################################
# 动态库 需要dllexport导出，不然Windows不生产.lib文件
# Windows .lib .dll
# linux .so
# mac .dylib

file(WRITE include/dlib.h [=[
#ifdef _WIN32
    __declspec(dllexport)
#endif
void DLib();
]=])

file(WRITE dlib.cpp [=[
#include "dlib.h"
void DLib(){}
]=])

add_library(${PROJECT_NAME}_dlib SHARED dlib.cpp include/dlib.h)
target_include_directories(${PROJECT_NAME}_dlib PUBLIC include)
#################################################################
## 执行程序 引用动态库和静态库
file(WRITE main.cpp [=[
#include "dlib.h"
#include "slib.h"
int main()
{
    DLib();
    SLib();
    return 0;
}
]=])

add_executable(${PROJECT_NAME}_main main.cpp)
target_link_libraries(${PROJECT_NAME}_main ${PROJECT_NAME}_dlib)
target_link_libraries(${PROJECT_NAME}_main ${PROJECT_NAME}_slib)
target_include_directories(${PROJECT_NAME}_main PUBLIC include)

######################################################################
### 安装目标 DESTINATION 指定相对 CMAKE_INSTALL_PREFIX 的输出路径
## 默认安装路径
#       Linux /usr/local
#       Windows C:\Program Files (x86)
# Linux
#   cmake -S . -B build -DCMAKE_INSTALL_PREFIX=./out
# Windows
#   cmake -S . -B build -DCMAKE_INSTALL_PREFIX=win_out
#   cmake --build build
#   cmake --install build --config Debug
#   或者
#   cmake --build build --config Debug
#   cmake --install build

# Windows安装命令： Remove-Item -Path "build" -Recurse -Force; Remove-Item -Path "out" -Recurse -Force; cmake -S . -B build -DCMAKE_INSTALL_PREFIX=out; cmake --build build; cmake --install build --config Debug
# Linux  安装命令： rm -rf build/ out/ && cmake -S . -B build -DCMAKE_INSTALL_PREFIX=./out && cmake --build build/ && cmake --install build
install(TARGETS ${PROJECT_NAME}_main ${PROJECT_NAME}_dlib ${PROJECT_NAME}_slib DESTINATION bin)

#[=[
目标分类输出
    RUNTIME
        有 add_executable 创建执行程序
        Windows动态链接库dll文件
    ARCHIVE
        Windows动态库导出符号 .lib
        静态库
            add_library添加 STATIC 参数
            Windows是 .lib，Unix、Linux和MinGW是.a
    LIBRARY
        动态库
            add_library添加 SHARED 参数
                Linux、Unix
                    .so
                mac
                    .dylib
    PUBLIC_HEADER、PRIVATE_HEADER
]=]

install(TARGETS ${PROJECT_NAME}_main RUNTIME DESTINATION test_install/bin) # 执行程序和dll文件输出

install(TARGETS ${PROJECT_NAME}_dlib ${PROJECT_NAME}_slib
        RUNTIME DESTINATION test_install/bin # 执行程序和dll文件输出
        ARCHIVE DESTINATION test_install/lib # 静态库和Windows动态库导出符号 .lib
        LIBRARY DESTINATION test_install/lib # linux和mac的动态库 .so .dylib

        # 头文件的安装
        PUBLIC_HEADER   DESTINATION test_install/include
        PRIVATE_HEADER  DESTINATION test_install/inc
        )































