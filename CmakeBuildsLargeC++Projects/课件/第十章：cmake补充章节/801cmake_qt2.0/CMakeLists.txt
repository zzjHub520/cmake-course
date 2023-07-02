cmake_minimum_required(VERSION 3.20)
project(qt_cmake VERSION 2.0)
#[[ 编译方法
64位编译
rd /S/Q x64
cmake -S . -B x64 -A x64 -DQT5=J:/Qt/Qt5.14.2/5.14.2/msvc2017_64 -DCMAKE_INSTALL_PREFIX=out 
cmake --build x64 --config Release
cmake --install x64 --config Release

32位编译
rd /S/Q Win32
cmake -S . -B Win32 -A Win32 -DQT5=J:/Qt/Qt5.14.2/5.14.2/msvc2017 -DCMAKE_INSTALL_PREFIX=out 
cmake --build Win32 --config Release
cmake --install Win32 --config Release
]]

# 自动把ui转换为c++代码
# uic qtcmake.ui > ui_qtcmake.h
set(CMAKE_AUTOUIC ON)

# 自动生成资源文件代码 rcc > .h
set(CMAKE_AUTORCC ON) 

# 自动生成信号槽代码
set(CMAKE_AUTOMOC ON)

# 自动加载所有源码、头文件、资源文件qrc、界面文件ui
file(GLOB SOURCE "*.cpp" "*.c"  "*.cc")
file(GLOB HEAD "*.h" "*.hpp")
file(GLOB QT "*.qrc" "*.ui")

# 32位和64位程序区分
#[[
指定vs编译器位32位 QT SDK也要对应的32位
cmake -S . -B build -A Win32 -DQt5_DIR=J:/Qt/Qt5.14.2/5.14.2/msvc2017/lib/cmake/Qt5
cmake -S . -B build -A x64 -DQt5_DIR=J:/Qt/Qt5.14.2/5.14.2/msvc2017_64/lib/cmake/Qt5
${CMAKE_GENERATOR_PLATFORM}
${CMAKE_VS_PLATFORM_NAME}"

CMAKE_GENERATOR_PLATFORM 只有在指定了 -A 才有用 默认为空
不指定-A时
CMAKE_GENERATOR_PLATFORM =
CMAKE_VS_PLATFORM_NAME = x64
指定后 -A x64
CMAKE_GENERATOR_PLATFORM = x64
CMAKE_VS_PLATFORM_NAME = x64
]]
message("CMAKE_GENERATOR_PLATFORM = ${CMAKE_GENERATOR_PLATFORM}")
message("CMAKE_VS_PLATFORM_NAME = ${CMAKE_VS_PLATFORM_NAME}")

# 编译执行程序
add_executable(${PROJECT_NAME}
${SOURCE}
${HEAD}
${QT}
)

# 传递 QT5 变量，自动生成
# 复制依赖的qt库文件 Qt5_DIR
# cmake -S . -B x64 -A x64 -DQT5=J:/Qt/Qt5.14.2/5.14.2/msvc2017_64 -DCMAKE_INSTALL_PREFIX=out 

set(Qt5_DIR ${QT5}/lib/cmake/Qt5)

# 获取执行程序依赖的QT库文件 
set(windeployqt "${QT5}/bin/windeployqt")

# 导入QT的库
find_package(Qt5 COMPONENTS Widgets REQUIRED)

#set(Qt5_DIR J:/Qt/Qt5.14.2/5.14.2/msvc2017_64/lib/cmake/Qt5)
# 指定qt依赖库和头文件路径
# Qt5_DIR
# Qt5Config.cmake
# J:\Qt\Qt5.14.2\5.14.2\msvc2017_64\lib\cmake\Qt5

# cmake -S . -B build -DQt5_DIR=J:/Qt/Qt5.14.2/5.14.2/msvc2017_64/lib/cmake/Qt5
target_link_libraries(${PROJECT_NAME}
Qt5::Widgets 
)

# J:/Qt/Qt5.14.2/5.14.2/msvc2017_64/bin/windeployqt build\Debug\qt_cmake.exe 
# J:/Qt/Qt5.14.2/5.14.2/msvc2017_64/bin/windeployqt
# 自动复制依赖的动态库 windeployqt.exe


# install 依赖的qt库和执行文件
# 指定安装路径 CMAKE_INSTALL_PREFIX
#[[
cmake -S . -B x64 -A x64 -DCMAKE_INSTALL_PREFIX=out -DQt5_DIR=J:/Qt/Qt5.14.2/5.14.2/msvc2017_64/lib/cmake/Qt5
cmake --build x64 --config Release
cmake --install x64 
]]
# out/x64  out/Win32
set(INSTALL_PATH 
${CMAKE_INSTALL_PREFIX}/${CMAKE_VS_PLATFORM_NAME})


#设置Debug和Release输出路径一致（windows）
set(RUMTIME ${CMAKE_BINARY_DIR}/bin)
set_target_properties(${PROJECT_NAME} 
PROPERTIES
RUNTIME_OUTPUT_DIRECTORY ${RUMTIME}
RUNTIME_OUTPUT_DIRECTORY_DEBUG ${RUMTIME}
RUNTIME_OUTPUT_DIRECTORY_RELEASE ${RUMTIME}
)

#[[
install(TARGETS ${PROJECT_NAME} 
CONFIGURATIONS Debug Release
RUNTIME DESTINATION ${INSTALL_PATH}
)
]]

# $<TARGET_FILE:${PROJECT_NAME}> 获取输出文件的全路径
# $<TARGET_FILE_DIR:${PROJECT_NAME}>  获取输出文件所在目录全路径

# J:/Qt/Qt5.14.2/5.14.2/msvc2017_64/bin/windeployqt build\Debug\qt_cmake.exe 
# cmake -S . -B x64 -A x64 -DCMAKE_INSTALL_PREFIX=out -DQT5=J:/Qt/Qt5.14.2/5.14.2/msvc2017_64
# 1 windeployqt直接复制qt库文件到输出路径

# 执行windeployqt 复制依赖的qt库到输出文件目录下
install( CODE "
execute_process(COMMAND 
${windeployqt} $<TARGET_FILE:${PROJECT_NAME}>
WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
"
)

# 复制输出的执行程序和依赖的qt库到安装路径
install(DIRECTORY 
$<TARGET_FILE_DIR:${PROJECT_NAME}>
DESTINATION
${INSTALL_PATH}
)
