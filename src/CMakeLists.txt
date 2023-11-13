# CMake version
cmake_minimum_required(VERSION 3.0)
project(src1)
# # Add the source files to the project
# add_executable(T333 main.cpp)

# # Set the output directory for the executable
# set_target_properties(T333 PROPERTIES
#     RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../build
# )

   
# Specify the required C++ standard
# if(CMAKE_VERSION GREATER "3.1.2") 
#     set(CMAKE_CXX_STANDARD 14)
#     set(CMAKE_CXX_STANDARD_REQUIRED ON)
#     set(CMAKE_CXX_EXTENSIONS OFF)
# else()
#     if(CMAKE_COMPILER_IS_GNUCXX)
#         set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
#     endif()    
# endif()    

add_subdirectory(1booking)
add_subdirectory(2template)
add_subdirectory(3dir)






