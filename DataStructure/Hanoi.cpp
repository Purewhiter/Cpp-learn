/*
 * @Author      : PureWhite
 * @Date        : 2021-02-25 23:18:40
 * @LastEditors : PureWhite
 * @LastEditTime: 2021-02-25 23:23:59
 * @Description : 
 */
#include <iostream>
using namespace std;
int m = 0;
void move(char A,int n,char C)
{
    cout << ++m << " move " << n << "," << A << "->" << C << endl;
}
void Hanoi(int n,char A,char B,char C)
{
    if(n==1)
        move(A, 1, C);
    else
    {
        Hanoi(n - 1, A, C, B);
        move(A, n, C);
        Hanoi(n - 1,B,A,C);
    }
}
int main()
{
    Hanoi(4, 'A', 'B', 'C');
    return 0;
}