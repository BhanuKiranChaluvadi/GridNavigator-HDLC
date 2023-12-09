#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE gridnavigator
#include <boost/test/unit_test.hpp>
extern "C" {
    #include "grid_navigation.h"
}

#define GRID_SIZE 5

BOOST_AUTO_TEST_CASE(nothingTest) {
    BOOST_CHECK(true); // This is a placeholder test case. You can replace it with your own test.
}

BOOST_AUTO_TEST_CASE(isValidMoveTest) {
    int x = 2;
    int y = 2;

    // Test valid moves
    BOOST_CHECK_EQUAL(isValidMove(&x, &y, 1), 1); // Up ↑
    BOOST_CHECK_EQUAL(isValidMove(&x, &y, 2), 1); // Down ↓
    BOOST_CHECK_EQUAL(isValidMove(&x, &y, 3), 1); // Right →
    BOOST_CHECK_EQUAL(isValidMove(&x, &y, 4), 1); // Left ←

    // Test invalid moves
    x = 0;
    y = 0;
    BOOST_CHECK_EQUAL(isValidMove(&x, &y, 1), 0); // Up ↑ (out of bounds)
    BOOST_CHECK_EQUAL(isValidMove(&x, &y, 4), 0); // Left ← (out of bounds)

    x = GRID_SIZE - 1;
    y = GRID_SIZE - 1;
    BOOST_CHECK_EQUAL(isValidMove(&x, &y, 2), 0); // Down ↓ (out of bounds)
    BOOST_CHECK_EQUAL(isValidMove(&x, &y, 3), 0); // Right → (out of bounds)
}