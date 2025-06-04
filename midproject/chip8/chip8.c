// chip8.c
#include "chip8.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// CHIP-8 預設字型（0–F 共 16 個字元，每個字元 5 bytes）
static const uint8_t chip8_fontset[80] = {
    0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
    0x20, 0x60, 0x20, 0x20, 0x70, // 1
    0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
    0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
    0x90, 0x90, 0xF0, 0x10, 0x10, // 4
    0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
    0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
    0xF0, 0x10, 0x20, 0x40, 0x40, // 7
    0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
    0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
    0xF0, 0x90, 0xF0, 0x90, 0x90, // A
    0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
    0xF0, 0x80, 0x80, 0x80, 0xF0, // C
    0xE0, 0x90, 0x90, 0x90, 0xE0, // D
    0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
    0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};

void chip8_init(Chip8 *chip8)
{
    // 隨機數初始化（後續 rnd 指令會用到）
    srand((unsigned)time(NULL));

    chip8->pc = 0x200; // 程式起始位址
    chip8->I = 0;
    chip8->sp = 0;
    chip8->delay_timer = 0;
    chip8->sound_timer = 0;

    // 清空記憶體、暫存器、堆疊、畫面、鍵盤
    memset(chip8->memory, 0, MEMORY_SIZE);
    memset(chip8->V, 0, NUM_REGISTERS);
    memset(chip8->stack, 0, STACK_SIZE * sizeof(uint16_t));
    memset(chip8->gfx, 0, SCREEN_WIDTH * SCREEN_HEIGHT);
    memset(chip8->keypad, 0, 16);

    // 載入預設字型到 memory[0x00 … 0x4F]
    memcpy(chip8->memory, chip8_fontset, sizeof(chip8_fontset));
}

int chip8_load_rom(Chip8 *chip8, const char *filename)
{
    FILE *rom = fopen(filename, "rb");
    if (!rom)
    {
        fprintf(stderr, "Error: 無法開啟 ROM 檔案 `%s`\n", filename);
        return 0;
    }
    fseek(rom, 0, SEEK_END);
    long size = ftell(rom);
    rewind(rom);

    if (size > (MEMORY_SIZE - 0x200))
    {
        fprintf(stderr, "Error: ROM 太大 (%ld bytes)\n", size);
        fclose(rom);
        return 0;
    }

    fread(chip8->memory + 0x200, 1, size, rom);
    fclose(rom);
    return 1;
}

void chip8_emulate_cycle(Chip8 *chip8)
{
    // 取指令 (2 bytes)
    // 從記憶體裡連續拿兩個 byte 拼成一條 16-bit 指令
    // 高位 (高 8 bits) 來自 memory[pc]，需要左移 8 位到高位元
    // 低位 (低 8 bits) 來自 memory[pc + 1]
    // 最後把兩個部分用 bitwise OR (|) 合併
    uint16_t opcode = (chip8->memory[chip8->pc] << 8) | chip8->memory[chip8->pc + 1];

    // 解碼與執行
    switch (opcode & 0xF000)
    {
    case 0x0000:
        switch (opcode & 0x00FF)
        {
        case 0x00E0: // CLS
            memset(chip8->gfx, 0, SCREEN_WIDTH * SCREEN_HEIGHT);
            chip8->pc += 2;
            break;
        case 0x00EE: // RET
            chip8->sp--;
            chip8->pc = chip8->stack[chip8->sp] + 2;
            break;
        default:
            chip8->pc += 2;
            break;
        }
        break;

    case 0x1000: // JP addr
        chip8->pc = opcode & 0x0FFF;
        break;
    case 0x2000: // CALL addr
        chip8->stack[chip8->sp++] = chip8->pc;
        chip8->pc = opcode & 0x0FFF;
        break;
    case 0x3000:
    { // SE Vx, byte
        uint8_t x = (opcode & 0x0F00) >> 8;
        uint8_t kk = opcode & 0x00FF;
        chip8->pc += (chip8->V[x] == kk) ? 4 : 2;
        break;
    }
    case 0x4000:
    { // SNE Vx, byte
        uint8_t x = (opcode & 0x0F00) >> 8;
        uint8_t kk = opcode & 0x00FF;
        chip8->pc += (chip8->V[x] != kk) ? 4 : 2;
        break;
    }
    case 0x5000:
    { // SE Vx, Vy
        uint8_t x = (opcode & 0x0F00) >> 8;
        uint8_t y = (opcode & 0x00F0) >> 4;
        chip8->pc += (chip8->V[x] == chip8->V[y]) ? 4 : 2;
        break;
    }
    case 0x6000: // LD Vx, byte
        chip8->V[(opcode & 0x0F00) >> 8] = opcode & 0x00FF;
        chip8->pc += 2;
        break;
    case 0x7000: // ADD Vx, byte
        chip8->V[(opcode & 0x0F00) >> 8] += opcode & 0x00FF;
        chip8->pc += 2;
        break;

    case 0x8000:
    { // 8xyN 算術/邏輯運算
        uint8_t x = (opcode & 0x0F00) >> 8;
        uint8_t y = (opcode & 0x00F0) >> 4;
        switch (opcode & 0x000F)
        {
        case 0x0:
            chip8->V[x] = chip8->V[y];
            break;
        case 0x1:
            chip8->V[x] |= chip8->V[y];
            break;
        case 0x2:
            chip8->V[x] &= chip8->V[y];
            break;
        case 0x3:
            chip8->V[x] ^= chip8->V[y];
            break;
        case 0x4:
        { // ADD with carry
            uint16_t sum = chip8->V[x] + chip8->V[y];
            chip8->V[0xF] = sum > 0xFF;
            chip8->V[x] = sum & 0xFF;
            break;
        }
        case 0x5: // SUB Vx = Vx - Vy
            chip8->V[0xF] = chip8->V[x] > chip8->V[y];
            chip8->V[x] -= chip8->V[y];
            break;
        case 0x6: // SHR Vx
            chip8->V[0xF] = chip8->V[x] & 0x1;
            chip8->V[x] >>= 1;
            break;
        case 0x7: // SUBN Vx = Vy - Vx
            chip8->V[0xF] = chip8->V[y] > chip8->V[x];
            chip8->V[x] = chip8->V[y] - chip8->V[x];
            break;
        case 0xE: // SHL Vx
            chip8->V[0xF] = (chip8->V[x] >> 7) & 0x1;
            chip8->V[x] <<= 1;
            break;
        }
        chip8->pc += 2;
        break;
    }

    case 0x9000:
    { // SNE Vx, Vy
        uint8_t x = (opcode & 0x0F00) >> 8;
        uint8_t y = (opcode & 0x00F0) >> 4;
        chip8->pc += (chip8->V[x] != chip8->V[y]) ? 4 : 2;
        break;
    }
    case 0xA000: // LD I, addr
        chip8->I = opcode & 0x0FFF;
        chip8->pc += 2;
        break;
    case 0xB000: // JP V0, addr
        chip8->pc = (opcode & 0x0FFF) + chip8->V[0];
        break;
    case 0xC000: // RND Vx, byte
        chip8->V[(opcode & 0x0F00) >> 8] = (rand() % 256) & (opcode & 0x00FF);
        chip8->pc += 2;
        break;

    case 0xD000:
    { // DRW Vx, Vy, nibble
        uint8_t x = chip8->V[(opcode & 0x0F00) >> 8] % SCREEN_WIDTH;
        uint8_t y = chip8->V[(opcode & 0x00F0) >> 4] % SCREEN_HEIGHT;
        uint8_t height = opcode & 0x000F;
        chip8->V[0xF] = 0;

        for (int row = 0; row < height; row++)
        {
            uint8_t sprite = chip8->memory[chip8->I + row];
            for (int col = 0; col < 8; col++)
            {
                if ((sprite & (0x80 >> col)) == 0)
                    continue;
                int idx = (x + col) + ((y + row) * SCREEN_WIDTH);
                if (chip8->gfx[idx])
                    chip8->V[0xF] = 1;
                chip8->gfx[idx] ^= 1;
            }
        }
        chip8->pc += 2;
        break;
    }

    case 0xE000:
    { // Key ops
        uint8_t x = (opcode & 0x0F00) >> 8;
        switch (opcode & 0x00FF)
        {
        case 0x9E:
            chip8->pc += chip8->keypad[chip8->V[x]] ? 4 : 2;
            break;
        case 0xA1:
            chip8->pc += !chip8->keypad[chip8->V[x]] ? 4 : 2;
            break;
        default:
            chip8->pc += 2;
            break;
        }
        break;
    }

    case 0xF000:
    { // Timer, memory ops
        uint8_t x = (opcode & 0x0F00) >> 8;
        switch (opcode & 0x00FF)
        {
        case 0x07: // LD Vx, DT
            chip8->V[x] = chip8->delay_timer;
            chip8->pc += 2;
            break;
        case 0x0A: // LD Vx, K
            // 等待按鍵
            for (int i = 0; i < 16; i++)
            {
                if (chip8->keypad[i])
                {
                    chip8->V[x] = i;
                    chip8->pc += 2;
                    goto pressed;
                }
            }
            return; // 還沒按就不前進
        pressed:
            break;
        case 0x15: // LD DT, Vx
            chip8->delay_timer = chip8->V[x];
            chip8->pc += 2;
            break;
        case 0x18: // LD ST, Vx
            chip8->sound_timer = chip8->V[x];
            chip8->pc += 2;
            break;
        case 0x1E: // ADD I, Vx
            chip8->I += chip8->V[x];
            chip8->pc += 2;
            break;
        case 0x29:                      // LD F, Vx
            chip8->I = chip8->V[x] * 5; // 字型位址 = 字元 × 5
            chip8->pc += 2;
            break;
        case 0x33: // LD B, Vx
            chip8->memory[chip8->I] = chip8->V[x] / 100;
            chip8->memory[chip8->I + 1] = (chip8->V[x] / 10) % 10;
            chip8->memory[chip8->I + 2] = chip8->V[x] % 10;
            chip8->pc += 2;
            break;
        case 0x55: // LD [I], Vx
            for (int i = 0; i <= x; i++)
                chip8->memory[chip8->I + i] = chip8->V[i];
            chip8->pc += 2;
            break;
        case 0x65: // LD Vx, [I]
            for (int i = 0; i <= x; i++)
                chip8->V[i] = chip8->memory[chip8->I + i];
            chip8->pc += 2;
            break;
        default:
            chip8->pc += 2;
            break;
        }
        break;
    }

    default:
        // 未知指令：直接跳過
        chip8->pc += 2;
        break;
    }

    // 更新定時器
    if (chip8->delay_timer > 0)
        chip8->delay_timer--;
    if (chip8->sound_timer > 0)
    {
        if (chip8->sound_timer == 1)
        {
            // TODO: 發出 beep
        }
        chip8->sound_timer--;
    }
}