cmake_minimum_required(VERSION 3.16.3)

project(training)

# Compile options
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_CXX_FLAGS "-fno-asm -std=c++11 -Wall -stdlib=libstdc++")
set(CMAKE_CXX_FLAGS_DEBUG "-g -Og")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Show message
message("Environment:Archlinux; clang version 12.0.0")
if(${CMAKE_BUILD_TYPE} STREQUAL DEBUG)
    message("Optional:-fno-asm -std=c++11 -Wall -stdlib=libstdc++ -g -Og, Type:Debug")
else(${CMAKE_BUILD_TYPE} STREQUAL RELEASE)
    message("Optional:-fno-asm -std=c++11 -Wall -stdlib=libstdc++ -O2, Type:Release")
endif(${CMAKE_BUILD_TYPE} STREQUAL DEBUG)