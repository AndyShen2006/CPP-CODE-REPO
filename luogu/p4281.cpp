#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 500010;

vector<int> G[MAX_N];
typedef pair<int, int> P;

int siz[MAX_N], dep[MAX_N], par[MAX_N], hs[MAX_N];

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
        if (!hs[x] || siz[it] > siz[hs[x]]) {
            hs[x] = it;
        }
        siz[x] += siz[it];
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
        if (it == par[x] || it == hs[x]) {
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

int dis(int u, int v)
{
    int p = lca(u, v);
    return dep[u] + dep[v] - dep[p] - dep[p];
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    // freopen("data/p4281b.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    int x, y, z;
    for (int i = 1; i <= n - 1; i++) {
        cin >> x >> y;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    dfs1(1);
    dfs2(1, 1);
    // for (int i = 1; i <= n; i++) {
    //     printf("Node:%d,size:%d,depth:%d,par:%d,hs:%d\n", i, siz[i], dep[i], par[i], hs[i]);
    // }
    // for (int i = 1; i <= n; i++) {
    //     printf("Node:%d,top:%d\n", i, top[i]);
    // }
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> z;
        int a = lca(x, y);
        int b = lca(y, z);
        int c = lca(x, z);
        int p = max({ P(dep[a], a), P(dep[b], b), P(dep[c], c) }).second;
        cout << p << ' ' << dis(p, x) + dis(p, y) + dis(p, z) << endl;
    }
    return 0;
}