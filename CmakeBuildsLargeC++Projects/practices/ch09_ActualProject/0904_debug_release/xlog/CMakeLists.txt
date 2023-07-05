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

# 配置输出路径 Debug Release版本输出路径一致
set(CONF_TYPES Debug Release RelWithDebInfo MinSizeRel)
list(APPEND CONF_TYPES "")

foreach (type IN LISTS CONF_TYPES)
    if (type)
        string(TOUPPER _${type} conf)
        message("conf = ${conf}")
    endif ()
    set_target_properties(${PROJECT_NAME} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY${conf} ${CMAKE_CURRENT_LIST_DIR}/../../bin # dll pdb exe 执行程序
            LIBRARY_OUTPUT_DIRECTORY${conf} ${CMAKE_CURRENT_LIST_DIR}/../../lib # .so .dylib
            LIBRARY_OUTPUT_DIRECTORY${conf} ${CMAKE_CURRENT_LIST_DIR}/../../lib # .lib .a
            PDB_OUTPUT_DIRECTORY${conf} ${CMAKE_CURRENT_LIST_DIR}/../../bin # .pdb
            )
endforeach ()







