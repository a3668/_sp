// input.h
#ifndef INPUT_H
#define INPUT_H

#include "chip8.h"
#include <SDL2/SDL.h>

// Update-chip8-keypad-state-based-on-SDL-keyboard-events
void input_update(Chip8 *chip8, SDL_Event *e);

#endif // INPUT_H