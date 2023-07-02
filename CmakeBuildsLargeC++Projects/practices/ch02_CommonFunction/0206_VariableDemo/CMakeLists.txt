project(blp_ch02_part06_VariableDemo)

set(VAR1 "测试变量VAR1的值")
message("VAR1=" ${VAR1})
message("VAR1 in string ${VAR1}")
message("\${VAR1}=${VAR1}")


set(VAR2 "VAR1")
message("VAR2=" ${VAR2})
message("VAR2=" ${${VAR2}})

unset(VAR1)
message("\${VAR1}=${VAR1}")








