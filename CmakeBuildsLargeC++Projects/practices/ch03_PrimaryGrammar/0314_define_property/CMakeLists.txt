#[=[
set_property(<GLOBAL                      |
              DIRECTORY [<dir>]           |
              TARGET    [<target1> ...]   |
              SOURCE    [<src1> ...]
                        [DIRECTORY <dirs> ...]
                        [TARGET_DIRECTORY <targets> ...] |
              INSTALL   [<file1> ...]     |
              TEST      [<test1> ...]     |
              CACHE     [<entry1> ...]    >
             [APPEND] [APPEND_STRING]
             PROPERTY <name> [<value1> ...])

get_property(<variable>
             <GLOBAL             |
              DIRECTORY [<dir>]  |
              TARGET    <target> |
              SOURCE    <source>
                        [DIRECTORY <dir> | TARGET_DIRECTORY <target>] |
              INSTALL   <file>   |
              TEST      <test>   |
              CACHE     <entry>  |
              VARIABLE           >
             PROPERTY <name>
             [SET | DEFINED | BRIEF_DOCS | FULL_DOCS])

define_property(<GLOBAL | DIRECTORY | TARGET | SOURCE |
                 TEST | VARIABLE | CACHED_VARIABLE>
                 PROPERTY <name> [INHERITED]
                 [BRIEF_DOCS <brief-doc> [docs...]]
                 [FULL_DOCS <full-doc> [docs...]]
                 [INITIALIZE_FROM_VARIABLE <variable>])
]=]

# get_property SET | DEFINED
set_property(GLOBAL PROPERTY P1 "p1")
get_property(var GLOBAL PROPERTY P1 SET)
message("P1 SET = ${var}")
if (var)
    message("P1 is set")
else ()
    message("P1 not set")
endif ()

# 只有调用define_property之后才会为1
get_property(var GLOBAL PROPERTY P1 DEFINED)
message("P1 DEF = ${var}")
if (var)
    message("P1 is set")
else ()
    message("P1 not set")
endif ()

# 定义属性 不需要赋值
define_property(GLOBAL PROPERTY TEST_DEF BRIEF_DOCS "p1 brief docs")
get_property(var GLOBAL PROPERTY TEST_DEF DEFINED)
message("TEST_DEF DEFINE = ${var}")

# 获取属性概要说明 BRIEF_DOCS
get_property(var GLOBAL PROPERTY TEST_DEF BRIEF_DOCS)
message("TEST_DEF BRIEF_DOCS = ${var}")
















