#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 100010;
vector<int> G[MAX_N];

int dep[MAX_N], siz[MAX_N], par[MAX_N], hs[MAX_N];
void dfs1(int x)
{
    siz[x] = 1;
    for (auto it : G[x]) {
        if (it == par[x]) {
            continue;
        }
        par[it] = x;
        dep[it] = dep[x] + 1;
        dfs1(it);
        siz[x] += siz[it];
        if (!hs[x] || siz[hs[x]] < siz[it]) {
            hs[x] = it;
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
    for (auto it : G[x]) {
        if (it == hs[x] || it == par[x]) {
            continue;
        }
        dfs2(it, it);
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

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    // freopen("data/p3398b.in", "r", stdin);
    // freopen("data/p3398b.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    int u, v;
    for (int i = 1; i <= n - 1; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dep[1] = 1;
    par[1] = 0;
    dfs1(1);
    dfs2(1, 0);
    int a, b, c, d;
    for (int i = 1; i <= q; i++) {
        cin >> a >> b >> c >> d;
        int x = lca(a, b);
        int y = lca(c, d);
        int k = lca(x, y);
        if (k == x) {
            if (lca(a, y) == y) {
                cout << "Y" << endl;
            } else if (lca(b, y) == y) {
                cout << "Y" << endl;
            } else {
                cout << "N" << endl;
            }
        } else if (k == y) {
            if (lca(c, x) == x) {
                cout << "Y" << endl;
            } else if (lca(d, x) == x) {
                cout << "Y" << endl;
            } else {
                cout << "N" << endl;
            }
        } else {
            cout << "N" << endl;
        }
    }
    return 0;
}