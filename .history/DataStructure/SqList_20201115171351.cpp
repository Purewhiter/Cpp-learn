/*
 * @Author      : PureWhite
 * @Date        : 2020-11-15 11:02:33
 * @LastEditors : PureWhite
 * @LastEditTime: 2020-11-15 17:13:52
 * @Description : 顺序表实现
 */

#include <iostream>
#define OK 1
#define ERROR 0
#define MAXSIZE 100
using namespace std;
typedef int ElementType;
typedef int Position;
typedef int Status;
typedef struct
{
    ElementType Data[MAXSIZE];
    int length;
} LNode;
typedef LNode *LNodePtr;
typedef LNodePtr List;

Status MakeEmpty(List &L)  //此处应传递L的地址
{
    L = new LNode;
    if(L == NULL)
    {
        cout << "创建失败！\n";
        return ERROR;
    }
    L->length = 0;
    cout << "创建成功！\n";
    return OK;
}

ElementType GetElem(List L, int i)
{
    if (i < 1 || i > L->length)
        return ERROR;
    return L->Data[i - 1];
}

Position Find(List L, ElementType x)
{
    for (int i = 0; i < L->length; i++)
        if (L->Data[i] == x)
            return i + 1;
    return ERROR;
}

Status Insert(List L, ElementType x, Position i)
{
    if (i < 1 || i > L->length + 1)
    {
        cout << "位置不合法！";
        return ERROR;
    }
    if (L->length == MAXSIZE)
    {
        cout << "空间已满！";
        return ERROR;
    }
    for (int j = L->length - 1; j >= i - 1; j--)
    {
        L->Data[j + 1] = L->Data[j];
    }
    L->Data[i - 1] = x;
    L->length++;
    cout << "插入成功！\n";
    return OK;
}

Status Delete(List L, Position i)
{
    if (i < 1 || i > L->length)
    {
        cout << "位置不合法！";
        return ERROR;
    }
    for (int j = i; j <= L->length - 1; j++)
        L->Data[j - 1] = L->Data[j];
    L->length--;
    cout << "删除成功！\n";
    return OK;
}

void Display(List L)
{
    for(int i = 0; i < L->length;i++)
        cout << L->Data[i] << "  ";
    cout << endl;
}
int main()
{
    List L;
    MakeEmpty(L);
    Insert(L, 9, 1);
    Insert(L, 10, 2);
    Display(L);
    Delete(L, 1);
    Display(L);
    return 0;
}