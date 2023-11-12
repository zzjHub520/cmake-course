cmake_minimum_required(VERSION 3.22)
project(PACKAGE)

set(CMAKE_PREFIX_PATH "../EXPORT/cmake-build-debug")

find_package(add)

message("${add_FOUND}")

add_executable(main main.cpp)
target_link_libraries(main PUBLIC add)

