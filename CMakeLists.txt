cmake_minimum_required(VERSION 3.22)
include(CheckIncludeFileCXX)

project(LibKitsune)

check_include_file_cxx(string HAS_STRING)
check_include_file_cxx(sstream HAS_SSTREAM)
check_include_file_cxx(thread HAS_THREAD)

option(LIBKITSUNE_EXAMPLE "Compile Example")

string(TOLOWER ${PROJECT_NAME} LIB_NAME)

add_library(${LIB_NAME}
    source/number.cpp
    source/string.cpp
    source/memory.cpp
    source/error.cpp
    source/threads.cpp
)

target_include_directories(${LIB_NAME} PUBLIC include)
target_compile_definitions(${LIB_NAME} PRIVATE
    HAS_STRING=${HAS_STRING}
    HAS_SSTREAM=${HAS_SSTREAM}
    HAS_THREAD=${HAS_THREAD}
)

set(LIBKITSUNE_EXAMPLE ON)
if(LIBKITSUNE_EXAMPLE)
    add_executable(example example/example.cpp)
    target_include_directories(example PUBLIC include)
    target_link_libraries(example PRIVATE ${LIB_NAME})
endif()