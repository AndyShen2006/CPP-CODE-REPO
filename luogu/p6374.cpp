#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 500010;
vector<int> G[MAX_N];
#define DEBUG 0

int size[MAX_N], dep[MAX_N], son[MAX_N], par[MAX_N];

void dfs1(int x)
{
    size[x] = 1;
    for (auto it : G[x]) {
        if (it == par[x]) {
            continue;
        }
        dep[it] = dep[x] + 1;
        par[it] = x;
        dfs1(it);
        size[x] += size[it];
        if (!son[x] || size[son[x]] < size[it]) {
            son[x] = it;
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
        if (it == par[x] || it == son[x]) {
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
    return 0;
}