# 505cmake_component/CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
project(cmake_component)
FILE(WRITE "a.cpp" "")
FILE(WRITE "doc.html" "")

install(FILES a.cpp 
DESTINATION src COMPONENT src
)

install(FILES doc.html 
DESTINATION doc COMPONENT doc
)
#  cmake -S . -B build -DCMAKE_INSTALL_PREFIX=out
#  cd build
#  cmake -DCOMPONENT=src -P cmake_install.cmake
# -- Install component: "doc"
#  cmake -DCOMPONENT=doc -P cmake_install.cmake