#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 ell;

const ell p1 = 399999949, rp1 = 359999963;
const ell p2 = 399999959, rp2 = 39999995;
const ell c1 = p2 * rp2;
const ell c2 = p1 * rp1, n = p1 * p2;

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
        ll a1 = queryMod(p1);
        ll a2 = queryMod(p2);
        ll ans = ll(((a1 * c1) % n + (a2 * c2) % n) % n);
        cout << "! " << ans << endl;
    }
    return 0;
}