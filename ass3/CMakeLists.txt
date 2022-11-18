cmake_minimum_required(VERSION 3.16)
project(ass3)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_PREFIX_PATH}/include)
include_directories(include)
link_directories(${CMAKE_PREFIX_PATH}/lib)
add_executable(exec main.cpp)
