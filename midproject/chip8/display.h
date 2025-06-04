// display.h
#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>
#include <SDL2/SDL.h>
#include "chip8.h"

#define DISPLAY_SCALE 10

#define WINDOW_WIDTH (SCREEN_WIDTH * DISPLAY_SCALE)
#define WINDOW_HEIGHT (SCREEN_HEIGHT * DISPLAY_SCALE)

typedef struct
{
    SDL_Window *window;
    SDL_Renderer *renderer;
} Display;

int display_init(Display *disp);

void display_render(Display *disp, const uint8_t gfx[]);

void display_destroy(Display *disp);

#endif