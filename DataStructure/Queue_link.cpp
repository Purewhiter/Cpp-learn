/*
 * @Author      : PureWhite
 * @Date        : 2021-02-26 14:49:55
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-02-26 15:13:16
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
typedef struct QNode
{
    ElemType data;
    struct QNode *next;
} QNode, *QueuePtr;
typedef struct
{
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

Status InitQueue(LinkQueue &Q) //初始化带头结点链队
{
    Q.front = Q.rear = new QNode;
    Q.front->next = NULL;
    return OK;
}
Status EnQueue(LinkQueue &Q, ElemType x) //入队
{
    QueuePtr p = new QNode;
    p->data = x;
    Q.rear->next = p;
    Q.rear = p;
    p->next = NULL;
    return OK;
}
Status DeQueue(LinkQueue &Q, ElemType &e) //出队
{
    if (Q.front == Q.rear) //队空
        return ERROR;
    QueuePtr p = Q.front->next; //p指向队头元素
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) //如果删除的是最后一个元素，则将尾指针指向头结点
        Q.rear = Q.front;
    delete p;
    return OK;
}
ElemType GetHead(LinkQueue Q)
{
    if (Q.front != Q.rear)
        return Q.front->next->data;
}

Status DestroyQueue(LinkQueue &Q) //销毁队列
{
    while (Q.front)
    {
        Q.rear = Q.front->next;
        delete Q.front;
        Q.front = Q.rear;
    }
    return OK;
}
void Display(LinkQueue Q)
{
    QueuePtr p=Q.front->next;
    while(p)
    {
        cout << p->data << " ";
        p=p->next;
    }
    cout << endl;
}
int main()
{
    LinkQueue Q;
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