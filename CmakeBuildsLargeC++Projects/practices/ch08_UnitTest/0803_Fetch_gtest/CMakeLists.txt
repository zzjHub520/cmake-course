if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.22)
endif ()
project(blp_0803)

# 使用 FetchContent 下载安装 googletest
include(FetchContent)

# 下载代码 git SVN http
# git 下载 gtest
#FetchContent_Declare(
#        googletest
#        GIT_REPOSITORY https://github.com/google/googletest.git
#        GIT_TAG release-1.12.1
#)

# http 下载 gtest
FetchContent_Declare(
        googletest
        URL http://cdn.tarsyun.com/src/release-1.11.0.tar.gz
)

# 编译安装 gtest
FetchContent_MakeAvailable(googletest)

#[[
# 第一步配置时会下载googletest
cmake -S . -B build
cmake --build build
cmake --install build --prefix=./
]]

