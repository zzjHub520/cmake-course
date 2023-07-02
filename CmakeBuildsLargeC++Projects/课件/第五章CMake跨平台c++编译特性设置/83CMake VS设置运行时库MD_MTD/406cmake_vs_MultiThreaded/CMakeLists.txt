#406cmake_vs_MultiThreaded/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project(test_vs)
file(WRITE slib.cpp [=[
#include <iostream>
void SLib()
{
    std::cout<<"SLib";
}
]=])

add_library(slib STATIC slib.cpp)

#静态库使用MT（静态导入运行时库）  MultiThreaded
# 运行时库，希望debug版本与release不同
# MultiThreadedDebug
# MultiThreadedDebugDLL

set_target_properties(slib PROPERTIES
#MSVC_RUNTIME_LIBRARY "MultiThreaded"
MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>" # debug版本时生成为 MultiThreadedDebug
)

file(WRITE main.cpp [=[
#include <iostream>
int main()
{
    std::cout<<"in main";
    void SLib();
    SLib();
    return 0;
}
]=])

# 默认运行时库时MD  MultiThreadedDLL
add_executable(main main.cpp)
set_target_properties(main PROPERTIES
#MSVC_RUNTIME_LIBRARY "MultiThreaded"
MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
)
target_link_libraries(main slib)
#[[
MultiThreaded
	Compile with -MT or equivalent flag(s) to use a multi-threaded statically-linked runtime library.
MultiThreadedDLL
	 Compile with -MD or equivalent flag(s) to use a multi-threaded dynamically-linked runtime library.
MultiThreadedDebug
	  Compile with -MTd or equivalent flag(s) to use a multi-threaded statically-linked runtime library.
MultiThreadedDebugDLL
	    Compile with -MDd or equivalent flag(s) to use a multi-threaded dynamically-linked runtime library.
]]