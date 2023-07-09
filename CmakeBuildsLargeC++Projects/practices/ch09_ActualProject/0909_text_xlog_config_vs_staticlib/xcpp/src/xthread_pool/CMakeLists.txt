if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.22)
endif ()
project(xthread_pool)

include(${CMAKE_CURRENT_LIST_DIR}/../../cmake/common.cmake)
cpp_library(${PROJECT_NAME})

# windows
# Remove-Item -Path "build" -Recurse -Force; Remove-Item -Path "out" -Recurse -Force; cmake -S . -B build -DCMAKE_INSTALL_PREFIX=out; cmake --build build; cmake --install build --config Debug