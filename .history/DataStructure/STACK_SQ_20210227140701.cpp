/*
 * @Author      : PureWhite
 * @Date        : 2021-02-25 22:11:08
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-02-26 16:36:57
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
        case '(':
            Push(S, ch);
            break;
        case '[':
            Push(S, ch);
            break;
        case ')':
            if (!StackEmpty(S) && GetTop(S) == '(')
                Pop(S, x);
            else
                flag = 0;
            break;
        case ']':
            if (!StackEmpty(S) && GetTop(S) == '[')
                Pop(S, x);
            else
                flag = 0;
            break;
        }
        cin >> ch;
    }
    if (StackEmpty(S) && flag)
        cout << "Matching success!" << endl;
    else
        cout << "failed!" << endl;
}
Status In(char x)
{}
char Precede(char x,char y)
{}
int Operate(int a,char theta,int b)
{}
char EvaluateExpression()//中缀表达式转为后缀表达式，然后运算
{
    Sqstack OPND, OPTR;
    int a, b;
    char theta;
    Push(OPTR, '#');
    cin >> ch;
    while(ch!='#'||GetTop(OPTR)!='#')
    {
        if(!In(ch))
        {
            Push(OPND, ch);
            cin >> ch;
        }
        else
            switch (Precede(GetTop(OPTR),ch))
            {
                case '<':
                    Push(OPTR, ch);
                    cin >> ch;
                    break;
                case '>':
                    Pop(OPTR,theta);
                    Pop(OPND, b);
                    Pop(OPND, a);
                    Push(OPND, Operate(a, theta, b));
                    break;
                case '=':
                    Pop(OPTR, x);
                    cin >> ch;
                    break;
            }
    }
    return GetTop(OPND);
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