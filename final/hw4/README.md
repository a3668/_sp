## 參考https://cs.lmu.edu/~ray/notes/gasexamples/

## 參數傳遞順序

From left to right, pass as many parameters as will fit in registers. The order in which registers are allocated, are: For integers and pointers, rdi, rsi, rdx, rcx, r8, r9

## .globl mul3

- 代表 mul3 這個是全局可見的符號，讓其他程式可以呼叫這個函數

## .text

- 表示後面的內容是程式的執行碼

## mul3:

- 代表 mul3 這個函數的開始位置，程式呼叫 mul3 時執行流程就會跳到這裡
- rsi(source index)
- rdi(destination index)
- rax(accumulator)

## gcc 指令執行過程：

執行 gcc -std=c99 mul3main.c mul3.s 時：

1. C 原始碼 mul3main.c → 編譯器 → 產生 mul3main.o

2. 組合語言檔 mul3.s → 組譯器 → 產生 mul3.o

3. 連結器（linker）將 mul3main.o、mul3.o 以及標準函式庫合成可執行檔，並依據 .globl mul3 把對 mul3 的呼叫綁定到 mul3.o 中的定義
