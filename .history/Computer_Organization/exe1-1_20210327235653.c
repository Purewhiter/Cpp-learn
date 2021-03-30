/*
 * @Author      : PureWhite
 * @Date        : 2021-03-27 20:26:20
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-03-27 23:56:52
 * @Description : 
 */
#include <stdio.h>
int x;
void dispBinary(int x)
{
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", (x >> i) & 1);
        if (i % 4 == 0)
            printf(" ");
    }
    printf("\n");
}
void displayFloat(float x)
{
    float *fp = &x;
    int *ip = (int *)fp, tmp = *ip;
    printf("%#x\n", tmp);
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", (tmp >> i) & 1);
        if (i % 4 == 0)
            printf(" ");
    }
    printf("\n");
}
void fun1(int);
void fun2(int);
int main()
{
    fun1(1);
    fun2(1);
    return 0;
}

void fun1(int x)
{
    printf("Before:");
    dispBinary(x);
    int mask = 0x00001fff;
    x = x ^ mask;
    printf("After: ");
    dispBinary(x);
}
void fun2(int x)
{
    printf("Before:");
    dispBinary(x);
    int mask = 0xfffc1fff;
    x = x & mask;
    printf("After: ");
    dispBinary(x);
}
void fun3(int x)
{
    printf("Before:");
    dispBinary(x);
    int mask = 0x1f800000;
    x = x | mask;
    printf("After: ");
    dispBinary(x);
}