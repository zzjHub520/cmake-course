if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.22)
endif ()
project(blp_0804)

file(WRITE gtest_fetch.cpp [=[
#include <gtest/gtest.h>
TEST(MyTest, MyTestDownload)
{
    EXPECT_EQ(7*6, 42);
}
TEST(MyTest, MyTestUpload)
{
    EXPECT_EQ(7*6, 41);
}

int main(int argc, char *argv[])
{
    //初始化gtest
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
]=])

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

add_executable(gtest_fetch gtest_fetch.cpp)
target_link_libraries(
        gtest_fetch
        GTest::gtest_main
)

# 联合ctest和gtest
include(GoogleTest)
gtest_discover_tests(gtest_fetch)

# 打开才能运行ctest
enable_testing()
#[[
# 第一步配置时会下载googletest
cmake -S . -B build
cmake --build build
cmake --install build --prefix=./
]]

