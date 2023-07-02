if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.25)
endif ()

project(blp_0506)

file(WRITE main.cpp [=[
int main()
{
    return 0;
}
]=])

add_executable(${PROJECT_NAME}_main main.cpp)
#target_compile_features(${PROJECT_NAME}_main PRIVATE cxx_std_17)
#target_compile_features(${PROJECT_NAME}_main PRIVATE cxx_std_23)

foreach (var IN LISTS CMAKE_CXX_COMPILE_FEATURES)
    message("${var}")
endforeach ()

message("---------------------------------------------")

# 判断当前编译器是否支持该特性
set(f1 cxx_std_23)
if (f1 IN_LIST CMAKE_CXX_COMPILE_FEATURES)
    message("${f1} OK!")
    target_compile_features(${PROJECT_NAME}_main PRIVATE ${f1})
else ()
    message("${f1} FAILED!")
endif ()