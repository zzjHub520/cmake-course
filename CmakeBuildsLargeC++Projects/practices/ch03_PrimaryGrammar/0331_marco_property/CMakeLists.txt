macro(my_parse)
    message("ARGN = ${ARGN}")
    cmake_parse_arguments(
            "MY"  # 前缀
            "LOG;FILE"  # option
            "BIN;LIB"  # 单值
            "TARGETS"  # 多值
            ${ARGN}  # 参数数组
    )
    message("MY_LOG = ${MY_LOG}")
    message("MY_FILE = ${MY_FILE}")
    message("MY_BIN = ${MY_BIN}")
    message("MY_TARGETS = ${MY_TARGETS}")
    # 参数类型传递错误
    message("MY_UNPARSED_ARGUMENTS = ${MY_UNPARSED_ARGUMENTS}")
    message("MY_KEYWORDS_MISSING_VALUES = ${MY_KEYWORDS_MISSING_VALUES}")

endmacro()

my_parse(
        LOG "mylog"
        BIN ../../bin
        TARGETS "tar1" "tar2"
        LIB
)