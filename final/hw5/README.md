```
gcc -S b.c
```

只產生組合語言，不產生目標檔案也不連結  
再來檢查函數是否有在組合語言裡出現  
檢查 .globl *函數名 是否出現  
檢查 *函數名: 標籤是否出現  

## mymin 函數

```
	.globl	_mymin                          ; -- Begin function mymin
	.p2align	2
_mymin:                                 ; @mymin
```

## mymax 函數

```
	.globl	_mymax                          ; -- Begin function mymax
	.p2align	2
_mymax:                                 ; @mymax
```

## maxCap 函數

```
	.globl	_maxCap                         ; -- Begin function maxCap
	.p2align	2
_maxCap:                                ; @maxCap
```

## 進行編譯

```
gcc -c b.c
```

## 用 objdump 將該目的檔反組譯

```
objdump -d b.o
```

這個命令會將機器碼轉換回組合語言指令並顯示在終端機上。你會看到程式碼區段（通常是 .text 區段）的反組譯結果。

```
b.o: file format mach-o arm64

Disassembly of section **TEXT,**text:

0000000000000000 <ltmp0>:
0: d10043ff sub sp, sp, #0x10
4: b9000be0 str w0, [sp, #0x8]
8: b90007e1 str w1, [sp, #0x4]
c: b9400be8 ldr w8, [sp, #0x8]
10: b94007e9 ldr w9, [sp, #0x4]
14: 6b090108 subs w8, w8, w9
18: 1a9fb7e8 cset w8, ge
1c: 370000a8 tbnz w8, #0x0, 0x30 <ltmp0+0x30>
20: 14000001 b 0x24 <ltmp0+0x24>
24: b9400be8 ldr w8, [sp, #0x8]
28: b9000fe8 str w8, [sp, #0xc]
2c: 14000004 b 0x3c <ltmp0+0x3c>
30: b94007e8 ldr w8, [sp, #0x4]
34: b9000fe8 str w8, [sp, #0xc]
38: 14000001 b 0x3c <ltmp0+0x3c>
3c: b9400fe0 ldr w0, [sp, #0xc]
40: 910043ff add sp, sp, #0x10
44: d65f03c0 ret

0000000000000048 <\_mymax>:
48: d10043ff sub sp, sp, #0x10
4c: b9000be0 str w0, [sp, #0x8]
50: b90007e1 str w1, [sp, #0x4]
54: b9400be8 ldr w8, [sp, #0x8]
58: b94007e9 ldr w9, [sp, #0x4]
5c: 6b090108 subs w8, w8, w9
60: 1a9fc7e8 cset w8, le
64: 370000a8 tbnz w8, #0x0, 0x78 <\_mymax+0x30>
68: 14000001 b 0x6c <\_mymax+0x24>
6c: b9400be8 ldr w8, [sp, #0x8]
70: b9000fe8 str w8, [sp, #0xc]
74: 14000004 b 0x84 <\_mymax+0x3c>
78: b94007e8 ldr w8, [sp, #0x4]
7c: b9000fe8 str w8, [sp, #0xc]
80: 14000001 b 0x84 <\_mymax+0x3c>
84: b9400fe0 ldr w0, [sp, #0xc]
88: 910043ff add sp, sp, #0x10
8c: d65f03c0 ret

0000000000000090 <\_maxCap>:
90: d100c3ff sub sp, sp, #0x30
94: a9027bfd stp x29, x30, [sp, #0x20]
98: 910083fd add x29, sp, #0x20
9c: f81f83a0 stur x0, [x29, #-0x8]
a0: b81f43a1 stur w1, [x29, #-0xc]
a4: b90013ff str wzr, [sp, #0x10]
a8: b85f43a8 ldur w8, [x29, #-0xc]
ac: 71000508 subs w8, w8, #0x1
b0: b9000fe8 str w8, [sp, #0xc]
b4: b9000bff str wzr, [sp, #0x8]
b8: 14000001 b 0xbc <\_maxCap+0x2c>
bc: b94013e8 ldr w8, [sp, #0x10]
c0: b9400fe9 ldr w9, [sp, #0xc]
c4: 6b090108 subs w8, w8, w9
c8: 1a9fb7e8 cset w8, ge
cc: 370004a8 tbnz w8, #0x0, 0x160 <\_maxCap+0xd0>
d0: 14000001 b 0xd4 <\_maxCap+0x44>
d4: f85f83a8 ldur x8, [x29, #-0x8]
d8: b98013e9 ldrsw x9, [sp, #0x10]
dc: b8697900 ldr w0, [x8, x9, lsl #2]
e0: f85f83a8 ldur x8, [x29, #-0x8]
e4: b9800fe9 ldrsw x9, [sp, #0xc]
e8: b8697901 ldr w1, [x8, x9, lsl #2]
ec: 94000000 bl 0xec <\_maxCap+0x5c>
f0: b9400fe8 ldr w8, [sp, #0xc]
f4: b94013e9 ldr w9, [sp, #0x10]
f8: 6b090108 subs w8, w8, w9
fc: 1b087c08 mul w8, w0, w8
100: b90007e8 str w8, [sp, #0x4]
104: b9400be0 ldr w0, [sp, #0x8]
108: b94007e1 ldr w1, [sp, #0x4]
10c: 94000000 bl 0x10c <\_maxCap+0x7c>
110: b9000be0 str w0, [sp, #0x8]
114: f85f83a8 ldur x8, [x29, #-0x8]
118: b98013e9 ldrsw x9, [sp, #0x10]
11c: b8697908 ldr w8, [x8, x9, lsl #2]
120: f85f83a9 ldur x9, [x29, #-0x8]
124: b9800fea ldrsw x10, [sp, #0xc]
128: b86a7929 ldr w9, [x9, x10, lsl #2]
12c: 6b090108 subs w8, w8, w9
130: 1a9fb7e8 cset w8, ge
134: 370000c8 tbnz w8, #0x0, 0x14c <\_maxCap+0xbc>
138: 14000001 b 0x13c <\_maxCap+0xac>
13c: b94013e8 ldr w8, [sp, #0x10]
140: 11000508 add w8, w8, #0x1
144: b90013e8 str w8, [sp, #0x10]
148: 14000005 b 0x15c <\_maxCap+0xcc>
14c: b9400fe8 ldr w8, [sp, #0xc]
150: 71000508 subs w8, w8, #0x1
154: b9000fe8 str w8, [sp, #0xc]
158: 14000001 b 0x15c <\_maxCap+0xcc>
15c: 17ffffd8 b 0xbc <\_maxCap+0x2c>
160: b9400be0 ldr w0, [sp, #0x8]
164: a9427bfd ldp x29, x30, [sp, #0x20]
168: 9100c3ff add sp, sp, #0x30
16c: d65f03c0 ret

0000000000000170 <\_main>:
170: d10183ff sub sp, sp, #0x60
174: a9057bfd stp x29, x30, [sp, #0x50]
178: 910143fd add x29, sp, #0x50
17c: 90000008 adrp x8, 0x0 <ltmp0>
180: f9400108 ldr x8, [x8]
184: f9400108 ldr x8, [x8]
188: f81f83a8 stur x8, [x29, #-0x8]
18c: b90023ff str wzr, [sp, #0x20]
190: 910093e0 add x0, sp, #0x24
194: f9000be0 str x0, [sp, #0x10]
198: d2800482 mov x2, #0x24 ; =36
19c: 90000001 adrp x1, 0x0 <ltmp0>
1a0: 91000021 add x1, x1, #0x0
1a4: 94000000 bl 0x1a4 <\_main+0x34>
1a8: f9400be0 ldr x0, [sp, #0x10]
1ac: 52800128 mov w8, #0x9 ; =9
1b0: b9001fe8 str w8, [sp, #0x1c]
1b4: b9401fe1 ldr w1, [sp, #0x1c]
1b8: 94000000 bl 0x1b8 <\_main+0x48>
1bc: b9001be0 str w0, [sp, #0x18]
1c0: b9401be9 ldr w9, [sp, #0x18]
1c4: aa0903e8 mov x8, x9
1c8: 910003e9 mov x9, sp
1cc: f9000128 str x8, [x9]
1d0: 90000000 adrp x0, 0x0 <ltmp0>
1d4: 91000000 add x0, x0, #0x0
1d8: 94000000 bl 0x1d8 <\_main+0x68>
1dc: f85f83a9 ldur x9, [x29, #-0x8]
1e0: 90000008 adrp x8, 0x0 <ltmp0>
1e4: f9400108 ldr x8, [x8]
1e8: f9400108 ldr x8, [x8]
1ec: eb090108 subs x8, x8, x9
1f0: 1a9f17e8 cset w8, eq
1f4: 37000068 tbnz w8, #0x0, 0x200 <\_main+0x90>
1f8: 14000001 b 0x1fc <\_main+0x8c>
1fc: 94000000 bl 0x1fc <\_main+0x8c>
200: 52800000 mov w0, #0x0 ; =0
204: a9457bfd ldp x29, x30, [sp, #0x50]
208: 910183ff add sp, sp, #0x60
20c: d65f03c0 ret
```

---

## 用 objdump 將該目的檔的表頭印出來

```
objdump -h b.o
```

```
b.o: file format mach-o arm64

Sections:
Idx Name Size VMA Type
0 **text 00000210 0000000000000000 TEXT
1 **const 00000024 0000000000000210 DATA
2 **cstring 00000012 0000000000000234 DATA
3 **compact_unwind 00000080 0000000000000248 DATA
```

Idx：區段索引（從 0 開始編號），方便參考與程式碼定位  
Name：區段名稱
Size：區段大小，表示這個區段在檔案或記憶體中所佔的位元組數
VMA：這個區段在執行時載入到記憶體的起始位址
Type：區段類型：TEXT 或 DATA
前兩個是機器碼（.text）和常數資料（.const），
接著是字串區段（.cstring），儲存程式中用到的 C 字串，
最後是用於例外與呼叫堆疊還原的精簡 unwind 資料（.compact_unwind）。
