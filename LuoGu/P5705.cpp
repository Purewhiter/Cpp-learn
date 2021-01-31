#include<iostream>
using namespace std;
int main()
{
    string a;
    cin >> a;
    for (int i = 4; i >= 0; i--)
        cout << a[i];
    return 0;
}
// #include<iostream>
// using namespace std;
// double invert(double x)
// {
//     int b=0;
//     int c = x * 10;
//     while(c)
//     {
//         b = b * 10 + c % 10;
//         c /= 10;
//     }
//     return double(b) / 1000;
// }
// int main()
// {
//     double a,b;
//     cin >> a;
//     b=invert(a);
//     cout << b;
//     return 0;
// }