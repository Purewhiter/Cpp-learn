/*
 * @Author      : PureWhite
 * @Date        : 2021-03-27 20:26:20
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-03-28 10:52:41
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
void fun5(int, int, int);
void fun6(int, int);
int main()
{
    // fun1(1);
    // fun2(1);
    // fun3(1);
    // fun4(-1);
    // fun5(60, 3, 5);
    fun6(2, 1);
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
    printf("Exter a 6-bit number(Hexdecimal,like 0x2a):");
    scanf("0x%x", &a);
    a = a << 23;
    x = x | a;
    printf("After: ");
    dispBinary(x);
}
void fun5(int x,int i,int j)
{
    printf("Before: ");
    dispBinary(x);
    int mask = -1;
    mask = mask << (j - i + 1);
    int y = (x >> i)&(~mask);
    printf("After: ");
    for (int k = (j-i); k >= 0; k--)
    {
        printf("%d", (y >> k) & 1);
        if (k % 4 == 0)
            printf(" ");
    }
    printf("\n");
}
void fun6(int x,int i)
{
    // int mask1 = (1 << i);
    // mask1 = mask1 & x;//mask1保存x第i位
    // int mask2 = (1 << (31 - i));
    // mask2 = mask2 & x;//mask2保存x第31-i位
    // x = x & ~(1<<i);
    // x = x & ~(1 << (31 - i));
    // mask1 = mask1 << (31 - i - i);
    // mask2=mask2>>()
    printf("Before:");
    dispBinary(x);
    int mask1 = (x >> i) & 1;
    int mask2 = (x >> (31 - i)) & 1;
    mask1 = mask1 << (31 - i);
    mask2 = mask2 << i;
    x = x & ~(1<<i);
    x = x & ~(1 << (31 - i));
    x = x | mask1;
    x = x | mask2;
    printf("After: ");
    dispBinary(x);
}