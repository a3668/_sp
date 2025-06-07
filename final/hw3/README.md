## c4.c 內容重點

### 949 行

p = "char else enum if int return sizeof for do while "//加上 do 放入符號表
如果沒有加 do 到 p，則 next() 不會認得 do，它會當成變數，而不是關鍵字

## dowhile.c 內容重點

- sum 函數使用 dowhile 邏輯
- main 會輸出 sum(11)

### 新增

test.sh 檔案裡也新增了

```
./c4 -s test/dowhile.c
```

```
./c4 test/dowhile.c
```

##執行

```
./test.sh
```

- 執行結果裡有正確輸出 sum(11)=66

## dowhile 的執行結果如下

```
+ ./c4 -s test/dowhile.c
1: #include <stdio.h>
2:
3: // sum(n) = 1+2+...+n
4: int sum(int n)
5: {
6:     int s, i;
7:     s = 0;
  671383560:     ENT 2
  671383576:     LLA -1
  671383592:     PSH
  671383600:     IMM 0
  671383616:     SI
8:     i = 1;
  671383624:     LLA -2
  671383640:     PSH
  671383648:     IMM 1
  671383664:     SI
9:     do
10:     {
11:         s = s + i;
  671383672:     LLA -1
  671383688:     PSH
  671383696:     LLA -1
  671383712:     LI
  671383720:     PSH
  671383728:     LLA -2
  671383744:     LI
  671383752:     ADD
  671383760:     SI
12:         i++;
  671383768:     LLA -2
  671383784:     PSH
  671383792:     LI
  671383800:     PSH
  671383808:     IMM 1
  671383824:     ADD
  671383832:     SI
  671383840:     PSH
  671383848:     IMM 1
  671383864:     SUB
13:     } while (i <= n);
  671383872:     LLA -2
  671383888:     LI
  671383896:     PSH
  671383904:     LLA 2
  671383920:     LI
  671383928:     LE
  671383936:     BNZ 671383672
14:     return s;
  671383952:     LLA -1
  671383968:     LI
  671383976:     LEV
15: }
  671383984:     LEV
16:
17: int main()
18: {
19:     printf("sum(11)=%d\n", sum(11));
  671383992:     ENT 0
  671384008:     IMM 671645696
  671384024:     PSH
  671384032:     IMM 11
  671384048:     PSH
  671384056:     JSR 671383560
  671384072:     ADJ 1
  671384088:     PSH
  671384096:     PRTF
  671384104:     ADJ 2
20:     return 0;
  671384120:     IMM 0
  671384136:     LEV
```

```
+ ./c4 test/dowhile.c
sum(11)=66
exit(0) cycle = 312
```
