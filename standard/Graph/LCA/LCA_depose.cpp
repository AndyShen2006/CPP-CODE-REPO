#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 500010;
vector<int> G[MAX_N];
#define DEBUG 0

int siz[MAX_N], dep[MAX_N], son[MAX_N], par[MAX_N];

void dfs1(int x)
{
    siz[x] = 1;
    for (auto it : G[x]) {
        if (it != par[x]) {
            par[it] = x;
            dep[it] = dep[x] + 1;
            dfs1(it);
            siz[x] += siz[it];
            if (!son[x] || siz[son[x]] < siz[it]) {
                son[x] = it;
            }
        }
    }
}

int top[MAX_N];
void dfs2(int x, int tx)
{
    top[x] = tx;
    if (son[x]) {
        dfs2(son[x], tx);
    }
    for (auto it : G[x]) {
        if (it != par[x] && it != son[x]) {
            dfs2(it, it);
        }
    }
}

int lca(int u, int v)
{
    while (top[u] != top[v]) {
        if (dep[top[u]] >= dep[top[v]]) {
            u = par[top[u]];
        } else {
            v = par[top[v]];
        }
    }
    return (dep[u] < dep[v] ? u : v);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, s;
    cin >> n >> m >> s;
    int u, v;
    for (int i = 1; i <= n; i++) {
        G[i].reserve(20);
    }
    for (int i = 1; i <= n - 1; i++) {
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    dep[s] = 1;
    par[s] = -1;
    dfs1(s);
    dfs2(s, s);
    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
    }
    for (int i = 1; i <= n; i++) {
        cout << top[i] << ' ';
    }
    cout << endl;
#if DEBUG
    for (int i = 1; i <= n; i++) {
        printf("%d:size:%d;depth:%d\n", i, size[i], depth[i]);
    }
#endif
    return 0;
}