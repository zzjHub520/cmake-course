# CACHE 变量作用域是全局的
# 普通变量的作用域 自身和子模块
set(VAR_NORMAL "test normal")
message("in main")
message("VAR_NORMAL = ${VAR_NORMAL}")
add_subdirectory(sub1)
add_subdirectory(sub2)
# 无法访问sub1中的普通变量
message("in main VAR_SUB1 = ${VAR_SUB1}")
# 访问sub1的全局缓存变量
message("== in main VAR_CACHE_SUB1 = ${VAR_CACHE_SUB1}")


