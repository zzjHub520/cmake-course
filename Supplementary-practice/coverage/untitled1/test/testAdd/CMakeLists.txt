project(testAdd)

add_executable(TestAdd TestAdd.cpp)
target_link_libraries(TestAdd PUBLIC addLib)
AddCoverage(TestAdd)