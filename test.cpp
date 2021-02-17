/*
 * @Author      : PureWhite
 * @Date        : 2021-02-02 22:44:10
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-02-03 21:57:01
 * @Description : 
 */
#include<iostream>
#include<vector>
using namespace std;
string s1;
int a;
int main()
{
    vector<int> vs = {1,2,3,4,5,6,7,8,9,0};
    for(auto i=vs.begin();i!=vs.end();i++)
        (*i)*= 2;
    for(auto i:vs)
        cout << i << endl;
    return 0;
}
