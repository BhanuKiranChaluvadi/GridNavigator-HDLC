#ifndef YAHDLC_DECODER_H
#define YAHDLC_DECODER_H

#include <stdint.h>
#include "grid_navigation.h"

#define RESET_DIRECTION -1
#define REPEAT_THRESHOLD 3

typedef struct
{
    char *data;
    int dataLength;
    int index;
    Direction lastMove; // Use Direction enum for lastMove
    int repeatCount;
    Position position;
} yahdlc_decoder_t;

void yahdlc_decoder_init(yahdlc_decoder_t *decoder, char *data, int len, Position startPosition);
uint8_t yahdlc_decode_frame(yahdlc_decoder_t *decoder);

#endif // YAHDLC_DECODER_H
