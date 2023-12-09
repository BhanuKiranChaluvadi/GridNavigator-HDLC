#ifndef GRID_NAVIGATION_H
#define GRID_NAVIGATION_H

#define GRID_SIZE 5

// Declare the character's starting position
extern int characterPosition[2];

// Function declarations
int isValidMove(int *x, int *y, int direction);
void moveCharacter(int *x, int *y, int direction);

#endif // GAME_LOGIC_H
