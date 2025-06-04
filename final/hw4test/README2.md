rdi, rsi, rdx, rcx, r8, r9.
mov <來源>, <目標>

imulq
64-bit 整數相乘

mov $1, %rax
• rax 寄存器儲存 系統呼叫號碼（syscall number）。
• 在 Linux 的 syscall 介面中：
• 1 代表 sys_write（寫入）。
• 這表示 我們即將呼叫 sys_write 來輸出文字。

mov $1, %rdi
• rdi 寄存器存放 第一個參數，這裡是檔案描述符（File Descriptor）。
• 1 代表 標準輸出（stdout）。

mov $message, %rsi
• rsi 寄存器存放 第二個參數，這是要寫入的 字串位址。
• message 變數代表字串的位址。

mov $13, %rdx
• rdx 寄存器存放 第三個參數，這是要寫入的 字串長度（位元組數）。
• 13 代表這個字串有 13 個位元組（包含換行符 \n）。

syscall
• 執行 Linux 系統呼叫
