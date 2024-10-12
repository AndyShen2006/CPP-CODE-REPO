#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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
    int T;
    cin >> T;
    while (T--) {
        ll x = 9e17;
        ll a = queryMod(x);
        ll ans = queryMod(x - a - 1) + 1;
        cout << "! " << ans << endl;
    }
    return 0;
}