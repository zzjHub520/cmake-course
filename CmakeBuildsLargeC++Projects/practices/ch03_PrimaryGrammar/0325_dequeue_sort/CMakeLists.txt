set(src "a;b1;c;d;d1;E;f;g;h;i")

# 双向队列操作方式
# 后端出队 a;b1;c;d;d1;E;f;g;h;i
list(POP_BACK src var)
message("POP_BACK ${var}")
message("src = ${src}")

# 前端出队 先进先出 a;b1;c;d;d1;E;f;g;h;i
list(POP_FRONT src var)
message("POP_FRONT ${var}")
message("src = ${src}")

# 去掉重复元素
set(rsrc "a;b;c;d;d;b;a;z;t;f")
message("rsrc = ${rsrc}")

list(REMOVE_DUPLICATES rsrc)
message("REMOVE_DUPLICATES rsrc = ${rsrc}")

# 数据排序
list(SORT rsrc)
message("SORT rsrc = ${rsrc}")
set(arr "3;23;122;157;1;5;7")
# 字典序排序
list(SORT arr)
message("arr = ${arr}")

# 自然数排序
list(SORT arr COMPARE NATURAL)
message("NATURAL arr = ${arr}")





