#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll p1 = 99999999999998807, p2 = p1 + 2;

inline ll queryMod(ll x)
{
    cout << "? " << x << endl;
    ll ans;
    cin >> ans;
    if (ans == -1) {
        exit(0);
    }
    return ans;
}

int main()
{
    // cerr << p1 << ' ' << p2 << endl;
    int T;
    cin >> T;
    while (T--) {
        ll a1 = queryMod(p1);
        ll a2 = queryMod(p2);
        cout << __gcd(p1 - a1, p2 - a2) << endl;
    }
    return 0;
}