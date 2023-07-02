#[[
set(<variable> <value>... CACHE <type> <docstring> [FORCE])
    type
        BOOL
            ON/OFF 选择框
        FILEPATH
            文件选择
        PATH
            目录选择
        STRING
            字符串
        INTERNAL
            内部变量
    docstring
        变量说明
    FORCE
        强制修改缓存，不设置第二次调用值不改
]]

set(VAR_BOOL1 "ON" CACHE BOOL "VAR bool 001")
set(VAR_BOOL2 "OFF" CACHE BOOL "VAR bool 002")
message("VAR_BOOL1 = ${VAR_BOOL1}")
message("VAR_BOOL2 = ${VAR_BOOL2}")
#选择文件
set(VAR_FILE "" CACHE FILEPATH "var FILEPATH")
#选择文件夹
set(VAR_PATH "" CACHE PATH "var PATH")
# 内部缓存变量
set(VAR_INTERNAL "" CACHE INTERNAL "var INTERNAL")
