# option的变量是缓存变量
option(OPT1 "opt1 doc" OFF)
message("OPT1 = ${OPT1}")

option(OPT1 "opt1 doc" ON)
message("OPT1 = ${OPT1}")
