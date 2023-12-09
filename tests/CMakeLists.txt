# find a boost install with the libraries unit_test_framework
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

# enable CTest testing
enable_testing()

# Add a testing executable
add_executable(unit_tests test_navigation.cpp)

target_link_libraries(unit_tests
    grid_navigation_lib
    Boost::unit_test_framework
)

target_compile_definitions(unit_tests
    PRIVATE
        BOOST_TEST_DYN_LINK
)

add_test(test_all unit_tests)