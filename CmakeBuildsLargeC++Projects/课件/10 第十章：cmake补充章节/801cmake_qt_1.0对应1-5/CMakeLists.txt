cmake_minimum_required(VERSION 3.20)
project(qt_cmake)

# 自动把ui转换为c++代码
# uic qtcmake.ui > ui_qtcmake.h
set(CMAKE_AUTOUIC ON)

# 自动生成资源文件代码 rcc > .h
set(CMAKE_AUTORCC ON) 

# 自动生成信号槽代码
set(CMAKE_AUTOMOC ON)


# 编译执行程序
add_executable(${PROJECT_NAME} 
main.cpp 
qtcmake.ui
qtcmake.cpp
qtcmake.h
qtcmake.qrc
)


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
