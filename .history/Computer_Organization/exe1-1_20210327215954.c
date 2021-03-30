/*
 * @Author      : PureWhite
 * @Date        : 2021-03-27 20:26:20
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-03-27 21:59:53
 * @Description : 
 */
#include<stdio.h>
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