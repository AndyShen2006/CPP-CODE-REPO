#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int MOD = 1e9 + 7;
int a[20];
ll f[20][200];
ll dfs(int pos, bool limit, ll sum)
{
    if (!pos) {
        return sum;
    }
    if (!limit && ~f[pos][sum]) {
        return f[pos][sum];
    }
    int ub = limit ? a[pos] : 9;
    ll ans = 0;
    for (int i = 0; i <= ub; i++) {
        ans = (ans + dfs(pos - 1, limit && (i == ub), sum + i)) % MOD;
    }
    if (!limit) {
        f[pos][sum] = ans;
    }
    return ans;
}

ll solve(ll x)
{
    int len = 0;
    while (x > 0) {
        a[++len] = int(x % 10);
        x /= 10;
    }
    return dfs(len, true, 0);
}

int main()
{
    memset(f, -1, sizeof(f));
    int T;
    cin >> T;
    while (T--) {
        ll l, r;
        cin >> l >> r;
        ll ans = (solve(r) - solve(l - 1)) % MOD;
        while (ans < 0) {
            ans += MOD;
        }
        cout << ans << endl;
    }
    return 0;
}