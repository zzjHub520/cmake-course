cmake_minimum_required(VERSION 3.25)
project(demo2)

set(CMAKE_CXX_STANDARD 17)

add_executable(demo2 main.cpp)




set(deferred_message "Deferred Message 1")
set(re_evaluated [[${deferred_message}]])
cmake_language(EVAL CODE "
  cmake_language(DEFER CALL message [[${deferred_message}]])
")
message("Immediate Message")
set(deferred_message "Deferred Message 2")








