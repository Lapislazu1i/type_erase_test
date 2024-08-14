cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(hdemo)

include_directories("include")

add_library(hlib SHARED 
"lib/lib.cpp"
)

add_executable(hbin
"bin/main.cpp"
)

target_link_libraries(hbin PRIVATE hlib)