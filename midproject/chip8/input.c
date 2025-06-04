// input.c
#include "input.h"

void input_update(Chip8 *chip8, SDL_Event *e)
{
    // Update keypad on keydown/keyup
    uint8_t val = (e->type == SDL_KEYDOWN) ? 1 : 0;
    switch (e->key.keysym.sym)
    {
    case SDLK_1:
        chip8->keypad[0x1] = val;
        break;
    case SDLK_2:
        chip8->keypad[0x2] = val;
        break;
    case SDLK_3:
        chip8->keypad[0x3] = val;
        break;
    case SDLK_4:
        chip8->keypad[0xC] = val;
        break;
    case SDLK_q:
        chip8->keypad[0x4] = val;
        break;
    case SDLK_w:
        chip8->keypad[0x5] = val;
        break;
    case SDLK_e:
        chip8->keypad[0x6] = val;
        break;
    case SDLK_r:
        chip8->keypad[0xD] = val;
        break;
    case SDLK_a:
        chip8->keypad[0x7] = val;
        break;
    case SDLK_s:
        chip8->keypad[0x8] = val;
        break;
    case SDLK_d:
        chip8->keypad[0x9] = val;
        break;
    case SDLK_f:
        chip8->keypad[0xE] = val;
        break;
    case SDLK_z:
        chip8->keypad[0xA] = val;
        break;
    case SDLK_x:
        chip8->keypad[0x0] = val;
        break;
    case SDLK_c:
        chip8->keypad[0xB] = val;
        break;
    case SDLK_v:
        chip8->keypad[0xF] = val;
        break;
    default:
        break;
    }
}