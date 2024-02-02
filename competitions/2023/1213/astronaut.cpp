#include <bits/stdc++.h>

using namespace std;
// Has been accepted on test1-3.
// Notice:some same values

typedef long long ll;
constexpr int MAX_N = 100010;
ll a[MAX_N];
multiset<ll> b;

int main()
{
    freopen("astronaut.in", "r", stdin);
    freopen("astronaut.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll tmp;
    for (int i = 1; i <= m; i++) {
        cin >> tmp;
        b.insert(tmp);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        auto it = b.upper_bound(a[i]);
        if (it == b.end()) {
            continue;
        }
        ans += *it;
        b.erase(it);
    }
    cout << ans << endl;
    return 0;
}