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

# 设置缓存变量 字符串类型
set(VAR1 "CACHE VAR1 VALUE1-1" CACHE STRING "cache doc")
# 缓存变量第二次修改不生效
set(VAR1 "CACHE VAR1 VALUE1-2" CACHE STRING "cache doc")
message("VAR1 = ${VAR1}")

# 强制修改缓存
set(VAR1 "CACHE VAR1 VALUE1-3 FORCE" CACHE STRING "cache doc" FORCE)
message("VAR1 = ${VAR1}")

