// c4.c - C in four functions

// char, int, and pointer types
// if, while, return, and expression statements
// just enough features to allow self-compilation and a bit more

// Written by Robert Swierczek
// 修改者: 陳鍾誠 (模組化並加上中文註解)

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <unistd.h>
#include <fcntl.h>
#define int long long // 64 bit 電腦

int *e; // current position in emitted code (e: 目前機器碼指標, le: 上一行機器碼指標)
int debug = 1;

// opcodes (機器碼的 op)
enum
{
    LLA,
    IMM,
    JMP,
    JSR,
    BZ,
    BNZ,
    ENT,
    ADJ,
    LEV,
    LI,
    LC,
    SI,
    SC,
    PSH,
    OR,
    XOR,
    AND,
    EQ,
    NE,
    LT,
    GT,
    LE,
    GE,
    SHL,
    SHR,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    OPEN,
    READ,
    CLOS,
    PRTF,
    MALC,
    FREE,
    MSET,
    MCMP,
    EXIT
};

int run(int *pc, int *bp, int *sp)
{                 // 虛擬機 => pc: 程式計數器, sp: 堆疊暫存器, bp: 框架暫存器
    int a, cycle; // a: 累積器, cycle: 執行指令數
    int i, *t;    // temps

    cycle = 0;
    while (1)
    {
        i = *pc++;
        ++cycle;
        if (debug)
        {
            printf("%d> %.4s", cycle,
                   &"LLA ,IMM ,JMP ,JSR ,BZ  ,BNZ ,ENT ,ADJ ,LEV ,LI  ,LC  ,SI  ,SC  ,PSH ,"
                    "OR  ,XOR ,AND ,EQ  ,NE  ,LT  ,GT  ,LE  ,GE  ,SHL ,SHR ,ADD ,SUB ,MUL ,DIV ,MOD ,"
                    "OPEN,READ,CLOS,PRTF,MALC,FREE,MSET,MCMP,EXIT,"[i * 5]);
            if (i <= ADJ)
                printf(" %d\n", *pc);
            else
                printf("\n");
        }
        if (i == LLA)
            a = (int)(bp + *pc++); // load local address 載入區域變數
        else if (i == IMM)
            a = *pc++; // load global address or immediate 載入全域變數或立即值
        else if (i == JMP)
            pc = (int *)*pc; // jump               躍躍指令
        else if (i == JSR)
        {
            *--sp = (int)(pc + 1);
            pc = (int *)*pc;
        } // jump to subroutine 跳到副程式
        else if (i == BZ)
            pc = a ? pc + 1 : (int *)*pc; // branch if zero     if (a==0) goto m[pc]
        else if (i == BNZ)
            pc = a ? (int *)*pc : pc + 1; // branch if not zero if (a!=0) goto m[pc]
        else if (i == ENT)
        {
            *--sp = (int)bp;
            bp = sp;
            sp = sp - *pc++;
        } // enter subroutine   進入副程式
        else if (i == ADJ)
            sp = sp + *pc++; // stack adjust       調整堆疊
        else if (i == LEV)
        {
            sp = bp;
            bp = (int *)*sp++;
            pc = (int *)*sp++;
        } // leave subroutine   離開副程式
        else if (i == LI)
            a = *(int *)a; // load int           載入整數
        else if (i == LC)
            a = *(char *)a; // load char          載入字元
        else if (i == SI)
            *(int *)*sp++ = a; // store int          儲存整數
        else if (i == SC)
            a = *(char *)*sp++ = a; // store char         儲存字元
        else if (i == PSH)
            *--sp = a; // push               推入堆疊

        else if (i == OR)
            a = *sp++ | a; // a = a OR *sp
        else if (i == XOR)
            a = *sp++ ^ a; // a = a XOR *sp
        else if (i == AND)
            a = *sp++ & a; // ...
        else if (i == EQ)
            a = *sp++ == a;
        else if (i == NE)
            a = *sp++ != a;
        else if (i == LT)
            a = *sp++ < a;
        else if (i == GT)
            a = *sp++ > a;
        else if (i == LE)
            a = *sp++ <= a;
        else if (i == GE)
            a = *sp++ >= a;
        else if (i == SHL)
            a = *sp++ << a;
        else if (i == SHR)
            a = *sp++ >> a;
        else if (i == ADD)
            a = *sp++ + a;
        else if (i == SUB)
            a = *sp++ - a;
        else if (i == MUL)
            a = *sp++ * a;
        else if (i == DIV)
            a = *sp++ / a;
        else if (i == MOD)
            a = *sp++ % a;

        else if (i == OPEN)
            a = open((char *)sp[1], *sp); // 開檔
        else if (i == READ)
            a = read(sp[2], (char *)sp[1], *sp); // 讀檔
        else if (i == CLOS)
            a = close(*sp); // 關檔
        else if (i == PRTF)
        {
            t = sp + pc[1];
            a = printf((char *)t[-1], t[-2], t[-3], t[-4], t[-5], t[-6]);
        } // printf("....", a, b, c, d, e)
        else if (i == MALC)
            a = (int)malloc(*sp); // 分配記憶體
        else if (i == FREE)
            free((void *)*sp); // 釋放記憶體
        else if (i == MSET)
            a = (int)memset((char *)sp[2], sp[1], *sp); // 設定記憶體
        else if (i == MCMP)
            a = memcmp((char *)sp[2], (char *)sp[1], *sp); // 比較記憶體
        else if (i == EXIT)
        {
            printf("exit(%d) cycle = %d\n", *sp, cycle);
            return *sp;
        } // EXIT 離開
        else
        {
            printf("unknown instruction = %d! cycle = %d\n", i, cycle);
            return -1;
        } // 錯誤處理
    }
}

int main() // 主程式
{
    int *pc;     // pc 負責讀取並解釋下一條指令
    int *power2; // pow 存放 函數的機器碼起始位址
    int *bp, *sp, poolsz, *t, *loc;

    poolsz = 256 * 1024; // arbitrary size
    if (!(e = malloc(poolsz)))
    {
        printf("could not malloc(%d) text area\n", poolsz);
        return -1;
    } // 程式段
    if (!(sp = malloc(poolsz)))
    {
        printf("could not malloc(%d) stack area\n", poolsz);
        return -1;
    } // 堆疊段

    memset(e, 0, poolsz);

    //  int power2(int n)
    // if(n == 0)return 1
    power2 = e;
    *e++ = ENT; // 將 ENT 存入 e 指向的位置,e 指向下一個機器碼存放位置
    *e++ = 0;   // 存入 0（表示分配 0 個區域變數），e 再次移動

    *e++ = LLA; // 載入區域變數的地址
    *e++ = 2;   // LLA 2 代表「載入 bp + 2 的地址」，也就是 n 的位置。

    *e++ = LI;  // 載入整數
    *e++ = PSH; // 推入堆疊 (準備比較)

    *e++ = IMM; // 將 0 載入 a
    *e++ = 0;   // 載入 `0`，準備與 `n` 比較

    *e++ = EQ; // a = 0 n = 0,如果相等a 就變1,當 n 不等於 0時，EQ 會產生 a = 0
    // BZ 會檢查到 a == 0，就會跳轉到遞迴處理 return 2 * power2(n - 1) 的那段機器碼。
    *e++ = BZ;
    loc = e;  // 的作用是記錄 BZ 指令存放的位置，方便稍後回填跳轉地址
    *e++ = 0; // 存放跳轉地址的位置
    /*
     在編譯 if (n == 0) return 1; 這類條件語句時：
     當下還不知道 return 1; 這段機器碼的位置
     所以 BZ 指令的跳轉地址還無法確定
     我們先讓 loc 存放 BZ 指令的地址，稍後再填充正確的跳轉位址
    */
    *e++ = IMM;
    *e++ = 1;
    *e++ = LEV; // 離開副程式

    // return 2 * power2(n - 1);
    *loc = (int)e;
    *e++ = LLA;
    *e++ = 2;  // 讀取n的地址
    *e++ = LI; // 取得n的值//LI 會從 a 指向的地址讀取值，這樣 a 就會存放 n 的值。
    *e++ = PSH;

    *e++ = IMM;
    *e++ = 1;   // 載入 `1`
    *e++ = SUB; // 計算 `n - 1`（`a = a - pop()`）

    *e++ = PSH; // 推入堆疊，準備當作 `power2(n - 1)` 的參數
    *e++ = JSR;
    *e++ = (int)power2; // 呼叫 `power2(n - 1)`

    *e++ = PSH; // 將 `power2(n - 1)` 的結果推入堆疊
    *e++ = IMM;
    *e++ = 2;   // 載入 `2`
    *e++ = MUL; // 計算 `2 * power2(n - 1)`

    *e++ = LEV; // 返回結果

    // 9: int main() {
    // 10:   printf("power2(3)=%d\n", power2(3));
    pc = e;
    *e++ = ENT;
    *e++ = 0;
    *e++ = IMM;
    *e++ = (int)"power2(3)=%d\n";
    *e++ = PSH;
    *e++ = IMM;
    *e++ = 3;
    *e++ = PSH;
    *e++ = JSR;
    *e++ = (int)power2;
    *e++ = ADJ;
    *e++ = 1;
    *e++ = PSH;
    *e++ = PRTF;
    *e++ = ADJ;
    *e++ = 2;
    // 11: }
    *e++ = LEV;

    // setup stack
    bp = sp = (int *)((int)sp + poolsz);
    *--sp = EXIT; // call exit if main returns
    *--sp = PSH;
    t = sp;
    *--sp = (int)t;
    return run(pc, bp, sp);
}