#xcpp/src/samples/CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
project(samples)
#获取当前目录下的所有子目录
file(GLOB dirs LIST_DIRECTORES true ${CMAKE_CURRENT_LIST_DIR}/* )
set(samps) # 存储所有的样例
foreach(dir IN LISTS dirs)
    if(EXISTS ${dir}/CMakeLists.txt)
        message("dir = ${dir}")
        list(APPEND samps ${dir})
    endif()
endforeach()

foreach(samp IN LISTS samps)
    add_subdirectory(${samp})
endforeach()



