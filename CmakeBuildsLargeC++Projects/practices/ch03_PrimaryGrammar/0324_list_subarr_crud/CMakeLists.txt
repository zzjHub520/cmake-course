set(src "a;b;c;d;e;f;g;h;i")
message("src = ${src}")
# 取其中一部分数组
list(SUBLIST src 0 3 var)
message("SUBLIST ${var}")

# 查找内容
# src = a;b;c;d;e;f;g;h;i
list(FIND src "d" b)
message("FIND b = ${b}")

list(LENGTH src length)
math(EXPR e "${length} - ${b}")

list(SUBLIST src ${b} ${e} var)
message("SUBLIST ${b} ${e} ${var}")

# 插入节点
# src = a;b;c;d;e;f;g;h;i
list(INSERT src 4 "d1")
list(INSERT src 2 "b1")
list(INSERT src 2 "b")
message("INSERT src = ${src}")

# 删除和修改节点
# src a;b;b;b1;c;d;d1;e;f;g;h;i

#通过节点值删除
list(REMOVE_ITEM src "b")
message("REMOVE_ITEM src = ${src}")

# a;b1;c;d;d1;e;f;g;h;i
# 删除指定位置
list(REMOVE_AT src 5)
#重新插入 相当于修改
list(INSERT src 5 "E")
message("REMOVE_AT INSERT src = ${src}")


# TRANSFORM 使用元素同时修改
# APPEND，PREPEND：将指定的值附加到列表的每个元素。
# list(TRANSFORM <list> <APPEND|PREPEND> <value> ...)
list(TRANSFORM src APPEND "--")
message("TRANSFORM APPEND src = ${src}")

# TOUPPER, TOLOWER: 转换为大、小写
# list(TRANSFORM <list> <TOLOWER|TOUPPER> ...)
list(TRANSFORM src TOUPPER)
message("TRANSFORM TOUPPER src = ${src}")

# STRIP:从列表的每个元素中删除前导空格和尾随空格。
# list(TRANSFORM <list> STRIP ...)
list(INSERT src 0 "  a")
list(TRANSFORM src STRIP)
message("TRANSFORM STRIP src = [${src}]")

# GENEX_STRIP:从列表的每个元素中删除生成器表达式。
# list(TRANSFORM <list> GENEX_STRIP ...)

# REPLACE:尽可能多次匹配正则表达式，并将替换表达式替换为列表中每个元素的匹配(语义与REGEX REPLACE from string()命令相同)。
# list(TRANSFORM <list> REPLACE <regular_expression>
#                              <replace_expression> ...)
list(TRANSFORM src REPLACE "[A-E]" "b")
message("TRANSFORM REPLACE src = [${src}]")

set(my_list "a  b;c d ")
list(TRANSFORM my_list REPLACE " +" ";")
message("TRANSFORM REPLACE my_list = [${my_list}]")

list(REMOVE_ITEM my_list "")
message("TRANSFORM REPLACE my_list = [${my_list}]")

# < SELECTOR >确定要转换列表中的哪些元素。一次只能指定一种类型的选择器。给定时，< SELECTOR >必须是以下之一：
# AT:指定一个索引列表。
#list(TRANSFORM <list> <ACTION> AT <index> [<index> ...] ...)
list(TRANSFORM src REPLACE "[A-Z]" "hh" AT 8 9 10)
message("TRANSFORM REPLACE AT src = [${src}]")

# FOR:指定一个范围，可选地使用一个增量来遍历该范围。
# list(TRANSFORM <list> <ACTION> FOR <start> <stop> [<step>] ...)
list(TRANSFORM src REPLACE "[A-Z]" "EE" FOR 6 10)
message("TRANSFORM REPLACE FOR src = [${src}]")

# REGEX:指定正则表达式。只有匹配正则表达式的元素才会被转换。
# list(TRANSFORM <list> <ACTION> REGEX <regular_expression> ...)
set(MY_LIST 0 1.txt 2.txt 3 4 5 6 7 8 9.txt)
list(TRANSFORM MY_LIST APPEND "追加,  " REGEX [[\.txt$]])
message("${MY_LIST}")
