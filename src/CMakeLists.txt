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

# Create a library from YAHDLC sources
add_library(yahdlc_lib STATIC ${YAHDLC_SOURCES} ${YAHDLC_HEADERS})

# Create a library target for grid_navigation
add_library(grid_navigation_lib grid_navigation.c yahdlc_decoder.c)

target_link_libraries(grid_navigation_lib yahdlc_lib)

# Create an executable target for project
add_executable(grid_navigation_yahdlc main.c)

# Link the library with your executable
target_link_libraries(grid_navigation_yahdlc grid_navigation_lib)
