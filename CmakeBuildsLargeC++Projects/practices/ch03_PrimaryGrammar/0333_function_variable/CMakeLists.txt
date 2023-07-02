
function(fun_var arg1)
    message("in fun_var ${arg1}")
    message("fun var1 = ${var1}")
    set(var1 "fun var")
    set(RET "1" PARENT_SCOPE) # 设定变量作用域到父（调用函数者、父目录）
endfunction()

set(var1 "main")
set(arg1 "main arg1")
fun_var(123)
message("main var1 = ${var1}")

add_subdirectory(sub)

func_sub1()
message("main sub1_var = ${sub1_var}")
