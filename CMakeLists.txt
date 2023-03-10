# @file CMakeLists.txt
# 
# CMake files for the Random Number Generator program

cmake_minimum_required(VERSION 3.25)

# project info
project(RandomNumberGenerator)

# C++17
set(CMAKE_CXX_STANDARD 17)

# Turn on warnings
if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # standard warnings
    add_compile_options(-Wall)
endif()

# Rainfall program
add_executable(Random-Number-Generator main.cpp)

# run command
add_custom_target(run $<TARGET_FILE:Random-Number-Generator> < ${CMAKE_SOURCE_DIR})

# check command - use diff to check output
find_program(DIFF diff)
find_package(Git QUIET)
if (NOT DIFF STREQUAL "DIFF-NOTFOUND")
    message(STATUS "Check output uses diff: ${DIFF}")
    add_custom_target(check 
        COMMAND $<TARGET_FILE:Random-Number-Generator> < ${CMAKE_SOURCE_DIR}/demo.csv | ${DIFF} ${CMAKE_SOURCE_DIR}/
    )
elseif(GIT_FOUND)
    message(STATUS "Check output uses git diff: ${GIT}")
    add_custom_target(check 
        COMMAND $<TARGET_FILE:Random-Number-Generator> < ${CMAKE_SOURCE_DIR} | ${GIT_EXECUTABLE} diff --no-index ${CMAKE_SOURCE_DIR}/
    )
else()
    message(STATUS "Check output is not implemented due to missing diff utilities")
endif()
