#include "grid_navigation.h"

// Function to check if a move is valid
int isValidMove(const Position *position, int direction)
{
    switch (direction)
    {
    case 1: // Up ↑
        return position->y > 0;
    case 2: // Down ↓
        return position->y < GRID_SIZE - 1;
    case 3: // Right →
        return position->x < GRID_SIZE - 1;
    case 4: // Left ←
        return position->x > 0;
    }
    return 0;
}

// Function to move the character on the grid
void moveCharacter(Position *position, int direction)
{
    if (!isValidMove(position, direction))
        return;

    switch (direction)
    {
    case 1: // Up ↑
        position->y -= 1;
        break;
    case 2: // Down ↓
        position->y += 1;
        break;
    case 3: // Right →
        position->x += 1;
        break;
    case 4: // Left ←
        position->x -= 1;
        break;
    }
}