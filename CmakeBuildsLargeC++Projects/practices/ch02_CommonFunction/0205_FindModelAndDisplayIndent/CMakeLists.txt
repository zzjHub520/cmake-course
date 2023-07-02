project(blp_ch02_part05_FindModelAndDisplayIndent)

#2.5 message Reporting checks查找库日志
#[[
CHECK_START 开始记录将要执行检查的消息
CHECK_PASS 记录检查的成功结果
CHECK_FAIL 记录不成功的检查结果
]]
message("=======================2.5=============================")
#开始查找
message(CHECK_START "查找xcpp")
#查找库xcpp的代码
# message消息缩进
set(CMAKE_MESSAGE_INDENT "--")

#嵌套查找
message(CHECK_START "查找xlog")
#查找xlog代码
message(CHECK_PASS "成功")

message(CHECK_START "查找xthreadpool")
message(CHECK_FAIL "失败")

#取消缩进
set(CMAKE_MESSAGE_INDENT "")
#结束查找 查找失败
message(CHECK_FAIL "失败")
