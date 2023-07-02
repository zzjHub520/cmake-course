set(var 1)

while (var)
    math(EXPR var "${var} + 1")
    math(EXPR re "${var} % 10")
    if (re)
        continue()
    endif ()

    message(${var})
    if (var GREATER 100)
        set(var 0) # break()
    endif ()
endwhile ()













