#include <bits/stdc++.h>

using namespace std;

#define int long long

void exgcd(int a, int b, int& x, int& y)
{
    if (b == 0) {
        x = 1, y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}

signed main()
{
    int a = 1e8, ra, b = 1e9 + 7, y;
    exgcd(a, b, ra, y);
    cout << ra + b << endl;
    cerr << (ra + b) * a % b;
    return 0;
}