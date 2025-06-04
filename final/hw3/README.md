./test.sh

### 949

p = "char else enum if int return sizeof for do while "//加上 do 放入符號表
如果沒有加 do 到 p，則 next() 不會認得 do，它會當成變數，而不是關鍵字
