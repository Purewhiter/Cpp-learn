/*
 * @Author      : PureWhite
 * @Date        : 2021-02-02 22:44:10
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-03-28 20:50:48
 * @Description : 
 */
#include<iostream>
#include<vector>
using namespace std;
string s1;
int a;
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
    return sign * res;                          //返回整数
}

int main()
{
    // vector<int> vs = {1,2,3,4,5,6,7,8,9,0};
    // for(auto i=vs.begin();i!=vs.end();i++)
    //     (*i)*= 2;
    // for(auto i:vs)
    //     cout << i << endl;
    // char *s="hhh";
    // char *t = s;
    // s = "jjj";
    // cout << s<<t<< endl;
    // int a = 10;
    // int t = a;
    // // a = 9;
    // int x = 0x41a4c000;
    // // float *fp = (float *)&x;
    // // float f = *fp;
    // // printf("%f", f);
    // int x = float_to_int(1.00002);
    long long x;
    printf("%d长度", sizeof(x));
    return 0;
}
