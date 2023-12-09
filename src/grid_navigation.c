#include "grid_navigation.h"

// Define the character's starting position
int characterPosition[2] = {0, 4}; // [row, col]

// Function to check if a move is valid
int isValidMove(int *x, int *y, int direction) {
    switch (direction) {
        case 1: // Up ↑
            if (*y < GRID_SIZE - 1) return 1;
            break;
        case 2: // Down ↓
            if (*y > 0) return 1;
            break;
        case 3: // Right →
            if (*x < GRID_SIZE - 1) return 1;
            break;
        case 4: // Left ←
            if (*x > 0) return 1;
            break;
    }
    return 0;
}

// Function to move the character on the grid
void moveCharacter(int *x, int *y, int direction) {
    switch (direction) {
        case 1: // Up ↑
            if (*y < GRID_SIZE - 1) *y += 1;
            break;
        case 2: // Down ↓
            if (*y > 0) *y -= 1;
            break;
        case 3: // Right →
            if (*x < GRID_SIZE - 1) *x += 1;
            break;
        case 4: // Left ←
            if (*x > 0) *x -= 1;
            break;
    }
}
