/*
 * @Author      : PureWhite
 * @Date        : 2021-02-02 22:44:10
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-03-30 21:21:07
 * @Description : 
 */
#include<iostream>
#include<vector>
using namespace std;
string s1;
int a;
int float_to_int(float x)
{
    int S, E, M, *ip, tmp, sign, exp, tail, result;
    ip = (int *)&x;
    tmp = *ip;
    S = (tmp >> 31) & 0x00000001;
    E = (tmp >> 23) & 0x000000ff;
    M = tmp & 0x007fffff;
    sign = (S == 0 ? 1 : -1);
    exp = E - 127;
    tail = (M | 0x00800000) >> (23 - exp);
    result = tail * sign;
    printf("%d\n", result);
    return result;
}
double float_to_double(float x); //第8题
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
    // long long x;
    // printf("%d长度", sizeof(x));
    // // double d = 10.2;
    // // printf("%lf", d);
    // float_to_int(0.00555);
    int a = 0xfff00000,b=0xff800000;//NaN
    float *fp1 = (float *)&a, *fp2 = (float *)&b;
    float f1 = *fp1,f2 = *fp2;
    long long int c = 0x7ff0000000000000;
    double *dp = (double *)&c, d = *dp;
    cout << d;
    // float_to_double(f2);
    return 0;
}
double float_to_double(float x)
{
    double d, *dp;
    long long int tmp = 0, S, E, M;
    int *ip, i;
    ip = (int *)&x;
    i = *ip;
    S = (i >> 31) & 0x00000001;
    E = (((i >> 23) & 0x000000ff) - 127) + 1023;
    M = i & 0x007fffff;
    tmp = tmp | (S << 63);
    tmp = tmp | (E << 52);
    tmp = tmp | (M << 29);
    dp = (double *)&tmp;
    d = *dp;
    printf("float:%f\n", x);
    printf("double:%lf\n", d);
    return d;
}