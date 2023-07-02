if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.25)
endif ()

project(blp_0404)


add_executable(${PROJECT_NAME} cmake_exp.cpp)
# 字符串比较
# $<STREQUAL:string1,string2>
# $<EQUAL:value1,value2>
add_custom_target(${PROJECT_NAME}_STRING COMMAND ${CMAKE_COMMAND} -E echo "$<STREQUAL:string1,string2>")
add_custom_target(${PROJECT_NAME}_NUM COMMAND ${CMAKE_COMMAND} -E echo "$<EQUAL:1,1>")

# 变量查询
#target_include_directories(${PROJECT_NAME} PUBLIC "$<CONFIG>")
add_custom_target(${PROJECT_NAME}_CONFI COMMAND ${CMAKE_COMMAND} -E echo "$<CONFIG>")
# $<CONFIG:Debug,Release>配置项是Debug,Release之一返回1
#target_include_directories(${PROJECT_NAME} PUBLIC "$<CONFIG:Debug,Release>")

# $<PLATFORM_ID:platform_ids> 系统名称 Windows Linux
#message("CMAKE_SYSTEM_NAME = ${CMAKE_SYSTEM_NAME}")
add_custom_target(${PROJECT_NAME}_SYSNAME COMMAND ${CMAKE_COMMAND} -E echo "$<PLATFORM_ID:Windows,Linux>")

# $<IF:condition,true_string,false_string>
# set(LIB ON)
add_custom_target(${PROJECT_NAME}_IF COMMAND ${CMAKE_COMMAND} -E echo "$<IF:$<BOOL:${LIB}>,ON_STRING,OFF_STRING>")


# 目标相关查询
# 生成目标的全路径
add_custom_target(${PROJECT_NAME}_T_F COMMAND ${CMAKE_COMMAND} -E echo "$<TARGET_FILE:${PROJECT_NAME}>")

# 获取目标的属性
add_custom_target(${PROJECT_NAME}_T_P COMMAND ${CMAKE_COMMAND} -E echo "$<TARGET_PROPERTY:${PROJECT_NAME},NAME>")









