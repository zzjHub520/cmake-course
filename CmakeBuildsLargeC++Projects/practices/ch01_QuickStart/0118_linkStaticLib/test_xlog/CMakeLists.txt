if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.25)
endif ()
project(blp_ch01_part18_test_xlog)
#指定头文件查找路径
include_directories(${blp_ch01_part18_xlog_SOURCE_DIR})

# 指定库查找路径  window自动找 ../xlog/build/Debug  ../xlog/build/Release
link_directories(${blp_ch01_part18_xlog_BINARY_DIR})

add_executable(${PROJECT_NAME} test_xlog.cpp)

# 指定加载的库
target_link_libraries(${PROJECT_NAME} blp_ch01_part18_xlog)