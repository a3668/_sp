// main.c
#include "chip8.h"
#include "display.h"
#include "input.h"
#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    // require a ROM filename on the command line
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <ROM file>\n", argv[0]);
        return 1;
    }

    Chip8 chip8;
    Display disp;

    chip8_init(&chip8);

    // load the ROM specified as argv[1]
    if (!chip8_load_rom(&chip8, argv[1]))
    {
        fprintf(stderr, "Error: Cannot open ROM file `%s`\n", argv[1]);
        return 1;
    }

    if (!display_init(&disp))
        return 1;

    SDL_Event e;
    int running = 1;
    while (running)
    {
        // process all pending SDL events
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                running = 0;
            input_update(&chip8, &e); // forward input to emulator
        }

        chip8_emulate_cycle(&chip8); // run one emulation cycle
        display_render(&disp, chip8.gfx);
        SDL_Delay(1000 / 60); // cap to ~60Hz
    }

    display_destroy(&disp);
    return 0;
}