# Grid Navigator HDLC

## Overview
This C-based program simulates a game terminal that navigates a character on a 5x5 grid. It interprets pre-recorded instructions wrapped in HDLC frames, ensuring the character moves within the grid legally.

## Usage
- Run the executable, which reads from `transmission.bin` and displays the final character position.

## Dependencies
- [yahdlc](https://github.com/bang-olufsen/yahdlc)

## Build
To build the project, follow these steps:
1. Create a build directory:
   ```bash
   mkdir build
   cd build
   ```
2. Run CMake and build the project:
   ```bash
   cmake ..
   make
   ```

## Run
After building the project, you can run the unit tests and the main program:
1. To run unit tests:
   ```bash
   ./tests/unit_tests
   ```
2. To run the main program:
   ```bash
   ./src/grid_navigation_yahdlc
   ```


