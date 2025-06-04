// display.c
#include "display.h"
#include <stdio.h>

int display_init(Display *disp)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        return 0;
    }
    disp->window = SDL_CreateWindow(
        "CHIP-8 Emulator",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN);
    if (!disp->window)
    {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 0;
    }
    disp->renderer = SDL_CreateRenderer(
        disp->window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!disp->renderer)
    {
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(disp->window);
        SDL_Quit();
        return 0;
    }

    SDL_SetRenderDrawColor(disp->renderer, 0, 0, 0, 255);
    SDL_RenderClear(disp->renderer);
    SDL_RenderPresent(disp->renderer);
    return 1;
}

void display_render(Display *disp, const uint8_t gfx[])
{
    SDL_SetRenderDrawColor(disp->renderer, 0, 0, 0, 255);
    SDL_RenderClear(disp->renderer);

    SDL_SetRenderDrawColor(disp->renderer, 255, 255, 255, 255);
    for (int y = 0; y < SCREEN_HEIGHT; ++y)
    {
        for (int x = 0; x < SCREEN_WIDTH; ++x)
        {
            if (gfx[x + y * SCREEN_WIDTH])
            {
                SDL_Rect pixel = {
                    x * DISPLAY_SCALE,
                    y * DISPLAY_SCALE,
                    DISPLAY_SCALE,
                    DISPLAY_SCALE};
                SDL_RenderFillRect(disp->renderer, &pixel);
            }
        }
    }

    SDL_RenderPresent(disp->renderer);
}

void display_destroy(Display *disp)
{
    if (disp->renderer)
        SDL_DestroyRenderer(disp->renderer);
    if (disp->window)
        SDL_DestroyWindow(disp->window);
    SDL_Quit();
}