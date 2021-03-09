/*
 * @Author      : PureWhite
 * @Date        : 2021-02-25 22:37:11
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-02-25 22:53:44
 * @Description : 
 */
#include <iostream>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100
using namespace std;
typedef int ElemType;
typedef int Status;
typedef struct StackNode
{
    ElemType data;
    StackNode *next;
} StackNode, *LinkStack;

Status InitStack(LinkStack &S)
{
    S = NULL;
    return OK;
}
Status Push(LinkStack &S,ElemType x)
{
    StackNode *p = new StackNode;
    p->data = x;
    p->next = S;
    S = p;
    return OK;
}
Status Pop(LinkStack &S,ElemType&e)
{
    if(S == NULL)
    return ERROR;
    e=S->data;
    StackNode *p = S;
    S=S->next;
    delete p;
    return OK;
}
ElemType GetTop(LinkStack &S)
{
    if(S!=NULL)
        return S->data;
}
int main()
{
    LinkStack S;
    InitStack(S);
    Push(S, 9);
    Push(S, 8);
    int e;
    Pop(S, e);
    cout << e << endl;
    cout<<GetTop(S) << endl;
    return 0;
}