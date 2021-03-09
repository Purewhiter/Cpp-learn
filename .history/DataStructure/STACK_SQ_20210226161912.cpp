/*
 * @Author      : PureWhite
 * @Date        : 2021-02-25 22:11:08
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-02-26 16:18:38
 * @Description : 
 */
#include <iostream>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100
using namespace std;
typedef char SElemType;
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
    if (S.base == NULL)
        exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}
Status Push(Sqstack &S, SElemType x)
{
    if (S.top - S.base == S.stacksize)
        return ERROR;
    *S.top++ = x;
    return OK;
}
SElemType GetTop(Sqstack S)
{
    if (S.top != S.base)
        return *(S.top - 1);
}
Status Pop(Sqstack &S, SElemType &e)
{
    if (S.top == S.base)
        return ERROR;
    e = *--S.top;
    return OK;
}
Status StackEmpty(Sqstack S)
{
    return S.top == S.base;
}
// void convert(int N)
// {
//     Sqstack S;
//     int e;
//     InitStack(S);
//     while (N)
//     {
//         Push(S, N % 8);
//         N /= 8;
//     }
//     while (!StackEmpty(S))
//     {
//         Pop(S, e);
//         cout << e;
//     }
//     cout << endl;
// }
void Matching()
{
    Sqstack S;
    InitStack(S);
    int flag = 1;
    char ch, x;
    cin >> ch;
    while (ch != '#' && flag)
    {
        switch (ch)
        {
        case '(' || '[':
            Push(S, ch);
            break;
        case ')':
            if (!StackEmpty(S) && GetTop(S) == ')')
                Pop(S, x);
            else
                flag = 0;
            break;
        case ']':
            if (!StackEmpty(S) && GetTop(S) == ']')
                Pop(S, x);
            else
                flag = 0;
            break;
        }
        cin >> ch;
    }
    if (StackEmpty(S) && flag)
        cout<<"Matching success!"<<endl;
    else cout<<"failed!"<<endl;
}
int main()
{
    // Sqstack S;
    // InitStack(S);
    // Push(S, 2);
    // Push(S, 3);
    // cout << GetTop(S);
    // convert(1348);
    Matching();
    return 0;
}