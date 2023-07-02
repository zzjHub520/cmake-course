# 普通变量
set(NVAR1 "normal var1")

#设置缓存变量覆盖同名普通变量的策略
# OLD 删除同名普通变量
# NEW 不删除普通变量，要访问cache要用$CACHE{var_name}
cmake_policy(SET CMP0126 NEW)

# CACHE 变量
set(NVAR1 "cache var1" CACHE STRING "cache doc")

message("NVAR1        = ${NVAR1}")
message("CACHE{NVAR1} = $CACHE{NVAR1}")








