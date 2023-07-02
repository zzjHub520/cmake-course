if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.22)
endif ()
project(blp_0805)


file(WRITE ${PROJECT_NAME}.cpp [=[
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

set(GTEST_PATH ${CMAKE_CURRENT_SOURCE_DIR}/gtest)
# 如果GTest 没有安装
if (NOT EXISTS ${GTEST_PATH})
    #1 解压文件 googletest-release-1.11.0.tar.gz
    # cmake -E 执行shell命令
    message("tar xf googletest-release-1.11.0.tar.gz")
    execute_process(
            COMMAND ${CMAKE_COMMAND} -E tar xf ${CMAKE_CURRENT_SOURCE_DIR}/googletest-release-1.11.0.tar.gz
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )

    #2 cmale 配置 cmake -S . -B build
    message("${CMAKE_COMMAND} -S ${GTEST_SOURCE} -B ${GTEST_SOURCE}/build")
    set(GTEST_SOURCE ${CMAKE_CURRENT_BINARY_DIR}/googletest-release-1.11.0)
    execute_process(
            COMMAND ${CMAKE_COMMAND} -S ${GTEST_SOURCE} -B ${GTEST_SOURCE}/build)

    #3 编译gtest  cmake --build build
    message("${CMAKE_COMMAND} --build ${GTEST_SOURCE}/build")
    execute_process(COMMAND ${CMAKE_COMMAND} --build ${GTEST_SOURCE}/build)

    #4 安装gtest cmake --install build --prefix
    execute_process(COMMAND ${CMAKE_COMMAND} --install ${GTEST_SOURCE}/build --prefix=${GTEST_PATH})
endif ()

add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp)
# 查找gtest库
# 设置find_package查找路径
set(CMAKE_PREFIX_PATH ${GTEST_PATH}/lib/cmake)
#set(GTest ${GTEST_PATH})
find_package(GTest)
message("GTest = ${GTest_FOUND}")
target_link_libraries(${PROJECT_NAME} GTest::gtest_main)

# 联合ctest和gtest
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

# 打开才能运行ctest
enable_testing()
