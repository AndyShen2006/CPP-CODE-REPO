#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr ll MOD = 1e9 + 7;

ll quickpow(ll x, ll n)
{
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

int main()
{
    int a, d, n;
    cin >> a >> d >> n;
    cout << (a * quickpow(d, n - 1)) % MOD << endl;
    return 0;
}