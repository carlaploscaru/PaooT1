# CMake version
cmake_minimum_required(VERSION 3.0)


# Project name

project(T11111)

# Define the search path for header files
include_directories(src)#ca sa nu trebuiasca sa scriu #include "../src/class.hpp>

# Specify the required C++ standard
if(CMAKE_VERSION GREATER "3.1.2") 
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
else()
    if(CMAKE_COMPILER_IS_GNUCXX)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
    endif()    
endif()    

# Define the executable
add_executable(${PROJECT_NAME} src/main.cpp
                    src/class.hpp)
               
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build")
#set(CMAKE_BUILD_TYPE Debug) to debu simbols