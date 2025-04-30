## gcc -S 001.c

產生組合語言

## gcc -c 001.c

## 用 objdump 將該目的檔反組譯

objdump -d 001.o
這個命令會將 my_program.o 中的機器碼轉換回組合語言指令並顯示在終端機上。你會看到程式碼區段（通常是 .text 區段）的反組譯結果。

001.o: file format mach-o arm64

Disassembly of section **TEXT,**text:

0000000000000000 <ltmp0>:
0: d10203ff sub sp, sp, #0x80
4: a9077bfd stp x29, x30, [sp, #0x70]
8: 9101c3fd add x29, sp, #0x70
c: 90000008 adrp x8, 0x0 <ltmp0>
10: f9400108 ldr x8, [x8]
14: f9400108 ldr x8, [x8]
18: f81f83a8 stur x8, [x29, #-0x8]
1c: b81e03bf stur wzr, [x29, #-0x20]
20: b81dc3a0 stur w0, [x29, #-0x24]
24: f81d03a1 stur x1, [x29, #-0x30]
28: f9001bff str xzr, [sp, #0x30]
2c: 14000001 b 0x30 <ltmp0+0x30>
30: 910003e9 mov x9, sp
34: d100d3a8 sub x8, x29, #0x34
38: f9000128 str x8, [x9]
3c: 90000000 adrp x0, 0x0 <ltmp0>
40: 91000000 add x0, x0, #0x0
44: 94000000 bl 0x44 <ltmp0+0x44>
48: b85cc3a8 ldur w8, [x29, #-0x34]
4c: 31000508 adds w8, w8, #0x1
50: 1a9f07e8 cset w8, ne
54: 37000068 tbnz w8, #0x0, 0x60 <ltmp0+0x60>
58: 14000001 b 0x5c <ltmp0+0x5c>
5c: 14000013 b 0xa8 <ltmp0+0xa8>
60: 910003e9 mov x9, sp
64: 9100e3e8 add x8, sp, #0x38
68: f9000128 str x8, [x9]
6c: d10073a8 sub x8, x29, #0x1c
70: f9000528 str x8, [x9, #0x8]
74: 90000000 adrp x0, 0x0 <ltmp0>
78: 91000000 add x0, x0, #0x0
7c: 94000000 bl 0x7c <ltmp0+0x7c>
80: 14000001 b 0x84 <ltmp0+0x84>
84: b85cc3a1 ldur w1, [x29, #-0x34]
88: b9403be2 ldr w2, [sp, #0x38]
8c: 9100c3e0 add x0, sp, #0x30
90: d10073a3 sub x3, x29, #0x1c
94: 94000000 bl 0x94 <ltmp0+0x94>
98: 14000001 b 0x9c <ltmp0+0x9c>
9c: 52800028 mov w8, #0x1 ; =1
a0: 3707fc88 tbnz w8, #0x0, 0x30 <ltmp0+0x30>
a4: 14000001 b 0xa8 <ltmp0+0xa8>
a8: 14000001 b 0xac <ltmp0+0xac>
ac: 94000000 bl 0xac <ltmp0+0xac>
b0: b9002fe0 str w0, [sp, #0x2c]
b4: 71002808 subs w8, w0, #0xa
b8: 1a9f17e8 cset w8, eq
bc: 52800009 mov w9, #0x0 ; =0
c0: b90027e9 str w9, [sp, #0x24]
c4: 370000e8 tbnz w8, #0x0, 0xe0 <ltmp0+0xe0>
c8: 14000001 b 0xcc <ltmp0+0xcc>
cc: b9402fe8 ldr w8, [sp, #0x2c]
d0: 31000508 adds w8, w8, #0x1
d4: 1a9f07e8 cset w8, ne
d8: b90027e8 str w8, [sp, #0x24]
dc: 14000001 b 0xe0 <ltmp0+0xe0>
e0: b94027e8 ldr w8, [sp, #0x24]
e4: 36000068 tbz w8, #0x0, 0xf0 <ltmp0+0xf0>
e8: 14000001 b 0xec <ltmp0+0xec>
ec: 17fffff0 b 0xac <ltmp0+0xac>
f0: 9100c3e0 add x0, sp, #0x30
f4: f9000fe0 str x0, [sp, #0x18]
f8: 94000000 bl 0xf8 <ltmp0+0xf8>
fc: 910003e9 mov x9, sp
100: d10073a8 sub x8, x29, #0x1c
104: f9000be8 str x8, [sp, #0x10]
108: f9000128 str x8, [x9]
10c: 90000000 adrp x0, 0x0 <ltmp0>
110: 91000000 add x0, x0, #0x0
114: 94000000 bl 0x114 <ltmp0+0x114>
118: f9400be1 ldr x1, [sp, #0x10]
11c: f9400fe0 ldr x0, [sp, #0x18]
120: 94000000 bl 0x120 <ltmp0+0x120>
124: b9002be0 str w0, [sp, #0x28]
128: b9402be8 ldr w8, [sp, #0x28]
12c: 71000108 subs w8, w8, #0x0
130: 1a9f17e8 cset w8, eq
134: 370000a8 tbnz w8, #0x0, 0x148 <ltmp0+0x148>
138: 14000001 b 0x13c <ltmp0+0x13c>
13c: 9100c3e0 add x0, sp, #0x30
140: 94000000 bl 0x140 <ltmp0+0x140>
144: 14000001 b 0x148 <ltmp0+0x148>
148: f85f83a9 ldur x9, [x29, #-0x8]
14c: 90000008 adrp x8, 0x0 <ltmp0>
150: f9400108 ldr x8, [x8]
154: f9400108 ldr x8, [x8]
158: eb090108 subs x8, x8, x9
15c: 1a9f17e8 cset w8, eq
160: 37000068 tbnz w8, #0x0, 0x16c <ltmp0+0x16c>
164: 14000001 b 0x168 <ltmp0+0x168>
168: 94000000 bl 0x168 <ltmp0+0x168>
16c: 52800000 mov w0, #0x0 ; =0
170: a9477bfd ldp x29, x30, [sp, #0x70]
174: 910203ff add sp, sp, #0x80
178: d65f03c0 ret

000000000000017c <\_add>:
17c: d10103ff sub sp, sp, #0x40
180: a9037bfd stp x29, x30, [sp, #0x30]
184: 9100c3fd add x29, sp, #0x30
188: f81f83a0 stur x0, [x29, #-0x8]
18c: b81f43a1 stur w1, [x29, #-0xc]
190: b81f03a2 stur w2, [x29, #-0x10]
194: f9000fe3 str x3, [sp, #0x18]
198: d2800300 mov x0, #0x18 ; =24
19c: 94000000 bl 0x19c <\_add+0x20>
1a0: f9000be0 str x0, [sp, #0x10]
1a4: b85f43a8 ldur w8, [x29, #-0xc]
1a8: f9400be9 ldr x9, [sp, #0x10]
1ac: b9000128 str w8, [x9]
1b0: b85f03a8 ldur w8, [x29, #-0x10]
1b4: f9400be9 ldr x9, [sp, #0x10]
1b8: b9000528 str w8, [x9, #0x4]
1bc: f9400fe0 ldr x0, [sp, #0x18]
1c0: 94000000 bl 0x1c0 <\_add+0x44>
1c4: 91000400 add x0, x0, #0x1
1c8: 94000000 bl 0x1c8 <\_add+0x4c>
1cc: f9400be8 ldr x8, [sp, #0x10]
1d0: f9000500 str x0, [x8, #0x8]
1d4: f9400be8 ldr x8, [sp, #0x10]
1d8: f9400500 ldr x0, [x8, #0x8]
1dc: f9400fe1 ldr x1, [sp, #0x18]
1e0: 92800002 mov x2, #-0x1 ; =-1
1e4: 94000000 bl 0x1e4 <\_add+0x68>
1e8: f9400be8 ldr x8, [sp, #0x10]
1ec: f900091f str xzr, [x8, #0x10]
1f0: f85f83a8 ldur x8, [x29, #-0x8]
1f4: f9400108 ldr x8, [x8]
1f8: f90007e8 str x8, [sp, #0x8]
1fc: f94007e8 ldr x8, [sp, #0x8]
200: f1000108 subs x8, x8, #0x0
204: 1a9f17e8 cset w8, eq
208: 37000228 tbnz w8, #0x0, 0x24c <\_add+0xd0>
20c: 14000001 b 0x210 <\_add+0x94>
210: 14000001 b 0x214 <\_add+0x98>
214: f94007e8 ldr x8, [sp, #0x8]
218: f9400908 ldr x8, [x8, #0x10]
21c: f1000108 subs x8, x8, #0x0
220: 1a9f17e8 cset w8, eq
224: 370000c8 tbnz w8, #0x0, 0x23c <\_add+0xc0>
228: 14000001 b 0x22c <\_add+0xb0>
22c: f94007e8 ldr x8, [sp, #0x8]
230: f9400908 ldr x8, [x8, #0x10]
234: f90007e8 str x8, [sp, #0x8]
238: 17fffff7 b 0x214 <\_add+0x98>
23c: f9400be8 ldr x8, [sp, #0x10]
240: f94007e9 ldr x9, [sp, #0x8]
244: f9000928 str x8, [x9, #0x10]
248: 14000005 b 0x25c <\_add+0xe0>
24c: f9400be8 ldr x8, [sp, #0x10]
250: f85f83a9 ldur x9, [x29, #-0x8]
254: f9000128 str x8, [x9]
258: 14000001 b 0x25c <\_add+0xe0>
25c: a9437bfd ldp x29, x30, [sp, #0x30]
260: 910103ff add sp, sp, #0x40
264: d65f03c0 ret

0000000000000268 <\_print>:
268: d10103ff sub sp, sp, #0x40
26c: a9037bfd stp x29, x30, [sp, #0x30]
270: 9100c3fd add x29, sp, #0x30
274: f81f83a0 stur x0, [x29, #-0x8]
278: f85f83a8 ldur x8, [x29, #-0x8]
27c: f9400108 ldr x8, [x8]
280: f81f03a8 stur x8, [x29, #-0x10]
284: 14000001 b 0x288 <\_print+0x20>
288: f85f03a8 ldur x8, [x29, #-0x10]
28c: f1000108 subs x8, x8, #0x0
290: 1a9f17e8 cset w8, eq
294: 370002c8 tbnz w8, #0x0, 0x2ec <\_print+0x84>
298: 14000001 b 0x29c <\_print+0x34>
29c: f85f03a8 ldur x8, [x29, #-0x10]
2a0: b9400108 ldr w8, [x8]
2a4: aa0803eb mov x11, x8
2a8: f85f03a8 ldur x8, [x29, #-0x10]
2ac: b9400508 ldr w8, [x8, #0x4]
2b0: aa0803ea mov x10, x8
2b4: f85f03a8 ldur x8, [x29, #-0x10]
2b8: f9400508 ldr x8, [x8, #0x8]
2bc: 910003e9 mov x9, sp
2c0: f900012b str x11, [x9]
2c4: f900052a str x10, [x9, #0x8]
2c8: f9000928 str x8, [x9, #0x10]
2cc: 90000000 adrp x0, 0x0 <ltmp0>
2d0: 91000000 add x0, x0, #0x0
2d4: 94000000 bl 0x2d4 <\_print+0x6c>
2d8: 14000001 b 0x2dc <\_print+0x74>
2dc: f85f03a8 ldur x8, [x29, #-0x10]
2e0: f9400908 ldr x8, [x8, #0x10]
2e4: f81f03a8 stur x8, [x29, #-0x10]
2e8: 17ffffe8 b 0x288 <\_print+0x20>
2ec: 90000000 adrp x0, 0x0 <ltmp0>
2f0: 91000000 add x0, x0, #0x0
2f4: 94000000 bl 0x2f4 <\_print+0x8c>
2f8: a9437bfd ldp x29, x30, [sp, #0x30]
2fc: 910103ff add sp, sp, #0x40
300: d65f03c0 ret

0000000000000304 <\_removeIsland>:
304: d10103ff sub sp, sp, #0x40
308: a9037bfd stp x29, x30, [sp, #0x30]
30c: 9100c3fd add x29, sp, #0x30
310: f81f83a0 stur x0, [x29, #-0x8]
314: f81f03a1 stur x1, [x29, #-0x10]
318: b9000fff str wzr, [sp, #0xc]
31c: f9000bff str xzr, [sp, #0x10]
320: f85f83a8 ldur x8, [x29, #-0x8]
324: f9400108 ldr x8, [x8]
328: f9000fe8 str x8, [sp, #0x18]
32c: 14000001 b 0x330 <\_removeIsland+0x2c>
330: f9400fe8 ldr x8, [sp, #0x18]
334: f1000108 subs x8, x8, #0x0
338: 1a9f17e8 cset w8, eq
33c: 37000508 tbnz w8, #0x0, 0x3dc <\_removeIsland+0xd8>
340: 14000001 b 0x344 <\_removeIsland+0x40>
344: f9400fe8 ldr x8, [sp, #0x18]
348: f9400500 ldr x0, [x8, #0x8]
34c: f85f03a1 ldur x1, [x29, #-0x10]
350: 94000000 bl 0x350 <\_removeIsland+0x4c>
354: 71000008 subs w8, w0, #0x0
358: 1a9f07e8 cset w8, ne
35c: 37000328 tbnz w8, #0x0, 0x3c0 <\_removeIsland+0xbc>
360: 14000001 b 0x364 <\_removeIsland+0x60>
364: f9400be8 ldr x8, [sp, #0x10]
368: f1000108 subs x8, x8, #0x0
36c: 1a9f17e8 cset w8, eq
370: 370000e8 tbnz w8, #0x0, 0x38c <\_removeIsland+0x88>
374: 14000001 b 0x378 <\_removeIsland+0x74>
378: f9400fe8 ldr x8, [sp, #0x18]
37c: f9400908 ldr x8, [x8, #0x10]
380: f9400be9 ldr x9, [sp, #0x10]
384: f9000928 str x8, [x9, #0x10]
388: 14000006 b 0x3a0 <\_removeIsland+0x9c>
38c: f9400fe8 ldr x8, [sp, #0x18]
390: f9400908 ldr x8, [x8, #0x10]
394: f85f83a9 ldur x9, [x29, #-0x8]
398: f9000128 str x8, [x9]
39c: 14000001 b 0x3a0 <\_removeIsland+0x9c>
3a0: 90000000 adrp x0, 0x0 <ltmp0>
3a4: 91000000 add x0, x0, #0x0
3a8: 94000000 bl 0x3a8 <\_removeIsland+0xa4>
3ac: 52800028 mov w8, #0x1 ; =1
3b0: b9000fe8 str w8, [sp, #0xc]
3b4: f9400fe0 ldr x0, [sp, #0x18]
3b8: 94000000 bl 0x3b8 <\_removeIsland+0xb4>
3bc: 14000008 b 0x3dc <\_removeIsland+0xd8>
3c0: 14000001 b 0x3c4 <\_removeIsland+0xc0>
3c4: f9400fe8 ldr x8, [sp, #0x18]
3c8: f9000be8 str x8, [sp, #0x10]
3cc: f9400fe8 ldr x8, [sp, #0x18]
3d0: f9400908 ldr x8, [x8, #0x10]
3d4: f9000fe8 str x8, [sp, #0x18]
3d8: 17ffffd6 b 0x330 <\_removeIsland+0x2c>
3dc: b9400fe8 ldr w8, [sp, #0xc]
3e0: 71000508 subs w8, w8, #0x1
3e4: 1a9f17e8 cset w8, eq
3e8: 370000c8 tbnz w8, #0x0, 0x400 <\_removeIsland+0xfc>
3ec: 14000001 b 0x3f0 <\_removeIsland+0xec>
3f0: 90000000 adrp x0, 0x0 <ltmp0>
3f4: 91000000 add x0, x0, #0x0
3f8: 94000000 bl 0x3f8 <\_removeIsland+0xf4>
3fc: 14000001 b 0x400 <\_removeIsland+0xfc>
400: b9400fe0 ldr w0, [sp, #0xc]
404: a9437bfd ldp x29, x30, [sp, #0x30]
408: 910103ff add sp, sp, #0x40
40c: d65f03c0 ret

## 用 objdump 將該目的檔的表頭印出來

命令 objdump -h 001.o
這個命令會列印出目的檔的區段表頭，包含每個區段的大小、位址、標誌等資訊。你會看到像 .text、.data、.bss 等區段的相關資訊。
**file format mach-o：**這表示這個檔案遵循 Mach-O (Mach Object) 檔案格式
**arm64：** 這表示這個目的檔包含的是針對 ARM64 架構處理器的機器碼
**Idx：** 這是區段的索引編號，從 0 開始。
**Name：** 這是區段的名稱。名稱通常以雙底線 \_\_ 開頭，後面跟著區段的邏輯名稱。
**Size：** 這是該區段的大小，以十六進制表示。
**VMA(Virtual Memory Address)：** 這是該區段在虛擬記憶體中的起始位址，以十六進制表示。在目的檔中，這個位址通常是 0，因為這些位址在連結器將多個目的檔和函式庫組合成最終可執行檔時才會被確定。
**Type：** 這是區段的類型，描述了該區段包含的內容。
結果如下：

001.o: file format mach-o arm64

Sections:
Idx Name Size VMA Type
0 **text 00000410 0000000000000000 TEXT
1 **cstring 0000003f 0000000000000410 DATA
2 \_\_compact_unwind 00000080 0000000000000450 DATA

以下我的表頭解釋
0 \_\_text 00000410 0000000000000000 TEXT

**text: 這個區段通常包含可執行程式碼 (instructions)。它是 "text" 區段的標準名稱。
00000410: 這表示 **text 區段的大小是 0x410 個位元組，換算成十進制是 1040 個位元組。
0000000000000000: 在目的檔中，**text 區段的虛擬記憶體起始位址通常是 0。
TEXT: 這明確地指出這個區段的類型是包含可執行程式碼的。
1 **cstring 0000003f 0000000000000410 DATA

**cstring: 這個區段通常包含以 null 字元結尾的 C 風格字串 (C-style strings)。例如，你在程式中使用的字串常數 (例如 printf("Hello, world!\n"); 中的 "Hello, world!\n") 會被儲存在這個區段。
0000003f: 這表示 **cstring 區段的大小是 0x3f 個位元組，換算成十進制是 63 個位元組。
0000000000000410: 這表示 **cstring 區段在虛擬記憶體中的起始位址是 0x410 (緊接著 **text 區段之後)。
DATA: 這表示這個區段包含的是已初始化的資料。
2 \_\_compact_unwind 00000080 0000000000000450 DATA

**compact_unwind: 這個區段包含緊湊的展開資訊 (compact unwind info)。展開資訊是編譯器產生的一種資料結構，用於在程式執行過程中發生異常或需要堆疊回溯 (stack unwinding) 時，能夠正確地恢復函數的執行環境。緊湊的展開格式是一種更有效率的方式來儲存這些資訊，特別是在 ARM 架構上。
00000080: 這表示 **compact_unwind 區段的大小是 0x80 個位元組，換算成十進制是 128 個位元組。
0000000000000450: 這表示 **compact_unwind 區段在虛擬記憶體中的起始位址是 0x450 (緊接著 **cstring 區段之後)。
DATA: 這表示這個區段包含的是已初始化的資料 (在這個案例中是展開資訊)。

