cmake_minimum_required(VERSION 3.16)

project(untitled)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

# Find the raylib package
find_package(raylib REQUIRED)

# Add the source files
add_executable(untitled main.c)

# Link raylib to the project
target_link_libraries(untitled raylib)

# Add the platform-specific dependencies for Unix systems
if(UNIX AND NOT APPLE)
    target_link_libraries(untitled m dl pthread)
endif()
