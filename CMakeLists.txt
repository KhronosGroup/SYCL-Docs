cmake_minimum_required(VERSION 3.13.0)

file(STRINGS "${CMAKE_CURRENT_LIST_DIR}/sycl_version.txt" sycl_version_strings NEWLINE_CONSUME)

foreach(version_var SYCLVERSION SYCLREVISION SYCLLANGVERSION OPENCLVERSION)
    string(REGEX REPLACE ".*${version_var}=([^\n]*)\n.*" "\\1" ${version_var} ${sycl_version_strings})
endforeach()

project(SYCL VERSION ${SYCLVERSION}.${SYCLREVISION} LANGUAGES NONE)


include("${CMAKE_BINARY_DIR}/conan_paths.cmake" OPTIONAL)
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
find_package(UseLATEX 2.4.9 REQUIRED)

add_subdirectory(latex)
