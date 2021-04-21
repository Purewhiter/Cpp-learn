/*
 * @Author      : PureWhite
 * @Date        : 2021-03-10 18:16:37
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-03-10 19:28:09
 * @Description : 
 */
#include<iostream>
#include<fstream>
using namespace std;
struct st
{
    int num;
    string name;
    string sex;
    int age;
    string addr;
};

int main()
{
    string s1 = "hh";
    string s2 = "hh";
    if(s1==s2)
        printf("=");
    else
        printf("!=");
    // string s= "你好啊";
    // fstream file;
    // file.open("text.txt", ios::app);
    // file << s<<endl;
    // file.write(s, sizeof(s));
    return 0;
}