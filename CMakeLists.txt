cmake_minimum_required(VERSION 3.10)

project(cfastcfurious)

file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/lib/src/*.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/inc)

target_compile_options(${PROJECT_NAME}
    PRIVATE
    -g -Wall)
