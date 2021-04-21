/*
 * @Author      : PureWhite
 * @Date        : 2021-03-31 11:43:17
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-04-13 22:37:23
 * @Description : 
 */
#include <stdio.h>
#include<iostream>
int float_to_int(float f)
{
    int *p = (int *)&f;
    int temp = *p;
    int sign = -1; //判断符号位
    if ((temp & 0x80000000) == 0)
    {
        sign = 1;
    }
    int exp = ((temp >> 23) & 0x000000ff) - 127; //求出指数位
    int tail = (temp & 0x007fffff) | 0x00800000; //求出尾数位
    int res = tail >> (23 - exp);                //求出有效数字
    printf("%d", res);
    return sign * res; //返回整数
}

void float2binary(float x, char a[])
{
    int i, j = 1;
    int *px;
    px = (int *)&x;
    for (i = 0; i < 32; i++)
    {
        if (*px & (j << (31 - i)))
            a[i] = 1;
        else
            a[i] = 0;
    }
    for (i = 0; i < 32; i++)
    {
        printf("%d", a[i]);
        if (i == 8)
            printf(",");
        if (i == 0)
            printf(",");
    }
}
int main()
{
    // float a;
    // int b;
    // scanf("%f", &a);
    // b = a;
    // printf("%d", b);
    // scanf("%f", &a);
    // printf("%f", a);
    // float_to_int(2147483600);
    // int a = 2147483648;
    // int b = -1;
    // int c = a / b;
    // printf("%d,%d\n", a, c);
    // char n[32];
    // float d = 0.4375;
    // float2binary(d, n);
    short y=-32768;
    short x=1;
    x=x-y;
    std::cout << x;
    return 0;
}