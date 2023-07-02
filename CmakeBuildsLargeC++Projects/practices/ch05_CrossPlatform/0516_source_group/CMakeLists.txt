if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.22)
endif ()

project(blp_ch05_part16_source_group)

#[=[
source_group(<name> [FILES <src>...] [REGULAR_EXPRESSION <regex>])
source_group(TREE <root> [PREFIX <prefix>] [FILES <src>...])
]=]

file(WRITE main.cpp [=[
int main()
{
    return 0;
}
]=])

file(WRITE a.cpp "")
file(WRITE b.cpp "")
file(WRITE a.h "")
file(WRITE b.h "")

add_executable(${PROJECT_NAME} main.cpp a.cpp b.cpp a.h b.h)

source_group(src FILES a.cpp b.cpp)
source_group(include FILES b.h)
#source_group(TREE . PREFIX include/inc FILES a.h)


















