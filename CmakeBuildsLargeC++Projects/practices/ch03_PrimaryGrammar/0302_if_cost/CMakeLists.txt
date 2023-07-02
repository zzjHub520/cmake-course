#[[
if(<condition>)
    <commands>
elseif(<condition>) # optional block, can be repeated
else()              # optional block
    <commands>
endif()
]]

#[[
if (<常量>) # constant 常量
如果常量是1， ON，YES，TRUE，Y或非零数（包括浮点数），则为真True
如果常量是0，OFF，NO，FALSE，N，IGNORE，NOTFOUND，空字符串，或以-NOTFOUND结尾则为假False
命名布尔常量不区分大小写
]]

if (1)
    message("1 is true")
endif ()

if (0)
    message("0 is true")
else ()
    message("0 is false")
endif ()

if (OFF)
    message("OFF is true")
elseif (NO)
    message("NO is true")
else ()
    message("OFF NO is false")
endif ()

if ()
    message("empty is true")
else ()
    message("empty is false")
endif ()

if (-1)
    message("-1 is true")
endif ()

if (123)
    message("123 is true")
endif ()

if (0.1)
    message("0.1 is true")
endif ()

if ("-NOTFOUND")
    message("NOTFOUND is true")
else ()
    message("NOTFOUND is false")
endif ()

if (-NOTFOUND)
    message("NOTFOUND is true")
else ()
    message("NOTFOUND is false")
endif ()

if (NOTFOUND)
    message("NOTFOUND is true")
else ()
    message("NOTFOUND is false")
endif ()












