#ifndef CHIP8_H
#define CHIP8_H

#include <stdint.h> // for uint8_t, uint16_t

#define MEMORY_SIZE 4096
#define NUM_REGISTERS 16
#define STACK_SIZE 16
#define SCREEN_WIDTH 64
#define SCREEN_HEIGHT 32

typedef struct Chip8
{
    uint8_t memory[MEMORY_SIZE];               ///< main RAM
    uint8_t V[NUM_REGISTERS];                  ///< V0–VF registers
    uint16_t I;                                ///< index register
    uint16_t pc;                               ///< program counter
    uint8_t gfx[SCREEN_WIDTH * SCREEN_HEIGHT]; ///< monochrome display buffer
    uint8_t delay_timer;                       ///< delay timer
    uint8_t sound_timer;                       ///< sound timer
    uint16_t stack[STACK_SIZE];                ///< call stack
    uint8_t sp;                                ///< stack pointer
    uint8_t keypad[16];                        ///< hex keypad state
} Chip8;

// Initialize the CHIP-8 system: clear memory, registers, load fontset, set pc = 0x200
void chip8_init(Chip8 *chip8);

// Load a CHIP-8 ROM into memory at 0x200; return 1 on success, 0 on failure
int chip8_load_rom(Chip8 *chip8, const char *filename);

// Emulate one cycle: fetch, decode, execute; also update delay & sound timers
void chip8_emulate_cycle(Chip8 *chip8);

#endif // CHIP8_H