if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.25)
endif ()

project(blp_0507)

# a.cpp b.cpp => a.cpp.o b.cpp.o
# a.cpp.o b.cpp.o => libtesta.so
# main.cpp libtesta.so => main
file(WRITE a.cpp [=[
#include <iostream>
void A(){ std::cout << "A\n"; }
]=])

file(WRITE b.cpp [=[
#include <iostream>
void B(){ std::cout << "B\n"; }
]=])

file(WRITE main.cpp [=[
#include <iostream>
void A();
void B();
int main()
{
    A();
    B();
    std::cout << "main\n";
}
]=])

# 添加object对象 testa_obj => a.cpp.o b.cpp.o
add_library(${PROJECT_NAME}_testa_obj OBJECT a.cpp b.cpp)

# -fPIC在 Windows VS 有警告
#if (NOT MSVC)
#    target_compile_options(${PROJECT_NAME}_testa_obj PRIVATE "-fPIC")
#endif ()

# -fPIC在 Windows VS 没有警告，是否添加-fPIC POSITION_INDEPENDENT_CODE ON添加
set_target_properties(${PROJECT_NAME}_testa_obj PROPERTIES POSITION_INDEPENDENT_CODE ON)

# obj => so
# 生成器表达式获取object对象
# $<TARGET_OBJECT:${PROJECT_NAME}_testa_obj> => a.cpp.o b.cpp.o
add_library(${PROJECT_NAME}_testa SHARED $<TARGET_OBJECTS:${PROJECT_NAME}_testa_obj>)

# 测试的执行程序
add_executable(${PROJECT_NAME}_main main.cpp)
# 执行程序依赖的库
target_link_libraries(${PROJECT_NAME}_main ${PROJECT_NAME}_testa)

















