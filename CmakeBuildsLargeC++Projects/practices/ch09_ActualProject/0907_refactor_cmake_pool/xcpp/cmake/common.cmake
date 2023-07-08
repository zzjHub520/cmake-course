# xcpp/cmake/common.cmake

# #cmakedefine _XCPP_NAMESPACE_ @_XCPP_NAMESPACE_@
set(_XCPP_NAMESPACE_ "namespace xcpp {")
# ${CMAKE_CURRENT_LIST_DIR}是common。cmake的路径
set(RUNTIME_DIR ${CMAKE_CURRENT_LIST_DIR}/../bin)
set(LIBRARY_DIR ${CMAKE_CURRENT_LIST_DIR}/../lib)

function(cpp_library name)

    message(STATUS "========== ${name} cpp_library =============")

    ############################################################
    # 配置项目是否是动态库
    # 用户指定xlog是动态库还是静态库
    option(${name}_SHARED "OFF is static" ON)
    message("${name}_SHARED = ${${name}_SHARED}")
    set(TYPE STATIC)
    if (${name}_SHARED)
        set(TYPE SHARED)
    endif ()

    ############################################################
    # 查找项目的源码和头文件
    aux_source_directory(${CMAKE_CURRENT_LIST_DIR} SRC)

    # 加入.h文件到编译依赖
    file(GLOB H_FILE ${CMAKE_CURRENT_LIST_DIR}/*.h)
    # 对外接口的头文件
    file(GLOB H_FILE_I ${CMAKE_CURRENT_LIST_DIR}/include/*.h)

    ############################################################
    # 生成库
    add_library(${name} ${TYPE} ${SRC} ${H_FILE} ${H_FILE_I})


    ############################################################
    # 静态库和动态库传递不同的宏变量给C++
    # XLOG_STATIC XLOG_EXPORTS
    if (XLOG_SHARED)
        target_compile_definitions(${name} PUBLIC XLOG_EXPORTS)
    else ()
        target_compile_definitions(${name} PUBLIC XLOG_STATIC)
    endif ()


    ############################################################
    # 设置头文件查找路径
    target_include_directories(${name} PRIVATE
            ${CMAKE_CURRENT_LIST_DIR}/include/
            ${CMAKE_CURRENT_LIST_DIR}
            )

    ############################################################
    target_compile_features(${name} PRIVATE cxx_std_14)


    ############################################################
    # 配置VS属性 bigobj
    if (MSVC)
        set_target_properties(${name} PROPERTIES
                COMPILE_FLAGS "-bigobj"
                )
    endif ()

    ############################################################
    ## 输出路径配置 Debug 和 Release 配置同一个路径
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
        set_target_properties(${name} PROPERTIES
                RUNTIME_OUTPUT_DIRECTORY${conf} ${RUNTIME_DIR} # dll pdb exe 执行程序
                LIBRARY_OUTPUT_DIRECTORY${conf} ${LIBRARY_DIR} # .so .dylib
                ARCHIVE_OUTPUT_DIRECTORY${conf} ${LIBRARY_DIR} # .lib .a
                PDB_OUTPUT_DIRECTORY${conf} ${RUNTIME_DIR}  # .pdb 调试
                )
    endforeach ()

    # 设置Debug添加 d 后缀
    set_target_properties(${name} PROPERTIES
            DEBUG_POSTFIX "d"
            )


    ############################################################
    ## 库的安装
    # 安装库 ${f}
    # cmake -S . -B build -DCMAKE_INSTALL_PREFIX=./out
    # 或者 cmake --install build --prefix=out2
    #  cmake --install win --config Release --prefix=out

    set(version 1.0)
    #设置安装的头文件
    set_target_properties(${name} PROPERTIES
            PUBLIC_HEADER "${H_FILE_I}"
            )

    install(TARGETS ${name}
            EXPORT ${name}
            RUNTIME DESTINATION bin
            LIBRARY DESTINATION lib
            PUBLIC_HEADER DESTINATION include
            )

    # 支持find_package
    # 生成并安装配置文件 xlogConfig.cmake
    install(EXPORT ${name} FILE ${name}Config.cmake
            DESTINATION lib/config/${name}-${version}
            )

    # 版本文件
    set(CONF_VAR_FILE ${CMAKE_CURRENT_LIST_DIR}/../../lib/conf/${name}-${version}/${name}ConfigVersion.cmake)
    message("CONF_VAR_FILE = ${CONF_VAR_FILE}")
    include(CMakePackageConfigHelpers)
    write_basic_package_version_file(
            ${CONF_VAR_FILE}
            VERSION ${version}
            COMPATIBILITY SameMajorVersion
    )
    install(FILES ${CONF_VAR_FILE}
            DESTINATION lib/config/${name}-${version}
            )


    message(STATUS "============================================")
endfunction()