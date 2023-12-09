cmake_minimum_required(VERSION 3.10)
project(GridNavigator-HDLC)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Include directories
include_directories(external/YAHDLC/C include)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(tests)