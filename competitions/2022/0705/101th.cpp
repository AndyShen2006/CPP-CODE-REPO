#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 1e6;

int a[MAX_N];

int main()
{
    // freopen("data/101th.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans, f, t;
    for (int i = 1; i <= m; i++) {
        ans = 0;
        cin >> f >> t;
        for (int i = f; i <= t; i++) {
            ans = __gcd(ans, a[i]);
        }
        cout << ans << endl;
    }
    return 0;
}