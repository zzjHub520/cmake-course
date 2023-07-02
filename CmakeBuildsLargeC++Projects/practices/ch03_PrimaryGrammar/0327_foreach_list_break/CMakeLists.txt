# 遍历list数组
set(args a b c d e)
foreach (var IN LISTS args)
    message(${var})
endforeach ()

foreach (var IN ITEMS args)
    message(${var})
endforeach ()

foreach (var IN ITEMS ${args}) # 必须是list值
    message(${var})
endforeach ()

foreach (var IN ITEMS "1;2;3;4;5") # 数组格式的字符串不支持
    message(${var})
endforeach ()

foreach (var IN ITEMS 1;2;3;4;5)
    message(${var})
endforeach ()

# 遍历多个list 可实现list按顺序拼接
set(A "0;1;2;3")
set(B "4;5;6;7")
set(out "")
foreach (var IN LISTS A B)
    string(APPEND out ${var} " ")
endforeach ()
message("out = ${out}")

# 同步遍历多个list
set(arr1 "1;2;3;4;5;6;7")
set(arr2 "A;B;C;D;E;F;G")
foreach (var IN ZIP_LISTS arr1 arr2)
    message("${var_0}: ${var_1}")
endforeach ()

foreach (var1 var2 IN ZIP_LISTS arr1 arr2)
    message("${var1}: ${var2}")
endforeach ()

# break() continue()
foreach (var RANGE 100)
    math(EXPR re "${var} % 3")
    if (NOT re)
        message(${var})
        continue()
    endif ()

    if (var GREATER 50)
        break()
    endif ()
    message(".")
endforeach ()








