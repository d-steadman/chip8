#ifndef CHIP8_H
#define CHIP8_H

/* Instruction components */
// NOTE: no use of unions here because values are store big-endian
typedef struct {
    uint16_t nnn;   // Lowest 12 bits of instruction
    uint8_t n;      // Lowest 4 bits of instruction
    uint8_t x;      // Lowest 4 bits of high-byte of instruction
    uint8_t y;      // Highest 4 bits of low-byte of instruction
    uint8_t kk;     // Lowest 8 bits of instruction
} Instruction;

/* Chip8 internal emulator state */
typedef struct {
    uint8_t *ram;
    uint8_t V[0xF]; // Registers
    uint16_t pc;    // Program counter
    Instruction instruction;

    uint8_t sp;     // Stack pointer
    uint16_t stack[16];

    uint8_t *keyboard; // 16 characters
    uint8_t *display;

    uint8_t delay_timer;
    uint8_t sound_time;
} Chip8;

Chip8 *init_chip8(void);
void load_game(const char *filename);
void read_instruction(void);

// Extern variables
extern Chip8 *chip8;

#endif
