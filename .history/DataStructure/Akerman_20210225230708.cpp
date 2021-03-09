/*
 * @Author      : PureWhite
 * @Date        : 2021-02-25 23:04:52
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-02-25 23:07:07
 * @Description : 
 */
#include<iostream>
using namespace std;
long long Ack(int m,int n)
{
    if(m==0)
        return n + 1;
    if(n==0)
        return Ack(m - 1, 1);
    return Ack(m - 1, Ack(m, n - 1));
}
int main()
{
    cout << Ack(4, 3);
    return 0;
}
