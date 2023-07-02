if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.22)
endif ()
project(blp_0606)

file(WRITE a.h "")
file(WRITE b.h "")
file(WRITE c.h "")
# 文件安装到指定目录
install(FILES a.h b.h DESTINATION include)

# 目标可选 OPTIONAL 目标不存在不出错
install(FILES c.h DESTINATION inc OPTIONAL)

# 文件类型 TYPE DOC LIB INCLUDE
include(GNUInstallDirs)
message("CMAKE_INSTALL_DATAROOTDIR = ${CMAKE_INSTALL_DATAROOTDIR}")
install(FILES a.h TYPE DOC)     # <DATAROOT dir>/doc
install(FILES b.h TYPE LIB)     # lib
install(FILES c.h TYPE INCLUDE) # include

# 文件权限 Windows目录无效
# 默认权限 OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
install(FILES a.h DESTINATION pub
        PERMISSIONS
        OWNER_READ OWNER_WRITE OWNER_EXECUTE
        GROUP_READ GROUP_WRITE GROUP_EXECUTE
        WORLD_READ WORLD_WRITE WORLD_EXECUTE
        )




