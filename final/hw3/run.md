- gcc -g -w c4.c -o c4
- ./c4 -s hello.c
  1: #include <stdio.h>
  2:
  3: int main()
  4: {
  5: printf("hello, world\n");
  671383560: ENT 0
  671383576: IMM 671645696
  671383592: PSH
  671383600: PRTF
  671383608: ADJ 1
  6: return 0;
  671383624: IMM 0
  671383640: LEV
  7: }
  671383648: LEV
- ./c4 -s test/fib.c
  1: #include <stdio.h>
  2:
  3: int f(int n) {
  4: if (n<=0) return 0;
  1610907656: ENT 0
  1610907672: LLA 2
  1610907688: LI  
   1610907696: PSH
  1610907704: IMM 0
  1610907720: LE  
   1610907728: BZ 0
  1610907744: IMM 0
  1610907760: LEV
  5: if (n==1) return 1;
  1610907768: LLA 2
  1610907784: LI  
   1610907792: PSH
  1610907800: IMM 1
  1610907816: EQ  
   1610907824: BZ 0
  1610907840: IMM 1
  1610907856: LEV
  6: return f(n-1) + f(n-2);
  1610907864: LLA 2
  1610907880: LI  
   1610907888: PSH
  1610907896: IMM 1
  1610907912: SUB
  1610907920: PSH
  1610907928: JSR 1610907656
  1610907944: ADJ 1
  1610907960: PSH
  1610907968: LLA 2
  1610907984: LI  
   1610907992: PSH
  1610908000: IMM 2
  1610908016: SUB
  1610908024: PSH
  1610908032: JSR 1610907656
  1610908048: ADJ 1
  1610908064: ADD
  1610908072: LEV
  7: }
  1610908080: LEV
  8:
  9: int main() {
  10: printf("f(7)=%d\n", f(7));
  1610908088: ENT 0
  1610908104: IMM 1611169792
  1610908120: PSH
  1610908128: IMM 7
  1610908144: PSH
  1610908152: JSR 1610907656
  1610908168: ADJ 1
  1610908184: PSH
  1610908192: PRTF
  1610908200: ADJ 2
  11: }
  1610908216: LEV
- ./c4 -s test/sum.c
  1: #include <stdio.h>
  2:
  3: // sum(n) = 1+2+...+n
  4: int sum(int n) {
  5: int s;
  6: int i;
  7: s=0;
  1342472200: ENT 2
  1342472216: LLA -1
  1342472232: PSH
  1342472240: IMM 0
  1342472256: SI  
  8: i=1;
  1342472264: LLA -2
  1342472280: PSH
  1342472288: IMM 1
  1342472304: SI  
  9: while (i <= n) {
  1342472312: LLA -2
  1342472328: LI  
   1342472336: PSH
  1342472344: LLA 2
  1342472360: LI  
   1342472368: LE  
   1342472376: BZ 0
  10: s = s + i;
  1342472392: LLA -1
  1342472408: PSH
  1342472416: LLA -1
  1342472432: LI  
   1342472440: PSH
  1342472448: LLA -2
  1342472464: LI  
   1342472472: ADD
  1342472480: SI  
  11: i ++;
  1342472488: LLA -2
  1342472504: PSH
  1342472512: LI  
   1342472520: PSH
  1342472528: IMM 1
  1342472544: ADD
  1342472552: SI  
   1342472560: PSH
  1342472568: IMM 1
  1342472584: SUB
  12: }
  13: return s;
  1342472592: JMP 1342472312
  1342472608: LLA -1
  1342472624: LI  
   1342472632: LEV
  14: }
  1342472640: LEV
  15:
  16: int main() {
  17: printf("sum(10)=%d\n", sum(10));
  1342472648: ENT 0
  1342472664: IMM 1342734336
  1342472680: PSH
  1342472688: IMM 10
  1342472704: PSH
  1342472712: JSR 1342472200
  1342472728: ADJ 1
  1342472744: PSH
  1342472752: PRTF
  1342472760: ADJ 2
  18: return 0;
  1342472776: IMM 0
  1342472792: LEV
  19: }
  1342472800: LEV
- ./c4 -s test/for.c
  1: #include <stdio.h>
  2:
  3: // sum(n) = 1+2+...+n
  4: int sum(int n) {
  5: int s, i;
  6: s = 0;
  671383560: ENT 2
  671383576: LLA -1
  671383592: PSH
  671383600: IMM 0
  671383616: SI  
  7: for (i=1;i <= n; i++) {
  671383624: LLA -2
  671383640: PSH
  671383648: IMM 1
  671383664: SI  
   671383672: LLA -2
  671383688: LI  
   671383696: PSH
  671383704: LLA 2
  671383720: LI  
   671383728: LE  
   671383736: BZ 0
  671383752: JMP 671383888
  671383768: LLA -2
  671383784: PSH
  671383792: LI  
   671383800: PSH
  671383808: IMM 1
  671383824: ADD
  671383832: SI  
   671383840: PSH
  671383848: IMM 1
  671383864: SUB
  671383872: JMP 671383672
  8: s = s + i;
  671383888: LLA -1
  671383904: PSH
  671383912: LLA -1
  671383928: LI  
   671383936: PSH
  671383944: LLA -2
  671383960: LI  
   671383968: ADD
  671383976: SI  
  9: }
  10: return s;
  671383984: JMP 671383768
  671384000: LLA -1
  671384016: LI  
   671384024: LEV
  11: }
  671384032: LEV
  12:
  13: int main() {
  14: printf("sum(10)=%d\n", sum(10));
  671384040: ENT 0
  671384056: IMM 671645696
  671384072: PSH
  671384080: IMM 10
  671384096: PSH
  671384104: JSR 671383560
  671384120: ADJ 1
  671384136: PSH
  671384144: PRTF
  671384152: ADJ 2
  15: return 0;
  671384168: IMM 0
  671384184: LEV
  16: }
  671384192: LEV
- ./c4 -s test/dowhile.c
  1: #include <stdio.h>
  2:
  3: // sum(n) = 1+2+...+n
  4: int sum(int n)
  5: {
  6: int s, i;
  7: s = 0;
  1342472200: ENT 2
  1342472216: LLA -1
  1342472232: PSH
  1342472240: IMM 0
  1342472256: SI  
  8: i = 1;
  1342472264: LLA -2
  1342472280: PSH
  1342472288: IMM 1
  1342472304: SI  
  9: do
  10: {
  11: s = s + i;
  1342472312: LLA -1
  1342472328: PSH
  1342472336: LLA -1
  1342472352: LI  
   1342472360: PSH
  1342472368: LLA -2
  1342472384: LI  
   1342472392: ADD
  1342472400: SI  
  12: i++;
  1342472408: LLA -2
  1342472424: PSH
  1342472432: LI  
   1342472440: PSH
  1342472448: IMM 1
  1342472464: ADD
  1342472472: SI  
   1342472480: PSH
  1342472488: IMM 1
  1342472504: SUB
  13: } while (i <= n);
  1342472512: LLA -2
  1342472528: LI  
   1342472536: PSH
  1342472544: LLA 2
  1342472560: LI  
   1342472568: LE  
   1342472576: BNZ 1342472312
  14: return s;
  1342472592: LLA -1
  1342472608: LI  
   1342472616: LEV
  15: }
  1342472624: LEV
  16:
  17: int main()
  18: {
  19: printf("sum(11)=%d\n", sum(11));
  1342472632: ENT 0
  1342472648: IMM 1342734336
  1342472664: PSH
  1342472672: IMM 11
  1342472688: PSH
  1342472696: JSR 1342472200
  1342472712: ADJ 1
  1342472728: PSH
  1342472736: PRTF
  1342472744: ADJ 2
  20: return 0;
  1342472760: IMM 0
  1342472776: LEV
- ./c4 test/for.c
  sum(10)=55
  exit(0) cycle = 323
- ./c4 test/dowhile.c
  sum(11)=66
  exit(0) cycle = 312
- ./c4 c4.c hello.c
  hello, world
  exit(0) cycle = 9
  exit(0) cycle = 29996
- ./c4 c4.c c4.c hello.c
  hello, world
  exit(0) cycle = 9
  exit(0) cycle = 29996
  exit(0) cycle = 13826800
