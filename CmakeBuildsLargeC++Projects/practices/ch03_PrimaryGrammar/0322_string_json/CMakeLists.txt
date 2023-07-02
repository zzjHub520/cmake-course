#[=[
JSON
  string(JSON <out-var> [ERROR_VARIABLE <error-var>]
         {GET | TYPE | LENGTH | REMOVE}
         <json-string> <member|index> [<member|index> ...])
  string(JSON <out-var> [ERROR_VARIABLE <error-var>]
         MEMBER <json-string>
         [<member|index> ...] <index>)
  string(JSON <out-var> [ERROR_VARIABLE <error-var>]
         SET <json-string>
         <member|index> [<member|index> ...] <value>)
  string(JSON <out-var> [ERROR_VARIABLE <error-var>]
         EQUAL <json-string1> <json-string2>)
]=]

# 测试用json
# json 对象{} json数组[]
# 格式 key：value
set(tjson
[=[
{
  "webs": {
    "web": [
      {
        "name": "cmake",
        "url": "cmake.org.cn"
      },{
        "name": "ffmpeg",
        "url": "ffmpeg.club"
      }

    ]
  }
}
]=])

message("${tjson}")

#[[
  string(JSON <out-var> [ERROR_VARIABLE <error-var>]
         {GET | TYPE | LENGTH | REMOVE}
         <json-string> <member|index> [<member|index> ...])
]]
# 访问webs->web[0]->name
string(JSON var ERROR_VARIABLE evar GET ${tjson} webs web 0 name)
message("webs web 0 name = ${var}")
message("evar = ${evar}")

string(JSON var ERROR_VARIABLE evar GET ${tjson} webs web 1 url)
message("webs web 0 url = ${var}")
if (${evar})
    message("evar = ${evar}")
endif ()

string(JSON var ERROR_VARIABLE evar GET ${tjson} webs web2 1 url)
if (${var})
    message("webs web 0 url = ${var}")
else ()
    message("NOTFOUND")
endif ()
message("evar = ${evar}")

# 读取json数组长度
string(JSON web_count ERROR_VARIABLE evar LENGTH ${tjson} webs web)
message("JSON LENGTH = ${web_count}")

#json的增加和修改
#[=[
  string(JSON <out-var> [ERROR_VARIABLE <error-var>]
         SET <json-string>
         <member|index> [<member|index> ...] <value>)
  value 必须是json
]=]
# json 的增加
string(JSON set_out SET ${tjson} webs web 2 [=[
{
    "name": "cpp",
    "url": "cppds.com"
}
]=])
message("set_out = ${set_out}")

# json 的修改
string(JSON set_out2 SET ${tjson} webs web 1 [=[
{
    "name": "ffmpeg2",
    "url": "ffmpeg.club"
}
]=])
message("set_out2 = ${set_out2}")

# json 删除
#[[
  string(JSON <out-var> [ERROR_VARIABLE <error-var>]
         {GET | TYPE | LENGTH | REMOVE}
         <json-string> <member|index> [<member|index> ...])
]]
string(JSON remove_out REMOVE ${set_out2} webs web 1)
string(JSON remove_out REMOVE ${remove_out} webs web 0)
message("remove_out = ${remove_out}")
