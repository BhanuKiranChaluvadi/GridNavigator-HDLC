#include <iostream>
#include "yahdlc.h"

int main() {
    // Initialize a YAHDLC control structure
    yahdlc_control_t control;
    control.frame = YAHDLC_FRAME_DATA;
    control.seq_no = 1;

    // Just print a message to indicate the program is running
    std::cout << "YAHDLC library integrated successfully. Control Frame: " 
              << control.frame << ", Sequence Number: " << static_cast<int>(control.seq_no) 
              << std::endl;

    return 0;
}
