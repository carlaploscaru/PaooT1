# Define the target library

cmake_minimum_required(VERSION 3.0)

# Project name
project(2template)

set(SOURCES template.hpp main2.cpp)

add_library(T44template
${SOURCES}
)
set_target_properties(T44template
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../../build
)