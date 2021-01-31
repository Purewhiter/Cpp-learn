/*
 * @Author      : PureWhite
 * @Date        : 2020-09-13 09:59:31
 * @LastEditors : PureWhite
 * @LastEditTime: 2020-09-13 10:43:27
 * @Description : 南农数据结构-实验1
 */
#include<iostream>
#include<string.h>
using namespace std;
typedef struct Student *PtrStu;
typedef PtrStu List;
typedef PtrStu Position;
struct Student
{
    long int num;
    char name[30];
    Position Next;
};
void swap(int &a,int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
};
int main()
{
 PtrStu A, B, C,head,p;
    A = (PtrStu)malloc(sizeof(Student));
    B = (PtrStu)malloc(sizeof(Student));
    C = (PtrStu)malloc(sizeof(Student));
    A->num = 1;
    strcpy(A->name , "Aname");
    B->num = 2;
    strcpy(B->name , "Bname");
    C->num = 3;
    strcpy(C->name , "Cname");
    head = A;
    A->Next = B;
    B->Next = C;
    C->Next = NULL;
    p = A;
    do
    {
        cout << p->num << ' ' << p->name << endl;
        p = p->Next;
    } while (p != NULL);
    // int a = 1;
    // int b = 2;
    // swap(a, b);
    // cout << a << ' ' << b;
    return 0;
}