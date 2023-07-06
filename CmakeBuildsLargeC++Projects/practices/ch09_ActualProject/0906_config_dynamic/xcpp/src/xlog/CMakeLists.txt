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
target_include_directories(${PROJECT_NAME} PRIVATE
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

# 默认为Debug
if (CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE Debug)
endif ()
# 配置输出路径 Debug Release版本输出路径一致
set(CONF_TYPES Debug Release RelWithDebInfo MinSizeRel)
list(APPEND CONF_TYPES "")

foreach (type IN LISTS CONF_TYPES)
    set(conf "")
    if (type)
        string(TOUPPER _${type} conf)
        message("conf = ${conf}")
    endif ()
    set_target_properties(${PROJECT_NAME} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY${conf} ${CMAKE_CURRENT_LIST_DIR}/../../bin # dll pdb exe 执行程序
            LIBRARY_OUTPUT_DIRECTORY${conf} ${CMAKE_CURRENT_LIST_DIR}/../../lib # .so .dylib
            ARCHIVE_OUTPUT_DIRECTORY${conf} ${CMAKE_CURRENT_LIST_DIR}/../../lib # .lib .a
            PDB_OUTPUT_DIRECTORY${conf} ${CMAKE_CURRENT_LIST_DIR}/../../bin # .pdb 调试
            )
endforeach ()

# 设置Debug添加 d 后缀
set_target_properties(${PROJECT_NAME} PROPERTIES
        DEBUG_POSTFIX "d"
        )


# 安装库 ${f}
# cmake -S . -B build -DCMAKE_INSTALL_PREFIX=./out
# 或者 cmake --install build --prefix=out2
#  cmake --install win --config Release --prefix=out

set(version 1.0)
#设置安装的头文件
set_target_properties(${PROJECT_NAME} PROPERTIES
        PUBLIC_HEADER "${H_FILE_I}"
        )

install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include
        )

# 支持find_package
# 生成并安装配置文件 xlogConfig.cmake
install(EXPORT ${PROJECT_NAME} FILE ${PROJECT_NAME}Config.cmake
        DESTINATION lib/config/${PROJECT_NAME}-${version}
        )

# 版本文件
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        ${CMAKE_CURRENT_LIST_DIR}/../../lib/conf/${PROJECT_NAME}-${version}/${PROJECT_NAME}ConfigVersion.cmake
        VERSION ${version}
        COMPATIBILITY SameMajorVersion
)
install(FILES ${CMAKE_CURRENT_LIST_DIR}/../../lib/conf/${PROJECT_NAME}ConfigVersion.cmake
        DESTINATION lib/config/${PROJECT_NAME}-${version}
        )


