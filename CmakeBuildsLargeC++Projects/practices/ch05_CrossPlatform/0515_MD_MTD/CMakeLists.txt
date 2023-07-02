if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.22)
endif ()

project(blp_ch05_part15_MD_MTD)

file(WRITE slib.cpp [=[
#include <iostream>
void SLib()
{
    std::cout << "SLib \n";
}
]=])

add_library(${PROJECT_NAME}_slib STATIC slib.cpp)

#静态库使用MT（静态导入运行时库）MultiThreaded
# 运行时库，希望debug版本与release不同
# MultiThreadedDebug
# MultiThreadedDebugDLL
set_target_properties(${PROJECT_NAME}_slib PROPERTIES
#        MSVC_RUNTIME_LIBRARY "MultiThreaded" # 也可以使用-MT，但使用-MT会影响跨平台的问题
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>" # 也可以使用-MT，但使用-MT会影响跨平台的问题
        )

file(WRITE main.cpp [=[
#include <iostream>
int main()
{
    std::cout << "in main \n";
    void SLib();
    SLib();
    return 0;
}
]=])

# 默认运行时库是-MD MultiThreadedDLL
add_executable(${PROJECT_NAME}_main main.cpp)
set_target_properties(${PROJECT_NAME}_main PROPERTIES
#        MSVC_RUNTIME_LIBRARY "MultiThreaded" # 也可以使用-MT，但使用-MT会影响跨平台的问题
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
        )
target_link_libraries(${PROJECT_NAME}_main ${PROJECT_NAME}_slib)

#[=[

MultiThreaded   Compile with -MT or equivalent flag(s) to use a multi-theaded statically-linked runtime library

MultiThreadedDLL   Compile with -MD or equivalent flag(s) to use a multi-theaded statically-linked runtime library

MultiThreadedDebug   Compile with -MTd or equivalent flag(s) to use a multi-theaded statically-linked runtime library

MultiThreadedDebugDLL   Compile with -MDd or equivalent flag(s) to use a multi-theaded statically-linked runtime library
]=]


















