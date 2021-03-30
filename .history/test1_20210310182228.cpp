/*
 * @Author      : PureWhite
 * @Date        : 2021-03-10 18:16:37
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-03-10 18:22:28
 * @Description : 
 */
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    string s = "你好啊";
    fstream file("test.txt", ios::binary);
    file.write(s.c_str(), sizeof(s));
    return 0;
}