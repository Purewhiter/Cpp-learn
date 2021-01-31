/*
 * @Author: PureWhite
 * @Date: 2020-08-19 09:48:27
 * @LastEditors: PureWhite
 * @LastEditTime: 2020-08-19 11:34:28
 * @Description: 
 */
#include<iostream>
using namespace std;
int main()
{
    int i,timeA,timeB;
    cin >> i;
    timeA=5*i;
    timeB=11+3*i;
    if (timeA<timeB)
        cout << "Local";
    else
        cout << "Luogu";
    return 0;
    
}