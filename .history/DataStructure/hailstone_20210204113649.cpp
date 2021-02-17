/*
 * @Author      : PureWhite
 * @Date        : 2021-02-04 11:26:37
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-02-04 11:36:49
 * @Description : 
 */
#include <iostream>
using namespace std;
int hailstone(int n)
{
    int length = 1;
    while (n > 1)
    {
        cout << n << " ";
        (n % 2) ? n = 3 *n + 1 : n /= 2;
        length++;
    }
    cout << n << endl;
    cout<<length << endl;
    return length;
}
int main()
{
    int n;
    cin >> n;
    hailstone(n);
    return 0;
}