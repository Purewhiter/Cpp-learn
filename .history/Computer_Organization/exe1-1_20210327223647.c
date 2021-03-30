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
void displayFloat(float x)
{
    float *fp = &x;
    int *ip = fp, i = *ip;
    printf("%#x\n", i);
}
int main()
{
    float x = 20.59375;
    displayFloat(x);
    return 0;
}