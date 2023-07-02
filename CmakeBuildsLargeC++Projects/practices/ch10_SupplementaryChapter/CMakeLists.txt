if ("${CMAKE_MINIMUM_REQUIRED_VERSION}" STREQUAL "")
    cmake_minimum_required(VERSION 3.25)
endif ()
project(ch10_SupplementaryChapter)

add_subdirectory(1002_Qt_SDK)
add_subdirectory(1003_Qt_dependency_lib_copy)
add_subdirectory(1004_Qt_resource_not_found_error)
add_subdirectory(1005_Qt_resource_ui_slot)
add_subdirectory(1006_x86_x64)
add_subdirectory(1007_Qt_install)
add_subdirectory(1008_cmake_autocopy_Qt_dependency_install)

