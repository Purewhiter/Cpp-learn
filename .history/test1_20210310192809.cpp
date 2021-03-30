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
    st stu;
    fstream fp;
    fp.open("test.txt", ios::out);
    cin >> stu.num >> stu.name >> stu.sex >> stu.age >> stu.addr;
    fp << stu.num <<" "<< stu.name <<" " <<stu.sex <<" "<< stu.age <<" "<< stu.addr << endl;
    // string s= "你好啊";
    // fstream file;
    // file.open("text.txt", ios::app);
    // file << s<<endl;
    // file.write(s, sizeof(s));
    return 0;
}