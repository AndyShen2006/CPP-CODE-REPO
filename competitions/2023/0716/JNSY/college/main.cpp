#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// ll c[100010];
map<ll, ll, greater<>> c;
map<ll, ll> pre;
ll n;

int main()
{
    freopen("college.in", "r", stdin);
    freopen("college.out", "w", stdout);
    cin >> n;
    ll tmp;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        c[tmp]++;
    }
    ll last = -1;
    for (auto it : c) {
        if (last == -1) {
            pre[it.first] = it.second;
            last = it.first;
        } else {
            pre[it.first] = c[last] + it.second;
        }
    }
    ll ans = 0, price = 0;
    for (auto it : pre) {
        if (it.second * it.first > ans) {
            ans = it.first * it.second;
            price = it.first;
        }
    }
    cout << ans << ' ' << price << endl;
    return 0;
}