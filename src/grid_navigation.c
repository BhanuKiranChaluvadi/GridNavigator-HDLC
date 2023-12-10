#include "grid_navigation.h"


// Function to check if a move is valid
int isValidMove(int *x, int *y, int direction)
{
    switch (direction)
    {
    case 1: // Up ↑
        if (*y > 0)
            return 1;
        break;
    case 2: // Down ↓
        if (*y < GRID_SIZE - 1)
            return 1;
        break;
    case 3: // Right →
        if (*x < GRID_SIZE - 1)
            return 1;
        break;
    case 4: // Left ←
        if (*x > 0)
            return 1;
        break;
    }
    return 0;
}

// Function to move the character on the grid
void moveCharacter(int *x, int *y, int direction)
{
    if (!isValidMove(x, y, direction))
        return;

    switch (direction)
    {
    case 1: // Up ↑
        *y -= 1;
        break;
    case 2: // Down ↓
        *y += 1;
        break;
    case 3: // Right →
        *x += 1;
        break;
    case 4: // Left ←
        *x -= 1;
        break;
    }
}