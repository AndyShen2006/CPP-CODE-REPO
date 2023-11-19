#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 1000010;
vector<int> T[MAX_N];

int siz[MAX_N], par[MAX_N], dep[MAX_N], son[MAX_N];

void dfs1(int x)
{
    siz[x] = 1;
    for (auto it : T[x]) {
        if (it == par[x]) {
            continue;
        }
        dep[it] = dep[x] + 1;
        par[it] = x;
        dfs1(it);
        siz[x] += siz[it];
        if (!son[x] || siz[it] > siz[son[x]]) {
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
    for (auto it : T[x]) {
        if (it == par[x] || it == son[x]) {
            continue;
        }
        dfs2(it, it);
    }
}

int lca(int x, int y)
{
}

int main()
{
    int n, cur, k;
    cin >> n >> cur >> k;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    for (int i = 1; i <= k; i++) {
        int d, t;
        cin >> d >> t;
    }
    return 0;
}