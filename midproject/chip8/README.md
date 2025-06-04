# chip8.c

## void chip8_init

初始化函式
設定亂數，避免每次啟動遊戲位置都相同
0x200 是遊戲起始位址，前面的 0x000~0x1FF 給字型資料和系統用，避免衝突
Index Register 和 Stack Pointer 都設為 0

## int chip8_load_rom

打開 ROM 檔案讀進 0x200 這個位置
rb 代表用二進位模式讀檔
read binary
再來讀取檔案大小，要檢查有沒有超過設定的記憶體
MEMORY_SIZE 是 4096 bytes，但是從 0x200 開始，所以剩下 3584，檔案不能超過
沒問題後就把檔案內容寫進記憶體

## void chip8_emulate_cycle

這是 CHIP-8 每一個「CPU 週期」的核心執行函數
[opcode 參考](http://devernay.free.fr/hacks/chip8/C8TECH10.HTM  
https://en.wikipedia.org/wiki/CHIP-8#Opcode_table)
一開始從記憶體的 pc 位置，連續讀 2 bytes，組合成一條 16-bit 指令  
解碼指令 (opcode)：先用 & 0xF000 取出高 4 bits（最高位）  
剩下的 12 bits 負責給這條指令需要的參數  
高 4 bits 決定這是哪一「大類」指令（例如跳躍、暫存器操作、繪圖等等）  
分類如下：  
0x0000 → 系統指令 (CLS, RET)  
0x1000 → 跳躍 JP addr  
0x2000 → 呼叫子程式 CALL addr  
0x3000 → 相等判斷 SE Vx, byte  
0x4000 → 不相等判斷 SNE Vx, byte  
0x5000 → 相等判斷 SE Vx, Vy  
0x6000 → 設定暫存器 LD Vx, byte  
0x7000 → 加法 ADD Vx, byte  
0x8000 → 算術與邏輯運算類（AND, OR, XOR, ADD 等）  
0x9000 → 不相等判斷 SNE Vx, Vy  
0xA000 → 設定 I 寄存器 LD I, addr  
0xB000 → 相對跳躍 JP V0, addr  
0xC000 → 亂數產生 RND Vx, byte  
0xD000 → 畫圖 DRW Vx, Vy, nibble  
0xE000 → 鍵盤判斷 EX9E / EXA1  
0xF000 → 計時器、記憶體相關操作

---

# input.c

input_update 這函式的作用是接收一個 SDL 鍵盤事件 e 和 Chip-8 模擬器狀態 chip8  
再來判斷是按下還是放開  
e->key.keysym.sym 取得了事件中按下的具體按鍵符號  
![鍵盤圖](/pic/keypad.png)

---

# display.c

## display_init

初始化 SDL 的顯示系統和建立視窗和渲染

### if (!disp->window)

檢查視窗是否建立成功，失敗會輸出錯誤訊息和清除已初始化的部分  
成功後為視窗建立一個渲染器
'' ![creatrender](/pic/CreateRenderer.png)
SDL_RENDERER_ACCELERATED: 啟用硬體加速  
SDL_RENDERER_PRESENTVSYNC: 啟用垂直同步 (防止畫面撕裂)

### SDL_SetRenderDrawColor(disp->renderer, 0, 0, 0, 255)

初始設定渲染器的繪圖顏色為黑色和不透明

### SDL_RenderClear(disp->renderer)

用當前繪圖顏色清除渲染器的繪圖緩衝區

### SDL_RenderPresent(disp->renderer)

將渲染器緩衝區的內容呈現到視窗上，讓視窗顯示為全黑

## display_render

負責將 Chip-8 的像素資料 (gfx) 繪製到 SDL 視窗上

### SDL_SetRenderDrawColor(disp->renderer, 0, 0, 0, 255);

清除上一幀的畫面 (塗成黑色)

### SDL_SetRenderDrawColor(disp->renderer, 255, 255, 255, 255);

設定繪圖顏色為白色，用於繪製 Chip-8 開啟的像素

## void display_destroy

檢查渲染器指標和視窗指標是否有效，有效則銷毀它

---

# main.c

負責程式的啟動、初始化各個模組、執行主要的模擬迴圈，以及在程式結束時進行清理工作

## if (argc < 2)

檢查使用者是否提供了 ROM 檔案名
如果參數數量小於 2 (程式名本身算一個參數)就是沒找到
接下來初始化 Chip8 模擬器的內部狀態 (如記憶體、暫存器等)

## if (!chip8_load_rom(&chip8, argv[1]))

呼叫 chip8_load_rom 載入 ROM，檢查回傳值判斷是否成功

## if (!display_init(&disp))

初始化顯示模組 (建立視窗和渲染器等)

## SDL 事件變數和程式運行旗標

running = 1 表示正在進行，0 表示準備退出

## chip8_emulate_cycle(&chip8)

呼叫函式執行 Chip-8 CPU 的一個指令週期

## display_render(&disp, chip8.gfx)

將 Chip8 模擬器狀態中的顯示記憶體 (gfx 陣列) 傳給顯示模組進行繪製

## SDL_Delay(1000 / 60);

這裡設定為 1000 毫秒 / 60 幀 = 約 16.6 毫秒，約 60 Hz

## display_destroy(&disp)

進行清理

[SDL2 內容](https://wiki.libsdl.org/SDL2/FrontPage)

test_opcode.ch8 測試 Opcode 是否正確  
Keypad_Test.ch8 測試鍵盤對應
