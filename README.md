# Grid Navigator HDLC

## Overview
This C-based program simulates a game terminal that navigates a character on a 5x5 grid. It interprets pre-recorded instructions wrapped in HDLC frames, ensuring the character moves within the grid legally.

## Key Features
- **Directional Movement:** Processes encoded integers for up, down, left, and right movements.
- **Boundary Checks:** Prevents the character from moving outside the 5x5 grid.
- **Instruction Filtering:** Discards any set of three identical consecutive instructions.
- **Efficiency:** Optimized for memory usage and code readability.

## Usage
- Compile the program with your preferred C compiler.
- Run the executable, which reads from `transmission.bin` and displays the final character position.

## Dependencies
- [yahdlc](https://github.com/bang-olufsen/yahdlc)

## Contribution
Contributions are welcome! Please read our contribution guidelines before submitting a pull request.

---

This README provides a clear introduction to what your project is, its primary features, basic usage instructions, dependencies, and an invitation for contributions. Feel free to modify it according to your specific project needs.