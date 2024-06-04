#include "Chip-8.h"
#include <iostream>
#include <GL/gl.h>
Chip8 chip;

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    if (!chip.loadApplication(argv[1])) {
        return 1;
    }

    // Initialize the Chip8 system and load the game into the memory
    chip.initialize();

    // Emulation loop
    for (;;) {
        chip.emulateCycle();

        // If the draw flag is set, update the screen
        if (chip.drawFlag) {
            // draw graphics
            chip.drawFlag = false;
        }

        // Store key press state (Press and Release)
        chip.setKeys();
    }

    return 0;
}


