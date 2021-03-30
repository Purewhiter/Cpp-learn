/*
 * @Author      : PureWhite
 * @Date        : 2021-03-10 18:16:37
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-03-10 18:26:01
 * @Description : 
 */
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    string s= "你好啊";
    fstream file;
    file.open("text.txt", ios::app);
    file << s;
    // file.write(s, sizeof(s));
    return 0;
}