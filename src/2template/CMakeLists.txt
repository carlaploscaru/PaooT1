# Define the target library

cmake_minimum_required(VERSION 3.0)

# Project name
project(2template)

set(SOURCES template.hpp main2.cpp)
# add_library(2template_library
#     template.hpp
# )

# Specify the include directories for this library
# target_include_directories(2template_library
#     PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
# )
add_library(T44template
${SOURCES}
)
set_target_properties(T44template
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../../build
)