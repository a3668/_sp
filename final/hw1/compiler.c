#include <assert.h>
#include "compiler.h"

int E();
void STMT();
void IF();
void BLOCK();

int tempIdx = 0, labelIdx = 0;

#define nextTemp() (tempIdx++)
#define nextLabel() (labelIdx++)
#define emit printf

int isNext(char *set)
{
    char eset[SMAX], etoken[SMAX];
    sprintf(eset, " %s ", set);
    sprintf(etoken, " %s ", tokens[tokenIdx]);
    return (tokenIdx < tokenTop && strstr(eset, etoken) != NULL);
    // strstr是eset裡面是否存在etoken
}

int isEnd()
{
    return tokenIdx >= tokenTop;
    // 當前索引>=總數 is 1
}

char *next()
{
    // printf("token[%d]=%s\n", tokenIdx, tokens[tokenIdx]);
    return tokens[tokenIdx++];
    // 返回tokens後idx++
}

char *skip(char *set)
{
    if (isNext(set))
    {
        return next();
    }
    else
    {
        printf("skip(%s) got %s fail!\n", set, next());
        assert(0);
    }
}

// F = (E) | Number | Id
int F()
{
    int f;
    if (isNext("("))
    {           // '(' E ')'
        next(); // (
        f = E();
        next(); // )
    }
    else
    { // Number | Id
        f = nextTemp();
        char *item = next();
        if (isdigit(*item))
        {
            emit("t%d = %s\n", f, item);
        }
        else
        {
            if (isNext("++"))
            {
                next();
                emit("%s = %s + 1\n", item, item);
            }
            emit("t%d = %s\n", f, item);
        }
    }
    return f;
}

// E = F (op E)*
int E()
{
    int i1 = F();
    while (isNext("+ - * / & | ! < > = <= >= == !="))
    {
        char *op = next();
        int i2 = E();
        int i = nextTemp();
        emit("t%d = t%d %s t%d\n", i, i1, op, i2);
        i1 = i;
    }
    return i1;
}

// FOR =  for (ASSIGN EXP; EXP) STMT

// ASSIGN = id '=' E;
void ASSIGN()
{
    char *id = next();
    skip("=");
    int e = E();
    skip(";");
    emit("%s = t%d\n", id, e);
}

// WHILE = while (E) STMT
void WHILE()
{
    int whileBegin = nextLabel();
    int whileEnd = nextLabel();
    emit("(L%d)\n", whileBegin);
    skip("while");
    skip("(");
    int e = E();
    emit("if not T%d goto L%d\n", e, whileEnd);
    skip(")");
    STMT();
    emit("goto L%d\n", whileBegin);
    emit("(L%d)\n", whileEnd);
}

// if (EXP) STMT (else STMT)?
void IF()
{
    skip("if");
    skip("(");
    E();
    skip(")");
    STMT();
    if (isNext("else"))
    {
        skip("else");
        STMT();
    }
}

// DOWHILE = do STMT while (E);
void DOWHILE()
{
    int doBegin = nextLabel(); // 產生 do-while 迴圈開始的標籤
    int doEnd = nextLabel();   // 產生 do-while 迴圈結束的標籤

    skip("do"); // 跳過 do 關鍵字

    emit("(L%d)\n", doBegin); // 輸出開始標籤

    STMT(); // 執行 do-while 迴圈內的敘述

    // 處理 while 條件部分
    skip("while"); // 跳過 while 關鍵字
    skip("(");     // 跳過左括號 '('
    int e = E();   // 解析條件表達式，結果存入臨時變數 e
    skip(")");     // 跳過右括號 ')'
    skip(";");     // 跳過分號 ';'

    // 若條件成立，跳回 do-while 迴圈開始的標籤
    emit("if T%d goto L%d\n", e, doBegin);

    emit("(L%d)\n", doEnd); // 輸出迴圈結束的標籤
}

// STMT = WHILE | BLOCK | IF | DOWHILE | ASSIGN
void STMT()
{
    if (isNext("do"))
        DOWHILE();
    else if (isNext("while"))
        WHILE();
    else if (isNext("if"))
        IF();
    else if (isNext("{"))
        BLOCK();
    else
        ASSIGN();
}

// STMTS = STMT*
void STMTS()
{
    while (!isEnd() && !isNext("}"))
    {
        STMT();
    }
}

// BLOCK = { STMTS }
void BLOCK()
{
    skip("{");
    STMTS();
    skip("}");
}

// PROG = STMTS
void PROG()
{
    STMTS();
}

void parse()
{
    printf("============ parse =============\n");
    tokenIdx = 0;
    PROG();
}