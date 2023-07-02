#407cmake_vs_group/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project(vs_group)
#[[
source_group(<name> [FILES <src>...] [REGULAR_EXPRESSION <regex>])
source_group(TREE <root> [PREFIX <prefix>] [FILES <src>...])
]]

file(WRITE main.cpp  [=[
int main()
{
    return 0;
}
]=])
file(WRITE a.cpp "")
file(WRITE b.cpp "")
file(WRITE a.h "")
file(WRITE b.h "")
add_executable(vs_group main.cpp a.cpp b.cpp  a.h b.h )
source_group(src FILES a.cpp b.cpp)
source_group(include FILES b.h)
# <root> 后面的src路径会去掉root的内容，显示剩下的路径
source_group(TREE . PREFIX include/inc FILES a.h)