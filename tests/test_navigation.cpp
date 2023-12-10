#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE gridnavigator
#include <boost/test/unit_test.hpp>
extern "C"
{
#include "grid_navigation.h"
}

BOOST_AUTO_TEST_CASE(isValidMoveTest)
{
    Position position = {2, 2}; // Starting position (x, y)

    // Test valid moves
    BOOST_CHECK_EQUAL(isValidMove(&position, UP), 1);    // Up ↑
    BOOST_CHECK_EQUAL(isValidMove(&position, DOWN), 1);  // Down ↓
    BOOST_CHECK_EQUAL(isValidMove(&position, RIGHT), 1); // Right →
    BOOST_CHECK_EQUAL(isValidMove(&position, LEFT), 1);  // Left ←

    // Test invalid moves
    position.x = 0;
    position.y = 0;
    BOOST_CHECK_EQUAL(isValidMove(&position, UP), 0);    // Up ↑ (out of bounds)
    BOOST_CHECK_EQUAL(isValidMove(&position, LEFT), 0);  // Left ← (out of bounds)

    position.x = GRID_SIZE - 1;
    position.y = GRID_SIZE - 1;
    BOOST_CHECK_EQUAL(isValidMove(&position, DOWN), 0);  // Down ↓ (out of bounds)
    BOOST_CHECK_EQUAL(isValidMove(&position, RIGHT), 0); // Right → (out of bounds)

    position.x = 0;
    position.y = GRID_SIZE - 1;
    BOOST_CHECK_EQUAL(isValidMove(&position, DOWN), 0);  // Down ↓ (out of bounds)
    BOOST_CHECK_EQUAL(isValidMove(&position, LEFT), 0);  // Left ← (out of bounds)

    position.x = GRID_SIZE - 1;
    position.y = 0;
    BOOST_CHECK_EQUAL(isValidMove(&position, UP), 0);    // Up ↑ (out of bounds)
    BOOST_CHECK_EQUAL(isValidMove(&position, RIGHT), 0); // Right → (out of bounds)
}

BOOST_AUTO_TEST_CASE(moveCharacterTest)
{
    Position position = {2, 2}; // Starting position (x, y)

    // Test valid moves
    moveCharacter(&position, UP);    // Up ↑
    BOOST_CHECK_EQUAL(position.x, 2);
    BOOST_CHECK_EQUAL(position.y, 1);

    moveCharacter(&position, DOWN);  // Down ↓
    BOOST_CHECK_EQUAL(position.x, 2);
    BOOST_CHECK_EQUAL(position.y, 2);

    moveCharacter(&position, RIGHT); // Right →
    BOOST_CHECK_EQUAL(position.x, 3);
    BOOST_CHECK_EQUAL(position.y, 2);

    moveCharacter(&position, LEFT);  // Left ←
    BOOST_CHECK_EQUAL(position.x, 2);
    BOOST_CHECK_EQUAL(position.y, 2);

    // Test invalid moves
    position.x = 0;
    position.y = 0;
    moveCharacter(&position, UP);    // Up ↑ (out of bounds)
    BOOST_CHECK_EQUAL(position.x, 0);
    BOOST_CHECK_EQUAL(position.y, 0);

    moveCharacter(&position, LEFT);  // Left ← (out of bounds)
    BOOST_CHECK_EQUAL(position.x, 0);
    BOOST_CHECK_EQUAL(position.y, 0);

    position.x = GRID_SIZE - 1;
    position.y = GRID_SIZE - 1;
    moveCharacter(&position, DOWN);  // Down ↓ (out of bounds)
    BOOST_CHECK_EQUAL(position.x, GRID_SIZE - 1);
    BOOST_CHECK_EQUAL(position.y, GRID_SIZE - 1);

    moveCharacter(&position, RIGHT); // Right → (out of bounds)
    BOOST_CHECK_EQUAL(position.x, GRID_SIZE - 1);
    BOOST_CHECK_EQUAL(position.y, GRID_SIZE - 1);
}
