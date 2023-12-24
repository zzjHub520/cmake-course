function(json_value out_value input)
    string(STRIP ${input} input_STRIP)
    if ("${input_STRIP}" STREQUAL "")
        set(${out_value} "\"${input}\"" PARENT_SCOPE)
        return()
    endif ()
    string(REGEX MATCH "^." initials ${input_STRIP})

    if (("${initials}" STREQUAL "[") OR ("${initials}" STREQUAL "{"))
        set(${out_value} "${input}" PARENT_SCOPE)
    else ()
        set(${out_value} "\"${input}\"" PARENT_SCOPE)
    endif ()
endfunction()

function(json_put out_json input_json member_index value)
    string(STRIP ${input_json} input_json_STRIP)
    string(REGEX MATCH "^." initials ${input_json_STRIP})

    string(JSON len LENGTH ${input_json})
    if ("${len}" EQUAL 0) # json为空
        if ("${initials}" STREQUAL "{")
            json_value(member_index "${member_index}")
            json_value(value "${value}")
            set(${out_json} "{\n  ${member_index}: ${value}\n}" PARENT_SCOPE)
        else ()
            json_value(value "${value}")
            set(${out_json} "[\n  ${value}\n]" PARENT_SCOPE)
        endif ()
        return()
    endif ()

    math(EXPR len "${len} - 1")
    set(out "")

    if ("${initials}" STREQUAL "[") # json 数组
        # 分解json数组
        foreach (i RANGE ${len})
            string(JSON ele_${i} GET "${input_json}" "${i}")
        endforeach ()

        # 再次组装json数组主体
        foreach (i RANGE ${len})
            # 插入json元素
            if ("${member_index}" STREQUAL "${i}")
                json_value(value "${value}")
                string(APPEND out "  ${value},\n")
                set(flag "TRUE")
            endif ()

            # 插入原有的元素
            json_value(ele_${i} "${ele_${i}}")
            string(APPEND out "  ${ele_${i}},\n")
        endforeach ()

        # 追加json元素
        if (NOT flag)
            json_value(value "${value}")
            string(APPEND out "  ${value},\n")
        endif ()

        # 组装成json数组
        string(REGEX REPLACE ",\n$" "" out ${out})
        string(PREPEND out "[\n")
        string(APPEND out "\n]")
    elseif ("${initials}" STREQUAL "{") # json 对象
        # 分解json对象
        foreach (i RANGE ${len})
            string(JSON key_${i} MEMBER "${input_json}" "${i}")
            string(JSON value_${i} GET "${input_json}" "${key_${i}}")
        endforeach ()

        # 再次json对象主体
        foreach (i RANGE ${len})
            # 修改对应的键的值
            if ("${key_${i}}" STREQUAL "${member_index}")
                set(value_${i} "${value}")
                set(flag "TRUE")
            endif ()

            # 插入原有字段
            json_value(key_${i} "${key_${i}}")
            json_value(value_${i} "${value_${i}}")
            string(APPEND out "  ${key_${i}}: ${value_${i}},\n")
        endforeach ()

        # 追加json字段
        if (NOT flag)
            json_value(member_index "${member_index}")
            json_value(value "${value}")
            string(APPEND out "  ${member_index}: ${value},\n")
        endif ()

        string(REGEX REPLACE ",\n$" "" out "${out}")
        string(PREPEND out "{\n")
        string(APPEND out "\n}")
    else ()
        message(FATAL_ERROR "json_put function <input_json> is unknown")
    endif ()
    set(${out_json} "${out}" PARENT_SCOPE)
endfunction()
