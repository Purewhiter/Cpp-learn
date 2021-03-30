/*
 * @Author      : PureWhite
 * @Date        : 2021-02-02 22:44:10
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-03-28 21:23:31
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
    // double d = 10.2;
    // printf("%lf", d);
    float_to_int(0.00555);
    return 0;
}
