/*
 * @Author      : PureWhite
 * @Date        : 2021-02-25 22:11:08
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-02-26 16:05:11
 * @Description : 
 */
#include <iostream>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100
using namespace std;
typedef int SElemType;
typedef int Status;
typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
} Sqstack;
Status InitStack(Sqstack &S)
{
    S.base = new SElemType[MAXSIZE];
    if(S.base == NULL)
        exit(OVERFLOW);
    S.top=S.base;
    S.stacksize = MAXSIZE;
    return OK;
}
Status Push(Sqstack &S,SElemType x)
{
    if(S.top-S.base==S.stacksize)
        return ERROR;
    *S.top++ = x;
    return OK;
}
SElemType GetTop(Sqstack S)
{
    if(S.top!=S.base)
        return *(S.top - 1);
}
Status Pop(Sqstack &S,SElemType&e)
{
    if(S.top==S.base)
        return ERROR;
    e = *--S.top;
    return OK;
}
Status StackEmpty(Sqstack S)
{
    return S.top == S.base;
}
void convert(int N)
{
    Sqstack S;
    int e;
    InitStack(S);
    while(N)
    {
        Push(S, S % 8);
        S /= 8;
    }
    while(!StackEmpty(S))
    {
        Pop(S, e);
        cout << e;
    }
    cout << endl;
}
int main()
{
    // Sqstack S;
    // InitStack(S);
    // Push(S, 2);
    // Push(S, 3);
    // cout << GetTop(S);
    convert(1348);
    return 0;
}