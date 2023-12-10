#include <stdio.h>
#include <stdlib.h>
#include "yahdlc_decoder.h"

int main()
{
    FILE *file = fopen("../transmission.bin", "rb");
    if (!file)
    {
        perror("Error opening file");
        return -1;
    }

    char data[1024];
    int readBytes = fread(data, 1, sizeof(data), file);
    fclose(file);

    // Initialize the decoder with the read data
    yahdlc_decoder_t decoder;
    Position startPosition = {0, 4};
    yahdlc_decoder_init(&decoder, data, readBytes, startPosition);

    // Process the data
    yahdlc_decode_frame(&decoder);

    printf("Final position of the character: (%d, %d)\n", decoder.position.x, decoder.position.y);

    return 0;
}
