## 參考https://cs.lmu.edu/~ray/notes/gasexamples/

From left to right, pass as many parameters as will fit in registers. The order in which registers are allocated, are: For integers and pointers, rdi, rsi, rdx, rcx, r8, r9

## .globl mul3

代表 mul3 這個是全局可見的符號，讓其他程式可以呼叫這個函數

## .text

表示後面的內容是程式的執行碼

## mul3:

代表 mul3 這個函數的開始位置，程式呼叫 mul3 時執行流程就會跳到這裡
rsi(source index)
rdi(destination index)
rax(accumulator)

## gcc 指令執行過程：

當你執行 gcc -std=c99 mul3main.c mul3.s 時，gcc 這個驅動程式會自動執行以下步驟：
它識別出 mul3main.c 是一個 C 原始碼檔，於是呼叫 C 編譯器將其編譯成一個目標檔（通常是 mul3main.o）。
它識別出 mul3.s 是一個組合語言原始碼檔，於是呼叫組合語言編譯器（組譯器）將其組合（Assemble）成另一個目標檔（通常是 mul3.o）。
最後，gcc 會自動呼叫連結器。連結器的任務是將所有輸入的目標檔（mul3main.o、mul3.o，以及執行程式所需用到的標準函式庫等等）合併成一個單一的可執行檔。在連結過程中，連結器會看到 mul3main.o 中有一個對 mul3 這個符號的引用需要被滿足。由於 mul3.o 中包含了 mul3 函式的定義，並且被標記為全域符號（.globl mul3），連結器就能夠成功地在 mul3.o 中找到 mul3 的實際程式碼位置，並將 mul3main.o 中對 mul3 的呼叫「連結」到這個位置。
