/*
 * @Author      : PureWhite
 * @Date        : 2021-02-26 21:23:27
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-02-26 21:23:28
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
// typedef ElemType SqBiTree[MAXSIZE];
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild,*rchild;
} BiTNode, *BiTree;
