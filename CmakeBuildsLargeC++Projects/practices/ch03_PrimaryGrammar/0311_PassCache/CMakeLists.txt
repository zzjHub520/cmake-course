# 命令行传递缓存变量
# cmake -S . -B -D PARA1=para001
message("PARA1 = ${PARA1}")
set(BUILD_SHARED_LIBS OFF CACHE BOOL "SO OR A")
message("BUILD_SHARED_LIBS = ${BUILD_SHARED_LIBS}")
