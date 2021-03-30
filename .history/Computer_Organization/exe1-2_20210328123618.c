/*
 * @Author      : PureWhite
 * @Date        : 2021-03-28 11:06:07
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-03-28 12:36:18
 * @Description : 
 */
#include <stdio.h>
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
void short_to_int(short x);
int main()
{
    short x = -32768;
    short_to_int(x);
    return 0;
}

void short_to_int(short x)
{
    int y;
    if (x & 0x8000) //x是负数
    {
        y = 0xffff0000 | x;
    }
    else
    {
        y = x & 0x00007fff;
    }
    printf("%d\n", y);
}