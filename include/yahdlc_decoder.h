#ifndef YAHDLC_DECODER_H
#define YAHDLC_DECODER_H

#include <stdint.h>
#include "grid_navigation.h"

typedef struct {
    char *data;
    int dataLength;
    int index;
    int lastMove;
    int repeatCount;
    Position position;
} yahdlc_decoder_t;

void yahdlc_decoder_init(yahdlc_decoder_t *decoder, char *data, int len, Position startPosition);
uint8_t yahdlc_decode_frame(yahdlc_decoder_t *decoder);

#endif // YAHDLC_DECODER_H
