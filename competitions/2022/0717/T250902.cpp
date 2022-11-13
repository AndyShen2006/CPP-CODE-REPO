#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a[50];

inline ll v(ll s)
{
    ll x = 1;
    ll ans = 0;
    while (s) {
        if (s % 2) {
            ans ^= a[x];
        }
        s /= 2;
        x++;
    }
    return ans;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }

    return 0;
}