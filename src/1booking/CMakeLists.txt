
cmake_minimum_required(VERSION 3.0)

# Define the target library
project(1booking)

set(SOURCES main.cpp
class.hpp)
# add_library(1booking_library
#     main.cpp
#     class.hpp
# )

# # Specify the include directories for this library
# target_include_directories(1booking_library
#     PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
# )

# Optionally, if you have a main executable that uses this library
add_executable(T44booking
    # main.cpp
    ${SOURCES}
)

# # Link the executable with the 1booking library and 2template library
# target_link_libraries(T44
#     PRIVATE 1booking_library
#     PRIVATE 2template_library
# )

# # Set the output directory for the executable
set_target_properties(T44booking
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../../build
)
