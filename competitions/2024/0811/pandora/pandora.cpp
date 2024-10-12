#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 100010;
vector<pair<int, int>> T[MAX_N];

int dep[MAX_N], siz[MAX_N], par[MAX_N], hs[MAX_N], len[MAX_N];
void dfs1(int x)
{
    siz[x] = 1;
    for (auto it : T[x]) {
        if (it.first == par[x]) {
            continue;
        }
        par[it.first] = x;
        dep[it.first] = dep[x] + 1;
        len[it.first] = len[x] + it.second;
        dfs1(it.first);
        siz[x] += siz[it.first];
        if (!hs[x] || siz[hs[x]] < siz[it.first]) {
            hs[x] = it.first;
        }
    }
}

int top[MAX_N];
void dfs2(int x, int tx)
{
    top[x] = tx;
    if (hs[x]) {
        dfs2(hs[x], tx);
    }
    for (auto it : T[x]) {
        if (it.first == hs[x] || it.first == par[x]) {
            continue;
        }
        dfs2(it.first, it.first);
    }
}

int lca(int u, int v)
{
    while (top[u] != top[v]) {
        if (dep[top[u]] > dep[top[v]]) {
            u = par[top[u]];
        } else {
            v = par[top[v]];
        }
    }
    return dep[u] > dep[v] ? v : u;
}

inline int dis(int u, int v)
{
    return len[u] + len[v] - 2 * len[lca(u, v)];
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    freopen("pandora.in", "r", stdin);
    // freopen("data/pandora1.in", "r", stdin);
    freopen("pandora.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    int u, v, w;
    for (int i = 1; i <= n - 1; i++) {
        cin >> u >> v >> w;
        T[u].emplace_back(v, w);
        T[v].emplace_back(u, w);
    }
    dep[1] = 1;
    par[1] = 0;
    dfs1(1);
    dfs2(1, 0);
    for (int i = 1; i <= q; i++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int ans = 0;
        for (int j = l1; j <= r1; j++) {
            for (int k = l2; k <= r2; k++) {
                ans = max(ans, dis(j, k));
            }
        }
        cout << ans << endl;
    }
    return 0;
}