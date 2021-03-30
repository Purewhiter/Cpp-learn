#include<stdio.h>
int x;
void dispBinary(int x)
{
    for(int i=31;i>=0;i--)
    {    printf("%d", (x >> i) & 1);
        if(i%8==0)
            printf(" ");
    }
    printf("\n");
}
int main()
{
    int x = 2;
    x = x >> 31;
    dispBinary(x);
    return 0;
}