#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr ll MAX_P = 4e8 + 10;
void exgcd(ll a, ll b, ll& x, ll& y)
{
    if (!b) {
        x = 1, y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}

// vector<ll> primes;
// bool nPrime[MAX_P];
// void euler(ll n)
// {
//     for (ll i = 2; i <= n; i++) {
//         if (!nPrime[i]) {
//             primes.push_back(i);
//         }
//         for (auto it : primes) {
//             if (i * it > n) {
//                 break;
//             }
//             nPrime[i * it] = true;
//             if (i % it == 0) {
//                 break;
//             }
//         }
//     }
// }

ll p1 = 399999949, rp1 = 359999963, c1 = p1 * rp1;
ll p2 = 399999959, rp2 = 39999995, c2 = p2 * rp2;

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
    // euler(4e8);
    // cout << "Finished Euler" << endl;
    // cout << primes.back() << endl;
    // cout << *(primes.end() - 2) << endl;
    ll a1 = queryMod(p1);
    ll a2 = queryMod(p2);
    ll n = p1 * p2;
    cout << "! " << (a1 * c1 + a2 * c2) % n << endl;
    return 0;
}