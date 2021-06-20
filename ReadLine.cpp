/*
 * @Author      : PureWhite
 * @Date        : 2021-05-18 21:20:15
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-05-18 21:20:15
 * @Description : 
 */
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    string s;
    fstream f("t.txt");
    f >> s;
    cout << s;
    return 0;
}