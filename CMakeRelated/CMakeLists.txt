set(json_array [=[
[
  "aa",
  "bb",
  {
    "o1": "v1",
    "o2": "v2"
  },
  "cc",
  [
    "v1",
    "v2"
  ]
]
]=])

set(json_object [=[
{
  "webs": {
    "name": "cmake",
    "usrl": "cmake.org.cn"
  },
  "aa": "AAAAA",
  "bb": "BBBBB",
  "cc": 123,
  "dd": [
    "a1",
    "a2"
  ]
}
]=])

#include(${CMAKE_SOURCE_DIR}/cmake/json_put.cmake)
#json_put(tt ${json_object} "aa" "[\"value\"]")
#
#
#message("${tt}")







