if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.22)
endif ()
project(blp_0607)

file(WRITE doc/index.html "")
file(WRITE doc/doc.html "")
file(WRITE doc/doc2.htm "")
file(WRITE doc/doc.cc "")
file(WRITE doc/doc.c "")
file(WRITE doc/sub/doc.html "")
file(WRITE doc/include/doc.h "")
file(WRITE doc/.svn/config "")
file(WRITE doc/.git/config "")

# DOC 类型指定安装路径 share/doc
# 安装doc目录下所有文件，包含子目录，空子目录也创建
install(DIRECTORY doc TYPE DOC)
install(DIRECTORY doc DESTINATION doc2)

install(DIRECTORY doc DESTINATION html_doc
        FILES_MATCHING
        PATTERN "*.html"
        PATTERN "*.htm"
        )

# 排除.git和.svn目录
install(DIRECTORY doc DESTINATION no_git_doc
        PATTERN ".git" EXCLUDE
        PATTERN ".svn" EXCLUDE
        )


# 排除.git和.svn目录
install(DIRECTORY doc DESTINATION src
        FILES_MATCHING
        PATTERN "*.cc"
        PATTERN "*.c"
        PATTERN ".git" EXCLUDE
        PATTERN ".svn" EXCLUDE
        )





