# 501cmake_install/CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
project(cmake_install)

#############################################
### 1 静态库 导出 .lib .a 

# 公开头文件
file(WRITE include/slib.h "void SLib();")

# 私有头文件
file(WRITE include/slib_pri.h "#define PRI")

file(WRITE slib.cpp "void SLib(){}")
add_library(slib STATIC slib.cpp include/slib.h include/slib_pri.h) 

set_target_properties(slib PROPERTIES PUBLIC_HEADER include/slib.h)
set_target_properties(slib PROPERTIES PRIVATE_HEADER include/slib_pri.h)

############################################################ 
# 2 动态库 需要dllexport导出，不然windows不生产.lib文件
# windows .lib .dll
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
add_library(dlib SHARED dlib.cpp include/dlib.h)
target_include_directories(dlib PUBLIC include)

##################################################
# 3 执行程序 引用动态库和静态库
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
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} dlib)
target_link_libraries(${PROJECT_NAME} slib)
target_include_directories(${PROJECT_NAME} PUBLIC include)


##################################################
### 安装目标 DESTINATION指定相对 CMAKE_INSTALL_PREFIX 的输出路径
## 默认安装路径 
#    linux /usr/local  
#    windows    C:/Program Files (x86)/
# Linux
#    cmake -S . -B build -DCMAKE_INSTALL_PREFIX=./out
# Windows 默认安装 Release版本
# cmake -S . -B win -DCMAKE_INSTALL_PREFIX=win_out
# cmake --build win
# cmake --install win --config Debug
# cmake --build win --config Release
# cmake --install win
install(TARGETS slib dlib ${PROJECT_NAME} DESTINATION bin)

#[[
目标分类输出
	RUNTIME
		由add_executable创建执行程序
		windows动态链接库dll文件
	ARCHIVE
		windows动态库库导出符号 .lib
		静态库
			add_library添加STATIC 参数
			windows是 .lib, Unix、Linux和MinGW是.a
	LIBRARY
		动态库
			add_library 使用SHARED 参数 
				linux、unix
					.so
				mac
					dylib
	PUBLIC_HEADER、PRIVATE_HEADER
]]

install(TARGETS ${PROJECT_NAME}
RUNTIME DESTINATION test_install/bin  # 执行程序和dll文件输出
)

install(TARGETS slib dlib
RUNTIME DESTINATION test_install/bin  # 执行程序和dll文件输出
ARCHIVE DESTINATION test_install/lib  # 静态库和windows动态库导出符号 .lib
LIBRARY DESTINATION test_install/lib  # linux和mac的动态库 .so .dylib

#头文件的安装
PUBLIC_HEADER DESTINATION test_install/include #公开头文件
PRIVATE_HEADER DESTINATION test_install/inc    #内部头文件
)

#[[
debug release 不同输出路径
    windows 编译过程
        cmake -S . -B win -DCMAKE_INSTALL_PREFIX=win_out
        cmake --build win --config Debug
        cmake --install win --config Debug
    Linux 编译过程  Debug, Release, RelWithDebInfo and MinSizeRel,
        cmake -S . -B build -DCMAKE_INSTALL_PREFIX=out -DCMAKE_BUILD_TYPE=Debug
        cmake --build build
        cmake --install build --config Debug


        cmake -S . -B build -DCMAKE_INSTALL_PREFIX=out -DCMAKE_BUILD_TYPE=Release
        cmake --build build
        cmake --install build --config Release
]]
install(TARGETS ${PROJECT_NAME}
CONFIGURATIONS Debug
RUNTIME DESTINATION debug/bin
)

install(TARGETS ${PROJECT_NAME}
CONFIGURATIONS Release RelWithDebInfo MinSizeRel
RUNTIME DESTINATION release/bin
)