/*
 * @Author      : PureWhite
 * @Date        : 2021-03-28 11:06:07
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-03-28 16:38:50
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
    int code;
} shorter;
int short_to_int(short x);
shorter int_to_short(int x);
int main()
{
    // short x = -32768;
    // short_to_int(x);
    int y = 3550;
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
    if (!(x ^ 0xffff8000)) //特殊情况，x=-32768
    {
        result.code = 0;
        result.a = x & 0x0000ffff;
        return result;
    }

    if (x & 0x80000000) //x是负数
    {
        x = (x ^ 0x7fffffff) + 1; //将x转为原码表示
    }
    if (x & 0x7fff8000) //x不在short表数范围内
    {
        result.code = -1;
        if (x & 0x80000000)    //x是负数
            result.a = 0x8000; //返回short的最小值-32768
        else
            result.a = 0x7fff; //x是正数，返回short的最大值32767
    }
    else //x在short表数范围内
    {
        result.code = 0;
        if (x & 0x80000000) //x是负数
            result.a = (x ^ 0x8000ffff) + 1;
        else //x不是负数
            result.a = x & 0x00007fff;
    }

    if(result.code==0)
        printf("Success!\n");
    else
        printf("Failed!\n");
    printf("return code=%d\nresult=%d\n", result.code, result.a);
    return result;
}
