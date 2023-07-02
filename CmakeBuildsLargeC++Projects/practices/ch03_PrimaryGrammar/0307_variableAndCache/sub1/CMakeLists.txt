message("in sub1 VAR_NORMAL = ${VAR_NORMAL}")

set(VAR_SUB1 "sub1 value")
message("in sub1 VAR_SUB1 = ${VAR_SUB1}")

#全局缓存变量

set(VAR_CACHE_SUB1 "VAR_CACHE_SUB1 value" CACHE STRING "sub1 doc")
message("== in sub1 VAR_CACHE_SUB1 = ${VAR_CACHE_SUB1}")
