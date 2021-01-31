#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, d, e, f,g,h;
    cin>>a>>b>>c>>d;
    e = a * 60 + b;
    f = c * 60 + d;
    g = (f - e) / 60;
    h = (f - e) % 60;
    cout << g <<" "<< h;
    return 0;
}