#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main()
{
    int m, t, s;
    cin >> m >> t >> s;
    if(t==0) 
        cout << 0;
    else if(s/t>=m)
        cout << 0;
    else
        cout << m - ceil(double(s) / t);
    return 0;
}