
cmake_minimum_required(VERSION 3.0)

# Define the target library
project(1booking)

set(SOURCES main.cpp
class.hpp)

add_executable(T44booking
    # main.cpp
    ${SOURCES}
)


# # Set the output directory for the executable
set_target_properties(T44booking
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../../build
)
