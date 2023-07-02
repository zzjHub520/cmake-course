#[[
if(<variable>)
如果给定一个定义为非假常量的变量，则为真否则为false了，包括变量未定义时。
宏参数不是变量。环境变量if(ENV{some_var})总是会评估为假。
]]

if (VAR_NOT_DEF) #未定义变量为false
    message("VAR_NOT_DEF is true")
else ()
    message("VAR_NOT_DEF is false")
endif ()

set(VAR1_TRUE "gdfsa")
if (VAR1_TRUE)
    message("VAR1_TRUE is true!")
else ()
    message("VAR1_TRUE is false!")
endif ()

#[[
if(<string>)
    带引号的字符串计算为false， 除非字符串的值是真正的常量之一
]]

if ("TRUE")
    message("string TRUE is true!")
endif ()

if ("ON")
    message("string ON is true!")
endif ()

if ("test")
    message("string test is true!")
else ()
    message("string test is false!")
endif ()

if ("1234")
    message("string 1234 is true!")
else ()
    message("string 1234 is false!")
endif ()





