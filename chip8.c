#include <assert.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#include "chip8.h"

Chip8 *init_chip8(void) {
    // Allocate memory
    Chip8 *chip8 = calloc(1, sizeof(Chip8));
    assert(chip8 != NULL);

    chip8->ram = calloc(4096, 1);
    assert(chip8 != NULL);

    chip8->keyboard = calloc(16, 1);
    assert(chip8 != NULL);


    chip8->display = calloc(64 * 32, 1);
    assert(chip8 != NULL);

    chip8->pc = 0x200;  // Default starting location for programs

    return chip8;
}

void load_game(const char *filename) {
    int fd = open(filename, O_RDONLY);

    // Read game code into memory buffer
    read(fd, chip8->ram, 4096-0x200);    // Reads maximum size for ROM file

    close(fd);
}

void read_instruction(void) {
    // Chip8 instruction is 16-bit big-endian integer
    uint16_t instruction = (chip8->ram[chip8->pc] << 8) | chip8->ram[chip8->pc + 1];

    // Seperate instruction parts for easy use later
    chip8->instruction.nnn = instruction & 0x0FFF;
    chip8->instruction.n = instruction & 0x000F;
    chip8->instruction.x = instruction & 0x0F00 >> 8;
    chip8->instruction.y = instruction & 0x00F0 >> 4;
    chip8->instruction.kk = instruction & 0x00FF;
}
