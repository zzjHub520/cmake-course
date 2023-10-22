project(export_tgt)

add_executable(${PROJECT_NAME} main.cpp)
export(TARGETS ${PROJECT_NAME} FILE aaa.cmake)
