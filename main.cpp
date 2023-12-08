#include <stdio.h>
#include "yahdlc.h"

int main() {
    // Initialize a YAHDLC control structure
    yahdlc_control_t control;
    control.frame = YAHDLC_FRAME_DATA;
    control.seq_no = 1;

    // Print a message to indicate the program is running
    printf("YAHDLC library integrated successfully. Control Frame: %d, Sequence Number: %d\n", 
           control.frame, control.seq_no);

    return 0;
}
