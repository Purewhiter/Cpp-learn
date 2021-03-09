/*
 * @Author      : PureWhite
 * @Date        : 2020-11-15 11:02:33
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-02-25 18:26:24
 * @Description : 顺序表实现
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
    ElemType *elem;
    int length;
}SqList;

Status InitList(SqList &L)//初始化顺序表
{
    L.elem=new ElemType[MAXSIZE];
    if(L.elem==NULL)
        exit(OVERFLOW);
    L.length = 0;
    return OK;
}

Status DestroyList(SqList &L)//删除顺序表
{
    if(L.elem==NULL)
        return ERROR;
    delete []L.elem;
    L.length = 0;
    return OK;
}
Status ClearList(SqList &L)//清空顺序表
{
    if(L.elem==NULL)
        return ERROR;
    L.length = 0;
    return OK;
}
ElemType GetElem(SqList L, int i)//顺序表取值
{
    if (i < 1 || i > L.length)
        return ERROR;
    return L.elem[i - 1];
}

int LocateElem(SqList L, ElemType x)//查找元素x
{
    for (int i = 0; i < L.length; i++)
        if (L.elem[i] == x)
            return i + 1;
    return ERROR;
}

Status Insert(SqList &L, int i, ElemType x)
{
    if (i < 1 || i > L.length + 1)
    {
        cout << "位置不合法！";
        return ERROR;
    }
    if (L.length == MAXSIZE)
    {
        cout << "空间已满！";
        return ERROR;
    }
    for (int j = L.length - 1; j >= i - 1; j--)
    {
        L.elem[j + 1] = L.elem[j];
    }
    L.elem[i - 1] = x;
    L.length++;
    cout << "插入成功！\n";
    return OK;
}

Status Delete(SqList &L, int i)
{
    if (i < 1 || i > L.length)
    {
        cout << "位置不合法！";
        return ERROR;
    }
    for (int j = i; j <= L.length - 1; j++)
        L.elem[j - 1] = L.elem[j];
    L.length--;
    cout << "删除成功！\n";
    return OK;
}
void CreateList(SqList &L,int n)
{
    int x;
    for(int i = 1; i <=n; i++)
    {
        cin >> x;
        Insert(L, i, x);
    }
}
void Display(SqList L)
{
    for(int i = 0; i < L.length;i++)
        cout << L.elem[i] << " ";
    cout << endl;
}
void MergeList(SqList LA,SqList LB,SqList &LC)
{

}
int main()
{
    SqList LA,LB,LC;
    InitList(LA);
    InitList(LB);
    CreateList(LA, 4);
    CreateList(LB, 7);
    Display(LA);
    Display(LB);
    return 0;
}