#include "yahdlc_decoder.h"

void yahdlc_decoder_init(yahdlc_decoder_t *decoder, char *data, int len, Position startPosition) {
    decoder->data = data;
    decoder->dataLength = len;
    decoder->index = 0;
    decoder->lastMove = -1;
    decoder->repeatCount = 0;
    decoder->position = startPosition;
}

uint8_t yahdlc_decode_frame(yahdlc_decoder_t *decoder) {
    if (decoder->index >= decoder->dataLength) return 0;
    
    int direction = decoder->data[decoder->index++];
    
    if (direction != decoder->lastMove) {
        if (decoder->repeatCount < 3 && decoder->lastMove != -1) {
            for (int k = 0; k < decoder->repeatCount; k++) {
                moveCharacter(&decoder->position, decoder->lastMove);
            }
        }
        decoder->lastMove = direction;
        decoder->repeatCount = 1;
    } else {
        decoder->repeatCount++;
        if (decoder->repeatCount == 3) {
            decoder->lastMove = -1;
            decoder->repeatCount = 0;
        }
    }

    return sizeof(direction);
}
