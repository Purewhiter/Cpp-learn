#include <stdio.h>
int x;
void dispBinary(int x)
{
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", (x >> i) & 1);
        if (i % 8 == 0)
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
int main()
{
    fun1(1);
    return 0;
}

void fun1(int x)
{
    printf("Before:");
    dispBinary(x);
    int mask = 0x00000fff;
    x = x ^ mask;
    printf("After:");
    dispBinary(x);
}