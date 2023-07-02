
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

# 取出begin和end之间的内容 test cmake string
set(STR1 "  begin test cmake string end ")
# 查找的开头字符串
set(BSTR "begin")
# 在${STR1}中，${BSTR}的位置存入b
# cmake位置以0开始
string(FIND ${STR1} ${BSTR} b)
message("FIND ${BSTR} POS ${b}")

string(FIND ${STR1} "end" e)
message("FIND end POS ${e}")

# 去掉begin字符位置
# 获取字符长度
string(LENGTH ${BSTR} size)
math(EXPR b "${b} + ${size}")
message("b = ${b}")

# e等于开始到结束的长度
math(EXPR length "${e} - ${b}")
message("length = ${length}")

# 获取字符串 在${STR1}字符串 ${b}位置取${length}长度字符串写入substr
string(SUBSTRING ${STR1} ${b} ${length} substr)
message("substr = [${substr}]")
# 去掉头尾 空格 \t \n \r
string(STRIP ${substr} substr)
message("substr = [${substr}]")

# 转成大写
string(TOUPPER ${substr} substr)
message("substr = [${substr}]")
















