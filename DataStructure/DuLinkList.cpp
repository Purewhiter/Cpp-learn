/*
 * @Author      : PureWhite
 * @Date        : 2021-02-25 17:22:46
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-02-25 17:22:47
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
typedef struct DuLNode
{
    ElemType data;
    DuLNode *next;
    DuLNode *prior;
} DuLNode, *DuLinkList;
int main()
{
    
}