cmake_minimum_required(VERSION 3.10)

project(cfastcfurious)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(libs/googletest)
