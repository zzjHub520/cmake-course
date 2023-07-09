#xcpp/src/samples/test_xlog/CMakeLists.txt
# xlog库编译
cmake_minimum_required(VERSION 3.22)
project(test_xlog)
include(${CMAKE_CURRENT_LIST_DIR}/../../../cmake/common.cmake)

#导入的xlog库是否是动态库
option(LOAD_XLOG_STATIC "" OFF)

message("XLOG_SHARED = ${XLOG_SHARED}")

if(DEFINED XLOG_SHARED )
    if(XLOG_SHARED)
        set(LOAD_XLOG_STATIC OFF)
    else()
        set(LOAD_XLOG_STATIC ON)
    endif()
endif()
message("LOAD_XLOG_STATIC is ${LOAD_XLOG_STATIC}")

cpp_execute(${PROJECT_NAME} xlog)

#配置头文件路径
target_include_directories(${PROJECT_NAME} PRIVATE "../../xlog/include")

if(LOAD_XLOG_STATIC)
    target_compile_definitions(${PROJECT_NAME} PRIVATE XLOG_STATIC)
    message("LOAD_XLOG_STATIC XLOG_STATIC ===")
endif()
