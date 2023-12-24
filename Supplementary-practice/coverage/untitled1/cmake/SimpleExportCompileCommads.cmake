set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (NOT MSVC)
    if (EXISTS "${CMAKE_BINARY_DIR}/compile_commands.json")
        include(${CMAKE_SOURCE_DIR}/cmake/json_put.cmake)

        file(READ "${CMAKE_BINARY_DIR}/compile_commands.json" jsonCommands)

        string(JSON len LENGTH "${jsonCommands}")
        math(EXPR len "${len} - 1")

        foreach (i RANGE ${len})
            string(JSON ele GET "${jsonCommands}" "${i}")
            string(JSON jsonCommands REMOVE "${jsonCommands}" "${i}")

            string(JSON command_value GET "${ele}" "command")
            string(JSON file_value GET "${ele}" "file")
            string(JSON ele REMOVE "${ele}" "command")
            string(JSON ele REMOVE "${ele}" "file")

            string(REPLACE "\\" "/" command_value "${command_value}")
            string(REPLACE "\\" "/" file_value "${file_value}")

            string(REPLACE " -" ";-" command_value "${command_value}")
            string(REPLACE "\"" "" command_value "${command_value}")
            list(TRANSFORM command_value PREPEND "\"")
            list(TRANSFORM command_value APPEND "\"")
            string(REPLACE ";" "," command_value "${command_value}")
            string(PREPEND command_value "[")
            string(APPEND command_value "]")
            json_put(ele "${ele}" "command" "${command_value}")
            json_put(ele "${ele}" "file" "${file_value}")

            json_put(jsonCommands "${jsonCommands}" "${i}" "${ele}")
        endforeach ()

        file(WRITE "${CMAKE_BINARY_DIR}/SimpleExportCompileCommads.json" "${jsonCommands}")
    else ()
        if (CMAKE_EXPORT_COMPILE_COMMANDS)
            message(WARNING [[CMAKE_EXPORT_COMPILE_COMMANDS = ON, The file SimpleExportCompileCommads.json will only be generated when cmake generated again.]])
        else ()
            message(WARNING [[CMAKE_EXPORT_COMPILE_COMMANDS = OFF, The file SimpleExportCompileCommads.json will only be generated when CMAKE_EXPORT_COMPILE_COMMANDS is ON.]])
        endif ()
    endif ()
endif ()


















