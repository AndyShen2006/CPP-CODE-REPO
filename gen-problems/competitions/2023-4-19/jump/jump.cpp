#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll exgcd(ll a, ll b, ll& x, ll& y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll r = exgcd(b, a % b, x, y);
    ll tmp = y;
    y = x - (a / b) * y;
    x = tmp;
    return r;
}

int main()
{
    int x, y, m, n, l;
    cin >> x >> y >> m >> n >> l;
    ll a = n - m;
    ll b = l;
    ll c = x - y;
    if (a < 0) {
        a = -a;
        c = -c;
    }
    ll x0 = 0, y0 = 0;
    ll g = exgcd(a, b, x0, y0);
    if (c % g) {
        cout << "Impossible" << endl;
    } else {
        cout << (c / g * x0 % (b / g) + b / g) % (b / g) << endl;
    }
    return 0;
}