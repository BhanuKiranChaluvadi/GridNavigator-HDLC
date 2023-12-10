#ifndef GRID_NAVIGATION_H
#define GRID_NAVIGATION_H

#define GRID_SIZE 5

typedef struct
{
    int x;
    int y;
} Position;

// Function declarations
int isValidMove(const Position *position, int direction);
void moveCharacter(Position *position, int direction);

#endif // GRID_NAVIGATION_H
