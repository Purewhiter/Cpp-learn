/*
 * @Author       : PureWhite
 * @Date         : 2020-08-19 09:50:27
 * @LastEditors : PureWhite
 * @LastEditTime: 2020-08-19 11:53:22
 * @Description  : 【深基3.例7】肥胖问题
 */
#include <iostream>
using namespace std;
int main()
{
    double m, h;
    cin>>m>>h;
    double BMI = m / h / h;
    if(BMI<18.5)
        cout << "Underweight";
    else if(BMI>=18.5&&BMI<24)
        cout << "Normal";
    else if(BMI>=24)
        cout << BMI << endl
             << "Overweight";
    return 0;
}