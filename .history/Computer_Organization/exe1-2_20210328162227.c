/*
 * @Author      : PureWhite
 * @Date        : 2021-03-28 11:06:07
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-03-28 16:22:10
 * @Description : 
 */
#include <stdio.h>
void displayShort(int x)
{
    for (int i = 15; i >= 0; i--)
    {
        printf("%d", (x >> i) & 1);
        if (i % 4 == 0)
            printf(" ");
    }
    printf("\n");
}
void displayInt(int x)
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
typedef struct shorter
{
    short a;
    int flag;
} shorter;
int short_to_int(short x);
shorter int_to_short(int x);
int main()
{
    // short x = -32768;
    // short_to_int(x);
    int y = -32769;
    int_to_short(y);
    return 0;
}

int short_to_int(short x)
{
    int y;
    printf("Before trans:\n");
    printf("Decimal: %d\n", x);
    printf("Binary:\n");
    displayShort(x);
    if (x & 0x8000) //x是负数
        y = 0xffff0000 | x;
    else
        y = x & 0x00007fff;
    printf("After trans:\n");
    printf("Decimal: %d\n", y);
    printf("Binary:\n");
    displayInt(y);
    return y;
}
shorter int_to_short(int x)
{
    shorter result;
    if (x & 0x80000000) //x是负数
    {
        x = (x ^ 0x7fffffff) + 1; //将x转为原码表示
    }
    if (x & 0x7fff8000) //x不在在short表数范围内
    {
        result.flag = -1;
        if (x & 0x80000000)    //x是负数
            result.a = 0x8000; //返回short的最小值-32768
        else
            result.a = 0x7fff; //x是正数，返回short的最大值32767
    }
    else
    {
        result.flag=0;
        if(x&0x80000000)
            result.a = (x ^ 0x8000ffff) + 1;
        else
            result.a = x&0x00007fff;
    }
    printf("flag=%d\nresult=%d\n", result.flag, result.a);
    return result;
}
