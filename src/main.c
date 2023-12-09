#include <stdio.h>
#include <stdlib.h>
#include "yahdlc.h"
#include "grid_navigation.h"

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

    printf("Total file size: %ld bytes\n", file_size);

    // Initialize game state
    int x = 0, y = 4;  // Character starts at (0, 4)
    int lastDirection = 0, repeatCount = 0;

    // Process the buffer
    yahdlc_control_t control;
    char dest[1024];  // Single byte buffer
    unsigned int dest_len = 1;  // Length is 1 byte

    for (int i = 0; i < file_size;) {
        dest_len = sizeof(dest);  // Reset dest_len for each frame

        int ret = yahdlc_get_data(&control, buffer + i, file_size - i, dest, &dest_len);
        if (ret < 0) {
            // Handle error or end of frame
            switch (ret) {
                case -EINVAL:
                    printf("Error: Invalid parameter.\n");
                    break;
                case -ENOMSG:
                    printf("Error: Invalid message.\n");
                    break;
                case -EIO:
                    printf("Error: Invalid Frame Check Sequence (FCS).\n");
                    break;
                default:
                    printf("Unknown error occurred.\n");
            }
            break;  // Exit the loop on error
        }

        // Print the decoded frame
        printf("Frame: Type=%d, Seq No=%d, Data Size=%u, Data=", control.frame, control.seq_no, dest_len);
    
        // Print each byte in the data as an integer
        for (unsigned int j = 0; j < dest_len; ++j) {
            printf("%d ", (unsigned char)dest[j]);
        }
        printf("\n");

        // Move to the next frame in the buffer
    }
}