CMAKE_MINIMUM_REQUIRED(VERSION 3.16.3)

project(client)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14 -pthread")

set(src_dir "${PROJECT_SOURCE_DIR}/src/")
set(include_dir "${PROJECT_SOURCE_DIR}/include/")
set(libs_dir "${PROJECT_SOURCE_DIR}/libs/")

file(GLOB source_files "${src_dir}/*.cpp")
file(GLOB header_files "${src_dir}/*.h")

add_subdirectory(${libs_dir}/socket-wrapper-1.0.7)

include_directories(${include_dir} ${libs_dir}/socket-wrapper-1.0.7/include/)

add_executable(client ${source_files} ${header_files})
target_link_libraries(client socket-wrapper)
add_dependencies(client socket-wrapper)