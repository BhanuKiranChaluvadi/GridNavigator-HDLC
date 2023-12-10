#include <stdio.h>
#include <stdlib.h>
#include "yahdlc.h"
#include "grid_navigation.h"

// Define the character's starting position
int characterPosition[2] = {0, 4}; // [row, col]

int main() {
    FILE *file = fopen("../transmission.bin", "rb");
    if (!file) {
        perror("Error opening transmission.bin");
        return -1;
    }

    // Read the entire file into a buffer
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *buffer = (char *)malloc(file_size);
    if (!buffer) {
        perror("Memory allocation failed");
        fclose(file);
        return -1;
    }
    fread(buffer, 1, file_size, file);
    fclose(file);

    // Process the buffer
    yahdlc_control_t control;
    unsigned int dest_len;
    char dest[1024];  // Adjust buffer size as needed

    int lastMove = -1, repeatCount = 0;

    for (int i = 0; i < file_size;) {
        int ret = yahdlc_get_data(&control, buffer + i, file_size - i, dest, &dest_len);
        if (ret < 0) {
            // Handle error or end of frame
            break;
        }

        // Process only if it's a data frame
        if (control.frame == YAHDLC_FRAME_DATA) {
            for (unsigned int j = 0; j < dest_len; ++j) {
                int move = (unsigned char)dest[j];

                if (move != lastMove) {
                    // If new move differs from lastMove, process the sequence
                    if (repeatCount < 3 && lastMove != -1) {
                        // Apply all non-repeated moves
                        for (int k = 0; k < repeatCount; k++) {
                            // moveCharacter(&characterPosition[0], &characterPosition[1], lastMove);
                            printf("...Current position of the character: (%d, %d)\n", characterPosition[0], characterPosition[1]);
                        }
                    }
                    // Reset for the new move
                    lastMove = move;
                    repeatCount = 1;
                } else {
                    // Increment repeat count for identical move
                    repeatCount++;
                    if (repeatCount == 3) {
                        // Reset if three identical moves are detected
                        lastMove = -1;
                        repeatCount = 0;
                    }
                }
            }
        }

        // Move to the next frame in the buffer
        i += ret;
    }

    // Process any remaining moves
    if (repeatCount < 3 && lastMove != -1) {
        for (int k = 0; k < repeatCount; k++) {
            // moveCharacter(&characterPosition[0], &characterPosition[1], lastMove);
            printf("Current position of the character: (%d, %d)\n", characterPosition[0], characterPosition[1]);
        }   
    }

    printf("Final position of the character: (%d, %d)\n", characterPosition[0], characterPosition[1]);

    free(buffer);
    return 0;
}
