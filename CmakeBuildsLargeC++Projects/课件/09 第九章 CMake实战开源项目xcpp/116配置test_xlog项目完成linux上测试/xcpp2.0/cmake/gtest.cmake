#xcpp/cmake/gest.cmake
#设置gtest的路径
set(GTEST_TOOLS ${CMAKE_CURRENT_LIST_DIR}/../tools)
#不同系统安装在不同的路径 CMAKE_SYSTEM_NAME = Linux Windows
set(GTEST_PATH  ${GTEST_TOOLS}/${CMAKE_SYSTEM_NAME}/gtest)
macro(setup_gtest)
    # 如果GTest没有安装
    if(NOT EXISTS ${GTEST_PATH})
    #1 解压文件 gtest-1.11.0.tar.gz  
    # cmake -E 执行shell命令  PROJECT_BINARY_DIR -B build
    message("tar xf gtest-1.11.0.tar.gz")
    execute_process(COMMAND  ${CMAKE_COMMAND}
    -E tar xf ${GTEST_TOOLS}/gtest-1.11.0.tar.gz 
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
endmacro()
