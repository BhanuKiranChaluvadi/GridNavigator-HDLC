# Find Boost with unit_test_framework
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

# Enable CTest testing
enable_testing()

# Add an executable for grid navigation tests
add_executable(GridNavigationTests test_navigation.cpp)

# Link the executable with the Grid Navigation Library and Boost's Unit Test Framework
target_link_libraries(GridNavigationTests
    GridNavigationLib
    Boost::unit_test_framework
)

# Define BOOST_TEST_DYN_LINK to enable dynamic linking with Boost Test
target_compile_definitions(GridNavigationTests
    PRIVATE
        BOOST_TEST_DYN_LINK
)

# Add the executable as a test
add_test(NAME GridNavigationAllTests COMMAND GridNavigationTests)