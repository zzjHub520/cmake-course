if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.22)
endif ()
project(blp_0609)

file(WRITE a.cpp "")
file(WRITE doc.html "")
install(FILES a.cpp DESTINATION src COMPONENT src)
install(FILES doc.html DESTINATION doc COMPONENT doc)

#[=[
cmake -S . -B build -DCMAKE_INSTALL_PREFIX=out
cd build
cmake -DCOMPONENT=src -P build/cmake_install.cmake
cmake -DCOMPONENT=doc -P build/cmake_install.cmake
]=]









