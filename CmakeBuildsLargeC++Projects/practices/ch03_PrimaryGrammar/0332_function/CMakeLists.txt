
macro(mac1 arg1 arg2)
    if (arg2)
        message("macro agr2 = ${arg2}")
    endif ()
endmacro()

function(fun1 arg1 arg2)
    if (arg1)
        message("arg1 is true")
        return()
    endif ()
    message("IN funtion fun1 arg1 = ${arg1}")
    if (arg2) # 函数区别于宏 可以当做变量
        message("function agr2 = ${arg2}")
    endif ()

    foreach (var IN LISTS ARGN)
        message("---var = ${var}")
    endforeach ()
endfunction()
fun1(OFF  TRUE "testfunc1" 1 3 ON)
mac1(OFF TRUE "testfunc1")
fun1(on  TRUE "testfunc1" 1 3 ON)








