# Add the YAHDLC source files
set(YAHDLC_SOURCES
    ../external/YAHDLC/C/yahdlc.c
    ../external/YAHDLC/C/fcs16.c
)

# Add the YAHDLC header files
set(YAHDLC_HEADERS
    ../external/YAHDLC/C/yahdlc.h
    ../external/YAHDLC/C/fcs16.h
)

# Create a Static Library for YAHDLC
add_library(YAHDLC STATIC ${YAHDLC_SOURCES} ${YAHDLC_HEADERS})

# Create a library target for grid_navigation
add_library(GridNavigationLib STATIC grid_navigation.c yahdlc_decoder.c)

# Link YAHDLC Library with Grid Navigation Library
target_link_libraries(GridNavigationLib YAHDLC)

# Create Executable for the Project
add_executable(GridNavigate main.c)

# Link Grid Navigation Library with the Executable
target_link_libraries(GridNavigate GridNavigationLib)

