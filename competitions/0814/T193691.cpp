#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr ll mod = 998244353;
// TODO:Quick Power
ll quickpower(ll x, ll n) //n^k
{
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * x % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

int main()
{
    ll T, R, n;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> R >> n;
        ll ans = ((n * (quickpower(R, n + 1) - R - n * R + n) % mod) * quickpower((R - 1), (mod << 1) - 4)) % mod;
        if (ans < 0) {
            ans += mod;
        }
        cout << ans << endl;
    }
    return 0;
}