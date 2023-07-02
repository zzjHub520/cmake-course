function(func_sub1)
    message("in sub1 func")
    math(EXPR sub1_var "${sub1_var} + 1")
    set(sub1_var ${sub1_var} PARENT_SCOPE)
endfunction()

func_sub1()
func_sub1()
message("sub sub1_var = ${sub1_var}")












