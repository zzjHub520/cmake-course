# 格式输出
function(print ret num n)
    string(LENGTH ${num} var)
    if (${var} LESS ${n})
        math(EXPR var "${var} + 1")
        foreach (i RANGE ${var} ${n})
            string(PREPEND num "0")
        endforeach ()
    endif ()
    set(${ret} ${num} PARENT_SCOPE)
endfunction()

#foreach (chi RANGE 6 10)
#    foreach (pi RANGE 2 13)
#        print(chi ${chi} 2)
#        print(pi ${pi} 2)
#        file(WRITE "${CMAKE_BINARY_DIR}/${chi}${pi}_/CMakeLists.txt" [=[if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
#    cmake_minimum_required(VERSION 3.22)
#endif ()
#]=]
#                "project(blp_${chi}${pi})"
#                )
#    endforeach ()
#endforeach ()
