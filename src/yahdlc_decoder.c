#include "yahdlc_decoder.h"
#include "yahdlc.h"

void yahdlc_decoder_init(yahdlc_decoder_t *decoder, char *data, int len, Position startPosition)
{
    decoder->data = data;
    decoder->dataLength = len;
    decoder->index = 0;
    decoder->lastMove = -1;
    decoder->repeatCount = 0;
    decoder->position = startPosition;
}

uint8_t yahdlc_decode_frame(yahdlc_decoder_t *decoder)
{
    yahdlc_control_t control;
    char dest[10];
    unsigned int dest_len;

    while (decoder->index < decoder->dataLength)
    {
        int ret = yahdlc_get_data(&control, decoder->data + decoder->index, decoder->dataLength - decoder->index, dest, &dest_len);
        if (ret < 0)
            break; // Error or no more frames

        decoder->index += ret;

        if (control.frame == YAHDLC_FRAME_DATA && dest_len > 0)
        {
            int direction = dest[0];
            if (direction >= 1 && direction <= 4)
            {
                if (direction != decoder->lastMove)
                {
                    if (decoder->repeatCount < 3 && decoder->lastMove != -1)
                    {
                        for (int k = 0; k < decoder->repeatCount; k++)
                        {
                            moveCharacter(&decoder->position, decoder->lastMove);
                        }
                    }
                    decoder->lastMove = direction;
                    decoder->repeatCount = 1;
                }
                else
                {
                    decoder->repeatCount++;
                    if (decoder->repeatCount == 3)
                    {
                        decoder->lastMove = -1;
                        decoder->repeatCount = 0;
                    }
                }
            }
        }
    }

    // Process any final remaining moves if they are less than 3
    if (decoder->repeatCount < 3 && decoder->lastMove != -1)
    {
        for (int k = 0; k < decoder->repeatCount; k++)
        {
            moveCharacter(&decoder->position, decoder->lastMove);
        }
    }

    return 0;
}
