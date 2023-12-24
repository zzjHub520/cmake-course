cmake_minimum_required(VERSION 3.22)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

# 添加覆盖率编译参数
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

add_executable(untitled main.cpp)

add_subdirectory(test)


