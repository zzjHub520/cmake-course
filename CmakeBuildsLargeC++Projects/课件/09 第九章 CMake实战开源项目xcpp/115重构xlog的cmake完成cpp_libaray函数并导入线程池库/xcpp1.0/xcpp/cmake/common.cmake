#xcpp/cmake/commmon.txt

# 统一的命名空间
# #cmakedefine _XCPP_NAMESPACE_ @_XCPP_NAMESPACE_@
set(_XCPP_NAMESPACE_ "namespace xcpp {")
#${CMAKE_CURRENT_LIST_DIR}是common.cmake的路径
set(RUNTIME_DIR ${CMAKE_CURRENT_LIST_DIR}/../bin)
set(LIBRARY_DIR ${CMAKE_CURRENT_LIST_DIR}/../lib)

function(cpp_library name)

    message(STATUS "================ ${name} cpp_library =================")
    
    #############################################################
    # 配置项目是否是动态库
    # 用户指定xlog是动态库还是静态库
    option(${name}_SHARED "OFF is static cpp_library" ON)
    message("${name}_SHARED = ${${name}_SHARED}")
    set(TYPE STATIC)
    if(${name}_SHARED)
        set(TYPE SHARED)
    endif()

    #############################################################
    # 查找项目的源码和头文件
    #CMAKE_CURRENT_LIST_DIR 当前CMakeLists.txt文件所在路径
    aux_source_directory(${CMAKE_CURRENT_LIST_DIR} SRC)
    
    #加入.h文件到编译依赖
    FILE(GLOB H_FILE ${CMAKE_CURRENT_LIST_DIR}/*.h)
    
    #对外接口的头文件
    FILE(GLOB H_FILE_I ${CMAKE_CURRENT_LIST_DIR}/include/*.h)


    #############################################################
    #生成库
    add_library(${name} ${TYPE} ${SRC} ${H_FILE} ${H_FILE_I})
    
    #############################################################
    # 静态库和动态库传递不同的宏变量给c++
    # XLOG_STATIC XLOG_EXPORTS
    if(XLOG_SHARED)
        target_compile_definitions(${name} PUBLIC XLOG_EXPORTS)
    else()
        target_compile_definitions(${name} PUBLIC XLOG_STATIC)
    endif()
    
    #############################################################
    #设置头文件查找路径
    target_include_directories(${name} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/include/
        ${CMAKE_CURRENT_LIST_DIR}
    )

    #############################################################
    #配置c++参数
    target_compile_features(${name} PRIVATE
        cxx_std_14
    )

    #############################################################
    #配置vs属性 bigobj
    if(MSVC)
        set_target_properties(${name} PROPERTIES
            COMPILE_FLAGS "-bigobj"
        )
    endif()
    
    
    #############################################################
    # 输出路径配置 Debug和Release配置同一个路径
    # 默认为Debug
    if(CMAKE_BUILD_TYPE STREQUAL "")
        set(CMAKE_BUILD_TYPE Debug)
    endif()
    
    # 配置输出路径 Debug Release版本输出路径一致
    set(CONF_TYPES Debug Release RelWithDebInfo MinSizeRel)
    list(APPEND CONF_TYPES "")
    foreach(type IN LISTS CONF_TYPES)
        set(conf "")
        if(type)
            string(TOUPPER _${type} conf)
            message("conf = ${conf}")
        endif()
        set_target_properties(${name} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY${conf} ${RUNTIME_DIR}  #dll  exe 执行程序
        LIBRARY_OUTPUT_DIRECTORY${conf} ${LIBRARY_DIR}  # .so .dylib 
        ARCHIVE_OUTPUT_DIRECTORY${conf} ${LIBRARY_DIR}  # .lib .a
        PDB_OUTPUT_DIRECTORY${conf} ${RUNTIME_DIR} #pdb
        )
    endforeach()
    
    # 设置debug添加d后缀
    set_target_properties(${name} PROPERTIES
        DEBUG_POSTFIX "d"
    )
    
    #############################################################
    # 库的安装配置
    # ${CMAKE_INSTALL_PREFIX}  
    # cmake -S . -B build -D CMAKE_INSTALL_PREFIX=./out
    # cmake --install build --prefix=out
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
    instaLl(EXPORT ${name} FILE ${name}Config.cmake
        DESTINATION lib/config/${name}-${version}
    )

    # 版本文件
    set(CONF_VER_FILE 
    ${CMAKE_CURRENT_LIST_DIR}/../../lib/conf/${name}-${version}/${name}ConfigVersion.cmake)
    
    message("CONF_VER_FILE = ${CONF_VER_FILE}")
    include(CMakePackageConfigHelpers)
    write_basic_package_version_file(
        ${CONF_VER_FILE}
        VERSION ${version}
        COMPATIBILITY SameMajorVersion  # 版本兼容问题
    )
    install(FILES ${CONF_VER_FILE}
        DESTINATION lib/config/${name}-${version}
    )
    message(STATUS "======================================================")
endfunction()

