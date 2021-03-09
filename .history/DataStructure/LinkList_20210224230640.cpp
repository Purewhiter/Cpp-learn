/*
 * @Author      : PureWhite
 * @Date        : 2021-02-24 22:17:40
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-02-24 23:06:40
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
typedef struct LNode
{
    ElemType data;
    LNode *next;
} LNode, *LinkList;

Status InitList(LinkList &L) //初始化链表
{
    L = new LNode; //生成头结点
    L->next = NULL;
    return OK;
}
Status GetElem(LinkList L, int i, ElemType &e)
{
    LNode *p = L->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (p == NULL || j > i)
        return ERROR;
    e = p->data;
    return OK;
}
LNode *Find(LinkList L, ElemType x) //查找x，返回其地址
{
    LNode *p = p->next;
    while (p && p->data != x)
        p = p->next;
    return p;
}
Status Insert(LinkList &L,int i,ElemType x)//在第i个位置插入元素x
{
    LNode *p = L;
    int j = 0;
    while(p&&j<i-1)//p定位到第i-1个元素
    {
        p=p->next;
        j++;
    }
    if(p==NULL||j>i-1)//i>n+1或i<1
        return ERROR;
    LNode *s = new LNode;
    s->data = x;
    s->next = p->next;
    p->next = s;
    return OK;
}
Status Delete(LinkList &L,int i)//删除链表第i个元素
{
    LNode *p = L;
    int j = 0;
    while(p->next&&j<i-1)//p定位到第i-1个元素，由于第i个元素必须存在，故此处为p->next
    {
        p=p->next;
        j++;
    }
    if(p->next==NULL||j>i-1)
    return ERROR;
    LNode *q=p->next;//保存第i个元素地址，以备delete
    p->next = q->next;
    delete q;
    return OK;
}
void CreateList_H(LinkList &L,int n)//创建链表，头插法，带头结点
{
    L=new LNode;
    L->next = NULL;
    for (int i = 0; i < n;i++)
    {
        LNode *p= new LNode;
        cin >> p->data;
        p->next = L->next;
        L->next = p;
    }
}
void CreateList_T(LinkList &L,int n)//创建链表，尾插法，带头结点
{
    L= new LNode;
    L->next = NULL;
    LNode *Tail=L;//
    for (int i = 0;i<n;i++)
    {
        LNode *p=new LNode;
        cin >> p->data;
        Tail->next = p;
        p->next = NULL;
        Tail = p;
    }
}
void Display(LinkList L)
{
    LNode *p = L->next;
    while(p != NULL)
    {
        cout << p << " ";
        p=p->next;
    }
}
int main()
{
    LinkList L;
    CreateList_T(L, 10);
    Display(L);
    return 0;
}