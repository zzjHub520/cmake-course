if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.25)
endif ()
project(blp_ch02_part02_CommentAndMessage)

#[[
message("参数1")
]]

message("参数1") # 测试message
message("参数1" "参数1" #[[ 注释在message中]] "参数1" "参数1")