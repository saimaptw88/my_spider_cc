cmake_minimum_required(VERSION 3.10)
project(RASPBERRY_PI)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wfatal-errors -Wundef")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_subdirectory(src)
