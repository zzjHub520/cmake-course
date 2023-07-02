if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.25)
endif ()
project(blp_ch02_part04_AdvanceMessageLog)

# FATAL_ERROR 打印代码路径和行号
# FATAL_ERROR 进程退出，生成退出
#message(FATAL_ERROR "test FATAL_ERROR")

# SEND_ERROR 打印代码路径和行号
# SEND_ERROR 进程继续，生成退出，不会生成add_executable() add_library()
message(SEND_ERROR "test SEND_ERROR")
add_executable(${PROJECT_NAME} main.cpp)

# WARNING 打印代码路径和行号
message(WARNING "test WARNING")

# NOTICE等同于none，也就是不加  message("test NOTICE")
message("test NOTICE")
message(NOTICE "test NOTICE")

# STATUS 加前缀 -- 用可能感兴趣 stdout
message(STATUS "test STATUS")

# VERBOSE 加前缀 -- 默认不显示 用户需要的详细信息
message(VERBOSE "test VERBOSE")

# 设置日志显示级别
# cmake -S . -B build --log-level=VERBOSE > log 2>&1

# DEBUG 加前缀 --
message(DEBUG "test DEBUG")


# TRACE 加前缀 -- 最低级
message(TRACE "test TRACE")

