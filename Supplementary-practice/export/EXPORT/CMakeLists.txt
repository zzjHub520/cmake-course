cmake_minimum_required(VERSION 3.22)
project(EXPORT)

add_library(add Add.cpp)
target_include_directories(add PUBLIC .)

export(TARGETS add FILE AddConfig.cmake)
