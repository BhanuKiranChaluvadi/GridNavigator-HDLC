#include "yahdlc_decoder.h"
#include "yahdlc.h"
#include "grid_navigation.h" // Include grid_navigation to use the Direction enum

static void processDirection(yahdlc_decoder_t *decoder, Direction direction);
static void processRemainingMoves(yahdlc_decoder_t *decoder);
static void updateMoveHistory(yahdlc_decoder_t *decoder, Direction direction);

void yahdlc_decoder_init(yahdlc_decoder_t *decoder, char *data, int len, Position startPosition)
{
    decoder->data = data;
    decoder->dataLength = len;
    decoder->index = 0;
    decoder->lastMove = RESET_DIRECTION; // RESET_DIRECTION should be adapted if necessary
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
            break;

        decoder->index += ret;

        if (control.frame == YAHDLC_FRAME_DATA && dest_len > 0)
        {
            Direction direction = (Direction)dest[0];
            if (direction >= UP && direction <= LEFT)
            {
                processDirection(decoder, direction);
            }
        }
    }

    processRemainingMoves(decoder);

    return 0;
}

static void processDirection(yahdlc_decoder_t *decoder, Direction direction)
{
    if (direction != decoder->lastMove)
    {
        if (decoder->repeatCount < REPEAT_THRESHOLD && decoder->lastMove != RESET_DIRECTION)
        {
            for (int k = 0; k < decoder->repeatCount; k++)
            {
                moveCharacter(&decoder->position, (Direction)decoder->lastMove);
            }
        }
        updateMoveHistory(decoder, direction);
    }
    else
    {
        decoder->repeatCount++;
        if (decoder->repeatCount == REPEAT_THRESHOLD)
        {
            updateMoveHistory(decoder, RESET_DIRECTION);
        }
    }
}

static void processRemainingMoves(yahdlc_decoder_t *decoder)
{
    if (decoder->repeatCount < REPEAT_THRESHOLD && decoder->lastMove != RESET_DIRECTION)
    {
        for (int k = 0; k < decoder->repeatCount; k++)
        {
            moveCharacter(&decoder->position, (Direction)decoder->lastMove);
        }
    }
}

static void updateMoveHistory(yahdlc_decoder_t *decoder, Direction direction)
{
    decoder->lastMove = direction;
    decoder->repeatCount = (direction != RESET_DIRECTION) ? 1 : 0;
}
