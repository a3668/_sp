## 寫一個 Makefile 來處理好多個檔案

make
gcc -std=c99 -O0 lexer.c compiler.c main.c -o compiler
把三個檔案一起編譯並連結，生成一個可執行檔 compiler

### ./compiler test/while.c 去執行

## DOWHILE = do STMT while (E);

### lex 就是詞法分析的輸出，而 dump 只是把 lex 的結果帶上序號再印一次

(L0) <-- 迴圈開始標籤
t1 = i <-- 迴圈體開始 (對應 i = i + 1;)
t2 = 1
t3 = t1 + t2
i = t3 <-- 迴圈體結束 (i = i + 1 的結果賦回 i)
t4 = i <-- 條件判斷開始 (對應 while (i < 10);)
t5 = 10
t6 = t4 < t5
if T6 goto L0 <-- 如果條件 T6 (i < 10) 為真，跳回 L0 繼續迴圈
(L1) <-- 迴圈結束標籤
