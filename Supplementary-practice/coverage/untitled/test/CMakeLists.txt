project(test)


file(DOWNLOAD https://codeload.github.com/linux-test-project/lcov/zip/refs/tags/v1.16 ${CMAKE_CURRENT_BINARY_DIR}/lcov-1.16.zip)

execute_process(COMMAND unzip -qo ${CMAKE_CURRENT_BINARY_DIR}/lcov-1.16.zip
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

set(LCOV_PATH ${CMAKE_CURRENT_BINARY_DIR}/lcov-1.16/bin/lcov)
set(GENHTML_PATH ${CMAKE_CURRENT_BINARY_DIR}/lcov-1.16/bin/genhtml)

add_executable(Test_main Test_main.cpp)

#add_custom_target()