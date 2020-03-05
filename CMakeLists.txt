# Copyright (c) 2011-2020 The Khronos Group, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

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
