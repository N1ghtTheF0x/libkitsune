cmake_minimum_required(VERSION 3.22)
include(CheckIncludeFileCXX)

project(LibKitsune)

string(TOLOWER ${PROJECT_NAME} LIB_NAME)

add_library(${LIB_NAME}
    source/string.cpp
    source/date.cpp
    source/logger.cpp
    source/array.cpp
)

target_include_directories(${LIB_NAME} PUBLIC include)