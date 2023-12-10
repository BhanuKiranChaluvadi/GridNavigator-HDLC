# Grid Navigator HDLC

## Overview
Grid Navigator HDLC is a C-based simulation program designed to navigate a character through a 5x5 grid. The program interprets pre-recorded instructions enclosed in HDLC frames and ensures that the character's movements within the grid are valid and within bounds.

## Getting Started
Clone the repository with all its submodules using the following command:
```bash
git clone --recurse-submodules git@github.com:BhanuKiranChaluvadi/GridNavigator-HDLC.git
```

## Dependencies
- [yahdlc](https://github.com/bang-olufsen/yahdlc): A library for handling HDLC framing.

## Build
1. Create a build directory and navigate into it:
   ```bash
   mkdir build && cd build
   ```
2. Configure the project with CMake:
   ```bash
   cmake ..
   ```
3. Compile the project:
   ```bash
   make
   ```

## Usage
To use the Grid Navigator HDLC, follow these steps:

### Running Unit Tests
To ensure everything is set up correctly:
```bash
./tests/GridNavigationTests
```

### Executing the Program
The program reads from `transmission.bin` and displays the final position of the character on the grid.
```bash
./src/GridNavigate
```