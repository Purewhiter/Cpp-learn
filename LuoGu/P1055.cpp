/*
 * @Author      : PureWhite
 * @Date        : 2020-08-19 12:07:25
 * @LastEditors : PureWhite
 * @LastEditTime: 2020-08-19 13:16:22
 * @Description : ISBN号码
 */
#include<iostream>
using namespace std;
int main()
{
    char s[14];//改为s[13]此数组会溢出？
    int n=0;
    cin >> s;
    for(int i=0,j=1; i<12; i++)
    {   
        if(s[i]=='-')
            continue;
        n = n + (s[i]-48) * j;
        j++;
    }
    char modNum;
    if (n%11 == 10)
        modNum = 'X';
    else
        modNum = n % 11 + '0';

    if(s[12]==modNum)
        cout << "Right";
    else
        {
            s[12]=modNum;
            cout << s;
        }

    return 0;

}