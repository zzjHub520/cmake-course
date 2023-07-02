#CMakeLists.txt test_xlog 102

project(blp_ch02_part15_test_xlog)
#指定头文件查找路径 
include_directories("../xlog")

# 指定库查找路径  window自动找 ../xlog/build/Debug  ../xlog/build/Release
#link_directories("../xlog/build")

add_executable(${PROJECT_NAME} test_xlog.cpp)

# 指定加载的库
target_link_libraries(${PROJECT_NAME} blp_ch02_part15_xlog)

