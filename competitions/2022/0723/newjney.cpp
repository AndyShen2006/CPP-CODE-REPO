#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 18;
int n;
int d[MAX_N][MAX_N];
constexpr int INF = 0x3f3f3f3f;
int dp[1 << MAX_N][MAX_N];

int rec(int S, int v)
{
    if (dp[S][v] >= 0) {
        return dp[S][v];
    }

    if (S == (1 << n) - 1 && v == 0) {
        return dp[S][v] = 0;
    }
    int res = INF;
    for (int u = 0; u < n; u++) {
        if (!(S >> u & 1)) {
            res = min(res, rec(S | 1 << u, u) + d[v][u]);
        }
    }
    return dp[S][v] = res;
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    int ans = rec(0, 0);
    cout << ((ans >= INF) ? -1 : ans) << endl;
}

int main()
{
    int m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[i][j] = INF;
        }
    }
    int f, t, v;
    for (int i = 1; i <= m; i++) {
        cin >> f >> t >> v;
        d[f - 1][t - 1] = min(d[f - 1][t - 1], v);
    }
    for (int i = 0; i < n; i++) {
        d[i][0] = 0;
    }
    solve();
    return 0;
}