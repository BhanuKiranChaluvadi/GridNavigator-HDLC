#include <stdio.h>
#include <stdlib.h>
#include "yahdlc.h"

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

    for (int i = 0; i < file_size;) {
        int ret = yahdlc_get_data(&control, buffer + i, file_size - i, dest, &dest_len);
        if (ret < 0) {
            // Handle error or end of frame
            break;
        }

        // Print the decoded frame
        printf("Frame: Type=%d, Seq No=%d, Data=", control.frame, control.seq_no);

        // Assuming the data is a series of integers
        for (unsigned int j = 0; j < dest_len; ++j) {
            printf("%d ", (unsigned char)dest[j]);
        }
        printf("\n");

        // Move to the next frame in the buffer
        i += ret;
    }

    free(buffer);
    return 0;
}