// Pull from Workspace/standard/LCA_simple.cpp
#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 100000;
//constexpr int INF = 2 << 8;

map<int, map<int, int>> G;
bool isFind[MAX_N] = { 0 };
int depth[MAX_N] = { 0 };
int parent[MAX_N] = { 0 };

void dfs(int root, int dep)
{
    isFind[root] = true;
    for (auto it : G[root]) {
        if (!isFind[it.first]) {
            depth[it.first] = dep + it.second;
            parent[it.first] = root;
            dfs(it.first, dep + it.second);
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
    freopen("data/p2621a.in", "r", stdin);
    int n, q, u, v, t;
    cin >> n >> q, n--;
    while (n--) {
        cin >> u >> v >> t;
        G[u].insert(make_pair(v, t));
        G[v].insert(make_pair(u, t));
    }
    dfs(1, 0);
    while (q--) {
        cin >> u >> v;
        cout << depth[u] + depth[v] - 2 * depth[lca(u, v)] << endl;
    }
}