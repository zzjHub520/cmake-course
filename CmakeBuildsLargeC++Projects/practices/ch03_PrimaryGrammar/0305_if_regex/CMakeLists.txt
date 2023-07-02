# 一元判断 DEFINED
set(VAR_DEF OFF)
if (DEFINED VAR_DEF)
    message("VAR_DEF is DEFINED")
endif ()

if (DEFINED VAR_NOT_DEF)
    message("VAR_NOT_DEF is DEFINED")
else ()
    message("VAR_NOT_DEF not DEFINED")
endif ()


# 二元判断 EQUAL(数字相等) STREQUAL(字符串相等)
set(VAR1 123)
if (VAR1 EQUAL "123")
    message("VAR1 EQUAL 123")
else ()
    message("VAR1 not EQUAL 123")
endif ()

set(VAR2 "test")
if (VAR2 EQUAL "test")
    message("VAR2 EQUAL test")
else ()
    message("VAR2 not EQUAL test")
endif ()

if (VAR2 STREQUAL "test")
    message("VAR2 STREQUAL test")
else ()
    message("VAR2 not STREQUAL test")
endif ()

if (VAR1 STREQUAL "123")
    message("VAR1 STREQUAL 123")
else ()
    message("VAR1 not STREQUAL 123")
endif ()

if (VAR1 STREQUAL 123)
    message("VAR1 STREQUAL 123")
else ()
    message("VAR1 not STREQUAL 123")
endif ()

#[[
正则表达式
MATCHES
if(<variable|string> MATCHES regex)
]]
set(STR1 "abcd1234")
if (STR1 MATCHES "[a-z]+")
    message([["abcd1234" MATCHES "[a-z]+"]])
else ()
    message([["abcd1234" not MATCHES "[a-z]+"]])
endif ()

if (STR1 MATCHES "^[a-z]+$")
    message([["abcd1234" MATCHES "^[a-z]+$"]])
else ()
    message([["abcd1234" not MATCHES "^[a-z]+$"]])
endif ()



