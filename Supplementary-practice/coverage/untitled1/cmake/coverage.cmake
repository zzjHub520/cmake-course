

file(DOWNLOAD https://codeload.github.com/linux-test-project/lcov/zip/refs/tags/v1.16 ${CMAKE_CURRENT_BINARY_DIR}/lcov-1.16.zip)

execute_process(COMMAND unzip -qo ${CMAKE_CURRENT_BINARY_DIR}/lcov-1.16.zip
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

set(LCOV ${CMAKE_CURRENT_BINARY_DIR}/lcov-1.16/bin/lcov)
set(GENHTML ${CMAKE_CURRENT_BINARY_DIR}/lcov-1.16/bin/genhtml)

cmake_policy(SET CMP0126 NEW)
set(TEST_TGTS "" CACHE STRING "All testing targets list" FORCE)

function(AddCoverage tgt)
    set(TEST_TGTS $CACHE{TEST_TGTS} ${tgt} CACHE STRING "All testing targets list" FORCE)
    add_custom_command(TARGET ${tgt}
            POST_BUILD
            COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${tgt}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
endfunction()

function(EndCoverage)
    add_custom_target(coverage ALL
            DEPENDS TestAdd TestSub
            )
endfunction()