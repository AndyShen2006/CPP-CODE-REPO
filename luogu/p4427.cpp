#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int MAX_N = 300010;
constexpr long long MOD = 998244353;
vector<int> T[MAX_N];

int par[MAX_N], siz[MAX_N], son[MAX_N];
long long kDep[MAX_N][60], kPre[MAX_N][60];

void dfs1(int x)
{
    siz[x] = 1;
    for (auto it : T[x]) {
        if (it == par[x]) {
            continue;
        }
        kDep[it][1] = kDep[x][1] + 1;
        for (int i = 2; i <= 50; i++) {
            kDep[it][i] = (kDep[it][i - 1] * kDep[it][1]) % MOD;
        }
        par[it] = x;
        dfs1(it);
        siz[x] += siz[it];
        if (!son[x] || siz[it] > siz[son[x]]) {
            son[x] = it;
        }
    }
}

int top[MAX_N];

void dfs2(int tx, int x)
{
    top[x] = tx;
    if (son[x]) {
        dfs2(tx, son[x]);
    }
    for (auto it : T[x]) {
        if (it == son[x] || it == par[x]) {
            continue;
        }
        dfs2(it, it);
    }
}

void dfs3(int x)
{
    for (auto it : T[x]) {
        if (it == par[x]) {
            continue;
        }
        for (int i = 1; i <= 50; i++) {
            kPre[it][i] = (kPre[x][i] + kDep[it][i]) % MOD;
        }
        dfs3(it);
    }
}

int lca(int x, int y)
{
    while (top[x] != top[y]) {
        if (kDep[top[x]][1] > kDep[top[y]][1]) {
            x = par[top[x]];
        } else {
            y = par[top[y]];
        }
    }
    return kDep[x][1] > kDep[y][1] ? y : x;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    // Build Tree and Tree composition
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    par[1] = 1;
    dfs1(1);
    // for (int i = 1; i <= n; i++) {
    //     cout << i << endl;
    //     for (int j = 1; j <= 5; j++) {
    //         cout << j << ' ' << kPre[i][j] << endl;
    //     }
    // }
    dfs2(1, 1);
    dfs3(1);
    // Response requests
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int u, v, k;
        cin >> u >> v >> k;
        int l = lca(u, v);
        long long ans = ((kPre[u][k] + kPre[v][k]) - (kPre[l][k] + kPre[par[l]][k]) + MOD) % MOD;
        while (ans < 0) {
            ans += MOD;
        }
        cout << ans << endl;
    }
    return 0;
}