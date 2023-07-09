#xcpp/CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
project(xcpp_all)
option(BUILD_XLOG "" ON)
option(BUILD_XTHREAD_POOL "" ON)
option(BUILD_SAMPLES "" ON)
option(BUILD_UNIT_TEST "" ON)
if(BUILD_XLOG)
    add_subdirectory(src/xlog)
endif()

if(BUILD_XTHREAD_POOL)
    add_subdirectory(src/xthread_pool)
endif()

if(BUILD_SAMPLES)
    add_subdirectory(src/samples)
    #添加依赖项，控制编译次序
    add_dependencies(test_xlog xlog)
    add_dependencies(test_xthread_pool xthread_pool)
endif()

if(BUILD_UNIT_TEST)
    enable_testing()
    add_subdirectory(src/xlog/unit_test)
    add_subdirectory(src/xthread_pool/unit_test)
endif()