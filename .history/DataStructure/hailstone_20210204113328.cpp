/*
 * @Author      : PureWhite
 * @Date        : 2021-02-04 11:26:37
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-02-04 11:33:28
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
    return length;
}
int main()
{
    hailstone(42);
    return 0;
}