if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.22)
endif ()

project(blp_0602)

####################################################
### 静态库 导出 .lib .a

# 公开头文件
file(WRITE include/slib.h "void SLib();")

# 私有头文件
file(WRITE include/slib_pri.h "#define PRI")

file(WRITE slib.cpp "void SLib(){}")
add_library(${PROJECT_NAME}_slib STATIC slib.cpp include/slib.h include/slib_pri.h)

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
