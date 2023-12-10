#include "grid_navigation.h"

int isValidMove(const Position *position, Direction direction)
{
    switch (direction)
    {
    case UP:
        return position->y > 0;
    case DOWN:
        return position->y < GRID_SIZE - 1;
    case RIGHT:
        return position->x < GRID_SIZE - 1;
    case LEFT:
        return position->x > 0;
    }
    return 0;
}

void moveCharacter(Position *position, Direction direction)
{
    if (!isValidMove(position, direction))
        return;
    switch (direction)
    {
    case UP:
        position->y -= 1;
        break;
    case DOWN:
        position->y += 1;
        break;
    case RIGHT:
        position->x += 1;
        break;
    case LEFT:
        position->x -= 1;
        break;
    }
}
