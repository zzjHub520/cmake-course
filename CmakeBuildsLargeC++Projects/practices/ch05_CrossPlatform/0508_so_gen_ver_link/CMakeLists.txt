if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.25)
endif ()

# 只在Linux上演示 动态库有版本号
project(blp_0508)

file(WRITE a.cpp [=[
void A(){}
]=])

file(WRITE main.cpp [=[
int main()
{
    return 0;
}
]=])


add_library(${PROJECT_NAME}_a SHARED a.cpp)

# libblp_ch05_part08_so_gen_ver_link_a.so -> libblp_ch05_part08_so_gen_ver_link_a.so.15
# libblp_ch05_part08_so_gen_ver_link_a.so.15 -> libblp_ch05_part08_so_gen_ver_link_a.so.2.0.1
# libblp_ch05_part08_so_gen_ver_link_a.so.2.0.1
set_target_properties(${PROJECT_NAME}_a PROPERTIES
        VERSION "2.0.1"
        SOVERSION "15"
        NO_SONAME OFF # OFF 生成  ON不生成库的符号链接
        )

add_executable(${PROJECT_NAME}_main main.cpp)
target_link_libraries(${PROJECT_NAME}_main ${PROJECT_NAME}_a)

set_target_properties(${PROJECT_NAME}_main PROPERTIES
        VERSION "2.0.1"
        #SOVERSION "15" # 执行程序无效
        #NO_SONAME OFF # OFF 生成  ON不生成库的符号链接
        )

















