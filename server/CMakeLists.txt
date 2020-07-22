CMAKE_MINIMUM_REQUIRED(VERSION 3.16.3)

project(server)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14 -pthread")

set(src_dir "${PROJECT_SOURCE_DIR}/src/")
set(include_dir "${PROJECT_SOURCE_DIR}/include/")
set(libs_dir "${PROJECT_SOURCE_DIR}/libs/")

file(GLOB source_files "${src_dir}/*.cpp")
file(GLOB header_files "${src_dir}/*.h")

include_directories(${include_dir})

add_executable(server ${source_files} ${header_files})