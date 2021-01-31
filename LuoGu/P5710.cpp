#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cin >> a;
    b = !(a % 2);
    c = a > 4 && a <= 12;
    printf("%d %d %d %d", b && c, b || c, (b&&!c)||(!b&&c), !(b || c));
    return 0;
}

