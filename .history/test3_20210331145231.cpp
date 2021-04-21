/*
 * @Author      : PureWhite
 * @Date        : 2021-03-31 11:43:17
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-03-31 14:52:30
 * @Description : 
 */
#include<stdio.h>
int float_to_int(float f)
{ 
    int *p = (int *)&f; 
    int temp = *p; 
    int sign= -1;              //判断符号位 
    if((temp & 0x80000000) == 0) 
    {  
    sign = 1; 
    } 
    int exp = ((temp >> 23) & 0x000000ff) - 127;//求出指数位 
    int tail = (temp & 0x007fffff) | 0x00800000;//求出尾数位 
    int res  = tail >> (23 - exp);              //求出有效数字
    printf("%d", res);
    return sign * res;                          //返回整数
}

int main()
{
    // float a;
    // int b;
    // scanf("%d", &b);
    // a = b;
    // printf("%f", a);
    // float_to_int(2147483600);
    int a = 1;
    a = a >> -1;
    printf("%d", a);
    return 0;
}