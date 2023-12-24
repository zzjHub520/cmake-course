project(add)

add_library(addLib Add.cpp Add.h)
target_include_directories(addLib PUBLIC .)

add_executable(addExec main.cpp)
target_link_libraries(addExec PUBLIC addLib)
