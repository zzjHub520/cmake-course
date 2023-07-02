#[=[
Search and Replace
  string(FIND <string> <substring> <out-var> [...])
  string(REPLACE <match-string> <replace-string> <out-var> <input>...)
  string(REGEX MATCH <match-regex> <out-var> <input>...)
  string(REGEX MATCHALL <match-regex> <out-var> <input>...)
  string(REGEX REPLACE <match-regex> <replace-expr> <out-var> <input>...)

Manipulation
  string(APPEND <string-var> [<input>...])
  string(PREPEND <string-var> [<input>...])
  string(CONCAT <out-var> [<input>...])
  string(JOIN <glue> <out-var> [<input>...])
  string(TOLOWER <string> <out-var>)
  string(TOUPPER <string> <out-var>)
  string(LENGTH <string> <out-var>)
  string(SUBSTRING <string> <begin> <length> <out-var>)
  string(STRIP <string> <out-var>)
  string(GENEX_STRIP <string> <out-var>)
  string(REPEAT <string> <count> <out-var>)
]=]

set(substr "test cmake string")
# 字符串追加
string(APPEND substr " append01 " "append02 ")
message("substr = [${substr}]")

# 字符串替换
# string(REPLACE <math-string> <replace-string> <out-var> <input> ...)
string(REPLACE "append" "REPLACE" substr ${substr})
message("substr = [${substr}]")

# 正则表达式
string(REGEX MATCH "[A-Z]+[0-9]+" output ${substr})
message("REGEX MATCH output = [${output}]")























