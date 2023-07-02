#703gtest_tar_build_install/CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
project(gtest_tar_build_install)

file(WRITE ${PROJECT_NAME}.cpp [=[
#include <gtest/gtest.h>
#include <iostream>
using namespace std;
TEST(MyTest,MyTestDownload)
{
    EXPECT_EQ(7*6,42);
}
TEST(MyTest,MyTestUpload)
{
    EXPECT_EQ(7*6,41);
}

class XLogTest :public ::testing::Test
{
protected:
    XLogTest(){cout<<"Create XLogTest"<<endl;}
    ~XLogTest(){cout<<"Drop XLogTest"<<endl;}
    void SetUp() override {cout<<"SetUp XLogTest"<<endl;} //每次测试开始进入
    void TearDown() override {cout<<"TearDown XLogTest"<<endl;} 
};
TEST_F(XLogTest,Init)
{
    ASSERT_TRUE(true);
}
TEST_F(XLogTest,Write)
{
    ASSERT_TRUE(false);
}
int main(int argc,char *argv[])
{
    //初始化gtest
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
]=])

set(GTEST_PATH ${CMAKE_SOURCE_DIR}/gtest)
# 如果GTest没有安装
if(NOT EXISTS ${GTEST_PATH})
    #1 解压文件 gtest-1.11.0.tar.gz  
    # cmake -E 执行shell命令  PROJECT_BINARY_DIR -B build
    message("tar xf gtest-1.11.0.tar.gz")
    execute_process(COMMAND  ${CMAKE_COMMAND}
    -E tar xf ${CMAKE_SOURCE_DIR}/gtest-1.11.0.tar.gz 
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
    )

    #2 cmake配置 cmake -S . -B build
    # googletest-release-1.11.0
    message("${CMAKE_COMMAND} -S ${GTEST_SOURCE} -B ${GTEST_SOURCE}/build")
    set(GTEST_SOURCE ${PROJECT_BINARY_DIR}/googletest-release-1.11.0)
    execute_process(COMMAND  ${CMAKE_COMMAND} -S ${GTEST_SOURCE} 
    -B ${GTEST_SOURCE}/build
    )
    # 3 编程gtest cmake --build build

    message("${CMAKE_COMMAND} --build ${GTEST_SOURCE}/build")
    execute_process(COMMAND  ${CMAKE_COMMAND} --build ${GTEST_SOURCE}/build)


    # 4 安装gtest cmake --install build --prefix
    execute_process(COMMAND  ${CMAKE_COMMAND} --install ${GTEST_SOURCE}/build
    --prefix=${GTEST_PATH} --config Debug
    )
endif()

add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp)

#[[
MultiThreaded
MultiThreadedDLL
MultiThreadedDebug   运行时静态库Debug版本
MultiThreadedDebugDLL  运行时动态库 Debug版本
]]
set_target_properties(${PROJECT_NAME} PROPERTIES
MSVC_RUNTIME_LIBRARY MultiThreadedDebug
)


# 查找gtest库 默认找不到 要找config文件
#设置find_package 查找路径
set(CMAKE_PREFIX_PATH ${GTEST_PATH}/lib/cmake/)
find_package(GTest)
message("GTest = ${GTest_FOUND}")
target_link_libraries(${PROJECT_NAME}
GTest::gtest_main
)

# 联合ctest和gtest
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

# 打开才能运行ctest
enable_testing()