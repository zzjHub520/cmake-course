#404cmake_version/CMakeLists.txt
# 只在Linux演示 动态库有版本号
cmake_minimum_required(VERSION 3.22)
project(cmake_version)

file(WRITE a.cpp [=[
void A(){};
]=]
)

file(WRITE main.cpp [=[
int main(){return 0;};
]=]
)

add_library(a SHARED a.cpp)
# liba.so  liba.so.15  liba.so.2.0.1
# liba.so -> liba.so.15*
# liba.so.15 -> liba.so.2.0.1*
# liba.so.2.0.1*
set_target_properties(a PROPERTIES
VERSION "2.0.1"
SOVERSION "15"
#NO_SONAME OFF #OFF生成 ON不生成库的符号链接
)

add_executable(main main.cpp)
target_link_libraries(main a)

# main -> main-2.0.1*
# main-2.0.1*
set_target_properties(main PROPERTIES
VERSION "2.0.1"
# SOVERSION "15" # 对执行程序无效
)