if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.25)
endif ()
project(ch08_UnitTest)

#add_subdirectory(0802_ctest_demo)
#add_subdirectory(0803_Fetch_gtest)
#add_subdirectory(0804_cmake_gtest_demo)
#add_subdirectory(0805_cmake_tar_gtest)
#add_subdirectory(0806_gtest_TEST_F)
add_subdirectory(0807_gtest_vs_runtime)

