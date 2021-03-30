/*
 * @Author      : PureWhite
 * @Date        : 2021-03-27 20:26:20
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-03-28 00:34:32
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
void fun3(int);
void fun4(int);
int main()
{
    fun1(1);
    fun2(1);
    fun3(1);
    fun4(-1);
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
    int mask = 0x007c0000;
    x = x | mask;
    printf("After: ");
    dispBinary(x);
}
void fun4(int x)
{
    printf("Before:");
    dispBinary(x);
    int mask = 0xe07fffff;
    x = x & mask;
    int a;
    printf("Exter a 6-bit number(Hexdecimal):");
    scanf("0x%x", &a);
    a = a << 23;
    x = x | a;
    printf("After: ");
    dispBinary(x);
}