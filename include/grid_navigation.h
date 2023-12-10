#ifndef GRID_NAVIGATION_H
#define GRID_NAVIGATION_H

#define GRID_SIZE 5

typedef enum
{
    UP = 1,
    DOWN = 2,
    RIGHT = 3,
    LEFT = 4
} Direction;

typedef struct
{
    int x;
    int y;
} Position;

int isValidMove(const Position *position, Direction direction);
void moveCharacter(Position *position, Direction direction);

#endif // GRID_NAVIGATION_H
