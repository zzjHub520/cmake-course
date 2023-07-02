macro(my_macro)
    message("in my macro")
endmacro()

# 宏名称大小写不敏感，尽量只用小写
# 调用是将宏代码复制过来
my_macro()
My_macro()

# 参数，实参数量要等于或者超过形参
macro(foo arg1 arg2)
    message("arg1 = ${arg1}  arg2 = ${arg2}")
    if (arg1)
        message("====== arg1 true =========")
    endif ()

    if (${arg1})
        message([[${arg1} true]])
    endif ()

endmacro()

foo(TRUE "test")

macro(foo2)
    # 参数数量
    message("ARGC = ${ARGC}")

    #参数list
    message("ARGN = ${ARGN}")

    # ARGN不是变量只能取值使用
    foreach (var IN ITEMS ${ARGN})
        message("var = ${var} ")
    endforeach ()

    message("ARGV0 = ${ARGV0}")
    message("ARGV1 = ${ARGV1}")
    message("ARGV2 = ${ARGV2}")
    message("ARGV3 = ${ARGV3}")
endmacro()

foo2(1 "test" True)









