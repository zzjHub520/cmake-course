set(VAR_OFF OFF)
if (NOT VAR_OFF)
    message("NOT VAR_OFF (true)")
endif ()

if (TRUE AND OFF)
    message("TRUE AND ON is true")
else ()
    message("TRUE AND ON is false")
endif ()

if (TRUE OR OFF)
    message("TRUE OR ON is true")
else ()
    message("TRUE OR ON is false")
endif ()

if (TRUE AND (OFF OR ON))
    message("TRUE AND (OFF OR ON) is true")
else ()
    message("TRUE AND (OFF OR ON) is false")
endif ()







