#xcpp/src/samples/test_xlog/CMakeLists.txt
# xlog库编译
cmake_minimum_required(VERSION 3.22)
project(test_xthread_pool)
include(${CMAKE_CURRENT_LIST_DIR}/../../../cmake/common.cmake)

#导入的xlog库是否是动态库
option(LOAD_XTHREAD_POOL_STATIC "" OFF)

message("XTHREAD_POOL_SHARED = ${XTHREAD_POOL_SHARED}")

if(DEFINED XTHREAD_POOL_SHARED )
    if(XTHREAD_POOL_SHARED)
        set(LOAD_XTHREAD_POOL_STATIC OFF)
    else()
        set(LOAD_XTHREAD_POOL_STATIC ON)
    endif()
endif()
message("LOAD_XTHREAD_POOL_STATIC is ${LOAD_XTHREAD_POOL_STATIC}")

cpp_execute(${PROJECT_NAME} xthread_pool)

#配置头文件路径
target_include_directories(${PROJECT_NAME} PRIVATE "../../xthread_pool/include")

if(LOAD_XTHREAD_POOL_STATIC)
    target_compile_definitions(${PROJECT_NAME} PRIVATE XTHREAD_POOL_STATIC)
    message("LOAD_XTHREAD_POOL_STATIC XTHREAD_POOL_STATIC ===")
endif()
