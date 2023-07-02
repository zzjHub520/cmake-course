#[[
foreach(<loop_var> <items>)
  <commands>
endforeach()
]]
set(out "")
foreach (var RANGE 5)
    message("var = ${var}")
    string(APPEND out ${var} " ")
endforeach ()
message("out = ${out}")

set(out "")
foreach (var RANGE 1 3)
    message("var = ${var}")
    string(APPEND out ${var} " ")
endforeach ()
message("out = ${out}")

set(out "")
foreach (var RANGE 0 10 3)
    message("var = ${var}")
    string(APPEND out ${var} " ")
endforeach ()
message("out = ${out}")
