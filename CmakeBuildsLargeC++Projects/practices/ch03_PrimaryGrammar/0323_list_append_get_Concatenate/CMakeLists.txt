#list 变量初始化
set(src "a" "b" "c" "d;e;f")
message("src = ${src}")
#获取list变量长度
list(LENGTH src length)
message("src length = ${length}")
#list追加写入
list(APPEND src "g")
list(APPEND src "h" "i")
message("src = ${src}")

# list访问 下标 0,1,2。。。结尾往前 -1，-2，-3
# src = a;b;c;d;e;f;g;h;i
list(GET src 1 var)
message("GET src 1 = ${var}")
list(GET src 5 var)
message("GET src 5 = ${var}")
list(GET src -1 var)
message("GET src -1 = ${var}")
list(GET src -2 var)
message("GET src -2 = ${var}")

# 拼接所有的节点
list(JOIN src "|" var)
message("JOIN ${var}")
list(JOIN src "" var)
message("JOIN ${var}")






