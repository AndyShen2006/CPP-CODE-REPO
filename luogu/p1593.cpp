#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr ll MOD = 9901;
map<ll, ll> di;
char isPrime[50000000];
vector<ll> primes;

ll qpow(ll a, ll n)
{
    ll base = a;
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        n >>= 1;
    }
    return res % MOD;
}

void exgcd(ll a, ll b, ll& x, ll& y)
{
    if (!b) {
        x = 1, y = 0;
        return;
    }
    exgcd(b, a % b, x, y);
    ll tmp = x;
    x = y;
    y = tmp - (a / b) * y;
}

ll mod_rev(ll a)
{
    ll x, y;
    exgcd(a, MOD, x, y);
    return (MOD + x % MOD) % MOD;
}

int main()
{
    ll a, b;
    cin >> a >> b;
    for (ll i = 2; i <= a; i++) {
        if (!isPrime[i]) {
            primes.emplace_back(i);
        }
        for (ll j = i + i; j <= a; j += i) {
            isPrime[j] = true;
        }
    }
    for (auto it : primes) {
        while (!(a % it)) {
            di[it]++;
            a /= it;
        }
    }
    ll ans = 1;
    for (auto it : di) {
        // printf("%lld %lld %lld %lld", it.first, it.second, qpow(it.first, it.second * b + 1) - 1, mod_rev(it.first - 1));
        ll mr = mod_rev(it.first - 1);
        ans *= (qpow(it.first, it.second * b + 1) - 1) * (mr == 0 ? 1 : mr);
        ans %= MOD;
    }
    cout << ans % MOD << endl;
    return 0;
}