cmake_minimum_required(VERSION 3.25)
project(demo1)

set(CMAKE_CXX_STANDARD 17)

add_executable(demo1 main1.cpp)
add_executable(demo2 main2.cpp)
add_executable(demo3 main3.cpp)


foreach (var RANGE 1 3)
    string(APPEND rmv "COMMAND ${CMAKE_COMMAND} -E remove -f $<TARGET_FILE:demo${var}>\n")
    string(APPEND compile "COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} -t demo${var}\n")
    string(APPEND exect "COMMAND $<TARGET_FILE:demo${var}>\n")
endforeach ()

cmake_language(EVAL CODE "
add_custom_target(aa ALL
        ${rmv}
        COMMAND ${CMAKE_COMMAND} -S ${CMAKE_SOURCE_DIR} -B ${CMAKE_BINARY_DIR}
${compile}
${exect})
")



cmake_language(CALL message STATUS "hello world==============")







