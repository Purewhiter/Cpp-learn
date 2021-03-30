/*
 * @Author      : PureWhite
 * @Date        : 2021-03-27 20:26:20
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-03-28 21:52:43
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
void fun1(int x);//将x的第0~12位取反
void fun2(int x);//将x的第13~17位清零
void fun3(int x);// 将x的第18~22位置1
void fun4(int x);//将x的23~28位替换为用户任意指定的6个比特
void fun5(int x, int i, int j);//若0≤i≤31，0≤j≤31，且j≥i，读取x的第i~j位的内容
void fun6(int x, int i);//若0≤i≤31，交换x的第i位和第31-i位
void fun7(int x);//根据x最高3位的值(数值范围应为0~8)，完成操作
int main()
{
    printf("fun1:\n");
    fun1(1);
    printf("fun2:\n");
    fun2(-1);
    printf("fun3:\n");
    fun3(1);
    printf("fun4:\n");
    fun4(-1);
    printf("fun5:\n");
    fun5(60, 3, 5);
    printf("fun6:\n");
    fun6(1, 0);
    printf("fun7:\n");
    fun7(0x80000000);
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
    scanf(" 0x%x", &a);
    a = a << 23;
    x = x | a;
    printf("After: ");
    dispBinary(x);
}
void fun5(int x, int i, int j)
{
    printf("Before: ");
    dispBinary(x);
    int mask = -1;
    mask = mask << (j - i + 1);
    int y = (x >> i) & (~mask);
    printf("After: ");
    for (int k = (j - i); k >= 0; k--)
    {
        printf("%d", (y >> k) & 1);
        if (k % 4 == 0)
            printf(" ");
    }
    printf("\n");
}
void fun6(int x, int i)
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
    x = x & ~(1 << i);
    x = x & ~(1 << (31 - i));
    x = x | mask1;
    x = x | mask2;
    printf("After: ");
    dispBinary(x);
}
void fun7(int x)
{
    int m = (x >> 29) & 0x00000007;
    switch (m)
    {
    case 1:
        fun1(x);
        break;
    case 2:
        fun2(x);
        break;
    case 3:
        fun3(x);
        break;
    case 4:
        fun4(x);
        break;
    case 5:
        fun5(x, 2, 5);
        break;
    case 6:
        fun6(x, 0);
        break;
    }
}