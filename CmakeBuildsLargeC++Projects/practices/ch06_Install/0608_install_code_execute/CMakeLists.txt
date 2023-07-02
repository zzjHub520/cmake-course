if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.22)
endif ()
project(blp_0608)

file(WRITE a.h "")
file(WRITE b.h "")
install(CODE "message(\"begin install\")")

install(FILES a.h TYPE INCLUDE)
install(CODE "message(\"a.h install success!\")")
install(FILES b.h TYPE INCLUDE)
install(CODE "message(\"b.h install success!\")")

# 写入安装时间
# string(TIMESTAMP now "%Y-%m-%d %H:%M:%S")
# 获取当前时间戳，并转换时间格式，写入now变量
install(CODE [=[
string(TIMESTAMP now "%Y-%m-%d %H:%M:%S")
message("${now}")
file(APPEND install_log.txt "${now}\n")
]=])





