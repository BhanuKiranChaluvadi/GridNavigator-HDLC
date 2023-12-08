cmake_minimum_required(VERSION 3.10)
project(GridNavigator-HDLC)

# Include directories for YAHDLC
include_directories(external/YAHDLC/C)

# Add the YAHDLC source files
set(YAHDLC_SOURCES
    external/YAHDLC/C/yahdlc.c
    external/YAHDLC/C/fcs16.c
)

# Add the YAHDLC header files
set(YAHDLC_HEADERS
    external/YAHDLC/C/yahdlc.h
    external/YAHDLC/C/fcs16.h
)

# Create a library from YAHDLC sources
add_library(HDLC_Lib STATIC ${YAHDLC_SOURCES} ${YAHDLC_HEADERS})

# Add the source files of your project
add_executable(GridNavigator-HDLC
    main.cpp
    # Add other source files of your project here
)

# Link HDLC_Lib with your executable
target_link_libraries(GridNavigator-HDLC HDLC_Lib)
