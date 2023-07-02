if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.25)
endif ()

project(blp_0403)

add_executable(${PROJECT_NAME} cmake_exp.cpp)

# 测试生成表达式的方式
# 1 利用cmake的错误来查看
#target_include_directories(${PROJECT_NAME} PUBLIC "$<BOOL:N>")
#target_include_directories(${PROJECT_NAME} PUBLIC "$<AND:1,0>")
#target_include_directories(${PROJECT_NAME} PUBLIC "$<OR:0,0>")
#target_include_directories(${PROJECT_NAME} PUBLIC "$<NOT:0>")
set(LIB OFF)
#target_include_directories(${PROJECT_NAME} PUBLIC "$<NOT:$<BOOL:${LIB}>>")
#target_include_directories(${PROJECT_NAME} PUBLIC "$<$<NOT:$<BOOL:${LIB}>>:STATIC>")

# 2 查看compile_commands.json文件
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 3 cmake生成表达式调试方法（官方）
# cmake -E echo "生成表达式"
add_custom_target(${PROJECT_NAME}_gen COMMAND ${CMAKE_COMMAND} -E echo "$<$<NOT:$<BOOL:${LIB}>>:STATIC=1>")