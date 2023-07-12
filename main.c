#include <stdio.h>
#include <stdlib.h>

#include "chip8.h"

// Extern chip8 state
Chip8 *chip8 = NULL;

int main() {
    chip8 = init_chip8();
    load_game("tests/ibm.ch8");

    return 0;
}
