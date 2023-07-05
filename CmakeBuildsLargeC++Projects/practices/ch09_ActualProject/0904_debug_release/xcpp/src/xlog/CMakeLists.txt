if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.22)
endif ()
project(xlog)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR} SRC)

# 加入.h文件到编译依赖
file(GLOB H_FILE ${CMAKE_CURRENT_LIST_DIR}/*.h)
# 对外接口的头文件
file(GLOB H_FILE_I ${CMAKE_CURRENT_LIST_DIR}/include/*.h)

add_library(${PROJECT_NAME} ${SRC} ${H_FILE} ${H_FILE_I})

# 设置头文件查找路径
target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include/
        ${CMAKE_CURRENT_LIST_DIR}
        )

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_14)

# 配置VS属性 bigobj
if (MSVC)
    set_target_properties(${PROJECT_NAME} PROPERTIES
            COMPILE_FLAGS "-bigobj"
            )
endif ()

# 静态库和动态库传递不同的宏变量给C++
# XLOG_STATIC XLOG_EXPORTS
target_compile_definitions(${PROJECT_NAME} PUBLIC XLOG_STATIC)







