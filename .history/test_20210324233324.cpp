/*
 * @Author      : PureWhite
 * @Date        : 2021-02-02 22:44:10
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-03-24 23:33:24
 * @Description : 
 */
#include<iostream>
#include<vector>
using namespace std;
string s1;
int a;
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
    int a = 10;
    int t = a;
    a = 9;

    char *s[] = {"aaa", "bbb", "ccc"};
    char *m = s[1];
    s[1]="kkkk";
    cout << m;
    return 0;
}
