#include<stdio.h>
int x;
void dispBinary(int x)
{
    for(int i=31;i>=0;i--)
        printf("%d", (x >> i) & 1);
    printf("\n");
}
int main()
{
    int a = 0;
    printf("%d", sizeof(a));
    return 0;
}