if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.25)
endif ()
project(blp_ch02_part10_AutoLoadSourceFile)

#108auto_src_h/CMakeLists.h
#[[
108auto_src_h
    CMakeLists.txt
    main.cpp
    src
        xlog.cpp
        xthread.cc
        xtest.c
    include
        xlog.h
        xthread.hpp
]]

#头文件加载路径
set(INCLUDE_PATH  "./include")
include_directories(${INCLUDE_PATH})

# 找到当前目录（.）下源码写入M_SRC变量中
aux_source_directory("." M_SRC)
aux_source_directory("./src" SRC)

#读取所有的头文件
file(GLOB H_FILE "${INCLUDE_PATH}/*.h*")

add_executable(${PROJECT_NAME} ${M_SRC} ${SRC} ${H_FILE})




