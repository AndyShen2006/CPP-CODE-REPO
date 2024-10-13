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

inline bool check(ll x)
{
    ll ans = queryMod(x);
    return ans == x;
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        ll l = 2, r = 1e18;
        while (l < r) {
            ll mid = (l + r) >> 1;
            if (check(mid)) {
                // cerr << l << ' ' << mid << ' ' << r << endl;
                l = mid + 1;
            } else {
                // cerr << l << ' ' << mid << ' ' << r << endl;
                r = mid;
            }
        }
        cout << "! " << l << endl;
    }
    return 0;
}