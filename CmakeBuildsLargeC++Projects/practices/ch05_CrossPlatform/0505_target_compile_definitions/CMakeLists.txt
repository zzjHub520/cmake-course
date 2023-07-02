if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.25)
endif ()

project(blp_0505)

# WRITE 写文件 清空原数据 如果文件不存在则创建
file(WRITE a.cpp [=[
#include <iostream>
void A()
{
    std::cout << "In A " << A_VAR << std::endl;
}
]=])

add_library(${PROJECT_NAME}_A STATIC a.cpp)

#[[
target_include_directories(<target> [SYSTEM] [AFTER|BEFORE]
  <INTERFACE|PUBLIC|PRIVATE> [items1...]
  [<INTERFACE|PUBLIC|PRIVATE> [items2...] ...])
]]
# PUBLIC 改变INCLUDE_DIRECTORIES INTERFACE_INCLUDE_DIRECTORIES
# INCLUDE_DIRECTORIES 当前目标使用的属性
# INTERFACE_INCLUDE_DIRECTORIES 依赖当前目标所使用的属性
target_include_directories(${PROJECT_NAME}_A PUBLIC "/A_PUBLIC")
# INCLUDE_DIRECTORIES 当前目标使用的属性
target_include_directories(${PROJECT_NAME}_A PRIVATE "/A_PRIVATE")
# INTERFACE_INCLUDE_DIRECTORIES 依赖当前目标所使用的属性
target_include_directories(${PROJECT_NAME}_A INTERFACE "/A_INTERFACE")

# 设定A库的宏
target_compile_definitions(${PROJECT_NAME}_A PUBLIC A_VAR=123)

#打印属性
include(CMakePrintHelpers)
cmake_print_properties(TARGETS ${PROJECT_NAME}_A PROPERTIES
        INCLUDE_DIRECTORIES
        INTERFACE_INCLUDE_DIRECTORIES
        )

# B -> A
file(WRITE b.cpp [=[
#include <iostream>
void A();
void B(){
    A();
    std::cout << "In B " << A_VAR << std::endl;
};
]=])

add_library(${PROJECT_NAME}_B STATIC b.cpp)
target_link_libraries(${PROJECT_NAME}_B PUBLIC ${PROJECT_NAME}_A)
target_include_directories(${PROJECT_NAME}_B PUBLIC "/B_PUBLIC")

# 设定B库的宏 STATIC 标志 B库编译时不需要，依赖B库的需要
target_compile_definitions(${PROJECT_NAME}_B INTERFACE STATIC=1)

# 不能打印继承的属性
include(CMakePrintHelpers)
cmake_print_properties(TARGETS ${PROJECT_NAME}_B PROPERTIES
        INCLUDE_DIRECTORIES
        INTERFACE_INCLUDE_DIRECTORIES
        )

# cmake 原生属性调试接口
set(CMAKE_DEBUG_TARGET_PROPERTIES
        INCLUDE_DIRECTORIES
        INTERFACE_INCLUDE_DIRECTORIES
        )

file(WRITE main.cpp [=[
#include <iostream>
int main() {
    void B();
    B();
    std::cout << "In main " << STATIC << std::endl;
    return 0;
}
]=])

# main -> B -> A
add_executable(${PROJECT_NAME}_main main.cpp)
target_link_libraries(${PROJECT_NAME}_main PUBLIC ${PROJECT_NAME}_B)


