set(exp "(3*10) + 5")
math(EXPR out ${exp})
message("${exp} = ${out}") # (3*10) + 5 = 35
math(EXPR out ${exp} OUTPUT_FORMAT DECIMAL) # 十进制
message("${exp} = ${out}") # (3*10) + 5 = 35
math(EXPR out ${exp} OUTPUT_FORMAT HEXADECIMAL) # 十六进制 0x
message("${exp} = ${out}") # (3*10) + 5 = 0X23


