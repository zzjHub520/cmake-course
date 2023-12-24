project(testSub)

add_executable(TestSub TestSub.cpp)
target_link_libraries(TestSub PUBLIC subLib)
AddCoverage(TestSub)


