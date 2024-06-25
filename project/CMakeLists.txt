# Minimum required version of CMake
cmake_minimum_required(VERSION 3.5)

# Project name
project(app)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SDL2 package
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Globbing for source files recursively
file(GLOB_RECURSE SOURCES 
    ${CMAKE_SOURCE_DIR}/src/*.cpp 
    ${CMAKE_SOURCE_DIR}/src/*/*.cpp
)

file(GLOB_RECURSE HEADERS 
    ${CMAKE_SOURCE_DIR}/src/*.hpp 
    ${CMAKE_SOURCE_DIR}/src/*/*.hpp
)

# Add the generated header directory to include directories
include_directories(${CMAKE_BINARY_DIR})

# Executable
add_executable(app ${SOURCES} ${HEADERS})

# Link SDL2 libraries
target_link_libraries(app ${SDL2_LIBRARIES})
