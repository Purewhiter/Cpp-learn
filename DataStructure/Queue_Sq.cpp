/*
 * @Author      : PureWhite
 * @Date        : 2021-02-25 23:37:02
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-02-26 14:48:08
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
typedef struct
{
    ElemType *base;
    int front;
    int rear;
} SqQueue;

Status InitQueue(SqQueue &Q)
{
    Q.base=new ElemType[MAXSIZE];
    if(Q.base==NULL)
        exit(OVERFLOW);
    Q.front = Q.rear = 0;
    return OK;
}
int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;//留出一个空位判断队满，故最大长度为MAXSIZE-1
}
Status EnQueue(SqQueue &Q,ElemType x)
{
    if((Q.rear+1)%MAXSIZE==Q.front)
        return ERROR;//队满
    Q.base[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MAXSIZE;
    return OK;
}
Status DeQueue(SqQueue &Q,ElemType &e)
{
    if(Q.rear==Q.front)//队空
        return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
    return OK;
}
ElemType GetHead(SqQueue Q)
{
    if(Q.front!=Q.rear)
        return Q.base[Q.front];
}
void Display(SqQueue Q)
{
    int q = Q.front;
    while(q!=Q.rear)
    {
        cout << Q.base[q]<<" ";
        q = (q + 1) % MAXSIZE;
    }
    cout << endl;
}
int main()
{
    SqQueue Q;
    int q;
    InitQueue(Q);
    for (int i = 1; i <= 10;i++)
        EnQueue(Q, i);
    Display(Q);
    for (int i = 5; i >= 1;i--)
        DeQueue(Q,q);
    Display(Q);
    for (int i = 5; i >= 1;i--)
        EnQueue(Q, i);
    Display(Q);
    return 0;
}