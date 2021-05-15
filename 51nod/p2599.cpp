// Pull from Workspace/standard/LCA_simple.cpp
#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 100000;
//constexpr int INF = 2 << 8;

map<int, set<int>> G;
bool isFind[MAX_N] = { 0 };
int depth[MAX_N] = { 0 };
int parent[MAX_N] = { 0 };

void dfs(int root, int dep)
{
    isFind[root] = true;
    for (auto it : G[root]) {
        if (!isFind[it]) {
            depth[it] = dep + 1;
            parent[it] = root;
            dfs(it, dep + 1);
        }
    }
}

int lca(int a, int b)
{
    while (depth[a] > depth[b]) {
        a = parent[a];
    }
    while (depth[a] < depth[b]) {
        b = parent[b];
    }
    while (a != b) {
        a = parent[a];
        b = parent[b];
    }
    return a;
}

int main()
{
    freopen("data/LCA_simplea.in", "r", stdin);
    int n, m, u, v;
    cin >> n, n--;
    while (n--) {
        cin >> u >> v;
        G[u].insert(v);
        G[v].insert(u);
    }
    dfs(1, 0);
    cin >> m;
    while (m--) {
        cin >> u >> v;
        cout << lca(u, v) << endl;
    }
}