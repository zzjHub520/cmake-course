project(sub)

add_library(subLib Sub.cpp Sub.h)
target_include_directories(subLib PUBLIC .)

add_executable(subExec main.cpp)
target_link_libraries(subExec PUBLIC subLib)

